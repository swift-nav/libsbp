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

#ifndef LIBSBP_SBP_MSG_TYPE_H
#define LIBSBP_SBP_MSG_TYPE_H

((* for p in packages *))
#include <libsbp/(((p.name)))_macros.h>
((*- endfor *))

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
((*- for m in real_messages *))
  (((m.v4_msg_type))) = (((m.legacy_msg_type))),
((*- endfor *))
} sbp_msg_type_t;

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP_MSG_TYPE_H */

