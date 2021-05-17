#ifndef LIBSBP_PIKSI_PACKERS_H
#define LIBSBP_PIKSI_PACKERS_H

#ifndef LIBSBP_PIKSI_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/piksi.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/base.h>
#include <libsbp/string.h>
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_almanac_t(u8 *buf, size_t len, const sbp_msg_almanac_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_t(const uint8_t *buf, size_t len, sbp_msg_almanac_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_set_time_t(u8 *buf, size_t len, const sbp_msg_set_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_set_time_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_set_time_t(const uint8_t *buf, size_t len, sbp_msg_set_time_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->flags);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_reset_t(u8 *buf, size_t len, const sbp_msg_reset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_t(const uint8_t *buf, size_t len, sbp_msg_reset_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_reset_dep_t(u8 *buf, size_t len, const sbp_msg_reset_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_dep_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_dep_t(const uint8_t *buf, size_t len, sbp_msg_reset_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_cw_results_t(u8 *buf, size_t len, const sbp_msg_cw_results_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cw_results_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_results_t(const uint8_t *buf, size_t len, sbp_msg_cw_results_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_cw_start_t(u8 *buf, size_t len, const sbp_msg_cw_start_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cw_start_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_start_t(const uint8_t *buf, size_t len, sbp_msg_cw_start_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->filter);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_reset_filters_t(u8 *buf, size_t len, const sbp_msg_reset_filters_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_filters_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->filter);
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_filters_t(const uint8_t *buf, size_t len, sbp_msg_reset_filters_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->filter);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_init_base_dep_t(u8 *buf, size_t len, const sbp_msg_init_base_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_init_base_dep_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_init_base_dep_t(const uint8_t *buf, size_t len, sbp_msg_init_base_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += ( 20 * sbp_packed_size_char(&msg->name[0]));
  packed_size += sbp_packed_size_u16(&msg->cpu);
  packed_size += sbp_packed_size_u32(&msg->stack_free);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_thread_state_t(u8 *buf, size_t len, const sbp_msg_thread_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_thread_state_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < 20; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->name[i]);
  }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->cpu);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->stack_free);
  return true;
}

static inline bool sbp_unpack_sbp_msg_thread_state_t(const uint8_t *buf, size_t len, sbp_msg_thread_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  for (uint8_t i = 0; i < 20; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->name[i]);
  }
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->cpu);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->stack_free);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_uart_channel_t(const sbp_uart_channel_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_float(&msg->tx_throughput);
  packed_size += sbp_packed_size_float(&msg->rx_throughput);
  packed_size += sbp_packed_size_u16(&msg->crc_error_count);
  packed_size += sbp_packed_size_u16(&msg->io_error_count);
  packed_size += sbp_packed_size_u8(&msg->tx_buffer_level);
  packed_size += sbp_packed_size_u8(&msg->rx_buffer_level);
  return packed_size;
}

static inline size_t sbp_pack_sbp_uart_channel_t(u8 *buf, size_t len, const sbp_uart_channel_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_uart_channel_t(msg) > len) { return false; }
  offset += sbp_pack_float(buf + offset, len - offset, &msg->tx_throughput);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->rx_throughput);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->crc_error_count);
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->io_error_count);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->tx_buffer_level);
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->rx_buffer_level);
  return offset;
}

static inline size_t sbp_unpack_sbp_uart_channel_t(const uint8_t *buf, size_t len, sbp_uart_channel_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->tx_throughput);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->rx_throughput);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->crc_error_count);
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->io_error_count);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->tx_buffer_level);
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->rx_buffer_level);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_period_t(const sbp_period_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s32(&msg->avg);
  packed_size += sbp_packed_size_s32(&msg->pmin);
  packed_size += sbp_packed_size_s32(&msg->pmax);
  packed_size += sbp_packed_size_s32(&msg->current);
  return packed_size;
}

static inline size_t sbp_pack_sbp_period_t(u8 *buf, size_t len, const sbp_period_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_period_t(msg) > len) { return false; }
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->avg);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->pmin);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->pmax);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->current);
  return offset;
}

static inline size_t sbp_unpack_sbp_period_t(const uint8_t *buf, size_t len, sbp_period_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->avg);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->pmin);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->pmax);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->current);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_latency_t(const sbp_latency_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s32(&msg->avg);
  packed_size += sbp_packed_size_s32(&msg->lmin);
  packed_size += sbp_packed_size_s32(&msg->lmax);
  packed_size += sbp_packed_size_s32(&msg->current);
  return packed_size;
}

static inline size_t sbp_pack_sbp_latency_t(u8 *buf, size_t len, const sbp_latency_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_latency_t(msg) > len) { return false; }
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->avg);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->lmin);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->lmax);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->current);
  return offset;
}

