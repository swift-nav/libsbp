#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/settings.h>
#include <libsbp/internal/unpacked/settings.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_settings_save_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_save_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_settings_save_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_save_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_save_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_save_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_save_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_settings_save_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_save_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_save_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *a, const sbp_msg_settings_save_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

bool pack_sbp_msg_settings_write_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_write_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_write_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_write_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_write_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_write_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_write_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_write_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_write_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_write_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *a, const sbp_msg_settings_write_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 254
      , 3, 3
      );
  return packed_size;
}

bool pack_sbp_msg_settings_write_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_write_resp_t *msg)
{
  if (!pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_write_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_write_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_write_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_write_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_write_resp_t *msg)
{
  if (!unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_write_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_write_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_write_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *a, const sbp_msg_settings_write_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 254,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 2, 2
      );
  return packed_size;
}

bool pack_sbp_msg_settings_read_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_req_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,2, 2,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_req_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,2, 2,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *a, const sbp_msg_settings_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,2,2
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

bool pack_sbp_msg_settings_read_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_resp_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_resp_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *a, const sbp_msg_settings_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->index);
  return packed_size;
}

bool pack_sbp_msg_settings_read_by_index_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_req_t *msg)
{
  if (!pack_u16(ctx, &msg->index)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_by_index_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_by_index_req_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_by_index_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_req_t *msg)
{
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_by_index_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_by_index_req_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *a, const sbp_msg_settings_read_by_index_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->index);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 253
      , 3, 4
      );
  return packed_size;
}

bool pack_sbp_msg_settings_read_by_index_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_resp_t *msg)
{
  if (!pack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, 253,3, 4,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_by_index_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_by_index_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_by_index_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_resp_t *msg)
{
  if (!unpack_u16(ctx, &msg->index)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, 253,3, 4,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_by_index_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_by_index_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *a, const sbp_msg_settings_read_by_index_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 253,3,4
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_settings_read_by_index_done_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_read_by_index_done_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_settings_read_by_index_done_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_read_by_index_done_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_read_by_index_done_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_read_by_index_done_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_read_by_index_done_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_settings_read_by_index_done_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_read_by_index_done_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_read_by_index_done_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *a, const sbp_msg_settings_read_by_index_done_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 255
      , 3, 3
      );
  return packed_size;
}

bool pack_sbp_msg_settings_register_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_register_t *msg)
{
  if (!sbp_multipart_string_pack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_register_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_register_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_register_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_register_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_register_t *msg)
{
  if (!sbp_multipart_string_unpack(&msg->setting, 255,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_register_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_register_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_register_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *a, const sbp_msg_settings_register_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_multipart_string_packed_len(&msg->setting, 254
      , 3, 3
      );
  return packed_size;
}

bool pack_sbp_msg_settings_register_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_settings_register_resp_t *msg)
{
  if (!pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_pack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_settings_register_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_settings_register_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_settings_register_resp_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_settings_register_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_settings_register_resp_t *msg)
{
  if (!unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_multipart_string_unpack(&msg->setting, 254,3, 3,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_settings_register_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_settings_register_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_settings_register_resp_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *a, const sbp_msg_settings_register_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 254,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}
