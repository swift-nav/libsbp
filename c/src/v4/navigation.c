/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/navigation.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/navigation.h>

bool sbp_msg_gps_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_gps_time_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gps_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_gps_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gps_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_gps_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_gps_time_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gps_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_gps_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gps_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_gps_time_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_gps_time_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_gps_time_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GPS_TIME, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_gps_time_cmp(const sbp_msg_gps_time_t *a,
                         const sbp_msg_gps_time_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->ns_residual, &b->ns_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_gps_time_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_gps_time_gnss_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gps_time_gnss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_gps_time_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gps_time_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_gps_time_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_gps_time_gnss_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gps_time_gnss_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_gps_time_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gps_time_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_gps_time_gnss_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_gps_time_gnss_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_gps_time_gnss_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GPS_TIME_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_gps_time_gnss_cmp(const sbp_msg_gps_time_gnss_t *a,
                              const sbp_msg_gps_time_gnss_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->ns_residual, &b->ns_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_utc_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_utc_time_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->year)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->month)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->day)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->hours)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->minutes)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seconds)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->ns)) {
    return false;
  }
  return true;
}

s8 sbp_msg_utc_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_utc_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_utc_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_utc_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_utc_time_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->year)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->month)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->day)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->hours)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->minutes)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seconds)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->ns)) {
    return false;
  }
  return true;
}

s8 sbp_msg_utc_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_utc_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_utc_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_utc_time_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_utc_time_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_utc_time_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_UTC_TIME, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_utc_time_cmp(const sbp_msg_utc_time_t *a,
                         const sbp_msg_utc_time_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->year, &b->year);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->month, &b->month);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->day, &b->day);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->hours, &b->hours);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->minutes, &b->minutes);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seconds, &b->seconds);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->ns, &b->ns);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_utc_time_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_utc_time_gnss_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->year)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->month)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->day)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->hours)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->minutes)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->seconds)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->ns)) {
    return false;
  }
  return true;
}

s8 sbp_msg_utc_time_gnss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_utc_time_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_utc_time_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_utc_time_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_utc_time_gnss_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->year)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->month)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->day)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->hours)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->minutes)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->seconds)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->ns)) {
    return false;
  }
  return true;
}

