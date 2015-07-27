/* Instruction building/extraction support for mist32. -*- C -*-

   THIS FILE IS MACHINE GENERATED WITH CGEN: Cpu tools GENerator.
   - the resultant file is machine generated, cgen-ibld.in isn't

   Copyright (C) 1996-2014 Free Software Foundation, Inc.

   This file is part of libopcodes.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

/* ??? Eventually more and more of this stuff can go to cpu-independent files.
   Keep that in mind.  */

#include "sysdep.h"
#include <stdio.h>
#include "ansidecl.h"
#include "dis-asm.h"
#include "bfd.h"
#include "symcat.h"
#include "mist32-desc.h"
#include "mist32-opc.h"
#include "cgen/basic-modes.h"
#include "opintl.h"
#include "safe-ctype.h"

#undef  min
#define min(a,b) ((a) < (b) ? (a) : (b))
#undef  max
#define max(a,b) ((a) > (b) ? (a) : (b))

/* Used by the ifield rtx function.  */
#define FLD(f) (fields->f)

static const char * insert_normal
  (CGEN_CPU_DESC, long, unsigned int, unsigned int, unsigned int,
   unsigned int, unsigned int, unsigned int, CGEN_INSN_BYTES_PTR);
static const char * insert_insn_normal
  (CGEN_CPU_DESC, const CGEN_INSN *,
   CGEN_FIELDS *, CGEN_INSN_BYTES_PTR, bfd_vma);
static int extract_normal
  (CGEN_CPU_DESC, CGEN_EXTRACT_INFO *, CGEN_INSN_INT,
   unsigned int, unsigned int, unsigned int, unsigned int,
   unsigned int, unsigned int, bfd_vma, long *);
static int extract_insn_normal
  (CGEN_CPU_DESC, const CGEN_INSN *, CGEN_EXTRACT_INFO *,
   CGEN_INSN_INT, CGEN_FIELDS *, bfd_vma);
#if CGEN_INT_INSN_P
static void put_insn_int_value
  (CGEN_CPU_DESC, CGEN_INSN_BYTES_PTR, int, int, CGEN_INSN_INT);
#endif
#if ! CGEN_INT_INSN_P
static CGEN_INLINE void insert_1
  (CGEN_CPU_DESC, unsigned long, int, int, int, unsigned char *);
static CGEN_INLINE int fill_cache
  (CGEN_CPU_DESC, CGEN_EXTRACT_INFO *,  int, int, bfd_vma);
static CGEN_INLINE long extract_1
  (CGEN_CPU_DESC, CGEN_EXTRACT_INFO *, int, int, int, unsigned char *, bfd_vma);
#endif

/* Operand insertion.  */

#if ! CGEN_INT_INSN_P

/* Subroutine of insert_normal.  */

static CGEN_INLINE void
insert_1 (CGEN_CPU_DESC cd,
	  unsigned long value,
	  int start,
	  int length,
	  int word_length,
	  unsigned char *bufp)
{
  unsigned long x,mask;
  int shift;

  x = cgen_get_insn_value (cd, bufp, word_length);

  /* Written this way to avoid undefined behaviour.  */
  mask = (((1L << (length - 1)) - 1) << 1) | 1;
  if (CGEN_INSN_LSB0_P)
    shift = (start + 1) - length;
  else
    shift = (word_length - (start + length));
  x = (x & ~(mask << shift)) | ((value & mask) << shift);

  cgen_put_insn_value (cd, bufp, word_length, (bfd_vma) x);
}

#endif /* ! CGEN_INT_INSN_P */

/* Default insertion routine.

   ATTRS is a mask of the boolean attributes.
   WORD_OFFSET is the offset in bits from the start of the insn of the value.
   WORD_LENGTH is the length of the word in bits in which the value resides.
   START is the starting bit number in the word, architecture origin.
   LENGTH is the length of VALUE in bits.
   TOTAL_LENGTH is the total length of the insn in bits.

   The result is an error message or NULL if success.  */

/* ??? This duplicates functionality with bfd's howto table and
   bfd_install_relocation.  */
/* ??? This doesn't handle bfd_vma's.  Create another function when
   necessary.  */

