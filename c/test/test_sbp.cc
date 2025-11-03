/*
 * Copyright (C) 2011-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <gtest/gtest.h>
#include <sbp.h>
#include <stdio.h>
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

static void test_callback(u16 sender_id, sbp_msg_type_t msg_type,
                          const sbp_msg_t* msg, void* context) {
  /* Do nothing. */
  (void)sender_id;
  (void)msg_type;
  (void)msg;
  (void)context;
}

static void test_callback2(u16 sender_id, sbp_msg_type_t msg_type,
                           const sbp_msg_t* msg, void* context) {
  /* Do nothing. */
  (void)sender_id;
  (void)msg_type;
  (void)msg;
  (void)context;
}

static sbp_msg_callbacks_node_t* sbp_find_callback(sbp_state_t* s,
                                                   sbp_msg_type_t msg_type) {
  /* If our list is empty, return NULL. */
  if (!s->sbp_msg_callbacks_head) return 0;

  /* Traverse the linked list and return the callback
   * function pointer if we find a node with a matching
   * message id.
   */
  sbp_msg_callbacks_node_t* p = s->sbp_msg_callbacks_head;
  do
    if (p->msg_type == msg_type) return p;

  while ((p = p->next));

  /* Didn't find a matching callback, return NULL. */
  return 0;
}

