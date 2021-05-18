#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/logging.h>
#include <libsbp/internal/unpacked/logging.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->level);
  packed_size += sbp_unterminated_string_packed_len(&msg->text, 254
      );
  return packed_size;
}

bool pack_sbp_msg_log_t(sbp_pack_ctx_t *ctx, const sbp_msg_log_t *msg)
{
  if (!pack_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->text, 254,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_log_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_log_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_log_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_log_t(sbp_unpack_ctx_t *ctx, sbp_msg_log_t *msg)
{
  if (!unpack_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->text, 254,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_log_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_log_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_log_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_log_t(const sbp_msg_log_t *a, const sbp_msg_log_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->level, &b->level);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, 254
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_u8(&msg->protocol);
  packed_size += (msg->n_fwd_payload * sbp_packed_size_char(&msg->fwd_payload[0]));
  return packed_size;
}

bool pack_sbp_msg_fwd_t(sbp_pack_ctx_t *ctx, const sbp_msg_fwd_t *msg)
{
  if (!pack_u8(ctx, &msg->source)) { return false; }
  if (!pack_u8(ctx, &msg->protocol)) { return false; }
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++)
  {
    if (!pack_char(ctx, &msg->fwd_payload[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_fwd_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_fwd_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_fwd_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_fwd_t(sbp_unpack_ctx_t *ctx, sbp_msg_fwd_t *msg)
{
  if (!unpack_u8(ctx, &msg->source)) { return false; }
  if (!unpack_u8(ctx, &msg->protocol)) { return false; }
    msg->n_fwd_payload = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_char(&msg->fwd_payload[0]));
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++) {
    if (!unpack_char(ctx, &msg->fwd_payload[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_fwd_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_fwd_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_fwd_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_fwd_t(const sbp_msg_fwd_t *a, const sbp_msg_fwd_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->protocol, &b->protocol);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_fwd_payload, &b->n_fwd_payload);
  for (uint8_t i = 0; i < a->n_fwd_payload && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->fwd_payload[i], &b->fwd_payload[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(&msg->text, 255
      );
  return packed_size;
}

bool pack_sbp_msg_print_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_print_dep_t *msg)
{
  if (!sbp_unterminated_string_pack(&msg->text, 255,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_print_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_print_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_print_dep_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_print_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_print_dep_t *msg)
{
  if (!sbp_unterminated_string_unpack(&msg->text, 255,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_print_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_print_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_print_dep_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *a, const sbp_msg_print_dep_t *b) {
  int ret = 0;
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, 255
    );
  if (ret != 0) { return ret; }
  return ret;
}
