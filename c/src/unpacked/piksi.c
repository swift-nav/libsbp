#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <libsbp/internal/unpacked/common.h>
#include <libsbp/unpacked/piksi.h>
#include <libsbp/internal/unpacked/piksi.h>
#include <libsbp/internal/unpacked/string/multipart.h>
#include <libsbp/internal/unpacked/string/null_terminated.h>
#include <libsbp/internal/unpacked/string/sequence.h>
#include <libsbp/internal/unpacked/string/unterminated.h>
                                                                                                              
size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_almanac_t(sbp_pack_ctx_t *ctx, const sbp_msg_almanac_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_almanac_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_almanac_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_almanac_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_almanac_t(sbp_unpack_ctx_t *ctx, sbp_msg_almanac_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_almanac_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_almanac_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_almanac_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_almanac_t(const sbp_msg_almanac_t *a, const sbp_msg_almanac_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_set_time_t(sbp_pack_ctx_t *ctx, const sbp_msg_set_time_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_set_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_set_time_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_set_time_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_set_time_t(sbp_unpack_ctx_t *ctx, sbp_msg_set_time_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_set_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_set_time_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_set_time_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_set_time_t(const sbp_msg_set_time_t *a, const sbp_msg_set_time_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_reset_t(sbp_pack_ctx_t *ctx, const sbp_msg_reset_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_reset_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_reset_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_reset_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_reset_t(sbp_unpack_ctx_t *ctx, sbp_msg_reset_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_reset_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_reset_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_reset_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_reset_t(const sbp_msg_reset_t *a, const sbp_msg_reset_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_reset_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_reset_dep_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_reset_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_reset_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_reset_dep_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_reset_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_reset_dep_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_reset_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_reset_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_reset_dep_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *a, const sbp_msg_reset_dep_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_cw_results_t(sbp_pack_ctx_t *ctx, const sbp_msg_cw_results_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_cw_results_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_cw_results_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_cw_results_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_cw_results_t(sbp_unpack_ctx_t *ctx, sbp_msg_cw_results_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_cw_results_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_cw_results_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_cw_results_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *a, const sbp_msg_cw_results_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_cw_start_t(sbp_pack_ctx_t *ctx, const sbp_msg_cw_start_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_cw_start_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_cw_start_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_cw_start_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_cw_start_t(sbp_unpack_ctx_t *ctx, sbp_msg_cw_start_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_cw_start_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_cw_start_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_cw_start_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *a, const sbp_msg_cw_start_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->filter);
  return packed_size;
}

bool pack_sbp_msg_reset_filters_t(sbp_pack_ctx_t *ctx, const sbp_msg_reset_filters_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->filter)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_reset_filters_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_reset_filters_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_reset_filters_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_reset_filters_t(sbp_unpack_ctx_t *ctx, sbp_msg_reset_filters_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->filter)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_reset_filters_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_reset_filters_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_reset_filters_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *a, const sbp_msg_reset_filters_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->filter, &b->filter);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_init_base_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_init_base_dep_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_init_base_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_init_base_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_init_base_dep_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_init_base_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_init_base_dep_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_init_base_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_init_base_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_init_base_dep_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *a, const sbp_msg_init_base_dep_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 20 * sbp_packed_size_char(&msg->name[0]));
  packed_size += sbp_packed_size_u16(&msg->cpu);
  packed_size += sbp_packed_size_u32(&msg->stack_free);
  return packed_size;
}

bool pack_sbp_msg_thread_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_thread_state_t *msg)
{
  for (uint8_t i = 0; i < 20; i++)
  {
    if (!sbp_pack_char(ctx, &msg->name[i])) { return false; }
  }
  if (!sbp_pack_u16(ctx, &msg->cpu)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->stack_free)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_thread_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_thread_state_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_thread_state_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_thread_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_thread_state_t *msg)
{
  for (uint8_t i = 0; i < 20; i++) {
    if (!sbp_unpack_char(ctx, &msg->name[i])) { return false; }
  }
  if (!sbp_unpack_u16(ctx, &msg->cpu)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->stack_free)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_thread_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_thread_state_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_thread_state_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *a, const sbp_msg_thread_state_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 20 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->name[i], &b->name[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->cpu, &b->cpu);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->stack_free, &b->stack_free);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_uart_channel_t(const sbp_uart_channel_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_float(&msg->tx_throughput);
  packed_size += sbp_packed_size_float(&msg->rx_throughput);
  packed_size += sbp_packed_size_u16(&msg->crc_error_count);
  packed_size += sbp_packed_size_u16(&msg->io_error_count);
  packed_size += sbp_packed_size_u8(&msg->tx_buffer_level);
  packed_size += sbp_packed_size_u8(&msg->rx_buffer_level);
  return packed_size;
}

bool pack_sbp_uart_channel_t(sbp_pack_ctx_t *ctx, const sbp_uart_channel_t *msg)
{
  if (!sbp_pack_float(ctx, &msg->tx_throughput)) { return false; }
  if (!sbp_pack_float(ctx, &msg->rx_throughput)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->crc_error_count)) { return false; }
  if (!sbp_pack_u16(ctx, &msg->io_error_count)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->tx_buffer_level)) { return false; }
  if (!sbp_pack_u8(ctx, &msg->rx_buffer_level)) { return false; }
  return true;
}

s8 sbp_pack_sbp_uart_channel_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_uart_channel_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_uart_channel_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_uart_channel_t(sbp_unpack_ctx_t *ctx, sbp_uart_channel_t *msg)
{
  if (!sbp_unpack_float(ctx, &msg->tx_throughput)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->rx_throughput)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->crc_error_count)) { return false; }
  if (!sbp_unpack_u16(ctx, &msg->io_error_count)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->tx_buffer_level)) { return false; }
  if (!sbp_unpack_u8(ctx, &msg->rx_buffer_level)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_uart_channel_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_uart_channel_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_uart_channel_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_uart_channel_t(const sbp_uart_channel_t *a, const sbp_uart_channel_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_float(&a->tx_throughput, &b->tx_throughput);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->rx_throughput, &b->rx_throughput);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->crc_error_count, &b->crc_error_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->io_error_count, &b->io_error_count);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->tx_buffer_level, &b->tx_buffer_level);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->rx_buffer_level, &b->rx_buffer_level);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_period_t(const sbp_period_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->avg);
  packed_size += sbp_packed_size_s32(&msg->pmin);
  packed_size += sbp_packed_size_s32(&msg->pmax);
  packed_size += sbp_packed_size_s32(&msg->current);
  return packed_size;
}

