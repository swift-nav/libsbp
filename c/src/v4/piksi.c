/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/piksi.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <libsbp/internal/v4/common.h>
#include <libsbp/internal/v4/piksi.h>
#include <libsbp/internal/v4/string/double_null_terminated.h>
#include <libsbp/internal/v4/string/multipart.h>
#include <libsbp/internal/v4/string/null_terminated.h>
#include <libsbp/internal/v4/string/unterminated.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/piksi.h>

bool sbp_msg_almanac_encode_internal(sbp_encode_ctx_t *ctx,
                                     const sbp_msg_almanac_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_almanac_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                          const sbp_msg_almanac_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_almanac_decode_internal(sbp_decode_ctx_t *ctx,
                                     sbp_msg_almanac_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_almanac_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                          sbp_msg_almanac_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_almanac_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_almanac_send(sbp_state_t *s, u16 sender_id,
                        const sbp_msg_almanac_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_almanac_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_ALMANAC, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_almanac_cmp(const sbp_msg_almanac_t *a,
                        const sbp_msg_almanac_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_set_time_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_set_time_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_set_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_set_time_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_set_time_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_set_time_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_set_time_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_set_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_set_time_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_set_time_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_set_time_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_set_time_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_set_time_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SET_TIME, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_set_time_cmp(const sbp_msg_set_time_t *a,
                         const sbp_msg_set_time_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_reset_encode_internal(sbp_encode_ctx_t *ctx,
                                   const sbp_msg_reset_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_reset_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                        const sbp_msg_reset_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_reset_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_reset_decode_internal(sbp_decode_ctx_t *ctx,
                                   sbp_msg_reset_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_reset_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                        sbp_msg_reset_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_reset_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_reset_send(sbp_state_t *s, u16 sender_id, const sbp_msg_reset_t *msg,
                      sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_reset_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_RESET, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_reset_cmp(const sbp_msg_reset_t *a, const sbp_msg_reset_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_reset_dep_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_reset_dep_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_reset_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_reset_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_reset_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_reset_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_reset_dep_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_reset_dep_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_reset_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_reset_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_reset_dep_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_reset_dep_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_reset_dep_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_RESET_DEP, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_reset_dep_cmp(const sbp_msg_reset_dep_t *a,
                          const sbp_msg_reset_dep_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_cw_results_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_cw_results_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_cw_results_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_cw_results_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_cw_results_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_cw_results_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_cw_results_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_cw_results_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_cw_results_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_cw_results_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_cw_results_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_cw_results_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_cw_results_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CW_RESULTS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_cw_results_cmp(const sbp_msg_cw_results_t *a,
                           const sbp_msg_cw_results_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_cw_start_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_msg_cw_start_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_cw_start_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_msg_cw_start_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_cw_start_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_cw_start_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_msg_cw_start_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_cw_start_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_msg_cw_start_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_cw_start_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_cw_start_send(sbp_state_t *s, u16 sender_id,
                         const sbp_msg_cw_start_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_cw_start_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CW_START, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_cw_start_cmp(const sbp_msg_cw_start_t *a,
                         const sbp_msg_cw_start_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_reset_filters_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_reset_filters_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->filter)) {
    return false;
  }
  return true;
}

s8 sbp_msg_reset_filters_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_reset_filters_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_reset_filters_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_reset_filters_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_reset_filters_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->filter)) {
    return false;
  }
  return true;
}

s8 sbp_msg_reset_filters_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_reset_filters_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_reset_filters_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_reset_filters_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_reset_filters_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_reset_filters_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_RESET_FILTERS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_reset_filters_cmp(const sbp_msg_reset_filters_t *a,
                              const sbp_msg_reset_filters_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->filter, &b->filter);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_init_base_dep_encode_internal(sbp_encode_ctx_t *ctx,
                                           const sbp_msg_init_base_dep_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_init_base_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                const sbp_msg_init_base_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_init_base_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_init_base_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                           sbp_msg_init_base_dep_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_init_base_dep_decode(const uint8_t *buf, uint8_t len,
                                uint8_t *n_read, sbp_msg_init_base_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_init_base_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_init_base_dep_send(sbp_state_t *s, u16 sender_id,
                              const sbp_msg_init_base_dep_t *msg,
                              sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_init_base_dep_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_INIT_BASE_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_init_base_dep_cmp(const sbp_msg_init_base_dep_t *a,
                              const sbp_msg_init_base_dep_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_thread_state_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_thread_state_t *msg) {
  for (size_t i = 0; i < SBP_MSG_THREAD_STATE_NAME_MAX; i++) {
    if (!sbp_char_encode(ctx, &msg->name[i])) {
      return false;
    }
  }
  if (!sbp_u16_encode(ctx, &msg->cpu)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->stack_free)) {
    return false;
  }
  return true;
}

s8 sbp_msg_thread_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_thread_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_thread_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_thread_state_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_thread_state_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_THREAD_STATE_NAME_MAX; i++) {
    if (!sbp_char_decode(ctx, &msg->name[i])) {
      return false;
    }
  }
  if (!sbp_u16_decode(ctx, &msg->cpu)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->stack_free)) {
    return false;
  }
  return true;
}

s8 sbp_msg_thread_state_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_thread_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_thread_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_thread_state_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_thread_state_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_thread_state_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_THREAD_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_thread_state_cmp(const sbp_msg_thread_state_t *a,
                             const sbp_msg_thread_state_t *b) {
  int ret = 0;

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_THREAD_STATE_NAME_MAX; i++) {
    ret = sbp_char_cmp(&a->name[i], &b->name[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->cpu, &b->cpu);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->stack_free, &b->stack_free);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_uart_channel_encode_internal(sbp_encode_ctx_t *ctx,
                                      const sbp_uart_channel_t *msg) {
  if (!sbp_float_encode(ctx, &msg->tx_throughput)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->rx_throughput)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->crc_error_count)) {
    return false;
  }
  if (!sbp_u16_encode(ctx, &msg->io_error_count)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->tx_buffer_level)) {
    return false;
  }
  if (!sbp_u8_encode(ctx, &msg->rx_buffer_level)) {
    return false;
  }
  return true;
}

s8 sbp_uart_channel_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_uart_channel_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_uart_channel_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_uart_channel_decode_internal(sbp_decode_ctx_t *ctx,
                                      sbp_uart_channel_t *msg) {
  if (!sbp_float_decode(ctx, &msg->tx_throughput)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->rx_throughput)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->crc_error_count)) {
    return false;
  }
  if (!sbp_u16_decode(ctx, &msg->io_error_count)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->tx_buffer_level)) {
    return false;
  }
  if (!sbp_u8_decode(ctx, &msg->rx_buffer_level)) {
    return false;
  }
  return true;
}

s8 sbp_uart_channel_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_uart_channel_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_uart_channel_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_uart_channel_cmp(const sbp_uart_channel_t *a,
                         const sbp_uart_channel_t *b) {
  int ret = 0;

  ret = sbp_float_cmp(&a->tx_throughput, &b->tx_throughput);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->rx_throughput, &b->rx_throughput);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->crc_error_count, &b->crc_error_count);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u16_cmp(&a->io_error_count, &b->io_error_count);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->tx_buffer_level, &b->tx_buffer_level);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->rx_buffer_level, &b->rx_buffer_level);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_period_encode_internal(sbp_encode_ctx_t *ctx,
                                const sbp_period_t *msg) {
  if (!sbp_s32_encode(ctx, &msg->avg)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->pmin)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->pmax)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->current)) {
    return false;
  }
  return true;
}

