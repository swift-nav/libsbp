#ifndef LIBSBP_SETTINGS_PACKERS_H
#define LIBSBP_SETTINGS_PACKERS_H

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/settings.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg) {
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_settings_save_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_save_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_save_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_save_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_write_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_write_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_write_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 254
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_write_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_write_resp_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_write_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_write_resp_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 2, 2
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_req_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,2, 2,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_req_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,2, 2,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_resp_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_resp_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->index);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_req_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->index)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_req_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->index)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 253
      , 3, 4
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_resp_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, 253,3, 4,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_resp_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, 253,3, 4,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg) {
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_settings_read_by_index_done_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_done_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_read_by_index_done_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_done_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_register_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_register_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_register_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 254
      , 3, 3
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_settings_register_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_register_resp_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_settings_register_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_register_resp_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

#endif
