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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml by
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

START_TEST(test_auto_check_sbp_observation_MsgEphemerisBds) {
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

    sbp_register_callback(&sbp_state, 0x89, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x89, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  137, 0,   128, 240, 147, 8,   12,  174, 179, 6,   0,   106,
        8,   0,   0,   0,   64,  48,  42,  0,   0,   1,   0,   125, 99,
        52,  50,  207, 46,  151, 176, 0,   112, 96,  67,  0,   164, 106,
        67,  0,   60,  255, 54,  0,   224, 47,  53,  0,   0,   143, 179,
        0,   192, 190, 52,  146, 101, 162, 196, 109, 104, 19,  62,  253,
        87,  86,  202, 62,  28,  251, 63,  0,   0,   0,   96,  151, 60,
        117, 63,  0,   0,   128, 154, 127, 93,  185, 64,  151, 193, 64,
        0,   10,  166, 4,   192, 160, 75,  174, 98,  8,   201, 35,  190,
        205, 29,  12,  71,  189, 150, 5,   192, 176, 72,  249, 189, 193,
        172, 240, 63,  72,  249, 188, 180, 160, 203, 9,   62,  0,   0,
        0,   0,   92,  51,  77,  191, 0,   128, 174, 43,  0,   0,   88,
        161, 174, 179, 6,   0,   106, 8,   6,   5,   0,   157, 249,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_bds_t *test_msg = (msg_ephemeris_bds_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = -0.0008911322802305222;
    test_msg->af1 = 1.2398970739013748e-12;
    test_msg->af2 = -7.318364664277155e-19;
    test_msg->c_ic = -6.658956408500671e-08;
    test_msg->c_is = 3.5529956221580505e-07;
    test_msg->c_rc = 234.640625;
    test_msg->c_rs = 224.4375;
    test_msg->c_uc = 7.606577128171921e-06;
    test_msg->c_us = 6.551854312419891e-07;
    test_msg->common.fit_interval = 10800;
    test_msg->common.health_bits = 0;
    test_msg->common.sid.code = 12;
    test_msg->common.sid.sat = 8;
    test_msg->common.toe.tow = 439214;
    test_msg->common.toe.wn = 2154;
    test_msg->common.ura = 2.0;
    test_msg->common.valid = 1;
    test_msg->dn = 1.1296899132622133e-09;
    test_msg->ecc = 0.005184737499803305;
    test_msg->inc = 1.0421769543504915;
    test_msg->inc_dot = 7.507455572801683e-10;
    test_msg->iodc = 5;
    test_msg->iode = 6;
    test_msg->m0 = 1.6943958190727237;
    test_msg->omega0 = -2.581073762870982;
    test_msg->omegadot = -2.303310227830545e-09;
    test_msg->sqrta = 6493.49845123291;
    test_msg->tgd1 = 1.0499999980595476e-08;
    test_msg->tgd2 = -1.0999999799921056e-09;
    test_msg->toc.tow = 439214;
    test_msg->toc.wn = 2154;
    test_msg->w = -2.698603205735458;
    sbp_send_message(&sbp_state, 0x89, 61568, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x89,
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
    msg_ephemeris_bds_t *check_msg =
        (msg_ephemeris_bds_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0 * 100 - -0.000891132280231 * 100) < 0.05,
                  "incorrect value for af0, expected -0.000891132280231, is %f",
                  check_msg->af0);
    ck_assert_msg((check_msg->af1 * 100 - 1.2398970739e-12 * 100) < 0.05,
                  "incorrect value for af1, expected 1.2398970739e-12, is %f",
                  check_msg->af1);
    ck_assert_msg((check_msg->af2 * 100 - -7.31836466428e-19 * 100) < 0.05,
                  "incorrect value for af2, expected -7.31836466428e-19, is %f",
                  check_msg->af2);
    ck_assert_msg((check_msg->c_ic * 100 - -6.6589564085e-08 * 100) < 0.05,
                  "incorrect value for c_ic, expected -6.6589564085e-08, is %f",
                  check_msg->c_ic);
    ck_assert_msg((check_msg->c_is * 100 - 3.55299562216e-07 * 100) < 0.05,
                  "incorrect value for c_is, expected 3.55299562216e-07, is %f",
                  check_msg->c_is);
    ck_assert_msg((check_msg->c_rc * 100 - 234.640625 * 100) < 0.05,
                  "incorrect value for c_rc, expected 234.640625, is %f",
                  check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs * 100 - 224.4375 * 100) < 0.05,
                  "incorrect value for c_rs, expected 224.4375, is %f",
                  check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc * 100 - 7.60657712817e-06 * 100) < 0.05,
                  "incorrect value for c_uc, expected 7.60657712817e-06, is %f",
                  check_msg->c_uc);
    ck_assert_msg((check_msg->c_us * 100 - 6.55185431242e-07 * 100) < 0.05,
                  "incorrect value for c_us, expected 6.55185431242e-07, is %f",
                  check_msg->c_us);
    ck_assert_msg(
        check_msg->common.fit_interval == 10800,
        "incorrect value for common.fit_interval, expected 10800, is %d",
        check_msg->common.fit_interval);
    ck_assert_msg(check_msg->common.health_bits == 0,
                  "incorrect value for common.health_bits, expected 0, is %d",
                  check_msg->common.health_bits);
    ck_assert_msg(check_msg->common.sid.code == 12,
                  "incorrect value for common.sid.code, expected 12, is %d",
                  check_msg->common.sid.code);
    ck_assert_msg(check_msg->common.sid.sat == 8,
                  "incorrect value for common.sid.sat, expected 8, is %d",
                  check_msg->common.sid.sat);
    ck_assert_msg(check_msg->common.toe.tow == 439214,
                  "incorrect value for common.toe.tow, expected 439214, is %d",
                  check_msg->common.toe.tow);
    ck_assert_msg(check_msg->common.toe.wn == 2154,
                  "incorrect value for common.toe.wn, expected 2154, is %d",
                  check_msg->common.toe.wn);
    ck_assert_msg((check_msg->common.ura * 100 - 2.0 * 100) < 0.05,
                  "incorrect value for common.ura, expected 2.0, is %f",
                  check_msg->common.ura);
    ck_assert_msg(check_msg->common.valid == 1,
                  "incorrect value for common.valid, expected 1, is %d",
                  check_msg->common.valid);
    ck_assert_msg((check_msg->dn * 100 - 1.12968991326e-09 * 100) < 0.05,
                  "incorrect value for dn, expected 1.12968991326e-09, is %f",
                  check_msg->dn);
    ck_assert_msg((check_msg->ecc * 100 - 0.0051847374998 * 100) < 0.05,
                  "incorrect value for ecc, expected 0.0051847374998, is %f",
                  check_msg->ecc);
    ck_assert_msg((check_msg->inc * 100 - 1.04217695435 * 100) < 0.05,
                  "incorrect value for inc, expected 1.04217695435, is %f",
                  check_msg->inc);
    ck_assert_msg(
        (check_msg->inc_dot * 100 - 7.5074555728e-10 * 100) < 0.05,
        "incorrect value for inc_dot, expected 7.5074555728e-10, is %f",
        check_msg->inc_dot);
    ck_assert_msg(check_msg->iodc == 5,
                  "incorrect value for iodc, expected 5, is %d",
                  check_msg->iodc);
    ck_assert_msg(check_msg->iode == 6,
                  "incorrect value for iode, expected 6, is %d",
                  check_msg->iode);
    ck_assert_msg((check_msg->m0 * 100 - 1.69439581907 * 100) < 0.05,
                  "incorrect value for m0, expected 1.69439581907, is %f",
                  check_msg->m0);
    ck_assert_msg((check_msg->omega0 * 100 - -2.58107376287 * 100) < 0.05,
                  "incorrect value for omega0, expected -2.58107376287, is %f",
                  check_msg->omega0);
    ck_assert_msg(
        (check_msg->omegadot * 100 - -2.30331022783e-09 * 100) < 0.05,
        "incorrect value for omegadot, expected -2.30331022783e-09, is %f",
        check_msg->omegadot);
    ck_assert_msg((check_msg->sqrta * 100 - 6493.49845123 * 100) < 0.05,
                  "incorrect value for sqrta, expected 6493.49845123, is %f",
                  check_msg->sqrta);
    ck_assert_msg((check_msg->tgd1 * 100 - 1.04999999806e-08 * 100) < 0.05,
                  "incorrect value for tgd1, expected 1.04999999806e-08, is %f",
                  check_msg->tgd1);
    ck_assert_msg(
        (check_msg->tgd2 * 100 - -1.09999997999e-09 * 100) < 0.05,
        "incorrect value for tgd2, expected -1.09999997999e-09, is %f",
        check_msg->tgd2);
    ck_assert_msg(check_msg->toc.tow == 439214,
                  "incorrect value for toc.tow, expected 439214, is %d",
                  check_msg->toc.tow);
    ck_assert_msg(check_msg->toc.wn == 2154,
                  "incorrect value for toc.wn, expected 2154, is %d",
                  check_msg->toc.wn);
    ck_assert_msg((check_msg->w * 100 - -2.69860320574 * 100) < 0.05,
                  "incorrect value for w, expected -2.69860320574, is %f",
                  check_msg->w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisBds_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgEphemerisBds");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisBds");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisBds);
  suite_add_tcase(s, tc_acq);
  return s;
}