static const char *
insert_normal (CGEN_CPU_DESC cd,
	       long value,
	       unsigned int attrs,
	       unsigned int word_offset,
	       unsigned int start,
	       unsigned int length,
	       unsigned int word_length,
	       unsigned int total_length,
	       CGEN_INSN_BYTES_PTR buffer)
{
  static char errbuf[100];
  /* Written this way to avoid undefined behaviour.  */
  unsigned long mask = (((1L << (length - 1)) - 1) << 1) | 1;

  /* If LENGTH is zero, this operand doesn't contribute to the value.  */
  if (length == 0)
    return NULL;

  if (word_length > 8 * sizeof (CGEN_INSN_INT))
    abort ();

  /* For architectures with insns smaller than the base-insn-bitsize,
     word_length may be too big.  */
  if (cd->min_insn_bitsize < cd->base_insn_bitsize)
    {
      if (word_offset == 0
	  && word_length > total_length)
	word_length = total_length;
    }

  /* Ensure VALUE will fit.  */
  if (CGEN_BOOL_ATTR (attrs, CGEN_IFLD_SIGN_OPT))
    {
      long minval = - (1L << (length - 1));
      unsigned long maxval = mask;
      
      if ((value > 0 && (unsigned long) value > maxval)
	  || value < minval)
	{
	  /* xgettext:c-format */
	  sprintf (errbuf,
		   _("operand out of range (%ld not between %ld and %lu)"),
		   value, minval, maxval);
	  return errbuf;
	}
    }
  else if (! CGEN_BOOL_ATTR (attrs, CGEN_IFLD_SIGNED))
    {
      unsigned long maxval = mask;
      unsigned long val = (unsigned long) value;

      /* For hosts with a word size > 32 check to see if value has been sign
	 extended beyond 32 bits.  If so then ignore these higher sign bits
	 as the user is attempting to store a 32-bit signed value into an
	 unsigned 32-bit field which is allowed.  */
      if (sizeof (unsigned long) > 4 && ((value >> 32) == -1))
	val &= 0xFFFFFFFF;

      if (val > maxval)
	{
	  /* xgettext:c-format */
	  sprintf (errbuf,
		   _("operand out of range (0x%lx not between 0 and 0x%lx)"),
		   val, maxval);
	  return errbuf;
	}
    }
  else
    {
      if (! cgen_signed_overflow_ok_p (cd))
	{
	  long minval = - (1L << (length - 1));
	  long maxval =   (1L << (length - 1)) - 1;
	  
	  if (value < minval || value > maxval)
	    {
	      sprintf
		/* xgettext:c-format */
		(errbuf, _("operand out of range (%ld not between %ld and %ld)"),
		 value, minval, maxval);
	      return errbuf;
	    }
	}
    }

#if CGEN_INT_INSN_P

  {
    int shift;

    if (CGEN_INSN_LSB0_P)
      shift = (word_offset + start + 1) - length;
    else
      shift = total_length - (word_offset + start + length);
    *buffer = (*buffer & ~(mask << shift)) | ((value & mask) << shift);
  }

#else /* ! CGEN_INT_INSN_P */

  {
    unsigned char *bufp = (unsigned char *) buffer + word_offset / 8;

    insert_1 (cd, value, start, length, word_length, bufp);
  }

#endif /* ! CGEN_INT_INSN_P */

  return NULL;
}

/* Default insn builder (insert handler).
   The instruction is recorded in CGEN_INT_INSN_P byte order (meaning
   that if CGEN_INSN_BYTES_PTR is an int * and thus, the value is
   recorded in host byte order, otherwise BUFFER is an array of bytes
   and the value is recorded in target byte order).
   The result is an error message or NULL if success.  */

static const char *
insert_insn_normal (CGEN_CPU_DESC cd,
		    const CGEN_INSN * insn,
		    CGEN_FIELDS * fields,
		    CGEN_INSN_BYTES_PTR buffer,
		    bfd_vma pc)
{
  const CGEN_SYNTAX *syntax = CGEN_INSN_SYNTAX (insn);
  unsigned long value;
  const CGEN_SYNTAX_CHAR_TYPE * syn;

  CGEN_INIT_INSERT (cd);
  value = CGEN_INSN_BASE_VALUE (insn);

  /* If we're recording insns as numbers (rather than a string of bytes),
     target byte order handling is deferred until later.  */

#if CGEN_INT_INSN_P

  put_insn_int_value (cd, buffer, cd->base_insn_bitsize,
		      CGEN_FIELDS_BITSIZE (fields), value);

#else

  cgen_put_insn_value (cd, buffer, min ((unsigned) cd->base_insn_bitsize,
					(unsigned) CGEN_FIELDS_BITSIZE (fields)),
		       value);

#endif /* ! CGEN_INT_INSN_P */

  /* ??? It would be better to scan the format's fields.
     Still need to be able to insert a value based on the operand though;
     e.g. storing a branch displacement that got resolved later.
     Needs more thought first.  */

  for (syn = CGEN_SYNTAX_STRING (syntax); * syn; ++ syn)
    {
      const char *errmsg;

      if (CGEN_SYNTAX_CHAR_P (* syn))
	continue;

      errmsg = (* cd->insert_operand) (cd, CGEN_SYNTAX_FIELD (*syn),
				       fields, buffer, pc);
      if (errmsg)
	return errmsg;
    }

  return NULL;
}

#if CGEN_INT_INSN_P
/* Cover function to store an insn value into an integral insn.  Must go here
   because it needs <prefix>-desc.h for CGEN_INT_INSN_P.  */

static void
put_insn_int_value (CGEN_CPU_DESC cd ATTRIBUTE_UNUSED,
		    CGEN_INSN_BYTES_PTR buf,
		    int length,
		    int insn_length,
		    CGEN_INSN_INT value)
{
  /* For architectures with insns smaller than the base-insn-bitsize,
     length may be too big.  */
  if (length > insn_length)
    *buf = value;
  else
    {
      int shift = insn_length - length;
      /* Written this way to avoid undefined behaviour.  */
      CGEN_INSN_INT mask = (((1L << (length - 1)) - 1) << 1) | 1;

      *buf = (*buf & ~(mask << shift)) | ((value & mask) << shift);
    }
}
#endif

/* Operand extraction.  */

#if ! CGEN_INT_INSN_P

/* Subroutine of extract_normal.
   Ensure sufficient bytes are cached in EX_INFO.
   OFFSET is the offset in bytes from the start of the insn of the value.
   BYTES is the length of the needed value.
   Returns 1 for success, 0 for failure.  */

