#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#define LIBSBP_NAVIGATION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
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
#define SBP_MSG_GPS_TIME               0x0102

	#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_GPS_TIME_FLAGS_TIME_SOURCE_SHIFT) \
                             & SBP_GPS_TIME_FLAGS_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GPS_TIME_FLAGS_TIME_SOURCE_MASK)) \
                             << (SBP_GPS_TIME_FLAGS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct {
  
  /**
* GPS week number[weeks]
   */
    u16
  wn
  ;
  /**
* GPS time of week rounded to the nearest millisecond[ms]
   */
    u32
  tow
  ;
  /**
 * Nanosecond residual of millisecond-rounded TOW (ranges
 * from -500000 to 500000)[ns]
   */
    s32
  ns_residual
  ;
  /**
* Status flags (reserved)
   */
    u8
  flags
  ;
} sbp_msg_gps_time_t;


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
#define SBP_MSG_GPS_TIME_GNSS          0x0104

	#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT) \
                             & SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)) \
                             << (SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct {
  
  /**
* GPS week number[weeks]
   */
    u16
  wn
  ;
  /**
* GPS time of week rounded to the nearest millisecond[ms]
   */
    u32
  tow
  ;
  /**
 * Nanosecond residual of millisecond-rounded TOW (ranges
 * from -500000 to 500000)[ns]
   */
    s32
  ns_residual
  ;
  /**
* Status flags (reserved)
   */
    u8
  flags
  ;
} sbp_msg_gps_time_gnss_t;


  /** UTC Time
   *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
   */
#define SBP_MSG_UTC_TIME               0x0103

	#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_FLAGS_TIME_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_FLAGS_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_FLAGS_TIME_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_FLAGS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct {
  
  /**
* Indicates source and time validity
   */
    u8
  flags
  ;
  /**
* GPS time of week rounded to the nearest millisecond[ms]
   */
    u32
  tow
  ;
  /**
* Year[year]
   */
    u16
  year
  ;
  /**
* Month (range 1 .. 12)[months]
   */
    u8
  month
  ;
  /**
* days in the month (range 1-31)[day]
   */
    u8
  day
  ;
  /**
* hours of day (range 0-23)[hours]
   */
    u8
  hours
  ;
  /**
* minutes of hour (range 0-59)[minutes]
   */
    u8
  minutes
  ;
  /**
* seconds of minute (range 0-60) rounded down[seconds]
   */
    u8
  seconds
  ;
  /**
* nanoseconds of second (range 0-999999999)[nanoseconds]
   */
    u32
  ns
  ;
} sbp_msg_utc_time_t;


  /** UTC Time
   *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
   */
#define SBP_MSG_UTC_TIME_GNSS          0x0105

	#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_GET(flags) \
                             (((flags) >> SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT) \
                             & SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)) \
                             << (SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT)));} while(0)
                             

#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct {
  
  /**
* Indicates source and time validity
   */
    u8
  flags
  ;
  /**
* GPS time of week rounded to the nearest millisecond[ms]
   */
    u32
  tow
  ;
  /**
* Year[year]
   */
    u16
  year
  ;
  /**
* Month (range 1 .. 12)[months]
   */
    u8
  month
  ;
  /**
* days in the month (range 1-31)[day]
   */
    u8
  day
  ;
  /**
* hours of day (range 0-23)[hours]
   */
    u8
  hours
  ;
  /**
* minutes of hour (range 0-59)[minutes]
   */
    u8
  minutes
  ;
  /**
* seconds of minute (range 0-60) rounded down[seconds]
   */
    u8
  seconds
  ;
  /**
* nanoseconds of second (range 0-999999999)[nanoseconds]
   */
    u32
  ns
  ;
} sbp_msg_utc_time_gnss_t;


  /** Dilution of Precision
   *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.  The flags field indicated whether the DOP reported
 * corresponds to differential or SPP solution.
   */
