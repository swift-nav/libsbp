/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/ndb.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/ndb.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ndb.h>

bool sbp_msg_ndb_event_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_ndb_event_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->recv_time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->event)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->object_type)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->result)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->data_source)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->object_sid)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->src_sid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->original_sender)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ndb_event_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_ndb_event_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ndb_event_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_ndb_event_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_ndb_event_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->recv_time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->event)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->object_type)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->result)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->data_source)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->object_sid)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->src_sid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->original_sender)) {
    return false;
  }
  return true;
}

s8 sbp_msg_ndb_event_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_ndb_event_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_ndb_event_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_ndb_event_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_ndb_event_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_ndb_event_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NDB_EVENT, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_ndb_event_cmp(const sbp_msg_ndb_event_t *a,
                          const sbp_msg_ndb_event_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->recv_time, &b->recv_time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->event, &b->event);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->object_type, &b->object_type);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->result, &b->result);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->data_source, &b->data_source);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->object_sid, &b->object_sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->src_sid, &b->src_sid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->original_sender, &b->original_sender);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
