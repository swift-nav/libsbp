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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrPhaseBiases.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/ssr.h>
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

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrPhaseBiases) {
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

    sbp_payload_callback_register(&sbp_state, 0x5e6, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x5e6, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  230, 5,   219, 206, 255, 209, 154, 144, 12,  213, 164, 169, 82,
        177, 230, 98,  209, 249, 22,  17,  29,  250, 245, 193, 219, 30,  212,
        177, 207, 187, 33,  146, 58,  204, 164, 65,  114, 49,  248, 52,  8,
        161, 44,  252, 166, 168, 232, 124, 134, 86,  173, 241, 174, 44,  142,
        155, 129, 143, 184, 161, 211, 15,  36,  189, 208, 194, 221, 152, 16,
        203, 87,  34,  188, 141, 104, 189, 102, 156, 252, 22,  251, 136, 49,
        188, 157, 222, 245, 49,  132, 16,  34,  142, 228, 85,  139, 221, 197,
        235, 98,  74,  107, 70,  36,  38,  239, 251, 112, 188, 124, 246, 141,
        164, 150, 104, 7,   213, 44,  21,  244, 192, 4,   143, 24,  42,  21,
        84,  136, 7,   42,  118, 45,  23,  174, 175, 129, 54,  169, 14,  213,
        2,   197, 98,  60,  13,  207, 105, 100, 129, 72,  136, 240, 140, 129,
        9,   114, 172, 151, 150, 17,  210, 127, 115, 151, 3,   242, 254, 215,
        14,  5,   34,  126, 2,   215, 65,  38,  176, 23,  210, 201, 97,  36,
        207, 92,  224, 26,  116, 155, 211, 165, 47,  102, 38,  67,  199, 55,
        117, 36,  169, 33,  1,   230, 201, 183, 21,  42,  62,  147, 173, 173,
        155, 98,  146, 231, 167, 138, 82,  167, 127, 229, 1,   2,   127, 237,
        207, 116, 90,  115, 159, 3,   42,  66,  145, 250, 201, 7,   251, 2,
        75,  230, 26,  213, 181, 56,  64,  97,  88,  255, 6,   147, 16,  89,
        203, 27,  68,  243, 230, 55,  242, 167, 169, 219, 240,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_phase_biases_t *test_msg =
        (msg_ssr_phase_biases_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[0].bias = -1311498533;
    test_msg->biases[0].code = 29;
    test_msg->biases[0].discontinuity_counter = 193;
    test_msg->biases[0].integer_indicator = 250;
    test_msg->biases[0].widelane_integer_indicator = 245;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[1].bias = 1101319226;
    test_msg->biases[1].code = 207;
    test_msg->biases[1].discontinuity_counter = 146;
    test_msg->biases[1].integer_indicator = 187;
    test_msg->biases[1].widelane_integer_indicator = 33;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[2].bias = -64184056;
    test_msg->biases[2].code = 114;
    test_msg->biases[2].discontinuity_counter = 52;
    test_msg->biases[2].integer_indicator = 49;
    test_msg->biases[2].widelane_integer_indicator = 248;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[3].bias = -240298362;
    test_msg->biases[3].code = 166;
    test_msg->biases[3].discontinuity_counter = 124;
    test_msg->biases[3].integer_indicator = 168;
    test_msg->biases[3].widelane_integer_indicator = 232;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[4].bias = -1581740159;
    test_msg->biases[4].code = 174;
    test_msg->biases[4].discontinuity_counter = 155;
    test_msg->biases[4].integer_indicator = 44;
    test_msg->biases[4].widelane_integer_indicator = 142;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[5].bias = -1730297136;
    test_msg->biases[5].code = 211;
    test_msg->biases[5].discontinuity_counter = 189;
    test_msg->biases[5].integer_indicator = 15;
    test_msg->biases[5].widelane_integer_indicator = 36;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[6].bias = -1117221444;
    test_msg->biases[6].code = 16;
    test_msg->biases[6].discontinuity_counter = 34;
    test_msg->biases[6].integer_indicator = 203;
    test_msg->biases[6].widelane_integer_indicator = 87;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[7].bias = -1137604357;
    test_msg->biases[7].code = 102;
    test_msg->biases[7].discontinuity_counter = 22;
    test_msg->biases[7].integer_indicator = 156;
    test_msg->biases[7].widelane_integer_indicator = 252;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[8].bias = -1910370172;
    test_msg->biases[8].code = 157;
    test_msg->biases[8].discontinuity_counter = 49;
    test_msg->biases[8].integer_indicator = 222;
    test_msg->biases[8].widelane_integer_indicator = 245;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[9].bias = 1247996869;
    test_msg->biases[9].code = 228;
    test_msg->biases[9].discontinuity_counter = 221;
    test_msg->biases[9].integer_indicator = 85;
    test_msg->biases[9].widelane_integer_indicator = 139;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[10].bias = -1133446161;
    test_msg->biases[10].code = 107;
    test_msg->biases[10].discontinuity_counter = 38;
    test_msg->biases[10].integer_indicator = 70;
    test_msg->biases[10].widelane_integer_indicator = 36;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[11].bias = -720934762;
    test_msg->biases[11].code = 124;
    test_msg->biases[11].discontinuity_counter = 164;
    test_msg->biases[11].integer_indicator = 246;
    test_msg->biases[11].widelane_integer_indicator = 141;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[12].bias = 706252548;
    test_msg->biases[12].code = 44;
    test_msg->biases[12].discontinuity_counter = 192;
    test_msg->biases[12].integer_indicator = 21;
    test_msg->biases[12].widelane_integer_indicator = 244;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[13].bias = 388855338;
    test_msg->biases[13].code = 21;
    test_msg->biases[13].discontinuity_counter = 7;
    test_msg->biases[13].integer_indicator = 84;
    test_msg->biases[13].widelane_integer_indicator = 136;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[14].bias = 47517353;
    test_msg->biases[14].code = 174;
    test_msg->biases[14].discontinuity_counter = 54;
    test_msg->biases[14].integer_indicator = 175;
    test_msg->biases[14].widelane_integer_indicator = 129;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[15].bias = -2124125745;
    test_msg->biases[15].code = 197;
    test_msg->biases[15].discontinuity_counter = 13;
    test_msg->biases[15].integer_indicator = 98;
    test_msg->biases[15].widelane_integer_indicator = 60;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[16].bias = -1401812607;
    test_msg->biases[16].code = 72;
    test_msg->biases[16].discontinuity_counter = 140;
    test_msg->biases[16].integer_indicator = 136;
    test_msg->biases[16].widelane_integer_indicator = 240;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[17].bias = 60257151;
    test_msg->biases[17].code = 151;
    test_msg->biases[17].discontinuity_counter = 210;
    test_msg->biases[17].integer_indicator = 150;
    test_msg->biases[17].widelane_integer_indicator = 17;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[18].bias = 41820677;
    test_msg->biases[18].code = 242;
    test_msg->biases[18].discontinuity_counter = 14;
    test_msg->biases[18].integer_indicator = 254;
    test_msg->biases[18].widelane_integer_indicator = 215;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[19].bias = 1640616471;
    test_msg->biases[19].code = 215;
    test_msg->biases[19].discontinuity_counter = 176;
    test_msg->biases[19].integer_indicator = 65;
    test_msg->biases[19].widelane_integer_indicator = 38;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[20].bias = -744786918;
    test_msg->biases[20].code = 36;
    test_msg->biases[20].discontinuity_counter = 224;
    test_msg->biases[20].integer_indicator = 207;
    test_msg->biases[20].widelane_integer_indicator = 92;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[21].bias = 1966589763;
    test_msg->biases[21].code = 165;
    test_msg->biases[21].discontinuity_counter = 38;
    test_msg->biases[21].integer_indicator = 47;
    test_msg->biases[21].widelane_integer_indicator = 102;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[22].bias = 364366310;
    test_msg->biases[22].code = 36;
    test_msg->biases[22].discontinuity_counter = 1;
    test_msg->biases[22].integer_indicator = 169;
    test_msg->biases[22].widelane_integer_indicator = 33;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[23].bias = -1839031379;
    test_msg->biases[23].code = 42;
    test_msg->biases[23].discontinuity_counter = 173;
    test_msg->biases[23].integer_indicator = 62;
    test_msg->biases[23].widelane_integer_indicator = 147;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[24].bias = 31817639;
    test_msg->biases[24].code = 231;
    test_msg->biases[24].discontinuity_counter = 82;
    test_msg->biases[24].integer_indicator = 167;
    test_msg->biases[24].widelane_integer_indicator = 138;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[25].bias = -1619830156;
    test_msg->biases[25].code = 2;
    test_msg->biases[25].discontinuity_counter = 207;
    test_msg->biases[25].integer_indicator = 127;
    test_msg->biases[25].widelane_integer_indicator = 237;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[26].bias = -83375622;
    test_msg->biases[26].code = 3;
    test_msg->biases[26].discontinuity_counter = 145;
    test_msg->biases[26].integer_indicator = 42;
    test_msg->biases[26].widelane_integer_indicator = 66;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[27].bias = 1077458389;
    test_msg->biases[27].code = 2;
    test_msg->biases[27].discontinuity_counter = 26;
    test_msg->biases[27].integer_indicator = 75;
    test_msg->biases[27].widelane_integer_indicator = 230;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[28].bias = -883355501;
    test_msg->biases[28].code = 97;
    test_msg->biases[28].discontinuity_counter = 6;
    test_msg->biases[28].integer_indicator = 88;
    test_msg->biases[28].widelane_integer_indicator = 255;
    if (sizeof(test_msg->biases) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->biases[0]);
    }
    test_msg->biases[29].bias = -1448611273;
    test_msg->biases[29].code = 27;
    test_msg->biases[29].discontinuity_counter = 230;
    test_msg->biases[29].integer_indicator = 68;
    test_msg->biases[29].widelane_integer_indicator = 243;
    test_msg->dispersive_bias = 98;
    test_msg->iod_ssr = 230;
    test_msg->mw_consistency = 209;
    test_msg->sid.code = 82;
    test_msg->sid.sat = 169;
    test_msg->time.tow = 210803409;
    test_msg->time.wn = 42197;
    test_msg->update_interval = 177;
    test_msg->yaw = 5881;
    test_msg->yaw_rate = 17;
    sbp_payload_send(&sbp_state, 0x5e6, 52955, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 52955,
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
    ck_assert_msg(last_frame.sender_id == 52955,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x5e6,
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
    msg_ssr_phase_biases_t *check_msg =
        (msg_ssr_phase_biases_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->biases[0].bias == -1311498533,
        "incorrect value for biases[0].bias, expected -1311498533, is %d",
        check_msg->biases[0].bias);
    ck_assert_msg(check_msg->biases[0].code == 29,
                  "incorrect value for biases[0].code, expected 29, is %d",
                  check_msg->biases[0].code);
    ck_assert_msg(check_msg->biases[0].discontinuity_counter == 193,
                  "incorrect value for biases[0].discontinuity_counter, "
                  "expected 193, is %d",
                  check_msg->biases[0].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[0].integer_indicator == 250,
        "incorrect value for biases[0].integer_indicator, expected 250, is %d",
        check_msg->biases[0].integer_indicator);
    ck_assert_msg(check_msg->biases[0].widelane_integer_indicator == 245,
                  "incorrect value for biases[0].widelane_integer_indicator, "
                  "expected 245, is %d",
                  check_msg->biases[0].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[1].bias == 1101319226,
        "incorrect value for biases[1].bias, expected 1101319226, is %d",
        check_msg->biases[1].bias);
    ck_assert_msg(check_msg->biases[1].code == 207,
                  "incorrect value for biases[1].code, expected 207, is %d",
                  check_msg->biases[1].code);
    ck_assert_msg(check_msg->biases[1].discontinuity_counter == 146,
                  "incorrect value for biases[1].discontinuity_counter, "
                  "expected 146, is %d",
                  check_msg->biases[1].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[1].integer_indicator == 187,
        "incorrect value for biases[1].integer_indicator, expected 187, is %d",
        check_msg->biases[1].integer_indicator);
    ck_assert_msg(check_msg->biases[1].widelane_integer_indicator == 33,
                  "incorrect value for biases[1].widelane_integer_indicator, "
                  "expected 33, is %d",
                  check_msg->biases[1].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[2].bias == -64184056,
        "incorrect value for biases[2].bias, expected -64184056, is %d",
        check_msg->biases[2].bias);
    ck_assert_msg(check_msg->biases[2].code == 114,
                  "incorrect value for biases[2].code, expected 114, is %d",
                  check_msg->biases[2].code);
    ck_assert_msg(check_msg->biases[2].discontinuity_counter == 52,
                  "incorrect value for biases[2].discontinuity_counter, "
                  "expected 52, is %d",
                  check_msg->biases[2].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[2].integer_indicator == 49,
        "incorrect value for biases[2].integer_indicator, expected 49, is %d",
        check_msg->biases[2].integer_indicator);
    ck_assert_msg(check_msg->biases[2].widelane_integer_indicator == 248,
                  "incorrect value for biases[2].widelane_integer_indicator, "
                  "expected 248, is %d",
                  check_msg->biases[2].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[3].bias == -240298362,
        "incorrect value for biases[3].bias, expected -240298362, is %d",
        check_msg->biases[3].bias);
    ck_assert_msg(check_msg->biases[3].code == 166,
                  "incorrect value for biases[3].code, expected 166, is %d",
                  check_msg->biases[3].code);
    ck_assert_msg(check_msg->biases[3].discontinuity_counter == 124,
                  "incorrect value for biases[3].discontinuity_counter, "
                  "expected 124, is %d",
                  check_msg->biases[3].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[3].integer_indicator == 168,
        "incorrect value for biases[3].integer_indicator, expected 168, is %d",
        check_msg->biases[3].integer_indicator);
    ck_assert_msg(check_msg->biases[3].widelane_integer_indicator == 232,
                  "incorrect value for biases[3].widelane_integer_indicator, "
                  "expected 232, is %d",
                  check_msg->biases[3].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[4].bias == -1581740159,
        "incorrect value for biases[4].bias, expected -1581740159, is %d",
        check_msg->biases[4].bias);
    ck_assert_msg(check_msg->biases[4].code == 174,
                  "incorrect value for biases[4].code, expected 174, is %d",
                  check_msg->biases[4].code);
    ck_assert_msg(check_msg->biases[4].discontinuity_counter == 155,
                  "incorrect value for biases[4].discontinuity_counter, "
                  "expected 155, is %d",
                  check_msg->biases[4].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[4].integer_indicator == 44,
        "incorrect value for biases[4].integer_indicator, expected 44, is %d",
        check_msg->biases[4].integer_indicator);
    ck_assert_msg(check_msg->biases[4].widelane_integer_indicator == 142,
                  "incorrect value for biases[4].widelane_integer_indicator, "
                  "expected 142, is %d",
                  check_msg->biases[4].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[5].bias == -1730297136,
        "incorrect value for biases[5].bias, expected -1730297136, is %d",
        check_msg->biases[5].bias);
    ck_assert_msg(check_msg->biases[5].code == 211,
                  "incorrect value for biases[5].code, expected 211, is %d",
                  check_msg->biases[5].code);
    ck_assert_msg(check_msg->biases[5].discontinuity_counter == 189,
                  "incorrect value for biases[5].discontinuity_counter, "
                  "expected 189, is %d",
                  check_msg->biases[5].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[5].integer_indicator == 15,
        "incorrect value for biases[5].integer_indicator, expected 15, is %d",
        check_msg->biases[5].integer_indicator);
    ck_assert_msg(check_msg->biases[5].widelane_integer_indicator == 36,
                  "incorrect value for biases[5].widelane_integer_indicator, "
                  "expected 36, is %d",
                  check_msg->biases[5].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[6].bias == -1117221444,
        "incorrect value for biases[6].bias, expected -1117221444, is %d",
        check_msg->biases[6].bias);
    ck_assert_msg(check_msg->biases[6].code == 16,
                  "incorrect value for biases[6].code, expected 16, is %d",
                  check_msg->biases[6].code);
    ck_assert_msg(check_msg->biases[6].discontinuity_counter == 34,
                  "incorrect value for biases[6].discontinuity_counter, "
                  "expected 34, is %d",
                  check_msg->biases[6].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[6].integer_indicator == 203,
        "incorrect value for biases[6].integer_indicator, expected 203, is %d",
        check_msg->biases[6].integer_indicator);
    ck_assert_msg(check_msg->biases[6].widelane_integer_indicator == 87,
                  "incorrect value for biases[6].widelane_integer_indicator, "
                  "expected 87, is %d",
                  check_msg->biases[6].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[7].bias == -1137604357,
        "incorrect value for biases[7].bias, expected -1137604357, is %d",
        check_msg->biases[7].bias);
    ck_assert_msg(check_msg->biases[7].code == 102,
                  "incorrect value for biases[7].code, expected 102, is %d",
                  check_msg->biases[7].code);
    ck_assert_msg(check_msg->biases[7].discontinuity_counter == 22,
                  "incorrect value for biases[7].discontinuity_counter, "
                  "expected 22, is %d",
                  check_msg->biases[7].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[7].integer_indicator == 156,
        "incorrect value for biases[7].integer_indicator, expected 156, is %d",
        check_msg->biases[7].integer_indicator);
    ck_assert_msg(check_msg->biases[7].widelane_integer_indicator == 252,
                  "incorrect value for biases[7].widelane_integer_indicator, "
                  "expected 252, is %d",
                  check_msg->biases[7].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[8].bias == -1910370172,
        "incorrect value for biases[8].bias, expected -1910370172, is %d",
        check_msg->biases[8].bias);
    ck_assert_msg(check_msg->biases[8].code == 157,
                  "incorrect value for biases[8].code, expected 157, is %d",
                  check_msg->biases[8].code);
    ck_assert_msg(check_msg->biases[8].discontinuity_counter == 49,
                  "incorrect value for biases[8].discontinuity_counter, "
                  "expected 49, is %d",
                  check_msg->biases[8].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[8].integer_indicator == 222,
        "incorrect value for biases[8].integer_indicator, expected 222, is %d",
        check_msg->biases[8].integer_indicator);
    ck_assert_msg(check_msg->biases[8].widelane_integer_indicator == 245,
                  "incorrect value for biases[8].widelane_integer_indicator, "
                  "expected 245, is %d",
                  check_msg->biases[8].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[9].bias == 1247996869,
        "incorrect value for biases[9].bias, expected 1247996869, is %d",
        check_msg->biases[9].bias);
    ck_assert_msg(check_msg->biases[9].code == 228,
                  "incorrect value for biases[9].code, expected 228, is %d",
                  check_msg->biases[9].code);
    ck_assert_msg(check_msg->biases[9].discontinuity_counter == 221,
                  "incorrect value for biases[9].discontinuity_counter, "
                  "expected 221, is %d",
                  check_msg->biases[9].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[9].integer_indicator == 85,
        "incorrect value for biases[9].integer_indicator, expected 85, is %d",
        check_msg->biases[9].integer_indicator);
    ck_assert_msg(check_msg->biases[9].widelane_integer_indicator == 139,
                  "incorrect value for biases[9].widelane_integer_indicator, "
                  "expected 139, is %d",
                  check_msg->biases[9].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[10].bias == -1133446161,
        "incorrect value for biases[10].bias, expected -1133446161, is %d",
        check_msg->biases[10].bias);
    ck_assert_msg(check_msg->biases[10].code == 107,
                  "incorrect value for biases[10].code, expected 107, is %d",
                  check_msg->biases[10].code);
    ck_assert_msg(check_msg->biases[10].discontinuity_counter == 38,
                  "incorrect value for biases[10].discontinuity_counter, "
                  "expected 38, is %d",
                  check_msg->biases[10].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[10].integer_indicator == 70,
        "incorrect value for biases[10].integer_indicator, expected 70, is %d",
        check_msg->biases[10].integer_indicator);
    ck_assert_msg(check_msg->biases[10].widelane_integer_indicator == 36,
                  "incorrect value for biases[10].widelane_integer_indicator, "
                  "expected 36, is %d",
                  check_msg->biases[10].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[11].bias == -720934762,
        "incorrect value for biases[11].bias, expected -720934762, is %d",
        check_msg->biases[11].bias);
    ck_assert_msg(check_msg->biases[11].code == 124,
                  "incorrect value for biases[11].code, expected 124, is %d",
                  check_msg->biases[11].code);
    ck_assert_msg(check_msg->biases[11].discontinuity_counter == 164,
                  "incorrect value for biases[11].discontinuity_counter, "
                  "expected 164, is %d",
                  check_msg->biases[11].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[11].integer_indicator == 246,
        "incorrect value for biases[11].integer_indicator, expected 246, is %d",
        check_msg->biases[11].integer_indicator);
    ck_assert_msg(check_msg->biases[11].widelane_integer_indicator == 141,
                  "incorrect value for biases[11].widelane_integer_indicator, "
                  "expected 141, is %d",
                  check_msg->biases[11].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[12].bias == 706252548,
        "incorrect value for biases[12].bias, expected 706252548, is %d",
        check_msg->biases[12].bias);
    ck_assert_msg(check_msg->biases[12].code == 44,
                  "incorrect value for biases[12].code, expected 44, is %d",
                  check_msg->biases[12].code);
    ck_assert_msg(check_msg->biases[12].discontinuity_counter == 192,
                  "incorrect value for biases[12].discontinuity_counter, "
                  "expected 192, is %d",
                  check_msg->biases[12].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[12].integer_indicator == 21,
        "incorrect value for biases[12].integer_indicator, expected 21, is %d",
        check_msg->biases[12].integer_indicator);
    ck_assert_msg(check_msg->biases[12].widelane_integer_indicator == 244,
                  "incorrect value for biases[12].widelane_integer_indicator, "
                  "expected 244, is %d",
                  check_msg->biases[12].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[13].bias == 388855338,
        "incorrect value for biases[13].bias, expected 388855338, is %d",
        check_msg->biases[13].bias);
    ck_assert_msg(check_msg->biases[13].code == 21,
                  "incorrect value for biases[13].code, expected 21, is %d",
                  check_msg->biases[13].code);
    ck_assert_msg(check_msg->biases[13].discontinuity_counter == 7,
                  "incorrect value for biases[13].discontinuity_counter, "
                  "expected 7, is %d",
                  check_msg->biases[13].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[13].integer_indicator == 84,
        "incorrect value for biases[13].integer_indicator, expected 84, is %d",
        check_msg->biases[13].integer_indicator);
    ck_assert_msg(check_msg->biases[13].widelane_integer_indicator == 136,
                  "incorrect value for biases[13].widelane_integer_indicator, "
                  "expected 136, is %d",
                  check_msg->biases[13].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[14].bias == 47517353,
        "incorrect value for biases[14].bias, expected 47517353, is %d",
        check_msg->biases[14].bias);
    ck_assert_msg(check_msg->biases[14].code == 174,
                  "incorrect value for biases[14].code, expected 174, is %d",
                  check_msg->biases[14].code);
    ck_assert_msg(check_msg->biases[14].discontinuity_counter == 54,
                  "incorrect value for biases[14].discontinuity_counter, "
                  "expected 54, is %d",
                  check_msg->biases[14].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[14].integer_indicator == 175,
        "incorrect value for biases[14].integer_indicator, expected 175, is %d",
        check_msg->biases[14].integer_indicator);
    ck_assert_msg(check_msg->biases[14].widelane_integer_indicator == 129,
                  "incorrect value for biases[14].widelane_integer_indicator, "
                  "expected 129, is %d",
                  check_msg->biases[14].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[15].bias == -2124125745,
        "incorrect value for biases[15].bias, expected -2124125745, is %d",
        check_msg->biases[15].bias);
    ck_assert_msg(check_msg->biases[15].code == 197,
                  "incorrect value for biases[15].code, expected 197, is %d",
                  check_msg->biases[15].code);
    ck_assert_msg(check_msg->biases[15].discontinuity_counter == 13,
                  "incorrect value for biases[15].discontinuity_counter, "
                  "expected 13, is %d",
                  check_msg->biases[15].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[15].integer_indicator == 98,
        "incorrect value for biases[15].integer_indicator, expected 98, is %d",
        check_msg->biases[15].integer_indicator);
    ck_assert_msg(check_msg->biases[15].widelane_integer_indicator == 60,
                  "incorrect value for biases[15].widelane_integer_indicator, "
                  "expected 60, is %d",
                  check_msg->biases[15].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[16].bias == -1401812607,
        "incorrect value for biases[16].bias, expected -1401812607, is %d",
        check_msg->biases[16].bias);
    ck_assert_msg(check_msg->biases[16].code == 72,
                  "incorrect value for biases[16].code, expected 72, is %d",
                  check_msg->biases[16].code);
    ck_assert_msg(check_msg->biases[16].discontinuity_counter == 140,
                  "incorrect value for biases[16].discontinuity_counter, "
                  "expected 140, is %d",
                  check_msg->biases[16].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[16].integer_indicator == 136,
        "incorrect value for biases[16].integer_indicator, expected 136, is %d",
        check_msg->biases[16].integer_indicator);
    ck_assert_msg(check_msg->biases[16].widelane_integer_indicator == 240,
                  "incorrect value for biases[16].widelane_integer_indicator, "
                  "expected 240, is %d",
                  check_msg->biases[16].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[17].bias == 60257151,
        "incorrect value for biases[17].bias, expected 60257151, is %d",
        check_msg->biases[17].bias);
    ck_assert_msg(check_msg->biases[17].code == 151,
                  "incorrect value for biases[17].code, expected 151, is %d",
                  check_msg->biases[17].code);
    ck_assert_msg(check_msg->biases[17].discontinuity_counter == 210,
                  "incorrect value for biases[17].discontinuity_counter, "
                  "expected 210, is %d",
                  check_msg->biases[17].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[17].integer_indicator == 150,
        "incorrect value for biases[17].integer_indicator, expected 150, is %d",
        check_msg->biases[17].integer_indicator);
    ck_assert_msg(check_msg->biases[17].widelane_integer_indicator == 17,
                  "incorrect value for biases[17].widelane_integer_indicator, "
                  "expected 17, is %d",
                  check_msg->biases[17].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[18].bias == 41820677,
        "incorrect value for biases[18].bias, expected 41820677, is %d",
        check_msg->biases[18].bias);
    ck_assert_msg(check_msg->biases[18].code == 242,
                  "incorrect value for biases[18].code, expected 242, is %d",
                  check_msg->biases[18].code);
    ck_assert_msg(check_msg->biases[18].discontinuity_counter == 14,
                  "incorrect value for biases[18].discontinuity_counter, "
                  "expected 14, is %d",
                  check_msg->biases[18].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[18].integer_indicator == 254,
        "incorrect value for biases[18].integer_indicator, expected 254, is %d",
        check_msg->biases[18].integer_indicator);
    ck_assert_msg(check_msg->biases[18].widelane_integer_indicator == 215,
                  "incorrect value for biases[18].widelane_integer_indicator, "
                  "expected 215, is %d",
                  check_msg->biases[18].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[19].bias == 1640616471,
        "incorrect value for biases[19].bias, expected 1640616471, is %d",
        check_msg->biases[19].bias);
    ck_assert_msg(check_msg->biases[19].code == 215,
                  "incorrect value for biases[19].code, expected 215, is %d",
                  check_msg->biases[19].code);
    ck_assert_msg(check_msg->biases[19].discontinuity_counter == 176,
                  "incorrect value for biases[19].discontinuity_counter, "
                  "expected 176, is %d",
                  check_msg->biases[19].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[19].integer_indicator == 65,
        "incorrect value for biases[19].integer_indicator, expected 65, is %d",
        check_msg->biases[19].integer_indicator);
    ck_assert_msg(check_msg->biases[19].widelane_integer_indicator == 38,
                  "incorrect value for biases[19].widelane_integer_indicator, "
                  "expected 38, is %d",
                  check_msg->biases[19].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[20].bias == -744786918,
        "incorrect value for biases[20].bias, expected -744786918, is %d",
        check_msg->biases[20].bias);
    ck_assert_msg(check_msg->biases[20].code == 36,
                  "incorrect value for biases[20].code, expected 36, is %d",
                  check_msg->biases[20].code);
    ck_assert_msg(check_msg->biases[20].discontinuity_counter == 224,
                  "incorrect value for biases[20].discontinuity_counter, "
                  "expected 224, is %d",
                  check_msg->biases[20].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[20].integer_indicator == 207,
        "incorrect value for biases[20].integer_indicator, expected 207, is %d",
        check_msg->biases[20].integer_indicator);
    ck_assert_msg(check_msg->biases[20].widelane_integer_indicator == 92,
                  "incorrect value for biases[20].widelane_integer_indicator, "
                  "expected 92, is %d",
                  check_msg->biases[20].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[21].bias == 1966589763,
        "incorrect value for biases[21].bias, expected 1966589763, is %d",
        check_msg->biases[21].bias);
    ck_assert_msg(check_msg->biases[21].code == 165,
                  "incorrect value for biases[21].code, expected 165, is %d",
                  check_msg->biases[21].code);
    ck_assert_msg(check_msg->biases[21].discontinuity_counter == 38,
                  "incorrect value for biases[21].discontinuity_counter, "
                  "expected 38, is %d",
                  check_msg->biases[21].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[21].integer_indicator == 47,
        "incorrect value for biases[21].integer_indicator, expected 47, is %d",
        check_msg->biases[21].integer_indicator);
    ck_assert_msg(check_msg->biases[21].widelane_integer_indicator == 102,
                  "incorrect value for biases[21].widelane_integer_indicator, "
                  "expected 102, is %d",
                  check_msg->biases[21].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[22].bias == 364366310,
        "incorrect value for biases[22].bias, expected 364366310, is %d",
        check_msg->biases[22].bias);
    ck_assert_msg(check_msg->biases[22].code == 36,
                  "incorrect value for biases[22].code, expected 36, is %d",
                  check_msg->biases[22].code);
    ck_assert_msg(check_msg->biases[22].discontinuity_counter == 1,
                  "incorrect value for biases[22].discontinuity_counter, "
                  "expected 1, is %d",
                  check_msg->biases[22].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[22].integer_indicator == 169,
        "incorrect value for biases[22].integer_indicator, expected 169, is %d",
        check_msg->biases[22].integer_indicator);
    ck_assert_msg(check_msg->biases[22].widelane_integer_indicator == 33,
                  "incorrect value for biases[22].widelane_integer_indicator, "
                  "expected 33, is %d",
                  check_msg->biases[22].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[23].bias == -1839031379,
        "incorrect value for biases[23].bias, expected -1839031379, is %d",
        check_msg->biases[23].bias);
    ck_assert_msg(check_msg->biases[23].code == 42,
                  "incorrect value for biases[23].code, expected 42, is %d",
                  check_msg->biases[23].code);
    ck_assert_msg(check_msg->biases[23].discontinuity_counter == 173,
                  "incorrect value for biases[23].discontinuity_counter, "
                  "expected 173, is %d",
                  check_msg->biases[23].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[23].integer_indicator == 62,
        "incorrect value for biases[23].integer_indicator, expected 62, is %d",
        check_msg->biases[23].integer_indicator);
    ck_assert_msg(check_msg->biases[23].widelane_integer_indicator == 147,
                  "incorrect value for biases[23].widelane_integer_indicator, "
                  "expected 147, is %d",
                  check_msg->biases[23].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[24].bias == 31817639,
        "incorrect value for biases[24].bias, expected 31817639, is %d",
        check_msg->biases[24].bias);
    ck_assert_msg(check_msg->biases[24].code == 231,
                  "incorrect value for biases[24].code, expected 231, is %d",
                  check_msg->biases[24].code);
    ck_assert_msg(check_msg->biases[24].discontinuity_counter == 82,
                  "incorrect value for biases[24].discontinuity_counter, "
                  "expected 82, is %d",
                  check_msg->biases[24].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[24].integer_indicator == 167,
        "incorrect value for biases[24].integer_indicator, expected 167, is %d",
        check_msg->biases[24].integer_indicator);
    ck_assert_msg(check_msg->biases[24].widelane_integer_indicator == 138,
                  "incorrect value for biases[24].widelane_integer_indicator, "
                  "expected 138, is %d",
                  check_msg->biases[24].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[25].bias == -1619830156,
        "incorrect value for biases[25].bias, expected -1619830156, is %d",
        check_msg->biases[25].bias);
    ck_assert_msg(check_msg->biases[25].code == 2,
                  "incorrect value for biases[25].code, expected 2, is %d",
                  check_msg->biases[25].code);
    ck_assert_msg(check_msg->biases[25].discontinuity_counter == 207,
                  "incorrect value for biases[25].discontinuity_counter, "
                  "expected 207, is %d",
                  check_msg->biases[25].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[25].integer_indicator == 127,
        "incorrect value for biases[25].integer_indicator, expected 127, is %d",
        check_msg->biases[25].integer_indicator);
    ck_assert_msg(check_msg->biases[25].widelane_integer_indicator == 237,
                  "incorrect value for biases[25].widelane_integer_indicator, "
                  "expected 237, is %d",
                  check_msg->biases[25].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[26].bias == -83375622,
        "incorrect value for biases[26].bias, expected -83375622, is %d",
        check_msg->biases[26].bias);
    ck_assert_msg(check_msg->biases[26].code == 3,
                  "incorrect value for biases[26].code, expected 3, is %d",
                  check_msg->biases[26].code);
    ck_assert_msg(check_msg->biases[26].discontinuity_counter == 145,
                  "incorrect value for biases[26].discontinuity_counter, "
                  "expected 145, is %d",
                  check_msg->biases[26].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[26].integer_indicator == 42,
        "incorrect value for biases[26].integer_indicator, expected 42, is %d",
        check_msg->biases[26].integer_indicator);
    ck_assert_msg(check_msg->biases[26].widelane_integer_indicator == 66,
                  "incorrect value for biases[26].widelane_integer_indicator, "
                  "expected 66, is %d",
                  check_msg->biases[26].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[27].bias == 1077458389,
        "incorrect value for biases[27].bias, expected 1077458389, is %d",
        check_msg->biases[27].bias);
    ck_assert_msg(check_msg->biases[27].code == 2,
                  "incorrect value for biases[27].code, expected 2, is %d",
                  check_msg->biases[27].code);
    ck_assert_msg(check_msg->biases[27].discontinuity_counter == 26,
                  "incorrect value for biases[27].discontinuity_counter, "
                  "expected 26, is %d",
                  check_msg->biases[27].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[27].integer_indicator == 75,
        "incorrect value for biases[27].integer_indicator, expected 75, is %d",
        check_msg->biases[27].integer_indicator);
    ck_assert_msg(check_msg->biases[27].widelane_integer_indicator == 230,
                  "incorrect value for biases[27].widelane_integer_indicator, "
                  "expected 230, is %d",
                  check_msg->biases[27].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[28].bias == -883355501,
        "incorrect value for biases[28].bias, expected -883355501, is %d",
        check_msg->biases[28].bias);
    ck_assert_msg(check_msg->biases[28].code == 97,
                  "incorrect value for biases[28].code, expected 97, is %d",
                  check_msg->biases[28].code);
    ck_assert_msg(check_msg->biases[28].discontinuity_counter == 6,
                  "incorrect value for biases[28].discontinuity_counter, "
                  "expected 6, is %d",
                  check_msg->biases[28].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[28].integer_indicator == 88,
        "incorrect value for biases[28].integer_indicator, expected 88, is %d",
        check_msg->biases[28].integer_indicator);
    ck_assert_msg(check_msg->biases[28].widelane_integer_indicator == 255,
                  "incorrect value for biases[28].widelane_integer_indicator, "
                  "expected 255, is %d",
                  check_msg->biases[28].widelane_integer_indicator);
    ck_assert_msg(
        check_msg->biases[29].bias == -1448611273,
        "incorrect value for biases[29].bias, expected -1448611273, is %d",
        check_msg->biases[29].bias);
    ck_assert_msg(check_msg->biases[29].code == 27,
                  "incorrect value for biases[29].code, expected 27, is %d",
                  check_msg->biases[29].code);
    ck_assert_msg(check_msg->biases[29].discontinuity_counter == 230,
                  "incorrect value for biases[29].discontinuity_counter, "
                  "expected 230, is %d",
                  check_msg->biases[29].discontinuity_counter);
    ck_assert_msg(
        check_msg->biases[29].integer_indicator == 68,
        "incorrect value for biases[29].integer_indicator, expected 68, is %d",
        check_msg->biases[29].integer_indicator);
    ck_assert_msg(check_msg->biases[29].widelane_integer_indicator == 243,
                  "incorrect value for biases[29].widelane_integer_indicator, "
                  "expected 243, is %d",
                  check_msg->biases[29].widelane_integer_indicator);
    ck_assert_msg(check_msg->dispersive_bias == 98,
                  "incorrect value for dispersive_bias, expected 98, is %d",
                  check_msg->dispersive_bias);
    ck_assert_msg(check_msg->iod_ssr == 230,
                  "incorrect value for iod_ssr, expected 230, is %d",
                  check_msg->iod_ssr);
    ck_assert_msg(check_msg->mw_consistency == 209,
                  "incorrect value for mw_consistency, expected 209, is %d",
                  check_msg->mw_consistency);
    ck_assert_msg(check_msg->sid.code == 82,
                  "incorrect value for sid.code, expected 82, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.sat == 169,
                  "incorrect value for sid.sat, expected 169, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->time.tow == 210803409,
                  "incorrect value for time.tow, expected 210803409, is %d",
                  check_msg->time.tow);
    ck_assert_msg(check_msg->time.wn == 42197,
                  "incorrect value for time.wn, expected 42197, is %d",
                  check_msg->time.wn);
    ck_assert_msg(check_msg->update_interval == 177,
                  "incorrect value for update_interval, expected 177, is %d",
                  check_msg->update_interval);
    ck_assert_msg(check_msg->yaw == 5881,
                  "incorrect value for yaw, expected 5881, is %d",
                  check_msg->yaw);
    ck_assert_msg(check_msg->yaw_rate == 17,
                  "incorrect value for yaw_rate, expected 17, is %d",
                  check_msg->yaw_rate);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrPhaseBiases_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_ssr_MsgSsrPhaseBiases");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrPhaseBiases");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_ssr_MsgSsrPhaseBiases);
  suite_add_tcase(s, tc_acq);
  return s;
}