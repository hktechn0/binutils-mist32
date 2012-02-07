/* tc-mist32.h -- Header file for the mist32.
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


#define TC_MI32

#define LISTING_HEADER "MIST32 GAS "

#define TARGET_ARCH bfd_arch_mist32

#define TARGET_FORMAT "elf32-mist32"

#define TARGET_BYTES_BIG_ENDIAN 1

#define WORKING_DOT_WORD

long md_pcrel_from_section (struct fix *, segT);
#define MD_PCREL_FROM_SECTION(FIXP, SEC) md_pcrel_from_section (FIXP, SEC)
