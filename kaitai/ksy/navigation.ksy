# Geodetic navigation messages reporting GPS time, position, velocity, and
# baseline position solutions. For position solutions, these messages define
# several different position solutions: single-point (SPP), RTK, and pseudo-
# absolute position solutions.  The SPP is the standalone, absolute GPS position
# solution using only a single receiver. The RTK solution is the differential GPS
# solution, which can use either a fixed/integer or floating carrier phase
# ambiguity. The pseudo-absolute position solution uses a user-provided, well-
# surveyed base station position (if available) and the RTK solution in tandem.
# When the inertial navigation mode indicates that the IMU is used, all messages
# are reported in the vehicle body frame as defined by device settings.  By
# default, the vehicle body frame is configured to be coincident with the antenna
# phase center.  When there is no inertial navigation, the solution will be
# reported at the phase center of the antenna. There is no inertial navigation
# capability on Piksi Multi or Duro.  The tow field, when valid, is most often the
# Time of Measurement. When this is the case, the 5th bit of flags is set to the
# default value of 0. When this is not the case, the tow may be a time of arrival
# or a local system timestamp, irrespective of the time reference (GPS Week or
# else), but not a Time of Measurement.

# Automatically generated from spec/yaml/swiftnav/sbp/navigation.yaml with generate.py.
# Please do not hand edit!

meta:
  id: navigation
  endian: le
  imports: [  ]

