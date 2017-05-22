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
 * Automatically generated from yaml/swiftnav/sbp/specan.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup specan Specan
 *
 * * Spectrum analyzer and related interference messages
 * \{ */

#ifndef LIBSBP_SPECAN_MESSAGES_H
#define LIBSBP_SPECAN_MESSAGES_H

#include "common.h"
#include "gnss.h"


/** Spectrum analyzer
 *
 * Spectrum analyzer packet.
 */
#define SBP_MSG_SPECAN 0x0050
typedef struct __attribute__((packed)) {
  sbp_gps_time_t t;                  /**< Receiver time of this observation */
  float freq_ref;           /**< Reference frequency of this packet
 */
  float freq_step;          /**< Frequency step of points in this packet
 */
  float amplitude_ref;      /**< Reference amplitude of this packet
 */
  float amplitude_unit;     /**< Amplitude unit value of points in this packet
 */
  u8 amplitude_value[0]; /**< Amplitude values (in the above units) of points in this packet
 */
} msg_specan_t;


/** \} */

#endif /* LIBSBP_SPECAN_MESSAGES_H */