bool pack_sbp_period_t(sbp_pack_ctx_t *ctx, const sbp_period_t *msg)
{
  if (!sbp_pack_s32(ctx, &msg->avg)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->pmin)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->pmax)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->current)) { return false; }
  return true;
}

s8 sbp_pack_sbp_period_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_period_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_period_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_period_t(sbp_unpack_ctx_t *ctx, sbp_period_t *msg)
{
  if (!sbp_unpack_s32(ctx, &msg->avg)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->pmin)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->pmax)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->current)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_period_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_period_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_period_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_period_t(const sbp_period_t *a, const sbp_period_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s32(&a->avg, &b->avg);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->pmin, &b->pmin);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->pmax, &b->pmax);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->current, &b->current);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_latency_t(const sbp_latency_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s32(&msg->avg);
  packed_size += sbp_packed_size_s32(&msg->lmin);
  packed_size += sbp_packed_size_s32(&msg->lmax);
  packed_size += sbp_packed_size_s32(&msg->current);
  return packed_size;
}

bool pack_sbp_latency_t(sbp_pack_ctx_t *ctx, const sbp_latency_t *msg)
{
  if (!sbp_pack_s32(ctx, &msg->avg)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->lmin)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->lmax)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->current)) { return false; }
  return true;
}

s8 sbp_pack_sbp_latency_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_latency_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_latency_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_latency_t(sbp_unpack_ctx_t *ctx, sbp_latency_t *msg)
{
  if (!sbp_unpack_s32(ctx, &msg->avg)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->lmin)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->lmax)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->current)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_latency_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_latency_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_latency_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_latency_t(const sbp_latency_t *a, const sbp_latency_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s32(&a->avg, &b->avg);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->lmin, &b->lmin);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->lmax, &b->lmax);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->current, &b->current);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_a);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_b);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_ftdi);
  packed_size += sbp_packed_size_sbp_latency_t(&msg->latency);
  packed_size += sbp_packed_size_sbp_period_t(&msg->obs_period);
  return packed_size;
}

