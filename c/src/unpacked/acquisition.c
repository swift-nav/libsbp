#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/acquisition.h>
#include <libsbp/internal/unpacked/acquisition.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
#include <libsbp/internal/unpacked/string/binary.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

bool pack_sbp_msg_acq_result_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_t *msg)
{
  if (!pack_float(ctx, &msg->cn0)) { return false; }
  if (!pack_float(ctx, &msg->cp)) { return false; }
  if (!pack_float(ctx, &msg->cf)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_acq_result_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_acq_result_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_acq_result_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_t *msg)
{
  if (!unpack_float(ctx, &msg->cn0)) { return false; }
  if (!unpack_float(ctx, &msg->cp)) { return false; }
  if (!unpack_float(ctx, &msg->cf)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_acq_result_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_acq_result_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_acq_result_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_dep_c_t *msg)
{
  if (!pack_float(ctx, &msg->cn0)) { return false; }
  if (!pack_float(ctx, &msg->cp)) { return false; }
  if (!pack_float(ctx, &msg->cf)) { return false; }
  if (!pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_acq_result_dep_c_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_dep_c_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_acq_result_dep_c_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_acq_result_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_dep_c_t *msg)
{
  if (!unpack_float(ctx, &msg->cn0)) { return false; }
  if (!unpack_float(ctx, &msg->cp)) { return false; }
  if (!unpack_float(ctx, &msg->cf)) { return false; }
  if (!unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_acq_result_dep_c_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_dep_c_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_acq_result_dep_c_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_acq_result_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_dep_b_t *msg)
{
  if (!pack_float(ctx, &msg->snr)) { return false; }
  if (!pack_float(ctx, &msg->cp)) { return false; }
  if (!pack_float(ctx, &msg->cf)) { return false; }
  if (!pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_acq_result_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_dep_b_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_acq_result_dep_b_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_acq_result_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_dep_b_t *msg)
{
  if (!unpack_float(ctx, &msg->snr)) { return false; }
  if (!unpack_float(ctx, &msg->cp)) { return false; }
  if (!unpack_float(ctx, &msg->cf)) { return false; }
  if (!unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_acq_result_dep_b_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_dep_b_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_acq_result_dep_b_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_acq_result_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_dep_a_t *msg)
{
  if (!pack_float(ctx, &msg->snr)) { return false; }
  if (!pack_float(ctx, &msg->cp)) { return false; }
  if (!pack_float(ctx, &msg->cf)) { return false; }
  if (!pack_u8(ctx, &msg->prn)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_acq_result_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_result_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_acq_result_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_acq_result_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_dep_a_t *msg)
{
  if (!unpack_float(ctx, &msg->snr)) { return false; }
  if (!unpack_float(ctx, &msg->cp)) { return false; }
  if (!unpack_float(ctx, &msg->cf)) { return false; }
  if (!unpack_u8(ctx, &msg->prn)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_acq_result_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_result_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_acq_result_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_acq_sv_profile_t(sbp_pack_ctx_t *ctx, const sbp_acq_sv_profile_t *msg)
{
  if (!pack_u8(ctx, &msg->job_type)) { return false; }
  if (!pack_u8(ctx, &msg->status)) { return false; }
  if (!pack_u16(ctx, &msg->cn0)) { return false; }
  if (!pack_u8(ctx, &msg->int_time)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!pack_u16(ctx, &msg->bin_width)) { return false; }
  if (!pack_u32(ctx, &msg->timestamp)) { return false; }
  if (!pack_u32(ctx, &msg->time_spent)) { return false; }
  if (!pack_s32(ctx, &msg->cf_min)) { return false; }
  if (!pack_s32(ctx, &msg->cf_max)) { return false; }
  if (!pack_s32(ctx, &msg->cf)) { return false; }
  if (!pack_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_pack_sbp_acq_sv_profile_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_acq_sv_profile_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_acq_sv_profile_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_acq_sv_profile_t(sbp_unpack_ctx_t *ctx, sbp_acq_sv_profile_t *msg)
{
  if (!unpack_u8(ctx, &msg->job_type)) { return false; }
  if (!unpack_u8(ctx, &msg->status)) { return false; }
  if (!unpack_u16(ctx, &msg->cn0)) { return false; }
  if (!unpack_u8(ctx, &msg->int_time)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u16(ctx, &msg->bin_width)) { return false; }
  if (!unpack_u32(ctx, &msg->timestamp)) { return false; }
  if (!unpack_u32(ctx, &msg->time_spent)) { return false; }
  if (!unpack_s32(ctx, &msg->cf_min)) { return false; }
  if (!unpack_s32(ctx, &msg->cf_max)) { return false; }
  if (!unpack_s32(ctx, &msg->cf)) { return false; }
  if (!unpack_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_acq_sv_profile_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_acq_sv_profile_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_acq_sv_profile_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
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

bool pack_sbp_acq_sv_profile_dep_t(sbp_pack_ctx_t *ctx, const sbp_acq_sv_profile_dep_t *msg)
{
  if (!pack_u8(ctx, &msg->job_type)) { return false; }
  if (!pack_u8(ctx, &msg->status)) { return false; }
  if (!pack_u16(ctx, &msg->cn0)) { return false; }
  if (!pack_u8(ctx, &msg->int_time)) { return false; }
  if (!pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!pack_u16(ctx, &msg->bin_width)) { return false; }
  if (!pack_u32(ctx, &msg->timestamp)) { return false; }
  if (!pack_u32(ctx, &msg->time_spent)) { return false; }
  if (!pack_s32(ctx, &msg->cf_min)) { return false; }
  if (!pack_s32(ctx, &msg->cf_max)) { return false; }
  if (!pack_s32(ctx, &msg->cf)) { return false; }
  if (!pack_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_pack_sbp_acq_sv_profile_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_acq_sv_profile_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_acq_sv_profile_dep_t(sbp_unpack_ctx_t *ctx, sbp_acq_sv_profile_dep_t *msg)
{
  if (!unpack_u8(ctx, &msg->job_type)) { return false; }
  if (!unpack_u8(ctx, &msg->status)) { return false; }
  if (!unpack_u16(ctx, &msg->cn0)) { return false; }
  if (!unpack_u8(ctx, &msg->int_time)) { return false; }
  if (!unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!unpack_u16(ctx, &msg->bin_width)) { return false; }
  if (!unpack_u32(ctx, &msg->timestamp)) { return false; }
  if (!unpack_u32(ctx, &msg->time_spent)) { return false; }
  if (!unpack_s32(ctx, &msg->cf_min)) { return false; }
  if (!unpack_s32(ctx, &msg->cf_max)) { return false; }
  if (!unpack_s32(ctx, &msg->cf)) { return false; }
  if (!unpack_u32(ctx, &msg->cp)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_acq_sv_profile_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
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

bool pack_sbp_msg_acq_sv_profile_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_sv_profile_t *msg)
{
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    if (!pack_sbp_acq_sv_profile_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_acq_sv_profile_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_sv_profile_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_acq_sv_profile_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_acq_sv_profile_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_sv_profile_t *msg)
{
    msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!unpack_sbp_acq_sv_profile_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_acq_sv_profile_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_sv_profile_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_acq_sv_profile_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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

bool pack_sbp_msg_acq_sv_profile_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg)
{
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    if (!pack_sbp_acq_sv_profile_dep_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_acq_sv_profile_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_acq_sv_profile_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_acq_sv_profile_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_sv_profile_dep_t *msg)
{
    msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!unpack_sbp_acq_sv_profile_dep_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_acq_sv_profile_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_acq_sv_profile_dep_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
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
