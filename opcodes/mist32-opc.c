/* Instruction opcode table for mist32.

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
#include "ansidecl.h"
#include "bfd.h"
#include "symcat.h"
#include "mist32-desc.h"
#include "mist32-opc.h"
#include "libiberty.h"

/* -- opc.c */
/* -- */
/* The hash functions are recorded here to help keep assembler code out of
   the disassembler and vice versa.  */

static int asm_hash_insn_p        (const CGEN_INSN *);
static unsigned int asm_hash_insn (const char *);
static int dis_hash_insn_p        (const CGEN_INSN *);
static unsigned int dis_hash_insn (const char *, CGEN_INSN_INT);

/* Instruction formats.  */

#define F(f) & mist32_cgen_ifld_table[MIST32_##f]
static const CGEN_IFMT ifmt_empty ATTRIBUTE_UNUSED = {
  0, 0, 0x0, { { 0 } }
};

static const CGEN_IFMT ifmt_add ATTRIBUTE_UNUSED = {
  32, 32, 0xfffffc00, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RESERVE1) }, { F (F_RD) }, { F (F_RS) }, { 0 } }
};

static const CGEN_IFMT ifmt_addi ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RD) }, { F (F_I11) }, { 0 } }
};

static const CGEN_IFMT ifmt_udivi ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RD) }, { F (F_UI11) }, { 0 } }
};

static const CGEN_IFMT ifmt_wl16 ATTRIBUTE_UNUSED = {
  32, 32, 0xffe00000, { { F (F_EXT) }, { F (F_OP) }, { F (F_RD) }, { F (F_UI16) }, { 0 } }
};

static const CGEN_IFMT ifmt_wh16 ATTRIBUTE_UNUSED = {
  32, 32, 0xffe00000, { { F (F_EXT) }, { F (F_OP) }, { F (F_RD) }, { F (F_UI16) }, { 0 } }
};

static const CGEN_IFMT ifmt_clr ATTRIBUTE_UNUSED = {
  32, 32, 0xfffffc1f, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RESERVE1) }, { F (F_RD) }, { F (F_RESERVE3) }, { 0 } }
};

static const CGEN_IFMT ifmt_lil ATTRIBUTE_UNUSED = {
  32, 32, 0xffe00000, { { F (F_EXT) }, { F (F_OP) }, { F (F_RD) }, { F (F_I16) }, { 0 } }
};

static const CGEN_IFMT ifmt_ld8i ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RD) }, { F (F_P11B) }, { 0 } }
};

static const CGEN_IFMT ifmt_ld16i ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RD) }, { F (F_P11H) }, { 0 } }
};

static const CGEN_IFMT ifmt_ld32i ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RD) }, { F (F_P11W) }, { 0 } }
};

static const CGEN_IFMT ifmt_pushi ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_CI16) }, { 0 } }
};

static const CGEN_IFMT ifmt_pushpc ATTRIBUTE_UNUSED = {
  32, 32, 0xffffffff, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RESERVE1) }, { F (F_RESERVE2) }, { F (F_RESERVE3) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldd8 ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_D6B) }, { F (F_RD) }, { F (F_RS) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldd16 ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_D6H) }, { F (F_RD) }, { F (F_RS) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldd32 ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_D6W) }, { F (F_RD) }, { F (F_RS) }, { 0 } }
};

static const CGEN_IFMT ifmt_bur ATTRIBUTE_UNUSED = {
  32, 32, 0xfff0fc1f, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_CC) }, { F (F_RESERVE1) }, { F (F_RD) }, { F (F_RESERVE3) }, { 0 } }
};

static const CGEN_IFMT ifmt_buri ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_CC) }, { F (F_UP16R) }, { 0 } }
};

static const CGEN_IFMT ifmt_bri ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_CC) }, { F (F_P16R) }, { 0 } }
};

static const CGEN_IFMT ifmt_bi ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_CC) }, { F (F_P16) }, { 0 } }
};

static const CGEN_IFMT ifmt_srieiwi ATTRIBUTE_UNUSED = {
  32, 32, 0xffff03e0, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RESERVE2) }, { F (F_UI11) }, { 0 } }
};