#define SBP_MSG_DOPS                   0x0208

	#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SHIFT (7u)
#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_DOPS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_DOPS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_DOPS_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_DOPS_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_DOPS_FLAGS_FIX_MODE_MASK)
#define SBP_DOPS_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_DOPS_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_DOPS_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_DOPS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_DOPS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_DOPS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_DOPS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_DOPS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_DOPS_FLAGS_FIX_MODE_UNDEFINED (5)
#define SBP_DOPS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Geometric Dilution of Precision[0.01]
   */
    u16
  gdop
  ;
  /**
* Position Dilution of Precision[0.01]
   */
    u16
  pdop
  ;
  /**
* Time Dilution of Precision[0.01]
   */
    u16
  tdop
  ;
  /**
* Horizontal Dilution of Precision[0.01]
   */
    u16
  hdop
  ;
  /**
* Vertical Dilution of Precision[0.01]
   */
    u16
  vdop
  ;
  /**
* Indicates the position solution with which the DOPS message corresponds
   */
    u8
  flags
  ;
} sbp_msg_dops_t;


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
#define SBP_MSG_POS_ECEF               0x0209

	#define SBP_POS_ECEF_FLAGS_TOW_TYPE_MASK (0x1)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_SHIFT (5u)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_FLAGS_TOW_TYPE_SHIFT) \
                             & SBP_POS_ECEF_FLAGS_TOW_TYPE_MASK)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_FLAGS_TOW_TYPE_MASK)) \
                             << (SBP_POS_ECEF_FLAGS_TOW_TYPE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_FLAGS_TOW_TYPE_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_OTHER (1)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* ECEF X coordinate[m]
   */
    double
  x
  ;
  /**
* ECEF Y coordinate[m]
   */
    double
  y
  ;
  /**
* ECEF Z coordinate[m]
   */
    double
  z
  ;
  /**
* Position estimated standard deviation[mm]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_ecef_t;


  /** Single-point position in ECEF
   *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. The message also
 * reports the upper triangular portion of the 3x3 covariance matrix.
 * If the receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_POS_ECEF_COV           0x0214

	#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_COV_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* ECEF X coordinate[m]
   */
    double
  x
  ;
  /**
* ECEF Y coordinate[m]
   */
    double
  y
  ;
  /**
* ECEF Z coordinate[m]
   */
    double
  z
  ;
  /**
* Estimated variance of x[m^2]
   */
    float
  cov_x_x
  ;
  /**
* Estimated covariance of x and y[m^2]
   */
    float
  cov_x_y
  ;
  /**
* Estimated covariance of x and z[m^2]
   */
    float
  cov_x_z
  ;
  /**
* Estimated variance of y[m^2]
   */
    float
  cov_y_y
  ;
  /**
* Estimated covariance of y and z[m^2]
   */
    float
  cov_y_z
  ;
  /**
* Estimated variance of z[m^2]
   */
    float
  cov_z_z
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_ecef_cov_t;


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
#define SBP_MSG_POS_LLH                0x020A

	#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height above WGS84 ellipsoid[m]
   */
    double
  height
  ;
  /**
* Horizontal position estimated standard deviation[mm]
   */
    u16
  h_accuracy
  ;
  /**
* Vertical position estimated standard deviation[mm]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution.
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_llh_t;


  /** Geodetic Position
   *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution as well as the upper triangle of the 3x3
 * covariance matrix.  The position information and Fix Mode flags should
 * follow the MSG_POS_LLH message.  Since the covariance matrix is computed
 * in the local-level North, East, Down frame, the covariance terms follow
 * with that convention. Thus, covariances are reported against the "downward"
 * measurement and care should be taken with the sign convention.
   */
#define SBP_MSG_POS_LLH_COV            0x0211

	#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) \
                             & SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                             << (SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_COV_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_COV_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height above WGS84 ellipsoid[m]
   */
    double
  height
  ;
  /**
* Estimated variance of northing[m^2]
   */
    float
  cov_n_n
  ;
  /**
* Covariance of northing and easting[m^2]
   */
    float
  cov_n_e
  ;
  /**
* Covariance of northing and downward measurement[m^2]
   */
    float
  cov_n_d
  ;
  /**
* Estimated variance of easting[m^2]
   */
    float
  cov_e_e
  ;
  /**
* Covariance of easting and downward measurement[m^2]
   */
    float
  cov_e_d
  ;
  /**
* Estimated variance of downward measurement[m^2]
   */
    float
  cov_d_d
  ;
  /**
* Number of satellites used in solution.
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_llh_cov_t;


  /** Baseline Position in ECEF
   *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
   */
#define SBP_MSG_BASELINE_ECEF          0x020B

	#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_ECEF_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_INVALID (0)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_FIXED_RTK (4)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Baseline ECEF X coordinate[mm]
   */
    s32
  x
  ;
  /**
* Baseline ECEF Y coordinate[mm]
   */
    s32
  y
  ;
  /**
* Baseline ECEF Z coordinate[mm]
   */
    s32
  z
  ;
  /**
* Position estimated standard deviation[mm]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_baseline_ecef_t;


  /** Baseline in NED
   *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_BASELINE_NED           0x020C

	#define SBP_BASELINE_NED_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_NED_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_NED_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_FLAGS_FIX_MODE_INVALID (0)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_FIXED_RTK (4)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Baseline North coordinate[mm]
   */
    s32
  n
  ;
  /**
* Baseline East coordinate[mm]
   */
    s32
  e
  ;
  /**
* Baseline Down coordinate[mm]
   */
    s32
  d
  ;
  /**
* Horizontal position estimated standard deviation[mm]
   */
    u16
  h_accuracy
  ;
  /**
* Vertical position estimated standard deviation[mm]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_baseline_ned_t;


  /** Velocity in ECEF
   *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_ECEF               0x020D

	#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity ECEF X coordinate[mm/s]
   */
    s32
  x
  ;
  /**
* Velocity ECEF Y coordinate[mm/s]
   */
    s32
  y
  ;
  /**
* Velocity ECEF Z coordinate[mm/s]
   */
    s32
  z
  ;
  /**
 * Velocity estimated standard deviation[mm/s]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ecef_t;


  /** Velocity in ECEF
   *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_ECEF_COV           0x0215

	#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity ECEF X coordinate[mm/s]
   */
    s32
  x
  ;
  /**
* Velocity ECEF Y coordinate[mm/s]
   */
    s32
  y
  ;
  /**
* Velocity ECEF Z coordinate[mm/s]
   */
    s32
  z
  ;
  /**
* Estimated variance of x[m^2/s^2]
   */
    float
  cov_x_x
  ;
  /**
* Estimated covariance of x and y[m^2/s^2]
   */
    float
  cov_x_y
  ;
  /**
* Estimated covariance of x and z[m^2/s^2]
   */
    float
  cov_x_z
  ;
  /**
* Estimated variance of y[m^2/s^2]
   */
    float
  cov_y_y
  ;
  /**
* Estimated covariance of y and z[m^2/s^2]
   */
    float
  cov_y_z
  ;
  /**
* Estimated variance of z[m^2/s^2]
   */
    float
  cov_z_z
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ecef_cov_t;


  /** Velocity in NED
   *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_NED                0x020E

	#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity North coordinate[mm/s]
   */
    s32
  n
  ;
  /**
* Velocity East coordinate[mm/s]
   */
    s32
  e
  ;
  /**
* Velocity Down coordinate[mm/s]
   */
    s32
  d
  ;
  /**
 * Horizontal velocity estimated standard deviation[mm/s]
   */
    u16
  h_accuracy
  ;
  /**
 * Vertical velocity estimated standard deviation[mm/s]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ned_t;


  /** Velocity in NED
   *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
 * portion of the 3x3 covariance matrix.
   */
#define SBP_MSG_VEL_NED_COV            0x0212

	#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) \
                             & SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                             << (SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity North coordinate[mm/s]
   */
    s32
  n
  ;
  /**
* Velocity East coordinate[mm/s]
   */
    s32
  e
  ;
  /**
* Velocity Down coordinate[mm/s]
   */
    s32
  d
  ;
  /**
* Estimated variance of northward measurement[m^2]
   */
    float
  cov_n_n
  ;
  /**
* Covariance of northward and eastward measurement[m^2]
   */
    float
  cov_n_e
  ;
  /**
* Covariance of northward and downward measurement[m^2]
   */
    float
  cov_n_d
  ;
  /**
* Estimated variance of eastward measurement[m^2]
   */
    float
  cov_e_e
  ;
  /**
* Covariance of eastward and downward measurement[m^2]
   */
    float
  cov_e_d
  ;
  /**
* Estimated variance of downward measurement[m^2]
   */
    float
  cov_d_d
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ned_cov_t;


  /** GNSS-only Position in ECEF
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
#define SBP_MSG_POS_ECEF_GNSS          0x0229

	#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* ECEF X coordinate[m]
   */
    double
  x
  ;
  /**
* ECEF Y coordinate[m]
   */
    double
  y
  ;
  /**
* ECEF Z coordinate[m]
   */
    double
  z
  ;
  /**
* Position estimated standard deviation[mm]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_ecef_gnss_t;


  /** GNSS-only Position in ECEF
   *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. The message also
 * reports the upper triangular portion of the 3x3 covariance matrix.
 * If the receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_POS_ECEF_COV_GNSS      0x0234

	#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* ECEF X coordinate[m]
   */
    double
  x
  ;
  /**
* ECEF Y coordinate[m]
   */
    double
  y
  ;
  /**
* ECEF Z coordinate[m]
   */
    double
  z
  ;
  /**
* Estimated variance of x[m^2]
   */
    float
  cov_x_x
  ;
  /**
* Estimated covariance of x and y[m^2]
   */
    float
  cov_x_y
  ;
  /**
* Estimated covariance of x and z[m^2]
   */
    float
  cov_x_z
  ;
  /**
* Estimated variance of y[m^2]
   */
    float
  cov_y_y
  ;
  /**
* Estimated covariance of y and z[m^2]
   */
    float
  cov_y_z
  ;
  /**
* Estimated variance of z[m^2]
   */
    float
  cov_z_z
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_ecef_cov_gnss_t;


  /** GNSS-only Geodetic Position
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
#define SBP_MSG_POS_LLH_GNSS           0x022A

	#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height above WGS84 ellipsoid[m]
   */
    double
  height
  ;
  /**
* Horizontal position estimated standard deviation[mm]
   */
    u16
  h_accuracy
  ;
  /**
* Vertical position estimated standard deviation[mm]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution.
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_llh_gnss_t;


  /** GNSS-only Geodetic Position
   *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution as well as the upper triangle of the 3x3
 * covariance matrix.  The position information and Fix Mode flags should
 * follow the MSG_POS_LLH message.  Since the covariance matrix is computed
 * in the local-level North, East, Down frame, the covariance terms follow
 * with that convention. Thus, covariances are reported against the "downward"
 * measurement and care should be taken with the sign convention.
   */
#define SBP_MSG_POS_LLH_COV_GNSS       0x0231

	#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height above WGS84 ellipsoid[m]
   */
    double
  height
  ;
  /**
* Estimated variance of northing[m^2]
   */
    float
  cov_n_n
  ;
  /**
* Covariance of northing and easting[m^2]
   */
    float
  cov_n_e
  ;
  /**
* Covariance of northing and downward measurement[m^2]
   */
    float
  cov_n_d
  ;
  /**
* Estimated variance of easting[m^2]
   */
    float
  cov_e_e
  ;
  /**
* Covariance of easting and downward measurement[m^2]
   */
    float
  cov_e_d
  ;
  /**
* Estimated variance of downward measurement[m^2]
   */
    float
  cov_d_d
  ;
  /**
* Number of satellites used in solution.
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_llh_cov_gnss_t;


  /** GNSS-only Velocity in ECEF
   *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_ECEF_GNSS          0x022D

	#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity ECEF X coordinate[mm/s]
   */
    s32
  x
  ;
  /**
* Velocity ECEF Y coordinate[mm/s]
   */
    s32
  y
  ;
  /**
* Velocity ECEF Z coordinate[mm/s]
   */
    s32
  z
  ;
  /**
 * Velocity estimated standard deviation[mm/s]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ecef_gnss_t;


  /** GNSS-only Velocity in ECEF
   *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_ECEF_COV_GNSS      0x0235

	#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity ECEF X coordinate[mm/s]
   */
    s32
  x
  ;
  /**
* Velocity ECEF Y coordinate[mm/s]
   */
    s32
  y
  ;
  /**
* Velocity ECEF Z coordinate[mm/s]
   */
    s32
  z
  ;
  /**
* Estimated variance of x[m^2/s^2]
   */
    float
  cov_x_x
  ;
  /**
* Estimated covariance of x and y[m^2/s^2]
   */
    float
  cov_x_y
  ;
  /**
* Estimated covariance of x and z[m^2/s^2]
   */
    float
  cov_x_z
  ;
  /**
* Estimated variance of y[m^2/s^2]
   */
    float
  cov_y_y
  ;
  /**
* Estimated covariance of y and z[m^2/s^2]
   */
    float
  cov_y_z
  ;
  /**
* Estimated variance of z[m^2/s^2]
   */
    float
  cov_z_z
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ecef_cov_gnss_t;


  /** GNSS-only Velocity in NED
   *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_NED_GNSS           0x022E

	#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity North coordinate[mm/s]
   */
    s32
  n
  ;
  /**
* Velocity East coordinate[mm/s]
   */
    s32
  e
  ;
  /**
* Velocity Down coordinate[mm/s]
   */
    s32
  d
  ;
  /**
 * Horizontal velocity estimated standard deviation[mm/s]
   */
    u16
  h_accuracy
  ;
  /**
 * Vertical velocity estimated standard deviation[mm/s]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ned_gnss_t;


  /** GNSS-only Velocity in NED
   *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
 * portion of the 3x3 covariance matrix.
   */
#define SBP_MSG_VEL_NED_COV_GNSS       0x0232

	#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity North coordinate[mm/s]
   */
    s32
  n
  ;
  /**
* Velocity East coordinate[mm/s]
   */
    s32
  e
  ;
  /**
* Velocity Down coordinate[mm/s]
   */
    s32
  d
  ;
  /**
* Estimated variance of northward measurement[m^2]
   */
    float
  cov_n_n
  ;
  /**
* Covariance of northward and eastward measurement[m^2]
   */
    float
  cov_n_e
  ;
  /**
* Covariance of northward and downward measurement[m^2]
   */
    float
  cov_n_d
  ;
  /**
* Estimated variance of eastward measurement[m^2]
   */
    float
  cov_e_e
  ;
  /**
* Covariance of eastward and downward measurement[m^2]
   */
    float
  cov_e_d
  ;
  /**
* Estimated variance of downward measurement[m^2]
   */
    float
  cov_d_d
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_ned_cov_gnss_t;


  /** Velocity in User Frame
   *
 * This message reports the velocity in the Vehicle Body Frame. By convention,
 * the x-axis should point out the nose of the vehicle and represent the forward
 * direction, while as the y-axis should point out the right hand side of the vehicle.
 * Since this is a right handed system, z should point out the bottom of the vehicle.
 * The orientation and origin of the Vehicle Body Frame are specified via the device settings.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow). This message is only produced by inertial versions of Swift
 * products and is not available from Piksi Multi or Duro.
   */
#define SBP_MSG_VEL_BODY               0x0213

	#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_GET(flags) \
                             (((flags) >> SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SHIFT) \
                             & SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MASK)) \
                             << (SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SHIFT)));} while(0)
                             

