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
 * Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup vehicle Vehicle
 *
 * Messages from a vehicle.
 * \{ */

#ifndef LIBSBP_LEGACY_VEHICLE_MESSAGES_H
#define LIBSBP_LEGACY_VEHICLE_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/vehicle_macros.h>

SBP_PACK_START

/** Vehicle forward (x-axis) velocity
 *
 * Message representing the x component of vehicle velocity in the user frame
 * at the odometry reference point(s) specified by the user. The offset for
 * the odometry reference point and the definition and origin of the user
 * frame are defined through the device settings interface. There are 4
 * possible user-defined sources of this message which are labeled arbitrarily
 * source 0 through 3. If using "processor time" time tags, the receiving end
 * will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to
 * synchronise odometry measurements with GNSS. Processor time shall roll over
 * to zero after one week.
 */

typedef struct SBP_ATTR_PACKED {
  u32 tow;      /**< Time field representing either milliseconds in the GPS
                     Week or local CPU time from the producing system in
                     milliseconds.  See the tow_source flag for the exact
                     source of this timestamp. [ms] */
  s32 velocity; /**< The signed forward component of vehicle velocity. [mm/s] */
  u8 flags;     /**< Status flags */
} msg_odometry_t;

/** Accumulated wheeltick count message
 *
 * Message containing the accumulated distance travelled by a wheel located at
 * an odometry reference point defined by the user. The offset for the
 * odometry reference point and the definition and origin of the user frame
 * are defined through the device settings interface. The source of this
 * message is identified by the source field, which is an integer ranging from
 * 0 to 255. The timestamp associated with this message should represent the
 * time when the accumulated tick count reached the value given by the
 * contents of this message as accurately as possible. If using "local CPU
 * time" time tags, the receiving end will expect a `MSG_GNSS_TIME_OFFSET`
 * when a PVT fix becomes available to synchronise wheeltick measurements with
 * GNSS. Local CPU time shall roll over to zero after one week.
 */

typedef struct SBP_ATTR_PACKED {
  u64 time;  /**< Time field representing either microseconds since the
                  last PPS, microseconds in the GPS Week or local CPU time
                  from the producing system in microseconds. See the
                  synch_type field for the exact meaning of this
                  timestamp. [us] */
  u8 flags;  /**< Field indicating the type of timestamp contained in the
                  time field. */
  u8 source; /**< ID of the sensor producing this message */
  s32 ticks; /**< Free-running counter of the accumulated distance for
                  this sensor. The counter should be incrementing if
                  travelling into one direction and decrementing when
                  travelling in the opposite direction. [arbitrary distance
                units] */
} msg_wheeltick_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_VEHICLE_MESSAGES_H */