static const CGEN_IFMT ifmt_srspadd ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_CI16W) }, { 0 } }
};

static const CGEN_IFMT ifmt_movepci ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_EXT) }, { F (F_OP) }, { F (F_ISIMM) }, { F (F_AFE) }, { F (F_RD) }, { F (F_I11W) }, { 0 } }
};

#undef F

#define A(a) (1 << CGEN_INSN_##a)
#define OPERAND(op) MIST32_OPERAND_##op
#define MNEM CGEN_SYNTAX_MNEMONIC /* syntax value for mnemonic */
#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))

/* The instruction table.  */

static const CGEN_OPCODE mist32_cgen_insn_opcode_table[MAX_INSNS] =
{
  /* Special null first entry.
     A `num' value of zero is thus invalid.
     Also, the special `invalid' insn resides here.  */
  { { 0, 0, 0, 0 }, {{0}}, 0, {0}},
/* add $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x0 }
  },
/* add $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x100000 }
  },
/* sub $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x200000 }
  },
/* sub $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x300000 }
  },
/* mull $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x400000 }
  },
/* mull $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x500000 }
  },
/* mulh $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x600000 }
  },
/* mulh $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x700000 }
  },
/* udiv $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x800000 }
  },
/* udiv $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x900000 }
  },
/* umod $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xa00000 }
  },
/* umod $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0xb00000 }
  },
/* cmp $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xc00000 }
  },
/* cmp $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0xd00000 }
  },
/* div $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xe00000 }
  },
/* div $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0xf00000 }
  },
/* mod $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x1000000 }
  },
/* mod $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x1100000 }
  },
/* neg $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x1200000 }
  },
/* umull $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x1400000 }
  },
/* umull $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x1500000 }
  },
/* umulh $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x1600000 }
  },
/* umulh $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x1700000 }
  },
/* addc $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x1c00000 }
  },
/* inc $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x2000000 }
  },
/* dec $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x2200000 }
  },
/* max $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x2600000 }
  },
/* max $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x2700000 }
  },
/* min $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x2800000 }
  },
/* min $rd,$i11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11), 0 } },
    & ifmt_addi, { 0x2900000 }
  },
/* umax $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x2a00000 }
  },
/* umax $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x2b00000 }
  },
/* umin $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x2c00000 }
  },
/* umin $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x2d00000 }
  },
/* sext8 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x3800000 }
  },
/* sext16 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x3a00000 }
  },
/* shl $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x8000000 }
  },
/* shl $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x8100000 }
  },
/* shr $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x8200000 }
  },
/* shr $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x8300000 }
  },
/* sar $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x8a00000 }
  },
/* sar $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x8b00000 }
  },
/* rol $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x9000000 }
  },
/* rol $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x9100000 }
  },
/* ror $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x9200000 }
  },
/* ror $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0x9300000 }
  },
/* and $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xc000000 }
  },
/* or $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xc200000 }
  },
/* xor $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xc400000 }
  },
/* not $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xc600000 }
  },
/* nand $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xc800000 }
  },
/* nor $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xca00000 }
  },
/* xnor $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xcc00000 }
  },
/* test $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xce00000 }
  },
/* wl16 $rd,$ui16l */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI16L), 0 } },
    & ifmt_wl16, { 0xd400000 }
  },
/* wh16 $rd,$i16h */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I16H), 0 } },
    & ifmt_wh16, { 0xd600000 }
  },
/* clrb $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0xd900000 }
  },
/* setb $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0xdb00000 }
  },
/* clr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0xdc00000 }
  },
/* set $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0xde00000 }
  },
/* revb $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xe000000 }
  },
/* rev8 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xe200000 }
  },
/* getb $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xe400000 }
  },
/* getb $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0xe500000 }
  },
/* get8 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0xe600000 }
  },
/* get8 $rd,$ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI11), 0 } },
    & ifmt_udivi, { 0xe700000 }
  },
/* lil $rd,$i16l */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I16L), 0 } },
    & ifmt_lil, { 0xec00000 }
  },
/* lih $rd,$i16h */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I16H), 0 } },
    & ifmt_wh16, { 0xee00000 }
  },
