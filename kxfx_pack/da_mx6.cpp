// kX Driver / kX Driver Interface / kX Driver Effects Library
// Copyright (c) Eugene Gavrilov, LeMury 2003-2004.
// All rights reserved

/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

// Written by: LeMury

// 10kX microcode
// Patch name: 'mx6'

char *mx6_copyright="Copyright (c) LeMury, 2003-2004. All rights reserved.";
char *mx6_engine="kX";
char *mx6_comment="General Purpose Mixer v1.13b; $nobypass";
char *mx6_created="05/03/2004";
char *mx6_guid="1175058b-a0df-4960-bdfb-0d4d2b3fd750";

char *mx6_name="MX6";
int mx6_itramsize=0,mx6_xtramsize=0;

//PARAMS COUNT 
#define	_VOL1	0x8008	//slider
#define	_VOL2	0x8009	//slider
#define	_VOL3	0x800A	//slider
#define	_VOL4	0x800B	//slider
#define	_VOL5	0x800C	//slider
#define	_VOL6	0x800D	//slider
#define	_S1A	0x800E	//slider
#define	_S1B	0x800F	//slider
#define	_S2A	0x8010	//slider
#define	_S2B	0x8011	//slider
#define	_S3A	0x8012	//slider
#define	_S3B	0x8013	//slider
#define	_S4A	0x8014	//slider
#define	_S4B	0x8015	//slider
#define	_S5A	0x8016	//slider
#define	_S5B	0x8017	//slider
#define	_S6A	0x8018	//slider
#define	_S6B	0x8019	//slider

#define _L_INSTR 0	//offset = 0
#define _R_INSTR 34	//offset = 34

dsp_register_info mx6_info[]={
	{ "In1L",0x4000,0x7,0xffff,0x0 },
	{ "In1R",0x4001,0x7,0xffff,0x0 },
	{ "In2L",0x4002,0x7,0xffff,0x0 },
	{ "In2R",0x4003,0x7,0xffff,0x0 },
	{ "In3L",0x4004,0x7,0xffff,0x0 },
	{ "In3R",0x4005,0x7,0xffff,0x0 },
	{ "In4L",0x4006,0x7,0xffff,0x0 },
	{ "In4R",0x4007,0x7,0xffff,0x0 },
	{ "In5L",0x4008,0x7,0xffff,0x0 },
	{ "In5R",0x4009,0x7,0xffff,0x0 },
	{ "In6L",0x400a,0x7,0xffff,0x0 },
	{ "In6R",0x400b,0x7,0xffff,0x0 },
	{ "MainL",0x8000,0x8,0xffff,0x0 },
	{ "MainR",0x8001,0x8,0xffff,0x0 },
	{ "RecL",0x8002,0x8,0xffff,0x0 },
	{ "RecR",0x8003,0x8,0xffff,0x0 },
	{ "Send1L",0x8004,0x8,0xffff,0x0 },
	{ "Send1R",0x8005,0x8,0xffff,0x0 },
	{ "Send2L",0x8006,0x8,0xffff,0x0 },
	{ "Send2R",0x8007,0x8,0xffff,0x0 },
	{ "vol1",0x8008,0x1,0xffff,0x0 },
	{ "vol2",0x8009,0x1,0xffff,0x0 },
	{ "vol3",0x800a,0x1,0xffff,0x0 },
	{ "vol4",0x800b,0x1,0xffff,0x0 },
	{ "vol5",0x800c,0x1,0xffff,0x0 },
	{ "vol6",0x800d,0x1,0xffff,0x0 },
	{ "S1a",0x800e,0x1,0xffff,0x0 },
	{ "S1b",0x800f,0x1,0xffff,0x0 },
	{ "S2a",0x8010,0x1,0xffff,0x0 },
	{ "S2b",0x8011,0x1,0xffff,0x0 },
	{ "S3a",0x8012,0x1,0xffff,0x0 },
	{ "S3b",0x8013,0x1,0xffff,0x0 },
	{ "S4a",0x8014,0x1,0xffff,0x0 },
	{ "S4b",0x8015,0x1,0xffff,0x0 },
	{ "S5a",0x8016,0x1,0xffff,0x0 },
	{ "S5b",0x8017,0x1,0xffff,0x0 },
	{ "S6a",0x8018,0x1,0xffff,0x0 },
	{ "S6b",0x8019,0x1,0xffff,0x0 },
	{ "result_l",0x801a,0x1,0xffff,0x0 },
	{ "result_r",0x801b,0x1,0xffff,0x0 },
	{ "res",0x801c,0x1,0xffff,0x1f },
	{ "a",0x801d,0x3,0xffff,0x0 },
	{ "m",0x801e,0x3,0xffff,0x0 },
	{ "rc",0x801f,0x3,0xffff,0x0 },
	{ "fx1",0x8020,0x3,0xffff,0x0 },
	{ "fx2",0x8021,0x3,0xffff,0x0 },
};

