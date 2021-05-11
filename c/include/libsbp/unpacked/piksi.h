#ifndef LIBSBP_PIKSI_MESSAGES_H
#define LIBSBP_PIKSI_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
#include <libsbp/unpacked/gnss.h>
/** Legacy message to load satellite almanac (host => Piksi)
 *
 * This is a legacy message for sending and loading a satellite
 * alamanac onto the Piksi's flash memory from the host.
 */
#define SBP_MSG_ALMANAC 0x0069

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_almanac_t;

/** Send GPS time from host (host => Piksi)
 *
 * This message sets up timing functionality using a coarse GPS
 * time estimate sent by the host.
 */
#define SBP_MSG_SET_TIME 0x0068

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_set_time_t;

/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the
 * bootloader.
 */
#define SBP_MSG_RESET 0x00B6

#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_MASK (0x1)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_SHIFT (0u)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_GET(flags) \
  (((flags) >> SBP_RESET_FLAGS_DEFAULT_SETTINGS_SHIFT) & SBP_RESET_FLAGS_DEFAULT_SETTINGS_MASK)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_RESET_FLAGS_DEFAULT_SETTINGS_MASK)) << (SBP_RESET_FLAGS_DEFAULT_SETTINGS_SHIFT))); \
  } while (0)

#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_PRESERVE_EXISTING_SETTINGS (0)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_RESORE_DEFAULT_SETTINGS (1)
typedef struct
{

  /**
   * Reset flags
   */
  u32 flags;
} sbp_msg_reset_t;

/** Reset the device (host => Piksi)
 *
 * This message from the host resets the Piksi back into the
 * bootloader.
 */
#define SBP_MSG_RESET_DEP 0x00B2

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_reset_dep_t;

/** Legacy message for CW interference channel (Piksi => host)
 *
 * This is an unused legacy message for result reporting from the
 * CW interference channel on the SwiftNAP. This message will be
 * removed in a future release.
 */
#define SBP_MSG_CW_RESULTS 0x00C0

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_cw_results_t;

/** Legacy message for CW interference channel (host => Piksi)
 *
 * This is an unused legacy message from the host for starting
 * the CW interference channel on the SwiftNAP. This message will
 * be removed in a future release.
 */
#define SBP_MSG_CW_START 0x00C1

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_cw_start_t;

/** Reset IAR filters (host => Piksi)
 *
 * This message resets either the DGNSS Kalman filters or Integer
 * Ambiguity Resolution (IAR) process.
 */
#define SBP_MSG_RESET_FILTERS 0x0022

#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_MASK (0x3)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SHIFT (0u)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_GET(flags) \
  (((flags) >> SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SHIFT) & \
   SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_MASK)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_MASK)) \
                 << (SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SHIFT))); \
  } while (0)

#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_DGNSS_FILTER (0)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_IAR_PROCESS (1)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_INERTIAL_FILTER (2)
typedef struct
{

  /**
   * Filter flags
   */
  u8 filter;
} sbp_msg_reset_filters_t;

/** Deprecated
 *
 * Deprecated
 */
#define SBP_MSG_INIT_BASE_DEP 0x0023

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_init_base_dep_t;

/** State of an RTOS thread
 *
 * The thread usage message from the device reports real-time
 * operating system (RTOS) thread usage statistics for the named
 * thread. The reported percentage values must be normalized.
 */
#define SBP_MSG_THREAD_STATE 0x0017

typedef struct
{

  /**
   * Thread name (NULL terminated)
   */
  char name[20];
  /**
   * Percentage cpu use for this thread. Values range from 0
   * - 1000 and needs to be renormalized to 100
   */
  u16 cpu;
  /**
   * Free stack space for this thread[bytes]
   */
  u32 stack_free;
} sbp_msg_thread_state_t;

/** State of the UART channel
 *
 * Throughput, utilization, and error counts on the RX/TX buffers
 * of this UART channel. The reported percentage values must
 * be normalized.
 */

typedef struct
{

  /**
   * UART transmit throughput[kB/s]
   */
  float tx_throughput;
  /**
   * UART receive throughput[kB/s]
   */
  float rx_throughput;
  /**
   * UART CRC error count
   */
  u16 crc_error_count;
  /**
   * UART IO error count
   */
  u16 io_error_count;
  /**
   * UART transmit buffer percentage utilization (ranges from
   * 0 to 255)
   */
  u8 tx_buffer_level;
  /**
   * UART receive buffer percentage utilization (ranges from
   * 0 to 255)
   */
  u8 rx_buffer_level;
} sbp_uart_channel_t;

