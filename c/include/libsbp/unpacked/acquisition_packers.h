#ifndef LIBSBP_ACQUISITION_PACKERS_H
#define LIBSBP_ACQUISITION_PACKERS_H

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/acquisition.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_t *msg)
{
  if (!sbp_pack_float(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_t *msg)
{
  if (!sbp_unpack_float(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->cn0);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_c_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_dep_c_t *msg)
{
  if (!sbp_pack_float(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_c_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_dep_c_t *msg)
{
  if (!sbp_unpack_float(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->snr);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_dep_b_t *msg)
{
  if (!sbp_pack_float(ctx, &msg->snr)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_dep_b_t *msg)
{
  if (!sbp_unpack_float(ctx, &msg->snr)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->snr);
  packed_size += sbp_packed_size_float(&msg->cp);
  packed_size += sbp_packed_size_float(&msg->cf);
  packed_size += sbp_packed_size_u8(&msg->prn);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_result_dep_a_t *msg)
{
  if (!sbp_pack_float(ctx, &msg->snr)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->prn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_result_dep_a_t *msg)
{
  if (!sbp_unpack_float(ctx, &msg->snr)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cp)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cf)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->prn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *msg) {
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

static inline bool sbp_pack_sbp_acq_sv_profile_t(sbp_pack_ctx_t *ctx, const sbp_acq_sv_profile_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->job_type)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->int_time)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->bin_width)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->timestamp)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->time_spent)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cf_min)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cf_max)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cf)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->cp)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_acq_sv_profile_t(sbp_unpack_ctx_t *ctx, sbp_acq_sv_profile_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->job_type)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->int_time)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->bin_width)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->timestamp)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->time_spent)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cf_min)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cf_max)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cf)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->cp)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *msg) {
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

static inline bool sbp_pack_sbp_acq_sv_profile_dep_t(sbp_pack_ctx_t *ctx, const sbp_acq_sv_profile_dep_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->job_type)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->cn0)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->int_time)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->bin_width)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->timestamp)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->time_spent)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cf_min)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cf_max)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->cf)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->cp)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_acq_sv_profile_dep_t(sbp_unpack_ctx_t *ctx, sbp_acq_sv_profile_dep_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->job_type)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->status)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->cn0)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->int_time)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->bin_width)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->timestamp)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->time_spent)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cf_min)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cf_max)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->cf)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->cp)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_acq_sv_profile * sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_sv_profile_t *msg)
{
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    if (!sbp_pack_sbp_acq_sv_profile_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_sv_profile_t *msg)
{
    msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_acq_sv_profile_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!sbp_unpack_sbp_acq_sv_profile_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_acq_sv_profile * sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_acq_sv_profile_dep_t *msg)
{
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++)
  {
    if (!sbp_pack_sbp_acq_sv_profile_dep_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_acq_sv_profile_dep_t *msg)
{
    msg->n_acq_sv_profile = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_acq_sv_profile_dep_t(&msg->acq_sv_profile[0]));
  for (uint8_t i = 0; i < msg->n_acq_sv_profile; i++) {
    if (!sbp_unpack_sbp_acq_sv_profile_dep_t(ctx, &msg->acq_sv_profile[i])) { return false; }
  }
  return true;
}

#endif