dsp_code mx6_code[]={
	{ 0x0,0x801d,0x2040,0x4000,0x8008 },
	{ 0x0,0x801e,0x2040,0x801d,0x2040 },
	{ 0x0,0x801f,0x2040,0x801d,0x2040 },
	{ 0x0,0x8020,0x2040,0x801d,0x800e },
	{ 0x0,0x8021,0x2040,0x801d,0x800f },
	{ 0x0,0x801d,0x2040,0x4002,0x8009 },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8010 },
	{ 0x0,0x8021,0x8021,0x801d,0x8011 },
	{ 0x0,0x801d,0x2040,0x4004,0x800a },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8012 },
	{ 0x0,0x8021,0x8021,0x801d,0x8013 },
	{ 0x0,0x801d,0x2040,0x4006,0x800b },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8014 },
	{ 0x0,0x8021,0x8021,0x801d,0x8015 },
	{ 0x0,0x801d,0x2040,0x4008,0x800c },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8016 },
	{ 0x0,0x8021,0x8021,0x801d,0x8017 },
	{ 0x0,0x801d,0x2040,0x400a,0x800d },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8004,0x8020,0x801d,0x8018 },
	{ 0x0,0x8006,0x8021,0x801d,0x8019 },
	{ 0xe,0x8000,0x801e,0x2040,0x801f },
	{ 0xe,0x8002,0x801f,0x2040,0x801e },
	{ 0xc,0x801d,0x801f,0x801c,0x2041 },
	{ 0xa,0x801a,0x801d,0x801d,0x801a },
	{ 0x0,0x801d,0x2040,0x4001,0x8008 },
	{ 0x0,0x801e,0x2040,0x801d,0x2040 },
	{ 0x0,0x801f,0x2040,0x801d,0x2040 },
	{ 0x0,0x8020,0x2040,0x801d,0x800e },
	{ 0x0,0x8021,0x2040,0x801d,0x800f },
	{ 0x0,0x801d,0x2040,0x4003,0x8009 },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8010 },
	{ 0x0,0x8021,0x8021,0x801d,0x8011 },
	{ 0x0,0x801d,0x2040,0x4005,0x800a },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8012 },
	{ 0x0,0x8021,0x8021,0x801d,0x8013 },
	{ 0x0,0x801d,0x2040,0x4007,0x800b },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8014 },
	{ 0x0,0x8021,0x8021,0x801d,0x8015 },
	{ 0x0,0x801d,0x2040,0x4009,0x800c },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8020,0x8020,0x801d,0x8016 },
	{ 0x0,0x8021,0x8021,0x801d,0x8017 },
	{ 0x0,0x801d,0x2040,0x400b,0x800d },
	{ 0x0,0x801e,0x801e,0x801d,0x2040 },
	{ 0x0,0x801f,0x801f,0x801d,0x2040 },
	{ 0x0,0x8005,0x8020,0x801d,0x8018 },
	{ 0x0,0x8007,0x8021,0x801d,0x8019 },
	{ 0xe,0x8001,0x801e,0x2040,0x801f },
	{ 0xe,0x8003,0x801f,0x2040,0x801e },
	{ 0xc,0x801d,0x801f,0x801c,0x2041 },
	{ 0xa,0x801b,0x801d,0x801d,0x801b },
};

