#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/new/acquisition.h>
#include <libsbp/internal/new/acquisition.h>
#include <libsbp/internal/new/string/multipart.h>
#include <libsbp/internal/new/string/null_terminated.h>
#include <libsbp/internal/new/string/double_null_terminated.h>
#include <libsbp/internal/new/string/unterminated.h>

size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_msg_acq_result_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_t *msg)
{
  if (!encode_float(ctx, &msg->cn0)) { return false; }
  if (!encode_float(ctx, &msg->cp)) { return false; }
  if (!encode_float(ctx, &msg->cf)) { return false; }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_acq_result_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_acq_result_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_acq_result_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_t *msg)
{
  if (!decode_float(ctx, &msg->cn0)) { return false; }
  if (!decode_float(ctx, &msg->cp)) { return false; }
  if (!decode_float(ctx, &msg->cf)) { return false; }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_acq_result_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_acq_result_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_acq_result_t(struct sbp_state *s, u16 sender_id, const sbp_msg_acq_result_t *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_acq_result_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *a, const sbp_msg_acq_result_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_msg_acq_result_dep_c_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_c_t *msg)
{
  if (!encode_float(ctx, &msg->cn0)) { return false; }
  if (!encode_float(ctx, &msg->cp)) { return false; }
  if (!encode_float(ctx, &msg->cf)) { return false; }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_acq_result_dep_c_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_dep_c_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_acq_result_dep_c_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_acq_result_dep_c_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_dep_c_t *msg)
{
  if (!decode_float(ctx, &msg->cn0)) { return false; }
  if (!decode_float(ctx, &msg->cp)) { return false; }
  if (!decode_float(ctx, &msg->cf)) { return false; }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_acq_result_dep_c_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_dep_c_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_acq_result_dep_c_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_acq_result_dep_c_t(struct sbp_state *s, u16 sender_id, const sbp_msg_acq_result_dep_c_t *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_acq_result_dep_c_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT_DEP_C, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *a, const sbp_msg_acq_result_dep_c_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->snr);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

bool encode_sbp_msg_acq_result_dep_b_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_b_t *msg)
{
  if (!encode_float(ctx, &msg->snr)) { return false; }
  if (!encode_float(ctx, &msg->cp)) { return false; }
  if (!encode_float(ctx, &msg->cf)) { return false; }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_acq_result_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_dep_b_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_acq_result_dep_b_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_acq_result_dep_b_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_dep_b_t *msg)
{
  if (!decode_float(ctx, &msg->snr)) { return false; }
  if (!decode_float(ctx, &msg->cp)) { return false; }
  if (!decode_float(ctx, &msg->cf)) { return false; }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_acq_result_dep_b_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_dep_b_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_acq_result_dep_b_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_acq_result_dep_b_t(struct sbp_state *s, u16 sender_id, const sbp_msg_acq_result_dep_b_t *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_acq_result_dep_b_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT_DEP_B, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *a, const sbp_msg_acq_result_dep_b_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->snr, &b->snr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->snr);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

bool encode_sbp_msg_acq_result_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_result_dep_a_t *msg)
{
  if (!encode_float(ctx, &msg->snr)) { return false; }
  if (!encode_float(ctx, &msg->cp)) { return false; }
  if (!encode_float(ctx, &msg->cf)) { return false; }
  if (!encode_u8(ctx, &msg->prn)) { return false; }
  return true;
}

s8 sbp_encode_sbp_msg_acq_result_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_acq_result_dep_a_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_acq_result_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_result_dep_a_t *msg)
{
  if (!decode_float(ctx, &msg->snr)) { return false; }
  if (!decode_float(ctx, &msg->cp)) { return false; }
  if (!decode_float(ctx, &msg->cf)) { return false; }
  if (!decode_u8(ctx, &msg->prn)) { return false; }
  return true;
}

