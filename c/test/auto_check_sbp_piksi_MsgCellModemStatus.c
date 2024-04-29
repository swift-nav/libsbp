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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/piksi.h>
#include <libsbp/sbp.h>
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

START_TEST(test_auto_check_sbp_piksi_MsgCellModemStatus) {
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

    sbp_callback_register(&sbp_state, 0xbe, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  190, 0,   19,  27,  255, 103, 205, 48,  6,   70,  123, 242, 46,
        52,  64,  176, 154, 98,  43,  132, 196, 89,  253, 161, 250, 174, 204,
        110, 47,  38,  187, 63,  102, 177, 162, 49,  80,  194, 37,  107, 60,
        225, 52,  101, 178, 142, 246, 21,  17,  93,  75,  169, 86,  16,  209,
        80,  243, 30,  206, 220, 206, 115, 47,  154, 91,  227, 88,  11,  1,
        85,  146, 100, 190, 232, 207, 61,  61,  201, 220, 31,  78,  34,  57,
        82,  59,  104, 65,  221, 0,   43,  210, 9,   32,  122, 29,  237, 11,
        151, 223, 18,  81,  204, 172, 234, 127, 3,   82,  133, 169, 12,  176,
        193, 0,   24,  121, 85,  55,  214, 198, 75,  234, 179, 214, 85,  94,
        115, 21,  73,  121, 75,  46,  158, 63,  100, 122, 213, 20,  85,  212,
        131, 50,  224, 218, 215, 215, 149, 2,   19,  129, 39,  164, 5,   175,
        6,   62,  51,  78,  66,  248, 116, 88,  90,  128, 226, 177, 0,   47,
        140, 33,  126, 221, 110, 144, 97,  74,  250, 181, 199, 27,  176, 65,
        185, 110, 92,  34,  44,  131, 96,  178, 40,  176, 4,   90,  36,  7,
        180, 244, 244, 23,  108, 171, 204, 196, 61,  51,  179, 242, 156, 81,
        83,  16,  15,  134, 40,  245, 253, 150, 94,  150, 144, 197, 113, 5,
        141, 232, 33,  101, 231, 38,  75,  178, 243, 119, 1,   248, 218, 86,
        7,   88,  197, 148, 240, 227, 2,   65,  173, 122, 143, 251, 156, 217,
        67,  239, 219, 31,  224, 176, 129, 81,  80,  40,  230,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.cell_modem_status.n_reserved = 250;

    test_msg.cell_modem_status.reserved[0] = 123;

    test_msg.cell_modem_status.reserved[1] = 242;

    test_msg.cell_modem_status.reserved[2] = 46;

    test_msg.cell_modem_status.reserved[3] = 52;

    test_msg.cell_modem_status.reserved[4] = 64;

    test_msg.cell_modem_status.reserved[5] = 176;

    test_msg.cell_modem_status.reserved[6] = 154;

    test_msg.cell_modem_status.reserved[7] = 98;

    test_msg.cell_modem_status.reserved[8] = 43;

    test_msg.cell_modem_status.reserved[9] = 132;

    test_msg.cell_modem_status.reserved[10] = 196;

    test_msg.cell_modem_status.reserved[11] = 89;

    test_msg.cell_modem_status.reserved[12] = 253;

    test_msg.cell_modem_status.reserved[13] = 161;

    test_msg.cell_modem_status.reserved[14] = 250;

    test_msg.cell_modem_status.reserved[15] = 174;

    test_msg.cell_modem_status.reserved[16] = 204;

    test_msg.cell_modem_status.reserved[17] = 110;

    test_msg.cell_modem_status.reserved[18] = 47;

    test_msg.cell_modem_status.reserved[19] = 38;

    test_msg.cell_modem_status.reserved[20] = 187;

    test_msg.cell_modem_status.reserved[21] = 63;

    test_msg.cell_modem_status.reserved[22] = 102;

    test_msg.cell_modem_status.reserved[23] = 177;

    test_msg.cell_modem_status.reserved[24] = 162;

    test_msg.cell_modem_status.reserved[25] = 49;

    test_msg.cell_modem_status.reserved[26] = 80;

    test_msg.cell_modem_status.reserved[27] = 194;

    test_msg.cell_modem_status.reserved[28] = 37;

    test_msg.cell_modem_status.reserved[29] = 107;

    test_msg.cell_modem_status.reserved[30] = 60;

    test_msg.cell_modem_status.reserved[31] = 225;

    test_msg.cell_modem_status.reserved[32] = 52;

    test_msg.cell_modem_status.reserved[33] = 101;

    test_msg.cell_modem_status.reserved[34] = 178;

    test_msg.cell_modem_status.reserved[35] = 142;

    test_msg.cell_modem_status.reserved[36] = 246;

    test_msg.cell_modem_status.reserved[37] = 21;

    test_msg.cell_modem_status.reserved[38] = 17;

    test_msg.cell_modem_status.reserved[39] = 93;

    test_msg.cell_modem_status.reserved[40] = 75;

    test_msg.cell_modem_status.reserved[41] = 169;

    test_msg.cell_modem_status.reserved[42] = 86;

    test_msg.cell_modem_status.reserved[43] = 16;

    test_msg.cell_modem_status.reserved[44] = 209;

    test_msg.cell_modem_status.reserved[45] = 80;

    test_msg.cell_modem_status.reserved[46] = 243;

    test_msg.cell_modem_status.reserved[47] = 30;

    test_msg.cell_modem_status.reserved[48] = 206;

    test_msg.cell_modem_status.reserved[49] = 220;

    test_msg.cell_modem_status.reserved[50] = 206;

    test_msg.cell_modem_status.reserved[51] = 115;

    test_msg.cell_modem_status.reserved[52] = 47;

    test_msg.cell_modem_status.reserved[53] = 154;

    test_msg.cell_modem_status.reserved[54] = 91;

    test_msg.cell_modem_status.reserved[55] = 227;

    test_msg.cell_modem_status.reserved[56] = 88;

    test_msg.cell_modem_status.reserved[57] = 11;

    test_msg.cell_modem_status.reserved[58] = 1;

    test_msg.cell_modem_status.reserved[59] = 85;

    test_msg.cell_modem_status.reserved[60] = 146;

    test_msg.cell_modem_status.reserved[61] = 100;

    test_msg.cell_modem_status.reserved[62] = 190;

    test_msg.cell_modem_status.reserved[63] = 232;

    test_msg.cell_modem_status.reserved[64] = 207;

    test_msg.cell_modem_status.reserved[65] = 61;

    test_msg.cell_modem_status.reserved[66] = 61;

    test_msg.cell_modem_status.reserved[67] = 201;

    test_msg.cell_modem_status.reserved[68] = 220;

    test_msg.cell_modem_status.reserved[69] = 31;

    test_msg.cell_modem_status.reserved[70] = 78;

    test_msg.cell_modem_status.reserved[71] = 34;

    test_msg.cell_modem_status.reserved[72] = 57;

    test_msg.cell_modem_status.reserved[73] = 82;

    test_msg.cell_modem_status.reserved[74] = 59;

    test_msg.cell_modem_status.reserved[75] = 104;

    test_msg.cell_modem_status.reserved[76] = 65;

    test_msg.cell_modem_status.reserved[77] = 221;

    test_msg.cell_modem_status.reserved[78] = 0;

    test_msg.cell_modem_status.reserved[79] = 43;

    test_msg.cell_modem_status.reserved[80] = 210;

    test_msg.cell_modem_status.reserved[81] = 9;

    test_msg.cell_modem_status.reserved[82] = 32;

    test_msg.cell_modem_status.reserved[83] = 122;

    test_msg.cell_modem_status.reserved[84] = 29;

    test_msg.cell_modem_status.reserved[85] = 237;

    test_msg.cell_modem_status.reserved[86] = 11;

    test_msg.cell_modem_status.reserved[87] = 151;

    test_msg.cell_modem_status.reserved[88] = 223;

    test_msg.cell_modem_status.reserved[89] = 18;

    test_msg.cell_modem_status.reserved[90] = 81;

    test_msg.cell_modem_status.reserved[91] = 204;

    test_msg.cell_modem_status.reserved[92] = 172;

    test_msg.cell_modem_status.reserved[93] = 234;

    test_msg.cell_modem_status.reserved[94] = 127;

    test_msg.cell_modem_status.reserved[95] = 3;

    test_msg.cell_modem_status.reserved[96] = 82;

    test_msg.cell_modem_status.reserved[97] = 133;

    test_msg.cell_modem_status.reserved[98] = 169;

    test_msg.cell_modem_status.reserved[99] = 12;

    test_msg.cell_modem_status.reserved[100] = 176;

    test_msg.cell_modem_status.reserved[101] = 193;

    test_msg.cell_modem_status.reserved[102] = 0;

    test_msg.cell_modem_status.reserved[103] = 24;

    test_msg.cell_modem_status.reserved[104] = 121;

    test_msg.cell_modem_status.reserved[105] = 85;

    test_msg.cell_modem_status.reserved[106] = 55;

    test_msg.cell_modem_status.reserved[107] = 214;

    test_msg.cell_modem_status.reserved[108] = 198;

    test_msg.cell_modem_status.reserved[109] = 75;

    test_msg.cell_modem_status.reserved[110] = 234;

    test_msg.cell_modem_status.reserved[111] = 179;

    test_msg.cell_modem_status.reserved[112] = 214;

    test_msg.cell_modem_status.reserved[113] = 85;

    test_msg.cell_modem_status.reserved[114] = 94;

    test_msg.cell_modem_status.reserved[115] = 115;

    test_msg.cell_modem_status.reserved[116] = 21;

    test_msg.cell_modem_status.reserved[117] = 73;

    test_msg.cell_modem_status.reserved[118] = 121;

    test_msg.cell_modem_status.reserved[119] = 75;

    test_msg.cell_modem_status.reserved[120] = 46;

    test_msg.cell_modem_status.reserved[121] = 158;

    test_msg.cell_modem_status.reserved[122] = 63;

    test_msg.cell_modem_status.reserved[123] = 100;

    test_msg.cell_modem_status.reserved[124] = 122;

    test_msg.cell_modem_status.reserved[125] = 213;

    test_msg.cell_modem_status.reserved[126] = 20;

    test_msg.cell_modem_status.reserved[127] = 85;

    test_msg.cell_modem_status.reserved[128] = 212;

    test_msg.cell_modem_status.reserved[129] = 131;

    test_msg.cell_modem_status.reserved[130] = 50;

    test_msg.cell_modem_status.reserved[131] = 224;

    test_msg.cell_modem_status.reserved[132] = 218;

    test_msg.cell_modem_status.reserved[133] = 215;

    test_msg.cell_modem_status.reserved[134] = 215;

    test_msg.cell_modem_status.reserved[135] = 149;

    test_msg.cell_modem_status.reserved[136] = 2;

    test_msg.cell_modem_status.reserved[137] = 19;

    test_msg.cell_modem_status.reserved[138] = 129;

    test_msg.cell_modem_status.reserved[139] = 39;

    test_msg.cell_modem_status.reserved[140] = 164;

    test_msg.cell_modem_status.reserved[141] = 5;

    test_msg.cell_modem_status.reserved[142] = 175;

    test_msg.cell_modem_status.reserved[143] = 6;

    test_msg.cell_modem_status.reserved[144] = 62;

    test_msg.cell_modem_status.reserved[145] = 51;

    test_msg.cell_modem_status.reserved[146] = 78;

    test_msg.cell_modem_status.reserved[147] = 66;

    test_msg.cell_modem_status.reserved[148] = 248;

    test_msg.cell_modem_status.reserved[149] = 116;

    test_msg.cell_modem_status.reserved[150] = 88;

    test_msg.cell_modem_status.reserved[151] = 90;

    test_msg.cell_modem_status.reserved[152] = 128;

    test_msg.cell_modem_status.reserved[153] = 226;

    test_msg.cell_modem_status.reserved[154] = 177;

    test_msg.cell_modem_status.reserved[155] = 0;

    test_msg.cell_modem_status.reserved[156] = 47;

    test_msg.cell_modem_status.reserved[157] = 140;

    test_msg.cell_modem_status.reserved[158] = 33;

    test_msg.cell_modem_status.reserved[159] = 126;

    test_msg.cell_modem_status.reserved[160] = 221;

    test_msg.cell_modem_status.reserved[161] = 110;

    test_msg.cell_modem_status.reserved[162] = 144;

    test_msg.cell_modem_status.reserved[163] = 97;

    test_msg.cell_modem_status.reserved[164] = 74;

    test_msg.cell_modem_status.reserved[165] = 250;

    test_msg.cell_modem_status.reserved[166] = 181;

    test_msg.cell_modem_status.reserved[167] = 199;

    test_msg.cell_modem_status.reserved[168] = 27;

    test_msg.cell_modem_status.reserved[169] = 176;

    test_msg.cell_modem_status.reserved[170] = 65;

    test_msg.cell_modem_status.reserved[171] = 185;

    test_msg.cell_modem_status.reserved[172] = 110;

    test_msg.cell_modem_status.reserved[173] = 92;

    test_msg.cell_modem_status.reserved[174] = 34;

    test_msg.cell_modem_status.reserved[175] = 44;

    test_msg.cell_modem_status.reserved[176] = 131;

    test_msg.cell_modem_status.reserved[177] = 96;

    test_msg.cell_modem_status.reserved[178] = 178;

    test_msg.cell_modem_status.reserved[179] = 40;

    test_msg.cell_modem_status.reserved[180] = 176;

    test_msg.cell_modem_status.reserved[181] = 4;

    test_msg.cell_modem_status.reserved[182] = 90;

    test_msg.cell_modem_status.reserved[183] = 36;

    test_msg.cell_modem_status.reserved[184] = 7;

    test_msg.cell_modem_status.reserved[185] = 180;

    test_msg.cell_modem_status.reserved[186] = 244;

    test_msg.cell_modem_status.reserved[187] = 244;

    test_msg.cell_modem_status.reserved[188] = 23;

    test_msg.cell_modem_status.reserved[189] = 108;

    test_msg.cell_modem_status.reserved[190] = 171;

    test_msg.cell_modem_status.reserved[191] = 204;

    test_msg.cell_modem_status.reserved[192] = 196;

    test_msg.cell_modem_status.reserved[193] = 61;

    test_msg.cell_modem_status.reserved[194] = 51;

    test_msg.cell_modem_status.reserved[195] = 179;

    test_msg.cell_modem_status.reserved[196] = 242;

    test_msg.cell_modem_status.reserved[197] = 156;

    test_msg.cell_modem_status.reserved[198] = 81;

    test_msg.cell_modem_status.reserved[199] = 83;

    test_msg.cell_modem_status.reserved[200] = 16;

    test_msg.cell_modem_status.reserved[201] = 15;

    test_msg.cell_modem_status.reserved[202] = 134;

    test_msg.cell_modem_status.reserved[203] = 40;

    test_msg.cell_modem_status.reserved[204] = 245;

    test_msg.cell_modem_status.reserved[205] = 253;

    test_msg.cell_modem_status.reserved[206] = 150;

    test_msg.cell_modem_status.reserved[207] = 94;

    test_msg.cell_modem_status.reserved[208] = 150;

    test_msg.cell_modem_status.reserved[209] = 144;

    test_msg.cell_modem_status.reserved[210] = 197;

    test_msg.cell_modem_status.reserved[211] = 113;

    test_msg.cell_modem_status.reserved[212] = 5;

    test_msg.cell_modem_status.reserved[213] = 141;

    test_msg.cell_modem_status.reserved[214] = 232;

    test_msg.cell_modem_status.reserved[215] = 33;

    test_msg.cell_modem_status.reserved[216] = 101;

    test_msg.cell_modem_status.reserved[217] = 231;

    test_msg.cell_modem_status.reserved[218] = 38;

    test_msg.cell_modem_status.reserved[219] = 75;

    test_msg.cell_modem_status.reserved[220] = 178;

    test_msg.cell_modem_status.reserved[221] = 243;

    test_msg.cell_modem_status.reserved[222] = 119;

    test_msg.cell_modem_status.reserved[223] = 1;

    test_msg.cell_modem_status.reserved[224] = 248;

    test_msg.cell_modem_status.reserved[225] = 218;

    test_msg.cell_modem_status.reserved[226] = 86;

    test_msg.cell_modem_status.reserved[227] = 7;

    test_msg.cell_modem_status.reserved[228] = 88;

    test_msg.cell_modem_status.reserved[229] = 197;

    test_msg.cell_modem_status.reserved[230] = 148;

    test_msg.cell_modem_status.reserved[231] = 240;

    test_msg.cell_modem_status.reserved[232] = 227;

    test_msg.cell_modem_status.reserved[233] = 2;

    test_msg.cell_modem_status.reserved[234] = 65;

    test_msg.cell_modem_status.reserved[235] = 173;

    test_msg.cell_modem_status.reserved[236] = 122;

    test_msg.cell_modem_status.reserved[237] = 143;

    test_msg.cell_modem_status.reserved[238] = 251;

    test_msg.cell_modem_status.reserved[239] = 156;

    test_msg.cell_modem_status.reserved[240] = 217;

    test_msg.cell_modem_status.reserved[241] = 67;

    test_msg.cell_modem_status.reserved[242] = 239;

    test_msg.cell_modem_status.reserved[243] = 219;

    test_msg.cell_modem_status.reserved[244] = 31;

    test_msg.cell_modem_status.reserved[245] = 224;

    test_msg.cell_modem_status.reserved[246] = 176;

    test_msg.cell_modem_status.reserved[247] = 129;

    test_msg.cell_modem_status.reserved[248] = 81;

    test_msg.cell_modem_status.reserved[249] = 80;

    test_msg.cell_modem_status.signal_error_rate = 8588.2001953125;

    test_msg.cell_modem_status.signal_strength = 103;

    sbp_message_send(&sbp_state, SbpMsgCellModemStatus, 6931, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 6931,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgCellModemStatus, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.cell_modem_status.n_reserved == 250,
        "incorrect value for last_msg.msg.cell_modem_status.n_reserved, "
        "expected 250, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.n_reserved);

    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[0] == 123,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[0], "
        "expected 123, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[0]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[1] == 242,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[1], "
        "expected 242, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[1]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[2] == 46,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[2], "
        "expected 46, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[2]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[3] == 52,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[3], "
        "expected 52, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[3]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[4] == 64,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[4], "
        "expected 64, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[4]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[5] == 176,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[5], "
        "expected 176, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[5]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[6] == 154,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[6], "
        "expected 154, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[6]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[7] == 98,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[7], "
        "expected 98, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[7]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[8] == 43,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[8], "
        "expected 43, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[8]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[9] == 132,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[9], "
        "expected 132, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[9]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[10] == 196,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[10], "
        "expected 196, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[10]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[11] == 89,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[11], "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[11]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[12] == 253,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[12], "
        "expected 253, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[12]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[13] == 161,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[13], "
        "expected 161, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[13]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[14] == 250,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[14], "
        "expected 250, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[14]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[15] == 174,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[15], "
        "expected 174, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[15]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[16] == 204,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[16], "
        "expected 204, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[16]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[17] == 110,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[17], "
        "expected 110, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[17]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[18] == 47,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[18], "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[18]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[19] == 38,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[19], "
        "expected 38, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[19]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[20] == 187,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[20], "
        "expected 187, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[20]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[21] == 63,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[21], "
        "expected 63, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[21]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[22] == 102,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[22], "
        "expected 102, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[22]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[23] == 177,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[23], "
        "expected 177, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[23]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[24] == 162,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[24], "
        "expected 162, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[24]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[25] == 49,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[25], "
        "expected 49, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[25]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[26] == 80,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[26], "
        "expected 80, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[26]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[27] == 194,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[27], "
        "expected 194, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[27]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[28] == 37,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[28], "
        "expected 37, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[28]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[29] == 107,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[29], "
        "expected 107, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[29]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[30] == 60,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[30], "
        "expected 60, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[30]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[31] == 225,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[31], "
        "expected 225, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[31]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[32] == 52,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[32], "
        "expected 52, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[32]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[33] == 101,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[33], "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[33]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[34] == 178,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[34], "
        "expected 178, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[34]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[35] == 142,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[35], "
        "expected 142, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[35]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[36] == 246,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[36], "
        "expected 246, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[36]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[37] == 21,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[37], "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[37]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[38] == 17,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[38], "
        "expected 17, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[38]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[39] == 93,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[39], "
        "expected 93, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[39]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[40] == 75,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[40], "
        "expected 75, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[40]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[41] == 169,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[41], "
        "expected 169, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[41]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[42] == 86,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[42], "
        "expected 86, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[42]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[43] == 16,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[43], "
        "expected 16, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[43]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[44] == 209,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[44], "
        "expected 209, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[44]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[45] == 80,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[45], "
        "expected 80, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[45]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[46] == 243,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[46], "
        "expected 243, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[46]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[47] == 30,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[47], "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[47]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[48] == 206,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[48], "
        "expected 206, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[48]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[49] == 220,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[49], "
        "expected 220, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[49]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[50] == 206,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[50], "
        "expected 206, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[50]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[51] == 115,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[51], "
        "expected 115, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[51]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[52] == 47,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[52], "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[52]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[53] == 154,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[53], "
        "expected 154, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[53]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[54] == 91,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[54], "
        "expected 91, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[54]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[55] == 227,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[55], "
        "expected 227, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[55]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[56] == 88,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[56], "
        "expected 88, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[56]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[57] == 11,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[57], "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[57]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[58] == 1,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[58], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[58]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[59] == 85,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[59], "
        "expected 85, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[59]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[60] == 146,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[60], "
        "expected 146, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[60]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[61] == 100,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[61], "
        "expected 100, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[61]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[62] == 190,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[62], "
        "expected 190, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[62]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[63] == 232,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[63], "
        "expected 232, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[63]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[64] == 207,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[64], "
        "expected 207, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[64]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[65] == 61,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[65], "
        "expected 61, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[65]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[66] == 61,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[66], "
        "expected 61, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[66]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[67] == 201,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[67], "
        "expected 201, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[67]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[68] == 220,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[68], "
        "expected 220, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[68]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[69] == 31,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[69], "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[69]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[70] == 78,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[70], "
        "expected 78, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[70]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[71] == 34,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[71], "
        "expected 34, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[71]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[72] == 57,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[72], "
        "expected 57, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[72]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[73] == 82,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[73], "
        "expected 82, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[73]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[74] == 59,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[74], "
        "expected 59, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[74]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[75] == 104,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[75], "
        "expected 104, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[75]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[76] == 65,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[76], "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[76]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[77] == 221,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[77], "
        "expected 221, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[77]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[78] == 0,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[78], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[78]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[79] == 43,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[79], "
        "expected 43, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[79]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[80] == 210,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[80], "
        "expected 210, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[80]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[81] == 9,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[81], "
        "expected 9, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[81]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[82] == 32,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[82], "
        "expected 32, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[82]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[83] == 122,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[83], "
        "expected 122, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[83]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[84] == 29,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[84], "
        "expected 29, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[84]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[85] == 237,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[85], "
        "expected 237, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[85]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[86] == 11,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[86], "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[86]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[87] == 151,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[87], "
        "expected 151, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[87]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[88] == 223,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[88], "
        "expected 223, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[88]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[89] == 18,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[89], "
        "expected 18, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[89]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[90] == 81,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[90], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[90]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[91] == 204,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[91], "
        "expected 204, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[91]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[92] == 172,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[92], "
        "expected 172, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[92]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[93] == 234,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[93], "
        "expected 234, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[93]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[94] == 127,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[94], "
        "expected 127, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[94]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[95] == 3,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[95], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[95]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[96] == 82,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[96], "
        "expected 82, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[96]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[97] == 133,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[97], "
        "expected 133, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[97]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[98] == 169,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[98], "
        "expected 169, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[98]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[99] == 12,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[99], "
        "expected 12, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[99]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[100] == 176,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[100], "
        "expected 176, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[100]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[101] == 193,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[101], "
        "expected 193, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[101]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[102] == 0,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[102], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[102]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[103] == 24,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[103], "
        "expected 24, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[103]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[104] == 121,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[104], "
        "expected 121, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[104]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[105] == 85,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[105], "
        "expected 85, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[105]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[106] == 55,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[106], "
        "expected 55, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[106]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[107] == 214,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[107], "
        "expected 214, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[107]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[108] == 198,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[108], "
        "expected 198, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[108]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[109] == 75,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[109], "
        "expected 75, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[109]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[110] == 234,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[110], "
        "expected 234, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[110]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[111] == 179,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[111], "
        "expected 179, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[111]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[112] == 214,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[112], "
        "expected 214, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[112]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[113] == 85,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[113], "
        "expected 85, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[113]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[114] == 94,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[114], "
        "expected 94, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[114]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[115] == 115,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[115], "
        "expected 115, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[115]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[116] == 21,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[116], "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[116]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[117] == 73,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[117], "
        "expected 73, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[117]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[118] == 121,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[118], "
        "expected 121, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[118]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[119] == 75,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[119], "
        "expected 75, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[119]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[120] == 46,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[120], "
        "expected 46, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[120]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[121] == 158,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[121], "
        "expected 158, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[121]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[122] == 63,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[122], "
        "expected 63, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[122]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[123] == 100,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[123], "
        "expected 100, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[123]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[124] == 122,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[124], "
        "expected 122, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[124]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[125] == 213,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[125], "
        "expected 213, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[125]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[126] == 20,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[126], "
        "expected 20, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[126]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[127] == 85,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[127], "
        "expected 85, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[127]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[128] == 212,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[128], "
        "expected 212, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[128]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[129] == 131,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[129], "
        "expected 131, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[129]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[130] == 50,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[130], "
        "expected 50, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[130]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[131] == 224,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[131], "
        "expected 224, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[131]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[132] == 218,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[132], "
        "expected 218, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[132]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[133] == 215,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[133], "
        "expected 215, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[133]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[134] == 215,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[134], "
        "expected 215, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[134]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[135] == 149,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[135], "
        "expected 149, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[135]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[136] == 2,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[136], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[136]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[137] == 19,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[137], "
        "expected 19, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[137]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[138] == 129,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[138], "
        "expected 129, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[138]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[139] == 39,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[139], "
        "expected 39, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[139]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[140] == 164,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[140], "
        "expected 164, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[140]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[141] == 5,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[141], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[141]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[142] == 175,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[142], "
        "expected 175, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[142]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[143] == 6,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[143], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[143]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[144] == 62,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[144], "
        "expected 62, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[144]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[145] == 51,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[145], "
        "expected 51, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[145]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[146] == 78,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[146], "
        "expected 78, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[146]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[147] == 66,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[147], "
        "expected 66, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[147]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[148] == 248,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[148], "
        "expected 248, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[148]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[149] == 116,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[149], "
        "expected 116, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[149]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[150] == 88,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[150], "
        "expected 88, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[150]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[151] == 90,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[151], "
        "expected 90, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[151]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[152] == 128,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[152], "
        "expected 128, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[152]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[153] == 226,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[153], "
        "expected 226, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[153]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[154] == 177,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[154], "
        "expected 177, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[154]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[155] == 0,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[155], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[155]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[156] == 47,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[156], "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[156]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[157] == 140,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[157], "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[157]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[158] == 33,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[158], "
        "expected 33, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[158]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[159] == 126,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[159], "
        "expected 126, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[159]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[160] == 221,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[160], "
        "expected 221, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[160]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[161] == 110,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[161], "
        "expected 110, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[161]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[162] == 144,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[162], "
        "expected 144, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[162]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[163] == 97,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[163], "
        "expected 97, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[163]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[164] == 74,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[164], "
        "expected 74, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[164]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[165] == 250,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[165], "
        "expected 250, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[165]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[166] == 181,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[166], "
        "expected 181, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[166]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[167] == 199,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[167], "
        "expected 199, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[167]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[168] == 27,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[168], "
        "expected 27, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[168]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[169] == 176,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[169], "
        "expected 176, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[169]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[170] == 65,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[170], "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[170]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[171] == 185,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[171], "
        "expected 185, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[171]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[172] == 110,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[172], "
        "expected 110, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[172]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[173] == 92,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[173], "
        "expected 92, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[173]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[174] == 34,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[174], "
        "expected 34, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[174]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[175] == 44,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[175], "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[175]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[176] == 131,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[176], "
        "expected 131, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[176]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[177] == 96,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[177], "
        "expected 96, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[177]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[178] == 178,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[178], "
        "expected 178, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[178]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[179] == 40,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[179], "
        "expected 40, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[179]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[180] == 176,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[180], "
        "expected 176, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[180]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[181] == 4,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[181], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[181]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[182] == 90,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[182], "
        "expected 90, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[182]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[183] == 36,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[183], "
        "expected 36, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[183]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[184] == 7,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[184], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[184]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[185] == 180,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[185], "
        "expected 180, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[185]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[186] == 244,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[186], "
        "expected 244, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[186]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[187] == 244,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[187], "
        "expected 244, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[187]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[188] == 23,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[188], "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[188]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[189] == 108,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[189], "
        "expected 108, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[189]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[190] == 171,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[190], "
        "expected 171, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[190]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[191] == 204,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[191], "
        "expected 204, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[191]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[192] == 196,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[192], "
        "expected 196, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[192]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[193] == 61,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[193], "
        "expected 61, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[193]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[194] == 51,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[194], "
        "expected 51, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[194]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[195] == 179,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[195], "
        "expected 179, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[195]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[196] == 242,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[196], "
        "expected 242, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[196]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[197] == 156,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[197], "
        "expected 156, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[197]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[198] == 81,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[198], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[198]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[199] == 83,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[199], "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[199]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[200] == 16,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[200], "
        "expected 16, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[200]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[201] == 15,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[201], "
        "expected 15, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[201]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[202] == 134,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[202], "
        "expected 134, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[202]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[203] == 40,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[203], "
        "expected 40, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[203]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[204] == 245,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[204], "
        "expected 245, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[204]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[205] == 253,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[205], "
        "expected 253, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[205]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[206] == 150,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[206], "
        "expected 150, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[206]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[207] == 94,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[207], "
        "expected 94, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[207]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[208] == 150,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[208], "
        "expected 150, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[208]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[209] == 144,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[209], "
        "expected 144, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[209]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[210] == 197,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[210], "
        "expected 197, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[210]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[211] == 113,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[211], "
        "expected 113, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[211]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[212] == 5,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[212], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[212]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[213] == 141,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[213], "
        "expected 141, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[213]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[214] == 232,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[214], "
        "expected 232, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[214]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[215] == 33,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[215], "
        "expected 33, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[215]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[216] == 101,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[216], "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[216]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[217] == 231,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[217], "
        "expected 231, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[217]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[218] == 38,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[218], "
        "expected 38, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[218]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[219] == 75,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[219], "
        "expected 75, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[219]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[220] == 178,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[220], "
        "expected 178, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[220]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[221] == 243,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[221], "
        "expected 243, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[221]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[222] == 119,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[222], "
        "expected 119, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[222]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[223] == 1,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[223], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[223]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[224] == 248,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[224], "
        "expected 248, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[224]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[225] == 218,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[225], "
        "expected 218, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[225]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[226] == 86,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[226], "
        "expected 86, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[226]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[227] == 7,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[227], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[227]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[228] == 88,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[228], "
        "expected 88, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[228]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[229] == 197,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[229], "
        "expected 197, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[229]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[230] == 148,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[230], "
        "expected 148, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[230]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[231] == 240,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[231], "
        "expected 240, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[231]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[232] == 227,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[232], "
        "expected 227, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[232]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[233] == 2,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[233], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[233]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[234] == 65,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[234], "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[234]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[235] == 173,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[235], "
        "expected 173, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[235]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[236] == 122,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[236], "
        "expected 122, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[236]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[237] == 143,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[237], "
        "expected 143, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[237]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[238] == 251,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[238], "
        "expected 251, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[238]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[239] == 156,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[239], "
        "expected 156, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[239]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[240] == 217,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[240], "
        "expected 217, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[240]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[241] == 67,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[241], "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[241]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[242] == 239,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[242], "
        "expected 239, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[242]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[243] == 219,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[243], "
        "expected 219, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[243]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[244] == 31,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[244], "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[244]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[245] == 224,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[245], "
        "expected 224, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[245]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[246] == 176,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[246], "
        "expected 176, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[246]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[247] == 129,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[247], "
        "expected 129, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[247]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[248] == 81,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[248], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[248]);
    ck_assert_msg(
        last_msg.msg.cell_modem_status.reserved[249] == 80,
        "incorrect value for last_msg.msg.cell_modem_status.reserved[249], "
        "expected 80, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.reserved[249]);

    ck_assert_msg(
        (last_msg.msg.cell_modem_status.signal_error_rate * 100 -
         8588.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.cell_modem_status.signal_error_rate, "
        "expected 8588.20019531, is %f",
        last_msg.msg.cell_modem_status.signal_error_rate);

    ck_assert_msg(
        last_msg.msg.cell_modem_status.signal_strength == 103,
        "incorrect value for last_msg.msg.cell_modem_status.signal_strength, "
        "expected 103, is %" PRId64,
        (int64_t)last_msg.msg.cell_modem_status.signal_strength);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_MsgCellModemStatus_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_piksi_MsgCellModemStatus");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_piksi_MsgCellModemStatus");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_MsgCellModemStatus);
  suite_add_tcase(s, tc_acq);
  return s;
}