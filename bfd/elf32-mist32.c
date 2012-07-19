/* mist32 support for 32-bit ELF
   Copyright 2011 Free Software Foundation, Inc.
   Written by Hirotaka Kawata (hirotaka@techno-st.net)

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf/mist32.h"
#include "libiberty.h"

/* R_MIST32_INSN_HI16 relocation for I16 format.  */

static bfd_reloc_status_type
mist32_elf_hi16_reloc (bfd *abfd,
		       arelent *reloc_entry,
		       asymbol *symbol,
		       void * data,
		       asection *input_section,
		       bfd *output_bfd,
		       char **error_message ATTRIBUTE_UNUSED)
{
  bfd_reloc_status_type ret;
  bfd_vma relocation;
  bfd_byte *addr;
  unsigned long insn;
  
  /* This part is from bfd_elf_generic_reloc.
     If we're relocating, and this an external symbol, we don't want
     to change anything.  */
  if (output_bfd != NULL
      && (symbol->flags & BSF_SECTION_SYM) == 0
      && (! reloc_entry->howto->partial_inplace
	  || reloc_entry->addend == 0))
    {
      reloc_entry->address += input_section->output_offset;
      return bfd_reloc_ok;
    }

  /* Sanity check the address (offset in section).  */
  if (reloc_entry->address > bfd_get_section_limit (abfd, input_section))
    return bfd_reloc_outofrange;

  ret = bfd_reloc_ok;
  if (bfd_is_und_section (symbol->section)
      && output_bfd == NULL)
    ret = bfd_reloc_undefined;

  if (bfd_is_com_section (symbol->section))
    relocation = 0;
  else
    relocation = symbol->value;

  relocation += symbol->section->output_section->vma;
  relocation += symbol->section->output_offset;
  relocation += reloc_entry->addend;

  /* adjust I16 format immediate */
  relocation = (relocation >> 16) & 0x0000ffff;
  relocation = (relocation & 0x001f) | ((relocation & 0xffe0) << 5);

  /* reloc insn */
  addr = (bfd_byte *) data + reloc_entry->address;
  insn = bfd_get_32 (abfd, addr);
  insn = (insn & 0xffe003e0) | relocation;
  bfd_put_32 (abfd, (bfd_vma) insn, addr);

  if (output_bfd != NULL)
    reloc_entry->address += input_section->output_offset;

  return ret;
}

/* R_MIST32_INSN_LO16 relocation for I16 format.  */

static bfd_reloc_status_type
mist32_elf_lo16_reloc (bfd *abfd,
		       arelent *reloc_entry,
		       asymbol *symbol,
		       void * data,
		       asection *input_section,
		       bfd *output_bfd,
		       char **error_message ATTRIBUTE_UNUSED)
{
  bfd_reloc_status_type ret;
  bfd_vma relocation;
  bfd_byte *addr;
  unsigned long insn;
  
  /* This part is from bfd_elf_generic_reloc.
     If we're relocating, and this an external symbol, we don't want
     to change anything.  */
  if (output_bfd != NULL
      && (symbol->flags & BSF_SECTION_SYM) == 0
      && (! reloc_entry->howto->partial_inplace
	  || reloc_entry->addend == 0))
    {
      reloc_entry->address += input_section->output_offset;
      return bfd_reloc_ok;
    }

  /* Sanity check the address (offset in section).  */
  if (reloc_entry->address > bfd_get_section_limit (abfd, input_section))
    return bfd_reloc_outofrange;

  ret = bfd_reloc_ok;
  if (bfd_is_und_section (symbol->section)
      && output_bfd == NULL)
    ret = bfd_reloc_undefined;

  if (bfd_is_com_section (symbol->section))
    relocation = 0;
  else
    relocation = symbol->value;

  relocation += symbol->section->output_section->vma;
  relocation += symbol->section->output_offset;
  relocation += reloc_entry->addend;

  /* adjust I16 format immediate */
  relocation &=  0x0000ffff;
  relocation = (relocation & 0x001f) | ((relocation & 0xffe0) << 5);

  /* reloc insn */
  addr = (bfd_byte *) data + reloc_entry->address;
  insn = bfd_get_32 (abfd, addr);
  insn = (insn & 0xffe003e0) | relocation;
  bfd_put_32 (abfd, (bfd_vma) insn, addr);

  if (output_bfd != NULL)
    reloc_entry->address += input_section->output_offset;

  return ret;
}

/* HOWTO */

