/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/linux.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/linux.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/linux.h>

void sbp_msg_linux_cpu_state_dep_a_cmdline_init(
    sbp_msg_linux_cpu_state_dep_a_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 236);
}

bool sbp_msg_linux_cpu_state_dep_a_cmdline_valid(
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 236);
}

int sbp_msg_linux_cpu_state_dep_a_cmdline_strcmp(
    const sbp_msg_linux_cpu_state_dep_a_t *a,
    const sbp_msg_linux_cpu_state_dep_a_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 236);
}

uint8_t sbp_msg_linux_cpu_state_dep_a_cmdline_encoded_len(
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 236);
}

uint8_t sbp_msg_linux_cpu_state_dep_a_cmdline_space_remaining(
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 236);
}
bool sbp_msg_linux_cpu_state_dep_a_cmdline_set(
    sbp_msg_linux_cpu_state_dep_a_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 236, new_str);
}

bool sbp_msg_linux_cpu_state_dep_a_cmdline_printf(
    sbp_msg_linux_cpu_state_dep_a_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 236, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_cpu_state_dep_a_cmdline_vprintf(
    sbp_msg_linux_cpu_state_dep_a_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 236, fmt, ap);
}

bool sbp_msg_linux_cpu_state_dep_a_cmdline_append_printf(
    sbp_msg_linux_cpu_state_dep_a_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 236, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_cpu_state_dep_a_cmdline_append_vprintf(
    sbp_msg_linux_cpu_state_dep_a_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 236, fmt, ap);
}

const char *sbp_msg_linux_cpu_state_dep_a_cmdline_get(
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 236);
}

size_t sbp_msg_linux_cpu_state_dep_a_encoded_len(
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u8_encoded_len(&msg->pcpu);
  encoded_len += (15 * sbp_char_encoded_len(&msg->tname[0]));
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 236);
  return encoded_len;
}

bool sbp_msg_linux_cpu_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pcpu)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_encode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 236, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_cpu_state_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_cpu_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_cpu_state_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_cpu_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_cpu_state_dep_a_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pcpu)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_decode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 236, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_cpu_state_dep_a_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_linux_cpu_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_cpu_state_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_cpu_state_dep_a_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_cpu_state_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_cpu_state_dep_a_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_CPU_STATE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_cpu_state_dep_a_cmp(
    const sbp_msg_linux_cpu_state_dep_a_t *a,
    const sbp_msg_linux_cpu_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pcpu, &b->pcpu);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 15; i++) {
    ret = sbp_char_cmp(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_cpu_state_dep_a_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_mem_state_dep_a_cmdline_init(
    sbp_msg_linux_mem_state_dep_a_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 236);
}

bool sbp_msg_linux_mem_state_dep_a_cmdline_valid(
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 236);
}

int sbp_msg_linux_mem_state_dep_a_cmdline_strcmp(
    const sbp_msg_linux_mem_state_dep_a_t *a,
    const sbp_msg_linux_mem_state_dep_a_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 236);
}

uint8_t sbp_msg_linux_mem_state_dep_a_cmdline_encoded_len(
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 236);
}

uint8_t sbp_msg_linux_mem_state_dep_a_cmdline_space_remaining(
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 236);
}
bool sbp_msg_linux_mem_state_dep_a_cmdline_set(
    sbp_msg_linux_mem_state_dep_a_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 236, new_str);
}

bool sbp_msg_linux_mem_state_dep_a_cmdline_printf(
    sbp_msg_linux_mem_state_dep_a_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 236, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_mem_state_dep_a_cmdline_vprintf(
    sbp_msg_linux_mem_state_dep_a_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 236, fmt, ap);
}

bool sbp_msg_linux_mem_state_dep_a_cmdline_append_printf(
    sbp_msg_linux_mem_state_dep_a_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 236, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_mem_state_dep_a_cmdline_append_vprintf(
    sbp_msg_linux_mem_state_dep_a_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 236, fmt, ap);
}

const char *sbp_msg_linux_mem_state_dep_a_cmdline_get(
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 236);
}

size_t sbp_msg_linux_mem_state_dep_a_encoded_len(
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u8_encoded_len(&msg->pmem);
  encoded_len += (15 * sbp_char_encoded_len(&msg->tname[0]));
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 236);
  return encoded_len;
}

