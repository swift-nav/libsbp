#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/navigation.h>
#include <libsbp/internal/new/navigation.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>

size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_gps_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_gps_time_t *msg)
{
  if (!pack_u16(ctx, &msg->wn)) { return false; }
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_gps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gps_time_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_gps_time_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_gps_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_gps_time_t *msg)
{
  if (!unpack_u16(ctx, &msg->wn)) { return false; }
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_gps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gps_time_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_gps_time_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_gps_time_t(struct sbp_state *s, u16 sender_id, const sbp_msg_gps_time_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_gps_time_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_GPS_TIME, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *a, const sbp_msg_gps_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_gps_time_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_gps_time_gnss_t *msg)
{
  if (!pack_u16(ctx, &msg->wn)) { return false; }
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_gps_time_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gps_time_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_gps_time_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_gps_time_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_gps_time_gnss_t *msg)
{
  if (!unpack_u16(ctx, &msg->wn)) { return false; }
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_gps_time_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gps_time_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_gps_time_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_gps_time_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_gps_time_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_gps_time_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_GPS_TIME_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *a, const sbp_msg_gps_time_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->year);
  packed_size += sbp_packed_size_u8(&msg->month);
  packed_size += sbp_packed_size_u8(&msg->day);
  packed_size += sbp_packed_size_u8(&msg->hours);
  packed_size += sbp_packed_size_u8(&msg->minutes);
  packed_size += sbp_packed_size_u8(&msg->seconds);
  packed_size += sbp_packed_size_u32(&msg->ns);
  return packed_size;
}

bool pack_sbp_msg_utc_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_utc_time_t *msg)
{
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->year)) { return false; }
  if (!pack_u8(ctx, &msg->month)) { return false; }
  if (!pack_u8(ctx, &msg->day)) { return false; }
  if (!pack_u8(ctx, &msg->hours)) { return false; }
  if (!pack_u8(ctx, &msg->minutes)) { return false; }
  if (!pack_u8(ctx, &msg->seconds)) { return false; }
  if (!pack_u32(ctx, &msg->ns)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_utc_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_utc_time_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_utc_time_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_utc_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_utc_time_t *msg)
{
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->year)) { return false; }
  if (!unpack_u8(ctx, &msg->month)) { return false; }
  if (!unpack_u8(ctx, &msg->day)) { return false; }
  if (!unpack_u8(ctx, &msg->hours)) { return false; }
  if (!unpack_u8(ctx, &msg->minutes)) { return false; }
  if (!unpack_u8(ctx, &msg->seconds)) { return false; }
  if (!unpack_u32(ctx, &msg->ns)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_utc_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_utc_time_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_utc_time_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_utc_time_t(struct sbp_state *s, u16 sender_id, const sbp_msg_utc_time_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_utc_time_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_UTC_TIME, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *a, const sbp_msg_utc_time_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->year, &b->year);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->month, &b->month);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->day, &b->day);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->hours, &b->hours);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->minutes, &b->minutes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seconds, &b->seconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->ns, &b->ns);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->year);
  packed_size += sbp_packed_size_u8(&msg->month);
  packed_size += sbp_packed_size_u8(&msg->day);
  packed_size += sbp_packed_size_u8(&msg->hours);
  packed_size += sbp_packed_size_u8(&msg->minutes);
  packed_size += sbp_packed_size_u8(&msg->seconds);
  packed_size += sbp_packed_size_u32(&msg->ns);
  return packed_size;
}