/** base station observation message receipt period
 *
 * Statistics on the period of observations received from the base
 * station. As complete observation sets are received, their time
 * of reception is compared with the prior set''s time of reception.
 * This measurement provides a proxy for link quality as incomplete
 * or missing sets will increase the period.  Long periods
 * can cause momentary RTK solution outages.
 */

typedef struct
{

  /**
   * Average period[ms]
   */
  s32 avg;
  /**
   * Minimum period[ms]
   */
  s32 pmin;
  /**
   * Maximum period[ms]
   */
  s32 pmax;
  /**
   * Smoothed estimate of the current period[ms]
   */
  s32 current;
} sbp_period_t;

/** Receiver-to-base station latency
 *
 * Statistics on the latency of observations received from the base
 * station. As observation packets are received their GPS time is
 * compared to the current GPS time calculated locally by the
 * receiver to give a precise measurement of the end-to-end
 * communication latency in the system.
 */

typedef struct
{

  /**
   * Average latency[ms]
   */
  s32 avg;
  /**
   * Minimum latency[ms]
   */
  s32 lmin;
  /**
   * Maximum latency[ms]
   */
  s32 lmax;
  /**
   * Smoothed estimate of the current latency[ms]
   */
  s32 current;
} sbp_latency_t;

/** State of the UART channels
 *
 * The UART message reports data latency and throughput of the UART
 * channels providing SBP I/O. On the default Piksi configuration,
 * UARTs A and B are used for telemetry radios, but can also be
 * host access ports for embedded hosts, or other interfaces in
 * future. The reported percentage values must be normalized.
 * Observations latency and period can be used to assess the
 * health of the differential corrections link. Latency provides
 * the timeliness of received base observations while the
 * period indicates their likelihood of transmission.
 */
#define SBP_MSG_UART_STATE 0x001D

typedef struct
{

  /**
   * State of UART A
   */
  sbp_uart_channel_t uart_a;
  /**
   * State of UART B
   */
  sbp_uart_channel_t uart_b;
  /**
   * State of UART FTDI (USB logger)
   */
  sbp_uart_channel_t uart_ftdi;
  /**
   * UART communication latency
   */
  sbp_latency_t latency;
  /**
   * Observation receipt period
   */
  sbp_period_t obs_period;
} sbp_msg_uart_state_t;

/** Deprecated
 *
 * Deprecated
 */
#define SBP_MSG_UART_STATE_DEPA 0x0018

typedef struct
{

  /**
   * State of UART A
   */
  sbp_uart_channel_t uart_a;
  /**
   * State of UART B
   */
  sbp_uart_channel_t uart_b;
  /**
   * State of UART FTDI (USB logger)
   */
  sbp_uart_channel_t uart_ftdi;
  /**
   * UART communication latency
   */
  sbp_latency_t latency;
} sbp_msg_uart_state_depa_t;

/** State of the Integer Ambiguity Resolution (IAR) process
 *
 * This message reports the state of the Integer Ambiguity
 * Resolution (IAR) process, which resolves unknown integer
 * ambiguities from double-differenced carrier-phase measurements
 * from satellite observations.
 */
#define SBP_MSG_IAR_STATE 0x0019

typedef struct
{

  /**
   * Number of integer ambiguity hypotheses remaining
   */
  u32 num_hyps;
} sbp_msg_iar_state_t;

/** Mask a satellite from use in Piksi subsystems
 *
 * This message allows setting a mask to prevent a particular satellite
 * from being used in various Piksi subsystems.
 */
#define SBP_MSG_MASK_SATELLITE 0x002B

#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_GET(flags) \
  (((flags) >> SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SHIFT) & SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_MASK)) \
                 << (SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SHIFT))); \
  } while (0)

#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_GET(flags) \
  (((flags) >> SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SHIFT) & SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_MASK)) \
                 << (SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SHIFT))); \
  } while (0)

#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)