bool sbp_msg_linux_mem_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_mem_state_dep_a_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pmem)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_encode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 236, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_mem_state_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_mem_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_mem_state_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_mem_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_mem_state_dep_a_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pmem)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_decode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 236, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_mem_state_dep_a_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_linux_mem_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_mem_state_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_mem_state_dep_a_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_mem_state_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_mem_state_dep_a_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_MEM_STATE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_mem_state_dep_a_cmp(
    const sbp_msg_linux_mem_state_dep_a_t *a,
    const sbp_msg_linux_mem_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pmem, &b->pmem);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 15; i++) {
    ret = sbp_char_cmp(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_mem_state_dep_a_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_linux_sys_state_dep_a_encoded_len(
    const sbp_msg_linux_sys_state_dep_a_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u16_encoded_len(&msg->mem_total);
  encoded_len += sbp_u8_encoded_len(&msg->pcpu);
  encoded_len += sbp_u8_encoded_len(&msg->pmem);
  encoded_len += sbp_u16_encoded_len(&msg->procs_starting);
  encoded_len += sbp_u16_encoded_len(&msg->procs_stopping);
  encoded_len += sbp_u16_encoded_len(&msg->pid_count);
  return encoded_len;
}

bool sbp_msg_linux_sys_state_dep_a_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_sys_state_dep_a_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->mem_total)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pcpu)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pmem)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->procs_starting)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->procs_stopping)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid_count)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_sys_state_dep_a_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_sys_state_dep_a_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_sys_state_dep_a_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_sys_state_dep_a_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_sys_state_dep_a_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->mem_total)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pcpu)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pmem)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->procs_starting)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->procs_stopping)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid_count)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_sys_state_dep_a_decode(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_linux_sys_state_dep_a_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_sys_state_dep_a_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_sys_state_dep_a_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_sys_state_dep_a_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_sys_state_dep_a_encode(payload, sizeof(payload),
                                                &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_SYS_STATE_DEP_A, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_sys_state_dep_a_cmp(
    const sbp_msg_linux_sys_state_dep_a_t *a,
    const sbp_msg_linux_sys_state_dep_a_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->mem_total, &b->mem_total);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pcpu, &b->pcpu);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pmem, &b->pmem);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->procs_starting, &b->procs_starting);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->procs_stopping, &b->procs_stopping);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid_count, &b->pid_count);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_process_socket_counts_cmdline_init(
    sbp_msg_linux_process_socket_counts_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 246);
}

bool sbp_msg_linux_process_socket_counts_cmdline_valid(
    const sbp_msg_linux_process_socket_counts_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 246);
}

int sbp_msg_linux_process_socket_counts_cmdline_strcmp(
    const sbp_msg_linux_process_socket_counts_t *a,
    const sbp_msg_linux_process_socket_counts_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 246);
}

uint8_t sbp_msg_linux_process_socket_counts_cmdline_encoded_len(
    const sbp_msg_linux_process_socket_counts_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 246);
}

uint8_t sbp_msg_linux_process_socket_counts_cmdline_space_remaining(
    const sbp_msg_linux_process_socket_counts_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 246);
}
bool sbp_msg_linux_process_socket_counts_cmdline_set(
    sbp_msg_linux_process_socket_counts_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 246, new_str);
}

bool sbp_msg_linux_process_socket_counts_cmdline_printf(
    sbp_msg_linux_process_socket_counts_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 246, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_socket_counts_cmdline_vprintf(
    sbp_msg_linux_process_socket_counts_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 246, fmt, ap);
}

bool sbp_msg_linux_process_socket_counts_cmdline_append_printf(
    sbp_msg_linux_process_socket_counts_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 246, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_socket_counts_cmdline_append_vprintf(
    sbp_msg_linux_process_socket_counts_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 246, fmt, ap);
}

const char *sbp_msg_linux_process_socket_counts_cmdline_get(
    const sbp_msg_linux_process_socket_counts_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 246);
}

size_t sbp_msg_linux_process_socket_counts_encoded_len(
    const sbp_msg_linux_process_socket_counts_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u16_encoded_len(&msg->socket_count);
  encoded_len += sbp_u16_encoded_len(&msg->socket_types);
  encoded_len += sbp_u16_encoded_len(&msg->socket_states);
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 246);
  return encoded_len;
}