TEST(Core, test_sbp_process) {
  /* TODO: Tests with different read function behaviour. */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  sbp_msg_callbacks_node_t n;
  sbp_msg_callbacks_node_t n2;

  sbp_callback_register(&s, SbpMsgLog, &logging_callback,
                        &DUMMY_MEMORY_FOR_CALLBACKS, &n);

  sbp_msg_t test_msg;
  memset(&test_msg, 0, sizeof(test_msg));
  test_msg.log.level = 3;
  sbp_msg_log_text_printf(&test_msg.log, false, NULL, "Hello, World!");

  logging_reset();
  dummy_reset();
  sbp_message_send(&s, SbpMsgLog, 0x42, &test_msg, &dummy_write);

  while (dummy_rd < dummy_wr) {
    EXPECT_GE(sbp_process(&s, &dummy_read), SBP_OK)
        << "sbp_process threw an error!";
  }

  EXPECT_EQ(last_msg.n_callbacks_logged, 1)
      << "one callback should have been logged";
  EXPECT_EQ(last_msg.sender_id, 0x42) << "sender_id decoded incorrectly";
  EXPECT_EQ(last_msg.msg_type, SbpMsgLog) << "len decoded incorrectly";
  EXPECT_EQ(sbp_message_cmp(SbpMsgLog, &last_msg.msg, &test_msg), 0)
      << "test data decoded incorrectly";
  EXPECT_EQ(last_msg.context, &DUMMY_MEMORY_FOR_CALLBACKS)
      << "context pointer incorrectly passed";

  sbp_callback_register(&s, SbpMsgUserData, &logging_callback,
                        &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
  EXPECT_NE(sbp_find_callback(&s, SbpMsgUserData), nullptr)
      << "second callback not found";

  sbp_remove_callback(&s, &n2);
  EXPECT_EQ(sbp_find_callback(&s, SbpMsgUserData), nullptr)
      << "callback not removed";

  logging_reset();

  sbp_message_send(&s, SbpMsgLog, 0x4243, &test_msg, &dummy_write);

  EXPECT_EQ(last_io_context, &DUMMY_MEMORY_FOR_IO)
      << "io context pointer incorrectly passed";

  last_io_context = 0;

  while (dummy_rd < dummy_wr) {
    EXPECT_GE(sbp_process(&s, &dummy_read), SBP_OK)
        << "sbp_process threw an error! (2)";
  }

  EXPECT_EQ(last_io_context, &DUMMY_MEMORY_FOR_IO)
      << "io context pointer incorrectly passed";

  EXPECT_EQ(last_msg.n_callbacks_logged, 1)
      << "one callback should have been logged (2)";
  EXPECT_EQ(last_msg.sender_id, 0x4243) << "sender_id decoded incorrectly (2)";
  EXPECT_EQ(last_msg.msg_type, SbpMsgLog) << "len decoded incorrectly (2)";

  logging_reset();
  sbp_clear_callbacks(&s);

  sbp_msg_t test_msg2;
  memset(&test_msg2, 0, sizeof(test_msg2));

  test_msg2.fwd.source = 1;
  test_msg2.fwd.protocol = 2;
  test_msg2.fwd.n_fwd_payload = 0;
  sbp_message_send(&s, SbpMsgFwd, 0x4243, &test_msg2, &dummy_write);

  int ret = 0;
  while (dummy_rd < dummy_wr) {
    ret |= sbp_process(&s, &dummy_read);
  }

  EXPECT_EQ(ret, SBP_OK_CALLBACK_UNDEFINED)
      << "sbp_process should have returned SBP_OK_CALLBACK_UNDEFINED "
         "if no cb was registered for that message type";

  EXPECT_EQ(last_msg.n_callbacks_logged, 0)
      << "no callbacks should have been logged";

  u8 awesome_message[] = {
      0x55, 0x01, 0x04, 0x25, 0x09, 0x08, 0x03, 0x61,
      0x77, 0x65, 0x73, 0x6F, 0x6D, 0x65, 0xEC, 0x3C,
  };
  logging_reset();
  dummy_reset();
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message);
  memcpy(dummy_buff, awesome_message, sizeof(awesome_message));

  sbp_msg_t decoded_awesome_message;
  memset(&decoded_awesome_message, 0, sizeof(decoded_awesome_message));
  decoded_awesome_message.log.level = 3;
  sbp_msg_log_text_printf(&decoded_awesome_message.log, false, NULL, "awesome");

  sbp_msg_callbacks_node_t m;
  sbp_callback_register(&s, SbpMsgLog, &logging_callback, 0, &m);

  while (dummy_rd < dummy_wr) {
    ASSERT_GE(sbp_process(&s, &dummy_read), SBP_OK)
        << "sbp_process threw an error! (3)";
  }

  EXPECT_EQ(last_msg.n_callbacks_logged, 1)
      << "one callback should have been logged (3)";
  EXPECT_EQ(last_msg.sender_id, 2341) << "sender_id decoded incorrectly (3)";
  EXPECT_EQ(last_msg.msg_type, SbpMsgLog) << "len decoded incorrectly (3)";
  EXPECT_EQ(sbp_message_cmp(SbpMsgLog, &last_msg.msg, &decoded_awesome_message),
            0)
      << "test data decoded incorrectly (3)";

  awesome_message[15] = 0xAA;
  logging_reset();
  dummy_reset();
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message);
  memcpy(dummy_buff, awesome_message, sizeof(awesome_message));

  ret = 0;
  while (dummy_rd < dummy_wr) {
    ret |= sbp_process(&s, &dummy_read);
  }

  EXPECT_EQ(ret, SBP_CRC_ERROR)
      << "sbp_process should have returned SBP_CRC_ERROR "
         "for malformed message";

  EXPECT_EQ(last_msg.n_callbacks_logged, 0)
      << "no callbacks should have been logged (2)";

  /* Test sbp_process with a one-byte-at-a-time read process */

  u8 awesome_message2[] = {
      0x55, 0x01, 0x04, 0x25, 0x09, 0x08, 0x03, 0x61,
      0x77, 0x65, 0x73, 0x6F, 0x6D, 0x65, 0xEC, 0x3C,
  };
  logging_reset();
  dummy_reset();
  sbp_clear_callbacks(&s);
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message2);
  memcpy(dummy_buff, awesome_message2, sizeof(awesome_message2));

  sbp_msg_callbacks_node_t p;
  sbp_callback_register(&s, SbpMsgLog, &logging_callback, 0, &p);

  while (dummy_rd < dummy_wr) {
    ASSERT_GE(sbp_process(&s, &dummy_read_single_byte), SBP_OK)
        << "sbp_process threw an error! (3)";
  }

  ASSERT_EQ(last_msg.n_callbacks_logged, 1)
      << "one callback should have been logged (3)";
  EXPECT_EQ(last_msg.sender_id, 2341) << "sender_id decoded incorrectly (3)";
  EXPECT_EQ(last_msg.msg_type, SbpMsgLog) << "len decoded incorrectly (3)";
  EXPECT_EQ(sbp_message_cmp(SbpMsgLog, &decoded_awesome_message, &last_msg.msg),
            0)
      << "test data decoded incorrectly (3)";

  /* Test sbp_process with a one-byte-at-a-time read that starts with garbage */

  u8 crappy_then_awesome_message[] = {
      0x99, 0x88, 0x77, 0x66, 0x55, 0x01, 0x04, 0x25, 0x09, 0x08,
      0x03, 0x61, 0x77, 0x65, 0x73, 0x6F, 0x6D, 0x65, 0xEC, 0x3C,
  };
  logging_reset();
  dummy_reset();
  sbp_clear_callbacks(&s);
  dummy_rd = 0;
  dummy_wr = sizeof(crappy_then_awesome_message);
  memcpy(dummy_buff, crappy_then_awesome_message,
         sizeof(crappy_then_awesome_message));

  sbp_msg_callbacks_node_t q;
  sbp_callback_register(&s, SbpMsgLog, &logging_callback, 0, &q);

  while (dummy_rd < dummy_wr) {
    ASSERT_GE(sbp_process(&s, &dummy_read_single_byte), SBP_OK)
        << "sbp_process threw an error! (3)";
  }

  EXPECT_EQ(last_msg.n_callbacks_logged, 1)
      << "one callback should have been logged (3)";
  EXPECT_EQ(last_msg.sender_id, 2341) << "sender_id decoded incorrectly (3)";
  EXPECT_EQ(last_msg.msg_type, SbpMsgLog) << "len decoded incorrectly (3)";
  EXPECT_EQ(sbp_message_cmp(SbpMsgLog, &last_msg.msg, &decoded_awesome_message),
            0)
      << "test data decoded incorrectly (3)";
}

