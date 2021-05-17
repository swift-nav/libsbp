#ifndef LIBSBP_SBAS_PACKERS_H
#define LIBSBP_SBAS_PACKERS_H

#ifndef LIBSBP_SBAS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/sbas.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_u8(&msg->message_type);
  packed_size += ( 27 * sbp_packed_size_u8(&msg->data[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_sbas_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_sbas_raw_t *msg)
{
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->message_type)) { return false; }
  for (uint8_t i = 0; i < 27; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sbas_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_sbas_raw_t *msg)
{
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->message_type)) { return false; }
  for (uint8_t i = 0; i < 27; i++) {
    if (!sbp_unpack_u8(ctx, &msg->data[i])) { return false; }
  }
  return true;
}

#endif
