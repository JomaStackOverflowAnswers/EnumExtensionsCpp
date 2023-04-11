#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>
#include <exception>
#include <memory>
#include <charconv>

#define EZNUM_REPEAT_MAX 512

#define FIVE_HUNDRED_AND_FOURTEENTH_ARGUMENT(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63, a64, a65, a66, a67, a68, a69, a70, a71, a72, a73, a74, a75, a76, a77, a78, a79, a80, a81, a82, a83, a84, a85, a86, a87, a88, a89, a90, a91, a92, a93, a94, a95, a96, a97, a98, a99, a100, a101, a102, a103, a104, a105, a106, a107, a108, a109, a110, a111, a112, a113, a114, a115, a116, a117, a118, a119, a120, a121, a122, a123, a124, a125, a126, a127, a128, a129, a130, a131, a132, a133, a134, a135, a136, a137, a138, a139, a140, a141, a142, a143, a144, a145, a146, a147, a148, a149, a150, a151, a152, a153, a154, a155, a156, a157, a158, a159, a160, a161, a162, a163, a164, a165, a166, a167, a168, a169, a170, a171, a172, a173, a174, a175, a176, a177, a178, a179, a180, a181, a182, a183, a184, a185, a186, a187, a188, a189, a190, a191, a192, a193, a194, a195, a196, a197, a198, a199, a200, a201, a202, a203, a204, a205, a206, a207, a208, a209, a210, a211, a212, a213, a214, a215, a216, a217, a218, a219, a220, a221, a222, a223, a224, a225, a226, a227, a228, a229, a230, a231, a232, a233, a234, a235, a236, a237, a238, a239, a240, a241, a242, a243, a244, a245, a246, a247, a248, a249, a250, a251, a252, a253, a254, a255, a256, a257, a258, a259, a260, a261, a262, a263, a264, a265, a266, a267, a268, a269, a270, a271, a272, a273, a274, a275, a276, a277, a278, a279, a280, a281, a282, a283, a284, a285, a286, a287, a288, a289, a290, a291, a292, a293, a294, a295, a296, a297, a298, a299, a300, a301, a302, a303, a304, a305, a306, a307, a308, a309, a310, a311, a312, a313, a314, a315, a316, a317, a318, a319, a320, a321, a322, a323, a324, a325, a326, a327, a328, a329, a330, a331, a332, a333, a334, a335, a336, a337, a338, a339, a340, a341, a342, a343, a344, a345, a346, a347, a348, a349, a350, a351, a352, a353, a354, a355, a356, a357, a358, a359, a360, a361, a362, a363, a364, a365, a366, a367, a368, a369, a370, a371, a372, a373, a374, a375, a376, a377, a378, a379, a380, a381, a382, a383, a384, a385, a386, a387, a388, a389, a390, a391, a392, a393, a394, a395, a396, a397, a398, a399, a400, a401, a402, a403, a404, a405, a406, a407, a408, a409, a410, a411, a412, a413, a414, a415, a416, a417, a418, a419, a420, a421, a422, a423, a424, a425, a426, a427, a428, a429, a430, a431, a432, a433, a434, a435, a436, a437, a438, a439, a440, a441, a442, a443, a444, a445, a446, a447, a448, a449, a450, a451, a452, a453, a454, a455, a456, a457, a458, a459, a460, a461, a462, a463, a464, a465, a466, a467, a468, a469, a470, a471, a472, a473, a474, a475, a476, a477, a478, a479, a480, a481, a482, a483, a484, a485, a486, a487, a488, a489, a490, a491, a492, a493, a494, a495, a496, a497, a498, a499, a500, a501, a502, a503, a504, a505, a506, a507, a508, a509, a510, a511, a512, a513, a514, ...) a514
#define COUNT_ARGUMENTS(...) FIVE_HUNDRED_AND_FOURTEENTH_ARGUMENT(dummy, __VA_ARGS__, 512, 511, 510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496, 495, 494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, 482, 481, 480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, 466, 465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, 452, 451, 450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436, 435, 434, 433, 432, 431, 430, 429, 428, 427, 426, 425, 424, 423, 422, 421, 420, 419, 418, 417, 416, 415, 414, 413, 412, 411, 410, 409, 408, 407, 406, 405, 404, 403, 402, 401, 400, 399, 398, 397, 396, 395, 394, 393, 392, 391, 390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379, 378, 377, 376, 375, 374, 373, 372, 371, 370, 369, 368, 367, 366, 365, 364, 363, 362, 361, 360, 359, 358, 357, 356, 355, 354, 353, 352, 351, 350, 349, 348, 347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331, 330, 329, 328, 327, 326, 325, 324, 323, 322, 321, 320, 319, 318, 317, 316, 315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 303, 302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 0)


#define COMMA_VALUE() ,

#define STRINGIFY(x) #x##s
#define CSTRINGIFY(x) #x

#define STRINGIFY_DEFER(x) STRINGIFY(x)
#define CSTRINGIFY_DEFER(x) CSTRINGIFY(x)

#define ADD_EXPRESSION_0(exp)
#define ADD_EXPRESSION_1(exp) exp()

#define EZNUM_510_DIVIDED_BY_3() 170
#define EZNUM_507_DIVIDED_BY_3() 169
#define EZNUM_504_DIVIDED_BY_3() 168
#define EZNUM_501_DIVIDED_BY_3() 167
#define EZNUM_498_DIVIDED_BY_3() 166
#define EZNUM_495_DIVIDED_BY_3() 165
#define EZNUM_492_DIVIDED_BY_3() 164
#define EZNUM_489_DIVIDED_BY_3() 163
#define EZNUM_486_DIVIDED_BY_3() 162
#define EZNUM_483_DIVIDED_BY_3() 161
#define EZNUM_480_DIVIDED_BY_3() 160
#define EZNUM_477_DIVIDED_BY_3() 159
#define EZNUM_474_DIVIDED_BY_3() 158
#define EZNUM_471_DIVIDED_BY_3() 157
#define EZNUM_468_DIVIDED_BY_3() 156
#define EZNUM_465_DIVIDED_BY_3() 155
#define EZNUM_462_DIVIDED_BY_3() 154
#define EZNUM_459_DIVIDED_BY_3() 153
#define EZNUM_456_DIVIDED_BY_3() 152
#define EZNUM_453_DIVIDED_BY_3() 151
#define EZNUM_450_DIVIDED_BY_3() 150
#define EZNUM_447_DIVIDED_BY_3() 149
#define EZNUM_444_DIVIDED_BY_3() 148
#define EZNUM_441_DIVIDED_BY_3() 147
#define EZNUM_438_DIVIDED_BY_3() 146
#define EZNUM_435_DIVIDED_BY_3() 145
#define EZNUM_432_DIVIDED_BY_3() 144
#define EZNUM_429_DIVIDED_BY_3() 143
#define EZNUM_426_DIVIDED_BY_3() 142
#define EZNUM_423_DIVIDED_BY_3() 141
#define EZNUM_420_DIVIDED_BY_3() 140
#define EZNUM_417_DIVIDED_BY_3() 139
#define EZNUM_414_DIVIDED_BY_3() 138
#define EZNUM_411_DIVIDED_BY_3() 137
#define EZNUM_408_DIVIDED_BY_3() 136
#define EZNUM_405_DIVIDED_BY_3() 135
#define EZNUM_402_DIVIDED_BY_3() 134
#define EZNUM_399_DIVIDED_BY_3() 133
#define EZNUM_396_DIVIDED_BY_3() 132
#define EZNUM_393_DIVIDED_BY_3() 131
#define EZNUM_390_DIVIDED_BY_3() 130
#define EZNUM_387_DIVIDED_BY_3() 129
#define EZNUM_384_DIVIDED_BY_3() 128
#define EZNUM_381_DIVIDED_BY_3() 127
#define EZNUM_378_DIVIDED_BY_3() 126
#define EZNUM_375_DIVIDED_BY_3() 125
#define EZNUM_372_DIVIDED_BY_3() 124
#define EZNUM_369_DIVIDED_BY_3() 123
#define EZNUM_366_DIVIDED_BY_3() 122
#define EZNUM_363_DIVIDED_BY_3() 121
#define EZNUM_360_DIVIDED_BY_3() 120
#define EZNUM_357_DIVIDED_BY_3() 119
#define EZNUM_354_DIVIDED_BY_3() 118
#define EZNUM_351_DIVIDED_BY_3() 117
#define EZNUM_348_DIVIDED_BY_3() 116
#define EZNUM_345_DIVIDED_BY_3() 115
#define EZNUM_342_DIVIDED_BY_3() 114
#define EZNUM_339_DIVIDED_BY_3() 113
#define EZNUM_336_DIVIDED_BY_3() 112
#define EZNUM_333_DIVIDED_BY_3() 111
#define EZNUM_330_DIVIDED_BY_3() 110
#define EZNUM_327_DIVIDED_BY_3() 109
#define EZNUM_324_DIVIDED_BY_3() 108
#define EZNUM_321_DIVIDED_BY_3() 107
#define EZNUM_318_DIVIDED_BY_3() 106
#define EZNUM_315_DIVIDED_BY_3() 105
#define EZNUM_312_DIVIDED_BY_3() 104
#define EZNUM_309_DIVIDED_BY_3() 103
#define EZNUM_306_DIVIDED_BY_3() 102
#define EZNUM_303_DIVIDED_BY_3() 101
#define EZNUM_300_DIVIDED_BY_3() 100
#define EZNUM_297_DIVIDED_BY_3() 99
#define EZNUM_294_DIVIDED_BY_3() 98
#define EZNUM_291_DIVIDED_BY_3() 97
#define EZNUM_288_DIVIDED_BY_3() 96
#define EZNUM_285_DIVIDED_BY_3() 95
#define EZNUM_282_DIVIDED_BY_3() 94
#define EZNUM_279_DIVIDED_BY_3() 93
#define EZNUM_276_DIVIDED_BY_3() 92
#define EZNUM_273_DIVIDED_BY_3() 91
#define EZNUM_270_DIVIDED_BY_3() 90
#define EZNUM_267_DIVIDED_BY_3() 89
#define EZNUM_264_DIVIDED_BY_3() 88
#define EZNUM_261_DIVIDED_BY_3() 87
#define EZNUM_258_DIVIDED_BY_3() 86
#define EZNUM_255_DIVIDED_BY_3() 85
#define EZNUM_252_DIVIDED_BY_3() 84
#define EZNUM_249_DIVIDED_BY_3() 83
#define EZNUM_246_DIVIDED_BY_3() 82
#define EZNUM_243_DIVIDED_BY_3() 81
#define EZNUM_240_DIVIDED_BY_3() 80
#define EZNUM_237_DIVIDED_BY_3() 79
#define EZNUM_234_DIVIDED_BY_3() 78
#define EZNUM_231_DIVIDED_BY_3() 77
#define EZNUM_228_DIVIDED_BY_3() 76
#define EZNUM_225_DIVIDED_BY_3() 75
#define EZNUM_222_DIVIDED_BY_3() 74
#define EZNUM_219_DIVIDED_BY_3() 73
#define EZNUM_216_DIVIDED_BY_3() 72
#define EZNUM_213_DIVIDED_BY_3() 71
#define EZNUM_210_DIVIDED_BY_3() 70
#define EZNUM_207_DIVIDED_BY_3() 69
#define EZNUM_204_DIVIDED_BY_3() 68
#define EZNUM_201_DIVIDED_BY_3() 67
#define EZNUM_198_DIVIDED_BY_3() 66
#define EZNUM_195_DIVIDED_BY_3() 65
#define EZNUM_192_DIVIDED_BY_3() 64
#define EZNUM_189_DIVIDED_BY_3() 63
#define EZNUM_186_DIVIDED_BY_3() 62
#define EZNUM_183_DIVIDED_BY_3() 61
#define EZNUM_180_DIVIDED_BY_3() 60
#define EZNUM_177_DIVIDED_BY_3() 59
#define EZNUM_174_DIVIDED_BY_3() 58
#define EZNUM_171_DIVIDED_BY_3() 57
#define EZNUM_168_DIVIDED_BY_3() 56
#define EZNUM_165_DIVIDED_BY_3() 55
#define EZNUM_162_DIVIDED_BY_3() 54
#define EZNUM_159_DIVIDED_BY_3() 53
#define EZNUM_156_DIVIDED_BY_3() 52
#define EZNUM_153_DIVIDED_BY_3() 51
#define EZNUM_150_DIVIDED_BY_3() 50
#define EZNUM_147_DIVIDED_BY_3() 49
#define EZNUM_144_DIVIDED_BY_3() 48
#define EZNUM_141_DIVIDED_BY_3() 47
#define EZNUM_138_DIVIDED_BY_3() 46
#define EZNUM_135_DIVIDED_BY_3() 45
#define EZNUM_132_DIVIDED_BY_3() 44
#define EZNUM_129_DIVIDED_BY_3() 43
#define EZNUM_126_DIVIDED_BY_3() 42
#define EZNUM_123_DIVIDED_BY_3() 41
#define EZNUM_120_DIVIDED_BY_3() 40
#define EZNUM_117_DIVIDED_BY_3() 39
#define EZNUM_114_DIVIDED_BY_3() 38
#define EZNUM_111_DIVIDED_BY_3() 37
#define EZNUM_108_DIVIDED_BY_3() 36
#define EZNUM_105_DIVIDED_BY_3() 35
#define EZNUM_102_DIVIDED_BY_3() 34
#define EZNUM_99_DIVIDED_BY_3() 33
#define EZNUM_96_DIVIDED_BY_3() 32
#define EZNUM_93_DIVIDED_BY_3() 31
#define EZNUM_90_DIVIDED_BY_3() 30
#define EZNUM_87_DIVIDED_BY_3() 29
#define EZNUM_84_DIVIDED_BY_3() 28
#define EZNUM_81_DIVIDED_BY_3() 27
#define EZNUM_78_DIVIDED_BY_3() 26
#define EZNUM_75_DIVIDED_BY_3() 25
#define EZNUM_72_DIVIDED_BY_3() 24
#define EZNUM_69_DIVIDED_BY_3() 23
#define EZNUM_66_DIVIDED_BY_3() 22
#define EZNUM_63_DIVIDED_BY_3() 21
#define EZNUM_60_DIVIDED_BY_3() 20
#define EZNUM_57_DIVIDED_BY_3() 19
#define EZNUM_54_DIVIDED_BY_3() 18
#define EZNUM_51_DIVIDED_BY_3() 17
#define EZNUM_48_DIVIDED_BY_3() 16
#define EZNUM_45_DIVIDED_BY_3() 15
#define EZNUM_42_DIVIDED_BY_3() 14
#define EZNUM_39_DIVIDED_BY_3() 13
#define EZNUM_36_DIVIDED_BY_3() 12
#define EZNUM_33_DIVIDED_BY_3() 11
#define EZNUM_30_DIVIDED_BY_3() 10
#define EZNUM_27_DIVIDED_BY_3() 9
#define EZNUM_24_DIVIDED_BY_3() 8
#define EZNUM_21_DIVIDED_BY_3() 7
#define EZNUM_18_DIVIDED_BY_3() 6
#define EZNUM_15_DIVIDED_BY_3() 5
#define EZNUM_12_DIVIDED_BY_3() 4
#define EZNUM_9_DIVIDED_BY_3() 3
#define EZNUM_6_DIVIDED_BY_3() 2
#define EZNUM_3_DIVIDED_BY_3() 1