s8 sbp_msg_utc_time_gnss_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_utc_time_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_utc_time_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_utc_time_gnss_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_utc_time_gnss_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_utc_time_gnss_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_UTC_TIME_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_utc_time_gnss_cmp(const sbp_msg_utc_time_gnss_t *a,
                              const sbp_msg_utc_time_gnss_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->year, &b->year);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->month, &b->month);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->day, &b->day);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->hours, &b->hours);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->minutes, &b->minutes);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->seconds, &b->seconds);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->ns, &b->ns);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_dops_encode_internal(sbp_encode_ctx_t *ctx,
                                  const sbp_msg_dops_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->gdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vdop)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_dops_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                       const sbp_msg_dops_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_dops_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_dops_decode_internal(sbp_decode_ctx_t *ctx, sbp_msg_dops_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->gdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vdop)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_dops_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                       sbp_msg_dops_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_dops_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_dops_send(sbp_state_t *s, u16 sender_id, const sbp_msg_dops_t *msg,
                     sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_dops_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_DOPS, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_dops_cmp(const sbp_msg_dops_t *a, const sbp_msg_dops_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->gdop, &b->gdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pdop, &b->pdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tdop, &b->tdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hdop, &b->hdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vdop, &b->vdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_pos_ecef_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_pos_ecef_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_pos_ecef_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_pos_ecef_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_ecef_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_pos_ecef_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_pos_ecef_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_ECEF, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_pos_ecef_cmp(const sbp_msg_pos_ecef_t *a,
                         const sbp_msg_pos_ecef_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_ecef_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_pos_ecef_cov_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_cov_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_pos_ecef_cov_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_cov_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_ecef_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_pos_ecef_cov_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_cov_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_pos_ecef_cov_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_cov_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_ecef_cov_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_pos_ecef_cov_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_pos_ecef_cov_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_ECEF_COV, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_ecef_cov_cmp(const sbp_msg_pos_ecef_cov_t *a,
                             const sbp_msg_pos_ecef_cov_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_llh_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_pos_llh_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_pos_llh_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_llh_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_pos_llh_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_pos_llh_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_llh_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_pos_llh_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_pos_llh_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_LLH, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_pos_llh_cmp(const sbp_msg_pos_llh_t *a,
                        const sbp_msg_pos_llh_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_llh_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_pos_llh_cov_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_cov_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_pos_llh_cov_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_cov_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_llh_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_pos_llh_cov_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_cov_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_pos_llh_cov_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_cov_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_llh_cov_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_pos_llh_cov_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_pos_llh_cov_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_LLH_COV, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_llh_cov_cmp(const sbp_msg_pos_llh_cov_t *a,
                            const sbp_msg_pos_llh_cov_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_estimated_horizontal_error_ellipse_encode_internal(
    sbp_encode_ctx_t *ctx,
    const sbp_estimated_horizontal_error_ellipse_t *msg) {
  if (!sbp_float_encode(ctx, &msg->semi_major)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->semi_minor)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->orientation)) {
    return false;
  }
  return true;
}

s8 sbp_estimated_horizontal_error_ellipse_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_estimated_horizontal_error_ellipse_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_estimated_horizontal_error_ellipse_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_estimated_horizontal_error_ellipse_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_estimated_horizontal_error_ellipse_t *msg) {
  if (!sbp_float_decode(ctx, &msg->semi_major)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->semi_minor)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->orientation)) {
    return false;
  }
  return true;
}

s8 sbp_estimated_horizontal_error_ellipse_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_estimated_horizontal_error_ellipse_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_estimated_horizontal_error_ellipse_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_estimated_horizontal_error_ellipse_cmp(
    const sbp_estimated_horizontal_error_ellipse_t *a,
    const sbp_estimated_horizontal_error_ellipse_t *b) {
  int ret = 0;

  ret = sbp_float_cmp(&a->semi_major, &b->semi_major);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->semi_minor, &b->semi_minor);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->orientation, &b->orientation);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_llh_acc_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_pos_llh_acc_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->orthometric_height)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->ct_accuracy)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->at_accuracy)) {
    return false;
  }
  if (!sbp_estimated_horizontal_error_ellipse_encode_internal(
          ctx, &msg->h_ellipse)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->confidence_and_geoid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_acc_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_pos_llh_acc_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_acc_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_llh_acc_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_pos_llh_acc_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->orthometric_height)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->ct_accuracy)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->at_accuracy)) {
    return false;
  }
  if (!sbp_estimated_horizontal_error_ellipse_decode_internal(
          ctx, &msg->h_ellipse)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->confidence_and_geoid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_acc_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_pos_llh_acc_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_acc_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_llh_acc_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_pos_llh_acc_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_pos_llh_acc_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_LLH_ACC, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_llh_acc_cmp(const sbp_msg_pos_llh_acc_t *a,
                            const sbp_msg_pos_llh_acc_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->orthometric_height, &b->orthometric_height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->ct_accuracy, &b->ct_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->at_accuracy, &b->at_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret =
      sbp_estimated_horizontal_error_ellipse_cmp(&a->h_ellipse, &b->h_ellipse);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->confidence_and_geoid, &b->confidence_and_geoid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_baseline_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_baseline_ecef_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ecef_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_baseline_ecef_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ecef_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_baseline_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_baseline_ecef_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ecef_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_baseline_ecef_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ecef_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_baseline_ecef_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_baseline_ecef_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_baseline_ecef_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASELINE_ECEF, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_baseline_ecef_cmp(const sbp_msg_baseline_ecef_t *a,
                              const sbp_msg_baseline_ecef_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_baseline_ned_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_baseline_ned_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ned_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_baseline_ned_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ned_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_baseline_ned_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_baseline_ned_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ned_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_baseline_ned_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ned_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_baseline_ned_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_baseline_ned_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_baseline_ned_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASELINE_NED, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_baseline_ned_cmp(const sbp_msg_baseline_ned_t *a,
                             const sbp_msg_baseline_ned_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ecef_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_vel_ecef_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_vel_ecef_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ecef_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_vel_ecef_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_vel_ecef_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ecef_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_vel_ecef_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_ecef_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_ECEF, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_vel_ecef_cmp(const sbp_msg_vel_ecef_t *a,
                         const sbp_msg_vel_ecef_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ecef_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_vel_ecef_cov_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_cov_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_vel_ecef_cov_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_cov_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ecef_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_vel_ecef_cov_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_cov_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_vel_ecef_cov_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_cov_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ecef_cov_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_vel_ecef_cov_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_vel_ecef_cov_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_ECEF_COV, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ecef_cov_cmp(const sbp_msg_vel_ecef_cov_t *a,
                             const sbp_msg_vel_ecef_cov_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ned_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_vel_ned_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_vel_ned_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ned_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_vel_ned_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_vel_ned_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ned_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_vel_ned_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_ned_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_NED, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_vel_ned_cmp(const sbp_msg_vel_ned_t *a,
                        const sbp_msg_vel_ned_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ned_cov_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_vel_ned_cov_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_cov_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_vel_ned_cov_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_cov_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ned_cov_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_vel_ned_cov_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_cov_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_vel_ned_cov_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_cov_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ned_cov_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_vel_ned_cov_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_vel_ned_cov_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_NED_COV, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ned_cov_cmp(const sbp_msg_vel_ned_cov_t *a,
                            const sbp_msg_vel_ned_cov_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_ecef_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_pos_ecef_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_gnss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_pos_ecef_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_ecef_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_pos_ecef_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_gnss_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_pos_ecef_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_ecef_gnss_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_pos_ecef_gnss_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_pos_ecef_gnss_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_ECEF_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_ecef_gnss_cmp(const sbp_msg_pos_ecef_gnss_t *a,
                              const sbp_msg_pos_ecef_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_ecef_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_cov_gnss_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_cov_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_ecef_cov_gnss_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_pos_ecef_cov_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_cov_gnss_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_pos_ecef_cov_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_cov_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_ecef_cov_gnss_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_pos_ecef_cov_gnss_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_pos_ecef_cov_gnss_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_ECEF_COV_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_ecef_cov_gnss_cmp(const sbp_msg_pos_ecef_cov_gnss_t *a,
                                  const sbp_msg_pos_ecef_cov_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_llh_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_pos_llh_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_gnss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_pos_llh_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_llh_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_pos_llh_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_gnss_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_pos_llh_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_llh_gnss_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_pos_llh_gnss_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_pos_llh_gnss_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_LLH_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_llh_gnss_cmp(const sbp_msg_pos_llh_gnss_t *a,
                             const sbp_msg_pos_llh_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_llh_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_pos_llh_cov_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_cov_gnss_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_pos_llh_cov_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_cov_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_llh_cov_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_pos_llh_cov_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_cov_gnss_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_pos_llh_cov_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_cov_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_llh_cov_gnss_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_pos_llh_cov_gnss_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_pos_llh_cov_gnss_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_LLH_COV_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_llh_cov_gnss_cmp(const sbp_msg_pos_llh_cov_gnss_t *a,
                                 const sbp_msg_pos_llh_cov_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ecef_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_vel_ecef_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_gnss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_vel_ecef_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ecef_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_vel_ecef_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_gnss_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_vel_ecef_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ecef_gnss_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_vel_ecef_gnss_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_vel_ecef_gnss_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_ECEF_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ecef_gnss_cmp(const sbp_msg_vel_ecef_gnss_t *a,
                              const sbp_msg_vel_ecef_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ecef_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_cov_gnss_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_cov_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ecef_cov_gnss_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_vel_ecef_cov_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_cov_gnss_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_vel_ecef_cov_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_cov_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ecef_cov_gnss_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_vel_ecef_cov_gnss_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_ecef_cov_gnss_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_ECEF_COV_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ecef_cov_gnss_cmp(const sbp_msg_vel_ecef_cov_gnss_t *a,
                                  const sbp_msg_vel_ecef_cov_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ned_gnss_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_vel_ned_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_gnss_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_vel_ned_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ned_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_vel_ned_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_gnss_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_vel_ned_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ned_gnss_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_vel_ned_gnss_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_vel_ned_gnss_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_NED_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ned_gnss_cmp(const sbp_msg_vel_ned_gnss_t *a,
                             const sbp_msg_vel_ned_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ned_cov_gnss_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_vel_ned_cov_gnss_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_cov_gnss_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_vel_ned_cov_gnss_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_cov_gnss_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ned_cov_gnss_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_vel_ned_cov_gnss_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_n)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_n_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_e)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_e_d)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_d_d)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_cov_gnss_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_vel_ned_cov_gnss_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_cov_gnss_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ned_cov_gnss_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_vel_ned_cov_gnss_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_ned_cov_gnss_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_NED_COV_GNSS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ned_cov_gnss_cmp(const sbp_msg_vel_ned_cov_gnss_t *a,
                                 const sbp_msg_vel_ned_cov_gnss_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_body_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_vel_body_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_body_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_vel_body_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_body_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_body_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_vel_body_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_x)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_x_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_y)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_y_z)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->cov_z_z)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_body_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_vel_body_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_body_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_body_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_vel_body_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_body_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_BODY, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_vel_body_cmp(const sbp_msg_vel_body_t *a,
                         const sbp_msg_vel_body_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_cog_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_vel_cog_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->cog)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->sog)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->vel_d)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->cog_accuracy)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->sog_accuracy)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->vel_d_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_cog_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_vel_cog_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_cog_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_cog_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_vel_cog_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->cog)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->sog)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->vel_d)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->cog_accuracy)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->sog_accuracy)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->vel_d_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_cog_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_vel_cog_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_cog_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_cog_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_vel_cog_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_cog_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_COG, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_vel_cog_cmp(const sbp_msg_vel_cog_t *a,
                        const sbp_msg_vel_cog_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->cog, &b->cog);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->sog, &b->sog);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->vel_d, &b->vel_d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->cog_accuracy, &b->cog_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->sog_accuracy, &b->sog_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->vel_d_accuracy, &b->vel_d_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_age_corrections_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_age_corrections_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->age)) {
    return false;
  }
  return true;
}

