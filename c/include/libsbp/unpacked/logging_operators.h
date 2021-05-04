#ifndef LIBSBP_LOGGING_OPERATORS_H
#define LIBSBP_LOGGING_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/logging.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_log_t &a, const sbp_msg_log_t &b)
{
  (void)a;
  (void)b;

  if (a.level != b.level)
  {
    return false;
  }
  if (sbp_strcmp(a.text, b.text, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_log_t &a, const sbp_msg_log_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b)
{
  (void)a;
  (void)b;

  if (a.source != b.source)
  {
    return false;
  }

  if (a.protocol != b.protocol)
  {
    return false;
  }
  if (a.n_fwd_payload != b.n_fwd_payload)
  {
    return false;
  }
  for (size_t fwd_payload_idx = 0; fwd_payload_idx < (size_t)a.n_fwd_payload; fwd_payload_idx++)
  {

    if (a.fwd_payload[fwd_payload_idx] != b.fwd_payload[fwd_payload_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b)
{
  (void)a;
  (void)b;

  if (sbp_strcmp(a.text, b.text, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b)
{
  return !(a == b);
}
#endif

#endif