/* CPU data header for mist32.

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

#ifndef MIST32_CPU_H
#define MIST32_CPU_H

#define CGEN_ARCH mist32

/* Given symbol S, return mist32_cgen_<S>.  */
#define CGEN_SYM(s) mist32##_cgen_##s


/* Selected cpu families.  */
#define HAVE_CPU_MIST32

#define CGEN_INSN_LSB0_P 1

/* Minimum size of any insn (in bytes).  */
#define CGEN_MIN_INSN_SIZE 4

/* Maximum size of any insn (in bytes).  */
#define CGEN_MAX_INSN_SIZE 4

#define CGEN_INT_INSN_P 1

/* Maximum number of syntax elements in an instruction.  */
#define CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS 12

/* CGEN_MNEMONIC_OPERANDS is defined if mnemonics have operands.
   e.g. In "b,a foo" the ",a" is an operand.  If mnemonics have operands
   we can't hash on everything up to the space.  */
#define CGEN_MNEMONIC_OPERANDS

/* Maximum number of fields in an instruction.  */
#define CGEN_ACTUAL_MAX_IFMT_OPERANDS 7

/* Enums.  */

/* Enum declaration for insn ext enums.  */
typedef enum insn_ext {
  EXT_0
} INSN_EXT;

/* Enum declaration for insn opcode enums.  */
typedef enum insn_op1 {
  OP_0, OP_1, OP_2, OP_3
 , OP_4, OP_5, OP_6, OP_7
 , OP_8, OP_9, OP_10, OP_11
 , OP_12, OP_13, OP_14, OP_15
 , OP_16, OP_17, OP_18, OP_19
 , OP_20, OP_21, OP_22, OP_23
 , OP_24, OP_25, OP_26, OP_27
 , OP_28, OP_29, OP_30, OP_31
 , OP_32, OP_33, OP_34, OP_35
 , OP_36, OP_37, OP_38, OP_39
 , OP_40, OP_41, OP_42, OP_43
 , OP_44, OP_45, OP_46, OP_47
 , OP_48, OP_49, OP_50, OP_51
 , OP_52, OP_53, OP_54, OP_55
 , OP_56, OP_57, OP_58, OP_59
 , OP_60, OP_61, OP_62, OP_63
 , OP_64, OP_65, OP_66, OP_67
 , OP_68, OP_69, OP_70, OP_71
 , OP_72, OP_73, OP_74, OP_75
 , OP_76, OP_77, OP_78, OP_79
 , OP_80, OP_81, OP_82, OP_83
 , OP_84, OP_85, OP_86, OP_87
 , OP_88, OP_89, OP_90, OP_91
 , OP_92, OP_93, OP_94, OP_95
 , OP_96, OP_97, OP_98, OP_99
 , OP_100, OP_101, OP_102, OP_103
 , OP_104, OP_105, OP_106, OP_107
 , OP_108, OP_109, OP_110, OP_111
 , OP_112, OP_113, OP_114, OP_115
 , OP_116, OP_117, OP_118, OP_119
 , OP_120, OP_121, OP_122, OP_123
 , OP_124, OP_125, OP_126, OP_127
 , OP_128, OP_129, OP_130, OP_131
 , OP_132, OP_133, OP_134, OP_135
 , OP_136, OP_137, OP_138, OP_139
 , OP_140, OP_141, OP_142, OP_143
 , OP_144, OP_145, OP_146, OP_147
 , OP_148, OP_149, OP_150, OP_151
 , OP_152, OP_153, OP_154, OP_155
 , OP_156, OP_157, OP_158, OP_159
 , OP_160, OP_161, OP_162, OP_163
 , OP_164, OP_165, OP_166, OP_167
 , OP_168, OP_169, OP_170, OP_171
 , OP_172, OP_173, OP_174, OP_175
 , OP_176, OP_177, OP_178, OP_179
 , OP_180, OP_181, OP_182, OP_183
 , OP_184, OP_185, OP_186, OP_187
 , OP_188, OP_189, OP_190, OP_191
 , OP_192, OP_193, OP_194, OP_195
 , OP_196, OP_197, OP_198, OP_199
 , OP_200, OP_201, OP_202, OP_203
 , OP_204, OP_205, OP_206, OP_207
 , OP_208, OP_209, OP_210, OP_211
 , OP_212, OP_213, OP_214, OP_215
 , OP_216, OP_217, OP_218, OP_219
 , OP_220, OP_221, OP_222, OP_223
 , OP_224, OP_225, OP_226, OP_227
 , OP_228, OP_229, OP_230, OP_231
 , OP_232, OP_233, OP_234, OP_235
 , OP_236, OP_237, OP_238, OP_239
 , OP_240, OP_241, OP_242, OP_243
 , OP_244, OP_245, OP_246, OP_247
 , OP_248, OP_249, OP_250, OP_251
 , OP_252, OP_253, OP_254, OP_255
 , OP_256, OP_257, OP_258, OP_259
 , OP_260, OP_261, OP_262, OP_263
 , OP_264, OP_265, OP_266, OP_267
 , OP_268, OP_269, OP_270, OP_271
 , OP_272, OP_273, OP_274, OP_275
 , OP_276, OP_277, OP_278, OP_279
 , OP_280, OP_281, OP_282, OP_283
 , OP_284, OP_285, OP_286, OP_287
 , OP_288, OP_289, OP_290, OP_291
 , OP_292, OP_293, OP_294, OP_295
 , OP_296, OP_297, OP_298, OP_299
 , OP_300, OP_301, OP_302, OP_303
 , OP_304, OP_305, OP_306, OP_307
 , OP_308, OP_309, OP_310, OP_311
 , OP_312, OP_313, OP_314, OP_315
 , OP_316, OP_317, OP_318, OP_319
 , OP_320, OP_321, OP_322, OP_323
 , OP_324, OP_325, OP_326, OP_327
 , OP_328, OP_329, OP_330, OP_331
 , OP_332, OP_333, OP_334, OP_335
 , OP_336, OP_337, OP_338, OP_339
 , OP_340, OP_341, OP_342, OP_343
 , OP_344, OP_345, OP_346, OP_347
 , OP_348, OP_349, OP_350, OP_351
 , OP_352, OP_353, OP_354, OP_355
 , OP_356, OP_357, OP_358, OP_359
 , OP_360, OP_361, OP_362, OP_363
 , OP_364, OP_365, OP_366, OP_367
 , OP_368, OP_369, OP_370, OP_371
 , OP_372, OP_373, OP_374, OP_375
 , OP_376, OP_377, OP_378, OP_379
 , OP_380, OP_381, OP_382, OP_383
 , OP_384, OP_385, OP_386, OP_387
 , OP_388, OP_389, OP_390, OP_391
 , OP_392, OP_393, OP_394, OP_395
 , OP_396, OP_397, OP_398, OP_399
 , OP_400, OP_401, OP_402, OP_403
 , OP_404, OP_405, OP_406, OP_407
 , OP_408, OP_409, OP_410, OP_411
 , OP_412, OP_413, OP_414, OP_415
 , OP_416, OP_417, OP_418, OP_419
 , OP_420, OP_421, OP_422, OP_423
 , OP_424, OP_425, OP_426, OP_427
 , OP_428, OP_429, OP_430, OP_431
 , OP_432, OP_433, OP_434, OP_435
 , OP_436, OP_437, OP_438, OP_439
 , OP_440, OP_441, OP_442, OP_443
 , OP_444, OP_445, OP_446, OP_447
 , OP_448, OP_449, OP_450, OP_451
 , OP_452, OP_453, OP_454, OP_455
 , OP_456, OP_457, OP_458, OP_459
 , OP_460, OP_461, OP_462, OP_463
 , OP_464, OP_465, OP_466, OP_467
 , OP_468, OP_469, OP_470, OP_471
 , OP_472, OP_473, OP_474, OP_475
 , OP_476, OP_477, OP_478, OP_479
 , OP_480, OP_481, OP_482, OP_483
 , OP_484, OP_485, OP_486, OP_487
 , OP_488, OP_489, OP_490, OP_491
 , OP_492, OP_493, OP_494, OP_495
 , OP_496, OP_497, OP_498, OP_499
 , OP_500, OP_501, OP_502, OP_503
 , OP_504, OP_505, OP_506, OP_507
 , OP_508, OP_509, OP_510, OP_511
 , OP_512, OP_513, OP_514, OP_515
 , OP_516, OP_517, OP_518, OP_519
 , OP_520, OP_521, OP_522, OP_523
 , OP_524, OP_525, OP_526, OP_527
 , OP_528, OP_529, OP_530, OP_531
 , OP_532, OP_533, OP_534, OP_535
 , OP_536, OP_537, OP_538, OP_539
 , OP_540, OP_541, OP_542, OP_543
 , OP_544, OP_545, OP_546, OP_547
 , OP_548, OP_549, OP_550, OP_551
 , OP_552, OP_553, OP_554, OP_555
 , OP_556, OP_557, OP_558, OP_559
 , OP_560, OP_561, OP_562, OP_563
 , OP_564, OP_565, OP_566, OP_567
 , OP_568, OP_569, OP_570, OP_571
 , OP_572, OP_573, OP_574, OP_575
 , OP_576, OP_577, OP_578, OP_579
 , OP_580, OP_581, OP_582, OP_583
 , OP_584, OP_585, OP_586, OP_587
 , OP_588, OP_589, OP_590, OP_591
 , OP_592, OP_593, OP_594, OP_595
 , OP_596, OP_597, OP_598, OP_599
 , OP_600, OP_601, OP_602, OP_603
 , OP_604, OP_605, OP_606, OP_607
 , OP_608, OP_609, OP_610, OP_611
 , OP_612, OP_613, OP_614, OP_615
 , OP_616, OP_617, OP_618, OP_619
 , OP_620, OP_621, OP_622, OP_623
 , OP_624, OP_625, OP_626, OP_627
 , OP_628, OP_629, OP_630, OP_631
 , OP_632, OP_633, OP_634, OP_635
 , OP_636, OP_637, OP_638, OP_639
 , OP_640, OP_641, OP_642, OP_643
 , OP_644, OP_645, OP_646, OP_647
 , OP_648, OP_649, OP_650, OP_651
 , OP_652, OP_653, OP_654, OP_655
 , OP_656, OP_657, OP_658, OP_659
 , OP_660, OP_661, OP_662, OP_663
 , OP_664, OP_665, OP_666, OP_667
 , OP_668, OP_669, OP_670, OP_671
 , OP_672, OP_673, OP_674, OP_675
 , OP_676, OP_677, OP_678, OP_679
 , OP_680, OP_681, OP_682, OP_683
 , OP_684, OP_685, OP_686, OP_687
 , OP_688, OP_689, OP_690, OP_691
 , OP_692, OP_693, OP_694, OP_695
 , OP_696, OP_697, OP_698, OP_699
 , OP_700, OP_701, OP_702, OP_703
 , OP_704, OP_705, OP_706, OP_707
 , OP_708, OP_709, OP_710, OP_711
 , OP_712, OP_713, OP_714, OP_715
 , OP_716, OP_717, OP_718, OP_719
 , OP_720, OP_721, OP_722, OP_723
 , OP_724, OP_725, OP_726, OP_727
 , OP_728, OP_729, OP_730, OP_731
 , OP_732, OP_733, OP_734, OP_735
 , OP_736, OP_737, OP_738, OP_739
 , OP_740, OP_741, OP_742, OP_743
 , OP_744, OP_745, OP_746, OP_747
 , OP_748, OP_749, OP_750, OP_751
 , OP_752, OP_753, OP_754, OP_755
 , OP_756, OP_757, OP_758, OP_759
 , OP_760, OP_761, OP_762, OP_763
 , OP_764, OP_765, OP_766, OP_767
 , OP_768, OP_769, OP_770, OP_771
 , OP_772, OP_773, OP_774, OP_775
 , OP_776, OP_777, OP_778, OP_779
 , OP_780, OP_781, OP_782, OP_783
 , OP_784, OP_785, OP_786, OP_787
 , OP_788, OP_789, OP_790, OP_791
 , OP_792, OP_793, OP_794, OP_795
 , OP_796, OP_797, OP_798, OP_799
 , OP_800, OP_801, OP_802, OP_803
 , OP_804, OP_805, OP_806, OP_807
 , OP_808, OP_809, OP_810, OP_811
 , OP_812, OP_813, OP_814, OP_815
 , OP_816, OP_817, OP_818, OP_819
 , OP_820, OP_821, OP_822, OP_823
 , OP_824, OP_825, OP_826, OP_827
 , OP_828, OP_829, OP_830, OP_831
 , OP_832, OP_833, OP_834, OP_835
 , OP_836, OP_837, OP_838, OP_839
 , OP_840, OP_841, OP_842, OP_843
 , OP_844, OP_845, OP_846, OP_847
 , OP_848, OP_849, OP_850, OP_851
 , OP_852, OP_853, OP_854, OP_855
 , OP_856, OP_857, OP_858, OP_859
 , OP_860, OP_861, OP_862, OP_863
 , OP_864, OP_865, OP_866, OP_867
 , OP_868, OP_869, OP_870, OP_871
 , OP_872, OP_873, OP_874, OP_875
 , OP_876, OP_877, OP_878, OP_879
 , OP_880, OP_881, OP_882, OP_883
 , OP_884, OP_885, OP_886, OP_887
 , OP_888, OP_889, OP_890, OP_891
 , OP_892, OP_893, OP_894, OP_895
 , OP_896, OP_897, OP_898, OP_899
 , OP_900, OP_901, OP_902, OP_903
 , OP_904, OP_905, OP_906, OP_907
 , OP_908, OP_909, OP_910, OP_911
 , OP_912, OP_913, OP_914, OP_915
 , OP_916, OP_917, OP_918, OP_919
 , OP_920, OP_921, OP_922, OP_923
 , OP_924, OP_925, OP_926, OP_927
 , OP_928, OP_929, OP_930, OP_931
 , OP_932, OP_933, OP_934, OP_935
 , OP_936, OP_937, OP_938, OP_939
 , OP_940, OP_941, OP_942, OP_943
 , OP_944, OP_945, OP_946, OP_947
 , OP_948, OP_949, OP_950, OP_951
 , OP_952, OP_953, OP_954, OP_955
 , OP_956, OP_957, OP_958, OP_959
 , OP_960, OP_961, OP_962, OP_963
 , OP_964, OP_965, OP_966, OP_967
 , OP_968, OP_969, OP_970, OP_971
 , OP_972, OP_973, OP_974, OP_975
 , OP_976, OP_977, OP_978, OP_979
 , OP_980, OP_981, OP_982, OP_983
 , OP_984, OP_985, OP_986, OP_987
 , OP_988, OP_989, OP_990, OP_991
 , OP_992, OP_993, OP_994, OP_995
 , OP_996, OP_997, OP_998, OP_999
 , OP_1000, OP_1001, OP_1002, OP_1003
 , OP_1004, OP_1005, OP_1006, OP_1007
 , OP_1008, OP_1009, OP_1010, OP_1011
 , OP_1012, OP_1013, OP_1014, OP_1015
 , OP_1016, OP_1017, OP_1018, OP_1019
 , OP_1020, OP_1021, OP_1022, OP_1023
} INSN_OP1;