s8 sbp_period_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                     const sbp_period_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_period_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_period_decode_internal(sbp_decode_ctx_t *ctx, sbp_period_t *msg) {
  if (!sbp_s32_decode(ctx, &msg->avg)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->pmin)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->pmax)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->current)) {
    return false;
  }
  return true;
}

s8 sbp_period_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                     sbp_period_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_period_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_period_cmp(const sbp_period_t *a, const sbp_period_t *b) {
  int ret = 0;

  ret = sbp_s32_cmp(&a->avg, &b->avg);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->pmin, &b->pmin);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->pmax, &b->pmax);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->current, &b->current);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_latency_encode_internal(sbp_encode_ctx_t *ctx,
                                 const sbp_latency_t *msg) {
  if (!sbp_s32_encode(ctx, &msg->avg)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->lmin)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->lmax)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->current)) {
    return false;
  }
  return true;
}

s8 sbp_latency_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                      const sbp_latency_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_latency_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_latency_decode_internal(sbp_decode_ctx_t *ctx, sbp_latency_t *msg) {
  if (!sbp_s32_decode(ctx, &msg->avg)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->lmin)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->lmax)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->current)) {
    return false;
  }
  return true;
}

s8 sbp_latency_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                      sbp_latency_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_latency_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_latency_cmp(const sbp_latency_t *a, const sbp_latency_t *b) {
  int ret = 0;

  ret = sbp_s32_cmp(&a->avg, &b->avg);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->lmin, &b->lmin);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->lmax, &b->lmax);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->current, &b->current);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_uart_state_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_uart_state_t *msg) {
  if (!sbp_uart_channel_encode_internal(ctx, &msg->uart_a)) {
    return false;
  }
  if (!sbp_uart_channel_encode_internal(ctx, &msg->uart_b)) {
    return false;
  }
  if (!sbp_uart_channel_encode_internal(ctx, &msg->uart_ftdi)) {
    return false;
  }
  if (!sbp_latency_encode_internal(ctx, &msg->latency)) {
    return false;
  }
  if (!sbp_period_encode_internal(ctx, &msg->obs_period)) {
    return false;
  }
  return true;
}

s8 sbp_msg_uart_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_uart_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_uart_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_uart_state_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_uart_state_t *msg) {
  if (!sbp_uart_channel_decode_internal(ctx, &msg->uart_a)) {
    return false;
  }
  if (!sbp_uart_channel_decode_internal(ctx, &msg->uart_b)) {
    return false;
  }
  if (!sbp_uart_channel_decode_internal(ctx, &msg->uart_ftdi)) {
    return false;
  }
  if (!sbp_latency_decode_internal(ctx, &msg->latency)) {
    return false;
  }
  if (!sbp_period_decode_internal(ctx, &msg->obs_period)) {
    return false;
  }
  return true;
}

