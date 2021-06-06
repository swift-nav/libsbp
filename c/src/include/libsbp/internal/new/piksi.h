#ifndef LIBSBP_UNPACKED_PIKSI_PRIVATE_H
#define LIBSBP_UNPACKED_PIKSI_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/piksi.h>
#include <libsbp/internal/new/common.h>
#include <libsbp/internal/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_almanac_t(sbp_encode_ctx_t *ctx, const sbp_msg_almanac_t *msg);
bool decode_sbp_msg_almanac_t(sbp_decode_ctx_t *ctx, sbp_msg_almanac_t *msg);

bool encode_sbp_msg_set_time_t(sbp_encode_ctx_t *ctx, const sbp_msg_set_time_t *msg);
bool decode_sbp_msg_set_time_t(sbp_decode_ctx_t *ctx, sbp_msg_set_time_t *msg);

bool encode_sbp_msg_reset_t(sbp_encode_ctx_t *ctx, const sbp_msg_reset_t *msg);
bool decode_sbp_msg_reset_t(sbp_decode_ctx_t *ctx, sbp_msg_reset_t *msg);

bool encode_sbp_msg_reset_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_reset_dep_t *msg);
bool decode_sbp_msg_reset_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_reset_dep_t *msg);

bool encode_sbp_msg_cw_results_t(sbp_encode_ctx_t *ctx, const sbp_msg_cw_results_t *msg);
bool decode_sbp_msg_cw_results_t(sbp_decode_ctx_t *ctx, sbp_msg_cw_results_t *msg);

bool encode_sbp_msg_cw_start_t(sbp_encode_ctx_t *ctx, const sbp_msg_cw_start_t *msg);
bool decode_sbp_msg_cw_start_t(sbp_decode_ctx_t *ctx, sbp_msg_cw_start_t *msg);

bool encode_sbp_msg_reset_filters_t(sbp_encode_ctx_t *ctx, const sbp_msg_reset_filters_t *msg);
bool decode_sbp_msg_reset_filters_t(sbp_decode_ctx_t *ctx, sbp_msg_reset_filters_t *msg);

bool encode_sbp_msg_init_base_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_init_base_dep_t *msg);
bool decode_sbp_msg_init_base_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_init_base_dep_t *msg);

bool encode_sbp_msg_thread_state_t(sbp_encode_ctx_t *ctx, const sbp_msg_thread_state_t *msg);
bool decode_sbp_msg_thread_state_t(sbp_decode_ctx_t *ctx, sbp_msg_thread_state_t *msg);

bool encode_sbp_uart_channel_t(sbp_encode_ctx_t *ctx, const sbp_uart_channel_t *msg);
bool decode_sbp_uart_channel_t(sbp_decode_ctx_t *ctx, sbp_uart_channel_t *msg);

bool encode_sbp_period_t(sbp_encode_ctx_t *ctx, const sbp_period_t *msg);
bool decode_sbp_period_t(sbp_decode_ctx_t *ctx, sbp_period_t *msg);

bool encode_sbp_latency_t(sbp_encode_ctx_t *ctx, const sbp_latency_t *msg);
bool decode_sbp_latency_t(sbp_decode_ctx_t *ctx, sbp_latency_t *msg);

bool encode_sbp_msg_uart_state_t(sbp_encode_ctx_t *ctx, const sbp_msg_uart_state_t *msg);
bool decode_sbp_msg_uart_state_t(sbp_decode_ctx_t *ctx, sbp_msg_uart_state_t *msg);

bool encode_sbp_msg_uart_state_depa_t(sbp_encode_ctx_t *ctx, const sbp_msg_uart_state_depa_t *msg);
bool decode_sbp_msg_uart_state_depa_t(sbp_decode_ctx_t *ctx, sbp_msg_uart_state_depa_t *msg);

bool encode_sbp_msg_iar_state_t(sbp_encode_ctx_t *ctx, const sbp_msg_iar_state_t *msg);
bool decode_sbp_msg_iar_state_t(sbp_decode_ctx_t *ctx, sbp_msg_iar_state_t *msg);