/* Enum declaration for insn is immediate.  */
typedef enum insn_isimm {
  ISIMM_0, ISIMM_1
} INSN_ISIMM;

/* Enum declaration for insn afe enums.  */
typedef enum insn_afe {
  AFE_0
} INSN_AFE;

/* Attributes.  */

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_MIST32, MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_MIST32, ISA_MAX
} ISA_ATTR;

/* Number of architecture variants.  */
#define MAX_ISAS  1
#define MAX_MACHS ((int) MACH_MAX)

/* Ifield support.  */

/* Ifield attribute indices.  */

/* Enum declaration for cgen_ifld attrs.  */
typedef enum cgen_ifld_attr {
  CGEN_IFLD_VIRTUAL, CGEN_IFLD_PCREL_ADDR, CGEN_IFLD_ABS_ADDR, CGEN_IFLD_RESERVED
 , CGEN_IFLD_SIGN_OPT, CGEN_IFLD_SIGNED, CGEN_IFLD_END_BOOLS, CGEN_IFLD_START_NBOOLS = 31
 , CGEN_IFLD_MACH, CGEN_IFLD_END_NBOOLS
} CGEN_IFLD_ATTR;

/* Number of non-boolean elements in cgen_ifld_attr.  */
#define CGEN_IFLD_NBOOL_ATTRS (CGEN_IFLD_END_NBOOLS - CGEN_IFLD_START_NBOOLS - 1)

