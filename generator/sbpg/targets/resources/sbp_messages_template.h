/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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

((* for m in msgs *))
((*- if m.desc *))
/** (((m.short_desc)))
 *
(((m.desc|commentify)))
 */
((*- endif *))
((*- if m.sbp_id *))
#define SBP_(((m.identifier.ljust(max_msgid_len)))) ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
((*- if m.fields *))
typedef struct __attribute__((packed)) {
  ((*- for f in m.fields *))
  ((*- if f.desc *))
  (((f|mk_id))) ((((f|mk_size).ljust(m.max_fid_len+4)))) /**< (((f.desc))) ((* if f.units *))[(((f.units)))] ((* endif *))*/
  ((*- else *))
  (((f|mk_id))) ((((f|mk_size).ljust(m.max_fid_len+4))))
  ((*- endif *))
  ((*- endfor *))
} (((m.identifier|convert)));
((*- endif *))

((* endfor *))
/** \} */

#endif /* LIBSBP_(((pkg_name|upper)))_MESSAGES_H */