#define __EZNUM_GET_MULTIPLE_OF_3_EXPAND_3(count) count()
#define __EZNUM_GET_MULTIPLE_OF_3_EXPAND_2(count) __EZNUM_GET_MULTIPLE_OF_3_EXPAND_3(EZNUM_##count##_DIVIDED_BY_3)
#define __EZNUM_GET_MULTIPLE_OF_3_EXPAND_1(count) __EZNUM_GET_MULTIPLE_OF_3_EXPAND_2(count)
#define EZNUM_GET_MULTIPLE_OF_3(...) __EZNUM_GET_MULTIPLE_OF_3_EXPAND_1(COUNT_ARGUMENTS(__VA_ARGS__))

#define __EZNUM_ENUM_REPEAT_1(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value)
#define __EZNUM_ENUM_REPEAT_2(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_1(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_3(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_2(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_4(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_3(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_5(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_4(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_6(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_5(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_7(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_6(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_8(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_7(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_9(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_8(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_10(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_9(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_11(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_10(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_12(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_11(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_13(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_12(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_14(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_13(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_15(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_14(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_16(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_15(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_17(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_16(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_18(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_17(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_19(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_18(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_20(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_19(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_21(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_20(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_22(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_21(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_23(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_22(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_24(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_23(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_25(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_24(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_26(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_25(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_27(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_26(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_28(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_27(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_29(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_28(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_30(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_29(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_31(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_30(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_32(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_31(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_33(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_32(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_34(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_33(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_35(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_34(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_36(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_35(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_37(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_36(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_38(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_37(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_39(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_38(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_40(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_39(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_41(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_40(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_42(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_41(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_43(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_42(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_44(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_43(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_45(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_44(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_46(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_45(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_47(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_46(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_48(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_47(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_49(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_48(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_50(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_49(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_51(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_50(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_52(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_51(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_53(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_52(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_54(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_53(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_55(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_54(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_56(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_55(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_57(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_56(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_58(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_57(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_59(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_58(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_60(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_59(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_61(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_60(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_62(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_61(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_63(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_62(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_64(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_63(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_65(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_64(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_66(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_65(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_67(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_66(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_68(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_67(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_69(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_68(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_70(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_69(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_71(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_70(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_72(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_71(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_73(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_72(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_74(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_73(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_75(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_74(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_76(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_75(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_77(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_76(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_78(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_77(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_79(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_78(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_80(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_79(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_81(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_80(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_82(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_81(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_83(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_82(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_84(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_83(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_85(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_84(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_86(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_85(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_87(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_86(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_88(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_87(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_89(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_88(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_90(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_89(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_91(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_90(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_92(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_91(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_93(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_92(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_94(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_93(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_95(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_94(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_96(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_95(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_97(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_96(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_98(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_97(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_99(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_98(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_100(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_99(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_101(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_100(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_102(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_101(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_103(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_102(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_104(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_103(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_105(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_104(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_106(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_105(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_107(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_106(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_108(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_107(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_109(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_108(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_110(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_109(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_111(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_110(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_112(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_111(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_113(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_112(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_114(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_113(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_115(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_114(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_116(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_115(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_117(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_116(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_118(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_117(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_119(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_118(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_120(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_119(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_121(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_120(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_122(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_121(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_123(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_122(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_124(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_123(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_125(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_124(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_126(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_125(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_127(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_126(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_128(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_127(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_129(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_128(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_130(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_129(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_131(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_130(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_132(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_131(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_133(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_132(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_134(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_133(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_135(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_134(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_136(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_135(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_137(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_136(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_138(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_137(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_139(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_138(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_140(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_139(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_141(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_140(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_142(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_141(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_143(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_142(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_144(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_143(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_145(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_144(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_146(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_145(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_147(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_146(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_148(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_147(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_149(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_148(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_150(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_149(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_151(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_150(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_152(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_151(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_153(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_152(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_154(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_153(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_155(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_154(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_156(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_155(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_157(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_156(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_158(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_157(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_159(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_158(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_160(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_159(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_161(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_160(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_162(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_161(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_163(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_162(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_164(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_163(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_165(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_164(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_166(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_165(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_167(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_166(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_168(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_167(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_169(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_168(Name, UType, count, x, __VA_ARGS__)
#define __EZNUM_ENUM_REPEAT_170(Name, UType, count, x, var, oper, value, ...) x(Name, UType, var, oper, value) __EZNUM_ENUM_REPEAT_169(Name, UType, count, x, __VA_ARGS__)