/* cgen_ifld attribute accessor macros.  */
#define CGEN_ATTR_CGEN_IFLD_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_IFLD_MACH-CGEN_IFLD_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_IFLD_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_IFLD_PCREL_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_PCREL_ADDR)) != 0)
#define CGEN_ATTR_CGEN_IFLD_ABS_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_ABS_ADDR)) != 0)
#define CGEN_ATTR_CGEN_IFLD_RESERVED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_RESERVED)) != 0)
#define CGEN_ATTR_CGEN_IFLD_SIGN_OPT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_SIGN_OPT)) != 0)
#define CGEN_ATTR_CGEN_IFLD_SIGNED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_SIGNED)) != 0)

/* Enum declaration for mist32 ifield types.  */
typedef enum ifield_type {
  MIST32_F_NIL, MIST32_F_ANYOF, MIST32_F_EXT, MIST32_F_OP
 , MIST32_F_ISIMM, MIST32_F_AFE, MIST32_F_CC, MIST32_F_RD
 , MIST32_F_RS, MIST32_F_I11H, MIST32_F_I11L, MIST32_F_I11
 , MIST32_F_UI11, MIST32_F_I11W, MIST32_F_P11HI, MIST32_F_P11LO
 , MIST32_F_P11B, MIST32_F_P11H, MIST32_F_P11W, MIST32_F_I16H
 , MIST32_F_I16L, MIST32_F_I16, MIST32_F_UI16, MIST32_F_P16
 , MIST32_F_UP16R, MIST32_F_P16R, MIST32_F_RESERVE1, MIST32_F_RESERVE2
 , MIST32_F_RESERVE3, MIST32_F_MAX
} IFIELD_TYPE;