TEST(Core, test_sbp_all_payload) {
  /* Tests registering for all messages */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  sbp_msg_callbacks_node_t n;

  sbp_all_message_callback_register(&s, &logging_callback,
                                    &DUMMY_MEMORY_FOR_CALLBACKS, &n);

  sbp_msg_t msg_1;
  memset(&msg_1, 0, sizeof(msg_1));
  msg_1.log.level = 3;
  sbp_msg_log_text_printf(&msg_1.log, false, NULL, "Hello, World");

  sbp_msg_t msg_2;
  memset(&msg_2, 0, sizeof(msg_2));
  msg_2.user_data.n_contents = 5;
  msg_2.user_data.contents[0] = 0x99;
  msg_2.user_data.contents[1] = 0x88;
  msg_2.user_data.contents[2] = 0x77;
  msg_2.user_data.contents[3] = 0x66;
  msg_2.user_data.contents[4] = 0x55;

  logging_reset();
  dummy_reset();
  sbp_message_send(&s, SbpMsgLog, 0x42, &msg_1, &dummy_write);
  sbp_message_send(&s, SbpMsgUserData, 0x43, &msg_2, &dummy_write);

  while (dummy_rd < dummy_wr) {
    ASSERT_GE(sbp_process(&s, &dummy_read), SBP_OK)
        << "sbp_process threw an error!";
  }

  EXPECT_EQ(last_msg.n_callbacks_logged, 2)
      << "two frame callback should have been logged, "
      << last_msg.n_callbacks_logged << " were";
  EXPECT_EQ(last_msg.sender_id, 0x43) << "sender_id decoded incorrectly";
  EXPECT_EQ(last_msg.msg_type, SbpMsgUserData) << "len decoded incorrectly";
  EXPECT_EQ(sbp_message_cmp(SbpMsgUserData, &msg_2, &last_msg.msg), 0)
      << "frame len decoded incorrectly";
}

