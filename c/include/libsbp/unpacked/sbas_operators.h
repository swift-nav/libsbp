#ifndef LIBSBP_SBAS_OPERATORS_H
#define LIBSBP_SBAS_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/unpacked/sbas.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b)
{
  (void)a;
  (void)b;

  if (a.sid.sat != b.sid.sat)
  {
    return false;
  }

  if (a.sid.code != b.sid.code)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.message_type != b.message_type)
  {
    return false;
  }
  for (size_t data_idx = 0; data_idx < 27; data_idx++)
  {

    if (a.data[data_idx] != b.data[data_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b)
{
  return !(a == b);
}
#endif

#endif