#define MAX_IFLD ((int) MIST32_F_MAX)

/* Hardware attribute indices.  */

/* Enum declaration for cgen_hw attrs.  */
typedef enum cgen_hw_attr {
  CGEN_HW_VIRTUAL, CGEN_HW_CACHE_ADDR, CGEN_HW_PC, CGEN_HW_PROFILE
 , CGEN_HW_END_BOOLS, CGEN_HW_START_NBOOLS = 31, CGEN_HW_MACH, CGEN_HW_END_NBOOLS
} CGEN_HW_ATTR;

/* Number of non-boolean elements in cgen_hw_attr.  */
#define CGEN_HW_NBOOL_ATTRS (CGEN_HW_END_NBOOLS - CGEN_HW_START_NBOOLS - 1)

/* cgen_hw attribute accessor macros.  */
#define CGEN_ATTR_CGEN_HW_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_HW_MACH-CGEN_HW_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_HW_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_HW_CACHE_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_CACHE_ADDR)) != 0)
#define CGEN_ATTR_CGEN_HW_PC_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_PC)) != 0)
#define CGEN_ATTR_CGEN_HW_PROFILE_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_PROFILE)) != 0)

/* Enum declaration for mist32 hardware types.  */
typedef enum cgen_hw_type {
  HW_H_MEMORY, HW_H_SINT, HW_H_UINT, HW_H_ADDR
 , HW_H_IADDR, HW_H_PC, HW_H_GR, HW_H_INT11
 , HW_H_UINT11, HW_H_INT16, HW_H_UINT16, HW_H_CC
 , HW_MAX
} CGEN_HW_TYPE;

