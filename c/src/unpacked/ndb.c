#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/sbp.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/ndb.h>
#include <libsbp/internal/unpacked/ndb.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *msg) {
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

bool pack_sbp_msg_ndb_event_t(sbp_pack_ctx_t *ctx, const sbp_msg_ndb_event_t *msg)
{
  if (!pack_u64(ctx, &msg->recv_time)) { return false; }
  if (!pack_u8(ctx, &msg->event)) { return false; }
  if (!pack_u8(ctx, &msg->object_type)) { return false; }
  if (!pack_u8(ctx, &msg->result)) { return false; }
  if (!pack_u8(ctx, &msg->data_source)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->object_sid)) { return false; }
  if (!pack_sbp_sbp_gnss_signal_t(ctx, &msg->src_sid)) { return false; }
  if (!pack_u16(ctx, &msg->original_sender)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_ndb_event_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ndb_event_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_ndb_event_t(&ctx, msg)) {
    return SBP_PACK_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_ndb_event_t(sbp_unpack_ctx_t *ctx, sbp_msg_ndb_event_t *msg)
{
  if (!unpack_u64(ctx, &msg->recv_time)) { return false; }
  if (!unpack_u8(ctx, &msg->event)) { return false; }
  if (!unpack_u8(ctx, &msg->object_type)) { return false; }
  if (!unpack_u8(ctx, &msg->result)) { return false; }
  if (!unpack_u8(ctx, &msg->data_source)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->object_sid)) { return false; }
  if (!unpack_sbp_sbp_gnss_signal_t(ctx, &msg->src_sid)) { return false; }
  if (!unpack_u16(ctx, &msg->original_sender)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_ndb_event_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ndb_event_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_ndb_event_t(&ctx, msg)) {
    return SBP_UNPACK_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *a, const sbp_msg_ndb_event_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->recv_time, &b->recv_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->event, &b->event);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->object_type, &b->object_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->result, &b->result);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->data_source, &b->data_source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->object_sid, &b->object_sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->src_sid, &b->src_sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->original_sender, &b->original_sender);
  if (ret != 0) { return ret; }
  return ret;
}