s8 sbp_decode_sbp_msg_acq_result_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_acq_result_dep_a_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_acq_result_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_acq_result_dep_a_t *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_acq_result_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_ACQ_RESULT_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *a, const sbp_msg_acq_result_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->snr, &b->snr);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->prn, &b->prn);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->job_type);
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_packed_size_u16(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->int_time);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u16(&msg->bin_width);
  packed_size += sbp_packed_size_u32(&msg->timestamp);
  packed_size += sbp_packed_size_u32(&msg->time_spent);
  packed_size += sbp_packed_size_s32(&msg->cf_min);
  packed_size += sbp_packed_size_s32(&msg->cf_max);
  packed_size += sbp_packed_size_s32(&msg->cf);
  packed_size += sbp_packed_size_u32(&msg->cp);
  return packed_size;
}

bool encode_sbp_acq_sv_profile_t(sbp_encode_ctx_t *ctx, const sbp_acq_sv_profile_t *msg)
{
  if (!encode_u8(ctx, &msg->job_type)) { return false; }
  if (!encode_u8(ctx, &msg->status)) { return false; }
  if (!encode_u16(ctx, &msg->cn0)) { return false; }
  if (!encode_u8(ctx, &msg->int_time)) { return false; }
  if (!encode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!encode_u16(ctx, &msg->bin_width)) { return false; }
  if (!encode_u32(ctx, &msg->timestamp)) { return false; }
  if (!encode_u32(ctx, &msg->time_spent)) { return false; }
  if (!encode_s32(ctx, &msg->cf_min)) { return false; }
  if (!encode_s32(ctx, &msg->cf_max)) { return false; }
  if (!encode_s32(ctx, &msg->cf)) { return false; }
  if (!encode_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_encode_sbp_acq_sv_profile_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_acq_sv_profile_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_acq_sv_profile_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_acq_sv_profile_t(sbp_decode_ctx_t *ctx, sbp_acq_sv_profile_t *msg)
{
  if (!decode_u8(ctx, &msg->job_type)) { return false; }
  if (!decode_u8(ctx, &msg->status)) { return false; }
  if (!decode_u16(ctx, &msg->cn0)) { return false; }
  if (!decode_u8(ctx, &msg->int_time)) { return false; }
  if (!decode_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!decode_u16(ctx, &msg->bin_width)) { return false; }
  if (!decode_u32(ctx, &msg->timestamp)) { return false; }
  if (!decode_u32(ctx, &msg->time_spent)) { return false; }
  if (!decode_s32(ctx, &msg->cf_min)) { return false; }
  if (!decode_s32(ctx, &msg->cf_max)) { return false; }
  if (!decode_s32(ctx, &msg->cf)) { return false; }
  if (!decode_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_decode_sbp_acq_sv_profile_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_acq_sv_profile_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_acq_sv_profile_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *a, const sbp_acq_sv_profile_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->job_type, &b->job_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->int_time, &b->int_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->bin_width, &b->bin_width);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->timestamp, &b->timestamp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time_spent, &b->time_spent);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_min, &b->cf_min);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_max, &b->cf_max);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->job_type);
  packed_size += sbp_packed_size_u8(&msg->status);
  packed_size += sbp_packed_size_u16(&msg->cn0);
  packed_size += sbp_packed_size_u8(&msg->int_time);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  packed_size += sbp_packed_size_u16(&msg->bin_width);
  packed_size += sbp_packed_size_u32(&msg->timestamp);
  packed_size += sbp_packed_size_u32(&msg->time_spent);
  packed_size += sbp_packed_size_s32(&msg->cf_min);
  packed_size += sbp_packed_size_s32(&msg->cf_max);
  packed_size += sbp_packed_size_s32(&msg->cf);
  packed_size += sbp_packed_size_u32(&msg->cp);
  return packed_size;
}