#define MAX_HW ((int) HW_MAX)

/* Operand attribute indices.  */

/* Enum declaration for cgen_operand attrs.  */
typedef enum cgen_operand_attr {
  CGEN_OPERAND_VIRTUAL, CGEN_OPERAND_PCREL_ADDR, CGEN_OPERAND_ABS_ADDR, CGEN_OPERAND_SIGN_OPT
 , CGEN_OPERAND_SIGNED, CGEN_OPERAND_NEGATIVE, CGEN_OPERAND_RELAX, CGEN_OPERAND_SEM_ONLY
 , CGEN_OPERAND_END_BOOLS, CGEN_OPERAND_START_NBOOLS = 31, CGEN_OPERAND_MACH, CGEN_OPERAND_END_NBOOLS
} CGEN_OPERAND_ATTR;

/* Number of non-boolean elements in cgen_operand_attr.  */
#define CGEN_OPERAND_NBOOL_ATTRS (CGEN_OPERAND_END_NBOOLS - CGEN_OPERAND_START_NBOOLS - 1)

/* cgen_operand attribute accessor macros.  */
#define CGEN_ATTR_CGEN_OPERAND_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_OPERAND_MACH-CGEN_OPERAND_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_OPERAND_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_PCREL_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_PCREL_ADDR)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_ABS_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_ABS_ADDR)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_SIGN_OPT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_SIGN_OPT)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_SIGNED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_SIGNED)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_NEGATIVE_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_NEGATIVE)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_RELAX_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_RELAX)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_SEM_ONLY_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_SEM_ONLY)) != 0)