bool sbp_msg_linux_process_socket_counts_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_socket_counts_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->socket_count)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->socket_types)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->socket_states)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 246, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_socket_counts_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_socket_counts_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_socket_counts_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_process_socket_counts_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_socket_counts_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->socket_count)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->socket_types)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->socket_states)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 246, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_socket_counts_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_socket_counts_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_socket_counts_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_process_socket_counts_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_socket_counts_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_process_socket_counts_encode(payload, sizeof(payload),
                                                      &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_PROCESS_SOCKET_COUNTS, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_process_socket_counts_cmp(
    const sbp_msg_linux_process_socket_counts_t *a,
    const sbp_msg_linux_process_socket_counts_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->socket_count, &b->socket_count);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->socket_types, &b->socket_types);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->socket_states, &b->socket_states);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_process_socket_counts_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_process_socket_queues_cmdline_init(
    sbp_msg_linux_process_socket_queues_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 180);
}

bool sbp_msg_linux_process_socket_queues_cmdline_valid(
    const sbp_msg_linux_process_socket_queues_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 180);
}

int sbp_msg_linux_process_socket_queues_cmdline_strcmp(
    const sbp_msg_linux_process_socket_queues_t *a,
    const sbp_msg_linux_process_socket_queues_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 180);
}

uint8_t sbp_msg_linux_process_socket_queues_cmdline_encoded_len(
    const sbp_msg_linux_process_socket_queues_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 180);
}

uint8_t sbp_msg_linux_process_socket_queues_cmdline_space_remaining(
    const sbp_msg_linux_process_socket_queues_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 180);
}
bool sbp_msg_linux_process_socket_queues_cmdline_set(
    sbp_msg_linux_process_socket_queues_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 180, new_str);
}

bool sbp_msg_linux_process_socket_queues_cmdline_printf(
    sbp_msg_linux_process_socket_queues_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 180, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_socket_queues_cmdline_vprintf(
    sbp_msg_linux_process_socket_queues_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 180, fmt, ap);
}

bool sbp_msg_linux_process_socket_queues_cmdline_append_printf(
    sbp_msg_linux_process_socket_queues_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 180, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_socket_queues_cmdline_append_vprintf(
    sbp_msg_linux_process_socket_queues_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 180, fmt, ap);
}

const char *sbp_msg_linux_process_socket_queues_cmdline_get(
    const sbp_msg_linux_process_socket_queues_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 180);
}

size_t sbp_msg_linux_process_socket_queues_encoded_len(
    const sbp_msg_linux_process_socket_queues_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u16_encoded_len(&msg->recv_queued);
  encoded_len += sbp_u16_encoded_len(&msg->send_queued);
  encoded_len += sbp_u16_encoded_len(&msg->socket_types);
  encoded_len += sbp_u16_encoded_len(&msg->socket_states);
  encoded_len += (64 * sbp_char_encoded_len(&msg->address_of_largest[0]));
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 180);
  return encoded_len;
}

