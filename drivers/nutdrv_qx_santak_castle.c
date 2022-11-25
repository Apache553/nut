/* nutdrv_qx_santak_castle.h - Subdriver for Santak Castle UPSes
 *
 * Copyright (C)
 *   2013 Daniele Pezzini <hyouko@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * NOTE:
 * This subdriver is based on nutdrv_qx_q1 driver. Implemented some vendor specific queries
 *
 */

#include "main.h"
#include "nutdrv_qx.h"
#include "nutdrv_qx_blazer-common.h"

#include "nutdrv_qx_santak_castle.h"

#define DRV_VERSION "SANTAK 0.1(Q1 0.7)"

static int castle_process_status_bits(item_t* item, char* value, const size_t valuelen);

/* qx2nut lookup table */
static item_t	q1_qx2nut[] = {

	/*
	 * > [Q1\r]
	 * < [(226.0 195.0 226.0 014 49.0 27.5 30.0 00001000\r]
	 *    01234567890123456789012345678901234567890123456
	 *    0         1         2         3         4
	 */

	/*
	 * > [Q6\r]
	 * < [(227.8 ---.- ---.- 49.9 219.8 ---.- ---.- 49.9 022 --- --- 039.9 ---.- 39.0 03980 100 35 00000000 00000000 11\r]
	 *    01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789
	 *	  0         1         2         3         4         5         6         7         8         9         10
	 */

	/*
	 * this part indicates some function enable/disable status
	 * in the last string:
	 *   E{0}D{1} - {0} is the enabled list, {1} is the disabled list
	 *   known function:
	 *	   p - Beep when working in bypass mode
	 *	   b - Beep when working in battery mode
	 *	   r - auto reboot (switch on ups when AC is back, i guess)
	 *
	 * > [QP\r]
	 * < [(40.0 70.0 180 264 EpbkcrafDo\r]
	 *    012345678901234567890123456789
	 *	  0         1         2
	 */


	/*
	 * > [WC\r]
	 * < [(0164 0213\r]
	 *    01234567890
	 *	  0         1
	 *	  Watt  VA
	 */

	{ "input.voltage",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	1,	5,	"%.1f",	0,	NULL,	NULL,	NULL },
	{ "input.frequency",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	19,	22,	"%.1f",	0,	NULL,	NULL,	NULL },
	{ "output.voltage",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	24,	28,	"%.1f",	0,	NULL,	NULL,	NULL },
	{ "output.frequency",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	42,	45,	"%.1f",	0,	NULL,	NULL,	NULL },
	{ "ups.load",			0,	NULL,	"Q6\r",	"",	110,	'(',	"",	47,	49,	"%.0f",	0,	NULL,	NULL,	NULL },
	{ "battery.voltage",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	59,	63,	"%.2f",	0,	NULL,	NULL,	NULL },
	{ "ups.temperature",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	71,	74,	"%.1f",	0,	NULL,	NULL,	NULL },
	{ "ups.firmware_estimated_duration",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	76,	80,	"%.0f",	0,	NULL,	NULL,	NULL },
	{ "battery.charge",		0,	NULL,	"Q6\r",	"",	110,	'(',	"",	82,	84,	"%.0f",	0,	NULL,	NULL,	NULL },

	{ "ups.realpower",		0,	NULL,	"WC\r",	"",	11,	'(',	"",	1,	4,	"%.0f",	0,	NULL,	NULL,	NULL },
	{ "ups.apparentpower",		0,	NULL,	"WC\r",	"",	11,	'(',	"",	6,	9,	"%.0f",	0,	NULL,	NULL,	NULL },
	/* Status bits */
	{ "ups.status",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	38,	38,	NULL,	QX_FLAG_QUICK_POLL,	NULL,	NULL,	blazer_process_status_bits },	/* Utility Fail (Immediate) */
	{ "ups.status",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	39,	39,	NULL,	QX_FLAG_QUICK_POLL,	NULL,	NULL,	blazer_process_status_bits },	/* Battery Low */
	{ "ups.status",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	40,	40,	NULL,	QX_FLAG_QUICK_POLL,	NULL,	NULL,	blazer_process_status_bits },	/* Bypass/Boost or Buck Active */
	{ "ups.alarm",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	41,	41,	NULL,	0,			NULL,	NULL,	blazer_process_status_bits },	/* UPS Failed */
	{ "ups.type",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	42,	42,	"%s",	QX_FLAG_STATIC,		NULL,	NULL,	blazer_process_status_bits },	/* UPS Type */
	{ "ups.status",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	43,	43,	NULL,	QX_FLAG_QUICK_POLL,	NULL,	NULL,	blazer_process_status_bits },	/* Test in Progress */
	{ "ups.status",			0,	NULL,	"Q1\r",	"",	47,	'(',	"",	44,	44,	NULL,	QX_FLAG_QUICK_POLL,	NULL,	NULL,	blazer_process_status_bits },	/* Shutdown Active */

	{ "ups.beeper.bypass.status",		0,	NULL,	"QP\r",	"",	21,	'(',	"",	19,	0,	"%s",	0,			NULL,	NULL,	castle_process_status_bits },	/* Bypass Beeper status */
	{ "ups.beeper.battery.status",		0,	NULL,	"QP\r",	"",	21,	'(',	"",	20,	0,	"%s",	0,			NULL,	NULL,	castle_process_status_bits },	/* Battery Beeper status */

	/* Instant commands */
	{ "beeper.bypass.enable",		0,	NULL,	"PEP\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "beeper.bypass.disable",		0,	NULL,	"PDP\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "beeper.battery.enable",		0,	NULL,	"PEB\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "beeper.battery.disable",		0,	NULL,	"PDB\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "load.off",			0,	NULL,	"S00R0000\r",	"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "load.on",			0,	NULL,	"C\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "shutdown.return",		0,	NULL,	"S%s\r",	"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	blazer_process_command },
	{ "shutdown.stayoff",		0,	NULL,	"S%sR0000\r",	"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	blazer_process_command },
	{ "shutdown.stop",		0,	NULL,	"C\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "test.battery.start",		0,	NULL,	"T%02d\r",	"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	blazer_process_command },
	{ "test.battery.start.deep",	0,	NULL,	"TL\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "test.battery.start.quick",	0,	NULL,	"T\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },
	{ "test.battery.stop",		0,	NULL,	"CT\r",		"",	0,	0,	"",	0,	0,	NULL,	QX_FLAG_CMD,	NULL,	NULL,	NULL },

	/* Server-side settable vars */
	{ "ups.delay.start",		ST_FLAG_RW,	blazer_r_ondelay,	NULL,	"",	0,	0,	"",	0,	0,	DEFAULT_ONDELAY,	QX_FLAG_ABSENT | QX_FLAG_SETVAR | QX_FLAG_RANGE,	NULL,	NULL,	blazer_process_setvar },
	{ "ups.delay.shutdown",		ST_FLAG_RW,	blazer_r_offdelay,	NULL,	"",	0,	0,	"",	0,	0,	DEFAULT_OFFDELAY,	QX_FLAG_ABSENT | QX_FLAG_SETVAR | QX_FLAG_RANGE,	NULL,	NULL,	blazer_process_setvar },

	/* End of structure. */
	{ NULL,				0,	NULL,	NULL,		"",	0,	0,	"",	0,	0,	NULL,	0,	NULL,	NULL,	NULL }
};

/* Testing table */
#ifdef TESTING
static testing_t	q1_testing[] = {
	{ "Q1\r",	"(215.0 195.0 230.0 014 49.0 22.7 30.0 00000000\r",	-1 },
	{ "QP\r",	"(40.0 70.0 180 264 EpbkcrafDo\r",	-1 },
	{ "Q6\r",	"(227.8 ---.- ---.- 49.9 219.8 ---.- ---.- 49.9 022 --- --- 039.9 ---.- 39.0 03980 100 35 00000000 00000000 11\r",	-1 },
	{ "S03\r",	"",	-1 },
	{ "C\r",	"",	-1 },
	{ "S02R0005\r",	"",	-1 },
	{ "S.5R0000\r",	"",	-1 },
	{ "T04\r",	"",	-1 },
	{ "TL\r",	"",	-1 },
	{ "T\r",	"",	-1 },
	{ "CT\r",	"",	-1 },
	{ NULL }
};
#endif	/* TESTING */

/* Subdriver-specific initups */
static void	q1_initups(void)
{
	blazer_initups_light(q1_qx2nut);
}

/* Subdriver interface */
subdriver_t	santak_castle_subdriver = {
	DRV_VERSION,
	blazer_claim_light,
	q1_qx2nut,
	q1_initups,
	NULL,
	blazer_makevartable_light,
	"ACK",
	"NAK",
#ifdef TESTING
	q1_testing,
#endif	/* TESTING */
};

static const char* status_list[] = {
	"disabled",
	"enabled",
	"unknown"
};

static int castle_process_status_bits(item_t* item, char* value, const size_t valuelen)
{
	const char* ptr = item->value;
	char interested;
	if (item->from == 19)
	{
		interested = 'p'; /* bypass */
	}
	else if (item->from == 20)
	{
		interested = 'b'; /* battery */
	}else
	{
		/* not supposed to be here */
		return -1;
	}

	int enabled = 0;
	int result = 2;
	while (*ptr)
	{
		if (*ptr == 'E')
			enabled = 1;
		else if (*ptr == 'D')
			enabled = 0;
		else if (*ptr == interested)
			result = enabled;
		++ptr;
	}

	snprintf(value, valuelen, "%s", status_list[result]);

	return 0;
}