/* Enum declaration for mist32 operand types.  */
typedef enum cgen_operand_type {
  MIST32_OPERAND_PC, MIST32_OPERAND_RD, MIST32_OPERAND_RS, MIST32_OPERAND_CC
 , MIST32_OPERAND_P16, MIST32_OPERAND_UP16R, MIST32_OPERAND_P16R, MIST32_OPERAND_P11B
 , MIST32_OPERAND_P11H, MIST32_OPERAND_P11W, MIST32_OPERAND_I11, MIST32_OPERAND_UI11
 , MIST32_OPERAND_I11W, MIST32_OPERAND_I16L, MIST32_OPERAND_UI16L, MIST32_OPERAND_I16H
 , MIST32_OPERAND_I32, MIST32_OPERAND_MAX
} CGEN_OPERAND_TYPE;

/* Number of operands types.  */
#define MAX_OPERANDS 17

/* Maximum number of operands referenced by any insn.  */
#define MAX_OPERAND_INSTANCES 8

/* Insn attribute indices.  */

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_END_BOOLS, CGEN_INSN_START_NBOOLS = 31
 , CGEN_INSN_MACH, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

/* cgen_insn attribute accessor macros.  */
#define CGEN_ATTR_CGEN_INSN_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_INSN_MACH-CGEN_INSN_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_INSN_ALIAS_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_ALIAS)) != 0)
#define CGEN_ATTR_CGEN_INSN_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_INSN_UNCOND_CTI_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_UNCOND_CTI)) != 0)
#define CGEN_ATTR_CGEN_INSN_COND_CTI_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_COND_CTI)) != 0)
#define CGEN_ATTR_CGEN_INSN_SKIP_CTI_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_SKIP_CTI)) != 0)
#define CGEN_ATTR_CGEN_INSN_DELAY_SLOT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_DELAY_SLOT)) != 0)
#define CGEN_ATTR_CGEN_INSN_RELAXABLE_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_RELAXABLE)) != 0)
#define CGEN_ATTR_CGEN_INSN_RELAXED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_RELAXED)) != 0)
#define CGEN_ATTR_CGEN_INSN_NO_DIS_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_NO_DIS)) != 0)
#define CGEN_ATTR_CGEN_INSN_PBB_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_PBB)) != 0)

/* cgen.h uses things we just defined.  */
#include "opcode/cgen.h"

extern const struct cgen_ifld mist32_cgen_ifld_table[];

/* Attributes.  */
extern const CGEN_ATTR_TABLE mist32_cgen_hardware_attr_table[];
extern const CGEN_ATTR_TABLE mist32_cgen_ifield_attr_table[];
extern const CGEN_ATTR_TABLE mist32_cgen_operand_attr_table[];
extern const CGEN_ATTR_TABLE mist32_cgen_insn_attr_table[];

/* Hardware decls.  */

extern CGEN_KEYWORD mist32_cgen_opval_h_gr;
extern CGEN_KEYWORD mist32_cgen_opval_h_cc;

extern const CGEN_HW_ENTRY mist32_cgen_hw_table[];



#endif /* MIST32_CPU_H */