#define SBP_MASK_SATELLITE_SID_CODE__MASK (0xff)
#define SBP_MASK_SATELLITE_SID_CODE__SHIFT (0u)
#define SBP_MASK_SATELLITE_SID_CODE__GET(flags) \
  (((flags) >> SBP_MASK_SATELLITE_SID_CODE__SHIFT) & SBP_MASK_SATELLITE_SID_CODE__MASK)
#define SBP_MASK_SATELLITE_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_SID_CODE__MASK)) << (SBP_MASK_SATELLITE_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_MASK_SATELLITE_SID_CODE__GPS_L1CA (0)
#define SBP_MASK_SATELLITE_SID_CODE__GPS_L2CM (1)
#define SBP_MASK_SATELLITE_SID_CODE__SBAS_L1CA (2)
#define SBP_MASK_SATELLITE_SID_CODE__GLO_L1CA (3)
#define SBP_MASK_SATELLITE_SID_CODE__GLO_L2CA (4)
#define SBP_MASK_SATELLITE_SID_CODE__GPS_L1P (5)
#define SBP_MASK_SATELLITE_SID_CODE__GPS_L2P (6)
#define SBP_MASK_SATELLITE_SID_CODE__BDS2_B1 (12)
#define SBP_MASK_SATELLITE_SID_CODE__BDS2_B2 (13)
#define SBP_MASK_SATELLITE_SID_CODE__GAL_E1B (14)
#define SBP_MASK_SATELLITE_SID_CODE__GAL_E7I (20)
#define SBP_MASK_SATELLITE_SID_CODE__BDS3_B2A (47)
typedef struct
{

  /**
   * Mask of systems that should ignore this satellite.
   */
  u8 mask;
  /**
   * GNSS signal for which the mask is applied
   */
  sbp_sbp_gnss_signal_t sid;
} sbp_msg_mask_satellite_t;

/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_MASK_SATELLITE_DEP 0x001B

#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_GET(flags) \
  (((flags) >> SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SHIFT) & \
   SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_MASK)) \
                 << (SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SHIFT))); \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_GET(flags) \
  (((flags) >> SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SHIFT) & \
   SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_MASK)) \
                 << (SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SHIFT))); \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)

#define SBP_MASK_SATELLITE_DEP_SID_CODE__MASK (0xff)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GET(flags) \
  (((flags) >> SBP_MASK_SATELLITE_DEP_SID_CODE__SHIFT) & SBP_MASK_SATELLITE_DEP_SID_CODE__MASK)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_DEP_SID_CODE__MASK)) << (SBP_MASK_SATELLITE_DEP_SID_CODE__SHIFT))); \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L1CA (0)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L2CM (1)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__SBAS_L1CA (2)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GLO_L1CA (3)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GLO_L2CA (4)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L1P (5)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L2P (6)
typedef struct
{

  /**
   * Mask of systems that should ignore this satellite.
   */
  u8 mask;
  /**
   * GNSS signal for which the mask is applied
   */
  sbp_gnss_signal_dep_t sid;
} sbp_msg_mask_satellite_dep_t;

/** Device temperature and voltage levels
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if
 * available.
 */
#define SBP_MSG_DEVICE_MONITOR 0x00B5

typedef struct
{

  /**
   * Device V_in[V / 1000]
   */
  s16 dev_vin;
  /**
   * Processor V_int[V / 1000]
   */
  s16 cpu_vint;
  /**
   * Processor V_aux[V / 1000]
   */
  s16 cpu_vaux;
  /**
   * Processor temperature[degrees C / 100]
   */
  s16 cpu_temperature;
  /**
   * Frontend temperature (if available)[degrees C / 100]
   */
  s16 fe_temperature;
} sbp_msg_device_monitor_t;

/** Execute a command (host => device)
 *
 * Request the recipient to execute an command.
 * Output will be sent in MSG_LOG messages, and the exit
 * code will be returned with MSG_COMMAND_RESP.
 */
#define SBP_MSG_COMMAND_REQ 0x00B8

typedef struct
{

  /**
   * Sequence number
   */
  u32 sequence;
  /**
   * Command line to execute
   */
  sbp_null_terminated_string_t command;
} sbp_msg_command_req_t;

