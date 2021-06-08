#ifndef LIBSBP_UNPACKED_SYSTEM_PRIVATE_H
#define LIBSBP_UNPACKED_SYSTEM_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/system.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_group_meta_t(sbp_encode_ctx_t *ctx, const sbp_msg_group_meta_t *msg);
bool decode_sbp_msg_group_meta_t(sbp_decode_ctx_t *ctx, sbp_msg_group_meta_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
