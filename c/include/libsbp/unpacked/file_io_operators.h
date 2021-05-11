#ifndef LIBSBP_FILE_IO_OPERATORS_H
#define LIBSBP_FILE_IO_OPERATORS_H

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/file_io.h instead"
#endif

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.offset != b.offset)
  {
    return false;
  }

  if (a.chunk_size != b.chunk_size)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }
  if (a.contents_count != b.contents_count)
  {
    return false;
  }
  for (size_t contents_idx = 0; contents_idx < (size_t)a.contents_count; contents_idx++)
  {

    if (a.contents[contents_idx] != b.contents[contents_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.offset != b.offset)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b)
{
  (void)a;
  (void)b;

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.offset != b.offset)
  {
    return false;
  }
  if (a.data_count != b.data_count)
  {
    return false;
  }
  for (size_t data_idx = 0; data_idx < (size_t)a.data_count; data_idx++)
  {

    if (a.data[data_idx] != b.data[data_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b)
{
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b)
{
  (void)a;
  (void)b;

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.window_size != b.window_size)
  {
    return false;
  }

  if (a.batch_size != b.batch_size)
  {
    return false;
  }

  if (a.fileio_version != b.fileio_version)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b)
{
  return !(a == b);
}
#endif

#endif
