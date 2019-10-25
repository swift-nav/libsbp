/*
 * Copyright (C) 2011-2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <stdio.h>
#include <check.h>
#include <sbp.h>


int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
int DUMMY_MEMORY_FOR_IO = 0xdead0000;

u32 dummy_wr = 0;
u32 dummy_rd = 0;
u8 dummy_buff[1024];
void* last_io_context;

void dummy_reset(void)
{
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

s32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

s32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

s32 dummy_read_single_byte(u8 *buff, u32 n, void* context)
{
  (void)n;
  last_io_context = context;
  memcpy(buff, dummy_buff + dummy_rd, 1);
  dummy_rd += 1;
  return 1;
}

s32 dummy_write_single_byte(u8 *buff, u32 n, void* context)
{
  (void)n;
  last_io_context = context;
  memcpy(dummy_buff + dummy_wr, buff, 1);
  dummy_wr += 1;
  return 1;
}

void printy_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  (void)context;
  printf("MSG id: 0x%04X, len: %d\n", sender_id, len);
  if (len > 0) {
    for (u8 i=0; i<len; i++)
      printf("0x%02X ", msg[i]);
  }
  printf("\n");
}

u32 n_callbacks_logged;
u16 last_sender_id;
u8 last_len;
u8 last_msg[256];
void* last_context;


u32 n_frame_callbacks_logged;
u16 last_frame_sender_id;
u16 last_frame_msg_type;
u8 last_frame_payload_len;
u16 last_frame_len;
u8 last_frame[256 + 8];
void* last_frame_context;

void logging_reset(void)
{
  n_callbacks_logged = 0;
  n_frame_callbacks_logged = 0;
  last_context = 0;
  last_sender_id = 0;
  last_len = 0;
  last_frame_context = 0;
  last_frame_sender_id = 0;
  last_frame_len = 0;
  last_frame_sender_id = 0;
  last_frame_msg_type = 0;
  memset(last_msg, 0, sizeof(last_msg));
  memset(last_frame, 0, sizeof(last_frame));
}

void logging_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  n_callbacks_logged++;
  last_sender_id = sender_id;
  last_len = len;
  last_context = context;
  memcpy(last_msg, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

void frame_logging_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                            u8 payload[], u16 frame_len, u8 frame[],
                            void *context) {
  n_frame_callbacks_logged++;
  last_frame_sender_id = sender_id;
  last_frame_msg_type = msg_type;
  last_frame_payload_len = payload_len;
  last_frame_context = context;
  last_frame_len = frame_len;
  memcpy(last_frame, frame, frame_len);

  /*printy_callback(sender_id, len, msg);*/
}

void test_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  /* Do nothing. */
  (void)sender_id;
  (void)len;
  (void)msg;
  (void)context;
}
void test_callback2(u16 sender_id, u8 len, u8 msg[], void* context)
{
  /* Do nothing. */
  (void)sender_id;
  (void)len;
  (void)msg;
  (void)context;
}

void test_frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                         u8 payload[], u16 frame_len, u8 frame[],
                         void *context)
{
  /* Do nothing. */
  (void)sender_id;
  (void)msg_type;
  (void)payload_len;
  (void)payload;
  (void)frame_len;
  (void)frame;
  (void)context;
}

void test_frame_callback2(u16 sender_id, u16 msg_type, u8 payload_len,
                          u8 payload[], u16 frame_len, u8 frame[],
                          void *context)
{
  /* Do nothing. */
  (void)sender_id;
  (void)msg_type;
  (void)payload_len;
  (void)payload;
  (void)frame_len;
  (void)frame;
  (void)context;
}

sbp_msg_callbacks_node_t* sbp_find_callback(sbp_state_t *s, u16 msg_type)
{
  /* If our list is empty, return NULL. */
  if (!s->sbp_msg_callbacks_head)
    return 0;

  /* Traverse the linked list and return the callback
   * function pointer if we find a node with a matching
   * message id.
   */
  sbp_msg_callbacks_node_t *p = s->sbp_msg_callbacks_head;
  do
    if (p->msg_type == msg_type)
      return p;

  while ((p = p->next));

  /* Didn't find a matching callback, return NULL. */
  return 0;
}

