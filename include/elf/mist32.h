/* mist32 ELF support for BFD.
   Copyright 1999, 2000, 2010 Free Software Foundation, Inc.
   Written by Hirotaka Kawata <hirotaka@techno-st.net>

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
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _ELF_MIST32_H
#define _ELF_MIST32_H

#include "elf/reloc-macros.h"


START_RELOC_NUMBERS (elf_mist32_reloc_type)
     RELOC_NUMBER (R_MIST32_NONE, 0)
     RELOC_NUMBER (R_MIST32_32, 1)
END_RELOC_NUMBERS (R_MIST32_max)

#endif /* _ELF_MIST32_H */
