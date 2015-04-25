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

static reloc_howto_type mist32_elf_howto_table[]=
{
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

  HOWTO (R_MIST32_32,		/* type */
	 0,			/* rightshift */
	 2,			/* size (0 = byte, 1 = short, 2 = long) */
	 32,			/* bitsize */
	 FALSE,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_bitfield, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_MIST32_32",		/* name */
	 FALSE,			/* partial_inplace */
	 0,			/* src_mask */
	 0xffffffff,		/* dst_mask */
	 FALSE),		/* pcrel_offset */
};

struct mist32_reloc_map
{
  bfd_reloc_code_real_type bfd_reloc_val;
  unsigned int mist32_reloc_val;
};

static const struct mist32_reloc_map mist32_reloc_map [] =
{
  { BFD_RELOC_NONE,		R_MIST32_NONE },
  { BFD_RELOC_32,		R_MIST32_32 },
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
mist32_info_to_howto_rela
    (bfd *               abfd ATTRIBUTE_UNUSED,
     arelent *           cache_ptr,
     Elf_Internal_Rela * dst)
{
  unsigned int r_type;

  r_type = ELF32_R_TYPE (dst->r_info);
  BFD_ASSERT (r_type < (unsigned int) R_MIST32_max);
  cache_ptr->howto = & mist32_elf_howto_table [r_type];
}



#define TARGET_BIG_SYM		mist32_elf32_vec
#define TARGET_BIG_NAME		"elf32-mist32"
#define ELF_ARCH		bfd_arch_mist32
#define ELF_MACHINE_CODE	EM_MIST32
#define ELF_MAXPAGESIZE  	0x4000

#define bfd_elf32_bfd_reloc_type_lookup mist32_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup mist32_reloc_name_lookup
#define elf_info_to_howto		mist32_info_to_howto_rela

#include "elf32-target.h"
