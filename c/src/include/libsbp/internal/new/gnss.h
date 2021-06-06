#ifndef LIBSBP_UNPACKED_GNSS_PRIVATE_H
#define LIBSBP_UNPACKED_GNSS_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/gnss.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool pack_sbp_sbp_gnss_signal_t(sbp_pack_ctx_t *ctx, const sbp_sbp_gnss_signal_t *msg);
bool unpack_sbp_sbp_gnss_signal_t(sbp_unpack_ctx_t *ctx, sbp_sbp_gnss_signal_t *msg);

bool pack_sbp_sv_id_t(sbp_pack_ctx_t *ctx, const sbp_sv_id_t *msg);
bool unpack_sbp_sv_id_t(sbp_unpack_ctx_t *ctx, sbp_sv_id_t *msg);

bool pack_sbp_gnss_signal_dep_t(sbp_pack_ctx_t *ctx, const sbp_gnss_signal_dep_t *msg);
bool unpack_sbp_gnss_signal_dep_t(sbp_unpack_ctx_t *ctx, sbp_gnss_signal_dep_t *msg);

bool pack_sbp_gps_time_dep_t(sbp_pack_ctx_t *ctx, const sbp_gps_time_dep_t *msg);
bool unpack_sbp_gps_time_dep_t(sbp_unpack_ctx_t *ctx, sbp_gps_time_dep_t *msg);

bool pack_sbp_gps_time_sec_t(sbp_pack_ctx_t *ctx, const sbp_gps_time_sec_t *msg);
bool unpack_sbp_gps_time_sec_t(sbp_unpack_ctx_t *ctx, sbp_gps_time_sec_t *msg);

bool pack_sbp_sbp_gps_time_t(sbp_pack_ctx_t *ctx, const sbp_sbp_gps_time_t *msg);
bool unpack_sbp_sbp_gps_time_t(sbp_unpack_ctx_t *ctx, sbp_sbp_gps_time_t *msg);

bool pack_sbp_carrier_phase_t(sbp_pack_ctx_t *ctx, const sbp_carrier_phase_t *msg);
bool unpack_sbp_carrier_phase_t(sbp_unpack_ctx_t *ctx, sbp_carrier_phase_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