static CGEN_INLINE int
fill_cache (CGEN_CPU_DESC cd ATTRIBUTE_UNUSED,
	    CGEN_EXTRACT_INFO *ex_info,
	    int offset,
	    int bytes,
	    bfd_vma pc)
{
  /* It's doubtful that the middle part has already been fetched so
     we don't optimize that case.  kiss.  */
  unsigned int mask;
  disassemble_info *info = (disassemble_info *) ex_info->dis_info;

  /* First do a quick check.  */
  mask = (1 << bytes) - 1;
  if (((ex_info->valid >> offset) & mask) == mask)
    return 1;

  /* Search for the first byte we need to read.  */
  for (mask = 1 << offset; bytes > 0; --bytes, ++offset, mask <<= 1)
    if (! (mask & ex_info->valid))
      break;

  if (bytes)
    {
      int status;

      pc += offset;
      status = (*info->read_memory_func)
	(pc, ex_info->insn_bytes + offset, bytes, info);

      if (status != 0)
	{
	  (*info->memory_error_func) (status, pc, info);
	  return 0;
	}

      ex_info->valid |= ((1 << bytes) - 1) << offset;
    }

  return 1;
}

/* Subroutine of extract_normal.  */

static CGEN_INLINE long
extract_1 (CGEN_CPU_DESC cd,
	   CGEN_EXTRACT_INFO *ex_info ATTRIBUTE_UNUSED,
	   int start,
	   int length,
	   int word_length,
	   unsigned char *bufp,
	   bfd_vma pc ATTRIBUTE_UNUSED)
{
  unsigned long x;
  int shift;

  x = cgen_get_insn_value (cd, bufp, word_length);

  if (CGEN_INSN_LSB0_P)
    shift = (start + 1) - length;
  else
    shift = (word_length - (start + length));
  return x >> shift;
}

#endif /* ! CGEN_INT_INSN_P */

/* Default extraction routine.

   INSN_VALUE is the first base_insn_bitsize bits of the insn in host order,
   or sometimes less for cases like the m32r where the base insn size is 32
   but some insns are 16 bits.
   ATTRS is a mask of the boolean attributes.  We only need `SIGNED',
   but for generality we take a bitmask of all of them.
   WORD_OFFSET is the offset in bits from the start of the insn of the value.
   WORD_LENGTH is the length of the word in bits in which the value resides.
   START is the starting bit number in the word, architecture origin.
   LENGTH is the length of VALUE in bits.
   TOTAL_LENGTH is the total length of the insn in bits.

   Returns 1 for success, 0 for failure.  */

/* ??? The return code isn't properly used.  wip.  */

/* ??? This doesn't handle bfd_vma's.  Create another function when
   necessary.  */

static int
extract_normal (CGEN_CPU_DESC cd,
#if ! CGEN_INT_INSN_P
		CGEN_EXTRACT_INFO *ex_info,
#else
		CGEN_EXTRACT_INFO *ex_info ATTRIBUTE_UNUSED,
#endif
		CGEN_INSN_INT insn_value,
		unsigned int attrs,
		unsigned int word_offset,
		unsigned int start,
		unsigned int length,
		unsigned int word_length,
		unsigned int total_length,
#if ! CGEN_INT_INSN_P
		bfd_vma pc,
#else
		bfd_vma pc ATTRIBUTE_UNUSED,
#endif
		long *valuep)
{
  long value, mask;

  /* If LENGTH is zero, this operand doesn't contribute to the value
     so give it a standard value of zero.  */
  if (length == 0)
    {
      *valuep = 0;
      return 1;
    }

  if (word_length > 8 * sizeof (CGEN_INSN_INT))
    abort ();

  /* For architectures with insns smaller than the insn-base-bitsize,
     word_length may be too big.  */
  if (cd->min_insn_bitsize < cd->base_insn_bitsize)
    {
      if (word_offset + word_length > total_length)
	word_length = total_length - word_offset;
    }

  /* Does the value reside in INSN_VALUE, and at the right alignment?  */

  if (CGEN_INT_INSN_P || (word_offset == 0 && word_length == total_length))
    {
      if (CGEN_INSN_LSB0_P)
	value = insn_value >> ((word_offset + start + 1) - length);
      else
	value = insn_value >> (total_length - ( word_offset + start + length));
    }

#if ! CGEN_INT_INSN_P

  else
    {
      unsigned char *bufp = ex_info->insn_bytes + word_offset / 8;

      if (word_length > 8 * sizeof (CGEN_INSN_INT))
	abort ();

      if (fill_cache (cd, ex_info, word_offset / 8, word_length / 8, pc) == 0)
	return 0;

      value = extract_1 (cd, ex_info, start, length, word_length, bufp, pc);
    }

#endif /* ! CGEN_INT_INSN_P */

  /* Written this way to avoid undefined behaviour.  */
  mask = (((1L << (length - 1)) - 1) << 1) | 1;

  value &= mask;
  /* sign extend? */
  if (CGEN_BOOL_ATTR (attrs, CGEN_IFLD_SIGNED)
      && (value & (1L << (length - 1))))
    value |= ~mask;

  *valuep = value;

  return 1;
}

/* Default insn extractor.

   INSN_VALUE is the first base_insn_bitsize bits, translated to host order.
   The extracted fields are stored in FIELDS.
   EX_INFO is used to handle reading variable length insns.
   Return the length of the insn in bits, or 0 if no match,
   or -1 if an error occurs fetching data (memory_error_func will have
   been called).  */

