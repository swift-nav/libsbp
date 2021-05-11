#ifndef LIBSBP_MAG_OPERATORS_H
#define LIBSBP_MAG_OPERATORS_H

#ifndef LIBSBP_MAG_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/mag.h instead"
#endif

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b)
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

  if (a.mag_x != b.mag_x)
  {
    return false;
  }

  if (a.mag_y != b.mag_y)
  {
    return false;
  }

  if (a.mag_z != b.mag_z)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b)
{
  return !(a == b);
}
#endif

#endif
