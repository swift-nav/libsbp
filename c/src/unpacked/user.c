#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/user.h>
#include <libsbp/internal/unpacked/user.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>

size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

bool pack_sbp_msg_user_data_t(sbp_pack_ctx_t *ctx, const sbp_msg_user_data_t *msg)
{
  for (uint8_t i = 0; i < msg->n_contents; i++)
  {
    if (!pack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_user_data_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_user_data_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_user_data_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_user_data_t(sbp_unpack_ctx_t *ctx, sbp_msg_user_data_t *msg)
{
    msg->n_contents = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!unpack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_user_data_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_user_data_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_user_data_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_user_data_t(const sbp_msg_user_data_t *a, const sbp_msg_user_data_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_contents, &b->n_contents);
  for (uint8_t i = 0; i < a->n_contents && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->contents[i], &b->contents[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