/* ulil $rd,$ui16l */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (UI16L), 0 } },
    & ifmt_wl16, { 0xf400000 }
  },
/* ld8 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x10000000 }
  },
/* ld8 $rd,$p11b */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11B), 0 } },
    & ifmt_ld8i, { 0x10100000 }
  },
/* ld16 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x10200000 }
  },
/* ld16 $rd,$p11h */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11H), 0 } },
    & ifmt_ld16i, { 0x10300000 }
  },
/* ld32 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x10400000 }
  },
/* ld32 $rd,$p11w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11W), 0 } },
    & ifmt_ld32i, { 0x10500000 }
  },
/* st8 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x10600000 }
  },
/* st8 $rd,$p11b */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11B), 0 } },
    & ifmt_ld8i, { 0x10700000 }
  },
/* st16 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x10800000 }
  },
/* st16 $rd,$p11h */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11H), 0 } },
    & ifmt_ld16i, { 0x10900000 }
  },
/* st32 $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x10a00000 }
  },
/* st32 $rd,$p11w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11W), 0 } },
    & ifmt_ld32i, { 0x10b00000 }
  },
/* push $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x11000000 }
  },
/* push $ci16 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (CI16), 0 } },
    & ifmt_pushi, { 0x11100000 }
  },
/* pushpc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x11200000 }
  },
/* pop $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x12000000 }
  },
/* ldd8 $rd,$rs,$d6b */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), ',', OP (D6B), 0 } },
    & ifmt_ldd8, { 0x13400000 }
  },
/* ldd16 $rd,$rs,$d6h */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), ',', OP (D6H), 0 } },
    & ifmt_ldd16, { 0x13600000 }
  },
/* ldd32 $rd,$rs,$d6w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), ',', OP (D6W), 0 } },
    & ifmt_ldd32, { 0x13800000 }
  },
/* std8 $rd,$rs,$d6b */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), ',', OP (D6B), 0 } },
    & ifmt_ldd8, { 0x13a00000 }
  },
/* std16 $rd,$rs,$d6h */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), ',', OP (D6H), 0 } },
    & ifmt_ldd16, { 0x13c00000 }
  },
/* std32 $rd,$rs,$d6w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), ',', OP (D6W), 0 } },
    & ifmt_ldd32, { 0x13e00000 }
  },
/* bur $rd,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (CC), 0 } },
    & ifmt_bur, { 0x14000000 }
  },
/* bur $up16r,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (UP16R), ',', OP (CC), 0 } },
    & ifmt_buri, { 0x14100000 }
  },
/* br $rd,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (CC), 0 } },
    & ifmt_bur, { 0x14200000 }
  },
/* br $p16r,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (P16R), ',', OP (CC), 0 } },
    & ifmt_bri, { 0x14300000 }
  },
/* b $rd,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (CC), 0 } },
    & ifmt_bur, { 0x14400000 }
  },
/* b $p16,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (P16), ',', OP (CC), 0 } },
    & ifmt_bi, { 0x14500000 }
  },
/* ib */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x14600000 }
  },
/* burn $rd,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (CC), 0 } },
    & ifmt_bur, { 0x16000000 }
  },
/* burn $up16r,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (UP16R), ',', OP (CC), 0 } },
    & ifmt_buri, { 0x16100000 }
  },
/* brn $rd,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (CC), 0 } },
    & ifmt_bur, { 0x16200000 }
  },
/* brn $p16r,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (P16R), ',', OP (CC), 0 } },
    & ifmt_bri, { 0x16300000 }
  },
/* bn $rd,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (CC), 0 } },
    & ifmt_bur, { 0x16400000 }
  },
/* bn $p16,$cc */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (P16), ',', OP (CC), 0 } },
    & ifmt_bi, { 0x16500000 }
  },
