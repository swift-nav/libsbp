#ifndef LIBSBP_NEW_PIKSI_MESSAGES_H
#define LIBSBP_NEW_PIKSI_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
/** Legacy message to load satellite almanac (host => Piksi)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_ALMANAC                 0x0069
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_almanac_t;

size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg);
s8 sbp_encode_sbp_msg_almanac_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_almanac_t *msg);
s8 sbp_decode_sbp_msg_almanac_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_almanac_t *msg);
s8 sbp_send_sbp_msg_almanac_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_almanac_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_almanac_t(const sbp_msg_almanac_t *a, const sbp_msg_almanac_t *b);


/** Send GPS time from host (host => Piksi)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_SET_TIME                0x0068
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_set_time_t;

size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg);
s8 sbp_encode_sbp_msg_set_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_set_time_t *msg);
s8 sbp_decode_sbp_msg_set_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_set_time_t *msg);
s8 sbp_send_sbp_msg_set_time_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_set_time_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_set_time_t(const sbp_msg_set_time_t *a, const sbp_msg_set_time_t *b);


#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_RESET_DEFAULT_SETTINGS_MASK (0x1)
#define SBP_RESET_DEFAULT_SETTINGS_SHIFT (0u)
#define SBP_RESET_DEFAULT_SETTINGS_GET(flags) \
                             (((flags) >> SBP_RESET_DEFAULT_SETTINGS_SHIFT) \
                             & SBP_RESET_DEFAULT_SETTINGS_MASK)
#define SBP_RESET_DEFAULT_SETTINGS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_RESET_DEFAULT_SETTINGS_MASK)) \
                             << (SBP_RESET_DEFAULT_SETTINGS_SHIFT)));} while(0)
                             

#define SBP_RESET_DEFAULT_SETTINGS_PRESERVE_EXISTING_SETTINGS (0)
#define SBP_RESET_DEFAULT_SETTINGS_RESORE_DEFAULT_SETTINGS (1)
#endif
/** Reset the device (host => Piksi)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_RESET                   0x00B6
#endif
typedef struct {
  u32 flags;
} sbp_msg_reset_t;

size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg);
s8 sbp_encode_sbp_msg_reset_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_reset_t *msg);
s8 sbp_decode_sbp_msg_reset_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_reset_t *msg);
s8 sbp_send_sbp_msg_reset_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_reset_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_reset_t(const sbp_msg_reset_t *a, const sbp_msg_reset_t *b);


/** Reset the device (host => Piksi)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_RESET_DEP               0x00B2
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_reset_dep_t;

size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg);
s8 sbp_encode_sbp_msg_reset_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_reset_dep_t *msg);
s8 sbp_decode_sbp_msg_reset_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_reset_dep_t *msg);
s8 sbp_send_sbp_msg_reset_dep_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_reset_dep_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *a, const sbp_msg_reset_dep_t *b);


/** Legacy message for CW interference channel (Piksi => host)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_CW_RESULTS              0x00C0
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_cw_results_t;

size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg);
s8 sbp_encode_sbp_msg_cw_results_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_cw_results_t *msg);
s8 sbp_decode_sbp_msg_cw_results_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_cw_results_t *msg);
s8 sbp_send_sbp_msg_cw_results_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_cw_results_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *a, const sbp_msg_cw_results_t *b);


/** Legacy message for CW interference channel (host => Piksi)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_CW_START                0x00C1
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_cw_start_t;

size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg);
s8 sbp_encode_sbp_msg_cw_start_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_cw_start_t *msg);
s8 sbp_decode_sbp_msg_cw_start_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_cw_start_t *msg);
s8 sbp_send_sbp_msg_cw_start_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_cw_start_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *a, const sbp_msg_cw_start_t *b);


#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK (0x3)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT (0u)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_GET(flags) \
                             (((flags) >> SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT) \
                             & SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)) \
                             << (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT)));} while(0)
                             

#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_DGNSS_FILTER (0)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_IAR_PROCESS (1)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_INERTIAL_FILTER (2)
#endif
/** Reset IAR filters (host => Piksi)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_RESET_FILTERS           0x0022
#endif
typedef struct {
  u8 filter;
} sbp_msg_reset_filters_t;

size_t sbp_packed_size_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *msg);
s8 sbp_encode_sbp_msg_reset_filters_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_reset_filters_t *msg);
s8 sbp_decode_sbp_msg_reset_filters_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_reset_filters_t *msg);
s8 sbp_send_sbp_msg_reset_filters_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_reset_filters_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *a, const sbp_msg_reset_filters_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_INIT_BASE_DEP           0x0023
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_init_base_dep_t;

size_t sbp_packed_size_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *msg);
s8 sbp_encode_sbp_msg_init_base_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_init_base_dep_t *msg);
s8 sbp_decode_sbp_msg_init_base_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_init_base_dep_t *msg);
s8 sbp_send_sbp_msg_init_base_dep_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_init_base_dep_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *a, const sbp_msg_init_base_dep_t *b);


/** State of an RTOS thread
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_THREAD_STATE            0x0017
#endif
typedef struct {
  char name[20];
  u16 cpu;
  u32 stack_free;
} sbp_msg_thread_state_t;

size_t sbp_packed_size_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *msg);
s8 sbp_encode_sbp_msg_thread_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_thread_state_t *msg);
s8 sbp_decode_sbp_msg_thread_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_thread_state_t *msg);
s8 sbp_send_sbp_msg_thread_state_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_thread_state_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *a, const sbp_msg_thread_state_t *b);


/** State of the UART channel
 *
((m.desc|commentify)))
 */