START_TEST(test_sbp_process)
{
  /* TODO: Tests with different read function behaviour. */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

  sbp_register_callback(&s, 0x2269, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

  u8 test_data[] = { 0x01, 0x02, 0x03, 0x04 };

  dummy_reset();
  sbp_send_message(&s, 0x2269, 0x42, sizeof(test_data), test_data, &dummy_write);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error!");
  }

  fail_unless(n_callbacks_logged == 1,
      "one callback should have been logged");
  fail_unless(last_sender_id == 0x42,
      "sender_id decoded incorrectly");
  fail_unless(last_len == sizeof(test_data),
      "len decoded incorrectly");
  fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
        == 0,
      "test data decoded incorrectly");
  fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
      "context pointer incorrectly passed");

  sbp_register_callback(&s, 0x2270, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
  fail_unless(sbp_find_callback(&s, 0x2270) != 0,
    "second callback not found");

  sbp_remove_callback(&s, &n2);
  fail_unless(sbp_find_callback(&s, 0x2270) == 0,
    "callback not removed");

  logging_reset();
  sbp_send_message(&s, 0x2269, 0x4243, 0, 0, &dummy_write);

  fail_unless(last_io_context == &DUMMY_MEMORY_FOR_IO,
      "io context pointer incorrectly passed");

  last_io_context = 0;

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error! (2)");
  }

  fail_unless(last_io_context == &DUMMY_MEMORY_FOR_IO,
      "io context pointer incorrectly passed");


  fail_unless(n_callbacks_logged == 1,
      "one callback should have been logged (2)");
  fail_unless(last_sender_id == 0x4243,
      "sender_id decoded incorrectly (2)");
  fail_unless(last_len == 0,
      "len decoded incorrectly (2)");

  logging_reset();
  sbp_send_message(&s, 0x22, 0x4243, 0, 0, &dummy_write);

  s8 ret = 0;
  while (dummy_rd < dummy_wr) {
    ret |= sbp_process(&s, &dummy_read);
  }

  fail_unless(ret == SBP_OK_CALLBACK_UNDEFINED,
      "sbp_process should have returned SBP_OK_CALLBACK_UNDEFINED "
      "if no cb was registered for that message type");

  fail_unless(n_callbacks_logged == 0,
      "no callbacks should have been logged");

  u8 awesome_message[] = {0x55, 0x33, 0x22, 0x77, 0x66,
                          0x02, 0x22, 0x33, 0x8A, 0x33};
  logging_reset();
  dummy_reset();
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message);
  memcpy(dummy_buff, awesome_message, sizeof(awesome_message));

  static sbp_msg_callbacks_node_t m;
  sbp_register_callback(&s, 0x2233, &logging_callback, 0, &m);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error! (3)");
  }

  fail_unless(n_callbacks_logged == 1,
      "one callback should have been logged (3)");
  fail_unless(last_sender_id == 0x6677,
      "sender_id decoded incorrectly (3)");
  fail_unless(last_len == 2,
      "len decoded incorrectly (3)");
  fail_unless(memcmp(last_msg, &awesome_message[6], 2)
        == 0,
      "test data decoded incorrectly (3)");

  awesome_message[4] = 0xAA;
  logging_reset();
  dummy_reset();
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message);
  memcpy(dummy_buff, awesome_message, sizeof(awesome_message));

  ret = 0;
  while (dummy_rd < dummy_wr) {
    ret |= sbp_process(&s, &dummy_read);
  }

  fail_unless(ret == SBP_CRC_ERROR,
      "sbp_process should have returned SBP_CRC_ERROR "
      "for malformed message");

  fail_unless(n_callbacks_logged == 0,
      "no callbacks should have been logged (2)");

  /* Test sbp_process with a one-byte-at-a-time read process */

  u8 awesome_message2[] = {0x55, 0x33, 0x22, 0x77, 0x66,
                          0x02, 0x22, 0x33, 0x8A, 0x33};
  logging_reset();
  dummy_reset();
  sbp_clear_callbacks(&s);
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message2);
  memcpy(dummy_buff, awesome_message2, sizeof(awesome_message2));

  static sbp_msg_callbacks_node_t p;
  sbp_register_callback(&s, 0x2233, &logging_callback, 0, &p);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read_single_byte) >= SBP_OK,
        "sbp_process threw an error! (3)");
  }

  fail_unless(n_callbacks_logged == 1,
      "one callback should have been logged (3)");
  fail_unless(last_sender_id == 0x6677,
      "sender_id decoded incorrectly (3)");
  fail_unless(last_len == 2,
      "len decoded incorrectly (3)");
  fail_unless(memcmp(last_msg, &awesome_message2[6], 2)
        == 0,
      "test data decoded incorrectly (3)");


  /* Test sbp_process with a one-byte-at-a-time read that starts with garbage */

  u8 crappy_then_awesome_message[] = {0x99, 0x88, 0x77, 0x66, 0x55, 0x33, 0x22, 0x77, 0x66,
                          0x02, 0x22, 0x33, 0x8A, 0x33};
  logging_reset();
  dummy_reset();
  sbp_clear_callbacks(&s);
  dummy_rd = 0;
  dummy_wr = sizeof(crappy_then_awesome_message);
  memcpy(dummy_buff, crappy_then_awesome_message, sizeof(crappy_then_awesome_message));

  static sbp_msg_callbacks_node_t q;
  sbp_register_callback(&s, 0x2233, &logging_callback, 0, &q);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read_single_byte) >= SBP_OK,
        "sbp_process threw an error! (3)");
  }

  fail_unless(n_callbacks_logged == 1,
      "one callback should have been logged (3)");
  fail_unless(last_sender_id == 0x6677,
      "sender_id decoded incorrectly (3)");
  fail_unless(last_len == 2,
      "len decoded incorrectly (3)");
  fail_unless(memcmp(last_msg, &crappy_then_awesome_message[10], 2)
        == 0,
      "test data decoded incorrectly (3)");

}
END_TEST