#define sbp_msg_command_req_t_command_init(f) sbp_null_terminated_string_init(f, 251)
#define sbp_msg_command_req_t_command_set(f, s) sbp_null_terminated_string_set(f, s, 251)
#define sbp_msg_command_req_t_command_printf(f, ...) sbp_null_terminated_string_printf(f, 251, __VA_ARGS__)
#define sbp_msg_command_req_t_command_packed_len(f) sbp_null_terminated_string_packed_len(f, 251)
#define sbp_msg_command_req_t_command_get(f) sbp_null_terminated_string_get(f, 251)
#define sbp_msg_command_req_t_command_len(f) (sbp_msg_command_req_t_command_packed_len(f) - 1)
#define sbp_msg_command_req_t_command_strcmp(a, b) sbp_null_terminated_string_strcmp(a, b, 251)
/** Exit code from executed command (device => host)
 *
 * The response to MSG_COMMAND_REQ with the return code of
 * the command.  A return code of zero indicates success.
 */
#define SBP_MSG_COMMAND_RESP 0x00B9

typedef struct
{

  /**
   * Sequence number
   */
  u32 sequence;
  /**
   * Exit code
   */
  s32 code;
} sbp_msg_command_resp_t;

/** Command output
 *
 * Returns the standard output and standard error of the
 * command requested by MSG_COMMAND_REQ.
 * The sequence number can be used to filter for filtering
 * the correct command.
 */
#define SBP_MSG_COMMAND_OUTPUT 0x00BC

typedef struct
{

  /**
   * Sequence number
   */
  u32 sequence;
  /**
   * Line of standard output or standard error
   */
  sbp_unterminated_string_t line;
} sbp_msg_command_output_t;

#define sbp_msg_command_output_t_line_init(f) sbp_unterminated_string_init(f, 251)
#define sbp_msg_command_output_t_line_set(f, s) sbp_unterminated_string_set(f, s, 251)
#define sbp_msg_command_output_t_line_printf(f, ...) sbp_unterminated_string_printf(f, 251, __VA_ARGS__)
#define sbp_msg_command_output_t_line_packed_len(f) sbp_unterminated_string_packed_len(f, 251)
#define sbp_msg_command_output_t_line_get(f) sbp_unterminated_string_get(f, 251)
#define sbp_msg_command_output_t_line_len(f) (sbp_msg_command_output_t_line_packed_len(f))
#define sbp_msg_command_output_t_line_strcmp(a, b) sbp_unterminated_string_strcmp(a, b, 251)
/** Request state of Piksi network interfaces
 *
 * Request state of Piksi network interfaces.
 * Output will be sent in MSG_NETWORK_STATE_RESP messages
 */
#define SBP_MSG_NETWORK_STATE_REQ 0x00BA

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_network_state_req_t;

/** State of network interface
 *
 * The state of a network interface on the Piksi.
 * Data is made to reflect output of ifaddrs struct returned by getifaddrs
 * in c.
 */
