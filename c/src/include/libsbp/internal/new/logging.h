#ifndef LIBSBP_UNPACKED_LOGGING_PRIVATE_H
#define LIBSBP_UNPACKED_LOGGING_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/logging.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_log_t(sbp_encode_ctx_t *ctx, const sbp_msg_log_t *msg);
bool decode_sbp_msg_log_t(sbp_decode_ctx_t *ctx, sbp_msg_log_t *msg);

bool encode_sbp_msg_fwd_t(sbp_encode_ctx_t *ctx, const sbp_msg_fwd_t *msg);
bool decode_sbp_msg_fwd_t(sbp_decode_ctx_t *ctx, sbp_msg_fwd_t *msg);

bool encode_sbp_msg_print_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_print_dep_t *msg);
bool decode_sbp_msg_print_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_print_dep_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
