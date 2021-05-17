#ifndef LIBSBP_FILE_IO_PACKERS_H
#define LIBSBP_FILE_IO_PACKERS_H

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/file_io.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_packed_size_u8(&msg->chunk_size);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 246
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_req_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->chunk_size)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->filename, 246,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_req_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->chunk_size)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->filename, 246,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  for (uint8_t i = 0; i < msg->n_contents; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
    msg->n_contents = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!sbp_unpack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->dirname, 247
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_req_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->dirname, 247,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_dir_req_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->dirname, 247,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_sequence_string_packed_len(&msg->contents, 251
      , 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_read_dir_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_read_dir_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_sequence_string_pack(&msg->contents, 251,255,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_read_dir_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_read_dir_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_sequence_string_unpack(&msg->contents, 251,255,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_remove_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_remove_t *msg)
{
  if (!sbp_null_terminated_string_pack(&msg->filename, 255,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_remove_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_remove_t *msg)
{
  if (!sbp_null_terminated_string_unpack(&msg->filename, 255,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->offset);
  packed_size += sbp_null_terminated_string_packed_len(&msg->filename, 247
      );
  packed_size += (msg->n_data * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_write_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_req_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->filename, 247,
      ctx)) { return false; }
  for (uint8_t i = 0; i < msg->n_data; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_write_req_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->offset)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->filename, 247,
      ctx)) { return false; }
    msg->n_data = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->data[0]));
  for (uint8_t i = 0; i < msg->n_data; i++) {
    if (!sbp_unpack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_write_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_write_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_write_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_write_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_config_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_config_req_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_config_req_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_u32(&msg->window_size);
  packed_size += sbp_packed_size_u32(&msg->batch_size);
  packed_size += sbp_packed_size_u32(&msg->fileio_version);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fileio_config_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_fileio_config_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->window_size)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->batch_size)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->fileio_version)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fileio_config_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_fileio_config_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->window_size)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->batch_size)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->fileio_version)) { return false; }
  return true;
}

#endif