static reloc_howto_type mist32_elf_howto_table[]=
{
  /* This reloc does nothing.  */
  HOWTO (R_MIST32_NONE,	        /* type */
	 0,			/* rightshift */
	 0,			/* size (0 = byte, 1 = short, 2 = long) */
	 32,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_bitfield, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_NONE",	/* name */
	 FALSE,			/* partial_inplace */
	 0,			/* src_mask */
	 0,			/* dst_mask */
	 FALSE),		/* pcrel_offset */

  /* A PC relative signed 16 bit relocation, right shifted by 2.  */
  HOWTO (R_MIST32_INSN_REL_16,  /* type */
	 2,			/* rightshift */
	 2,			/* size (0 = byte, 1 = short, 2 = long) */
	 16,			/* bitsize */
	 TRUE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_signed, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_INSN_REL_16", /* name */
	 FALSE,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x0000ffff,		/* dst_mask */
	 TRUE),			/* pcrel_offset */

  /* A PC relative unsigned 16 bit relocation, right shifted by 2.  */
  HOWTO (R_MIST32_INSN_REL_U16, /* type */
	 2,			/* rightshift */
	 2,			/* size (0 = byte, 1 = short, 2 = long) */
	 16,			/* bitsize */
	 TRUE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_unsigned, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_INSN_REL_U16", /* name */
	 FALSE,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x0000ffff,		/* dst_mask */
	 TRUE),			/* pcrel_offset */

  /* A absolute 16 bit relocation, right shifted by 2.  */
  HOWTO (R_MIST32_INSN_ABS_16,  /* type */
	 2,			/* rightshift */
	 2,			/* size (0 = byte, 1 = short, 2 = long) */
	 16,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_signed, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_INSN_ABS_16", /* name */
	 FALSE,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x0000ffff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */

  /* Lower 16 bits of address. */
  HOWTO (R_MIST32_INSN_LO_16,   /* type */
	 0,			/* rightshift */
	 1,			/* size (0 = byte, 1 = short, 2 = long) */
	 16,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_dont, /* complain_on_overflow */
	 mist32_elf_lo16_reloc,	/* special_function */
	 "R_MIST32_INSN_LO_16", /* name */
	 FALSE,			/* partial_inplace */
	 0,			/* src_mask */
	 0x0000ffff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */

  /* High 16 bits of address. */
  HOWTO (R_MIST32_INSN_HI_16,   /* type */
	 16,			/* rightshift */
	 1,			/* size (0 = byte, 1 = short, 2 = long) */
	 16,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_dont, /* complain_on_overflow */
	 mist32_elf_hi16_reloc,	/* special_function */
	 "R_MIST32_INSN_HI_16",	/* name */
	 FALSE,			/* partial_inplace */
	 0,			/* src_mask */
	 0x0000ffff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */

  /* A 8 bit absolute relocation.  */
  HOWTO (R_MIST32_8,		/* type */
	 0,			/* rightshift */
	 0,			/* size (0 = byte, 1 = short, 2 = long) */
	 8,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_bitfield, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_8",		/* name */
	 TRUE,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x000000ff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */

  /* A 16 bit absolute relocation.  */
  HOWTO (R_MIST32_16,		/* type */
	 0,			/* rightshift */
	 1,			/* size (0 = byte, 1 = short, 2 = long) */
	 16,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_bitfield, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_16",		/* name */
	 TRUE,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x0000ffff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */

  /* A 32 bit absolute relocation.  */
  HOWTO (R_MIST32_32,		/* type */
	 0,			/* rightshift */
	 2,			/* size (0 = byte, 1 = short, 2 = long) */
	 32,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_bitfield, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_32",		/* name */
	 TRUE,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0xffffffff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */

};

/* Map BFD reloc types to mist32 ELF reloc types.  */

struct mist32_reloc_map
{
  bfd_reloc_code_real_type bfd_reloc_val;
  unsigned int mist32_reloc_val;
};

static const struct mist32_reloc_map mist32_reloc_map [] =
{
  { BFD_RELOC_NONE,		R_MIST32_NONE },
  { BFD_RELOC_32,		R_MIST32_32 },
  { BFD_RELOC_16,		R_MIST32_16 },
  { BFD_RELOC_8,		R_MIST32_8 },
  { BFD_RELOC_MIST32_REL_16,	R_MIST32_INSN_REL_16 },
  { BFD_RELOC_MIST32_REL_U16,	R_MIST32_INSN_REL_U16 },
  { BFD_RELOC_MIST32_ABS_16,	R_MIST32_INSN_ABS_16 },
  { BFD_RELOC_HI16, 		R_MIST32_INSN_HI_16 },
  { BFD_RELOC_LO16, 		R_MIST32_INSN_LO_16 }
};

static reloc_howto_type *
mist32_reloc_type_lookup
    (bfd *                    abfd ATTRIBUTE_UNUSED,
     bfd_reloc_code_real_type code)
{
  unsigned int i;

  for (i = ARRAY_SIZE (mist32_reloc_map); --i;)
    if (mist32_reloc_map [i].bfd_reloc_val == code)
      return & mist32_elf_howto_table [mist32_reloc_map[i].mist32_reloc_val];
  
  return NULL;
}

static reloc_howto_type *
mist32_reloc_name_lookup (bfd *abfd ATTRIBUTE_UNUSED, const char *r_name)
{
  unsigned int i;

  for (i = 0;
       i < sizeof (mist32_elf_howto_table) / sizeof (mist32_elf_howto_table[0]);
       i++)
    if (mist32_elf_howto_table[i].name != NULL
	&& strcasecmp (mist32_elf_howto_table[i].name, r_name) == 0)
      return &mist32_elf_howto_table[i];

  return NULL;
}

static void
mist32_info_to_howto
    (bfd *               abfd ATTRIBUTE_UNUSED,
     arelent *           cache_ptr,
     Elf_Internal_Rela * dst)
{
  unsigned int r_type;

  r_type = ELF32_R_TYPE (dst->r_info);
  BFD_ASSERT (r_type < (unsigned int) R_MIST32_max);
  cache_ptr->howto = & mist32_elf_howto_table [r_type];
}



#define ELF_ARCH		bfd_arch_mist32
#define ELF_MACHINE_CODE	EM_MIST32
#define ELF_MACHINE_ALT1	EM_MIST32
#define ELF_MAXPAGESIZE  	0x4000

#define TARGET_BIG_SYM		mist32_elf32_vec
#define TARGET_BIG_NAME		"elf32-mist32"

#define elf_info_to_howto_rel		NULL
#define elf_info_to_howto		mist32_info_to_howto

#define elf_backend_can_gc_sections	1
#define elf_backend_rela_normal		1

#define bfd_elf32_bfd_reloc_type_lookup mist32_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup mist32_reloc_name_lookup

#include "elf32-target.h"