bool pack_sbp_msg_uart_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_uart_state_t *msg)
{
  if (!sbp_pack_sbp_uart_channel_t(ctx, &msg->uart_a)) { return false; }
  if (!sbp_pack_sbp_uart_channel_t(ctx, &msg->uart_b)) { return false; }
  if (!sbp_pack_sbp_uart_channel_t(ctx, &msg->uart_ftdi)) { return false; }
  if (!sbp_pack_sbp_latency_t(ctx, &msg->latency)) { return false; }
  if (!sbp_pack_sbp_period_t(ctx, &msg->obs_period)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_uart_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_uart_state_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_uart_state_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_uart_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_uart_state_t *msg)
{
  if (!sbp_unpack_sbp_uart_channel_t(ctx, &msg->uart_a)) { return false; }
  if (!sbp_unpack_sbp_uart_channel_t(ctx, &msg->uart_b)) { return false; }
  if (!sbp_unpack_sbp_uart_channel_t(ctx, &msg->uart_ftdi)) { return false; }
  if (!sbp_unpack_sbp_latency_t(ctx, &msg->latency)) { return false; }
  if (!sbp_unpack_sbp_period_t(ctx, &msg->obs_period)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_uart_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_uart_state_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_uart_state_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *a, const sbp_msg_uart_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_uart_channel_t(&a->uart_a, &b->uart_a);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_uart_channel_t(&a->uart_b, &b->uart_b);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_uart_channel_t(&a->uart_ftdi, &b->uart_ftdi);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_latency_t(&a->latency, &b->latency);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_period_t(&a->obs_period, &b->obs_period);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_a);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_b);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_ftdi);
  packed_size += sbp_packed_size_sbp_latency_t(&msg->latency);
  return packed_size;
}

bool pack_sbp_msg_uart_state_depa_t(sbp_pack_ctx_t *ctx, const sbp_msg_uart_state_depa_t *msg)
{
  if (!sbp_pack_sbp_uart_channel_t(ctx, &msg->uart_a)) { return false; }
  if (!sbp_pack_sbp_uart_channel_t(ctx, &msg->uart_b)) { return false; }
  if (!sbp_pack_sbp_uart_channel_t(ctx, &msg->uart_ftdi)) { return false; }
  if (!sbp_pack_sbp_latency_t(ctx, &msg->latency)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_uart_state_depa_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_uart_state_depa_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_uart_state_depa_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_uart_state_depa_t(sbp_unpack_ctx_t *ctx, sbp_msg_uart_state_depa_t *msg)
{
  if (!sbp_unpack_sbp_uart_channel_t(ctx, &msg->uart_a)) { return false; }
  if (!sbp_unpack_sbp_uart_channel_t(ctx, &msg->uart_b)) { return false; }
  if (!sbp_unpack_sbp_uart_channel_t(ctx, &msg->uart_ftdi)) { return false; }
  if (!sbp_unpack_sbp_latency_t(ctx, &msg->latency)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_uart_state_depa_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_uart_state_depa_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_uart_state_depa_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *a, const sbp_msg_uart_state_depa_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_sbp_uart_channel_t(&a->uart_a, &b->uart_a);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_uart_channel_t(&a->uart_b, &b->uart_b);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_uart_channel_t(&a->uart_ftdi, &b->uart_ftdi);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_latency_t(&a->latency, &b->latency);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->num_hyps);
  return packed_size;
}

bool pack_sbp_msg_iar_state_t(sbp_pack_ctx_t *ctx, const sbp_msg_iar_state_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->num_hyps)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_iar_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_iar_state_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_iar_state_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_iar_state_t(sbp_unpack_ctx_t *ctx, sbp_msg_iar_state_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->num_hyps)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_iar_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_iar_state_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_iar_state_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *a, const sbp_msg_iar_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->num_hyps, &b->num_hyps);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

bool pack_sbp_msg_mask_satellite_t(sbp_pack_ctx_t *ctx, const sbp_msg_mask_satellite_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->mask)) { return false; }
  if (!sbp_pack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_mask_satellite_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_mask_satellite_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_mask_satellite_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_mask_satellite_t(sbp_unpack_ctx_t *ctx, sbp_msg_mask_satellite_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->mask)) { return false; }
  if (!sbp_unpack_sbp_sbp_gnss_signal_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_mask_satellite_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_mask_satellite_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_mask_satellite_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *a, const sbp_msg_mask_satellite_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->mask, &b->mask);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

