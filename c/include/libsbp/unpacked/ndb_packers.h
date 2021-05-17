#ifndef LIBSBP_NDB_PACKERS_H
#define LIBSBP_NDB_PACKERS_H

#ifndef LIBSBP_NDB_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ndb.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->recv_time);
  packed_size += sbp_packed_size_u8(&msg->event);
  packed_size += sbp_packed_size_u8(&msg->object_type);
  packed_size += sbp_packed_size_u8(&msg->result);
  packed_size += sbp_packed_size_u8(&msg->data_source);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->object_sid);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->src_sid);
  packed_size += sbp_packed_size_u16(&msg->original_sender);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_ndb_event_t(sbp_pack_ctx_t *ctx, const sbp_msg_ndb_event_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->recv_time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->event)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->object_type)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->result)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->data_source)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->object_sid)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->src_sid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->original_sender)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ndb_event_t(sbp_unpack_ctx_t *ctx, sbp_msg_ndb_event_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->recv_time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->event)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->object_type)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->result)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->data_source)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->object_sid)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->src_sid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->original_sender)) { return false; }
  return true;
}

#endif