typedef struct {
  float tx_throughput;
  float rx_throughput;
  u16 crc_error_count;
  u16 io_error_count;
  u8 tx_buffer_level;
  u8 rx_buffer_level;
} sbp_uart_channel_t;

size_t sbp_packed_size_sbp_uart_channel_t(const sbp_uart_channel_t *msg);
s8 sbp_encode_sbp_uart_channel_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_uart_channel_t *msg);
s8 sbp_decode_sbp_uart_channel_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_uart_channel_t *msg);

int sbp_cmp_sbp_uart_channel_t(const sbp_uart_channel_t *a, const sbp_uart_channel_t *b);


/** base station observation message receipt period
 *
((m.desc|commentify)))
 */
typedef struct {
  s32 avg;
  s32 pmin;
  s32 pmax;
  s32 current;
} sbp_period_t;

size_t sbp_packed_size_sbp_period_t(const sbp_period_t *msg);
s8 sbp_encode_sbp_period_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_period_t *msg);
s8 sbp_decode_sbp_period_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_period_t *msg);

int sbp_cmp_sbp_period_t(const sbp_period_t *a, const sbp_period_t *b);


/** Receiver-to-base station latency
 *
((m.desc|commentify)))
 */
typedef struct {
  s32 avg;
  s32 lmin;
  s32 lmax;
  s32 current;
} sbp_latency_t;

size_t sbp_packed_size_sbp_latency_t(const sbp_latency_t *msg);
s8 sbp_encode_sbp_latency_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_latency_t *msg);
s8 sbp_decode_sbp_latency_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_latency_t *msg);

int sbp_cmp_sbp_latency_t(const sbp_latency_t *a, const sbp_latency_t *b);