bool encode_sbp_acq_sv_profile_dep_t(sbp_encode_ctx_t *ctx, const sbp_acq_sv_profile_dep_t *msg)
{
  if (!encode_u8(ctx, &msg->job_type)) { return false; }
  if (!encode_u8(ctx, &msg->status)) { return false; }
  if (!encode_u16(ctx, &msg->cn0)) { return false; }
  if (!encode_u8(ctx, &msg->int_time)) { return false; }
  if (!encode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!encode_u16(ctx, &msg->bin_width)) { return false; }
  if (!encode_u32(ctx, &msg->timestamp)) { return false; }
  if (!encode_u32(ctx, &msg->time_spent)) { return false; }
  if (!encode_s32(ctx, &msg->cf_min)) { return false; }
  if (!encode_s32(ctx, &msg->cf_max)) { return false; }
  if (!encode_s32(ctx, &msg->cf)) { return false; }
  if (!encode_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_encode_sbp_acq_sv_profile_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_acq_sv_profile_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx, sbp_acq_sv_profile_dep_t *msg)
{
  if (!decode_u8(ctx, &msg->job_type)) { return false; }
  if (!decode_u8(ctx, &msg->status)) { return false; }
  if (!decode_u16(ctx, &msg->cn0)) { return false; }
  if (!decode_u8(ctx, &msg->int_time)) { return false; }
  if (!decode_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!decode_u16(ctx, &msg->bin_width)) { return false; }
  if (!decode_u32(ctx, &msg->timestamp)) { return false; }
  if (!decode_u32(ctx, &msg->time_spent)) { return false; }
  if (!decode_s32(ctx, &msg->cf_min)) { return false; }
  if (!decode_s32(ctx, &msg->cf_max)) { return false; }
  if (!decode_s32(ctx, &msg->cf)) { return false; }
  if (!decode_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_decode_sbp_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_acq_sv_profile_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *a, const sbp_acq_sv_profile_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->job_type, &b->job_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->cn0, &b->cn0);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->int_time, &b->int_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->bin_width, &b->bin_width);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->timestamp, &b->timestamp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->time_spent, &b->time_spent);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_min, &b->cf_min);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf_max, &b->cf_max);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->cf, &b->cf);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->cp, &b->cp);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_acq_sv_profile * sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  return packed_size;
}

bool encode_sbp_msg_acq_sv_profile_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_t *msg)
{
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    if (!encode_sbp_acq_sv_profile_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_acq_sv_profile_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_sv_profile_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_acq_sv_profile_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_acq_sv_profile_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_sv_profile_t *msg)
{
    msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!decode_sbp_acq_sv_profile_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_acq_sv_profile_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_sv_profile_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_acq_sv_profile_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_acq_sv_profile_t(struct sbp_state *s, u16 sender_id, const sbp_msg_acq_sv_profile_t *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_acq_sv_profile_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_ACQ_SV_PROFILE, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *a, const sbp_msg_acq_sv_profile_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_acq_sv_profile, &b->n_acq_sv_profile);
  for (uint8_t i = 0; i < a->n_acq_sv_profile && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_acq_sv_profile_t(&a->acq_sv_profile[i], &b->acq_sv_profile[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_acq_sv_profile * sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  return packed_size;
}

bool encode_sbp_msg_acq_sv_profile_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg)
{
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    if (!encode_sbp_acq_sv_profile_dep_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_encode_sbp_msg_acq_sv_profile_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_sv_profile_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!encode_sbp_msg_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool decode_sbp_msg_acq_sv_profile_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_acq_sv_profile_dep_t *msg)
{
    msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!decode_sbp_acq_sv_profile_dep_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_decode_sbp_msg_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_sv_profile_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!decode_sbp_msg_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_acq_sv_profile_dep_t(struct sbp_state *s, u16 sender_id, const sbp_msg_acq_sv_profile_dep_t *msg, sbp_write_fn_t write)
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_encode_sbp_msg_acq_sv_profile_dep_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_payload_send(s, SBP_MSG_ACQ_SV_PROFILE_DEP, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *a, const sbp_msg_acq_sv_profile_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_acq_sv_profile, &b->n_acq_sv_profile);
  for (uint8_t i = 0; i < a->n_acq_sv_profile && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_acq_sv_profile_dep_t(&a->acq_sv_profile[i], &b->acq_sv_profile[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
