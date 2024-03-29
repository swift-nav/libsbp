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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDep.yaml by
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

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep) {
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

    sbp_payload_callback_register(&sbp_state, 0x5fb, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x5fb, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  251, 5,   204, 151, 245, 158, 228, 114, 117, 50,  158, 156, 42,
        119, 156, 157, 112, 47,  60,  132, 40,  70,  87,  235, 83,  177, 198,
        3,   14,  8,   70,  12,  44,  53,  181, 90,  174, 247, 150, 58,  172,
        247, 179, 119, 176, 125, 4,   177, 229, 113, 14,  77,  153, 185, 23,
        53,  222, 187, 146, 250, 91,  212, 215, 14,  107, 250, 94,  107, 33,
        91,  234, 0,   213, 139, 95,  179, 50,  21,  74,  174, 169, 61,  86,
        91,  142, 51,  108, 9,   38,  225, 146, 101, 73,  139, 56,  117, 82,
        37,  213, 108, 205, 93,  18,  19,  195, 33,  202, 87,  206, 178, 125,
        188, 119, 56,  69,  150, 150, 76,  3,   131, 18,  73,  208, 72,  232,
        8,   250, 203, 178, 170, 163, 252, 86,  49,  247, 178, 166, 56,  31,
        10,  119, 213, 241, 212, 164, 1,   162, 42,  18,  124, 169, 121, 158,
        26,  56,  23,  142, 125, 40,  120, 67,  45,  126, 235, 110, 23,  12,
        241, 88,  69,  239, 252, 57,  93,  44,  201, 216, 173, 242, 178, 17,
        5,   223, 169, 192, 3,   77,  107, 2,   144, 233, 14,  88,  32,  209,
        1,   17,  123, 155, 41,  183, 244, 158, 82,  53,  103, 14,  202, 185,
        35,  181, 21,  118, 254, 250, 50,  184, 50,  31,  45,  56,  163, 177,
        126, 217, 79,  171, 239, 237, 188, 238, 112, 201, 118, 141, 18,  163,
        103, 35,  63,  21,  82,  129, 18,  117, 85,  190, 79,  210, 215, 227,
        177,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_stec_correction_dep_t *test_msg =
        (msg_ssr_stec_correction_dep_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.iod_atmo = 60;
    test_msg->header.num_msgs = 157;
    test_msg->header.seq_num = 112;
    test_msg->header.tile_id = 30066;
    test_msg->header.tile_set_id = 58526;
    test_msg->header.time.tow = 714907186;
    test_msg->header.time.wn = 40055;
    test_msg->header.update_interval = 47;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0].stec_coeff[0]);
    }
    test_msg->stec_sat_list[0].stec_coeff[0] = -5289;
    if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0].stec_coeff[0]);
    }
    test_msg->stec_sat_list[0].stec_coeff[1] = -20141;
    if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0].stec_coeff[0]);
    }
    test_msg->stec_sat_list[0].stec_coeff[2] = 966;
    if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0].stec_coeff[0]);
    }
    test_msg->stec_sat_list[0].stec_coeff[3] = 2062;
    test_msg->stec_sat_list[0].stec_quality_indicator = 70;
    test_msg->stec_sat_list[0].sv_id.constellation = 40;
    test_msg->stec_sat_list[0].sv_id.satId = 132;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[1].stec_coeff[0]);
    }
    test_msg->stec_sat_list[1].stec_coeff[0] = -19147;
    if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[1].stec_coeff[0]);
    }
    test_msg->stec_sat_list[1].stec_coeff[1] = -20902;
    if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[1].stec_coeff[0]);
    }
    test_msg->stec_sat_list[1].stec_coeff[2] = -26889;
    if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[1].stec_coeff[0]);
    }
    test_msg->stec_sat_list[1].stec_coeff[3] = -21446;
    test_msg->stec_sat_list[1].stec_quality_indicator = 44;
    test_msg->stec_sat_list[1].sv_id.constellation = 12;
    test_msg->stec_sat_list[1].sv_id.satId = 70;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[2].stec_coeff[0]);
    }
    test_msg->stec_sat_list[2].stec_coeff[0] = 32176;
    if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[2].stec_coeff[0]);
    }
    test_msg->stec_sat_list[2].stec_coeff[1] = -20220;
    if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[2].stec_coeff[0]);
    }
    test_msg->stec_sat_list[2].stec_coeff[2] = 29157;
    if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[2].stec_coeff[0]);
    }
    test_msg->stec_sat_list[2].stec_coeff[3] = 19726;
    test_msg->stec_sat_list[2].stec_quality_indicator = 119;
    test_msg->stec_sat_list[2].sv_id.constellation = 179;
    test_msg->stec_sat_list[2].sv_id.satId = 247;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[3].stec_coeff[0]);
    }
    test_msg->stec_sat_list[3].stec_coeff[0] = -8651;
    if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[3].stec_coeff[0]);
    }
    test_msg->stec_sat_list[3].stec_coeff[1] = -27973;
    if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[3].stec_coeff[0]);
    }
    test_msg->stec_sat_list[3].stec_coeff[2] = 23546;
    if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[3].stec_coeff[0]);
    }
    test_msg->stec_sat_list[3].stec_coeff[3] = -10284;
    test_msg->stec_sat_list[3].stec_quality_indicator = 23;
    test_msg->stec_sat_list[3].sv_id.constellation = 185;
    test_msg->stec_sat_list[3].sv_id.satId = 153;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[4].stec_coeff[0]);
    }
    test_msg->stec_sat_list[4].stec_coeff[0] = 27486;
    if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[4].stec_coeff[0]);
    }
    test_msg->stec_sat_list[4].stec_coeff[1] = 23329;
    if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[4].stec_coeff[0]);
    }
    test_msg->stec_sat_list[4].stec_coeff[2] = 234;
    if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[4].stec_coeff[0]);
    }
    test_msg->stec_sat_list[4].stec_coeff[3] = -29739;
    test_msg->stec_sat_list[4].stec_quality_indicator = 250;
    test_msg->stec_sat_list[4].sv_id.constellation = 107;
    test_msg->stec_sat_list[4].sv_id.satId = 14;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[5].stec_coeff[0]);
    }
    test_msg->stec_sat_list[5].stec_coeff[0] = 18965;
    if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[5].stec_coeff[0]);
    }
    test_msg->stec_sat_list[5].stec_coeff[1] = -22098;
    if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[5].stec_coeff[0]);
    }
    test_msg->stec_sat_list[5].stec_coeff[2] = 22077;
    if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[5].stec_coeff[0]);
    }
    test_msg->stec_sat_list[5].stec_coeff[3] = -29093;
    test_msg->stec_sat_list[5].stec_quality_indicator = 50;
    test_msg->stec_sat_list[5].sv_id.constellation = 179;
    test_msg->stec_sat_list[5].sv_id.satId = 95;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[6].stec_coeff[0]);
    }
    test_msg->stec_sat_list[6].stec_coeff[0] = -7898;
    if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[6].stec_coeff[0]);
    }
    test_msg->stec_sat_list[6].stec_coeff[1] = 26002;
    if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[6].stec_coeff[0]);
    }
    test_msg->stec_sat_list[6].stec_coeff[2] = -29879;
    if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[6].stec_coeff[0]);
    }
    test_msg->stec_sat_list[6].stec_coeff[3] = 30008;
    test_msg->stec_sat_list[6].stec_quality_indicator = 9;
    test_msg->stec_sat_list[6].sv_id.constellation = 108;
    test_msg->stec_sat_list[6].sv_id.satId = 51;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[7].stec_coeff[0]);
    }
    test_msg->stec_sat_list[7].stec_coeff[0] = -12948;
    if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[7].stec_coeff[0]);
    }
    test_msg->stec_sat_list[7].stec_coeff[1] = 4701;
    if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[7].stec_coeff[0]);
    }
    test_msg->stec_sat_list[7].stec_coeff[2] = -15597;
    if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[7].stec_coeff[0]);
    }
    test_msg->stec_sat_list[7].stec_coeff[3] = -13791;
    test_msg->stec_sat_list[7].stec_quality_indicator = 213;
    test_msg->stec_sat_list[7].sv_id.constellation = 37;
    test_msg->stec_sat_list[7].sv_id.satId = 82;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[8].stec_coeff[0]);
    }
    test_msg->stec_sat_list[8].stec_coeff[0] = -17283;
    if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[8].stec_coeff[0]);
    }
    test_msg->stec_sat_list[8].stec_coeff[1] = 14455;
    if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[8].stec_coeff[0]);
    }
    test_msg->stec_sat_list[8].stec_coeff[2] = -27067;
    if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[8].stec_coeff[0]);
    }
    test_msg->stec_sat_list[8].stec_coeff[3] = 19606;
    test_msg->stec_sat_list[8].stec_quality_indicator = 178;
    test_msg->stec_sat_list[8].sv_id.constellation = 206;
    test_msg->stec_sat_list[8].sv_id.satId = 87;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[9].stec_coeff[0]);
    }
    test_msg->stec_sat_list[9].stec_coeff[0] = -12215;
    if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[9].stec_coeff[0]);
    }
    test_msg->stec_sat_list[9].stec_coeff[1] = -6072;
    if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[9].stec_coeff[0]);
    }
    test_msg->stec_sat_list[9].stec_coeff[2] = -1528;
    if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[9].stec_coeff[0]);
    }
    test_msg->stec_sat_list[9].stec_coeff[3] = -19765;
    test_msg->stec_sat_list[9].stec_quality_indicator = 18;
    test_msg->stec_sat_list[9].sv_id.constellation = 131;
    test_msg->stec_sat_list[9].sv_id.satId = 3;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[10].stec_coeff[0]);
    }
    test_msg->stec_sat_list[10].stec_coeff[0] = 12630;
    if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[10].stec_coeff[0]);
    }
    test_msg->stec_sat_list[10].stec_coeff[1] = -19721;
    if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[10].stec_coeff[0]);
    }
    test_msg->stec_sat_list[10].stec_coeff[2] = 14502;
    if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[10].stec_coeff[0]);
    }
    test_msg->stec_sat_list[10].stec_coeff[3] = 2591;
    test_msg->stec_sat_list[10].stec_quality_indicator = 252;
    test_msg->stec_sat_list[10].sv_id.constellation = 163;
    test_msg->stec_sat_list[10].sv_id.satId = 170;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[11].stec_coeff[0]);
    }
    test_msg->stec_sat_list[11].stec_coeff[0] = -23340;
    if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[11].stec_coeff[0]);
    }
    test_msg->stec_sat_list[11].stec_coeff[1] = -24063;
    if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[11].stec_coeff[0]);
    }
    test_msg->stec_sat_list[11].stec_coeff[2] = 4650;
    if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[11].stec_coeff[0]);
    }
    test_msg->stec_sat_list[11].stec_coeff[3] = -22148;
    test_msg->stec_sat_list[11].stec_quality_indicator = 241;
    test_msg->stec_sat_list[11].sv_id.constellation = 213;
    test_msg->stec_sat_list[11].sv_id.satId = 119;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[12].stec_coeff[0]);
    }
    test_msg->stec_sat_list[12].stec_coeff[0] = 5944;
    if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[12].stec_coeff[0]);
    }
    test_msg->stec_sat_list[12].stec_coeff[1] = 32142;
    if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[12].stec_coeff[0]);
    }
    test_msg->stec_sat_list[12].stec_coeff[2] = 30760;
    if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[12].stec_coeff[0]);
    }
    test_msg->stec_sat_list[12].stec_coeff[3] = 11587;
    test_msg->stec_sat_list[12].stec_quality_indicator = 26;
    test_msg->stec_sat_list[12].sv_id.constellation = 158;
    test_msg->stec_sat_list[12].sv_id.satId = 121;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[13].stec_coeff[0]);
    }
    test_msg->stec_sat_list[13].stec_coeff[0] = 3095;
    if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[13].stec_coeff[0]);
    }
    test_msg->stec_sat_list[13].stec_coeff[1] = 22769;
    if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[13].stec_coeff[0]);
    }
    test_msg->stec_sat_list[13].stec_coeff[2] = -4283;
    if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[13].stec_coeff[0]);
    }
    test_msg->stec_sat_list[13].stec_coeff[3] = 14844;
    test_msg->stec_sat_list[13].stec_quality_indicator = 110;
    test_msg->stec_sat_list[13].sv_id.constellation = 235;
    test_msg->stec_sat_list[13].sv_id.satId = 126;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[14].stec_coeff[0]);
    }
    test_msg->stec_sat_list[14].stec_coeff[0] = -21032;
    if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[14].stec_coeff[0]);
    }
    test_msg->stec_sat_list[14].stec_coeff[1] = -19726;
    if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[14].stec_coeff[0]);
    }
    test_msg->stec_sat_list[14].stec_coeff[2] = 1297;
    if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[14].stec_coeff[0]);
    }
    test_msg->stec_sat_list[14].stec_coeff[3] = -22049;
    test_msg->stec_sat_list[14].stec_quality_indicator = 201;
    test_msg->stec_sat_list[14].sv_id.constellation = 44;
    test_msg->stec_sat_list[14].sv_id.satId = 93;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[15].stec_coeff[0]);
    }
    test_msg->stec_sat_list[15].stec_coeff[0] = 619;
    if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[15].stec_coeff[0]);
    }
    test_msg->stec_sat_list[15].stec_coeff[1] = -5744;
    if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[15].stec_coeff[0]);
    }
    test_msg->stec_sat_list[15].stec_coeff[2] = 22542;
    if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[15].stec_coeff[0]);
    }
    test_msg->stec_sat_list[15].stec_coeff[3] = -12000;
    test_msg->stec_sat_list[15].stec_quality_indicator = 77;
    test_msg->stec_sat_list[15].sv_id.constellation = 3;
    test_msg->stec_sat_list[15].sv_id.satId = 192;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[16].stec_coeff[0]);
    }
    test_msg->stec_sat_list[16].stec_coeff[0] = 10651;
    if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[16].stec_coeff[0]);
    }
    test_msg->stec_sat_list[16].stec_coeff[1] = -2889;
    if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[16].stec_coeff[0]);
    }
    test_msg->stec_sat_list[16].stec_coeff[2] = 21150;
    if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[16].stec_coeff[0]);
    }
    test_msg->stec_sat_list[16].stec_coeff[3] = 26421;
    test_msg->stec_sat_list[16].stec_quality_indicator = 123;
    test_msg->stec_sat_list[16].sv_id.constellation = 17;
    test_msg->stec_sat_list[16].sv_id.satId = 1;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[17].stec_coeff[0]);
    }
    test_msg->stec_sat_list[17].stec_coeff[0] = -19165;
    if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[17].stec_coeff[0]);
    }
    test_msg->stec_sat_list[17].stec_coeff[1] = 30229;
    if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[17].stec_coeff[0]);
    }
    test_msg->stec_sat_list[17].stec_coeff[2] = -1282;
    if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[17].stec_coeff[0]);
    }
    test_msg->stec_sat_list[17].stec_coeff[3] = -18382;
    test_msg->stec_sat_list[17].stec_quality_indicator = 185;
    test_msg->stec_sat_list[17].sv_id.constellation = 202;
    test_msg->stec_sat_list[17].sv_id.satId = 14;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[18].stec_coeff[0]);
    }
    test_msg->stec_sat_list[18].stec_coeff[0] = -23752;
    if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[18].stec_coeff[0]);
    }
    test_msg->stec_sat_list[18].stec_coeff[1] = 32433;
    if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[18].stec_coeff[0]);
    }
    test_msg->stec_sat_list[18].stec_coeff[2] = 20441;
    if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[18].stec_coeff[0]);
    }
    test_msg->stec_sat_list[18].stec_coeff[3] = -4181;
    test_msg->stec_sat_list[18].stec_quality_indicator = 45;
    test_msg->stec_sat_list[18].sv_id.constellation = 31;
    test_msg->stec_sat_list[18].sv_id.satId = 50;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[19].stec_coeff[0]);
    }
    test_msg->stec_sat_list[19].stec_coeff[0] = -13968;
    if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[19].stec_coeff[0]);
    }
    test_msg->stec_sat_list[19].stec_coeff[1] = -29322;
    if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[19].stec_coeff[0]);
    }
    test_msg->stec_sat_list[19].stec_coeff[2] = -23790;
    if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[19].stec_coeff[0]);
    }
    test_msg->stec_sat_list[19].stec_coeff[3] = 9063;
    test_msg->stec_sat_list[19].stec_quality_indicator = 238;
    test_msg->stec_sat_list[19].sv_id.constellation = 188;
    test_msg->stec_sat_list[19].sv_id.satId = 237;
    if (sizeof(test_msg->stec_sat_list) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[0]);
    }
    if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[20].stec_coeff[0]);
    }
    test_msg->stec_sat_list[20].stec_coeff[0] = 4737;
    if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[20].stec_coeff[0]);
    }
    test_msg->stec_sat_list[20].stec_coeff[1] = 21877;
    if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[20].stec_coeff[0]);
    }
    test_msg->stec_sat_list[20].stec_coeff[2] = 20414;
    if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->stec_sat_list[20].stec_coeff[0]);
    }
    test_msg->stec_sat_list[20].stec_coeff[3] = -10286;
    test_msg->stec_sat_list[20].stec_quality_indicator = 82;
    test_msg->stec_sat_list[20].sv_id.constellation = 21;
    test_msg->stec_sat_list[20].sv_id.satId = 63;
    sbp_payload_send(&sbp_state, 0x5fb, 38860, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 38860,
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
    ck_assert_msg(last_frame.sender_id == 38860,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x5fb,
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
    msg_ssr_stec_correction_dep_t *check_msg =
        (msg_ssr_stec_correction_dep_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.iod_atmo == 60,
                  "incorrect value for header.iod_atmo, expected 60, is %d",
                  check_msg->header.iod_atmo);
    ck_assert_msg(check_msg->header.num_msgs == 157,
                  "incorrect value for header.num_msgs, expected 157, is %d",
                  check_msg->header.num_msgs);
    ck_assert_msg(check_msg->header.seq_num == 112,
                  "incorrect value for header.seq_num, expected 112, is %d",
                  check_msg->header.seq_num);
    ck_assert_msg(check_msg->header.tile_id == 30066,
                  "incorrect value for header.tile_id, expected 30066, is %d",
                  check_msg->header.tile_id);
    ck_assert_msg(
        check_msg->header.tile_set_id == 58526,
        "incorrect value for header.tile_set_id, expected 58526, is %d",
        check_msg->header.tile_set_id);
    ck_assert_msg(
        check_msg->header.time.tow == 714907186,
        "incorrect value for header.time.tow, expected 714907186, is %d",
        check_msg->header.time.tow);
    ck_assert_msg(check_msg->header.time.wn == 40055,
                  "incorrect value for header.time.wn, expected 40055, is %d",
                  check_msg->header.time.wn);
    ck_assert_msg(
        check_msg->header.update_interval == 47,
        "incorrect value for header.update_interval, expected 47, is %d",
        check_msg->header.update_interval);
    ck_assert_msg(check_msg->stec_sat_list[0].stec_coeff[0] == -5289,
                  "incorrect value for stec_sat_list[0].stec_coeff[0], "
                  "expected -5289, is %d",
                  check_msg->stec_sat_list[0].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[0].stec_coeff[1] == -20141,
                  "incorrect value for stec_sat_list[0].stec_coeff[1], "
                  "expected -20141, is %d",
                  check_msg->stec_sat_list[0].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[0].stec_coeff[2] == 966,
                  "incorrect value for stec_sat_list[0].stec_coeff[2], "
                  "expected 966, is %d",
                  check_msg->stec_sat_list[0].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[0].stec_coeff[3] == 2062,
                  "incorrect value for stec_sat_list[0].stec_coeff[3], "
                  "expected 2062, is %d",
                  check_msg->stec_sat_list[0].stec_coeff[3]);
    ck_assert_msg(check_msg->stec_sat_list[0].stec_quality_indicator == 70,
                  "incorrect value for "
                  "stec_sat_list[0].stec_quality_indicator, expected 70, is %d",
                  check_msg->stec_sat_list[0].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[0].sv_id.constellation == 40,
                  "incorrect value for stec_sat_list[0].sv_id.constellation, "
                  "expected 40, is %d",
                  check_msg->stec_sat_list[0].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[0].sv_id.satId == 132,
        "incorrect value for stec_sat_list[0].sv_id.satId, expected 132, is %d",
        check_msg->stec_sat_list[0].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[1].stec_coeff[0] == -19147,
                  "incorrect value for stec_sat_list[1].stec_coeff[0], "
                  "expected -19147, is %d",
                  check_msg->stec_sat_list[1].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[1].stec_coeff[1] == -20902,
                  "incorrect value for stec_sat_list[1].stec_coeff[1], "
                  "expected -20902, is %d",
                  check_msg->stec_sat_list[1].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[1].stec_coeff[2] == -26889,
                  "incorrect value for stec_sat_list[1].stec_coeff[2], "
                  "expected -26889, is %d",
                  check_msg->stec_sat_list[1].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[1].stec_coeff[3] == -21446,
                  "incorrect value for stec_sat_list[1].stec_coeff[3], "
                  "expected -21446, is %d",
                  check_msg->stec_sat_list[1].stec_coeff[3]);
    ck_assert_msg(check_msg->stec_sat_list[1].stec_quality_indicator == 44,
                  "incorrect value for "
                  "stec_sat_list[1].stec_quality_indicator, expected 44, is %d",
                  check_msg->stec_sat_list[1].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[1].sv_id.constellation == 12,
                  "incorrect value for stec_sat_list[1].sv_id.constellation, "
                  "expected 12, is %d",
                  check_msg->stec_sat_list[1].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[1].sv_id.satId == 70,
        "incorrect value for stec_sat_list[1].sv_id.satId, expected 70, is %d",
        check_msg->stec_sat_list[1].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[2].stec_coeff[0] == 32176,
                  "incorrect value for stec_sat_list[2].stec_coeff[0], "
                  "expected 32176, is %d",
                  check_msg->stec_sat_list[2].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[2].stec_coeff[1] == -20220,
                  "incorrect value for stec_sat_list[2].stec_coeff[1], "
                  "expected -20220, is %d",
                  check_msg->stec_sat_list[2].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[2].stec_coeff[2] == 29157,
                  "incorrect value for stec_sat_list[2].stec_coeff[2], "
                  "expected 29157, is %d",
                  check_msg->stec_sat_list[2].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[2].stec_coeff[3] == 19726,
                  "incorrect value for stec_sat_list[2].stec_coeff[3], "
                  "expected 19726, is %d",
                  check_msg->stec_sat_list[2].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[2].stec_quality_indicator == 119,
        "incorrect value for stec_sat_list[2].stec_quality_indicator, expected "
        "119, is %d",
        check_msg->stec_sat_list[2].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[2].sv_id.constellation == 179,
                  "incorrect value for stec_sat_list[2].sv_id.constellation, "
                  "expected 179, is %d",
                  check_msg->stec_sat_list[2].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[2].sv_id.satId == 247,
        "incorrect value for stec_sat_list[2].sv_id.satId, expected 247, is %d",
        check_msg->stec_sat_list[2].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[3].stec_coeff[0] == -8651,
                  "incorrect value for stec_sat_list[3].stec_coeff[0], "
                  "expected -8651, is %d",
                  check_msg->stec_sat_list[3].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[3].stec_coeff[1] == -27973,
                  "incorrect value for stec_sat_list[3].stec_coeff[1], "
                  "expected -27973, is %d",
                  check_msg->stec_sat_list[3].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[3].stec_coeff[2] == 23546,
                  "incorrect value for stec_sat_list[3].stec_coeff[2], "
                  "expected 23546, is %d",
                  check_msg->stec_sat_list[3].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[3].stec_coeff[3] == -10284,
                  "incorrect value for stec_sat_list[3].stec_coeff[3], "
                  "expected -10284, is %d",
                  check_msg->stec_sat_list[3].stec_coeff[3]);
    ck_assert_msg(check_msg->stec_sat_list[3].stec_quality_indicator == 23,
                  "incorrect value for "
                  "stec_sat_list[3].stec_quality_indicator, expected 23, is %d",
                  check_msg->stec_sat_list[3].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[3].sv_id.constellation == 185,
                  "incorrect value for stec_sat_list[3].sv_id.constellation, "
                  "expected 185, is %d",
                  check_msg->stec_sat_list[3].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[3].sv_id.satId == 153,
        "incorrect value for stec_sat_list[3].sv_id.satId, expected 153, is %d",
        check_msg->stec_sat_list[3].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[4].stec_coeff[0] == 27486,
                  "incorrect value for stec_sat_list[4].stec_coeff[0], "
                  "expected 27486, is %d",
                  check_msg->stec_sat_list[4].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[4].stec_coeff[1] == 23329,
                  "incorrect value for stec_sat_list[4].stec_coeff[1], "
                  "expected 23329, is %d",
                  check_msg->stec_sat_list[4].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[4].stec_coeff[2] == 234,
                  "incorrect value for stec_sat_list[4].stec_coeff[2], "
                  "expected 234, is %d",
                  check_msg->stec_sat_list[4].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[4].stec_coeff[3] == -29739,
                  "incorrect value for stec_sat_list[4].stec_coeff[3], "
                  "expected -29739, is %d",
                  check_msg->stec_sat_list[4].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[4].stec_quality_indicator == 250,
        "incorrect value for stec_sat_list[4].stec_quality_indicator, expected "
        "250, is %d",
        check_msg->stec_sat_list[4].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[4].sv_id.constellation == 107,
                  "incorrect value for stec_sat_list[4].sv_id.constellation, "
                  "expected 107, is %d",
                  check_msg->stec_sat_list[4].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[4].sv_id.satId == 14,
        "incorrect value for stec_sat_list[4].sv_id.satId, expected 14, is %d",
        check_msg->stec_sat_list[4].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[5].stec_coeff[0] == 18965,
                  "incorrect value for stec_sat_list[5].stec_coeff[0], "
                  "expected 18965, is %d",
                  check_msg->stec_sat_list[5].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[5].stec_coeff[1] == -22098,
                  "incorrect value for stec_sat_list[5].stec_coeff[1], "
                  "expected -22098, is %d",
                  check_msg->stec_sat_list[5].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[5].stec_coeff[2] == 22077,
                  "incorrect value for stec_sat_list[5].stec_coeff[2], "
                  "expected 22077, is %d",
                  check_msg->stec_sat_list[5].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[5].stec_coeff[3] == -29093,
                  "incorrect value for stec_sat_list[5].stec_coeff[3], "
                  "expected -29093, is %d",
                  check_msg->stec_sat_list[5].stec_coeff[3]);
    ck_assert_msg(check_msg->stec_sat_list[5].stec_quality_indicator == 50,
                  "incorrect value for "
                  "stec_sat_list[5].stec_quality_indicator, expected 50, is %d",
                  check_msg->stec_sat_list[5].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[5].sv_id.constellation == 179,
                  "incorrect value for stec_sat_list[5].sv_id.constellation, "
                  "expected 179, is %d",
                  check_msg->stec_sat_list[5].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[5].sv_id.satId == 95,
        "incorrect value for stec_sat_list[5].sv_id.satId, expected 95, is %d",
        check_msg->stec_sat_list[5].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[6].stec_coeff[0] == -7898,
                  "incorrect value for stec_sat_list[6].stec_coeff[0], "
                  "expected -7898, is %d",
                  check_msg->stec_sat_list[6].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[6].stec_coeff[1] == 26002,
                  "incorrect value for stec_sat_list[6].stec_coeff[1], "
                  "expected 26002, is %d",
                  check_msg->stec_sat_list[6].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[6].stec_coeff[2] == -29879,
                  "incorrect value for stec_sat_list[6].stec_coeff[2], "
                  "expected -29879, is %d",
                  check_msg->stec_sat_list[6].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[6].stec_coeff[3] == 30008,
                  "incorrect value for stec_sat_list[6].stec_coeff[3], "
                  "expected 30008, is %d",
                  check_msg->stec_sat_list[6].stec_coeff[3]);
    ck_assert_msg(check_msg->stec_sat_list[6].stec_quality_indicator == 9,
                  "incorrect value for "
                  "stec_sat_list[6].stec_quality_indicator, expected 9, is %d",
                  check_msg->stec_sat_list[6].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[6].sv_id.constellation == 108,
                  "incorrect value for stec_sat_list[6].sv_id.constellation, "
                  "expected 108, is %d",
                  check_msg->stec_sat_list[6].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[6].sv_id.satId == 51,
        "incorrect value for stec_sat_list[6].sv_id.satId, expected 51, is %d",
        check_msg->stec_sat_list[6].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[7].stec_coeff[0] == -12948,
                  "incorrect value for stec_sat_list[7].stec_coeff[0], "
                  "expected -12948, is %d",
                  check_msg->stec_sat_list[7].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[7].stec_coeff[1] == 4701,
                  "incorrect value for stec_sat_list[7].stec_coeff[1], "
                  "expected 4701, is %d",
                  check_msg->stec_sat_list[7].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[7].stec_coeff[2] == -15597,
                  "incorrect value for stec_sat_list[7].stec_coeff[2], "
                  "expected -15597, is %d",
                  check_msg->stec_sat_list[7].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[7].stec_coeff[3] == -13791,
                  "incorrect value for stec_sat_list[7].stec_coeff[3], "
                  "expected -13791, is %d",
                  check_msg->stec_sat_list[7].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[7].stec_quality_indicator == 213,
        "incorrect value for stec_sat_list[7].stec_quality_indicator, expected "
        "213, is %d",
        check_msg->stec_sat_list[7].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[7].sv_id.constellation == 37,
                  "incorrect value for stec_sat_list[7].sv_id.constellation, "
                  "expected 37, is %d",
                  check_msg->stec_sat_list[7].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[7].sv_id.satId == 82,
        "incorrect value for stec_sat_list[7].sv_id.satId, expected 82, is %d",
        check_msg->stec_sat_list[7].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[8].stec_coeff[0] == -17283,
                  "incorrect value for stec_sat_list[8].stec_coeff[0], "
                  "expected -17283, is %d",
                  check_msg->stec_sat_list[8].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[8].stec_coeff[1] == 14455,
                  "incorrect value for stec_sat_list[8].stec_coeff[1], "
                  "expected 14455, is %d",
                  check_msg->stec_sat_list[8].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[8].stec_coeff[2] == -27067,
                  "incorrect value for stec_sat_list[8].stec_coeff[2], "
                  "expected -27067, is %d",
                  check_msg->stec_sat_list[8].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[8].stec_coeff[3] == 19606,
                  "incorrect value for stec_sat_list[8].stec_coeff[3], "
                  "expected 19606, is %d",
                  check_msg->stec_sat_list[8].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[8].stec_quality_indicator == 178,
        "incorrect value for stec_sat_list[8].stec_quality_indicator, expected "
        "178, is %d",
        check_msg->stec_sat_list[8].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[8].sv_id.constellation == 206,
                  "incorrect value for stec_sat_list[8].sv_id.constellation, "
                  "expected 206, is %d",
                  check_msg->stec_sat_list[8].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[8].sv_id.satId == 87,
        "incorrect value for stec_sat_list[8].sv_id.satId, expected 87, is %d",
        check_msg->stec_sat_list[8].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[9].stec_coeff[0] == -12215,
                  "incorrect value for stec_sat_list[9].stec_coeff[0], "
                  "expected -12215, is %d",
                  check_msg->stec_sat_list[9].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[9].stec_coeff[1] == -6072,
                  "incorrect value for stec_sat_list[9].stec_coeff[1], "
                  "expected -6072, is %d",
                  check_msg->stec_sat_list[9].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[9].stec_coeff[2] == -1528,
                  "incorrect value for stec_sat_list[9].stec_coeff[2], "
                  "expected -1528, is %d",
                  check_msg->stec_sat_list[9].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[9].stec_coeff[3] == -19765,
                  "incorrect value for stec_sat_list[9].stec_coeff[3], "
                  "expected -19765, is %d",
                  check_msg->stec_sat_list[9].stec_coeff[3]);
    ck_assert_msg(check_msg->stec_sat_list[9].stec_quality_indicator == 18,
                  "incorrect value for "
                  "stec_sat_list[9].stec_quality_indicator, expected 18, is %d",
                  check_msg->stec_sat_list[9].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[9].sv_id.constellation == 131,
                  "incorrect value for stec_sat_list[9].sv_id.constellation, "
                  "expected 131, is %d",
                  check_msg->stec_sat_list[9].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[9].sv_id.satId == 3,
        "incorrect value for stec_sat_list[9].sv_id.satId, expected 3, is %d",
        check_msg->stec_sat_list[9].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[10].stec_coeff[0] == 12630,
                  "incorrect value for stec_sat_list[10].stec_coeff[0], "
                  "expected 12630, is %d",
                  check_msg->stec_sat_list[10].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[10].stec_coeff[1] == -19721,
                  "incorrect value for stec_sat_list[10].stec_coeff[1], "
                  "expected -19721, is %d",
                  check_msg->stec_sat_list[10].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[10].stec_coeff[2] == 14502,
                  "incorrect value for stec_sat_list[10].stec_coeff[2], "
                  "expected 14502, is %d",
                  check_msg->stec_sat_list[10].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[10].stec_coeff[3] == 2591,
                  "incorrect value for stec_sat_list[10].stec_coeff[3], "
                  "expected 2591, is %d",
                  check_msg->stec_sat_list[10].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[10].stec_quality_indicator == 252,
        "incorrect value for stec_sat_list[10].stec_quality_indicator, "
        "expected 252, is %d",
        check_msg->stec_sat_list[10].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[10].sv_id.constellation == 163,
                  "incorrect value for stec_sat_list[10].sv_id.constellation, "
                  "expected 163, is %d",
                  check_msg->stec_sat_list[10].sv_id.constellation);
    ck_assert_msg(check_msg->stec_sat_list[10].sv_id.satId == 170,
                  "incorrect value for stec_sat_list[10].sv_id.satId, expected "
                  "170, is %d",
                  check_msg->stec_sat_list[10].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[11].stec_coeff[0] == -23340,
                  "incorrect value for stec_sat_list[11].stec_coeff[0], "
                  "expected -23340, is %d",
                  check_msg->stec_sat_list[11].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[11].stec_coeff[1] == -24063,
                  "incorrect value for stec_sat_list[11].stec_coeff[1], "
                  "expected -24063, is %d",
                  check_msg->stec_sat_list[11].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[11].stec_coeff[2] == 4650,
                  "incorrect value for stec_sat_list[11].stec_coeff[2], "
                  "expected 4650, is %d",
                  check_msg->stec_sat_list[11].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[11].stec_coeff[3] == -22148,
                  "incorrect value for stec_sat_list[11].stec_coeff[3], "
                  "expected -22148, is %d",
                  check_msg->stec_sat_list[11].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[11].stec_quality_indicator == 241,
        "incorrect value for stec_sat_list[11].stec_quality_indicator, "
        "expected 241, is %d",
        check_msg->stec_sat_list[11].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[11].sv_id.constellation == 213,
                  "incorrect value for stec_sat_list[11].sv_id.constellation, "
                  "expected 213, is %d",
                  check_msg->stec_sat_list[11].sv_id.constellation);
    ck_assert_msg(check_msg->stec_sat_list[11].sv_id.satId == 119,
                  "incorrect value for stec_sat_list[11].sv_id.satId, expected "
                  "119, is %d",
                  check_msg->stec_sat_list[11].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[12].stec_coeff[0] == 5944,
                  "incorrect value for stec_sat_list[12].stec_coeff[0], "
                  "expected 5944, is %d",
                  check_msg->stec_sat_list[12].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[12].stec_coeff[1] == 32142,
                  "incorrect value for stec_sat_list[12].stec_coeff[1], "
                  "expected 32142, is %d",
                  check_msg->stec_sat_list[12].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[12].stec_coeff[2] == 30760,
                  "incorrect value for stec_sat_list[12].stec_coeff[2], "
                  "expected 30760, is %d",
                  check_msg->stec_sat_list[12].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[12].stec_coeff[3] == 11587,
                  "incorrect value for stec_sat_list[12].stec_coeff[3], "
                  "expected 11587, is %d",
                  check_msg->stec_sat_list[12].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[12].stec_quality_indicator == 26,
        "incorrect value for stec_sat_list[12].stec_quality_indicator, "
        "expected 26, is %d",
        check_msg->stec_sat_list[12].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[12].sv_id.constellation == 158,
                  "incorrect value for stec_sat_list[12].sv_id.constellation, "
                  "expected 158, is %d",
                  check_msg->stec_sat_list[12].sv_id.constellation);
    ck_assert_msg(check_msg->stec_sat_list[12].sv_id.satId == 121,
                  "incorrect value for stec_sat_list[12].sv_id.satId, expected "
                  "121, is %d",
                  check_msg->stec_sat_list[12].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[13].stec_coeff[0] == 3095,
                  "incorrect value for stec_sat_list[13].stec_coeff[0], "
                  "expected 3095, is %d",
                  check_msg->stec_sat_list[13].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[13].stec_coeff[1] == 22769,
                  "incorrect value for stec_sat_list[13].stec_coeff[1], "
                  "expected 22769, is %d",
                  check_msg->stec_sat_list[13].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[13].stec_coeff[2] == -4283,
                  "incorrect value for stec_sat_list[13].stec_coeff[2], "
                  "expected -4283, is %d",
                  check_msg->stec_sat_list[13].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[13].stec_coeff[3] == 14844,
                  "incorrect value for stec_sat_list[13].stec_coeff[3], "
                  "expected 14844, is %d",
                  check_msg->stec_sat_list[13].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[13].stec_quality_indicator == 110,
        "incorrect value for stec_sat_list[13].stec_quality_indicator, "
        "expected 110, is %d",
        check_msg->stec_sat_list[13].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[13].sv_id.constellation == 235,
                  "incorrect value for stec_sat_list[13].sv_id.constellation, "
                  "expected 235, is %d",
                  check_msg->stec_sat_list[13].sv_id.constellation);
    ck_assert_msg(check_msg->stec_sat_list[13].sv_id.satId == 126,
                  "incorrect value for stec_sat_list[13].sv_id.satId, expected "
                  "126, is %d",
                  check_msg->stec_sat_list[13].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[14].stec_coeff[0] == -21032,
                  "incorrect value for stec_sat_list[14].stec_coeff[0], "
                  "expected -21032, is %d",
                  check_msg->stec_sat_list[14].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[14].stec_coeff[1] == -19726,
                  "incorrect value for stec_sat_list[14].stec_coeff[1], "
                  "expected -19726, is %d",
                  check_msg->stec_sat_list[14].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[14].stec_coeff[2] == 1297,
                  "incorrect value for stec_sat_list[14].stec_coeff[2], "
                  "expected 1297, is %d",
                  check_msg->stec_sat_list[14].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[14].stec_coeff[3] == -22049,
                  "incorrect value for stec_sat_list[14].stec_coeff[3], "
                  "expected -22049, is %d",
                  check_msg->stec_sat_list[14].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[14].stec_quality_indicator == 201,
        "incorrect value for stec_sat_list[14].stec_quality_indicator, "
        "expected 201, is %d",
        check_msg->stec_sat_list[14].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[14].sv_id.constellation == 44,
                  "incorrect value for stec_sat_list[14].sv_id.constellation, "
                  "expected 44, is %d",
                  check_msg->stec_sat_list[14].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[14].sv_id.satId == 93,
        "incorrect value for stec_sat_list[14].sv_id.satId, expected 93, is %d",
        check_msg->stec_sat_list[14].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[15].stec_coeff[0] == 619,
                  "incorrect value for stec_sat_list[15].stec_coeff[0], "
                  "expected 619, is %d",
                  check_msg->stec_sat_list[15].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[15].stec_coeff[1] == -5744,
                  "incorrect value for stec_sat_list[15].stec_coeff[1], "
                  "expected -5744, is %d",
                  check_msg->stec_sat_list[15].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[15].stec_coeff[2] == 22542,
                  "incorrect value for stec_sat_list[15].stec_coeff[2], "
                  "expected 22542, is %d",
                  check_msg->stec_sat_list[15].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[15].stec_coeff[3] == -12000,
                  "incorrect value for stec_sat_list[15].stec_coeff[3], "
                  "expected -12000, is %d",
                  check_msg->stec_sat_list[15].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[15].stec_quality_indicator == 77,
        "incorrect value for stec_sat_list[15].stec_quality_indicator, "
        "expected 77, is %d",
        check_msg->stec_sat_list[15].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[15].sv_id.constellation == 3,
                  "incorrect value for stec_sat_list[15].sv_id.constellation, "
                  "expected 3, is %d",
                  check_msg->stec_sat_list[15].sv_id.constellation);
    ck_assert_msg(check_msg->stec_sat_list[15].sv_id.satId == 192,
                  "incorrect value for stec_sat_list[15].sv_id.satId, expected "
                  "192, is %d",
                  check_msg->stec_sat_list[15].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[16].stec_coeff[0] == 10651,
                  "incorrect value for stec_sat_list[16].stec_coeff[0], "
                  "expected 10651, is %d",
                  check_msg->stec_sat_list[16].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[16].stec_coeff[1] == -2889,
                  "incorrect value for stec_sat_list[16].stec_coeff[1], "
                  "expected -2889, is %d",
                  check_msg->stec_sat_list[16].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[16].stec_coeff[2] == 21150,
                  "incorrect value for stec_sat_list[16].stec_coeff[2], "
                  "expected 21150, is %d",
                  check_msg->stec_sat_list[16].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[16].stec_coeff[3] == 26421,
                  "incorrect value for stec_sat_list[16].stec_coeff[3], "
                  "expected 26421, is %d",
                  check_msg->stec_sat_list[16].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[16].stec_quality_indicator == 123,
        "incorrect value for stec_sat_list[16].stec_quality_indicator, "
        "expected 123, is %d",
        check_msg->stec_sat_list[16].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[16].sv_id.constellation == 17,
                  "incorrect value for stec_sat_list[16].sv_id.constellation, "
                  "expected 17, is %d",
                  check_msg->stec_sat_list[16].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[16].sv_id.satId == 1,
        "incorrect value for stec_sat_list[16].sv_id.satId, expected 1, is %d",
        check_msg->stec_sat_list[16].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[17].stec_coeff[0] == -19165,
                  "incorrect value for stec_sat_list[17].stec_coeff[0], "
                  "expected -19165, is %d",
                  check_msg->stec_sat_list[17].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[17].stec_coeff[1] == 30229,
                  "incorrect value for stec_sat_list[17].stec_coeff[1], "
                  "expected 30229, is %d",
                  check_msg->stec_sat_list[17].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[17].stec_coeff[2] == -1282,
                  "incorrect value for stec_sat_list[17].stec_coeff[2], "
                  "expected -1282, is %d",
                  check_msg->stec_sat_list[17].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[17].stec_coeff[3] == -18382,
                  "incorrect value for stec_sat_list[17].stec_coeff[3], "
                  "expected -18382, is %d",
                  check_msg->stec_sat_list[17].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[17].stec_quality_indicator == 185,
        "incorrect value for stec_sat_list[17].stec_quality_indicator, "
        "expected 185, is %d",
        check_msg->stec_sat_list[17].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[17].sv_id.constellation == 202,
                  "incorrect value for stec_sat_list[17].sv_id.constellation, "
                  "expected 202, is %d",
                  check_msg->stec_sat_list[17].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[17].sv_id.satId == 14,
        "incorrect value for stec_sat_list[17].sv_id.satId, expected 14, is %d",
        check_msg->stec_sat_list[17].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[18].stec_coeff[0] == -23752,
                  "incorrect value for stec_sat_list[18].stec_coeff[0], "
                  "expected -23752, is %d",
                  check_msg->stec_sat_list[18].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[18].stec_coeff[1] == 32433,
                  "incorrect value for stec_sat_list[18].stec_coeff[1], "
                  "expected 32433, is %d",
                  check_msg->stec_sat_list[18].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[18].stec_coeff[2] == 20441,
                  "incorrect value for stec_sat_list[18].stec_coeff[2], "
                  "expected 20441, is %d",
                  check_msg->stec_sat_list[18].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[18].stec_coeff[3] == -4181,
                  "incorrect value for stec_sat_list[18].stec_coeff[3], "
                  "expected -4181, is %d",
                  check_msg->stec_sat_list[18].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[18].stec_quality_indicator == 45,
        "incorrect value for stec_sat_list[18].stec_quality_indicator, "
        "expected 45, is %d",
        check_msg->stec_sat_list[18].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[18].sv_id.constellation == 31,
                  "incorrect value for stec_sat_list[18].sv_id.constellation, "
                  "expected 31, is %d",
                  check_msg->stec_sat_list[18].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[18].sv_id.satId == 50,
        "incorrect value for stec_sat_list[18].sv_id.satId, expected 50, is %d",
        check_msg->stec_sat_list[18].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[19].stec_coeff[0] == -13968,
                  "incorrect value for stec_sat_list[19].stec_coeff[0], "
                  "expected -13968, is %d",
                  check_msg->stec_sat_list[19].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[19].stec_coeff[1] == -29322,
                  "incorrect value for stec_sat_list[19].stec_coeff[1], "
                  "expected -29322, is %d",
                  check_msg->stec_sat_list[19].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[19].stec_coeff[2] == -23790,
                  "incorrect value for stec_sat_list[19].stec_coeff[2], "
                  "expected -23790, is %d",
                  check_msg->stec_sat_list[19].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[19].stec_coeff[3] == 9063,
                  "incorrect value for stec_sat_list[19].stec_coeff[3], "
                  "expected 9063, is %d",
                  check_msg->stec_sat_list[19].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[19].stec_quality_indicator == 238,
        "incorrect value for stec_sat_list[19].stec_quality_indicator, "
        "expected 238, is %d",
        check_msg->stec_sat_list[19].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[19].sv_id.constellation == 188,
                  "incorrect value for stec_sat_list[19].sv_id.constellation, "
                  "expected 188, is %d",
                  check_msg->stec_sat_list[19].sv_id.constellation);
    ck_assert_msg(check_msg->stec_sat_list[19].sv_id.satId == 237,
                  "incorrect value for stec_sat_list[19].sv_id.satId, expected "
                  "237, is %d",
                  check_msg->stec_sat_list[19].sv_id.satId);
    ck_assert_msg(check_msg->stec_sat_list[20].stec_coeff[0] == 4737,
                  "incorrect value for stec_sat_list[20].stec_coeff[0], "
                  "expected 4737, is %d",
                  check_msg->stec_sat_list[20].stec_coeff[0]);
    ck_assert_msg(check_msg->stec_sat_list[20].stec_coeff[1] == 21877,
                  "incorrect value for stec_sat_list[20].stec_coeff[1], "
                  "expected 21877, is %d",
                  check_msg->stec_sat_list[20].stec_coeff[1]);
    ck_assert_msg(check_msg->stec_sat_list[20].stec_coeff[2] == 20414,
                  "incorrect value for stec_sat_list[20].stec_coeff[2], "
                  "expected 20414, is %d",
                  check_msg->stec_sat_list[20].stec_coeff[2]);
    ck_assert_msg(check_msg->stec_sat_list[20].stec_coeff[3] == -10286,
                  "incorrect value for stec_sat_list[20].stec_coeff[3], "
                  "expected -10286, is %d",
                  check_msg->stec_sat_list[20].stec_coeff[3]);
    ck_assert_msg(
        check_msg->stec_sat_list[20].stec_quality_indicator == 82,
        "incorrect value for stec_sat_list[20].stec_quality_indicator, "
        "expected 82, is %d",
        check_msg->stec_sat_list[20].stec_quality_indicator);
    ck_assert_msg(check_msg->stec_sat_list[20].sv_id.constellation == 21,
                  "incorrect value for stec_sat_list[20].sv_id.constellation, "
                  "expected 21, is %d",
                  check_msg->stec_sat_list[20].sv_id.constellation);
    ck_assert_msg(
        check_msg->stec_sat_list[20].sv_id.satId == 63,
        "incorrect value for stec_sat_list[20].sv_id.satId, expected 63, is %d",
        check_msg->stec_sat_list[20].sv_id.satId);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep);
  suite_add_tcase(s, tc_acq);
  return s;
}