static int
extract_insn_normal (CGEN_CPU_DESC cd,
		     const CGEN_INSN *insn,
		     CGEN_EXTRACT_INFO *ex_info,
		     CGEN_INSN_INT insn_value,
		     CGEN_FIELDS *fields,
		     bfd_vma pc)
{
  const CGEN_SYNTAX *syntax = CGEN_INSN_SYNTAX (insn);
  const CGEN_SYNTAX_CHAR_TYPE *syn;

  CGEN_FIELDS_BITSIZE (fields) = CGEN_INSN_BITSIZE (insn);

  CGEN_INIT_EXTRACT (cd);

  for (syn = CGEN_SYNTAX_STRING (syntax); *syn; ++syn)
    {
      int length;

      if (CGEN_SYNTAX_CHAR_P (*syn))
	continue;

      length = (* cd->extract_operand) (cd, CGEN_SYNTAX_FIELD (*syn),
					ex_info, insn_value, fields, pc);
      if (length <= 0)
	return length;
    }

  /* We recognized and successfully extracted this insn.  */
  return CGEN_INSN_BITSIZE (insn);
}

/* Machine generated code added here.  */

const char * mist32_cgen_insert_operand
  (CGEN_CPU_DESC, int, CGEN_FIELDS *, CGEN_INSN_BYTES_PTR, bfd_vma);

/* Main entry point for operand insertion.

   This function is basically just a big switch statement.  Earlier versions
   used tables to look up the function to use, but
   - if the table contains both assembler and disassembler functions then
     the disassembler contains much of the assembler and vice-versa,
   - there's a lot of inlining possibilities as things grow,
   - using a switch statement avoids the function call overhead.

   This function could be moved into `parse_insn_normal', but keeping it
   separate makes clear the interface between `parse_insn_normal' and each of
   the handlers.  It's also needed by GAS to insert operands that couldn't be
   resolved during parsing.  */

