#ifndef LIBSBP_FILE_IO_PACKERS_H
#define LIBSBP_FILE_IO_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/file_io.h>

static inline size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->offset) + sizeof(msg->chunk_size) +
         (msg->filename_count * sizeof(msg->filename[0]));
}

static inline bool sbp_pack_sbp_msg_fileio_read_req_t(u8 *buf, size_t len, const sbp_msg_fileio_read_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgoffset = htole32(msg->offset);
  memcpy(buf + offset, &msgoffset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgchunk_size = msg->chunk_size;
  memcpy(buf + offset, &msgchunk_size, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgfilename_idx = 0; msgfilename_idx < (size_t)msg->filename_count; msgfilename_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgfilenamemsgfilename_idx = msg->filename[msgfilename_idx];
    memcpy(buf + offset, &msgfilenamemsgfilename_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_req_t(const u8 *buf, size_t len, sbp_msg_fileio_read_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->offset, buf + offset, 4);
  msg->offset = le32toh(msg->offset);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->chunk_size, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  msg->filename_count = (u8)((len - offset) / 1);

  for (size_t msgfilename_idx = 0; msgfilename_idx < msg->filename_count; msgfilename_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->filename[msgfilename_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + (msg->contents_count * sizeof(msg->contents[0]));
}

static inline bool sbp_pack_sbp_msg_fileio_read_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_read_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->contents_count; msgcontents_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgcontentsmsgcontents_idx = msg->contents[msgcontents_idx];
    memcpy(buf + offset, &msgcontentsmsgcontents_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_read_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  msg->contents_count = (u8)((len - offset) / 1);

  for (size_t msgcontents_idx = 0; msgcontents_idx < msg->contents_count; msgcontents_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->offset) + (msg->dirname_count * sizeof(msg->dirname[0]));
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_req_t(u8 *buf, size_t len, const sbp_msg_fileio_read_dir_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_dir_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgoffset = htole32(msg->offset);
  memcpy(buf + offset, &msgoffset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgdirname_idx = 0; msgdirname_idx < (size_t)msg->dirname_count; msgdirname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgdirnamemsgdirname_idx = msg->dirname[msgdirname_idx];
    memcpy(buf + offset, &msgdirnamemsgdirname_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_fileio_read_dir_req_t(const u8 *buf, size_t len, sbp_msg_fileio_read_dir_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->offset, buf + offset, 4);
  msg->offset = le32toh(msg->offset);
  // NOLINTNEXTLINE
  offset += 4;
  msg->dirname_count = (u8)((len - offset) / 1);

  for (size_t msgdirname_idx = 0; msgdirname_idx < msg->dirname_count; msgdirname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->dirname[msgdirname_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + (msg->contents_count * sizeof(msg->contents[0]));
}

static inline bool
sbp_pack_sbp_msg_fileio_read_dir_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_read_dir_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgcontents_idx = 0; msgcontents_idx < (size_t)msg->contents_count; msgcontents_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgcontentsmsgcontents_idx = msg->contents[msgcontents_idx];
    memcpy(buf + offset, &msgcontentsmsgcontents_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_fileio_read_dir_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_read_dir_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  msg->contents_count = (u8)((len - offset) / 1);

  for (size_t msgcontents_idx = 0; msgcontents_idx < msg->contents_count; msgcontents_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->contents[msgcontents_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg)
{
  (void)msg;
  return 0 + (msg->filename_count * sizeof(msg->filename[0]));
}

static inline bool sbp_pack_sbp_msg_fileio_remove_t(u8 *buf, size_t len, const sbp_msg_fileio_remove_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_remove_t(msg) > len)
  {
    return false;
  }

  for (size_t msgfilename_idx = 0; msgfilename_idx < (size_t)msg->filename_count; msgfilename_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgfilenamemsgfilename_idx = msg->filename[msgfilename_idx];
    memcpy(buf + offset, &msgfilenamemsgfilename_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_remove_t(const u8 *buf, size_t len, sbp_msg_fileio_remove_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->filename_count = (u8)((len - offset) / 1);

  for (size_t msgfilename_idx = 0; msgfilename_idx < msg->filename_count; msgfilename_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->filename[msgfilename_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->offset) + (msg->filename_count * sizeof(msg->filename[0])) +
         (msg->data_count * sizeof(msg->data[0]));
}

static inline bool sbp_pack_sbp_msg_fileio_write_req_t(u8 *buf, size_t len, const sbp_msg_fileio_write_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_write_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgoffset = htole32(msg->offset);
  memcpy(buf + offset, &msgoffset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgfilename_idx = 0; msgfilename_idx < (size_t)msg->filename_count; msgfilename_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgfilenamemsgfilename_idx = msg->filename[msgfilename_idx];
    memcpy(buf + offset, &msgfilenamemsgfilename_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  for (size_t msgdata_idx = 0; msgdata_idx < (size_t)msg->data_count; msgdata_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgdatamsgdata_idx = msg->data[msgdata_idx];
    memcpy(buf + offset, &msgdatamsgdata_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_req_t(const u8 *buf, size_t len, sbp_msg_fileio_write_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->offset, buf + offset, 4);
  msg->offset = le32toh(msg->offset);
  // NOLINTNEXTLINE
  offset += 4;
  msg->filename_count = (u8)((len - offset) / 1);

  for (size_t msgfilename_idx = 0; msgfilename_idx < msg->filename_count; msgfilename_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->filename[msgfilename_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  msg->data_count = (u8)((len - offset) / 1);

  for (size_t msgdata_idx = 0; msgdata_idx < msg->data_count; msgdata_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->data[msgdata_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence);
}

static inline bool sbp_pack_sbp_msg_fileio_write_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_write_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_write_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_write_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence);
}

static inline bool sbp_pack_sbp_msg_fileio_config_req_t(u8 *buf, size_t len, const sbp_msg_fileio_config_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_config_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_req_t(const u8 *buf, size_t len, sbp_msg_fileio_config_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->window_size) + sizeof(msg->batch_size) + sizeof(msg->fileio_version);
}

static inline bool sbp_pack_sbp_msg_fileio_config_resp_t(u8 *buf, size_t len, const sbp_msg_fileio_config_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_fileio_config_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgwindow_size = htole32(msg->window_size);
  memcpy(buf + offset, &msgwindow_size, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgbatch_size = htole32(msg->batch_size);
  memcpy(buf + offset, &msgbatch_size, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgfileio_version = htole32(msg->fileio_version);
  memcpy(buf + offset, &msgfileio_version, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_resp_t(const u8 *buf, size_t len, sbp_msg_fileio_config_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->window_size, buf + offset, 4);
  msg->window_size = le32toh(msg->window_size);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->batch_size, buf + offset, 4);
  msg->batch_size = le32toh(msg->batch_size);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->fileio_version, buf + offset, 4);
  msg->fileio_version = le32toh(msg->fileio_version);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

#endif
