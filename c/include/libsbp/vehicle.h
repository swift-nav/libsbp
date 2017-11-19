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
 * Message representing the forward component of vehicle velocity, which
 * corresponds with the body axis x direction. There are 4 possible user-defined
 * sources of this message  which are labeled arbitrarily source 0 through 3.
 */
#define SBP_MSG_FWD_VEL 0x0903
typedef struct __attribute__((packed)) {
  u32 tow;         /**< Time field representing either milliseconds in the GPS Week or local CPU
time from the producing system in milliseconds.  See the tow_source flag
for the exact source of this timestamp.
 [ms] */
  s32 velocity;    /**< The signed forward component of vehicle velocity.
 [mm/s] */
  u8 flags;       /**< Status flags */
} msg_fwd_vel_t;


/** \} */

#endif /* LIBSBP_VEHICLE_MESSAGES_H */