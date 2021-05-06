/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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

/** \defgroup (((pkg_name))) (((pkg_name|capitalize)))
 *
 * (((description|commentify)))
 * \{ */

#ifndef LIBSBP_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_(((pkg_name|upper)))_MESSAGES_H

#include "common.h"

((*- for i in include *))
#include "(((i)))"
((*- endfor *))

SBP_PACK_START

((* for m in msgs *))
((*- if m.desc *))
/** (((m.short_desc)))
 *
(((m.desc|commentify)))
 */
((*- endif *))
((*- if m.is_real_message *))
#define SBP_(((m.identifier.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
((*- if m.fields *))
((*- if m.sbp_id or m.embedded_type *))
((*- for f in m.fields *))
((*- if f.options.fields *))
(((f|create_bitfield_macros(m.identifier))))
((*- endif *))
((*- endfor *))
((*- endif *))

((*- if m.fields|first == m.fields|last *))
((*- if (m.fields|first)|field_is_variable_sized *))
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
((*- endif *))
((*- endif *))

typedef struct SBP_ATTR_PACKED {
  ((*- for f in m.fields *))
  ((*- if m.fields|first != m.fields|last *))
  ((*- if f|field_is_variable_sized *))
#ifdef SBP_ENABLE_VARIABLE_SIZED_ARRAYS
  ((*- endif *))
  ((*- endif *))
  ((*- if f.desc *))
  (((f|mk_id))) ((((f|mk_size).ljust(m.max_fid_len+4)))) /**< (((f.desc))) ((* if f.units *))[(((f.units)))] ((* endif *))*/
  ((*- else *))
  (((f|mk_id))) ((((f|mk_size).ljust(m.max_fid_len+4))))
  ((*- endif *))
  ((*- if m.fields|first != m.fields|last *))
  ((*- if f|field_is_variable_sized *))
#endif
  ((*- endif *))
  ((*- endif *))
  ((*- endfor *))
} (((m.identifier|convert)));
((*- if m.fields|first == m.fields|last *))
((*- if (m.fields|first)|field_is_variable_sized *))
#endif
((*- endif *))
((*- endif *))
((*- endif *))

((* endfor *))
/** \} */

SBP_PACK_END

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */

