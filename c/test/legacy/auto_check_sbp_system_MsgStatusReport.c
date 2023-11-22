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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusReport.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/system.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_system_MsgStatusReport) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

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

    sbp_payload_callback_register(&sbp_state, 0xfffe, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xfffe, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  254, 255, 6,   84,  252, 82,  253, 177, 95,  3,   60,  143, 90,
        233, 21,  208, 98,  247, 203, 221, 198, 156, 207, 217, 238, 162, 136,
        154, 11,  114, 236, 134, 235, 12,  133, 9,   30,  175, 145, 26,  114,
        215, 20,  146, 249, 54,  54,  133, 193, 106, 186, 210, 183, 0,   129,
        5,   248, 225, 149, 135, 127, 2,   26,  88,  92,  10,  103, 73,  3,
        103, 68,  76,  184, 33,  206, 194, 163, 123, 30,  151, 176, 149, 172,
        184, 231, 118, 230, 200, 168, 100, 109, 10,  233, 4,   60,  247, 82,
        215, 166, 28,  138, 110, 45,  98,  218, 244, 179, 126, 107, 92,  124,
        94,  157, 42,  187, 124, 6,   97,  247, 160, 188, 110, 120, 254, 214,
        110, 51,  240, 164, 147, 18,  74,  178, 67,  4,   27,  73,  190, 64,
        179, 146, 125, 153, 192, 46,  202, 66,  248, 46,  40,  161, 173, 242,
        214, 3,   11,  1,   118, 70,  162, 61,  178, 27,  156, 40,  191, 113,
        230, 200, 72,  8,   215, 245, 78,  59,  222, 250, 115, 32,  33,  30,
        211, 170, 145, 92,  157, 75,  24,  169, 6,   55,  62,  8,   107, 82,
        140, 49,  179, 122, 90,  71,  28,  88,  103, 51,  177, 72,  93,  39,
        148, 11,  202, 42,  34,  92,  204, 102, 29,  98,  249, 91,  134, 95,
        23,  248, 192, 20,  83,  195, 95,  180, 54,  36,  186, 75,  64,  20,
        157, 133, 12,  149, 28,  14,  185, 129, 101, 239, 74,  248, 245, 30,
        228, 88,  142, 212, 53,  224, 158, 166,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_status_report_t *test_msg = (msg_status_report_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->reporting_system = 64850;
    test_msg->sbp_version = 24497;
    test_msg->sequence = 1519336451;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[0].component = 52215;
    test_msg->status[0].generic = 221;
    test_msg->status[0].specific = 198;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[1].component = 53148;
    test_msg->status[1].generic = 217;
    test_msg->status[1].specific = 238;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[2].component = 34978;
    test_msg->status[2].generic = 154;
    test_msg->status[2].specific = 11;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[3].component = 60530;
    test_msg->status[3].generic = 134;
    test_msg->status[3].specific = 235;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[4].component = 34060;
    test_msg->status[4].generic = 9;
    test_msg->status[4].specific = 30;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[5].component = 37295;
    test_msg->status[5].generic = 26;
    test_msg->status[5].specific = 114;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[6].component = 5335;
    test_msg->status[6].generic = 146;
    test_msg->status[6].specific = 249;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[7].component = 13878;
    test_msg->status[7].generic = 133;
    test_msg->status[7].specific = 193;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[8].component = 47722;
    test_msg->status[8].generic = 210;
    test_msg->status[8].specific = 183;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[9].component = 33024;
    test_msg->status[9].generic = 5;
    test_msg->status[9].specific = 248;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[10].component = 38369;
    test_msg->status[10].generic = 135;
    test_msg->status[10].specific = 127;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[11].component = 6658;
    test_msg->status[11].generic = 88;
    test_msg->status[11].specific = 92;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[12].component = 26378;
    test_msg->status[12].generic = 73;
    test_msg->status[12].specific = 3;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[13].component = 17511;
    test_msg->status[13].generic = 76;
    test_msg->status[13].specific = 184;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[14].component = 52769;
    test_msg->status[14].generic = 194;
    test_msg->status[14].specific = 163;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[15].component = 7803;
    test_msg->status[15].generic = 151;
    test_msg->status[15].specific = 176;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[16].component = 44181;
    test_msg->status[16].generic = 184;
    test_msg->status[16].specific = 231;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[17].component = 58998;
    test_msg->status[17].generic = 200;
    test_msg->status[17].specific = 168;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[18].component = 28004;
    test_msg->status[18].generic = 10;
    test_msg->status[18].specific = 233;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[19].component = 15364;
    test_msg->status[19].generic = 247;
    test_msg->status[19].specific = 82;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[20].component = 42711;
    test_msg->status[20].generic = 28;
    test_msg->status[20].specific = 138;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[21].component = 11630;
    test_msg->status[21].generic = 98;
    test_msg->status[21].specific = 218;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[22].component = 46068;
    test_msg->status[22].generic = 126;
    test_msg->status[22].specific = 107;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[23].component = 31836;
    test_msg->status[23].generic = 94;
    test_msg->status[23].specific = 157;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[24].component = 47914;
    test_msg->status[24].generic = 124;
    test_msg->status[24].specific = 6;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[25].component = 63329;
    test_msg->status[25].generic = 160;
    test_msg->status[25].specific = 188;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[26].component = 30830;
    test_msg->status[26].generic = 254;
    test_msg->status[26].specific = 214;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[27].component = 13166;
    test_msg->status[27].generic = 240;
    test_msg->status[27].specific = 164;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[28].component = 4755;
    test_msg->status[28].generic = 74;
    test_msg->status[28].specific = 178;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[29].component = 1091;
    test_msg->status[29].generic = 27;
    test_msg->status[29].specific = 73;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[30].component = 16574;
    test_msg->status[30].generic = 179;
    test_msg->status[30].specific = 146;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[31].component = 39293;
    test_msg->status[31].generic = 192;
    test_msg->status[31].specific = 46;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[32].component = 17098;
    test_msg->status[32].generic = 248;
    test_msg->status[32].specific = 46;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[33].component = 41256;
    test_msg->status[33].generic = 173;
    test_msg->status[33].specific = 242;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[34].component = 982;
    test_msg->status[34].generic = 11;
    test_msg->status[34].specific = 1;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[35].component = 18038;
    test_msg->status[35].generic = 162;
    test_msg->status[35].specific = 61;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[36].component = 7090;
    test_msg->status[36].generic = 156;
    test_msg->status[36].specific = 40;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[37].component = 29119;
    test_msg->status[37].generic = 230;
    test_msg->status[37].specific = 200;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[38].component = 2120;
    test_msg->status[38].generic = 215;
    test_msg->status[38].specific = 245;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[39].component = 15182;
    test_msg->status[39].generic = 222;
    test_msg->status[39].specific = 250;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[40].component = 8307;
    test_msg->status[40].generic = 33;
    test_msg->status[40].specific = 30;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[41].component = 43731;
    test_msg->status[41].generic = 145;
    test_msg->status[41].specific = 92;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[42].component = 19357;
    test_msg->status[42].generic = 24;
    test_msg->status[42].specific = 169;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[43].component = 14086;
    test_msg->status[43].generic = 62;
    test_msg->status[43].specific = 8;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[44].component = 21099;
    test_msg->status[44].generic = 140;
    test_msg->status[44].specific = 49;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[45].component = 31411;
    test_msg->status[45].generic = 90;
    test_msg->status[45].specific = 71;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[46].component = 22556;
    test_msg->status[46].generic = 103;
    test_msg->status[46].specific = 51;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[47].component = 18609;
    test_msg->status[47].generic = 93;
    test_msg->status[47].specific = 39;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[48].component = 2964;
    test_msg->status[48].generic = 202;
    test_msg->status[48].specific = 42;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[49].component = 23586;
    test_msg->status[49].generic = 204;
    test_msg->status[49].specific = 102;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[50].component = 25117;
    test_msg->status[50].generic = 249;
    test_msg->status[50].specific = 91;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[51].component = 24454;
    test_msg->status[51].generic = 23;
    test_msg->status[51].specific = 248;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[52].component = 5312;
    test_msg->status[52].generic = 83;
    test_msg->status[52].specific = 195;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[53].component = 46175;
    test_msg->status[53].generic = 54;
    test_msg->status[53].specific = 36;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[54].component = 19386;
    test_msg->status[54].generic = 64;
    test_msg->status[54].specific = 20;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[55].component = 34205;
    test_msg->status[55].generic = 12;
    test_msg->status[55].specific = 149;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[56].component = 3612;
    test_msg->status[56].generic = 185;
    test_msg->status[56].specific = 129;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[57].component = 61285;
    test_msg->status[57].generic = 74;
    test_msg->status[57].specific = 248;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[58].component = 7925;
    test_msg->status[58].generic = 228;
    test_msg->status[58].specific = 88;
    if (sizeof(test_msg->status) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->status[0]);
    }
    test_msg->status[59].component = 54414;
    test_msg->status[59].generic = 53;
    test_msg->status[59].specific = 224;
    test_msg->uptime = 1657804265;
    sbp_payload_send(&sbp_state, 0xfffe, 21510, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 21510,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 21510,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xfffe,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_status_report_t *check_msg =
        (msg_status_report_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->reporting_system == 64850,
                  "incorrect value for reporting_system, expected 64850, is %d",
                  check_msg->reporting_system);
    ck_assert_msg(check_msg->sbp_version == 24497,
                  "incorrect value for sbp_version, expected 24497, is %d",
                  check_msg->sbp_version);
    ck_assert_msg(check_msg->sequence == 1519336451,
                  "incorrect value for sequence, expected 1519336451, is %d",
                  check_msg->sequence);
    ck_assert_msg(
        check_msg->status[0].component == 52215,
        "incorrect value for status[0].component, expected 52215, is %d",
        check_msg->status[0].component);
    ck_assert_msg(check_msg->status[0].generic == 221,
                  "incorrect value for status[0].generic, expected 221, is %d",
                  check_msg->status[0].generic);
    ck_assert_msg(check_msg->status[0].specific == 198,
                  "incorrect value for status[0].specific, expected 198, is %d",
                  check_msg->status[0].specific);
    ck_assert_msg(
        check_msg->status[1].component == 53148,
        "incorrect value for status[1].component, expected 53148, is %d",
        check_msg->status[1].component);
    ck_assert_msg(check_msg->status[1].generic == 217,
                  "incorrect value for status[1].generic, expected 217, is %d",
                  check_msg->status[1].generic);
    ck_assert_msg(check_msg->status[1].specific == 238,
                  "incorrect value for status[1].specific, expected 238, is %d",
                  check_msg->status[1].specific);
    ck_assert_msg(
        check_msg->status[2].component == 34978,
        "incorrect value for status[2].component, expected 34978, is %d",
        check_msg->status[2].component);
    ck_assert_msg(check_msg->status[2].generic == 154,
                  "incorrect value for status[2].generic, expected 154, is %d",
                  check_msg->status[2].generic);
    ck_assert_msg(check_msg->status[2].specific == 11,
                  "incorrect value for status[2].specific, expected 11, is %d",
                  check_msg->status[2].specific);
    ck_assert_msg(
        check_msg->status[3].component == 60530,
        "incorrect value for status[3].component, expected 60530, is %d",
        check_msg->status[3].component);
    ck_assert_msg(check_msg->status[3].generic == 134,
                  "incorrect value for status[3].generic, expected 134, is %d",
                  check_msg->status[3].generic);
    ck_assert_msg(check_msg->status[3].specific == 235,
                  "incorrect value for status[3].specific, expected 235, is %d",
                  check_msg->status[3].specific);
    ck_assert_msg(
        check_msg->status[4].component == 34060,
        "incorrect value for status[4].component, expected 34060, is %d",
        check_msg->status[4].component);
    ck_assert_msg(check_msg->status[4].generic == 9,
                  "incorrect value for status[4].generic, expected 9, is %d",
                  check_msg->status[4].generic);
    ck_assert_msg(check_msg->status[4].specific == 30,
                  "incorrect value for status[4].specific, expected 30, is %d",
                  check_msg->status[4].specific);
    ck_assert_msg(
        check_msg->status[5].component == 37295,
        "incorrect value for status[5].component, expected 37295, is %d",
        check_msg->status[5].component);
    ck_assert_msg(check_msg->status[5].generic == 26,
                  "incorrect value for status[5].generic, expected 26, is %d",
                  check_msg->status[5].generic);
    ck_assert_msg(check_msg->status[5].specific == 114,
                  "incorrect value for status[5].specific, expected 114, is %d",
                  check_msg->status[5].specific);
    ck_assert_msg(
        check_msg->status[6].component == 5335,
        "incorrect value for status[6].component, expected 5335, is %d",
        check_msg->status[6].component);
    ck_assert_msg(check_msg->status[6].generic == 146,
                  "incorrect value for status[6].generic, expected 146, is %d",
                  check_msg->status[6].generic);
    ck_assert_msg(check_msg->status[6].specific == 249,
                  "incorrect value for status[6].specific, expected 249, is %d",
                  check_msg->status[6].specific);
    ck_assert_msg(
        check_msg->status[7].component == 13878,
        "incorrect value for status[7].component, expected 13878, is %d",
        check_msg->status[7].component);
    ck_assert_msg(check_msg->status[7].generic == 133,
                  "incorrect value for status[7].generic, expected 133, is %d",
                  check_msg->status[7].generic);
    ck_assert_msg(check_msg->status[7].specific == 193,
                  "incorrect value for status[7].specific, expected 193, is %d",
                  check_msg->status[7].specific);
    ck_assert_msg(
        check_msg->status[8].component == 47722,
        "incorrect value for status[8].component, expected 47722, is %d",
        check_msg->status[8].component);
    ck_assert_msg(check_msg->status[8].generic == 210,
                  "incorrect value for status[8].generic, expected 210, is %d",
                  check_msg->status[8].generic);
    ck_assert_msg(check_msg->status[8].specific == 183,
                  "incorrect value for status[8].specific, expected 183, is %d",
                  check_msg->status[8].specific);
    ck_assert_msg(
        check_msg->status[9].component == 33024,
        "incorrect value for status[9].component, expected 33024, is %d",
        check_msg->status[9].component);
    ck_assert_msg(check_msg->status[9].generic == 5,
                  "incorrect value for status[9].generic, expected 5, is %d",
                  check_msg->status[9].generic);
    ck_assert_msg(check_msg->status[9].specific == 248,
                  "incorrect value for status[9].specific, expected 248, is %d",
                  check_msg->status[9].specific);
    ck_assert_msg(
        check_msg->status[10].component == 38369,
        "incorrect value for status[10].component, expected 38369, is %d",
        check_msg->status[10].component);
    ck_assert_msg(check_msg->status[10].generic == 135,
                  "incorrect value for status[10].generic, expected 135, is %d",
                  check_msg->status[10].generic);
    ck_assert_msg(
        check_msg->status[10].specific == 127,
        "incorrect value for status[10].specific, expected 127, is %d",
        check_msg->status[10].specific);
    ck_assert_msg(
        check_msg->status[11].component == 6658,
        "incorrect value for status[11].component, expected 6658, is %d",
        check_msg->status[11].component);
    ck_assert_msg(check_msg->status[11].generic == 88,
                  "incorrect value for status[11].generic, expected 88, is %d",
                  check_msg->status[11].generic);
    ck_assert_msg(check_msg->status[11].specific == 92,
                  "incorrect value for status[11].specific, expected 92, is %d",
                  check_msg->status[11].specific);
    ck_assert_msg(
        check_msg->status[12].component == 26378,
        "incorrect value for status[12].component, expected 26378, is %d",
        check_msg->status[12].component);
    ck_assert_msg(check_msg->status[12].generic == 73,
                  "incorrect value for status[12].generic, expected 73, is %d",
                  check_msg->status[12].generic);
    ck_assert_msg(check_msg->status[12].specific == 3,
                  "incorrect value for status[12].specific, expected 3, is %d",
                  check_msg->status[12].specific);
    ck_assert_msg(
        check_msg->status[13].component == 17511,
        "incorrect value for status[13].component, expected 17511, is %d",
        check_msg->status[13].component);
    ck_assert_msg(check_msg->status[13].generic == 76,
                  "incorrect value for status[13].generic, expected 76, is %d",
                  check_msg->status[13].generic);
    ck_assert_msg(
        check_msg->status[13].specific == 184,
        "incorrect value for status[13].specific, expected 184, is %d",
        check_msg->status[13].specific);
    ck_assert_msg(
        check_msg->status[14].component == 52769,
        "incorrect value for status[14].component, expected 52769, is %d",
        check_msg->status[14].component);
    ck_assert_msg(check_msg->status[14].generic == 194,
                  "incorrect value for status[14].generic, expected 194, is %d",
                  check_msg->status[14].generic);
    ck_assert_msg(
        check_msg->status[14].specific == 163,
        "incorrect value for status[14].specific, expected 163, is %d",
        check_msg->status[14].specific);
    ck_assert_msg(
        check_msg->status[15].component == 7803,
        "incorrect value for status[15].component, expected 7803, is %d",
        check_msg->status[15].component);
    ck_assert_msg(check_msg->status[15].generic == 151,
                  "incorrect value for status[15].generic, expected 151, is %d",
                  check_msg->status[15].generic);
    ck_assert_msg(
        check_msg->status[15].specific == 176,
        "incorrect value for status[15].specific, expected 176, is %d",
        check_msg->status[15].specific);
    ck_assert_msg(
        check_msg->status[16].component == 44181,
        "incorrect value for status[16].component, expected 44181, is %d",
        check_msg->status[16].component);
    ck_assert_msg(check_msg->status[16].generic == 184,
                  "incorrect value for status[16].generic, expected 184, is %d",
                  check_msg->status[16].generic);
    ck_assert_msg(
        check_msg->status[16].specific == 231,
        "incorrect value for status[16].specific, expected 231, is %d",
        check_msg->status[16].specific);
    ck_assert_msg(
        check_msg->status[17].component == 58998,
        "incorrect value for status[17].component, expected 58998, is %d",
        check_msg->status[17].component);
    ck_assert_msg(check_msg->status[17].generic == 200,
                  "incorrect value for status[17].generic, expected 200, is %d",
                  check_msg->status[17].generic);
    ck_assert_msg(
        check_msg->status[17].specific == 168,
        "incorrect value for status[17].specific, expected 168, is %d",
        check_msg->status[17].specific);
    ck_assert_msg(
        check_msg->status[18].component == 28004,
        "incorrect value for status[18].component, expected 28004, is %d",
        check_msg->status[18].component);
    ck_assert_msg(check_msg->status[18].generic == 10,
                  "incorrect value for status[18].generic, expected 10, is %d",
                  check_msg->status[18].generic);
    ck_assert_msg(
        check_msg->status[18].specific == 233,
        "incorrect value for status[18].specific, expected 233, is %d",
        check_msg->status[18].specific);
    ck_assert_msg(
        check_msg->status[19].component == 15364,
        "incorrect value for status[19].component, expected 15364, is %d",
        check_msg->status[19].component);
    ck_assert_msg(check_msg->status[19].generic == 247,
                  "incorrect value for status[19].generic, expected 247, is %d",
                  check_msg->status[19].generic);
    ck_assert_msg(check_msg->status[19].specific == 82,
                  "incorrect value for status[19].specific, expected 82, is %d",
                  check_msg->status[19].specific);
    ck_assert_msg(
        check_msg->status[20].component == 42711,
        "incorrect value for status[20].component, expected 42711, is %d",
        check_msg->status[20].component);
    ck_assert_msg(check_msg->status[20].generic == 28,
                  "incorrect value for status[20].generic, expected 28, is %d",
                  check_msg->status[20].generic);
    ck_assert_msg(
        check_msg->status[20].specific == 138,
        "incorrect value for status[20].specific, expected 138, is %d",
        check_msg->status[20].specific);
    ck_assert_msg(
        check_msg->status[21].component == 11630,
        "incorrect value for status[21].component, expected 11630, is %d",
        check_msg->status[21].component);
    ck_assert_msg(check_msg->status[21].generic == 98,
                  "incorrect value for status[21].generic, expected 98, is %d",
                  check_msg->status[21].generic);
    ck_assert_msg(
        check_msg->status[21].specific == 218,
        "incorrect value for status[21].specific, expected 218, is %d",
        check_msg->status[21].specific);
    ck_assert_msg(
        check_msg->status[22].component == 46068,
        "incorrect value for status[22].component, expected 46068, is %d",
        check_msg->status[22].component);
    ck_assert_msg(check_msg->status[22].generic == 126,
                  "incorrect value for status[22].generic, expected 126, is %d",
                  check_msg->status[22].generic);
    ck_assert_msg(
        check_msg->status[22].specific == 107,
        "incorrect value for status[22].specific, expected 107, is %d",
        check_msg->status[22].specific);
    ck_assert_msg(
        check_msg->status[23].component == 31836,
        "incorrect value for status[23].component, expected 31836, is %d",
        check_msg->status[23].component);
    ck_assert_msg(check_msg->status[23].generic == 94,
                  "incorrect value for status[23].generic, expected 94, is %d",
                  check_msg->status[23].generic);
    ck_assert_msg(
        check_msg->status[23].specific == 157,
        "incorrect value for status[23].specific, expected 157, is %d",
        check_msg->status[23].specific);
    ck_assert_msg(
        check_msg->status[24].component == 47914,
        "incorrect value for status[24].component, expected 47914, is %d",
        check_msg->status[24].component);
    ck_assert_msg(check_msg->status[24].generic == 124,
                  "incorrect value for status[24].generic, expected 124, is %d",
                  check_msg->status[24].generic);
    ck_assert_msg(check_msg->status[24].specific == 6,
                  "incorrect value for status[24].specific, expected 6, is %d",
                  check_msg->status[24].specific);
    ck_assert_msg(
        check_msg->status[25].component == 63329,
        "incorrect value for status[25].component, expected 63329, is %d",
        check_msg->status[25].component);
    ck_assert_msg(check_msg->status[25].generic == 160,
                  "incorrect value for status[25].generic, expected 160, is %d",
                  check_msg->status[25].generic);
    ck_assert_msg(
        check_msg->status[25].specific == 188,
        "incorrect value for status[25].specific, expected 188, is %d",
        check_msg->status[25].specific);
    ck_assert_msg(
        check_msg->status[26].component == 30830,
        "incorrect value for status[26].component, expected 30830, is %d",
        check_msg->status[26].component);
    ck_assert_msg(check_msg->status[26].generic == 254,
                  "incorrect value for status[26].generic, expected 254, is %d",
                  check_msg->status[26].generic);
    ck_assert_msg(
        check_msg->status[26].specific == 214,
        "incorrect value for status[26].specific, expected 214, is %d",
        check_msg->status[26].specific);
    ck_assert_msg(
        check_msg->status[27].component == 13166,
        "incorrect value for status[27].component, expected 13166, is %d",
        check_msg->status[27].component);
    ck_assert_msg(check_msg->status[27].generic == 240,
                  "incorrect value for status[27].generic, expected 240, is %d",
                  check_msg->status[27].generic);
    ck_assert_msg(
        check_msg->status[27].specific == 164,
        "incorrect value for status[27].specific, expected 164, is %d",
        check_msg->status[27].specific);
    ck_assert_msg(
        check_msg->status[28].component == 4755,
        "incorrect value for status[28].component, expected 4755, is %d",
        check_msg->status[28].component);
    ck_assert_msg(check_msg->status[28].generic == 74,
                  "incorrect value for status[28].generic, expected 74, is %d",
                  check_msg->status[28].generic);
    ck_assert_msg(
        check_msg->status[28].specific == 178,
        "incorrect value for status[28].specific, expected 178, is %d",
        check_msg->status[28].specific);
    ck_assert_msg(
        check_msg->status[29].component == 1091,
        "incorrect value for status[29].component, expected 1091, is %d",
        check_msg->status[29].component);
    ck_assert_msg(check_msg->status[29].generic == 27,
                  "incorrect value for status[29].generic, expected 27, is %d",
                  check_msg->status[29].generic);
    ck_assert_msg(check_msg->status[29].specific == 73,
                  "incorrect value for status[29].specific, expected 73, is %d",
                  check_msg->status[29].specific);
    ck_assert_msg(
        check_msg->status[30].component == 16574,
        "incorrect value for status[30].component, expected 16574, is %d",
        check_msg->status[30].component);
    ck_assert_msg(check_msg->status[30].generic == 179,
                  "incorrect value for status[30].generic, expected 179, is %d",
                  check_msg->status[30].generic);
    ck_assert_msg(
        check_msg->status[30].specific == 146,
        "incorrect value for status[30].specific, expected 146, is %d",
        check_msg->status[30].specific);
    ck_assert_msg(
        check_msg->status[31].component == 39293,
        "incorrect value for status[31].component, expected 39293, is %d",
        check_msg->status[31].component);
    ck_assert_msg(check_msg->status[31].generic == 192,
                  "incorrect value for status[31].generic, expected 192, is %d",
                  check_msg->status[31].generic);
    ck_assert_msg(check_msg->status[31].specific == 46,
                  "incorrect value for status[31].specific, expected 46, is %d",
                  check_msg->status[31].specific);
    ck_assert_msg(
        check_msg->status[32].component == 17098,
        "incorrect value for status[32].component, expected 17098, is %d",
        check_msg->status[32].component);
    ck_assert_msg(check_msg->status[32].generic == 248,
                  "incorrect value for status[32].generic, expected 248, is %d",
                  check_msg->status[32].generic);
    ck_assert_msg(check_msg->status[32].specific == 46,
                  "incorrect value for status[32].specific, expected 46, is %d",
                  check_msg->status[32].specific);
    ck_assert_msg(
        check_msg->status[33].component == 41256,
        "incorrect value for status[33].component, expected 41256, is %d",
        check_msg->status[33].component);
    ck_assert_msg(check_msg->status[33].generic == 173,
                  "incorrect value for status[33].generic, expected 173, is %d",
                  check_msg->status[33].generic);
    ck_assert_msg(
        check_msg->status[33].specific == 242,
        "incorrect value for status[33].specific, expected 242, is %d",
        check_msg->status[33].specific);
    ck_assert_msg(
        check_msg->status[34].component == 982,
        "incorrect value for status[34].component, expected 982, is %d",
        check_msg->status[34].component);
    ck_assert_msg(check_msg->status[34].generic == 11,
                  "incorrect value for status[34].generic, expected 11, is %d",
                  check_msg->status[34].generic);
    ck_assert_msg(check_msg->status[34].specific == 1,
                  "incorrect value for status[34].specific, expected 1, is %d",
                  check_msg->status[34].specific);
    ck_assert_msg(
        check_msg->status[35].component == 18038,
        "incorrect value for status[35].component, expected 18038, is %d",
        check_msg->status[35].component);
    ck_assert_msg(check_msg->status[35].generic == 162,
                  "incorrect value for status[35].generic, expected 162, is %d",
                  check_msg->status[35].generic);
    ck_assert_msg(check_msg->status[35].specific == 61,
                  "incorrect value for status[35].specific, expected 61, is %d",
                  check_msg->status[35].specific);
    ck_assert_msg(
        check_msg->status[36].component == 7090,
        "incorrect value for status[36].component, expected 7090, is %d",
        check_msg->status[36].component);
    ck_assert_msg(check_msg->status[36].generic == 156,
                  "incorrect value for status[36].generic, expected 156, is %d",
                  check_msg->status[36].generic);
    ck_assert_msg(check_msg->status[36].specific == 40,
                  "incorrect value for status[36].specific, expected 40, is %d",
                  check_msg->status[36].specific);
    ck_assert_msg(
        check_msg->status[37].component == 29119,
        "incorrect value for status[37].component, expected 29119, is %d",
        check_msg->status[37].component);
    ck_assert_msg(check_msg->status[37].generic == 230,
                  "incorrect value for status[37].generic, expected 230, is %d",
                  check_msg->status[37].generic);
    ck_assert_msg(
        check_msg->status[37].specific == 200,
        "incorrect value for status[37].specific, expected 200, is %d",
        check_msg->status[37].specific);
    ck_assert_msg(
        check_msg->status[38].component == 2120,
        "incorrect value for status[38].component, expected 2120, is %d",
        check_msg->status[38].component);
    ck_assert_msg(check_msg->status[38].generic == 215,
                  "incorrect value for status[38].generic, expected 215, is %d",
                  check_msg->status[38].generic);
    ck_assert_msg(
        check_msg->status[38].specific == 245,
        "incorrect value for status[38].specific, expected 245, is %d",
        check_msg->status[38].specific);
    ck_assert_msg(
        check_msg->status[39].component == 15182,
        "incorrect value for status[39].component, expected 15182, is %d",
        check_msg->status[39].component);
    ck_assert_msg(check_msg->status[39].generic == 222,
                  "incorrect value for status[39].generic, expected 222, is %d",
                  check_msg->status[39].generic);
    ck_assert_msg(
        check_msg->status[39].specific == 250,
        "incorrect value for status[39].specific, expected 250, is %d",
        check_msg->status[39].specific);
    ck_assert_msg(
        check_msg->status[40].component == 8307,
        "incorrect value for status[40].component, expected 8307, is %d",
        check_msg->status[40].component);
    ck_assert_msg(check_msg->status[40].generic == 33,
                  "incorrect value for status[40].generic, expected 33, is %d",
                  check_msg->status[40].generic);
    ck_assert_msg(check_msg->status[40].specific == 30,
                  "incorrect value for status[40].specific, expected 30, is %d",
                  check_msg->status[40].specific);
    ck_assert_msg(
        check_msg->status[41].component == 43731,
        "incorrect value for status[41].component, expected 43731, is %d",
        check_msg->status[41].component);
    ck_assert_msg(check_msg->status[41].generic == 145,
                  "incorrect value for status[41].generic, expected 145, is %d",
                  check_msg->status[41].generic);
    ck_assert_msg(check_msg->status[41].specific == 92,
                  "incorrect value for status[41].specific, expected 92, is %d",
                  check_msg->status[41].specific);
    ck_assert_msg(
        check_msg->status[42].component == 19357,
        "incorrect value for status[42].component, expected 19357, is %d",
        check_msg->status[42].component);
    ck_assert_msg(check_msg->status[42].generic == 24,
                  "incorrect value for status[42].generic, expected 24, is %d",
                  check_msg->status[42].generic);
    ck_assert_msg(
        check_msg->status[42].specific == 169,
        "incorrect value for status[42].specific, expected 169, is %d",
        check_msg->status[42].specific);
    ck_assert_msg(
        check_msg->status[43].component == 14086,
        "incorrect value for status[43].component, expected 14086, is %d",
        check_msg->status[43].component);
    ck_assert_msg(check_msg->status[43].generic == 62,
                  "incorrect value for status[43].generic, expected 62, is %d",
                  check_msg->status[43].generic);
    ck_assert_msg(check_msg->status[43].specific == 8,
                  "incorrect value for status[43].specific, expected 8, is %d",
                  check_msg->status[43].specific);
    ck_assert_msg(
        check_msg->status[44].component == 21099,
        "incorrect value for status[44].component, expected 21099, is %d",
        check_msg->status[44].component);
    ck_assert_msg(check_msg->status[44].generic == 140,
                  "incorrect value for status[44].generic, expected 140, is %d",
                  check_msg->status[44].generic);
    ck_assert_msg(check_msg->status[44].specific == 49,
                  "incorrect value for status[44].specific, expected 49, is %d",
                  check_msg->status[44].specific);
    ck_assert_msg(
        check_msg->status[45].component == 31411,
        "incorrect value for status[45].component, expected 31411, is %d",
        check_msg->status[45].component);
    ck_assert_msg(check_msg->status[45].generic == 90,
                  "incorrect value for status[45].generic, expected 90, is %d",
                  check_msg->status[45].generic);
    ck_assert_msg(check_msg->status[45].specific == 71,
                  "incorrect value for status[45].specific, expected 71, is %d",
                  check_msg->status[45].specific);
    ck_assert_msg(
        check_msg->status[46].component == 22556,
        "incorrect value for status[46].component, expected 22556, is %d",
        check_msg->status[46].component);
    ck_assert_msg(check_msg->status[46].generic == 103,
                  "incorrect value for status[46].generic, expected 103, is %d",
                  check_msg->status[46].generic);
    ck_assert_msg(check_msg->status[46].specific == 51,
                  "incorrect value for status[46].specific, expected 51, is %d",
                  check_msg->status[46].specific);
    ck_assert_msg(
        check_msg->status[47].component == 18609,
        "incorrect value for status[47].component, expected 18609, is %d",
        check_msg->status[47].component);
    ck_assert_msg(check_msg->status[47].generic == 93,
                  "incorrect value for status[47].generic, expected 93, is %d",
                  check_msg->status[47].generic);
    ck_assert_msg(check_msg->status[47].specific == 39,
                  "incorrect value for status[47].specific, expected 39, is %d",
                  check_msg->status[47].specific);
    ck_assert_msg(
        check_msg->status[48].component == 2964,
        "incorrect value for status[48].component, expected 2964, is %d",
        check_msg->status[48].component);
    ck_assert_msg(check_msg->status[48].generic == 202,
                  "incorrect value for status[48].generic, expected 202, is %d",
                  check_msg->status[48].generic);
    ck_assert_msg(check_msg->status[48].specific == 42,
                  "incorrect value for status[48].specific, expected 42, is %d",
                  check_msg->status[48].specific);
    ck_assert_msg(
        check_msg->status[49].component == 23586,
        "incorrect value for status[49].component, expected 23586, is %d",
        check_msg->status[49].component);
    ck_assert_msg(check_msg->status[49].generic == 204,
                  "incorrect value for status[49].generic, expected 204, is %d",
                  check_msg->status[49].generic);
    ck_assert_msg(
        check_msg->status[49].specific == 102,
        "incorrect value for status[49].specific, expected 102, is %d",
        check_msg->status[49].specific);
    ck_assert_msg(
        check_msg->status[50].component == 25117,
        "incorrect value for status[50].component, expected 25117, is %d",
        check_msg->status[50].component);
    ck_assert_msg(check_msg->status[50].generic == 249,
                  "incorrect value for status[50].generic, expected 249, is %d",
                  check_msg->status[50].generic);
    ck_assert_msg(check_msg->status[50].specific == 91,
                  "incorrect value for status[50].specific, expected 91, is %d",
                  check_msg->status[50].specific);
    ck_assert_msg(
        check_msg->status[51].component == 24454,
        "incorrect value for status[51].component, expected 24454, is %d",
        check_msg->status[51].component);
    ck_assert_msg(check_msg->status[51].generic == 23,
                  "incorrect value for status[51].generic, expected 23, is %d",
                  check_msg->status[51].generic);
    ck_assert_msg(
        check_msg->status[51].specific == 248,
        "incorrect value for status[51].specific, expected 248, is %d",
        check_msg->status[51].specific);
    ck_assert_msg(
        check_msg->status[52].component == 5312,
        "incorrect value for status[52].component, expected 5312, is %d",
        check_msg->status[52].component);
    ck_assert_msg(check_msg->status[52].generic == 83,
                  "incorrect value for status[52].generic, expected 83, is %d",
                  check_msg->status[52].generic);
    ck_assert_msg(
        check_msg->status[52].specific == 195,
        "incorrect value for status[52].specific, expected 195, is %d",
        check_msg->status[52].specific);
    ck_assert_msg(
        check_msg->status[53].component == 46175,
        "incorrect value for status[53].component, expected 46175, is %d",
        check_msg->status[53].component);
    ck_assert_msg(check_msg->status[53].generic == 54,
                  "incorrect value for status[53].generic, expected 54, is %d",
                  check_msg->status[53].generic);
    ck_assert_msg(check_msg->status[53].specific == 36,
                  "incorrect value for status[53].specific, expected 36, is %d",
                  check_msg->status[53].specific);
    ck_assert_msg(
        check_msg->status[54].component == 19386,
        "incorrect value for status[54].component, expected 19386, is %d",
        check_msg->status[54].component);
    ck_assert_msg(check_msg->status[54].generic == 64,
                  "incorrect value for status[54].generic, expected 64, is %d",
                  check_msg->status[54].generic);
    ck_assert_msg(check_msg->status[54].specific == 20,
                  "incorrect value for status[54].specific, expected 20, is %d",
                  check_msg->status[54].specific);
    ck_assert_msg(
        check_msg->status[55].component == 34205,
        "incorrect value for status[55].component, expected 34205, is %d",
        check_msg->status[55].component);
    ck_assert_msg(check_msg->status[55].generic == 12,
                  "incorrect value for status[55].generic, expected 12, is %d",
                  check_msg->status[55].generic);
    ck_assert_msg(
        check_msg->status[55].specific == 149,
        "incorrect value for status[55].specific, expected 149, is %d",
        check_msg->status[55].specific);
    ck_assert_msg(
        check_msg->status[56].component == 3612,
        "incorrect value for status[56].component, expected 3612, is %d",
        check_msg->status[56].component);
    ck_assert_msg(check_msg->status[56].generic == 185,
                  "incorrect value for status[56].generic, expected 185, is %d",
                  check_msg->status[56].generic);
    ck_assert_msg(
        check_msg->status[56].specific == 129,
        "incorrect value for status[56].specific, expected 129, is %d",
        check_msg->status[56].specific);
    ck_assert_msg(
        check_msg->status[57].component == 61285,
        "incorrect value for status[57].component, expected 61285, is %d",
        check_msg->status[57].component);
    ck_assert_msg(check_msg->status[57].generic == 74,
                  "incorrect value for status[57].generic, expected 74, is %d",
                  check_msg->status[57].generic);
    ck_assert_msg(
        check_msg->status[57].specific == 248,
        "incorrect value for status[57].specific, expected 248, is %d",
        check_msg->status[57].specific);
    ck_assert_msg(
        check_msg->status[58].component == 7925,
        "incorrect value for status[58].component, expected 7925, is %d",
        check_msg->status[58].component);
    ck_assert_msg(check_msg->status[58].generic == 228,
                  "incorrect value for status[58].generic, expected 228, is %d",
                  check_msg->status[58].generic);
    ck_assert_msg(check_msg->status[58].specific == 88,
                  "incorrect value for status[58].specific, expected 88, is %d",
                  check_msg->status[58].specific);
    ck_assert_msg(
        check_msg->status[59].component == 54414,
        "incorrect value for status[59].component, expected 54414, is %d",
        check_msg->status[59].component);
    ck_assert_msg(check_msg->status[59].generic == 53,
                  "incorrect value for status[59].generic, expected 53, is %d",
                  check_msg->status[59].generic);
    ck_assert_msg(
        check_msg->status[59].specific == 224,
        "incorrect value for status[59].specific, expected 224, is %d",
        check_msg->status[59].specific);
    ck_assert_msg(check_msg->uptime == 1657804265,
                  "incorrect value for uptime, expected 1657804265, is %d",
                  check_msg->uptime);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_system_MsgStatusReport_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_system_MsgStatusReport");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_system_MsgStatusReport");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_system_MsgStatusReport);
  suite_add_tcase(s, tc_acq);
  return s;
}