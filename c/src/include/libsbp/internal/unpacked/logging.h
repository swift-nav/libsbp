#ifndef LIBSBP_UNPACKED_LOGGING_PRIVATE_H
#define LIBSBP_UNPACKED_LOGGING_PRIVATE_H

#include <stdbool.h>

#include <libsbp/unpacked/logging.h>
#include <libsbp/internal/unpacked/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_log_t(sbp_pack_ctx_t *ctx, const sbp_msg_log_t *msg);
bool unpack_sbp_msg_log_t(sbp_unpack_ctx_t *ctx, sbp_msg_log_t *msg);

bool pack_sbp_msg_fwd_t(sbp_pack_ctx_t *ctx, const sbp_msg_fwd_t *msg);
bool unpack_sbp_msg_fwd_t(sbp_unpack_ctx_t *ctx, sbp_msg_fwd_t *msg);

bool pack_sbp_msg_print_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_print_dep_t *msg);
bool unpack_sbp_msg_print_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_print_dep_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