START_TEST(test_sbp_frame)
{
  /* TODO: Tests with different read function behaviour. */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

  sbp_register_frame_callback(&s, 0x2269, &frame_logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

  u8 test_data[] = { 0x01, 0x02, 0x03, 0x04 };
  u8 test_frame[] = { 0x55, 0x69, 0x22, 0x42, 0x00, 0x04, 0x01, 0x02, 0x03, 0x04, 0x3D, 0xF7 };

  dummy_reset();
  sbp_send_message(&s, 0x2269, 0x42, sizeof(test_data), test_data, &dummy_write);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error!");
  }

  fail_unless(n_frame_callbacks_logged == 1,
      "one frame callback should have been logged");
  fail_unless(last_frame_sender_id == 0x42,
      "sender_id decoded incorrectly");
  fail_unless(last_frame_payload_len == sizeof(test_data),
      "len decoded incorrectly");
  fail_unless(last_frame_len == sizeof(test_data) + 8,
      "frame len decoded incorrectly");
  fail_unless(last_frame_msg_type == 0x2269,
      "msg_type decoded incorrectly");
  char test[1024];
  char* ptr = test;
  for (int i = 0; i < last_frame_len; i++) {
    ptr += sprintf(ptr, "%02X", last_frame[i]);
  }
  fail_unless(memcmp(last_frame, test_frame, sizeof(test_frame)-1)
        == 0,
      "decoded incorrectly %s", test);
  fail_unless(last_frame_context == &DUMMY_MEMORY_FOR_CALLBACKS,
      "context pointer incorrectly passed");

  sbp_register_frame_callback(&s, 0x2270, &frame_logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
  fail_unless(sbp_find_callback(&s, 0x2270) != 0,
    "second callback not found");

  sbp_remove_callback(&s, &n2);
  fail_unless(sbp_find_callback(&s, 0x2270) == 0,
    "callback not removed");

  /* Test sbp_process with both a frame callback and a not frame callback */

  static sbp_msg_callbacks_node_t n3;
  static sbp_msg_callbacks_node_t n4;

  logging_reset();
  dummy_reset();
  sbp_clear_callbacks(&s);

  static sbp_msg_callbacks_node_t q;
  sbp_register_callback(&s, 0x2269, &logging_callback, 0, &n3);
  sbp_register_frame_callback(&s, 0x2269, &frame_logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n4);
  sbp_send_message(&s, 0x2269, 0x42, sizeof(test_data), test_data, &dummy_write);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read_single_byte) >= SBP_OK,
        "sbp_process threw an error! (3)");
  }

  fail_unless(n_callbacks_logged == 1,
      "one regular callback should have been logged (3)");
  fail_unless(n_frame_callbacks_logged == 1,
      "one frame callback should have been logged (3)");

  /* now remove frame callback and make sure that the regular callback is still there */
  sbp_remove_callback(&s, &n4);
  dummy_reset();
  sbp_send_message(&s, 0x2269, 0x42, sizeof(test_data), test_data, &dummy_write);
  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read_single_byte) >= SBP_OK,
        "sbp_process threw an error! (3)");
  }

  fail_unless(n_callbacks_logged == 2,
      "two regular callback should have been logged (3)");

  /* now test that no frame callback with bad msg and direct writing to buffer */
  u8 awesome_message[] = {0x55, 0x33, 0x22, 0x77, 0x66,
                          0x02, 0x22, 0x33, 0x8A, 0x33};
  logging_reset();
  dummy_reset();
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message);
  memcpy(dummy_buff, awesome_message, sizeof(awesome_message));

  static sbp_msg_callbacks_node_t m;
  sbp_register_frame_callback(&s, 0x2233, &frame_logging_callback, 0, &m);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error! (3)");
  }

  fail_unless(n_frame_callbacks_logged == 1,
      "one callback should have been logged (3)");
  fail_unless(last_frame_sender_id == 0x6677,
      "sender_id decoded incorrectly (3)");
  fail_unless(last_frame_payload_len == 2,
      "len decoded incorrectly (3)");
  fail_unless(memcmp(last_frame, awesome_message, sizeof(awesome_message))
        == 0,
      "test data decoded incorrectly (3) %x", last_frame[sizeof(awesome_message)-1]);

  awesome_message[4] = 0xAA;
  logging_reset();
  dummy_reset();
  dummy_rd = 0;
  dummy_wr = sizeof(awesome_message);
  memcpy(dummy_buff, awesome_message, sizeof(awesome_message));

  s8 ret = 0;
  while (dummy_rd < dummy_wr) {
    ret |= sbp_process(&s, &dummy_read);
  }

  fail_unless(ret == SBP_CRC_ERROR,
      "sbp_process should have returned SBP_CRC_ERROR "
      "for malformed message");

  fail_unless(n_frame_callbacks_logged == 0,
      "no frame callbacks should have been logged (2)");

}
END_TEST

