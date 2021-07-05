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
 * Automatically generated from yaml/swiftnav/sbp/navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NAVIGATION_MACROS_H
#define LIBSBP_NAVIGATION_MACROS_H

#define SBP_MSG_GPS_TIME 0x0102
#define SBP_GPS_TIME_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_GPS_TIME_TIME_SOURCE_SHIFT) & SBP_GPS_TIME_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_TIME_SOURCE_SET(flags, val)           \
  do {                                                     \
    ((flags) |= (((val) & (SBP_GPS_TIME_TIME_SOURCE_MASK)) \
                 << (SBP_GPS_TIME_TIME_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_GPS_TIME_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_TIME_SOURCE_PROPAGATED (2)
#define SBP_MSG_GPS_TIME_GNSS 0x0104
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_GET(flags)      \
  (((flags) >> SBP_GPS_TIME_GNSS_TIME_SOURCE_SHIFT) & \
   SBP_GPS_TIME_GNSS_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_GPS_TIME_GNSS_TIME_SOURCE_MASK)) \
                 << (SBP_GPS_TIME_GNSS_TIME_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_GPS_TIME_GNSS_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_GNSS_TIME_SOURCE_PROPAGATED (2)
#define SBP_MSG_UTC_TIME 0x0103
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_GET(flags)      \
  (((flags) >> SBP_UTC_TIME_UTC_OFFSET_SOURCE_SHIFT) & \
   SBP_UTC_TIME_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_UTC_TIME_UTC_OFFSET_SOURCE_MASK)) \
                 << (SBP_UTC_TIME_UTC_OFFSET_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_UTC_TIME_TIME_SOURCE_SHIFT) & SBP_UTC_TIME_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_TIME_SOURCE_SET(flags, val)           \
  do {                                                     \
    ((flags) |= (((val) & (SBP_UTC_TIME_TIME_SOURCE_MASK)) \
                 << (SBP_UTC_TIME_TIME_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_UTC_TIME_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_TIME_SOURCE_PROPAGATED (2)
#define SBP_MSG_UTC_TIME_GNSS 0x0105
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_GET(flags)      \
  (((flags) >> SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SHIFT) & \
   SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_MASK)) \
                 << (SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_GNSS_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_GET(flags)      \
  (((flags) >> SBP_UTC_TIME_GNSS_TIME_SOURCE_SHIFT) & \
   SBP_UTC_TIME_GNSS_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_UTC_TIME_GNSS_TIME_SOURCE_MASK)) \
                 << (SBP_UTC_TIME_GNSS_TIME_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_UTC_TIME_GNSS_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_GNSS_TIME_SOURCE_PROPAGATED (2)
#define SBP_MSG_DOPS 0x0208
#define SBP_DOPS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_DOPS_RAIM_REPAIR_FLAG_SHIFT (7u)
#define SBP_DOPS_RAIM_REPAIR_FLAG_GET(flags)      \
  (((flags) >> SBP_DOPS_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_DOPS_RAIM_REPAIR_FLAG_MASK)
#define SBP_DOPS_RAIM_REPAIR_FLAG_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_DOPS_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_DOPS_RAIM_REPAIR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_DOPS_FIX_MODE_MASK (0x7)
#define SBP_DOPS_FIX_MODE_SHIFT (0u)
#define SBP_DOPS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_DOPS_FIX_MODE_SHIFT) & SBP_DOPS_FIX_MODE_MASK)
#define SBP_DOPS_FIX_MODE_SET(flags, val)                                \
  do {                                                                   \
    ((flags) |=                                                          \
     (((val) & (SBP_DOPS_FIX_MODE_MASK)) << (SBP_DOPS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_DOPS_FIX_MODE_INVALID (0)
#define SBP_DOPS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_DOPS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_DOPS_FIX_MODE_FLOAT_RTK (3)
#define SBP_DOPS_FIX_MODE_FIXED_RTK (4)
#define SBP_DOPS_FIX_MODE_UNDEFINED (5)
#define SBP_DOPS_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_ECEF 0x0209
#define SBP_POS_ECEF_TOW_TYPE_MASK (0x1)
#define SBP_POS_ECEF_TOW_TYPE_SHIFT (5u)
#define SBP_POS_ECEF_TOW_TYPE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_TOW_TYPE_SHIFT) & SBP_POS_ECEF_TOW_TYPE_MASK)
#define SBP_POS_ECEF_TOW_TYPE_SET(flags, val)           \
  do {                                                  \
    ((flags) |= (((val) & (SBP_POS_ECEF_TOW_TYPE_MASK)) \
                 << (SBP_POS_ECEF_TOW_TYPE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_TOW_TYPE_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_TOW_TYPE_OTHER (1)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_FIX_MODE_SHIFT) & SBP_POS_ECEF_FIX_MODE_MASK)
#define SBP_POS_ECEF_FIX_MODE_SET(flags, val)           \
  do {                                                  \
    ((flags) |= (((val) & (SBP_POS_ECEF_FIX_MODE_MASK)) \
                 << (SBP_POS_ECEF_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_ECEF_COV 0x0214
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_COV_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_COV_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_COV_FIX_MODE_SHIFT) & \
   SBP_POS_ECEF_COV_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_FIX_MODE_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_FIX_MODE_MASK)) \
                 << (SBP_POS_ECEF_COV_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_COV_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_COV_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_LLH 0x020A
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_POS_LLH_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_POS_LLH_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_POS_LLH_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_FIX_MODE_SHIFT) & SBP_POS_LLH_FIX_MODE_MASK)
#define SBP_POS_LLH_FIX_MODE_SET(flags, val)                                   \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_POS_LLH_FIX_MODE_MASK)) << (SBP_POS_LLH_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_LLH_COV 0x0211
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_COV_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_COV_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_COV_FIX_MODE_SHIFT) & SBP_POS_LLH_COV_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_FIX_MODE_SET(flags, val)           \
  do {                                                     \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_FIX_MODE_MASK)) \
                 << (SBP_POS_LLH_COV_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_COV_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_BASELINE_ECEF 0x020B
#define SBP_BASELINE_ECEF_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_BASELINE_ECEF_FIX_MODE_SHIFT) & \
   SBP_BASELINE_ECEF_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_FIX_MODE_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_BASELINE_ECEF_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_ECEF_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_ECEF_FIX_MODE_INVALID (0)
#define SBP_BASELINE_ECEF_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_ECEF_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_ECEF_FIX_MODE_FIXED_RTK (4)
#define SBP_MSG_BASELINE_NED 0x020C
#define SBP_BASELINE_NED_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_BASELINE_NED_FIX_MODE_SHIFT) & \
   SBP_BASELINE_NED_FIX_MODE_MASK)
#define SBP_BASELINE_NED_FIX_MODE_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_BASELINE_NED_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_NED_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_NED_FIX_MODE_INVALID (0)
#define SBP_BASELINE_NED_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_NED_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_NED_FIX_MODE_FIXED_RTK (4)
#define SBP_MSG_VEL_ECEF 0x020D
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                              \
    ((flags) |= (((val) & (SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_VEL_ECEF_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_VEL_ECEF_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_ECEF_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_ECEF_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_VELOCITY_MODE_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_VEL_ECEF_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_ECEF_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_VELOCITY_MODE_DEAD_RECKONING (3)
#define SBP_MSG_VEL_ECEF_COV 0x0215
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_COV_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_COV_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_ECEF_COV_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_ECEF_COV_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_COV_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_COV_VELOCITY_MODE_DEAD_RECKONING (3)
#define SBP_MSG_VEL_NED 0x020E
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_VEL_NED_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_VEL_NED_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_VEL_NED_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_NED_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_VEL_NED_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_VEL_NED_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_NED_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_NED_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_NED_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_VELOCITY_MODE_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_VEL_NED_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_NED_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_VELOCITY_MODE_DEAD_RECKONING (3)
#define SBP_MSG_VEL_NED_COV 0x0212
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_GET(flags)      \
  (((flags) >> SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SHIFT) & \
   SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_COV_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_VEL_NED_COV_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_VEL_NED_COV_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_NED_COV_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_COV_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_COV_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_NED_COV_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_NED_COV_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_VELOCITY_MODE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_VEL_NED_COV_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_NED_COV_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_COV_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_COV_VELOCITY_MODE_DEAD_RECKONING (3)
#define SBP_MSG_POS_ECEF_GNSS 0x0229
#define SBP_POS_ECEF_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_GNSS_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_GNSS_FIX_MODE_SHIFT) & \
   SBP_POS_ECEF_GNSS_FIX_MODE_MASK)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_POS_ECEF_GNSS_FIX_MODE_MASK)) \
                 << (SBP_POS_ECEF_GNSS_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_GNSS_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_ECEF_COV_GNSS 0x0234
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_COV_GNSS_FIX_MODE_SHIFT) & \
   SBP_POS_ECEF_COV_GNSS_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_GNSS_FIX_MODE_MASK)) \
                 << (SBP_POS_ECEF_COV_GNSS_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_GNSS_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_LLH_GNSS 0x022A
#define SBP_POS_LLH_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_GNSS_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_LLH_GNSS_FIX_MODE_SHIFT) & \
   SBP_POS_LLH_GNSS_FIX_MODE_MASK)
#define SBP_POS_LLH_GNSS_FIX_MODE_SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_POS_LLH_GNSS_FIX_MODE_MASK)) \
                 << (SBP_POS_LLH_GNSS_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_GNSS_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_POS_LLH_COV_GNSS 0x0231
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_LLH_COV_GNSS_FIX_MODE_SHIFT) & \
   SBP_POS_LLH_COV_GNSS_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_GNSS_FIX_MODE_MASK)) \
                 << (SBP_POS_LLH_COV_GNSS_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_COV_GNSS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_GNSS_FIX_MODE_SBAS_POSITION (6)
#define SBP_MSG_VEL_ECEF_GNSS 0x022D
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_ECEF_GNSS_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_MSG_VEL_ECEF_COV_GNSS 0x0235
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_MSG_VEL_NED_GNSS 0x022E
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_NED_GNSS_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_NED_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_VEL_NED_GNSS_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_NED_GNSS_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_MSG_VEL_NED_COV_GNSS 0x0232
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_GNSS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_MSG_VEL_BODY 0x0213
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_BODY_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_VEL_BODY_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_VEL_BODY_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_BODY_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_BODY_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_BODY_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_BODY_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_BODY_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_BODY_VELOCITY_MODE_GET(flags)      \
  (((flags) >> SBP_VEL_BODY_VELOCITY_MODE_SHIFT) & \
   SBP_VEL_BODY_VELOCITY_MODE_MASK)
#define SBP_VEL_BODY_VELOCITY_MODE_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_VEL_BODY_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_BODY_VELOCITY_MODE_SHIFT)));    \
  } while (0)

#define SBP_VEL_BODY_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_BODY_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_BODY_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_BODY_VELOCITY_MODE_DEAD_RECKONING (3)
#define SBP_MSG_AGE_CORRECTIONS 0x0210
#define SBP_MSG_GPS_TIME_DEP_A 0x0100
#define SBP_MSG_DOPS_DEP_A 0x0206
#define SBP_MSG_POS_ECEF_DEP_A 0x0200
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_ECEF_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE \
  (0)
#define SBP_POS_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_ECEF_DEP_A_FIX_MODE_SHIFT) & \
   SBP_POS_ECEF_DEP_A_FIX_MODE_MASK)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_POS_ECEF_DEP_A_FIX_MODE_MASK)) \
                 << (SBP_POS_ECEF_DEP_A_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_ECEF_DEP_A_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_ECEF_DEP_A_FIX_MODE_FLOAT_RTK (2)
#define SBP_MSG_POS_LLH_DEP_A 0x0201
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SHIFT (5u)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_GET(flags)      \
  (((flags) >> SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_LLH_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (4u)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags)      \
  (((flags) >> SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE \
  (0)
#define SBP_POS_LLH_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_MASK (0x1)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_SHIFT (3u)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_GET(flags)      \
  (((flags) >> SBP_POS_LLH_DEP_A_HEIGHT_MODE_SHIFT) & \
   SBP_POS_LLH_DEP_A_HEIGHT_MODE_MASK)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_POS_LLH_DEP_A_HEIGHT_MODE_MASK)) \
                 << (SBP_POS_LLH_DEP_A_HEIGHT_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_HEIGHT_ABOVE_WGS84_ELLIPSOID (0)
#define SBP_POS_LLH_DEP_A_HEIGHT_MODE_HEIGHT_ABOVE_MEAN_SEA_LEVEL (1)
#define SBP_POS_LLH_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_DEP_A_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_POS_LLH_DEP_A_FIX_MODE_SHIFT) & \
   SBP_POS_LLH_DEP_A_FIX_MODE_MASK)
#define SBP_POS_LLH_DEP_A_FIX_MODE_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_POS_LLH_DEP_A_FIX_MODE_MASK)) \
                 << (SBP_POS_LLH_DEP_A_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_POS_LLH_DEP_A_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_LLH_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_LLH_DEP_A_FIX_MODE_FLOAT_RTK (2)
#define SBP_MSG_BASELINE_ECEF_DEP_A 0x0202
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_GET(flags)      \
  (((flags) >> SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR \
  (1)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags)      \
  (((flags) >> SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do {                                                                 \
    ((flags) |=                                                        \
     (((val) & (SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_MASK))  \
      << (SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));     \
  } while (0)

#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE \
  (0)
#define SBP_BASELINE_ECEF_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE \
  (1)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SHIFT) & \
   SBP_BASELINE_ECEF_DEP_A_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_BASELINE_ECEF_DEP_A_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_ECEF_DEP_A_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_ECEF_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_MSG_BASELINE_NED_DEP_A 0x0203
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_GET(flags)      \
  (((flags) >> SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val)           \
  do {                                                                    \
    ((flags) |= (((val) & (SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_NED_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR \
  (1)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags)      \
  (((flags) >> SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do {                                                                \
    ((flags) |=                                                       \
     (((val) & (SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_MASK))  \
      << (SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));     \
  } while (0)

#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE \
  (0)
#define SBP_BASELINE_NED_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE \
  (1)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_BASELINE_NED_DEP_A_FIX_MODE_SHIFT) & \
   SBP_BASELINE_NED_DEP_A_FIX_MODE_MASK)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_BASELINE_NED_DEP_A_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_NED_DEP_A_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_NED_DEP_A_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_NED_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_MSG_VEL_ECEF_DEP_A 0x0204
#define SBP_MSG_VEL_NED_DEP_A 0x0205
#define SBP_MSG_BASELINE_HEADING_DEP_A 0x0207
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_GET(flags)      \
  (((flags) >> SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SET(flags, val)           \
  do {                                                                        \
    ((flags) |= (((val) & (SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR \
  (1)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_GET(flags)      \
  (((flags) >> SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do {                                                                    \
    ((flags) |=                                                           \
     (((val) & (SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_MASK))  \
      << (SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_SHIFT)));     \
  } while (0)

#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE \
  (0)
#define SBP_BASELINE_HEADING_DEP_A_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE \
  (1)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SHIFT) & \
   SBP_BASELINE_HEADING_DEP_A_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_BASELINE_HEADING_DEP_A_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_HEADING_DEP_A_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_HEADING_DEP_A_FIX_MODE_FIXED_RTK (1)
#define SBP_MSG_PROTECTION_LEVEL_DEP_A 0x0216
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK (0x7)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT (0u)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_GET(flags) \
  (((flags) >>                                                                \
    SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT) &       \
   SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SET(flags,  \
                                                                       val)    \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) &                                                                 \
       (SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK))      \
      << (SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT))); \
  } while (0)

#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_SAFE_STATE_PROTECTION_LEVEL_SHALL_NOT_BE_USED_FOR_SAFETY_CRITICAL_APPLICATION \
  (0)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_1 \
  (1)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_2 \
  (2)
#define SBP_PROTECTION_LEVEL_DEP_A_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_3 \
  (3)
#define SBP_MSG_PROTECTION_LEVEL 0x0217
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK (0x7)
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT (0u)
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT) & \
   SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)
#define SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SET(flags, val) \
  do {                                                                       \
    ((flags) |=                                                              \
     (((val) & (SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK))  \
      << (SBP_PROTECTION_LEVEL_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT)));     \
  } while (0)

#define SBP_PROTECTION_LEVEL_FIX_MODE_MASK (0x7)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SHIFT (15u)
#define SBP_PROTECTION_LEVEL_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_FIX_MODE_SHIFT) & \
   SBP_PROTECTION_LEVEL_FIX_MODE_MASK)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_FIX_MODE_MASK)) \
                 << (SBP_PROTECTION_LEVEL_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_FIX_MODE_INVALID (0)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_PROTECTION_LEVEL_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_PROTECTION_LEVEL_FIX_MODE_FLOAT_RTK (3)
#define SBP_PROTECTION_LEVEL_FIX_MODE_FIXED_RTK (4)
#define SBP_PROTECTION_LEVEL_FIX_MODE_DEAD_RECKONING (5)
#define SBP_PROTECTION_LEVEL_FIX_MODE_SBAS_POSITION (6)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SHIFT (18u)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
  do {                                                                \
    ((flags) |=                                                       \
     (((val) & (SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_MASK))  \
      << (SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_SHIFT)));     \
  } while (0)

#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_PROTECTION_LEVEL_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_MASK (0x1)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_SHIFT (20u)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_TIME_STATUS_SHIFT) & \
   SBP_PROTECTION_LEVEL_TIME_STATUS_MASK)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_TIME_STATUS_MASK)) \
                 << (SBP_PROTECTION_LEVEL_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_TIME_STATUS_GNSS_TIME_OF_VALIDITY (0)
#define SBP_PROTECTION_LEVEL_TIME_STATUS_OTHER (1)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_MASK (0x1)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_SHIFT (21u)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_VELOCITY_VALID_SHIFT) & \
   SBP_PROTECTION_LEVEL_VELOCITY_VALID_MASK)
#define SBP_PROTECTION_LEVEL_VELOCITY_VALID_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_VELOCITY_VALID_MASK)) \
                 << (SBP_PROTECTION_LEVEL_VELOCITY_VALID_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_MASK (0x1)
#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SHIFT (22u)
#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SHIFT) & \
   SBP_PROTECTION_LEVEL_ATTITUDE_VALID_MASK)
#define SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_ATTITUDE_VALID_MASK)) \
                 << (SBP_PROTECTION_LEVEL_ATTITUDE_VALID_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SHIFT (23u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_HPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SHIFT (24u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_VPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SHIFT (25u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_ATPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SHIFT (26u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_CTPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SHIFT (27u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_HVPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SHIFT (28u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_VVPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SHIFT (29u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_HOPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SHIFT (30u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_POPL_SHIFT)));    \
  } while (0)

#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_MASK (0x1)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SHIFT (31u)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_GET(flags)      \
  (((flags) >> SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SHIFT) & \
   SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_MASK)
#define SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_SAFE_STATE_ROPL_SHIFT)));    \
  } while (0)

#endif /* LIBSBP_NAVIGATION_MACROS_H */