bool sbp_msg_linux_process_socket_queues_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_socket_queues_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->recv_queued)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->send_queued)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->socket_types)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->socket_states)) {
    return false;
  }
  for (uint8_t i = 0; i < 64; i++) {
    if (!sbp_char_encode(ctx, &msg->address_of_largest[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 180, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_socket_queues_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_socket_queues_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_socket_queues_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_process_socket_queues_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_socket_queues_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->recv_queued)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->send_queued)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->socket_types)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->socket_states)) {
    return false;
  }
  for (uint8_t i = 0; i < 64; i++) {
    if (!sbp_char_decode(ctx, &msg->address_of_largest[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 180, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_socket_queues_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_socket_queues_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_socket_queues_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_process_socket_queues_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_socket_queues_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_process_socket_queues_encode(payload, sizeof(payload),
                                                      &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_PROCESS_SOCKET_QUEUES, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_process_socket_queues_cmp(
    const sbp_msg_linux_process_socket_queues_t *a,
    const sbp_msg_linux_process_socket_queues_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->recv_queued, &b->recv_queued);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->send_queued, &b->send_queued);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->socket_types, &b->socket_types);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->socket_states, &b->socket_states);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 64; i++) {
    ret = sbp_char_cmp(&a->address_of_largest[i], &b->address_of_largest[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_process_socket_queues_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_linux_socket_usage_encoded_len(
    const sbp_msg_linux_socket_usage_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->avg_queue_depth);
  encoded_len += sbp_u32_encoded_len(&msg->max_queue_depth);
  encoded_len += (16 * sbp_u16_encoded_len(&msg->socket_state_counts[0]));
  encoded_len += (16 * sbp_u16_encoded_len(&msg->socket_type_counts[0]));
  return encoded_len;
}

bool sbp_msg_linux_socket_usage_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_socket_usage_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->avg_queue_depth)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->max_queue_depth)) {
    return false;
  }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_u16_encode(ctx, &msg->socket_state_counts[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_u16_encode(ctx, &msg->socket_type_counts[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_linux_socket_usage_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_linux_socket_usage_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_socket_usage_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_socket_usage_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_socket_usage_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->avg_queue_depth)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->max_queue_depth)) {
    return false;
  }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_u16_decode(ctx, &msg->socket_state_counts[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_u16_decode(ctx, &msg->socket_type_counts[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_linux_socket_usage_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_linux_socket_usage_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_socket_usage_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_socket_usage_send(struct sbp_state *s, u16 sender_id,
                                   const sbp_msg_linux_socket_usage_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_socket_usage_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_SOCKET_USAGE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_linux_socket_usage_cmp(const sbp_msg_linux_socket_usage_t *a,
                                   const sbp_msg_linux_socket_usage_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->avg_queue_depth, &b->avg_queue_depth);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->max_queue_depth, &b->max_queue_depth);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 16; i++) {
    ret = sbp_u16_cmp(&a->socket_state_counts[i], &b->socket_state_counts[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 16; i++) {
    ret = sbp_u16_cmp(&a->socket_type_counts[i], &b->socket_type_counts[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_process_fd_count_cmdline_init(
    sbp_msg_linux_process_fd_count_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 250);
}

bool sbp_msg_linux_process_fd_count_cmdline_valid(
    const sbp_msg_linux_process_fd_count_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 250);
}

int sbp_msg_linux_process_fd_count_cmdline_strcmp(
    const sbp_msg_linux_process_fd_count_t *a,
    const sbp_msg_linux_process_fd_count_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 250);
}

uint8_t sbp_msg_linux_process_fd_count_cmdline_encoded_len(
    const sbp_msg_linux_process_fd_count_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 250);
}

uint8_t sbp_msg_linux_process_fd_count_cmdline_space_remaining(
    const sbp_msg_linux_process_fd_count_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 250);
}
bool sbp_msg_linux_process_fd_count_cmdline_set(
    sbp_msg_linux_process_fd_count_t *msg, const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 250, new_str);
}

bool sbp_msg_linux_process_fd_count_cmdline_printf(
    sbp_msg_linux_process_fd_count_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 250, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_fd_count_cmdline_vprintf(
    sbp_msg_linux_process_fd_count_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 250, fmt, ap);
}

bool sbp_msg_linux_process_fd_count_cmdline_append_printf(
    sbp_msg_linux_process_fd_count_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 250, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_fd_count_cmdline_append_vprintf(
    sbp_msg_linux_process_fd_count_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 250, fmt, ap);
}

const char *sbp_msg_linux_process_fd_count_cmdline_get(
    const sbp_msg_linux_process_fd_count_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 250);
}

size_t sbp_msg_linux_process_fd_count_encoded_len(
    const sbp_msg_linux_process_fd_count_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u16_encoded_len(&msg->fd_count);
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 250);
  return encoded_len;
}

bool sbp_msg_linux_process_fd_count_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_fd_count_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->fd_count)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 250, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_fd_count_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_fd_count_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_fd_count_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_process_fd_count_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_fd_count_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->fd_count)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 250, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_fd_count_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_fd_count_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_fd_count_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_process_fd_count_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_fd_count_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_process_fd_count_encode(payload, sizeof(payload),
                                                 &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_PROCESS_FD_COUNT, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_process_fd_count_cmp(
    const sbp_msg_linux_process_fd_count_t *a,
    const sbp_msg_linux_process_fd_count_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->fd_count, &b->fd_count);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_process_fd_count_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_process_fd_summary_most_opened_init(
    sbp_msg_linux_process_fd_summary_t *msg) {
  sbp_double_null_terminated_string_init(&msg->most_opened, 251);
}

bool sbp_msg_linux_process_fd_summary_most_opened_valid(
    const sbp_msg_linux_process_fd_summary_t *msg) {
  return sbp_double_null_terminated_string_valid(&msg->most_opened, 251);
}

int sbp_msg_linux_process_fd_summary_most_opened_strcmp(
    const sbp_msg_linux_process_fd_summary_t *a,
    const sbp_msg_linux_process_fd_summary_t *b) {
  return sbp_double_null_terminated_string_strcmp(&a->most_opened,
                                                  &b->most_opened, 251);
}

uint8_t sbp_msg_linux_process_fd_summary_most_opened_encoded_len(
    const sbp_msg_linux_process_fd_summary_t *msg) {
  return sbp_double_null_terminated_string_encoded_len(&msg->most_opened, 251);
}

uint8_t sbp_msg_linux_process_fd_summary_most_opened_space_remaining(
    const sbp_msg_linux_process_fd_summary_t *msg) {
  return sbp_double_null_terminated_string_space_remaining(&msg->most_opened,
                                                           251);
}
uint8_t sbp_msg_linux_process_fd_summary_most_opened_count_sections(
    const sbp_msg_linux_process_fd_summary_t *msg) {
  return sbp_double_null_terminated_string_count_sections(&msg->most_opened,
                                                          251);
}

bool sbp_msg_linux_process_fd_summary_most_opened_add_section(
    sbp_msg_linux_process_fd_summary_t *msg, const char *new_str) {
  return sbp_double_null_terminated_string_add_section(&msg->most_opened, 251,
                                                       new_str);
}

bool sbp_msg_linux_process_fd_summary_most_opened_add_section_printf(
    sbp_msg_linux_process_fd_summary_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_double_null_terminated_string_add_section_vprintf(
      &msg->most_opened, 251, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_fd_summary_most_opened_add_section_vprintf(
    sbp_msg_linux_process_fd_summary_t *msg, const char *fmt, va_list ap) {
  return sbp_double_null_terminated_string_add_section_vprintf(
      &msg->most_opened, 251, fmt, ap);
}

bool sbp_msg_linux_process_fd_summary_most_opened_append(
    sbp_msg_linux_process_fd_summary_t *msg, const char *str) {
  return sbp_double_null_terminated_string_append(&msg->most_opened, 251, str);
}

bool sbp_msg_linux_process_fd_summary_most_opened_append_printf(
    sbp_msg_linux_process_fd_summary_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_double_null_terminated_string_append_vprintf(&msg->most_opened,
                                                              251, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_process_fd_summary_most_opened_append_vprintf(
    sbp_msg_linux_process_fd_summary_t *msg, const char *fmt, va_list ap) {
  return sbp_double_null_terminated_string_append_vprintf(&msg->most_opened,
                                                          251, fmt, ap);
}

const char *sbp_msg_linux_process_fd_summary_most_opened_get_section(
    const sbp_msg_linux_process_fd_summary_t *msg, uint8_t section) {
  return sbp_double_null_terminated_string_get_section(&msg->most_opened, 251,
                                                       section);
}

uint8_t sbp_msg_linux_process_fd_summary_most_opened_section_strlen(
    const sbp_msg_linux_process_fd_summary_t *msg, uint8_t section) {
  return sbp_double_null_terminated_string_section_strlen(&msg->most_opened,
                                                          251, section);
}

size_t sbp_msg_linux_process_fd_summary_encoded_len(
    const sbp_msg_linux_process_fd_summary_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u32_encoded_len(&msg->sys_fd_count);
  encoded_len +=
      sbp_double_null_terminated_string_encoded_len(&msg->most_opened, 251);
  return encoded_len;
}

bool sbp_msg_linux_process_fd_summary_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_process_fd_summary_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sys_fd_count)) {
    return false;
  }
  if (!sbp_double_null_terminated_string_encode(&msg->most_opened, 251, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_fd_summary_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_linux_process_fd_summary_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_fd_summary_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_process_fd_summary_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_linux_process_fd_summary_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sys_fd_count)) {
    return false;
  }
  if (!sbp_double_null_terminated_string_decode(&msg->most_opened, 251, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_process_fd_summary_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_linux_process_fd_summary_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_process_fd_summary_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_process_fd_summary_send(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_linux_process_fd_summary_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_process_fd_summary_encode(payload, sizeof(payload),
                                                   &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_PROCESS_FD_SUMMARY, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_linux_process_fd_summary_cmp(
    const sbp_msg_linux_process_fd_summary_t *a,
    const sbp_msg_linux_process_fd_summary_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sys_fd_count, &b->sys_fd_count);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_process_fd_summary_most_opened_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_cpu_state_cmdline_init(sbp_msg_linux_cpu_state_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 231);
}

bool sbp_msg_linux_cpu_state_cmdline_valid(
    const sbp_msg_linux_cpu_state_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 231);
}

int sbp_msg_linux_cpu_state_cmdline_strcmp(const sbp_msg_linux_cpu_state_t *a,
                                           const sbp_msg_linux_cpu_state_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 231);
}

uint8_t sbp_msg_linux_cpu_state_cmdline_encoded_len(
    const sbp_msg_linux_cpu_state_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 231);
}

uint8_t sbp_msg_linux_cpu_state_cmdline_space_remaining(
    const sbp_msg_linux_cpu_state_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 231);
}
bool sbp_msg_linux_cpu_state_cmdline_set(sbp_msg_linux_cpu_state_t *msg,
                                         const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 231, new_str);
}

bool sbp_msg_linux_cpu_state_cmdline_printf(sbp_msg_linux_cpu_state_t *msg,
                                            const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 231, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_cpu_state_cmdline_vprintf(sbp_msg_linux_cpu_state_t *msg,
                                             const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 231, fmt, ap);
}

bool sbp_msg_linux_cpu_state_cmdline_append_printf(
    sbp_msg_linux_cpu_state_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 231, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_cpu_state_cmdline_append_vprintf(
    sbp_msg_linux_cpu_state_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 231, fmt, ap);
}

const char *sbp_msg_linux_cpu_state_cmdline_get(
    const sbp_msg_linux_cpu_state_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 231);
}

