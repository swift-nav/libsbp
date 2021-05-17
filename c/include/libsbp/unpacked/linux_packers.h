#ifndef LIBSBP_LINUX_PACKERS_H
#define LIBSBP_LINUX_PACKERS_H

#ifndef LIBSBP_LINUX_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/linux.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/unpacked/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_dep_a_t(const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 236
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pcpu)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!sbp_pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 236,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_cpu_state_dep_a_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pcpu)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 236,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_dep_a_t(const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 236
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_mem_state_dep_a_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pmem)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!sbp_pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 236,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_mem_state_dep_a_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pmem)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 236,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_dep_a_t(const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->mem_total);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u16(&msg->procs_starting);
  packed_size += sbp_packed_size_u16(&msg->procs_stopping);
  packed_size += sbp_packed_size_u16(&msg->pid_count);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_dep_a_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_sys_state_dep_a_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->mem_total)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pcpu)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pmem)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid_count)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_dep_a_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_sys_state_dep_a_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->mem_total)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pcpu)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pmem)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid_count)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_counts_t(const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->socket_count);
  packed_size += sbp_packed_size_u16(&msg->socket_types);
  packed_size += sbp_packed_size_u16(&msg->socket_states);
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 246
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_counts_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_socket_counts_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->socket_count)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->socket_types)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->socket_states)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 246,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_counts_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_socket_counts_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->socket_count)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->socket_types)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->socket_states)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 246,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_socket_queues_t(const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->recv_queued);
  packed_size += sbp_packed_size_u16(&msg->send_queued);
  packed_size += sbp_packed_size_u16(&msg->socket_types);
  packed_size += sbp_packed_size_u16(&msg->socket_states);
  packed_size += ( 64 * sbp_packed_size_char(&msg->address_of_largest[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 180
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_socket_queues_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_socket_queues_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->recv_queued)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->send_queued)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->socket_types)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->socket_states)) { return false; }
  for (uint8_t i = 0; i < 64; i++)
  {
    if (!sbp_pack_char(ctx, &msg->address_of_largest[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 180,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_socket_queues_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_socket_queues_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->recv_queued)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->send_queued)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->socket_types)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->socket_states)) { return false; }
  for (uint8_t i = 0; i < 64; i++) {
    if (!sbp_unpack_char(ctx, &msg->address_of_largest[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 180,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_socket_usage_t(const sbp_msg_linux_socket_usage_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->avg_queue_depth);
  packed_size += sbp_packed_size_u32(&msg->max_queue_depth);
  packed_size += ( 16 * sbp_packed_size_u16(&msg->socket_state_counts[0]));
  packed_size += ( 16 * sbp_packed_size_u16(&msg->socket_type_counts[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_socket_usage_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_socket_usage_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->avg_queue_depth)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->max_queue_depth)) { return false; }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!sbp_pack_u16(ctx, &msg->socket_state_counts[i])) { return false; }
  }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!sbp_pack_u16(ctx, &msg->socket_type_counts[i])) { return false; }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_socket_usage_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_socket_usage_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->avg_queue_depth)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->max_queue_depth)) { return false; }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_unpack_u16(ctx, &msg->socket_state_counts[i])) { return false; }
  }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_unpack_u16(ctx, &msg->socket_type_counts[i])) { return false; }
  }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_count_t(const sbp_msg_linux_process_fd_count_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u16(&msg->fd_count);
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 250
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_count_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_fd_count_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->fd_count)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 250,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_count_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_fd_count_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->fd_count)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 250,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_process_fd_summary_t(const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sys_fd_count);
  packed_size += sbp_sequence_string_packed_len(&msg->most_opened, 251
      , 0
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_process_fd_summary_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_process_fd_summary_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sys_fd_count)) { return false; }
  if (!sbp_sequence_string_pack(&msg->most_opened, 251,0,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_process_fd_summary_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_process_fd_summary_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sys_fd_count)) { return false; }
  if (!sbp_sequence_string_unpack(&msg->most_opened, 251,0,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_cpu_state_t(const sbp_msg_linux_cpu_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 231
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_cpu_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_cpu_state_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pcpu)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!sbp_pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 231,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_cpu_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_cpu_state_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pcpu)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 231,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_mem_state_t(const sbp_msg_linux_mem_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->index);
  packed_size += sbp_packed_size_u16(&msg->pid);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  packed_size += ( 15 * sbp_packed_size_char(&msg->tname[0]));
  packed_size += sbp_unterminated_string_packed_len(&msg->cmdline, 231
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_mem_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_mem_state_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pmem)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++)
  {
    if (!sbp_pack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_pack(&msg->cmdline, 231,
      ctx)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_mem_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_mem_state_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->index)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pmem)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_unpack_char(ctx, &msg->tname[i])) { return false; }
  }
  if (!sbp_unterminated_string_unpack(&msg->cmdline, 231,
      ctx)) { return false; }
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_linux_sys_state_t(const sbp_msg_linux_sys_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->mem_total);
  packed_size += sbp_packed_size_u8(&msg->pcpu);
  packed_size += sbp_packed_size_u8(&msg->pmem);
  packed_size += sbp_packed_size_u16(&msg->procs_starting);
  packed_size += sbp_packed_size_u16(&msg->procs_stopping);
  packed_size += sbp_packed_size_u16(&msg->pid_count);
  packed_size += sbp_packed_size_u32(&msg->time);
  packed_size += sbp_packed_size_u8(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_linux_sys_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_linux_sys_state_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->mem_total)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pcpu)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->pmem)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->pid_count)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->time)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_linux_sys_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_linux_sys_state_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->mem_total)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pcpu)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->pmem)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->procs_starting)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->procs_stopping)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->pid_count)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->time)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->flags)) { return false; }
  return true;
}

#endif
