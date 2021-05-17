#ifndef LIBSBP_LOGGING_PACKERS_H
#define LIBSBP_LOGGING_PACKERS_H

#ifndef LIBSBP_LOGGING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/logging.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_log_t(const sbp_msg_log_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->level);
  packed_size += sbp_unterminated_string_packed_len(&msg->text, 254
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_log_t(sbp_pack_ctx_t *ctx, const sbp_msg_log_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->text, 254,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_log_t(sbp_unpack_ctx_t *ctx, sbp_msg_log_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->level)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->text, 254,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_fwd_t(const sbp_msg_fwd_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->source);
  packed_size += sbp_packed_size_u8(&msg->protocol);
  packed_size += (msg->n_fwd_payload * sbp_packed_size_char(&msg->fwd_payload[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_fwd_t(sbp_pack_ctx_t *ctx, const sbp_msg_fwd_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->source)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->protocol)) { return false; }
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++)
  {
    if (!sbp_pack_char(ctx, &msg->fwd_payload[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_fwd_t(sbp_unpack_ctx_t *ctx, sbp_msg_fwd_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->source)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->protocol)) { return false; }
    msg->n_fwd_payload = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_char(&msg->fwd_payload[0]));
  for (uint8_t i = 0; i < msg->n_fwd_payload; i++) {
    if (!sbp_unpack_char(ctx, &msg->fwd_payload[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_unterminated_string_packed_len(&msg->text, 255
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_print_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_print_dep_t *msg)
{
  if (!sbp_unterminated_string_pack(&msg->text, 255,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_print_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_print_dep_t *msg)
{
  if (!sbp_unterminated_string_unpack(&msg->text, 255,
      ctx)) { return false; }
  return true;
}

#endif