bool pack_sbp_msg_mask_satellite_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_mask_satellite_dep_t *msg)
{
  if (!sbp_pack_u8(ctx, &msg->mask)) { return false; }
  if (!sbp_pack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_mask_satellite_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_mask_satellite_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_mask_satellite_dep_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_mask_satellite_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_mask_satellite_dep_t *msg)
{
  if (!sbp_unpack_u8(ctx, &msg->mask)) { return false; }
  if (!sbp_unpack_sbp_gnss_signal_dep_t(ctx, &msg->sid)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_mask_satellite_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_mask_satellite_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_mask_satellite_dep_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *a, const sbp_msg_mask_satellite_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->mask, &b->mask);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s16(&msg->dev_vin);
  packed_size += sbp_packed_size_s16(&msg->cpu_vint);
  packed_size += sbp_packed_size_s16(&msg->cpu_vaux);
  packed_size += sbp_packed_size_s16(&msg->cpu_temperature);
  packed_size += sbp_packed_size_s16(&msg->fe_temperature);
  return packed_size;
}

bool pack_sbp_msg_device_monitor_t(sbp_pack_ctx_t *ctx, const sbp_msg_device_monitor_t *msg)
{
  if (!sbp_pack_s16(ctx, &msg->dev_vin)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->cpu_vint)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->cpu_vaux)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->cpu_temperature)) { return false; }
  if (!sbp_pack_s16(ctx, &msg->fe_temperature)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_device_monitor_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_device_monitor_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_device_monitor_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_device_monitor_t(sbp_unpack_ctx_t *ctx, sbp_msg_device_monitor_t *msg)
{
  if (!sbp_unpack_s16(ctx, &msg->dev_vin)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->cpu_vint)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->cpu_vaux)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->cpu_temperature)) { return false; }
  if (!sbp_unpack_s16(ctx, &msg->fe_temperature)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_device_monitor_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_device_monitor_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_device_monitor_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *a, const sbp_msg_device_monitor_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s16(&a->dev_vin, &b->dev_vin);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->cpu_vint, &b->cpu_vint);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->cpu_vaux, &b->cpu_vaux);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->cpu_temperature, &b->cpu_temperature);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s16(&a->fe_temperature, &b->fe_temperature);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_null_terminated_string_packed_len(&msg->command, 251
      );
  return packed_size;
}

