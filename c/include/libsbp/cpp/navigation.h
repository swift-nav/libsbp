/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_NAVIGATION_MESSAGES_H
#define LIBSBP_CPP_NAVIGATION_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * GPS Time
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
  constexpr u16 MSG_GPS_TIME = 0x0102;

  
  struct SBP_ATTR_PACKED MsgGpsTime {
    u16 wn /** GPS week number [weeks] */
    u32 tow /** GPS time of week rounded to the nearest millisecond [ms] */
    s32 ns_residual /** Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
    u8 flags /** Status flags (reserved) */
  };

  
  /**
   * GPS Time
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
  constexpr u16 MSG_GPS_TIME_GNSS = 0x0104;

  
  struct SBP_ATTR_PACKED MsgGpsTimeGnss {
    u16 wn /** GPS week number [weeks] */
    u32 tow /** GPS time of week rounded to the nearest millisecond [ms] */
    s32 ns_residual /** Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
    u8 flags /** Status flags (reserved) */
  };

  
  /**
   * UTC Time
   *
   * This message reports the Universal Coordinated Time (UTC).  Note the flags
   * which indicate the source of the UTC offset value and source of the time fix.
   */
  constexpr u16 MSG_UTC_TIME = 0x0103;

  
  struct SBP_ATTR_PACKED MsgUtcTime {
    u8 flags /** Indicates source and time validity */
    u32 tow /** GPS time of week rounded to the nearest millisecond [ms] */
    u16 year /** Year [year] */
    u8 month /** Month (range 1 .. 12) [months] */
    u8 day /** days in the month (range 1-31) [day] */
    u8 hours /** hours of day (range 0-23) [hours] */
    u8 minutes /** minutes of hour (range 0-59) [minutes] */
    u8 seconds /** seconds of minute (range 0-60) rounded down [seconds] */
    u32 ns /** nanoseconds of second (range 0-999999999) [nanoseconds] */
  };

  
  /**
   * UTC Time
   *
   * This message reports the Universal Coordinated Time (UTC).  Note the flags
   * which indicate the source of the UTC offset value and source of the time fix.
   */
  constexpr u16 MSG_UTC_TIME_GNSS = 0x0105;

  
  struct SBP_ATTR_PACKED MsgUtcTimeGnss {
    u8 flags /** Indicates source and time validity */
    u32 tow /** GPS time of week rounded to the nearest millisecond [ms] */
    u16 year /** Year [year] */
    u8 month /** Month (range 1 .. 12) [months] */
    u8 day /** days in the month (range 1-31) [day] */
    u8 hours /** hours of day (range 0-23) [hours] */
    u8 minutes /** minutes of hour (range 0-59) [minutes] */
    u8 seconds /** seconds of minute (range 0-60) rounded down [seconds] */
    u32 ns /** nanoseconds of second (range 0-999999999) [nanoseconds] */
  };

  
  /**
   * Dilution of Precision
   *
   * This dilution of precision (DOP) message describes the effect of
   * navigation satellite geometry on positional measurement
   * precision.  The flags field indicated whether the DOP reported
   * corresponds to differential or SPP solution.
   */
  constexpr u16 MSG_DOPS = 0x0208;

  
  struct SBP_ATTR_PACKED MsgDops {
    u32 tow /** GPS Time of Week [ms] */
    u16 gdop /** Geometric Dilution of Precision [0.01] */
    u16 pdop /** Position Dilution of Precision [0.01] */
    u16 tdop /** Time Dilution of Precision [0.01] */
    u16 hdop /** Horizontal Dilution of Precision [0.01] */
    u16 vdop /** Vertical Dilution of Precision [0.01] */
    u8 flags /** Indicates the position solution with which the DOPS message corresponds */
  };

  
  /**
   * Single-point position in ECEF
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
  constexpr u16 MSG_POS_ECEF = 0x0209;

  
  struct SBP_ATTR_PACKED MsgPosEcef {
    u32 tow /** GPS Time of Week [ms] */
    double x /** ECEF X coordinate [m] */
    double y /** ECEF Y coordinate [m] */
    double z /** ECEF Z coordinate [m] */
    u16 accuracy /** Position estimated standard deviation [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Single-point position in ECEF
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
  constexpr u16 MSG_POS_ECEF_COV = 0x0214;

  
  struct SBP_ATTR_PACKED MsgPosEcefCov {
    u32 tow /** GPS Time of Week [ms] */
    double x /** ECEF X coordinate [m] */
    double y /** ECEF Y coordinate [m] */
    double z /** ECEF Z coordinate [m] */
    float cov_x_x /** Estimated variance of x [m^2] */
    float cov_x_y /** Estimated covariance of x and y [m^2] */
    float cov_x_z /** Estimated covariance of x and z [m^2] */
    float cov_y_y /** Estimated variance of y [m^2] */
    float cov_y_z /** Estimated covariance of y and z [m^2] */
    float cov_z_z /** Estimated variance of z [m^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Geodetic Position
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
  constexpr u16 MSG_POS_LLH = 0x020A;

  
  struct SBP_ATTR_PACKED MsgPosLlh {
    u32 tow /** GPS Time of Week [ms] */
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height above WGS84 ellipsoid [m] */
    u16 h_accuracy /** Horizontal position estimated standard deviation [mm] */
    u16 v_accuracy /** Vertical position estimated standard deviation [mm] */
    u8 n_sats /** Number of satellites used in solution. */
    u8 flags /** Status flags */
  };

  
  /**
   * Geodetic Position
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
  constexpr u16 MSG_POS_LLH_COV = 0x0211;

  
  struct SBP_ATTR_PACKED MsgPosLlhCov {
    u32 tow /** GPS Time of Week [ms] */
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height above WGS84 ellipsoid [m] */
    float cov_n_n /** Estimated variance of northing [m^2] */
    float cov_n_e /** Covariance of northing and easting [m^2] */
    float cov_n_d /** Covariance of northing and downward measurement [m^2] */
    float cov_e_e /** Estimated variance of easting [m^2] */
    float cov_e_d /** Covariance of easting and downward measurement [m^2] */
    float cov_d_d /** Estimated variance of downward measurement [m^2] */
    u8 n_sats /** Number of satellites used in solution. */
    u8 flags /** Status flags */
  };

  
  /**
   * Baseline Position in ECEF
   *
   * This message reports the baseline solution in Earth Centered
   * Earth Fixed (ECEF) coordinates. This baseline is the relative
   * vector distance from the base station to the rover receiver. The
   * full GPS time is given by the preceding MSG_GPS_TIME with the
   * matching time-of-week (tow).
   */
  constexpr u16 MSG_BASELINE_ECEF = 0x020B;

  
  struct SBP_ATTR_PACKED MsgBaselineEcef {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Baseline ECEF X coordinate [mm] */
    s32 y /** Baseline ECEF Y coordinate [mm] */
    s32 z /** Baseline ECEF Z coordinate [mm] */
    u16 accuracy /** Position estimated standard deviation [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Baseline in NED
   *
   * This message reports the baseline solution in North East Down
   * (NED) coordinates. This baseline is the relative vector distance
   * from the base station to the rover receiver, and NED coordinate
   * system is defined at the local WGS84 tangent plane centered at the
   * base station position.  The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_BASELINE_NED = 0x020C;

  
  struct SBP_ATTR_PACKED MsgBaselineNed {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Baseline North coordinate [mm] */
    s32 e /** Baseline East coordinate [mm] */
    s32 d /** Baseline Down coordinate [mm] */
    u16 h_accuracy /** Horizontal position estimated standard deviation [mm] */
    u16 v_accuracy /** Vertical position estimated standard deviation [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Velocity in ECEF
   *
   * This message reports the velocity in Earth Centered Earth Fixed
   * (ECEF) coordinates. The full GPS time is given by the preceding
   * MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_ECEF = 0x020D;

  
  struct SBP_ATTR_PACKED MsgVelEcef {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Velocity ECEF X coordinate [mm/s] */
    s32 y /** Velocity ECEF Y coordinate [mm/s] */
    s32 z /** Velocity ECEF Z coordinate [mm/s] */
    u16 accuracy /** Velocity estimated standard deviation
 [mm/s] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Velocity in ECEF
   *
   * This message reports the velocity in Earth Centered Earth Fixed
   * (ECEF) coordinates. The full GPS time is given by the preceding
   * MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_ECEF_COV = 0x0215;

  
  struct SBP_ATTR_PACKED MsgVelEcefCov {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Velocity ECEF X coordinate [mm/s] */
    s32 y /** Velocity ECEF Y coordinate [mm/s] */
    s32 z /** Velocity ECEF Z coordinate [mm/s] */
    float cov_x_x /** Estimated variance of x [m^2/s^2] */
    float cov_x_y /** Estimated covariance of x and y [m^2/s^2] */
    float cov_x_z /** Estimated covariance of x and z [m^2/s^2] */
    float cov_y_y /** Estimated variance of y [m^2/s^2] */
    float cov_y_z /** Estimated covariance of y and z [m^2/s^2] */
    float cov_z_z /** Estimated variance of z [m^2/s^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Velocity in NED
   *
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_NED = 0x020E;

  
  struct SBP_ATTR_PACKED MsgVelNed {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Velocity North coordinate [mm/s] */
    s32 e /** Velocity East coordinate [mm/s] */
    s32 d /** Velocity Down coordinate [mm/s] */
    u16 h_accuracy /** Horizontal velocity estimated standard deviation
 [mm/s] */
    u16 v_accuracy /** Vertical velocity estimated standard deviation
 [mm/s] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Velocity in NED
   *
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
   * portion of the 3x3 covariance matrix.
   */
  constexpr u16 MSG_VEL_NED_COV = 0x0212;

  
  struct SBP_ATTR_PACKED MsgVelNedCov {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Velocity North coordinate [mm/s] */
    s32 e /** Velocity East coordinate [mm/s] */
    s32 d /** Velocity Down coordinate [mm/s] */
    float cov_n_n /** Estimated variance of northward measurement [m^2] */
    float cov_n_e /** Covariance of northward and eastward measurement [m^2] */
    float cov_n_d /** Covariance of northward and downward measurement [m^2] */
    float cov_e_e /** Estimated variance of eastward measurement [m^2] */
    float cov_e_d /** Covariance of eastward and downward measurement [m^2] */
    float cov_d_d /** Estimated variance of downward measurement [m^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Position in ECEF
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
  constexpr u16 MSG_POS_ECEF_GNSS = 0x0229;

  
  struct SBP_ATTR_PACKED MsgPosEcefGnss {
    u32 tow /** GPS Time of Week [ms] */
    double x /** ECEF X coordinate [m] */
    double y /** ECEF Y coordinate [m] */
    double z /** ECEF Z coordinate [m] */
    u16 accuracy /** Position estimated standard deviation [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Position in ECEF
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
  constexpr u16 MSG_POS_ECEF_COV_GNSS = 0x0234;

  
  struct SBP_ATTR_PACKED MsgPosEcefCovGnss {
    u32 tow /** GPS Time of Week [ms] */
    double x /** ECEF X coordinate [m] */
    double y /** ECEF Y coordinate [m] */
    double z /** ECEF Z coordinate [m] */
    float cov_x_x /** Estimated variance of x [m^2] */
    float cov_x_y /** Estimated covariance of x and y [m^2] */
    float cov_x_z /** Estimated covariance of x and z [m^2] */
    float cov_y_y /** Estimated variance of y [m^2] */
    float cov_y_z /** Estimated covariance of y and z [m^2] */
    float cov_z_z /** Estimated variance of z [m^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Geodetic Position
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
  constexpr u16 MSG_POS_LLH_GNSS = 0x022A;

  
  struct SBP_ATTR_PACKED MsgPosLlhGnss {
    u32 tow /** GPS Time of Week [ms] */
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height above WGS84 ellipsoid [m] */
    u16 h_accuracy /** Horizontal position estimated standard deviation [mm] */
    u16 v_accuracy /** Vertical position estimated standard deviation [mm] */
    u8 n_sats /** Number of satellites used in solution. */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Geodetic Position
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
  constexpr u16 MSG_POS_LLH_COV_GNSS = 0x0231;

  
  struct SBP_ATTR_PACKED MsgPosLlhCovGnss {
    u32 tow /** GPS Time of Week [ms] */
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height above WGS84 ellipsoid [m] */
    float cov_n_n /** Estimated variance of northing [m^2] */
    float cov_n_e /** Covariance of northing and easting [m^2] */
    float cov_n_d /** Covariance of northing and downward measurement [m^2] */
    float cov_e_e /** Estimated variance of easting [m^2] */
    float cov_e_d /** Covariance of easting and downward measurement [m^2] */
    float cov_d_d /** Estimated variance of downward measurement [m^2] */
    u8 n_sats /** Number of satellites used in solution. */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Velocity in ECEF
   *
   * This message reports the velocity in Earth Centered Earth Fixed
   * (ECEF) coordinates. The full GPS time is given by the preceding
   * MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_ECEF_GNSS = 0x022D;

  
  struct SBP_ATTR_PACKED MsgVelEcefGnss {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Velocity ECEF X coordinate [mm/s] */
    s32 y /** Velocity ECEF Y coordinate [mm/s] */
    s32 z /** Velocity ECEF Z coordinate [mm/s] */
    u16 accuracy /** Velocity estimated standard deviation
 [mm/s] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Velocity in ECEF
   *
   * This message reports the velocity in Earth Centered Earth Fixed
   * (ECEF) coordinates. The full GPS time is given by the preceding
   * MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_ECEF_COV_GNSS = 0x0235;

  
  struct SBP_ATTR_PACKED MsgVelEcefCovGnss {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Velocity ECEF X coordinate [mm/s] */
    s32 y /** Velocity ECEF Y coordinate [mm/s] */
    s32 z /** Velocity ECEF Z coordinate [mm/s] */
    float cov_x_x /** Estimated variance of x [m^2/s^2] */
    float cov_x_y /** Estimated covariance of x and y [m^2/s^2] */
    float cov_x_z /** Estimated covariance of x and z [m^2/s^2] */
    float cov_y_y /** Estimated variance of y [m^2/s^2] */
    float cov_y_z /** Estimated covariance of y and z [m^2/s^2] */
    float cov_z_z /** Estimated variance of z [m^2/s^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Velocity in NED
   *
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_NED_GNSS = 0x022E;

  
  struct SBP_ATTR_PACKED MsgVelNedGnss {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Velocity North coordinate [mm/s] */
    s32 e /** Velocity East coordinate [mm/s] */
    s32 d /** Velocity Down coordinate [mm/s] */
    u16 h_accuracy /** Horizontal velocity estimated standard deviation
 [mm/s] */
    u16 v_accuracy /** Vertical velocity estimated standard deviation
 [mm/s] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * GNSS-only Velocity in NED
   *
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
   * portion of the 3x3 covariance matrix.
   */
  constexpr u16 MSG_VEL_NED_COV_GNSS = 0x0232;

  
  struct SBP_ATTR_PACKED MsgVelNedCovGnss {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Velocity North coordinate [mm/s] */
    s32 e /** Velocity East coordinate [mm/s] */
    s32 d /** Velocity Down coordinate [mm/s] */
    float cov_n_n /** Estimated variance of northward measurement [m^2] */
    float cov_n_e /** Covariance of northward and eastward measurement [m^2] */
    float cov_n_d /** Covariance of northward and downward measurement [m^2] */
    float cov_e_e /** Estimated variance of eastward measurement [m^2] */
    float cov_e_d /** Covariance of eastward and downward measurement [m^2] */
    float cov_d_d /** Estimated variance of downward measurement [m^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Velocity in User Frame
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
  constexpr u16 MSG_VEL_BODY = 0x0213;

  
  struct SBP_ATTR_PACKED MsgVelBody {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Velocity in x direction [mm/s] */
    s32 y /** Velocity in y direction [mm/s] */
    s32 z /** Velocity in z direction [mm/s] */
    float cov_x_x /** Estimated variance of x [m^2] */
    float cov_x_y /** Covariance of x and y [m^2] */
    float cov_x_z /** Covariance of x and z [m^2] */
    float cov_y_y /** Estimated variance of y [m^2] */
    float cov_y_z /** Covariance of y and z [m^2] */
    float cov_z_z /** Estimated variance of z [m^2] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Age of corrections
   *
   * This message reports the Age of the corrections used for the current
   * Differential solution
   */
  constexpr u16 MSG_AGE_CORRECTIONS = 0x0210;

  
  struct SBP_ATTR_PACKED MsgAgeCorrections {
    u32 tow /** GPS Time of Week [ms] */
    u16 age /** Age of the corrections (0xFFFF indicates invalid) [deciseconds] */
  };

  
  /**
   * GPS Time (v1.0)
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
  constexpr u16 MSG_GPS_TIME_DEP_A = 0x0100;

  
  struct SBP_ATTR_PACKED MsgGpsTimeDepA {
    u16 wn /** GPS week number [weeks] */
    u32 tow /** GPS time of week rounded to the nearest millisecond [ms] */
    s32 ns_residual /** Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
    u8 flags /** Status flags (reserved) */
  };

  
  /**
   * Dilution of Precision
   *
   * This dilution of precision (DOP) message describes the effect of
   * navigation satellite geometry on positional measurement
   * precision.
   */
  constexpr u16 MSG_DOPS_DEP_A = 0x0206;

  
  struct SBP_ATTR_PACKED MsgDopsDepA {
    u32 tow /** GPS Time of Week [ms] */
    u16 gdop /** Geometric Dilution of Precision [0.01] */
    u16 pdop /** Position Dilution of Precision [0.01] */
    u16 tdop /** Time Dilution of Precision [0.01] */
    u16 hdop /** Horizontal Dilution of Precision [0.01] */
    u16 vdop /** Vertical Dilution of Precision [0.01] */
  };

  
  /**
   * Single-point position in ECEF
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
  constexpr u16 MSG_POS_ECEF_DEP_A = 0x0200;

  
  struct SBP_ATTR_PACKED MsgPosEcefDepA {
    u32 tow /** GPS Time of Week [ms] */
    double x /** ECEF X coordinate [m] */
    double y /** ECEF Y coordinate [m] */
    double z /** ECEF Z coordinate [m] */
    u16 accuracy /** Position accuracy estimate (not implemented). Defaults
to 0.
 [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Geodetic Position
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
  constexpr u16 MSG_POS_LLH_DEP_A = 0x0201;

  
  struct SBP_ATTR_PACKED MsgPosLlhDepA {
    u32 tow /** GPS Time of Week [ms] */
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height [m] */
    u16 h_accuracy /** Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
    u16 v_accuracy /** Vertical position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
    u8 n_sats /** Number of satellites used in solution. */
    u8 flags /** Status flags */
  };

  
  /**
   * Baseline Position in ECEF
   *
   * This message reports the baseline solution in Earth Centered
   * Earth Fixed (ECEF) coordinates. This baseline is the relative
   * vector distance from the base station to the rover receiver. The
   * full GPS time is given by the preceding MSG_GPS_TIME with the
   * matching time-of-week (tow).
   */
  constexpr u16 MSG_BASELINE_ECEF_DEP_A = 0x0202;

  
  struct SBP_ATTR_PACKED MsgBaselineEcefDepA {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Baseline ECEF X coordinate [mm] */
    s32 y /** Baseline ECEF Y coordinate [mm] */
    s32 z /** Baseline ECEF Z coordinate [mm] */
    u16 accuracy /** Position accuracy estimate
 [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Baseline in NED
   *
   * This message reports the baseline solution in North East Down
   * (NED) coordinates. This baseline is the relative vector distance
   * from the base station to the rover receiver, and NED coordinate
   * system is defined at the local WGS84 tangent plane centered at the
   * base station position.  The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_BASELINE_NED_DEP_A = 0x0203;

  
  struct SBP_ATTR_PACKED MsgBaselineNedDepA {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Baseline North coordinate [mm] */
    s32 e /** Baseline East coordinate [mm] */
    s32 d /** Baseline Down coordinate [mm] */
    u16 h_accuracy /** Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
    u16 v_accuracy /** Vertical position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Velocity in ECEF
   *
   * This message reports the velocity in Earth Centered Earth Fixed
   * (ECEF) coordinates. The full GPS time is given by the preceding
   * MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_ECEF_DEP_A = 0x0204;

  
  struct SBP_ATTR_PACKED MsgVelEcefDepA {
    u32 tow /** GPS Time of Week [ms] */
    s32 x /** Velocity ECEF X coordinate [mm/s] */
    s32 y /** Velocity ECEF Y coordinate [mm/s] */
    s32 z /** Velocity ECEF Z coordinate [mm/s] */
    u16 accuracy /** Velocity accuracy estimate (not implemented). Defaults
to 0.
 [mm/s] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags (reserved) */
  };

  
  /**
   * Velocity in NED
   *
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_VEL_NED_DEP_A = 0x0205;

  
  struct SBP_ATTR_PACKED MsgVelNedDepA {
    u32 tow /** GPS Time of Week [ms] */
    s32 n /** Velocity North coordinate [mm/s] */
    s32 e /** Velocity East coordinate [mm/s] */
    s32 d /** Velocity Down coordinate [mm/s] */
    u16 h_accuracy /** Horizontal velocity accuracy estimate (not
implemented). Defaults to 0.
 [mm/s] */
    u16 v_accuracy /** Vertical velocity accuracy estimate (not
implemented). Defaults to 0.
 [mm/s] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags (reserved) */
  };

  
  /**
   * Heading relative to True North
   *
   * This message reports the baseline heading pointing from the base station
   * to the rover relative to True North. The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_BASELINE_HEADING_DEP_A = 0x0207;

  
  struct SBP_ATTR_PACKED MsgBaselineHeadingDepA {
    u32 tow /** GPS Time of Week [ms] */
    u32 heading /** Heading [mdeg] */
    u8 n_sats /** Number of satellites used in solution */
    u8 flags /** Status flags */
  };

  
  /**
   * Computed Position and Protection Level
   *
   * This message reports the local vertical and horizontal protection levels
   * associated with a given LLH position solution. The full GPS time is given
   * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */
  constexpr u16 MSG_PROTECTION_LEVEL = 0x0216;

  
  struct SBP_ATTR_PACKED MsgProtectionLevel {
    u32 tow /** GPS Time of Week [ms] */
    u16 vpl /** Vertical protection level [cm] */
    u16 hpl /** Horizontal protection level [cm] */
    double lat /** Latitude [deg] */
    double lon /** Longitude [deg] */
    double height /** Height [m] */
    u8 flags /** Status flags */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_NAVIGATION_MESSAGES_H */