/* srspr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x18000000 }
  },
/* srpdtr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x18200000 }
  },
/* srpidr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x18400000 }
  },
/* srcidr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x18600000 }
  },
/* srmoder $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x18800000 }
  },
/* srieir $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x18a00000 }
  },
/* srtisr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19000000 }
  },
/* srkpdtr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19200000 }
  },
/* srmmur $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19400000 }
  },
/* sriosr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19600000 }
  },
/* srtidr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19800000 }
  },
/* srppsr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19a00000 }
  },
/* srppcr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19c00000 }
  },
/* sruspr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x19e00000 }
  },
/* srppdtr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1a000000 }
  },
/* srptidr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1a200000 }
  },
/* srpsr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1a600000 }
  },
/* srfrcr */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x1a800000 }
  },
/* srfrclr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1aa00000 }
  },
/* srfrchr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1ac00000 }
  },
/* srpflagr $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1ae00000 }
  },
/* srfi0r $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1b000000 }
  },
/* srfi1r $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1b200000 }
  },
/* srspw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1c000000 }
  },
/* srpdtw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1c200000 }
  },
/* srieiw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1ca00000 }
  },
/* srieiw $ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (UI11), 0 } },
    & ifmt_srieiwi, { 0x1cb00000 }
  },
/* srtisw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1d000000 }
  },
/* srkpdtw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1d200000 }
  },
/* srmmuw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1d400000 }
  },
/* srmmuw $ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (UI11), 0 } },
    & ifmt_srieiwi, { 0x1d500000 }
  },
/* srppsw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1da00000 }
  },
/* srppcw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1dc00000 }
  },
/* sruspw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1de00000 }
  },
/* srppdtw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1e000000 }
  },
/* srptidw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1e200000 }
  },
/* sridtw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1e400000 }
  },
/* srpsw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1e600000 }
  },
/* srfrcw */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x1e800000 }
  },
/* srfrclw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1ea00000 }
  },
/* srfrchw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1ec00000 }
  },
/* srpflagw $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x1ee00000 }
  },
/* srspadd $ci16w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (CI16W), 0 } },
    & ifmt_srspadd, { 0x1ff00000 }
  },
/* nop */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x20000000 }
  },
/* halt */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x20200000 }
  },
/* move $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x20400000 }
  },
/* movepc $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x20600000 }
  },
/* movepc $rd,$i11w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I11W), 0 } },
    & ifmt_movepci, { 0x20700000 }
  },
/* swi $rd */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), 0 } },
    & ifmt_clr, { 0x24000000 }
  },
/* swi $ui11 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (UI11), 0 } },
    & ifmt_srieiwi, { 0x24100000 }
  },
/* tas $rd,$rs */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RS), 0 } },
    & ifmt_add, { 0x24200000 }
  },
/* tas $rd,$p11w */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (P11W), 0 } },
    & ifmt_ld32i, { 0x24300000 }
  },
/* idts */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_pushpc, { 0x24400000 }
  },
};

#undef A
#undef OPERAND
#undef MNEM
#undef OP

/* Formats for ALIAS macro-insns.  */

#define F(f) & mist32_cgen_ifld_table[MIST32_##f]
#undef F

/* Each non-simple macro entry points to an array of expansion possibilities.  */

#define A(a) (1 << CGEN_INSN_##a)
#define OPERAND(op) MIST32_OPERAND_##op
#define MNEM CGEN_SYNTAX_MNEMONIC /* syntax value for mnemonic */
#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))

/* The macro instruction table.  */

static const CGEN_IBASE mist32_cgen_macro_insn_table[] =
{
};

/* The macro instruction opcode table.  */

static const CGEN_OPCODE mist32_cgen_macro_insn_opcode_table[] =
{
};

#undef A
#undef OPERAND
#undef MNEM
#undef OP

#ifndef CGEN_ASM_HASH_P
#define CGEN_ASM_HASH_P(insn) 1
#endif

#ifndef CGEN_DIS_HASH_P
#define CGEN_DIS_HASH_P(insn) 1
#endif

/* Return non-zero if INSN is to be added to the hash table.
   Targets are free to override CGEN_{ASM,DIS}_HASH_P in the .opc file.  */

static int
asm_hash_insn_p (insn)
     const CGEN_INSN *insn ATTRIBUTE_UNUSED;
{
  return CGEN_ASM_HASH_P (insn);
}

