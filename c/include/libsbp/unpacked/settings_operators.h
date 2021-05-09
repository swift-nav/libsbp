#ifndef LIBSBP_SETTINGS_OPERATORS_H
#define LIBSBP_SETTINGS_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/settings.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b)
{
  (void)a;
  (void)b;

  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.status != b.status)
  {
    return false;
  }
  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b)
{
  (void)a;
  (void)b;

  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_by_index_req_t &a,
                              const sbp_msg_settings_read_by_index_req_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &a,
                              const sbp_msg_settings_read_by_index_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_by_index_resp_t &a,
                              const sbp_msg_settings_read_by_index_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.index != b.index)
  {
    return false;
  }
  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_resp_t &a,
                              const sbp_msg_settings_read_by_index_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_by_index_done_t &a,
                              const sbp_msg_settings_read_by_index_done_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_done_t &a,
                              const sbp_msg_settings_read_by_index_done_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b)
{
  (void)a;
  (void)b;

  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.status != b.status)
  {
    return false;
  }
  if (a.setting_count != b.setting_count)
  {
    return false;
  }
  for (size_t setting_idx = 0; setting_idx < (size_t)a.setting_count; setting_idx++)
  {

    if (a.setting[setting_idx] != b.setting[setting_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b)
{
  return !(a == b);
}
#endif

#endif