/** State of the UART channels
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_UART_STATE              0x001D
#endif
typedef struct {
  sbp_uart_channel_t uart_a;
  sbp_uart_channel_t uart_b;
  sbp_uart_channel_t uart_ftdi;
  sbp_latency_t latency;
  sbp_period_t obs_period;
} sbp_msg_uart_state_t;

size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg);
s8 sbp_encode_sbp_msg_uart_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_uart_state_t *msg);
s8 sbp_decode_sbp_msg_uart_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_uart_state_t *msg);
s8 sbp_send_sbp_msg_uart_state_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_uart_state_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *a, const sbp_msg_uart_state_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_UART_STATE_DEPA         0x0018
#endif
typedef struct {
  sbp_uart_channel_t uart_a;
  sbp_uart_channel_t uart_b;
  sbp_uart_channel_t uart_ftdi;
  sbp_latency_t latency;
} sbp_msg_uart_state_depa_t;

size_t sbp_packed_size_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *msg);
s8 sbp_encode_sbp_msg_uart_state_depa_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_uart_state_depa_t *msg);
s8 sbp_decode_sbp_msg_uart_state_depa_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_uart_state_depa_t *msg);
s8 sbp_send_sbp_msg_uart_state_depa_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_uart_state_depa_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *a, const sbp_msg_uart_state_depa_t *b);


/** State of the Integer Ambiguity Resolution (IAR) process
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_IAR_STATE               0x0019
#endif
typedef struct {
  u32 num_hyps;
} sbp_msg_iar_state_t;

size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg);
s8 sbp_encode_sbp_msg_iar_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_iar_state_t *msg);
s8 sbp_decode_sbp_msg_iar_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_iar_state_t *msg);
s8 sbp_send_sbp_msg_iar_state_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_iar_state_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *a, const sbp_msg_iar_state_t *b);


#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT) \
                             & SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)) \
                             << (SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT) \
                             & SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)) \
                             << (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)
#endif
/** Mask a satellite from use in Piksi subsystems
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_MASK_SATELLITE          0x002B
#endif
typedef struct {
  u8 mask;
  sbp_sbp_gnss_signal_t sid;
} sbp_msg_mask_satellite_t;

size_t sbp_packed_size_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *msg);
s8 sbp_encode_sbp_msg_mask_satellite_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_mask_satellite_t *msg);
s8 sbp_decode_sbp_msg_mask_satellite_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_mask_satellite_t *msg);
s8 sbp_send_sbp_msg_mask_satellite_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_mask_satellite_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *a, const sbp_msg_mask_satellite_t *b);


#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)
#endif
/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_MASK_SATELLITE_DEP      0x001B
#endif
typedef struct {
  u8 mask;
  sbp_gnss_signal_dep_t sid;
} sbp_msg_mask_satellite_dep_t;

size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *msg);
s8 sbp_encode_sbp_msg_mask_satellite_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_mask_satellite_dep_t *msg);
s8 sbp_decode_sbp_msg_mask_satellite_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_mask_satellite_dep_t *msg);
s8 sbp_send_sbp_msg_mask_satellite_dep_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_mask_satellite_dep_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *a, const sbp_msg_mask_satellite_dep_t *b);


/** Device temperature and voltage levels
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_DEVICE_MONITOR          0x00B5
#endif
typedef struct {
  s16 dev_vin;
  s16 cpu_vint;
  s16 cpu_vaux;
  s16 cpu_temperature;
  s16 fe_temperature;
} sbp_msg_device_monitor_t;

size_t sbp_packed_size_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *msg);
s8 sbp_encode_sbp_msg_device_monitor_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_device_monitor_t *msg);
s8 sbp_decode_sbp_msg_device_monitor_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_device_monitor_t *msg);
s8 sbp_send_sbp_msg_device_monitor_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_device_monitor_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *a, const sbp_msg_device_monitor_t *b);


/** Execute a command (host => device)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_COMMAND_REQ             0x00B8
#endif
typedef struct {
  u32 sequence;
  sbp_null_terminated_string_t command;
} sbp_msg_command_req_t;
  void sbp_msg_command_req_t_command_init(sbp_null_terminated_string_t *s);
  bool sbp_msg_command_req_t_command_valid(const sbp_null_terminated_string_t *s);
  int sbp_msg_command_req_t_command_strcmp(const sbp_null_terminated_string_t *a, const sbp_null_terminated_string_t *b);
  uint8_t sbp_msg_command_req_t_command_packed_len(const sbp_null_terminated_string_t *s);
  uint8_t sbp_msg_command_req_t_command_space_remaining(const sbp_null_terminated_string_t *s);
  bool sbp_msg_command_req_t_command_set(sbp_null_terminated_string_t *s, const char *new_str);
  bool sbp_msg_command_req_t_command_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_command_req_t_command_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_command_req_t_command_append_printf(sbp_null_terminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_command_req_t_command_append_vprintf(sbp_null_terminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_command_req_t_command_get(const sbp_null_terminated_string_t *s);

size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg);
s8 sbp_encode_sbp_msg_command_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_command_req_t *msg);
s8 sbp_decode_sbp_msg_command_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_command_req_t *msg);
s8 sbp_send_sbp_msg_command_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_command_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_command_req_t(const sbp_msg_command_req_t *a, const sbp_msg_command_req_t *b);


/** Exit code from executed command (device => host)
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_COMMAND_RESP            0x00B9
#endif
typedef struct {
  u32 sequence;
  s32 code;
} sbp_msg_command_resp_t;

size_t sbp_packed_size_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *msg);
s8 sbp_encode_sbp_msg_command_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_command_resp_t *msg);
s8 sbp_decode_sbp_msg_command_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_command_resp_t *msg);
s8 sbp_send_sbp_msg_command_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_command_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *a, const sbp_msg_command_resp_t *b);


/** Command output
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_COMMAND_OUTPUT          0x00BC
#endif
typedef struct {
  u32 sequence;
  sbp_unterminated_string_t line;
} sbp_msg_command_output_t;
  void sbp_msg_command_output_t_line_init(sbp_unterminated_string_t *s);
  bool sbp_msg_command_output_t_line_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_command_output_t_line_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_command_output_t_line_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_command_output_t_line_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_command_output_t_line_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_command_output_t_line_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_command_output_t_line_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_command_output_t_line_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_command_output_t_line_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_command_output_t_line_get(const sbp_unterminated_string_t *s);

size_t sbp_packed_size_sbp_msg_command_output_t(const sbp_msg_command_output_t *msg);
s8 sbp_encode_sbp_msg_command_output_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_command_output_t *msg);
s8 sbp_decode_sbp_msg_command_output_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_command_output_t *msg);
s8 sbp_send_sbp_msg_command_output_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_command_output_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_command_output_t(const sbp_msg_command_output_t *a, const sbp_msg_command_output_t *b);


/** Request state of Piksi network interfaces
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_NETWORK_STATE_REQ       0x00BA
#endif
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_network_state_req_t;

size_t sbp_packed_size_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *msg);
s8 sbp_encode_sbp_msg_network_state_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_network_state_req_t *msg);
s8 sbp_decode_sbp_msg_network_state_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_network_state_req_t *msg);
s8 sbp_send_sbp_msg_network_state_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_network_state_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *a, const sbp_msg_network_state_req_t *b);


#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT (15u)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT (14u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT (13u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT (12u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT (11u)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT (10u)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT (9u)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT (8u)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT (7u)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT (6u)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT (5u)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT (4u)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT (3u)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT (2u)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT (1u)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT (0u)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT)));} while(0)
                             

#endif
/** State of network interface
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_NETWORK_STATE_RESP      0x00BB
#endif
typedef struct {
  u8 ipv4_address[4];
  u8 ipv4_mask_size;
  u8 ipv6_address[16];
  u8 ipv6_mask_size;
  u32 rx_bytes;
  u32 tx_bytes;
  char interface_name[16];
  u32 flags;
} sbp_msg_network_state_resp_t;

size_t sbp_packed_size_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *msg);
s8 sbp_encode_sbp_msg_network_state_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_network_state_resp_t *msg);
s8 sbp_decode_sbp_msg_network_state_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_network_state_resp_t *msg);
s8 sbp_send_sbp_msg_network_state_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_network_state_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *a, const sbp_msg_network_state_resp_t *b);


/** Bandwidth usage measurement for a single interface
 *
((m.desc|commentify)))
 */
