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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/signing.h>
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
static u32 dummy_rd = 0;
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
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_signing_MsgEcdsaSignatureDepA) {
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

    sbp_callback_register(&sbp_state, 0xC06, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  6,   12,  66,  0,   255, 0,   1,   2,   1,   2,   3,   4,   0,
        1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,
        7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,
        5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,
        3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   0,
        1,   2,   3,   4,   5,   6,   7,   10,  21,  23,  63,  140, 37,  130,
        106, 28,  40,  165, 179, 73,  178, 60,  126, 114, 78,  113, 27,  95,
        3,   62,  104, 145, 96,  19,  92,  123, 14,  90,  153, 183, 9,   72,
        81,  118, 112, 124, 16,  182, 76,  146, 115, 58,  144, 17,  105, 66,
        31,  135, 54,  100, 84,  181, 103, 11,  88,  133, 155, 167, 173, 143,
        86,  158, 20,  168, 132, 141, 102, 50,  48,  71,  147, 53,  87,  1,
        108, 138, 36,  134, 139, 163, 82,  43,  52,  150, 12,  30,  110, 156,
        107, 120, 91,  122, 69,  164, 170, 116, 25,  94,  5,   22,  24,  162,
        175, 38,  157, 98,  44,  160, 47,  97,  142, 8,   74,  13,  177, 15,
        128, 26,  131, 154, 65,  169, 55,  136, 125, 171, 161, 29,  129, 151,
        68,  166, 51,  70,  45,  56,  79,  149, 99,  42,  101, 152, 39,  89,
        180, 64,  49,  6,   80,  172, 32,  109, 2,   119, 93,  176, 0,   33,
        57,  34,  18,  85,  121, 137, 83,  111, 59,  7,   77,  4,   117, 159,
        148, 35,  61,  41,  67,  46,  127, 75,  174, 97,  172,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ecdsa_signature_dep_a.certificate_id[0] = 1;

    test_msg.ecdsa_signature_dep_a.certificate_id[1] = 2;

    test_msg.ecdsa_signature_dep_a.certificate_id[2] = 3;

    test_msg.ecdsa_signature_dep_a.certificate_id[3] = 4;

    test_msg.ecdsa_signature_dep_a.flags = 0;

    test_msg.ecdsa_signature_dep_a.n_signed_messages = 184;

    test_msg.ecdsa_signature_dep_a.on_demand_counter = 2;

    test_msg.ecdsa_signature_dep_a.signature[0] = 0;

    test_msg.ecdsa_signature_dep_a.signature[1] = 1;

    test_msg.ecdsa_signature_dep_a.signature[2] = 2;

    test_msg.ecdsa_signature_dep_a.signature[3] = 3;

    test_msg.ecdsa_signature_dep_a.signature[4] = 4;

    test_msg.ecdsa_signature_dep_a.signature[5] = 5;

    test_msg.ecdsa_signature_dep_a.signature[6] = 6;

    test_msg.ecdsa_signature_dep_a.signature[7] = 7;

    test_msg.ecdsa_signature_dep_a.signature[8] = 0;

    test_msg.ecdsa_signature_dep_a.signature[9] = 1;

    test_msg.ecdsa_signature_dep_a.signature[10] = 2;

    test_msg.ecdsa_signature_dep_a.signature[11] = 3;

    test_msg.ecdsa_signature_dep_a.signature[12] = 4;

    test_msg.ecdsa_signature_dep_a.signature[13] = 5;

    test_msg.ecdsa_signature_dep_a.signature[14] = 6;

    test_msg.ecdsa_signature_dep_a.signature[15] = 7;

    test_msg.ecdsa_signature_dep_a.signature[16] = 0;

    test_msg.ecdsa_signature_dep_a.signature[17] = 1;

    test_msg.ecdsa_signature_dep_a.signature[18] = 2;

    test_msg.ecdsa_signature_dep_a.signature[19] = 3;

    test_msg.ecdsa_signature_dep_a.signature[20] = 4;

    test_msg.ecdsa_signature_dep_a.signature[21] = 5;

    test_msg.ecdsa_signature_dep_a.signature[22] = 6;

    test_msg.ecdsa_signature_dep_a.signature[23] = 7;

    test_msg.ecdsa_signature_dep_a.signature[24] = 0;

    test_msg.ecdsa_signature_dep_a.signature[25] = 1;

    test_msg.ecdsa_signature_dep_a.signature[26] = 2;

    test_msg.ecdsa_signature_dep_a.signature[27] = 3;

    test_msg.ecdsa_signature_dep_a.signature[28] = 4;

    test_msg.ecdsa_signature_dep_a.signature[29] = 5;

    test_msg.ecdsa_signature_dep_a.signature[30] = 6;

    test_msg.ecdsa_signature_dep_a.signature[31] = 7;

    test_msg.ecdsa_signature_dep_a.signature[32] = 0;

    test_msg.ecdsa_signature_dep_a.signature[33] = 1;

    test_msg.ecdsa_signature_dep_a.signature[34] = 2;

    test_msg.ecdsa_signature_dep_a.signature[35] = 3;

    test_msg.ecdsa_signature_dep_a.signature[36] = 4;

    test_msg.ecdsa_signature_dep_a.signature[37] = 5;

    test_msg.ecdsa_signature_dep_a.signature[38] = 6;

    test_msg.ecdsa_signature_dep_a.signature[39] = 7;

    test_msg.ecdsa_signature_dep_a.signature[40] = 0;

    test_msg.ecdsa_signature_dep_a.signature[41] = 1;

    test_msg.ecdsa_signature_dep_a.signature[42] = 2;

    test_msg.ecdsa_signature_dep_a.signature[43] = 3;

    test_msg.ecdsa_signature_dep_a.signature[44] = 4;

    test_msg.ecdsa_signature_dep_a.signature[45] = 5;

    test_msg.ecdsa_signature_dep_a.signature[46] = 6;

    test_msg.ecdsa_signature_dep_a.signature[47] = 7;

    test_msg.ecdsa_signature_dep_a.signature[48] = 0;

    test_msg.ecdsa_signature_dep_a.signature[49] = 1;

    test_msg.ecdsa_signature_dep_a.signature[50] = 2;

    test_msg.ecdsa_signature_dep_a.signature[51] = 3;

    test_msg.ecdsa_signature_dep_a.signature[52] = 4;

    test_msg.ecdsa_signature_dep_a.signature[53] = 5;

    test_msg.ecdsa_signature_dep_a.signature[54] = 6;

    test_msg.ecdsa_signature_dep_a.signature[55] = 7;

    test_msg.ecdsa_signature_dep_a.signature[56] = 0;

    test_msg.ecdsa_signature_dep_a.signature[57] = 1;

    test_msg.ecdsa_signature_dep_a.signature[58] = 2;

    test_msg.ecdsa_signature_dep_a.signature[59] = 3;

    test_msg.ecdsa_signature_dep_a.signature[60] = 4;

    test_msg.ecdsa_signature_dep_a.signature[61] = 5;

    test_msg.ecdsa_signature_dep_a.signature[62] = 6;

    test_msg.ecdsa_signature_dep_a.signature[63] = 7;

    test_msg.ecdsa_signature_dep_a.signed_messages[0] = 10;

    test_msg.ecdsa_signature_dep_a.signed_messages[1] = 21;

    test_msg.ecdsa_signature_dep_a.signed_messages[2] = 23;

    test_msg.ecdsa_signature_dep_a.signed_messages[3] = 63;

    test_msg.ecdsa_signature_dep_a.signed_messages[4] = 140;

    test_msg.ecdsa_signature_dep_a.signed_messages[5] = 37;

    test_msg.ecdsa_signature_dep_a.signed_messages[6] = 130;

    test_msg.ecdsa_signature_dep_a.signed_messages[7] = 106;

    test_msg.ecdsa_signature_dep_a.signed_messages[8] = 28;

    test_msg.ecdsa_signature_dep_a.signed_messages[9] = 40;

    test_msg.ecdsa_signature_dep_a.signed_messages[10] = 165;

    test_msg.ecdsa_signature_dep_a.signed_messages[11] = 179;

    test_msg.ecdsa_signature_dep_a.signed_messages[12] = 73;

    test_msg.ecdsa_signature_dep_a.signed_messages[13] = 178;

    test_msg.ecdsa_signature_dep_a.signed_messages[14] = 60;

    test_msg.ecdsa_signature_dep_a.signed_messages[15] = 126;

    test_msg.ecdsa_signature_dep_a.signed_messages[16] = 114;

    test_msg.ecdsa_signature_dep_a.signed_messages[17] = 78;

    test_msg.ecdsa_signature_dep_a.signed_messages[18] = 113;

    test_msg.ecdsa_signature_dep_a.signed_messages[19] = 27;

    test_msg.ecdsa_signature_dep_a.signed_messages[20] = 95;

    test_msg.ecdsa_signature_dep_a.signed_messages[21] = 3;

    test_msg.ecdsa_signature_dep_a.signed_messages[22] = 62;

    test_msg.ecdsa_signature_dep_a.signed_messages[23] = 104;

    test_msg.ecdsa_signature_dep_a.signed_messages[24] = 145;

    test_msg.ecdsa_signature_dep_a.signed_messages[25] = 96;

    test_msg.ecdsa_signature_dep_a.signed_messages[26] = 19;

    test_msg.ecdsa_signature_dep_a.signed_messages[27] = 92;

    test_msg.ecdsa_signature_dep_a.signed_messages[28] = 123;

    test_msg.ecdsa_signature_dep_a.signed_messages[29] = 14;

    test_msg.ecdsa_signature_dep_a.signed_messages[30] = 90;

    test_msg.ecdsa_signature_dep_a.signed_messages[31] = 153;

    test_msg.ecdsa_signature_dep_a.signed_messages[32] = 183;

    test_msg.ecdsa_signature_dep_a.signed_messages[33] = 9;

    test_msg.ecdsa_signature_dep_a.signed_messages[34] = 72;

    test_msg.ecdsa_signature_dep_a.signed_messages[35] = 81;

    test_msg.ecdsa_signature_dep_a.signed_messages[36] = 118;

    test_msg.ecdsa_signature_dep_a.signed_messages[37] = 112;

    test_msg.ecdsa_signature_dep_a.signed_messages[38] = 124;

    test_msg.ecdsa_signature_dep_a.signed_messages[39] = 16;

    test_msg.ecdsa_signature_dep_a.signed_messages[40] = 182;

    test_msg.ecdsa_signature_dep_a.signed_messages[41] = 76;

    test_msg.ecdsa_signature_dep_a.signed_messages[42] = 146;

    test_msg.ecdsa_signature_dep_a.signed_messages[43] = 115;

    test_msg.ecdsa_signature_dep_a.signed_messages[44] = 58;

    test_msg.ecdsa_signature_dep_a.signed_messages[45] = 144;

    test_msg.ecdsa_signature_dep_a.signed_messages[46] = 17;

    test_msg.ecdsa_signature_dep_a.signed_messages[47] = 105;

    test_msg.ecdsa_signature_dep_a.signed_messages[48] = 66;

    test_msg.ecdsa_signature_dep_a.signed_messages[49] = 31;

    test_msg.ecdsa_signature_dep_a.signed_messages[50] = 135;

    test_msg.ecdsa_signature_dep_a.signed_messages[51] = 54;

    test_msg.ecdsa_signature_dep_a.signed_messages[52] = 100;

    test_msg.ecdsa_signature_dep_a.signed_messages[53] = 84;

    test_msg.ecdsa_signature_dep_a.signed_messages[54] = 181;

    test_msg.ecdsa_signature_dep_a.signed_messages[55] = 103;

    test_msg.ecdsa_signature_dep_a.signed_messages[56] = 11;

    test_msg.ecdsa_signature_dep_a.signed_messages[57] = 88;

    test_msg.ecdsa_signature_dep_a.signed_messages[58] = 133;

    test_msg.ecdsa_signature_dep_a.signed_messages[59] = 155;

    test_msg.ecdsa_signature_dep_a.signed_messages[60] = 167;

    test_msg.ecdsa_signature_dep_a.signed_messages[61] = 173;

    test_msg.ecdsa_signature_dep_a.signed_messages[62] = 143;

    test_msg.ecdsa_signature_dep_a.signed_messages[63] = 86;

    test_msg.ecdsa_signature_dep_a.signed_messages[64] = 158;

    test_msg.ecdsa_signature_dep_a.signed_messages[65] = 20;

    test_msg.ecdsa_signature_dep_a.signed_messages[66] = 168;

    test_msg.ecdsa_signature_dep_a.signed_messages[67] = 132;

    test_msg.ecdsa_signature_dep_a.signed_messages[68] = 141;

    test_msg.ecdsa_signature_dep_a.signed_messages[69] = 102;

    test_msg.ecdsa_signature_dep_a.signed_messages[70] = 50;

    test_msg.ecdsa_signature_dep_a.signed_messages[71] = 48;

    test_msg.ecdsa_signature_dep_a.signed_messages[72] = 71;

    test_msg.ecdsa_signature_dep_a.signed_messages[73] = 147;

    test_msg.ecdsa_signature_dep_a.signed_messages[74] = 53;

    test_msg.ecdsa_signature_dep_a.signed_messages[75] = 87;

    test_msg.ecdsa_signature_dep_a.signed_messages[76] = 1;

    test_msg.ecdsa_signature_dep_a.signed_messages[77] = 108;

    test_msg.ecdsa_signature_dep_a.signed_messages[78] = 138;

    test_msg.ecdsa_signature_dep_a.signed_messages[79] = 36;

    test_msg.ecdsa_signature_dep_a.signed_messages[80] = 134;

    test_msg.ecdsa_signature_dep_a.signed_messages[81] = 139;

    test_msg.ecdsa_signature_dep_a.signed_messages[82] = 163;

    test_msg.ecdsa_signature_dep_a.signed_messages[83] = 82;

    test_msg.ecdsa_signature_dep_a.signed_messages[84] = 43;

    test_msg.ecdsa_signature_dep_a.signed_messages[85] = 52;

    test_msg.ecdsa_signature_dep_a.signed_messages[86] = 150;

    test_msg.ecdsa_signature_dep_a.signed_messages[87] = 12;

    test_msg.ecdsa_signature_dep_a.signed_messages[88] = 30;

    test_msg.ecdsa_signature_dep_a.signed_messages[89] = 110;

    test_msg.ecdsa_signature_dep_a.signed_messages[90] = 156;

    test_msg.ecdsa_signature_dep_a.signed_messages[91] = 107;

    test_msg.ecdsa_signature_dep_a.signed_messages[92] = 120;

    test_msg.ecdsa_signature_dep_a.signed_messages[93] = 91;

    test_msg.ecdsa_signature_dep_a.signed_messages[94] = 122;

    test_msg.ecdsa_signature_dep_a.signed_messages[95] = 69;

    test_msg.ecdsa_signature_dep_a.signed_messages[96] = 164;

    test_msg.ecdsa_signature_dep_a.signed_messages[97] = 170;

    test_msg.ecdsa_signature_dep_a.signed_messages[98] = 116;

    test_msg.ecdsa_signature_dep_a.signed_messages[99] = 25;

    test_msg.ecdsa_signature_dep_a.signed_messages[100] = 94;

    test_msg.ecdsa_signature_dep_a.signed_messages[101] = 5;

    test_msg.ecdsa_signature_dep_a.signed_messages[102] = 22;

    test_msg.ecdsa_signature_dep_a.signed_messages[103] = 24;

    test_msg.ecdsa_signature_dep_a.signed_messages[104] = 162;

    test_msg.ecdsa_signature_dep_a.signed_messages[105] = 175;

    test_msg.ecdsa_signature_dep_a.signed_messages[106] = 38;

    test_msg.ecdsa_signature_dep_a.signed_messages[107] = 157;

    test_msg.ecdsa_signature_dep_a.signed_messages[108] = 98;

    test_msg.ecdsa_signature_dep_a.signed_messages[109] = 44;

    test_msg.ecdsa_signature_dep_a.signed_messages[110] = 160;

    test_msg.ecdsa_signature_dep_a.signed_messages[111] = 47;

    test_msg.ecdsa_signature_dep_a.signed_messages[112] = 97;

    test_msg.ecdsa_signature_dep_a.signed_messages[113] = 142;

    test_msg.ecdsa_signature_dep_a.signed_messages[114] = 8;

    test_msg.ecdsa_signature_dep_a.signed_messages[115] = 74;

    test_msg.ecdsa_signature_dep_a.signed_messages[116] = 13;

    test_msg.ecdsa_signature_dep_a.signed_messages[117] = 177;

    test_msg.ecdsa_signature_dep_a.signed_messages[118] = 15;

    test_msg.ecdsa_signature_dep_a.signed_messages[119] = 128;

    test_msg.ecdsa_signature_dep_a.signed_messages[120] = 26;

    test_msg.ecdsa_signature_dep_a.signed_messages[121] = 131;

    test_msg.ecdsa_signature_dep_a.signed_messages[122] = 154;

    test_msg.ecdsa_signature_dep_a.signed_messages[123] = 65;

    test_msg.ecdsa_signature_dep_a.signed_messages[124] = 169;

    test_msg.ecdsa_signature_dep_a.signed_messages[125] = 55;

    test_msg.ecdsa_signature_dep_a.signed_messages[126] = 136;

    test_msg.ecdsa_signature_dep_a.signed_messages[127] = 125;

    test_msg.ecdsa_signature_dep_a.signed_messages[128] = 171;

    test_msg.ecdsa_signature_dep_a.signed_messages[129] = 161;

    test_msg.ecdsa_signature_dep_a.signed_messages[130] = 29;

    test_msg.ecdsa_signature_dep_a.signed_messages[131] = 129;

    test_msg.ecdsa_signature_dep_a.signed_messages[132] = 151;

    test_msg.ecdsa_signature_dep_a.signed_messages[133] = 68;

    test_msg.ecdsa_signature_dep_a.signed_messages[134] = 166;

    test_msg.ecdsa_signature_dep_a.signed_messages[135] = 51;

    test_msg.ecdsa_signature_dep_a.signed_messages[136] = 70;

    test_msg.ecdsa_signature_dep_a.signed_messages[137] = 45;

    test_msg.ecdsa_signature_dep_a.signed_messages[138] = 56;

    test_msg.ecdsa_signature_dep_a.signed_messages[139] = 79;

    test_msg.ecdsa_signature_dep_a.signed_messages[140] = 149;

    test_msg.ecdsa_signature_dep_a.signed_messages[141] = 99;

    test_msg.ecdsa_signature_dep_a.signed_messages[142] = 42;

    test_msg.ecdsa_signature_dep_a.signed_messages[143] = 101;

    test_msg.ecdsa_signature_dep_a.signed_messages[144] = 152;

    test_msg.ecdsa_signature_dep_a.signed_messages[145] = 39;

    test_msg.ecdsa_signature_dep_a.signed_messages[146] = 89;

    test_msg.ecdsa_signature_dep_a.signed_messages[147] = 180;

    test_msg.ecdsa_signature_dep_a.signed_messages[148] = 64;

    test_msg.ecdsa_signature_dep_a.signed_messages[149] = 49;

    test_msg.ecdsa_signature_dep_a.signed_messages[150] = 6;

    test_msg.ecdsa_signature_dep_a.signed_messages[151] = 80;

    test_msg.ecdsa_signature_dep_a.signed_messages[152] = 172;

    test_msg.ecdsa_signature_dep_a.signed_messages[153] = 32;

    test_msg.ecdsa_signature_dep_a.signed_messages[154] = 109;

    test_msg.ecdsa_signature_dep_a.signed_messages[155] = 2;

    test_msg.ecdsa_signature_dep_a.signed_messages[156] = 119;

    test_msg.ecdsa_signature_dep_a.signed_messages[157] = 93;

    test_msg.ecdsa_signature_dep_a.signed_messages[158] = 176;

    test_msg.ecdsa_signature_dep_a.signed_messages[159] = 0;

    test_msg.ecdsa_signature_dep_a.signed_messages[160] = 33;

    test_msg.ecdsa_signature_dep_a.signed_messages[161] = 57;

    test_msg.ecdsa_signature_dep_a.signed_messages[162] = 34;

    test_msg.ecdsa_signature_dep_a.signed_messages[163] = 18;

    test_msg.ecdsa_signature_dep_a.signed_messages[164] = 85;

    test_msg.ecdsa_signature_dep_a.signed_messages[165] = 121;

    test_msg.ecdsa_signature_dep_a.signed_messages[166] = 137;

    test_msg.ecdsa_signature_dep_a.signed_messages[167] = 83;

    test_msg.ecdsa_signature_dep_a.signed_messages[168] = 111;

    test_msg.ecdsa_signature_dep_a.signed_messages[169] = 59;

    test_msg.ecdsa_signature_dep_a.signed_messages[170] = 7;

    test_msg.ecdsa_signature_dep_a.signed_messages[171] = 77;

    test_msg.ecdsa_signature_dep_a.signed_messages[172] = 4;

    test_msg.ecdsa_signature_dep_a.signed_messages[173] = 117;

    test_msg.ecdsa_signature_dep_a.signed_messages[174] = 159;

    test_msg.ecdsa_signature_dep_a.signed_messages[175] = 148;

    test_msg.ecdsa_signature_dep_a.signed_messages[176] = 35;

    test_msg.ecdsa_signature_dep_a.signed_messages[177] = 61;

    test_msg.ecdsa_signature_dep_a.signed_messages[178] = 41;

    test_msg.ecdsa_signature_dep_a.signed_messages[179] = 67;

    test_msg.ecdsa_signature_dep_a.signed_messages[180] = 46;

    test_msg.ecdsa_signature_dep_a.signed_messages[181] = 127;

    test_msg.ecdsa_signature_dep_a.signed_messages[182] = 75;

    test_msg.ecdsa_signature_dep_a.signed_messages[183] = 174;

    test_msg.ecdsa_signature_dep_a.stream_counter = 1;

    sbp_message_send(&sbp_state, SbpMsgEcdsaSignatureDepA, 66, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 66,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgEcdsaSignatureDepA, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.certificate_id[0] == 1,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.certificate_id[0], expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.certificate_id[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.certificate_id[1] == 2,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.certificate_id[1], expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.certificate_id[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.certificate_id[2] == 3,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.certificate_id[2], expected 3, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.certificate_id[2]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.certificate_id[3] == 4,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.certificate_id[3], expected 4, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.certificate_id[3]);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.flags == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.flags, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.n_signed_messages == 184,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.n_signed_messages, expected 184, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.n_signed_messages);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.on_demand_counter == 2,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.on_demand_counter, expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.on_demand_counter);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[0] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[0], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[1] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[1], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[2] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[2], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[2]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[3] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[3], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[3]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[4] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[4], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[4]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[5] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[5], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[5]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[6] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[6], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[6]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[7] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[7], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[7]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[8] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[8], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[8]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[9] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[9], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[9]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[10] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[10], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[10]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[11] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[11], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[11]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[12] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[12], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[12]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[13] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[13], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[13]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[14] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[14], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[14]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[15] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[15], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[15]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[16] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[16], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[16]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[17] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[17], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[17]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[18] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[18], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[18]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[19] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[19], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[19]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[20] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[20], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[20]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[21] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[21], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[21]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[22] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[22], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[22]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[23] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[23], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[23]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[24] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[24], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[24]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[25] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[25], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[25]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[26] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[26], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[26]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[27] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[27], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[27]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[28] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[28], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[28]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[29] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[29], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[29]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[30] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[30], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[30]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[31] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[31], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[31]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[32] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[32], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[32]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[33] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[33], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[33]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[34] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[34], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[34]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[35] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[35], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[35]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[36] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[36], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[36]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[37] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[37], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[37]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[38] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[38], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[38]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[39] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[39], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[39]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[40] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[40], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[40]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[41] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[41], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[41]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[42] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[42], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[42]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[43] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[43], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[43]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[44] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[44], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[44]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[45] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[45], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[45]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[46] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[46], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[46]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[47] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[47], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[47]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[48] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[48], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[48]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[49] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[49], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[49]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[50] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[50], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[50]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[51] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[51], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[51]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[52] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[52], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[52]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[53] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[53], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[53]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[54] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[54], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[54]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[55] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[55], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[55]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[56] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[56], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[56]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[57] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[57], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[57]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[58] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[58], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[58]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[59] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[59], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[59]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[60] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[60], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[60]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[61] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[61], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[61]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[62] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[62], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[62]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signature[63] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_a.signature[63], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signature[63]);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[0] == 10,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[0], expected 10, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[1] == 21,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[1], expected 21, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[2] == 23,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[2], expected 23, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[2]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[3] == 63,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[3], expected 63, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[3]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[4] == 140,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[4], expected 140, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[4]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[5] == 37,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[5], expected 37, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[5]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[6] == 130,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[6], expected 130, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[6]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[7] == 106,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[7], expected 106, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[7]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[8] == 28,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[8], expected 28, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[8]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[9] == 40,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[9], expected 40, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[9]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[10] == 165,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[10], expected 165, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[10]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[11] == 179,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[11], expected 179, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[11]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[12] == 73,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[12], expected 73, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[12]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[13] == 178,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[13], expected 178, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[13]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[14] == 60,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[14], expected 60, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[14]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[15] == 126,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[15], expected 126, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[15]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[16] == 114,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[16], expected 114, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[16]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[17] == 78,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[17], expected 78, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[17]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[18] == 113,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[18], expected 113, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[18]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[19] == 27,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[19], expected 27, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[19]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[20] == 95,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[20], expected 95, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[20]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[21] == 3,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[21], expected 3, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[21]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[22] == 62,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[22], expected 62, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[22]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[23] == 104,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[23], expected 104, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[23]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[24] == 145,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[24], expected 145, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[24]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[25] == 96,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[25], expected 96, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[25]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[26] == 19,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[26], expected 19, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[26]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[27] == 92,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[27], expected 92, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[27]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[28] == 123,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[28], expected 123, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[28]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[29] == 14,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[29], expected 14, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[29]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[30] == 90,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[30], expected 90, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[30]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[31] == 153,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[31], expected 153, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[31]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[32] == 183,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[32], expected 183, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[32]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[33] == 9,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[33], expected 9, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[33]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[34] == 72,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[34], expected 72, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[34]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[35] == 81,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[35], expected 81, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[35]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[36] == 118,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[36], expected 118, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[36]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[37] == 112,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[37], expected 112, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[37]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[38] == 124,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[38], expected 124, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[38]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[39] == 16,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[39], expected 16, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[39]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[40] == 182,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[40], expected 182, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[40]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[41] == 76,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[41], expected 76, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[41]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[42] == 146,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[42], expected 146, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[42]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[43] == 115,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[43], expected 115, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[43]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[44] == 58,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[44], expected 58, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[44]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[45] == 144,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[45], expected 144, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[45]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[46] == 17,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[46], expected 17, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[46]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[47] == 105,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[47], expected 105, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[47]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[48] == 66,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[48], expected 66, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[48]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[49] == 31,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[49], expected 31, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[49]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[50] == 135,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[50], expected 135, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[50]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[51] == 54,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[51], expected 54, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[51]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[52] == 100,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[52], expected 100, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[52]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[53] == 84,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[53], expected 84, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[53]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[54] == 181,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[54], expected 181, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[54]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[55] == 103,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[55], expected 103, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[55]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[56] == 11,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[56], expected 11, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[56]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[57] == 88,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[57], expected 88, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[57]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[58] == 133,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[58], expected 133, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[58]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[59] == 155,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[59], expected 155, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[59]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[60] == 167,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[60], expected 167, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[60]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[61] == 173,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[61], expected 173, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[61]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[62] == 143,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[62], expected 143, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[62]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[63] == 86,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[63], expected 86, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[63]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[64] == 158,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[64], expected 158, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[64]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[65] == 20,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[65], expected 20, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[65]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[66] == 168,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[66], expected 168, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[66]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[67] == 132,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[67], expected 132, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[67]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[68] == 141,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[68], expected 141, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[68]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[69] == 102,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[69], expected 102, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[69]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[70] == 50,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[70], expected 50, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[70]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[71] == 48,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[71], expected 48, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[71]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[72] == 71,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[72], expected 71, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[72]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[73] == 147,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[73], expected 147, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[73]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[74] == 53,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[74], expected 53, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[74]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[75] == 87,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[75], expected 87, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[75]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[76] == 1,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[76], expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[76]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[77] == 108,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[77], expected 108, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[77]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[78] == 138,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[78], expected 138, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[78]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[79] == 36,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[79], expected 36, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[79]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[80] == 134,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[80], expected 134, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[80]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[81] == 139,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[81], expected 139, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[81]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[82] == 163,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[82], expected 163, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[82]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[83] == 82,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[83], expected 82, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[83]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[84] == 43,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[84], expected 43, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[84]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[85] == 52,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[85], expected 52, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[85]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[86] == 150,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[86], expected 150, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[86]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[87] == 12,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[87], expected 12, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[87]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[88] == 30,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[88], expected 30, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[88]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[89] == 110,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[89], expected 110, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[89]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[90] == 156,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[90], expected 156, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[90]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[91] == 107,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[91], expected 107, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[91]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[92] == 120,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[92], expected 120, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[92]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[93] == 91,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[93], expected 91, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[93]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[94] == 122,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[94], expected 122, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[94]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[95] == 69,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[95], expected 69, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[95]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[96] == 164,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[96], expected 164, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[96]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[97] == 170,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[97], expected 170, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[97]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[98] == 116,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[98], expected 116, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[98]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[99] == 25,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[99], expected 25, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[99]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[100] == 94,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[100], expected 94, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[100]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[101] == 5,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[101], expected 5, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[101]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[102] == 22,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[102], expected 22, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[102]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[103] == 24,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[103], expected 24, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[103]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[104] == 162,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[104], expected "
        "162, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[104]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[105] == 175,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[105], expected "
        "175, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[105]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[106] == 38,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[106], expected 38, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[106]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[107] == 157,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[107], expected "
        "157, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[107]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[108] == 98,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[108], expected 98, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[108]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[109] == 44,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[109], expected 44, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[109]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[110] == 160,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[110], expected "
        "160, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[110]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[111] == 47,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[111], expected 47, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[111]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[112] == 97,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[112], expected 97, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[112]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[113] == 142,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[113], expected "
        "142, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[113]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[114] == 8,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[114], expected 8, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[114]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[115] == 74,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[115], expected 74, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[115]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[116] == 13,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[116], expected 13, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[116]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[117] == 177,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[117], expected "
        "177, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[117]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[118] == 15,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[118], expected 15, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[118]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[119] == 128,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[119], expected "
        "128, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[119]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[120] == 26,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[120], expected 26, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[120]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[121] == 131,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[121], expected "
        "131, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[121]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[122] == 154,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[122], expected "
        "154, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[122]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[123] == 65,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[123], expected 65, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[123]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[124] == 169,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[124], expected "
        "169, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[124]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[125] == 55,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[125], expected 55, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[125]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[126] == 136,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[126], expected "
        "136, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[126]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[127] == 125,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[127], expected "
        "125, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[127]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[128] == 171,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[128], expected "
        "171, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[128]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[129] == 161,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[129], expected "
        "161, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[129]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[130] == 29,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[130], expected 29, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[130]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[131] == 129,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[131], expected "
        "129, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[131]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[132] == 151,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[132], expected "
        "151, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[132]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[133] == 68,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[133], expected 68, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[133]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[134] == 166,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[134], expected "
        "166, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[134]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[135] == 51,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[135], expected 51, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[135]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[136] == 70,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[136], expected 70, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[136]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[137] == 45,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[137], expected 45, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[137]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[138] == 56,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[138], expected 56, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[138]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[139] == 79,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[139], expected 79, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[139]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[140] == 149,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[140], expected "
        "149, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[140]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[141] == 99,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[141], expected 99, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[141]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[142] == 42,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[142], expected 42, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[142]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[143] == 101,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[143], expected "
        "101, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[143]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[144] == 152,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[144], expected "
        "152, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[144]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[145] == 39,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[145], expected 39, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[145]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[146] == 89,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[146], expected 89, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[146]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[147] == 180,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[147], expected "
        "180, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[147]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[148] == 64,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[148], expected 64, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[148]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[149] == 49,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[149], expected 49, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[149]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[150] == 6,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[150], expected 6, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[150]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[151] == 80,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[151], expected 80, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[151]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[152] == 172,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[152], expected "
        "172, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[152]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[153] == 32,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[153], expected 32, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[153]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[154] == 109,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[154], expected "
        "109, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[154]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[155] == 2,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[155], expected 2, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[155]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[156] == 119,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[156], expected "
        "119, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[156]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[157] == 93,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[157], expected 93, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[157]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[158] == 176,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[158], expected "
        "176, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[158]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[159] == 0,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[159], expected 0, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[159]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[160] == 33,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[160], expected 33, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[160]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[161] == 57,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[161], expected 57, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[161]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[162] == 34,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[162], expected 34, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[162]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[163] == 18,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[163], expected 18, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[163]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[164] == 85,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[164], expected 85, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[164]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[165] == 121,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[165], expected "
        "121, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[165]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[166] == 137,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[166], expected "
        "137, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[166]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[167] == 83,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[167], expected 83, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[167]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[168] == 111,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[168], expected "
        "111, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[168]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[169] == 59,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[169], expected 59, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[169]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[170] == 7,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[170], expected 7, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[170]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[171] == 77,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[171], expected 77, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[171]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[172] == 4,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[172], expected 4, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[172]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[173] == 117,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[173], expected "
        "117, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[173]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[174] == 159,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[174], expected "
        "159, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[174]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[175] == 148,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[175], expected "
        "148, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[175]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[176] == 35,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[176], expected 35, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[176]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[177] == 61,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[177], expected 61, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[177]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[178] == 41,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[178], expected 41, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[178]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[179] == 67,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[179], expected 67, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[179]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[180] == 46,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[180], expected 46, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[180]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[181] == 127,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[181], expected "
        "127, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[181]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[182] == 75,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[182], expected 75, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[182]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_a.signed_messages[183] == 174,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_a.signed_messages[183], expected "
        "174, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature_dep_a.signed_messages[183]);

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_a.stream_counter == 1,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_a.stream_counter, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.ecdsa_signature_dep_a.stream_counter);
  }
}
END_TEST

Suite *auto_check_sbp_signing_MsgEcdsaSignatureDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_signing_MsgEcdsaSignatureDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_signing_MsgEcdsaSignatureDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_signing_MsgEcdsaSignatureDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}