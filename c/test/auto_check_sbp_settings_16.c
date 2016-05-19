/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <settings.h>

static u32 n_callbacks_logged;
static u16 last_sender_id;
static u8 last_len;
static u8 last_msg[256];
static void* last_context;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset()
{
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static u32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static u32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

static void logging_reset()
{
  n_callbacks_logged = 0;
  last_context = 0;
  memset(last_msg, 0, sizeof(last_msg));
}

static void logging_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  n_callbacks_logged++;
  last_sender_id = sender_id;
  last_len = len;
  last_context = context;
  memcpy(last_msg, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

START_TEST( test_auto_check_sbp_settings_16 )
{
  static sbp_msg_callbacks_node_t n;
  //static sbp_msg_callbacks_node_t n2;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xa7, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,167,0,246,215,78,0,0,116,101,108,101,109,101,116,114,121,95,114,97,100,105,111,0,99,111,110,102,105,103,117,114,97,116,105,111,110,95,115,116,114,105,110,103,0,65,84,38,70,44,65,84,83,49,61,49,49,53,44,65,84,83,50,61,49,50,56,44,65,84,83,53,61,48,44,65,84,38,87,44,65,84,90,0,248,233, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0xa7, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_settings_read_by_index_resp_t* msg = ( msg_settings_read_by_index_resp_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->index == 0, "incorrect value for index, expected 0, is %d", msg->index);
    fail_unless(strstr(msg->setting, ((char []){(char)116,(char)101,(char)108,(char)101,(char)109,(char)101,(char)116,(char)114,(char)121,(char)95,(char)114,(char)97,(char)100,(char)105,(char)111,(char)0,(char)99,(char)111,(char)110,(char)102,(char)105,(char)103,(char)117,(char)114,(char)97,(char)116,(char)105,(char)111,(char)110,(char)95,(char)115,(char)116,(char)114,(char)105,(char)110,(char)103,(char)0,(char)65,(char)84,(char)38,(char)70,(char)44,(char)65,(char)84,(char)83,(char)49,(char)61,(char)49,(char)49,(char)53,(char)44,(char)65,(char)84,(char)83,(char)50,(char)61,(char)49,(char)50,(char)56,(char)44,(char)65,(char)84,(char)83,(char)53,(char)61,(char)48,(char)44,(char)65,(char)84,(char)38,(char)87,(char)44,(char)65,(char)84,(char)90,(char)0,0})) != NULL, "incorrect value for msg->setting, expected string '%s', is '%s'", ((char []){(char)116,(char)101,(char)108,(char)101,(char)109,(char)101,(char)116,(char)114,(char)121,(char)95,(char)114,(char)97,(char)100,(char)105,(char)111,(char)0,(char)99,(char)111,(char)110,(char)102,(char)105,(char)103,(char)117,(char)114,(char)97,(char)116,(char)105,(char)111,(char)110,(char)95,(char)115,(char)116,(char)114,(char)105,(char)110,(char)103,(char)0,(char)65,(char)84,(char)38,(char)70,(char)44,(char)65,(char)84,(char)83,(char)49,(char)61,(char)49,(char)49,(char)53,(char)44,(char)65,(char)84,(char)83,(char)50,(char)61,(char)49,(char)50,(char)56,(char)44,(char)65,(char)84,(char)83,(char)53,(char)61,(char)48,(char)44,(char)65,(char)84,(char)38,(char)87,(char)44,(char)65,(char)84,(char)90,(char)0,0}), msg->setting);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xa7, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,167,0,246,215,35,1,0,117,97,114,116,95,102,116,100,105,0,109,111,100,101,0,83,66,80,0,101,110,117,109,58,83,66,80,44,78,77,69,65,0,167,243, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0xa7, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_settings_read_by_index_resp_t* msg = ( msg_settings_read_by_index_resp_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->index == 1, "incorrect value for index, expected 1, is %d", msg->index);
    fail_unless(strstr(msg->setting, ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0,0})) != NULL, "incorrect value for msg->setting, expected string '%s', is '%s'", ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0,0}), msg->setting);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xa7, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,167,0,246,215,35,2,0,117,97,114,116,95,102,116,100,105,0,115,98,112,95,109,101,115,115,97,103,101,95,109,97,115,107,0,54,53,53,51,53,0,4,56, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0xa7, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_settings_read_by_index_resp_t* msg = ( msg_settings_read_by_index_resp_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->index == 2, "incorrect value for index, expected 2, is %d", msg->index);
    fail_unless(strstr(msg->setting, ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)115,(char)98,(char)112,(char)95,(char)109,(char)101,(char)115,(char)115,(char)97,(char)103,(char)101,(char)95,(char)109,(char)97,(char)115,(char)107,(char)0,(char)54,(char)53,(char)53,(char)51,(char)53,(char)0,0})) != NULL, "incorrect value for msg->setting, expected string '%s', is '%s'", ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)115,(char)98,(char)112,(char)95,(char)109,(char)101,(char)115,(char)115,(char)97,(char)103,(char)101,(char)95,(char)109,(char)97,(char)115,(char)107,(char)0,(char)54,(char)53,(char)53,(char)51,(char)53,(char)0,0}), msg->setting);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xa7, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,167,0,246,215,29,3,0,117,97,114,116,95,102,116,100,105,0,98,97,117,100,114,97,116,101,0,49,48,48,48,48,48,48,0,242,146, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0xa7, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_settings_read_by_index_resp_t* msg = ( msg_settings_read_by_index_resp_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->index == 3, "incorrect value for index, expected 3, is %d", msg->index);
    fail_unless(strstr(msg->setting, ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)98,(char)97,(char)117,(char)100,(char)114,(char)97,(char)116,(char)101,(char)0,(char)49,(char)48,(char)48,(char)48,(char)48,(char)48,(char)48,(char)0,0})) != NULL, "incorrect value for msg->setting, expected string '%s', is '%s'", ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)98,(char)97,(char)117,(char)100,(char)114,(char)97,(char)116,(char)101,(char)0,(char)49,(char)48,(char)48,(char)48,(char)48,(char)48,(char)48,(char)0,0}), msg->setting);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xa7, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,167,0,246,215,36,4,0,117,97,114,116,95,117,97,114,116,97,0,109,111,100,101,0,83,66,80,0,101,110,117,109,58,83,66,80,44,78,77,69,65,0,22,4, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0xa7, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_settings_read_by_index_resp_t* msg = ( msg_settings_read_by_index_resp_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->index == 4, "incorrect value for index, expected 4, is %d", msg->index);
    fail_unless(strstr(msg->setting, ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)117,(char)97,(char)114,(char)116,(char)97,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0,0})) != NULL, "incorrect value for msg->setting, expected string '%s', is '%s'", ((char []){(char)117,(char)97,(char)114,(char)116,(char)95,(char)117,(char)97,(char)114,(char)116,(char)97,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0,0}), msg->setting);
  }
}
END_TEST

Suite* auto_check_sbp_settings_16_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_settings_16");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_settings_16");
  tcase_add_test(tc_acq, test_auto_check_sbp_settings_16);
  suite_add_tcase(s, tc_acq);
  return s;
}