s8 sbp_msg_uart_state_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_uart_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_uart_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_uart_state_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_uart_state_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_uart_state_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_UART_STATE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_uart_state_cmp(const sbp_msg_uart_state_t *a,
                           const sbp_msg_uart_state_t *b) {
  int ret = 0;

  ret = sbp_uart_channel_cmp(&a->uart_a, &b->uart_a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_uart_channel_cmp(&a->uart_b, &b->uart_b);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_uart_channel_cmp(&a->uart_ftdi, &b->uart_ftdi);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_latency_cmp(&a->latency, &b->latency);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_period_cmp(&a->obs_period, &b->obs_period);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_uart_state_depa_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_uart_state_depa_t *msg) {
  if (!sbp_uart_channel_encode_internal(ctx, &msg->uart_a)) {
    return false;
  }
  if (!sbp_uart_channel_encode_internal(ctx, &msg->uart_b)) {
    return false;
  }
  if (!sbp_uart_channel_encode_internal(ctx, &msg->uart_ftdi)) {
    return false;
  }
  if (!sbp_latency_encode_internal(ctx, &msg->latency)) {
    return false;
  }
  return true;
}

s8 sbp_msg_uart_state_depa_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_uart_state_depa_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_uart_state_depa_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_uart_state_depa_decode_internal(sbp_decode_ctx_t *ctx,
                                             sbp_msg_uart_state_depa_t *msg) {
  if (!sbp_uart_channel_decode_internal(ctx, &msg->uart_a)) {
    return false;
  }
  if (!sbp_uart_channel_decode_internal(ctx, &msg->uart_b)) {
    return false;
  }
  if (!sbp_uart_channel_decode_internal(ctx, &msg->uart_ftdi)) {
    return false;
  }
  if (!sbp_latency_decode_internal(ctx, &msg->latency)) {
    return false;
  }
  return true;
}

s8 sbp_msg_uart_state_depa_decode(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read,
                                  sbp_msg_uart_state_depa_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_uart_state_depa_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_uart_state_depa_send(sbp_state_t *s, u16 sender_id,
                                const sbp_msg_uart_state_depa_t *msg,
                                sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_uart_state_depa_encode(payload, sizeof(payload),
                                          &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_UART_STATE_DEPA, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_uart_state_depa_cmp(const sbp_msg_uart_state_depa_t *a,
                                const sbp_msg_uart_state_depa_t *b) {
  int ret = 0;

  ret = sbp_uart_channel_cmp(&a->uart_a, &b->uart_a);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_uart_channel_cmp(&a->uart_b, &b->uart_b);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_uart_channel_cmp(&a->uart_ftdi, &b->uart_ftdi);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_latency_cmp(&a->latency, &b->latency);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_iar_state_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_msg_iar_state_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->num_hyps)) {
    return false;
  }
  return true;
}

s8 sbp_msg_iar_state_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_msg_iar_state_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_iar_state_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_iar_state_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_msg_iar_state_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->num_hyps)) {
    return false;
  }
  return true;
}

s8 sbp_msg_iar_state_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_msg_iar_state_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_iar_state_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_iar_state_send(sbp_state_t *s, u16 sender_id,
                          const sbp_msg_iar_state_t *msg,
                          sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_iar_state_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_IAR_STATE, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_iar_state_cmp(const sbp_msg_iar_state_t *a,
                          const sbp_msg_iar_state_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->num_hyps, &b->num_hyps);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_mask_satellite_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_mask_satellite_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->mask)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_mask_satellite_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_mask_satellite_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_mask_satellite_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_mask_satellite_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_mask_satellite_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->mask)) {
    return false;
  }
  if (!sbp_v4_gnss_signal_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_mask_satellite_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_mask_satellite_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_mask_satellite_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_mask_satellite_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_mask_satellite_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_mask_satellite_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_MASK_SATELLITE, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_mask_satellite_cmp(const sbp_msg_mask_satellite_t *a,
                               const sbp_msg_mask_satellite_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->mask, &b->mask);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gnss_signal_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_mask_satellite_dep_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_mask_satellite_dep_t *msg) {
  if (!sbp_u8_encode(ctx, &msg->mask)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_encode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_mask_satellite_dep_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_mask_satellite_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_mask_satellite_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_mask_satellite_dep_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_mask_satellite_dep_t *msg) {
  if (!sbp_u8_decode(ctx, &msg->mask)) {
    return false;
  }
  if (!sbp_gnss_signal_dep_decode_internal(ctx, &msg->sid)) {
    return false;
  }
  return true;
}

s8 sbp_msg_mask_satellite_dep_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_mask_satellite_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_mask_satellite_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_mask_satellite_dep_send(sbp_state_t *s, u16 sender_id,
                                   const sbp_msg_mask_satellite_dep_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_mask_satellite_dep_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_MASK_SATELLITE_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_mask_satellite_dep_cmp(const sbp_msg_mask_satellite_dep_t *a,
                                   const sbp_msg_mask_satellite_dep_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->mask, &b->mask);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gnss_signal_dep_cmp(&a->sid, &b->sid);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_device_monitor_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_device_monitor_t *msg) {
  if (!sbp_s16_encode(ctx, &msg->dev_vin)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->cpu_vint)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->cpu_vaux)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->cpu_temperature)) {
    return false;
  }
  if (!sbp_s16_encode(ctx, &msg->fe_temperature)) {
    return false;
  }
  return true;
}

s8 sbp_msg_device_monitor_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_device_monitor_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_device_monitor_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_device_monitor_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_device_monitor_t *msg) {
  if (!sbp_s16_decode(ctx, &msg->dev_vin)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->cpu_vint)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->cpu_vaux)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->cpu_temperature)) {
    return false;
  }
  if (!sbp_s16_decode(ctx, &msg->fe_temperature)) {
    return false;
  }
  return true;
}

