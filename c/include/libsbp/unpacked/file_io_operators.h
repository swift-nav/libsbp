#ifndef LIBSBP_FILE_IO_OPERATORS_H
#define LIBSBP_FILE_IO_OPERATORS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/file_io.h>
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
  if (a.n_filename != b.n_filename)
  {
    return false;
  }
  for (size_t filename_idx = 0; filename_idx < (size_t)a.n_filename; filename_idx++)
  {

    if (a.filename[filename_idx] != b.filename[filename_idx])
    {
      return false;
    }
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
  if (a.n_dirname != b.n_dirname)
  {
    return false;
  }
  for (size_t dirname_idx = 0; dirname_idx < (size_t)a.n_dirname; dirname_idx++)
  {

    if (a.dirname[dirname_idx] != b.dirname[dirname_idx])
    {
      return false;
    }
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

  if (a.n_filename != b.n_filename)
  {
    return false;
  }
  for (size_t filename_idx = 0; filename_idx < (size_t)a.n_filename; filename_idx++)
  {

    if (a.filename[filename_idx] != b.filename[filename_idx])
    {
      return false;
    }
  }

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
  if (a.n_filename != b.n_filename)
  {
    return false;
  }
  for (size_t filename_idx = 0; filename_idx < (size_t)a.n_filename; filename_idx++)
  {

    if (a.filename[filename_idx] != b.filename[filename_idx])
    {
      return false;
    }
  }
  if (a.n_data != b.n_data)
  {
    return false;
  }
  for (size_t data_idx = 0; data_idx < (size_t)a.n_data; data_idx++)
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