bool pack_sbp_msg_command_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_command_req_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_null_terminated_string_pack(&msg->command, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_command_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_command_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_command_req_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_command_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_command_req_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_null_terminated_string_unpack(&msg->command, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_command_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_command_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_command_req_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_command_req_t(const sbp_msg_command_req_t *a, const sbp_msg_command_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->command, &b->command, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_s32(&msg->code);
  return packed_size;
}

bool pack_sbp_msg_command_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_command_resp_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_pack_s32(ctx, &msg->code)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_command_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_command_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_command_resp_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_command_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_command_resp_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unpack_s32(ctx, &msg->code)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_command_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_command_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_command_resp_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *a, const sbp_msg_command_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->code, &b->code);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_command_output_t(const sbp_msg_command_output_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_unterminated_string_packed_len(&msg->line, 251
      );
  return packed_size;
}

bool pack_sbp_msg_command_output_t(sbp_pack_ctx_t *ctx, const sbp_msg_command_output_t *msg)
{
  if (!sbp_pack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unterminated_string_pack(&msg->line, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_command_output_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_command_output_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_command_output_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_command_output_t(sbp_unpack_ctx_t *ctx, sbp_msg_command_output_t *msg)
{
  if (!sbp_unpack_u32(ctx, &msg->sequence)) { return false; }
  if (!sbp_unterminated_string_unpack(&msg->line, 251,
      ctx)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_command_output_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_command_output_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_command_output_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_command_output_t(const sbp_msg_command_output_t *a, const sbp_msg_command_output_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->line, &b->line, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *msg) {
  (void)msg;
  return 0;
}

bool pack_sbp_msg_network_state_req_t(sbp_pack_ctx_t *ctx, const sbp_msg_network_state_req_t *msg)
{
  (void)ctx;
  (void)msg;
  return true;
  return true;
}

s8 sbp_pack_sbp_msg_network_state_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_network_state_req_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_network_state_req_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_network_state_req_t(sbp_unpack_ctx_t *ctx, sbp_msg_network_state_req_t *msg)
{
    (void)ctx;
  (void)msg;
  return true;
}

s8 sbp_unpack_sbp_msg_network_state_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_network_state_req_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_network_state_req_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *a, const sbp_msg_network_state_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 4 * sbp_packed_size_u8(&msg->ipv4_address[0]));
  packed_size += sbp_packed_size_u8(&msg->ipv4_mask_size);
  packed_size += ( 16 * sbp_packed_size_u8(&msg->ipv6_address[0]));
  packed_size += sbp_packed_size_u8(&msg->ipv6_mask_size);
  packed_size += sbp_packed_size_u32(&msg->rx_bytes);
  packed_size += sbp_packed_size_u32(&msg->tx_bytes);
  packed_size += ( 16 * sbp_packed_size_char(&msg->interface_name[0]));
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

bool pack_sbp_msg_network_state_resp_t(sbp_pack_ctx_t *ctx, const sbp_msg_network_state_resp_t *msg)
{
  for (uint8_t i = 0; i < 4; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->ipv4_address[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->ipv4_mask_size)) { return false; }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->ipv6_address[i])) { return false; }
  }
  if (!sbp_pack_u8(ctx, &msg->ipv6_mask_size)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->rx_bytes)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tx_bytes)) { return false; }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!sbp_pack_char(ctx, &msg->interface_name[i])) { return false; }
  }
  if (!sbp_pack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_pack_sbp_msg_network_state_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_network_state_resp_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_network_state_resp_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_network_state_resp_t(sbp_unpack_ctx_t *ctx, sbp_msg_network_state_resp_t *msg)
{
  for (uint8_t i = 0; i < 4; i++) {
    if (!sbp_unpack_u8(ctx, &msg->ipv4_address[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->ipv4_mask_size)) { return false; }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_unpack_u8(ctx, &msg->ipv6_address[i])) { return false; }
  }
  if (!sbp_unpack_u8(ctx, &msg->ipv6_mask_size)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->rx_bytes)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tx_bytes)) { return false; }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_unpack_char(ctx, &msg->interface_name[i])) { return false; }
  }
  if (!sbp_unpack_u32(ctx, &msg->flags)) { return false; }
  return true;
}

s8 sbp_unpack_sbp_msg_network_state_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_network_state_resp_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_network_state_resp_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *a, const sbp_msg_network_state_resp_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 4 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->ipv4_address[i], &b->ipv4_address[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->ipv4_mask_size, &b->ipv4_mask_size);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->ipv6_address[i], &b->ipv6_address[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->ipv6_mask_size, &b->ipv6_mask_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->rx_bytes, &b->rx_bytes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tx_bytes, &b->tx_bytes);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->interface_name[i], &b->interface_name[i]);
  }
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_network_usage_t(const sbp_network_usage_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u64(&msg->duration);
  packed_size += sbp_packed_size_u64(&msg->total_bytes);
  packed_size += sbp_packed_size_u32(&msg->rx_bytes);
  packed_size += sbp_packed_size_u32(&msg->tx_bytes);
  packed_size += ( 16 * sbp_packed_size_char(&msg->interface_name[0]));
  return packed_size;
}

