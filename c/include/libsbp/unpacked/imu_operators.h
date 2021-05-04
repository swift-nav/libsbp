#ifndef LIBSBP_IMU_OPERATORS_H
#define LIBSBP_IMU_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/imu.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.tow_f != b.tow_f)
  {
    return false;
  }

  if (a.acc_x != b.acc_x)
  {
    return false;
  }

  if (a.acc_y != b.acc_y)
  {
    return false;
  }

  if (a.acc_z != b.acc_z)
  {
    return false;
  }

  if (a.gyr_x != b.gyr_x)
  {
    return false;
  }

  if (a.gyr_y != b.gyr_y)
  {
    return false;
  }

  if (a.gyr_z != b.gyr_z)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_imu_raw_t &a, const sbp_msg_imu_raw_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b)
{
  (void)a;
  (void)b;

  if (a.imu_type != b.imu_type)
  {
    return false;
  }

  if (a.temp != b.temp)
  {
    return false;
  }

  if (a.imu_conf != b.imu_conf)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_imu_aux_t &a, const sbp_msg_imu_aux_t &b)
{
  return !(a == b);
}
#endif

#endif