s8 sbp_msg_age_corrections_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_age_corrections_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_age_corrections_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_age_corrections_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_age_corrections_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->age)) {
    return false;
  }
  return true;
}

s8 sbp_msg_age_corrections_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_age_corrections_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_age_corrections_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_age_corrections_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_age_corrections_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_age_corrections_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_AGE_CORRECTIONS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_age_corrections_cmp(const sbp_msg_age_corrections_t *a,
                                const sbp_msg_age_corrections_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->age, &b->age);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_gps_time_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_gps_time_dep_a_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gps_time_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_gps_time_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gps_time_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_gps_time_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_gps_time_dep_a_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->ns_residual)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_gps_time_dep_a_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_gps_time_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_gps_time_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_gps_time_dep_a_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_gps_time_dep_a_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_gps_time_dep_a_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_GPS_TIME_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_gps_time_dep_a_cmp(const sbp_msg_gps_time_dep_a_t *a,
                               const sbp_msg_gps_time_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->ns_residual, &b->ns_residual);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_dops_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_dops_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->gdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->tdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vdop)) {
    return false;
  }
  return true;
}

s8 sbp_msg_dops_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_dops_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_dops_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_dops_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_dops_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->gdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->tdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hdop)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vdop)) {
    return false;
  }
  return true;
}

