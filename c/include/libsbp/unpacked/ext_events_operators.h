#ifndef LIBSBP_EXT_EVENTS_OPERATORS_H
#define LIBSBP_EXT_EVENTS_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/ext_events.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b)
{
  (void)a;
  (void)b;

  if (a.wn != b.wn)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.ns_residual != b.ns_residual)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.pin != b.pin)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b)
{
  return !(a == b);
}
#endif

#endif
