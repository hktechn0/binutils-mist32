/* tc-mist32.c -- Assembler for the mist32.
   Copyright 2011
   Free Software Foundation. Inc.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to
   the Free Software Foundation, 51 Franklin Street - Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#include "as.h"
#include "subsegs.h"     
#include "symcat.h"
#include "opcodes/mist32-desc.h"
#include "opcodes/mist32-opc.h"
#include "cgen.h"
#include "elf/common.h"
#include "elf/mist32.h"
#include "libbfd.h"
#include "safe-ctype.h"

const char comment_chars[]        = ";";
const char line_comment_chars[]   = "#;";
const char line_separator_chars[] = "";
const char EXP_CHARS[]            = "eE";
const char FLT_CHARS[]            = "RrFf";

#define DEFAULT_MACHINE bfd_mach_mist32
static unsigned long mist32_mach = bfd_mach_mist32;

typedef struct
{
  const CGEN_INSN *	insn;
  const CGEN_INSN *	orig_insn;
  CGEN_FIELDS		fields;
#if CGEN_INT_INSN_P
  CGEN_INSN_INT         buffer [1];
#define INSN_VALUE(buf) (*(buf))
#else
  unsigned char         buffer [CGEN_MAX_INSN_SIZE];
#define INSN_VALUE(buf) (buf)
#endif
  char *		addr;
  fragS *		frag;
  int                   num_fixups;
  fixS *                fixups [GAS_CGEN_MAX_FIXUPS];
  int                   indices [MAX_OPERAND_INSTANCES];
}
mist32_insn;

/* options */
const char *md_shortopts = "";
struct option md_longopts[] = {
  {NULL, no_argument, NULL, 0}
};
size_t md_longopts_size = sizeof (md_longopts);

/* support pseudo-opts */
const pseudo_typeS md_pseudo_table[] =
{
  { NULL, 	NULL, 		0 }
};


int
md_parse_option (int c, char * arg ATTRIBUTE_UNUSED)
{
  switch(c)
    {
    default:
      break;
    }
  return 0;
}

void
md_show_usage (FILE * stream)
{
  fprintf (stream, _(" mist32 specific command line options:\n"));
}

void
md_begin (void)
{
  /* Initialize the `cgen' interface.  */

  /* Set the machine number and endian.  */
  gas_cgen_cpu_desc = mist32_cgen_cpu_open (CGEN_CPU_OPEN_MACHS, 0,
					      CGEN_CPU_OPEN_ENDIAN,
					      CGEN_ENDIAN_BIG,
					      CGEN_CPU_OPEN_END);

  mist32_cgen_init_asm (gas_cgen_cpu_desc);

  /* This is a callback from cgen to gas to parse operands.  */
  cgen_set_parse_operand_fn (gas_cgen_cpu_desc, gas_cgen_parse_operand);

  /* Set the ELF flags if desired. */
  /*  if (m32c_flags)
      bfd_set_private_flags (stdoutput, m32c_flags);*/

  /* Set the machine type */
  bfd_default_set_arch_mach (stdoutput, bfd_arch_mist32, mist32_mach);
}

void
md_assemble (char *str)
{
  mist32_insn insn;
  char *errmsg;
  finished_insnS results;
  
  /* Initialize GAS's cgen interface for a new instruction.  */
  gas_cgen_init_parse ();
  
  memset (&insn, 0, sizeof (insn));
  
  insn.insn = mist32_cgen_assemble_insn
    (gas_cgen_cpu_desc, str, & insn.fields, insn.buffer, &errmsg);
  
  if (!insn.insn)
    {
      as_bad ("%s", errmsg);
      return;
    }
  
  /* Doesn't really matter what we pass for RELAX_P here.  */
  gas_cgen_finish_insn (insn.insn, insn.buffer,
			CGEN_FIELDS_BITSIZE (& insn.fields), 1, &results);
}

/* The syntax in the manual says constants begin with '#'.
   We just ignore it.  */

