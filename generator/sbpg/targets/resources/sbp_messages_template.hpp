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

/*****************************************************************************
 * Automatically generated from yaml/(((filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_CPP_(((pkg_name|upper)))_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

((*- for i in include *))
#include <libsbp/cpp/(((i)))>
((*- endfor *))

namespace sbp {
  ((* for message in package_messages if extract_template_fields(message, all_messages) | length < 2 *))
  ((*- if message.desc *))
  /**
   * (((message.short_desc)))
   *
   * (((message.desc|commentify(2))))
   */
  ((*- endif *))
  ((*- if message.fields *))
  (((message|mk_template(all_messages))))
  struct SBP_ATTR_PACKED (((message.identifier|pascal_case))) {
    ((*- for field in message.fields *))
    ((*- if field.desc *))
    (((field|mk_field))) /** (((field.desc))) ((* if field.units *))[(((field.units)))] ((* endif *))*/
    ((*- else *))
    (((field|mk_field)))
    ((*- endif *))
    ((*- endfor *))
  };
  ((*- endif *))
  ((* endfor *))

}  // namespace sbp

#endif /* LIBSBP_CPP_(((pkg_name|upper)))_MESSAGES_H */