s8 sbp_msg_device_monitor_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_device_monitor_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_device_monitor_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_device_monitor_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_device_monitor_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_device_monitor_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_DEVICE_MONITOR, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_device_monitor_cmp(const sbp_msg_device_monitor_t *a,
                               const sbp_msg_device_monitor_t *b) {
  int ret = 0;

  ret = sbp_s16_cmp(&a->dev_vin, &b->dev_vin);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->cpu_vint, &b->cpu_vint);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->cpu_vaux, &b->cpu_vaux);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->cpu_temperature, &b->cpu_temperature);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s16_cmp(&a->fe_temperature, &b->fe_temperature);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_command_req_command_init(sbp_msg_command_req_t *msg) {
  sbp_null_terminated_string_init(&msg->command);
}

bool sbp_msg_command_req_command_valid(const sbp_msg_command_req_t *msg) {
  return sbp_null_terminated_string_valid(&msg->command,
                                          SBP_MSG_COMMAND_REQ_COMMAND_MAX);
}

int sbp_msg_command_req_command_strcmp(const sbp_msg_command_req_t *a,
                                       const sbp_msg_command_req_t *b) {
  return sbp_null_terminated_string_strcmp(&a->command, &b->command,
                                           SBP_MSG_COMMAND_REQ_COMMAND_MAX);
}

size_t sbp_msg_command_req_command_encoded_len(
    const sbp_msg_command_req_t *msg) {
  return sbp_null_terminated_string_encoded_len(
      &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX);
}

size_t sbp_msg_command_req_command_space_remaining(
    const sbp_msg_command_req_t *msg) {
  return sbp_null_terminated_string_space_remaining(
      &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX);
}
bool sbp_msg_command_req_command_set(sbp_msg_command_req_t *msg,
                                     const char *new_str, bool should_trunc,
                                     size_t *n_written) {
  return sbp_null_terminated_string_set(&msg->command,
                                        SBP_MSG_COMMAND_REQ_COMMAND_MAX,
                                        should_trunc, n_written, new_str);
}

bool sbp_msg_command_req_command_set_raw(sbp_msg_command_req_t *msg,
                                         const char *new_buf,
                                         size_t new_buf_len, bool should_trunc,
                                         size_t *n_written) {
  return sbp_null_terminated_string_set_raw(
      &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX, should_trunc, n_written,
      new_buf, new_buf_len);
}

