/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/mag.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup mag Mag
 *
 * * Magnetometer (mag) messages.
 * \{ */

#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include "common.h"


/** Raw magnetometer data
 *
 * Raw data from the magnetometer.
 */
#define SBP_MSG_MAG_RAW 0x0902
typedef struct __attribute__((packed)) {
  u32 tow;      /**< Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 [ms] */
  u8 tow_f;    /**< Milliseconds since start of GPS week, fractional part
 [ms / 256] */
  s16 mag_x;    /**< Magnetic field in the body frame X axis */
  s16 mag_y;    /**< Magnetic field in the body frame Y axis */
  s16 mag_z;    /**< Magnetic field in the body frame Z axis */
} msg_mag_raw_t;


/** \} */

#endif /* LIBSBP_MAG_MESSAGES_H */