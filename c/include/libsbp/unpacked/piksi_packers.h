#ifndef LIBSBP_PIKSI_PACKERS_H
#define LIBSBP_PIKSI_PACKERS_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/gnss.h>
#include <libsbp/unpacked/piksi.h>

static inline size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_almanac_t(u8 *buf, size_t len, const sbp_msg_almanac_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_t(const u8 *buf, size_t len, sbp_msg_almanac_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_set_time_t(u8 *buf, size_t len, const sbp_msg_set_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_set_time_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_set_time_t(const u8 *buf, size_t len, sbp_msg_set_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_reset_t(u8 *buf, size_t len, const sbp_msg_reset_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_reset_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_t(const u8 *buf, size_t len, sbp_msg_reset_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_reset_dep_t(u8 *buf, size_t len, const sbp_msg_reset_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_reset_dep_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_dep_t(const u8 *buf, size_t len, sbp_msg_reset_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_cw_results_t(u8 *buf, size_t len, const sbp_msg_cw_results_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_cw_results_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_results_t(const u8 *buf, size_t len, sbp_msg_cw_results_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_cw_start_t(u8 *buf, size_t len, const sbp_msg_cw_start_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_cw_start_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_start_t(const u8 *buf, size_t len, sbp_msg_cw_start_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->filter);
}

static inline bool sbp_pack_sbp_msg_reset_filters_t(u8 *buf, size_t len, const sbp_msg_reset_filters_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_reset_filters_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgfilter = msg->filter;
  memcpy(buf + offset, &msgfilter, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_filters_t(const u8 *buf, size_t len, sbp_msg_reset_filters_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->filter, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_init_base_dep_t(u8 *buf, size_t len, const sbp_msg_init_base_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_init_base_dep_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_init_base_dep_t(const u8 *buf, size_t len, sbp_msg_init_base_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *msg)
{
  (void)msg;
  return 0 + (20 * sizeof(msg->name[0])) + sizeof(msg->cpu) + sizeof(msg->stack_free);
}

static inline bool sbp_pack_sbp_msg_thread_state_t(u8 *buf, size_t len, const sbp_msg_thread_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_thread_state_t(msg) > len)
  {
    return false;
  }

  for (size_t msgname_idx = 0; msgname_idx < 20; msgname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msgnamemsgname_idx = msg->name[msgname_idx];
    memcpy(buf + offset, &msgnamemsgname_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcpu = htole16(msg->cpu);
  memcpy(buf + offset, &msgcpu, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgstack_free = htole32(msg->stack_free);
  memcpy(buf + offset, &msgstack_free, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_thread_state_t(const u8 *buf, size_t len, sbp_msg_thread_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgname_idx = 0; msgname_idx < 20; msgname_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->name[msgname_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->cpu, buf + offset, 2);
  msg->cpu = le16toh(msg->cpu);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->stack_free, buf + offset, 4);
  msg->stack_free = le32toh(msg->stack_free);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_uart_channel_t(const sbp_uart_channel_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tx_throughput) + sizeof(msg->rx_throughput) + sizeof(msg->crc_error_count) +
         sizeof(msg->io_error_count) + sizeof(msg->tx_buffer_level) + sizeof(msg->rx_buffer_level);
}

static inline bool sbp_pack_sbp_uart_channel_t(u8 *buf, size_t len, const sbp_uart_channel_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_uart_channel_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  float msgtx_throughput = msg->tx_throughput;
  memcpy(buf + offset, &msgtx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgrx_throughput = msg->rx_throughput;
  memcpy(buf + offset, &msgrx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcrc_error_count = htole16(msg->crc_error_count);
  memcpy(buf + offset, &msgcrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgio_error_count = htole16(msg->io_error_count);
  memcpy(buf + offset, &msgio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgtx_buffer_level = msg->tx_buffer_level;
  memcpy(buf + offset, &msgtx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgrx_buffer_level = msg->rx_buffer_level;
  memcpy(buf + offset, &msgrx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_uart_channel_t(const u8 *buf, size_t len, sbp_uart_channel_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->crc_error_count, buf + offset, 2);
  msg->crc_error_count = le16toh(msg->crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->io_error_count, buf + offset, 2);
  msg->io_error_count = le16toh(msg->io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_period_t(const sbp_period_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->avg) + sizeof(msg->pmin) + sizeof(msg->pmax) + sizeof(msg->current);
}

static inline bool sbp_pack_sbp_period_t(u8 *buf, size_t len, const sbp_period_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_period_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgavg = htole32(*(const u32 *)&msg->avg);
  memcpy(buf + offset, &msgavg, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgpmin = htole32(*(const u32 *)&msg->pmin);
  memcpy(buf + offset, &msgpmin, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgpmax = htole32(*(const u32 *)&msg->pmax);
  memcpy(buf + offset, &msgpmax, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcurrent = htole32(*(const u32 *)&msg->current);
  memcpy(buf + offset, &msgcurrent, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_period_t(const u8 *buf, size_t len, sbp_period_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->avg, buf + offset, 4);
  u32 msgavg = *(const u32 *)&msg->avg;
  msgavg = le32toh(msgavg);
  msg->avg = *(const s32 *)&msgavg;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->pmin, buf + offset, 4);
  u32 msgpmin = *(const u32 *)&msg->pmin;
  msgpmin = le32toh(msgpmin);
  msg->pmin = *(const s32 *)&msgpmin;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->pmax, buf + offset, 4);
  u32 msgpmax = *(const u32 *)&msg->pmax;
  msgpmax = le32toh(msgpmax);
  msg->pmax = *(const s32 *)&msgpmax;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->current, buf + offset, 4);
  u32 msgcurrent = *(const u32 *)&msg->current;
  msgcurrent = le32toh(msgcurrent);
  msg->current = *(const s32 *)&msgcurrent;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_latency_t(const sbp_latency_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->avg) + sizeof(msg->lmin) + sizeof(msg->lmax) + sizeof(msg->current);
}

static inline bool sbp_pack_sbp_latency_t(u8 *buf, size_t len, const sbp_latency_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_latency_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgavg = htole32(*(const u32 *)&msg->avg);
  memcpy(buf + offset, &msgavg, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglmin = htole32(*(const u32 *)&msg->lmin);
  memcpy(buf + offset, &msglmin, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglmax = htole32(*(const u32 *)&msg->lmax);
  memcpy(buf + offset, &msglmax, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcurrent = htole32(*(const u32 *)&msg->current);
  memcpy(buf + offset, &msgcurrent, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_latency_t(const u8 *buf, size_t len, sbp_latency_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->avg, buf + offset, 4);
  u32 msgavg = *(const u32 *)&msg->avg;
  msgavg = le32toh(msgavg);
  msg->avg = *(const s32 *)&msgavg;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->lmin, buf + offset, 4);
  u32 msglmin = *(const u32 *)&msg->lmin;
  msglmin = le32toh(msglmin);
  msg->lmin = *(const s32 *)&msglmin;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->lmax, buf + offset, 4);
  u32 msglmax = *(const u32 *)&msg->lmax;
  msglmax = le32toh(msglmax);
  msg->lmax = *(const s32 *)&msglmax;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->current, buf + offset, 4);
  u32 msgcurrent = *(const u32 *)&msg->current;
  msgcurrent = le32toh(msgcurrent);
  msg->current = *(const s32 *)&msgcurrent;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg)
{
  (void)msg;
  return 0 +
         (0 + sizeof(msg->uart_a.tx_throughput) + sizeof(msg->uart_a.rx_throughput) +
          sizeof(msg->uart_a.crc_error_count) + sizeof(msg->uart_a.io_error_count) +
          sizeof(msg->uart_a.tx_buffer_level) + sizeof(msg->uart_a.rx_buffer_level)) +
         (0 + sizeof(msg->uart_b.tx_throughput) + sizeof(msg->uart_b.rx_throughput) +
          sizeof(msg->uart_b.crc_error_count) + sizeof(msg->uart_b.io_error_count) +
          sizeof(msg->uart_b.tx_buffer_level) + sizeof(msg->uart_b.rx_buffer_level)) +
         (0 + sizeof(msg->uart_ftdi.tx_throughput) + sizeof(msg->uart_ftdi.rx_throughput) +
          sizeof(msg->uart_ftdi.crc_error_count) + sizeof(msg->uart_ftdi.io_error_count) +
          sizeof(msg->uart_ftdi.tx_buffer_level) + sizeof(msg->uart_ftdi.rx_buffer_level)) +
         (0 + sizeof(msg->latency.avg) + sizeof(msg->latency.lmin) + sizeof(msg->latency.lmax) +
          sizeof(msg->latency.current)) +
         (0 + sizeof(msg->obs_period.avg) + sizeof(msg->obs_period.pmin) + sizeof(msg->obs_period.pmax) +
          sizeof(msg->obs_period.current));
}

static inline bool sbp_pack_sbp_msg_uart_state_t(u8 *buf, size_t len, const sbp_msg_uart_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_uart_state_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_atx_throughput = msg->uart_a.tx_throughput;
  memcpy(buf + offset, &msguart_atx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_arx_throughput = msg->uart_a.rx_throughput;
  memcpy(buf + offset, &msguart_arx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_acrc_error_count = htole16(msg->uart_a.crc_error_count);
  memcpy(buf + offset, &msguart_acrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_aio_error_count = htole16(msg->uart_a.io_error_count);
  memcpy(buf + offset, &msguart_aio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_atx_buffer_level = msg->uart_a.tx_buffer_level;
  memcpy(buf + offset, &msguart_atx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_arx_buffer_level = msg->uart_a.rx_buffer_level;
  memcpy(buf + offset, &msguart_arx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_btx_throughput = msg->uart_b.tx_throughput;
  memcpy(buf + offset, &msguart_btx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_brx_throughput = msg->uart_b.rx_throughput;
  memcpy(buf + offset, &msguart_brx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_bcrc_error_count = htole16(msg->uart_b.crc_error_count);
  memcpy(buf + offset, &msguart_bcrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_bio_error_count = htole16(msg->uart_b.io_error_count);
  memcpy(buf + offset, &msguart_bio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_btx_buffer_level = msg->uart_b.tx_buffer_level;
  memcpy(buf + offset, &msguart_btx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_brx_buffer_level = msg->uart_b.rx_buffer_level;
  memcpy(buf + offset, &msguart_brx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_ftditx_throughput = msg->uart_ftdi.tx_throughput;
  memcpy(buf + offset, &msguart_ftditx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_ftdirx_throughput = msg->uart_ftdi.rx_throughput;
  memcpy(buf + offset, &msguart_ftdirx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_ftdicrc_error_count = htole16(msg->uart_ftdi.crc_error_count);
  memcpy(buf + offset, &msguart_ftdicrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_ftdiio_error_count = htole16(msg->uart_ftdi.io_error_count);
  memcpy(buf + offset, &msguart_ftdiio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_ftditx_buffer_level = msg->uart_ftdi.tx_buffer_level;
  memcpy(buf + offset, &msguart_ftditx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_ftdirx_buffer_level = msg->uart_ftdi.rx_buffer_level;
  memcpy(buf + offset, &msguart_ftdirx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencyavg = htole32(*(const u32 *)&msg->latency.avg);
  memcpy(buf + offset, &msglatencyavg, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencylmin = htole32(*(const u32 *)&msg->latency.lmin);
  memcpy(buf + offset, &msglatencylmin, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencylmax = htole32(*(const u32 *)&msg->latency.lmax);
  memcpy(buf + offset, &msglatencylmax, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencycurrent = htole32(*(const u32 *)&msg->latency.current);
  memcpy(buf + offset, &msglatencycurrent, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgobs_periodavg = htole32(*(const u32 *)&msg->obs_period.avg);
  memcpy(buf + offset, &msgobs_periodavg, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgobs_periodpmin = htole32(*(const u32 *)&msg->obs_period.pmin);
  memcpy(buf + offset, &msgobs_periodpmin, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgobs_periodpmax = htole32(*(const u32 *)&msg->obs_period.pmax);
  memcpy(buf + offset, &msgobs_periodpmax, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgobs_periodcurrent = htole32(*(const u32 *)&msg->obs_period.current);
  memcpy(buf + offset, &msgobs_periodcurrent, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_t(const u8 *buf, size_t len, sbp_msg_uart_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.crc_error_count, buf + offset, 2);
  msg->uart_a.crc_error_count = le16toh(msg->uart_a.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.io_error_count, buf + offset, 2);
  msg->uart_a.io_error_count = le16toh(msg->uart_a.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.crc_error_count, buf + offset, 2);
  msg->uart_b.crc_error_count = le16toh(msg->uart_b.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.io_error_count, buf + offset, 2);
  msg->uart_b.io_error_count = le16toh(msg->uart_b.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.crc_error_count, buf + offset, 2);
  msg->uart_ftdi.crc_error_count = le16toh(msg->uart_ftdi.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.io_error_count, buf + offset, 2);
  msg->uart_ftdi.io_error_count = le16toh(msg->uart_ftdi.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.avg, buf + offset, 4);
  u32 msglatencyavg = *(const u32 *)&msg->latency.avg;
  msglatencyavg = le32toh(msglatencyavg);
  msg->latency.avg = *(const s32 *)&msglatencyavg;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.lmin, buf + offset, 4);
  u32 msglatencylmin = *(const u32 *)&msg->latency.lmin;
  msglatencylmin = le32toh(msglatencylmin);
  msg->latency.lmin = *(const s32 *)&msglatencylmin;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.lmax, buf + offset, 4);
  u32 msglatencylmax = *(const u32 *)&msg->latency.lmax;
  msglatencylmax = le32toh(msglatencylmax);
  msg->latency.lmax = *(const s32 *)&msglatencylmax;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.current, buf + offset, 4);
  u32 msglatencycurrent = *(const u32 *)&msg->latency.current;
  msglatencycurrent = le32toh(msglatencycurrent);
  msg->latency.current = *(const s32 *)&msglatencycurrent;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->obs_period.avg, buf + offset, 4);
  u32 msgobs_periodavg = *(const u32 *)&msg->obs_period.avg;
  msgobs_periodavg = le32toh(msgobs_periodavg);
  msg->obs_period.avg = *(const s32 *)&msgobs_periodavg;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->obs_period.pmin, buf + offset, 4);
  u32 msgobs_periodpmin = *(const u32 *)&msg->obs_period.pmin;
  msgobs_periodpmin = le32toh(msgobs_periodpmin);
  msg->obs_period.pmin = *(const s32 *)&msgobs_periodpmin;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->obs_period.pmax, buf + offset, 4);
  u32 msgobs_periodpmax = *(const u32 *)&msg->obs_period.pmax;
  msgobs_periodpmax = le32toh(msgobs_periodpmax);
  msg->obs_period.pmax = *(const s32 *)&msgobs_periodpmax;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->obs_period.current, buf + offset, 4);
  u32 msgobs_periodcurrent = *(const u32 *)&msg->obs_period.current;
  msgobs_periodcurrent = le32toh(msgobs_periodcurrent);
  msg->obs_period.current = *(const s32 *)&msgobs_periodcurrent;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *msg)
{
  (void)msg;
  return 0 +
         (0 + sizeof(msg->uart_a.tx_throughput) + sizeof(msg->uart_a.rx_throughput) +
          sizeof(msg->uart_a.crc_error_count) + sizeof(msg->uart_a.io_error_count) +
          sizeof(msg->uart_a.tx_buffer_level) + sizeof(msg->uart_a.rx_buffer_level)) +
         (0 + sizeof(msg->uart_b.tx_throughput) + sizeof(msg->uart_b.rx_throughput) +
          sizeof(msg->uart_b.crc_error_count) + sizeof(msg->uart_b.io_error_count) +
          sizeof(msg->uart_b.tx_buffer_level) + sizeof(msg->uart_b.rx_buffer_level)) +
         (0 + sizeof(msg->uart_ftdi.tx_throughput) + sizeof(msg->uart_ftdi.rx_throughput) +
          sizeof(msg->uart_ftdi.crc_error_count) + sizeof(msg->uart_ftdi.io_error_count) +
          sizeof(msg->uart_ftdi.tx_buffer_level) + sizeof(msg->uart_ftdi.rx_buffer_level)) +
         (0 + sizeof(msg->latency.avg) + sizeof(msg->latency.lmin) + sizeof(msg->latency.lmax) +
          sizeof(msg->latency.current));
}

static inline bool sbp_pack_sbp_msg_uart_state_depa_t(u8 *buf, size_t len, const sbp_msg_uart_state_depa_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_uart_state_depa_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_atx_throughput = msg->uart_a.tx_throughput;
  memcpy(buf + offset, &msguart_atx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_arx_throughput = msg->uart_a.rx_throughput;
  memcpy(buf + offset, &msguart_arx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_acrc_error_count = htole16(msg->uart_a.crc_error_count);
  memcpy(buf + offset, &msguart_acrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_aio_error_count = htole16(msg->uart_a.io_error_count);
  memcpy(buf + offset, &msguart_aio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_atx_buffer_level = msg->uart_a.tx_buffer_level;
  memcpy(buf + offset, &msguart_atx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_arx_buffer_level = msg->uart_a.rx_buffer_level;
  memcpy(buf + offset, &msguart_arx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_btx_throughput = msg->uart_b.tx_throughput;
  memcpy(buf + offset, &msguart_btx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_brx_throughput = msg->uart_b.rx_throughput;
  memcpy(buf + offset, &msguart_brx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_bcrc_error_count = htole16(msg->uart_b.crc_error_count);
  memcpy(buf + offset, &msguart_bcrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_bio_error_count = htole16(msg->uart_b.io_error_count);
  memcpy(buf + offset, &msguart_bio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_btx_buffer_level = msg->uart_b.tx_buffer_level;
  memcpy(buf + offset, &msguart_btx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_brx_buffer_level = msg->uart_b.rx_buffer_level;
  memcpy(buf + offset, &msguart_brx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_ftditx_throughput = msg->uart_ftdi.tx_throughput;
  memcpy(buf + offset, &msguart_ftditx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msguart_ftdirx_throughput = msg->uart_ftdi.rx_throughput;
  memcpy(buf + offset, &msguart_ftdirx_throughput, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_ftdicrc_error_count = htole16(msg->uart_ftdi.crc_error_count);
  memcpy(buf + offset, &msguart_ftdicrc_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msguart_ftdiio_error_count = htole16(msg->uart_ftdi.io_error_count);
  memcpy(buf + offset, &msguart_ftdiio_error_count, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_ftditx_buffer_level = msg->uart_ftdi.tx_buffer_level;
  memcpy(buf + offset, &msguart_ftditx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msguart_ftdirx_buffer_level = msg->uart_ftdi.rx_buffer_level;
  memcpy(buf + offset, &msguart_ftdirx_buffer_level, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencyavg = htole32(*(const u32 *)&msg->latency.avg);
  memcpy(buf + offset, &msglatencyavg, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencylmin = htole32(*(const u32 *)&msg->latency.lmin);
  memcpy(buf + offset, &msglatencylmin, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencylmax = htole32(*(const u32 *)&msg->latency.lmax);
  memcpy(buf + offset, &msglatencylmax, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msglatencycurrent = htole32(*(const u32 *)&msg->latency.current);
  memcpy(buf + offset, &msglatencycurrent, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_depa_t(const u8 *buf, size_t len, sbp_msg_uart_state_depa_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.crc_error_count, buf + offset, 2);
  msg->uart_a.crc_error_count = le16toh(msg->uart_a.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.io_error_count, buf + offset, 2);
  msg->uart_a.io_error_count = le16toh(msg->uart_a.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_a.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.crc_error_count, buf + offset, 2);
  msg->uart_b.crc_error_count = le16toh(msg->uart_b.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.io_error_count, buf + offset, 2);
  msg->uart_b.io_error_count = le16toh(msg->uart_b.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_b.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.tx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.rx_throughput, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.crc_error_count, buf + offset, 2);
  msg->uart_ftdi.crc_error_count = le16toh(msg->uart_ftdi.crc_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.io_error_count, buf + offset, 2);
  msg->uart_ftdi.io_error_count = le16toh(msg->uart_ftdi.io_error_count);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.tx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->uart_ftdi.rx_buffer_level, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.avg, buf + offset, 4);
  u32 msglatencyavg = *(const u32 *)&msg->latency.avg;
  msglatencyavg = le32toh(msglatencyavg);
  msg->latency.avg = *(const s32 *)&msglatencyavg;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.lmin, buf + offset, 4);
  u32 msglatencylmin = *(const u32 *)&msg->latency.lmin;
  msglatencylmin = le32toh(msglatencylmin);
  msg->latency.lmin = *(const s32 *)&msglatencylmin;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.lmax, buf + offset, 4);
  u32 msglatencylmax = *(const u32 *)&msg->latency.lmax;
  msglatencylmax = le32toh(msglatencylmax);
  msg->latency.lmax = *(const s32 *)&msglatencylmax;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->latency.current, buf + offset, 4);
  u32 msglatencycurrent = *(const u32 *)&msg->latency.current;
  msglatencycurrent = le32toh(msglatencycurrent);
  msg->latency.current = *(const s32 *)&msglatencycurrent;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->num_hyps);
}

static inline bool sbp_pack_sbp_msg_iar_state_t(u8 *buf, size_t len, const sbp_msg_iar_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_iar_state_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgnum_hyps = htole32(msg->num_hyps);
  memcpy(buf + offset, &msgnum_hyps, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_iar_state_t(const u8 *buf, size_t len, sbp_msg_iar_state_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->num_hyps, buf + offset, 4);
  msg->num_hyps = le32toh(msg->num_hyps);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->mask) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code));
}

static inline bool sbp_pack_sbp_msg_mask_satellite_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_mask_satellite_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmask = msg->mask;
  memcpy(buf + offset, &msgmask, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_t(const u8 *buf, size_t len, sbp_msg_mask_satellite_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->mask, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->mask) + (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) + sizeof(msg->sid.reserved));
}

static inline bool sbp_pack_sbp_msg_mask_satellite_dep_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_mask_satellite_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmask = msg->mask;
  memcpy(buf + offset, &msgmask, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsidsat = htole16(msg->sid.sat);
  memcpy(buf + offset, &msgsidsat, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_dep_t(const u8 *buf, size_t len, sbp_msg_mask_satellite_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->mask, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->dev_vin) + sizeof(msg->cpu_vint) + sizeof(msg->cpu_vaux) + sizeof(msg->cpu_temperature) +
         sizeof(msg->fe_temperature);
}

static inline bool sbp_pack_sbp_msg_device_monitor_t(u8 *buf, size_t len, const sbp_msg_device_monitor_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_device_monitor_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgdev_vin = htole16(*(const u16 *)&msg->dev_vin);
  memcpy(buf + offset, &msgdev_vin, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcpu_vint = htole16(*(const u16 *)&msg->cpu_vint);
  memcpy(buf + offset, &msgcpu_vint, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcpu_vaux = htole16(*(const u16 *)&msg->cpu_vaux);
  memcpy(buf + offset, &msgcpu_vaux, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgcpu_temperature = htole16(*(const u16 *)&msg->cpu_temperature);
  memcpy(buf + offset, &msgcpu_temperature, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgfe_temperature = htole16(*(const u16 *)&msg->fe_temperature);
  memcpy(buf + offset, &msgfe_temperature, 2);
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_device_monitor_t(const u8 *buf, size_t len, sbp_msg_device_monitor_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->dev_vin, buf + offset, 2);
  u16 msgdev_vin = *(const u16 *)&msg->dev_vin;
  msgdev_vin = le16toh(msgdev_vin);
  msg->dev_vin = *(const s16 *)&msgdev_vin;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->cpu_vint, buf + offset, 2);
  u16 msgcpu_vint = *(const u16 *)&msg->cpu_vint;
  msgcpu_vint = le16toh(msgcpu_vint);
  msg->cpu_vint = *(const s16 *)&msgcpu_vint;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->cpu_vaux, buf + offset, 2);
  u16 msgcpu_vaux = *(const u16 *)&msg->cpu_vaux;
  msgcpu_vaux = le16toh(msgcpu_vaux);
  msg->cpu_vaux = *(const s16 *)&msgcpu_vaux;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->cpu_temperature, buf + offset, 2);
  u16 msgcpu_temperature = *(const u16 *)&msg->cpu_temperature;
  msgcpu_temperature = le16toh(msgcpu_temperature);
  msg->cpu_temperature = *(const s16 *)&msgcpu_temperature;
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->fe_temperature, buf + offset, 2);
  u16 msgfe_temperature = *(const u16 *)&msg->fe_temperature;
  msgfe_temperature = le16toh(msgfe_temperature);
  msg->fe_temperature = *(const s16 *)&msgfe_temperature;
  // NOLINTNEXTLINE
  offset += 2;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sbp_strlen(msg->command, "nul");
}

static inline bool sbp_pack_sbp_msg_command_req_t(u8 *buf, size_t len, const sbp_msg_command_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_command_req_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;
  if (offset + sbp_strlen(msg->command, "nul") > len)
  {
    return false;
  }
  // NOLINTNEXTLINE
  offset += sbp_pack_string(buf + offset, msg->command, "nul");
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_req_t(const u8 *buf, size_t len, sbp_msg_command_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  // NOLINTNEXTLINE
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->command, "nul");
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sizeof(msg->code);
}

static inline bool sbp_pack_sbp_msg_command_resp_t(u8 *buf, size_t len, const sbp_msg_command_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_command_resp_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgcode = htole32(*(const u32 *)&msg->code);
  memcpy(buf + offset, &msgcode, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_resp_t(const u8 *buf, size_t len, sbp_msg_command_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->code, buf + offset, 4);
  u32 msgcode = *(const u32 *)&msg->code;
  msgcode = le32toh(msgcode);
  msg->code = *(const s32 *)&msgcode;
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_command_output_t(const sbp_msg_command_output_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->sequence) + sbp_strlen(msg->line, "none");
}

static inline bool sbp_pack_sbp_msg_command_output_t(u8 *buf, size_t len, const sbp_msg_command_output_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_command_output_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  // NOLINTNEXTLINE
  offset += 4;
  if (offset + sbp_strlen(msg->line, "none") > len)
  {
    return false;
  }
  // NOLINTNEXTLINE
  offset += sbp_pack_string(buf + offset, msg->line, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_output_t(const u8 *buf, size_t len, sbp_msg_command_output_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  // NOLINTNEXTLINE
  offset += 4;
  // NOLINTNEXTLINE
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->line, "none");
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *msg)
{
  (void)msg;
  return 0;
}

static inline bool sbp_pack_sbp_msg_network_state_req_t(u8 *buf, size_t len, const sbp_msg_network_state_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_network_state_req_t(msg) > len)
  {
    return false;
  }

  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_req_t(const u8 *buf, size_t len, sbp_msg_network_state_req_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  return true;
}

static inline size_t sbp_packed_size_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *msg)
{
  (void)msg;
  return 0 + (4 * sizeof(msg->ipv4_address[0])) + sizeof(msg->ipv4_mask_size) + (16 * sizeof(msg->ipv6_address[0])) +
         sizeof(msg->ipv6_mask_size) + sizeof(msg->rx_bytes) + sizeof(msg->tx_bytes) +
         (16 * sizeof(msg->interface_name[0])) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_network_state_resp_t(u8 *buf, size_t len, const sbp_msg_network_state_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_network_state_resp_t(msg) > len)
  {
    return false;
  }

  for (size_t msgipv4_address_idx = 0; msgipv4_address_idx < 4; msgipv4_address_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgipv4_addressmsgipv4_address_idx = msg->ipv4_address[msgipv4_address_idx];
    memcpy(buf + offset, &msgipv4_addressmsgipv4_address_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgipv4_mask_size = msg->ipv4_mask_size;
  memcpy(buf + offset, &msgipv4_mask_size, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgipv6_address_idx = 0; msgipv6_address_idx < 16; msgipv6_address_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgipv6_addressmsgipv6_address_idx = msg->ipv6_address[msgipv6_address_idx];
    memcpy(buf + offset, &msgipv6_addressmsgipv6_address_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgipv6_mask_size = msg->ipv6_mask_size;
  memcpy(buf + offset, &msgipv6_mask_size, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgrx_bytes = htole32(msg->rx_bytes);
  memcpy(buf + offset, &msgrx_bytes, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtx_bytes = htole32(msg->tx_bytes);
  memcpy(buf + offset, &msgtx_bytes, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msginterface_namemsginterface_name_idx = msg->interface_name[msginterface_name_idx];
    memcpy(buf + offset, &msginterface_namemsginterface_name_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_resp_t(const u8 *buf, size_t len, sbp_msg_network_state_resp_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgipv4_address_idx = 0; msgipv4_address_idx < 4; msgipv4_address_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->ipv4_address[msgipv4_address_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->ipv4_mask_size, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;
  for (size_t msgipv6_address_idx = 0; msgipv6_address_idx < 16; msgipv6_address_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->ipv6_address[msgipv6_address_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->ipv6_mask_size, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->rx_bytes, buf + offset, 4);
  msg->rx_bytes = le32toh(msg->rx_bytes);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tx_bytes, buf + offset, 4);
  msg->tx_bytes = le32toh(msg->tx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->interface_name[msginterface_name_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  // NOLINTNEXTLINE
  offset += 4;
  return true;
}

static inline size_t sbp_packed_size_sbp_network_usage_t(const sbp_network_usage_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->duration) + sizeof(msg->total_bytes) + sizeof(msg->rx_bytes) + sizeof(msg->tx_bytes) +
         (16 * sizeof(msg->interface_name[0]));
}

static inline bool sbp_pack_sbp_network_usage_t(u8 *buf, size_t len, const sbp_network_usage_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_network_usage_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgduration = htole64(msg->duration);
  memcpy(buf + offset, &msgduration, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgtotal_bytes = htole64(msg->total_bytes);
  memcpy(buf + offset, &msgtotal_bytes, 8);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgrx_bytes = htole32(msg->rx_bytes);
  memcpy(buf + offset, &msgrx_bytes, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtx_bytes = htole32(msg->tx_bytes);
  memcpy(buf + offset, &msgtx_bytes, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    char msginterface_namemsginterface_name_idx = msg->interface_name[msginterface_name_idx];
    memcpy(buf + offset, &msginterface_namemsginterface_name_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_network_usage_t(const u8 *buf, size_t len, sbp_network_usage_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->duration, buf + offset, 8);
  msg->duration = le64toh(msg->duration);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->total_bytes, buf + offset, 8);
  msg->total_bytes = le64toh(msg->total_bytes);
  // NOLINTNEXTLINE
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->rx_bytes, buf + offset, 4);
  msg->rx_bytes = le32toh(msg->rx_bytes);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tx_bytes, buf + offset, 4);
  msg->tx_bytes = le32toh(msg->tx_bytes);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->interface_name[msginterface_name_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *msg)
{
  (void)msg;
  return 0 + (msg->n_interfaces * (0 + sizeof(msg->interfaces[0].duration) + sizeof(msg->interfaces[0].total_bytes) +
                                   sizeof(msg->interfaces[0].rx_bytes) + sizeof(msg->interfaces[0].tx_bytes) +
                                   (16 * sizeof(msg->interfaces[0].interface_name[0]))));
}

static inline bool
sbp_pack_sbp_msg_network_bandwidth_usage_t(u8 *buf, size_t len, const sbp_msg_network_bandwidth_usage_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_network_bandwidth_usage_t(msg) > len)
  {
    return false;
  }

  for (size_t msginterfaces_idx = 0; msginterfaces_idx < (size_t)msg->n_interfaces; msginterfaces_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    u64 msginterfacesmsginterfaces_idxduration = htole64(msg->interfaces[msginterfaces_idx].duration);
    memcpy(buf + offset, &msginterfacesmsginterfaces_idxduration, 8);
    // NOLINTNEXTLINE
    offset += 8;

    if (offset + 8 > len)
    {
      return false;
    }
    u64 msginterfacesmsginterfaces_idxtotal_bytes = htole64(msg->interfaces[msginterfaces_idx].total_bytes);
    memcpy(buf + offset, &msginterfacesmsginterfaces_idxtotal_bytes, 8);
    // NOLINTNEXTLINE
    offset += 8;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msginterfacesmsginterfaces_idxrx_bytes = htole32(msg->interfaces[msginterfaces_idx].rx_bytes);
    memcpy(buf + offset, &msginterfacesmsginterfaces_idxrx_bytes, 4);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    u32 msginterfacesmsginterfaces_idxtx_bytes = htole32(msg->interfaces[msginterfaces_idx].tx_bytes);
    memcpy(buf + offset, &msginterfacesmsginterfaces_idxtx_bytes, 4);
    // NOLINTNEXTLINE
    offset += 4;
    for (size_t msginterfacesmsginterfaces_idxinterface_name_idx = 0;
         msginterfacesmsginterfaces_idxinterface_name_idx < 16;
         msginterfacesmsginterfaces_idxinterface_name_idx++)
    {

      if (offset + 1 > len)
      {
        return false;
      }
      char msginterfacesmsginterfaces_idxinterface_namemsginterfacesmsginterfaces_idxinterface_name_idx =
          msg->interfaces[msginterfaces_idx].interface_name[msginterfacesmsginterfaces_idxinterface_name_idx];
      memcpy(buf + offset,
             &msginterfacesmsginterfaces_idxinterface_namemsginterfacesmsginterfaces_idxinterface_name_idx,
             1);
      // NOLINTNEXTLINE
      offset += 1;
    }
  }
  return true;
}

static inline bool
sbp_unpack_sbp_msg_network_bandwidth_usage_t(const u8 *buf, size_t len, sbp_msg_network_bandwidth_usage_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_interfaces = (u8)((len - offset) / 40);

  for (size_t msginterfaces_idx = 0; msginterfaces_idx < msg->n_interfaces; msginterfaces_idx++)
  {

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->interfaces[msginterfaces_idx].duration, buf + offset, 8);
    msg->interfaces[msginterfaces_idx].duration = le64toh(msg->interfaces[msginterfaces_idx].duration);
    // NOLINTNEXTLINE
    offset += 8;

    if (offset + 8 > len)
    {
      return false;
    }
    memcpy(&msg->interfaces[msginterfaces_idx].total_bytes, buf + offset, 8);
    msg->interfaces[msginterfaces_idx].total_bytes = le64toh(msg->interfaces[msginterfaces_idx].total_bytes);
    // NOLINTNEXTLINE
    offset += 8;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->interfaces[msginterfaces_idx].rx_bytes, buf + offset, 4);
    msg->interfaces[msginterfaces_idx].rx_bytes = le32toh(msg->interfaces[msginterfaces_idx].rx_bytes);
    // NOLINTNEXTLINE
    offset += 4;

    if (offset + 4 > len)
    {
      return false;
    }
    memcpy(&msg->interfaces[msginterfaces_idx].tx_bytes, buf + offset, 4);
    msg->interfaces[msginterfaces_idx].tx_bytes = le32toh(msg->interfaces[msginterfaces_idx].tx_bytes);
    // NOLINTNEXTLINE
    offset += 4;
    for (size_t msginterfacesmsginterfaces_idxinterface_name_idx = 0;
         msginterfacesmsginterfaces_idxinterface_name_idx < 16;
         msginterfacesmsginterfaces_idxinterface_name_idx++)
    {

      if (offset + 1 > len)
      {
        return false;
      }
      memcpy(&msg->interfaces[msginterfaces_idx].interface_name[msginterfacesmsginterfaces_idxinterface_name_idx],
             buf + offset,
             1);
      // NOLINTNEXTLINE
      offset += 1;
    }
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->signal_strength) + sizeof(msg->signal_error_rate) +
         (msg->n_reserved * sizeof(msg->reserved[0]));
}

static inline bool sbp_pack_sbp_msg_cell_modem_status_t(u8 *buf, size_t len, const sbp_msg_cell_modem_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_cell_modem_status_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  s8 msgsignal_strength = msg->signal_strength;
  memcpy(buf + offset, &msgsignal_strength, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgsignal_error_rate = msg->signal_error_rate;
  memcpy(buf + offset, &msgsignal_error_rate, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgreserved_idx = 0; msgreserved_idx < (size_t)msg->n_reserved; msgreserved_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgreservedmsgreserved_idx = msg->reserved[msgreserved_idx];
    memcpy(buf + offset, &msgreservedmsgreserved_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_cell_modem_status_t(const u8 *buf, size_t len, sbp_msg_cell_modem_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->signal_strength, buf + offset, 1);
  // NOLINTNEXTLINE
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->signal_error_rate, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  msg->n_reserved = (u8)((len - offset) / 1);

  for (size_t msgreserved_idx = 0; msgreserved_idx < msg->n_reserved; msgreserved_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->reserved[msgreserved_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel_tag) + (0 + sizeof(msg->t.tow) + sizeof(msg->t.wn)) + sizeof(msg->freq_ref) +
         sizeof(msg->freq_step) + sizeof(msg->amplitude_ref) + sizeof(msg->amplitude_unit) +
         (msg->n_amplitude_value * sizeof(msg->amplitude_value[0]));
}

static inline bool sbp_pack_sbp_msg_specan_dep_t(u8 *buf, size_t len, const sbp_msg_specan_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_specan_dep_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgchannel_tag = htole16(msg->channel_tag);
  memcpy(buf + offset, &msgchannel_tag, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgttow = htole32(msg->t.tow);
  memcpy(buf + offset, &msgttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtwn = htole16(msg->t.wn);
  memcpy(buf + offset, &msgtwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgfreq_ref = msg->freq_ref;
  memcpy(buf + offset, &msgfreq_ref, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgfreq_step = msg->freq_step;
  memcpy(buf + offset, &msgfreq_step, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgamplitude_ref = msg->amplitude_ref;
  memcpy(buf + offset, &msgamplitude_ref, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgamplitude_unit = msg->amplitude_unit;
  memcpy(buf + offset, &msgamplitude_unit, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < (size_t)msg->n_amplitude_value;
       msgamplitude_value_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgamplitude_valuemsgamplitude_value_idx = msg->amplitude_value[msgamplitude_value_idx];
    memcpy(buf + offset, &msgamplitude_valuemsgamplitude_value_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_dep_t(const u8 *buf, size_t len, sbp_msg_specan_dep_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->channel_tag, buf + offset, 2);
  msg->channel_tag = le16toh(msg->channel_tag);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->t.tow, buf + offset, 4);
  msg->t.tow = le32toh(msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t.wn, buf + offset, 2);
  msg->t.wn = le16toh(msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->freq_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->freq_step, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->amplitude_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->amplitude_unit, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  msg->n_amplitude_value = (u8)((len - offset) / 1);

  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < msg->n_amplitude_value; msgamplitude_value_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->amplitude_value[msgamplitude_value_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->channel_tag) + (0 + sizeof(msg->t.tow) + sizeof(msg->t.ns_residual) + sizeof(msg->t.wn)) +
         sizeof(msg->freq_ref) + sizeof(msg->freq_step) + sizeof(msg->amplitude_ref) + sizeof(msg->amplitude_unit) +
         (msg->n_amplitude_value * sizeof(msg->amplitude_value[0]));
}

static inline bool sbp_pack_sbp_msg_specan_t(u8 *buf, size_t len, const sbp_msg_specan_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_specan_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgchannel_tag = htole16(msg->channel_tag);
  memcpy(buf + offset, &msgchannel_tag, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgttow = htole32(msg->t.tow);
  memcpy(buf + offset, &msgttow, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtns_residual = htole32(*(const u32 *)&msg->t.ns_residual);
  memcpy(buf + offset, &msgtns_residual, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtwn = htole16(msg->t.wn);
  memcpy(buf + offset, &msgtwn, 2);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgfreq_ref = msg->freq_ref;
  memcpy(buf + offset, &msgfreq_ref, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgfreq_step = msg->freq_step;
  memcpy(buf + offset, &msgfreq_step, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgamplitude_ref = msg->amplitude_ref;
  memcpy(buf + offset, &msgamplitude_ref, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgamplitude_unit = msg->amplitude_unit;
  memcpy(buf + offset, &msgamplitude_unit, 4);
  // NOLINTNEXTLINE
  offset += 4;
  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < (size_t)msg->n_amplitude_value;
       msgamplitude_value_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgamplitude_valuemsgamplitude_value_idx = msg->amplitude_value[msgamplitude_value_idx];
    memcpy(buf + offset, &msgamplitude_valuemsgamplitude_value_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_t(const u8 *buf, size_t len, sbp_msg_specan_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->channel_tag, buf + offset, 2);
  msg->channel_tag = le16toh(msg->channel_tag);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->t.tow, buf + offset, 4);
  msg->t.tow = le32toh(msg->t.tow);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->t.ns_residual, buf + offset, 4);
  u32 msgtns_residual = *(const u32 *)&msg->t.ns_residual;
  msgtns_residual = le32toh(msgtns_residual);
  msg->t.ns_residual = *(const s32 *)&msgtns_residual;
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->t.wn, buf + offset, 2);
  msg->t.wn = le16toh(msg->t.wn);
  // NOLINTNEXTLINE
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->freq_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->freq_step, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->amplitude_ref, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->amplitude_unit, buf + offset, 4);
  // NOLINTNEXTLINE
  offset += 4;
  msg->n_amplitude_value = (u8)((len - offset) / 1);

  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < msg->n_amplitude_value; msgamplitude_value_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->amplitude_value[msgamplitude_value_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline size_t sbp_packed_size_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *msg)
{
  (void)msg;
  return 0 + (8 * sizeof(msg->rf_gain[0])) + (8 * sizeof(msg->if_gain[0]));
}

static inline bool sbp_pack_sbp_msg_front_end_gain_t(u8 *buf, size_t len, const sbp_msg_front_end_gain_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_front_end_gain_t(msg) > len)
  {
    return false;
  }

  for (size_t msgrf_gain_idx = 0; msgrf_gain_idx < 8; msgrf_gain_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    s8 msgrf_gainmsgrf_gain_idx = msg->rf_gain[msgrf_gain_idx];
    memcpy(buf + offset, &msgrf_gainmsgrf_gain_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  for (size_t msgif_gain_idx = 0; msgif_gain_idx < 8; msgif_gain_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    s8 msgif_gainmsgif_gain_idx = msg->if_gain[msgif_gain_idx];
    memcpy(buf + offset, &msgif_gainmsgif_gain_idx, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_front_end_gain_t(const u8 *buf, size_t len, sbp_msg_front_end_gain_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  for (size_t msgrf_gain_idx = 0; msgrf_gain_idx < 8; msgrf_gain_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->rf_gain[msgrf_gain_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  for (size_t msgif_gain_idx = 0; msgif_gain_idx < 8; msgif_gain_idx++)
  {

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->if_gain[msgif_gain_idx], buf + offset, 1);
    // NOLINTNEXTLINE
    offset += 1;
  }
  return true;
}

#endif
