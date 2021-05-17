#ifndef LIBSBP_PIKSI_OPERATORS_H
#define LIBSBP_PIKSI_OPERATORS_H

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
#include <libsbp/string.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_almanac_t(const sbp_msg_almanac_t *a, const sbp_msg_almanac_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return sbp_cmp_sbp_msg_almanac_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return sbp_cmp_sbp_msg_almanac_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return sbp_cmp_sbp_msg_almanac_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return sbp_cmp_sbp_msg_almanac_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return sbp_cmp_sbp_msg_almanac_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return sbp_cmp_sbp_msg_almanac_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_set_time_t(const sbp_msg_set_time_t *a, const sbp_msg_set_time_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return sbp_cmp_sbp_msg_set_time_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return sbp_cmp_sbp_msg_set_time_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return sbp_cmp_sbp_msg_set_time_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return sbp_cmp_sbp_msg_set_time_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return sbp_cmp_sbp_msg_set_time_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return sbp_cmp_sbp_msg_set_time_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_reset_t(const sbp_msg_reset_t *a, const sbp_msg_reset_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return sbp_cmp_sbp_msg_reset_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return sbp_cmp_sbp_msg_reset_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return sbp_cmp_sbp_msg_reset_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return sbp_cmp_sbp_msg_reset_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return sbp_cmp_sbp_msg_reset_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return sbp_cmp_sbp_msg_reset_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *a, const sbp_msg_reset_dep_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return sbp_cmp_sbp_msg_reset_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return sbp_cmp_sbp_msg_reset_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return sbp_cmp_sbp_msg_reset_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return sbp_cmp_sbp_msg_reset_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return sbp_cmp_sbp_msg_reset_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return sbp_cmp_sbp_msg_reset_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *a, const sbp_msg_cw_results_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return sbp_cmp_sbp_msg_cw_results_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return sbp_cmp_sbp_msg_cw_results_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return sbp_cmp_sbp_msg_cw_results_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return sbp_cmp_sbp_msg_cw_results_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return sbp_cmp_sbp_msg_cw_results_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return sbp_cmp_sbp_msg_cw_results_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *a, const sbp_msg_cw_start_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return sbp_cmp_sbp_msg_cw_start_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return sbp_cmp_sbp_msg_cw_start_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return sbp_cmp_sbp_msg_cw_start_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return sbp_cmp_sbp_msg_cw_start_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return sbp_cmp_sbp_msg_cw_start_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return sbp_cmp_sbp_msg_cw_start_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *a, const sbp_msg_reset_filters_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->filter, &b->filter);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return sbp_cmp_sbp_msg_reset_filters_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return sbp_cmp_sbp_msg_reset_filters_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return sbp_cmp_sbp_msg_reset_filters_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return sbp_cmp_sbp_msg_reset_filters_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return sbp_cmp_sbp_msg_reset_filters_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return sbp_cmp_sbp_msg_reset_filters_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *a, const sbp_msg_init_base_dep_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return sbp_cmp_sbp_msg_init_base_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *a, const sbp_msg_thread_state_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return sbp_cmp_sbp_msg_thread_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return sbp_cmp_sbp_msg_thread_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return sbp_cmp_sbp_msg_thread_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return sbp_cmp_sbp_msg_thread_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return sbp_cmp_sbp_msg_thread_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return sbp_cmp_sbp_msg_thread_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_uart_channel_t(const sbp_uart_channel_t *a, const sbp_uart_channel_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b) {
  return sbp_cmp_sbp_uart_channel_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b) {
  return sbp_cmp_sbp_uart_channel_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b) {
  return sbp_cmp_sbp_uart_channel_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b) {
  return sbp_cmp_sbp_uart_channel_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b) {
  return sbp_cmp_sbp_uart_channel_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_uart_channel_t &a, const sbp_uart_channel_t &b) {
  return sbp_cmp_sbp_uart_channel_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_period_t(const sbp_period_t *a, const sbp_period_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_period_t &a, const sbp_period_t &b) {
  return sbp_cmp_sbp_period_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_period_t &a, const sbp_period_t &b) {
  return sbp_cmp_sbp_period_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_period_t &a, const sbp_period_t &b) {
  return sbp_cmp_sbp_period_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_period_t &a, const sbp_period_t &b) {
  return sbp_cmp_sbp_period_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_period_t &a, const sbp_period_t &b) {
  return sbp_cmp_sbp_period_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_period_t &a, const sbp_period_t &b) {
  return sbp_cmp_sbp_period_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_latency_t(const sbp_latency_t *a, const sbp_latency_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_latency_t &a, const sbp_latency_t &b) {
  return sbp_cmp_sbp_latency_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_latency_t &a, const sbp_latency_t &b) {
  return sbp_cmp_sbp_latency_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_latency_t &a, const sbp_latency_t &b) {
  return sbp_cmp_sbp_latency_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_latency_t &a, const sbp_latency_t &b) {
  return sbp_cmp_sbp_latency_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_latency_t &a, const sbp_latency_t &b) {
  return sbp_cmp_sbp_latency_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_latency_t &a, const sbp_latency_t &b) {
  return sbp_cmp_sbp_latency_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *a, const sbp_msg_uart_state_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return sbp_cmp_sbp_msg_uart_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return sbp_cmp_sbp_msg_uart_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return sbp_cmp_sbp_msg_uart_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return sbp_cmp_sbp_msg_uart_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return sbp_cmp_sbp_msg_uart_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return sbp_cmp_sbp_msg_uart_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *a, const sbp_msg_uart_state_depa_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return sbp_cmp_sbp_msg_uart_state_depa_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *a, const sbp_msg_iar_state_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->num_hyps, &b->num_hyps);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return sbp_cmp_sbp_msg_iar_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return sbp_cmp_sbp_msg_iar_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return sbp_cmp_sbp_msg_iar_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return sbp_cmp_sbp_msg_iar_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return sbp_cmp_sbp_msg_iar_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return sbp_cmp_sbp_msg_iar_state_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *a, const sbp_msg_mask_satellite_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->mask, &b->mask);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *a, const sbp_msg_mask_satellite_dep_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->mask, &b->mask);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_gnss_signal_dep_t(&a->sid, &b->sid);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return sbp_cmp_sbp_msg_mask_satellite_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *a, const sbp_msg_device_monitor_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return sbp_cmp_sbp_msg_device_monitor_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return sbp_cmp_sbp_msg_device_monitor_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return sbp_cmp_sbp_msg_device_monitor_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return sbp_cmp_sbp_msg_device_monitor_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return sbp_cmp_sbp_msg_device_monitor_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return sbp_cmp_sbp_msg_device_monitor_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_command_req_t(const sbp_msg_command_req_t *a, const sbp_msg_command_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->command, &b->command, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return sbp_cmp_sbp_msg_command_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return sbp_cmp_sbp_msg_command_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return sbp_cmp_sbp_msg_command_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return sbp_cmp_sbp_msg_command_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return sbp_cmp_sbp_msg_command_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return sbp_cmp_sbp_msg_command_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *a, const sbp_msg_command_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->code, &b->code);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return sbp_cmp_sbp_msg_command_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return sbp_cmp_sbp_msg_command_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return sbp_cmp_sbp_msg_command_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return sbp_cmp_sbp_msg_command_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return sbp_cmp_sbp_msg_command_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return sbp_cmp_sbp_msg_command_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_command_output_t(const sbp_msg_command_output_t *a, const sbp_msg_command_output_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->line, &b->line, 251
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return sbp_cmp_sbp_msg_command_output_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return sbp_cmp_sbp_msg_command_output_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return sbp_cmp_sbp_msg_command_output_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return sbp_cmp_sbp_msg_command_output_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return sbp_cmp_sbp_msg_command_output_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return sbp_cmp_sbp_msg_command_output_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *a, const sbp_msg_network_state_req_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return sbp_cmp_sbp_msg_network_state_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return sbp_cmp_sbp_msg_network_state_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return sbp_cmp_sbp_msg_network_state_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return sbp_cmp_sbp_msg_network_state_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return sbp_cmp_sbp_msg_network_state_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return sbp_cmp_sbp_msg_network_state_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *a, const sbp_msg_network_state_resp_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return sbp_cmp_sbp_msg_network_state_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_network_usage_t(const sbp_network_usage_t *a, const sbp_network_usage_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_network_usage_t &a, const sbp_network_usage_t &b) {
  return sbp_cmp_sbp_network_usage_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_network_usage_t &a, const sbp_network_usage_t &b) {
  return sbp_cmp_sbp_network_usage_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_network_usage_t &a, const sbp_network_usage_t &b) {
  return sbp_cmp_sbp_network_usage_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_network_usage_t &a, const sbp_network_usage_t &b) {
  return sbp_cmp_sbp_network_usage_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_network_usage_t &a, const sbp_network_usage_t &b) {
  return sbp_cmp_sbp_network_usage_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_network_usage_t &a, const sbp_network_usage_t &b) {
  return sbp_cmp_sbp_network_usage_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *a, const sbp_msg_network_bandwidth_usage_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_interfaces, &b->n_interfaces);
  for (uint8_t i = 0; i < a->n_interfaces && ret == 0; i++)
  {
    ret = sbp_cmp_sbp_network_usage_t(&a->interfaces[i], &b->interfaces[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return sbp_cmp_sbp_msg_network_bandwidth_usage_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *a, const sbp_msg_cell_modem_status_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return sbp_cmp_sbp_msg_cell_modem_status_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *a, const sbp_msg_specan_dep_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return sbp_cmp_sbp_msg_specan_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return sbp_cmp_sbp_msg_specan_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return sbp_cmp_sbp_msg_specan_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return sbp_cmp_sbp_msg_specan_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return sbp_cmp_sbp_msg_specan_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return sbp_cmp_sbp_msg_specan_dep_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_specan_t(const sbp_msg_specan_t *a, const sbp_msg_specan_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return sbp_cmp_sbp_msg_specan_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return sbp_cmp_sbp_msg_specan_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return sbp_cmp_sbp_msg_specan_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return sbp_cmp_sbp_msg_specan_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return sbp_cmp_sbp_msg_specan_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return sbp_cmp_sbp_msg_specan_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *a, const sbp_msg_front_end_gain_t *b) {
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

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return sbp_cmp_sbp_msg_front_end_gain_t(&a, &b) >= 0;
}
#endif

#endif