static inline size_t sbp_unpack_sbp_latency_t(const uint8_t *buf, size_t len, sbp_latency_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->avg);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->lmin);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->lmax);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->current);
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_a);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_b);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_ftdi);
  packed_size += sbp_packed_size_sbp_latency_t(&msg->latency);
  packed_size += sbp_packed_size_sbp_period_t(&msg->obs_period);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_uart_state_t(u8 *buf, size_t len, const sbp_msg_uart_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_uart_state_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_a);
  offset += sbp_pack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_b);
  offset += sbp_pack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_ftdi);
  offset += sbp_pack_sbp_latency_t(buf + offset, len - offset, &msg->latency);
  offset += sbp_pack_sbp_period_t(buf + offset, len - offset, &msg->obs_period);
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_t(const uint8_t *buf, size_t len, sbp_msg_uart_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_a);
  offset += sbp_unpack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_b);
  offset += sbp_unpack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_ftdi);
  offset += sbp_unpack_sbp_latency_t(buf + offset, len - offset, &msg->latency);
  offset += sbp_unpack_sbp_period_t(buf + offset, len - offset, &msg->obs_period);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_a);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_b);
  packed_size += sbp_packed_size_sbp_uart_channel_t(&msg->uart_ftdi);
  packed_size += sbp_packed_size_sbp_latency_t(&msg->latency);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_uart_state_depa_t(u8 *buf, size_t len, const sbp_msg_uart_state_depa_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_uart_state_depa_t(msg) > len) { return false; }
  offset += sbp_pack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_a);
  offset += sbp_pack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_b);
  offset += sbp_pack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_ftdi);
  offset += sbp_pack_sbp_latency_t(buf + offset, len - offset, &msg->latency);
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_depa_t(const uint8_t *buf, size_t len, sbp_msg_uart_state_depa_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_a);
  offset += sbp_unpack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_b);
  offset += sbp_unpack_sbp_uart_channel_t(buf + offset, len - offset, &msg->uart_ftdi);
  offset += sbp_unpack_sbp_latency_t(buf + offset, len - offset, &msg->latency);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->num_hyps);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_iar_state_t(u8 *buf, size_t len, const sbp_msg_iar_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_iar_state_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->num_hyps);
  return true;
}

static inline bool sbp_unpack_sbp_msg_iar_state_t(const uint8_t *buf, size_t len, sbp_msg_iar_state_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->num_hyps);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_sbp_sbp_gnss_signal_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_mask_satellite_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mask_satellite_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->mask);
  offset += sbp_pack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_t(const uint8_t *buf, size_t len, sbp_msg_mask_satellite_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->mask);
  offset += sbp_unpack_sbp_sbp_gnss_signal_t(buf + offset, len - offset, &msg->sid);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u8(&msg->mask);
  packed_size += sbp_packed_size_sbp_gnss_signal_dep_t(&msg->sid);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_mask_satellite_dep_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mask_satellite_dep_t(msg) > len) { return false; }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->mask);
  offset += sbp_pack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_dep_t(const uint8_t *buf, size_t len, sbp_msg_mask_satellite_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->mask);
  offset += sbp_unpack_sbp_gnss_signal_dep_t(buf + offset, len - offset, &msg->sid);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s16(&msg->dev_vin);
  packed_size += sbp_packed_size_s16(&msg->cpu_vint);
  packed_size += sbp_packed_size_s16(&msg->cpu_vaux);
  packed_size += sbp_packed_size_s16(&msg->cpu_temperature);
  packed_size += sbp_packed_size_s16(&msg->fe_temperature);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_device_monitor_t(u8 *buf, size_t len, const sbp_msg_device_monitor_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_device_monitor_t(msg) > len) { return false; }
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->dev_vin);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->cpu_vint);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->cpu_vaux);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->cpu_temperature);
  offset += sbp_pack_s16(buf + offset, len - offset, &msg->fe_temperature);
  return true;
}