TEST(Core, test_sbp_big_msg) {
  /* Tests registering for max size message SBP_MAX_PAYLOAD_LEN (255) */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  sbp_msg_callbacks_node_t n2;

  sbp_callback_register(&s, SbpMsgUserData, &logging_callback,
                        &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

  sbp_msg_t big_msg;
  memset(&big_msg, 0, sizeof(big_msg));
  big_msg.user_data.n_contents = SBP_MSG_USER_DATA_CONTENTS_MAX;
  for (u8 i = 0; i < SBP_MSG_USER_DATA_CONTENTS_MAX; i++) {
    big_msg.user_data.contents[i] = i;
  }

  logging_reset();
  dummy_reset();
  sbp_message_send(&s, SbpMsgUserData, 0x42, &big_msg, &dummy_write);

  s8 ret = SBP_OK;
  while (dummy_rd < dummy_wr) {
    ret = sbp_process(&s, &dummy_read);
    ASSERT_GE(ret, SBP_OK) << "sbp_process threw an error! error_code: " << ret;
  }

  EXPECT_EQ(last_msg.n_callbacks_logged, 1)
      << "one frame callback should have been logged, "
      << last_msg.n_callbacks_logged << " were";
  EXPECT_EQ(last_msg.sender_id, 0x42) << "sender_id decoded incorrectly";
  EXPECT_EQ(last_msg.msg_type, SbpMsgUserData) << "len decoded incorrectly";
  EXPECT_EQ(sbp_message_cmp(SbpMsgUserData, &last_msg.msg, &big_msg), 0)
      << "frame len decoded incorrectly";
}

TEST(Core, test_callbacks) {
  sbp_state_t s;
  sbp_state_init(&s);

  /* Start with no callbacks registered.  */
  sbp_clear_callbacks(&s);

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgUserData), nullptr)
      << "sbp_find_callback should return NULL if no callbacks registered";

  EXPECT_EQ(sbp_callback_register(&s, SbpMsgLog, &test_callback, 0, 0),
            SBP_NULL_ERROR)
      << "sbp_callback_register should return an error if node is NULL";

  /* Add a first callback. */

  sbp_msg_callbacks_node_t n;

  int NUMBER = 42;

  EXPECT_EQ(sbp_callback_register(&s, SbpMsgLog, 0, 0, &n), SBP_NULL_ERROR)
      << "sbp_callback_register should return an error if cb is NULL";

  EXPECT_EQ(sbp_callback_register(&s, SbpMsgLog, &test_callback, &NUMBER, &n),
            SBP_OK)
      << "sbp_callback_register should return success if "
         "everything is groovy";

  EXPECT_EQ(sbp_callback_register(&s, SbpMsgLog, &test_callback, 0, &n),
            SBP_CALLBACK_ERROR)
      << "sbp_callback_register should return "
         "SBP_CALLBACK_ERROR if a callback "
         "of the same type is already registered";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgUserData), nullptr)
      << "sbp_find_callback should return NULL if callback not registered";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgLog), &n)
      << "sbp_find_callback didn't return the correct callback node pointer";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgLog)->context, &NUMBER)
      << "sbp_find_callback didn't return the correct context pointer";

  /* Add a second callback. */

  sbp_msg_callbacks_node_t m;

  int NUMBER2 = 84;

  EXPECT_EQ(
      sbp_callback_register(&s, SbpMsgUserData, &test_callback2, &NUMBER2, &m),
      SBP_OK)
      << "sbp_callback_register should return success if "
         "everything is groovy (2)";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgLog), &n)
      << "sbp_find_callback didn't return the correct callback function "
         "pointer (2)";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgLog)->context, &NUMBER)
      << "sbp_find_callback didn't return the correct context pointer";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgUserData), &m)
      << "sbp_find_callback didn't return the correct callback function "
         "pointer (3)";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgUserData)->context, &NUMBER2)
      << "sbp_find_callback didn't return the correct context pointer";

  EXPECT_EQ(sbp_callback_register(&s, SbpMsgUserData, &test_callback, 0, &n),
            SBP_CALLBACK_ERROR)
      << "sbp_callback_register should return "
         "SBP_CALLBACK_ERROR if a callback "
         "of the same type is already registered (2)";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgFwd), nullptr)
      << "sbp_find_callback should return NULL if callback not registered (2)";

  /* Clear all the registered callbacks and check they can no longer be found.
   */
  sbp_clear_callbacks(&s);

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgUserData), nullptr)
      << "sbp_find_callback should return NULL if no callbacks registered (2)";

  EXPECT_EQ(sbp_find_callback(&s, SbpMsgLog), nullptr)
      << "sbp_find_callback should return NULL if no callbacks registered (3)";
}

}  // namespace