#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity in x direction[mm/s]
   */
    s32
  x
  ;
  /**
* Velocity in y direction[mm/s]
   */
    s32
  y
  ;
  /**
* Velocity in z direction[mm/s]
   */
    s32
  z
  ;
  /**
* Estimated variance of x[m^2]
   */
    float
  cov_x_x
  ;
  /**
* Covariance of x and y[m^2]
   */
    float
  cov_x_y
  ;
  /**
* Covariance of x and z[m^2]
   */
    float
  cov_x_z
  ;
  /**
* Estimated variance of y[m^2]
   */
    float
  cov_y_y
  ;
  /**
* Covariance of y and z[m^2]
   */
    float
  cov_y_z
  ;
  /**
* Estimated variance of z[m^2]
   */
    float
  cov_z_z
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_vel_body_t;


  /** Age of corrections
   *
 * This message reports the Age of the corrections used for the current
 * Differential solution
   */
#define SBP_MSG_AGE_CORRECTIONS        0x0210

typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Age of the corrections (0xFFFF indicates invalid)[deciseconds]
   */
    u16
  age
  ;
} sbp_msg_age_corrections_t;


  /** GPS Time (v1.0)
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
#define SBP_MSG_GPS_TIME_DEP_A         0x0100

typedef struct {
  
  /**
* GPS week number[weeks]
   */
    u16
  wn
  ;
  /**
* GPS time of week rounded to the nearest millisecond[ms]
   */
    u32
  tow
  ;
  /**
 * Nanosecond residual of millisecond-rounded TOW (ranges
 * from -500000 to 500000)[ns]
   */
    s32
  ns_residual
  ;
  /**
* Status flags (reserved)
   */
    u8
  flags
  ;
} sbp_msg_gps_time_dep_a_t;


  /** Dilution of Precision
   *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.
   */
