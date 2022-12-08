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
 * Automatically generated from yaml/swiftnav/sbp/skylark.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SKYLARK_MACROS_H
#define LIBSBP_SKYLARK_MACROS_H

#define SBP_MSG_ACKNOWLEDGE 0x0FA0
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK (0xffu)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT (0u)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT) & \
        SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK))
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_SET(flags, val)                      \
  do {                                                                     \
    (flags) = (u8)((flags & (~(SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK          \
                               << SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT))) | \
                   (((val) & (SBP_ACKNOWLEDGE_RESPONSE_CODE_MASK))         \
                    << (SBP_ACKNOWLEDGE_RESPONSE_CODE_SHIFT)));            \
  } while (0)

#define SBP_ACKNOWLEDGE_RESPONSE_CODE_OK (0)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_OUT_OF_COVERAGE (1)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_FORBIDDEN (2)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_INVALID_REQUEST (3)
#define SBP_ACKNOWLEDGE_RESPONSE_CODE_INVALID_AREA_ID (4)
/**
 * Encoded length of sbp_msg_acknowledge_t (V4 API) and
 * msg_acknowledge_t (legacy API)
 */
#define SBP_MSG_ACKNOWLEDGE_ENCODED_LEN 11u

#endif /* LIBSBP_SKYLARK_MACROS_H */