const char *
mist32_cgen_insert_operand (CGEN_CPU_DESC cd,
			     int opindex,
			     CGEN_FIELDS * fields,
			     CGEN_INSN_BYTES_PTR buffer,
			     bfd_vma pc ATTRIBUTE_UNUSED)
{
  const char * errmsg = NULL;
  unsigned int total_length = CGEN_FIELDS_BITSIZE (fields);

  switch (opindex)
    {
    case MIST32_OPERAND_CC :
      errmsg = insert_normal (cd, fields->f_cc, 0, 0, 19, 4, 32, total_length, buffer);
      break;
    case MIST32_OPERAND_CI16 :
      errmsg = insert_normal (cd, fields->f_ci16, 0, 0, 15, 16, 32, total_length, buffer);
      break;
    case MIST32_OPERAND_CI16W :
      {
        long value = fields->f_ci16w;
        value = ((SI) (((value) & (-4))) >> (2));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 16, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_D6B :
      {
        long value = fields->f_d6b;
        value = ((SI) (value) >> (0));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 6, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_D6H :
      {
        long value = fields->f_d6h;
        value = ((SI) (((value) & (-2))) >> (1));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 6, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_D6W :
      {
        long value = fields->f_d6w;
        value = ((SI) (((value) & (-4))) >> (2));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 6, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_I11 :
      {
{
  FLD (f_i11h) = ((((INT) (FLD (f_i11)) >> (5))) & (63));
  FLD (f_i11l) = ((FLD (f_i11)) & (31));
}
        errmsg = insert_normal (cd, fields->f_i11h, 0, 0, 15, 6, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_i11l, 0, 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_I11W :
      {
{
  FLD (f_i11h) = ((((INT) (FLD (f_i11w)) >> (7))) & (63));
  FLD (f_i11l) = ((((INT) (FLD (f_i11w)) >> (2))) & (31));
}
        errmsg = insert_normal (cd, fields->f_i11h, 0, 0, 15, 6, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_i11l, 0, 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_I16H :
      {
{
  FLD (f_i16h) = ((UINT) (FLD (f_ui16)) >> (5));
  FLD (f_i16l) = ((FLD (f_ui16)) & (31));
}
        errmsg = insert_normal (cd, fields->f_i16h, 0, 0, 20, 11, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_i16l, 0, 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_I16L :
      {
{
  FLD (f_i16h) = ((((INT) (FLD (f_i16)) >> (5))) & (2047));
  FLD (f_i16l) = ((FLD (f_i16)) & (31));
}
        errmsg = insert_normal (cd, fields->f_i16h, 0, 0, 20, 11, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_i16l, 0, 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_P11B :
      {
{
  FLD (f_p11hi) = ((UINT) (FLD (f_p11b)) >> (5));
  FLD (f_p11lo) = ((FLD (f_p11b)) & (31));
}
        errmsg = insert_normal (cd, fields->f_p11hi, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 6, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_p11lo, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_P11H :
      {
{
  FLD (f_p11hi) = ((UINT) (FLD (f_p11h)) >> (6));
  FLD (f_p11lo) = ((UINT) (((FLD (f_p11h)) & (62))) >> (1));
}
        errmsg = insert_normal (cd, fields->f_p11hi, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 6, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_p11lo, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_P11W :
      {
{
  FLD (f_p11hi) = ((UINT) (FLD (f_p11w)) >> (7));
  FLD (f_p11lo) = ((((UINT) (FLD (f_p11w)) >> (2))) & (31));
}
        errmsg = insert_normal (cd, fields->f_p11hi, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 6, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_p11lo, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_P16 :
      {
        long value = fields->f_p16;
        value = ((USI) (((pc) & (-4))) >> (2));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 16, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_P16R :
      {
        long value = fields->f_p16r;
        value = ((SI) (((value) - (((pc) & (-4))))) >> (2));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_SIGNED)|(1<<CGEN_IFLD_PCREL_ADDR), 0, 15, 16, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_RD :
      errmsg = insert_normal (cd, fields->f_rd, 0, 0, 9, 5, 32, total_length, buffer);
      break;
    case MIST32_OPERAND_RS :
      errmsg = insert_normal (cd, fields->f_rs, 0, 0, 4, 5, 32, total_length, buffer);
      break;
    case MIST32_OPERAND_UD6B :
      errmsg = insert_normal (cd, fields->f_ud6b, 0, 0, 15, 6, 32, total_length, buffer);
      break;
    case MIST32_OPERAND_UD6H :
      {
        long value = fields->f_ud6h;
        value = ((USI) (((value) & (-2))) >> (1));
        errmsg = insert_normal (cd, value, 0, 0, 15, 6, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_UD6W :
      {
        long value = fields->f_ud6w;
        value = ((USI) (((value) & (-4))) >> (2));
        errmsg = insert_normal (cd, value, 0, 0, 15, 6, 32, total_length, buffer);
      }
      break;
    case MIST32_OPERAND_UI11 :
      {
{
  FLD (f_i11h) = ((UINT) (FLD (f_ui11)) >> (5));
  FLD (f_i11l) = ((FLD (f_ui11)) & (31));
}
        errmsg = insert_normal (cd, fields->f_i11h, 0, 0, 15, 6, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_i11l, 0, 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_UI16L :
      {
{
  FLD (f_i16h) = ((UINT) (FLD (f_ui16)) >> (5));
  FLD (f_i16l) = ((FLD (f_ui16)) & (31));
}
        errmsg = insert_normal (cd, fields->f_i16h, 0, 0, 20, 11, 32, total_length, buffer);
        if (errmsg)
          break;
        errmsg = insert_normal (cd, fields->f_i16l, 0, 0, 4, 5, 32, total_length, buffer);
        if (errmsg)
          break;
      }
      break;
    case MIST32_OPERAND_UP16R :
      {
        long value = fields->f_up16r;
        value = ((USI) (((value) - (((pc) & (-4))))) >> (2));
        errmsg = insert_normal (cd, value, 0|(1<<CGEN_IFLD_PCREL_ADDR), 0, 15, 16, 32, total_length, buffer);
      }
      break;

    default :
      /* xgettext:c-format */
      fprintf (stderr, _("Unrecognized field %d while building insn.\n"),
	       opindex);
      abort ();
  }

  return errmsg;
}

int mist32_cgen_extract_operand
  (CGEN_CPU_DESC, int, CGEN_EXTRACT_INFO *, CGEN_INSN_INT, CGEN_FIELDS *, bfd_vma);

/* Main entry point for operand extraction.
   The result is <= 0 for error, >0 for success.
   ??? Actual values aren't well defined right now.

   This function is basically just a big switch statement.  Earlier versions
   used tables to look up the function to use, but
   - if the table contains both assembler and disassembler functions then
     the disassembler contains much of the assembler and vice-versa,
   - there's a lot of inlining possibilities as things grow,
   - using a switch statement avoids the function call overhead.

   This function could be moved into `print_insn_normal', but keeping it
   separate makes clear the interface between `print_insn_normal' and each of
   the handlers.  */

int
mist32_cgen_extract_operand (CGEN_CPU_DESC cd,
			     int opindex,
			     CGEN_EXTRACT_INFO *ex_info,
			     CGEN_INSN_INT insn_value,
			     CGEN_FIELDS * fields,
			     bfd_vma pc)
{
  /* Assume success (for those operands that are nops).  */
  int length = 1;
  unsigned int total_length = CGEN_FIELDS_BITSIZE (fields);

  switch (opindex)
    {
    case MIST32_OPERAND_CC :
      length = extract_normal (cd, ex_info, insn_value, 0, 0, 19, 4, 32, total_length, pc, & fields->f_cc);
      break;
    case MIST32_OPERAND_CI16 :
      length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 16, 32, total_length, pc, & fields->f_ci16);
      break;
    case MIST32_OPERAND_CI16W :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 16, 32, total_length, pc, & value);
        value = ((value) << (2));
        fields->f_ci16w = value;
      }
      break;
    case MIST32_OPERAND_D6B :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 6, 32, total_length, pc, & value);
        value = ((value) << (0));
        fields->f_d6b = value;
      }
      break;
    case MIST32_OPERAND_D6H :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 6, 32, total_length, pc, & value);
        value = ((value) << (1));
        fields->f_d6h = value;
      }
      break;
    case MIST32_OPERAND_D6W :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_SIGNED), 0, 15, 6, 32, total_length, pc, & value);
        value = ((value) << (2));
        fields->f_d6w = value;
      }
      break;
    case MIST32_OPERAND_I11 :
      {
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 6, 32, total_length, pc, & fields->f_i11h);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_i11l);
        if (length <= 0) break;
{
  FLD (f_i11) = ((((1024) ^ (((((FLD (f_i11h)) << (5))) | (FLD (f_i11l)))))) - (1024));
}
      }
      break;
    case MIST32_OPERAND_I11W :
      {
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 6, 32, total_length, pc, & fields->f_i11h);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_i11l);
        if (length <= 0) break;
{
  FLD (f_i11w) = ((((4096) ^ (((((FLD (f_i11h)) << (7))) | (((FLD (f_i11l)) << (2))))))) - (4096));
}
      }
      break;
    case MIST32_OPERAND_I16H :
      {
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 20, 11, 32, total_length, pc, & fields->f_i16h);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_i16l);
        if (length <= 0) break;
{
  FLD (f_ui16) = ((((FLD (f_i16h)) << (5))) | (FLD (f_i16l)));
}
      }
      break;
    case MIST32_OPERAND_I16L :
      {
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 20, 11, 32, total_length, pc, & fields->f_i16h);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_i16l);
        if (length <= 0) break;
{
  FLD (f_i16) = ((((32768) ^ (((((FLD (f_i16h)) << (5))) | (FLD (f_i16l)))))) - (32768));
}
      }
      break;
    case MIST32_OPERAND_P11B :
      {
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 6, 32, total_length, pc, & fields->f_p11hi);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 4, 5, 32, total_length, pc, & fields->f_p11lo);
        if (length <= 0) break;
{
  FLD (f_p11b) = ((((FLD (f_p11hi)) << (5))) | (FLD (f_p11lo)));
}
      }
      break;
    case MIST32_OPERAND_P11H :
      {
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 6, 32, total_length, pc, & fields->f_p11hi);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 4, 5, 32, total_length, pc, & fields->f_p11lo);
        if (length <= 0) break;
{
  FLD (f_p11h) = ((((FLD (f_p11hi)) << (6))) | (((FLD (f_p11lo)) << (1))));
}
      }
      break;
    case MIST32_OPERAND_P11W :
      {
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 6, 32, total_length, pc, & fields->f_p11hi);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 4, 5, 32, total_length, pc, & fields->f_p11lo);
        if (length <= 0) break;
{
  FLD (f_p11w) = ((((FLD (f_p11hi)) << (7))) | (((FLD (f_p11lo)) << (2))));
}
      }
      break;
    case MIST32_OPERAND_P16 :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_ABS_ADDR), 0, 15, 16, 32, total_length, pc, & value);
        value = ((value) << (2));
        fields->f_p16 = value;
      }
      break;
    case MIST32_OPERAND_P16R :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_SIGNED)|(1<<CGEN_IFLD_PCREL_ADDR), 0, 15, 16, 32, total_length, pc, & value);
        value = ((((value) << (2))) + (((pc) & (-4))));
        fields->f_p16r = value;
      }
      break;
    case MIST32_OPERAND_RD :
      length = extract_normal (cd, ex_info, insn_value, 0, 0, 9, 5, 32, total_length, pc, & fields->f_rd);
      break;
    case MIST32_OPERAND_RS :
      length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_rs);
      break;
    case MIST32_OPERAND_UD6B :
      length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 6, 32, total_length, pc, & fields->f_ud6b);
      break;
    case MIST32_OPERAND_UD6H :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 6, 32, total_length, pc, & value);
        value = ((value) << (1));
        fields->f_ud6h = value;
      }
      break;
    case MIST32_OPERAND_UD6W :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 6, 32, total_length, pc, & value);
        value = ((value) << (2));
        fields->f_ud6w = value;
      }
      break;
    case MIST32_OPERAND_UI11 :
      {
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 15, 6, 32, total_length, pc, & fields->f_i11h);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_i11l);
        if (length <= 0) break;
{
  FLD (f_ui11) = ((((FLD (f_i11h)) << (5))) | (FLD (f_i11l)));
}
      }
      break;
    case MIST32_OPERAND_UI16L :
      {
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 20, 11, 32, total_length, pc, & fields->f_i16h);
        if (length <= 0) break;
        length = extract_normal (cd, ex_info, insn_value, 0, 0, 4, 5, 32, total_length, pc, & fields->f_i16l);
        if (length <= 0) break;
{
  FLD (f_ui16) = ((((FLD (f_i16h)) << (5))) | (FLD (f_i16l)));
}
      }
      break;
    case MIST32_OPERAND_UP16R :
      {
        long value;
        length = extract_normal (cd, ex_info, insn_value, 0|(1<<CGEN_IFLD_PCREL_ADDR), 0, 15, 16, 32, total_length, pc, & value);
        value = ((((value) << (2))) + (((pc) & (-4))));
        fields->f_up16r = value;
      }
      break;

    default :
      /* xgettext:c-format */
      fprintf (stderr, _("Unrecognized field %d while decoding insn.\n"),
	       opindex);
      abort ();
    }

  return length;
}

