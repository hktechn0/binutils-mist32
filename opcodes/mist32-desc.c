/* CPU data for mist32.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright 1996-2010 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#include "sysdep.h"
#include <stdio.h>
#include <stdarg.h>
#include "ansidecl.h"
#include "bfd.h"
#include "symcat.h"
#include "mist32-desc.h"
#include "mist32-opc.h"
#include "opintl.h"
#include "libiberty.h"
#include "xregex.h"

/* Attributes.  */

static const CGEN_ATTR_ENTRY bool_attr[] =
{
  { "#f", 0 },
  { "#t", 1 },
  { 0, 0 }
};

static const CGEN_ATTR_ENTRY MACH_attr[] ATTRIBUTE_UNUSED =
{
  { "base", MACH_BASE },
  { "mist32", MACH_MIST32 },
  { "max", MACH_MAX },
  { 0, 0 }
};

static const CGEN_ATTR_ENTRY ISA_attr[] ATTRIBUTE_UNUSED =
{
  { "mist32", ISA_MIST32 },
  { "max", ISA_MAX },
  { 0, 0 }
};

const CGEN_ATTR_TABLE mist32_cgen_ifield_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "PCREL-ADDR", &bool_attr[0], &bool_attr[0] },
  { "ABS-ADDR", &bool_attr[0], &bool_attr[0] },
  { "RESERVED", &bool_attr[0], &bool_attr[0] },
  { "SIGN-OPT", &bool_attr[0], &bool_attr[0] },
  { "SIGNED", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

const CGEN_ATTR_TABLE mist32_cgen_hardware_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "CACHE-ADDR", &bool_attr[0], &bool_attr[0] },
  { "PC", &bool_attr[0], &bool_attr[0] },
  { "PROFILE", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

const CGEN_ATTR_TABLE mist32_cgen_operand_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "PCREL-ADDR", &bool_attr[0], &bool_attr[0] },
  { "ABS-ADDR", &bool_attr[0], &bool_attr[0] },
  { "SIGN-OPT", &bool_attr[0], &bool_attr[0] },
  { "SIGNED", &bool_attr[0], &bool_attr[0] },
  { "NEGATIVE", &bool_attr[0], &bool_attr[0] },
  { "RELAX", &bool_attr[0], &bool_attr[0] },
  { "SEM-ONLY", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

const CGEN_ATTR_TABLE mist32_cgen_insn_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "ALIAS", &bool_attr[0], &bool_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "UNCOND-CTI", &bool_attr[0], &bool_attr[0] },
  { "COND-CTI", &bool_attr[0], &bool_attr[0] },
  { "SKIP-CTI", &bool_attr[0], &bool_attr[0] },
  { "DELAY-SLOT", &bool_attr[0], &bool_attr[0] },
  { "RELAXABLE", &bool_attr[0], &bool_attr[0] },
  { "RELAXED", &bool_attr[0], &bool_attr[0] },
  { "NO-DIS", &bool_attr[0], &bool_attr[0] },
  { "PBB", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

/* Instruction set variants.  */

static const CGEN_ISA mist32_cgen_isa_table[] = {
  { "mist32", 32, 32, 32, 32 },
  { 0, 0, 0, 0, 0 }
};

/* Machine variants.  */

static const CGEN_MACH mist32_cgen_mach_table[] = {
  { "mist32", "mist32", MACH_MIST32, 0 },
  { 0, 0, 0, 0 }
};

static CGEN_KEYWORD_ENTRY mist32_cgen_opval_h_gr_entries[] =
{
  { "rtmp", 7, {0, {{{0, 0}}}}, 0, 0 },
  { "rglobl", 29, {0, {{{0, 0}}}}, 0, 0 },
  { "rbase", 30, {0, {{{0, 0}}}}, 0, 0 },
  { "rret", 31, {0, {{{0, 0}}}}, 0, 0 },
  { "r0", 0, {0, {{{0, 0}}}}, 0, 0 },
  { "r1", 1, {0, {{{0, 0}}}}, 0, 0 },
  { "r2", 2, {0, {{{0, 0}}}}, 0, 0 },
  { "r3", 3, {0, {{{0, 0}}}}, 0, 0 },
  { "r4", 4, {0, {{{0, 0}}}}, 0, 0 },
  { "r5", 5, {0, {{{0, 0}}}}, 0, 0 },
  { "r6", 6, {0, {{{0, 0}}}}, 0, 0 },
  { "r7", 7, {0, {{{0, 0}}}}, 0, 0 },
  { "r8", 8, {0, {{{0, 0}}}}, 0, 0 },
  { "r9", 9, {0, {{{0, 0}}}}, 0, 0 },
  { "r10", 10, {0, {{{0, 0}}}}, 0, 0 },
  { "r11", 11, {0, {{{0, 0}}}}, 0, 0 },
  { "r12", 12, {0, {{{0, 0}}}}, 0, 0 },
  { "r13", 13, {0, {{{0, 0}}}}, 0, 0 },
  { "r14", 14, {0, {{{0, 0}}}}, 0, 0 },
  { "r15", 15, {0, {{{0, 0}}}}, 0, 0 },
  { "r16", 16, {0, {{{0, 0}}}}, 0, 0 },
  { "r17", 17, {0, {{{0, 0}}}}, 0, 0 },
  { "r18", 18, {0, {{{0, 0}}}}, 0, 0 },
  { "r19", 19, {0, {{{0, 0}}}}, 0, 0 },
  { "r20", 20, {0, {{{0, 0}}}}, 0, 0 },
  { "r21", 21, {0, {{{0, 0}}}}, 0, 0 },
  { "r22", 22, {0, {{{0, 0}}}}, 0, 0 },
  { "r23", 23, {0, {{{0, 0}}}}, 0, 0 },
  { "r24", 24, {0, {{{0, 0}}}}, 0, 0 },
  { "r25", 25, {0, {{{0, 0}}}}, 0, 0 },
  { "r26", 26, {0, {{{0, 0}}}}, 0, 0 },
  { "r27", 27, {0, {{{0, 0}}}}, 0, 0 },
  { "r28", 28, {0, {{{0, 0}}}}, 0, 0 },
  { "r29", 29, {0, {{{0, 0}}}}, 0, 0 },
  { "r30", 30, {0, {{{0, 0}}}}, 0, 0 },
  { "r31", 31, {0, {{{0, 0}}}}, 0, 0 }
};

CGEN_KEYWORD mist32_cgen_opval_h_gr =
{
  & mist32_cgen_opval_h_gr_entries[0],
  36,
  0, 0, 0, 0, ""
};

static CGEN_KEYWORD_ENTRY mist32_cgen_opval_h_cc_entries[] =
{
  { "#al", 0, {0, {{{0, 0}}}}, 0, 0 },
  { "#eq", 1, {0, {{{0, 0}}}}, 0, 0 },
  { "#z", 1, {0, {{{0, 0}}}}, 0, 0 },
  { "#ne", 2, {0, {{{0, 0}}}}, 0, 0 },
  { "#nz", 2, {0, {{{0, 0}}}}, 0, 0 },
  { "#neq", 2, {0, {{{0, 0}}}}, 0, 0 },
  { "#mi", 3, {0, {{{0, 0}}}}, 0, 0 },
  { "#pl", 4, {0, {{{0, 0}}}}, 0, 0 },
  { "#en", 5, {0, {{{0, 0}}}}, 0, 0 },
  { "#on", 6, {0, {{{0, 0}}}}, 0, 0 },
  { "#of", 7, {0, {{{0, 0}}}}, 0, 0 },
  { "#geu", 8, {0, {{{0, 0}}}}, 0, 0 },
  { "#c", 8, {0, {{{0, 0}}}}, 0, 0 },
  { "#ueo", 8, {0, {{{0, 0}}}}, 0, 0 },
  { "#ltu", 9, {0, {{{0, 0}}}}, 0, 0 },
  { "#nc", 9, {0, {{{0, 0}}}}, 0, 0 },
  { "#uu", 9, {0, {{{0, 0}}}}, 0, 0 },
  { "#gtu", 10, {0, {{{0, 0}}}}, 0, 0 },
  { "#uo", 10, {0, {{{0, 0}}}}, 0, 0 },
  { "#leu", 11, {0, {{{0, 0}}}}, 0, 0 },
  { "#ueu", 11, {0, {{{0, 0}}}}, 0, 0 },
  { "#ge", 12, {0, {{{0, 0}}}}, 0, 0 },
  { "#seo", 12, {0, {{{0, 0}}}}, 0, 0 },
  { "#lt", 13, {0, {{{0, 0}}}}, 0, 0 },
  { "#su", 13, {0, {{{0, 0}}}}, 0, 0 },
  { "#gt", 14, {0, {{{0, 0}}}}, 0, 0 },
  { "#so", 14, {0, {{{0, 0}}}}, 0, 0 },
  { "#le", 15, {0, {{{0, 0}}}}, 0, 0 },
  { "#seu", 15, {0, {{{0, 0}}}}, 0, 0 }
};

CGEN_KEYWORD mist32_cgen_opval_h_cc =
{
  & mist32_cgen_opval_h_cc_entries[0],
  29,
  0, 0, 0, 0, ""
};


/* The hardware table.  */

#define A(a) (1 << CGEN_HW_##a)

const CGEN_HW_ENTRY mist32_cgen_hw_table[] =
{
  { "h-memory", HW_H_MEMORY, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-sint", HW_H_SINT, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint", HW_H_UINT, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-addr", HW_H_ADDR, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-iaddr", HW_H_IADDR, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-pc", HW_H_PC, CGEN_ASM_NONE, 0, { 0|A(PC), { { { (1<<MACH_BASE), 0 } } } } },
  { "h-gr", HW_H_GR, CGEN_ASM_KEYWORD, (PTR) & mist32_cgen_opval_h_gr, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-int11", HW_H_INT11, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint11", HW_H_UINT11, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-int16", HW_H_INT16, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint16", HW_H_UINT16, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-cc", HW_H_CC, CGEN_ASM_KEYWORD, (PTR) & mist32_cgen_opval_h_cc, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { 0, 0, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } }
};

#undef A


/* The instruction field table.  */

#define A(a) (1 << CGEN_IFLD_##a)

const CGEN_IFLD mist32_cgen_ifld_table[] =
{
  { MIST32_F_NIL, "f-nil", 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_ANYOF, "f-anyof", 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_EXT, "f-ext", 0, 32, 31, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_OP, "f-op", 0, 32, 30, 10, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_ISIMM, "f-isimm", 0, 32, 20, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_AFE, "f-afe", 0, 32, 19, 4, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_CC, "f-cc", 0, 32, 19, 4, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_RD, "f-rd", 0, 32, 9, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_RS, "f-rs", 0, 32, 4, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I11H, "f-i11h", 0, 32, 15, 6, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I11L, "f-i11l", 0, 32, 4, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I11, "f-i11", 0, 0, 0, 0,{ 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_UI11, "f-ui11", 0, 0, 0, 0,{ 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I11W, "f-i11w", 0, 0, 0, 0,{ 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P11HI, "f-p11hi", 0, 32, 15, 6, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P11LO, "f-p11lo", 0, 32, 4, 5, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P11B, "f-p11b", 0, 0, 0, 0,{ 0|A(ABS_ADDR)|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P11H, "f-p11h", 0, 0, 0, 0,{ 0|A(ABS_ADDR)|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P11W, "f-p11w", 0, 0, 0, 0,{ 0|A(ABS_ADDR)|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I16H, "f-i16h", 0, 32, 20, 11, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I16L, "f-i16l", 0, 32, 4, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_I16, "f-i16", 0, 0, 0, 0,{ 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_UI16, "f-ui16", 0, 0, 0, 0,{ 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P16, "f-p16", 0, 32, 15, 16, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_UP16R, "f-up16r", 0, 32, 15, 16, { 0|A(PCREL_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_P16R, "f-p16r", 0, 32, 15, 16, { 0|A(PCREL_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_RESERVE1, "f-reserve1", 0, 32, 15, 6, { 0|A(RESERVED), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_RESERVE2, "f-reserve2", 0, 32, 9, 5, { 0|A(RESERVED), { { { (1<<MACH_BASE), 0 } } } }  },
  { MIST32_F_RESERVE3, "f-reserve3", 0, 32, 4, 5, { 0|A(RESERVED), { { { (1<<MACH_BASE), 0 } } } }  },
  { 0, 0, 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } }
};

#undef A



/* multi ifield declarations */

const CGEN_MAYBE_MULTI_IFLD MIST32_F_I11_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_UI11_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_I11W_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_P11B_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_P11H_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_P11W_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_I16_MULTI_IFIELD [];
const CGEN_MAYBE_MULTI_IFLD MIST32_F_UI16_MULTI_IFIELD [];


/* multi ifield definitions */

const CGEN_MAYBE_MULTI_IFLD MIST32_F_I11_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I11H] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I11L] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_UI11_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I11H] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I11L] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_I11W_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I11H] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I11L] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_P11B_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P11HI] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P11LO] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_P11H_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P11HI] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P11LO] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_P11W_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P11HI] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P11LO] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_I16_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I16H] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I16L] } },
    { 0, { (const PTR) 0 } }
};
const CGEN_MAYBE_MULTI_IFLD MIST32_F_UI16_MULTI_IFIELD [] =
{
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I16H] } },
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_I16L] } },
    { 0, { (const PTR) 0 } }
};

