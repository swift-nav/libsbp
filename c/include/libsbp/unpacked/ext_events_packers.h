#ifndef LIBSBP_EXT_EVENTS_PACKERS_H
#define LIBSBP_EXT_EVENTS_PACKERS_H

#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ext_events.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->wn);
  packed_size += sbp_packed_size_u32(&msg->tow);
  packed_size += sbp_packed_size_s32(&msg->ns_residual);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += sbp_packed_size_u8(&msg->pin);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ext_event_t(sbp_pack_ctx_t *ctx, const sbp_msg_ext_event_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pin)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ext_event_t(sbp_unpack_ctx_t *ctx, sbp_msg_ext_event_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->wn)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tow)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->ns_residual)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pin)) { return false; }
  return true;
}

#endif
