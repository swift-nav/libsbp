/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/piksi.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_PIKSI_MACROS_H
#define LIBSBP_PIKSI_MACROS_H

#define SBP_MSG_ALMANAC 0x0069
/**
 * Encoded length of sbp_msg_almanac_t (V4 API) and
 * msg_almanac_t (legacy API)
 */
#define SBP_MSG_ALMANAC_ENCODED_LEN 0u

#define SBP_MSG_SET_TIME 0x0068
/**
 * Encoded length of sbp_msg_set_time_t (V4 API) and
 * msg_set_time_t (legacy API)
 */
#define SBP_MSG_SET_TIME_ENCODED_LEN 0u

#define SBP_MSG_RESET 0x00B6
#define SBP_RESET_DEFAULT_SETTINGS_MASK (0x1)
#define SBP_RESET_DEFAULT_SETTINGS_SHIFT (0u)
#define SBP_RESET_DEFAULT_SETTINGS_GET(flags)            \
  ((u32)(((flags) >> SBP_RESET_DEFAULT_SETTINGS_SHIFT) & \
         SBP_RESET_DEFAULT_SETTINGS_MASK))
#define SBP_RESET_DEFAULT_SETTINGS_SET(flags, val)                         \
  do {                                                                     \
    (flags) = (u32)((flags) | (((val) & (SBP_RESET_DEFAULT_SETTINGS_MASK)) \
                               << (SBP_RESET_DEFAULT_SETTINGS_SHIFT)));    \
  } while (0)

#define SBP_RESET_DEFAULT_SETTINGS_PRESERVE_EXISTING_SETTINGS (0)
#define SBP_RESET_DEFAULT_SETTINGS_RESORE_DEFAULT_SETTINGS (1)
/**
 * Encoded length of sbp_msg_reset_t (V4 API) and
 * msg_reset_t (legacy API)
 */
#define SBP_MSG_RESET_ENCODED_LEN 4u

#define SBP_MSG_RESET_DEP 0x00B2
/**
 * Encoded length of sbp_msg_reset_dep_t (V4 API) and
 * msg_reset_dep_t (legacy API)
 */
#define SBP_MSG_RESET_DEP_ENCODED_LEN 0u

#define SBP_MSG_CW_RESULTS 0x00C0
/**
 * Encoded length of sbp_msg_cw_results_t (V4 API) and
 * msg_cw_results_t (legacy API)
 */
#define SBP_MSG_CW_RESULTS_ENCODED_LEN 0u

#define SBP_MSG_CW_START 0x00C1
/**
 * Encoded length of sbp_msg_cw_start_t (V4 API) and
 * msg_cw_start_t (legacy API)
 */
#define SBP_MSG_CW_START_ENCODED_LEN 0u

#define SBP_MSG_RESET_FILTERS 0x0022
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK (0x3)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT (0u)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_GET(flags)           \
  ((u8)(((flags) >> SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT) & \
        SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK))
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SET(flags, val)        \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) |                                                      \
             (((val) & (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)) \
              << (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT)));    \
  } while (0)

#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_DGNSS_FILTER (0)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_IAR_PROCESS (1)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_INERTIAL_FILTER (2)
/**
 * Encoded length of sbp_msg_reset_filters_t (V4 API) and
 * msg_reset_filters_t (legacy API)
 */
#define SBP_MSG_RESET_FILTERS_ENCODED_LEN 1u

#define SBP_MSG_INIT_BASE_DEP 0x0023
/**
 * Encoded length of sbp_msg_init_base_dep_t (V4 API) and
 * msg_init_base_dep_t (legacy API)
 */
#define SBP_MSG_INIT_BASE_DEP_ENCODED_LEN 0u

#define SBP_MSG_THREAD_STATE 0x0017
/**
 * The maximum number of items that can be stored in
 * sbp_msg_thread_state_t::name (V4 API) or msg_thread_state_t::name (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_THREAD_STATE_NAME_MAX 20u

/**
 * Encoded length of sbp_msg_thread_state_t (V4 API) and
 * msg_thread_state_t (legacy API)
 */
#define SBP_MSG_THREAD_STATE_ENCODED_LEN 26u

/**
 * Encoded length of sbp_uart_channel_t (V4 API) and
 * uart_channel_t (legacy API)
 */
#define SBP_UART_CHANNEL_ENCODED_LEN 14u

/**
 * Encoded length of sbp_period_t (V4 API) and
 * period_t (legacy API)
 */
#define SBP_PERIOD_ENCODED_LEN 16u

