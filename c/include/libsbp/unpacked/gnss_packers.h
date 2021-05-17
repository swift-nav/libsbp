#ifndef LIBSBP_GNSS_PACKERS_H
#define LIBSBP_GNSS_PACKERS_H

#ifndef LIBSBP_GNSS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/gnss.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->sat);
  packed_size += sbp_packed_size_u8(&msg->code);
  return packed_size;
}

static inline bool sbp_pack_sbp_sbp_gnss_signal_t(sbp_pack_ctx_t *ctx, const sbp_sbp_gnss_signal_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->sat)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->code)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_sbp_gnss_signal_t(sbp_unpack_ctx_t *ctx, sbp_sbp_gnss_signal_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->sat)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->code)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->satId);
  packed_size += sbp_packed_size_u8(&msg->constellation);
  return packed_size;
}

static inline bool sbp_pack_sbp_sv_id_t(sbp_pack_ctx_t *ctx, const sbp_sv_id_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->satId)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->constellation)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_sv_id_t(sbp_unpack_ctx_t *ctx, sbp_sv_id_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->satId)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->constellation)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->sat);
  packed_size += sbp_packed_size_u8(&msg->code);
  packed_size += sbp_packed_size_u8(&msg->reserved);
  return packed_size;
}

static inline bool sbp_pack_sbp_gnss_signal_dep_t(sbp_pack_ctx_t *ctx, const sbp_gnss_signal_dep_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->sat)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->code)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->reserved)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gnss_signal_dep_t(sbp_unpack_ctx_t *ctx, sbp_gnss_signal_dep_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->sat)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->code)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->reserved)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

static inline bool sbp_pack_sbp_gps_time_dep_t(sbp_pack_ctx_t *ctx, const sbp_gps_time_dep_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gps_time_dep_t(sbp_unpack_ctx_t *ctx, sbp_gps_time_dep_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

static inline bool sbp_pack_sbp_gps_time_sec_t(sbp_pack_ctx_t *ctx, const sbp_gps_time_sec_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gps_time_sec_t(sbp_unpack_ctx_t *ctx, sbp_gps_time_sec_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u16(&msg->wn);
  return packed_size;
}

static inline bool sbp_pack_sbp_sbp_gps_time_t(sbp_pack_ctx_t *ctx, const sbp_sbp_gps_time_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_sbp_gps_time_t(sbp_unpack_ctx_t *ctx, sbp_sbp_gps_time_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->i);
  packed_size += sbp_packed_size_u8(&msg->f);
  return packed_size;
}

static inline bool sbp_pack_sbp_carrier_phase_t(sbp_pack_ctx_t *ctx, const sbp_carrier_phase_t *msg)
{
  if (!sbp_pack_s32(ctx, &msg->i)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->f)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_carrier_phase_t(sbp_unpack_ctx_t *ctx, sbp_carrier_phase_t *msg)
{
  if (!sbp_unpack_s32(ctx, &msg->i)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->f)) { return false; }
  return true;
}

#endif