#define SBP_MSG_DOPS_DEP_A             0x0206

typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Geometric Dilution of Precision[0.01]
   */
    u16
  gdop
  ;
  /**
* Position Dilution of Precision[0.01]
   */
    u16
  pdop
  ;
  /**
* Time Dilution of Precision[0.01]
   */
    u16
  tdop
  ;
  /**
* Horizontal Dilution of Precision[0.01]
   */
    u16
  hdop
  ;
  /**
* Vertical Dilution of Precision[0.01]
   */
    u16
  vdop
  ;
} sbp_msg_dops_dep_a_t;


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
#define SBP_MSG_POS_ECEF_DEP_A         0x0200

	#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (2)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* ECEF X coordinate[m]
   */
    double
  x
  ;
  /**
* ECEF Y coordinate[m]
   */
    double
  y
  ;
  /**
* ECEF Z coordinate[m]
   */
    double
  z
  ;
  /**
 * Position accuracy estimate (not implemented). Defaults
 * to 0.[mm]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_ecef_dep_a_t;


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
#define SBP_MSG_POS_LLH_DEP_A          0x0201

	#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (5u)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (4u)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_MASK (0x1)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SHIFT (3u)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SHIFT) \
                             & SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_MASK)) \
                             << (SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_HEIGHT_ABOVE_WGS84_ELLIPSOID (0)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_HEIGHT_ABOVE_MEAN_SEA_LEVEL (1)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (2)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height[m]
   */
    double
  height
  ;
  /**
 * Horizontal position accuracy estimate (not
 * implemented). Defaults to 0.[mm]
   */
    u16
  h_accuracy
  ;
  /**
 * Vertical position accuracy estimate (not
 * implemented). Defaults to 0.[mm]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution.
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_pos_llh_dep_a_t;


  /** Baseline Position in ECEF
   *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
   */