cgen_insert_fn * const mist32_cgen_insert_handlers[] = 
{
  insert_insn_normal,
};

cgen_extract_fn * const mist32_cgen_extract_handlers[] = 
{
  extract_insn_normal,
};

int mist32_cgen_get_int_operand     (CGEN_CPU_DESC, int, const CGEN_FIELDS *);
bfd_vma mist32_cgen_get_vma_operand (CGEN_CPU_DESC, int, const CGEN_FIELDS *);

/* Getting values from cgen_fields is handled by a collection of functions.
   They are distinguished by the type of the VALUE argument they return.
   TODO: floating point, inlining support, remove cases where result type
   not appropriate.  */

int
mist32_cgen_get_int_operand (CGEN_CPU_DESC cd ATTRIBUTE_UNUSED,
			     int opindex,
			     const CGEN_FIELDS * fields)
{
  int value;

  switch (opindex)
    {
    case MIST32_OPERAND_CC :
      value = fields->f_cc;
      break;
    case MIST32_OPERAND_CI16 :
      value = fields->f_ci16;
      break;
    case MIST32_OPERAND_CI16W :
      value = fields->f_ci16w;
      break;
    case MIST32_OPERAND_D6B :
      value = fields->f_d6b;
      break;
    case MIST32_OPERAND_D6H :
      value = fields->f_d6h;
      break;
    case MIST32_OPERAND_D6W :
      value = fields->f_d6w;
      break;
    case MIST32_OPERAND_I11 :
      value = fields->f_i11;
      break;
    case MIST32_OPERAND_I11W :
      value = fields->f_i11w;
      break;
    case MIST32_OPERAND_I16H :
      value = fields->f_ui16;
      break;
    case MIST32_OPERAND_I16L :
      value = fields->f_i16;
      break;
    case MIST32_OPERAND_P11B :
      value = fields->f_p11b;
      break;
    case MIST32_OPERAND_P11H :
      value = fields->f_p11h;
      break;
    case MIST32_OPERAND_P11W :
      value = fields->f_p11w;
      break;
    case MIST32_OPERAND_P16 :
      value = fields->f_p16;
      break;
    case MIST32_OPERAND_P16R :
      value = fields->f_p16r;
      break;
    case MIST32_OPERAND_RD :
      value = fields->f_rd;
      break;
    case MIST32_OPERAND_RS :
      value = fields->f_rs;
      break;
    case MIST32_OPERAND_UD6B :
      value = fields->f_ud6b;
      break;
    case MIST32_OPERAND_UD6H :
      value = fields->f_ud6h;
      break;
    case MIST32_OPERAND_UD6W :
      value = fields->f_ud6w;
      break;
    case MIST32_OPERAND_UI11 :
      value = fields->f_ui11;
      break;
    case MIST32_OPERAND_UI16L :
      value = fields->f_ui16;
      break;
    case MIST32_OPERAND_UP16R :
      value = fields->f_up16r;
      break;

    default :
      /* xgettext:c-format */
      fprintf (stderr, _("Unrecognized field %d while getting int operand.\n"),
		       opindex);
      abort ();
  }

  return value;
}