#define __EZNUM_ENUM_MAP_ENUMT_STRINGT_VALUE(Name, UType, var, oper, value) {Name::var, #var},
#define __EZNUM_ENUM_MAP_INTEGRALT_ENUMT_VALUE(Name, UType, var, oper, value) {static_cast<UType>(Name::var), Name::var},
#define __EZNUM_ENUM_MAP_STRINGT_INTEGRALT_VALUE_NO_NAME(Name, UType, var, oper, value) {#var, Name::var},
#define __EZNUM_ENUM_MAP_STRINGT_INTEGRALT_VALUE_WITH_NAME(Name, UType, var, oper, value) {STRINGIFY_DEFER(Name::var), Name::var},
#define __EZNUM_ENUM_MAP_STRINGT_INTEGRALT_VALUE_INTEGRAL(Name, UType, var, oper, value) {IntegralExtensions::ToString(static_cast<UType>(Name::var)), Name::var},

#define __EZNUM_ENUM_GET_EQ(value) = value,
#define __EZNUM_ENUM_GET__(value) ,
#define __EZNUM_ENUM_GET_VALUE_EXPAND(exp, value) exp(value)
#define __EZNUM_ENUM_GET_VALUE(Name, UType, var, oper, value) var __EZNUM_ENUM_GET_VALUE_EXPAND(__EZNUM_ENUM_GET_##oper, value)
#define __EZNUM_ENUM_GET_ONLY_VALUE(Name, UType, var, oper, value) Name::var,

