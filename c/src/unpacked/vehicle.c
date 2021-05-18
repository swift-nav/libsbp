#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/vehicle.h>
#include <libsbp/internal/unpacked/vehicle.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->velocity);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_odometry_t(sbp_pack_ctx_t *ctx, const sbp_msg_odometry_t *msg)
{
  if (!pack_u32(ctx, &msg->tow)) { return false; }
  if (!pack_s32(ctx, &msg->velocity)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_odometry_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_odometry_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_odometry_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_odometry_t(sbp_unpack_ctx_t *ctx, sbp_msg_odometry_t *msg)
{
  if (!unpack_u32(ctx, &msg->tow)) { return false; }
  if (!unpack_s32(ctx, &msg->velocity)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_odometry_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_odometry_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_odometry_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_odometry_t(const sbp_msg_odometry_t *a, const sbp_msg_odometry_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->velocity, &b->velocity);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_s32(&msg->ticks);
  return packed_size;
}

bool pack_sbp_msg_wheeltick_t(sbp_pack_ctx_t *ctx, const sbp_msg_wheeltick_t *msg)
{
  if (!pack_u64(ctx, &msg->time)) { return false; }
  if (!pack_u8(ctx, &msg->flags)) { return false; }
  if (!pack_u8(ctx, &msg->source)) { return false; }
  if (!pack_s32(ctx, &msg->ticks)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_wheeltick_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_wheeltick_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_wheeltick_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_wheeltick_t(sbp_unpack_ctx_t *ctx, sbp_msg_wheeltick_t *msg)
{
  if (!unpack_u64(ctx, &msg->time)) { return false; }
  if (!unpack_u8(ctx, &msg->flags)) { return false; }
  if (!unpack_u8(ctx, &msg->source)) { return false; }
  if (!unpack_s32(ctx, &msg->ticks)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_wheeltick_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_wheeltick_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_wheeltick_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *a, const sbp_msg_wheeltick_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->time, &b->time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ticks, &b->ticks);
  if (ret != 0) { return ret; }
  return ret;
}