bfd_vma
mist32_cgen_get_vma_operand (CGEN_CPU_DESC cd ATTRIBUTE_UNUSED,
			     int opindex,
			     const CGEN_FIELDS * fields)
{
  bfd_vma value;

  switch (opindex)
    {
    case MIST32_OPERAND_CC :
      value = fields->f_cc;
      break;
    case MIST32_OPERAND_CI16 :
      value = fields->f_ci16;
      break;
    case MIST32_OPERAND_CI16W :
      value = fields->f_ci16w;
      break;
    case MIST32_OPERAND_D6B :
      value = fields->f_d6b;
      break;
    case MIST32_OPERAND_D6H :
      value = fields->f_d6h;
      break;
    case MIST32_OPERAND_D6W :
      value = fields->f_d6w;
      break;
    case MIST32_OPERAND_I11 :
      value = fields->f_i11;
      break;
    case MIST32_OPERAND_I11W :
      value = fields->f_i11w;
      break;
    case MIST32_OPERAND_I16H :
      value = fields->f_ui16;
      break;
    case MIST32_OPERAND_I16L :
      value = fields->f_i16;
      break;
    case MIST32_OPERAND_P11B :
      value = fields->f_p11b;
      break;
    case MIST32_OPERAND_P11H :
      value = fields->f_p11h;
      break;
    case MIST32_OPERAND_P11W :
      value = fields->f_p11w;
      break;
    case MIST32_OPERAND_P16 :
      value = fields->f_p16;
      break;
    case MIST32_OPERAND_P16R :
      value = fields->f_p16r;
      break;
    case MIST32_OPERAND_RD :
      value = fields->f_rd;
      break;
    case MIST32_OPERAND_RS :
      value = fields->f_rs;
      break;
    case MIST32_OPERAND_UD6B :
      value = fields->f_ud6b;
      break;
    case MIST32_OPERAND_UD6H :
      value = fields->f_ud6h;
      break;
    case MIST32_OPERAND_UD6W :
      value = fields->f_ud6w;
      break;
    case MIST32_OPERAND_UI11 :
      value = fields->f_ui11;
      break;
    case MIST32_OPERAND_UI16L :
      value = fields->f_ui16;
      break;
    case MIST32_OPERAND_UP16R :
      value = fields->f_up16r;
      break;

    default :
      /* xgettext:c-format */
      fprintf (stderr, _("Unrecognized field %d while getting vma operand.\n"),
		       opindex);
      abort ();
  }

  return value;
}

void mist32_cgen_set_int_operand  (CGEN_CPU_DESC, int, CGEN_FIELDS *, int);
void mist32_cgen_set_vma_operand  (CGEN_CPU_DESC, int, CGEN_FIELDS *, bfd_vma);

/* Stuffing values in cgen_fields is handled by a collection of functions.
   They are distinguished by the type of the VALUE argument they accept.
   TODO: floating point, inlining support, remove cases where argument type
   not appropriate.  */

