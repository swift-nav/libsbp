#ifndef LIBSBP_SOLUTION_META_PACKERS_H
#define LIBSBP_SOLUTION_META_PACKERS_H

#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/solution_meta.h instead"
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
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_solution_input_type_t(const sbp_solution_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->sensor_type);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_solution_input_type_t(sbp_pack_ctx_t *ctx, const sbp_solution_input_type_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->sensor_type)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_solution_input_type_t(sbp_unpack_ctx_t *ctx, sbp_solution_input_type_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->sensor_type)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  packed_size += sbp_packed_size_u8(&msg->n_sats);
  packed_size += sbp_packed_size_u16(&msg->age_corrections);
  packed_size += sbp_packed_size_u8(&msg->alignment_status);
  packed_size += sbp_packed_size_u32(&msg->last_used_gnss_pos_tow);
  packed_size += sbp_packed_size_u32(&msg->last_used_gnss_vel_tow);
  packed_size += (msg->n_sol_in * sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_soln_meta_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_soln_meta_dep_a_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vdop)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->alignment_status)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->last_used_gnss_pos_tow)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->last_used_gnss_vel_tow)) { return false; }
  for (uint8_t i = 0; i < msg->n_sol_in; i++)
  {
    if (!sbp_pack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_soln_meta_dep_a_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vdop)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->alignment_status)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->last_used_gnss_pos_tow)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->last_used_gnss_vel_tow)) { return false; }
    msg->n_sol_in = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  for (uint8_t i = 0; i < msg->n_sol_in; i++) {
    if (!sbp_unpack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u16(&msg->pdop);
  packed_size += sbp_packed_size_u16(&msg->hdop);
  packed_size += sbp_packed_size_u16(&msg->vdop);
  packed_size += sbp_packed_size_u16(&msg->age_corrections);
  packed_size += sbp_packed_size_u32(&msg->age_gnss);
  packed_size += (msg->n_sol_in * sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_soln_meta_t(sbp_pack_ctx_t *ctx, const sbp_msg_soln_meta_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->vdop)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->age_gnss)) { return false; }
  for (uint8_t i = 0; i < msg->n_sol_in; i++)
  {
    if (!sbp_pack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_t(sbp_unpack_ctx_t *ctx, sbp_msg_soln_meta_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->vdop)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->age_gnss)) { return false; }
    msg->n_sol_in = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  for (uint8_t i = 0; i < msg->n_sol_in; i++) {
    if (!sbp_unpack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_gnss_input_type_t(sbp_pack_ctx_t *ctx, const sbp_gnss_input_type_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_gnss_input_type_t(sbp_unpack_ctx_t *ctx, sbp_gnss_input_type_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_imu_input_type_t(sbp_pack_ctx_t *ctx, const sbp_imu_input_type_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_imu_input_type_t(sbp_unpack_ctx_t *ctx, sbp_imu_input_type_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_odo_input_type_t(sbp_pack_ctx_t *ctx, const sbp_odo_input_type_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_odo_input_type_t(sbp_unpack_ctx_t *ctx, sbp_odo_input_type_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

#endif