START_TEST(test_sbp_all_msg)
{
  /* Tests registering for all messages */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  static sbp_msg_callbacks_node_t n;

  sbp_register_all_msg_callback(&s, &frame_logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

  u8 msg_1[] = { 0x01, 0x02, 0x03, 0x04 };
  u8 msg_2[] = { 0x05, 0x06, 0x07 };

  dummy_reset();
  logging_reset();
  sbp_send_message(&s, 0x2269, 0x42, sizeof(msg_1), msg_1, &dummy_write);
  sbp_send_message(&s, 0x2270, 0x43, sizeof(msg_2), msg_2, &dummy_write);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error!");
  }

  fail_unless(n_frame_callbacks_logged == 2,
      "two frame callback should have been logged, %u were", n_frame_callbacks_logged);
  fail_unless(last_frame_sender_id == 0x43,
      "sender_id decoded incorrectly");
  fail_unless(last_frame_payload_len == sizeof(msg_2),
      "len decoded incorrectly");
  fail_unless(last_frame_len == sizeof(msg_2) + 8,
      "frame len decoded incorrectly");
}
END_TEST

START_TEST(test_sbp_big_msg)
{
  /* Tests registering for max size message SBP_MAX_PAYLOAD_LEN (255) */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

  sbp_register_frame_callback(&s, 0x2269, &frame_logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
  sbp_register_callback(&s, 0x2269, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

  u8 big_msg[SBP_MAX_PAYLOAD_LEN];
  for(int i = 0; i < sizeof(big_msg); i++) { big_msg[i]=i;}

  dummy_reset();
  logging_reset();
  sbp_send_message(&s, 0x2269, 0x42, sizeof(big_msg), big_msg, &dummy_write);

  s8 ret = SBP_OK;
  while (dummy_rd < dummy_wr) {
    ret = sbp_process(&s, &dummy_read);
    fail_unless(ret >= SBP_OK,
        "sbp_process threw an error! error_code: %d", ret);
  }

  fail_unless(n_frame_callbacks_logged == 1,
      "one frame callback should have been logged, %u were", n_frame_callbacks_logged);
  fail_unless(n_callbacks_logged == 1,
      "one callbackx should have been logged, %u were", n_frame_callbacks_logged);
  fail_unless(last_frame_sender_id == 0x42,
      "sender_id decoded incorrectly");
  fail_unless(last_frame_payload_len == sizeof(big_msg),
      "len decoded incorrectly");
  fail_unless(last_frame_len == SBP_MAX_FRAME_LEN,
      "frame len decoded incorrectly");
  fail_unless(memcmp(SBP_FRAME_MSG_PAYLOAD(last_frame), big_msg, sizeof(big_msg))
        == 0,
      "frame data decoded incorrectly (3) %x");
  /* check that CRC wasn't chopped off */
  fail_unless((last_frame[262]  == 0x35 && last_frame[261] == 0xA6),
      "CRC was incorrect. Should be %x and was %x", 0x35A6,  *((u16*) &(last_frame[261])));
}
END_TEST

START_TEST(test_sbp_send_message)
{
  /* TODO: Tests with different write function behaviour. */

  sbp_state_t s;
  sbp_state_init(&s);


  u8 smsg[] = { 0x22, 0x33 };

  fail_unless(sbp_send_message(&s, 0x2233, 0x4455, 0, smsg, 0) == SBP_NULL_ERROR,
      "sbp_send_message should return an error if write is NULL");

  dummy_reset();
  fail_unless(sbp_send_message(&s, 0x2233, 0x4455, 1, 0, &dummy_write)
        == SBP_NULL_ERROR,
      "sbp_send_message should return an error if payload is NULL and len != 0");

  dummy_reset();
  fail_unless(sbp_send_message(&s, 0x2233, 0x4455, 0, 0, &dummy_write)
        == SBP_OK,
      "sbp_send_message should return OK if payload is NULL and len == 0");

  u8 zero_len_message[] = {0x55, 0x33, 0x22, 0x55, 0x44, 0x00, 0x2C, 0x4C};

  fail_unless(memcmp(dummy_buff, zero_len_message, sizeof(zero_len_message))
        == 0,
      "sbp_send_message encode error for len = 0");

  dummy_reset();
  sbp_send_message(&s, 0x2233, 0x6677, sizeof(smsg), smsg, &dummy_write);

  u8 awesome_message[] = {0x55, 0x33, 0x22, 0x77, 0x66,
                          0x02, 0x22, 0x33, 0x8A, 0x33};

  fail_unless(memcmp(dummy_buff, awesome_message, sizeof(awesome_message))
        == 0,
      "sbp_send_message encode error for test message");
}
END_TEST

START_TEST(test_callbacks)
{

  sbp_state_t s;
  sbp_state_init(&s);

  /* Start with no callbacks registered.  */
  sbp_clear_callbacks(&s);

  fail_unless(sbp_find_callback(&s, 0x1234) == 0,
      "sbp_find_callback should return NULL if no callbacks registered");

  fail_unless(sbp_register_callback(&s, 0x2233, &test_callback, 0, 0) == SBP_NULL_ERROR,
      "sbp_register_callback should return an error if node is NULL");

  /* Add a first callback. */

  static sbp_msg_callbacks_node_t n;

  int NUMBER = 42;

  fail_unless(sbp_register_callback(&s, 0x2233, 0, 0, &n) == SBP_NULL_ERROR,
      "sbp_register_callback should return an error if cb is NULL");

  fail_unless(sbp_register_callback(&s, 0x2233, &test_callback, &NUMBER, &n) == SBP_OK,
      "sbp_register_callback should return success if everything is groovy");

  fail_unless(sbp_register_callback(&s, 0x2233, &test_callback, 0, &n)
        == SBP_CALLBACK_ERROR,
      "sbp_register_callback should return SBP_CALLBACK_ERROR if a callback "
      "of the same type is already registered");

  fail_unless(sbp_find_callback(&s, 0x1234) == 0,
      "sbp_find_callback should return NULL if callback not registered");

  fail_unless(sbp_find_callback(&s, 0x2233) == &n,
      "sbp_find_callback didn't return the correct callback node pointer");

  fail_unless(sbp_find_callback(&s, 0x2233)->context == &NUMBER,
      "sbp_find_callback didn't return the correct context pointer");

  /* Add a second callback. */

  static sbp_msg_callbacks_node_t m;

  int NUMBER2 = 84;

  fail_unless(sbp_register_callback(&s, 0x1234, &test_callback2, &NUMBER2, &m) == SBP_OK,
      "sbp_register_callback should return success if everything is groovy (2)");

  fail_unless(sbp_find_callback(&s, 0x2233) == &n,
      "sbp_find_callback didn't return the correct callback function pointer (2)");

  fail_unless(sbp_find_callback(&s, 0x2233)->context == &NUMBER,
      "sbp_find_callback didn't return the correct context pointer");

  fail_unless(sbp_find_callback(&s, 0x1234) == &m,
      "sbp_find_callback didn't return the correct callback function pointer (3)");

  fail_unless(sbp_find_callback(&s, 0x1234)->context == &NUMBER2,
      "sbp_find_callback didn't return the correct context pointer");

  fail_unless(sbp_register_callback(&s, 0x1234, &test_callback, 0, &n)
        == SBP_CALLBACK_ERROR,
      "sbp_register_callback should return SBP_CALLBACK_ERROR if a callback "
      "of the same type is already registered (2)");

  fail_unless(sbp_find_callback(&s, 0x7788) == 0,
      "sbp_find_callback should return NULL if callback not registered (2)");

  /* Clear all the registered callbacks and check they can no longer be found. */
  sbp_clear_callbacks(&s);

  fail_unless(sbp_find_callback(&s, 0x1234) == 0,
      "sbp_find_callback should return NULL if no callbacks registered (2)");

  fail_unless(sbp_find_callback(&s, 0x2233) == 0,
      "sbp_find_callback should return NULL if no callbacks registered (3)");

}
END_TEST

START_TEST(test_frame_callbacks)
{

  sbp_state_t s;
  sbp_state_init(&s);

  /* Start with no callbacks registered.  */
  sbp_clear_callbacks(&s);

  fail_unless(sbp_find_callback(&s, 0x1234) == 0,
      "sbp_find_callback should return NULL if no callbacks registered");

  fail_unless(sbp_register_frame_callback(&s, 0x2233, &test_frame_callback, 0, 0) == SBP_NULL_ERROR,
      "sbp_register_frame_callback should return an error if node is NULL");

  /* Add a first callback. */

  static sbp_msg_callbacks_node_t n;

  int NUMBER = 42;

  fail_unless(sbp_register_frame_callback(&s, 0x2233, 0, 0, &n) == SBP_NULL_ERROR,
      "sbp_register_callback should return an error if cb is NULL");

  fail_unless(sbp_register_frame_callback(&s, 0x2233, &test_frame_callback, &NUMBER, &n) == SBP_OK,
      "sbp_register_callback should return success if everything is groovy");

  fail_unless(sbp_register_frame_callback(&s, 0x2233, &test_frame_callback, 0, &n)
        == SBP_CALLBACK_ERROR,
      "sbp_register_callback should return SBP_CALLBACK_ERROR if a callback "
      "of the same type is already registered");

  fail_unless(sbp_find_callback(&s, 0x1234) == 0,
      "sbp_find_callback should return NULL if callback not registered");

  fail_unless(sbp_find_callback(&s, 0x2233) == &n,
      "sbp_find_callback didn't return the correct callback node pointer");

  fail_unless(sbp_find_callback(&s, 0x2233)->context == &NUMBER,
      "sbp_find_callback didn't return the correct context pointer");

  /* Add a second callback. */

  static sbp_msg_callbacks_node_t m;

  int NUMBER2 = 84;

  fail_unless(sbp_register_frame_callback(&s, 0x1234, &test_frame_callback2, &NUMBER2, &m) == SBP_OK,
      "sbp_register_callback should return success if everything is groovy (2)");

  fail_unless(sbp_find_callback(&s, 0x2233) == &n,
      "sbp_find_callback didn't return the correct callback function pointer (2)");

  fail_unless(sbp_find_callback(&s, 0x2233)->context == &NUMBER,
      "sbp_find_callback didn't return the correct context pointer");

  fail_unless(sbp_find_callback(&s, 0x1234) == &m,
      "sbp_find_callback didn't return the correct callback function pointer (3)");

  fail_unless(sbp_find_callback(&s, 0x1234)->context == &NUMBER2,
      "sbp_find_callback didn't return the correct context pointer");

  fail_unless(sbp_register_frame_callback(&s, 0x1234, &test_frame_callback, 0, &n)
        == SBP_CALLBACK_ERROR,
      "sbp_register_callback should return SBP_CALLBACK_ERROR if a callback "
      "of the same type is already registered (2)");

  fail_unless(sbp_find_callback(&s, 0x7788) == 0,
      "sbp_find_callback should return NULL if callback not registered (2)");

  /* Clear all the registered callbacks and check they can no longer be found. */

  sbp_clear_callbacks(&s);

  fail_unless(sbp_find_callback(&s, 0x1234) == 0,
      "sbp_find_callback should return NULL if no callbacks registered (2)");

  fail_unless(sbp_find_callback(&s, 0x2233) == 0,
      "sbp_find_callback should return NULL if no callbacks registered (3)");

}
END_TEST

START_TEST(test_msg_buff_backwards_compatibility)
{
  /* TODO: Tests with different read function behaviour. */

  sbp_state_t s;
  sbp_state_init(&s);
  sbp_state_set_io_context(&s, &DUMMY_MEMORY_FOR_IO);

  static sbp_msg_callbacks_node_t n;

  sbp_register_callback(&s, 0x2269, &test_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

  u8 test_data[] = { 0x01, 0x02, 0x03, 0x04 };

  dummy_reset();
  sbp_send_message(&s, 0x2269, 0x42, sizeof(test_data), test_data, &dummy_write);

  while (dummy_rd < dummy_wr) {
    fail_unless(sbp_process(&s, &dummy_read) >= SBP_OK,
        "sbp_process threw an error!");
  }
   fail_unless(s.msg_buff[0] == 0x01, "msg_buff backwards compatibility broken!");
   fail_unless(s.msg_buff[1] == 0x02, "msg_buff backwards compatibility broken!");
   fail_unless(s.msg_buff[2] == 0x03, "msg_buff backwards compatibility broken!");
   fail_unless(s.msg_buff[3] == 0x04, "msg_buff backwards compatibility broken!");
}
END_TEST

Suite* sbp_suite(void)
{
  Suite *s = suite_create("SBP");

  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_msg_buff_backwards_compatibility);
  tcase_add_test(tc_core, test_callbacks);
  tcase_add_test(tc_core, test_sbp_send_message);
  tcase_add_test(tc_core, test_sbp_process);
  tcase_add_test(tc_core, test_sbp_frame);
  tcase_add_test(tc_core, test_frame_callbacks);
  tcase_add_test(tc_core, test_sbp_all_msg);
  tcase_add_test(tc_core, test_sbp_big_msg);

  suite_add_tcase(s, tc_core);

  return s;
}
