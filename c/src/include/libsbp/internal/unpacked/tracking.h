#ifndef LIBSBP_UNPACKED_TRACKING_PRIVATE_H
#define LIBSBP_UNPACKED_TRACKING_PRIVATE_H

#include <stdbool.h>

#include <libsbp/unpacked/tracking.h>
#include <libsbp/internal/unpacked/common.h>
#include <libsbp/internal/unpacked/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_msg_tracking_state_detailed_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_a_t *msg);
bool unpack_sbp_msg_tracking_state_detailed_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_a_t *msg);

bool pack_sbp_msg_tracking_state_detailed_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_detailed_dep_t *msg);
bool unpack_sbp_msg_tracking_state_detailed_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_detailed_dep_t *msg);

bool pack_sbp_tracking_channel_state_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_state_t *msg);
bool unpack_sbp_tracking_channel_state_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_state_t *msg);

bool pack_sbp_msg_tracking_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_t *msg);
bool unpack_sbp_msg_tracking_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_t *msg);

bool pack_sbp_measurement_state_t(sbp_pack_ctx_t *ctx, const sbp_measurement_state_t *msg);
bool unpack_sbp_measurement_state_t(sbp_unpack_ctx_t *ctx, sbp_measurement_state_t *msg);

bool pack_sbp_msg_measurement_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_measurement_state_t *msg);
bool unpack_sbp_msg_measurement_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_measurement_state_t *msg);

bool pack_sbp_tracking_channel_correlation_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_correlation_t *msg);
bool unpack_sbp_tracking_channel_correlation_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_correlation_t *msg);

bool pack_sbp_msg_tracking_iq_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_iq_t *msg);
bool unpack_sbp_msg_tracking_iq_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_iq_t *msg);

bool pack_sbp_tracking_channel_correlation_dep_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_correlation_dep_t *msg);
bool unpack_sbp_tracking_channel_correlation_dep_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_correlation_dep_t *msg);

bool pack_sbp_msg_tracking_iq_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_iq_dep_b_t *msg);
bool unpack_sbp_msg_tracking_iq_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_iq_dep_b_t *msg);

bool pack_sbp_msg_tracking_iq_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_iq_dep_a_t *msg);
bool unpack_sbp_msg_tracking_iq_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_iq_dep_a_t *msg);

bool pack_sbp_tracking_channel_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_state_dep_a_t *msg);
bool unpack_sbp_tracking_channel_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_state_dep_a_t *msg);

bool pack_sbp_msg_tracking_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_dep_a_t *msg);
bool unpack_sbp_msg_tracking_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_dep_a_t *msg);

bool pack_sbp_tracking_channel_state_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_tracking_channel_state_dep_b_t *msg);
bool unpack_sbp_tracking_channel_state_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_tracking_channel_state_dep_b_t *msg);

bool pack_sbp_msg_tracking_state_dep_b_t(sbp_pack_ctx_t *ctx, const sbp_msg_tracking_state_dep_b_t *msg);
bool unpack_sbp_msg_tracking_state_dep_b_t(sbp_unpack_ctx_t *ctx, sbp_msg_tracking_state_dep_b_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