bool pack_sbp_msg_utc_time_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_utc_time_gnss_t *msg)
{
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->year)) { return false; }
  if (!pack_u8(ctx, &msg->month)) { return false; }
  if (!pack_u8(ctx, &msg->day)) { return false; }
  if (!pack_u8(ctx, &msg->hours)) { return false; }
  if (!pack_u8(ctx, &msg->minutes)) { return false; }
  if (!pack_u8(ctx, &msg->seconds)) { return false; }
  if (!pack_u32(ctx, &msg->ns)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_utc_time_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_utc_time_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_utc_time_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_utc_time_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_utc_time_gnss_t *msg)
{
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->year)) { return false; }
  if (!unpack_u8(ctx, &msg->month)) { return false; }
  if (!unpack_u8(ctx, &msg->day)) { return false; }
  if (!unpack_u8(ctx, &msg->hours)) { return false; }
  if (!unpack_u8(ctx, &msg->minutes)) { return false; }
  if (!unpack_u8(ctx, &msg->seconds)) { return false; }
  if (!unpack_u32(ctx, &msg->ns)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_utc_time_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_utc_time_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_utc_time_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_utc_time_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_utc_time_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_utc_time_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_UTC_TIME_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *a, const sbp_msg_utc_time_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->year, &b->year);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->month, &b->month);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->day, &b->day);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->hours, &b->hours);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->minutes, &b->minutes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->seconds, &b->seconds);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->ns, &b->ns);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->gdop);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->tdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_dops_t(sbp_pack_ctx_t *ctx, const sbp_msg_dops_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->gdop)) { return false; }
  if (!pack_u16(ctx, &msg->pdop)) { return false; }
  if (!pack_u16(ctx, &msg->tdop)) { return false; }
  if (!pack_u16(ctx, &msg->hdop)) { return false; }
  if (!pack_u16(ctx, &msg->vdop)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_dops_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dops_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_dops_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_dops_t(sbp_unpack_ctx_t *ctx, sbp_msg_dops_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->gdop)) { return false; }
  if (!unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!unpack_u16(ctx, &msg->tdop)) { return false; }
  if (!unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!unpack_u16(ctx, &msg->vdop)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_dops_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dops_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_dops_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_dops_t(struct sbp_state *s, u16 sender_id, const sbp_msg_dops_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_dops_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_DOPS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_dops_t(const sbp_msg_dops_t *a, const sbp_msg_dops_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->gdop, &b->gdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tdop, &b->tdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->x)) { return false; }
  if (!pack_double(ctx, &msg->y)) { return false; }
  if (!pack_double(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_ecef_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->x)) { return false; }
  if (!unpack_double(ctx, &msg->y)) { return false; }
  if (!unpack_double(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_ecef_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_ecef_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_ecef_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_ecef_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_ecef_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_ECEF, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *a, const sbp_msg_pos_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_ecef_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_cov_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->x)) { return false; }
  if (!pack_double(ctx, &msg->y)) { return false; }
  if (!pack_double(ctx, &msg->z)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_ecef_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_cov_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_ecef_cov_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_ecef_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_cov_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->x)) { return false; }
  if (!unpack_double(ctx, &msg->y)) { return false; }
  if (!unpack_double(ctx, &msg->z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_ecef_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_cov_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_ecef_cov_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_ecef_cov_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_ecef_cov_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_ecef_cov_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_ECEF_COV, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *a, const sbp_msg_pos_ecef_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_llh_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_llh_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_llh_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_llh_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_llh_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_llh_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_llh_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_llh_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_llh_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_LLH, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *a, const sbp_msg_pos_llh_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_llh_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_cov_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_llh_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_cov_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_llh_cov_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_llh_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_cov_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_llh_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_cov_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_llh_cov_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_llh_cov_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_llh_cov_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_llh_cov_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_LLH_COV, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *a, const sbp_msg_pos_llh_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_baseline_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ecef_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_baseline_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ecef_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_baseline_ecef_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_baseline_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ecef_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_baseline_ecef_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ecef_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_baseline_ecef_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_baseline_ecef_t(struct sbp_state *s, u16 sender_id, const sbp_msg_baseline_ecef_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_baseline_ecef_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_BASELINE_ECEF, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *a, const sbp_msg_baseline_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_baseline_ned_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ned_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_baseline_ned_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ned_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_baseline_ned_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_baseline_ned_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ned_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_baseline_ned_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ned_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_baseline_ned_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_baseline_ned_t(struct sbp_state *s, u16 sender_id, const sbp_msg_baseline_ned_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_baseline_ned_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_BASELINE_NED, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *a, const sbp_msg_baseline_ned_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ecef_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ecef_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ecef_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ecef_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ecef_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ecef_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ecef_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_ECEF, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *a, const sbp_msg_vel_ecef_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ecef_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_cov_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ecef_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_cov_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ecef_cov_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ecef_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_cov_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ecef_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_cov_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ecef_cov_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ecef_cov_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ecef_cov_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ecef_cov_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_ECEF_COV, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *a, const sbp_msg_vel_ecef_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ned_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ned_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ned_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ned_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ned_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ned_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ned_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ned_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ned_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_NED, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *a, const sbp_msg_vel_ned_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ned_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_cov_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ned_cov_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_cov_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ned_cov_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ned_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_cov_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ned_cov_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_cov_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ned_cov_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ned_cov_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ned_cov_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ned_cov_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_NED_COV, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *a, const sbp_msg_vel_ned_cov_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_ecef_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->x)) { return false; }
  if (!pack_double(ctx, &msg->y)) { return false; }
  if (!pack_double(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_ecef_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_ecef_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_ecef_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->x)) { return false; }
  if (!unpack_double(ctx, &msg->y)) { return false; }
  if (!unpack_double(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_ecef_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_ecef_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_ecef_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_ecef_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_ecef_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_ECEF_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *a, const sbp_msg_pos_ecef_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_ecef_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->x)) { return false; }
  if (!pack_double(ctx, &msg->y)) { return false; }
  if (!pack_double(ctx, &msg->z)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_cov_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_ecef_cov_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_ecef_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->x)) { return false; }
  if (!unpack_double(ctx, &msg->y)) { return false; }
  if (!unpack_double(ctx, &msg->z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_cov_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_ecef_cov_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_ecef_cov_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_ecef_cov_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_ECEF_COV_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *a, const sbp_msg_pos_ecef_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_llh_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_llh_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_llh_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_llh_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_llh_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_llh_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_llh_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_llh_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_llh_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_LLH_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *a, const sbp_msg_pos_llh_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_llh_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_cov_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_llh_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_cov_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_llh_cov_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_llh_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_cov_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_cov_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_llh_cov_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_llh_cov_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_llh_cov_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_llh_cov_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_LLH_COV_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *a, const sbp_msg_pos_llh_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ecef_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ecef_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ecef_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ecef_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ecef_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ecef_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ecef_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ecef_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ecef_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_ECEF_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *a, const sbp_msg_vel_ecef_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ecef_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_cov_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ecef_cov_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ecef_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_cov_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ecef_cov_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ecef_cov_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ecef_cov_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_ECEF_COV_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *a, const sbp_msg_vel_ecef_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ned_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ned_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ned_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ned_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ned_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ned_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ned_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ned_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ned_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_NED_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *a, const sbp_msg_vel_ned_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_float(&msg->cov_n_n);
  packed_size += sbp_packed_size_float(&msg->cov_n_e);
  packed_size += sbp_packed_size_float(&msg->cov_n_d);
  packed_size += sbp_packed_size_float(&msg->cov_e_e);
  packed_size += sbp_packed_size_float(&msg->cov_e_d);
  packed_size += sbp_packed_size_float(&msg->cov_d_d);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ned_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_cov_gnss_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ned_cov_gnss_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_cov_gnss_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ned_cov_gnss_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ned_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_cov_gnss_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_cov_gnss_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ned_cov_gnss_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ned_cov_gnss_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ned_cov_gnss_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ned_cov_gnss_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_NED_COV_GNSS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *a, const sbp_msg_vel_ned_cov_gnss_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_n, &b->cov_n_n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_e, &b->cov_n_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_n_d, &b->cov_n_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_e, &b->cov_e_e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_e_d, &b->cov_e_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_d_d, &b->cov_d_d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_float(&msg->cov_x_x);
  packed_size += sbp_packed_size_float(&msg->cov_x_y);
  packed_size += sbp_packed_size_float(&msg->cov_x_z);
  packed_size += sbp_packed_size_float(&msg->cov_y_y);
  packed_size += sbp_packed_size_float(&msg->cov_y_z);
  packed_size += sbp_packed_size_float(&msg->cov_z_z);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_body_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_body_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_body_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_body_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_body_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_body_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_body_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_body_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_body_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_body_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_body_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_body_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_body_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_BODY, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *a, const sbp_msg_vel_body_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_x, &b->cov_x_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_y, &b->cov_x_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_x_z, &b->cov_x_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_y, &b->cov_y_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_y_z, &b->cov_y_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cov_z_z, &b->cov_z_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->age);
  return packed_size;
}

bool pack_sbp_msg_age_corrections_t(sbp_pack_ctx_t *ctx, const sbp_msg_age_corrections_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->age)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_age_corrections_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_age_corrections_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_age_corrections_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_age_corrections_t(sbp_unpack_ctx_t *ctx, sbp_msg_age_corrections_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->age)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_age_corrections_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_age_corrections_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_age_corrections_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_age_corrections_t(struct sbp_state *s, u16 sender_id, const sbp_msg_age_corrections_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_age_corrections_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_AGE_CORRECTIONS, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *a, const sbp_msg_age_corrections_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->age, &b->age);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_gps_time_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_gps_time_dep_a_t *msg)
{
  if (!pack_u16(ctx, &msg->wn)) { return false; }
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_gps_time_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_gps_time_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_gps_time_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_gps_time_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_gps_time_dep_a_t *msg)
{
  if (!unpack_u16(ctx, &msg->wn)) { return false; }
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_gps_time_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_gps_time_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_gps_time_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_gps_time_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_gps_time_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_gps_time_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_GPS_TIME_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *a, const sbp_msg_gps_time_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->gdop);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->tdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  return packed_size;
}

