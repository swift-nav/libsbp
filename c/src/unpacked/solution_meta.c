#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/solution_meta.h>
#include <libsbp/internal/unpacked/solution_meta.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>

size_t sbp_packed_size_sbp_solution_input_type_t(const sbp_solution_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->sensor_type);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_solution_input_type_t(sbp_pack_ctx_t *ctx, const sbp_solution_input_type_t *msg)
{
  if (!pack_u8(ctx, &msg->sensor_type)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_solution_input_type_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_solution_input_type_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_solution_input_type_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_solution_input_type_t(sbp_unpack_ctx_t *ctx, sbp_solution_input_type_t *msg)
{
  if (!unpack_u8(ctx, &msg->sensor_type)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_solution_input_type_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_solution_input_type_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_solution_input_type_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_solution_input_type_t(const sbp_solution_input_type_t *a, const sbp_solution_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->sensor_type, &b->sensor_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *msg) {
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

bool pack_sbp_msg_soln_meta_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_soln_meta_dep_a_t *msg)
{
  if (!pack_u16(ctx, &msg->pdop)) { return false; }
  if (!pack_u16(ctx, &msg->hdop)) { return false; }
  if (!pack_u16(ctx, &msg->vdop)) { return false; }
  if (!pack_u8(ctx, &msg->n_sats)) { return false; }
  if (!pack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!pack_u8(ctx, &msg->alignment_status)) { return false; }
  if (!pack_u32(ctx, &msg->last_used_gnss_pos_tow)) { return false; }
  if (!pack_u32(ctx, &msg->last_used_gnss_vel_tow)) { return false; }
  for (uint8_t i = 0; i < msg->n_sol_in; i++)
  {
    if (!pack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_soln_meta_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_soln_meta_dep_a_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_soln_meta_dep_a_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_soln_meta_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_soln_meta_dep_a_t *msg)
{
  if (!unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!unpack_u16(ctx, &msg->vdop)) { return false; }
  if (!unpack_u8(ctx, &msg->n_sats)) { return false; }
  if (!unpack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!unpack_u8(ctx, &msg->alignment_status)) { return false; }
  if (!unpack_u32(ctx, &msg->last_used_gnss_pos_tow)) { return false; }
  if (!unpack_u32(ctx, &msg->last_used_gnss_vel_tow)) { return false; }
    msg->n_sol_in = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  for (uint8_t i = 0; i < msg->n_sol_in; i++) {
    if (!unpack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_soln_meta_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_soln_meta_dep_a_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_soln_meta_dep_a_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_soln_meta_dep_a_t(struct sbp_state *s, u16 sender_id, const sbp_msg_soln_meta_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_soln_meta_dep_a_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_SOLN_META_DEP_A, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *a, const sbp_msg_soln_meta_dep_a_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sats, &b->n_sats);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->age_corrections, &b->age_corrections);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->alignment_status, &b->alignment_status);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->last_used_gnss_pos_tow, &b->last_used_gnss_pos_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->last_used_gnss_vel_tow, &b->last_used_gnss_vel_tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sol_in, &b->n_sol_in);
  for (uint8_t i = 0; i < a->n_sol_in && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_solution_input_type_t(&a->sol_in[i], &b->sol_in[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg) {
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

bool pack_sbp_msg_soln_meta_t(sbp_pack_ctx_t *ctx, const sbp_msg_soln_meta_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u16(ctx, &msg->pdop)) { return false; }
  if (!pack_u16(ctx, &msg->hdop)) { return false; }
  if (!pack_u16(ctx, &msg->vdop)) { return false; }
  if (!pack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!pack_u32(ctx, &msg->age_gnss)) { return false; }
  for (uint8_t i = 0; i < msg->n_sol_in; i++)
  {
    if (!pack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_soln_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_soln_meta_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_soln_meta_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_soln_meta_t(sbp_unpack_ctx_t *ctx, sbp_msg_soln_meta_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u16(ctx, &msg->pdop)) { return false; }
  if (!unpack_u16(ctx, &msg->hdop)) { return false; }
  if (!unpack_u16(ctx, &msg->vdop)) { return false; }
  if (!unpack_u16(ctx, &msg->age_corrections)) { return false; }
  if (!unpack_u32(ctx, &msg->age_gnss)) { return false; }
    msg->n_sol_in = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_solution_input_type_t(&msg->sol_in[0]));
  for (uint8_t i = 0; i < msg->n_sol_in; i++) {
    if (!unpack_sbp_solution_input_type_t(ctx, &msg->sol_in[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_soln_meta_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_soln_meta_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_soln_meta_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_soln_meta_t(struct sbp_state *s, u16 sender_id, const sbp_msg_soln_meta_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_soln_meta_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_SOLN_META, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *a, const sbp_msg_soln_meta_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->pdop, &b->pdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->hdop, &b->hdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->vdop, &b->vdop);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->age_corrections, &b->age_corrections);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->age_gnss, &b->age_gnss);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_sol_in, &b->n_sol_in);
  for (uint8_t i = 0; i < a->n_sol_in && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_solution_input_type_t(&a->sol_in[i], &b->sol_in[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_gnss_input_type_t(sbp_pack_ctx_t *ctx, const sbp_gnss_input_type_t *msg)
{
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_gnss_input_type_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gnss_input_type_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_gnss_input_type_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_gnss_input_type_t(sbp_unpack_ctx_t *ctx, sbp_gnss_input_type_t *msg)
{
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_gnss_input_type_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gnss_input_type_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_gnss_input_type_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *a, const sbp_gnss_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_imu_input_type_t(sbp_pack_ctx_t *ctx, const sbp_imu_input_type_t *msg)
{
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_imu_input_type_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_imu_input_type_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_imu_input_type_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_imu_input_type_t(sbp_unpack_ctx_t *ctx, sbp_imu_input_type_t *msg)
{
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_imu_input_type_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_imu_input_type_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_imu_input_type_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_imu_input_type_t(const sbp_imu_input_type_t *a, const sbp_imu_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_odo_input_type_t(sbp_pack_ctx_t *ctx, const sbp_odo_input_type_t *msg)
{
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_odo_input_type_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_odo_input_type_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_odo_input_type_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_odo_input_type_t(sbp_unpack_ctx_t *ctx, sbp_odo_input_type_t *msg)
{
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_odo_input_type_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_odo_input_type_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_odo_input_type_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_odo_input_type_t(const sbp_odo_input_type_t *a, const sbp_odo_input_type_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