s8 sbp_msg_dops_dep_a_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_dops_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_dops_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_dops_dep_a_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_dops_dep_a_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_dops_dep_a_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_DOPS_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_dops_dep_a_cmp(const sbp_msg_dops_dep_a_t *a,
                           const sbp_msg_dops_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->gdop, &b->gdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pdop, &b->pdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->tdop, &b->tdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hdop, &b->hdop);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vdop, &b->vdop);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_ecef_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_pos_ecef_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_pos_ecef_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_ecef_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_pos_ecef_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_ecef_dep_a_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_pos_ecef_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_ecef_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_ecef_dep_a_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_pos_ecef_dep_a_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_pos_ecef_dep_a_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_ECEF_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_ecef_dep_a_cmp(const sbp_msg_pos_ecef_dep_a_t *a,
                               const sbp_msg_pos_ecef_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_pos_llh_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_pos_llh_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_pos_llh_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_pos_llh_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_pos_llh_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_pos_llh_dep_a_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_pos_llh_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_pos_llh_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_pos_llh_dep_a_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_pos_llh_dep_a_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_pos_llh_dep_a_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_POS_LLH_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_pos_llh_dep_a_cmp(const sbp_msg_pos_llh_dep_a_t *a,
                              const sbp_msg_pos_llh_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_baseline_ecef_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ecef_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ecef_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_baseline_ecef_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ecef_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_baseline_ecef_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_ecef_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ecef_dep_a_decode(const uint8_t *buf, uint8_t len,
                                      uint8_t *n_read,
                                      sbp_msg_baseline_ecef_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ecef_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_baseline_ecef_dep_a_send(sbp_state_t *s, u16 sender_id,
                                    const sbp_msg_baseline_ecef_dep_a_t *msg,
                                    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_baseline_ecef_dep_a_encode(payload, sizeof(payload),
                                              &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASELINE_ECEF_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_baseline_ecef_dep_a_cmp(const sbp_msg_baseline_ecef_dep_a_t *a,
                                    const sbp_msg_baseline_ecef_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_baseline_ned_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_ned_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ned_dep_a_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_baseline_ned_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ned_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_baseline_ned_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_ned_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_ned_dep_a_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_baseline_ned_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_ned_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_baseline_ned_dep_a_send(sbp_state_t *s, u16 sender_id,
                                   const sbp_msg_baseline_ned_dep_a_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_baseline_ned_dep_a_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASELINE_NED_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_baseline_ned_dep_a_cmp(const sbp_msg_baseline_ned_dep_a_t *a,
                                   const sbp_msg_baseline_ned_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ecef_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_vel_ecef_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_vel_ecef_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ecef_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_vel_ecef_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->z)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ecef_dep_a_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_vel_ecef_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ecef_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ecef_dep_a_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_vel_ecef_dep_a_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_vel_ecef_dep_a_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_ECEF_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ecef_dep_a_cmp(const sbp_msg_vel_ecef_dep_a_t *a,
                               const sbp_msg_vel_ecef_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->x, &b->x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->y, &b->y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->z, &b->z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->accuracy, &b->accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_vel_ned_dep_a_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_vel_ned_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_dep_a_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_vel_ned_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_vel_ned_dep_a_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_vel_ned_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->n)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->e)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->d)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->h_accuracy)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->v_accuracy)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_vel_ned_dep_a_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_vel_ned_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_vel_ned_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_vel_ned_dep_a_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_vel_ned_dep_a_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_vel_ned_dep_a_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_VEL_NED_DEP_A, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_vel_ned_dep_a_cmp(const sbp_msg_vel_ned_dep_a_t *a,
                              const sbp_msg_vel_ned_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->n, &b->n);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->e, &b->e);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->d, &b->d);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_baseline_heading_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_baseline_heading_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->heading)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_heading_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_baseline_heading_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_heading_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_baseline_heading_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_baseline_heading_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->heading)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->n_sats)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_baseline_heading_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_baseline_heading_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_baseline_heading_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_baseline_heading_dep_a_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_baseline_heading_dep_a_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_baseline_heading_dep_a_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_BASELINE_HEADING_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_baseline_heading_dep_a_cmp(
    const sbp_msg_baseline_heading_dep_a_t *a,
    const sbp_msg_baseline_heading_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->heading, &b->heading);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_sats, &b->n_sats);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_protection_level_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_dep_a_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hpl)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_protection_level_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_protection_level_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_protection_level_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_protection_level_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_protection_level_dep_a_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hpl)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_protection_level_dep_a_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_protection_level_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_protection_level_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_protection_level_dep_a_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_protection_level_dep_a_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_protection_level_dep_a_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_PROTECTION_LEVEL_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_protection_level_dep_a_cmp(
    const sbp_msg_protection_level_dep_a_t *a,
    const sbp_msg_protection_level_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vpl, &b->vpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hpl, &b->hpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_protection_level_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_protection_level_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->atpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->ctpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hvpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->vvpl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->hopl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->popl)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->ropl)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_encode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->v_x)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->v_y)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->v_z)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->roll)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->pitch)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->heading)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_protection_level_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_protection_level_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_protection_level_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_protection_level_decode_internal(sbp_decode_ctx_t *ctx,
                                              sbp_msg_protection_level_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->tow)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->wn)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->atpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->ctpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hvpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->vvpl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->hopl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->popl)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->ropl)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lat)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->lon)) {
    return false;
  }
  if (!sbp_double_decode(ctx, &msg->height)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->v_x)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->v_y)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->v_z)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->roll)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->pitch)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->heading)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_protection_level_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_msg_protection_level_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_protection_level_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_protection_level_send(sbp_state_t *s, u16 sender_id,
                                 const sbp_msg_protection_level_t *msg,
                                 sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_protection_level_encode(payload, sizeof(payload),
                                           &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_PROTECTION_LEVEL, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_protection_level_cmp(const sbp_msg_protection_level_t *a,
                                 const sbp_msg_protection_level_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->tow, &b->tow);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->wn, &b->wn);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hpl, &b->hpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vpl, &b->vpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->atpl, &b->atpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->ctpl, &b->ctpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hvpl, &b->hvpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->vvpl, &b->vvpl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->hopl, &b->hopl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->popl, &b->popl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->ropl, &b->ropl);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lat, &b->lat);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->lon, &b->lon);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_double_cmp(&a->height, &b->height);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->v_x, &b->v_x);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->v_y, &b->v_y);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->v_z, &b->v_z);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->roll, &b->roll);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->pitch, &b->pitch);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->heading, &b->heading);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