#define __EZNUM_ENUM_EXPAND_3(Name, UType, count, iexp, exp, ...) exp(Name, UType, count, iexp, __VA_ARGS__)
#define __EZNUM_ENUM_EXPAND_2(Name, UType, count, iexp, exp, ...) __EZNUM_ENUM_EXPAND_3(Name, UType, count, iexp, exp, __VA_ARGS__)
#define __EZNUM_ENUM_EXPAND_1(Name, UType, count, iexp, ...) __EZNUM_ENUM_EXPAND_2(Name, UType, count, iexp, __EZNUM_ENUM_REPEAT_##count, __VA_ARGS__)

#define __EZNUM_ENUM_DECLARATION(Name, UType, count, ...) enum class Name : UType   \
{                                                                                    \
    __EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_GET_VALUE, __VA_ARGS__) \
};

#define __EZNUM_ENUM_EXTENSIONS_DECLARATION(Name, UType, count, ...)                                                                                                                                                                                                                                                                                                                           \
    class Name##EnumExtensions                                                                                                                                                                                                                                                                                                                                                                  \
    {                                                                                                                                                                                                                                                                                                                                                                                           \
    public:                                                                                                                                                                                                                                                                                                                                                                                     \
        [[nodiscard]] static String ToIntegralString(const Name &value)                                                                                                                                                                                                                                                                                                                         \
        {                                                                                                                                                                                                                                                                                                                                                                                       \
            using namespace Extensions;                                                                                                                                                                                                                                                                                                                                                              \
            return EnumExtensions::ToIntegralString(value);                                                                                                                                                                                                                                                                                                                                     \
        }                                                                                                                                                                                                                                                                                                                                                                                       \
        [[nodiscard]] static UType ToIntegral(const Name &value)                                                                                                                                                                                                                                                                                                                                \
        {                                                                                                                                                                                                                                                                                                                                                                                       \
            using namespace Extensions;                                                                                                                                                                                                                                                                                                                                                         \
            return EnumExtensions::ToIntegral<Name>(value);                                                                                                                                                                                                                                                                                                                                     \
        }                                                                                                                                                                                                                                                                                                                                                                                       \
        [[nodiscard]] static std::string ToString(const Name &value, bool includeEnumName = false)                                                                                                                                                                                                                                                                                              \
        {                                                                                                                                                                                                                                                                                                                                                                                       \
            using namespace Extensions;                                                                                                                                                                                                                                                                                                                                                               \
            static const std::map<Name, String> values = {__EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_MAP_ENUMT_STRINGT_VALUE, __VA_ARGS__)};                                                                                                                                                                                                                                      \
            return includeEnumName ? STRINGIFY_DEFER(Name::) + values.at(value) : values.at(value);                                                                                                                                                                                                                                                                               \
        }                                                                                                                                                                                                                                                                                                                                                                                       \
        [[nodiscard]] static Name Parse(const UType &value)                                                                                                                                                                                                                                                                                                                                     \
        {                                                                                                                                                                                                                                                                                                                                                                                       \
            using namespace Exceptions;                                                                                                                                                                                                                                                                                                                                                          \
            static const std::map<UType, Name> values = {__EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_MAP_INTEGRALT_ENUMT_VALUE, __VA_ARGS__)};                                                                                                                                                                                                                                     \
            try                                                                                                                                                                                                                                                                                                                                                                                 \
            {                                                                                                                                                                                                                                                                                                                                                                                   \
                return values.at(value);                                                                                                                                                                                                                                                                                                                                                        \
            }                                                                                                                                                                                                                                                                                                                                                                                   \
            catch (...)                                                                                                                                                                                                                                                                                                                                                                         \
            {                                                                                                                                                                                                                                                                                                                                                                                   \
                throw ParseException(STRINGIFY_DEFER(Name##EnumExtensions::Parse));                                                                                                                                                                                                                                                                                                                             \
            }                                                                                                                                                                                                                                                                                                                                                                                   \
        }                                                                                                                                                                                                                                                                                                                                                                                       \
        [[nodiscard]] static Name Parse(const String &value)                                                                                                                                                                                                                                                                                                                                    \
        {                                                                                                                                                                                                                                                                                                                                                                                       \
            using namespace Exceptions;                                                                                                                                                                                                                                                                                                                                                          \
            using namespace Extensions;  \
            static const std::map<String, Name> values = {__EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_MAP_STRINGT_INTEGRALT_VALUE_NO_NAME, __VA_ARGS__) __EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_MAP_STRINGT_INTEGRALT_VALUE_WITH_NAME, __VA_ARGS__) __EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_MAP_STRINGT_INTEGRALT_VALUE_INTEGRAL, __VA_ARGS__)}; \
            try                                                                                                                                                                                                                                                                                                                                                                                 \
            {                                                                                                                                                                                                                                                                                                                                                                                   \
                return values.at(value);                                                                                                                                                                                                                                                                                                                                                        \
            }                                                                                                                                                                                                                                                                                                                                                                                   \
            catch (...)                                                                                                                                                                                                                                                                                                                                                                         \
            {                                                                                                                                                                                                                                                                                                                                                                                   \
                throw ParseException(STRINGIFY_DEFER(Name##EnumExtensions::Parse));                                                                                                                                                                                                                                                                                                                             \
            }                                                                                                                                                                                                                                                                                                                                                                                   \
        }                                                                                                                                                                                                                                                                                                                                                                                       \
        [[nodiscard]] static std::vector<Name> GetValues()                                                                                                                                                                                                                                                                                                                                      \
        {                                                                                                                                                                                                                                                                                                                                                                                       \
            return {__EZNUM_ENUM_EXPAND_1(Name, UType, count, __EZNUM_ENUM_GET_ONLY_VALUE, __VA_ARGS__)};                                                                                                                                                                                                                                                                                     \
        }                                                                                                                                                                                                                                                                                                                                                                                       \
    };