void 
md_operand (expressionS *expressionP)
{
  if (* input_line_pointer == '#')
    {
      input_line_pointer ++;
      expression (expressionP);
    }
}

valueT
md_section_align (segT segment, valueT size)
{
  int align = bfd_get_section_alignment (stdoutput, segment);
  return ((size + (1 << align) - 1) & (-1 << align));
}

symbolS *
md_undefined_symbol (char *name ATTRIBUTE_UNUSED)
{
  return 0;
}

char *
md_atof (int type, char *litP, int *sizeP)
{
  return ieee_md_atof (type, litP, sizeP, TRUE);
}

void
md_convert_frag (bfd *   abfd ATTRIBUTE_UNUSED,
		 segT    sec ATTRIBUTE_UNUSED,
		 fragS * fragP ATTRIBUTE_UNUSED)
{
  /* No assembler relaxation is defined (or necessary) for this port.  */
  abort ();
}

long
md_pcrel_from_section (fixS * fixP, segT sec)
{
  if (fixP->fx_addsy != (symbolS *) NULL
      && (! S_IS_DEFINED (fixP->fx_addsy)
	  || S_GET_SEGMENT (fixP->fx_addsy) != sec))
    /* The symbol is undefined (or is defined but not in this section).
       Let the linker figure it out.  */
    return 0;

  return (fixP->fx_frag->fr_address + fixP->fx_where);
}

void
md_number_to_chars (char * buf, valueT val, int n)
{
  number_to_chars_bigendian (buf, val, n);
}


int
md_estimate_size_before_relax (fragS *fragP ATTRIBUTE_UNUSED, segT segment ATTRIBUTE_UNUSED)
{
  /* No assembler relaxation is defined (or necessary) for this port.  */
  abort ();
} 

arelent *
tc_gen_reloc (asection *sec, fixS *fx)
{
  /*  if (fx->fx_r_type == BFD_RELOC_M32C_RL_JUMP
      || fx->fx_r_type == BFD_RELOC_M32C_RL_1ADDR
      || fx->fx_r_type == BFD_RELOC_M32C_RL_2ADDR)*/
  if(0)
    {
      arelent * reloc;
 
      reloc = xmalloc (sizeof (* reloc));
 
      reloc->sym_ptr_ptr = xmalloc (sizeof (asymbol *));
      *reloc->sym_ptr_ptr = symbol_get_bfdsym (fx->fx_addsy);
      reloc->address = fx->fx_frag->fr_address + fx->fx_where;
      reloc->howto = bfd_reloc_type_lookup (stdoutput, fx->fx_r_type);
      reloc->addend = fx->fx_offset;
      return reloc;

    }
  return gas_cgen_tc_gen_reloc (sec, fx);
}

void
md_apply_fix (struct fix *f, valueT *t, segT s)
{
  /*  if (f->fx_r_type == BFD_RELOC_M32C_RL_JUMP
      || f->fx_r_type == BFD_RELOC_M32C_RL_1ADDR
      || f->fx_r_type == BFD_RELOC_M32C_RL_2ADDR)
    return;
  */
  gas_cgen_md_apply_fix (f, t, s);
}

/* Return the bfd reloc type for OPERAND of INSN at fixup FIXP.
   Returns BFD_RELOC_NONE if no reloc type can be found.
   *FIXP may be modified if desired.  */

bfd_reloc_code_real_type
md_cgen_lookup_reloc (const CGEN_INSN *    insn ATTRIBUTE_UNUSED,
		      const CGEN_OPERAND * operand,
		      fixS *               fixP ATTRIBUTE_UNUSED)
{
  switch (operand->type)
    {
    case MIST32_OPERAND_I11:  return BFD_RELOC_NONE;
      /*
	case MIST32_OPERAND_xx: fixP->fx_pcrel = 1; return BFD_RELOC_32;
      */
    default : /* Avoid -Wall warning.  */
      break;
    }

  return BFD_RELOC_NONE;
}