bool pack_sbp_msg_dops_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_dops_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->gdop)) { return false; }
  if (!pack_u16(ctx, &msg->pdop)) { return false; }
  if (!pack_u16(ctx, &msg->tdop)) { return false; }
  if (!pack_u16(ctx, &msg->hdop)) { return false; }
  if (!pack_u16(ctx, &msg->vdop)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_dops_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_dops_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_dops_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_dops_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_dops_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->gdop)) { return false; }
  if (!unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!unpack_u16(ctx, &msg->tdop)) { return false; }
  if (!unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!unpack_u16(ctx, &msg->vdop)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_dops_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_dops_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_dops_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_dops_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_dops_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_dops_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_DOPS_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *a, const sbp_msg_dops_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->gdop, &b->gdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->tdop, &b->tdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->x);
  packed_size += sbp_packed_size_double(&msg->y);
  packed_size += sbp_packed_size_double(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_ecef_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->x)) { return false; }
  if (!pack_double(ctx, &msg->y)) { return false; }
  if (!pack_double(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_ecef_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_ecef_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_ecef_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_ecef_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->x)) { return false; }
  if (!unpack_double(ctx, &msg->y)) { return false; }
  if (!unpack_double(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_ecef_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_ecef_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_ecef_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_ecef_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_ecef_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_ecef_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_ECEF_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *a, const sbp_msg_pos_ecef_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_pos_llh_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_pos_llh_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_pos_llh_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_pos_llh_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_pos_llh_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_pos_llh_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_pos_llh_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_pos_llh_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_pos_llh_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_pos_llh_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_pos_llh_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_POS_LLH_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *a, const sbp_msg_pos_llh_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_baseline_ecef_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ecef_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_baseline_ecef_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ecef_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_baseline_ecef_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_baseline_ecef_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ecef_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ecef_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_baseline_ecef_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_baseline_ecef_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_baseline_ecef_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_baseline_ecef_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_BASELINE_ECEF_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *a, const sbp_msg_baseline_ecef_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_baseline_ned_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ned_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_baseline_ned_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_ned_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_baseline_ned_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_baseline_ned_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ned_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_baseline_ned_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_ned_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_baseline_ned_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_baseline_ned_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_baseline_ned_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_baseline_ned_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_BASELINE_NED_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *a, const sbp_msg_baseline_ned_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->x);
  packed_size += sbp_packed_size_s32(&msg->y);
  packed_size += sbp_packed_size_s32(&msg->z);
  packed_size += sbp_packed_size_u16(&msg->accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ecef_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->x)) { return false; }
  if (!pack_s32(ctx, &msg->y)) { return false; }
  if (!pack_s32(ctx, &msg->z)) { return false; }
  if (!pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ecef_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ecef_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ecef_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ecef_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->x)) { return false; }
  if (!unpack_s32(ctx, &msg->y)) { return false; }
  if (!unpack_s32(ctx, &msg->z)) { return false; }
  if (!unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ecef_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ecef_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ecef_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ecef_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ecef_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ecef_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_ECEF_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *a, const sbp_msg_vel_ecef_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->x, &b->x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->y, &b->y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->z, &b->z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->accuracy, &b->accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->n);
  packed_size += sbp_packed_size_s32(&msg->e);
  packed_size += sbp_packed_size_s32(&msg->d);
  packed_size += sbp_packed_size_u16(&msg->h_accuracy);
  packed_size += sbp_packed_size_u16(&msg->v_accuracy);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_vel_ned_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->n)) { return false; }
  if (!pack_s32(ctx, &msg->e)) { return false; }
  if (!pack_s32(ctx, &msg->d)) { return false; }
  if (!pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_vel_ned_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_vel_ned_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_vel_ned_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_vel_ned_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->n)) { return false; }
  if (!unpack_s32(ctx, &msg->e)) { return false; }
  if (!unpack_s32(ctx, &msg->d)) { return false; }
  if (!unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_vel_ned_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_vel_ned_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_vel_ned_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_vel_ned_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_vel_ned_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_vel_ned_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_VEL_NED_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *a, const sbp_msg_vel_ned_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->n, &b->n);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->e, &b->e);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->d, &b->d);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->h_accuracy, &b->h_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->v_accuracy, &b->v_accuracy);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u32(&msg->heading);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_baseline_heading_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_heading_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u32(ctx, &msg->heading)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_baseline_heading_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_heading_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_baseline_heading_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_baseline_heading_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_heading_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u32(ctx, &msg->heading)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_baseline_heading_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_heading_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_baseline_heading_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_baseline_heading_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_baseline_heading_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_baseline_heading_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_BASELINE_HEADING_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *a, const sbp_msg_baseline_heading_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->heading, &b->heading);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->vpl);
  packed_size += sbp_packed_size_u16(&msg->hpl);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_protection_level_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_protection_level_dep_a_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->vpl)) { return false; }
  if (!pack_u16(ctx, &msg->hpl)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_protection_level_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_protection_level_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_protection_level_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_protection_level_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_protection_level_dep_a_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->vpl)) { return false; }
  if (!unpack_u16(ctx, &msg->hpl)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_protection_level_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_protection_level_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_protection_level_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_protection_level_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_protection_level_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_protection_level_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_PROTECTION_LEVEL_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *a, const sbp_msg_protection_level_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vpl, &b->vpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hpl, &b->hpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s16(&msg->wn);
  packed_size += sbp_packed_size_u16(&msg->hpl);
  packed_size += sbp_packed_size_u16(&msg->vpl);
  packed_size += sbp_packed_size_u16(&msg->atpl);
  packed_size += sbp_packed_size_u16(&msg->ctpl);
  packed_size += sbp_packed_size_u16(&msg->hvpl);
  packed_size += sbp_packed_size_u16(&msg->vvpl);
  packed_size += sbp_packed_size_u16(&msg->hopl);
  packed_size += sbp_packed_size_u16(&msg->popl);
  packed_size += sbp_packed_size_u16(&msg->ropl);
  packed_size += sbp_packed_size_double(&msg->lat);
  packed_size += sbp_packed_size_double(&msg->lon);
  packed_size += sbp_packed_size_double(&msg->height);
  packed_size += sbp_packed_size_s32(&msg->v_x);
  packed_size += sbp_packed_size_s32(&msg->v_y);
  packed_size += sbp_packed_size_s32(&msg->v_z);
  packed_size += sbp_packed_size_s32(&msg->roll);
  packed_size += sbp_packed_size_s32(&msg->pitch);
  packed_size += sbp_packed_size_s32(&msg->heading);
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_protection_level_t(sbp_pack_ctx_t *ctx, const sbp_msg_protection_level_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s16(ctx, &msg->wn)) { return false; }
  if (!pack_u16(ctx, &msg->hpl)) { return false; }
  if (!pack_u16(ctx, &msg->vpl)) { return false; }
  if (!pack_u16(ctx, &msg->atpl)) { return false; }
  if (!pack_u16(ctx, &msg->ctpl)) { return false; }
  if (!pack_u16(ctx, &msg->hvpl)) { return false; }
  if (!pack_u16(ctx, &msg->vvpl)) { return false; }
  if (!pack_u16(ctx, &msg->hopl)) { return false; }
  if (!pack_u16(ctx, &msg->popl)) { return false; }
  if (!pack_u16(ctx, &msg->ropl)) { return false; }
  if (!pack_double(ctx, &msg->lat)) { return false; }
  if (!pack_double(ctx, &msg->lon)) { return false; }
  if (!pack_double(ctx, &msg->height)) { return false; }
  if (!pack_s32(ctx, &msg->v_x)) { return false; }
  if (!pack_s32(ctx, &msg->v_y)) { return false; }
  if (!pack_s32(ctx, &msg->v_z)) { return false; }
  if (!pack_s32(ctx, &msg->roll)) { return false; }
  if (!pack_s32(ctx, &msg->pitch)) { return false; }
  if (!pack_s32(ctx, &msg->heading)) { return false; }
  if (!pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_protection_level_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_protection_level_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_protection_level_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_protection_level_t(sbp_unpack_ctx_t *ctx, sbp_msg_protection_level_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s16(ctx, &msg->wn)) { return false; }
  if (!unpack_u16(ctx, &msg->hpl)) { return false; }
  if (!unpack_u16(ctx, &msg->vpl)) { return false; }
  if (!unpack_u16(ctx, &msg->atpl)) { return false; }
  if (!unpack_u16(ctx, &msg->ctpl)) { return false; }
  if (!unpack_u16(ctx, &msg->hvpl)) { return false; }
  if (!unpack_u16(ctx, &msg->vvpl)) { return false; }
  if (!unpack_u16(ctx, &msg->hopl)) { return false; }
  if (!unpack_u16(ctx, &msg->popl)) { return false; }
  if (!unpack_u16(ctx, &msg->ropl)) { return false; }
  if (!unpack_double(ctx, &msg->lat)) { return false; }
  if (!unpack_double(ctx, &msg->lon)) { return false; }
  if (!unpack_double(ctx, &msg->height)) { return false; }
  if (!unpack_s32(ctx, &msg->v_x)) { return false; }
  if (!unpack_s32(ctx, &msg->v_y)) { return false; }
  if (!unpack_s32(ctx, &msg->v_z)) { return false; }
  if (!unpack_s32(ctx, &msg->roll)) { return false; }
  if (!unpack_s32(ctx, &msg->pitch)) { return false; }
  if (!unpack_s32(ctx, &msg->heading)) { return false; }
  if (!unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_protection_level_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_protection_level_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_protection_level_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_protection_level_t(struct sbp_state *s, u16 sender_id, const sbp_msg_protection_level_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_protection_level_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_payload(s, SBP_MSG_PROTECTION_LEVEL, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *a, const sbp_msg_protection_level_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hpl, &b->hpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vpl, &b->vpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->atpl, &b->atpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->ctpl, &b->ctpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hvpl, &b->hvpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vvpl, &b->vvpl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hopl, &b->hopl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->popl, &b->popl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->ropl, &b->ropl);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lat, &b->lat);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->lon, &b->lon);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_double(&a->height, &b->height);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->v_x, &b->v_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->v_y, &b->v_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->v_z, &b->v_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->roll, &b->roll);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->pitch, &b->pitch);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->heading, &b->heading);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