#define SBP_MSG_NETWORK_STATE_RESP 0x00BB

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT (15u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT (14u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT (13u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT (12u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT (11u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT (10u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT (9u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT (8u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT (7u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT (6u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT (5u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT (4u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT (3u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT (2u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT (1u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SHIFT (0u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_GET(flags) \
  (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SHIFT) & \
   SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_MASK)) \
                 << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SHIFT))); \
  } while (0)

typedef struct
{

  /**
   * IPv4 address (all zero when unavailable)
   */
  u8 ipv4_address[4];
  /**
   * IPv4 netmask CIDR notation
   */
  u8 ipv4_mask_size;
  /**
   * IPv6 address (all zero when unavailable)
   */
  u8 ipv6_address[16];
  /**
   * IPv6 netmask CIDR notation
   */
  u8 ipv6_mask_size;
  /**
   * Number of Rx bytes
   */
  u32 rx_bytes;
  /**
   * Number of Tx bytes
   */
  u32 tx_bytes;
  /**
   * Interface Name
   */
  char interface_name[16];
  /**
   * Interface flags from SIOCGIFFLAGS
   */
  u32 flags;
} sbp_msg_network_state_resp_t;

/** Bandwidth usage measurement for a single interface.
 *
 * The bandwidth usage for each interface can be reported
 * within this struct and utilize multiple fields to fully
 * specify the type of traffic that is being tracked. As
 * either the interval of collection or the collection time
 * may vary, both a timestamp and period field is provided,
 * though may not necessarily be populated with a value.
 */

typedef struct
{

  /**
   * Duration over which the measurement was collected[ms]
   */
  u64 duration;
  /**
   * Number of bytes handled in total within period
   */
  u64 total_bytes;
  /**
   * Number of bytes transmitted within period
   */
  u32 rx_bytes;
  /**
   * Number of bytes received within period
   */
  u32 tx_bytes;
  /**
   * Interface Name
   */
  char interface_name[16];
} sbp_network_usage_t;

/** Bandwidth usage reporting message
 *
 * The bandwidth usage, a list of usage by interface.
 */
#define SBP_MSG_NETWORK_BANDWIDTH_USAGE 0x00BD

typedef struct
{

  /**
   * Usage measurement array
   */
  sbp_network_usage_t interfaces[6];
  /**
   * Number of items in interfaces
   */
  u8 interfaces_count;
} sbp_msg_network_bandwidth_usage_t;

/** Cell modem information update message
 *
 * If a cell modem is present on a piksi device, this message
 * will be send periodically to update the host on the status
 * of the modem and its various parameters.
 */
#define SBP_MSG_CELL_MODEM_STATUS 0x00BE

typedef struct
{

  /**
   * Received cell signal strength in dBm, zero translates to unknown[dBm]
   */
  s8 signal_strength;
  /**
   * BER as reported by the modem, zero translates to unknown
   */
  float signal_error_rate;
  /**
   * Unspecified data TBD for this schema
   */
  u8 reserved[250];
  /**
   * Number of items in reserved
   */
  u8 reserved_count;
} sbp_msg_cell_modem_status_t;

/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_SPECAN_DEP 0x0050

typedef struct
{

  /**
   * Channel ID
   */
  u16 channel_tag;
  /**
   * Receiver time of this observation
   */
  sbp_gps_time_dep_t t;
  /**
   * Reference frequency of this packet[MHz]
   */
  float freq_ref;
  /**
   * Frequency step of points in this packet[MHz]
   */
  float freq_step;
  /**
   * Reference amplitude of this packet[dB]
   */
  float amplitude_ref;
  /**
   * Amplitude unit value of points in this packet[dB]
   */
  float amplitude_unit;
  /**
   * Amplitude values (in the above units) of points in this packet
   */
  u8 amplitude_value[231];
  /**
   * Number of items in amplitude_value
   */
  u8 amplitude_value_count;
} sbp_msg_specan_dep_t;

/** Spectrum analyzer
 *
 * Spectrum analyzer packet.
 */
#define SBP_MSG_SPECAN 0x0051

typedef struct
{

  /**
   * Channel ID
   */
  u16 channel_tag;
  /**
   * Receiver time of this observation
   */
  sbp_sbp_gps_time_t t;
  /**
   * Reference frequency of this packet[MHz]
   */
  float freq_ref;
  /**
   * Frequency step of points in this packet[MHz]
   */
  float freq_step;
  /**
   * Reference amplitude of this packet[dB]
   */
  float amplitude_ref;
  /**
   * Amplitude unit value of points in this packet[dB]
   */
  float amplitude_unit;
  /**
   * Amplitude values (in the above units) of points in this packet
   */
  u8 amplitude_value[227];
  /**
   * Number of items in amplitude_value
   */
  u8 amplitude_value_count;
} sbp_msg_specan_t;

/** RF AGC status
 *
 * This message describes the gain of each channel in the receiver frontend. Each
 * gain is encoded as a non-dimensional percentage relative to the maximum range
 * possible for the gain stage of the frontend. By convention, each gain array
 * has 8 entries and the index of the array corresponding to the index of the rf channel
 * in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
 * A negative value implies an error for the particular gain stage as reported by the frontend.
 */
#define SBP_MSG_FRONT_END_GAIN 0x00BF

typedef struct
{

  /**
   * RF gain for each frontend channel[percent]
   */
  s8 rf_gain[8];
  /**
   * Intermediate frequency gain for each frontend channel[percent]
   */
  s8 if_gain[8];
} sbp_msg_front_end_gain_t;

#include <libsbp/unpacked/piksi_operators.h>
#include <libsbp/unpacked/piksi_packers.h>

#endif /* LIBSBP_PIKSI_MESSAGES_H */