typedef struct {
  u64 duration;
  u64 total_bytes;
  u32 rx_bytes;
  u32 tx_bytes;
  char interface_name[16];
} sbp_network_usage_t;

size_t sbp_packed_size_sbp_network_usage_t(const sbp_network_usage_t *msg);
s8 sbp_encode_sbp_network_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_network_usage_t *msg);
s8 sbp_decode_sbp_network_usage_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_network_usage_t *msg);

int sbp_cmp_sbp_network_usage_t(const sbp_network_usage_t *a, const sbp_network_usage_t *b);


/** Bandwidth usage reporting message
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_NETWORK_BANDWIDTH_USAGE 0x00BD
#endif
typedef struct {
  sbp_network_usage_t interfaces[6];
  u8 n_interfaces;
} sbp_msg_network_bandwidth_usage_t;

size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *msg);
s8 sbp_encode_sbp_msg_network_bandwidth_usage_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_network_bandwidth_usage_t *msg);
s8 sbp_decode_sbp_msg_network_bandwidth_usage_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_network_bandwidth_usage_t *msg);
s8 sbp_send_sbp_msg_network_bandwidth_usage_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_network_bandwidth_usage_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *a, const sbp_msg_network_bandwidth_usage_t *b);


/** Cell modem information update message
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_CELL_MODEM_STATUS       0x00BE
#endif
typedef struct {
  s8 signal_strength;
  float signal_error_rate;
  u8 reserved[250];
  u8 n_reserved;
} sbp_msg_cell_modem_status_t;

size_t sbp_packed_size_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *msg);
s8 sbp_encode_sbp_msg_cell_modem_status_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_cell_modem_status_t *msg);
s8 sbp_decode_sbp_msg_cell_modem_status_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_cell_modem_status_t *msg);
s8 sbp_send_sbp_msg_cell_modem_status_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_cell_modem_status_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *a, const sbp_msg_cell_modem_status_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_SPECAN_DEP              0x0050
#endif
typedef struct {
  u16 channel_tag;
  sbp_gps_time_dep_t t;
  float freq_ref;
  float freq_step;
  float amplitude_ref;
  float amplitude_unit;
  u8 amplitude_value[231];
  u8 n_amplitude_value;
} sbp_msg_specan_dep_t;

size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg);
s8 sbp_encode_sbp_msg_specan_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_specan_dep_t *msg);
s8 sbp_decode_sbp_msg_specan_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_specan_dep_t *msg);
s8 sbp_send_sbp_msg_specan_dep_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_specan_dep_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *a, const sbp_msg_specan_dep_t *b);


/** Spectrum analyzer
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_SPECAN                  0x0051
#endif
typedef struct {
  u16 channel_tag;
  sbp_sbp_gps_time_t t;
  float freq_ref;
  float freq_step;
  float amplitude_ref;
  float amplitude_unit;
  u8 amplitude_value[227];
  u8 n_amplitude_value;
} sbp_msg_specan_t;

size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg);
s8 sbp_encode_sbp_msg_specan_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_specan_t *msg);
s8 sbp_decode_sbp_msg_specan_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_specan_t *msg);
s8 sbp_send_sbp_msg_specan_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_specan_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_specan_t(const sbp_msg_specan_t *a, const sbp_msg_specan_t *b);


/** RF AGC status
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_PIKSI_MESSAGES_H
#define SBP_MSG_FRONT_END_GAIN          0x00BF
#endif
typedef struct {
  s8 rf_gain[8];
  s8 if_gain[8];
} sbp_msg_front_end_gain_t;

size_t sbp_packed_size_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *msg);
s8 sbp_encode_sbp_msg_front_end_gain_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_front_end_gain_t *msg);
s8 sbp_decode_sbp_msg_front_end_gain_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_front_end_gain_t *msg);
s8 sbp_send_sbp_msg_front_end_gain_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_front_end_gain_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *a, const sbp_msg_front_end_gain_t *b);



#ifdef __cplusplus
  }
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

#endif /* LIBSBP_NEW_PIKSI_MESSAGES_H */
