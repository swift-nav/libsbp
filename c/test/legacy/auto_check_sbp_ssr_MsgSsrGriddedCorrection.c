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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrection.yaml by
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
#include <libsbp/legacy/ssr.h>

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

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrection) {
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

    sbp_payload_callback_register(&sbp_state, 0x5fc, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x5fc, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  252, 5,   196, 249, 253, 21,  14,  151, 50,  120, 133, 29,  151,
        174, 229, 151, 189, 204, 196, 105, 170, 120, 149, 169, 37,  244, 78,
        72,  140, 101, 2,   173, 88,  70,  180, 54,  152, 115, 78,  201, 161,
        23,  135, 152, 98,  61,  75,  178, 120, 229, 146, 55,  58,  169, 234,
        230, 69,  172, 191, 127, 146, 89,  150, 91,  111, 225, 41,  17,  119,
        52,  166, 166, 120, 57,  221, 12,  3,   156, 70,  156, 35,  127, 8,
        127, 58,  128, 55,  115, 80,  157, 122, 153, 124, 27,  128, 98,  103,
        204, 75,  238, 128, 226, 148, 248, 61,  216, 208, 149, 167, 224, 40,
        144, 186, 157, 227, 72,  240, 100, 35,  12,  212, 7,   59,  176, 81,
        86,  27,  24,  155, 67,  43,  132, 45,  203, 44,  6,   112, 183, 231,
        176, 79,  194, 253, 247, 103, 91,  226, 116, 148, 23,  62,  227, 240,
        29,  219, 205, 18,  242, 207, 72,  71,  79,  37,  42,  176, 201, 202,
        91,  105, 115, 146, 59,  110, 44,  109, 128, 183, 185, 67,  31,  165,
        92,  79,  189, 180, 94,  7,   162, 121, 156, 210, 47,  7,   7,   205,
        174, 41,  241, 129, 210, 43,  101, 186, 208, 195, 226, 247, 187, 219,
        160, 120, 192, 102, 166, 42,  246, 173, 94,  102, 156, 222, 30,  35,
        247, 64,  189, 137, 204, 220, 32,  71,  222, 222, 201, 246, 3,   25,
        45,  251, 239, 115, 88,  218, 10,  209, 120, 65,  175, 131, 194, 41,
        174, 137, 17,  68,  28,  253, 42,  178, 35,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_gridded_correction_t *test_msg =
        (msg_ssr_gridded_correction_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.iod_atmo = 170;
    test_msg->header.num_msgs = 48535;
    test_msg->header.seq_num = 50380;
    test_msg->header.tile_id = 12951;
    test_msg->header.tile_set_id = 3605;
    test_msg->header.time.tow = 2535294328;
    test_msg->header.time.wn = 58798;
    test_msg->header.tropo_quality_indicator = 120;
    test_msg->header.update_interval = 105;
    test_msg->index = 43413;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[0].residual = -21246;
    test_msg->stec_residuals[0].stddev = 88;
    test_msg->stec_residuals[0].sv_id.constellation = 101;
    test_msg->stec_residuals[0].sv_id.satId = 140;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[1].residual = -26570;
    test_msg->stec_residuals[1].stddev = 115;
    test_msg->stec_residuals[1].sv_id.constellation = 180;
    test_msg->stec_residuals[1].sv_id.satId = 70;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[2].residual = 6049;
    test_msg->stec_residuals[2].stddev = 135;
    test_msg->stec_residuals[2].sv_id.constellation = 201;
    test_msg->stec_residuals[2].sv_id.satId = 78;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[3].residual = 19261;
    test_msg->stec_residuals[3].stddev = 178;
    test_msg->stec_residuals[3].sv_id.constellation = 98;
    test_msg->stec_residuals[3].sv_id.satId = 152;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[4].residual = 14226;
    test_msg->stec_residuals[4].stddev = 58;
    test_msg->stec_residuals[4].sv_id.constellation = 229;
    test_msg->stec_residuals[4].sv_id.satId = 120;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[5].residual = 17894;
    test_msg->stec_residuals[5].stddev = 172;
    test_msg->stec_residuals[5].sv_id.constellation = 234;
    test_msg->stec_residuals[5].sv_id.satId = 169;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[6].residual = 22930;
    test_msg->stec_residuals[6].stddev = 150;
    test_msg->stec_residuals[6].sv_id.constellation = 127;
    test_msg->stec_residuals[6].sv_id.satId = 191;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[7].residual = 10721;
    test_msg->stec_residuals[7].stddev = 17;
    test_msg->stec_residuals[7].sv_id.constellation = 111;
    test_msg->stec_residuals[7].sv_id.satId = 91;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[8].residual = -22874;
    test_msg->stec_residuals[8].stddev = 120;
    test_msg->stec_residuals[8].sv_id.constellation = 52;
    test_msg->stec_residuals[8].sv_id.satId = 119;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[9].residual = 780;
    test_msg->stec_residuals[9].stddev = 156;
    test_msg->stec_residuals[9].sv_id.constellation = 221;
    test_msg->stec_residuals[9].sv_id.satId = 57;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[10].residual = 32547;
    test_msg->stec_residuals[10].stddev = 8;
    test_msg->stec_residuals[10].sv_id.constellation = 156;
    test_msg->stec_residuals[10].sv_id.satId = 70;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[11].residual = 14208;
    test_msg->stec_residuals[11].stddev = 115;
    test_msg->stec_residuals[11].sv_id.constellation = 58;
    test_msg->stec_residuals[11].sv_id.satId = 127;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[12].residual = -26246;
    test_msg->stec_residuals[12].stddev = 124;
    test_msg->stec_residuals[12].sv_id.constellation = 157;
    test_msg->stec_residuals[12].sv_id.satId = 80;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[13].residual = 26466;
    test_msg->stec_residuals[13].stddev = 204;
    test_msg->stec_residuals[13].sv_id.constellation = 128;
    test_msg->stec_residuals[13].sv_id.satId = 27;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[14].residual = -7552;
    test_msg->stec_residuals[14].stddev = 148;
    test_msg->stec_residuals[14].sv_id.constellation = 238;
    test_msg->stec_residuals[14].sv_id.satId = 75;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[15].residual = -12072;
    test_msg->stec_residuals[15].stddev = 149;
    test_msg->stec_residuals[15].sv_id.constellation = 61;
    test_msg->stec_residuals[15].sv_id.satId = 248;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[16].residual = -28632;
    test_msg->stec_residuals[16].stddev = 186;
    test_msg->stec_residuals[16].sv_id.constellation = 224;
    test_msg->stec_residuals[16].sv_id.satId = 167;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[17].residual = -4024;
    test_msg->stec_residuals[17].stddev = 100;
    test_msg->stec_residuals[17].sv_id.constellation = 227;
    test_msg->stec_residuals[17].sv_id.satId = 157;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[18].residual = 2004;
    test_msg->stec_residuals[18].stddev = 59;
    test_msg->stec_residuals[18].sv_id.constellation = 12;
    test_msg->stec_residuals[18].sv_id.satId = 35;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[19].residual = 6998;
    test_msg->stec_residuals[19].stddev = 24;
    test_msg->stec_residuals[19].sv_id.constellation = 81;
    test_msg->stec_residuals[19].sv_id.satId = 176;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[20].residual = -31701;
    test_msg->stec_residuals[20].stddev = 45;
    test_msg->stec_residuals[20].sv_id.constellation = 67;
    test_msg->stec_residuals[20].sv_id.satId = 155;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[21].residual = 28678;
    test_msg->stec_residuals[21].stddev = 183;
    test_msg->stec_residuals[21].sv_id.constellation = 44;
    test_msg->stec_residuals[21].sv_id.satId = 203;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[22].residual = -15793;
    test_msg->stec_residuals[22].stddev = 253;
    test_msg->stec_residuals[22].sv_id.constellation = 176;
    test_msg->stec_residuals[22].sv_id.satId = 231;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[23].residual = -7589;
    test_msg->stec_residuals[23].stddev = 116;
    test_msg->stec_residuals[23].sv_id.constellation = 103;
    test_msg->stec_residuals[23].sv_id.satId = 247;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[24].residual = -7362;
    test_msg->stec_residuals[24].stddev = 240;
    test_msg->stec_residuals[24].sv_id.constellation = 23;
    test_msg->stec_residuals[24].sv_id.satId = 148;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[25].residual = 4813;
    test_msg->stec_residuals[25].stddev = 242;
    test_msg->stec_residuals[25].sv_id.constellation = 219;
    test_msg->stec_residuals[25].sv_id.satId = 29;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[26].residual = 20295;
    test_msg->stec_residuals[26].stddev = 37;
    test_msg->stec_residuals[26].sv_id.constellation = 72;
    test_msg->stec_residuals[26].sv_id.satId = 207;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[27].residual = -13623;
    test_msg->stec_residuals[27].stddev = 91;
    test_msg->stec_residuals[27].sv_id.constellation = 176;
    test_msg->stec_residuals[27].sv_id.satId = 42;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[28].residual = 15250;
    test_msg->stec_residuals[28].stddev = 110;
    test_msg->stec_residuals[28].sv_id.constellation = 115;
    test_msg->stec_residuals[28].sv_id.satId = 105;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[29].residual = -18560;
    test_msg->stec_residuals[29].stddev = 185;
    test_msg->stec_residuals[29].sv_id.constellation = 109;
    test_msg->stec_residuals[29].sv_id.satId = 44;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[30].residual = 23717;
    test_msg->stec_residuals[30].stddev = 79;
    test_msg->stec_residuals[30].sv_id.constellation = 31;
    test_msg->stec_residuals[30].sv_id.satId = 67;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[31].residual = 1886;
    test_msg->stec_residuals[31].stddev = 162;
    test_msg->stec_residuals[31].sv_id.constellation = 180;
    test_msg->stec_residuals[31].sv_id.satId = 189;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[32].residual = 12242;
    test_msg->stec_residuals[32].stddev = 7;
    test_msg->stec_residuals[32].sv_id.constellation = 156;
    test_msg->stec_residuals[32].sv_id.satId = 121;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[33].residual = 10670;
    test_msg->stec_residuals[33].stddev = 241;
    test_msg->stec_residuals[33].sv_id.constellation = 205;
    test_msg->stec_residuals[33].sv_id.satId = 7;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[34].residual = 25899;
    test_msg->stec_residuals[34].stddev = 186;
    test_msg->stec_residuals[34].sv_id.constellation = 210;
    test_msg->stec_residuals[34].sv_id.satId = 129;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[35].residual = -2078;
    test_msg->stec_residuals[35].stddev = 187;
    test_msg->stec_residuals[35].sv_id.constellation = 195;
    test_msg->stec_residuals[35].sv_id.satId = 208;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[36].residual = -16264;
    test_msg->stec_residuals[36].stddev = 102;
    test_msg->stec_residuals[36].sv_id.constellation = 160;
    test_msg->stec_residuals[36].sv_id.satId = 219;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[37].residual = -21002;
    test_msg->stec_residuals[37].stddev = 94;
    test_msg->stec_residuals[37].sv_id.constellation = 42;
    test_msg->stec_residuals[37].sv_id.satId = 166;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[38].residual = 7902;
    test_msg->stec_residuals[38].stddev = 35;
    test_msg->stec_residuals[38].sv_id.constellation = 156;
    test_msg->stec_residuals[38].sv_id.satId = 102;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[39].residual = -30275;
    test_msg->stec_residuals[39].stddev = 204;
    test_msg->stec_residuals[39].sv_id.constellation = 64;
    test_msg->stec_residuals[39].sv_id.satId = 247;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[40].residual = -8633;
    test_msg->stec_residuals[40].stddev = 222;
    test_msg->stec_residuals[40].sv_id.constellation = 32;
    test_msg->stec_residuals[40].sv_id.satId = 220;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[41].residual = 6403;
    test_msg->stec_residuals[41].stddev = 45;
    test_msg->stec_residuals[41].sv_id.constellation = 246;
    test_msg->stec_residuals[41].sv_id.satId = 201;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[42].residual = 22643;
    test_msg->stec_residuals[42].stddev = 218;
    test_msg->stec_residuals[42].sv_id.constellation = 239;
    test_msg->stec_residuals[42].sv_id.satId = 251;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[43].residual = 16760;
    test_msg->stec_residuals[43].stddev = 175;
    test_msg->stec_residuals[43].sv_id.constellation = 209;
    test_msg->stec_residuals[43].sv_id.satId = 10;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[44].residual = -20951;
    test_msg->stec_residuals[44].stddev = 137;
    test_msg->stec_residuals[44].sv_id.constellation = 194;
    test_msg->stec_residuals[44].sv_id.satId = 131;
    if (sizeof(test_msg->stec_residuals) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_residuals[0]);
    }
    test_msg->stec_residuals[45].residual = -740;
    test_msg->stec_residuals[45].stddev = 42;
    test_msg->stec_residuals[45].sv_id.constellation = 68;
    test_msg->stec_residuals[45].sv_id.satId = 17;
    test_msg->tropo_delay_correction.hydro = -3035;
    test_msg->tropo_delay_correction.stddev = 72;
    test_msg->tropo_delay_correction.wet = 78;
    sbp_payload_send(&sbp_state, 0x5fc, 63940, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 63940,
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
    ck_assert_msg(last_frame.sender_id == 63940,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x5fc,
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
    msg_ssr_gridded_correction_t *check_msg =
        (msg_ssr_gridded_correction_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.iod_atmo == 170,
                  "incorrect value for header.iod_atmo, expected 170, is %d",
                  check_msg->header.iod_atmo);
    ck_assert_msg(check_msg->header.num_msgs == 48535,
                  "incorrect value for header.num_msgs, expected 48535, is %d",
                  check_msg->header.num_msgs);
    ck_assert_msg(check_msg->header.seq_num == 50380,
                  "incorrect value for header.seq_num, expected 50380, is %d",
                  check_msg->header.seq_num);
    ck_assert_msg(check_msg->header.tile_id == 12951,
                  "incorrect value for header.tile_id, expected 12951, is %d",
                  check_msg->header.tile_id);
    ck_assert_msg(
        check_msg->header.tile_set_id == 3605,
        "incorrect value for header.tile_set_id, expected 3605, is %d",
        check_msg->header.tile_set_id);
    ck_assert_msg(
        check_msg->header.time.tow == 2535294328,
        "incorrect value for header.time.tow, expected 2535294328, is %d",
        check_msg->header.time.tow);
    ck_assert_msg(check_msg->header.time.wn == 58798,
                  "incorrect value for header.time.wn, expected 58798, is %d",
                  check_msg->header.time.wn);
    ck_assert_msg(check_msg->header.tropo_quality_indicator == 120,
                  "incorrect value for header.tropo_quality_indicator, "
                  "expected 120, is %d",
                  check_msg->header.tropo_quality_indicator);
    ck_assert_msg(
        check_msg->header.update_interval == 105,
        "incorrect value for header.update_interval, expected 105, is %d",
        check_msg->header.update_interval);
    ck_assert_msg(check_msg->index == 43413,
                  "incorrect value for index, expected 43413, is %d",
                  check_msg->index);
    ck_assert_msg(check_msg->stec_residuals[0].residual == -21246,
                  "incorrect value for stec_residuals[0].residual, expected "
                  "-21246, is %d",
                  check_msg->stec_residuals[0].residual);
    ck_assert_msg(
        check_msg->stec_residuals[0].stddev == 88,
        "incorrect value for stec_residuals[0].stddev, expected 88, is %d",
        check_msg->stec_residuals[0].stddev);
    ck_assert_msg(check_msg->stec_residuals[0].sv_id.constellation == 101,
                  "incorrect value for stec_residuals[0].sv_id.constellation, "
                  "expected 101, is %d",
                  check_msg->stec_residuals[0].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[0].sv_id.satId == 140,
                  "incorrect value for stec_residuals[0].sv_id.satId, expected "
                  "140, is %d",
                  check_msg->stec_residuals[0].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[1].residual == -26570,
                  "incorrect value for stec_residuals[1].residual, expected "
                  "-26570, is %d",
                  check_msg->stec_residuals[1].residual);
    ck_assert_msg(
        check_msg->stec_residuals[1].stddev == 115,
        "incorrect value for stec_residuals[1].stddev, expected 115, is %d",
        check_msg->stec_residuals[1].stddev);
    ck_assert_msg(check_msg->stec_residuals[1].sv_id.constellation == 180,
                  "incorrect value for stec_residuals[1].sv_id.constellation, "
                  "expected 180, is %d",
                  check_msg->stec_residuals[1].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_residuals[1].sv_id.satId == 70,
        "incorrect value for stec_residuals[1].sv_id.satId, expected 70, is %d",
        check_msg->stec_residuals[1].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[2].residual == 6049,
        "incorrect value for stec_residuals[2].residual, expected 6049, is %d",
        check_msg->stec_residuals[2].residual);
    ck_assert_msg(
        check_msg->stec_residuals[2].stddev == 135,
        "incorrect value for stec_residuals[2].stddev, expected 135, is %d",
        check_msg->stec_residuals[2].stddev);
    ck_assert_msg(check_msg->stec_residuals[2].sv_id.constellation == 201,
                  "incorrect value for stec_residuals[2].sv_id.constellation, "
                  "expected 201, is %d",
                  check_msg->stec_residuals[2].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_residuals[2].sv_id.satId == 78,
        "incorrect value for stec_residuals[2].sv_id.satId, expected 78, is %d",
        check_msg->stec_residuals[2].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[3].residual == 19261,
        "incorrect value for stec_residuals[3].residual, expected 19261, is %d",
        check_msg->stec_residuals[3].residual);
    ck_assert_msg(
        check_msg->stec_residuals[3].stddev == 178,
        "incorrect value for stec_residuals[3].stddev, expected 178, is %d",
        check_msg->stec_residuals[3].stddev);
    ck_assert_msg(check_msg->stec_residuals[3].sv_id.constellation == 98,
                  "incorrect value for stec_residuals[3].sv_id.constellation, "
                  "expected 98, is %d",
                  check_msg->stec_residuals[3].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[3].sv_id.satId == 152,
                  "incorrect value for stec_residuals[3].sv_id.satId, expected "
                  "152, is %d",
                  check_msg->stec_residuals[3].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[4].residual == 14226,
        "incorrect value for stec_residuals[4].residual, expected 14226, is %d",
        check_msg->stec_residuals[4].residual);
    ck_assert_msg(
        check_msg->stec_residuals[4].stddev == 58,
        "incorrect value for stec_residuals[4].stddev, expected 58, is %d",
        check_msg->stec_residuals[4].stddev);
    ck_assert_msg(check_msg->stec_residuals[4].sv_id.constellation == 229,
                  "incorrect value for stec_residuals[4].sv_id.constellation, "
                  "expected 229, is %d",
                  check_msg->stec_residuals[4].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[4].sv_id.satId == 120,
                  "incorrect value for stec_residuals[4].sv_id.satId, expected "
                  "120, is %d",
                  check_msg->stec_residuals[4].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[5].residual == 17894,
        "incorrect value for stec_residuals[5].residual, expected 17894, is %d",
        check_msg->stec_residuals[5].residual);
    ck_assert_msg(
        check_msg->stec_residuals[5].stddev == 172,
        "incorrect value for stec_residuals[5].stddev, expected 172, is %d",
        check_msg->stec_residuals[5].stddev);
    ck_assert_msg(check_msg->stec_residuals[5].sv_id.constellation == 234,
                  "incorrect value for stec_residuals[5].sv_id.constellation, "
                  "expected 234, is %d",
                  check_msg->stec_residuals[5].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[5].sv_id.satId == 169,
                  "incorrect value for stec_residuals[5].sv_id.satId, expected "
                  "169, is %d",
                  check_msg->stec_residuals[5].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[6].residual == 22930,
        "incorrect value for stec_residuals[6].residual, expected 22930, is %d",
        check_msg->stec_residuals[6].residual);
    ck_assert_msg(
        check_msg->stec_residuals[6].stddev == 150,
        "incorrect value for stec_residuals[6].stddev, expected 150, is %d",
        check_msg->stec_residuals[6].stddev);
    ck_assert_msg(check_msg->stec_residuals[6].sv_id.constellation == 127,
                  "incorrect value for stec_residuals[6].sv_id.constellation, "
                  "expected 127, is %d",
                  check_msg->stec_residuals[6].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[6].sv_id.satId == 191,
                  "incorrect value for stec_residuals[6].sv_id.satId, expected "
                  "191, is %d",
                  check_msg->stec_residuals[6].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[7].residual == 10721,
        "incorrect value for stec_residuals[7].residual, expected 10721, is %d",
        check_msg->stec_residuals[7].residual);
    ck_assert_msg(
        check_msg->stec_residuals[7].stddev == 17,
        "incorrect value for stec_residuals[7].stddev, expected 17, is %d",
        check_msg->stec_residuals[7].stddev);
    ck_assert_msg(check_msg->stec_residuals[7].sv_id.constellation == 111,
                  "incorrect value for stec_residuals[7].sv_id.constellation, "
                  "expected 111, is %d",
                  check_msg->stec_residuals[7].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_residuals[7].sv_id.satId == 91,
        "incorrect value for stec_residuals[7].sv_id.satId, expected 91, is %d",
        check_msg->stec_residuals[7].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[8].residual == -22874,
                  "incorrect value for stec_residuals[8].residual, expected "
                  "-22874, is %d",
                  check_msg->stec_residuals[8].residual);
    ck_assert_msg(
        check_msg->stec_residuals[8].stddev == 120,
        "incorrect value for stec_residuals[8].stddev, expected 120, is %d",
        check_msg->stec_residuals[8].stddev);
    ck_assert_msg(check_msg->stec_residuals[8].sv_id.constellation == 52,
                  "incorrect value for stec_residuals[8].sv_id.constellation, "
                  "expected 52, is %d",
                  check_msg->stec_residuals[8].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[8].sv_id.satId == 119,
                  "incorrect value for stec_residuals[8].sv_id.satId, expected "
                  "119, is %d",
                  check_msg->stec_residuals[8].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[9].residual == 780,
        "incorrect value for stec_residuals[9].residual, expected 780, is %d",
        check_msg->stec_residuals[9].residual);
    ck_assert_msg(
        check_msg->stec_residuals[9].stddev == 156,
        "incorrect value for stec_residuals[9].stddev, expected 156, is %d",
        check_msg->stec_residuals[9].stddev);
    ck_assert_msg(check_msg->stec_residuals[9].sv_id.constellation == 221,
                  "incorrect value for stec_residuals[9].sv_id.constellation, "
                  "expected 221, is %d",
                  check_msg->stec_residuals[9].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_residuals[9].sv_id.satId == 57,
        "incorrect value for stec_residuals[9].sv_id.satId, expected 57, is %d",
        check_msg->stec_residuals[9].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[10].residual == 32547,
                  "incorrect value for stec_residuals[10].residual, expected "
                  "32547, is %d",
                  check_msg->stec_residuals[10].residual);
    ck_assert_msg(
        check_msg->stec_residuals[10].stddev == 8,
        "incorrect value for stec_residuals[10].stddev, expected 8, is %d",
        check_msg->stec_residuals[10].stddev);
    ck_assert_msg(check_msg->stec_residuals[10].sv_id.constellation == 156,
                  "incorrect value for stec_residuals[10].sv_id.constellation, "
                  "expected 156, is %d",
                  check_msg->stec_residuals[10].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[10].sv_id.satId == 70,
                  "incorrect value for stec_residuals[10].sv_id.satId, "
                  "expected 70, is %d",
                  check_msg->stec_residuals[10].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[11].residual == 14208,
                  "incorrect value for stec_residuals[11].residual, expected "
                  "14208, is %d",
                  check_msg->stec_residuals[11].residual);
    ck_assert_msg(
        check_msg->stec_residuals[11].stddev == 115,
        "incorrect value for stec_residuals[11].stddev, expected 115, is %d",
        check_msg->stec_residuals[11].stddev);
    ck_assert_msg(check_msg->stec_residuals[11].sv_id.constellation == 58,
                  "incorrect value for stec_residuals[11].sv_id.constellation, "
                  "expected 58, is %d",
                  check_msg->stec_residuals[11].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[11].sv_id.satId == 127,
                  "incorrect value for stec_residuals[11].sv_id.satId, "
                  "expected 127, is %d",
                  check_msg->stec_residuals[11].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[12].residual == -26246,
                  "incorrect value for stec_residuals[12].residual, expected "
                  "-26246, is %d",
                  check_msg->stec_residuals[12].residual);
    ck_assert_msg(
        check_msg->stec_residuals[12].stddev == 124,
        "incorrect value for stec_residuals[12].stddev, expected 124, is %d",
        check_msg->stec_residuals[12].stddev);
    ck_assert_msg(check_msg->stec_residuals[12].sv_id.constellation == 157,
                  "incorrect value for stec_residuals[12].sv_id.constellation, "
                  "expected 157, is %d",
                  check_msg->stec_residuals[12].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[12].sv_id.satId == 80,
                  "incorrect value for stec_residuals[12].sv_id.satId, "
                  "expected 80, is %d",
                  check_msg->stec_residuals[12].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[13].residual == 26466,
                  "incorrect value for stec_residuals[13].residual, expected "
                  "26466, is %d",
                  check_msg->stec_residuals[13].residual);
    ck_assert_msg(
        check_msg->stec_residuals[13].stddev == 204,
        "incorrect value for stec_residuals[13].stddev, expected 204, is %d",
        check_msg->stec_residuals[13].stddev);
    ck_assert_msg(check_msg->stec_residuals[13].sv_id.constellation == 128,
                  "incorrect value for stec_residuals[13].sv_id.constellation, "
                  "expected 128, is %d",
                  check_msg->stec_residuals[13].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[13].sv_id.satId == 27,
                  "incorrect value for stec_residuals[13].sv_id.satId, "
                  "expected 27, is %d",
                  check_msg->stec_residuals[13].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[14].residual == -7552,
                  "incorrect value for stec_residuals[14].residual, expected "
                  "-7552, is %d",
                  check_msg->stec_residuals[14].residual);
    ck_assert_msg(
        check_msg->stec_residuals[14].stddev == 148,
        "incorrect value for stec_residuals[14].stddev, expected 148, is %d",
        check_msg->stec_residuals[14].stddev);
    ck_assert_msg(check_msg->stec_residuals[14].sv_id.constellation == 238,
                  "incorrect value for stec_residuals[14].sv_id.constellation, "
                  "expected 238, is %d",
                  check_msg->stec_residuals[14].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[14].sv_id.satId == 75,
                  "incorrect value for stec_residuals[14].sv_id.satId, "
                  "expected 75, is %d",
                  check_msg->stec_residuals[14].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[15].residual == -12072,
                  "incorrect value for stec_residuals[15].residual, expected "
                  "-12072, is %d",
                  check_msg->stec_residuals[15].residual);
    ck_assert_msg(
        check_msg->stec_residuals[15].stddev == 149,
        "incorrect value for stec_residuals[15].stddev, expected 149, is %d",
        check_msg->stec_residuals[15].stddev);
    ck_assert_msg(check_msg->stec_residuals[15].sv_id.constellation == 61,
                  "incorrect value for stec_residuals[15].sv_id.constellation, "
                  "expected 61, is %d",
                  check_msg->stec_residuals[15].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[15].sv_id.satId == 248,
                  "incorrect value for stec_residuals[15].sv_id.satId, "
                  "expected 248, is %d",
                  check_msg->stec_residuals[15].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[16].residual == -28632,
                  "incorrect value for stec_residuals[16].residual, expected "
                  "-28632, is %d",
                  check_msg->stec_residuals[16].residual);
    ck_assert_msg(
        check_msg->stec_residuals[16].stddev == 186,
        "incorrect value for stec_residuals[16].stddev, expected 186, is %d",
        check_msg->stec_residuals[16].stddev);
    ck_assert_msg(check_msg->stec_residuals[16].sv_id.constellation == 224,
                  "incorrect value for stec_residuals[16].sv_id.constellation, "
                  "expected 224, is %d",
                  check_msg->stec_residuals[16].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[16].sv_id.satId == 167,
                  "incorrect value for stec_residuals[16].sv_id.satId, "
                  "expected 167, is %d",
                  check_msg->stec_residuals[16].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[17].residual == -4024,
                  "incorrect value for stec_residuals[17].residual, expected "
                  "-4024, is %d",
                  check_msg->stec_residuals[17].residual);
    ck_assert_msg(
        check_msg->stec_residuals[17].stddev == 100,
        "incorrect value for stec_residuals[17].stddev, expected 100, is %d",
        check_msg->stec_residuals[17].stddev);
    ck_assert_msg(check_msg->stec_residuals[17].sv_id.constellation == 227,
                  "incorrect value for stec_residuals[17].sv_id.constellation, "
                  "expected 227, is %d",
                  check_msg->stec_residuals[17].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[17].sv_id.satId == 157,
                  "incorrect value for stec_residuals[17].sv_id.satId, "
                  "expected 157, is %d",
                  check_msg->stec_residuals[17].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[18].residual == 2004,
        "incorrect value for stec_residuals[18].residual, expected 2004, is %d",
        check_msg->stec_residuals[18].residual);
    ck_assert_msg(
        check_msg->stec_residuals[18].stddev == 59,
        "incorrect value for stec_residuals[18].stddev, expected 59, is %d",
        check_msg->stec_residuals[18].stddev);
    ck_assert_msg(check_msg->stec_residuals[18].sv_id.constellation == 12,
                  "incorrect value for stec_residuals[18].sv_id.constellation, "
                  "expected 12, is %d",
                  check_msg->stec_residuals[18].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[18].sv_id.satId == 35,
                  "incorrect value for stec_residuals[18].sv_id.satId, "
                  "expected 35, is %d",
                  check_msg->stec_residuals[18].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[19].residual == 6998,
        "incorrect value for stec_residuals[19].residual, expected 6998, is %d",
        check_msg->stec_residuals[19].residual);
    ck_assert_msg(
        check_msg->stec_residuals[19].stddev == 24,
        "incorrect value for stec_residuals[19].stddev, expected 24, is %d",
        check_msg->stec_residuals[19].stddev);
    ck_assert_msg(check_msg->stec_residuals[19].sv_id.constellation == 81,
                  "incorrect value for stec_residuals[19].sv_id.constellation, "
                  "expected 81, is %d",
                  check_msg->stec_residuals[19].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[19].sv_id.satId == 176,
                  "incorrect value for stec_residuals[19].sv_id.satId, "
                  "expected 176, is %d",
                  check_msg->stec_residuals[19].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[20].residual == -31701,
                  "incorrect value for stec_residuals[20].residual, expected "
                  "-31701, is %d",
                  check_msg->stec_residuals[20].residual);
    ck_assert_msg(
        check_msg->stec_residuals[20].stddev == 45,
        "incorrect value for stec_residuals[20].stddev, expected 45, is %d",
        check_msg->stec_residuals[20].stddev);
    ck_assert_msg(check_msg->stec_residuals[20].sv_id.constellation == 67,
                  "incorrect value for stec_residuals[20].sv_id.constellation, "
                  "expected 67, is %d",
                  check_msg->stec_residuals[20].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[20].sv_id.satId == 155,
                  "incorrect value for stec_residuals[20].sv_id.satId, "
                  "expected 155, is %d",
                  check_msg->stec_residuals[20].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[21].residual == 28678,
                  "incorrect value for stec_residuals[21].residual, expected "
                  "28678, is %d",
                  check_msg->stec_residuals[21].residual);
    ck_assert_msg(
        check_msg->stec_residuals[21].stddev == 183,
        "incorrect value for stec_residuals[21].stddev, expected 183, is %d",
        check_msg->stec_residuals[21].stddev);
    ck_assert_msg(check_msg->stec_residuals[21].sv_id.constellation == 44,
                  "incorrect value for stec_residuals[21].sv_id.constellation, "
                  "expected 44, is %d",
                  check_msg->stec_residuals[21].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[21].sv_id.satId == 203,
                  "incorrect value for stec_residuals[21].sv_id.satId, "
                  "expected 203, is %d",
                  check_msg->stec_residuals[21].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[22].residual == -15793,
                  "incorrect value for stec_residuals[22].residual, expected "
                  "-15793, is %d",
                  check_msg->stec_residuals[22].residual);
    ck_assert_msg(
        check_msg->stec_residuals[22].stddev == 253,
        "incorrect value for stec_residuals[22].stddev, expected 253, is %d",
        check_msg->stec_residuals[22].stddev);
    ck_assert_msg(check_msg->stec_residuals[22].sv_id.constellation == 176,
                  "incorrect value for stec_residuals[22].sv_id.constellation, "
                  "expected 176, is %d",
                  check_msg->stec_residuals[22].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[22].sv_id.satId == 231,
                  "incorrect value for stec_residuals[22].sv_id.satId, "
                  "expected 231, is %d",
                  check_msg->stec_residuals[22].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[23].residual == -7589,
                  "incorrect value for stec_residuals[23].residual, expected "
                  "-7589, is %d",
                  check_msg->stec_residuals[23].residual);
    ck_assert_msg(
        check_msg->stec_residuals[23].stddev == 116,
        "incorrect value for stec_residuals[23].stddev, expected 116, is %d",
        check_msg->stec_residuals[23].stddev);
    ck_assert_msg(check_msg->stec_residuals[23].sv_id.constellation == 103,
                  "incorrect value for stec_residuals[23].sv_id.constellation, "
                  "expected 103, is %d",
                  check_msg->stec_residuals[23].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[23].sv_id.satId == 247,
                  "incorrect value for stec_residuals[23].sv_id.satId, "
                  "expected 247, is %d",
                  check_msg->stec_residuals[23].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[24].residual == -7362,
                  "incorrect value for stec_residuals[24].residual, expected "
                  "-7362, is %d",
                  check_msg->stec_residuals[24].residual);
    ck_assert_msg(
        check_msg->stec_residuals[24].stddev == 240,
        "incorrect value for stec_residuals[24].stddev, expected 240, is %d",
        check_msg->stec_residuals[24].stddev);
    ck_assert_msg(check_msg->stec_residuals[24].sv_id.constellation == 23,
                  "incorrect value for stec_residuals[24].sv_id.constellation, "
                  "expected 23, is %d",
                  check_msg->stec_residuals[24].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[24].sv_id.satId == 148,
                  "incorrect value for stec_residuals[24].sv_id.satId, "
                  "expected 148, is %d",
                  check_msg->stec_residuals[24].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[25].residual == 4813,
        "incorrect value for stec_residuals[25].residual, expected 4813, is %d",
        check_msg->stec_residuals[25].residual);
    ck_assert_msg(
        check_msg->stec_residuals[25].stddev == 242,
        "incorrect value for stec_residuals[25].stddev, expected 242, is %d",
        check_msg->stec_residuals[25].stddev);
    ck_assert_msg(check_msg->stec_residuals[25].sv_id.constellation == 219,
                  "incorrect value for stec_residuals[25].sv_id.constellation, "
                  "expected 219, is %d",
                  check_msg->stec_residuals[25].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[25].sv_id.satId == 29,
                  "incorrect value for stec_residuals[25].sv_id.satId, "
                  "expected 29, is %d",
                  check_msg->stec_residuals[25].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[26].residual == 20295,
                  "incorrect value for stec_residuals[26].residual, expected "
                  "20295, is %d",
                  check_msg->stec_residuals[26].residual);
    ck_assert_msg(
        check_msg->stec_residuals[26].stddev == 37,
        "incorrect value for stec_residuals[26].stddev, expected 37, is %d",
        check_msg->stec_residuals[26].stddev);
    ck_assert_msg(check_msg->stec_residuals[26].sv_id.constellation == 72,
                  "incorrect value for stec_residuals[26].sv_id.constellation, "
                  "expected 72, is %d",
                  check_msg->stec_residuals[26].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[26].sv_id.satId == 207,
                  "incorrect value for stec_residuals[26].sv_id.satId, "
                  "expected 207, is %d",
                  check_msg->stec_residuals[26].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[27].residual == -13623,
                  "incorrect value for stec_residuals[27].residual, expected "
                  "-13623, is %d",
                  check_msg->stec_residuals[27].residual);
    ck_assert_msg(
        check_msg->stec_residuals[27].stddev == 91,
        "incorrect value for stec_residuals[27].stddev, expected 91, is %d",
        check_msg->stec_residuals[27].stddev);
    ck_assert_msg(check_msg->stec_residuals[27].sv_id.constellation == 176,
                  "incorrect value for stec_residuals[27].sv_id.constellation, "
                  "expected 176, is %d",
                  check_msg->stec_residuals[27].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[27].sv_id.satId == 42,
                  "incorrect value for stec_residuals[27].sv_id.satId, "
                  "expected 42, is %d",
                  check_msg->stec_residuals[27].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[28].residual == 15250,
                  "incorrect value for stec_residuals[28].residual, expected "
                  "15250, is %d",
                  check_msg->stec_residuals[28].residual);
    ck_assert_msg(
        check_msg->stec_residuals[28].stddev == 110,
        "incorrect value for stec_residuals[28].stddev, expected 110, is %d",
        check_msg->stec_residuals[28].stddev);
    ck_assert_msg(check_msg->stec_residuals[28].sv_id.constellation == 115,
                  "incorrect value for stec_residuals[28].sv_id.constellation, "
                  "expected 115, is %d",
                  check_msg->stec_residuals[28].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[28].sv_id.satId == 105,
                  "incorrect value for stec_residuals[28].sv_id.satId, "
                  "expected 105, is %d",
                  check_msg->stec_residuals[28].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[29].residual == -18560,
                  "incorrect value for stec_residuals[29].residual, expected "
                  "-18560, is %d",
                  check_msg->stec_residuals[29].residual);
    ck_assert_msg(
        check_msg->stec_residuals[29].stddev == 185,
        "incorrect value for stec_residuals[29].stddev, expected 185, is %d",
        check_msg->stec_residuals[29].stddev);
    ck_assert_msg(check_msg->stec_residuals[29].sv_id.constellation == 109,
                  "incorrect value for stec_residuals[29].sv_id.constellation, "
                  "expected 109, is %d",
                  check_msg->stec_residuals[29].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[29].sv_id.satId == 44,
                  "incorrect value for stec_residuals[29].sv_id.satId, "
                  "expected 44, is %d",
                  check_msg->stec_residuals[29].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[30].residual == 23717,
                  "incorrect value for stec_residuals[30].residual, expected "
                  "23717, is %d",
                  check_msg->stec_residuals[30].residual);
    ck_assert_msg(
        check_msg->stec_residuals[30].stddev == 79,
        "incorrect value for stec_residuals[30].stddev, expected 79, is %d",
        check_msg->stec_residuals[30].stddev);
    ck_assert_msg(check_msg->stec_residuals[30].sv_id.constellation == 31,
                  "incorrect value for stec_residuals[30].sv_id.constellation, "
                  "expected 31, is %d",
                  check_msg->stec_residuals[30].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[30].sv_id.satId == 67,
                  "incorrect value for stec_residuals[30].sv_id.satId, "
                  "expected 67, is %d",
                  check_msg->stec_residuals[30].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[31].residual == 1886,
        "incorrect value for stec_residuals[31].residual, expected 1886, is %d",
        check_msg->stec_residuals[31].residual);
    ck_assert_msg(
        check_msg->stec_residuals[31].stddev == 162,
        "incorrect value for stec_residuals[31].stddev, expected 162, is %d",
        check_msg->stec_residuals[31].stddev);
    ck_assert_msg(check_msg->stec_residuals[31].sv_id.constellation == 180,
                  "incorrect value for stec_residuals[31].sv_id.constellation, "
                  "expected 180, is %d",
                  check_msg->stec_residuals[31].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[31].sv_id.satId == 189,
                  "incorrect value for stec_residuals[31].sv_id.satId, "
                  "expected 189, is %d",
                  check_msg->stec_residuals[31].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[32].residual == 12242,
                  "incorrect value for stec_residuals[32].residual, expected "
                  "12242, is %d",
                  check_msg->stec_residuals[32].residual);
    ck_assert_msg(
        check_msg->stec_residuals[32].stddev == 7,
        "incorrect value for stec_residuals[32].stddev, expected 7, is %d",
        check_msg->stec_residuals[32].stddev);
    ck_assert_msg(check_msg->stec_residuals[32].sv_id.constellation == 156,
                  "incorrect value for stec_residuals[32].sv_id.constellation, "
                  "expected 156, is %d",
                  check_msg->stec_residuals[32].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[32].sv_id.satId == 121,
                  "incorrect value for stec_residuals[32].sv_id.satId, "
                  "expected 121, is %d",
                  check_msg->stec_residuals[32].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[33].residual == 10670,
                  "incorrect value for stec_residuals[33].residual, expected "
                  "10670, is %d",
                  check_msg->stec_residuals[33].residual);
    ck_assert_msg(
        check_msg->stec_residuals[33].stddev == 241,
        "incorrect value for stec_residuals[33].stddev, expected 241, is %d",
        check_msg->stec_residuals[33].stddev);
    ck_assert_msg(check_msg->stec_residuals[33].sv_id.constellation == 205,
                  "incorrect value for stec_residuals[33].sv_id.constellation, "
                  "expected 205, is %d",
                  check_msg->stec_residuals[33].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_residuals[33].sv_id.satId == 7,
        "incorrect value for stec_residuals[33].sv_id.satId, expected 7, is %d",
        check_msg->stec_residuals[33].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[34].residual == 25899,
                  "incorrect value for stec_residuals[34].residual, expected "
                  "25899, is %d",
                  check_msg->stec_residuals[34].residual);
    ck_assert_msg(
        check_msg->stec_residuals[34].stddev == 186,
        "incorrect value for stec_residuals[34].stddev, expected 186, is %d",
        check_msg->stec_residuals[34].stddev);
    ck_assert_msg(check_msg->stec_residuals[34].sv_id.constellation == 210,
                  "incorrect value for stec_residuals[34].sv_id.constellation, "
                  "expected 210, is %d",
                  check_msg->stec_residuals[34].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[34].sv_id.satId == 129,
                  "incorrect value for stec_residuals[34].sv_id.satId, "
                  "expected 129, is %d",
                  check_msg->stec_residuals[34].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[35].residual == -2078,
                  "incorrect value for stec_residuals[35].residual, expected "
                  "-2078, is %d",
                  check_msg->stec_residuals[35].residual);
    ck_assert_msg(
        check_msg->stec_residuals[35].stddev == 187,
        "incorrect value for stec_residuals[35].stddev, expected 187, is %d",
        check_msg->stec_residuals[35].stddev);
    ck_assert_msg(check_msg->stec_residuals[35].sv_id.constellation == 195,
                  "incorrect value for stec_residuals[35].sv_id.constellation, "
                  "expected 195, is %d",
                  check_msg->stec_residuals[35].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[35].sv_id.satId == 208,
                  "incorrect value for stec_residuals[35].sv_id.satId, "
                  "expected 208, is %d",
                  check_msg->stec_residuals[35].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[36].residual == -16264,
                  "incorrect value for stec_residuals[36].residual, expected "
                  "-16264, is %d",
                  check_msg->stec_residuals[36].residual);
    ck_assert_msg(
        check_msg->stec_residuals[36].stddev == 102,
        "incorrect value for stec_residuals[36].stddev, expected 102, is %d",
        check_msg->stec_residuals[36].stddev);
    ck_assert_msg(check_msg->stec_residuals[36].sv_id.constellation == 160,
                  "incorrect value for stec_residuals[36].sv_id.constellation, "
                  "expected 160, is %d",
                  check_msg->stec_residuals[36].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[36].sv_id.satId == 219,
                  "incorrect value for stec_residuals[36].sv_id.satId, "
                  "expected 219, is %d",
                  check_msg->stec_residuals[36].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[37].residual == -21002,
                  "incorrect value for stec_residuals[37].residual, expected "
                  "-21002, is %d",
                  check_msg->stec_residuals[37].residual);
    ck_assert_msg(
        check_msg->stec_residuals[37].stddev == 94,
        "incorrect value for stec_residuals[37].stddev, expected 94, is %d",
        check_msg->stec_residuals[37].stddev);
    ck_assert_msg(check_msg->stec_residuals[37].sv_id.constellation == 42,
                  "incorrect value for stec_residuals[37].sv_id.constellation, "
                  "expected 42, is %d",
                  check_msg->stec_residuals[37].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[37].sv_id.satId == 166,
                  "incorrect value for stec_residuals[37].sv_id.satId, "
                  "expected 166, is %d",
                  check_msg->stec_residuals[37].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[38].residual == 7902,
        "incorrect value for stec_residuals[38].residual, expected 7902, is %d",
        check_msg->stec_residuals[38].residual);
    ck_assert_msg(
        check_msg->stec_residuals[38].stddev == 35,
        "incorrect value for stec_residuals[38].stddev, expected 35, is %d",
        check_msg->stec_residuals[38].stddev);
    ck_assert_msg(check_msg->stec_residuals[38].sv_id.constellation == 156,
                  "incorrect value for stec_residuals[38].sv_id.constellation, "
                  "expected 156, is %d",
                  check_msg->stec_residuals[38].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[38].sv_id.satId == 102,
                  "incorrect value for stec_residuals[38].sv_id.satId, "
                  "expected 102, is %d",
                  check_msg->stec_residuals[38].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[39].residual == -30275,
                  "incorrect value for stec_residuals[39].residual, expected "
                  "-30275, is %d",
                  check_msg->stec_residuals[39].residual);
    ck_assert_msg(
        check_msg->stec_residuals[39].stddev == 204,
        "incorrect value for stec_residuals[39].stddev, expected 204, is %d",
        check_msg->stec_residuals[39].stddev);
    ck_assert_msg(check_msg->stec_residuals[39].sv_id.constellation == 64,
                  "incorrect value for stec_residuals[39].sv_id.constellation, "
                  "expected 64, is %d",
                  check_msg->stec_residuals[39].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[39].sv_id.satId == 247,
                  "incorrect value for stec_residuals[39].sv_id.satId, "
                  "expected 247, is %d",
                  check_msg->stec_residuals[39].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[40].residual == -8633,
                  "incorrect value for stec_residuals[40].residual, expected "
                  "-8633, is %d",
                  check_msg->stec_residuals[40].residual);
    ck_assert_msg(
        check_msg->stec_residuals[40].stddev == 222,
        "incorrect value for stec_residuals[40].stddev, expected 222, is %d",
        check_msg->stec_residuals[40].stddev);
    ck_assert_msg(check_msg->stec_residuals[40].sv_id.constellation == 32,
                  "incorrect value for stec_residuals[40].sv_id.constellation, "
                  "expected 32, is %d",
                  check_msg->stec_residuals[40].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[40].sv_id.satId == 220,
                  "incorrect value for stec_residuals[40].sv_id.satId, "
                  "expected 220, is %d",
                  check_msg->stec_residuals[40].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[41].residual == 6403,
        "incorrect value for stec_residuals[41].residual, expected 6403, is %d",
        check_msg->stec_residuals[41].residual);
    ck_assert_msg(
        check_msg->stec_residuals[41].stddev == 45,
        "incorrect value for stec_residuals[41].stddev, expected 45, is %d",
        check_msg->stec_residuals[41].stddev);
    ck_assert_msg(check_msg->stec_residuals[41].sv_id.constellation == 246,
                  "incorrect value for stec_residuals[41].sv_id.constellation, "
                  "expected 246, is %d",
                  check_msg->stec_residuals[41].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[41].sv_id.satId == 201,
                  "incorrect value for stec_residuals[41].sv_id.satId, "
                  "expected 201, is %d",
                  check_msg->stec_residuals[41].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[42].residual == 22643,
                  "incorrect value for stec_residuals[42].residual, expected "
                  "22643, is %d",
                  check_msg->stec_residuals[42].residual);
    ck_assert_msg(
        check_msg->stec_residuals[42].stddev == 218,
        "incorrect value for stec_residuals[42].stddev, expected 218, is %d",
        check_msg->stec_residuals[42].stddev);
    ck_assert_msg(check_msg->stec_residuals[42].sv_id.constellation == 239,
                  "incorrect value for stec_residuals[42].sv_id.constellation, "
                  "expected 239, is %d",
                  check_msg->stec_residuals[42].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[42].sv_id.satId == 251,
                  "incorrect value for stec_residuals[42].sv_id.satId, "
                  "expected 251, is %d",
                  check_msg->stec_residuals[42].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[43].residual == 16760,
                  "incorrect value for stec_residuals[43].residual, expected "
                  "16760, is %d",
                  check_msg->stec_residuals[43].residual);
    ck_assert_msg(
        check_msg->stec_residuals[43].stddev == 175,
        "incorrect value for stec_residuals[43].stddev, expected 175, is %d",
        check_msg->stec_residuals[43].stddev);
    ck_assert_msg(check_msg->stec_residuals[43].sv_id.constellation == 209,
                  "incorrect value for stec_residuals[43].sv_id.constellation, "
                  "expected 209, is %d",
                  check_msg->stec_residuals[43].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[43].sv_id.satId == 10,
                  "incorrect value for stec_residuals[43].sv_id.satId, "
                  "expected 10, is %d",
                  check_msg->stec_residuals[43].sv_id.satId);
    ck_assert_msg(check_msg->stec_residuals[44].residual == -20951,
                  "incorrect value for stec_residuals[44].residual, expected "
                  "-20951, is %d",
                  check_msg->stec_residuals[44].residual);
    ck_assert_msg(
        check_msg->stec_residuals[44].stddev == 137,
        "incorrect value for stec_residuals[44].stddev, expected 137, is %d",
        check_msg->stec_residuals[44].stddev);
    ck_assert_msg(check_msg->stec_residuals[44].sv_id.constellation == 194,
                  "incorrect value for stec_residuals[44].sv_id.constellation, "
                  "expected 194, is %d",
                  check_msg->stec_residuals[44].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[44].sv_id.satId == 131,
                  "incorrect value for stec_residuals[44].sv_id.satId, "
                  "expected 131, is %d",
                  check_msg->stec_residuals[44].sv_id.satId);
    ck_assert_msg(
        check_msg->stec_residuals[45].residual == -740,
        "incorrect value for stec_residuals[45].residual, expected -740, is %d",
        check_msg->stec_residuals[45].residual);
    ck_assert_msg(
        check_msg->stec_residuals[45].stddev == 42,
        "incorrect value for stec_residuals[45].stddev, expected 42, is %d",
        check_msg->stec_residuals[45].stddev);
    ck_assert_msg(check_msg->stec_residuals[45].sv_id.constellation == 68,
                  "incorrect value for stec_residuals[45].sv_id.constellation, "
                  "expected 68, is %d",
                  check_msg->stec_residuals[45].sv_id.constellation);
    ck_assert_msg(check_msg->stec_residuals[45].sv_id.satId == 17,
                  "incorrect value for stec_residuals[45].sv_id.satId, "
                  "expected 17, is %d",
                  check_msg->stec_residuals[45].sv_id.satId);
    ck_assert_msg(check_msg->tropo_delay_correction.hydro == -3035,
                  "incorrect value for tropo_delay_correction.hydro, expected "
                  "-3035, is %d",
                  check_msg->tropo_delay_correction.hydro);
    ck_assert_msg(
        check_msg->tropo_delay_correction.stddev == 72,
        "incorrect value for tropo_delay_correction.stddev, expected 72, is %d",
        check_msg->tropo_delay_correction.stddev);
    ck_assert_msg(
        check_msg->tropo_delay_correction.wet == 78,
        "incorrect value for tropo_delay_correction.wet, expected 78, is %d",
        check_msg->tropo_delay_correction.wet);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrection_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrection");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrection");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrection);
  suite_add_tcase(s, tc_acq);
  return s;
}