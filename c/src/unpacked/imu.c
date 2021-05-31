#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/imu.h>
#include <libsbp/internal/unpacked/imu.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/double_null_terminated.h>
#include <libsbp/internal/unpacked/string/unterminated.h>

size_t sbp_packed_size_sbp_msg_imu_raw_t(const sbp_msg_imu_raw_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->tow_f);
  packed_size += sbp_packed_size_s16(&msg->acc_x);
  packed_size += sbp_packed_size_s16(&msg->acc_y);
  packed_size += sbp_packed_size_s16(&msg->acc_z);
  packed_size += sbp_packed_size_s16(&msg->gyr_x);
  packed_size += sbp_packed_size_s16(&msg->gyr_y);
  packed_size += sbp_packed_size_s16(&msg->gyr_z);
  return packed_size;
}

bool pack_sbp_msg_imu_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_imu_raw_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_u8(ctx, &msg->tow_f)) { return false; }
  if (!pack_s16(ctx, &msg->acc_x)) { return false; }
  if (!pack_s16(ctx, &msg->acc_y)) { return false; }
  if (!pack_s16(ctx, &msg->acc_z)) { return false; }
  if (!pack_s16(ctx, &msg->gyr_x)) { return false; }
  if (!pack_s16(ctx, &msg->gyr_y)) { return false; }
  if (!pack_s16(ctx, &msg->gyr_z)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_imu_raw_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_imu_raw_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_imu_raw_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_imu_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_imu_raw_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_u8(ctx, &msg->tow_f)) { return false; }
  if (!unpack_s16(ctx, &msg->acc_x)) { return false; }
  if (!unpack_s16(ctx, &msg->acc_y)) { return false; }
  if (!unpack_s16(ctx, &msg->acc_z)) { return false; }
  if (!unpack_s16(ctx, &msg->gyr_x)) { return false; }
  if (!unpack_s16(ctx, &msg->gyr_y)) { return false; }
  if (!unpack_s16(ctx, &msg->gyr_z)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_imu_raw_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_imu_raw_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_imu_raw_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_imu_raw_t(struct sbp_state *s, u16 sender_id, const sbp_msg_imu_raw_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_imu_raw_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_IMU_RAW, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_imu_raw_t(const sbp_msg_imu_raw_t *a, const sbp_msg_imu_raw_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tow_f, &b->tow_f);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->acc_x, &b->acc_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->acc_y, &b->acc_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->acc_z, &b->acc_z);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->gyr_x, &b->gyr_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->gyr_y, &b->gyr_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->gyr_z, &b->gyr_z);
  if (ret != 0) { return ret; }
  return ret;
}

size_t sbp_packed_size_sbp_msg_imu_aux_t(const sbp_msg_imu_aux_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->imu_type);
  packed_size += sbp_packed_size_s16(&msg->temp);
  packed_size += sbp_packed_size_u8(&msg->imu_conf);
  return packed_size;
}

bool pack_sbp_msg_imu_aux_t(sbp_pack_ctx_t *ctx, const sbp_msg_imu_aux_t *msg)
{
  if (!pack_u8(ctx, &msg->imu_type)) { return false; }
  if (!pack_s16(ctx, &msg->temp)) { return false; }
  if (!pack_u8(ctx, &msg->imu_conf)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_imu_aux_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_imu_aux_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_imu_aux_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_imu_aux_t(sbp_unpack_ctx_t *ctx, sbp_msg_imu_aux_t *msg)
{
  if (!unpack_u8(ctx, &msg->imu_type)) { return false; }
  if (!unpack_s16(ctx, &msg->temp)) { return false; }
  if (!unpack_u8(ctx, &msg->imu_conf)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_imu_aux_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_imu_aux_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_imu_aux_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}
s8 sbp_send_sbp_msg_imu_aux_t(struct sbp_state *s, u16 sender_id, const sbp_msg_imu_aux_t *msg, s32 (*write)(u8 *buff, u32 n, void *context))
{
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_pack_sbp_msg_imu_aux_t(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) { return ret; }
  return sbp_send_message(s, SBP_MSG_IMU_AUX, sender_id, payload_len, payload, write);
}

int sbp_cmp_sbp_msg_imu_aux_t(const sbp_msg_imu_aux_t *a, const sbp_msg_imu_aux_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->imu_type, &b->imu_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->temp, &b->temp);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->imu_conf, &b->imu_conf);
  if (ret != 0) { return ret; }
  return ret;
}
