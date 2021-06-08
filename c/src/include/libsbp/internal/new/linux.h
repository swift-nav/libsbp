#ifndef LIBSBP_UNPACKED_LINUX_PRIVATE_H
#define LIBSBP_UNPACKED_LINUX_PRIVATE_H

#include <stdbool.h>

#include <libsbp/new/linux.h>
#include <libsbp/internal/new/common.h>

#ifdef __cplusplus
  extern "C" {
#endif

bool encode_sbp_msg_linux_cpu_state_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_cpu_state_dep_a_t *msg);
bool decode_sbp_msg_linux_cpu_state_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_cpu_state_dep_a_t *msg);

bool encode_sbp_msg_linux_mem_state_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_mem_state_dep_a_t *msg);
bool decode_sbp_msg_linux_mem_state_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_mem_state_dep_a_t *msg);

bool encode_sbp_msg_linux_sys_state_dep_a_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_sys_state_dep_a_t *msg);
bool decode_sbp_msg_linux_sys_state_dep_a_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_sys_state_dep_a_t *msg);

bool encode_sbp_msg_linux_process_socket_counts_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_socket_counts_t *msg);
bool decode_sbp_msg_linux_process_socket_counts_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_process_socket_counts_t *msg);

bool encode_sbp_msg_linux_process_socket_queues_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_socket_queues_t *msg);
bool decode_sbp_msg_linux_process_socket_queues_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_process_socket_queues_t *msg);

bool encode_sbp_msg_linux_socket_usage_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_socket_usage_t *msg);
bool decode_sbp_msg_linux_socket_usage_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_socket_usage_t *msg);

bool encode_sbp_msg_linux_process_fd_count_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_fd_count_t *msg);
bool decode_sbp_msg_linux_process_fd_count_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_process_fd_count_t *msg);

bool encode_sbp_msg_linux_process_fd_summary_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_fd_summary_t *msg);
bool decode_sbp_msg_linux_process_fd_summary_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_process_fd_summary_t *msg);

bool encode_sbp_msg_linux_cpu_state_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_cpu_state_t *msg);
bool decode_sbp_msg_linux_cpu_state_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_cpu_state_t *msg);

bool encode_sbp_msg_linux_mem_state_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_mem_state_t *msg);
bool decode_sbp_msg_linux_mem_state_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_mem_state_t *msg);

bool encode_sbp_msg_linux_sys_state_t(sbp_encode_ctx_t *ctx, const sbp_msg_linux_sys_state_t *msg);
bool decode_sbp_msg_linux_sys_state_t(sbp_decode_ctx_t *ctx, sbp_msg_linux_sys_state_t *msg);

#ifdef __cplusplus
  }
#endif

#endif
