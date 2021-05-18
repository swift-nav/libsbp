/**
 * Copyright (C) 2019 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_CPP_MESSAGE_TRAITS_H
#define SBP_CPP_MESSAGE_TRAITS_H

#include <libsbp/unpacked/sbp_msg.h>
((*- for i in includes *))
#include <libsbp/unpacked/(((i))).h>
((*- endfor *))

namespace sbp {

/**
 * Type traits containing meta-information for each SBP message type.
 *
 * These are only meant to be used by the C++ library at compile time.
 * These are automatically generated, DO NOT EDIT.
 */
template<typename>
struct MessageTraits;

((* for m in msgs *))
((*- if m.is_real_message *))
template<>
struct MessageTraits<(((m.identifier|convert_unpacked)))> {
  static constexpr u16 id = (((m.sbp_id)));
  static const (((m.identifier|convert_unpacked))) &get(const sbp_msg_t &msg) { return msg.(((m.identifier|convert_unpacked_union))); }
};

((* endif *))
((* endfor *))


} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H

