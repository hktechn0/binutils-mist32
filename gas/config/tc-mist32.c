/* tc-mist32.c -- Assembler for the mist32.
   Copyright 2011
   Free Software Foundation. Inc.
   Contributed by Hirotaka Kawata <hirotaka@techno-st.net>

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

typedef struct mist32_insn mist32_insn;

struct mist32_insn
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
};

const char comment_chars[]        = ";";
const char line_comment_chars[]   = "#;";
const char line_separator_chars[] = "!";
const char EXP_CHARS[]            = "eE";
const char FLT_CHARS[]            = "RrFf";

/* options */
const char *md_shortopts = "";

struct option md_longopts[] = {
  {NULL, no_argument, NULL, 0}
};
size_t md_longopts_size = sizeof (md_longopts);

unsigned long mist32_machine = 0; /* default */

int
md_parse_option (int c ATTRIBUTE_UNUSED, char * arg ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_show_usage (FILE * stream ATTRIBUTE_UNUSED)
{
}

/* support pseudo-opts */
const pseudo_typeS md_pseudo_table[] =
{
  { NULL, 	NULL, 		0 }
};

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
}

void
md_assemble (char *str)
{
  mist32_insn insn;
  char *errmsg;
  
  /* Initialize GAS's cgen interface for a new instruction.  */
  gas_cgen_init_parse ();
  
  insn.insn = mist32_cgen_assemble_insn
    (gas_cgen_cpu_desc, str, & insn.fields, insn.buffer, &errmsg);
  
  if (!insn.insn)
    {
      as_bad ("%s", errmsg);
      return;
    }
  
  /* Doesn't really matter what we pass for RELAX_P here.  */
  gas_cgen_finish_insn (insn.insn, insn.buffer,
			CGEN_FIELDS_BITSIZE (& insn.fields), 1, NULL);
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

/* Interface to relax_segment.  */
int
md_estimate_size_before_relax (fragS *fragP ATTRIBUTE_UNUSED, segT segment ATTRIBUTE_UNUSED)
{
  /* No assembler relaxation is defined (or necessary) for this port.  */
  abort ();
} 

void
md_convert_frag (bfd *   abfd ATTRIBUTE_UNUSED,
		 segT    sec ATTRIBUTE_UNUSED,
		 fragS * fragP ATTRIBUTE_UNUSED)
{
  /* No assembler relaxation is defined (or necessary) for this port.  */
  abort ();
}


/* Functions concerning relocs.  */

/* The location from which a PC relative jump should be calculated,
   given a PC relative reloc. */

long
md_pcrel_from_section (fixS * fixP, segT sec)
{
  if (fixP->fx_addsy != (symbolS *) NULL
      && (! S_IS_DEFINED (fixP->fx_addsy)
	  || S_GET_SEGMENT (fixP->fx_addsy) != sec
          || S_IS_EXTERNAL (fixP->fx_addsy)
          || S_IS_WEAK (fixP->fx_addsy)))
    {
      if (S_GET_SEGMENT (fixP->fx_addsy) != sec
          && S_IS_DEFINED (fixP->fx_addsy)
          && ! S_IS_EXTERNAL (fixP->fx_addsy)
          && ! S_IS_WEAK (fixP->fx_addsy))
        return fixP->fx_offset;

    /* The symbol is undefined (or is defined but not in this section).
       Let the linker figure it out. */
    return 0;
  }

  return (fixP->fx_frag->fr_address + fixP->fx_where) & ~3;
}

/* Return the bfd reloc type for OPERAND of INSN at fixup FIXP.
   Returns BFD_RELOC_NONE if no reloc type can be found.
   *FIXP may be modified if desired. */

bfd_reloc_code_real_type
md_cgen_lookup_reloc (const CGEN_INSN *    insn ATTRIBUTE_UNUSED,
		      const CGEN_OPERAND * operand,
		      fixS *               fixP)
{
  fixP->fx_pcrel = 0;

  switch (operand->type)
    {
    case MIST32_OPERAND_P11B:
      return BFD_RELOC_MIST32_ABS_11B;
    case MIST32_OPERAND_P11H:
      return BFD_RELOC_MIST32_ABS_11H;
    case MIST32_OPERAND_P11W:
      return BFD_RELOC_MIST32_ABS_11;

    case MIST32_OPERAND_P16:
      return BFD_RELOC_MIST32_ABS_16;

    case MIST32_OPERAND_P16R:
      fixP->fx_pcrel = 1;
      return BFD_RELOC_MIST32_REL_16;
    case MIST32_OPERAND_UP16R:
      fixP->fx_pcrel = 1;
      return BFD_RELOC_MIST32_REL_U16;

    case MIST32_OPERAND_I16H:
      return BFD_RELOC_HI16;
    case MIST32_OPERAND_I16L:
    case MIST32_OPERAND_UI16L:
      return BFD_RELOC_LO16;

    default : /* Avoid -Wall warning.  */
      break;
    }

  return BFD_RELOC_NONE;
}

/* Write a value out to the object file, using the appropriate endianness.  */

void
md_number_to_chars (char * buf, valueT val, int n)
{
  number_to_chars_bigendian (buf, val, n);
}

/* Turn a string in input_line_pointer into a floating point constant of type
   type, and store the appropriate bytes in *litP.  The number of LITTLENUMS
   emitted is stored in *sizeP .  An error message is returned, or NULL on OK.
*/

/* Equal to MAX_PRECISION in atof-ieee.c.  */
#define MAX_LITTLENUMS 6

char *
md_atof (int type, char *litP, int *sizeP)
{
  return ieee_md_atof (type, litP, sizeP, TRUE);
}
