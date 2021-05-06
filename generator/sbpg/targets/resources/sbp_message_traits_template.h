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

((*- for i in includes *))
#include <libsbp/(((i))).h>
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
((*- if m.fields *))
((*- if m.fields|first == m.fields|last *))
((*- if (m.fields|first)|field_is_variable_sized *))
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
((*- endif *))
((*- endif *))
template<>
struct MessageTraits<(((m.identifier|convert)))> {
  static constexpr u16 id = (((m.sbp_id)));
};
((*- if m.fields|first == m.fields|last *))
((*- if (m.fields|first)|field_is_variable_sized *))
#endif
((*- endif *))
((*- endif *))
((* endif *))
((* endfor *))


} // namespace sbp

#endif //SBP_CPP_MESSAGE_TRAITS_H
