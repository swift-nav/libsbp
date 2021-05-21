#ifndef LIBSBP_UNPACKED_ORIENTATION_PRIVATE_H
#define LIBSBP_UNPACKED_ORIENTATION_PRIVATE_H

#include <stdbool.h>

#include <libsbp/unpacked/orientation.h>
#include <libsbp/internal/unpacked/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_baseline_heading_t(sbp_pack_ctx_t *ctx, const sbp_msg_baseline_heading_t *msg);
bool unpack_sbp_msg_baseline_heading_t(sbp_unpack_ctx_t *ctx, sbp_msg_baseline_heading_t *msg);

bool pack_sbp_msg_orient_quat_t(sbp_pack_ctx_t *ctx, const sbp_msg_orient_quat_t *msg);
bool unpack_sbp_msg_orient_quat_t(sbp_unpack_ctx_t *ctx, sbp_msg_orient_quat_t *msg);

bool pack_sbp_msg_orient_euler_t(sbp_pack_ctx_t *ctx, const sbp_msg_orient_euler_t *msg);
bool unpack_sbp_msg_orient_euler_t(sbp_unpack_ctx_t *ctx, sbp_msg_orient_euler_t *msg);

bool pack_sbp_msg_angular_rate_t(sbp_pack_ctx_t *ctx, const sbp_msg_angular_rate_t *msg);
bool unpack_sbp_msg_angular_rate_t(sbp_unpack_ctx_t *ctx, sbp_msg_angular_rate_t *msg);

#ifdef __cplusplus
  }
#endif

#endif