bool encode_sbp_msg_mask_satellite_t(sbp_encode_ctx_t *ctx, const sbp_msg_mask_satellite_t *msg);
bool decode_sbp_msg_mask_satellite_t(sbp_decode_ctx_t *ctx, sbp_msg_mask_satellite_t *msg);

bool encode_sbp_msg_mask_satellite_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_mask_satellite_dep_t *msg);
bool decode_sbp_msg_mask_satellite_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_mask_satellite_dep_t *msg);

bool encode_sbp_msg_device_monitor_t(sbp_encode_ctx_t *ctx, const sbp_msg_device_monitor_t *msg);
bool decode_sbp_msg_device_monitor_t(sbp_decode_ctx_t *ctx, sbp_msg_device_monitor_t *msg);

bool encode_sbp_msg_command_req_t(sbp_encode_ctx_t *ctx, const sbp_msg_command_req_t *msg);
bool decode_sbp_msg_command_req_t(sbp_decode_ctx_t *ctx, sbp_msg_command_req_t *msg);

bool encode_sbp_msg_command_resp_t(sbp_encode_ctx_t *ctx, const sbp_msg_command_resp_t *msg);
bool decode_sbp_msg_command_resp_t(sbp_decode_ctx_t *ctx, sbp_msg_command_resp_t *msg);

bool encode_sbp_msg_command_output_t(sbp_encode_ctx_t *ctx, const sbp_msg_command_output_t *msg);
bool decode_sbp_msg_command_output_t(sbp_decode_ctx_t *ctx, sbp_msg_command_output_t *msg);

bool encode_sbp_msg_network_state_req_t(sbp_encode_ctx_t *ctx, const sbp_msg_network_state_req_t *msg);
bool decode_sbp_msg_network_state_req_t(sbp_decode_ctx_t *ctx, sbp_msg_network_state_req_t *msg);

bool encode_sbp_msg_network_state_resp_t(sbp_encode_ctx_t *ctx, const sbp_msg_network_state_resp_t *msg);
bool decode_sbp_msg_network_state_resp_t(sbp_decode_ctx_t *ctx, sbp_msg_network_state_resp_t *msg);

bool encode_sbp_network_usage_t(sbp_encode_ctx_t *ctx, const sbp_network_usage_t *msg);
bool decode_sbp_network_usage_t(sbp_decode_ctx_t *ctx, sbp_network_usage_t *msg);

bool encode_sbp_msg_network_bandwidth_usage_t(sbp_encode_ctx_t *ctx, const sbp_msg_network_bandwidth_usage_t *msg);
bool decode_sbp_msg_network_bandwidth_usage_t(sbp_decode_ctx_t *ctx, sbp_msg_network_bandwidth_usage_t *msg);

bool encode_sbp_msg_cell_modem_status_t(sbp_encode_ctx_t *ctx, const sbp_msg_cell_modem_status_t *msg);
bool decode_sbp_msg_cell_modem_status_t(sbp_decode_ctx_t *ctx, sbp_msg_cell_modem_status_t *msg);

bool encode_sbp_msg_specan_dep_t(sbp_encode_ctx_t *ctx, const sbp_msg_specan_dep_t *msg);
bool decode_sbp_msg_specan_dep_t(sbp_decode_ctx_t *ctx, sbp_msg_specan_dep_t *msg);

bool encode_sbp_msg_specan_t(sbp_encode_ctx_t *ctx, const sbp_msg_specan_t *msg);
bool decode_sbp_msg_specan_t(sbp_decode_ctx_t *ctx, sbp_msg_specan_t *msg);

bool encode_sbp_msg_front_end_gain_t(sbp_encode_ctx_t *ctx, const sbp_msg_front_end_gain_t *msg);
bool decode_sbp_msg_front_end_gain_t(sbp_decode_ctx_t *ctx, sbp_msg_front_end_gain_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
