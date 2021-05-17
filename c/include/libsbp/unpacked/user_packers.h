#ifndef LIBSBP_USER_PACKERS_H
#define LIBSBP_USER_PACKERS_H

#ifndef LIBSBP_USER_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/user.h instead"
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
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_contents * sbp_packed_size_u8(&msg->contents[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_user_data_t(sbp_pack_ctx_t *ctx, const sbp_msg_user_data_t *msg)
{
  for (uint8_t i = 0; i < msg->n_contents; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_user_data_t(sbp_unpack_ctx_t *ctx, sbp_msg_user_data_t *msg)
{
    msg->n_contents = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->contents[0]));
  for (uint8_t i = 0; i < msg->n_contents; i++) {
    if (!sbp_unpack_u8(ctx, &msg->contents[i])) { return false; }
  }
  return true;
}

#endif
