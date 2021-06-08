/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
(((description|commentify)))
 * \{ */

#ifndef LIBSBP_LEGACY_(((pkg_name|upper)))_MESSAGES_H
#define LIBSBP_LEGACY_(((pkg_name|upper)))_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/(((pkg_name)))_macros.h>
((*- for i in include *))
#include <libsbp/legacy/(((i)))>
((*- endfor *))

SBP_PACK_START

((* for m in msgs *))
((*- if m.desc *))
/** (((m.short_desc)))
 *
(((m.desc|commentify)))
 */
((*- endif *))
((*- if m.fields *))

typedef struct SBP_ATTR_PACKED {
  ((*- for f in m.fields *))
  ((*- if f.desc *))
  (((f|mk_id))) ((((f|mk_size).ljust(m.max_fid_len+4)))) /**< ((( f.desc|commentify_field(f,m) ))) ((* if f.units *))[(((f.units)))] ((* endif *))*/
  ((*- else *))
  (((f|mk_id))) ((((f|mk_size).ljust(m.max_fid_len+4))))
  ((*- endif *))
  ((*- endfor *))
} (((m.identifier|convert)));
((*- endif *))

((* endfor *))
/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_(((pkg_name|upper)))_MESSAGES_H */