types:

  msg_gps_time:
    doc: |
      This message reports the GPS time, representing the time since the GPS
      epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
      and seconds of the week. The weeks begin at the Saturday/Sunday
      transition. GPS week 0 began at the beginning of the GPS time scale.

      Within each week number, the GPS time of the week is between between 0
      and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
      leap seconds, and as of now, has a small offset from UTC. In a message
      stream, this message precedes a set of other navigation messages
      referenced to the same time (but lacking the ns field) and indicates a
      more precise time of these messages.
    seq:
      - id: wn
        doc: |
          GPS week number
        type: u2
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: ns_residual
        doc: |
          Nanosecond residual of millisecond-rounded TOW (ranges from -500000
          to 500000)
        type: s4
      - id: flags
        doc: |
          Status flags (reserved)
        type: u1
  
  msg_gps_time_gnss:
    doc: |
      This message reports the GPS time, representing the time since the GPS
      epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
      and seconds of the week. The weeks begin at the Saturday/Sunday
      transition. GPS week 0 began at the beginning of the GPS time scale.

      Within each week number, the GPS time of the week is between between 0
      and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
      leap seconds, and as of now, has a small offset from UTC. In a message
      stream, this message precedes a set of other navigation messages
      referenced to the same time (but lacking the ns field) and indicates a
      more precise time of these messages.
    seq:
      - id: wn
        doc: |
          GPS week number
        type: u2
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: ns_residual
        doc: |
          Nanosecond residual of millisecond-rounded TOW (ranges from -500000
          to 500000)
        type: s4
      - id: flags
        doc: |
          Status flags (reserved)
        type: u1
  
  msg_utc_time:
    doc: |
      This message reports the Universal Coordinated Time (UTC).  Note the
      flags which indicate the source of the UTC offset value and source of
      the time fix.
    seq:
      - id: flags
        doc: |
          Indicates source and time validity
        type: u1
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: year
        doc: |
          Year
        type: u2
      - id: month
        doc: |
          Month (range 1 .. 12)
        type: u1
      - id: day
        doc: |
          days in the month (range 1-31)
        type: u1
      - id: hours
        doc: |
          hours of day (range 0-23)
        type: u1
      - id: minutes
        doc: |
          minutes of hour (range 0-59)
        type: u1
      - id: seconds
        doc: |
          seconds of minute (range 0-60) rounded down
        type: u1
      - id: ns
        doc: |
          nanoseconds of second (range 0-999999999)
        type: u4
  
  msg_utc_time_gnss:
    doc: |
      This message reports the Universal Coordinated Time (UTC).  Note the
      flags which indicate the source of the UTC offset value and source of
      the time fix.
    seq:
      - id: flags
        doc: |
          Indicates source and time validity
        type: u1
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: year
        doc: |
          Year
        type: u2
      - id: month
        doc: |
          Month (range 1 .. 12)
        type: u1
      - id: day
        doc: |
          days in the month (range 1-31)
        type: u1
      - id: hours
        doc: |
          hours of day (range 0-23)
        type: u1
      - id: minutes
        doc: |
          minutes of hour (range 0-59)
        type: u1
      - id: seconds
        doc: |
          seconds of minute (range 0-60) rounded down
        type: u1
      - id: ns
        doc: |
          nanoseconds of second (range 0-999999999)
        type: u4
  
  msg_dops:
    doc: |
      This dilution of precision (DOP) message describes the effect of
      navigation satellite geometry on positional measurement precision.  The
      flags field indicated whether the DOP reported corresponds to
      differential or SPP solution.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: gdop
        doc: |
          Geometric Dilution of Precision
        type: u2
      - id: pdop
        doc: |
          Position Dilution of Precision
        type: u2
      - id: tdop
        doc: |
          Time Dilution of Precision
        type: u2
      - id: hdop
        doc: |
          Horizontal Dilution of Precision
        type: u2
      - id: vdop
        doc: |
          Vertical Dilution of Precision
        type: u2
      - id: flags
        doc: |
          Indicates the position solution with which the DOPS message
          corresponds
        type: u1
  
  msg_pos_ecef:
    doc: |
      The position solution message reports absolute Earth Centered Earth
      Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
      RTK) of the position solution. If the rover receiver knows the surveyed
      position of the base station and has an RTK solution, this reports a
      pseudo-absolute position solution using the base station position and
      the rover's RTK baseline vector. The full GPS time is given by the
      preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          ECEF X coordinate
        type: f8
      - id: y
        doc: |
          ECEF Y coordinate
        type: f8
      - id: z
        doc: |
          ECEF Z coordinate
        type: f8
      - id: accuracy
        doc: |
          Position estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_ecef_cov:
    doc: |
      The position solution message reports absolute Earth Centered Earth
      Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
      RTK) of the position solution. The message also reports the upper
      triangular portion of the 3x3 covariance matrix. If the receiver knows
      the surveyed position of the base station and has an RTK solution, this
      reports a pseudo-absolute position solution using the base station
      position and the rover's RTK baseline vector. The full GPS time is given
      by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          ECEF X coordinate
        type: f8
      - id: y
        doc: |
          ECEF Y coordinate
        type: f8
      - id: z
        doc: |
          ECEF Z coordinate
        type: f8
      - id: cov_x_x
        doc: |
          Estimated variance of x
        type: f4
      - id: cov_x_y
        doc: |
          Estimated covariance of x and y
        type: f4
      - id: cov_x_z
        doc: |
          Estimated covariance of x and z
        type: f4
      - id: cov_y_y
        doc: |
          Estimated variance of y
        type: f4
      - id: cov_y_z
        doc: |
          Estimated covariance of y and z
        type: f4
      - id: cov_z_z
        doc: |
          Estimated variance of z
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_llh:
    doc: |
      This position solution message reports the absolute geodetic coordinates
      and the status (single point vs pseudo-absolute RTK) of the position
      solution. If the rover receiver knows the surveyed position of the base
      station and has an RTK solution, this reports a pseudo-absolute position
      solution using the base station position and the rover's RTK baseline
      vector. The full GPS time is given by the preceding MSG_GPS_TIME with
      the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height above WGS84 ellipsoid
        type: f8
      - id: h_accuracy
        doc: |
          Horizontal position estimated standard deviation
        type: u2
      - id: v_accuracy
        doc: |
          Vertical position estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution.
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_llh_cov:
    doc: |
      This position solution message reports the absolute geodetic coordinates
      and the status (single point vs pseudo-absolute RTK) of the position
      solution as well as the upper triangle of the 3x3 covariance matrix.
      The position information and Fix Mode flags follow the MSG_POS_LLH
      message.  Since the covariance matrix is computed in the local-level
      North, East, Down frame, the covariance terms follow that convention.
      Thus, covariances are reported against the "downward" measurement and
      care should be taken with the sign convention.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height above WGS84 ellipsoid
        type: f8
      - id: cov_n_n
        doc: |
          Estimated variance of northing
        type: f4
      - id: cov_n_e
        doc: |
          Covariance of northing and easting
        type: f4
      - id: cov_n_d
        doc: |
          Covariance of northing and downward measurement
        type: f4
      - id: cov_e_e
        doc: |
          Estimated variance of easting
        type: f4
      - id: cov_e_d
        doc: |
          Covariance of easting and downward measurement
        type: f4
      - id: cov_d_d
        doc: |
          Estimated variance of downward measurement
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution.
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  estimated_horizontal_error_ellipse:
    seq:
      - id: semi_major
        doc: |
          The semi major axis of the estimated horizontal error ellipse at the
          user-configured confidence level; zero implies invalid.
        type: f4
      - id: semi_minor
        doc: |
          The semi minor axis of the estimated horizontal error ellipse at the
          user-configured confidence level; zero implies invalid.
        type: f4
      - id: orientation
        doc: |
          The orientation of the semi major axis of the estimated horizontal
          error ellipse with respect to North.
        type: f4
  
  msg_pos_llh_acc:
    doc: |
      This position solution message reports the absolute geodetic coordinates
      and the status (single point vs pseudo-absolute RTK) of the position
      solution as well as the estimated horizontal, vertical, cross-track and
      along-track errors.  The position information and Fix Mode flags  follow
      the MSG_POS_LLH message. Since the covariance matrix is computed in the
      local-level North, East, Down frame, the estimated error terms follow
      that convention.

      The estimated errors are reported at a user-configurable confidence
      level. The user-configured percentile is encoded in the percentile
      field.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height above WGS84 ellipsoid
        type: f8
      - id: orthometric_height
        doc: |
          Height above the geoid (i.e. height above mean sea level). See
          confidence_and_geoid for geoid model used.
        type: f8
      - id: h_accuracy
        doc: |
          Estimated horizontal error at the user-configured confidence level;
          zero implies invalid.
        type: f4
      - id: v_accuracy
        doc: |
          Estimated vertical error at the user-configured confidence level;
          zero implies invalid.
        type: f4
      - id: ct_accuracy
        doc: |
          Estimated cross-track error at the user-configured confidence level;
          zero implies invalid.
        type: f4
      - id: at_accuracy
        doc: |
          Estimated along-track error at the user-configured confidence level;
          zero implies invalid.
        type: f4
      - id: h_ellipse
        doc: |
          The estimated horizontal error ellipse at the user-configured
          confidence level.
        type: estimated_horizontal_error_ellipse
      - id: confidence_and_geoid
        doc: |
          The lower bits describe the configured confidence level for the
          estimated position error. The middle bits describe the geoid model
          used to calculate the orthometric height.
        type: u1
      - id: n_sats
        doc: |
          Number of satellites used in solution.
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_baseline_ecef:
    doc: |
      This message reports the baseline solution in Earth Centered Earth Fixed
      (ECEF) coordinates. This baseline is the relative vector distance from
      the base station to the rover receiver. The full GPS time is given by
      the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Baseline ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Baseline ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Baseline ECEF Z coordinate
        type: s4
      - id: accuracy
        doc: |
          Position estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_baseline_ned:
    doc: |
      This message reports the baseline solution in North East Down (NED)
      coordinates. This baseline is the relative vector distance from the base
      station to the rover receiver, and NED coordinate system is defined at
      the local WGS84 tangent plane centered at the base station position.
      The full GPS time is given by the preceding MSG_GPS_TIME with the
      matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Baseline North coordinate
        type: s4
      - id: e
        doc: |
          Baseline East coordinate
        type: s4
      - id: d
        doc: |
          Baseline Down coordinate
        type: s4
      - id: h_accuracy
        doc: |
          Horizontal position estimated standard deviation
        type: u2
      - id: v_accuracy
        doc: |
          Vertical position estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ecef:
    doc: |
      This message reports the velocity in Earth Centered Earth Fixed (ECEF)
      coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
      with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Velocity ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Velocity ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Velocity ECEF Z coordinate
        type: s4
      - id: accuracy
        doc: |
          Velocity estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ecef_cov:
    doc: |
      This message reports the velocity in Earth Centered Earth Fixed (ECEF)
      coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
      with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Velocity ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Velocity ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Velocity ECEF Z coordinate
        type: s4
      - id: cov_x_x
        doc: |
          Estimated variance of x
        type: f4
      - id: cov_x_y
        doc: |
          Estimated covariance of x and y
        type: f4
      - id: cov_x_z
        doc: |
          Estimated covariance of x and z
        type: f4
      - id: cov_y_y
        doc: |
          Estimated variance of y
        type: f4
      - id: cov_y_z
        doc: |
          Estimated covariance of y and z
        type: f4
      - id: cov_z_z
        doc: |
          Estimated variance of z
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ned:
    doc: |
      This message reports the velocity in local North East Down (NED)
      coordinates. The NED coordinate system is defined as the local WGS84
      tangent plane centered at the current position. The full GPS time is
      given by the preceding MSG_GPS_TIME with the matching time-of-week
      (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Velocity North coordinate
        type: s4
      - id: e
        doc: |
          Velocity East coordinate
        type: s4
      - id: d
        doc: |
          Velocity Down coordinate
        type: s4
      - id: h_accuracy
        doc: |
          Horizontal velocity estimated standard deviation
        type: u2
      - id: v_accuracy
        doc: |
          Vertical velocity estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ned_cov:
    doc: |
      This message reports the velocity in local North East Down (NED)
      coordinates. The NED coordinate system is defined as the local WGS84
      tangent plane centered at the current position. The full GPS time is
      given by the preceding MSG_GPS_TIME with the matching time-of-week
      (tow). This message is similar to the MSG_VEL_NED, but it includes the
      upper triangular portion of the 3x3 covariance matrix.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Velocity North coordinate
        type: s4
      - id: e
        doc: |
          Velocity East coordinate
        type: s4
      - id: d
        doc: |
          Velocity Down coordinate
        type: s4
      - id: cov_n_n
        doc: |
          Estimated variance of northward measurement
        type: f4
      - id: cov_n_e
        doc: |
          Covariance of northward and eastward measurement
        type: f4
      - id: cov_n_d
        doc: |
          Covariance of northward and downward measurement
        type: f4
      - id: cov_e_e
        doc: |
          Estimated variance of eastward measurement
        type: f4
      - id: cov_e_d
        doc: |
          Covariance of eastward and downward measurement
        type: f4
      - id: cov_d_d
        doc: |
          Estimated variance of downward measurement
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_ecef_gnss:
    doc: |
      The position solution message reports absolute Earth Centered Earth
      Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
      RTK) of the position solution. If the rover receiver knows the surveyed
      position of the base station and has an RTK solution, this reports a
      pseudo-absolute position solution using the base station position and
      the rover's RTK baseline vector. The full GPS time is given by the
      preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          ECEF X coordinate
        type: f8
      - id: y
        doc: |
          ECEF Y coordinate
        type: f8
      - id: z
        doc: |
          ECEF Z coordinate
        type: f8
      - id: accuracy
        doc: |
          Position estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_ecef_cov_gnss:
    doc: |
      The position solution message reports absolute Earth Centered Earth
      Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
      RTK) of the position solution. The message also reports the upper
      triangular portion of the 3x3 covariance matrix. If the receiver knows
      the surveyed position of the base station and has an RTK solution, this
      reports a pseudo-absolute position solution using the base station
      position and the rover's RTK baseline vector. The full GPS time is given
      by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          ECEF X coordinate
        type: f8
      - id: y
        doc: |
          ECEF Y coordinate
        type: f8
      - id: z
        doc: |
          ECEF Z coordinate
        type: f8
      - id: cov_x_x
        doc: |
          Estimated variance of x
        type: f4
      - id: cov_x_y
        doc: |
          Estimated covariance of x and y
        type: f4
      - id: cov_x_z
        doc: |
          Estimated covariance of x and z
        type: f4
      - id: cov_y_y
        doc: |
          Estimated variance of y
        type: f4
      - id: cov_y_z
        doc: |
          Estimated covariance of y and z
        type: f4
      - id: cov_z_z
        doc: |
          Estimated variance of z
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_llh_gnss:
    doc: |
      This position solution message reports the absolute geodetic coordinates
      and the status (single point vs pseudo-absolute RTK) of the position
      solution. If the rover receiver knows the surveyed position of the base
      station and has an RTK solution, this reports a pseudo-absolute position
      solution using the base station position and the rover's RTK baseline
      vector. The full GPS time is given by the preceding MSG_GPS_TIME with
      the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height above WGS84 ellipsoid
        type: f8
      - id: h_accuracy
        doc: |
          Horizontal position estimated standard deviation
        type: u2
      - id: v_accuracy
        doc: |
          Vertical position estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution.
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_llh_cov_gnss:
    doc: |
      This position solution message reports the absolute geodetic coordinates
      and the status (single point vs pseudo-absolute RTK) of the position
      solution as well as the upper triangle of the 3x3 covariance matrix.
      The position information and Fix Mode flags should follow the
      MSG_POS_LLH message.  Since the covariance matrix is computed in the
      local-level North, East, Down frame, the covariance terms follow with
      that convention. Thus, covariances are reported against the "downward"
      measurement and care should be taken with the sign convention.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height above WGS84 ellipsoid
        type: f8
      - id: cov_n_n
        doc: |
          Estimated variance of northing
        type: f4
      - id: cov_n_e
        doc: |
          Covariance of northing and easting
        type: f4
      - id: cov_n_d
        doc: |
          Covariance of northing and downward measurement
        type: f4
      - id: cov_e_e
        doc: |
          Estimated variance of easting
        type: f4
      - id: cov_e_d
        doc: |
          Covariance of easting and downward measurement
        type: f4
      - id: cov_d_d
        doc: |
          Estimated variance of downward measurement
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution.
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ecef_gnss:
    doc: |
      This message reports the velocity in Earth Centered Earth Fixed (ECEF)
      coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
      with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Velocity ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Velocity ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Velocity ECEF Z coordinate
        type: s4
      - id: accuracy
        doc: |
          Velocity estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ecef_cov_gnss:
    doc: |
      This message reports the velocity in Earth Centered Earth Fixed (ECEF)
      coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
      with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Velocity ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Velocity ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Velocity ECEF Z coordinate
        type: s4
      - id: cov_x_x
        doc: |
          Estimated variance of x
        type: f4
      - id: cov_x_y
        doc: |
          Estimated covariance of x and y
        type: f4
      - id: cov_x_z
        doc: |
          Estimated covariance of x and z
        type: f4
      - id: cov_y_y
        doc: |
          Estimated variance of y
        type: f4
      - id: cov_y_z
        doc: |
          Estimated covariance of y and z
        type: f4
      - id: cov_z_z
        doc: |
          Estimated variance of z
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ned_gnss:
    doc: |
      This message reports the velocity in local North East Down (NED)
      coordinates. The NED coordinate system is defined as the local WGS84
      tangent plane centered at the current position. The full GPS time is
      given by the preceding MSG_GPS_TIME with the matching time-of-week
      (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Velocity North coordinate
        type: s4
      - id: e
        doc: |
          Velocity East coordinate
        type: s4
      - id: d
        doc: |
          Velocity Down coordinate
        type: s4
      - id: h_accuracy
        doc: |
          Horizontal velocity estimated standard deviation
        type: u2
      - id: v_accuracy
        doc: |
          Vertical velocity estimated standard deviation
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ned_cov_gnss:
    doc: |
      This message reports the velocity in local North East Down (NED)
      coordinates. The NED coordinate system is defined as the local WGS84
      tangent plane centered at the current position. The full GPS time is
      given by the preceding MSG_GPS_TIME with the matching time-of-week
      (tow). This message is similar to the MSG_VEL_NED, but it includes the
      upper triangular portion of the 3x3 covariance matrix.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Velocity North coordinate
        type: s4
      - id: e
        doc: |
          Velocity East coordinate
        type: s4
      - id: d
        doc: |
          Velocity Down coordinate
        type: s4
      - id: cov_n_n
        doc: |
          Estimated variance of northward measurement
        type: f4
      - id: cov_n_e
        doc: |
          Covariance of northward and eastward measurement
        type: f4
      - id: cov_n_d
        doc: |
          Covariance of northward and downward measurement
        type: f4
      - id: cov_e_e
        doc: |
          Estimated variance of eastward measurement
        type: f4
      - id: cov_e_d
        doc: |
          Covariance of eastward and downward measurement
        type: f4
      - id: cov_d_d
        doc: |
          Estimated variance of downward measurement
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_body:
    doc: |
      This message reports the velocity in the Vehicle Body Frame. By
      convention, the x-axis should point out the nose of the vehicle and
      represent the forward direction, while as the y-axis should point out
      the right hand side of the vehicle. Since this is a right handed system,
      z should point out the bottom of the vehicle. The orientation and origin
      of the Vehicle Body Frame are specified via the device settings. The
      full GPS time is given by the preceding MSG_GPS_TIME with the matching
      time-of-week (tow). This message is only produced by inertial versions
      of Swift products and is not available from Piksi Multi or Duro.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Velocity in x direction
        type: s4
      - id: y
        doc: |
          Velocity in y direction
        type: s4
      - id: z
        doc: |
          Velocity in z direction
        type: s4
      - id: cov_x_x
        doc: |
          Estimated variance of x
        type: f4
      - id: cov_x_y
        doc: |
          Covariance of x and y
        type: f4
      - id: cov_x_z
        doc: |
          Covariance of x and z
        type: f4
      - id: cov_y_y
        doc: |
          Estimated variance of y
        type: f4
      - id: cov_y_z
        doc: |
          Covariance of y and z
        type: f4
      - id: cov_z_z
        doc: |
          Estimated variance of z
        type: f4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_cog:
    doc: |
      This message reports the receiver course over ground (COG) and speed
      over  ground (SOG) based on the horizontal (N-E) components of the NED
      velocity  vector. It also includes the vertical velocity coordinate. A
      flag is provided to indicate whether the COG value has been frozen. When
      the flag is set to true, the COG field is set to its last valid value
      until  the system exceeds a minimum velocity threshold. No other fields
      are  affected by this flag.  The NED coordinate system is defined as the
      local WGS84 tangent  plane centered at the current position. The full
      GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
      of-week (tow). Note: course over ground represents the receiver's
      direction of travel,  but not necessarily the device heading.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: cog
        doc: |
          Course over ground relative to north direction
        type: u4
      - id: sog
        doc: |
          Speed over ground (based on horizontal velocity)
        type: u4
      - id: v_up
        doc: |
          Vertical velocity component (positive up)
        type: s4
      - id: cog_accuracy
        doc: |
          Course over ground estimated standard deviation
        type: u4
      - id: sog_accuracy
        doc: |
          Speed over ground estimated standard deviation
        type: u4
      - id: v_up_accuracy
        doc: |
          Vertical velocity estimated standard deviation
        type: u4
      - id: flags
        doc: |
          Status flags
        type: u2
  
  msg_age_corrections:
    doc: |
      This message reports the Age of the corrections used for the current
      Differential solution.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: age
        doc: |
          Age of the corrections (0xFFFF indicates invalid)
        type: u2
  
  msg_gps_time_dep_a:
    doc: |
      This message reports the GPS time, representing the time since the GPS
      epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
      and seconds of the week. The weeks begin at the Saturday/Sunday
      transition. GPS week 0 began at the beginning of the GPS time scale.

      Within each week number, the GPS time of the week is between between 0
      and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
      leap seconds, and as of now, has a small offset from UTC. In a message
      stream, this message precedes a set of other navigation messages
      referenced to the same time (but lacking the ns field) and indicates a
      more precise time of these messages.
    seq:
      - id: wn
        doc: |
          GPS week number
        type: u2
      - id: tow
        doc: |
          GPS time of week rounded to the nearest millisecond
        type: u4
      - id: ns_residual
        doc: |
          Nanosecond residual of millisecond-rounded TOW (ranges from -500000
          to 500000)
        type: s4
      - id: flags
        doc: |
          Status flags (reserved)
        type: u1
  
  msg_dops_dep_a:
    doc: |
      This dilution of precision (DOP) message describes the effect of
      navigation satellite geometry on positional measurement precision.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: gdop
        doc: |
          Geometric Dilution of Precision
        type: u2
      - id: pdop
        doc: |
          Position Dilution of Precision
        type: u2
      - id: tdop
        doc: |
          Time Dilution of Precision
        type: u2
      - id: hdop
        doc: |
          Horizontal Dilution of Precision
        type: u2
      - id: vdop
        doc: |
          Vertical Dilution of Precision
        type: u2
  
  msg_pos_ecef_dep_a:
    doc: |
      The position solution message reports absolute Earth Centered Earth
      Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
      RTK) of the position solution. If the rover receiver knows the surveyed
      position of the base station and has an RTK solution, this reports a
      pseudo-absolute position solution using the base station position and
      the rover's RTK baseline vector. The full GPS time is given by the
      preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          ECEF X coordinate
        type: f8
      - id: y
        doc: |
          ECEF Y coordinate
        type: f8
      - id: z
        doc: |
          ECEF Z coordinate
        type: f8
      - id: accuracy
        doc: |
          Position accuracy estimate (not implemented). Defaults to 0.
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_pos_llh_dep_a:
    doc: |
      This position solution message reports the absolute geodetic coordinates
      and the status (single point vs pseudo-absolute RTK) of the position
      solution. If the rover receiver knows the surveyed position of the base
      station and has an RTK solution, this reports a pseudo-absolute position
      solution using the base station position and the rover's RTK baseline
      vector. The full GPS time is given by the preceding MSG_GPS_TIME with
      the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height
        type: f8
      - id: h_accuracy
        doc: |
          Horizontal position accuracy estimate (not implemented). Defaults to
          0.
        type: u2
      - id: v_accuracy
        doc: |
          Vertical position accuracy estimate (not implemented). Defaults to
          0.
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution.
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_baseline_ecef_dep_a:
    doc: |
      This message reports the baseline solution in Earth Centered Earth Fixed
      (ECEF) coordinates. This baseline is the relative vector distance from
      the base station to the rover receiver. The full GPS time is given by
      the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Baseline ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Baseline ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Baseline ECEF Z coordinate
        type: s4
      - id: accuracy
        doc: |
          Position accuracy estimate
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_baseline_ned_dep_a:
    doc: |
      This message reports the baseline solution in North East Down (NED)
      coordinates. This baseline is the relative vector distance from the base
      station to the rover receiver, and NED coordinate system is defined at
      the local WGS84 tangent plane centered at the base station position.
      The full GPS time is given by the preceding MSG_GPS_TIME with the
      matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Baseline North coordinate
        type: s4
      - id: e
        doc: |
          Baseline East coordinate
        type: s4
      - id: d
        doc: |
          Baseline Down coordinate
        type: s4
      - id: h_accuracy
        doc: |
          Horizontal position accuracy estimate (not implemented). Defaults to
          0.
        type: u2
      - id: v_accuracy
        doc: |
          Vertical position accuracy estimate (not implemented). Defaults to
          0.
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_vel_ecef_dep_a:
    doc: |
      This message reports the velocity in Earth Centered Earth Fixed (ECEF)
      coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
      with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          Velocity ECEF X coordinate
        type: s4
      - id: y
        doc: |
          Velocity ECEF Y coordinate
        type: s4
      - id: z
        doc: |
          Velocity ECEF Z coordinate
        type: s4
      - id: accuracy
        doc: |
          Velocity accuracy estimate (not implemented). Defaults to 0.
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags (reserved)
        type: u1
  
  msg_vel_ned_dep_a:
    doc: |
      This message reports the velocity in local North East Down (NED)
      coordinates. The NED coordinate system is defined as the local WGS84
      tangent plane centered at the current position. The full GPS time is
      given by the preceding MSG_GPS_TIME with the matching time-of-week
      (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: n
        doc: |
          Velocity North coordinate
        type: s4
      - id: e
        doc: |
          Velocity East coordinate
        type: s4
      - id: d
        doc: |
          Velocity Down coordinate
        type: s4
      - id: h_accuracy
        doc: |
          Horizontal velocity accuracy estimate (not implemented). Defaults to
          0.
        type: u2
      - id: v_accuracy
        doc: |
          Vertical velocity accuracy estimate (not implemented). Defaults to
          0.
        type: u2
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags (reserved)
        type: u1
  
  msg_baseline_heading_dep_a:
    doc: |
      This message reports the baseline heading pointing from the base station
      to the rover relative to True North. The full GPS time is given by the
      preceding MSG_GPS_TIME with the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: heading
        doc: |
          Heading
        type: u4
      - id: n_sats
        doc: |
          Number of satellites used in solution
        type: u1
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_protection_level_dep_a:
    doc: |
      This message reports the local vertical and horizontal protection levels
      associated with a given LLH position solution. The full GPS time is
      given by the preceding MSG_GPS_TIME with the matching time-of-week
      (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: vpl
        doc: |
          Vertical protection level
        type: u2
      - id: hpl
        doc: |
          Horizontal protection level
        type: u2
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height
        type: f8
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_protection_level:
    doc: |
      This message reports the protection levels associated to the given state
      estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
      the matching time-of-week (tow).
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: wn
        doc: |
          GPS week number
        type: s2
      - id: hpl
        doc: |
          Horizontal protection level
        type: u2
      - id: vpl
        doc: |
          Vertical protection level
        type: u2
      - id: atpl
        doc: |
          Along-track position error protection level
        type: u2
      - id: ctpl
        doc: |
          Cross-track position error protection level
        type: u2
      - id: hvpl
        doc: |
          Protection level for the error vector between estimated and true
          along/cross track velocity vector
        type: u2
      - id: vvpl
        doc: |
          Protection level for the velocity in vehicle upright direction
          (different from vertical direction if on a slope)
        type: u2
      - id: hopl
        doc: |
          Heading orientation protection level
        type: u2
      - id: popl
        doc: |
          Pitch orientation protection level
        type: u2
      - id: ropl
        doc: |
          Roll orientation protection level
        type: u2
      - id: lat
        doc: |
          Latitude
        type: f8
      - id: lon
        doc: |
          Longitude
        type: f8
      - id: height
        doc: |
          Height
        type: f8
      - id: v_x
        doc: |
          Velocity in vehicle x direction
        type: s4
      - id: v_y
        doc: |
          Velocity in vehicle y direction
        type: s4
      - id: v_z
        doc: |
          Velocity in vehicle z direction
        type: s4
      - id: roll
        doc: |
          Roll angle
        type: s4
      - id: pitch
        doc: |
          Pitch angle
        type: s4
      - id: heading
        doc: |
          Heading angle
        type: s4
      - id: flags
        doc: |
          Status flags
        type: u4
  
  msg_utc_leap_second:
    doc: |
      UTC-GPST leap seconds before and after the most recent (past, or future,
      for announced insertions) UTC leap second insertion.
    seq:
      - id: reserved_0
        doc: |
          Reserved.
        type: s2
      - id: reserved_1
        doc: |
          Reserved.
        type: s2
      - id: reserved_2
        doc: |
          Reserved.
        type: s1
      - id: count_before
        doc: |
          Leap second count before insertion.
        type: s1
      - id: reserved_3
        doc: |
          Reserved.
        type: u2
      - id: reserved_4
        doc: |
          Reserved.
        type: u2
      - id: ref_wn
        doc: |
          Leap second reference GPS week number.
        type: u2
      - id: ref_dn
        doc: |
          Leap second reference day number.
        type: u1
      - id: count_after
        doc: |
          Leap second count after insertion.
        type: s1
  
  msg_reference_frame_param:
    seq:
      - id: ssr_iod
        doc: |
          SSR IOD parameter.
        type: u1
      - id: sn
        doc: |
          Name of source coordinate-system.
        type: str
        encoding: ascii
        size: 32
      - id: tn
        doc: |
          Name of target coordinate-system.
        type: str
        encoding: ascii
        size: 32
      - id: sin
        doc: |
          System Identification Number.
        type: u1
      - id: utn
        doc: |
          Utilized Transformation Message.
        type: u2
      - id: re_t0
        doc: |
          Reference Epoch t0 for transformation parameter set given as
          Modified Julian Day (MJD) Number minus 44244 days.
        type: u2
      - id: delta_x0
        doc: |
          Translation in X for Reference Epoch t0.
        type: s4
      - id: delta_y0
        doc: |
          Translation in Y for Reference Epoch t0.
        type: s4
      - id: delta_z0
        doc: |
          Translation in Z for Reference Epoch t0.
        type: s4
      - id: theta_01
        doc: |
          Rotation around the X-axis for Reference Epoch t0.
        type: s4
      - id: theta_02
        doc: |
          Rotation around the Y-axis for Reference Epoch t0.
        type: s4
      - id: theta_03
        doc: |
          Rotation around the Z-axis for Reference Epoch t0.
        type: s4
      - id: scale
        doc: |
          Scale correction for Reference Epoch t0.
        type: s4
      - id: dot_delta_x0
        doc: |
          Rate of change of translation in X.
        type: s4
      - id: dot_delta_y0
        doc: |
          Rate of change of translation in Y.
        type: s4
      - id: dot_delta_z0
        doc: |
          Rate of change of translation in Z.
        type: s4
      - id: dot_theta_01
        doc: |
          Rate of change of rotation around the X-axis.
        type: s4
      - id: dot_theta_02
        doc: |
          Rate of change of rotation around the Y-axis.
        type: s4
      - id: dot_theta_03
        doc: |
          Rate of change of rotation around the Z-axis.
        type: s4
      - id: dot_scale
        doc: |
          Rate of change of scale correction.
        type: s2
  
  msg_pose_relative:
    doc: |
      This solution message reports the relative pose of a sensor between two
      time instances. The relative pose comprises of a rotation and a
      translation which relates the sensor (e.g. camera) frame at a given time
      (first keyframe) to the sensor frame at another time (second keyframe).
      The relative translations is a 3x1 vector described in the first
      keyframe.  Relative rotation is described by a quaternion from second
      keyframe to the first keyframe.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: sensor_id
        doc: |
          ID of the sensor producing this message
        type: u1
      - id: timestamp_1
        doc: |
          Timestamp of first keyframe
        type: u4
      - id: timestamp_2
        doc: |
          Timestamp of second keyframe
        type: u4
      - id: trans
        doc: |
          Relative translation [x,y,z] described in first keyframe
        type: s4
        repeat: expr
        repeat-expr: 3
      - id: w
        doc: |
          Real component of quaternion to describe relative rotation (second
          to first keyframe)
        type: s4
      - id: x
        doc: |
          1st imaginary component of quaternion to describe relative rotation
          (second to first keyframe)
        type: s4
      - id: y
        doc: |
          2nd imaginary component of quaternion to describe relative rotation
          (second to first keyframe)
        type: s4
      - id: z
        doc: |
          3rd imaginary component of quaternion to describe relative rotation
          (second to first keyframe)
        type: s4
      - id: cov_r_x_x
        doc: |
          Estimated variance of x (relative translation)
        type: f4
      - id: cov_r_x_y
        doc: |
          Covariance of x and y (relative translation)
        type: f4
      - id: cov_r_x_z
        doc: |
          Covariance of x and z (relative translation)
        type: f4
      - id: cov_r_y_y
        doc: |
          Estimated variance of y (relative translation)
        type: f4
      - id: cov_r_y_z
        doc: |
          Covariance of y and z (relative translation)
        type: f4
      - id: cov_r_z_z
        doc: |
          Estimated variance of z (relative translation)
        type: f4
      - id: cov_c_x_x
        doc: |
          Estimated variance of x (relative rotation)
        type: f4
      - id: cov_c_x_y
        doc: |
          Covariance of x and y (relative rotation)
        type: f4
      - id: cov_c_x_z
        doc: |
          Covariance of x and z (relative rotation)
        type: f4
      - id: cov_c_y_y
        doc: |
          Estimated variance of y (relative rotation)
        type: f4
      - id: cov_c_y_z
        doc: |
          Covariance of y and z (relative rotation)
        type: f4
      - id: cov_c_z_z
        doc: |
          Estimated variance of z (relative rotation)
        type: f4
      - id: flags
        doc: |
          Status flags of relative translation and rotation
        type: u1
  