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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/legacy/tracking.h>

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void* context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void* context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8* buff, u32 n, void* context) {
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

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void* context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_tracking_MsgTrackingState) {
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

    sbp_payload_callback_register(&sbp_state, 0x41, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x41, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  65,  0,   55,  129, 252, 117, 184, 3,   102, 38,  106, 140, 141,
        25,  4,   90,  195, 246, 108, 75,  82,  137, 127, 45,  163, 32,  46,
        187, 93,  153, 60,  201, 147, 23,  29,  5,   208, 181, 30,  219, 69,
        254, 136, 3,   121, 33,  98,  144, 215, 133, 182, 14,  56,  169, 77,
        218, 62,  242, 84,  171, 249, 152, 137, 131, 130, 193, 21,  42,  68,
        253, 227, 216, 227, 24,  26,  210, 179, 19,  15,  227, 255, 122, 75,
        187, 200, 217, 48,  218, 122, 187, 238, 142, 149, 238, 55,  251, 212,
        128, 160, 194, 104, 113, 255, 141, 62,  43,  69,  245, 39,  100, 230,
        108, 56,  247, 68,  149, 143, 137, 101, 233, 70,  49,  165, 38,  110,
        218, 230, 80,  213, 196, 179, 139, 128, 15,  178, 196, 171, 8,   212,
        97,  194, 83,  233, 79,  99,  55,  90,  31,  180, 5,   25,  105, 186,
        22,  224, 80,  111, 8,   48,  106, 166, 4,   48,  156, 49,  86,  19,
        142, 146, 91,  124, 115, 64,  28,  230, 115, 178, 190, 131, 16,  242,
        105, 59,  182, 113, 192, 180, 48,  179, 166, 31,  172, 211, 77,  228,
        140, 49,  128, 77,  240, 194, 134, 194, 41,  58,  18,  53,  129, 55,
        91,  72,  134, 92,  33,  224, 157, 56,  186, 54,  224, 174, 82,  84,
        148, 190, 236, 54,  62,  67,  52,  215, 57,  254, 16,  133, 36,  174,
        219, 172, 145, 17,  192, 179, 111, 97,  207, 56,  208, 134, 180, 17,
        43,  226, 255, 182, 140, 113, 141, 111,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_t* test_msg = (msg_tracking_state_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 102;
    test_msg->states[0].fcn = 3;
    test_msg->states[0].sid.code = 184;
    test_msg->states[0].sid.sat = 117;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 141;
    test_msg->states[1].fcn = 140;
    test_msg->states[1].sid.code = 106;
    test_msg->states[1].sid.sat = 38;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 195;
    test_msg->states[2].fcn = 90;
    test_msg->states[2].sid.code = 4;
    test_msg->states[2].sid.sat = 25;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 82;
    test_msg->states[3].fcn = 75;
    test_msg->states[3].sid.code = 108;
    test_msg->states[3].sid.sat = 246;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 163;
    test_msg->states[4].fcn = 45;
    test_msg->states[4].sid.code = 127;
    test_msg->states[4].sid.sat = 137;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 93;
    test_msg->states[5].fcn = 187;
    test_msg->states[5].sid.code = 46;
    test_msg->states[5].sid.sat = 32;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 147;
    test_msg->states[6].fcn = 201;
    test_msg->states[6].sid.code = 60;
    test_msg->states[6].sid.sat = 153;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 208;
    test_msg->states[7].fcn = 5;
    test_msg->states[7].sid.code = 29;
    test_msg->states[7].sid.sat = 23;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 69;
    test_msg->states[8].fcn = 219;
    test_msg->states[8].sid.code = 30;
    test_msg->states[8].sid.sat = 181;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = 121;
    test_msg->states[9].fcn = 3;
    test_msg->states[9].sid.code = 136;
    test_msg->states[9].sid.sat = 254;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = 215;
    test_msg->states[10].fcn = 144;
    test_msg->states[10].sid.code = 98;
    test_msg->states[10].sid.sat = 33;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[11].cn0 = 56;
    test_msg->states[11].fcn = 14;
    test_msg->states[11].sid.code = 182;
    test_msg->states[11].sid.sat = 133;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[12].cn0 = 62;
    test_msg->states[12].fcn = 218;
    test_msg->states[12].sid.code = 77;
    test_msg->states[12].sid.sat = 169;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[13].cn0 = 249;
    test_msg->states[13].fcn = 171;
    test_msg->states[13].sid.code = 84;
    test_msg->states[13].sid.sat = 242;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[14].cn0 = 130;
    test_msg->states[14].fcn = 131;
    test_msg->states[14].sid.code = 137;
    test_msg->states[14].sid.sat = 152;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[15].cn0 = 68;
    test_msg->states[15].fcn = 42;
    test_msg->states[15].sid.code = 21;
    test_msg->states[15].sid.sat = 193;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[16].cn0 = 227;
    test_msg->states[16].fcn = 216;
    test_msg->states[16].sid.code = 227;
    test_msg->states[16].sid.sat = 253;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[17].cn0 = 179;
    test_msg->states[17].fcn = 210;
    test_msg->states[17].sid.code = 26;
    test_msg->states[17].sid.sat = 24;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[18].cn0 = 255;
    test_msg->states[18].fcn = 227;
    test_msg->states[18].sid.code = 15;
    test_msg->states[18].sid.sat = 19;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[19].cn0 = 200;
    test_msg->states[19].fcn = 187;
    test_msg->states[19].sid.code = 75;
    test_msg->states[19].sid.sat = 122;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[20].cn0 = 122;
    test_msg->states[20].fcn = 218;
    test_msg->states[20].sid.code = 48;
    test_msg->states[20].sid.sat = 217;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[21].cn0 = 149;
    test_msg->states[21].fcn = 142;
    test_msg->states[21].sid.code = 238;
    test_msg->states[21].sid.sat = 187;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[22].cn0 = 212;
    test_msg->states[22].fcn = 251;
    test_msg->states[22].sid.code = 55;
    test_msg->states[22].sid.sat = 238;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[23].cn0 = 104;
    test_msg->states[23].fcn = 194;
    test_msg->states[23].sid.code = 160;
    test_msg->states[23].sid.sat = 128;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[24].cn0 = 62;
    test_msg->states[24].fcn = 141;
    test_msg->states[24].sid.code = 255;
    test_msg->states[24].sid.sat = 113;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[25].cn0 = 39;
    test_msg->states[25].fcn = 245;
    test_msg->states[25].sid.code = 69;
    test_msg->states[25].sid.sat = 43;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[26].cn0 = 56;
    test_msg->states[26].fcn = 108;
    test_msg->states[26].sid.code = 230;
    test_msg->states[26].sid.sat = 100;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[27].cn0 = 143;
    test_msg->states[27].fcn = 149;
    test_msg->states[27].sid.code = 68;
    test_msg->states[27].sid.sat = 247;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[28].cn0 = 70;
    test_msg->states[28].fcn = 233;
    test_msg->states[28].sid.code = 101;
    test_msg->states[28].sid.sat = 137;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[29].cn0 = 110;
    test_msg->states[29].fcn = 38;
    test_msg->states[29].sid.code = 165;
    test_msg->states[29].sid.sat = 49;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[30].cn0 = 213;
    test_msg->states[30].fcn = 80;
    test_msg->states[30].sid.code = 230;
    test_msg->states[30].sid.sat = 218;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[31].cn0 = 128;
    test_msg->states[31].fcn = 139;
    test_msg->states[31].sid.code = 179;
    test_msg->states[31].sid.sat = 196;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[32].cn0 = 171;
    test_msg->states[32].fcn = 196;
    test_msg->states[32].sid.code = 178;
    test_msg->states[32].sid.sat = 15;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[33].cn0 = 194;
    test_msg->states[33].fcn = 97;
    test_msg->states[33].sid.code = 212;
    test_msg->states[33].sid.sat = 8;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[34].cn0 = 99;
    test_msg->states[34].fcn = 79;
    test_msg->states[34].sid.code = 233;
    test_msg->states[34].sid.sat = 83;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[35].cn0 = 180;
    test_msg->states[35].fcn = 31;
    test_msg->states[35].sid.code = 90;
    test_msg->states[35].sid.sat = 55;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[36].cn0 = 186;
    test_msg->states[36].fcn = 105;
    test_msg->states[36].sid.code = 25;
    test_msg->states[36].sid.sat = 5;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[37].cn0 = 111;
    test_msg->states[37].fcn = 80;
    test_msg->states[37].sid.code = 224;
    test_msg->states[37].sid.sat = 22;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[38].cn0 = 166;
    test_msg->states[38].fcn = 106;
    test_msg->states[38].sid.code = 48;
    test_msg->states[38].sid.sat = 8;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[39].cn0 = 49;
    test_msg->states[39].fcn = 156;
    test_msg->states[39].sid.code = 48;
    test_msg->states[39].sid.sat = 4;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[40].cn0 = 146;
    test_msg->states[40].fcn = 142;
    test_msg->states[40].sid.code = 19;
    test_msg->states[40].sid.sat = 86;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[41].cn0 = 64;
    test_msg->states[41].fcn = 115;
    test_msg->states[41].sid.code = 124;
    test_msg->states[41].sid.sat = 91;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[42].cn0 = 178;
    test_msg->states[42].fcn = 115;
    test_msg->states[42].sid.code = 230;
    test_msg->states[42].sid.sat = 28;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[43].cn0 = 242;
    test_msg->states[43].fcn = 16;
    test_msg->states[43].sid.code = 131;
    test_msg->states[43].sid.sat = 190;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[44].cn0 = 113;
    test_msg->states[44].fcn = 182;
    test_msg->states[44].sid.code = 59;
    test_msg->states[44].sid.sat = 105;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[45].cn0 = 179;
    test_msg->states[45].fcn = 48;
    test_msg->states[45].sid.code = 180;
    test_msg->states[45].sid.sat = 192;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[46].cn0 = 211;
    test_msg->states[46].fcn = 172;
    test_msg->states[46].sid.code = 31;
    test_msg->states[46].sid.sat = 166;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[47].cn0 = 49;
    test_msg->states[47].fcn = 140;
    test_msg->states[47].sid.code = 228;
    test_msg->states[47].sid.sat = 77;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[48].cn0 = 194;
    test_msg->states[48].fcn = 240;
    test_msg->states[48].sid.code = 77;
    test_msg->states[48].sid.sat = 128;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[49].cn0 = 58;
    test_msg->states[49].fcn = 41;
    test_msg->states[49].sid.code = 194;
    test_msg->states[49].sid.sat = 134;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[50].cn0 = 55;
    test_msg->states[50].fcn = 129;
    test_msg->states[50].sid.code = 53;
    test_msg->states[50].sid.sat = 18;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[51].cn0 = 92;
    test_msg->states[51].fcn = 134;
    test_msg->states[51].sid.code = 72;
    test_msg->states[51].sid.sat = 91;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[52].cn0 = 56;
    test_msg->states[52].fcn = 157;
    test_msg->states[52].sid.code = 224;
    test_msg->states[52].sid.sat = 33;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[53].cn0 = 174;
    test_msg->states[53].fcn = 224;
    test_msg->states[53].sid.code = 54;
    test_msg->states[53].sid.sat = 186;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[54].cn0 = 190;
    test_msg->states[54].fcn = 148;
    test_msg->states[54].sid.code = 84;
    test_msg->states[54].sid.sat = 82;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[55].cn0 = 67;
    test_msg->states[55].fcn = 62;
    test_msg->states[55].sid.code = 54;
    test_msg->states[55].sid.sat = 236;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[56].cn0 = 254;
    test_msg->states[56].fcn = 57;
    test_msg->states[56].sid.code = 215;
    test_msg->states[56].sid.sat = 52;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[57].cn0 = 174;
    test_msg->states[57].fcn = 36;
    test_msg->states[57].sid.code = 133;
    test_msg->states[57].sid.sat = 16;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[58].cn0 = 17;
    test_msg->states[58].fcn = 145;
    test_msg->states[58].sid.code = 172;
    test_msg->states[58].sid.sat = 219;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[59].cn0 = 97;
    test_msg->states[59].fcn = 111;
    test_msg->states[59].sid.code = 179;
    test_msg->states[59].sid.sat = 192;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[60].cn0 = 134;
    test_msg->states[60].fcn = 208;
    test_msg->states[60].sid.code = 56;
    test_msg->states[60].sid.sat = 207;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[61].cn0 = 226;
    test_msg->states[61].fcn = 43;
    test_msg->states[61].sid.code = 17;
    test_msg->states[61].sid.sat = 180;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[62].cn0 = 113;
    test_msg->states[62].fcn = 140;
    test_msg->states[62].sid.code = 182;
    test_msg->states[62].sid.sat = 255;
    sbp_payload_send(&sbp_state, 0x41, 33079, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 33079,
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
    ck_assert_msg(last_frame.sender_id == 33079,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x41,
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
    msg_tracking_state_t* check_msg =
        (msg_tracking_state_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->states[0].cn0 == 102,
                  "incorrect value for states[0].cn0, expected 102, is %d",
                  check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].fcn == 3,
                  "incorrect value for states[0].fcn, expected 3, is %d",
                  check_msg->states[0].fcn);
    ck_assert_msg(check_msg->states[0].sid.code == 184,
                  "incorrect value for states[0].sid.code, expected 184, is %d",
                  check_msg->states[0].sid.code);
    ck_assert_msg(check_msg->states[0].sid.sat == 117,
                  "incorrect value for states[0].sid.sat, expected 117, is %d",
                  check_msg->states[0].sid.sat);
    ck_assert_msg(check_msg->states[1].cn0 == 141,
                  "incorrect value for states[1].cn0, expected 141, is %d",
                  check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].fcn == 140,
                  "incorrect value for states[1].fcn, expected 140, is %d",
                  check_msg->states[1].fcn);
    ck_assert_msg(check_msg->states[1].sid.code == 106,
                  "incorrect value for states[1].sid.code, expected 106, is %d",
                  check_msg->states[1].sid.code);
    ck_assert_msg(check_msg->states[1].sid.sat == 38,
                  "incorrect value for states[1].sid.sat, expected 38, is %d",
                  check_msg->states[1].sid.sat);
    ck_assert_msg(check_msg->states[2].cn0 == 195,
                  "incorrect value for states[2].cn0, expected 195, is %d",
                  check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].fcn == 90,
                  "incorrect value for states[2].fcn, expected 90, is %d",
                  check_msg->states[2].fcn);
    ck_assert_msg(check_msg->states[2].sid.code == 4,
                  "incorrect value for states[2].sid.code, expected 4, is %d",
                  check_msg->states[2].sid.code);
    ck_assert_msg(check_msg->states[2].sid.sat == 25,
                  "incorrect value for states[2].sid.sat, expected 25, is %d",
                  check_msg->states[2].sid.sat);
    ck_assert_msg(check_msg->states[3].cn0 == 82,
                  "incorrect value for states[3].cn0, expected 82, is %d",
                  check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].fcn == 75,
                  "incorrect value for states[3].fcn, expected 75, is %d",
                  check_msg->states[3].fcn);
    ck_assert_msg(check_msg->states[3].sid.code == 108,
                  "incorrect value for states[3].sid.code, expected 108, is %d",
                  check_msg->states[3].sid.code);
    ck_assert_msg(check_msg->states[3].sid.sat == 246,
                  "incorrect value for states[3].sid.sat, expected 246, is %d",
                  check_msg->states[3].sid.sat);
    ck_assert_msg(check_msg->states[4].cn0 == 163,
                  "incorrect value for states[4].cn0, expected 163, is %d",
                  check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].fcn == 45,
                  "incorrect value for states[4].fcn, expected 45, is %d",
                  check_msg->states[4].fcn);
    ck_assert_msg(check_msg->states[4].sid.code == 127,
                  "incorrect value for states[4].sid.code, expected 127, is %d",
                  check_msg->states[4].sid.code);
    ck_assert_msg(check_msg->states[4].sid.sat == 137,
                  "incorrect value for states[4].sid.sat, expected 137, is %d",
                  check_msg->states[4].sid.sat);
    ck_assert_msg(check_msg->states[5].cn0 == 93,
                  "incorrect value for states[5].cn0, expected 93, is %d",
                  check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].fcn == 187,
                  "incorrect value for states[5].fcn, expected 187, is %d",
                  check_msg->states[5].fcn);
    ck_assert_msg(check_msg->states[5].sid.code == 46,
                  "incorrect value for states[5].sid.code, expected 46, is %d",
                  check_msg->states[5].sid.code);
    ck_assert_msg(check_msg->states[5].sid.sat == 32,
                  "incorrect value for states[5].sid.sat, expected 32, is %d",
                  check_msg->states[5].sid.sat);
    ck_assert_msg(check_msg->states[6].cn0 == 147,
                  "incorrect value for states[6].cn0, expected 147, is %d",
                  check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].fcn == 201,
                  "incorrect value for states[6].fcn, expected 201, is %d",
                  check_msg->states[6].fcn);
    ck_assert_msg(check_msg->states[6].sid.code == 60,
                  "incorrect value for states[6].sid.code, expected 60, is %d",
                  check_msg->states[6].sid.code);
    ck_assert_msg(check_msg->states[6].sid.sat == 153,
                  "incorrect value for states[6].sid.sat, expected 153, is %d",
                  check_msg->states[6].sid.sat);
    ck_assert_msg(check_msg->states[7].cn0 == 208,
                  "incorrect value for states[7].cn0, expected 208, is %d",
                  check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].fcn == 5,
                  "incorrect value for states[7].fcn, expected 5, is %d",
                  check_msg->states[7].fcn);
    ck_assert_msg(check_msg->states[7].sid.code == 29,
                  "incorrect value for states[7].sid.code, expected 29, is %d",
                  check_msg->states[7].sid.code);
    ck_assert_msg(check_msg->states[7].sid.sat == 23,
                  "incorrect value for states[7].sid.sat, expected 23, is %d",
                  check_msg->states[7].sid.sat);
    ck_assert_msg(check_msg->states[8].cn0 == 69,
                  "incorrect value for states[8].cn0, expected 69, is %d",
                  check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].fcn == 219,
                  "incorrect value for states[8].fcn, expected 219, is %d",
                  check_msg->states[8].fcn);
    ck_assert_msg(check_msg->states[8].sid.code == 30,
                  "incorrect value for states[8].sid.code, expected 30, is %d",
                  check_msg->states[8].sid.code);
    ck_assert_msg(check_msg->states[8].sid.sat == 181,
                  "incorrect value for states[8].sid.sat, expected 181, is %d",
                  check_msg->states[8].sid.sat);
    ck_assert_msg(check_msg->states[9].cn0 == 121,
                  "incorrect value for states[9].cn0, expected 121, is %d",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].fcn == 3,
                  "incorrect value for states[9].fcn, expected 3, is %d",
                  check_msg->states[9].fcn);
    ck_assert_msg(check_msg->states[9].sid.code == 136,
                  "incorrect value for states[9].sid.code, expected 136, is %d",
                  check_msg->states[9].sid.code);
    ck_assert_msg(check_msg->states[9].sid.sat == 254,
                  "incorrect value for states[9].sid.sat, expected 254, is %d",
                  check_msg->states[9].sid.sat);
    ck_assert_msg(check_msg->states[10].cn0 == 215,
                  "incorrect value for states[10].cn0, expected 215, is %d",
                  check_msg->states[10].cn0);
    ck_assert_msg(check_msg->states[10].fcn == 144,
                  "incorrect value for states[10].fcn, expected 144, is %d",
                  check_msg->states[10].fcn);
    ck_assert_msg(check_msg->states[10].sid.code == 98,
                  "incorrect value for states[10].sid.code, expected 98, is %d",
                  check_msg->states[10].sid.code);
    ck_assert_msg(check_msg->states[10].sid.sat == 33,
                  "incorrect value for states[10].sid.sat, expected 33, is %d",
                  check_msg->states[10].sid.sat);
    ck_assert_msg(check_msg->states[11].cn0 == 56,
                  "incorrect value for states[11].cn0, expected 56, is %d",
                  check_msg->states[11].cn0);
    ck_assert_msg(check_msg->states[11].fcn == 14,
                  "incorrect value for states[11].fcn, expected 14, is %d",
                  check_msg->states[11].fcn);
    ck_assert_msg(
        check_msg->states[11].sid.code == 182,
        "incorrect value for states[11].sid.code, expected 182, is %d",
        check_msg->states[11].sid.code);
    ck_assert_msg(check_msg->states[11].sid.sat == 133,
                  "incorrect value for states[11].sid.sat, expected 133, is %d",
                  check_msg->states[11].sid.sat);
    ck_assert_msg(check_msg->states[12].cn0 == 62,
                  "incorrect value for states[12].cn0, expected 62, is %d",
                  check_msg->states[12].cn0);
    ck_assert_msg(check_msg->states[12].fcn == 218,
                  "incorrect value for states[12].fcn, expected 218, is %d",
                  check_msg->states[12].fcn);
    ck_assert_msg(check_msg->states[12].sid.code == 77,
                  "incorrect value for states[12].sid.code, expected 77, is %d",
                  check_msg->states[12].sid.code);
    ck_assert_msg(check_msg->states[12].sid.sat == 169,
                  "incorrect value for states[12].sid.sat, expected 169, is %d",
                  check_msg->states[12].sid.sat);
    ck_assert_msg(check_msg->states[13].cn0 == 249,
                  "incorrect value for states[13].cn0, expected 249, is %d",
                  check_msg->states[13].cn0);
    ck_assert_msg(check_msg->states[13].fcn == 171,
                  "incorrect value for states[13].fcn, expected 171, is %d",
                  check_msg->states[13].fcn);
    ck_assert_msg(check_msg->states[13].sid.code == 84,
                  "incorrect value for states[13].sid.code, expected 84, is %d",
                  check_msg->states[13].sid.code);
    ck_assert_msg(check_msg->states[13].sid.sat == 242,
                  "incorrect value for states[13].sid.sat, expected 242, is %d",
                  check_msg->states[13].sid.sat);
    ck_assert_msg(check_msg->states[14].cn0 == 130,
                  "incorrect value for states[14].cn0, expected 130, is %d",
                  check_msg->states[14].cn0);
    ck_assert_msg(check_msg->states[14].fcn == 131,
                  "incorrect value for states[14].fcn, expected 131, is %d",
                  check_msg->states[14].fcn);
    ck_assert_msg(
        check_msg->states[14].sid.code == 137,
        "incorrect value for states[14].sid.code, expected 137, is %d",
        check_msg->states[14].sid.code);
    ck_assert_msg(check_msg->states[14].sid.sat == 152,
                  "incorrect value for states[14].sid.sat, expected 152, is %d",
                  check_msg->states[14].sid.sat);
    ck_assert_msg(check_msg->states[15].cn0 == 68,
                  "incorrect value for states[15].cn0, expected 68, is %d",
                  check_msg->states[15].cn0);
    ck_assert_msg(check_msg->states[15].fcn == 42,
                  "incorrect value for states[15].fcn, expected 42, is %d",
                  check_msg->states[15].fcn);
    ck_assert_msg(check_msg->states[15].sid.code == 21,
                  "incorrect value for states[15].sid.code, expected 21, is %d",
                  check_msg->states[15].sid.code);
    ck_assert_msg(check_msg->states[15].sid.sat == 193,
                  "incorrect value for states[15].sid.sat, expected 193, is %d",
                  check_msg->states[15].sid.sat);
    ck_assert_msg(check_msg->states[16].cn0 == 227,
                  "incorrect value for states[16].cn0, expected 227, is %d",
                  check_msg->states[16].cn0);
    ck_assert_msg(check_msg->states[16].fcn == 216,
                  "incorrect value for states[16].fcn, expected 216, is %d",
                  check_msg->states[16].fcn);
    ck_assert_msg(
        check_msg->states[16].sid.code == 227,
        "incorrect value for states[16].sid.code, expected 227, is %d",
        check_msg->states[16].sid.code);
    ck_assert_msg(check_msg->states[16].sid.sat == 253,
                  "incorrect value for states[16].sid.sat, expected 253, is %d",
                  check_msg->states[16].sid.sat);
    ck_assert_msg(check_msg->states[17].cn0 == 179,
                  "incorrect value for states[17].cn0, expected 179, is %d",
                  check_msg->states[17].cn0);
    ck_assert_msg(check_msg->states[17].fcn == 210,
                  "incorrect value for states[17].fcn, expected 210, is %d",
                  check_msg->states[17].fcn);
    ck_assert_msg(check_msg->states[17].sid.code == 26,
                  "incorrect value for states[17].sid.code, expected 26, is %d",
                  check_msg->states[17].sid.code);
    ck_assert_msg(check_msg->states[17].sid.sat == 24,
                  "incorrect value for states[17].sid.sat, expected 24, is %d",
                  check_msg->states[17].sid.sat);
    ck_assert_msg(check_msg->states[18].cn0 == 255,
                  "incorrect value for states[18].cn0, expected 255, is %d",
                  check_msg->states[18].cn0);
    ck_assert_msg(check_msg->states[18].fcn == 227,
                  "incorrect value for states[18].fcn, expected 227, is %d",
                  check_msg->states[18].fcn);
    ck_assert_msg(check_msg->states[18].sid.code == 15,
                  "incorrect value for states[18].sid.code, expected 15, is %d",
                  check_msg->states[18].sid.code);
    ck_assert_msg(check_msg->states[18].sid.sat == 19,
                  "incorrect value for states[18].sid.sat, expected 19, is %d",
                  check_msg->states[18].sid.sat);
    ck_assert_msg(check_msg->states[19].cn0 == 200,
                  "incorrect value for states[19].cn0, expected 200, is %d",
                  check_msg->states[19].cn0);
    ck_assert_msg(check_msg->states[19].fcn == 187,
                  "incorrect value for states[19].fcn, expected 187, is %d",
                  check_msg->states[19].fcn);
    ck_assert_msg(check_msg->states[19].sid.code == 75,
                  "incorrect value for states[19].sid.code, expected 75, is %d",
                  check_msg->states[19].sid.code);
    ck_assert_msg(check_msg->states[19].sid.sat == 122,
                  "incorrect value for states[19].sid.sat, expected 122, is %d",
                  check_msg->states[19].sid.sat);
    ck_assert_msg(check_msg->states[20].cn0 == 122,
                  "incorrect value for states[20].cn0, expected 122, is %d",
                  check_msg->states[20].cn0);
    ck_assert_msg(check_msg->states[20].fcn == 218,
                  "incorrect value for states[20].fcn, expected 218, is %d",
                  check_msg->states[20].fcn);
    ck_assert_msg(check_msg->states[20].sid.code == 48,
                  "incorrect value for states[20].sid.code, expected 48, is %d",
                  check_msg->states[20].sid.code);
    ck_assert_msg(check_msg->states[20].sid.sat == 217,
                  "incorrect value for states[20].sid.sat, expected 217, is %d",
                  check_msg->states[20].sid.sat);
    ck_assert_msg(check_msg->states[21].cn0 == 149,
                  "incorrect value for states[21].cn0, expected 149, is %d",
                  check_msg->states[21].cn0);
    ck_assert_msg(check_msg->states[21].fcn == 142,
                  "incorrect value for states[21].fcn, expected 142, is %d",
                  check_msg->states[21].fcn);
    ck_assert_msg(
        check_msg->states[21].sid.code == 238,
        "incorrect value for states[21].sid.code, expected 238, is %d",
        check_msg->states[21].sid.code);
    ck_assert_msg(check_msg->states[21].sid.sat == 187,
                  "incorrect value for states[21].sid.sat, expected 187, is %d",
                  check_msg->states[21].sid.sat);
    ck_assert_msg(check_msg->states[22].cn0 == 212,
                  "incorrect value for states[22].cn0, expected 212, is %d",
                  check_msg->states[22].cn0);
    ck_assert_msg(check_msg->states[22].fcn == 251,
                  "incorrect value for states[22].fcn, expected 251, is %d",
                  check_msg->states[22].fcn);
    ck_assert_msg(check_msg->states[22].sid.code == 55,
                  "incorrect value for states[22].sid.code, expected 55, is %d",
                  check_msg->states[22].sid.code);
    ck_assert_msg(check_msg->states[22].sid.sat == 238,
                  "incorrect value for states[22].sid.sat, expected 238, is %d",
                  check_msg->states[22].sid.sat);
    ck_assert_msg(check_msg->states[23].cn0 == 104,
                  "incorrect value for states[23].cn0, expected 104, is %d",
                  check_msg->states[23].cn0);
    ck_assert_msg(check_msg->states[23].fcn == 194,
                  "incorrect value for states[23].fcn, expected 194, is %d",
                  check_msg->states[23].fcn);
    ck_assert_msg(
        check_msg->states[23].sid.code == 160,
        "incorrect value for states[23].sid.code, expected 160, is %d",
        check_msg->states[23].sid.code);
    ck_assert_msg(check_msg->states[23].sid.sat == 128,
                  "incorrect value for states[23].sid.sat, expected 128, is %d",
                  check_msg->states[23].sid.sat);
    ck_assert_msg(check_msg->states[24].cn0 == 62,
                  "incorrect value for states[24].cn0, expected 62, is %d",
                  check_msg->states[24].cn0);
    ck_assert_msg(check_msg->states[24].fcn == 141,
                  "incorrect value for states[24].fcn, expected 141, is %d",
                  check_msg->states[24].fcn);
    ck_assert_msg(
        check_msg->states[24].sid.code == 255,
        "incorrect value for states[24].sid.code, expected 255, is %d",
        check_msg->states[24].sid.code);
    ck_assert_msg(check_msg->states[24].sid.sat == 113,
                  "incorrect value for states[24].sid.sat, expected 113, is %d",
                  check_msg->states[24].sid.sat);
    ck_assert_msg(check_msg->states[25].cn0 == 39,
                  "incorrect value for states[25].cn0, expected 39, is %d",
                  check_msg->states[25].cn0);
    ck_assert_msg(check_msg->states[25].fcn == 245,
                  "incorrect value for states[25].fcn, expected 245, is %d",
                  check_msg->states[25].fcn);
    ck_assert_msg(check_msg->states[25].sid.code == 69,
                  "incorrect value for states[25].sid.code, expected 69, is %d",
                  check_msg->states[25].sid.code);
    ck_assert_msg(check_msg->states[25].sid.sat == 43,
                  "incorrect value for states[25].sid.sat, expected 43, is %d",
                  check_msg->states[25].sid.sat);
    ck_assert_msg(check_msg->states[26].cn0 == 56,
                  "incorrect value for states[26].cn0, expected 56, is %d",
                  check_msg->states[26].cn0);
    ck_assert_msg(check_msg->states[26].fcn == 108,
                  "incorrect value for states[26].fcn, expected 108, is %d",
                  check_msg->states[26].fcn);
    ck_assert_msg(
        check_msg->states[26].sid.code == 230,
        "incorrect value for states[26].sid.code, expected 230, is %d",
        check_msg->states[26].sid.code);
    ck_assert_msg(check_msg->states[26].sid.sat == 100,
                  "incorrect value for states[26].sid.sat, expected 100, is %d",
                  check_msg->states[26].sid.sat);
    ck_assert_msg(check_msg->states[27].cn0 == 143,
                  "incorrect value for states[27].cn0, expected 143, is %d",
                  check_msg->states[27].cn0);
    ck_assert_msg(check_msg->states[27].fcn == 149,
                  "incorrect value for states[27].fcn, expected 149, is %d",
                  check_msg->states[27].fcn);
    ck_assert_msg(check_msg->states[27].sid.code == 68,
                  "incorrect value for states[27].sid.code, expected 68, is %d",
                  check_msg->states[27].sid.code);
    ck_assert_msg(check_msg->states[27].sid.sat == 247,
                  "incorrect value for states[27].sid.sat, expected 247, is %d",
                  check_msg->states[27].sid.sat);
    ck_assert_msg(check_msg->states[28].cn0 == 70,
                  "incorrect value for states[28].cn0, expected 70, is %d",
                  check_msg->states[28].cn0);
    ck_assert_msg(check_msg->states[28].fcn == 233,
                  "incorrect value for states[28].fcn, expected 233, is %d",
                  check_msg->states[28].fcn);
    ck_assert_msg(
        check_msg->states[28].sid.code == 101,
        "incorrect value for states[28].sid.code, expected 101, is %d",
        check_msg->states[28].sid.code);
    ck_assert_msg(check_msg->states[28].sid.sat == 137,
                  "incorrect value for states[28].sid.sat, expected 137, is %d",
                  check_msg->states[28].sid.sat);
    ck_assert_msg(check_msg->states[29].cn0 == 110,
                  "incorrect value for states[29].cn0, expected 110, is %d",
                  check_msg->states[29].cn0);
    ck_assert_msg(check_msg->states[29].fcn == 38,
                  "incorrect value for states[29].fcn, expected 38, is %d",
                  check_msg->states[29].fcn);
    ck_assert_msg(
        check_msg->states[29].sid.code == 165,
        "incorrect value for states[29].sid.code, expected 165, is %d",
        check_msg->states[29].sid.code);
    ck_assert_msg(check_msg->states[29].sid.sat == 49,
                  "incorrect value for states[29].sid.sat, expected 49, is %d",
                  check_msg->states[29].sid.sat);
    ck_assert_msg(check_msg->states[30].cn0 == 213,
                  "incorrect value for states[30].cn0, expected 213, is %d",
                  check_msg->states[30].cn0);
    ck_assert_msg(check_msg->states[30].fcn == 80,
                  "incorrect value for states[30].fcn, expected 80, is %d",
                  check_msg->states[30].fcn);
    ck_assert_msg(
        check_msg->states[30].sid.code == 230,
        "incorrect value for states[30].sid.code, expected 230, is %d",
        check_msg->states[30].sid.code);
    ck_assert_msg(check_msg->states[30].sid.sat == 218,
                  "incorrect value for states[30].sid.sat, expected 218, is %d",
                  check_msg->states[30].sid.sat);
    ck_assert_msg(check_msg->states[31].cn0 == 128,
                  "incorrect value for states[31].cn0, expected 128, is %d",
                  check_msg->states[31].cn0);
    ck_assert_msg(check_msg->states[31].fcn == 139,
                  "incorrect value for states[31].fcn, expected 139, is %d",
                  check_msg->states[31].fcn);
    ck_assert_msg(
        check_msg->states[31].sid.code == 179,
        "incorrect value for states[31].sid.code, expected 179, is %d",
        check_msg->states[31].sid.code);
    ck_assert_msg(check_msg->states[31].sid.sat == 196,
                  "incorrect value for states[31].sid.sat, expected 196, is %d",
                  check_msg->states[31].sid.sat);
    ck_assert_msg(check_msg->states[32].cn0 == 171,
                  "incorrect value for states[32].cn0, expected 171, is %d",
                  check_msg->states[32].cn0);
    ck_assert_msg(check_msg->states[32].fcn == 196,
                  "incorrect value for states[32].fcn, expected 196, is %d",
                  check_msg->states[32].fcn);
    ck_assert_msg(
        check_msg->states[32].sid.code == 178,
        "incorrect value for states[32].sid.code, expected 178, is %d",
        check_msg->states[32].sid.code);
    ck_assert_msg(check_msg->states[32].sid.sat == 15,
                  "incorrect value for states[32].sid.sat, expected 15, is %d",
                  check_msg->states[32].sid.sat);
    ck_assert_msg(check_msg->states[33].cn0 == 194,
                  "incorrect value for states[33].cn0, expected 194, is %d",
                  check_msg->states[33].cn0);
    ck_assert_msg(check_msg->states[33].fcn == 97,
                  "incorrect value for states[33].fcn, expected 97, is %d",
                  check_msg->states[33].fcn);
    ck_assert_msg(
        check_msg->states[33].sid.code == 212,
        "incorrect value for states[33].sid.code, expected 212, is %d",
        check_msg->states[33].sid.code);
    ck_assert_msg(check_msg->states[33].sid.sat == 8,
                  "incorrect value for states[33].sid.sat, expected 8, is %d",
                  check_msg->states[33].sid.sat);
    ck_assert_msg(check_msg->states[34].cn0 == 99,
                  "incorrect value for states[34].cn0, expected 99, is %d",
                  check_msg->states[34].cn0);
    ck_assert_msg(check_msg->states[34].fcn == 79,
                  "incorrect value for states[34].fcn, expected 79, is %d",
                  check_msg->states[34].fcn);
    ck_assert_msg(
        check_msg->states[34].sid.code == 233,
        "incorrect value for states[34].sid.code, expected 233, is %d",
        check_msg->states[34].sid.code);
    ck_assert_msg(check_msg->states[34].sid.sat == 83,
                  "incorrect value for states[34].sid.sat, expected 83, is %d",
                  check_msg->states[34].sid.sat);
    ck_assert_msg(check_msg->states[35].cn0 == 180,
                  "incorrect value for states[35].cn0, expected 180, is %d",
                  check_msg->states[35].cn0);
    ck_assert_msg(check_msg->states[35].fcn == 31,
                  "incorrect value for states[35].fcn, expected 31, is %d",
                  check_msg->states[35].fcn);
    ck_assert_msg(check_msg->states[35].sid.code == 90,
                  "incorrect value for states[35].sid.code, expected 90, is %d",
                  check_msg->states[35].sid.code);
    ck_assert_msg(check_msg->states[35].sid.sat == 55,
                  "incorrect value for states[35].sid.sat, expected 55, is %d",
                  check_msg->states[35].sid.sat);
    ck_assert_msg(check_msg->states[36].cn0 == 186,
                  "incorrect value for states[36].cn0, expected 186, is %d",
                  check_msg->states[36].cn0);
    ck_assert_msg(check_msg->states[36].fcn == 105,
                  "incorrect value for states[36].fcn, expected 105, is %d",
                  check_msg->states[36].fcn);
    ck_assert_msg(check_msg->states[36].sid.code == 25,
                  "incorrect value for states[36].sid.code, expected 25, is %d",
                  check_msg->states[36].sid.code);
    ck_assert_msg(check_msg->states[36].sid.sat == 5,
                  "incorrect value for states[36].sid.sat, expected 5, is %d",
                  check_msg->states[36].sid.sat);
    ck_assert_msg(check_msg->states[37].cn0 == 111,
                  "incorrect value for states[37].cn0, expected 111, is %d",
                  check_msg->states[37].cn0);
    ck_assert_msg(check_msg->states[37].fcn == 80,
                  "incorrect value for states[37].fcn, expected 80, is %d",
                  check_msg->states[37].fcn);
    ck_assert_msg(
        check_msg->states[37].sid.code == 224,
        "incorrect value for states[37].sid.code, expected 224, is %d",
        check_msg->states[37].sid.code);
    ck_assert_msg(check_msg->states[37].sid.sat == 22,
                  "incorrect value for states[37].sid.sat, expected 22, is %d",
                  check_msg->states[37].sid.sat);
    ck_assert_msg(check_msg->states[38].cn0 == 166,
                  "incorrect value for states[38].cn0, expected 166, is %d",
                  check_msg->states[38].cn0);
    ck_assert_msg(check_msg->states[38].fcn == 106,
                  "incorrect value for states[38].fcn, expected 106, is %d",
                  check_msg->states[38].fcn);
    ck_assert_msg(check_msg->states[38].sid.code == 48,
                  "incorrect value for states[38].sid.code, expected 48, is %d",
                  check_msg->states[38].sid.code);
    ck_assert_msg(check_msg->states[38].sid.sat == 8,
                  "incorrect value for states[38].sid.sat, expected 8, is %d",
                  check_msg->states[38].sid.sat);
    ck_assert_msg(check_msg->states[39].cn0 == 49,
                  "incorrect value for states[39].cn0, expected 49, is %d",
                  check_msg->states[39].cn0);
    ck_assert_msg(check_msg->states[39].fcn == 156,
                  "incorrect value for states[39].fcn, expected 156, is %d",
                  check_msg->states[39].fcn);
    ck_assert_msg(check_msg->states[39].sid.code == 48,
                  "incorrect value for states[39].sid.code, expected 48, is %d",
                  check_msg->states[39].sid.code);
    ck_assert_msg(check_msg->states[39].sid.sat == 4,
                  "incorrect value for states[39].sid.sat, expected 4, is %d",
                  check_msg->states[39].sid.sat);
    ck_assert_msg(check_msg->states[40].cn0 == 146,
                  "incorrect value for states[40].cn0, expected 146, is %d",
                  check_msg->states[40].cn0);
    ck_assert_msg(check_msg->states[40].fcn == 142,
                  "incorrect value for states[40].fcn, expected 142, is %d",
                  check_msg->states[40].fcn);
    ck_assert_msg(check_msg->states[40].sid.code == 19,
                  "incorrect value for states[40].sid.code, expected 19, is %d",
                  check_msg->states[40].sid.code);
    ck_assert_msg(check_msg->states[40].sid.sat == 86,
                  "incorrect value for states[40].sid.sat, expected 86, is %d",
                  check_msg->states[40].sid.sat);
    ck_assert_msg(check_msg->states[41].cn0 == 64,
                  "incorrect value for states[41].cn0, expected 64, is %d",
                  check_msg->states[41].cn0);
    ck_assert_msg(check_msg->states[41].fcn == 115,
                  "incorrect value for states[41].fcn, expected 115, is %d",
                  check_msg->states[41].fcn);
    ck_assert_msg(
        check_msg->states[41].sid.code == 124,
        "incorrect value for states[41].sid.code, expected 124, is %d",
        check_msg->states[41].sid.code);
    ck_assert_msg(check_msg->states[41].sid.sat == 91,
                  "incorrect value for states[41].sid.sat, expected 91, is %d",
                  check_msg->states[41].sid.sat);
    ck_assert_msg(check_msg->states[42].cn0 == 178,
                  "incorrect value for states[42].cn0, expected 178, is %d",
                  check_msg->states[42].cn0);
    ck_assert_msg(check_msg->states[42].fcn == 115,
                  "incorrect value for states[42].fcn, expected 115, is %d",
                  check_msg->states[42].fcn);
    ck_assert_msg(
        check_msg->states[42].sid.code == 230,
        "incorrect value for states[42].sid.code, expected 230, is %d",
        check_msg->states[42].sid.code);
    ck_assert_msg(check_msg->states[42].sid.sat == 28,
                  "incorrect value for states[42].sid.sat, expected 28, is %d",
                  check_msg->states[42].sid.sat);
    ck_assert_msg(check_msg->states[43].cn0 == 242,
                  "incorrect value for states[43].cn0, expected 242, is %d",
                  check_msg->states[43].cn0);
    ck_assert_msg(check_msg->states[43].fcn == 16,
                  "incorrect value for states[43].fcn, expected 16, is %d",
                  check_msg->states[43].fcn);
    ck_assert_msg(
        check_msg->states[43].sid.code == 131,
        "incorrect value for states[43].sid.code, expected 131, is %d",
        check_msg->states[43].sid.code);
    ck_assert_msg(check_msg->states[43].sid.sat == 190,
                  "incorrect value for states[43].sid.sat, expected 190, is %d",
                  check_msg->states[43].sid.sat);
    ck_assert_msg(check_msg->states[44].cn0 == 113,
                  "incorrect value for states[44].cn0, expected 113, is %d",
                  check_msg->states[44].cn0);
    ck_assert_msg(check_msg->states[44].fcn == 182,
                  "incorrect value for states[44].fcn, expected 182, is %d",
                  check_msg->states[44].fcn);
    ck_assert_msg(check_msg->states[44].sid.code == 59,
                  "incorrect value for states[44].sid.code, expected 59, is %d",
                  check_msg->states[44].sid.code);
    ck_assert_msg(check_msg->states[44].sid.sat == 105,
                  "incorrect value for states[44].sid.sat, expected 105, is %d",
                  check_msg->states[44].sid.sat);
    ck_assert_msg(check_msg->states[45].cn0 == 179,
                  "incorrect value for states[45].cn0, expected 179, is %d",
                  check_msg->states[45].cn0);
    ck_assert_msg(check_msg->states[45].fcn == 48,
                  "incorrect value for states[45].fcn, expected 48, is %d",
                  check_msg->states[45].fcn);
    ck_assert_msg(
        check_msg->states[45].sid.code == 180,
        "incorrect value for states[45].sid.code, expected 180, is %d",
        check_msg->states[45].sid.code);
    ck_assert_msg(check_msg->states[45].sid.sat == 192,
                  "incorrect value for states[45].sid.sat, expected 192, is %d",
                  check_msg->states[45].sid.sat);
    ck_assert_msg(check_msg->states[46].cn0 == 211,
                  "incorrect value for states[46].cn0, expected 211, is %d",
                  check_msg->states[46].cn0);
    ck_assert_msg(check_msg->states[46].fcn == 172,
                  "incorrect value for states[46].fcn, expected 172, is %d",
                  check_msg->states[46].fcn);
    ck_assert_msg(check_msg->states[46].sid.code == 31,
                  "incorrect value for states[46].sid.code, expected 31, is %d",
                  check_msg->states[46].sid.code);
    ck_assert_msg(check_msg->states[46].sid.sat == 166,
                  "incorrect value for states[46].sid.sat, expected 166, is %d",
                  check_msg->states[46].sid.sat);
    ck_assert_msg(check_msg->states[47].cn0 == 49,
                  "incorrect value for states[47].cn0, expected 49, is %d",
                  check_msg->states[47].cn0);
    ck_assert_msg(check_msg->states[47].fcn == 140,
                  "incorrect value for states[47].fcn, expected 140, is %d",
                  check_msg->states[47].fcn);
    ck_assert_msg(
        check_msg->states[47].sid.code == 228,
        "incorrect value for states[47].sid.code, expected 228, is %d",
        check_msg->states[47].sid.code);
    ck_assert_msg(check_msg->states[47].sid.sat == 77,
                  "incorrect value for states[47].sid.sat, expected 77, is %d",
                  check_msg->states[47].sid.sat);
    ck_assert_msg(check_msg->states[48].cn0 == 194,
                  "incorrect value for states[48].cn0, expected 194, is %d",
                  check_msg->states[48].cn0);
    ck_assert_msg(check_msg->states[48].fcn == 240,
                  "incorrect value for states[48].fcn, expected 240, is %d",
                  check_msg->states[48].fcn);
    ck_assert_msg(check_msg->states[48].sid.code == 77,
                  "incorrect value for states[48].sid.code, expected 77, is %d",
                  check_msg->states[48].sid.code);
    ck_assert_msg(check_msg->states[48].sid.sat == 128,
                  "incorrect value for states[48].sid.sat, expected 128, is %d",
                  check_msg->states[48].sid.sat);
    ck_assert_msg(check_msg->states[49].cn0 == 58,
                  "incorrect value for states[49].cn0, expected 58, is %d",
                  check_msg->states[49].cn0);
    ck_assert_msg(check_msg->states[49].fcn == 41,
                  "incorrect value for states[49].fcn, expected 41, is %d",
                  check_msg->states[49].fcn);
    ck_assert_msg(
        check_msg->states[49].sid.code == 194,
        "incorrect value for states[49].sid.code, expected 194, is %d",
        check_msg->states[49].sid.code);
    ck_assert_msg(check_msg->states[49].sid.sat == 134,
                  "incorrect value for states[49].sid.sat, expected 134, is %d",
                  check_msg->states[49].sid.sat);
    ck_assert_msg(check_msg->states[50].cn0 == 55,
                  "incorrect value for states[50].cn0, expected 55, is %d",
                  check_msg->states[50].cn0);
    ck_assert_msg(check_msg->states[50].fcn == 129,
                  "incorrect value for states[50].fcn, expected 129, is %d",
                  check_msg->states[50].fcn);
    ck_assert_msg(check_msg->states[50].sid.code == 53,
                  "incorrect value for states[50].sid.code, expected 53, is %d",
                  check_msg->states[50].sid.code);
    ck_assert_msg(check_msg->states[50].sid.sat == 18,
                  "incorrect value for states[50].sid.sat, expected 18, is %d",
                  check_msg->states[50].sid.sat);
    ck_assert_msg(check_msg->states[51].cn0 == 92,
                  "incorrect value for states[51].cn0, expected 92, is %d",
                  check_msg->states[51].cn0);
    ck_assert_msg(check_msg->states[51].fcn == 134,
                  "incorrect value for states[51].fcn, expected 134, is %d",
                  check_msg->states[51].fcn);
    ck_assert_msg(check_msg->states[51].sid.code == 72,
                  "incorrect value for states[51].sid.code, expected 72, is %d",
                  check_msg->states[51].sid.code);
    ck_assert_msg(check_msg->states[51].sid.sat == 91,
                  "incorrect value for states[51].sid.sat, expected 91, is %d",
                  check_msg->states[51].sid.sat);
    ck_assert_msg(check_msg->states[52].cn0 == 56,
                  "incorrect value for states[52].cn0, expected 56, is %d",
                  check_msg->states[52].cn0);
    ck_assert_msg(check_msg->states[52].fcn == 157,
                  "incorrect value for states[52].fcn, expected 157, is %d",
                  check_msg->states[52].fcn);
    ck_assert_msg(
        check_msg->states[52].sid.code == 224,
        "incorrect value for states[52].sid.code, expected 224, is %d",
        check_msg->states[52].sid.code);
    ck_assert_msg(check_msg->states[52].sid.sat == 33,
                  "incorrect value for states[52].sid.sat, expected 33, is %d",
                  check_msg->states[52].sid.sat);
    ck_assert_msg(check_msg->states[53].cn0 == 174,
                  "incorrect value for states[53].cn0, expected 174, is %d",
                  check_msg->states[53].cn0);
    ck_assert_msg(check_msg->states[53].fcn == 224,
                  "incorrect value for states[53].fcn, expected 224, is %d",
                  check_msg->states[53].fcn);
    ck_assert_msg(check_msg->states[53].sid.code == 54,
                  "incorrect value for states[53].sid.code, expected 54, is %d",
                  check_msg->states[53].sid.code);
    ck_assert_msg(check_msg->states[53].sid.sat == 186,
                  "incorrect value for states[53].sid.sat, expected 186, is %d",
                  check_msg->states[53].sid.sat);
    ck_assert_msg(check_msg->states[54].cn0 == 190,
                  "incorrect value for states[54].cn0, expected 190, is %d",
                  check_msg->states[54].cn0);
    ck_assert_msg(check_msg->states[54].fcn == 148,
                  "incorrect value for states[54].fcn, expected 148, is %d",
                  check_msg->states[54].fcn);
    ck_assert_msg(check_msg->states[54].sid.code == 84,
                  "incorrect value for states[54].sid.code, expected 84, is %d",
                  check_msg->states[54].sid.code);
    ck_assert_msg(check_msg->states[54].sid.sat == 82,
                  "incorrect value for states[54].sid.sat, expected 82, is %d",
                  check_msg->states[54].sid.sat);
    ck_assert_msg(check_msg->states[55].cn0 == 67,
                  "incorrect value for states[55].cn0, expected 67, is %d",
                  check_msg->states[55].cn0);
    ck_assert_msg(check_msg->states[55].fcn == 62,
                  "incorrect value for states[55].fcn, expected 62, is %d",
                  check_msg->states[55].fcn);
    ck_assert_msg(check_msg->states[55].sid.code == 54,
                  "incorrect value for states[55].sid.code, expected 54, is %d",
                  check_msg->states[55].sid.code);
    ck_assert_msg(check_msg->states[55].sid.sat == 236,
                  "incorrect value for states[55].sid.sat, expected 236, is %d",
                  check_msg->states[55].sid.sat);
    ck_assert_msg(check_msg->states[56].cn0 == 254,
                  "incorrect value for states[56].cn0, expected 254, is %d",
                  check_msg->states[56].cn0);
    ck_assert_msg(check_msg->states[56].fcn == 57,
                  "incorrect value for states[56].fcn, expected 57, is %d",
                  check_msg->states[56].fcn);
    ck_assert_msg(
        check_msg->states[56].sid.code == 215,
        "incorrect value for states[56].sid.code, expected 215, is %d",
        check_msg->states[56].sid.code);
    ck_assert_msg(check_msg->states[56].sid.sat == 52,
                  "incorrect value for states[56].sid.sat, expected 52, is %d",
                  check_msg->states[56].sid.sat);
    ck_assert_msg(check_msg->states[57].cn0 == 174,
                  "incorrect value for states[57].cn0, expected 174, is %d",
                  check_msg->states[57].cn0);
    ck_assert_msg(check_msg->states[57].fcn == 36,
                  "incorrect value for states[57].fcn, expected 36, is %d",
                  check_msg->states[57].fcn);
    ck_assert_msg(
        check_msg->states[57].sid.code == 133,
        "incorrect value for states[57].sid.code, expected 133, is %d",
        check_msg->states[57].sid.code);
    ck_assert_msg(check_msg->states[57].sid.sat == 16,
                  "incorrect value for states[57].sid.sat, expected 16, is %d",
                  check_msg->states[57].sid.sat);
    ck_assert_msg(check_msg->states[58].cn0 == 17,
                  "incorrect value for states[58].cn0, expected 17, is %d",
                  check_msg->states[58].cn0);
    ck_assert_msg(check_msg->states[58].fcn == 145,
                  "incorrect value for states[58].fcn, expected 145, is %d",
                  check_msg->states[58].fcn);
    ck_assert_msg(
        check_msg->states[58].sid.code == 172,
        "incorrect value for states[58].sid.code, expected 172, is %d",
        check_msg->states[58].sid.code);
    ck_assert_msg(check_msg->states[58].sid.sat == 219,
                  "incorrect value for states[58].sid.sat, expected 219, is %d",
                  check_msg->states[58].sid.sat);
    ck_assert_msg(check_msg->states[59].cn0 == 97,
                  "incorrect value for states[59].cn0, expected 97, is %d",
                  check_msg->states[59].cn0);
    ck_assert_msg(check_msg->states[59].fcn == 111,
                  "incorrect value for states[59].fcn, expected 111, is %d",
                  check_msg->states[59].fcn);
    ck_assert_msg(
        check_msg->states[59].sid.code == 179,
        "incorrect value for states[59].sid.code, expected 179, is %d",
        check_msg->states[59].sid.code);
    ck_assert_msg(check_msg->states[59].sid.sat == 192,
                  "incorrect value for states[59].sid.sat, expected 192, is %d",
                  check_msg->states[59].sid.sat);
    ck_assert_msg(check_msg->states[60].cn0 == 134,
                  "incorrect value for states[60].cn0, expected 134, is %d",
                  check_msg->states[60].cn0);
    ck_assert_msg(check_msg->states[60].fcn == 208,
                  "incorrect value for states[60].fcn, expected 208, is %d",
                  check_msg->states[60].fcn);
    ck_assert_msg(check_msg->states[60].sid.code == 56,
                  "incorrect value for states[60].sid.code, expected 56, is %d",
                  check_msg->states[60].sid.code);
    ck_assert_msg(check_msg->states[60].sid.sat == 207,
                  "incorrect value for states[60].sid.sat, expected 207, is %d",
                  check_msg->states[60].sid.sat);
    ck_assert_msg(check_msg->states[61].cn0 == 226,
                  "incorrect value for states[61].cn0, expected 226, is %d",
                  check_msg->states[61].cn0);
    ck_assert_msg(check_msg->states[61].fcn == 43,
                  "incorrect value for states[61].fcn, expected 43, is %d",
                  check_msg->states[61].fcn);
    ck_assert_msg(check_msg->states[61].sid.code == 17,
                  "incorrect value for states[61].sid.code, expected 17, is %d",
                  check_msg->states[61].sid.code);
    ck_assert_msg(check_msg->states[61].sid.sat == 180,
                  "incorrect value for states[61].sid.sat, expected 180, is %d",
                  check_msg->states[61].sid.sat);
    ck_assert_msg(check_msg->states[62].cn0 == 113,
                  "incorrect value for states[62].cn0, expected 113, is %d",
                  check_msg->states[62].cn0);
    ck_assert_msg(check_msg->states[62].fcn == 140,
                  "incorrect value for states[62].fcn, expected 140, is %d",
                  check_msg->states[62].fcn);
    ck_assert_msg(
        check_msg->states[62].sid.code == 182,
        "incorrect value for states[62].sid.code, expected 182, is %d",
        check_msg->states[62].sid.code);
    ck_assert_msg(check_msg->states[62].sid.sat == 255,
                  "incorrect value for states[62].sid.sat, expected 255, is %d",
                  check_msg->states[62].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x13, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x13, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   197, 253, 28,
        66,  1,   203, 0,   0,   0,   231, 99,  16, 66,  1,   208, 0,   0,
        0,   212, 129, 22,  66,  1,   212, 0,   0,  0,   58,  21,  28,  66,
        1,   217, 0,   0,   0,   178, 33,  40,  66, 1,   218, 0,   0,   0,
        235, 189, 21,  66,  1,   220, 0,   0,   0,  29,  177, 25,  66,  1,
        222, 0,   0,   0,   43,  169, 27,  66,  1,  225, 0,   0,   0,   137,
        125, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 222, 97,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_dep_b_t* test_msg =
        (msg_tracking_state_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 39.24782180786133;
    test_msg->states[0].sid.code = 0;
    test_msg->states[0].sid.reserved = 0;
    test_msg->states[0].sid.sat = 202;
    test_msg->states[0].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 36.09756088256836;
    test_msg->states[1].sid.code = 0;
    test_msg->states[1].sid.reserved = 0;
    test_msg->states[1].sid.sat = 203;
    test_msg->states[1].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 37.62678527832031;
    test_msg->states[2].sid.code = 0;
    test_msg->states[2].sid.reserved = 0;
    test_msg->states[2].sid.sat = 208;
    test_msg->states[2].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 39.020729064941406;
    test_msg->states[3].sid.code = 0;
    test_msg->states[3].sid.reserved = 0;
    test_msg->states[3].sid.sat = 212;
    test_msg->states[3].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 42.03290557861328;
    test_msg->states[4].sid.code = 0;
    test_msg->states[4].sid.reserved = 0;
    test_msg->states[4].sid.sat = 217;
    test_msg->states[4].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 37.43546676635742;
    test_msg->states[5].sid.code = 0;
    test_msg->states[5].sid.reserved = 0;
    test_msg->states[5].sid.sat = 218;
    test_msg->states[5].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 38.4229621887207;
    test_msg->states[6].sid.code = 0;
    test_msg->states[6].sid.reserved = 0;
    test_msg->states[6].sid.sat = 220;
    test_msg->states[6].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 38.91520309448242;
    test_msg->states[7].sid.code = 0;
    test_msg->states[7].sid.reserved = 0;
    test_msg->states[7].sid.sat = 222;
    test_msg->states[7].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 42.62259292602539;
    test_msg->states[8].sid.code = 0;
    test_msg->states[8].sid.reserved = 0;
    test_msg->states[8].sid.sat = 225;
    test_msg->states[8].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = -1.0;
    test_msg->states[9].sid.code = 0;
    test_msg->states[9].sid.reserved = 0;
    test_msg->states[9].sid.sat = 0;
    test_msg->states[9].state = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = -1.0;
    test_msg->states[10].sid.code = 0;
    test_msg->states[10].sid.reserved = 0;
    test_msg->states[10].sid.sat = 0;
    test_msg->states[10].state = 0;
    sbp_payload_send(&sbp_state, 0x13, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x13,
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
    msg_tracking_state_dep_b_t* check_msg =
        (msg_tracking_state_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->states[0].cn0 * 100 - 39.2478218079 * 100) < 0.05,
        "incorrect value for states[0].cn0, expected 39.2478218079, is %f",
        check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].sid.code == 0,
                  "incorrect value for states[0].sid.code, expected 0, is %d",
                  check_msg->states[0].sid.code);
    ck_assert_msg(
        check_msg->states[0].sid.reserved == 0,
        "incorrect value for states[0].sid.reserved, expected 0, is %d",
        check_msg->states[0].sid.reserved);
    ck_assert_msg(check_msg->states[0].sid.sat == 202,
                  "incorrect value for states[0].sid.sat, expected 202, is %d",
                  check_msg->states[0].sid.sat);
    ck_assert_msg(check_msg->states[0].state == 1,
                  "incorrect value for states[0].state, expected 1, is %d",
                  check_msg->states[0].state);
    ck_assert_msg(
        (check_msg->states[1].cn0 * 100 - 36.0975608826 * 100) < 0.05,
        "incorrect value for states[1].cn0, expected 36.0975608826, is %f",
        check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].sid.code == 0,
                  "incorrect value for states[1].sid.code, expected 0, is %d",
                  check_msg->states[1].sid.code);
    ck_assert_msg(
        check_msg->states[1].sid.reserved == 0,
        "incorrect value for states[1].sid.reserved, expected 0, is %d",
        check_msg->states[1].sid.reserved);
    ck_assert_msg(check_msg->states[1].sid.sat == 203,
                  "incorrect value for states[1].sid.sat, expected 203, is %d",
                  check_msg->states[1].sid.sat);
    ck_assert_msg(check_msg->states[1].state == 1,
                  "incorrect value for states[1].state, expected 1, is %d",
                  check_msg->states[1].state);
    ck_assert_msg(
        (check_msg->states[2].cn0 * 100 - 37.6267852783 * 100) < 0.05,
        "incorrect value for states[2].cn0, expected 37.6267852783, is %f",
        check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].sid.code == 0,
                  "incorrect value for states[2].sid.code, expected 0, is %d",
                  check_msg->states[2].sid.code);
    ck_assert_msg(
        check_msg->states[2].sid.reserved == 0,
        "incorrect value for states[2].sid.reserved, expected 0, is %d",
        check_msg->states[2].sid.reserved);
    ck_assert_msg(check_msg->states[2].sid.sat == 208,
                  "incorrect value for states[2].sid.sat, expected 208, is %d",
                  check_msg->states[2].sid.sat);
    ck_assert_msg(check_msg->states[2].state == 1,
                  "incorrect value for states[2].state, expected 1, is %d",
                  check_msg->states[2].state);
    ck_assert_msg(
        (check_msg->states[3].cn0 * 100 - 39.0207290649 * 100) < 0.05,
        "incorrect value for states[3].cn0, expected 39.0207290649, is %f",
        check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].sid.code == 0,
                  "incorrect value for states[3].sid.code, expected 0, is %d",
                  check_msg->states[3].sid.code);
    ck_assert_msg(
        check_msg->states[3].sid.reserved == 0,
        "incorrect value for states[3].sid.reserved, expected 0, is %d",
        check_msg->states[3].sid.reserved);
    ck_assert_msg(check_msg->states[3].sid.sat == 212,
                  "incorrect value for states[3].sid.sat, expected 212, is %d",
                  check_msg->states[3].sid.sat);
    ck_assert_msg(check_msg->states[3].state == 1,
                  "incorrect value for states[3].state, expected 1, is %d",
                  check_msg->states[3].state);
    ck_assert_msg(
        (check_msg->states[4].cn0 * 100 - 42.0329055786 * 100) < 0.05,
        "incorrect value for states[4].cn0, expected 42.0329055786, is %f",
        check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].sid.code == 0,
                  "incorrect value for states[4].sid.code, expected 0, is %d",
                  check_msg->states[4].sid.code);
    ck_assert_msg(
        check_msg->states[4].sid.reserved == 0,
        "incorrect value for states[4].sid.reserved, expected 0, is %d",
        check_msg->states[4].sid.reserved);
    ck_assert_msg(check_msg->states[4].sid.sat == 217,
                  "incorrect value for states[4].sid.sat, expected 217, is %d",
                  check_msg->states[4].sid.sat);
    ck_assert_msg(check_msg->states[4].state == 1,
                  "incorrect value for states[4].state, expected 1, is %d",
                  check_msg->states[4].state);
    ck_assert_msg(
        (check_msg->states[5].cn0 * 100 - 37.4354667664 * 100) < 0.05,
        "incorrect value for states[5].cn0, expected 37.4354667664, is %f",
        check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].sid.code == 0,
                  "incorrect value for states[5].sid.code, expected 0, is %d",
                  check_msg->states[5].sid.code);
    ck_assert_msg(
        check_msg->states[5].sid.reserved == 0,
        "incorrect value for states[5].sid.reserved, expected 0, is %d",
        check_msg->states[5].sid.reserved);
    ck_assert_msg(check_msg->states[5].sid.sat == 218,
                  "incorrect value for states[5].sid.sat, expected 218, is %d",
                  check_msg->states[5].sid.sat);
    ck_assert_msg(check_msg->states[5].state == 1,
                  "incorrect value for states[5].state, expected 1, is %d",
                  check_msg->states[5].state);
    ck_assert_msg(
        (check_msg->states[6].cn0 * 100 - 38.4229621887 * 100) < 0.05,
        "incorrect value for states[6].cn0, expected 38.4229621887, is %f",
        check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].sid.code == 0,
                  "incorrect value for states[6].sid.code, expected 0, is %d",
                  check_msg->states[6].sid.code);
    ck_assert_msg(
        check_msg->states[6].sid.reserved == 0,
        "incorrect value for states[6].sid.reserved, expected 0, is %d",
        check_msg->states[6].sid.reserved);
    ck_assert_msg(check_msg->states[6].sid.sat == 220,
                  "incorrect value for states[6].sid.sat, expected 220, is %d",
                  check_msg->states[6].sid.sat);
    ck_assert_msg(check_msg->states[6].state == 1,
                  "incorrect value for states[6].state, expected 1, is %d",
                  check_msg->states[6].state);
    ck_assert_msg(
        (check_msg->states[7].cn0 * 100 - 38.9152030945 * 100) < 0.05,
        "incorrect value for states[7].cn0, expected 38.9152030945, is %f",
        check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].sid.code == 0,
                  "incorrect value for states[7].sid.code, expected 0, is %d",
                  check_msg->states[7].sid.code);
    ck_assert_msg(
        check_msg->states[7].sid.reserved == 0,
        "incorrect value for states[7].sid.reserved, expected 0, is %d",
        check_msg->states[7].sid.reserved);
    ck_assert_msg(check_msg->states[7].sid.sat == 222,
                  "incorrect value for states[7].sid.sat, expected 222, is %d",
                  check_msg->states[7].sid.sat);
    ck_assert_msg(check_msg->states[7].state == 1,
                  "incorrect value for states[7].state, expected 1, is %d",
                  check_msg->states[7].state);
    ck_assert_msg(
        (check_msg->states[8].cn0 * 100 - 42.622592926 * 100) < 0.05,
        "incorrect value for states[8].cn0, expected 42.622592926, is %f",
        check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].sid.code == 0,
                  "incorrect value for states[8].sid.code, expected 0, is %d",
                  check_msg->states[8].sid.code);
    ck_assert_msg(
        check_msg->states[8].sid.reserved == 0,
        "incorrect value for states[8].sid.reserved, expected 0, is %d",
        check_msg->states[8].sid.reserved);
    ck_assert_msg(check_msg->states[8].sid.sat == 225,
                  "incorrect value for states[8].sid.sat, expected 225, is %d",
                  check_msg->states[8].sid.sat);
    ck_assert_msg(check_msg->states[8].state == 1,
                  "incorrect value for states[8].state, expected 1, is %d",
                  check_msg->states[8].state);
    ck_assert_msg((check_msg->states[9].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[9].cn0, expected -1.0, is %f",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].sid.code == 0,
                  "incorrect value for states[9].sid.code, expected 0, is %d",
                  check_msg->states[9].sid.code);
    ck_assert_msg(
        check_msg->states[9].sid.reserved == 0,
        "incorrect value for states[9].sid.reserved, expected 0, is %d",
        check_msg->states[9].sid.reserved);
    ck_assert_msg(check_msg->states[9].sid.sat == 0,
                  "incorrect value for states[9].sid.sat, expected 0, is %d",
                  check_msg->states[9].sid.sat);
    ck_assert_msg(check_msg->states[9].state == 0,
                  "incorrect value for states[9].state, expected 0, is %d",
                  check_msg->states[9].state);
    ck_assert_msg((check_msg->states[10].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[10].cn0, expected -1.0, is %f",
                  check_msg->states[10].cn0);
    ck_assert_msg(check_msg->states[10].sid.code == 0,
                  "incorrect value for states[10].sid.code, expected 0, is %d",
                  check_msg->states[10].sid.code);
    ck_assert_msg(
        check_msg->states[10].sid.reserved == 0,
        "incorrect value for states[10].sid.reserved, expected 0, is %d",
        check_msg->states[10].sid.reserved);
    ck_assert_msg(check_msg->states[10].sid.sat == 0,
                  "incorrect value for states[10].sid.sat, expected 0, is %d",
                  check_msg->states[10].sid.sat);
    ck_assert_msg(check_msg->states[10].state == 0,
                  "incorrect value for states[10].state, expected 0, is %d",
                  check_msg->states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x13, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x13, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   250, 249, 27,
        66,  1,   203, 0,   0,   0,   40,  143, 11, 66,  1,   208, 0,   0,
        0,   190, 200, 21,  66,  1,   212, 0,   0,  0,   251, 233, 26,  66,
        1,   217, 0,   0,   0,   209, 238, 39,  66, 1,   218, 0,   0,   0,
        162, 219, 21,  66,  1,   220, 0,   0,   0,  162, 197, 25,  66,  1,
        222, 0,   0,   0,   14,  35,  28,  66,  1,  225, 0,   0,   0,   9,
        153, 43,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 20,  31,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_dep_b_t* test_msg =
        (msg_tracking_state_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 38.994117736816406;
    test_msg->states[0].sid.code = 0;
    test_msg->states[0].sid.reserved = 0;
    test_msg->states[0].sid.sat = 202;
    test_msg->states[0].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 34.889801025390625;
    test_msg->states[1].sid.code = 0;
    test_msg->states[1].sid.reserved = 0;
    test_msg->states[1].sid.sat = 203;
    test_msg->states[1].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 37.44603729248047;
    test_msg->states[2].sid.code = 0;
    test_msg->states[2].sid.reserved = 0;
    test_msg->states[2].sid.sat = 208;
    test_msg->states[2].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 38.72849655151367;
    test_msg->states[3].sid.code = 0;
    test_msg->states[3].sid.reserved = 0;
    test_msg->states[3].sid.sat = 212;
    test_msg->states[3].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 41.983219146728516;
    test_msg->states[4].sid.code = 0;
    test_msg->states[4].sid.reserved = 0;
    test_msg->states[4].sid.sat = 217;
    test_msg->states[4].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 37.46448516845703;
    test_msg->states[5].sid.code = 0;
    test_msg->states[5].sid.reserved = 0;
    test_msg->states[5].sid.sat = 218;
    test_msg->states[5].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 38.44300079345703;
    test_msg->states[6].sid.code = 0;
    test_msg->states[6].sid.reserved = 0;
    test_msg->states[6].sid.sat = 220;
    test_msg->states[6].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 39.03423309326172;
    test_msg->states[7].sid.code = 0;
    test_msg->states[7].sid.reserved = 0;
    test_msg->states[7].sid.sat = 222;
    test_msg->states[7].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 42.89944839477539;
    test_msg->states[8].sid.code = 0;
    test_msg->states[8].sid.reserved = 0;
    test_msg->states[8].sid.sat = 225;
    test_msg->states[8].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = -1.0;
    test_msg->states[9].sid.code = 0;
    test_msg->states[9].sid.reserved = 0;
    test_msg->states[9].sid.sat = 0;
    test_msg->states[9].state = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = -1.0;
    test_msg->states[10].sid.code = 0;
    test_msg->states[10].sid.reserved = 0;
    test_msg->states[10].sid.sat = 0;
    test_msg->states[10].state = 0;
    sbp_payload_send(&sbp_state, 0x13, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x13,
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
    msg_tracking_state_dep_b_t* check_msg =
        (msg_tracking_state_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->states[0].cn0 * 100 - 38.9941177368 * 100) < 0.05,
        "incorrect value for states[0].cn0, expected 38.9941177368, is %f",
        check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].sid.code == 0,
                  "incorrect value for states[0].sid.code, expected 0, is %d",
                  check_msg->states[0].sid.code);
    ck_assert_msg(
        check_msg->states[0].sid.reserved == 0,
        "incorrect value for states[0].sid.reserved, expected 0, is %d",
        check_msg->states[0].sid.reserved);
    ck_assert_msg(check_msg->states[0].sid.sat == 202,
                  "incorrect value for states[0].sid.sat, expected 202, is %d",
                  check_msg->states[0].sid.sat);
    ck_assert_msg(check_msg->states[0].state == 1,
                  "incorrect value for states[0].state, expected 1, is %d",
                  check_msg->states[0].state);
    ck_assert_msg(
        (check_msg->states[1].cn0 * 100 - 34.8898010254 * 100) < 0.05,
        "incorrect value for states[1].cn0, expected 34.8898010254, is %f",
        check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].sid.code == 0,
                  "incorrect value for states[1].sid.code, expected 0, is %d",
                  check_msg->states[1].sid.code);
    ck_assert_msg(
        check_msg->states[1].sid.reserved == 0,
        "incorrect value for states[1].sid.reserved, expected 0, is %d",
        check_msg->states[1].sid.reserved);
    ck_assert_msg(check_msg->states[1].sid.sat == 203,
                  "incorrect value for states[1].sid.sat, expected 203, is %d",
                  check_msg->states[1].sid.sat);
    ck_assert_msg(check_msg->states[1].state == 1,
                  "incorrect value for states[1].state, expected 1, is %d",
                  check_msg->states[1].state);
    ck_assert_msg(
        (check_msg->states[2].cn0 * 100 - 37.4460372925 * 100) < 0.05,
        "incorrect value for states[2].cn0, expected 37.4460372925, is %f",
        check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].sid.code == 0,
                  "incorrect value for states[2].sid.code, expected 0, is %d",
                  check_msg->states[2].sid.code);
    ck_assert_msg(
        check_msg->states[2].sid.reserved == 0,
        "incorrect value for states[2].sid.reserved, expected 0, is %d",
        check_msg->states[2].sid.reserved);
    ck_assert_msg(check_msg->states[2].sid.sat == 208,
                  "incorrect value for states[2].sid.sat, expected 208, is %d",
                  check_msg->states[2].sid.sat);
    ck_assert_msg(check_msg->states[2].state == 1,
                  "incorrect value for states[2].state, expected 1, is %d",
                  check_msg->states[2].state);
    ck_assert_msg(
        (check_msg->states[3].cn0 * 100 - 38.7284965515 * 100) < 0.05,
        "incorrect value for states[3].cn0, expected 38.7284965515, is %f",
        check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].sid.code == 0,
                  "incorrect value for states[3].sid.code, expected 0, is %d",
                  check_msg->states[3].sid.code);
    ck_assert_msg(
        check_msg->states[3].sid.reserved == 0,
        "incorrect value for states[3].sid.reserved, expected 0, is %d",
        check_msg->states[3].sid.reserved);
    ck_assert_msg(check_msg->states[3].sid.sat == 212,
                  "incorrect value for states[3].sid.sat, expected 212, is %d",
                  check_msg->states[3].sid.sat);
    ck_assert_msg(check_msg->states[3].state == 1,
                  "incorrect value for states[3].state, expected 1, is %d",
                  check_msg->states[3].state);
    ck_assert_msg(
        (check_msg->states[4].cn0 * 100 - 41.9832191467 * 100) < 0.05,
        "incorrect value for states[4].cn0, expected 41.9832191467, is %f",
        check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].sid.code == 0,
                  "incorrect value for states[4].sid.code, expected 0, is %d",
                  check_msg->states[4].sid.code);
    ck_assert_msg(
        check_msg->states[4].sid.reserved == 0,
        "incorrect value for states[4].sid.reserved, expected 0, is %d",
        check_msg->states[4].sid.reserved);
    ck_assert_msg(check_msg->states[4].sid.sat == 217,
                  "incorrect value for states[4].sid.sat, expected 217, is %d",
                  check_msg->states[4].sid.sat);
    ck_assert_msg(check_msg->states[4].state == 1,
                  "incorrect value for states[4].state, expected 1, is %d",
                  check_msg->states[4].state);
    ck_assert_msg(
        (check_msg->states[5].cn0 * 100 - 37.4644851685 * 100) < 0.05,
        "incorrect value for states[5].cn0, expected 37.4644851685, is %f",
        check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].sid.code == 0,
                  "incorrect value for states[5].sid.code, expected 0, is %d",
                  check_msg->states[5].sid.code);
    ck_assert_msg(
        check_msg->states[5].sid.reserved == 0,
        "incorrect value for states[5].sid.reserved, expected 0, is %d",
        check_msg->states[5].sid.reserved);
    ck_assert_msg(check_msg->states[5].sid.sat == 218,
                  "incorrect value for states[5].sid.sat, expected 218, is %d",
                  check_msg->states[5].sid.sat);
    ck_assert_msg(check_msg->states[5].state == 1,
                  "incorrect value for states[5].state, expected 1, is %d",
                  check_msg->states[5].state);
    ck_assert_msg(
        (check_msg->states[6].cn0 * 100 - 38.4430007935 * 100) < 0.05,
        "incorrect value for states[6].cn0, expected 38.4430007935, is %f",
        check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].sid.code == 0,
                  "incorrect value for states[6].sid.code, expected 0, is %d",
                  check_msg->states[6].sid.code);
    ck_assert_msg(
        check_msg->states[6].sid.reserved == 0,
        "incorrect value for states[6].sid.reserved, expected 0, is %d",
        check_msg->states[6].sid.reserved);
    ck_assert_msg(check_msg->states[6].sid.sat == 220,
                  "incorrect value for states[6].sid.sat, expected 220, is %d",
                  check_msg->states[6].sid.sat);
    ck_assert_msg(check_msg->states[6].state == 1,
                  "incorrect value for states[6].state, expected 1, is %d",
                  check_msg->states[6].state);
    ck_assert_msg(
        (check_msg->states[7].cn0 * 100 - 39.0342330933 * 100) < 0.05,
        "incorrect value for states[7].cn0, expected 39.0342330933, is %f",
        check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].sid.code == 0,
                  "incorrect value for states[7].sid.code, expected 0, is %d",
                  check_msg->states[7].sid.code);
    ck_assert_msg(
        check_msg->states[7].sid.reserved == 0,
        "incorrect value for states[7].sid.reserved, expected 0, is %d",
        check_msg->states[7].sid.reserved);
    ck_assert_msg(check_msg->states[7].sid.sat == 222,
                  "incorrect value for states[7].sid.sat, expected 222, is %d",
                  check_msg->states[7].sid.sat);
    ck_assert_msg(check_msg->states[7].state == 1,
                  "incorrect value for states[7].state, expected 1, is %d",
                  check_msg->states[7].state);
    ck_assert_msg(
        (check_msg->states[8].cn0 * 100 - 42.8994483948 * 100) < 0.05,
        "incorrect value for states[8].cn0, expected 42.8994483948, is %f",
        check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].sid.code == 0,
                  "incorrect value for states[8].sid.code, expected 0, is %d",
                  check_msg->states[8].sid.code);
    ck_assert_msg(
        check_msg->states[8].sid.reserved == 0,
        "incorrect value for states[8].sid.reserved, expected 0, is %d",
        check_msg->states[8].sid.reserved);
    ck_assert_msg(check_msg->states[8].sid.sat == 225,
                  "incorrect value for states[8].sid.sat, expected 225, is %d",
                  check_msg->states[8].sid.sat);
    ck_assert_msg(check_msg->states[8].state == 1,
                  "incorrect value for states[8].state, expected 1, is %d",
                  check_msg->states[8].state);
    ck_assert_msg((check_msg->states[9].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[9].cn0, expected -1.0, is %f",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].sid.code == 0,
                  "incorrect value for states[9].sid.code, expected 0, is %d",
                  check_msg->states[9].sid.code);
    ck_assert_msg(
        check_msg->states[9].sid.reserved == 0,
        "incorrect value for states[9].sid.reserved, expected 0, is %d",
        check_msg->states[9].sid.reserved);
    ck_assert_msg(check_msg->states[9].sid.sat == 0,
                  "incorrect value for states[9].sid.sat, expected 0, is %d",
                  check_msg->states[9].sid.sat);
    ck_assert_msg(check_msg->states[9].state == 0,
                  "incorrect value for states[9].state, expected 0, is %d",
                  check_msg->states[9].state);
    ck_assert_msg((check_msg->states[10].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[10].cn0, expected -1.0, is %f",
                  check_msg->states[10].cn0);
    ck_assert_msg(check_msg->states[10].sid.code == 0,
                  "incorrect value for states[10].sid.code, expected 0, is %d",
                  check_msg->states[10].sid.code);
    ck_assert_msg(
        check_msg->states[10].sid.reserved == 0,
        "incorrect value for states[10].sid.reserved, expected 0, is %d",
        check_msg->states[10].sid.reserved);
    ck_assert_msg(check_msg->states[10].sid.sat == 0,
                  "incorrect value for states[10].sid.sat, expected 0, is %d",
                  check_msg->states[10].sid.sat);
    ck_assert_msg(check_msg->states[10].state == 0,
                  "incorrect value for states[10].state, expected 0, is %d",
                  check_msg->states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x13, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x13, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   123, 209, 27,
        66,  1,   203, 0,   0,   0,   214, 64,  15, 66,  1,   208, 0,   0,
        0,   56,  55,  22,  66,  1,   212, 0,   0,  0,   91,  142, 27,  66,
        1,   217, 0,   0,   0,   253, 154, 41,  66, 1,   218, 0,   0,   0,
        128, 142, 22,  66,  1,   220, 0,   0,   0,  17,  174, 23,  66,  1,
        222, 0,   0,   0,   155, 2,   29,  66,  1,  225, 0,   0,   0,   162,
        100, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 233, 71,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_dep_b_t* test_msg =
        (msg_tracking_state_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 38.95457077026367;
    test_msg->states[0].sid.code = 0;
    test_msg->states[0].sid.reserved = 0;
    test_msg->states[0].sid.sat = 202;
    test_msg->states[0].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 35.813316345214844;
    test_msg->states[1].sid.code = 0;
    test_msg->states[1].sid.reserved = 0;
    test_msg->states[1].sid.sat = 203;
    test_msg->states[1].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 37.553924560546875;
    test_msg->states[2].sid.code = 0;
    test_msg->states[2].sid.reserved = 0;
    test_msg->states[2].sid.sat = 208;
    test_msg->states[2].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 38.88901901245117;
    test_msg->states[3].sid.code = 0;
    test_msg->states[3].sid.reserved = 0;
    test_msg->states[3].sid.sat = 212;
    test_msg->states[3].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 42.4013557434082;
    test_msg->states[4].sid.code = 0;
    test_msg->states[4].sid.reserved = 0;
    test_msg->states[4].sid.sat = 217;
    test_msg->states[4].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 37.63916015625;
    test_msg->states[5].sid.code = 0;
    test_msg->states[5].sid.reserved = 0;
    test_msg->states[5].sid.sat = 218;
    test_msg->states[5].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 37.919986724853516;
    test_msg->states[6].sid.code = 0;
    test_msg->states[6].sid.reserved = 0;
    test_msg->states[6].sid.sat = 220;
    test_msg->states[6].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 39.25254440307617;
    test_msg->states[7].sid.code = 0;
    test_msg->states[7].sid.reserved = 0;
    test_msg->states[7].sid.sat = 222;
    test_msg->states[7].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 42.59827423095703;
    test_msg->states[8].sid.code = 0;
    test_msg->states[8].sid.reserved = 0;
    test_msg->states[8].sid.sat = 225;
    test_msg->states[8].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = -1.0;
    test_msg->states[9].sid.code = 0;
    test_msg->states[9].sid.reserved = 0;
    test_msg->states[9].sid.sat = 0;
    test_msg->states[9].state = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = -1.0;
    test_msg->states[10].sid.code = 0;
    test_msg->states[10].sid.reserved = 0;
    test_msg->states[10].sid.sat = 0;
    test_msg->states[10].state = 0;
    sbp_payload_send(&sbp_state, 0x13, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x13,
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
    msg_tracking_state_dep_b_t* check_msg =
        (msg_tracking_state_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->states[0].cn0 * 100 - 38.9545707703 * 100) < 0.05,
        "incorrect value for states[0].cn0, expected 38.9545707703, is %f",
        check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].sid.code == 0,
                  "incorrect value for states[0].sid.code, expected 0, is %d",
                  check_msg->states[0].sid.code);
    ck_assert_msg(
        check_msg->states[0].sid.reserved == 0,
        "incorrect value for states[0].sid.reserved, expected 0, is %d",
        check_msg->states[0].sid.reserved);
    ck_assert_msg(check_msg->states[0].sid.sat == 202,
                  "incorrect value for states[0].sid.sat, expected 202, is %d",
                  check_msg->states[0].sid.sat);
    ck_assert_msg(check_msg->states[0].state == 1,
                  "incorrect value for states[0].state, expected 1, is %d",
                  check_msg->states[0].state);
    ck_assert_msg(
        (check_msg->states[1].cn0 * 100 - 35.8133163452 * 100) < 0.05,
        "incorrect value for states[1].cn0, expected 35.8133163452, is %f",
        check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].sid.code == 0,
                  "incorrect value for states[1].sid.code, expected 0, is %d",
                  check_msg->states[1].sid.code);
    ck_assert_msg(
        check_msg->states[1].sid.reserved == 0,
        "incorrect value for states[1].sid.reserved, expected 0, is %d",
        check_msg->states[1].sid.reserved);
    ck_assert_msg(check_msg->states[1].sid.sat == 203,
                  "incorrect value for states[1].sid.sat, expected 203, is %d",
                  check_msg->states[1].sid.sat);
    ck_assert_msg(check_msg->states[1].state == 1,
                  "incorrect value for states[1].state, expected 1, is %d",
                  check_msg->states[1].state);
    ck_assert_msg(
        (check_msg->states[2].cn0 * 100 - 37.5539245605 * 100) < 0.05,
        "incorrect value for states[2].cn0, expected 37.5539245605, is %f",
        check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].sid.code == 0,
                  "incorrect value for states[2].sid.code, expected 0, is %d",
                  check_msg->states[2].sid.code);
    ck_assert_msg(
        check_msg->states[2].sid.reserved == 0,
        "incorrect value for states[2].sid.reserved, expected 0, is %d",
        check_msg->states[2].sid.reserved);
    ck_assert_msg(check_msg->states[2].sid.sat == 208,
                  "incorrect value for states[2].sid.sat, expected 208, is %d",
                  check_msg->states[2].sid.sat);
    ck_assert_msg(check_msg->states[2].state == 1,
                  "incorrect value for states[2].state, expected 1, is %d",
                  check_msg->states[2].state);
    ck_assert_msg(
        (check_msg->states[3].cn0 * 100 - 38.8890190125 * 100) < 0.05,
        "incorrect value for states[3].cn0, expected 38.8890190125, is %f",
        check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].sid.code == 0,
                  "incorrect value for states[3].sid.code, expected 0, is %d",
                  check_msg->states[3].sid.code);
    ck_assert_msg(
        check_msg->states[3].sid.reserved == 0,
        "incorrect value for states[3].sid.reserved, expected 0, is %d",
        check_msg->states[3].sid.reserved);
    ck_assert_msg(check_msg->states[3].sid.sat == 212,
                  "incorrect value for states[3].sid.sat, expected 212, is %d",
                  check_msg->states[3].sid.sat);
    ck_assert_msg(check_msg->states[3].state == 1,
                  "incorrect value for states[3].state, expected 1, is %d",
                  check_msg->states[3].state);
    ck_assert_msg(
        (check_msg->states[4].cn0 * 100 - 42.4013557434 * 100) < 0.05,
        "incorrect value for states[4].cn0, expected 42.4013557434, is %f",
        check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].sid.code == 0,
                  "incorrect value for states[4].sid.code, expected 0, is %d",
                  check_msg->states[4].sid.code);
    ck_assert_msg(
        check_msg->states[4].sid.reserved == 0,
        "incorrect value for states[4].sid.reserved, expected 0, is %d",
        check_msg->states[4].sid.reserved);
    ck_assert_msg(check_msg->states[4].sid.sat == 217,
                  "incorrect value for states[4].sid.sat, expected 217, is %d",
                  check_msg->states[4].sid.sat);
    ck_assert_msg(check_msg->states[4].state == 1,
                  "incorrect value for states[4].state, expected 1, is %d",
                  check_msg->states[4].state);
    ck_assert_msg(
        (check_msg->states[5].cn0 * 100 - 37.6391601562 * 100) < 0.05,
        "incorrect value for states[5].cn0, expected 37.6391601562, is %f",
        check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].sid.code == 0,
                  "incorrect value for states[5].sid.code, expected 0, is %d",
                  check_msg->states[5].sid.code);
    ck_assert_msg(
        check_msg->states[5].sid.reserved == 0,
        "incorrect value for states[5].sid.reserved, expected 0, is %d",
        check_msg->states[5].sid.reserved);
    ck_assert_msg(check_msg->states[5].sid.sat == 218,
                  "incorrect value for states[5].sid.sat, expected 218, is %d",
                  check_msg->states[5].sid.sat);
    ck_assert_msg(check_msg->states[5].state == 1,
                  "incorrect value for states[5].state, expected 1, is %d",
                  check_msg->states[5].state);
    ck_assert_msg(
        (check_msg->states[6].cn0 * 100 - 37.9199867249 * 100) < 0.05,
        "incorrect value for states[6].cn0, expected 37.9199867249, is %f",
        check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].sid.code == 0,
                  "incorrect value for states[6].sid.code, expected 0, is %d",
                  check_msg->states[6].sid.code);
    ck_assert_msg(
        check_msg->states[6].sid.reserved == 0,
        "incorrect value for states[6].sid.reserved, expected 0, is %d",
        check_msg->states[6].sid.reserved);
    ck_assert_msg(check_msg->states[6].sid.sat == 220,
                  "incorrect value for states[6].sid.sat, expected 220, is %d",
                  check_msg->states[6].sid.sat);
    ck_assert_msg(check_msg->states[6].state == 1,
                  "incorrect value for states[6].state, expected 1, is %d",
                  check_msg->states[6].state);
    ck_assert_msg(
        (check_msg->states[7].cn0 * 100 - 39.2525444031 * 100) < 0.05,
        "incorrect value for states[7].cn0, expected 39.2525444031, is %f",
        check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].sid.code == 0,
                  "incorrect value for states[7].sid.code, expected 0, is %d",
                  check_msg->states[7].sid.code);
    ck_assert_msg(
        check_msg->states[7].sid.reserved == 0,
        "incorrect value for states[7].sid.reserved, expected 0, is %d",
        check_msg->states[7].sid.reserved);
    ck_assert_msg(check_msg->states[7].sid.sat == 222,
                  "incorrect value for states[7].sid.sat, expected 222, is %d",
                  check_msg->states[7].sid.sat);
    ck_assert_msg(check_msg->states[7].state == 1,
                  "incorrect value for states[7].state, expected 1, is %d",
                  check_msg->states[7].state);
    ck_assert_msg(
        (check_msg->states[8].cn0 * 100 - 42.598274231 * 100) < 0.05,
        "incorrect value for states[8].cn0, expected 42.598274231, is %f",
        check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].sid.code == 0,
                  "incorrect value for states[8].sid.code, expected 0, is %d",
                  check_msg->states[8].sid.code);
    ck_assert_msg(
        check_msg->states[8].sid.reserved == 0,
        "incorrect value for states[8].sid.reserved, expected 0, is %d",
        check_msg->states[8].sid.reserved);
    ck_assert_msg(check_msg->states[8].sid.sat == 225,
                  "incorrect value for states[8].sid.sat, expected 225, is %d",
                  check_msg->states[8].sid.sat);
    ck_assert_msg(check_msg->states[8].state == 1,
                  "incorrect value for states[8].state, expected 1, is %d",
                  check_msg->states[8].state);
    ck_assert_msg((check_msg->states[9].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[9].cn0, expected -1.0, is %f",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].sid.code == 0,
                  "incorrect value for states[9].sid.code, expected 0, is %d",
                  check_msg->states[9].sid.code);
    ck_assert_msg(
        check_msg->states[9].sid.reserved == 0,
        "incorrect value for states[9].sid.reserved, expected 0, is %d",
        check_msg->states[9].sid.reserved);
    ck_assert_msg(check_msg->states[9].sid.sat == 0,
                  "incorrect value for states[9].sid.sat, expected 0, is %d",
                  check_msg->states[9].sid.sat);
    ck_assert_msg(check_msg->states[9].state == 0,
                  "incorrect value for states[9].state, expected 0, is %d",
                  check_msg->states[9].state);
    ck_assert_msg((check_msg->states[10].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[10].cn0, expected -1.0, is %f",
                  check_msg->states[10].cn0);
    ck_assert_msg(check_msg->states[10].sid.code == 0,
                  "incorrect value for states[10].sid.code, expected 0, is %d",
                  check_msg->states[10].sid.code);
    ck_assert_msg(
        check_msg->states[10].sid.reserved == 0,
        "incorrect value for states[10].sid.reserved, expected 0, is %d",
        check_msg->states[10].sid.reserved);
    ck_assert_msg(check_msg->states[10].sid.sat == 0,
                  "incorrect value for states[10].sid.sat, expected 0, is %d",
                  check_msg->states[10].sid.sat);
    ck_assert_msg(check_msg->states[10].state == 0,
                  "incorrect value for states[10].state, expected 0, is %d",
                  check_msg->states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x13, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x13, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  19,  0,   246, 215, 99,  1,   202, 0,   0,   0,   120, 122, 29,
        66,  1,   203, 0,   0,   0,   66,  22,  18,  66,  1,   208, 0,   0,
        0,   153, 163, 24,  66,  1,   212, 0,   0,   0,   178, 204, 28,  66,
        1,   217, 0,   0,   0,   220, 59,  38,  66,  1,   218, 0,   0,   0,
        161, 27,  20,  66,  1,   220, 0,   0,   0,   125, 107, 24,  66,  1,
        222, 0,   0,   0,   242, 46,  28,  66,  1,   225, 0,   0,   0,   231,
        130, 41,  66,  0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 73,  193,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_dep_b_t* test_msg =
        (msg_tracking_state_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 39.369598388671875;
    test_msg->states[0].sid.code = 0;
    test_msg->states[0].sid.reserved = 0;
    test_msg->states[0].sid.sat = 202;
    test_msg->states[0].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 36.52173614501953;
    test_msg->states[1].sid.code = 0;
    test_msg->states[1].sid.reserved = 0;
    test_msg->states[1].sid.sat = 203;
    test_msg->states[1].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 38.15976333618164;
    test_msg->states[2].sid.code = 0;
    test_msg->states[2].sid.reserved = 0;
    test_msg->states[2].sid.sat = 208;
    test_msg->states[2].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 39.19989776611328;
    test_msg->states[3].sid.code = 0;
    test_msg->states[3].sid.reserved = 0;
    test_msg->states[3].sid.sat = 212;
    test_msg->states[3].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 41.55845642089844;
    test_msg->states[4].sid.code = 0;
    test_msg->states[4].sid.reserved = 0;
    test_msg->states[4].sid.sat = 217;
    test_msg->states[4].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 37.026981353759766;
    test_msg->states[5].sid.code = 0;
    test_msg->states[5].sid.reserved = 0;
    test_msg->states[5].sid.sat = 218;
    test_msg->states[5].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 38.1049690246582;
    test_msg->states[6].sid.code = 0;
    test_msg->states[6].sid.reserved = 0;
    test_msg->states[6].sid.sat = 220;
    test_msg->states[6].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 39.04584503173828;
    test_msg->states[7].sid.code = 0;
    test_msg->states[7].sid.reserved = 0;
    test_msg->states[7].sid.sat = 222;
    test_msg->states[7].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 42.37783432006836;
    test_msg->states[8].sid.code = 0;
    test_msg->states[8].sid.reserved = 0;
    test_msg->states[8].sid.sat = 225;
    test_msg->states[8].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = -1.0;
    test_msg->states[9].sid.code = 0;
    test_msg->states[9].sid.reserved = 0;
    test_msg->states[9].sid.sat = 0;
    test_msg->states[9].state = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = -1.0;
    test_msg->states[10].sid.code = 0;
    test_msg->states[10].sid.reserved = 0;
    test_msg->states[10].sid.sat = 0;
    test_msg->states[10].state = 0;
    sbp_payload_send(&sbp_state, 0x13, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x13,
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
    msg_tracking_state_dep_b_t* check_msg =
        (msg_tracking_state_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->states[0].cn0 * 100 - 39.3695983887 * 100) < 0.05,
        "incorrect value for states[0].cn0, expected 39.3695983887, is %f",
        check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].sid.code == 0,
                  "incorrect value for states[0].sid.code, expected 0, is %d",
                  check_msg->states[0].sid.code);
    ck_assert_msg(
        check_msg->states[0].sid.reserved == 0,
        "incorrect value for states[0].sid.reserved, expected 0, is %d",
        check_msg->states[0].sid.reserved);
    ck_assert_msg(check_msg->states[0].sid.sat == 202,
                  "incorrect value for states[0].sid.sat, expected 202, is %d",
                  check_msg->states[0].sid.sat);
    ck_assert_msg(check_msg->states[0].state == 1,
                  "incorrect value for states[0].state, expected 1, is %d",
                  check_msg->states[0].state);
    ck_assert_msg(
        (check_msg->states[1].cn0 * 100 - 36.521736145 * 100) < 0.05,
        "incorrect value for states[1].cn0, expected 36.521736145, is %f",
        check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].sid.code == 0,
                  "incorrect value for states[1].sid.code, expected 0, is %d",
                  check_msg->states[1].sid.code);
    ck_assert_msg(
        check_msg->states[1].sid.reserved == 0,
        "incorrect value for states[1].sid.reserved, expected 0, is %d",
        check_msg->states[1].sid.reserved);
    ck_assert_msg(check_msg->states[1].sid.sat == 203,
                  "incorrect value for states[1].sid.sat, expected 203, is %d",
                  check_msg->states[1].sid.sat);
    ck_assert_msg(check_msg->states[1].state == 1,
                  "incorrect value for states[1].state, expected 1, is %d",
                  check_msg->states[1].state);
    ck_assert_msg(
        (check_msg->states[2].cn0 * 100 - 38.1597633362 * 100) < 0.05,
        "incorrect value for states[2].cn0, expected 38.1597633362, is %f",
        check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].sid.code == 0,
                  "incorrect value for states[2].sid.code, expected 0, is %d",
                  check_msg->states[2].sid.code);
    ck_assert_msg(
        check_msg->states[2].sid.reserved == 0,
        "incorrect value for states[2].sid.reserved, expected 0, is %d",
        check_msg->states[2].sid.reserved);
    ck_assert_msg(check_msg->states[2].sid.sat == 208,
                  "incorrect value for states[2].sid.sat, expected 208, is %d",
                  check_msg->states[2].sid.sat);
    ck_assert_msg(check_msg->states[2].state == 1,
                  "incorrect value for states[2].state, expected 1, is %d",
                  check_msg->states[2].state);
    ck_assert_msg(
        (check_msg->states[3].cn0 * 100 - 39.1998977661 * 100) < 0.05,
        "incorrect value for states[3].cn0, expected 39.1998977661, is %f",
        check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].sid.code == 0,
                  "incorrect value for states[3].sid.code, expected 0, is %d",
                  check_msg->states[3].sid.code);
    ck_assert_msg(
        check_msg->states[3].sid.reserved == 0,
        "incorrect value for states[3].sid.reserved, expected 0, is %d",
        check_msg->states[3].sid.reserved);
    ck_assert_msg(check_msg->states[3].sid.sat == 212,
                  "incorrect value for states[3].sid.sat, expected 212, is %d",
                  check_msg->states[3].sid.sat);
    ck_assert_msg(check_msg->states[3].state == 1,
                  "incorrect value for states[3].state, expected 1, is %d",
                  check_msg->states[3].state);
    ck_assert_msg(
        (check_msg->states[4].cn0 * 100 - 41.5584564209 * 100) < 0.05,
        "incorrect value for states[4].cn0, expected 41.5584564209, is %f",
        check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].sid.code == 0,
                  "incorrect value for states[4].sid.code, expected 0, is %d",
                  check_msg->states[4].sid.code);
    ck_assert_msg(
        check_msg->states[4].sid.reserved == 0,
        "incorrect value for states[4].sid.reserved, expected 0, is %d",
        check_msg->states[4].sid.reserved);
    ck_assert_msg(check_msg->states[4].sid.sat == 217,
                  "incorrect value for states[4].sid.sat, expected 217, is %d",
                  check_msg->states[4].sid.sat);
    ck_assert_msg(check_msg->states[4].state == 1,
                  "incorrect value for states[4].state, expected 1, is %d",
                  check_msg->states[4].state);
    ck_assert_msg(
        (check_msg->states[5].cn0 * 100 - 37.0269813538 * 100) < 0.05,
        "incorrect value for states[5].cn0, expected 37.0269813538, is %f",
        check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].sid.code == 0,
                  "incorrect value for states[5].sid.code, expected 0, is %d",
                  check_msg->states[5].sid.code);
    ck_assert_msg(
        check_msg->states[5].sid.reserved == 0,
        "incorrect value for states[5].sid.reserved, expected 0, is %d",
        check_msg->states[5].sid.reserved);
    ck_assert_msg(check_msg->states[5].sid.sat == 218,
                  "incorrect value for states[5].sid.sat, expected 218, is %d",
                  check_msg->states[5].sid.sat);
    ck_assert_msg(check_msg->states[5].state == 1,
                  "incorrect value for states[5].state, expected 1, is %d",
                  check_msg->states[5].state);
    ck_assert_msg(
        (check_msg->states[6].cn0 * 100 - 38.1049690247 * 100) < 0.05,
        "incorrect value for states[6].cn0, expected 38.1049690247, is %f",
        check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].sid.code == 0,
                  "incorrect value for states[6].sid.code, expected 0, is %d",
                  check_msg->states[6].sid.code);
    ck_assert_msg(
        check_msg->states[6].sid.reserved == 0,
        "incorrect value for states[6].sid.reserved, expected 0, is %d",
        check_msg->states[6].sid.reserved);
    ck_assert_msg(check_msg->states[6].sid.sat == 220,
                  "incorrect value for states[6].sid.sat, expected 220, is %d",
                  check_msg->states[6].sid.sat);
    ck_assert_msg(check_msg->states[6].state == 1,
                  "incorrect value for states[6].state, expected 1, is %d",
                  check_msg->states[6].state);
    ck_assert_msg(
        (check_msg->states[7].cn0 * 100 - 39.0458450317 * 100) < 0.05,
        "incorrect value for states[7].cn0, expected 39.0458450317, is %f",
        check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].sid.code == 0,
                  "incorrect value for states[7].sid.code, expected 0, is %d",
                  check_msg->states[7].sid.code);
    ck_assert_msg(
        check_msg->states[7].sid.reserved == 0,
        "incorrect value for states[7].sid.reserved, expected 0, is %d",
        check_msg->states[7].sid.reserved);
    ck_assert_msg(check_msg->states[7].sid.sat == 222,
                  "incorrect value for states[7].sid.sat, expected 222, is %d",
                  check_msg->states[7].sid.sat);
    ck_assert_msg(check_msg->states[7].state == 1,
                  "incorrect value for states[7].state, expected 1, is %d",
                  check_msg->states[7].state);
    ck_assert_msg(
        (check_msg->states[8].cn0 * 100 - 42.3778343201 * 100) < 0.05,
        "incorrect value for states[8].cn0, expected 42.3778343201, is %f",
        check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].sid.code == 0,
                  "incorrect value for states[8].sid.code, expected 0, is %d",
                  check_msg->states[8].sid.code);
    ck_assert_msg(
        check_msg->states[8].sid.reserved == 0,
        "incorrect value for states[8].sid.reserved, expected 0, is %d",
        check_msg->states[8].sid.reserved);
    ck_assert_msg(check_msg->states[8].sid.sat == 225,
                  "incorrect value for states[8].sid.sat, expected 225, is %d",
                  check_msg->states[8].sid.sat);
    ck_assert_msg(check_msg->states[8].state == 1,
                  "incorrect value for states[8].state, expected 1, is %d",
                  check_msg->states[8].state);
    ck_assert_msg((check_msg->states[9].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[9].cn0, expected -1.0, is %f",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].sid.code == 0,
                  "incorrect value for states[9].sid.code, expected 0, is %d",
                  check_msg->states[9].sid.code);
    ck_assert_msg(
        check_msg->states[9].sid.reserved == 0,
        "incorrect value for states[9].sid.reserved, expected 0, is %d",
        check_msg->states[9].sid.reserved);
    ck_assert_msg(check_msg->states[9].sid.sat == 0,
                  "incorrect value for states[9].sid.sat, expected 0, is %d",
                  check_msg->states[9].sid.sat);
    ck_assert_msg(check_msg->states[9].state == 0,
                  "incorrect value for states[9].state, expected 0, is %d",
                  check_msg->states[9].state);
    ck_assert_msg((check_msg->states[10].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[10].cn0, expected -1.0, is %f",
                  check_msg->states[10].cn0);
    ck_assert_msg(check_msg->states[10].sid.code == 0,
                  "incorrect value for states[10].sid.code, expected 0, is %d",
                  check_msg->states[10].sid.code);
    ck_assert_msg(
        check_msg->states[10].sid.reserved == 0,
        "incorrect value for states[10].sid.reserved, expected 0, is %d",
        check_msg->states[10].sid.reserved);
    ck_assert_msg(check_msg->states[10].sid.sat == 0,
                  "incorrect value for states[10].sid.sat, expected 0, is %d",
                  check_msg->states[10].sid.sat);
    ck_assert_msg(check_msg->states[10].state == 0,
                  "incorrect value for states[10].state, expected 0, is %d",
                  check_msg->states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x13, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x13, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   103, 208, 30,
        66,  1,   203, 0,   0,   0,   117, 24,  18, 66,  1,   208, 0,   0,
        0,   200, 173, 20,  66,  1,   212, 0,   0,  0,   137, 68,  27,  66,
        1,   217, 0,   0,   0,   243, 51,  40,  66, 1,   218, 0,   0,   0,
        225, 58,  23,  66,  1,   220, 0,   0,   0,  132, 221, 22,  66,  1,
        222, 0,   0,   0,   157, 29,  26,  66,  1,  225, 0,   0,   0,   133,
        21,  41,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 126, 47,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_dep_b_t* test_msg =
        (msg_tracking_state_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 39.70351791381836;
    test_msg->states[0].sid.code = 0;
    test_msg->states[0].sid.reserved = 0;
    test_msg->states[0].sid.sat = 202;
    test_msg->states[0].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 36.52388381958008;
    test_msg->states[1].sid.code = 0;
    test_msg->states[1].sid.reserved = 0;
    test_msg->states[1].sid.sat = 203;
    test_msg->states[1].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 37.169708251953125;
    test_msg->states[2].sid.code = 0;
    test_msg->states[2].sid.reserved = 0;
    test_msg->states[2].sid.sat = 208;
    test_msg->states[2].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 38.81692886352539;
    test_msg->states[3].sid.code = 0;
    test_msg->states[3].sid.reserved = 0;
    test_msg->states[3].sid.sat = 212;
    test_msg->states[3].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 42.05073165893555;
    test_msg->states[4].sid.code = 0;
    test_msg->states[4].sid.reserved = 0;
    test_msg->states[4].sid.sat = 217;
    test_msg->states[4].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 37.807498931884766;
    test_msg->states[5].sid.code = 0;
    test_msg->states[5].sid.reserved = 0;
    test_msg->states[5].sid.sat = 218;
    test_msg->states[5].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 37.71632385253906;
    test_msg->states[6].sid.code = 0;
    test_msg->states[6].sid.reserved = 0;
    test_msg->states[6].sid.sat = 220;
    test_msg->states[6].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 38.5289192199707;
    test_msg->states[7].sid.code = 0;
    test_msg->states[7].sid.reserved = 0;
    test_msg->states[7].sid.sat = 222;
    test_msg->states[7].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 42.27101516723633;
    test_msg->states[8].sid.code = 0;
    test_msg->states[8].sid.reserved = 0;
    test_msg->states[8].sid.sat = 225;
    test_msg->states[8].state = 1;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = -1.0;
    test_msg->states[9].sid.code = 0;
    test_msg->states[9].sid.reserved = 0;
    test_msg->states[9].sid.sat = 0;
    test_msg->states[9].state = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = -1.0;
    test_msg->states[10].sid.code = 0;
    test_msg->states[10].sid.reserved = 0;
    test_msg->states[10].sid.sat = 0;
    test_msg->states[10].state = 0;
    sbp_payload_send(&sbp_state, 0x13, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x13,
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
    msg_tracking_state_dep_b_t* check_msg =
        (msg_tracking_state_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->states[0].cn0 * 100 - 39.7035179138 * 100) < 0.05,
        "incorrect value for states[0].cn0, expected 39.7035179138, is %f",
        check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].sid.code == 0,
                  "incorrect value for states[0].sid.code, expected 0, is %d",
                  check_msg->states[0].sid.code);
    ck_assert_msg(
        check_msg->states[0].sid.reserved == 0,
        "incorrect value for states[0].sid.reserved, expected 0, is %d",
        check_msg->states[0].sid.reserved);
    ck_assert_msg(check_msg->states[0].sid.sat == 202,
                  "incorrect value for states[0].sid.sat, expected 202, is %d",
                  check_msg->states[0].sid.sat);
    ck_assert_msg(check_msg->states[0].state == 1,
                  "incorrect value for states[0].state, expected 1, is %d",
                  check_msg->states[0].state);
    ck_assert_msg(
        (check_msg->states[1].cn0 * 100 - 36.5238838196 * 100) < 0.05,
        "incorrect value for states[1].cn0, expected 36.5238838196, is %f",
        check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].sid.code == 0,
                  "incorrect value for states[1].sid.code, expected 0, is %d",
                  check_msg->states[1].sid.code);
    ck_assert_msg(
        check_msg->states[1].sid.reserved == 0,
        "incorrect value for states[1].sid.reserved, expected 0, is %d",
        check_msg->states[1].sid.reserved);
    ck_assert_msg(check_msg->states[1].sid.sat == 203,
                  "incorrect value for states[1].sid.sat, expected 203, is %d",
                  check_msg->states[1].sid.sat);
    ck_assert_msg(check_msg->states[1].state == 1,
                  "incorrect value for states[1].state, expected 1, is %d",
                  check_msg->states[1].state);
    ck_assert_msg(
        (check_msg->states[2].cn0 * 100 - 37.169708252 * 100) < 0.05,
        "incorrect value for states[2].cn0, expected 37.169708252, is %f",
        check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].sid.code == 0,
                  "incorrect value for states[2].sid.code, expected 0, is %d",
                  check_msg->states[2].sid.code);
    ck_assert_msg(
        check_msg->states[2].sid.reserved == 0,
        "incorrect value for states[2].sid.reserved, expected 0, is %d",
        check_msg->states[2].sid.reserved);
    ck_assert_msg(check_msg->states[2].sid.sat == 208,
                  "incorrect value for states[2].sid.sat, expected 208, is %d",
                  check_msg->states[2].sid.sat);
    ck_assert_msg(check_msg->states[2].state == 1,
                  "incorrect value for states[2].state, expected 1, is %d",
                  check_msg->states[2].state);
    ck_assert_msg(
        (check_msg->states[3].cn0 * 100 - 38.8169288635 * 100) < 0.05,
        "incorrect value for states[3].cn0, expected 38.8169288635, is %f",
        check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].sid.code == 0,
                  "incorrect value for states[3].sid.code, expected 0, is %d",
                  check_msg->states[3].sid.code);
    ck_assert_msg(
        check_msg->states[3].sid.reserved == 0,
        "incorrect value for states[3].sid.reserved, expected 0, is %d",
        check_msg->states[3].sid.reserved);
    ck_assert_msg(check_msg->states[3].sid.sat == 212,
                  "incorrect value for states[3].sid.sat, expected 212, is %d",
                  check_msg->states[3].sid.sat);
    ck_assert_msg(check_msg->states[3].state == 1,
                  "incorrect value for states[3].state, expected 1, is %d",
                  check_msg->states[3].state);
    ck_assert_msg(
        (check_msg->states[4].cn0 * 100 - 42.0507316589 * 100) < 0.05,
        "incorrect value for states[4].cn0, expected 42.0507316589, is %f",
        check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].sid.code == 0,
                  "incorrect value for states[4].sid.code, expected 0, is %d",
                  check_msg->states[4].sid.code);
    ck_assert_msg(
        check_msg->states[4].sid.reserved == 0,
        "incorrect value for states[4].sid.reserved, expected 0, is %d",
        check_msg->states[4].sid.reserved);
    ck_assert_msg(check_msg->states[4].sid.sat == 217,
                  "incorrect value for states[4].sid.sat, expected 217, is %d",
                  check_msg->states[4].sid.sat);
    ck_assert_msg(check_msg->states[4].state == 1,
                  "incorrect value for states[4].state, expected 1, is %d",
                  check_msg->states[4].state);
    ck_assert_msg(
        (check_msg->states[5].cn0 * 100 - 37.8074989319 * 100) < 0.05,
        "incorrect value for states[5].cn0, expected 37.8074989319, is %f",
        check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].sid.code == 0,
                  "incorrect value for states[5].sid.code, expected 0, is %d",
                  check_msg->states[5].sid.code);
    ck_assert_msg(
        check_msg->states[5].sid.reserved == 0,
        "incorrect value for states[5].sid.reserved, expected 0, is %d",
        check_msg->states[5].sid.reserved);
    ck_assert_msg(check_msg->states[5].sid.sat == 218,
                  "incorrect value for states[5].sid.sat, expected 218, is %d",
                  check_msg->states[5].sid.sat);
    ck_assert_msg(check_msg->states[5].state == 1,
                  "incorrect value for states[5].state, expected 1, is %d",
                  check_msg->states[5].state);
    ck_assert_msg(
        (check_msg->states[6].cn0 * 100 - 37.7163238525 * 100) < 0.05,
        "incorrect value for states[6].cn0, expected 37.7163238525, is %f",
        check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].sid.code == 0,
                  "incorrect value for states[6].sid.code, expected 0, is %d",
                  check_msg->states[6].sid.code);
    ck_assert_msg(
        check_msg->states[6].sid.reserved == 0,
        "incorrect value for states[6].sid.reserved, expected 0, is %d",
        check_msg->states[6].sid.reserved);
    ck_assert_msg(check_msg->states[6].sid.sat == 220,
                  "incorrect value for states[6].sid.sat, expected 220, is %d",
                  check_msg->states[6].sid.sat);
    ck_assert_msg(check_msg->states[6].state == 1,
                  "incorrect value for states[6].state, expected 1, is %d",
                  check_msg->states[6].state);
    ck_assert_msg(
        (check_msg->states[7].cn0 * 100 - 38.52891922 * 100) < 0.05,
        "incorrect value for states[7].cn0, expected 38.52891922, is %f",
        check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].sid.code == 0,
                  "incorrect value for states[7].sid.code, expected 0, is %d",
                  check_msg->states[7].sid.code);
    ck_assert_msg(
        check_msg->states[7].sid.reserved == 0,
        "incorrect value for states[7].sid.reserved, expected 0, is %d",
        check_msg->states[7].sid.reserved);
    ck_assert_msg(check_msg->states[7].sid.sat == 222,
                  "incorrect value for states[7].sid.sat, expected 222, is %d",
                  check_msg->states[7].sid.sat);
    ck_assert_msg(check_msg->states[7].state == 1,
                  "incorrect value for states[7].state, expected 1, is %d",
                  check_msg->states[7].state);
    ck_assert_msg(
        (check_msg->states[8].cn0 * 100 - 42.2710151672 * 100) < 0.05,
        "incorrect value for states[8].cn0, expected 42.2710151672, is %f",
        check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].sid.code == 0,
                  "incorrect value for states[8].sid.code, expected 0, is %d",
                  check_msg->states[8].sid.code);
    ck_assert_msg(
        check_msg->states[8].sid.reserved == 0,
        "incorrect value for states[8].sid.reserved, expected 0, is %d",
        check_msg->states[8].sid.reserved);
    ck_assert_msg(check_msg->states[8].sid.sat == 225,
                  "incorrect value for states[8].sid.sat, expected 225, is %d",
                  check_msg->states[8].sid.sat);
    ck_assert_msg(check_msg->states[8].state == 1,
                  "incorrect value for states[8].state, expected 1, is %d",
                  check_msg->states[8].state);
    ck_assert_msg((check_msg->states[9].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[9].cn0, expected -1.0, is %f",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].sid.code == 0,
                  "incorrect value for states[9].sid.code, expected 0, is %d",
                  check_msg->states[9].sid.code);
    ck_assert_msg(
        check_msg->states[9].sid.reserved == 0,
        "incorrect value for states[9].sid.reserved, expected 0, is %d",
        check_msg->states[9].sid.reserved);
    ck_assert_msg(check_msg->states[9].sid.sat == 0,
                  "incorrect value for states[9].sid.sat, expected 0, is %d",
                  check_msg->states[9].sid.sat);
    ck_assert_msg(check_msg->states[9].state == 0,
                  "incorrect value for states[9].state, expected 0, is %d",
                  check_msg->states[9].state);
    ck_assert_msg((check_msg->states[10].cn0 * 100 - -1.0 * 100) < 0.05,
                  "incorrect value for states[10].cn0, expected -1.0, is %f",
                  check_msg->states[10].cn0);
    ck_assert_msg(check_msg->states[10].sid.code == 0,
                  "incorrect value for states[10].sid.code, expected 0, is %d",
                  check_msg->states[10].sid.code);
    ck_assert_msg(
        check_msg->states[10].sid.reserved == 0,
        "incorrect value for states[10].sid.reserved, expected 0, is %d",
        check_msg->states[10].sid.reserved);
    ck_assert_msg(check_msg->states[10].sid.sat == 0,
                  "incorrect value for states[10].sid.sat, expected 0, is %d",
                  check_msg->states[10].sid.sat);
    ck_assert_msg(check_msg->states[10].state == 0,
                  "incorrect value for states[10].state, expected 0, is %d",
                  check_msg->states[10].state);
  }
}
END_TEST

Suite* legacy_auto_check_sbp_tracking_MsgTrackingState_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_tracking_MsgTrackingState");
  TCase* tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_tracking_MsgTrackingState");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_tracking_MsgTrackingState);
  suite_add_tcase(s, tc_acq);
  return s;
}