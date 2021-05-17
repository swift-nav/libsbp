#ifndef LIBSBP_MAG_PACKERS_H
#define LIBSBP_MAG_PACKERS_H

#ifndef LIBSBP_MAG_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/mag.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->tow_f);
  packed_size += sbp_packed_size_s16(&msg->mag_x);
  packed_size += sbp_packed_size_s16(&msg->mag_y);
  packed_size += sbp_packed_size_s16(&msg->mag_z);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_mag_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_mag_raw_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tow_f)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->mag_x)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->mag_y)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->mag_z)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_mag_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_mag_raw_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tow_f)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->mag_x)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->mag_y)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->mag_z)) { return false; }
  return true;
}

#endif
