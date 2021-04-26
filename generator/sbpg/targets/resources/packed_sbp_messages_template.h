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

#ifndef LIBSBP_PACKED_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_PACKED_(((pkg_name|upper)))_MESSAGES_H

#include <libsbp/common.h>

((*- for i in include *))
#include <libsbp/packed/(((i)))>
((*- endfor *))

SBP_PACK_START

((* for m in msgs *))
((*- if m.fields *))
((*- for f in m.fields *))
((*- if f.options.fields *))
(((f|create_bitfield_macros(m.identifier))))
((*- endif *))
((*- endfor *))
((*- endif *))
((*- if m.desc *))
/** (((m.short_desc)))
 *
(((m.desc|commentify)))
 */
((*- endif *))
typedef struct SBP_ATTR_PACKED {
((*- if m.is_real_message *))
#define SBP_(((m.identifier.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
  ((* for f in m.fields *))

  ((*- if f.desc *))
  /** 
   (((f.desc|commentify))) ((* if f.units *))[(((f.units)))] ((* endif *))
   */
  ((*- endif *))
  (((f|mk_packed_id))) ((((f|mk_size).ljust(m.max_fid_len+4))))
  ((* endfor *))
} (((m.identifier|convert_packed)));

((* endfor *))
/** \} */

SBP_PACK_END

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */
