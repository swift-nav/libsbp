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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGal.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <observation.h>
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

START_TEST(test_auto_check_sbp_observation_MsgEphemerisGal) {
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

    sbp_register_callback(&sbp_state, 0x8d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x8d, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  141, 0,   128, 240, 153, 27,  14,  32,  217, 6,   0,   106, 8,
        20,  174, 71,  64,  64,  56,  0,   0,   1,   0,   0,   0,   16,  49,
        0,   0,   16,  49,  0,   0,   34,  65,  0,   184, 132, 67,  0,   0,
        16,  53,  0,   0,   134, 54,  0,   0,   8,   179, 0,   0,   8,   179,
        217, 204, 130, 105, 128, 182, 43,  62,  248, 106, 31,  220, 8,   136,
        253, 191, 0,   0,   0,   0,   151, 92,  38,  63,  0,   0,   0,   55,
        154, 64,  181, 64,  56,  38,  1,   141, 255, 182, 242, 63,  222, 147,
        136, 39,  79,  186, 56,  190, 80,  114, 204, 251, 193, 92,  191, 63,
        237, 55,  19,  41,  177, 73,  239, 63,  49,  65,  189, 240, 8,   216,
        245, 189, 255, 255, 255, 255, 67,  235, 241, 190, 255, 255, 255, 255,
        255, 255, 161, 189, 0,   0,   0,   0,   32,  217, 6,   0,   106, 8,
        108, 0,   108, 0,   0,   71,  208,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_gal_t *test_msg = (msg_ephemeris_gal_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = -1.7088896129280325e-05;
    test_msg->af1 = -8.185452315956353e-12;
    test_msg->af2 = 0.0;
    test_msg->bgd_e1e5a = 2.0954757928848267e-09;
    test_msg->bgd_e1e5b = 2.0954757928848267e-09;
    test_msg->c_ic = -3.166496753692627e-08;
    test_msg->c_is = -3.166496753692627e-08;
    test_msg->c_rc = 265.4375;
    test_msg->c_rs = 10.125;
    test_msg->c_uc = 5.364418029785156e-07;
    test_msg->c_us = 3.993511199951172e-06;
    test_msg->common.fit_interval = 14400;
    test_msg->common.health_bits = 0;
    test_msg->common.sid.code = 14;
    test_msg->common.sid.sat = 27;
    test_msg->common.toe.tow = 448800;
    test_msg->common.toe.wn = 2154;
    test_msg->common.ura = 3.119999885559082;
    test_msg->common.valid = 1;
    test_msg->dn = 3.2262058129932258e-09;
    test_msg->ecc = 0.00017060607206076384;
    test_msg->inc = 0.9777456094977858;
    test_msg->inc_dot = -3.1787038343451465e-10;
    test_msg->iodc = 108;
    test_msg->iode = 108;
    test_msg->m0 = -1.8457115744155868;
    test_msg->omega0 = 1.16967730598334;
    test_msg->omegadot = -5.757382675240872e-09;
    test_msg->source = 0;
    test_msg->sqrta = 5440.602401733398;
    test_msg->toc.tow = 448800;
    test_msg->toc.wn = 2154;
    test_msg->w = 0.12250912091662625;
    sbp_send_message(&sbp_state, 0x8d, 61568, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 61568,
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
    ck_assert_msg(last_frame.sender_id == 61568,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x8d,
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
    msg_ephemeris_gal_t *check_msg =
        (msg_ephemeris_gal_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0 * 100 - -1.70888961293e-05 * 100) < 0.05,
                  "incorrect value for af0, expected -1.70888961293e-05, is %f",
                  check_msg->af0);
    ck_assert_msg((check_msg->af1 * 100 - -8.18545231596e-12 * 100) < 0.05,
                  "incorrect value for af1, expected -8.18545231596e-12, is %f",
                  check_msg->af1);
    ck_assert_msg((check_msg->af2 * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for af2, expected 0.0, is %f",
                  check_msg->af2);
    ck_assert_msg(
        (check_msg->bgd_e1e5a * 100 - 2.09547579288e-09 * 100) < 0.05,
        "incorrect value for bgd_e1e5a, expected 2.09547579288e-09, is %f",
        check_msg->bgd_e1e5a);
    ck_assert_msg(
        (check_msg->bgd_e1e5b * 100 - 2.09547579288e-09 * 100) < 0.05,
        "incorrect value for bgd_e1e5b, expected 2.09547579288e-09, is %f",
        check_msg->bgd_e1e5b);
    ck_assert_msg(
        (check_msg->c_ic * 100 - -3.16649675369e-08 * 100) < 0.05,
        "incorrect value for c_ic, expected -3.16649675369e-08, is %f",
        check_msg->c_ic);
    ck_assert_msg(
        (check_msg->c_is * 100 - -3.16649675369e-08 * 100) < 0.05,
        "incorrect value for c_is, expected -3.16649675369e-08, is %f",
        check_msg->c_is);
    ck_assert_msg((check_msg->c_rc * 100 - 265.4375 * 100) < 0.05,
                  "incorrect value for c_rc, expected 265.4375, is %f",
                  check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs * 100 - 10.125 * 100) < 0.05,
                  "incorrect value for c_rs, expected 10.125, is %f",
                  check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc * 100 - 5.36441802979e-07 * 100) < 0.05,
                  "incorrect value for c_uc, expected 5.36441802979e-07, is %f",
                  check_msg->c_uc);
    ck_assert_msg((check_msg->c_us * 100 - 3.99351119995e-06 * 100) < 0.05,
                  "incorrect value for c_us, expected 3.99351119995e-06, is %f",
                  check_msg->c_us);
    ck_assert_msg(
        check_msg->common.fit_interval == 14400,
        "incorrect value for common.fit_interval, expected 14400, is %d",
        check_msg->common.fit_interval);
    ck_assert_msg(check_msg->common.health_bits == 0,
                  "incorrect value for common.health_bits, expected 0, is %d",
                  check_msg->common.health_bits);
    ck_assert_msg(check_msg->common.sid.code == 14,
                  "incorrect value for common.sid.code, expected 14, is %d",
                  check_msg->common.sid.code);
    ck_assert_msg(check_msg->common.sid.sat == 27,
                  "incorrect value for common.sid.sat, expected 27, is %d",
                  check_msg->common.sid.sat);
    ck_assert_msg(check_msg->common.toe.tow == 448800,
                  "incorrect value for common.toe.tow, expected 448800, is %d",
                  check_msg->common.toe.tow);
    ck_assert_msg(check_msg->common.toe.wn == 2154,
                  "incorrect value for common.toe.wn, expected 2154, is %d",
                  check_msg->common.toe.wn);
    ck_assert_msg(
        (check_msg->common.ura * 100 - 3.11999988556 * 100) < 0.05,
        "incorrect value for common.ura, expected 3.11999988556, is %f",
        check_msg->common.ura);
    ck_assert_msg(check_msg->common.valid == 1,
                  "incorrect value for common.valid, expected 1, is %d",
                  check_msg->common.valid);
    ck_assert_msg((check_msg->dn * 100 - 3.22620581299e-09 * 100) < 0.05,
                  "incorrect value for dn, expected 3.22620581299e-09, is %f",
                  check_msg->dn);
    ck_assert_msg((check_msg->ecc * 100 - 0.000170606072061 * 100) < 0.05,
                  "incorrect value for ecc, expected 0.000170606072061, is %f",
                  check_msg->ecc);
    ck_assert_msg((check_msg->inc * 100 - 0.977745609498 * 100) < 0.05,
                  "incorrect value for inc, expected 0.977745609498, is %f",
                  check_msg->inc);
    ck_assert_msg(
        (check_msg->inc_dot * 100 - -3.17870383435e-10 * 100) < 0.05,
        "incorrect value for inc_dot, expected -3.17870383435e-10, is %f",
        check_msg->inc_dot);
    ck_assert_msg(check_msg->iodc == 108,
                  "incorrect value for iodc, expected 108, is %d",
                  check_msg->iodc);
    ck_assert_msg(check_msg->iode == 108,
                  "incorrect value for iode, expected 108, is %d",
                  check_msg->iode);
    ck_assert_msg((check_msg->m0 * 100 - -1.84571157442 * 100) < 0.05,
                  "incorrect value for m0, expected -1.84571157442, is %f",
                  check_msg->m0);
    ck_assert_msg((check_msg->omega0 * 100 - 1.16967730598 * 100) < 0.05,
                  "incorrect value for omega0, expected 1.16967730598, is %f",
                  check_msg->omega0);
    ck_assert_msg(
        (check_msg->omegadot * 100 - -5.75738267524e-09 * 100) < 0.05,
        "incorrect value for omegadot, expected -5.75738267524e-09, is %f",
        check_msg->omegadot);
    ck_assert_msg(check_msg->source == 0,
                  "incorrect value for source, expected 0, is %d",
                  check_msg->source);
    ck_assert_msg((check_msg->sqrta * 100 - 5440.60240173 * 100) < 0.05,
                  "incorrect value for sqrta, expected 5440.60240173, is %f",
                  check_msg->sqrta);
    ck_assert_msg(check_msg->toc.tow == 448800,
                  "incorrect value for toc.tow, expected 448800, is %d",
                  check_msg->toc.tow);
    ck_assert_msg(check_msg->toc.wn == 2154,
                  "incorrect value for toc.wn, expected 2154, is %d",
                  check_msg->toc.wn);
    ck_assert_msg((check_msg->w * 100 - 0.122509120917 * 100) < 0.05,
                  "incorrect value for w, expected 0.122509120917, is %f",
                  check_msg->w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisGal_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgEphemerisGal");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisGal");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisGal);
  suite_add_tcase(s, tc_acq);
  return s;
}