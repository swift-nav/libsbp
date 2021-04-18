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

#include <gtest/gtest.h>
((*- for message in package_messages *))
#include <libsbp/(((pkg_name))).h>
#include <libsbp/cpp/(((pkg_name))).h>
((*- endfor *))

((* for message in package_messages if extract_template_fields(message, all_messages) | length < 2 *))
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

}
((* endfor *))
