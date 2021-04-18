/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated. Do not modify by hand!

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <libsbp/ndb.h>
#include <libsbp/cpp/ndb.h>


TEST(test_msg_ndb_event, default_construction) {
  sbp::MsgNdbEvent variable;
  (void) variable;
}

TEST(test_msg_ndb_event, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgNdbEvent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ndb_event_t *c_struct = reinterpret_cast<const msg_ndb_event_t*>(buffer);
  const sbp::MsgNdbEvent *cpp_struct = reinterpret_cast<const sbp::MsgNdbEvent*>(buffer);

//
//  EXPECT_EQ(c_struct->recv_time, cpp_struct->recv_time);
//
//  EXPECT_EQ(c_struct->event, cpp_struct->event);
//
//  EXPECT_EQ(c_struct->object_type, cpp_struct->object_type);
//
//  EXPECT_EQ(c_struct->result, cpp_struct->result);
//
//  EXPECT_EQ(c_struct->data_source, cpp_struct->data_source);
//
//  EXPECT_EQ(c_struct->object_sid, cpp_struct->object_sid);
//
//  EXPECT_EQ(c_struct->src_sid, cpp_struct->src_sid);
//
//  EXPECT_EQ(c_struct->original_sender, cpp_struct->original_sender);
//
}