static int
dis_hash_insn_p (insn)
     const CGEN_INSN *insn;
{
  /* If building the hash table and the NO-DIS attribute is present,
     ignore.  */
  if (CGEN_INSN_ATTR_VALUE (insn, CGEN_INSN_NO_DIS))
    return 0;
  return CGEN_DIS_HASH_P (insn);
}

#ifndef CGEN_ASM_HASH
#define CGEN_ASM_HASH_SIZE 127
#ifdef CGEN_MNEMONIC_OPERANDS
#define CGEN_ASM_HASH(mnem) (*(unsigned char *) (mnem) % CGEN_ASM_HASH_SIZE)
#else
#define CGEN_ASM_HASH(mnem) (*(unsigned char *) (mnem) % CGEN_ASM_HASH_SIZE) /*FIXME*/
#endif
#endif

/* It doesn't make much sense to provide a default here,
   but while this is under development we do.
   BUFFER is a pointer to the bytes of the insn, target order.
   VALUE is the first base_insn_bitsize bits as an int in host order.  */

#ifndef CGEN_DIS_HASH
#define CGEN_DIS_HASH_SIZE 256
#define CGEN_DIS_HASH(buf, value) (*(unsigned char *) (buf))
#endif

/* The result is the hash value of the insn.
   Targets are free to override CGEN_{ASM,DIS}_HASH in the .opc file.  */

static unsigned int
asm_hash_insn (mnem)
     const char * mnem;
{
  return CGEN_ASM_HASH (mnem);
}

/* BUF is a pointer to the bytes of the insn, target order.
   VALUE is the first base_insn_bitsize bits as an int in host order.  */

static unsigned int
dis_hash_insn (buf, value)
     const char * buf ATTRIBUTE_UNUSED;
     CGEN_INSN_INT value ATTRIBUTE_UNUSED;
{
  return CGEN_DIS_HASH (buf, value);
}

/* Set the recorded length of the insn in the CGEN_FIELDS struct.  */

static void
set_fields_bitsize (CGEN_FIELDS *fields, int size)
{
  CGEN_FIELDS_BITSIZE (fields) = size;
}

/* Function to call before using the operand instance table.
   This plugs the opcode entries and macro instructions into the cpu table.  */

void
mist32_cgen_init_opcode_table (CGEN_CPU_DESC cd)
{
  int i;
  int num_macros = (sizeof (mist32_cgen_macro_insn_table) /
		    sizeof (mist32_cgen_macro_insn_table[0]));
  const CGEN_IBASE *ib = & mist32_cgen_macro_insn_table[0];
  const CGEN_OPCODE *oc = & mist32_cgen_macro_insn_opcode_table[0];
  CGEN_INSN *insns = xmalloc (num_macros * sizeof (CGEN_INSN));

  /* This test has been added to avoid a warning generated
     if memset is called with a third argument of value zero.  */
  if (num_macros >= 1)
    memset (insns, 0, num_macros * sizeof (CGEN_INSN));
  for (i = 0; i < num_macros; ++i)
    {
      insns[i].base = &ib[i];
      insns[i].opcode = &oc[i];
      mist32_cgen_build_insn_regex (& insns[i]);
    }
  cd->macro_insn_table.init_entries = insns;
  cd->macro_insn_table.entry_size = sizeof (CGEN_IBASE);
  cd->macro_insn_table.num_init_entries = num_macros;

  oc = & mist32_cgen_insn_opcode_table[0];
  insns = (CGEN_INSN *) cd->insn_table.init_entries;
  for (i = 0; i < MAX_INSNS; ++i)
    {
      insns[i].opcode = &oc[i];
      mist32_cgen_build_insn_regex (& insns[i]);
    }

  cd->sizeof_fields = sizeof (CGEN_FIELDS);
  cd->set_fields_bitsize = set_fields_bitsize;

  cd->asm_hash_p = asm_hash_insn_p;
  cd->asm_hash = asm_hash_insn;
  cd->asm_hash_size = CGEN_ASM_HASH_SIZE;

  cd->dis_hash_p = dis_hash_insn_p;
  cd->dis_hash = dis_hash_insn;
  cd->dis_hash_size = CGEN_DIS_HASH_SIZE;
}
