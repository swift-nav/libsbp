#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/mag.h>
#include <libsbp/internal/unpacked/mag.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->tow_f);
  packed_size += sbp_packed_size_s16(&msg->mag_x);
  packed_size += sbp_packed_size_s16(&msg->mag_y);
  packed_size += sbp_packed_size_s16(&msg->mag_z);
  return packed_size;
}

bool pack_sbp_msg_mag_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_mag_raw_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tow_f)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->mag_x)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->mag_y)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->mag_z)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_mag_raw_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_mag_raw_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_mag_raw_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_mag_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_mag_raw_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tow_f)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->mag_x)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->mag_y)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->mag_z)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_mag_raw_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_mag_raw_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_mag_raw_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *a, const sbp_msg_mag_raw_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tow_f, &b->tow_f);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->mag_x, &b->mag_x);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->mag_y, &b->mag_y);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->mag_z, &b->mag_z);
  if (ret != 0) { return ret; }
  return ret;
}
