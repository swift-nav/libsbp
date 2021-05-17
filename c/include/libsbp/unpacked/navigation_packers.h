#ifndef LIBSBP_NAVIGATION_PACKERS_H
#define LIBSBP_NAVIGATION_PACKERS_H

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/navigation.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gps_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_gps_time_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_gps_time_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gps_time_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_gps_time_gnss_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_gps_time_gnss_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg) {
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

static inline bool sbp_pack_sbp_msg_utc_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_utc_time_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->year)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->month)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->day)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->hours)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->minutes)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->seconds)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->ns)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_utc_time_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->year)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->month)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->day)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->hours)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->minutes)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->seconds)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->ns)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_utc_time_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_utc_time_gnss_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->year)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->month)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->day)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->hours)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->minutes)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->seconds)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->ns)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_utc_time_gnss_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->year)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->month)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->day)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->hours)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->minutes)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->seconds)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->ns)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg) {
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

static inline bool sbp_pack_sbp_msg_dops_t(sbp_pack_ctx_t *ctx, const sbp_msg_dops_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->gdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->tdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vdop)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_t(sbp_unpack_ctx_t *ctx, sbp_msg_dops_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->gdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->tdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vdop)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->x)) { return false; }
  if (!sbp_pack_double(ctx, &msg->y)) { return false; }
  if (!sbp_pack_double(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_cov_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->x)) { return false; }
  if (!sbp_pack_double(ctx, &msg->y)) { return false; }
  if (!sbp_pack_double(ctx, &msg->z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_cov_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_llh_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_llh_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_cov_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_cov_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg) {
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

static inline bool sbp_pack_sbp_msg_baseline_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ecef_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ecef_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg) {
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

static inline bool sbp_pack_sbp_msg_baseline_ned_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ned_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ned_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ecef_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_cov_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_cov_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ned_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ned_cov_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_cov_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_cov_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_ecef_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->x)) { return false; }
  if (!sbp_pack_double(ctx, &msg->y)) { return false; }
  if (!sbp_pack_double(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->x)) { return false; }
  if (!sbp_pack_double(ctx, &msg->y)) { return false; }
  if (!sbp_pack_double(ctx, &msg->z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_llh_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_llh_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_cov_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_cov_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ecef_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ned_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ned_cov_gnss_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_cov_gnss_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_cov_gnss_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_n)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_n_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_e)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_e_d)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_d_d)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_body_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_body_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_pack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_body_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_body_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_x)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_x_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_y)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_y_z)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->cov_z_z)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->age);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_age_corrections_t(sbp_pack_ctx_t *ctx, const sbp_msg_age_corrections_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->age)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_age_corrections_t(sbp_unpack_ctx_t *ctx, sbp_msg_age_corrections_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->age)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_gps_time_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_gps_time_dep_a_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_gps_time_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_gps_time_dep_a_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->gdop);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->tdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_dops_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_dops_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->gdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->tdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vdop)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_dops_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->gdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->tdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vdop)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_ecef_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_ecef_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->x)) { return false; }
  if (!sbp_pack_double(ctx, &msg->y)) { return false; }
  if (!sbp_pack_double(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_ecef_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_pos_llh_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_pos_llh_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_pos_llh_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_baseline_ecef_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ecef_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ecef_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_baseline_ned_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_ned_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_ned_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ecef_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ecef_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ecef_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->z)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_vel_ned_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_vel_ned_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_vel_ned_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->n)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->e)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->d)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->h_accuracy)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->v_accuracy)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u32(&msg->heading);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_baseline_heading_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_heading_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->heading)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_heading_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->heading)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_protection_level_dep_a_t(const sbp_msg_protection_level_dep_a_t *msg) {
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

static inline bool sbp_pack_sbp_msg_protection_level_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_protection_level_dep_a_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hpl)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_protection_level_dep_a_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hpl)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg) {
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

static inline bool sbp_pack_sbp_msg_protection_level_t(sbp_pack_ctx_t *ctx, const sbp_msg_protection_level_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->wn)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->atpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->ctpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hvpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vvpl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hopl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->popl)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->ropl)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_pack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_pack_double(ctx, &msg->height)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->v_x)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->v_y)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->v_z)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->roll)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->pitch)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->heading)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_t(sbp_unpack_ctx_t *ctx, sbp_msg_protection_level_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->wn)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->atpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->ctpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hvpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vvpl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hopl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->popl)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->ropl)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lat)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->lon)) { return false; }
  if (!sbp_unpack_double(ctx, &msg->height)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->v_x)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->v_y)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->v_z)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->roll)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->pitch)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->heading)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

#endif