/* The operand table.  */

#define A(a) (1 << CGEN_OPERAND_##a)
#define OPERAND(op) MIST32_OPERAND_##op

const CGEN_OPERAND mist32_cgen_operand_table[] =
{
/* pc: program counter */
  { "pc", MIST32_OPERAND_PC, HW_H_PC, 0, 0,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_NIL] } }, 
    { 0|A(SEM_ONLY), { { { (1<<MACH_BASE), 0 } } } }  },
/* rd: destination register */
  { "rd", MIST32_OPERAND_RD, HW_H_GR, 9, 5,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_RD] } }, 
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* rs: source register */
  { "rs", MIST32_OPERAND_RS, HW_H_GR, 4, 5,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_RS] } }, 
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* cc: condition code */
  { "cc", MIST32_OPERAND_CC, HW_H_CC, 19, 4,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_CC] } }, 
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* p16: 16bit absolute unsigned address */
  { "p16", MIST32_OPERAND_P16, HW_H_IADDR, 15, 16,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P16] } }, 
    { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* up16r: 16bit relative unsigned address */
  { "up16r", MIST32_OPERAND_UP16R, HW_H_IADDR, 15, 16,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_UP16R] } }, 
    { 0|A(PCREL_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* p16r: 16bit relative address */
  { "p16r", MIST32_OPERAND_P16R, HW_H_IADDR, 15, 16,
    { 0, { (const PTR) &mist32_cgen_ifld_table[MIST32_F_P16R] } }, 
    { 0|A(PCREL_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* p11b: 11bit byte align address */
  { "p11b", MIST32_OPERAND_P11B, HW_H_IADDR, 4, 11,
    { 2, { (const PTR) &MIST32_F_P11B_MULTI_IFIELD[0] } }, 
    { 0|A(ABS_ADDR)|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* p11h: 11bit half word align address */
  { "p11h", MIST32_OPERAND_P11H, HW_H_IADDR, 4, 11,
    { 2, { (const PTR) &MIST32_F_P11H_MULTI_IFIELD[0] } }, 
    { 0|A(ABS_ADDR)|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* p11w: 11bit word align address */
  { "p11w", MIST32_OPERAND_P11W, HW_H_IADDR, 4, 11,
    { 2, { (const PTR) &MIST32_F_P11W_MULTI_IFIELD[0] } }, 
    { 0|A(ABS_ADDR)|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* i11: 11bit immediate */
  { "i11", MIST32_OPERAND_I11, HW_H_INT11, 4, 11,
    { 2, { (const PTR) &MIST32_F_I11_MULTI_IFIELD[0] } }, 
    { 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* ui11: 11bit unsigned immediate */
  { "ui11", MIST32_OPERAND_UI11, HW_H_UINT11, 4, 11,
    { 2, { (const PTR) &MIST32_F_UI11_MULTI_IFIELD[0] } }, 
    { 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* i11w: 11bit word align immediate */
  { "i11w", MIST32_OPERAND_I11W, HW_H_INT11, 4, 11,
    { 2, { (const PTR) &MIST32_F_I11W_MULTI_IFIELD[0] } }, 
    { 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* i16l: 16 bit immediate, lo */
  { "i16l", MIST32_OPERAND_I16L, HW_H_INT16, 4, 16,
    { 2, { (const PTR) &MIST32_F_I16_MULTI_IFIELD[0] } }, 
    { 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* ui16l: 16 bit unsigned immediate, lo */
  { "ui16l", MIST32_OPERAND_UI16L, HW_H_UINT16, 4, 16,
    { 2, { (const PTR) &MIST32_F_UI16_MULTI_IFIELD[0] } }, 
    { 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* i16h: 16 bit immediate, hi */
  { "i16h", MIST32_OPERAND_I16H, HW_H_UINT16, 4, 16,
    { 2, { (const PTR) &MIST32_F_UI16_MULTI_IFIELD[0] } }, 
    { 0|A(VIRTUAL), { { { (1<<MACH_BASE), 0 } } } }  },
/* i32: 32bit immediate for li */
  { "i32", MIST32_OPERAND_I32, HW_H_UINT, 0, 0,
    { 0, { (const PTR) 0 } }, 
    { 0|A(SEM_ONLY), { { { (1<<MACH_BASE), 0 } } } }  },
/* sentinel */
  { 0, 0, 0, 0, 0,
    { 0, { (const PTR) 0 } },
    { 0, { { { (1<<MACH_BASE), 0 } } } } }
};

#undef A


/* The instruction table.  */

#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))
#define A(a) (1 << CGEN_INSN_##a)

static const CGEN_IBASE mist32_cgen_insn_table[MAX_INSNS] =
{
  /* Special null first entry.
     A `num' value of zero is thus invalid.
     Also, the special `invalid' insn resides here.  */
  { 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
/* add $rd,$rs */
  {
    MIST32_INSN_ADD, "add", "add", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* add $rd,$i11 */
  {
    MIST32_INSN_ADDI, "addi", "add", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sub $rd,$rs */
  {
    MIST32_INSN_SUB, "sub", "sub", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sub $rd,$i11 */
  {
    MIST32_INSN_SUBI, "subi", "sub", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mull $rd,$rs */
  {
    MIST32_INSN_MULL, "mull", "mull", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mull $rd,$i11 */
  {
    MIST32_INSN_MULLI, "mulli", "mull", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mulh $rd,$rs */
  {
    MIST32_INSN_MULH, "mulh", "mulh", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mulh $rd,$i11 */
  {
    MIST32_INSN_MULHI, "mulhi", "mulh", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* udiv $rd,$rs */
  {
    MIST32_INSN_UDIV, "udiv", "udiv", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* udiv $rd,$ui11 */
  {
    MIST32_INSN_UDIVI, "udivi", "udiv", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* umod $rd,$rs */
  {
    MIST32_INSN_UMOD, "umod", "umod", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* umod $rd,$ui11 */
  {
    MIST32_INSN_UMODI, "umodi", "umod", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* cmp $rd,$rs */
  {
    MIST32_INSN_CMP, "cmp", "cmp", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* cmp $rd,$i11 */
  {
    MIST32_INSN_CMPI, "cmpi", "cmp", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* div $rd,$rs */
  {
    MIST32_INSN_DIV, "div", "div", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* div $rd,$i11 */
  {
    MIST32_INSN_DIVI, "divi", "div", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mod $rd,$rs */
  {
    MIST32_INSN_MOD, "mod", "mod", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mod $rd,$i11 */
  {
    MIST32_INSN_MODI, "modi", "mod", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* neg $rd,$rs */
  {
    MIST32_INSN_NEG, "neg", "neg", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* addc $rd,$rs */
  {
    MIST32_INSN_ADDC, "addc", "addc", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* inc $rd,$rs */
  {
    MIST32_INSN_INC, "inc", "inc", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* dec $rd,$rs */
  {
    MIST32_INSN_DEC, "dec", "dec", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sext8 $rd,$rs */
  {
    MIST32_INSN_SEXT8, "sext8", "sext8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sext16 $rd,$rs */
  {
    MIST32_INSN_SEXT16, "sext16", "sext16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* shl $rd,$rs */
  {
    MIST32_INSN_SHL, "shl", "shl", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* shl $rd,$ui11 */
  {
    MIST32_INSN_SHLI, "shli", "shl", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* shr $rd,$rs */
  {
    MIST32_INSN_SHR, "shr", "shr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* shr $rd,$ui11 */
  {
    MIST32_INSN_SHRI, "shri", "shr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sar $rd,$rs */
  {
    MIST32_INSN_SAR, "sar", "sar", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sar $rd,$ui11 */
  {
    MIST32_INSN_SARI, "sari", "sar", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* rol $rd,$rs */
  {
    MIST32_INSN_ROL, "rol", "rol", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* rol $rd,$ui11 */
  {
    MIST32_INSN_ROLI, "roli", "rol", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ror $rd,$rs */
  {
    MIST32_INSN_ROR, "ror", "ror", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ror $rd,$ui11 */
  {
    MIST32_INSN_RORI, "rori", "ror", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* and $rd,$rs */
  {
    MIST32_INSN_AND, "and", "and", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* or $rd,$rs */
  {
    MIST32_INSN_OR, "or", "or", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* xor $rd,$rs */
  {
    MIST32_INSN_XOR, "xor", "xor", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* not $rd,$rs */
  {
    MIST32_INSN_NOT, "not", "not", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* nand $rd,$rs */
  {
    MIST32_INSN_NAND, "nand", "nand", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* nor $rd,$rs */
  {
    MIST32_INSN_NOR, "nor", "nor", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* xnor $rd,$rs */
  {
    MIST32_INSN_XNOR, "xnor", "xnor", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* test $rd,$rs */
  {
    MIST32_INSN_TEST, "test", "test", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* wl16 $rd,$ui16l */
  {
    MIST32_INSN_WL16, "wl16", "wl16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* wh16 $rd,$i16h */
  {
    MIST32_INSN_WH16, "wh16", "wh16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* clrb $rd,$ui11 */
  {
    MIST32_INSN_CLRB, "clrb", "clrb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* setb $rd,$ui11 */
  {
    MIST32_INSN_SETB, "setb", "setb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* clr $rd */
  {
    MIST32_INSN_CLR, "clr", "clr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* set $rd */
  {
    MIST32_INSN_SET, "set", "set", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* revb $rd,$rs */
  {
    MIST32_INSN_REVB, "revb", "revb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* rev8 $rd,$rs */
  {
    MIST32_INSN_REV8, "rev8", "rev8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* getb $rd,$rs */
  {
    MIST32_INSN_GETB, "getb", "getb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* getb $rd,$ui11 */
  {
    MIST32_INSN_GETBI, "getbi", "getb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* get8 $rd,$rs */
  {
    MIST32_INSN_GET8, "get8", "get8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* get8 $rd,$ui11 */
  {
    MIST32_INSN_GET8I, "get8i", "get8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lil $rd,$i16l */
  {
    MIST32_INSN_LIL, "lil", "lil", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lih $rd,$i16h */
  {
    MIST32_INSN_LIH, "lih", "lih", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ulil $rd,$ui16l */
  {
    MIST32_INSN_ULIL, "ulil", "ulil", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ld8 $rd,$rs */
  {
    MIST32_INSN_LD8, "ld8", "ld8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ld8 $rd,$p11b */
  {
    MIST32_INSN_LD8I, "ld8i", "ld8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ld16 $rd,$rs */
  {
    MIST32_INSN_LD16, "ld16", "ld16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ld16 $rd,$p11h */
  {
    MIST32_INSN_LD16I, "ld16i", "ld16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ld32 $rd,$rs */
  {
    MIST32_INSN_LD32, "ld32", "ld32", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ld32 $rd,$p11w */
  {
    MIST32_INSN_LD32I, "ld32i", "ld32", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* st8 $rd,$rs */
  {
    MIST32_INSN_ST8, "st8", "st8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* st8 $rd,$p11b */
  {
    MIST32_INSN_ST8I, "st8i", "st8", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* st16 $rd,$rs */
  {
    MIST32_INSN_ST16, "st16", "st16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* st16 $rd,$p11h */
  {
    MIST32_INSN_ST16I, "st16i", "st16", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* st32 $rd,$rs */
  {
    MIST32_INSN_ST32, "st32", "st32", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* st32 $rd,$p11w */
  {
    MIST32_INSN_ST32I, "st32i", "st32", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* push $rd */
  {
    MIST32_INSN_PUSH, "push", "push", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* pushpc */
  {
    MIST32_INSN_PUSHPC, "pushpc", "pushpc", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* pop $rd */
  {
    MIST32_INSN_POP, "pop", "pop", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bur $rd,$cc */
  {
    MIST32_INSN_BUR, "bur", "bur", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bur $up16r,$cc */
  {
    MIST32_INSN_BURI, "buri", "bur", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* br $rd,$cc */
  {
    MIST32_INSN_BR, "br", "br", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* br $p16r,$cc */
  {
    MIST32_INSN_BRI, "bri", "br", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* b $rd,$cc */
  {
    MIST32_INSN_B, "b", "b", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* b $p16,$cc */
  {
    MIST32_INSN_BI, "bi", "b", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ib */
  {
    MIST32_INSN_IB, "ib", "ib", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* burn $rd,$cc */
  {
    MIST32_INSN_BURN, "burn", "burn", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* burn $up16r,$cc */
  {
    MIST32_INSN_BURNI, "burni", "burn", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* brn $rd,$cc */
  {
    MIST32_INSN_BRN, "brn", "brn", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* brn $p16r,$cc */
  {
    MIST32_INSN_BRNI, "brni", "brn", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bn $rd,$cc */
  {
    MIST32_INSN_BN, "bn", "bn", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bn $p16,$cc */
  {
    MIST32_INSN_BNI, "bni", "bn", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srspr $rd */
  {
    MIST32_INSN_SRSPR, "srspr", "srspr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpdtr $rd */
  {
    MIST32_INSN_SRPDTR, "srpdtr", "srpdtr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpidr $rd */
  {
    MIST32_INSN_SRPIDR, "srpidr", "srpidr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srcidr $rd */
  {
    MIST32_INSN_SRCIDR, "srcidr", "srcidr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srmoder $rd */
  {
    MIST32_INSN_SRMODER, "srmoder", "srmoder", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srieir $rd */
  {
    MIST32_INSN_SRIEIR, "srieir", "srieir", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srtisr $rd */
  {
    MIST32_INSN_SRTISR, "srtisr", "srtisr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srkpdtr $rd */
  {
    MIST32_INSN_SRKPDTR, "srkpdtr", "srkpdtr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srmmur $rd */
  {
    MIST32_INSN_SRMMUR, "srmmur", "srmmur", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sriosr $rd */
  {
    MIST32_INSN_SRIOSR, "sriosr", "sriosr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srtidr $rd */
  {
    MIST32_INSN_SRTIDR, "srtidr", "srtidr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srppsr $rd */
  {
    MIST32_INSN_SRPPSR, "srppsr", "srppsr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srppcr $rd */
  {
    MIST32_INSN_SRPPCR, "srppcr", "srppcr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srppdtr $rd */
  {
    MIST32_INSN_SRPPDTR, "srppdtr", "srppdtr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srptidr $rd */
  {
    MIST32_INSN_SRPTIDR, "srptidr", "srptidr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpsr $rd */
  {
    MIST32_INSN_SRPSR, "srpsr", "srpsr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srfrcr */
  {
    MIST32_INSN_SRFRCR, "srfrcr", "srfrcr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srfrclr $rd */
  {
    MIST32_INSN_SRFRCLR, "srfrclr", "srfrclr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srfrchr $rd */
  {
    MIST32_INSN_SRFRCHR, "srfrchr", "srfrchr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpflagr $rd */
  {
    MIST32_INSN_SRPFLAGR, "srpflagr", "srpflagr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srspw $rd */
  {
    MIST32_INSN_SRSPW, "srspw", "srspw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpdtw $rd */
  {
    MIST32_INSN_SRPDTW, "srpdtw", "srpdtw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srieiw $rd */
  {
    MIST32_INSN_SRIEIW, "srieiw", "srieiw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srieiw $ui11 */
  {
    MIST32_INSN_SRIEIWI, "srieiwi", "srieiw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srtisw $rd */
  {
    MIST32_INSN_SRTISW, "srtisw", "srtisw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srkpdtw $rd */
  {
    MIST32_INSN_SRKPDTW, "srkpdtw", "srkpdtw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srmmuw $rd */
  {
    MIST32_INSN_SRMMUW, "srmmuw", "srmmuw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srmmuw $ui11 */
  {
    MIST32_INSN_SRMMUWI, "srmmuwi", "srmmuw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srppsw $rd */
  {
    MIST32_INSN_SRPPSW, "srppsw", "srppsw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srppcw $rd */
  {
    MIST32_INSN_SRPPCW, "srppcw", "srppcw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srppdtw $rd */
  {
    MIST32_INSN_SRPPDTW, "srppdtw", "srppdtw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srptidw $rd */
  {
    MIST32_INSN_SRPTIDW, "srptidw", "srptidw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sridtw $rd */
  {
    MIST32_INSN_SRIDTW, "sridtw", "sridtw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpsw $rd */
  {
    MIST32_INSN_SRPSW, "srpsw", "srpsw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srfrcw */
  {
    MIST32_INSN_SRFRCW, "srfrcw", "srfrcw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srfrclw $rd */
  {
    MIST32_INSN_SRFRCLW, "srfrclw", "srfrclw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srfrchw $rd */
  {
    MIST32_INSN_SRFRCHW, "srfrchw", "srfrchw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srpflagw $rd */
  {
    MIST32_INSN_SRPFLAGW, "srpflagw", "srpflagw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srspadd $p16 */
  {
    MIST32_INSN_SRSPADD, "srspadd", "srspadd", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* nop */
  {
    MIST32_INSN_NOP, "nop", "nop", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* halt */
  {
    MIST32_INSN_HALT, "halt", "halt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* move $rd,$rs */
  {
    MIST32_INSN_MOVE, "move", "move", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* movepc $rd,$rs */
  {
    MIST32_INSN_MOVEPC, "movepc", "movepc", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* movepc $rd,$i11w */
  {
    MIST32_INSN_MOVEPCI, "movepci", "movepc", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* swi $rd */
  {
    MIST32_INSN_SWI, "swi", "swi", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* swi $ui11 */
  {
    MIST32_INSN_SWII, "swii", "swi", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* tas $rd,$rs */
  {
    MIST32_INSN_TAS, "tas", "tas", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* tas $rd,$p11w */
  {
    MIST32_INSN_TASI, "tasi", "tas", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* idts */
  {
    MIST32_INSN_IDTS, "idts", "idts", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
};

#undef OP
#undef A

/* Initialize anything needed to be done once, before any cpu_open call.  */

static void
init_tables (void)
{
}

static const CGEN_MACH * lookup_mach_via_bfd_name (const CGEN_MACH *, const char *);
static void build_hw_table      (CGEN_CPU_TABLE *);
static void build_ifield_table  (CGEN_CPU_TABLE *);
static void build_operand_table (CGEN_CPU_TABLE *);
static void build_insn_table    (CGEN_CPU_TABLE *);
static void mist32_cgen_rebuild_tables (CGEN_CPU_TABLE *);

/* Subroutine of mist32_cgen_cpu_open to look up a mach via its bfd name.  */

static const CGEN_MACH *
lookup_mach_via_bfd_name (const CGEN_MACH *table, const char *name)
{
  while (table->name)
    {
      if (strcmp (name, table->bfd_name) == 0)
	return table;
      ++table;
    }
  abort ();
}

/* Subroutine of mist32_cgen_cpu_open to build the hardware table.  */

static void
build_hw_table (CGEN_CPU_TABLE *cd)
{
  int i;
  int machs = cd->machs;
  const CGEN_HW_ENTRY *init = & mist32_cgen_hw_table[0];
  /* MAX_HW is only an upper bound on the number of selected entries.
     However each entry is indexed by it's enum so there can be holes in
     the table.  */
  const CGEN_HW_ENTRY **selected =
    (const CGEN_HW_ENTRY **) xmalloc (MAX_HW * sizeof (CGEN_HW_ENTRY *));

  cd->hw_table.init_entries = init;
  cd->hw_table.entry_size = sizeof (CGEN_HW_ENTRY);
  memset (selected, 0, MAX_HW * sizeof (CGEN_HW_ENTRY *));
  /* ??? For now we just use machs to determine which ones we want.  */
  for (i = 0; init[i].name != NULL; ++i)
    if (CGEN_HW_ATTR_VALUE (&init[i], CGEN_HW_MACH)
	& machs)
      selected[init[i].type] = &init[i];
  cd->hw_table.entries = selected;
  cd->hw_table.num_entries = MAX_HW;
}

/* Subroutine of mist32_cgen_cpu_open to build the hardware table.  */

static void
build_ifield_table (CGEN_CPU_TABLE *cd)
{
  cd->ifld_table = & mist32_cgen_ifld_table[0];
}

/* Subroutine of mist32_cgen_cpu_open to build the hardware table.  */

static void
build_operand_table (CGEN_CPU_TABLE *cd)
{
  int i;
  int machs = cd->machs;
  const CGEN_OPERAND *init = & mist32_cgen_operand_table[0];
  /* MAX_OPERANDS is only an upper bound on the number of selected entries.
     However each entry is indexed by it's enum so there can be holes in
     the table.  */
  const CGEN_OPERAND **selected = xmalloc (MAX_OPERANDS * sizeof (* selected));

  cd->operand_table.init_entries = init;
  cd->operand_table.entry_size = sizeof (CGEN_OPERAND);
  memset (selected, 0, MAX_OPERANDS * sizeof (CGEN_OPERAND *));
  /* ??? For now we just use mach to determine which ones we want.  */
  for (i = 0; init[i].name != NULL; ++i)
    if (CGEN_OPERAND_ATTR_VALUE (&init[i], CGEN_OPERAND_MACH)
	& machs)
      selected[init[i].type] = &init[i];
  cd->operand_table.entries = selected;
  cd->operand_table.num_entries = MAX_OPERANDS;
}

/* Subroutine of mist32_cgen_cpu_open to build the hardware table.
   ??? This could leave out insns not supported by the specified mach/isa,
   but that would cause errors like "foo only supported by bar" to become
   "unknown insn", so for now we include all insns and require the app to
   do the checking later.
   ??? On the other hand, parsing of such insns may require their hardware or
   operand elements to be in the table [which they mightn't be].  */

static void
build_insn_table (CGEN_CPU_TABLE *cd)
{
  int i;
  const CGEN_IBASE *ib = & mist32_cgen_insn_table[0];
  CGEN_INSN *insns = xmalloc (MAX_INSNS * sizeof (CGEN_INSN));

  memset (insns, 0, MAX_INSNS * sizeof (CGEN_INSN));
  for (i = 0; i < MAX_INSNS; ++i)
    insns[i].base = &ib[i];
  cd->insn_table.init_entries = insns;
  cd->insn_table.entry_size = sizeof (CGEN_IBASE);
  cd->insn_table.num_init_entries = MAX_INSNS;
}

/* Subroutine of mist32_cgen_cpu_open to rebuild the tables.  */

static void
mist32_cgen_rebuild_tables (CGEN_CPU_TABLE *cd)
{
  int i;
  CGEN_BITSET *isas = cd->isas;
  unsigned int machs = cd->machs;

  cd->int_insn_p = CGEN_INT_INSN_P;

  /* Data derived from the isa spec.  */
#define UNSET (CGEN_SIZE_UNKNOWN + 1)
  cd->default_insn_bitsize = UNSET;
  cd->base_insn_bitsize = UNSET;
  cd->min_insn_bitsize = 65535; /* Some ridiculously big number.  */
  cd->max_insn_bitsize = 0;
  for (i = 0; i < MAX_ISAS; ++i)
    if (cgen_bitset_contains (isas, i))
      {
	const CGEN_ISA *isa = & mist32_cgen_isa_table[i];

	/* Default insn sizes of all selected isas must be
	   equal or we set the result to 0, meaning "unknown".  */
	if (cd->default_insn_bitsize == UNSET)
	  cd->default_insn_bitsize = isa->default_insn_bitsize;
	else if (isa->default_insn_bitsize == cd->default_insn_bitsize)
	  ; /* This is ok.  */
	else
	  cd->default_insn_bitsize = CGEN_SIZE_UNKNOWN;

	/* Base insn sizes of all selected isas must be equal
	   or we set the result to 0, meaning "unknown".  */
	if (cd->base_insn_bitsize == UNSET)
	  cd->base_insn_bitsize = isa->base_insn_bitsize;
	else if (isa->base_insn_bitsize == cd->base_insn_bitsize)
	  ; /* This is ok.  */
	else
	  cd->base_insn_bitsize = CGEN_SIZE_UNKNOWN;

	/* Set min,max insn sizes.  */
	if (isa->min_insn_bitsize < cd->min_insn_bitsize)
	  cd->min_insn_bitsize = isa->min_insn_bitsize;
	if (isa->max_insn_bitsize > cd->max_insn_bitsize)
	  cd->max_insn_bitsize = isa->max_insn_bitsize;
      }

  /* Data derived from the mach spec.  */
  for (i = 0; i < MAX_MACHS; ++i)
    if (((1 << i) & machs) != 0)
      {
	const CGEN_MACH *mach = & mist32_cgen_mach_table[i];

	if (mach->insn_chunk_bitsize != 0)
	{
	  if (cd->insn_chunk_bitsize != 0 && cd->insn_chunk_bitsize != mach->insn_chunk_bitsize)
	    {
	      fprintf (stderr, "mist32_cgen_rebuild_tables: conflicting insn-chunk-bitsize values: `%d' vs. `%d'\n",
		       cd->insn_chunk_bitsize, mach->insn_chunk_bitsize);
	      abort ();
	    }

 	  cd->insn_chunk_bitsize = mach->insn_chunk_bitsize;
	}
      }

  /* Determine which hw elements are used by MACH.  */
  build_hw_table (cd);

  /* Build the ifield table.  */
  build_ifield_table (cd);

  /* Determine which operands are used by MACH/ISA.  */
  build_operand_table (cd);

  /* Build the instruction table.  */
  build_insn_table (cd);
}

/* Initialize a cpu table and return a descriptor.
   It's much like opening a file, and must be the first function called.
   The arguments are a set of (type/value) pairs, terminated with
   CGEN_CPU_OPEN_END.

   Currently supported values:
   CGEN_CPU_OPEN_ISAS:    bitmap of values in enum isa_attr
   CGEN_CPU_OPEN_MACHS:   bitmap of values in enum mach_attr
   CGEN_CPU_OPEN_BFDMACH: specify 1 mach using bfd name
   CGEN_CPU_OPEN_ENDIAN:  specify endian choice
   CGEN_CPU_OPEN_END:     terminates arguments

   ??? Simultaneous multiple isas might not make sense, but it's not (yet)
   precluded.  */

CGEN_CPU_DESC
mist32_cgen_cpu_open (enum cgen_cpu_open_arg arg_type, ...)
{
  CGEN_CPU_TABLE *cd = (CGEN_CPU_TABLE *) xmalloc (sizeof (CGEN_CPU_TABLE));
  static int init_p;
  CGEN_BITSET *isas = 0;  /* 0 = "unspecified" */
  unsigned int machs = 0; /* 0 = "unspecified" */
  enum cgen_endian endian = CGEN_ENDIAN_UNKNOWN;
  va_list ap;

  if (! init_p)
    {
      init_tables ();
      init_p = 1;
    }

  memset (cd, 0, sizeof (*cd));

  va_start (ap, arg_type);
  while (arg_type != CGEN_CPU_OPEN_END)
    {
      switch (arg_type)
	{
	case CGEN_CPU_OPEN_ISAS :
	  isas = va_arg (ap, CGEN_BITSET *);
	  break;
	case CGEN_CPU_OPEN_MACHS :
	  machs = va_arg (ap, unsigned int);
	  break;
	case CGEN_CPU_OPEN_BFDMACH :
	  {
	    const char *name = va_arg (ap, const char *);
	    const CGEN_MACH *mach =
	      lookup_mach_via_bfd_name (mist32_cgen_mach_table, name);

	    machs |= 1 << mach->num;
	    break;
	  }
	case CGEN_CPU_OPEN_ENDIAN :
	  endian = va_arg (ap, enum cgen_endian);
	  break;
	default :
	  fprintf (stderr, "mist32_cgen_cpu_open: unsupported argument `%d'\n",
		   arg_type);
	  abort (); /* ??? return NULL? */
	}
      arg_type = va_arg (ap, enum cgen_cpu_open_arg);
    }
  va_end (ap);

  /* Mach unspecified means "all".  */
  if (machs == 0)
    machs = (1 << MAX_MACHS) - 1;
  /* Base mach is always selected.  */
  machs |= 1;
  if (endian == CGEN_ENDIAN_UNKNOWN)
    {
      /* ??? If target has only one, could have a default.  */
      fprintf (stderr, "mist32_cgen_cpu_open: no endianness specified\n");
      abort ();
    }

  cd->isas = cgen_bitset_copy (isas);
  cd->machs = machs;
  cd->endian = endian;
  /* FIXME: for the sparc case we can determine insn-endianness statically.
     The worry here is where both data and insn endian can be independently
     chosen, in which case this function will need another argument.
     Actually, will want to allow for more arguments in the future anyway.  */
  cd->insn_endian = endian;

  /* Table (re)builder.  */
  cd->rebuild_tables = mist32_cgen_rebuild_tables;
  mist32_cgen_rebuild_tables (cd);

  /* Default to not allowing signed overflow.  */
  cd->signed_overflow_ok_p = 0;
  
  return (CGEN_CPU_DESC) cd;
}

/* Cover fn to mist32_cgen_cpu_open to handle the simple case of 1 isa, 1 mach.
   MACH_NAME is the bfd name of the mach.  */

CGEN_CPU_DESC
mist32_cgen_cpu_open_1 (const char *mach_name, enum cgen_endian endian)
{
  return mist32_cgen_cpu_open (CGEN_CPU_OPEN_BFDMACH, mach_name,
			       CGEN_CPU_OPEN_ENDIAN, endian,
			       CGEN_CPU_OPEN_END);
}

/* Close a cpu table.
   ??? This can live in a machine independent file, but there's currently
   no place to put this file (there's no libcgen).  libopcodes is the wrong
   place as some simulator ports use this but they don't use libopcodes.  */

void
mist32_cgen_cpu_close (CGEN_CPU_DESC cd)
{
  unsigned int i;
  const CGEN_INSN *insns;

  if (cd->macro_insn_table.init_entries)
    {
      insns = cd->macro_insn_table.init_entries;
      for (i = 0; i < cd->macro_insn_table.num_init_entries; ++i, ++insns)
	if (CGEN_INSN_RX ((insns)))
	  regfree (CGEN_INSN_RX (insns));
    }

  if (cd->insn_table.init_entries)
    {
      insns = cd->insn_table.init_entries;
      for (i = 0; i < cd->insn_table.num_init_entries; ++i, ++insns)
	if (CGEN_INSN_RX (insns))
	  regfree (CGEN_INSN_RX (insns));
    }  

  if (cd->macro_insn_table.init_entries)
    free ((CGEN_INSN *) cd->macro_insn_table.init_entries);

  if (cd->insn_table.init_entries)
    free ((CGEN_INSN *) cd->insn_table.init_entries);

  if (cd->hw_table.entries)
    free ((CGEN_HW_ENTRY *) cd->hw_table.entries);

  if (cd->operand_table.entries)
    free ((CGEN_HW_ENTRY *) cd->operand_table.entries);

  free (cd);
}

