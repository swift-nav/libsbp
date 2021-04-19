#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#define LIBSBP_ORIENTATION_MESSAGES_H

#include "common.h"

SBP_PACK_START
/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
 * that time-matched RTK mode is used when the base station is moving.
 */
#define SBP_MSG_BASELINE_HEADING 0x020F

#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_GET(flags)      \
  (((flags) >> SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SHIFT) & \
   SBP_BASELINE_HEADING_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_BASELINE_HEADING_FLAGS_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SHIFT)));    \
  } while (0)

#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_INVALID (0)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_FIXED_RTK (4)
typedef struct SBP_ATTR_PACKED {
  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Heading[mdeg]
   */
  u32 heading;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_heading_t;
/** Quaternion 4 component vector
 *
 * This message reports the quaternion vector describing the vehicle body
 * frame's orientation with respect to a local-level NED frame. The components
 * of the vector should sum to a unit vector assuming that the LSB of each
 * component as a value of 2^-31. This message will only be available in future
 * INS versions of Swift Products and is not produced by Piksi Multi or Duro.
 */
#define SBP_MSG_ORIENT_QUAT 0x0220

#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_VALID (1)
typedef struct SBP_ATTR_PACKED {
  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Real component[2^-31]
   */
  s32 w;
  /**
   * 1st imaginary component[2^-31]
   */
  s32 x;
  /**
   * 2nd imaginary component[2^-31]
   */
  s32 y;
  /**
   * 3rd imaginary component[2^-31]
   */
  s32 z;
  /**
   * Estimated standard deviation of w[N/A]
   */
  float w_accuracy;
  /**
   * Estimated standard deviation of x[N/A]
   */
  float x_accuracy;
  /**
   * Estimated standard deviation of y[N/A]
   */
  float y_accuracy;
  /**
   * Estimated standard deviation of z[N/A]
   */
  float z_accuracy;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_orient_quat_t;
/** Euler angles
 *
 * This message reports the yaw, pitch, and roll angles of the vehicle body
 * frame. The rotations should applied intrinsically in the order yaw, pitch,
 * and roll in order to rotate the from a frame aligned with the local-level NED
 * frame to the vehicle body frame.  This message will only be available in
 * future INS versions of Swift Products and is not produced by Piksi Multi or
 * Duro.
 */
#define SBP_MSG_ORIENT_EULER 0x0221

#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                       \
    ((flags) |= (((val) & (SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_VALID (1)
typedef struct SBP_ATTR_PACKED {
  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * rotation about the forward axis of the vehicle[microdegrees]
   */
  s32 roll;
  /**
   * rotation about the rightward axis of the vehicle[microdegrees]
   */
  s32 pitch;
  /**
   * rotation about the downward axis of the vehicle[microdegrees]
   */
  s32 yaw;
  /**
   * Estimated standard deviation of roll[degrees]
   */
  float roll_accuracy;
  /**
   * Estimated standard deviation of pitch[degrees]
   */
  float pitch_accuracy;
  /**
   * Estimated standard deviation of yaw[degrees]
   */
  float yaw_accuracy;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_orient_euler_t;
/** Vehicle Body Frame instantaneous angular rates
 *
 * This message reports the orientation rates in the vehicle body frame.
 * The values represent the measurements a strapped down gyroscope would
 * make and are not equivalent to the time derivative of the Euler angles.
 * The orientation and origin of the user frame is specified via device
 * settings. By convention, the vehicle x-axis is expected to be aligned with
 * the forward direction, while the vehicle y-axis is expected to be aligned
 * with the right direction, and the vehicle z-axis should be aligned with the
 * down direction. This message will only be available in future INS versions of
 * Swift Products and is not produced by Piksi Multi or Duro.
 */
#define SBP_MSG_ANGULAR_RATE 0x0222

#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_GET(flags)      \
  (((flags) >> SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SHIFT) & \
   SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SET(flags, val)           \
  do {                                                                       \
    ((flags) |= (((val) & (SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SHIFT)));    \
  } while (0)

#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_VALID (1)
typedef struct SBP_ATTR_PACKED {
  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * angular rate about x axis[microdegrees/s]
   */
  s32 x;
  /**
   * angular rate about y axis[microdegrees/s]
   */
  s32 y;
  /**
   * angular rate about z axis[microdegrees/s]
   */
  s32 z;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_angular_rate_t;

SBP_PACK_END

#endif /* LIBSBP_ORIENTATION_MESSAGES_H */