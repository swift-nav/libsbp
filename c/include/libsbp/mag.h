/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
 * * Magnetometer (mag) messages.
 * \{ */

#ifndef LIBSBP_MAG_MESSAGES_H
#define LIBSBP_MAG_MESSAGES_H

#include "common.h"

SBP_PACK_START
#ifdef __ghs__
#pragma pack(1)
#endif


/** Raw magnetometer data
 *
 * Raw data from the magnetometer.
 */
#define SBP_MSG_MAG_RAW 0x0902

typedef struct SBP_ATTR_PACKED {
  u32 tow;      /**< Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 [ms] */
  u8 tow_f;    /**< Milliseconds since start of GPS week, fractional part
 [ms / 256] */
  s16 mag_x;    /**< Magnetic field in the body frame X axis [microteslas] */
  s16 mag_y;    /**< Magnetic field in the body frame Y axis [microteslas] */
  s16 mag_z;    /**< Magnetic field in the body frame Z axis [microteslas] */
} msg_mag_raw_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_MAG_RAW(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_mag_raw_t, tow ) == 0, "Offset of tow in msg_mag_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mag_raw_t, tow ) == 0, offset_of_tow_in_msg_mag_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_mag_raw_t, tow_f ) == 0 + sizeof(u32), "Offset of tow_f in msg_mag_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mag_raw_t, tow_f ) == 0 + sizeof(u32), offset_of_tow_f_in_msg_mag_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_mag_raw_t, mag_x ) == 0 + sizeof(u32) + sizeof(u8), "Offset of mag_x in msg_mag_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mag_raw_t, mag_x ) == 0 + sizeof(u32) + sizeof(u8), offset_of_mag_x_in_msg_mag_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_mag_raw_t, mag_y ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(s16), "Offset of mag_y in msg_mag_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mag_raw_t, mag_y ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(s16), offset_of_mag_y_in_msg_mag_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_mag_raw_t, mag_z ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(s16) + sizeof(s16), "Offset of mag_z in msg_mag_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_mag_raw_t, mag_z ) == 0 + sizeof(u32) + sizeof(u8) + sizeof(s16) + sizeof(s16), offset_of_mag_z_in_msg_mag_raw_t_is_incorrect)
#endif
}


#ifdef __ghs__
#pragma pack()
#endif
SBP_PACK_END

#endif /* LIBSBP_MAG_MESSAGES_H */