#define SBP_MSG_BASELINE_ECEF_DEP_A    0x0202

	#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Baseline ECEF X coordinate[mm]
   */
    s32
  x
  ;
  /**
* Baseline ECEF Y coordinate[mm]
   */
    s32
  y
  ;
  /**
* Baseline ECEF Z coordinate[mm]
   */
    s32
  z
  ;
  /**
 * Position accuracy estimate[mm]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_baseline_ecef_dep_a_t;


  /** Baseline in NED
   *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_BASELINE_NED_DEP_A     0x0203

	#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Baseline North coordinate[mm]
   */
    s32
  n
  ;
  /**
* Baseline East coordinate[mm]
   */
    s32
  e
  ;
  /**
* Baseline Down coordinate[mm]
   */
    s32
  d
  ;
  /**
 * Horizontal position accuracy estimate (not
 * implemented). Defaults to 0.[mm]
   */
    u16
  h_accuracy
  ;
  /**
 * Vertical position accuracy estimate (not
 * implemented). Defaults to 0.[mm]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_baseline_ned_dep_a_t;


  /** Velocity in ECEF
   *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_ECEF_DEP_A         0x0204

typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity ECEF X coordinate[mm/s]
   */
    s32
  x
  ;
  /**
* Velocity ECEF Y coordinate[mm/s]
   */
    s32
  y
  ;
  /**
* Velocity ECEF Z coordinate[mm/s]
   */
    s32
  z
  ;
  /**
 * Velocity accuracy estimate (not implemented). Defaults
 * to 0.[mm/s]
   */
    u16
  accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags (reserved)
   */
    u8
  flags
  ;
} sbp_msg_vel_ecef_dep_a_t;


  /** Velocity in NED
   *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_VEL_NED_DEP_A          0x0205

typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Velocity North coordinate[mm/s]
   */
    s32
  n
  ;
  /**
* Velocity East coordinate[mm/s]
   */
    s32
  e
  ;
  /**
* Velocity Down coordinate[mm/s]
   */
    s32
  d
  ;
  /**
 * Horizontal velocity accuracy estimate (not
 * implemented). Defaults to 0.[mm/s]
   */
    u16
  h_accuracy
  ;
  /**
 * Vertical velocity accuracy estimate (not
 * implemented). Defaults to 0.[mm/s]
   */
    u16
  v_accuracy
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags (reserved)
   */
    u8
  flags
  ;
} sbp_msg_vel_ned_dep_a_t;


  /** Heading relative to True North
   *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_BASELINE_HEADING_DEP_A 0x0207

	#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) \
                             & SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                             << (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) \
                             & SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                             << (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Heading[mdeg]
   */
    u32
  heading
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_baseline_heading_dep_a_t;


  /** Computed Position and Protection Level
   *
 * This message reports the local vertical and horizontal protection levels
 * associated with a given LLH position solution. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
#define SBP_MSG_PROTECTION_LEVEL       0x0216

	#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK (0x7)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT (0u)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_GET(flags) \
                             (((flags) >> SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT) \
                             & SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)) \
                             << (SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT)));} while(0)
                             

#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SAFE_STATE_PROTECTION_LEVEL_SHALL_NOT_BE_USED_FOR_SAFETY_CRITICAL_APPLICATION (0)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_1 (1)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_2 (2)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_3 (3)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Vertical protection level[cm]
   */
    u16
  vpl
  ;
  /**
* Horizontal protection level[cm]
   */
    u16
  hpl
  ;
  /**
* Latitude[deg]
   */
    double
  lat
  ;
  /**
* Longitude[deg]
   */
    double
  lon
  ;
  /**
* Height[m]
   */
    double
  height
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_protection_level_t;



#include <libsbp/unpacked/navigation_operators.h>
#include <libsbp/unpacked/navigation_packers.h>

#endif /* LIBSBP_NAVIGATION_MESSAGES_H */