bool sbp_msg_command_req_command_printf(sbp_msg_command_req_t *msg,
                                        bool should_trunc, size_t *n_written,
                                        const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_vprintf(
      &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX, should_trunc, n_written,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_command_req_command_vprintf(sbp_msg_command_req_t *msg,
                                         bool should_trunc, size_t *n_written,
                                         const char *fmt, va_list ap) {
  return sbp_null_terminated_string_vprintf(&msg->command,
                                            SBP_MSG_COMMAND_REQ_COMMAND_MAX,
                                            should_trunc, n_written, fmt, ap);
}

bool sbp_msg_command_req_command_append_printf(sbp_msg_command_req_t *msg,
                                               bool should_trunc,
                                               size_t *n_written,
                                               const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_null_terminated_string_append_vprintf(
      &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX, should_trunc, n_written,
      fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_command_req_command_append_vprintf(sbp_msg_command_req_t *msg,
                                                bool should_trunc,
                                                size_t *n_written,
                                                const char *fmt, va_list ap) {
  return sbp_null_terminated_string_append_vprintf(
      &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX, should_trunc, n_written,
      fmt, ap);
}

const char *sbp_msg_command_req_command_get(const sbp_msg_command_req_t *msg) {
  return sbp_null_terminated_string_get(&msg->command,
                                        SBP_MSG_COMMAND_REQ_COMMAND_MAX);
}

size_t sbp_msg_command_req_command_strlen(const sbp_msg_command_req_t *msg) {
  return sbp_null_terminated_string_strlen(&msg->command,
                                           SBP_MSG_COMMAND_REQ_COMMAND_MAX);
}

bool sbp_msg_command_req_encode_internal(sbp_encode_ctx_t *ctx,
                                         const sbp_msg_command_req_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_null_terminated_string_encode(
          &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_command_req_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                              const sbp_msg_command_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_command_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_command_req_decode_internal(sbp_decode_ctx_t *ctx,
                                         sbp_msg_command_req_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_null_terminated_string_decode(
          &msg->command, SBP_MSG_COMMAND_REQ_COMMAND_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_command_req_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                              sbp_msg_command_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_command_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_command_req_send(sbp_state_t *s, u16 sender_id,
                            const sbp_msg_command_req_t *msg,
                            sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_command_req_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_COMMAND_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_command_req_cmp(const sbp_msg_command_req_t *a,
                            const sbp_msg_command_req_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_command_req_command_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_command_resp_encode_internal(sbp_encode_ctx_t *ctx,
                                          const sbp_msg_command_resp_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_s32_encode(ctx, &msg->code)) {
    return false;
  }
  return true;
}

s8 sbp_msg_command_resp_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                               const sbp_msg_command_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_command_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_command_resp_decode_internal(sbp_decode_ctx_t *ctx,
                                          sbp_msg_command_resp_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_s32_decode(ctx, &msg->code)) {
    return false;
  }
  return true;
}

s8 sbp_msg_command_resp_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                               sbp_msg_command_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_command_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_command_resp_send(sbp_state_t *s, u16 sender_id,
                             const sbp_msg_command_resp_t *msg,
                             sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_command_resp_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_COMMAND_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_command_resp_cmp(const sbp_msg_command_resp_t *a,
                             const sbp_msg_command_resp_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_s32_cmp(&a->code, &b->code);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

void sbp_msg_command_output_line_init(sbp_msg_command_output_t *msg) {
  sbp_unterminated_string_init(&msg->line);
}

bool sbp_msg_command_output_line_valid(const sbp_msg_command_output_t *msg) {
  return sbp_unterminated_string_valid(&msg->line,
                                       SBP_MSG_COMMAND_OUTPUT_LINE_MAX);
}

int sbp_msg_command_output_line_strcmp(const sbp_msg_command_output_t *a,
                                       const sbp_msg_command_output_t *b) {
  return sbp_unterminated_string_strcmp(&a->line, &b->line,
                                        SBP_MSG_COMMAND_OUTPUT_LINE_MAX);
}

size_t sbp_msg_command_output_line_encoded_len(
    const sbp_msg_command_output_t *msg) {
  return sbp_unterminated_string_encoded_len(&msg->line,
                                             SBP_MSG_COMMAND_OUTPUT_LINE_MAX);
}

size_t sbp_msg_command_output_line_space_remaining(
    const sbp_msg_command_output_t *msg) {
  return sbp_unterminated_string_space_remaining(
      &msg->line, SBP_MSG_COMMAND_OUTPUT_LINE_MAX);
}
bool sbp_msg_command_output_line_set(sbp_msg_command_output_t *msg,
                                     const char *new_str, bool should_trunc,
                                     size_t *n_written) {
  return sbp_unterminated_string_set(&msg->line,
                                     SBP_MSG_COMMAND_OUTPUT_LINE_MAX,
                                     should_trunc, n_written, new_str);
}

bool sbp_msg_command_output_line_set_raw(sbp_msg_command_output_t *msg,
                                         const char *new_buf,
                                         size_t new_buf_len, bool should_trunc,
                                         size_t *n_written) {
  return sbp_unterminated_string_set_raw(
      &msg->line, SBP_MSG_COMMAND_OUTPUT_LINE_MAX, should_trunc, n_written,
      new_buf, new_buf_len);
}

bool sbp_msg_command_output_line_printf(sbp_msg_command_output_t *msg,
                                        bool should_trunc, size_t *n_written,
                                        const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_vprintf(&msg->line,
                                             SBP_MSG_COMMAND_OUTPUT_LINE_MAX,
                                             should_trunc, n_written, fmt, ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_command_output_line_vprintf(sbp_msg_command_output_t *msg,
                                         bool should_trunc, size_t *n_written,
                                         const char *fmt, va_list ap) {
  return sbp_unterminated_string_vprintf(&msg->line,
                                         SBP_MSG_COMMAND_OUTPUT_LINE_MAX,
                                         should_trunc, n_written, fmt, ap);
}

bool sbp_msg_command_output_line_append_printf(sbp_msg_command_output_t *msg,
                                               bool should_trunc,
                                               size_t *n_written,
                                               const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  bool ret = sbp_unterminated_string_append_vprintf(
      &msg->line, SBP_MSG_COMMAND_OUTPUT_LINE_MAX, should_trunc, n_written, fmt,
      ap);
  va_end(ap);
  return ret;
}

bool sbp_msg_command_output_line_append_vprintf(sbp_msg_command_output_t *msg,
                                                bool should_trunc,
                                                size_t *n_written,
                                                const char *fmt, va_list ap) {
  return sbp_unterminated_string_append_vprintf(
      &msg->line, SBP_MSG_COMMAND_OUTPUT_LINE_MAX, should_trunc, n_written, fmt,
      ap);
}

const char *sbp_msg_command_output_line_get(
    const sbp_msg_command_output_t *msg) {
  return sbp_unterminated_string_get(&msg->line,
                                     SBP_MSG_COMMAND_OUTPUT_LINE_MAX);
}

size_t sbp_msg_command_output_line_strlen(const sbp_msg_command_output_t *msg) {
  return sbp_unterminated_string_strlen(&msg->line,
                                        SBP_MSG_COMMAND_OUTPUT_LINE_MAX);
}

bool sbp_msg_command_output_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_command_output_t *msg) {
  if (!sbp_u32_encode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_unterminated_string_encode(&msg->line,
                                      SBP_MSG_COMMAND_OUTPUT_LINE_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_command_output_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_command_output_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_command_output_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_command_output_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_command_output_t *msg) {
  if (!sbp_u32_decode(ctx, &msg->sequence)) {
    return false;
  }
  if (!sbp_unterminated_string_decode(&msg->line,
                                      SBP_MSG_COMMAND_OUTPUT_LINE_MAX, ctx)) {
    return false;
  }
  return true;
}

s8 sbp_msg_command_output_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_command_output_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_command_output_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_command_output_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_command_output_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_command_output_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_COMMAND_OUTPUT, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_command_output_cmp(const sbp_msg_command_output_t *a,
                               const sbp_msg_command_output_t *b) {
  int ret = 0;

  ret = sbp_u32_cmp(&a->sequence, &b->sequence);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_msg_command_output_line_strcmp(a, b);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_network_state_req_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_network_state_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_network_state_req_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_network_state_req_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_network_state_req_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_network_state_req_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_network_state_req_t *msg) {
  (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_msg_network_state_req_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_network_state_req_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_network_state_req_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_network_state_req_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_network_state_req_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_network_state_req_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NETWORK_STATE_REQ, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_network_state_req_cmp(const sbp_msg_network_state_req_t *a,
                                  const sbp_msg_network_state_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

bool sbp_msg_network_state_resp_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_network_state_resp_t *msg) {
  for (size_t i = 0; i < SBP_MSG_NETWORK_STATE_RESP_IPV4_ADDRESS_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->ipv4_address[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->ipv4_mask_size)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_NETWORK_STATE_RESP_IPV6_ADDRESS_MAX; i++) {
    if (!sbp_u8_encode(ctx, &msg->ipv6_address[i])) {
      return false;
    }
  }
  if (!sbp_u8_encode(ctx, &msg->ipv6_mask_size)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->rx_bytes)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tx_bytes)) {
    return false;
  }
  for (size_t i = 0; i < SBP_MSG_NETWORK_STATE_RESP_INTERFACE_NAME_MAX; i++) {
    if (!sbp_char_encode(ctx, &msg->interface_name[i])) {
      return false;
    }
  }
  if (!sbp_u32_encode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_network_state_resp_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_msg_network_state_resp_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_network_state_resp_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_network_state_resp_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_network_state_resp_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_NETWORK_STATE_RESP_IPV4_ADDRESS_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->ipv4_address[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->ipv4_mask_size)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_NETWORK_STATE_RESP_IPV6_ADDRESS_MAX; i++) {
    if (!sbp_u8_decode(ctx, &msg->ipv6_address[i])) {
      return false;
    }
  }
  if (!sbp_u8_decode(ctx, &msg->ipv6_mask_size)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->rx_bytes)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tx_bytes)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_MSG_NETWORK_STATE_RESP_INTERFACE_NAME_MAX; i++) {
    if (!sbp_char_decode(ctx, &msg->interface_name[i])) {
      return false;
    }
  }
  if (!sbp_u32_decode(ctx, &msg->flags)) {
    return false;
  }
  return true;
}

s8 sbp_msg_network_state_resp_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_msg_network_state_resp_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_network_state_resp_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_network_state_resp_send(sbp_state_t *s, u16 sender_id,
                                   const sbp_msg_network_state_resp_t *msg,
                                   sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_network_state_resp_encode(payload, sizeof(payload),
                                             &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NETWORK_STATE_RESP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_network_state_resp_cmp(const sbp_msg_network_state_resp_t *a,
                                   const sbp_msg_network_state_resp_t *b) {
  int ret = 0;

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_NETWORK_STATE_RESP_IPV4_ADDRESS_MAX; i++) {
    ret = sbp_u8_cmp(&a->ipv4_address[i], &b->ipv4_address[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->ipv4_mask_size, &b->ipv4_mask_size);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_NETWORK_STATE_RESP_IPV6_ADDRESS_MAX; i++) {
    ret = sbp_u8_cmp(&a->ipv6_address[i], &b->ipv6_address[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->ipv6_mask_size, &b->ipv6_mask_size);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->rx_bytes, &b->rx_bytes);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tx_bytes, &b->tx_bytes);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0;
       ret == 0 && i < SBP_MSG_NETWORK_STATE_RESP_INTERFACE_NAME_MAX; i++) {
    ret = sbp_char_cmp(&a->interface_name[i], &b->interface_name[i]);
  }
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->flags, &b->flags);
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_network_usage_encode_internal(sbp_encode_ctx_t *ctx,
                                       const sbp_network_usage_t *msg) {
  if (!sbp_u64_encode(ctx, &msg->duration)) {
    return false;
  }
  if (!sbp_u64_encode(ctx, &msg->total_bytes)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->rx_bytes)) {
    return false;
  }
  if (!sbp_u32_encode(ctx, &msg->tx_bytes)) {
    return false;
  }
  for (size_t i = 0; i < SBP_NETWORK_USAGE_INTERFACE_NAME_MAX; i++) {
    if (!sbp_char_encode(ctx, &msg->interface_name[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_network_usage_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                            const sbp_network_usage_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_network_usage_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_network_usage_decode_internal(sbp_decode_ctx_t *ctx,
                                       sbp_network_usage_t *msg) {
  if (!sbp_u64_decode(ctx, &msg->duration)) {
    return false;
  }
  if (!sbp_u64_decode(ctx, &msg->total_bytes)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->rx_bytes)) {
    return false;
  }
  if (!sbp_u32_decode(ctx, &msg->tx_bytes)) {
    return false;
  }
  for (uint8_t i = 0; i < SBP_NETWORK_USAGE_INTERFACE_NAME_MAX; i++) {
    if (!sbp_char_decode(ctx, &msg->interface_name[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_network_usage_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                            sbp_network_usage_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_network_usage_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

int sbp_network_usage_cmp(const sbp_network_usage_t *a,
                          const sbp_network_usage_t *b) {
  int ret = 0;

  ret = sbp_u64_cmp(&a->duration, &b->duration);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u64_cmp(&a->total_bytes, &b->total_bytes);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->rx_bytes, &b->rx_bytes);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u32_cmp(&a->tx_bytes, &b->tx_bytes);
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_NETWORK_USAGE_INTERFACE_NAME_MAX;
       i++) {
    ret = sbp_char_cmp(&a->interface_name[i], &b->interface_name[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_network_bandwidth_usage_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_network_bandwidth_usage_t *msg) {
  for (size_t i = 0; i < msg->n_interfaces; i++) {
    if (!sbp_network_usage_encode_internal(ctx, &msg->interfaces[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_network_bandwidth_usage_encode(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_network_bandwidth_usage_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_network_bandwidth_usage_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_network_bandwidth_usage_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_network_bandwidth_usage_t *msg) {
  msg->n_interfaces =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_NETWORK_USAGE_ENCODED_LEN);
  for (uint8_t i = 0; i < msg->n_interfaces; i++) {
    if (!sbp_network_usage_decode_internal(ctx, &msg->interfaces[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_network_bandwidth_usage_decode(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_network_bandwidth_usage_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_network_bandwidth_usage_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_network_bandwidth_usage_send(
    sbp_state_t *s, u16 sender_id, const sbp_msg_network_bandwidth_usage_t *msg,
    sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_network_bandwidth_usage_encode(payload, sizeof(payload),
                                                  &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_NETWORK_BANDWIDTH_USAGE, sender_id,
                          payload_len, payload, write);
}

int sbp_msg_network_bandwidth_usage_cmp(
    const sbp_msg_network_bandwidth_usage_t *a,
    const sbp_msg_network_bandwidth_usage_t *b) {
  int ret = 0;

  ret = sbp_u8_cmp(&a->n_interfaces, &b->n_interfaces);
  for (uint8_t i = 0; ret == 0 && i < a->n_interfaces; i++) {
    ret = sbp_network_usage_cmp(&a->interfaces[i], &b->interfaces[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_cell_modem_status_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_cell_modem_status_t *msg) {
  if (!sbp_s8_encode(ctx, &msg->signal_strength)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->signal_error_rate)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_reserved; i++) {
    if (!sbp_u8_encode(ctx, &msg->reserved[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_cell_modem_status_encode(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_msg_cell_modem_status_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_cell_modem_status_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_cell_modem_status_decode_internal(
    sbp_decode_ctx_t *ctx, sbp_msg_cell_modem_status_t *msg) {
  if (!sbp_s8_decode(ctx, &msg->signal_strength)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->signal_error_rate)) {
    return false;
  }
  msg->n_reserved =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_reserved; i++) {
    if (!sbp_u8_decode(ctx, &msg->reserved[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_cell_modem_status_decode(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_msg_cell_modem_status_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_cell_modem_status_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_cell_modem_status_send(sbp_state_t *s, u16 sender_id,
                                  const sbp_msg_cell_modem_status_t *msg,
                                  sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_cell_modem_status_encode(payload, sizeof(payload),
                                            &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_CELL_MODEM_STATUS, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_cell_modem_status_cmp(const sbp_msg_cell_modem_status_t *a,
                                  const sbp_msg_cell_modem_status_t *b) {
  int ret = 0;

  ret = sbp_s8_cmp(&a->signal_strength, &b->signal_strength);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->signal_error_rate, &b->signal_error_rate);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_reserved, &b->n_reserved);
  for (uint8_t i = 0; ret == 0 && i < a->n_reserved; i++) {
    ret = sbp_u8_cmp(&a->reserved[i], &b->reserved[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_specan_dep_encode_internal(sbp_encode_ctx_t *ctx,
                                        const sbp_msg_specan_dep_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->channel_tag)) {
    return false;
  }
  if (!sbp_gps_time_dep_encode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->freq_ref)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->freq_step)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->amplitude_ref)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->amplitude_unit)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_amplitude_value; i++) {
    if (!sbp_u8_encode(ctx, &msg->amplitude_value[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_specan_dep_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                             const sbp_msg_specan_dep_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_specan_dep_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_specan_dep_decode_internal(sbp_decode_ctx_t *ctx,
                                        sbp_msg_specan_dep_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->channel_tag)) {
    return false;
  }
  if (!sbp_gps_time_dep_decode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->freq_ref)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->freq_step)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->amplitude_ref)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->amplitude_unit)) {
    return false;
  }
  msg->n_amplitude_value =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++) {
    if (!sbp_u8_decode(ctx, &msg->amplitude_value[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_specan_dep_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                             sbp_msg_specan_dep_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_specan_dep_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_specan_dep_send(sbp_state_t *s, u16 sender_id,
                           const sbp_msg_specan_dep_t *msg,
                           sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret =
      sbp_msg_specan_dep_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SPECAN_DEP, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_specan_dep_cmp(const sbp_msg_specan_dep_t *a,
                           const sbp_msg_specan_dep_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->channel_tag, &b->channel_tag);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_gps_time_dep_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->freq_ref, &b->freq_ref);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->freq_step, &b->freq_step);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->amplitude_ref, &b->amplitude_ref);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->amplitude_unit, &b->amplitude_unit);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_amplitude_value, &b->n_amplitude_value);
  for (uint8_t i = 0; ret == 0 && i < a->n_amplitude_value; i++) {
    ret = sbp_u8_cmp(&a->amplitude_value[i], &b->amplitude_value[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_specan_encode_internal(sbp_encode_ctx_t *ctx,
                                    const sbp_msg_specan_t *msg) {
  if (!sbp_u16_encode(ctx, &msg->channel_tag)) {
    return false;
  }
  if (!sbp_v4_gps_time_encode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->freq_ref)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->freq_step)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->amplitude_ref)) {
    return false;
  }
  if (!sbp_float_encode(ctx, &msg->amplitude_unit)) {
    return false;
  }
  for (size_t i = 0; i < msg->n_amplitude_value; i++) {
    if (!sbp_u8_encode(ctx, &msg->amplitude_value[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_specan_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                         const sbp_msg_specan_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_specan_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_specan_decode_internal(sbp_decode_ctx_t *ctx,
                                    sbp_msg_specan_t *msg) {
  if (!sbp_u16_decode(ctx, &msg->channel_tag)) {
    return false;
  }
  if (!sbp_v4_gps_time_decode_internal(ctx, &msg->t)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->freq_ref)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->freq_step)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->amplitude_ref)) {
    return false;
  }
  if (!sbp_float_decode(ctx, &msg->amplitude_unit)) {
    return false;
  }
  msg->n_amplitude_value =
      (uint8_t)((ctx->buf_len - ctx->offset) / SBP_ENCODED_LEN_U8);
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++) {
    if (!sbp_u8_decode(ctx, &msg->amplitude_value[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_specan_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                         sbp_msg_specan_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_specan_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_specan_send(sbp_state_t *s, u16 sender_id,
                       const sbp_msg_specan_t *msg, sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_specan_encode(payload, sizeof(payload), &payload_len, msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_SPECAN, sender_id, payload_len, payload,
                          write);
}

int sbp_msg_specan_cmp(const sbp_msg_specan_t *a, const sbp_msg_specan_t *b) {
  int ret = 0;

  ret = sbp_u16_cmp(&a->channel_tag, &b->channel_tag);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_v4_gps_time_cmp(&a->t, &b->t);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->freq_ref, &b->freq_ref);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->freq_step, &b->freq_step);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->amplitude_ref, &b->amplitude_ref);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_float_cmp(&a->amplitude_unit, &b->amplitude_unit);
  if (ret != 0) {
    return ret;
  }

  ret = sbp_u8_cmp(&a->n_amplitude_value, &b->n_amplitude_value);
  for (uint8_t i = 0; ret == 0 && i < a->n_amplitude_value; i++) {
    ret = sbp_u8_cmp(&a->amplitude_value[i], &b->amplitude_value[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}

bool sbp_msg_front_end_gain_encode_internal(
    sbp_encode_ctx_t *ctx, const sbp_msg_front_end_gain_t *msg) {
  for (size_t i = 0; i < SBP_MSG_FRONT_END_GAIN_RF_GAIN_MAX; i++) {
    if (!sbp_s8_encode(ctx, &msg->rf_gain[i])) {
      return false;
    }
  }
  for (size_t i = 0; i < SBP_MSG_FRONT_END_GAIN_IF_GAIN_MAX; i++) {
    if (!sbp_s8_encode(ctx, &msg->if_gain[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_front_end_gain_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                 const sbp_msg_front_end_gain_t *msg) {
  sbp_encode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_front_end_gain_encode_internal(&ctx, msg)) {
    return SBP_ENCODE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

bool sbp_msg_front_end_gain_decode_internal(sbp_decode_ctx_t *ctx,
                                            sbp_msg_front_end_gain_t *msg) {
  for (uint8_t i = 0; i < SBP_MSG_FRONT_END_GAIN_RF_GAIN_MAX; i++) {
    if (!sbp_s8_decode(ctx, &msg->rf_gain[i])) {
      return false;
    }
  }
  for (uint8_t i = 0; i < SBP_MSG_FRONT_END_GAIN_IF_GAIN_MAX; i++) {
    if (!sbp_s8_decode(ctx, &msg->if_gain[i])) {
      return false;
    }
  }
  return true;
}

s8 sbp_msg_front_end_gain_decode(const uint8_t *buf, uint8_t len,
                                 uint8_t *n_read,
                                 sbp_msg_front_end_gain_t *msg) {
  sbp_decode_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!sbp_msg_front_end_gain_decode_internal(&ctx, msg)) {
    return SBP_DECODE_ERROR;
  }
  if (n_read != NULL) {
    *n_read = (uint8_t)ctx.offset;
  }
  return SBP_OK;
}

s8 sbp_msg_front_end_gain_send(sbp_state_t *s, u16 sender_id,
                               const sbp_msg_front_end_gain_t *msg,
                               sbp_write_fn_t write) {
  uint8_t payload[SBP_MAX_PAYLOAD_LEN];
  uint8_t payload_len;
  s8 ret = sbp_msg_front_end_gain_encode(payload, sizeof(payload), &payload_len,
                                         msg);
  if (ret != SBP_OK) {
    return ret;
  }
  return sbp_payload_send(s, SBP_MSG_FRONT_END_GAIN, sender_id, payload_len,
                          payload, write);
}

int sbp_msg_front_end_gain_cmp(const sbp_msg_front_end_gain_t *a,
                               const sbp_msg_front_end_gain_t *b) {
  int ret = 0;

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_FRONT_END_GAIN_RF_GAIN_MAX; i++) {
    ret = sbp_s8_cmp(&a->rf_gain[i], &b->rf_gain[i]);
  }
  if (ret != 0) {
    return ret;
  }

  for (uint8_t i = 0; ret == 0 && i < SBP_MSG_FRONT_END_GAIN_IF_GAIN_MAX; i++) {
    ret = sbp_s8_cmp(&a->if_gain[i], &b->if_gain[i]);
  }
  if (ret != 0) {
    return ret;
  }
  return ret;
}