void
mist32_cgen_set_int_operand (CGEN_CPU_DESC cd ATTRIBUTE_UNUSED,
			     int opindex,
			     CGEN_FIELDS * fields,
			     int value)
{
  switch (opindex)
    {
    case MIST32_OPERAND_CC :
      fields->f_cc = value;
      break;
    case MIST32_OPERAND_CI16 :
      fields->f_ci16 = value;
      break;
    case MIST32_OPERAND_CI16W :
      fields->f_ci16w = value;
      break;
    case MIST32_OPERAND_D6B :
      fields->f_d6b = value;
      break;
    case MIST32_OPERAND_D6H :
      fields->f_d6h = value;
      break;
    case MIST32_OPERAND_D6W :
      fields->f_d6w = value;
      break;
    case MIST32_OPERAND_I11 :
      fields->f_i11 = value;
      break;
    case MIST32_OPERAND_I11W :
      fields->f_i11w = value;
      break;
    case MIST32_OPERAND_I16H :
      fields->f_ui16 = value;
      break;
    case MIST32_OPERAND_I16L :
      fields->f_i16 = value;
      break;
    case MIST32_OPERAND_P11B :
      fields->f_p11b = value;
      break;
    case MIST32_OPERAND_P11H :
      fields->f_p11h = value;
      break;
    case MIST32_OPERAND_P11W :
      fields->f_p11w = value;
      break;
    case MIST32_OPERAND_P16 :
      fields->f_p16 = value;
      break;
    case MIST32_OPERAND_P16R :
      fields->f_p16r = value;
      break;
    case MIST32_OPERAND_RD :
      fields->f_rd = value;
      break;
    case MIST32_OPERAND_RS :
      fields->f_rs = value;
      break;
    case MIST32_OPERAND_UD6B :
      fields->f_ud6b = value;
      break;
    case MIST32_OPERAND_UD6H :
      fields->f_ud6h = value;
      break;
    case MIST32_OPERAND_UD6W :
      fields->f_ud6w = value;
      break;
    case MIST32_OPERAND_UI11 :
      fields->f_ui11 = value;
      break;
    case MIST32_OPERAND_UI16L :
      fields->f_ui16 = value;
      break;
    case MIST32_OPERAND_UP16R :
      fields->f_up16r = value;
      break;

    default :
      /* xgettext:c-format */
      fprintf (stderr, _("Unrecognized field %d while setting int operand.\n"),
		       opindex);
      abort ();
  }
}

void
mist32_cgen_set_vma_operand (CGEN_CPU_DESC cd ATTRIBUTE_UNUSED,
			     int opindex,
			     CGEN_FIELDS * fields,
			     bfd_vma value)
{
  switch (opindex)
    {
    case MIST32_OPERAND_CC :
      fields->f_cc = value;
      break;
    case MIST32_OPERAND_CI16 :
      fields->f_ci16 = value;
      break;
    case MIST32_OPERAND_CI16W :
      fields->f_ci16w = value;
      break;
    case MIST32_OPERAND_D6B :
      fields->f_d6b = value;
      break;
    case MIST32_OPERAND_D6H :
      fields->f_d6h = value;
      break;
    case MIST32_OPERAND_D6W :
      fields->f_d6w = value;
      break;
    case MIST32_OPERAND_I11 :
      fields->f_i11 = value;
      break;
    case MIST32_OPERAND_I11W :
      fields->f_i11w = value;
      break;
    case MIST32_OPERAND_I16H :
      fields->f_ui16 = value;
      break;
    case MIST32_OPERAND_I16L :
      fields->f_i16 = value;
      break;
    case MIST32_OPERAND_P11B :
      fields->f_p11b = value;
      break;
    case MIST32_OPERAND_P11H :
      fields->f_p11h = value;
      break;
    case MIST32_OPERAND_P11W :
      fields->f_p11w = value;
      break;
    case MIST32_OPERAND_P16 :
      fields->f_p16 = value;
      break;
    case MIST32_OPERAND_P16R :
      fields->f_p16r = value;
      break;
    case MIST32_OPERAND_RD :
      fields->f_rd = value;
      break;
    case MIST32_OPERAND_RS :
      fields->f_rs = value;
      break;
    case MIST32_OPERAND_UD6B :
      fields->f_ud6b = value;
      break;
    case MIST32_OPERAND_UD6H :
      fields->f_ud6h = value;
      break;
    case MIST32_OPERAND_UD6W :
      fields->f_ud6w = value;
      break;
    case MIST32_OPERAND_UI11 :
      fields->f_ui11 = value;
      break;
    case MIST32_OPERAND_UI16L :
      fields->f_ui16 = value;
      break;
    case MIST32_OPERAND_UP16R :
      fields->f_up16r = value;
      break;

    default :
      /* xgettext:c-format */
      fprintf (stderr, _("Unrecognized field %d while setting vma operand.\n"),
		       opindex);
      abort ();
  }
}

/* Function to call before using the instruction builder tables.  */

void
mist32_cgen_init_ibld_table (CGEN_CPU_DESC cd)
{
  cd->insert_handlers = & mist32_cgen_insert_handlers[0];
  cd->extract_handlers = & mist32_cgen_extract_handlers[0];

  cd->insert_operand = mist32_cgen_insert_operand;
  cd->extract_operand = mist32_cgen_extract_operand;

  cd->get_int_operand = mist32_cgen_get_int_operand;
  cd->set_int_operand = mist32_cgen_set_int_operand;
  cd->get_vma_operand = mist32_cgen_get_vma_operand;
  cd->set_vma_operand = mist32_cgen_set_vma_operand;
}
