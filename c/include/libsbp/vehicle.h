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
 * Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup vehicle Vehicle
 *
 * * Messages from a vehicle.
 * \{ */

#ifndef LIBSBP_VEHICLE_MESSAGES_H
#define LIBSBP_VEHICLE_MESSAGES_H

#include "common.h"


/** Vehicle forward (x-axis) velocity
 *
 * Message representing the x component of vehicle velocity in the user frame at the odometry
 * reference point(s) specified by the user. The offset for the odometry reference point and 
 * the definition and origin of the user frame are defined through the device settings interface.
 * There are 4 possible user-defined sources of this message  which are labeled arbitrarily 
 * source 0 through 3.
 */
#define SBP_MSG_ODOMETRY 0x0903
typedef struct __attribute__((packed)) {
  u32 tow;         /**< Time field representing either milliseconds in the GPS Week or local CPU
time from the producing system in milliseconds.  See the tow_source flag
for the exact source of this timestamp.
 [ms] */
  s32 velocity;    /**< The signed forward component of vehicle velocity.
 [mm/s] */
  u8 flags;       /**< Status flags */
} msg_odometry_t;
int msg_odometry_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_odometry_t * in, uint64_t max_len, char* out_str);

/** \} */

#endif /* LIBSBP_VEHICLE_MESSAGES_H */