#define __EZNUM_ENUM_OUTPUT_OPERATOR_DECLARATION(Name, UType, count, ...) \
    std::ostream &operator<<(std::ostream &os, const Name &value)          \
    {                                                                      \
        os << Name##EnumExtensions::ToString(value);                       \
        return os;                                                         \
    }
#define __EZNUM_ENUM_UT_EXPAND_1(Name, UType, count, ...) __EZNUM_ENUM_DECLARATION(Name, UType, count, __VA_ARGS__) __EZNUM_ENUM_EXTENSIONS_DECLARATION(Name, UType, count, __VA_ARGS__) __EZNUM_ENUM_OUTPUT_OPERATOR_DECLARATION(Name, UType, count, __VA_ARGS_)
#define EZNUM_ENUM_UT(Name, UType, ...) __EZNUM_ENUM_UT_EXPAND_1(Name, UType, EZNUM_GET_MULTIPLE_OF_3(__VA_ARGS__), __VA_ARGS__)
#define EZNUM_ENUM(Name, ...) EZNUM_ENUM_UT(Name, int, __VA_ARGS__)




using String = std::string;
using namespace std::string_literals;

#define SPACE_CHAR (' ')
#define EMPTY_STRING (""s)


namespace Exceptions
{

	class ExceptionBase : public std::exception
	{
	public:
		ExceptionBase(const std::string& message = EMPTY_STRING, const int& code = 0, std::unique_ptr<ExceptionBase>&& innerException = nullptr)
			: _message(message), _code(code), _innerException(std::move(innerException))
		{
		}