size_t sbp_msg_linux_cpu_state_encoded_len(
    const sbp_msg_linux_cpu_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u8_encoded_len(&msg->pcpu);
  encoded_len += sbp_u32_encoded_len(&msg->time);
  encoded_len += sbp_u8_encoded_len(&msg->flags);
  encoded_len += (15 * sbp_char_encoded_len(&msg->tname[0]));
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 231);
  return encoded_len;
}

bool sbp_msg_linux_cpu_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_cpu_state_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pcpu)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_encode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 231, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_cpu_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_linux_cpu_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_cpu_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_cpu_state_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_linux_cpu_state_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pcpu)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_decode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 231, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_cpu_state_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_linux_cpu_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_cpu_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_cpu_state_send(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_linux_cpu_state_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_cpu_state_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_CPU_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_linux_cpu_state_cmp(const sbp_msg_linux_cpu_state_t *a,
                                const sbp_msg_linux_cpu_state_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pcpu, &b->pcpu);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 15; i++) {
    ret = sbp_char_cmp(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_cpu_state_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_linux_mem_state_cmdline_init(sbp_msg_linux_mem_state_t *msg) {
  sbp_unterminated_string_init(&msg->cmdline, 231);
}

bool sbp_msg_linux_mem_state_cmdline_valid(
    const sbp_msg_linux_mem_state_t *msg) {
  return sbp_unterminated_string_valid(&msg->cmdline, 231);
}

int sbp_msg_linux_mem_state_cmdline_strcmp(const sbp_msg_linux_mem_state_t *a,
                                           const sbp_msg_linux_mem_state_t *b) {
  return sbp_unterminated_string_strcmp(&a->cmdline, &b->cmdline, 231);
}

uint8_t sbp_msg_linux_mem_state_cmdline_encoded_len(
    const sbp_msg_linux_mem_state_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->cmdline, 231);
}

uint8_t sbp_msg_linux_mem_state_cmdline_space_remaining(
    const sbp_msg_linux_mem_state_t *msg) {
  return sbp_unterminated_string_space_remaining(&msg->cmdline, 231);
}
bool sbp_msg_linux_mem_state_cmdline_set(sbp_msg_linux_mem_state_t *msg,
                                         const char *new_str) {
  return sbp_unterminated_string_set(&msg->cmdline, 231, new_str);
}

bool sbp_msg_linux_mem_state_cmdline_printf(sbp_msg_linux_mem_state_t *msg,
                                            const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->cmdline, 231, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_mem_state_cmdline_vprintf(sbp_msg_linux_mem_state_t *msg,
                                             const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->cmdline, 231, fmt, ap);
}

bool sbp_msg_linux_mem_state_cmdline_append_printf(
    sbp_msg_linux_mem_state_t *msg, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret =
      sbp_unterminated_string_append_vprintf(&msg->cmdline, 231, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_linux_mem_state_cmdline_append_vprintf(
    sbp_msg_linux_mem_state_t *msg, const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(&msg->cmdline, 231, fmt, ap);
}

const char *sbp_msg_linux_mem_state_cmdline_get(
    const sbp_msg_linux_mem_state_t *msg) {
  return sbp_unterminated_string_get(&msg->cmdline, 231);
}

size_t sbp_msg_linux_mem_state_encoded_len(
    const sbp_msg_linux_mem_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u8_encoded_len(&msg->index);
  encoded_len += sbp_u16_encoded_len(&msg->pid);
  encoded_len += sbp_u8_encoded_len(&msg->pmem);
  encoded_len += sbp_u32_encoded_len(&msg->time);
  encoded_len += sbp_u8_encoded_len(&msg->flags);
  encoded_len += (15 * sbp_char_encoded_len(&msg->tname[0]));
  encoded_len += sbp_unterminated_string_encoded_len(&msg->cmdline, 231);
  return encoded_len;
}

bool sbp_msg_linux_mem_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_mem_state_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pmem)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_encode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_encode(&msg->cmdline, 231, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_mem_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_linux_mem_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_mem_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_mem_state_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_linux_mem_state_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->index)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pmem)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  for (uint8_t i = 0; i < 15; i++) {
    if (!sbp_char_decode(ctx, &msg->tname[i])) {
      return false;
    }
  }
  if (!sbp_unterminated_string_decode(&msg->cmdline, 231, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_mem_state_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_linux_mem_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_mem_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_mem_state_send(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_linux_mem_state_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_mem_state_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_MEM_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_linux_mem_state_cmp(const sbp_msg_linux_mem_state_t *a,
                                const sbp_msg_linux_mem_state_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->index, &b->index);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid, &b->pid);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pmem, &b->pmem);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < 15; i++) {
    ret = sbp_char_cmp(&a->tname[i], &b->tname[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_linux_mem_state_cmdline_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

size_t sbp_msg_linux_sys_state_encoded_len(
    const sbp_msg_linux_sys_state_t *msg) {
  size_t encoded_len = 0;
  encoded_len += sbp_u16_encoded_len(&msg->mem_total);
  encoded_len += sbp_u8_encoded_len(&msg->pcpu);
  encoded_len += sbp_u8_encoded_len(&msg->pmem);
  encoded_len += sbp_u16_encoded_len(&msg->procs_starting);
  encoded_len += sbp_u16_encoded_len(&msg->procs_stopping);
  encoded_len += sbp_u16_encoded_len(&msg->pid_count);
  encoded_len += sbp_u32_encoded_len(&msg->time);
  encoded_len += sbp_u8_encoded_len(&msg->flags);
  return encoded_len;
}

bool sbp_msg_linux_sys_state_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_linux_sys_state_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->mem_total)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pcpu)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->pmem)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->procs_starting)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->procs_stopping)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->pid_count)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_sys_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_linux_sys_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_sys_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_linux_sys_state_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_linux_sys_state_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->mem_total)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pcpu)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->pmem)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->procs_starting)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->procs_stopping)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->pid_count)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->time)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_linux_sys_state_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_linux_sys_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_linux_sys_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_linux_sys_state_send(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_linux_sys_state_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_linux_sys_state_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_LINUX_SYS_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_linux_sys_state_cmp(const sbp_msg_linux_sys_state_t *a,
                                const sbp_msg_linux_sys_state_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->mem_total, &b->mem_total);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pcpu, &b->pcpu);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->pmem, &b->pmem);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->procs_starting, &b->procs_starting);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->procs_stopping, &b->procs_stopping);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->pid_count, &b->pid_count);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->time, &b->time);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}
