/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/skylark.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/skylark.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/skylark.h>

bool sbp_msg_acknowledge_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_acknowledge_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->request_id)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->area_id)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->response_code)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->correction_mask_on_demand)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->correction_mask_stream)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->solution_id)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acknowledge_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_acknowledge_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acknowledge_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_acknowledge_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_acknowledge_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->request_id)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->area_id)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->response_code)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->correction_mask_on_demand)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->correction_mask_stream)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->solution_id)) {
    return false;
  }
  return true;
}

s8 sbp_msg_acknowledge_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_acknowledge_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_acknowledge_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_acknowledge_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_acknowledge_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_acknowledge_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ACKNOWLEDGE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_acknowledge_cmp(const sbp_msg_acknowledge_t *a,
                            const sbp_msg_acknowledge_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->request_id, &b->request_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->area_id, &b->area_id);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->response_code, &b->response_code);
  if (ret != 0) {
    return ret;
  }

  ret =
      sbp_u16_cmp(&a->correction_mask_on_demand, &b->correction_mask_on_demand);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->correction_mask_stream, &b->correction_mask_stream);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->solution_id, &b->solution_id);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
