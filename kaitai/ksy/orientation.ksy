# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Orientation Messages
#
# Automatically generated from spec/yaml/swiftnav/sbp/orientation.yaml with generate.py.
# Do not modify by hand!

meta:
  id: orientation
  endian: le
  imports: [  ]

types:

  msg_baseline_heading:
    doc: |
      This message reports the baseline heading pointing from the base station
      to the rover relative to True North. The full GPS time is given by the
      preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
      intended that time-matched RTK mode is used when the base station is
      moving.
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
  
  msg_orient_quat:
    doc: |
      This message reports the quaternion vector describing the vehicle body
      frame's orientation with respect to a local-level NED frame. The
      components of the vector should sum to a unit vector assuming that the
      LSB of each component as a value of 2^-31. This message will only be
      available in future INS versions of Swift Products and is not produced
      by Piksi Multi or Duro.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: w
        doc: |
          Real component
        type: s4
      - id: x
        doc: |
          1st imaginary component
        type: s4
      - id: y
        doc: |
          2nd imaginary component
        type: s4
      - id: z
        doc: |
          3rd imaginary component
        type: s4
      - id: w_accuracy
        doc: |
          Estimated standard deviation of w
        type: f4
      - id: x_accuracy
        doc: |
          Estimated standard deviation of x
        type: f4
      - id: y_accuracy
        doc: |
          Estimated standard deviation of y
        type: f4
      - id: z_accuracy
        doc: |
          Estimated standard deviation of z
        type: f4
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_orient_euler:
    doc: |
      This message reports the yaw, pitch, and roll angles of the vehicle body
      frame. The rotations should applied intrinsically in the order yaw,
      pitch, and roll in order to rotate the from a frame aligned with the
      local-level NED frame to the vehicle body frame.  This message will only
      be available in future INS versions of Swift Products and is not
      produced by Piksi Multi or Duro.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: roll
        doc: |
          rotation about the forward axis of the vehicle
        type: s4
      - id: pitch
        doc: |
          rotation about the rightward axis of the vehicle
        type: s4
      - id: yaw
        doc: |
          rotation about the downward axis of the vehicle
        type: s4
      - id: roll_accuracy
        doc: |
          Estimated standard deviation of roll
        type: f4
      - id: pitch_accuracy
        doc: |
          Estimated standard deviation of pitch
        type: f4
      - id: yaw_accuracy
        doc: |
          Estimated standard deviation of yaw
        type: f4
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_angular_rate:
    doc: |
      This message reports the orientation rates in the vehicle body frame.
      The values represent the measurements a strapped down gyroscope would
      make and are not equivalent to the time derivative of the Euler angles.
      The orientation and origin of the user frame is specified via device
      settings. By convention, the vehicle x-axis is expected to be aligned
      with the forward direction, while the vehicle y-axis is expected to be
      aligned with the right direction, and the vehicle z-axis should be
      aligned with the down direction. This message will only be available in
      future INS versions of Swift Products and is not produced by Piksi Multi
      or Duro.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: x
        doc: |
          angular rate about x axis
        type: s4
      - id: y
        doc: |
          angular rate about y axis
        type: s4
      - id: z
        doc: |
          angular rate about z axis
        type: s4
      - id: flags
        doc: |
          Status flags
        type: u1
  
  msg_orient_quat_cov:
    doc: |
      This message reports the orientation as a unit quaternion together with
      the upper triangle of the symmetric 3x3 attitude covariance matrix and a
      GPS time-of-week time-tag. The reference frame of the quaternion and the
      parameterization of the covariance matrix are both encoded in the flags
      field, allowing additional frames or parameterizations to be added later
      without introducing a new message. By default the quaternion describes
      the orientation of the vehicle body frame with respect to a local-level
      NED frame (matching MSG_ORIENT_QUAT) and the covariance is expressed as
      small-angle rotation errors about the axes of that NED frame; in this
      default case the cov_xx, cov_yy, cov_zz diagonal entries correspond to
      the variance of the rotation error about North, East, and Down
      respectively. The components of the quaternion sum to a unit vector
      assuming that the LSB of each component has a value of 2^-31. This
      message will only be available in future INS versions of Swift Products
      and is not produced by Piksi Multi or Duro.
    seq:
      - id: tow
        doc: |
          GPS Time of Week
        type: u4
      - id: w
        doc: |
          Real component
        type: s4
      - id: x
        doc: |
          1st imaginary component
        type: s4
      - id: y
        doc: |
          2nd imaginary component
        type: s4
      - id: z
        doc: |
          3rd imaginary component
        type: s4
      - id: cov_xx
        doc: |
          Estimated variance of the rotation error about the 1st axis of the
          covariance frame
        type: f4
      - id: cov_xy
        doc: |
          Estimated covariance of the rotation errors about the 1st and 2nd
          axes of the covariance frame
        type: f4
      - id: cov_xz
        doc: |
          Estimated covariance of the rotation errors about the 1st and 3rd
          axes of the covariance frame
        type: f4
      - id: cov_yy
        doc: |
          Estimated variance of the rotation error about the 2nd axis of the
          covariance frame
        type: f4
      - id: cov_yz
        doc: |
          Estimated covariance of the rotation errors about the 2nd and 3rd
          axes of the covariance frame
        type: f4
      - id: cov_zz
        doc: |
          Estimated variance of the rotation error about the 3rd axis of the
          covariance frame
        type: f4
      - id: flags
        doc: |
          Status flags
        type: u1
  
