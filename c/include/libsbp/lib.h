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
 * Automatically generated from piksi/yaml/
 * with generate.py at 2015-03-13 13:32:04.091582. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_LIB_MESSAGES_H
#define LIBSBP_LIB_MESSAGES_H

#include "common.h"


/** None
  * Statistics on the latency of observations received from the base
 * station. As observation packets are received their GPS time is
 * compared to the current GPS time calculated locally by the
 * receiver to give a precise measurement of the end-to-end
 * communication latency in the system.
 */
typedef struct __attribute__((packed)) {
  s32 avg;        /**< Average latency. [ms] */
  s32 lmin;       /**< Minimum latency. [ms] */
  s32 lmax;       /**< Maximum latency. [ms] */
  s32 current;    /**< Smoothed estimate of the current latency. [ms] */
} latency_t;


/** None
  * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles.
 */
typedef struct __attribute__((packed)) {
  u32 i;    /**< Carrier phase whole cycles. [cycles] */
  u8 f;    /**< Carrier phase fractional part. [cycles / 255] */
} carrier_phase_t;


#endif /* LIBSBP_LIB_MESSAGES_H */