		ExceptionBase(const ExceptionBase& other)
			: _message(other._message),
			_code(other._code),
			_innerException(other._innerException ? std::make_unique<ExceptionBase>(*other._innerException) : nullptr)
		{
		}

		virtual const char* what() const noexcept
		{
			return _message.c_str();
		}

		String Message() const noexcept
		{
			return this->_message;
		}

		int Code() const noexcept
		{
			return this->_code;
		}

		std::unique_ptr<ExceptionBase> InnerException() const noexcept
		{
			return std::make_unique<ExceptionBase>(*_innerException);
		}

		~ExceptionBase() = default;

	private:
		const std::string _message;
		const int _code;
		const std::unique_ptr<ExceptionBase> _innerException;
	};

	class ConvertException : public ExceptionBase
	{
	public:
		ConvertException(const std::string& message = EMPTY_STRING, const int& code = 0, std::unique_ptr<ExceptionBase>&& innerException = nullptr)
			: ExceptionBase(STRINGIFY(ConvertException.) + message + ".", code, std::move(innerException))
		{
		}

	private:
	};

	class ParseException : public ExceptionBase
	{
	public:
		ParseException(const std::string& message = EMPTY_STRING, const int& code = 0, std::unique_ptr<ExceptionBase>&& innerException = nullptr)
			: ExceptionBase(STRINGIFY(ParseException.) + message + ".", code, std::move(innerException))
		{
		}

	private:
	};
}

namespace Extensions
{
	class StringExtensions
	{
	public:
		[[nodiscard]] static String PadRight(const String& data, const size_t& totalWidth, const char& padding = SPACE_CHAR)
		{
			if (data.length() >= totalWidth)
			{
				return data;
			}
			String ret = data;
			ret.resize(totalWidth, padding);
			return ret;
		}
	private:
	};

	class IntegralExtensions
	{
	public:
		template<typename T>
		static std::string ToString(const T& value) requires std::is_integral_v<T> {
			using namespace Exceptions;
			char buffer[32] = {};
			auto [p, ec] = std::to_chars(buffer, buffer + sizeof(buffer), value);
			if (ec == std::errc{}) {
				return std::string(buffer, p - buffer);
			}
			throw ConvertException();
		}


	private:
	};

	class EnumExtensions
	{
	public:
		template <typename EnumType>
		[[nodiscard]] static std::string ToIntegralString(const EnumType& enumValue)
			requires std::is_enum_v<EnumType>
		{
			return IntegralExtensions::ToString(ToIntegral(enumValue));
		}

		template <typename EnumType>
		[[nodiscard]] static std::underlying_type_t<EnumType> ToIntegral(const EnumType& enumValue)
			requires std::is_enum_v<EnumType>
		{
			return static_cast<std::underlying_type_t<EnumType>>(enumValue);
		}


	private:
	};
}


namespace Enums
{
	EZNUM_ENUM_UT(Variables, int,
		X, _, _,
		Y, EQ, 25,
		Z, EQ, 75)

		EZNUM_ENUM_UT(Fruit, int32_t,
			PEAR, EQ, -100,
			APPLE, _, _,
			BANANA, _, _,
			ORANGE, EQ, 100,
			MANGO, _, _,
			STRAWBERRY, EQ, 75,
			WATERMELON, EQ, 100)

