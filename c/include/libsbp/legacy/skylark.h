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

/** \defgroup skylark Skylark
 *
 * Messages from the Skylark corrections service.
 * \{ */

#ifndef LIBSBP_LEGACY_SKYLARK_MESSAGES_H
#define LIBSBP_LEGACY_SKYLARK_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/skylark_macros.h>

SBP_PACK_START

typedef struct SBP_ATTR_PACKED {
  u8 request_counter;            /**< Echo of the request counter field from
                                      the corresponding CRA message, or 255
                                      if no request counter was provided. */
  u32 area_id;                   /**< Echo of the Area ID field from the
                                      corresponding CRA message. */
  u8 response_code;              /**< Reported status of the request. */
  u16 correction_mask_on_demand; /**< Contains the message group(s) that
                                      will be sent in response from the
                                      corresponding CRA correction mask. An
                                      echo of the correction mask field
                                      from the corresponding CRA message. */
  u16 correction_mask_stream;    /**< For future expansion. Always set to
                                      0. */
  u8 solution_id;                /**< The solution ID of the instance
                                      providing the corrections. */
} msg_acknowledge_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SKYLARK_MESSAGES_H */