/**
 * Encoded length of sbp_latency_t (V4 API) and
 * latency_t (legacy API)
 */
#define SBP_LATENCY_ENCODED_LEN 16u

#define SBP_MSG_UART_STATE 0x001D
/**
 * Encoded length of sbp_msg_uart_state_t (V4 API) and
 * msg_uart_state_t (legacy API)
 */
#define SBP_MSG_UART_STATE_ENCODED_LEN 74u

#define SBP_MSG_UART_STATE_DEPA 0x0018
/**
 * Encoded length of sbp_msg_uart_state_depa_t (V4 API) and
 * msg_uart_state_depa_t (legacy API)
 */
#define SBP_MSG_UART_STATE_DEPA_ENCODED_LEN 58u

#define SBP_MSG_IAR_STATE 0x0019
/**
 * Encoded length of sbp_msg_iar_state_t (V4 API) and
 * msg_iar_state_t (legacy API)
 */
#define SBP_MSG_IAR_STATE_ENCODED_LEN 4u

#define SBP_MSG_MASK_SATELLITE 0x002B
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_GET(flags)           \
  ((u8)(((flags) >> SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT) & \
        SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK))
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SET(flags, val)                  \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) | (((val) & (SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)) \
                        << (SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING \
  (1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_GET(flags)           \
  ((u8)(((flags) >> SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT) & \
        SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK))
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SET(flags, val)              \
  do {                                                                      \
    (flags) = (u8)((flags) |                                                \
                   (((val) & (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)) \
                    << (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS \
  (1)
/**
 * Encoded length of sbp_msg_mask_satellite_t (V4 API) and
 * msg_mask_satellite_t (legacy API)
 */
#define SBP_MSG_MASK_SATELLITE_ENCODED_LEN 3u

#define SBP_MSG_MASK_SATELLITE_DEP 0x001B
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_GET(flags)           \
  ((u8)(((flags) >> SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT) & \
        SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK))
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SET(flags, val)              \
  do {                                                                        \
    (flags) = (u8)((flags) |                                                  \
                   (((val) & (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)) \
                    << (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING \
  (1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_GET(flags)           \
  ((u8)(((flags) >> SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT) & \
        SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK))
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SET(flags, val)             \
  do {                                                                         \
    (flags) = (u8)(                                                            \
        (flags) | (((val) & (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)) \
                   << (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS \
  (1)
/**
 * Encoded length of sbp_msg_mask_satellite_dep_t (V4 API) and
 * msg_mask_satellite_dep_t (legacy API)
 */
#define SBP_MSG_MASK_SATELLITE_DEP_ENCODED_LEN 5u

#define SBP_MSG_DEVICE_MONITOR 0x00B5
/**
 * Encoded length of sbp_msg_device_monitor_t (V4 API) and
 * msg_device_monitor_t (legacy API)
 */
#define SBP_MSG_DEVICE_MONITOR_ENCODED_LEN 10u

#define SBP_MSG_COMMAND_REQ 0x00B8
/**
 * The maximum number of items that can be stored in
 * sbp_msg_command_req_t::command (V4 API) or msg_command_req_t::command (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_COMMAND_REQ_COMMAND_MAX 251u

/**
 * Encoded length of sbp_msg_command_req_t (V4 API) and
 * msg_command_req_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_command_req_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_COMMAND_REQ_ENCODED_OVERHEAD 4u

#define SBP_MSG_COMMAND_RESP 0x00B9
/**
 * Encoded length of sbp_msg_command_resp_t (V4 API) and
 * msg_command_resp_t (legacy API)
 */
#define SBP_MSG_COMMAND_RESP_ENCODED_LEN 8u

#define SBP_MSG_COMMAND_OUTPUT 0x00BC
/**
 * The maximum number of items that can be stored in
 * sbp_msg_command_output_t::line (V4 API) or msg_command_output_t::line (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_COMMAND_OUTPUT_LINE_MAX 251u

/**
 * Encoded length of sbp_msg_command_output_t (V4 API) and
 * msg_command_output_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_command_output_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_COMMAND_OUTPUT_ENCODED_OVERHEAD 4u

#define SBP_MSG_NETWORK_STATE_REQ 0x00BA
/**
 * Encoded length of sbp_msg_network_state_req_t (V4 API) and
 * msg_network_state_req_t (legacy API)
 */
#define SBP_MSG_NETWORK_STATE_REQ_ENCODED_LEN 0u

#define SBP_MSG_NETWORK_STATE_RESP 0x00BB
/**
 * The maximum number of items that can be stored in
 * sbp_msg_network_state_resp_t::ipv4_address (V4 API) or
 * msg_network_state_resp_t::ipv4_address (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_NETWORK_STATE_RESP_IPV4_ADDRESS_MAX 4u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_network_state_resp_t::ipv6_address (V4 API) or
 * msg_network_state_resp_t::ipv6_address (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_NETWORK_STATE_RESP_IPV6_ADDRESS_MAX 16u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_network_state_resp_t::interface_name (V4 API) or
 * msg_network_state_resp_t::interface_name (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_NETWORK_STATE_RESP_INTERFACE_NAME_MAX 16u

#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT (15u)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_GET(flags) \
  ((u32)(((flags) >>                                                        \
          SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT) & \
         SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SET(flags,     \
                                                                     val)       \
  do {                                                                          \
    (flags) = (u32)(                                                            \
        (flags) |                                                               \
        (((val) &                                                               \
          (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT (14u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_GET(    \
    flags)                                                                   \
  ((u32)(                                                                    \
      ((flags) >>                                                            \
       SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SET(           \
    flags, val)                                                                     \
  do {                                                                              \
    (flags) = (u32)(                                                                \
        (flags) |                                                                   \
        (((val) &                                                                   \
          (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT (13u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_GET(    \
    flags)                                                                   \
  ((u32)(                                                                    \
      ((flags) >>                                                            \
       SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SET(           \
    flags, val)                                                                     \
  do {                                                                              \
    (flags) = (u32)(                                                                \
        (flags) |                                                                   \
        (((val) &                                                                   \
          (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT (12u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_GET(    \
    flags)                                                                   \
  ((u32)(                                                                    \
      ((flags) >>                                                            \
       SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SET(           \
    flags, val)                                                                     \
  do {                                                                              \
    (flags) = (u32)(                                                                \
        (flags) |                                                                   \
        (((val) &                                                                   \
          (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT \
  (11u)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_GET(    \
    flags)                                                                      \
  ((u32)(                                                                       \
      ((flags) >>                                                               \
       SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SET(           \
    flags, val)                                                                        \
  do {                                                                                 \
    (flags) = (u32)(                                                                   \
        (flags) |                                                                      \
        (((val) &                                                                      \
          (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT (10u)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_GET(    \
    flags)                                                                   \
  ((u32)(                                                                    \
      ((flags) >>                                                            \
       SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SET(           \
    flags, val)                                                                     \
  do {                                                                              \
    (flags) = (u32)(                                                                \
        (flags) |                                                                   \
        (((val) &                                                                   \
          (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT \
  (9u)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_GET(    \
    flags)                                                                         \
  ((u32)(                                                                          \
      ((flags) >>                                                                  \
       SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SET(           \
    flags, val)                                                                           \
  do {                                                                                    \
    (flags) = (u32)(                                                                      \
        (flags) |                                                                         \
        (((val) &                                                                         \
          (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT (8u)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_GET(flags) \
  ((u32)(((flags) >>                                                       \
          SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT) & \
         SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    (flags) = (u32)(                                                           \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT \
  (7u)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_GET(    \
    flags)                                                                       \
  ((u32)(                                                                        \
      ((flags) >>                                                                \
       SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SET(           \
    flags, val)                                                                         \
  do {                                                                                  \
    (flags) = (u32)(                                                                    \
        (flags) |                                                                       \
        (((val) &                                                                       \
          (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT (6u)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_GET(flags) \
  ((u32)(((flags) >>                                                       \
          SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT) & \
         SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    (flags) = (u32)(                                                           \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT (5u)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_GET(    \
    flags)                                                                   \
  ((u32)(                                                                    \
      ((flags) >>                                                            \
       SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SET(           \
    flags, val)                                                                     \
  do {                                                                              \
    (flags) = (u32)(                                                                \
        (flags) |                                                                   \
        (((val) &                                                                   \
          (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT \
  (4u)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_GET(    \
    flags)                                                                             \
  ((u32)(                                                                              \
      ((flags) >>                                                                      \
       SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SET(           \
    flags, val)                                                                               \
  do {                                                                                        \
    (flags) = (u32)(                                                                          \
        (flags) |                                                                             \
        (((val) &                                                                             \
          (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT (3u)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_GET(flags) \
  ((u32)(((flags) >>                                                      \
          SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT) & \
         SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SET(flags, val) \
  do {                                                                         \
    (flags) = (u32)(                                                           \
        (flags) |                                                              \
        (((val) &                                                              \
          (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK))       \
         << (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT)));  \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT (2u)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_GET(flags) \
  ((u32)(((flags) >>                                                         \
          SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT) & \
         SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SET(flags,     \
                                                                      val)       \
  do {                                                                           \
    (flags) = (u32)(                                                             \
        (flags) |                                                                \
        (((val) &                                                                \
          (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT (1u)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_GET(    \
    flags)                                                                    \
  ((u32)(                                                                     \
      ((flags) >>                                                             \
       SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT) & \
      SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SET(           \
    flags, val)                                                                      \
  do {                                                                               \
    (flags) = (u32)(                                                                 \
        (flags) |                                                                    \
        (((val) &                                                                    \
          (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK))      \
         << (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT (0u)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_GET(flags)            \
  ((u32)(((flags) >> SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT) & \
         SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK))
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SET(flags, val)         \
  do {                                                                         \
    (flags) =                                                                  \
        (u32)((flags) |                                                        \
              (((val) & (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK)) \
               << (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT)));    \
  } while (0)

/**
 * Encoded length of sbp_msg_network_state_resp_t (V4 API) and
 * msg_network_state_resp_t (legacy API)
 */
#define SBP_MSG_NETWORK_STATE_RESP_ENCODED_LEN 50u

/**
 * The maximum number of items that can be stored in
 * sbp_network_usage_t::interface_name (V4 API) or
 * network_usage_t::interface_name (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_NETWORK_USAGE_INTERFACE_NAME_MAX 16u

/**
 * Encoded length of sbp_network_usage_t (V4 API) and
 * network_usage_t (legacy API)
 */
#define SBP_NETWORK_USAGE_ENCODED_LEN 40u

#define SBP_MSG_NETWORK_BANDWIDTH_USAGE 0x00BD
/**
 * The maximum number of items that can be stored in
 * sbp_msg_network_bandwidth_usage_t::interfaces (V4 API) or
 * msg_network_bandwidth_usage_t::interfaces (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_NETWORK_BANDWIDTH_USAGE_INTERFACES_MAX 6u

/**
 * Encoded length of sbp_msg_network_bandwidth_usage_t (V4 API) and
 * msg_network_bandwidth_usage_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_network_bandwidth_usage_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_NETWORK_BANDWIDTH_USAGE_ENCODED_OVERHEAD 0u

#define SBP_MSG_CELL_MODEM_STATUS 0x00BE
/**
 * The maximum number of items that can be stored in
 * sbp_msg_cell_modem_status_t::reserved (V4 API) or
 * msg_cell_modem_status_t::reserved (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_CELL_MODEM_STATUS_RESERVED_MAX 250u

/**
 * Encoded length of sbp_msg_cell_modem_status_t (V4 API) and
 * msg_cell_modem_status_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_cell_modem_status_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_CELL_MODEM_STATUS_ENCODED_OVERHEAD 5u

#define SBP_MSG_SPECAN_DEP 0x0050
/**
 * The maximum number of items that can be stored in
 * sbp_msg_specan_dep_t::amplitude_value (V4 API) or
 * msg_specan_dep_t::amplitude_value (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SPECAN_DEP_AMPLITUDE_VALUE_MAX 231u

/**
 * Encoded length of sbp_msg_specan_dep_t (V4 API) and
 * msg_specan_dep_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_specan_dep_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SPECAN_DEP_ENCODED_OVERHEAD 24u

#define SBP_MSG_SPECAN 0x0051
/**
 * The maximum number of items that can be stored in
 * sbp_msg_specan_t::amplitude_value (V4 API) or msg_specan_t::amplitude_value
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_SPECAN_AMPLITUDE_VALUE_MAX 227u

/**
 * Encoded length of sbp_msg_specan_t (V4 API) and
 * msg_specan_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_specan_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SPECAN_ENCODED_OVERHEAD 28u

#define SBP_MSG_FRONT_END_GAIN 0x00BF
/**
 * The maximum number of items that can be stored in
 * sbp_msg_front_end_gain_t::rf_gain (V4 API) or msg_front_end_gain_t::rf_gain
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_FRONT_END_GAIN_RF_GAIN_MAX 8u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_front_end_gain_t::if_gain (V4 API) or msg_front_end_gain_t::if_gain
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_FRONT_END_GAIN_IF_GAIN_MAX 8u

/**
 * Encoded length of sbp_msg_front_end_gain_t (V4 API) and
 * msg_front_end_gain_t (legacy API)
 */
#define SBP_MSG_FRONT_END_GAIN_ENCODED_LEN 16u

#endif /* LIBSBP_PIKSI_MACROS_H */