		EZNUM_ENUM(Animal,
			Dog, _, _,
			Cat, _, _,
			Monkey, EQ, 50,
			Fish, _, _,
			Human, EQ, 100,
			Duck, _, _,
			__COUNT, _, _)

		EZNUM_ENUM_UT(MathVars32, int32_t,
			X, _, _,
			Y, _, _,
			Z, EQ, 75)

		EZNUM_ENUM_UT(MathVars64, int64_t,
			X, _, _,
			Y, _, _,
			Z, EQ, 75)

		EZNUM_ENUM(Vowels,
			A, EQ, 75,
			E, _, _,
			I, EQ, 1500,
			O, EQ, -5,
			U, _, _)

		EZNUM_ENUM(MobaGame,
			Dota2, EQ, 100,
			LeagueOfLegends, EQ, 101,
			HeroesOfTheStorm, EQ, 102,
			Smite, EQ, 103,
			Vainglory, EQ, 104,
			ArenaOfValor, EQ, 105,
			Paragon, EQ, 106,
			HeroesOfNewerth, EQ, -100)
}


#define PRINT_VALUES(Name) std::cout << "EnumName: "s + #Name << std::endl; \
std::cout << StringExtensions::PadRight(EMPTY_STRING , 21 + 128, '_') << std::endl; \
for (Name element : Name##EnumExtensions::GetValues()) \
{ \
	std::cout << StringExtensions::PadRight(Name##EnumExtensions::ToString(element), 16) << " | " << \
		StringExtensions::PadRight(Name##EnumExtensions::ToString(element, true),32) << " | " << \
		StringExtensions::PadRight(Name##EnumExtensions::ToIntegralString(element),8) << " | " << \
		StringExtensions::PadRight(IntegralExtensions::ToString(Name##EnumExtensions::ToIntegral(element)),8) << " | " << \
		StringExtensions::PadRight(Name##EnumExtensions::ToString(Name##EnumExtensions::Parse(Name##EnumExtensions::ToString(element))),16) << " | " << \
		StringExtensions::PadRight(Name##EnumExtensions::ToString(Name##EnumExtensions::Parse(Name##EnumExtensions::ToString(element, true))),16) << " | " << \
		StringExtensions::PadRight(Name##EnumExtensions::ToString(Name##EnumExtensions::Parse(Name##EnumExtensions::ToIntegralString(element))),16) << " | " << \
		StringExtensions::PadRight(Name##EnumExtensions::ToString(Name##EnumExtensions::Parse(Name##EnumExtensions::ToIntegral(element))),16) << std::endl; \
} \
std::cout<< std::endl;


int main() {


	using namespace Enums;
	using namespace Extensions;
	PRINT_VALUES(Variables)
	PRINT_VALUES(Fruit)
	PRINT_VALUES(Animal)
	PRINT_VALUES(MathVars32)
	PRINT_VALUES(MathVars64)
	PRINT_VALUES(Vowels)
	PRINT_VALUES(MobaGame)
	/*	std::cout << "EnumName: "s + "MobaGame" << std::endl;
	std::cout << StringExtensions::PadRight(EMPTY_STRING, 21 + 128, '_') << std::endl;
	for (MobaGame element : MobaGameEnumExtensions::GetValues())
	{
		std::cout << StringExtensions::PadRight(MobaGameEnumExtensions::ToString(element), 16) << " | " << StringExtensions::PadRight(MobaGameEnumExtensions::ToString(element, true), 32) << " | " << StringExtensions::PadRight(MobaGameEnumExtensions::ToIntegralString(element), 8) << " | " << StringExtensions::PadRight(IntegralExtensions::ToString(MobaGameEnumExtensions::ToIntegral(element)), 8) << " | " << StringExtensions::PadRight(MobaGameEnumExtensions::ToString(MobaGameEnumExtensions::Parse(MobaGameEnumExtensions::ToString(element))), 16) << " | " << StringExtensions::PadRight(MobaGameEnumExtensions::ToString(MobaGameEnumExtensions::Parse(MobaGameEnumExtensions::ToString(element, true))), 16) << " | " << StringExtensions::PadRight(MobaGameEnumExtensions::ToString(MobaGameEnumExtensions::Parse(MobaGameEnumExtensions::ToIntegralString(element))), 16) << " | " << StringExtensions::PadRight(MobaGameEnumExtensions::ToString(MobaGameEnumExtensions::Parse(MobaGameEnumExtensions::ToIntegral(element))), 16) << std::endl;
	}
	std::cout << std::endl;*/
		std::cin.get();
	return 0;
}
