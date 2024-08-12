/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMeta.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/solution_meta.h>
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

START_TEST(test_auto_check_sbp_solution_meta_MsgSolnMeta) {
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

    sbp_callback_register(&sbp_state, 0xff0e, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  14,  255, 0,   60,  254, 48,  208, 65,  216, 122, 45,  196, 160,
        144, 228, 8,   83,  89,  87,  3,   213, 95,  109, 86,  131, 71,  70,
        84,  73,  131, 26,  82,  247, 140, 97,  115, 110, 118, 253, 2,   122,
        186, 148, 122, 148, 180, 231, 68,  46,  190, 102, 243, 48,  192, 15,
        208, 89,  56,  10,  245, 2,   254, 201, 120, 32,  126, 2,   83,  161,
        238, 123, 102, 230, 76,  190, 225, 182, 207, 228, 7,   218, 117, 89,
        29,  191, 56,  248, 185, 255, 46,  18,  72,  142, 82,  113, 26,  4,
        172, 254, 178, 136, 113, 115, 58,  193, 89,  227, 182, 246, 76,  77,
        108, 245, 41,  31,  70,  124, 249, 145, 15,  78,  228, 38,  241, 129,
        8,   176, 251, 72,  248, 80,  115, 244, 231, 145, 191, 190, 178, 168,
        89,  233, 69,  176, 174, 140, 182, 141, 81,  82,  92,  79,  101, 223,
        100, 64,  184, 215, 124, 37,  21,  227, 135, 102, 72,  36,  219, 56,
        146, 90,  219, 104, 227, 102, 83,  12,  41,  122, 173, 94,  1,   174,
        134, 130, 104, 237, 116, 249, 107, 230, 130, 123, 25,  162, 57,  223,
        193, 174, 146, 193, 239, 44,  246, 197, 214, 80,  83,  100, 66,  72,
        133, 137, 140, 82,  2,   2,   96,  9,   96,  158, 134, 97,  43,  129,
        141, 25,  183, 200, 214, 57,  248, 103, 222, 65,  195, 15,  244, 21,
        180, 46,  140, 130, 36,  17,  194, 209, 65,  254, 115, 103, 152, 129,
        234, 235, 194, 234, 170, 201, 210, 154, 150, 247,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.soln_meta.age_corrections = 21256;

    test_msg.soln_meta.age_gnss = 3573765977;

    test_msg.soln_meta.hdop = 41156;

    test_msg.soln_meta.n_sol_in = 119;

    test_msg.soln_meta.pdop = 11642;

    test_msg.soln_meta.sol_in[0].flags = 109;

    test_msg.soln_meta.sol_in[0].sensor_type = 95;

    test_msg.soln_meta.sol_in[1].flags = 131;

    test_msg.soln_meta.sol_in[1].sensor_type = 86;

    test_msg.soln_meta.sol_in[2].flags = 70;

    test_msg.soln_meta.sol_in[2].sensor_type = 71;

    test_msg.soln_meta.sol_in[3].flags = 73;

    test_msg.soln_meta.sol_in[3].sensor_type = 84;

    test_msg.soln_meta.sol_in[4].flags = 26;

    test_msg.soln_meta.sol_in[4].sensor_type = 131;

    test_msg.soln_meta.sol_in[5].flags = 247;

    test_msg.soln_meta.sol_in[5].sensor_type = 82;

    test_msg.soln_meta.sol_in[6].flags = 97;

    test_msg.soln_meta.sol_in[6].sensor_type = 140;

    test_msg.soln_meta.sol_in[7].flags = 110;

    test_msg.soln_meta.sol_in[7].sensor_type = 115;

    test_msg.soln_meta.sol_in[8].flags = 253;

    test_msg.soln_meta.sol_in[8].sensor_type = 118;

    test_msg.soln_meta.sol_in[9].flags = 122;

    test_msg.soln_meta.sol_in[9].sensor_type = 2;

    test_msg.soln_meta.sol_in[10].flags = 148;

    test_msg.soln_meta.sol_in[10].sensor_type = 186;

    test_msg.soln_meta.sol_in[11].flags = 148;

    test_msg.soln_meta.sol_in[11].sensor_type = 122;

    test_msg.soln_meta.sol_in[12].flags = 231;

    test_msg.soln_meta.sol_in[12].sensor_type = 180;

    test_msg.soln_meta.sol_in[13].flags = 46;

    test_msg.soln_meta.sol_in[13].sensor_type = 68;

    test_msg.soln_meta.sol_in[14].flags = 102;

    test_msg.soln_meta.sol_in[14].sensor_type = 190;

    test_msg.soln_meta.sol_in[15].flags = 48;

    test_msg.soln_meta.sol_in[15].sensor_type = 243;

    test_msg.soln_meta.sol_in[16].flags = 15;

    test_msg.soln_meta.sol_in[16].sensor_type = 192;

    test_msg.soln_meta.sol_in[17].flags = 89;

    test_msg.soln_meta.sol_in[17].sensor_type = 208;

    test_msg.soln_meta.sol_in[18].flags = 10;

    test_msg.soln_meta.sol_in[18].sensor_type = 56;

    test_msg.soln_meta.sol_in[19].flags = 2;

    test_msg.soln_meta.sol_in[19].sensor_type = 245;

    test_msg.soln_meta.sol_in[20].flags = 201;

    test_msg.soln_meta.sol_in[20].sensor_type = 254;

    test_msg.soln_meta.sol_in[21].flags = 32;

    test_msg.soln_meta.sol_in[21].sensor_type = 120;

    test_msg.soln_meta.sol_in[22].flags = 2;

    test_msg.soln_meta.sol_in[22].sensor_type = 126;

    test_msg.soln_meta.sol_in[23].flags = 161;

    test_msg.soln_meta.sol_in[23].sensor_type = 83;

    test_msg.soln_meta.sol_in[24].flags = 123;

    test_msg.soln_meta.sol_in[24].sensor_type = 238;

    test_msg.soln_meta.sol_in[25].flags = 230;

    test_msg.soln_meta.sol_in[25].sensor_type = 102;

    test_msg.soln_meta.sol_in[26].flags = 190;

    test_msg.soln_meta.sol_in[26].sensor_type = 76;

    test_msg.soln_meta.sol_in[27].flags = 182;

    test_msg.soln_meta.sol_in[27].sensor_type = 225;

    test_msg.soln_meta.sol_in[28].flags = 228;

    test_msg.soln_meta.sol_in[28].sensor_type = 207;

    test_msg.soln_meta.sol_in[29].flags = 218;

    test_msg.soln_meta.sol_in[29].sensor_type = 7;

    test_msg.soln_meta.sol_in[30].flags = 89;

    test_msg.soln_meta.sol_in[30].sensor_type = 117;

    test_msg.soln_meta.sol_in[31].flags = 191;

    test_msg.soln_meta.sol_in[31].sensor_type = 29;

    test_msg.soln_meta.sol_in[32].flags = 248;

    test_msg.soln_meta.sol_in[32].sensor_type = 56;

    test_msg.soln_meta.sol_in[33].flags = 255;

    test_msg.soln_meta.sol_in[33].sensor_type = 185;

    test_msg.soln_meta.sol_in[34].flags = 18;

    test_msg.soln_meta.sol_in[34].sensor_type = 46;

    test_msg.soln_meta.sol_in[35].flags = 142;

    test_msg.soln_meta.sol_in[35].sensor_type = 72;

    test_msg.soln_meta.sol_in[36].flags = 113;

    test_msg.soln_meta.sol_in[36].sensor_type = 82;

    test_msg.soln_meta.sol_in[37].flags = 4;

    test_msg.soln_meta.sol_in[37].sensor_type = 26;

    test_msg.soln_meta.sol_in[38].flags = 254;

    test_msg.soln_meta.sol_in[38].sensor_type = 172;

    test_msg.soln_meta.sol_in[39].flags = 136;

    test_msg.soln_meta.sol_in[39].sensor_type = 178;

    test_msg.soln_meta.sol_in[40].flags = 115;

    test_msg.soln_meta.sol_in[40].sensor_type = 113;

    test_msg.soln_meta.sol_in[41].flags = 193;

    test_msg.soln_meta.sol_in[41].sensor_type = 58;

    test_msg.soln_meta.sol_in[42].flags = 227;

    test_msg.soln_meta.sol_in[42].sensor_type = 89;

    test_msg.soln_meta.sol_in[43].flags = 246;

    test_msg.soln_meta.sol_in[43].sensor_type = 182;

    test_msg.soln_meta.sol_in[44].flags = 77;

    test_msg.soln_meta.sol_in[44].sensor_type = 76;

    test_msg.soln_meta.sol_in[45].flags = 245;

    test_msg.soln_meta.sol_in[45].sensor_type = 108;

    test_msg.soln_meta.sol_in[46].flags = 31;

    test_msg.soln_meta.sol_in[46].sensor_type = 41;

    test_msg.soln_meta.sol_in[47].flags = 124;

    test_msg.soln_meta.sol_in[47].sensor_type = 70;

    test_msg.soln_meta.sol_in[48].flags = 145;

    test_msg.soln_meta.sol_in[48].sensor_type = 249;

    test_msg.soln_meta.sol_in[49].flags = 78;

    test_msg.soln_meta.sol_in[49].sensor_type = 15;

    test_msg.soln_meta.sol_in[50].flags = 38;

    test_msg.soln_meta.sol_in[50].sensor_type = 228;

    test_msg.soln_meta.sol_in[51].flags = 129;

    test_msg.soln_meta.sol_in[51].sensor_type = 241;

    test_msg.soln_meta.sol_in[52].flags = 176;

    test_msg.soln_meta.sol_in[52].sensor_type = 8;

    test_msg.soln_meta.sol_in[53].flags = 72;

    test_msg.soln_meta.sol_in[53].sensor_type = 251;

    test_msg.soln_meta.sol_in[54].flags = 80;

    test_msg.soln_meta.sol_in[54].sensor_type = 248;

    test_msg.soln_meta.sol_in[55].flags = 244;

    test_msg.soln_meta.sol_in[55].sensor_type = 115;

    test_msg.soln_meta.sol_in[56].flags = 145;

    test_msg.soln_meta.sol_in[56].sensor_type = 231;

    test_msg.soln_meta.sol_in[57].flags = 190;

    test_msg.soln_meta.sol_in[57].sensor_type = 191;

    test_msg.soln_meta.sol_in[58].flags = 168;

    test_msg.soln_meta.sol_in[58].sensor_type = 178;

    test_msg.soln_meta.sol_in[59].flags = 233;

    test_msg.soln_meta.sol_in[59].sensor_type = 89;

    test_msg.soln_meta.sol_in[60].flags = 176;

    test_msg.soln_meta.sol_in[60].sensor_type = 69;

    test_msg.soln_meta.sol_in[61].flags = 140;

    test_msg.soln_meta.sol_in[61].sensor_type = 174;

    test_msg.soln_meta.sol_in[62].flags = 141;

    test_msg.soln_meta.sol_in[62].sensor_type = 182;

    test_msg.soln_meta.sol_in[63].flags = 82;

    test_msg.soln_meta.sol_in[63].sensor_type = 81;

    test_msg.soln_meta.sol_in[64].flags = 79;

    test_msg.soln_meta.sol_in[64].sensor_type = 92;

    test_msg.soln_meta.sol_in[65].flags = 223;

    test_msg.soln_meta.sol_in[65].sensor_type = 101;

    test_msg.soln_meta.sol_in[66].flags = 64;

    test_msg.soln_meta.sol_in[66].sensor_type = 100;

    test_msg.soln_meta.sol_in[67].flags = 215;

    test_msg.soln_meta.sol_in[67].sensor_type = 184;

    test_msg.soln_meta.sol_in[68].flags = 37;

    test_msg.soln_meta.sol_in[68].sensor_type = 124;

    test_msg.soln_meta.sol_in[69].flags = 227;

    test_msg.soln_meta.sol_in[69].sensor_type = 21;

    test_msg.soln_meta.sol_in[70].flags = 102;

    test_msg.soln_meta.sol_in[70].sensor_type = 135;

    test_msg.soln_meta.sol_in[71].flags = 36;

    test_msg.soln_meta.sol_in[71].sensor_type = 72;

    test_msg.soln_meta.sol_in[72].flags = 56;

    test_msg.soln_meta.sol_in[72].sensor_type = 219;

    test_msg.soln_meta.sol_in[73].flags = 90;

    test_msg.soln_meta.sol_in[73].sensor_type = 146;

    test_msg.soln_meta.sol_in[74].flags = 104;

    test_msg.soln_meta.sol_in[74].sensor_type = 219;

    test_msg.soln_meta.sol_in[75].flags = 102;

    test_msg.soln_meta.sol_in[75].sensor_type = 227;

    test_msg.soln_meta.sol_in[76].flags = 12;

    test_msg.soln_meta.sol_in[76].sensor_type = 83;

    test_msg.soln_meta.sol_in[77].flags = 122;

    test_msg.soln_meta.sol_in[77].sensor_type = 41;

    test_msg.soln_meta.sol_in[78].flags = 94;

    test_msg.soln_meta.sol_in[78].sensor_type = 173;

    test_msg.soln_meta.sol_in[79].flags = 174;

    test_msg.soln_meta.sol_in[79].sensor_type = 1;

    test_msg.soln_meta.sol_in[80].flags = 130;

    test_msg.soln_meta.sol_in[80].sensor_type = 134;

    test_msg.soln_meta.sol_in[81].flags = 237;

    test_msg.soln_meta.sol_in[81].sensor_type = 104;

    test_msg.soln_meta.sol_in[82].flags = 249;

    test_msg.soln_meta.sol_in[82].sensor_type = 116;

    test_msg.soln_meta.sol_in[83].flags = 230;

    test_msg.soln_meta.sol_in[83].sensor_type = 107;

    test_msg.soln_meta.sol_in[84].flags = 123;

    test_msg.soln_meta.sol_in[84].sensor_type = 130;

    test_msg.soln_meta.sol_in[85].flags = 162;

    test_msg.soln_meta.sol_in[85].sensor_type = 25;

    test_msg.soln_meta.sol_in[86].flags = 223;

    test_msg.soln_meta.sol_in[86].sensor_type = 57;

    test_msg.soln_meta.sol_in[87].flags = 174;

    test_msg.soln_meta.sol_in[87].sensor_type = 193;

    test_msg.soln_meta.sol_in[88].flags = 193;

    test_msg.soln_meta.sol_in[88].sensor_type = 146;

    test_msg.soln_meta.sol_in[89].flags = 44;

    test_msg.soln_meta.sol_in[89].sensor_type = 239;

    test_msg.soln_meta.sol_in[90].flags = 197;

    test_msg.soln_meta.sol_in[90].sensor_type = 246;

    test_msg.soln_meta.sol_in[91].flags = 80;

    test_msg.soln_meta.sol_in[91].sensor_type = 214;

    test_msg.soln_meta.sol_in[92].flags = 100;

    test_msg.soln_meta.sol_in[92].sensor_type = 83;

    test_msg.soln_meta.sol_in[93].flags = 72;

    test_msg.soln_meta.sol_in[93].sensor_type = 66;

    test_msg.soln_meta.sol_in[94].flags = 137;

    test_msg.soln_meta.sol_in[94].sensor_type = 133;

    test_msg.soln_meta.sol_in[95].flags = 82;

    test_msg.soln_meta.sol_in[95].sensor_type = 140;

    test_msg.soln_meta.sol_in[96].flags = 2;

    test_msg.soln_meta.sol_in[96].sensor_type = 2;

    test_msg.soln_meta.sol_in[97].flags = 9;

    test_msg.soln_meta.sol_in[97].sensor_type = 96;

    test_msg.soln_meta.sol_in[98].flags = 158;

    test_msg.soln_meta.sol_in[98].sensor_type = 96;

    test_msg.soln_meta.sol_in[99].flags = 97;

    test_msg.soln_meta.sol_in[99].sensor_type = 134;

    test_msg.soln_meta.sol_in[100].flags = 129;

    test_msg.soln_meta.sol_in[100].sensor_type = 43;

    test_msg.soln_meta.sol_in[101].flags = 25;

    test_msg.soln_meta.sol_in[101].sensor_type = 141;

    test_msg.soln_meta.sol_in[102].flags = 200;

    test_msg.soln_meta.sol_in[102].sensor_type = 183;

    test_msg.soln_meta.sol_in[103].flags = 57;

    test_msg.soln_meta.sol_in[103].sensor_type = 214;

    test_msg.soln_meta.sol_in[104].flags = 103;

    test_msg.soln_meta.sol_in[104].sensor_type = 248;

    test_msg.soln_meta.sol_in[105].flags = 65;

    test_msg.soln_meta.sol_in[105].sensor_type = 222;

    test_msg.soln_meta.sol_in[106].flags = 15;

    test_msg.soln_meta.sol_in[106].sensor_type = 195;

    test_msg.soln_meta.sol_in[107].flags = 21;

    test_msg.soln_meta.sol_in[107].sensor_type = 244;

    test_msg.soln_meta.sol_in[108].flags = 46;

    test_msg.soln_meta.sol_in[108].sensor_type = 180;

    test_msg.soln_meta.sol_in[109].flags = 130;

    test_msg.soln_meta.sol_in[109].sensor_type = 140;

    test_msg.soln_meta.sol_in[110].flags = 17;

    test_msg.soln_meta.sol_in[110].sensor_type = 36;

    test_msg.soln_meta.sol_in[111].flags = 209;

    test_msg.soln_meta.sol_in[111].sensor_type = 194;

    test_msg.soln_meta.sol_in[112].flags = 254;

    test_msg.soln_meta.sol_in[112].sensor_type = 65;

    test_msg.soln_meta.sol_in[113].flags = 103;

    test_msg.soln_meta.sol_in[113].sensor_type = 115;

    test_msg.soln_meta.sol_in[114].flags = 129;

    test_msg.soln_meta.sol_in[114].sensor_type = 152;

    test_msg.soln_meta.sol_in[115].flags = 235;

    test_msg.soln_meta.sol_in[115].sensor_type = 234;

    test_msg.soln_meta.sol_in[116].flags = 234;

    test_msg.soln_meta.sol_in[116].sensor_type = 194;

    test_msg.soln_meta.sol_in[117].flags = 201;

    test_msg.soln_meta.sol_in[117].sensor_type = 170;

    test_msg.soln_meta.sol_in[118].flags = 154;

    test_msg.soln_meta.sol_in[118].sensor_type = 210;

    test_msg.soln_meta.tow = 3628191792;

    test_msg.soln_meta.vdop = 58512;

    sbp_message_send(&sbp_state, SbpMsgSolnMeta, 15360, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 15360,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSolnMeta, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.soln_meta.age_corrections == 21256,
                  "incorrect value for last_msg.msg.soln_meta.age_corrections, "
                  "expected 21256, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.age_corrections);

    ck_assert_msg(last_msg.msg.soln_meta.age_gnss == 3573765977,
                  "incorrect value for last_msg.msg.soln_meta.age_gnss, "
                  "expected 3573765977, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.age_gnss);

    ck_assert_msg(last_msg.msg.soln_meta.hdop == 41156,
                  "incorrect value for last_msg.msg.soln_meta.hdop, expected "
                  "41156, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.hdop);

    ck_assert_msg(last_msg.msg.soln_meta.n_sol_in == 119,
                  "incorrect value for last_msg.msg.soln_meta.n_sol_in, "
                  "expected 119, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.n_sol_in);

    ck_assert_msg(last_msg.msg.soln_meta.pdop == 11642,
                  "incorrect value for last_msg.msg.soln_meta.pdop, expected "
                  "11642, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.pdop);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[0].flags == 109,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[0].flags, "
                  "expected 109, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[0].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[0].sensor_type == 95,
        "incorrect value for last_msg.msg.soln_meta.sol_in[0].sensor_type, "
        "expected 95, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[0].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[1].flags == 131,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[1].flags, "
                  "expected 131, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[1].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[1].sensor_type == 86,
        "incorrect value for last_msg.msg.soln_meta.sol_in[1].sensor_type, "
        "expected 86, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[1].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[2].flags == 70,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[2].flags, "
                  "expected 70, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[2].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[2].sensor_type == 71,
        "incorrect value for last_msg.msg.soln_meta.sol_in[2].sensor_type, "
        "expected 71, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[2].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[3].flags == 73,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[3].flags, "
                  "expected 73, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[3].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[3].sensor_type == 84,
        "incorrect value for last_msg.msg.soln_meta.sol_in[3].sensor_type, "
        "expected 84, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[3].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[4].flags == 26,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[4].flags, "
                  "expected 26, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[4].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[4].sensor_type == 131,
        "incorrect value for last_msg.msg.soln_meta.sol_in[4].sensor_type, "
        "expected 131, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[4].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[5].flags == 247,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[5].flags, "
                  "expected 247, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[5].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[5].sensor_type == 82,
        "incorrect value for last_msg.msg.soln_meta.sol_in[5].sensor_type, "
        "expected 82, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[5].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[6].flags == 97,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[6].flags, "
                  "expected 97, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[6].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[6].sensor_type == 140,
        "incorrect value for last_msg.msg.soln_meta.sol_in[6].sensor_type, "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[6].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[7].flags == 110,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[7].flags, "
                  "expected 110, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[7].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[7].sensor_type == 115,
        "incorrect value for last_msg.msg.soln_meta.sol_in[7].sensor_type, "
        "expected 115, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[7].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[8].flags == 253,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[8].flags, "
                  "expected 253, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[8].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[8].sensor_type == 118,
        "incorrect value for last_msg.msg.soln_meta.sol_in[8].sensor_type, "
        "expected 118, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[8].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.sol_in[9].flags == 122,
                  "incorrect value for last_msg.msg.soln_meta.sol_in[9].flags, "
                  "expected 122, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.sol_in[9].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[9].sensor_type == 2,
        "incorrect value for last_msg.msg.soln_meta.sol_in[9].sensor_type, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[9].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[10].flags == 148,
        "incorrect value for last_msg.msg.soln_meta.sol_in[10].flags, expected "
        "148, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[10].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[10].sensor_type == 186,
        "incorrect value for last_msg.msg.soln_meta.sol_in[10].sensor_type, "
        "expected 186, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[10].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[11].flags == 148,
        "incorrect value for last_msg.msg.soln_meta.sol_in[11].flags, expected "
        "148, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[11].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[11].sensor_type == 122,
        "incorrect value for last_msg.msg.soln_meta.sol_in[11].sensor_type, "
        "expected 122, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[11].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[12].flags == 231,
        "incorrect value for last_msg.msg.soln_meta.sol_in[12].flags, expected "
        "231, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[12].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[12].sensor_type == 180,
        "incorrect value for last_msg.msg.soln_meta.sol_in[12].sensor_type, "
        "expected 180, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[12].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[13].flags == 46,
        "incorrect value for last_msg.msg.soln_meta.sol_in[13].flags, expected "
        "46, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[13].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[13].sensor_type == 68,
        "incorrect value for last_msg.msg.soln_meta.sol_in[13].sensor_type, "
        "expected 68, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[13].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[14].flags == 102,
        "incorrect value for last_msg.msg.soln_meta.sol_in[14].flags, expected "
        "102, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[14].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[14].sensor_type == 190,
        "incorrect value for last_msg.msg.soln_meta.sol_in[14].sensor_type, "
        "expected 190, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[14].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[15].flags == 48,
        "incorrect value for last_msg.msg.soln_meta.sol_in[15].flags, expected "
        "48, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[15].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[15].sensor_type == 243,
        "incorrect value for last_msg.msg.soln_meta.sol_in[15].sensor_type, "
        "expected 243, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[15].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[16].flags == 15,
        "incorrect value for last_msg.msg.soln_meta.sol_in[16].flags, expected "
        "15, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[16].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[16].sensor_type == 192,
        "incorrect value for last_msg.msg.soln_meta.sol_in[16].sensor_type, "
        "expected 192, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[16].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[17].flags == 89,
        "incorrect value for last_msg.msg.soln_meta.sol_in[17].flags, expected "
        "89, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[17].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[17].sensor_type == 208,
        "incorrect value for last_msg.msg.soln_meta.sol_in[17].sensor_type, "
        "expected 208, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[17].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[18].flags == 10,
        "incorrect value for last_msg.msg.soln_meta.sol_in[18].flags, expected "
        "10, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[18].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[18].sensor_type == 56,
        "incorrect value for last_msg.msg.soln_meta.sol_in[18].sensor_type, "
        "expected 56, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[18].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[19].flags == 2,
        "incorrect value for last_msg.msg.soln_meta.sol_in[19].flags, expected "
        "2, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[19].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[19].sensor_type == 245,
        "incorrect value for last_msg.msg.soln_meta.sol_in[19].sensor_type, "
        "expected 245, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[19].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[20].flags == 201,
        "incorrect value for last_msg.msg.soln_meta.sol_in[20].flags, expected "
        "201, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[20].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[20].sensor_type == 254,
        "incorrect value for last_msg.msg.soln_meta.sol_in[20].sensor_type, "
        "expected 254, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[20].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[21].flags == 32,
        "incorrect value for last_msg.msg.soln_meta.sol_in[21].flags, expected "
        "32, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[21].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[21].sensor_type == 120,
        "incorrect value for last_msg.msg.soln_meta.sol_in[21].sensor_type, "
        "expected 120, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[21].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[22].flags == 2,
        "incorrect value for last_msg.msg.soln_meta.sol_in[22].flags, expected "
        "2, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[22].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[22].sensor_type == 126,
        "incorrect value for last_msg.msg.soln_meta.sol_in[22].sensor_type, "
        "expected 126, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[22].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[23].flags == 161,
        "incorrect value for last_msg.msg.soln_meta.sol_in[23].flags, expected "
        "161, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[23].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[23].sensor_type == 83,
        "incorrect value for last_msg.msg.soln_meta.sol_in[23].sensor_type, "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[23].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[24].flags == 123,
        "incorrect value for last_msg.msg.soln_meta.sol_in[24].flags, expected "
        "123, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[24].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[24].sensor_type == 238,
        "incorrect value for last_msg.msg.soln_meta.sol_in[24].sensor_type, "
        "expected 238, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[24].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[25].flags == 230,
        "incorrect value for last_msg.msg.soln_meta.sol_in[25].flags, expected "
        "230, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[25].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[25].sensor_type == 102,
        "incorrect value for last_msg.msg.soln_meta.sol_in[25].sensor_type, "
        "expected 102, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[25].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[26].flags == 190,
        "incorrect value for last_msg.msg.soln_meta.sol_in[26].flags, expected "
        "190, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[26].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[26].sensor_type == 76,
        "incorrect value for last_msg.msg.soln_meta.sol_in[26].sensor_type, "
        "expected 76, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[26].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[27].flags == 182,
        "incorrect value for last_msg.msg.soln_meta.sol_in[27].flags, expected "
        "182, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[27].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[27].sensor_type == 225,
        "incorrect value for last_msg.msg.soln_meta.sol_in[27].sensor_type, "
        "expected 225, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[27].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[28].flags == 228,
        "incorrect value for last_msg.msg.soln_meta.sol_in[28].flags, expected "
        "228, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[28].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[28].sensor_type == 207,
        "incorrect value for last_msg.msg.soln_meta.sol_in[28].sensor_type, "
        "expected 207, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[28].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[29].flags == 218,
        "incorrect value for last_msg.msg.soln_meta.sol_in[29].flags, expected "
        "218, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[29].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[29].sensor_type == 7,
        "incorrect value for last_msg.msg.soln_meta.sol_in[29].sensor_type, "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[29].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[30].flags == 89,
        "incorrect value for last_msg.msg.soln_meta.sol_in[30].flags, expected "
        "89, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[30].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[30].sensor_type == 117,
        "incorrect value for last_msg.msg.soln_meta.sol_in[30].sensor_type, "
        "expected 117, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[30].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[31].flags == 191,
        "incorrect value for last_msg.msg.soln_meta.sol_in[31].flags, expected "
        "191, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[31].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[31].sensor_type == 29,
        "incorrect value for last_msg.msg.soln_meta.sol_in[31].sensor_type, "
        "expected 29, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[31].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[32].flags == 248,
        "incorrect value for last_msg.msg.soln_meta.sol_in[32].flags, expected "
        "248, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[32].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[32].sensor_type == 56,
        "incorrect value for last_msg.msg.soln_meta.sol_in[32].sensor_type, "
        "expected 56, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[32].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[33].flags == 255,
        "incorrect value for last_msg.msg.soln_meta.sol_in[33].flags, expected "
        "255, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[33].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[33].sensor_type == 185,
        "incorrect value for last_msg.msg.soln_meta.sol_in[33].sensor_type, "
        "expected 185, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[33].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[34].flags == 18,
        "incorrect value for last_msg.msg.soln_meta.sol_in[34].flags, expected "
        "18, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[34].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[34].sensor_type == 46,
        "incorrect value for last_msg.msg.soln_meta.sol_in[34].sensor_type, "
        "expected 46, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[34].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[35].flags == 142,
        "incorrect value for last_msg.msg.soln_meta.sol_in[35].flags, expected "
        "142, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[35].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[35].sensor_type == 72,
        "incorrect value for last_msg.msg.soln_meta.sol_in[35].sensor_type, "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[35].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[36].flags == 113,
        "incorrect value for last_msg.msg.soln_meta.sol_in[36].flags, expected "
        "113, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[36].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[36].sensor_type == 82,
        "incorrect value for last_msg.msg.soln_meta.sol_in[36].sensor_type, "
        "expected 82, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[36].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[37].flags == 4,
        "incorrect value for last_msg.msg.soln_meta.sol_in[37].flags, expected "
        "4, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[37].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[37].sensor_type == 26,
        "incorrect value for last_msg.msg.soln_meta.sol_in[37].sensor_type, "
        "expected 26, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[37].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[38].flags == 254,
        "incorrect value for last_msg.msg.soln_meta.sol_in[38].flags, expected "
        "254, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[38].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[38].sensor_type == 172,
        "incorrect value for last_msg.msg.soln_meta.sol_in[38].sensor_type, "
        "expected 172, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[38].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[39].flags == 136,
        "incorrect value for last_msg.msg.soln_meta.sol_in[39].flags, expected "
        "136, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[39].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[39].sensor_type == 178,
        "incorrect value for last_msg.msg.soln_meta.sol_in[39].sensor_type, "
        "expected 178, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[39].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[40].flags == 115,
        "incorrect value for last_msg.msg.soln_meta.sol_in[40].flags, expected "
        "115, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[40].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[40].sensor_type == 113,
        "incorrect value for last_msg.msg.soln_meta.sol_in[40].sensor_type, "
        "expected 113, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[40].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[41].flags == 193,
        "incorrect value for last_msg.msg.soln_meta.sol_in[41].flags, expected "
        "193, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[41].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[41].sensor_type == 58,
        "incorrect value for last_msg.msg.soln_meta.sol_in[41].sensor_type, "
        "expected 58, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[41].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[42].flags == 227,
        "incorrect value for last_msg.msg.soln_meta.sol_in[42].flags, expected "
        "227, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[42].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[42].sensor_type == 89,
        "incorrect value for last_msg.msg.soln_meta.sol_in[42].sensor_type, "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[42].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[43].flags == 246,
        "incorrect value for last_msg.msg.soln_meta.sol_in[43].flags, expected "
        "246, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[43].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[43].sensor_type == 182,
        "incorrect value for last_msg.msg.soln_meta.sol_in[43].sensor_type, "
        "expected 182, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[43].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[44].flags == 77,
        "incorrect value for last_msg.msg.soln_meta.sol_in[44].flags, expected "
        "77, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[44].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[44].sensor_type == 76,
        "incorrect value for last_msg.msg.soln_meta.sol_in[44].sensor_type, "
        "expected 76, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[44].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[45].flags == 245,
        "incorrect value for last_msg.msg.soln_meta.sol_in[45].flags, expected "
        "245, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[45].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[45].sensor_type == 108,
        "incorrect value for last_msg.msg.soln_meta.sol_in[45].sensor_type, "
        "expected 108, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[45].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[46].flags == 31,
        "incorrect value for last_msg.msg.soln_meta.sol_in[46].flags, expected "
        "31, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[46].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[46].sensor_type == 41,
        "incorrect value for last_msg.msg.soln_meta.sol_in[46].sensor_type, "
        "expected 41, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[46].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[47].flags == 124,
        "incorrect value for last_msg.msg.soln_meta.sol_in[47].flags, expected "
        "124, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[47].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[47].sensor_type == 70,
        "incorrect value for last_msg.msg.soln_meta.sol_in[47].sensor_type, "
        "expected 70, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[47].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[48].flags == 145,
        "incorrect value for last_msg.msg.soln_meta.sol_in[48].flags, expected "
        "145, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[48].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[48].sensor_type == 249,
        "incorrect value for last_msg.msg.soln_meta.sol_in[48].sensor_type, "
        "expected 249, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[48].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[49].flags == 78,
        "incorrect value for last_msg.msg.soln_meta.sol_in[49].flags, expected "
        "78, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[49].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[49].sensor_type == 15,
        "incorrect value for last_msg.msg.soln_meta.sol_in[49].sensor_type, "
        "expected 15, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[49].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[50].flags == 38,
        "incorrect value for last_msg.msg.soln_meta.sol_in[50].flags, expected "
        "38, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[50].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[50].sensor_type == 228,
        "incorrect value for last_msg.msg.soln_meta.sol_in[50].sensor_type, "
        "expected 228, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[50].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[51].flags == 129,
        "incorrect value for last_msg.msg.soln_meta.sol_in[51].flags, expected "
        "129, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[51].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[51].sensor_type == 241,
        "incorrect value for last_msg.msg.soln_meta.sol_in[51].sensor_type, "
        "expected 241, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[51].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[52].flags == 176,
        "incorrect value for last_msg.msg.soln_meta.sol_in[52].flags, expected "
        "176, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[52].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[52].sensor_type == 8,
        "incorrect value for last_msg.msg.soln_meta.sol_in[52].sensor_type, "
        "expected 8, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[52].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[53].flags == 72,
        "incorrect value for last_msg.msg.soln_meta.sol_in[53].flags, expected "
        "72, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[53].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[53].sensor_type == 251,
        "incorrect value for last_msg.msg.soln_meta.sol_in[53].sensor_type, "
        "expected 251, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[53].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[54].flags == 80,
        "incorrect value for last_msg.msg.soln_meta.sol_in[54].flags, expected "
        "80, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[54].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[54].sensor_type == 248,
        "incorrect value for last_msg.msg.soln_meta.sol_in[54].sensor_type, "
        "expected 248, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[54].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[55].flags == 244,
        "incorrect value for last_msg.msg.soln_meta.sol_in[55].flags, expected "
        "244, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[55].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[55].sensor_type == 115,
        "incorrect value for last_msg.msg.soln_meta.sol_in[55].sensor_type, "
        "expected 115, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[55].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[56].flags == 145,
        "incorrect value for last_msg.msg.soln_meta.sol_in[56].flags, expected "
        "145, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[56].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[56].sensor_type == 231,
        "incorrect value for last_msg.msg.soln_meta.sol_in[56].sensor_type, "
        "expected 231, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[56].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[57].flags == 190,
        "incorrect value for last_msg.msg.soln_meta.sol_in[57].flags, expected "
        "190, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[57].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[57].sensor_type == 191,
        "incorrect value for last_msg.msg.soln_meta.sol_in[57].sensor_type, "
        "expected 191, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[57].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[58].flags == 168,
        "incorrect value for last_msg.msg.soln_meta.sol_in[58].flags, expected "
        "168, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[58].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[58].sensor_type == 178,
        "incorrect value for last_msg.msg.soln_meta.sol_in[58].sensor_type, "
        "expected 178, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[58].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[59].flags == 233,
        "incorrect value for last_msg.msg.soln_meta.sol_in[59].flags, expected "
        "233, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[59].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[59].sensor_type == 89,
        "incorrect value for last_msg.msg.soln_meta.sol_in[59].sensor_type, "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[59].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[60].flags == 176,
        "incorrect value for last_msg.msg.soln_meta.sol_in[60].flags, expected "
        "176, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[60].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[60].sensor_type == 69,
        "incorrect value for last_msg.msg.soln_meta.sol_in[60].sensor_type, "
        "expected 69, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[60].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[61].flags == 140,
        "incorrect value for last_msg.msg.soln_meta.sol_in[61].flags, expected "
        "140, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[61].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[61].sensor_type == 174,
        "incorrect value for last_msg.msg.soln_meta.sol_in[61].sensor_type, "
        "expected 174, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[61].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[62].flags == 141,
        "incorrect value for last_msg.msg.soln_meta.sol_in[62].flags, expected "
        "141, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[62].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[62].sensor_type == 182,
        "incorrect value for last_msg.msg.soln_meta.sol_in[62].sensor_type, "
        "expected 182, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[62].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[63].flags == 82,
        "incorrect value for last_msg.msg.soln_meta.sol_in[63].flags, expected "
        "82, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[63].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[63].sensor_type == 81,
        "incorrect value for last_msg.msg.soln_meta.sol_in[63].sensor_type, "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[63].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[64].flags == 79,
        "incorrect value for last_msg.msg.soln_meta.sol_in[64].flags, expected "
        "79, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[64].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[64].sensor_type == 92,
        "incorrect value for last_msg.msg.soln_meta.sol_in[64].sensor_type, "
        "expected 92, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[64].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[65].flags == 223,
        "incorrect value for last_msg.msg.soln_meta.sol_in[65].flags, expected "
        "223, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[65].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[65].sensor_type == 101,
        "incorrect value for last_msg.msg.soln_meta.sol_in[65].sensor_type, "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[65].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[66].flags == 64,
        "incorrect value for last_msg.msg.soln_meta.sol_in[66].flags, expected "
        "64, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[66].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[66].sensor_type == 100,
        "incorrect value for last_msg.msg.soln_meta.sol_in[66].sensor_type, "
        "expected 100, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[66].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[67].flags == 215,
        "incorrect value for last_msg.msg.soln_meta.sol_in[67].flags, expected "
        "215, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[67].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[67].sensor_type == 184,
        "incorrect value for last_msg.msg.soln_meta.sol_in[67].sensor_type, "
        "expected 184, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[67].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[68].flags == 37,
        "incorrect value for last_msg.msg.soln_meta.sol_in[68].flags, expected "
        "37, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[68].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[68].sensor_type == 124,
        "incorrect value for last_msg.msg.soln_meta.sol_in[68].sensor_type, "
        "expected 124, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[68].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[69].flags == 227,
        "incorrect value for last_msg.msg.soln_meta.sol_in[69].flags, expected "
        "227, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[69].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[69].sensor_type == 21,
        "incorrect value for last_msg.msg.soln_meta.sol_in[69].sensor_type, "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[69].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[70].flags == 102,
        "incorrect value for last_msg.msg.soln_meta.sol_in[70].flags, expected "
        "102, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[70].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[70].sensor_type == 135,
        "incorrect value for last_msg.msg.soln_meta.sol_in[70].sensor_type, "
        "expected 135, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[70].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[71].flags == 36,
        "incorrect value for last_msg.msg.soln_meta.sol_in[71].flags, expected "
        "36, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[71].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[71].sensor_type == 72,
        "incorrect value for last_msg.msg.soln_meta.sol_in[71].sensor_type, "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[71].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[72].flags == 56,
        "incorrect value for last_msg.msg.soln_meta.sol_in[72].flags, expected "
        "56, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[72].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[72].sensor_type == 219,
        "incorrect value for last_msg.msg.soln_meta.sol_in[72].sensor_type, "
        "expected 219, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[72].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[73].flags == 90,
        "incorrect value for last_msg.msg.soln_meta.sol_in[73].flags, expected "
        "90, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[73].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[73].sensor_type == 146,
        "incorrect value for last_msg.msg.soln_meta.sol_in[73].sensor_type, "
        "expected 146, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[73].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[74].flags == 104,
        "incorrect value for last_msg.msg.soln_meta.sol_in[74].flags, expected "
        "104, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[74].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[74].sensor_type == 219,
        "incorrect value for last_msg.msg.soln_meta.sol_in[74].sensor_type, "
        "expected 219, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[74].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[75].flags == 102,
        "incorrect value for last_msg.msg.soln_meta.sol_in[75].flags, expected "
        "102, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[75].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[75].sensor_type == 227,
        "incorrect value for last_msg.msg.soln_meta.sol_in[75].sensor_type, "
        "expected 227, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[75].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[76].flags == 12,
        "incorrect value for last_msg.msg.soln_meta.sol_in[76].flags, expected "
        "12, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[76].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[76].sensor_type == 83,
        "incorrect value for last_msg.msg.soln_meta.sol_in[76].sensor_type, "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[76].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[77].flags == 122,
        "incorrect value for last_msg.msg.soln_meta.sol_in[77].flags, expected "
        "122, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[77].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[77].sensor_type == 41,
        "incorrect value for last_msg.msg.soln_meta.sol_in[77].sensor_type, "
        "expected 41, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[77].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[78].flags == 94,
        "incorrect value for last_msg.msg.soln_meta.sol_in[78].flags, expected "
        "94, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[78].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[78].sensor_type == 173,
        "incorrect value for last_msg.msg.soln_meta.sol_in[78].sensor_type, "
        "expected 173, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[78].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[79].flags == 174,
        "incorrect value for last_msg.msg.soln_meta.sol_in[79].flags, expected "
        "174, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[79].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[79].sensor_type == 1,
        "incorrect value for last_msg.msg.soln_meta.sol_in[79].sensor_type, "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[79].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[80].flags == 130,
        "incorrect value for last_msg.msg.soln_meta.sol_in[80].flags, expected "
        "130, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[80].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[80].sensor_type == 134,
        "incorrect value for last_msg.msg.soln_meta.sol_in[80].sensor_type, "
        "expected 134, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[80].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[81].flags == 237,
        "incorrect value for last_msg.msg.soln_meta.sol_in[81].flags, expected "
        "237, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[81].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[81].sensor_type == 104,
        "incorrect value for last_msg.msg.soln_meta.sol_in[81].sensor_type, "
        "expected 104, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[81].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[82].flags == 249,
        "incorrect value for last_msg.msg.soln_meta.sol_in[82].flags, expected "
        "249, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[82].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[82].sensor_type == 116,
        "incorrect value for last_msg.msg.soln_meta.sol_in[82].sensor_type, "
        "expected 116, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[82].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[83].flags == 230,
        "incorrect value for last_msg.msg.soln_meta.sol_in[83].flags, expected "
        "230, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[83].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[83].sensor_type == 107,
        "incorrect value for last_msg.msg.soln_meta.sol_in[83].sensor_type, "
        "expected 107, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[83].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[84].flags == 123,
        "incorrect value for last_msg.msg.soln_meta.sol_in[84].flags, expected "
        "123, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[84].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[84].sensor_type == 130,
        "incorrect value for last_msg.msg.soln_meta.sol_in[84].sensor_type, "
        "expected 130, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[84].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[85].flags == 162,
        "incorrect value for last_msg.msg.soln_meta.sol_in[85].flags, expected "
        "162, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[85].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[85].sensor_type == 25,
        "incorrect value for last_msg.msg.soln_meta.sol_in[85].sensor_type, "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[85].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[86].flags == 223,
        "incorrect value for last_msg.msg.soln_meta.sol_in[86].flags, expected "
        "223, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[86].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[86].sensor_type == 57,
        "incorrect value for last_msg.msg.soln_meta.sol_in[86].sensor_type, "
        "expected 57, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[86].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[87].flags == 174,
        "incorrect value for last_msg.msg.soln_meta.sol_in[87].flags, expected "
        "174, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[87].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[87].sensor_type == 193,
        "incorrect value for last_msg.msg.soln_meta.sol_in[87].sensor_type, "
        "expected 193, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[87].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[88].flags == 193,
        "incorrect value for last_msg.msg.soln_meta.sol_in[88].flags, expected "
        "193, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[88].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[88].sensor_type == 146,
        "incorrect value for last_msg.msg.soln_meta.sol_in[88].sensor_type, "
        "expected 146, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[88].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[89].flags == 44,
        "incorrect value for last_msg.msg.soln_meta.sol_in[89].flags, expected "
        "44, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[89].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[89].sensor_type == 239,
        "incorrect value for last_msg.msg.soln_meta.sol_in[89].sensor_type, "
        "expected 239, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[89].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[90].flags == 197,
        "incorrect value for last_msg.msg.soln_meta.sol_in[90].flags, expected "
        "197, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[90].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[90].sensor_type == 246,
        "incorrect value for last_msg.msg.soln_meta.sol_in[90].sensor_type, "
        "expected 246, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[90].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[91].flags == 80,
        "incorrect value for last_msg.msg.soln_meta.sol_in[91].flags, expected "
        "80, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[91].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[91].sensor_type == 214,
        "incorrect value for last_msg.msg.soln_meta.sol_in[91].sensor_type, "
        "expected 214, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[91].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[92].flags == 100,
        "incorrect value for last_msg.msg.soln_meta.sol_in[92].flags, expected "
        "100, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[92].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[92].sensor_type == 83,
        "incorrect value for last_msg.msg.soln_meta.sol_in[92].sensor_type, "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[92].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[93].flags == 72,
        "incorrect value for last_msg.msg.soln_meta.sol_in[93].flags, expected "
        "72, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[93].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[93].sensor_type == 66,
        "incorrect value for last_msg.msg.soln_meta.sol_in[93].sensor_type, "
        "expected 66, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[93].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[94].flags == 137,
        "incorrect value for last_msg.msg.soln_meta.sol_in[94].flags, expected "
        "137, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[94].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[94].sensor_type == 133,
        "incorrect value for last_msg.msg.soln_meta.sol_in[94].sensor_type, "
        "expected 133, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[94].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[95].flags == 82,
        "incorrect value for last_msg.msg.soln_meta.sol_in[95].flags, expected "
        "82, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[95].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[95].sensor_type == 140,
        "incorrect value for last_msg.msg.soln_meta.sol_in[95].sensor_type, "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[95].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[96].flags == 2,
        "incorrect value for last_msg.msg.soln_meta.sol_in[96].flags, expected "
        "2, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[96].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[96].sensor_type == 2,
        "incorrect value for last_msg.msg.soln_meta.sol_in[96].sensor_type, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[96].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[97].flags == 9,
        "incorrect value for last_msg.msg.soln_meta.sol_in[97].flags, expected "
        "9, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[97].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[97].sensor_type == 96,
        "incorrect value for last_msg.msg.soln_meta.sol_in[97].sensor_type, "
        "expected 96, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[97].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[98].flags == 158,
        "incorrect value for last_msg.msg.soln_meta.sol_in[98].flags, expected "
        "158, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[98].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[98].sensor_type == 96,
        "incorrect value for last_msg.msg.soln_meta.sol_in[98].sensor_type, "
        "expected 96, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[98].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[99].flags == 97,
        "incorrect value for last_msg.msg.soln_meta.sol_in[99].flags, expected "
        "97, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[99].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[99].sensor_type == 134,
        "incorrect value for last_msg.msg.soln_meta.sol_in[99].sensor_type, "
        "expected 134, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[99].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[100].flags == 129,
        "incorrect value for last_msg.msg.soln_meta.sol_in[100].flags, "
        "expected 129, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[100].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[100].sensor_type == 43,
        "incorrect value for last_msg.msg.soln_meta.sol_in[100].sensor_type, "
        "expected 43, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[100].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[101].flags == 25,
        "incorrect value for last_msg.msg.soln_meta.sol_in[101].flags, "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[101].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[101].sensor_type == 141,
        "incorrect value for last_msg.msg.soln_meta.sol_in[101].sensor_type, "
        "expected 141, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[101].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[102].flags == 200,
        "incorrect value for last_msg.msg.soln_meta.sol_in[102].flags, "
        "expected 200, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[102].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[102].sensor_type == 183,
        "incorrect value for last_msg.msg.soln_meta.sol_in[102].sensor_type, "
        "expected 183, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[102].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[103].flags == 57,
        "incorrect value for last_msg.msg.soln_meta.sol_in[103].flags, "
        "expected 57, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[103].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[103].sensor_type == 214,
        "incorrect value for last_msg.msg.soln_meta.sol_in[103].sensor_type, "
        "expected 214, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[103].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[104].flags == 103,
        "incorrect value for last_msg.msg.soln_meta.sol_in[104].flags, "
        "expected 103, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[104].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[104].sensor_type == 248,
        "incorrect value for last_msg.msg.soln_meta.sol_in[104].sensor_type, "
        "expected 248, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[104].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[105].flags == 65,
        "incorrect value for last_msg.msg.soln_meta.sol_in[105].flags, "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[105].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[105].sensor_type == 222,
        "incorrect value for last_msg.msg.soln_meta.sol_in[105].sensor_type, "
        "expected 222, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[105].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[106].flags == 15,
        "incorrect value for last_msg.msg.soln_meta.sol_in[106].flags, "
        "expected 15, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[106].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[106].sensor_type == 195,
        "incorrect value for last_msg.msg.soln_meta.sol_in[106].sensor_type, "
        "expected 195, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[106].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[107].flags == 21,
        "incorrect value for last_msg.msg.soln_meta.sol_in[107].flags, "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[107].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[107].sensor_type == 244,
        "incorrect value for last_msg.msg.soln_meta.sol_in[107].sensor_type, "
        "expected 244, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[107].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[108].flags == 46,
        "incorrect value for last_msg.msg.soln_meta.sol_in[108].flags, "
        "expected 46, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[108].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[108].sensor_type == 180,
        "incorrect value for last_msg.msg.soln_meta.sol_in[108].sensor_type, "
        "expected 180, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[108].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[109].flags == 130,
        "incorrect value for last_msg.msg.soln_meta.sol_in[109].flags, "
        "expected 130, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[109].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[109].sensor_type == 140,
        "incorrect value for last_msg.msg.soln_meta.sol_in[109].sensor_type, "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[109].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[110].flags == 17,
        "incorrect value for last_msg.msg.soln_meta.sol_in[110].flags, "
        "expected 17, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[110].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[110].sensor_type == 36,
        "incorrect value for last_msg.msg.soln_meta.sol_in[110].sensor_type, "
        "expected 36, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[110].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[111].flags == 209,
        "incorrect value for last_msg.msg.soln_meta.sol_in[111].flags, "
        "expected 209, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[111].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[111].sensor_type == 194,
        "incorrect value for last_msg.msg.soln_meta.sol_in[111].sensor_type, "
        "expected 194, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[111].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[112].flags == 254,
        "incorrect value for last_msg.msg.soln_meta.sol_in[112].flags, "
        "expected 254, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[112].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[112].sensor_type == 65,
        "incorrect value for last_msg.msg.soln_meta.sol_in[112].sensor_type, "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[112].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[113].flags == 103,
        "incorrect value for last_msg.msg.soln_meta.sol_in[113].flags, "
        "expected 103, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[113].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[113].sensor_type == 115,
        "incorrect value for last_msg.msg.soln_meta.sol_in[113].sensor_type, "
        "expected 115, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[113].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[114].flags == 129,
        "incorrect value for last_msg.msg.soln_meta.sol_in[114].flags, "
        "expected 129, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[114].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[114].sensor_type == 152,
        "incorrect value for last_msg.msg.soln_meta.sol_in[114].sensor_type, "
        "expected 152, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[114].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[115].flags == 235,
        "incorrect value for last_msg.msg.soln_meta.sol_in[115].flags, "
        "expected 235, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[115].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[115].sensor_type == 234,
        "incorrect value for last_msg.msg.soln_meta.sol_in[115].sensor_type, "
        "expected 234, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[115].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[116].flags == 234,
        "incorrect value for last_msg.msg.soln_meta.sol_in[116].flags, "
        "expected 234, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[116].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[116].sensor_type == 194,
        "incorrect value for last_msg.msg.soln_meta.sol_in[116].sensor_type, "
        "expected 194, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[116].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[117].flags == 201,
        "incorrect value for last_msg.msg.soln_meta.sol_in[117].flags, "
        "expected 201, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[117].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[117].sensor_type == 170,
        "incorrect value for last_msg.msg.soln_meta.sol_in[117].sensor_type, "
        "expected 170, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[117].sensor_type);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[118].flags == 154,
        "incorrect value for last_msg.msg.soln_meta.sol_in[118].flags, "
        "expected 154, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[118].flags);

    ck_assert_msg(
        last_msg.msg.soln_meta.sol_in[118].sensor_type == 210,
        "incorrect value for last_msg.msg.soln_meta.sol_in[118].sensor_type, "
        "expected 210, is %" PRId64,
        (int64_t)last_msg.msg.soln_meta.sol_in[118].sensor_type);

    ck_assert_msg(last_msg.msg.soln_meta.tow == 3628191792,
                  "incorrect value for last_msg.msg.soln_meta.tow, expected "
                  "3628191792, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.tow);

    ck_assert_msg(last_msg.msg.soln_meta.vdop == 58512,
                  "incorrect value for last_msg.msg.soln_meta.vdop, expected "
                  "58512, is %" PRId64,
                  (int64_t)last_msg.msg.soln_meta.vdop);
  }
}
END_TEST

Suite *auto_check_sbp_solution_meta_MsgSolnMeta_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_solution_meta_MsgSolnMeta");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_solution_meta_MsgSolnMeta");
  tcase_add_test(tc_acq, test_auto_check_sbp_solution_meta_MsgSolnMeta);
  suite_add_tcase(s, tc_acq);
  return s;
}