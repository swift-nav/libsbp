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
((*- for message in package_messages *))
#include <libsbp/(((pkg_name))).h>
#include <libsbp/cpp/(((pkg_name))).h>
((*- endfor *))

((* for message in package_messages if message.fields and extract_template_fields(message, all_messages) | length < 2 *))
TEST(test_(((message.identifier|snake_case))), default_construction) {
  ((*- if is_zero_array_message(message) *))
  sbp::(((message.identifier|pascal_case)))<> variable;
  ((*- elif is_templated_field_message(message, all_messages) *))
  sbp::(((message.identifier|pascal_case)))<1> variable;
  ((*- else *))
  sbp::(((message.identifier|pascal_case))) variable;
  ((*- endif *))
  (void) variable;
}

TEST(test_(((message.identifier|snake_case))), reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));

  ((*- if is_zero_array_message(message) *))
  constexpr size_t kBufferSize = sizeof(sbp::(((message.identifier|pascal_case)))<>);
  ((*- elif is_templated_field_message(message, all_messages) *))
  constexpr size_t kBufferSize = sizeof(sbp::(((message.identifier|pascal_case)))<1>);
  ((*- else *))
  constexpr size_t kBufferSize = sizeof(sbp::(((message.identifier|pascal_case))));
  ((*- endif *))

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const (((message.identifier | c_struct_name))) *c_struct = reinterpret_cast<const (((message.identifier | c_struct_name)))*>(buffer);

  ((*- if is_zero_array_message(message) *))
  const sbp::(((message.identifier|pascal_case)))<> *cpp_struct = reinterpret_cast<const sbp::(((message.identifier|pascal_case)))<>*>(buffer);
  ((*- elif is_templated_field_message(message, all_messages) *))
  const sbp::(((message.identifier|pascal_case)))<1> *cpp_struct = reinterpret_cast<const sbp::(((message.identifier|pascal_case)))<1>*>(buffer);
  ((*- else *))
  const sbp::(((message.identifier | pascal_case))) *cpp_struct = reinterpret_cast<const sbp::(((message.identifier | pascal_case)))*>(buffer);
  ((*- endif *))

//  ((*- for field in message.fields *))
//  EXPECT_EQ(c_struct->(((field.identifier))), cpp_struct->(((field.identifier))));
//  ((*- endfor *))
}
((* endfor *))
