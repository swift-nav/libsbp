#ifndef LIBSBP_ORIENTATION_OPERATORS_H
#define LIBSBP_ORIENTATION_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/orientation.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.heading != b.heading)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.w != b.w)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (fabs(a.w_accuracy - b.w_accuracy) > 0.001)
  {
    return false;
  }

  if (fabs(a.x_accuracy - b.x_accuracy) > 0.001)
  {
    return false;
  }

  if (fabs(a.y_accuracy - b.y_accuracy) > 0.001)
  {
    return false;
  }

  if (fabs(a.z_accuracy - b.z_accuracy) > 0.001)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.roll != b.roll)
  {
    return false;
  }

  if (a.pitch != b.pitch)
  {
    return false;
  }

  if (a.yaw != b.yaw)
  {
    return false;
  }

  if (fabs(a.roll_accuracy - b.roll_accuracy) > 0.001)
  {
    return false;
  }

  if (fabs(a.pitch_accuracy - b.pitch_accuracy) > 0.001)
  {
    return false;
  }

  if (fabs(a.yaw_accuracy - b.yaw_accuracy) > 0.001)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b)
{
  return !(a == b);
}
#endif

#endif