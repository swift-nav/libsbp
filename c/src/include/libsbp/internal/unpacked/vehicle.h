#ifndef LIBSBP_UNPACKED_VEHICLE_PRIVATE_H
#define LIBSBP_UNPACKED_VEHICLE_PRIVATE_H

#include <stdbool.h>

#include <libsbp/unpacked/vehicle.h>
#include <libsbp/internal/unpacked/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_odometry_t(sbp_pack_ctx_t *ctx, const sbp_msg_odometry_t *msg);
bool unpack_sbp_msg_odometry_t(sbp_unpack_ctx_t *ctx, sbp_msg_odometry_t *msg);

bool pack_sbp_msg_wheeltick_t(sbp_pack_ctx_t *ctx, const sbp_msg_wheeltick_t *msg);
bool unpack_sbp_msg_wheeltick_t(sbp_unpack_ctx_t *ctx, sbp_msg_wheeltick_t *msg);

#ifdef __cplusplus
  }
#endif

#endif