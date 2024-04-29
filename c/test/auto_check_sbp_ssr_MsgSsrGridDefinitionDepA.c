/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGridDefinitionDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_ssr_MsgSsrGridDefinitionDepA) {
  static sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x5f5, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  245, 5,   181, 247, 255, 11,  84,  171, 229, 132, 143, 46,  204,
        52,  92,  104, 25,  204, 182, 22,  98,  203, 123, 211, 38,  13,  253,
        129, 173, 171, 235, 253, 26,  203, 3,   120, 126, 42,  44,  39,  87,
        69,  154, 13,  28,  179, 32,  47,  36,  195, 39,  198, 134, 235, 134,
        57,  120, 243, 151, 35,  17,  201, 211, 125, 117, 164, 142, 101, 239,
        144, 158, 239, 90,  56,  71,  120, 67,  221, 114, 10,  190, 4,   230,
        164, 171, 78,  185, 90,  46,  177, 82,  228, 123, 222, 227, 145, 195,
        219, 27,  56,  227, 246, 215, 144, 158, 31,  214, 241, 254, 200, 86,
        142, 89,  12,  121, 29,  124, 9,   19,  153, 44,  35,  126, 14,  217,
        65,  116, 26,  139, 122, 114, 90,  124, 81,  0,   186, 246, 46,  98,
        179, 243, 198, 217, 36,  30,  202, 12,  135, 61,  42,  150, 221, 102,
        83,  179, 43,  252, 81,  62,  126, 204, 195, 238, 18,  128, 193, 53,
        94,  99,  63,  182, 2,   186, 220, 77,  186, 224, 220, 13,  212, 182,
        88,  15,  151, 5,   93,  251, 164, 18,  228, 168, 226, 195, 44,  170,
        145, 36,  58,  96,  107, 144, 11,  228, 12,  163, 238, 247, 159, 189,
        1,   115, 65,  202, 121, 47,  193, 11,  96,  93,  72,  81,  207, 121,
        19,  151, 136, 233, 51,  133, 195, 77,  44,  147, 206, 120, 252, 77,
        212, 68,  60,  206, 106, 207, 243, 158, 94,  6,   3,   205, 92,  84,
        2,   220, 50,  61,  38,  141, 117, 108, 101, 76,  139,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_grid_definition_dep_a.header.area_width = 43860;

    test_msg.ssr_grid_definition_dep_a.header.lat_nw_corner_enc = 34021;

    test_msg.ssr_grid_definition_dep_a.header.lon_nw_corner_enc = 11919;

    test_msg.ssr_grid_definition_dep_a.header.num_msgs = 204;

    test_msg.ssr_grid_definition_dep_a.header.region_size_inverse = 11;

    test_msg.ssr_grid_definition_dep_a.header.seq_num = 52;

    test_msg.ssr_grid_definition_dep_a.n_rle_list = 246;

    test_msg.ssr_grid_definition_dep_a.rle_list[0] = 92;

    test_msg.ssr_grid_definition_dep_a.rle_list[1] = 104;

    test_msg.ssr_grid_definition_dep_a.rle_list[2] = 25;

    test_msg.ssr_grid_definition_dep_a.rle_list[3] = 204;

    test_msg.ssr_grid_definition_dep_a.rle_list[4] = 182;

    test_msg.ssr_grid_definition_dep_a.rle_list[5] = 22;

    test_msg.ssr_grid_definition_dep_a.rle_list[6] = 98;

    test_msg.ssr_grid_definition_dep_a.rle_list[7] = 203;

    test_msg.ssr_grid_definition_dep_a.rle_list[8] = 123;

    test_msg.ssr_grid_definition_dep_a.rle_list[9] = 211;

    test_msg.ssr_grid_definition_dep_a.rle_list[10] = 38;

    test_msg.ssr_grid_definition_dep_a.rle_list[11] = 13;

    test_msg.ssr_grid_definition_dep_a.rle_list[12] = 253;

    test_msg.ssr_grid_definition_dep_a.rle_list[13] = 129;

    test_msg.ssr_grid_definition_dep_a.rle_list[14] = 173;

    test_msg.ssr_grid_definition_dep_a.rle_list[15] = 171;

    test_msg.ssr_grid_definition_dep_a.rle_list[16] = 235;

    test_msg.ssr_grid_definition_dep_a.rle_list[17] = 253;

    test_msg.ssr_grid_definition_dep_a.rle_list[18] = 26;

    test_msg.ssr_grid_definition_dep_a.rle_list[19] = 203;

    test_msg.ssr_grid_definition_dep_a.rle_list[20] = 3;

    test_msg.ssr_grid_definition_dep_a.rle_list[21] = 120;

    test_msg.ssr_grid_definition_dep_a.rle_list[22] = 126;

    test_msg.ssr_grid_definition_dep_a.rle_list[23] = 42;

    test_msg.ssr_grid_definition_dep_a.rle_list[24] = 44;

    test_msg.ssr_grid_definition_dep_a.rle_list[25] = 39;

    test_msg.ssr_grid_definition_dep_a.rle_list[26] = 87;

    test_msg.ssr_grid_definition_dep_a.rle_list[27] = 69;

    test_msg.ssr_grid_definition_dep_a.rle_list[28] = 154;

    test_msg.ssr_grid_definition_dep_a.rle_list[29] = 13;

    test_msg.ssr_grid_definition_dep_a.rle_list[30] = 28;

    test_msg.ssr_grid_definition_dep_a.rle_list[31] = 179;

    test_msg.ssr_grid_definition_dep_a.rle_list[32] = 32;

    test_msg.ssr_grid_definition_dep_a.rle_list[33] = 47;

    test_msg.ssr_grid_definition_dep_a.rle_list[34] = 36;

    test_msg.ssr_grid_definition_dep_a.rle_list[35] = 195;

    test_msg.ssr_grid_definition_dep_a.rle_list[36] = 39;

    test_msg.ssr_grid_definition_dep_a.rle_list[37] = 198;

    test_msg.ssr_grid_definition_dep_a.rle_list[38] = 134;

    test_msg.ssr_grid_definition_dep_a.rle_list[39] = 235;

    test_msg.ssr_grid_definition_dep_a.rle_list[40] = 134;

    test_msg.ssr_grid_definition_dep_a.rle_list[41] = 57;

    test_msg.ssr_grid_definition_dep_a.rle_list[42] = 120;

    test_msg.ssr_grid_definition_dep_a.rle_list[43] = 243;

    test_msg.ssr_grid_definition_dep_a.rle_list[44] = 151;

    test_msg.ssr_grid_definition_dep_a.rle_list[45] = 35;

    test_msg.ssr_grid_definition_dep_a.rle_list[46] = 17;

    test_msg.ssr_grid_definition_dep_a.rle_list[47] = 201;

    test_msg.ssr_grid_definition_dep_a.rle_list[48] = 211;

    test_msg.ssr_grid_definition_dep_a.rle_list[49] = 125;

    test_msg.ssr_grid_definition_dep_a.rle_list[50] = 117;

    test_msg.ssr_grid_definition_dep_a.rle_list[51] = 164;

    test_msg.ssr_grid_definition_dep_a.rle_list[52] = 142;

    test_msg.ssr_grid_definition_dep_a.rle_list[53] = 101;

    test_msg.ssr_grid_definition_dep_a.rle_list[54] = 239;

    test_msg.ssr_grid_definition_dep_a.rle_list[55] = 144;

    test_msg.ssr_grid_definition_dep_a.rle_list[56] = 158;

    test_msg.ssr_grid_definition_dep_a.rle_list[57] = 239;

    test_msg.ssr_grid_definition_dep_a.rle_list[58] = 90;

    test_msg.ssr_grid_definition_dep_a.rle_list[59] = 56;

    test_msg.ssr_grid_definition_dep_a.rle_list[60] = 71;

    test_msg.ssr_grid_definition_dep_a.rle_list[61] = 120;

    test_msg.ssr_grid_definition_dep_a.rle_list[62] = 67;

    test_msg.ssr_grid_definition_dep_a.rle_list[63] = 221;

    test_msg.ssr_grid_definition_dep_a.rle_list[64] = 114;

    test_msg.ssr_grid_definition_dep_a.rle_list[65] = 10;

    test_msg.ssr_grid_definition_dep_a.rle_list[66] = 190;

    test_msg.ssr_grid_definition_dep_a.rle_list[67] = 4;

    test_msg.ssr_grid_definition_dep_a.rle_list[68] = 230;

    test_msg.ssr_grid_definition_dep_a.rle_list[69] = 164;

    test_msg.ssr_grid_definition_dep_a.rle_list[70] = 171;

    test_msg.ssr_grid_definition_dep_a.rle_list[71] = 78;

    test_msg.ssr_grid_definition_dep_a.rle_list[72] = 185;

    test_msg.ssr_grid_definition_dep_a.rle_list[73] = 90;

    test_msg.ssr_grid_definition_dep_a.rle_list[74] = 46;

    test_msg.ssr_grid_definition_dep_a.rle_list[75] = 177;

    test_msg.ssr_grid_definition_dep_a.rle_list[76] = 82;

    test_msg.ssr_grid_definition_dep_a.rle_list[77] = 228;

    test_msg.ssr_grid_definition_dep_a.rle_list[78] = 123;

    test_msg.ssr_grid_definition_dep_a.rle_list[79] = 222;

    test_msg.ssr_grid_definition_dep_a.rle_list[80] = 227;

    test_msg.ssr_grid_definition_dep_a.rle_list[81] = 145;

    test_msg.ssr_grid_definition_dep_a.rle_list[82] = 195;

    test_msg.ssr_grid_definition_dep_a.rle_list[83] = 219;

    test_msg.ssr_grid_definition_dep_a.rle_list[84] = 27;

    test_msg.ssr_grid_definition_dep_a.rle_list[85] = 56;

    test_msg.ssr_grid_definition_dep_a.rle_list[86] = 227;

    test_msg.ssr_grid_definition_dep_a.rle_list[87] = 246;

    test_msg.ssr_grid_definition_dep_a.rle_list[88] = 215;

    test_msg.ssr_grid_definition_dep_a.rle_list[89] = 144;

    test_msg.ssr_grid_definition_dep_a.rle_list[90] = 158;

    test_msg.ssr_grid_definition_dep_a.rle_list[91] = 31;

    test_msg.ssr_grid_definition_dep_a.rle_list[92] = 214;

    test_msg.ssr_grid_definition_dep_a.rle_list[93] = 241;

    test_msg.ssr_grid_definition_dep_a.rle_list[94] = 254;

    test_msg.ssr_grid_definition_dep_a.rle_list[95] = 200;

    test_msg.ssr_grid_definition_dep_a.rle_list[96] = 86;

    test_msg.ssr_grid_definition_dep_a.rle_list[97] = 142;

    test_msg.ssr_grid_definition_dep_a.rle_list[98] = 89;

    test_msg.ssr_grid_definition_dep_a.rle_list[99] = 12;

    test_msg.ssr_grid_definition_dep_a.rle_list[100] = 121;

    test_msg.ssr_grid_definition_dep_a.rle_list[101] = 29;

    test_msg.ssr_grid_definition_dep_a.rle_list[102] = 124;

    test_msg.ssr_grid_definition_dep_a.rle_list[103] = 9;

    test_msg.ssr_grid_definition_dep_a.rle_list[104] = 19;

    test_msg.ssr_grid_definition_dep_a.rle_list[105] = 153;

    test_msg.ssr_grid_definition_dep_a.rle_list[106] = 44;

    test_msg.ssr_grid_definition_dep_a.rle_list[107] = 35;

    test_msg.ssr_grid_definition_dep_a.rle_list[108] = 126;

    test_msg.ssr_grid_definition_dep_a.rle_list[109] = 14;

    test_msg.ssr_grid_definition_dep_a.rle_list[110] = 217;

    test_msg.ssr_grid_definition_dep_a.rle_list[111] = 65;

    test_msg.ssr_grid_definition_dep_a.rle_list[112] = 116;

    test_msg.ssr_grid_definition_dep_a.rle_list[113] = 26;

    test_msg.ssr_grid_definition_dep_a.rle_list[114] = 139;

    test_msg.ssr_grid_definition_dep_a.rle_list[115] = 122;

    test_msg.ssr_grid_definition_dep_a.rle_list[116] = 114;

    test_msg.ssr_grid_definition_dep_a.rle_list[117] = 90;

    test_msg.ssr_grid_definition_dep_a.rle_list[118] = 124;

    test_msg.ssr_grid_definition_dep_a.rle_list[119] = 81;

    test_msg.ssr_grid_definition_dep_a.rle_list[120] = 0;

    test_msg.ssr_grid_definition_dep_a.rle_list[121] = 186;

    test_msg.ssr_grid_definition_dep_a.rle_list[122] = 246;

    test_msg.ssr_grid_definition_dep_a.rle_list[123] = 46;

    test_msg.ssr_grid_definition_dep_a.rle_list[124] = 98;

    test_msg.ssr_grid_definition_dep_a.rle_list[125] = 179;

    test_msg.ssr_grid_definition_dep_a.rle_list[126] = 243;

    test_msg.ssr_grid_definition_dep_a.rle_list[127] = 198;

    test_msg.ssr_grid_definition_dep_a.rle_list[128] = 217;

    test_msg.ssr_grid_definition_dep_a.rle_list[129] = 36;

    test_msg.ssr_grid_definition_dep_a.rle_list[130] = 30;

    test_msg.ssr_grid_definition_dep_a.rle_list[131] = 202;

    test_msg.ssr_grid_definition_dep_a.rle_list[132] = 12;

    test_msg.ssr_grid_definition_dep_a.rle_list[133] = 135;

    test_msg.ssr_grid_definition_dep_a.rle_list[134] = 61;

    test_msg.ssr_grid_definition_dep_a.rle_list[135] = 42;

    test_msg.ssr_grid_definition_dep_a.rle_list[136] = 150;

    test_msg.ssr_grid_definition_dep_a.rle_list[137] = 221;

    test_msg.ssr_grid_definition_dep_a.rle_list[138] = 102;

    test_msg.ssr_grid_definition_dep_a.rle_list[139] = 83;

    test_msg.ssr_grid_definition_dep_a.rle_list[140] = 179;

    test_msg.ssr_grid_definition_dep_a.rle_list[141] = 43;

    test_msg.ssr_grid_definition_dep_a.rle_list[142] = 252;

    test_msg.ssr_grid_definition_dep_a.rle_list[143] = 81;

    test_msg.ssr_grid_definition_dep_a.rle_list[144] = 62;

    test_msg.ssr_grid_definition_dep_a.rle_list[145] = 126;

    test_msg.ssr_grid_definition_dep_a.rle_list[146] = 204;

    test_msg.ssr_grid_definition_dep_a.rle_list[147] = 195;

    test_msg.ssr_grid_definition_dep_a.rle_list[148] = 238;

    test_msg.ssr_grid_definition_dep_a.rle_list[149] = 18;

    test_msg.ssr_grid_definition_dep_a.rle_list[150] = 128;

    test_msg.ssr_grid_definition_dep_a.rle_list[151] = 193;

    test_msg.ssr_grid_definition_dep_a.rle_list[152] = 53;

    test_msg.ssr_grid_definition_dep_a.rle_list[153] = 94;

    test_msg.ssr_grid_definition_dep_a.rle_list[154] = 99;

    test_msg.ssr_grid_definition_dep_a.rle_list[155] = 63;

    test_msg.ssr_grid_definition_dep_a.rle_list[156] = 182;

    test_msg.ssr_grid_definition_dep_a.rle_list[157] = 2;

    test_msg.ssr_grid_definition_dep_a.rle_list[158] = 186;

    test_msg.ssr_grid_definition_dep_a.rle_list[159] = 220;

    test_msg.ssr_grid_definition_dep_a.rle_list[160] = 77;

    test_msg.ssr_grid_definition_dep_a.rle_list[161] = 186;

    test_msg.ssr_grid_definition_dep_a.rle_list[162] = 224;

    test_msg.ssr_grid_definition_dep_a.rle_list[163] = 220;

    test_msg.ssr_grid_definition_dep_a.rle_list[164] = 13;

    test_msg.ssr_grid_definition_dep_a.rle_list[165] = 212;

    test_msg.ssr_grid_definition_dep_a.rle_list[166] = 182;

    test_msg.ssr_grid_definition_dep_a.rle_list[167] = 88;

    test_msg.ssr_grid_definition_dep_a.rle_list[168] = 15;

    test_msg.ssr_grid_definition_dep_a.rle_list[169] = 151;

    test_msg.ssr_grid_definition_dep_a.rle_list[170] = 5;

    test_msg.ssr_grid_definition_dep_a.rle_list[171] = 93;

    test_msg.ssr_grid_definition_dep_a.rle_list[172] = 251;

    test_msg.ssr_grid_definition_dep_a.rle_list[173] = 164;

    test_msg.ssr_grid_definition_dep_a.rle_list[174] = 18;

    test_msg.ssr_grid_definition_dep_a.rle_list[175] = 228;

    test_msg.ssr_grid_definition_dep_a.rle_list[176] = 168;

    test_msg.ssr_grid_definition_dep_a.rle_list[177] = 226;

    test_msg.ssr_grid_definition_dep_a.rle_list[178] = 195;

    test_msg.ssr_grid_definition_dep_a.rle_list[179] = 44;

    test_msg.ssr_grid_definition_dep_a.rle_list[180] = 170;

    test_msg.ssr_grid_definition_dep_a.rle_list[181] = 145;

    test_msg.ssr_grid_definition_dep_a.rle_list[182] = 36;

    test_msg.ssr_grid_definition_dep_a.rle_list[183] = 58;

    test_msg.ssr_grid_definition_dep_a.rle_list[184] = 96;

    test_msg.ssr_grid_definition_dep_a.rle_list[185] = 107;

    test_msg.ssr_grid_definition_dep_a.rle_list[186] = 144;

    test_msg.ssr_grid_definition_dep_a.rle_list[187] = 11;

    test_msg.ssr_grid_definition_dep_a.rle_list[188] = 228;

    test_msg.ssr_grid_definition_dep_a.rle_list[189] = 12;

    test_msg.ssr_grid_definition_dep_a.rle_list[190] = 163;

    test_msg.ssr_grid_definition_dep_a.rle_list[191] = 238;

    test_msg.ssr_grid_definition_dep_a.rle_list[192] = 247;

    test_msg.ssr_grid_definition_dep_a.rle_list[193] = 159;

    test_msg.ssr_grid_definition_dep_a.rle_list[194] = 189;

    test_msg.ssr_grid_definition_dep_a.rle_list[195] = 1;

    test_msg.ssr_grid_definition_dep_a.rle_list[196] = 115;

    test_msg.ssr_grid_definition_dep_a.rle_list[197] = 65;

    test_msg.ssr_grid_definition_dep_a.rle_list[198] = 202;

    test_msg.ssr_grid_definition_dep_a.rle_list[199] = 121;

    test_msg.ssr_grid_definition_dep_a.rle_list[200] = 47;

    test_msg.ssr_grid_definition_dep_a.rle_list[201] = 193;

    test_msg.ssr_grid_definition_dep_a.rle_list[202] = 11;

    test_msg.ssr_grid_definition_dep_a.rle_list[203] = 96;

    test_msg.ssr_grid_definition_dep_a.rle_list[204] = 93;

    test_msg.ssr_grid_definition_dep_a.rle_list[205] = 72;

    test_msg.ssr_grid_definition_dep_a.rle_list[206] = 81;

    test_msg.ssr_grid_definition_dep_a.rle_list[207] = 207;

    test_msg.ssr_grid_definition_dep_a.rle_list[208] = 121;

    test_msg.ssr_grid_definition_dep_a.rle_list[209] = 19;

    test_msg.ssr_grid_definition_dep_a.rle_list[210] = 151;

    test_msg.ssr_grid_definition_dep_a.rle_list[211] = 136;

    test_msg.ssr_grid_definition_dep_a.rle_list[212] = 233;

    test_msg.ssr_grid_definition_dep_a.rle_list[213] = 51;

    test_msg.ssr_grid_definition_dep_a.rle_list[214] = 133;

    test_msg.ssr_grid_definition_dep_a.rle_list[215] = 195;

    test_msg.ssr_grid_definition_dep_a.rle_list[216] = 77;

    test_msg.ssr_grid_definition_dep_a.rle_list[217] = 44;

    test_msg.ssr_grid_definition_dep_a.rle_list[218] = 147;

    test_msg.ssr_grid_definition_dep_a.rle_list[219] = 206;

    test_msg.ssr_grid_definition_dep_a.rle_list[220] = 120;

    test_msg.ssr_grid_definition_dep_a.rle_list[221] = 252;

    test_msg.ssr_grid_definition_dep_a.rle_list[222] = 77;

    test_msg.ssr_grid_definition_dep_a.rle_list[223] = 212;

    test_msg.ssr_grid_definition_dep_a.rle_list[224] = 68;

    test_msg.ssr_grid_definition_dep_a.rle_list[225] = 60;

    test_msg.ssr_grid_definition_dep_a.rle_list[226] = 206;

    test_msg.ssr_grid_definition_dep_a.rle_list[227] = 106;

    test_msg.ssr_grid_definition_dep_a.rle_list[228] = 207;

    test_msg.ssr_grid_definition_dep_a.rle_list[229] = 243;

    test_msg.ssr_grid_definition_dep_a.rle_list[230] = 158;

    test_msg.ssr_grid_definition_dep_a.rle_list[231] = 94;

    test_msg.ssr_grid_definition_dep_a.rle_list[232] = 6;

    test_msg.ssr_grid_definition_dep_a.rle_list[233] = 3;

    test_msg.ssr_grid_definition_dep_a.rle_list[234] = 205;

    test_msg.ssr_grid_definition_dep_a.rle_list[235] = 92;

    test_msg.ssr_grid_definition_dep_a.rle_list[236] = 84;

    test_msg.ssr_grid_definition_dep_a.rle_list[237] = 2;

    test_msg.ssr_grid_definition_dep_a.rle_list[238] = 220;

    test_msg.ssr_grid_definition_dep_a.rle_list[239] = 50;

    test_msg.ssr_grid_definition_dep_a.rle_list[240] = 61;

    test_msg.ssr_grid_definition_dep_a.rle_list[241] = 38;

    test_msg.ssr_grid_definition_dep_a.rle_list[242] = 141;

    test_msg.ssr_grid_definition_dep_a.rle_list[243] = 117;

    test_msg.ssr_grid_definition_dep_a.rle_list[244] = 108;

    test_msg.ssr_grid_definition_dep_a.rle_list[245] = 101;

    sbp_message_send(&sbp_state, SbpMsgSsrGridDefinitionDepA, 63413, &test_msg,
                     &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 63413,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgSsrGridDefinitionDepA, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.header.area_width == 43860,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.header.area_width, expected "
        "43860, is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.header.area_width);

    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.header.lat_nw_corner_enc ==
            34021,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.header.lat_nw_corner_enc, "
        "expected 34021, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_grid_definition_dep_a.header.lat_nw_corner_enc);

    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.header.lon_nw_corner_enc ==
            11919,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.header.lon_nw_corner_enc, "
        "expected 11919, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_grid_definition_dep_a.header.lon_nw_corner_enc);

    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.header.num_msgs == 204,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.header.num_msgs, expected 204, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.header.num_msgs);

    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.header.region_size_inverse == 11,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.header.region_size_inverse, "
        "expected 11, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_grid_definition_dep_a.header.region_size_inverse);

    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.header.seq_num == 52,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.header.seq_num, expected 52, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.header.seq_num);

    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.n_rle_list == 246,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.n_rle_list, expected "
                  "246, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.n_rle_list);

    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[0] == 92,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[0], "
                  "expected 92, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[0]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[1] == 104,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[1], "
                  "expected 104, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[1]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[2] == 25,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[2], "
                  "expected 25, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[2]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[3] == 204,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[3], "
                  "expected 204, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[3]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[4] == 182,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[4], "
                  "expected 182, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[4]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[5] == 22,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[5], "
                  "expected 22, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[5]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[6] == 98,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[6], "
                  "expected 98, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[6]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[7] == 203,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[7], "
                  "expected 203, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[7]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[8] == 123,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[8], "
                  "expected 123, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[8]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[9] == 211,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[9], "
                  "expected 211, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[9]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[10] == 38,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[10], "
                  "expected 38, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[10]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[11] == 13,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[11], "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[11]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[12] == 253,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[12], "
                  "expected 253, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[12]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[13] == 129,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[13], "
                  "expected 129, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[13]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[14] == 173,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[14], "
                  "expected 173, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[14]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[15] == 171,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[15], "
                  "expected 171, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[15]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[16] == 235,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[16], "
                  "expected 235, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[16]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[17] == 253,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[17], "
                  "expected 253, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[17]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[18] == 26,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[18], "
                  "expected 26, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[18]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[19] == 203,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[19], "
                  "expected 203, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[19]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[20] == 3,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[20], "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[20]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[21] == 120,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[21], "
                  "expected 120, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[21]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[22] == 126,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[22], "
                  "expected 126, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[22]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[23] == 42,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[23], "
                  "expected 42, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[23]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[24] == 44,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[24], "
                  "expected 44, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[24]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[25] == 39,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[25], "
                  "expected 39, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[25]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[26] == 87,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[26], "
                  "expected 87, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[26]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[27] == 69,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[27], "
                  "expected 69, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[27]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[28] == 154,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[28], "
                  "expected 154, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[28]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[29] == 13,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[29], "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[29]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[30] == 28,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[30], "
                  "expected 28, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[30]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[31] == 179,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[31], "
                  "expected 179, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[31]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[32] == 32,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[32], "
                  "expected 32, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[32]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[33] == 47,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[33], "
                  "expected 47, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[33]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[34] == 36,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[34], "
                  "expected 36, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[34]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[35] == 195,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[35], "
                  "expected 195, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[35]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[36] == 39,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[36], "
                  "expected 39, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[36]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[37] == 198,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[37], "
                  "expected 198, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[37]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[38] == 134,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[38], "
                  "expected 134, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[38]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[39] == 235,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[39], "
                  "expected 235, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[39]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[40] == 134,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[40], "
                  "expected 134, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[40]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[41] == 57,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[41], "
                  "expected 57, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[41]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[42] == 120,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[42], "
                  "expected 120, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[42]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[43] == 243,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[43], "
                  "expected 243, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[43]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[44] == 151,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[44], "
                  "expected 151, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[44]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[45] == 35,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[45], "
                  "expected 35, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[45]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[46] == 17,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[46], "
                  "expected 17, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[46]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[47] == 201,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[47], "
                  "expected 201, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[47]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[48] == 211,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[48], "
                  "expected 211, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[48]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[49] == 125,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[49], "
                  "expected 125, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[49]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[50] == 117,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[50], "
                  "expected 117, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[50]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[51] == 164,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[51], "
                  "expected 164, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[51]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[52] == 142,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[52], "
                  "expected 142, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[52]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[53] == 101,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[53], "
                  "expected 101, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[53]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[54] == 239,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[54], "
                  "expected 239, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[54]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[55] == 144,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[55], "
                  "expected 144, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[55]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[56] == 158,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[56], "
                  "expected 158, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[56]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[57] == 239,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[57], "
                  "expected 239, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[57]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[58] == 90,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[58], "
                  "expected 90, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[58]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[59] == 56,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[59], "
                  "expected 56, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[59]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[60] == 71,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[60], "
                  "expected 71, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[60]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[61] == 120,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[61], "
                  "expected 120, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[61]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[62] == 67,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[62], "
                  "expected 67, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[62]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[63] == 221,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[63], "
                  "expected 221, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[63]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[64] == 114,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[64], "
                  "expected 114, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[64]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[65] == 10,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[65], "
                  "expected 10, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[65]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[66] == 190,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[66], "
                  "expected 190, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[66]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[67] == 4,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[67], "
                  "expected 4, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[67]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[68] == 230,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[68], "
                  "expected 230, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[68]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[69] == 164,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[69], "
                  "expected 164, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[69]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[70] == 171,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[70], "
                  "expected 171, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[70]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[71] == 78,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[71], "
                  "expected 78, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[71]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[72] == 185,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[72], "
                  "expected 185, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[72]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[73] == 90,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[73], "
                  "expected 90, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[73]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[74] == 46,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[74], "
                  "expected 46, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[74]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[75] == 177,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[75], "
                  "expected 177, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[75]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[76] == 82,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[76], "
                  "expected 82, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[76]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[77] == 228,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[77], "
                  "expected 228, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[77]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[78] == 123,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[78], "
                  "expected 123, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[78]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[79] == 222,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[79], "
                  "expected 222, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[79]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[80] == 227,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[80], "
                  "expected 227, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[80]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[81] == 145,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[81], "
                  "expected 145, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[81]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[82] == 195,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[82], "
                  "expected 195, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[82]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[83] == 219,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[83], "
                  "expected 219, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[83]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[84] == 27,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[84], "
                  "expected 27, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[84]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[85] == 56,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[85], "
                  "expected 56, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[85]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[86] == 227,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[86], "
                  "expected 227, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[86]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[87] == 246,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[87], "
                  "expected 246, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[87]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[88] == 215,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[88], "
                  "expected 215, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[88]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[89] == 144,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[89], "
                  "expected 144, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[89]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[90] == 158,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[90], "
                  "expected 158, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[90]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[91] == 31,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[91], "
                  "expected 31, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[91]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[92] == 214,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[92], "
                  "expected 214, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[92]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[93] == 241,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[93], "
                  "expected 241, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[93]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[94] == 254,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[94], "
                  "expected 254, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[94]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[95] == 200,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[95], "
                  "expected 200, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[95]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[96] == 86,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[96], "
                  "expected 86, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[96]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[97] == 142,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[97], "
                  "expected 142, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[97]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[98] == 89,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[98], "
                  "expected 89, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[98]);
    ck_assert_msg(last_msg.msg.ssr_grid_definition_dep_a.rle_list[99] == 12,
                  "incorrect value for "
                  "last_msg.msg.ssr_grid_definition_dep_a.rle_list[99], "
                  "expected 12, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[99]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[100] == 121,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[100], expected 121, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[100]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[101] == 29,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[101], expected 29, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[101]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[102] == 124,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[102], expected 124, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[102]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[103] == 9,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[103], expected 9, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[103]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[104] == 19,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[104], expected 19, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[104]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[105] == 153,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[105], expected 153, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[105]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[106] == 44,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[106], expected 44, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[106]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[107] == 35,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[107], expected 35, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[107]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[108] == 126,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[108], expected 126, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[108]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[109] == 14,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[109], expected 14, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[109]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[110] == 217,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[110], expected 217, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[110]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[111] == 65,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[111], expected 65, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[111]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[112] == 116,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[112], expected 116, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[112]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[113] == 26,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[113], expected 26, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[113]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[114] == 139,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[114], expected 139, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[114]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[115] == 122,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[115], expected 122, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[115]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[116] == 114,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[116], expected 114, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[116]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[117] == 90,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[117], expected 90, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[117]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[118] == 124,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[118], expected 124, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[118]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[119] == 81,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[119], expected 81, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[119]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[120] == 0,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[120], expected 0, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[120]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[121] == 186,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[121], expected 186, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[121]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[122] == 246,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[122], expected 246, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[122]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[123] == 46,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[123], expected 46, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[123]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[124] == 98,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[124], expected 98, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[124]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[125] == 179,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[125], expected 179, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[125]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[126] == 243,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[126], expected 243, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[126]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[127] == 198,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[127], expected 198, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[127]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[128] == 217,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[128], expected 217, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[128]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[129] == 36,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[129], expected 36, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[129]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[130] == 30,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[130], expected 30, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[130]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[131] == 202,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[131], expected 202, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[131]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[132] == 12,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[132], expected 12, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[132]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[133] == 135,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[133], expected 135, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[133]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[134] == 61,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[134], expected 61, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[134]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[135] == 42,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[135], expected 42, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[135]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[136] == 150,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[136], expected 150, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[136]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[137] == 221,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[137], expected 221, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[137]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[138] == 102,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[138], expected 102, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[138]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[139] == 83,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[139], expected 83, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[139]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[140] == 179,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[140], expected 179, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[140]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[141] == 43,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[141], expected 43, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[141]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[142] == 252,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[142], expected 252, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[142]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[143] == 81,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[143], expected 81, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[143]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[144] == 62,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[144], expected 62, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[144]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[145] == 126,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[145], expected 126, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[145]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[146] == 204,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[146], expected 204, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[146]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[147] == 195,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[147], expected 195, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[147]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[148] == 238,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[148], expected 238, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[148]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[149] == 18,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[149], expected 18, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[149]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[150] == 128,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[150], expected 128, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[150]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[151] == 193,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[151], expected 193, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[151]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[152] == 53,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[152], expected 53, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[152]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[153] == 94,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[153], expected 94, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[153]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[154] == 99,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[154], expected 99, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[154]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[155] == 63,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[155], expected 63, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[155]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[156] == 182,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[156], expected 182, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[156]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[157] == 2,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[157], expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[157]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[158] == 186,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[158], expected 186, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[158]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[159] == 220,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[159], expected 220, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[159]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[160] == 77,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[160], expected 77, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[160]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[161] == 186,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[161], expected 186, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[161]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[162] == 224,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[162], expected 224, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[162]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[163] == 220,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[163], expected 220, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[163]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[164] == 13,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[164], expected 13, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[164]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[165] == 212,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[165], expected 212, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[165]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[166] == 182,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[166], expected 182, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[166]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[167] == 88,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[167], expected 88, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[167]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[168] == 15,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[168], expected 15, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[168]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[169] == 151,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[169], expected 151, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[169]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[170] == 5,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[170], expected 5, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[170]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[171] == 93,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[171], expected 93, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[171]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[172] == 251,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[172], expected 251, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[172]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[173] == 164,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[173], expected 164, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[173]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[174] == 18,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[174], expected 18, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[174]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[175] == 228,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[175], expected 228, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[175]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[176] == 168,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[176], expected 168, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[176]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[177] == 226,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[177], expected 226, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[177]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[178] == 195,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[178], expected 195, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[178]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[179] == 44,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[179], expected 44, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[179]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[180] == 170,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[180], expected 170, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[180]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[181] == 145,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[181], expected 145, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[181]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[182] == 36,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[182], expected 36, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[182]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[183] == 58,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[183], expected 58, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[183]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[184] == 96,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[184], expected 96, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[184]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[185] == 107,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[185], expected 107, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[185]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[186] == 144,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[186], expected 144, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[186]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[187] == 11,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[187], expected 11, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[187]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[188] == 228,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[188], expected 228, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[188]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[189] == 12,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[189], expected 12, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[189]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[190] == 163,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[190], expected 163, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[190]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[191] == 238,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[191], expected 238, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[191]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[192] == 247,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[192], expected 247, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[192]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[193] == 159,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[193], expected 159, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[193]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[194] == 189,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[194], expected 189, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[194]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[195] == 1,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[195], expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[195]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[196] == 115,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[196], expected 115, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[196]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[197] == 65,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[197], expected 65, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[197]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[198] == 202,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[198], expected 202, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[198]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[199] == 121,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[199], expected 121, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[199]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[200] == 47,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[200], expected 47, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[200]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[201] == 193,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[201], expected 193, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[201]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[202] == 11,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[202], expected 11, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[202]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[203] == 96,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[203], expected 96, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[203]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[204] == 93,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[204], expected 93, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[204]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[205] == 72,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[205], expected 72, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[205]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[206] == 81,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[206], expected 81, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[206]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[207] == 207,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[207], expected 207, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[207]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[208] == 121,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[208], expected 121, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[208]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[209] == 19,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[209], expected 19, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[209]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[210] == 151,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[210], expected 151, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[210]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[211] == 136,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[211], expected 136, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[211]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[212] == 233,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[212], expected 233, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[212]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[213] == 51,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[213], expected 51, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[213]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[214] == 133,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[214], expected 133, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[214]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[215] == 195,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[215], expected 195, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[215]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[216] == 77,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[216], expected 77, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[216]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[217] == 44,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[217], expected 44, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[217]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[218] == 147,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[218], expected 147, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[218]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[219] == 206,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[219], expected 206, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[219]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[220] == 120,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[220], expected 120, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[220]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[221] == 252,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[221], expected 252, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[221]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[222] == 77,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[222], expected 77, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[222]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[223] == 212,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[223], expected 212, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[223]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[224] == 68,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[224], expected 68, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[224]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[225] == 60,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[225], expected 60, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[225]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[226] == 206,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[226], expected 206, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[226]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[227] == 106,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[227], expected 106, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[227]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[228] == 207,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[228], expected 207, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[228]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[229] == 243,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[229], expected 243, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[229]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[230] == 158,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[230], expected 158, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[230]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[231] == 94,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[231], expected 94, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[231]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[232] == 6,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[232], expected 6, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[232]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[233] == 3,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[233], expected 3, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[233]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[234] == 205,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[234], expected 205, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[234]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[235] == 92,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[235], expected 92, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[235]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[236] == 84,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[236], expected 84, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[236]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[237] == 2,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[237], expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[237]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[238] == 220,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[238], expected 220, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[238]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[239] == 50,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[239], expected 50, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[239]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[240] == 61,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[240], expected 61, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[240]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[241] == 38,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[241], expected 38, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[241]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[242] == 141,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[242], expected 141, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[242]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[243] == 117,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[243], expected 117, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[243]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[244] == 108,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[244], expected 108, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[244]);
    ck_assert_msg(
        last_msg.msg.ssr_grid_definition_dep_a.rle_list[245] == 101,
        "incorrect value for "
        "last_msg.msg.ssr_grid_definition_dep_a.rle_list[245], expected 101, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_grid_definition_dep_a.rle_list[245]);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrGridDefinitionDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_ssr_MsgSsrGridDefinitionDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_ssr_MsgSsrGridDefinitionDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrGridDefinitionDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}