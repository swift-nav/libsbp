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
 * Automatically generated from yaml/swiftnav/sbp/navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup navigation Navigation
 *
 *  * Geodetic navigation messages reporting GPS time, position, velocity,
 * and baseline position solutions. For position solutions, these
 * messages define several different position solutions: single-point
 * (SPP), RTK, and pseudo-absolute position solutions.
 * 
 * The SPP is the standalone, absolute GPS position solution using only
 * a single receiver. The RTK solution is the differential GPS
 * solution, which can use either a fixed/integer or floating carrier
 * phase ambiguity. The pseudo-absolute position solution uses a
 * user-provided, well-surveyed base station position (if available)
 * and the RTK solution in tandem.
 * \{ */

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#define LIBSBP_NAVIGATION_MESSAGES_H

#include "common.h"


/** GPS Time
 *
 * This message reports the GPS time, representing the time since
 * the GPS epoch began on midnight January 6, 1980 UTC. GPS time
 * counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of
 * the GPS time scale.
 * 
 * Within each week number, the GPS time of the week is between
 * between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
 * does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a
 * set of other navigation messages referenced to the same time
 * (but lacking the ns field) and indicates a more precise time of
 * these messages.
 */
#define SBP_MSG_GPS_TIME         0x0100
typedef struct __attribute__((packed)) {
  u16 wn;       /**< GPS week number [weeks] */
  u32 tow;      /**< GPS time of week rounded to the nearest millisecond [ms] */
  s32 ns;       /**< Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
  u8 flags;    /**< Status flags (reserved) */
} msg_gps_time_t;


/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.
 */
#define SBP_MSG_DOPS             0x0206
typedef struct __attribute__((packed)) {
  u32 tow;     /**< GPS Time of Week [ms] */
  u16 gdop;    /**< Geometric Dilution of Precision [0.01] */
  u16 pdop;    /**< Position Dilution of Precision [0.01] */
  u16 tdop;    /**< Time Dilution of Precision [0.01] */
  u16 hdop;    /**< Horizontal Dilution of Precision [0.01] */
  u16 vdop;    /**< Vertical Dilution of Precision [0.01] */
} msg_dops_t;


/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF         0x0200
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  double x;           /**< ECEF X coordinate [m] */
  double y;           /**< ECEF Y coordinate [m] */
  double z;           /**< ECEF Z coordinate [m] */
  u16 accuracy;    /**< Position accuracy estimate (not implemented). Defaults
to 0.
 [mm] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_pos_ecef_t;


/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_POS_LLH          0x0201
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  double lat;           /**< Latitude [deg] */
  double lon;           /**< Longitude [deg] */
  double height;        /**< Height [m] */
  u16 h_accuracy;    /**< Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u16 v_accuracy;    /**< Vertical position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u8 n_sats;        /**< Number of satellites used in solution. */
  u8 flags;         /**< Status flags */
} msg_pos_llh_t;


/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_ECEF    0x0202
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  s32 x;           /**< Baseline ECEF X coordinate [mm] */
  s32 y;           /**< Baseline ECEF Y coordinate [mm] */
  s32 z;           /**< Baseline ECEF Z coordinate [mm] */
  u16 accuracy;    /**< Position accuracy estimate (not implemented). Defaults
to 0.
 [mm] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_baseline_ecef_t;


/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_NED     0x0203
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 n;             /**< Baseline North coordinate [mm] */
  s32 e;             /**< Baseline East coordinate [mm] */
  s32 d;             /**< Baseline Down coordinate [mm] */
  u16 h_accuracy;    /**< Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u16 v_accuracy;    /**< Vertical position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u8 n_sats;        /**< Number of satellites used in solution */
  u8 flags;         /**< Status flags */
} msg_baseline_ned_t;


/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF         0x0204
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  s32 x;           /**< Velocity ECEF X coordinate [mm/s] */
  s32 y;           /**< Velocity ECEF Y coordinate [mm/s] */
  s32 z;           /**< Velocity ECEF Z coordinate [mm/s] */
  u16 accuracy;    /**< Velocity accuracy estimate (not implemented). Defaults
to 0.
 [mm/s] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags (reserved) */
} msg_vel_ecef_t;


/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_NED          0x0205
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 n;             /**< Velocity North coordinate [mm/s] */
  s32 e;             /**< Velocity East coordinate [mm/s] */
  s32 d;             /**< Velocity Down coordinate [mm/s] */
  u16 h_accuracy;    /**< Horizontal velocity accuracy estimate (not
implemented). Defaults to 0.
 [mm/s] */
  u16 v_accuracy;    /**< Vertical velocity accuracy estimate (not
implemented). Defaults to 0.
 [mm/s] */
  u8 n_sats;        /**< Number of satellites used in solution */
  u8 flags;         /**< Status flags (reserved) */
} msg_vel_ned_t;


/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_HEADING 0x0207
typedef struct __attribute__((packed)) {
  u32 tow;        /**< GPS Time of Week [ms] */
  u32 heading;    /**< Heading [mdeg] */
  u8 n_sats;     /**< Number of satellites used in solution */
  u8 flags;      /**< Status flags */
} msg_baseline_heading_t;


/** \} */

#endif /* LIBSBP_NAVIGATION_MESSAGES_H */