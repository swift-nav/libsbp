#ifndef LIBSBP_UNPACKED_SYSTEM_PRIVATE_H
#define LIBSBP_UNPACKED_SYSTEM_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/system.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_startup_t(sbp_encode_ctx_t *ctx, const sbp_msg_startup_t *msg);
bool decode_sbp_msg_startup_t(sbp_decode_ctx_t *ctx, sbp_msg_startup_t *msg);

bool encode_sbp_msg_dgnss_status_t(sbp_encode_ctx_t *ctx, const sbp_msg_dgnss_status_t *msg);
bool decode_sbp_msg_dgnss_status_t(sbp_decode_ctx_t *ctx, sbp_msg_dgnss_status_t *msg);

bool encode_sbp_msg_heartbeat_t(sbp_encode_ctx_t *ctx, const sbp_msg_heartbeat_t *msg);
bool decode_sbp_msg_heartbeat_t(sbp_decode_ctx_t *ctx, sbp_msg_heartbeat_t *msg);

bool encode_sbp_sub_system_report_t(sbp_encode_ctx_t *ctx, const sbp_sub_system_report_t *msg);
bool decode_sbp_sub_system_report_t(sbp_decode_ctx_t *ctx, sbp_sub_system_report_t *msg);

bool encode_sbp_msg_status_report_t(sbp_encode_ctx_t *ctx, const sbp_msg_status_report_t *msg);
bool decode_sbp_msg_status_report_t(sbp_decode_ctx_t *ctx, sbp_msg_status_report_t *msg);

bool encode_sbp_msg_ins_status_t(sbp_encode_ctx_t *ctx, const sbp_msg_ins_status_t *msg);
bool decode_sbp_msg_ins_status_t(sbp_decode_ctx_t *ctx, sbp_msg_ins_status_t *msg);

bool encode_sbp_msg_csac_telemetry_t(sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_t *msg);
bool decode_sbp_msg_csac_telemetry_t(sbp_decode_ctx_t *ctx, sbp_msg_csac_telemetry_t *msg);

bool encode_sbp_msg_csac_telemetry_labels_t(sbp_encode_ctx_t *ctx, const sbp_msg_csac_telemetry_labels_t *msg);
bool decode_sbp_msg_csac_telemetry_labels_t(sbp_decode_ctx_t *ctx, sbp_msg_csac_telemetry_labels_t *msg);

bool encode_sbp_msg_ins_updates_t(sbp_encode_ctx_t *ctx, const sbp_msg_ins_updates_t *msg);
bool decode_sbp_msg_ins_updates_t(sbp_decode_ctx_t *ctx, sbp_msg_ins_updates_t *msg);

bool encode_sbp_msg_gnss_time_offset_t(sbp_encode_ctx_t *ctx, const sbp_msg_gnss_time_offset_t *msg);
bool decode_sbp_msg_gnss_time_offset_t(sbp_decode_ctx_t *ctx, sbp_msg_gnss_time_offset_t *msg);

bool encode_sbp_msg_pps_time_t(sbp_encode_ctx_t *ctx, const sbp_msg_pps_time_t *msg);
bool decode_sbp_msg_pps_time_t(sbp_decode_ctx_t *ctx, sbp_msg_pps_time_t *msg);

bool encode_sbp_msg_group_meta_t(sbp_encode_ctx_t *ctx, const sbp_msg_group_meta_t *msg);
bool decode_sbp_msg_group_meta_t(sbp_decode_ctx_t *ctx, sbp_msg_group_meta_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
