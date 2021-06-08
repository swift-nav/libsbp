#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/system.h>
#include <libsbp/internal/new/system.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>

size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->group_id);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->n_group_msgs);
  packed_size += (msg->n_group_msgs * sbp_packed_size_u16(&msg->group_msgs[0]));
  return packed_size;
}

bool encode_sbp_msg_group_meta_t(sbp_encode_ctx_t *ctx, const sbp_msg_group_meta_t *msg)
{
  if (!encode_u8(ctx, &msg->group_id)) { return false; }
  if (!encode_u8(ctx, &msg->flags)) { return false; }
  if (!encode_u8(ctx, &msg->n_group_msgs)) { return false; }
  for (uint8_t i = 0; i < msg->n_group_msgs; i++)
  {
    if (!encode_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_group_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_group_meta_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_group_meta_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_group_meta_t(sbp_decode_ctx_t *ctx, sbp_msg_group_meta_t *msg)
{
  if (!decode_u8(ctx, &msg->group_id)) { return false; }
  if (!decode_u8(ctx, &msg->flags)) { return false; }
  if (!decode_u8(ctx, &msg->n_group_msgs)) { return false; }
    msg->n_group_msgs = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u16(&msg->group_msgs[0]));
  for (uint8_t i = 0; i < msg->n_group_msgs; i++) {
    if (!decode_u16(ctx, &msg->group_msgs[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_group_meta_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_group_meta_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_group_meta_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_group_meta_t(struct sbp_state *s, u16 sender_id, const sbp_msg_group_meta_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_group_meta_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_GROUP_META, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *a, const sbp_msg_group_meta_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->group_id, &b->group_id);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_group_msgs, &b->n_group_msgs);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_group_msgs, &b->n_group_msgs);
  for (uint8_t i = 0; i < a->n_group_msgs && ret == 0; i++)
  {
    ret = sbp_cmp_u16(&a->group_msgs[i], &b->group_msgs[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
