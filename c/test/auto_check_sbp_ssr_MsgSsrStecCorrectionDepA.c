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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml by
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

START_TEST(test_auto_check_sbp_ssr_MsgSsrStecCorrectionDepA) {
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

    sbp_callback_register(&sbp_state, 0x5eb, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  235, 5,   39,  7,   252, 70,  81,  196, 232, 185, 43,  147, 123,
        39,  4,   126, 19,  111, 97,  248, 130, 217, 217, 106, 58,  12,  65,
        230, 171, 81,  95,  86,  16,  39,  84,  228, 208, 201, 81,  219, 99,
        203, 61,  182, 66,  125, 203, 3,   193, 44,  100, 220, 125, 60,  21,
        93,  218, 247, 158, 207, 93,  129, 134, 14,  209, 48,  14,  215, 153,
        148, 147, 72,  225, 180, 236, 205, 201, 33,  3,   246, 204, 19,  3,
        98,  4,   194, 191, 246, 76,  219, 31,  191, 113, 79,  177, 15,  251,
        33,  19,  96,  54,  58,  146, 210, 100, 249, 72,  21,  161, 211, 198,
        21,  238, 111, 107, 36,  227, 225, 213, 3,   71,  243, 63,  65,  236,
        92,  77,  0,   169, 15,  182, 5,   240, 180, 9,   122, 86,  232, 6,
        103, 104, 254, 189, 81,  110, 2,   49,  202, 84,  216, 55,  50,  181,
        5,   123, 80,  49,  244, 224, 188, 125, 164, 230, 56,  66,  124, 168,
        59,  139, 106, 118, 51,  187, 216, 191, 158, 77,  92,  58,  253, 132,
        150, 165, 9,   154, 189, 218, 61,  209, 1,   82,  181, 196, 23,  53,
        182, 112, 192, 206, 167, 157, 244, 35,  1,   189, 217, 61,  88,  97,
        201, 201, 74,  251, 217, 14,  104, 184, 54,  52,  74,  238, 10,  129,
        22,  178, 226, 109, 88,  157, 30,  196, 175, 26,  76,  34,  116, 220,
        154, 232, 12,  179, 244, 15,  155, 196, 202, 72,  70,  115, 10,  214,
        114, 39,  245, 28,  237, 68,  136, 155,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_stec_correction_dep_a.header.iod_atmo = 4;

    test_msg.ssr_stec_correction_dep_a.header.num_msgs = 147;

    test_msg.ssr_stec_correction_dep_a.header.seq_num = 123;

    test_msg.ssr_stec_correction_dep_a.header.time.tow = 3905179974;

    test_msg.ssr_stec_correction_dep_a.header.time.wn = 11193;

    test_msg.ssr_stec_correction_dep_a.header.update_interval = 39;

    test_msg.ssr_stec_correction_dep_a.n_stec_sat_list = 22;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[0] = -1951;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[1] = -9854;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[2] = 27353;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[3] = 3130;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_quality_indicator =
        111;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].sv_id.constellation =
        19;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[0].sv_id.satId = 126;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[0] = 24401;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[1] = 4182;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[2] = 21543;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[3] = -12060;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_quality_indicator =
        171;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].sv_id.constellation =
        230;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[1].sv_id.satId = 65;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[0] = -13469;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[1] = -18883;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[2] = 32066;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[3] = 971;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_quality_indicator =
        219;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].sv_id.constellation =
        81;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[2].sv_id.satId = 201;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[0] = 32220;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[1] = 5436;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[2] = -9635;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[3] = -24841;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_quality_indicator =
        100;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].sv_id.constellation =
        44;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[3].sv_id.satId = 193;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[0] = 3718;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[1] = 12497;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[2] = -10482;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[3] = -27495;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_quality_indicator =
        129;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].sv_id.constellation =
        93;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[4].sv_id.satId = 207;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[0] = -4940;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[1] = -13875;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[2] = 801;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[3] = -13066;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_quality_indicator =
        225;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].sv_id.constellation =
        72;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[5].sv_id.satId = 147;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[0] = -15868;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[1] = -2369;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[2] = -9396;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[3] = -16609;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_quality_indicator =
        98;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].sv_id.constellation = 3;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[6].sv_id.satId = 19;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[0] = -1265;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[1] = 4897;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[2] = 13920;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[3] = -28102;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_quality_indicator =
        177;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].sv_id.constellation =
        79;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[7].sv_id.satId = 113;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[0] = 5448;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[1] = -11359;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[2] = 5574;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[3] = 28654;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_quality_indicator =
        249;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].sv_id.constellation =
        100;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[8].sv_id.satId = 210;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[0] = -10783;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[1] = 18179;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[2] = 16371;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[3] = -5055;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_quality_indicator =
        227;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].sv_id.constellation =
        36;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[9].sv_id.satId = 107;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[0] = 4009;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[1] = 1462;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[2] = -19216;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[3] = 31241;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10]
        .stec_quality_indicator = 0;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10].sv_id.constellation =
        77;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[10].sv_id.satId = 92;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[0] = 26727;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[1] = -16898;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[2] = 28241;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[3] = 12546;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11]
        .stec_quality_indicator = 6;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11].sv_id.constellation =
        232;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[11].sv_id.satId = 86;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[0] = 12855;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[1] = 1461;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[2] = 20603;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[3] = -3023;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12]
        .stec_quality_indicator = 216;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12].sv_id.constellation =
        84;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[12].sv_id.satId = 202;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[0] = -6492;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[1] = 16952;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[2] = -22404;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[3] = -29893;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13]
        .stec_quality_indicator = 125;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13].sv_id.constellation =
        188;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[13].sv_id.satId = 224;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[0] = -10053;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[1] = -24897;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[2] = 23629;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[3] = -710;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14]
        .stec_quality_indicator = 51;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14].sv_id.constellation =
        118;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[14].sv_id.satId = 106;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[0] = -26103;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[1] = -9539;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[2] = -11971;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[3] = 20993;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15]
        .stec_quality_indicator = 165;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15].sv_id.constellation =
        150;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[15].sv_id.satId = 132;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[0] = -18891;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[1] = -16272;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[2] = -22578;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[3] = -2915;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16]
        .stec_quality_indicator = 23;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16].sv_id.constellation =
        196;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[16].sv_id.satId = 181;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[0] = 15833;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[1] = 24920;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[2] = -13879;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[3] = -1206;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17]
        .stec_quality_indicator = 189;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17].sv_id.constellation =
        1;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[17].sv_id.satId = 35;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[0] = 14008;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[1] = 18996;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[2] = 2798;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[3] = 5761;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18]
        .stec_quality_indicator = 104;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18].sv_id.constellation =
        14;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[18].sv_id.satId = 217;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[0] = -25256;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[1] = -15330;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[2] = 6831;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[3] = 8780;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19]
        .stec_quality_indicator = 109;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19].sv_id.constellation =
        226;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[19].sv_id.satId = 178;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[0] = 3304;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[1] = -2893;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[2] = -25841;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[3] = -13628;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20]
        .stec_quality_indicator = 154;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20].sv_id.constellation =
        220;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[20].sv_id.satId = 116;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[0] = -10742;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[1] = 10098;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[2] = 7413;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[3] = 17645;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21]
        .stec_quality_indicator = 115;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21].sv_id.constellation =
        70;

    test_msg.ssr_stec_correction_dep_a.stec_sat_list[21].sv_id.satId = 72;

    sbp_message_send(&sbp_state, SbpMsgSsrStecCorrectionDepA, 1831, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1831,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgSsrStecCorrectionDepA, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.header.iod_atmo == 4,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.header.iod_atmo, expected 4, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.header.iod_atmo);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.header.num_msgs == 147,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.header.num_msgs, expected 147, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.header.num_msgs);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.header.seq_num == 123,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.header.seq_num, expected 123, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.header.seq_num);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.header.time.tow == 3905179974,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.header.time.tow, expected "
        "3905179974, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.header.time.tow);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.header.time.wn == 11193,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.header.time.wn, expected "
        "11193, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.header.time.wn);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.header.update_interval == 39,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.header.update_interval, "
        "expected 39, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.header.update_interval);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.n_stec_sat_list == 22,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.n_stec_sat_list, expected 22, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.n_stec_sat_list);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[0] ==
            -1951,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[0],"
        " expected -1951, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[1] ==
            -9854,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[1],"
        " expected -9854, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[2] ==
            27353,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[2],"
        " expected 27353, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[3] ==
            3130,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_coeff[3],"
        " expected 3130, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
                .stec_quality_indicator == 111,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].stec_quality_"
        "indicator, expected 111, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
                .sv_id.constellation == 19,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].sv_id."
        "constellation, expected 19, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].sv_id.satId ==
            126,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0].sv_id.satId, "
        "expected 126, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[0]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[0] ==
            24401,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[0],"
        " expected 24401, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[1] ==
            4182,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[1],"
        " expected 4182, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[2] ==
            21543,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[2],"
        " expected 21543, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[3] ==
            -12060,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_coeff[3],"
        " expected -12060, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
                .stec_quality_indicator == 171,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].stec_quality_"
        "indicator, expected 171, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
                .sv_id.constellation == 230,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].sv_id."
        "constellation, expected 230, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].sv_id.satId ==
            65,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1].sv_id.satId, "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[1]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[0] ==
            -13469,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[0],"
        " expected -13469, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[1] ==
            -18883,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[1],"
        " expected -18883, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[2] ==
            32066,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[2],"
        " expected 32066, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[3] ==
            971,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_coeff[3],"
        " expected 971, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
                .stec_quality_indicator == 219,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].stec_quality_"
        "indicator, expected 219, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
                .sv_id.constellation == 81,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].sv_id."
        "constellation, expected 81, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].sv_id.satId ==
            201,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2].sv_id.satId, "
        "expected 201, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[2]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[0] ==
            32220,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[0],"
        " expected 32220, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[1] ==
            5436,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[1],"
        " expected 5436, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[2] ==
            -9635,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[2],"
        " expected -9635, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[3] ==
            -24841,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_coeff[3],"
        " expected -24841, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
                .stec_quality_indicator == 100,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].stec_quality_"
        "indicator, expected 100, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
                .sv_id.constellation == 44,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].sv_id."
        "constellation, expected 44, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].sv_id.satId ==
            193,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3].sv_id.satId, "
        "expected 193, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[3]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[0] ==
            3718,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[0],"
        " expected 3718, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[1] ==
            12497,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[1],"
        " expected 12497, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[2] ==
            -10482,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[2],"
        " expected -10482, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[3] ==
            -27495,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_coeff[3],"
        " expected -27495, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
                .stec_quality_indicator == 129,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].stec_quality_"
        "indicator, expected 129, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
                .sv_id.constellation == 93,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].sv_id."
        "constellation, expected 93, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].sv_id.satId ==
            207,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4].sv_id.satId, "
        "expected 207, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[4]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[0] ==
            -4940,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[0],"
        " expected -4940, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[1] ==
            -13875,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[1],"
        " expected -13875, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[2] ==
            801,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[2],"
        " expected 801, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[3] ==
            -13066,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_coeff[3],"
        " expected -13066, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
                .stec_quality_indicator == 225,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].stec_quality_"
        "indicator, expected 225, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
                .sv_id.constellation == 72,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].sv_id."
        "constellation, expected 72, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].sv_id.satId ==
            147,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5].sv_id.satId, "
        "expected 147, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[5]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[0] ==
            -15868,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[0],"
        " expected -15868, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[1] ==
            -2369,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[1],"
        " expected -2369, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[2] ==
            -9396,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[2],"
        " expected -9396, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[3] ==
            -16609,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_coeff[3],"
        " expected -16609, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
                .stec_quality_indicator == 98,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].stec_quality_"
        "indicator, expected 98, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
                .sv_id.constellation == 3,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].sv_id."
        "constellation, expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].sv_id.satId ==
            19,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6].sv_id.satId, "
        "expected 19, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[6]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[0] ==
            -1265,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[0],"
        " expected -1265, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[1] ==
            4897,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[1],"
        " expected 4897, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[2] ==
            13920,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[2],"
        " expected 13920, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[3] ==
            -28102,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_coeff[3],"
        " expected -28102, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
                .stec_quality_indicator == 177,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].stec_quality_"
        "indicator, expected 177, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
                .sv_id.constellation == 79,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].sv_id."
        "constellation, expected 79, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].sv_id.satId ==
            113,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7].sv_id.satId, "
        "expected 113, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[7]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[0] ==
            5448,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[0],"
        " expected 5448, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[1] ==
            -11359,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[1],"
        " expected -11359, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[2] ==
            5574,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[2],"
        " expected 5574, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[3] ==
            28654,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_coeff[3],"
        " expected 28654, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
                .stec_quality_indicator == 249,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].stec_quality_"
        "indicator, expected 249, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
                .sv_id.constellation == 100,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].sv_id."
        "constellation, expected 100, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].sv_id.satId ==
            210,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8].sv_id.satId, "
        "expected 210, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[8]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[0] ==
            -10783,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[0],"
        " expected -10783, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[1] ==
            18179,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[1],"
        " expected 18179, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[2] ==
            16371,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[2],"
        " expected 16371, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[3] ==
            -5055,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_coeff[3],"
        " expected -5055, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
                .stec_quality_indicator == 227,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].stec_quality_"
        "indicator, expected 227, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
                .sv_id.constellation == 36,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].sv_id."
        "constellation, expected 36, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].sv_id.satId ==
            107,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9].sv_id.satId, "
        "expected 107, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[9]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
                .stec_coeff[0] == 4009,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[0]"
        ", expected 4009, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
                .stec_coeff[1] == 1462,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[1]"
        ", expected 1462, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
                .stec_coeff[2] == -19216,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[2]"
        ", expected -19216, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
                .stec_coeff[3] == 31241,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_coeff[3]"
        ", expected 31241, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
                .stec_quality_indicator == 0,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].stec_quality_"
        "indicator, expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
                .sv_id.constellation == 77,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].sv_id."
        "constellation, expected 77, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].sv_id.satId ==
            92,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10].sv_id.satId, "
        "expected 92, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[10]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
                .stec_coeff[0] == 26727,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[0]"
        ", expected 26727, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
                .stec_coeff[1] == -16898,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[1]"
        ", expected -16898, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
                .stec_coeff[2] == 28241,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[2]"
        ", expected 28241, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
                .stec_coeff[3] == 12546,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_coeff[3]"
        ", expected 12546, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
                .stec_quality_indicator == 6,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].stec_quality_"
        "indicator, expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
                .sv_id.constellation == 232,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].sv_id."
        "constellation, expected 232, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].sv_id.satId ==
            86,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11].sv_id.satId, "
        "expected 86, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[11]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
                .stec_coeff[0] == 12855,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[0]"
        ", expected 12855, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
                .stec_coeff[1] == 1461,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[1]"
        ", expected 1461, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
                .stec_coeff[2] == 20603,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[2]"
        ", expected 20603, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
                .stec_coeff[3] == -3023,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_coeff[3]"
        ", expected -3023, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
                .stec_quality_indicator == 216,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].stec_quality_"
        "indicator, expected 216, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
                .sv_id.constellation == 84,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].sv_id."
        "constellation, expected 84, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].sv_id.satId ==
            202,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12].sv_id.satId, "
        "expected 202, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[12]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
                .stec_coeff[0] == -6492,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[0]"
        ", expected -6492, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
                .stec_coeff[1] == 16952,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[1]"
        ", expected 16952, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
                .stec_coeff[2] == -22404,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[2]"
        ", expected -22404, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
                .stec_coeff[3] == -29893,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_coeff[3]"
        ", expected -29893, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
                .stec_quality_indicator == 125,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].stec_quality_"
        "indicator, expected 125, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
                .sv_id.constellation == 188,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].sv_id."
        "constellation, expected 188, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].sv_id.satId ==
            224,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13].sv_id.satId, "
        "expected 224, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[13]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
                .stec_coeff[0] == -10053,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[0]"
        ", expected -10053, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
                .stec_coeff[1] == -24897,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[1]"
        ", expected -24897, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
                .stec_coeff[2] == 23629,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[2]"
        ", expected 23629, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
                .stec_coeff[3] == -710,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_coeff[3]"
        ", expected -710, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
                .stec_quality_indicator == 51,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].stec_quality_"
        "indicator, expected 51, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
                .sv_id.constellation == 118,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].sv_id."
        "constellation, expected 118, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].sv_id.satId ==
            106,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14].sv_id.satId, "
        "expected 106, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[14]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
                .stec_coeff[0] == -26103,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[0]"
        ", expected -26103, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
                .stec_coeff[1] == -9539,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[1]"
        ", expected -9539, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
                .stec_coeff[2] == -11971,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[2]"
        ", expected -11971, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
                .stec_coeff[3] == 20993,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_coeff[3]"
        ", expected 20993, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
                .stec_quality_indicator == 165,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].stec_quality_"
        "indicator, expected 165, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
                .sv_id.constellation == 150,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].sv_id."
        "constellation, expected 150, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].sv_id.satId ==
            132,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15].sv_id.satId, "
        "expected 132, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[15]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
                .stec_coeff[0] == -18891,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[0]"
        ", expected -18891, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
                .stec_coeff[1] == -16272,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[1]"
        ", expected -16272, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
                .stec_coeff[2] == -22578,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[2]"
        ", expected -22578, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
                .stec_coeff[3] == -2915,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_coeff[3]"
        ", expected -2915, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
                .stec_quality_indicator == 23,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].stec_quality_"
        "indicator, expected 23, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
                .sv_id.constellation == 196,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].sv_id."
        "constellation, expected 196, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].sv_id.satId ==
            181,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16].sv_id.satId, "
        "expected 181, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[16]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
                .stec_coeff[0] == 15833,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[0]"
        ", expected 15833, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
                .stec_coeff[1] == 24920,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[1]"
        ", expected 24920, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
                .stec_coeff[2] == -13879,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[2]"
        ", expected -13879, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
                .stec_coeff[3] == -1206,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_coeff[3]"
        ", expected -1206, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
                .stec_quality_indicator == 189,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].stec_quality_"
        "indicator, expected 189, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
                .sv_id.constellation == 1,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].sv_id."
        "constellation, expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].sv_id.satId ==
            35,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17].sv_id.satId, "
        "expected 35, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[17]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
                .stec_coeff[0] == 14008,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[0]"
        ", expected 14008, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
                .stec_coeff[1] == 18996,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[1]"
        ", expected 18996, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
                .stec_coeff[2] == 2798,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[2]"
        ", expected 2798, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
                .stec_coeff[3] == 5761,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_coeff[3]"
        ", expected 5761, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
                .stec_quality_indicator == 104,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].stec_quality_"
        "indicator, expected 104, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
                .sv_id.constellation == 14,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].sv_id."
        "constellation, expected 14, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].sv_id.satId ==
            217,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18].sv_id.satId, "
        "expected 217, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[18]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
                .stec_coeff[0] == -25256,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[0]"
        ", expected -25256, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
                .stec_coeff[1] == -15330,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[1]"
        ", expected -15330, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
                .stec_coeff[2] == 6831,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[2]"
        ", expected 6831, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
                .stec_coeff[3] == 8780,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_coeff[3]"
        ", expected 8780, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
                .stec_quality_indicator == 109,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].stec_quality_"
        "indicator, expected 109, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
                .sv_id.constellation == 226,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].sv_id."
        "constellation, expected 226, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].sv_id.satId ==
            178,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19].sv_id.satId, "
        "expected 178, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[19]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
                .stec_coeff[0] == 3304,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[0]"
        ", expected 3304, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
                .stec_coeff[1] == -2893,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[1]"
        ", expected -2893, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
                .stec_coeff[2] == -25841,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[2]"
        ", expected -25841, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
                .stec_coeff[3] == -13628,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_coeff[3]"
        ", expected -13628, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
                .stec_quality_indicator == 154,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].stec_quality_"
        "indicator, expected 154, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
                .sv_id.constellation == 220,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].sv_id."
        "constellation, expected 220, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].sv_id.satId ==
            116,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20].sv_id.satId, "
        "expected 116, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[20]
            .sv_id.satId);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
                .stec_coeff[0] == -10742,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[0]"
        ", expected -10742, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .stec_coeff[0]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
                .stec_coeff[1] == 10098,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[1]"
        ", expected 10098, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .stec_coeff[1]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
                .stec_coeff[2] == 7413,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[2]"
        ", expected 7413, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .stec_coeff[2]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
                .stec_coeff[3] == 17645,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_coeff[3]"
        ", expected 17645, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .stec_coeff[3]);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
                .stec_quality_indicator == 115,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].stec_quality_"
        "indicator, expected 115, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .stec_quality_indicator);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
                .sv_id.constellation == 70,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].sv_id."
        "constellation, expected 70, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .sv_id.constellation);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].sv_id.satId ==
            72,
        "incorrect value for "
        "last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21].sv_id.satId, "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.ssr_stec_correction_dep_a.stec_sat_list[21]
            .sv_id.satId);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrStecCorrectionDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_ssr_MsgSsrStecCorrectionDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_ssr_MsgSsrStecCorrectionDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrStecCorrectionDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}