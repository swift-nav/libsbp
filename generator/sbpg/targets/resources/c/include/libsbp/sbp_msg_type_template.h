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
  (((m.msg_type))) = ((('0x%04X'|format(m.sbp_id)))),
((*- endfor *))
  SbpMsgAll = 0,
  SbpMsgUnknown = 0,
} sbp_msg_type_t;

static inline const char *sbp_msg_type_to_string(sbp_msg_type_t msg_type) {
  switch(msg_type) {
    ((*- for m in real_messages *))
    case (((m.msg_type))):
      return "(((m.name)))";
    ((*- endfor *))
    case SbpMsgAll:
    default:
      return "(unknown)";
  }
}

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP_MSG_TYPE_H */

