#ifndef LIBSBP_UNPACKED_IMU_PRIVATE_H
#define LIBSBP_UNPACKED_IMU_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/imu.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_imu_raw_t(sbp_pack_ctx_t *ctx, const sbp_msg_imu_raw_t *msg);
bool unpack_sbp_msg_imu_raw_t(sbp_unpack_ctx_t *ctx, sbp_msg_imu_raw_t *msg);

bool pack_sbp_msg_imu_aux_t(sbp_pack_ctx_t *ctx, const sbp_msg_imu_aux_t *msg);
bool unpack_sbp_msg_imu_aux_t(sbp_unpack_ctx_t *ctx, sbp_msg_imu_aux_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
