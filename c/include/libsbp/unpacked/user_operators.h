#ifndef LIBSBP_USER_OPERATORS_H
#define LIBSBP_USER_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/user.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b)
{
  (void)a;
  (void)b;

  if (a.n_contents != b.n_contents)
  {
    return false;
  }
  for (size_t contents_idx = 0; contents_idx < (size_t)a.n_contents; contents_idx++)
  {

    if (a.contents[contents_idx] != b.contents[contents_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b)
{
  return !(a == b);
}
#endif

#endif