bool pack_sbp_network_usage_t(sbp_pack_ctx_t *ctx, const sbp_network_usage_t *msg)
{
  if (!sbp_pack_u64(ctx, &msg->duration)) { return false; }
  if (!sbp_pack_u64(ctx, &msg->total_bytes)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->rx_bytes)) { return false; }
  if (!sbp_pack_u32(ctx, &msg->tx_bytes)) { return false; }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (!sbp_pack_char(ctx, &msg->interface_name[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_network_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_network_usage_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_network_usage_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_network_usage_t(sbp_unpack_ctx_t *ctx, sbp_network_usage_t *msg)
{
  if (!sbp_unpack_u64(ctx, &msg->duration)) { return false; }
  if (!sbp_unpack_u64(ctx, &msg->total_bytes)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->rx_bytes)) { return false; }
  if (!sbp_unpack_u32(ctx, &msg->tx_bytes)) { return false; }
  for (uint8_t i = 0; i < 16; i++) {
    if (!sbp_unpack_char(ctx, &msg->interface_name[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_network_usage_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_network_usage_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_network_usage_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_network_usage_t(const sbp_network_usage_t *a, const sbp_network_usage_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->duration, &b->duration);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u64(&a->total_bytes, &b->total_bytes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->rx_bytes, &b->rx_bytes);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tx_bytes, &b->tx_bytes);
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 16 && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->interface_name[i], &b->interface_name[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *msg) {
  size_t packed_size = 0;
  packed_size += (msg->n_interfaces * sbp_packed_size_sbp_network_usage_t(&msg->interfaces[0]));
  return packed_size;
}

bool pack_sbp_msg_network_bandwidth_usage_t(sbp_pack_ctx_t *ctx, const sbp_msg_network_bandwidth_usage_t *msg)
{
  for (uint8_t i = 0; i < msg->n_interfaces; i++)
  {
    if (!sbp_pack_sbp_network_usage_t(ctx, &msg->interfaces[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_network_bandwidth_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_network_bandwidth_usage_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_network_bandwidth_usage_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_network_bandwidth_usage_t(sbp_unpack_ctx_t *ctx, sbp_msg_network_bandwidth_usage_t *msg)
{
    msg->n_interfaces = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_sbp_network_usage_t(&msg->interfaces[0]));
  for (uint8_t i = 0; i < msg->n_interfaces; i++) {
    if (!sbp_unpack_sbp_network_usage_t(ctx, &msg->interfaces[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_network_bandwidth_usage_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_network_bandwidth_usage_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_network_bandwidth_usage_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *a, const sbp_msg_network_bandwidth_usage_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_interfaces, &b->n_interfaces);
  for (uint8_t i = 0; i < a->n_interfaces && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_network_usage_t(&a->interfaces[i], &b->interfaces[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_s8(&msg->signal_strength);
  packed_size += sbp_packed_size_float(&msg->signal_error_rate);
  packed_size += (msg->n_reserved * sbp_packed_size_u8(&msg->reserved[0]));
  return packed_size;
}

bool pack_sbp_msg_cell_modem_status_t(sbp_pack_ctx_t *ctx, const sbp_msg_cell_modem_status_t *msg)
{
  if (!sbp_pack_s8(ctx, &msg->signal_strength)) { return false; }
  if (!sbp_pack_float(ctx, &msg->signal_error_rate)) { return false; }
  for (uint8_t i = 0; i < msg->n_reserved; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->reserved[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_cell_modem_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_cell_modem_status_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_cell_modem_status_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_cell_modem_status_t(sbp_unpack_ctx_t *ctx, sbp_msg_cell_modem_status_t *msg)
{
  if (!sbp_unpack_s8(ctx, &msg->signal_strength)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->signal_error_rate)) { return false; }
    msg->n_reserved = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->reserved[0]));
  for (uint8_t i = 0; i < msg->n_reserved; i++) {
    if (!sbp_unpack_u8(ctx, &msg->reserved[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_cell_modem_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_cell_modem_status_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_cell_modem_status_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *a, const sbp_msg_cell_modem_status_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_s8(&a->signal_strength, &b->signal_strength);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->signal_error_rate, &b->signal_error_rate);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_reserved, &b->n_reserved);
  for (uint8_t i = 0; i < a->n_reserved && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->reserved[i], &b->reserved[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->channel_tag);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t);
  packed_size += sbp_packed_size_float(&msg->freq_ref);
  packed_size += sbp_packed_size_float(&msg->freq_step);
  packed_size += sbp_packed_size_float(&msg->amplitude_ref);
  packed_size += sbp_packed_size_float(&msg->amplitude_unit);
  packed_size += (msg->n_amplitude_value * sbp_packed_size_u8(&msg->amplitude_value[0]));
  return packed_size;
}

bool pack_sbp_msg_specan_dep_t(sbp_pack_ctx_t *ctx, const sbp_msg_specan_dep_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->channel_tag)) { return false; }
  if (!sbp_pack_sbp_gps_time_dep_t(ctx, &msg->t)) { return false; }
  if (!sbp_pack_float(ctx, &msg->freq_ref)) { return false; }
  if (!sbp_pack_float(ctx, &msg->freq_step)) { return false; }
  if (!sbp_pack_float(ctx, &msg->amplitude_ref)) { return false; }
  if (!sbp_pack_float(ctx, &msg->amplitude_unit)) { return false; }
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->amplitude_value[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_specan_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_specan_dep_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_specan_dep_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_specan_dep_t(sbp_unpack_ctx_t *ctx, sbp_msg_specan_dep_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->channel_tag)) { return false; }
  if (!sbp_unpack_sbp_gps_time_dep_t(ctx, &msg->t)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->freq_ref)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->freq_step)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->amplitude_ref)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->amplitude_unit)) { return false; }
    msg->n_amplitude_value = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->amplitude_value[0]));
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++) {
    if (!sbp_unpack_u8(ctx, &msg->amplitude_value[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_specan_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_specan_dep_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_specan_dep_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *a, const sbp_msg_specan_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->channel_tag, &b->channel_tag);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gps_time_dep_t(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->freq_ref, &b->freq_ref);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->freq_step, &b->freq_step);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->amplitude_ref, &b->amplitude_ref);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->amplitude_unit, &b->amplitude_unit);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_amplitude_value, &b->n_amplitude_value);
  for (uint8_t i = 0; i < a->n_amplitude_value && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->amplitude_value[i], &b->amplitude_value[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg) {
  size_t packed_size = 0;
  packed_size += sbp_packed_size_u16(&msg->channel_tag);
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->t);
  packed_size += sbp_packed_size_float(&msg->freq_ref);
  packed_size += sbp_packed_size_float(&msg->freq_step);
  packed_size += sbp_packed_size_float(&msg->amplitude_ref);
  packed_size += sbp_packed_size_float(&msg->amplitude_unit);
  packed_size += (msg->n_amplitude_value * sbp_packed_size_u8(&msg->amplitude_value[0]));
  return packed_size;
}

bool pack_sbp_msg_specan_t(sbp_pack_ctx_t *ctx, const sbp_msg_specan_t *msg)
{
  if (!sbp_pack_u16(ctx, &msg->channel_tag)) { return false; }
  if (!sbp_pack_sbp_sbp_gps_time_t(ctx, &msg->t)) { return false; }
  if (!sbp_pack_float(ctx, &msg->freq_ref)) { return false; }
  if (!sbp_pack_float(ctx, &msg->freq_step)) { return false; }
  if (!sbp_pack_float(ctx, &msg->amplitude_ref)) { return false; }
  if (!sbp_pack_float(ctx, &msg->amplitude_unit)) { return false; }
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++)
  {
    if (!sbp_pack_u8(ctx, &msg->amplitude_value[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_specan_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_specan_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_specan_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_specan_t(sbp_unpack_ctx_t *ctx, sbp_msg_specan_t *msg)
{
  if (!sbp_unpack_u16(ctx, &msg->channel_tag)) { return false; }
  if (!sbp_unpack_sbp_sbp_gps_time_t(ctx, &msg->t)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->freq_ref)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->freq_step)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->amplitude_ref)) { return false; }
  if (!sbp_unpack_float(ctx, &msg->amplitude_unit)) { return false; }
    msg->n_amplitude_value = (uint8_t)((ctx->buf_len - ctx->offset) / sbp_packed_size_u8(&msg->amplitude_value[0]));
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++) {
    if (!sbp_unpack_u8(ctx, &msg->amplitude_value[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_specan_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_specan_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_specan_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_specan_t(const sbp_msg_specan_t *a, const sbp_msg_specan_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->channel_tag, &b->channel_tag);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gps_time_t(&a->t, &b->t);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->freq_ref, &b->freq_ref);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->freq_step, &b->freq_step);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->amplitude_ref, &b->amplitude_ref);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_float(&a->amplitude_unit, &b->amplitude_unit);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_amplitude_value, &b->n_amplitude_value);
  for (uint8_t i = 0; i < a->n_amplitude_value && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->amplitude_value[i], &b->amplitude_value[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
                                                                                                              
size_t sbp_packed_size_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *msg) {
  size_t packed_size = 0;
  packed_size += ( 8 * sbp_packed_size_s8(&msg->rf_gain[0]));
  packed_size += ( 8 * sbp_packed_size_s8(&msg->if_gain[0]));
  return packed_size;
}

bool pack_sbp_msg_front_end_gain_t(sbp_pack_ctx_t *ctx, const sbp_msg_front_end_gain_t *msg)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (!sbp_pack_s8(ctx, &msg->rf_gain[i])) { return false; }
  }
  for (uint8_t i = 0; i < 8; i++)
  {
    if (!sbp_pack_s8(ctx, &msg->if_gain[i])) { return false; }
  }
  return true;
}

s8 sbp_pack_sbp_msg_front_end_gain_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_front_end_gain_t *msg) {
  sbp_pack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!pack_sbp_msg_front_end_gain_t(&ctx, msg)) {
    return SBP_WRITE_ERROR;
  }
  if (n_written != NULL) {
    *n_written = ctx.offset;
  }
  return SBP_OK;
}

bool unpack_sbp_msg_front_end_gain_t(sbp_unpack_ctx_t *ctx, sbp_msg_front_end_gain_t *msg)
{
  for (uint8_t i = 0; i < 8; i++) {
    if (!sbp_unpack_s8(ctx, &msg->rf_gain[i])) { return false; }
  }
  for (uint8_t i = 0; i < 8; i++) {
    if (!sbp_unpack_s8(ctx, &msg->if_gain[i])) { return false; }
  }
  return true;
}

s8 sbp_unpack_sbp_msg_front_end_gain_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_front_end_gain_t *msg) {
  sbp_unpack_ctx_t ctx;
  ctx.buf = buf;
  ctx.buf_len = len;
  ctx.offset = 0;
  if (!unpack_sbp_msg_front_end_gain_t(&ctx, msg)) {
    return SBP_READ_ERROR;
  }
  if (n_read != NULL) {
    *n_read = ctx.offset;
  }
  return SBP_OK;
}

int sbp_cmp_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *a, const sbp_msg_front_end_gain_t *b) {
  int ret = 0;
  
  for (uint8_t i = 0; i < 8 && ret == 0; i++)
  {
    ret = sbp_cmp_s8(&a->rf_gain[i], &b->rf_gain[i]);
  }
  if (ret != 0) { return ret; }
  
  for (uint8_t i = 0; i < 8 && ret == 0; i++)
  {
    ret = sbp_cmp_s8(&a->if_gain[i], &b->if_gain[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}