static inline bool sbp_unpack_sbp_msg_device_monitor_t(const uint8_t *buf, size_t len, sbp_msg_device_monitor_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->dev_vin);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->cpu_vint);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->cpu_vaux);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->cpu_temperature);
  offset += sbp_unpack_s16(buf + offset, len - offset, &msg->fe_temperature);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_null_terminated_string_packed_len(&msg->command, 251
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_command_req_t(u8 *buf, size_t len, const sbp_msg_command_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_req_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_null_terminated_string_pack(&msg->command, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_req_t(const uint8_t *buf, size_t len, sbp_msg_command_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_null_terminated_string_unpack(&msg->command, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_packed_size_s32(&msg->code);
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_command_resp_t(u8 *buf, size_t len, const sbp_msg_command_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_resp_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_pack_s32(buf + offset, len - offset, &msg->code);
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_resp_t(const uint8_t *buf, size_t len, sbp_msg_command_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unpack_s32(buf + offset, len - offset, &msg->code);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_command_output_t(const sbp_msg_command_output_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u32(&msg->sequence);
  packed_size += sbp_unterminated_string_packed_len(&msg->line, 251
      );
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_command_output_t(u8 *buf, size_t len, const sbp_msg_command_output_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_output_t(msg) > len) { return false; }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unterminated_string_pack(&msg->line, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_output_t(const uint8_t *buf, size_t len, sbp_msg_command_output_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->sequence);
  offset += sbp_unterminated_string_unpack(&msg->line, 251,
      buf + offset, (uint8_t)(len - offset));
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_network_state_req_t(u8 *buf, size_t len, const sbp_msg_network_state_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_state_req_t(msg) > len) { return false; }
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_req_t(const uint8_t *buf, size_t len, sbp_msg_network_state_req_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *msg) {
  size_t packed_size = 0;
  (void)msg;
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

static inline bool sbp_pack_sbp_msg_network_state_resp_t(u8 *buf, size_t len, const sbp_msg_network_state_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_state_resp_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < 4; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->ipv4_address[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->ipv4_mask_size);
  for (uint8_t i = 0; i < 16; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->ipv6_address[i]);
  }
  offset += sbp_pack_u8(buf + offset, len - offset, &msg->ipv6_mask_size);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->rx_bytes);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tx_bytes);
  for (uint8_t i = 0; i < 16; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->interface_name[i]);
  }
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_resp_t(const uint8_t *buf, size_t len, sbp_msg_network_state_resp_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  for (uint8_t i = 0; i < 4; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->ipv4_address[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->ipv4_mask_size);
  for (uint8_t i = 0; i < 16; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->ipv6_address[i]);
  }
  offset += sbp_unpack_u8(buf + offset, len - offset, &msg->ipv6_mask_size);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->rx_bytes);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tx_bytes);
  for (uint8_t i = 0; i < 16; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->interface_name[i]);
  }
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->flags);
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_network_usage_t(const sbp_network_usage_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u64(&msg->duration);
  packed_size += sbp_packed_size_u64(&msg->total_bytes);
  packed_size += sbp_packed_size_u32(&msg->rx_bytes);
  packed_size += sbp_packed_size_u32(&msg->tx_bytes);
  packed_size += ( 16 * sbp_packed_size_char(&msg->interface_name[0]));
  return packed_size;
}

static inline size_t sbp_pack_sbp_network_usage_t(u8 *buf, size_t len, const sbp_network_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_network_usage_t(msg) > len) { return false; }
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->duration);
  offset += sbp_pack_u64(buf + offset, len - offset, &msg->total_bytes);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->rx_bytes);
  offset += sbp_pack_u32(buf + offset, len - offset, &msg->tx_bytes);
  for (uint8_t i = 0; i < 16; i++) 
  {
    offset += sbp_pack_char(buf + offset, len - offset, &msg->interface_name[i]);
  }
  return offset;
}

static inline size_t sbp_unpack_sbp_network_usage_t(const uint8_t *buf, size_t len, sbp_network_usage_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->duration);
  offset += sbp_unpack_u64(buf + offset, len - offset, &msg->total_bytes);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->rx_bytes);
  offset += sbp_unpack_u32(buf + offset, len - offset, &msg->tx_bytes);
  for (uint8_t i = 0; i < 16; i++)
  {
    offset += sbp_unpack_char(buf + offset, len - offset, &msg->interface_name[i]);
  }
  return offset;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += (msg->n_interfaces * sbp_packed_size_sbp_network_usage_t(&msg->interfaces[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_network_bandwidth_usage_t(u8 *buf, size_t len, const sbp_msg_network_bandwidth_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_bandwidth_usage_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < msg->n_interfaces; i++) 
  {
    offset += sbp_pack_sbp_network_usage_t(buf + offset, len - offset, &msg->interfaces[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_bandwidth_usage_t(const uint8_t *buf, size_t len, sbp_msg_network_bandwidth_usage_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  msg->n_interfaces = (uint8_t)((len - offset) / sbp_packed_size_sbp_network_usage_t(&msg->interfaces[0]));
  for (uint8_t i = 0; i < msg->n_interfaces; i++)
  {
    offset += sbp_unpack_sbp_network_usage_t(buf + offset, len - offset, &msg->interfaces[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_s8(&msg->signal_strength);
  packed_size += sbp_packed_size_float(&msg->signal_error_rate);
  packed_size += (msg->n_reserved * sbp_packed_size_u8(&msg->reserved[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_cell_modem_status_t(u8 *buf, size_t len, const sbp_msg_cell_modem_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cell_modem_status_t(msg) > len) { return false; }
  offset += sbp_pack_s8(buf + offset, len - offset, &msg->signal_strength);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->signal_error_rate);
  for (uint8_t i = 0; i < msg->n_reserved; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->reserved[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_cell_modem_status_t(const uint8_t *buf, size_t len, sbp_msg_cell_modem_status_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_s8(buf + offset, len - offset, &msg->signal_strength);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->signal_error_rate);
  msg->n_reserved = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->reserved[0]));
  for (uint8_t i = 0; i < msg->n_reserved; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->reserved[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->channel_tag);
  packed_size += sbp_packed_size_sbp_gps_time_dep_t(&msg->t);
  packed_size += sbp_packed_size_float(&msg->freq_ref);
  packed_size += sbp_packed_size_float(&msg->freq_step);
  packed_size += sbp_packed_size_float(&msg->amplitude_ref);
  packed_size += sbp_packed_size_float(&msg->amplitude_unit);
  packed_size += (msg->n_amplitude_value * sbp_packed_size_u8(&msg->amplitude_value[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_specan_dep_t(u8 *buf, size_t len, const sbp_msg_specan_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_specan_dep_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->channel_tag);
  offset += sbp_pack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->t);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->freq_ref);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->freq_step);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->amplitude_ref);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->amplitude_unit);
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->amplitude_value[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_dep_t(const uint8_t *buf, size_t len, sbp_msg_specan_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->channel_tag);
  offset += sbp_unpack_sbp_gps_time_dep_t(buf + offset, len - offset, &msg->t);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->freq_ref);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->freq_step);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->amplitude_ref);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->amplitude_unit);
  msg->n_amplitude_value = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->amplitude_value[0]));
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->amplitude_value[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += sbp_packed_size_u16(&msg->channel_tag);
  packed_size += sbp_packed_size_sbp_sbp_gps_time_t(&msg->t);
  packed_size += sbp_packed_size_float(&msg->freq_ref);
  packed_size += sbp_packed_size_float(&msg->freq_step);
  packed_size += sbp_packed_size_float(&msg->amplitude_ref);
  packed_size += sbp_packed_size_float(&msg->amplitude_unit);
  packed_size += (msg->n_amplitude_value * sbp_packed_size_u8(&msg->amplitude_value[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_specan_t(u8 *buf, size_t len, const sbp_msg_specan_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_specan_t(msg) > len) { return false; }
  offset += sbp_pack_u16(buf + offset, len - offset, &msg->channel_tag);
  offset += sbp_pack_sbp_sbp_gps_time_t(buf + offset, len - offset, &msg->t);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->freq_ref);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->freq_step);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->amplitude_ref);
  offset += sbp_pack_float(buf + offset, len - offset, &msg->amplitude_unit);
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++) 
  {
    offset += sbp_pack_u8(buf + offset, len - offset, &msg->amplitude_value[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_t(const uint8_t *buf, size_t len, sbp_msg_specan_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  offset += sbp_unpack_u16(buf + offset, len - offset, &msg->channel_tag);
  offset += sbp_unpack_sbp_sbp_gps_time_t(buf + offset, len - offset, &msg->t);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->freq_ref);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->freq_step);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->amplitude_ref);
  offset += sbp_unpack_float(buf + offset, len - offset, &msg->amplitude_unit);
  msg->n_amplitude_value = (uint8_t)((len - offset) / sbp_packed_size_u8(&msg->amplitude_value[0]));
  for (uint8_t i = 0; i < msg->n_amplitude_value; i++)
  {
    offset += sbp_unpack_u8(buf + offset, len - offset, &msg->amplitude_value[i]);
  }
  return true;
  return true;
}
                                                                                                              
static inline size_t sbp_packed_size_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *msg) {
  size_t packed_size = 0;
  (void)msg;
  packed_size += ( 8 * sbp_packed_size_s8(&msg->rf_gain[0]));
  packed_size += ( 8 * sbp_packed_size_s8(&msg->if_gain[0]));
  return packed_size;
}

static inline bool sbp_pack_sbp_msg_front_end_gain_t(u8 *buf, size_t len, const sbp_msg_front_end_gain_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_front_end_gain_t(msg) > len) { return false; }
  for (uint8_t i = 0; i < 8; i++) 
  {
    offset += sbp_pack_s8(buf + offset, len - offset, &msg->rf_gain[i]);
  }
  for (uint8_t i = 0; i < 8; i++) 
  {
    offset += sbp_pack_s8(buf + offset, len - offset, &msg->if_gain[i]);
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_front_end_gain_t(const uint8_t *buf, size_t len, sbp_msg_front_end_gain_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  for (uint8_t i = 0; i < 8; i++)
  {
    offset += sbp_unpack_s8(buf + offset, len - offset, &msg->rf_gain[i]);
  }
  for (uint8_t i = 0; i < 8; i++)
  {
    offset += sbp_unpack_s8(buf + offset, len - offset, &msg->if_gain[i]);
  }
  return true;
}

#endif
