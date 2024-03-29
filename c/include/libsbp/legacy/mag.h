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
 * Automatically generated from yaml/swiftnav/sbp/mag.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup mag Mag
 *
 * Magnetometer (mag) messages.
 * \{ */

#ifndef LIBSBP_LEGACY_MAG_MESSAGES_H
#define LIBSBP_LEGACY_MAG_MESSAGES_H

#include <libsbp/common.h>

SBP_MESSAGE(
    "The legacy libsbp API has been deprecated. This file and all symbols "
    "contained will "
    "be removed in version 6. You should immediately switch over to the modern "
    "libsbp API.")

#include <libsbp/mag_macros.h>

SBP_PACK_START

/** Raw magnetometer data
 *
 * Raw data from the magnetometer.
 */

typedef struct SBP_ATTR_PACKED SBP_DEPRECATED {
  u32 tow;   /**< Milliseconds since start of GPS week. If the high bit is
                  set, the time is unknown or invalid. [ms] */
  u8 tow_f;  /**< Milliseconds since start of GPS week, fractional part [ms /
                256] */
  s16 mag_x; /**< Magnetic field in the body frame X axis [microteslas] */
  s16 mag_y; /**< Magnetic field in the body frame Y axis [microteslas] */
  s16 mag_z; /**< Magnetic field in the body frame Z axis [microteslas] */
} msg_mag_raw_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_MAG_MESSAGES_H */