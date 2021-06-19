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
#define SBP_MSG_SET_TIME 0x0068
#define SBP_MSG_RESET 0x00B6
#define SBP_RESET_DEFAULT_SETTINGS_MASK (0x1)
#define SBP_RESET_DEFAULT_SETTINGS_SHIFT (0u)
#define SBP_RESET_DEFAULT_SETTINGS_GET(flags)      \
  (((flags) >> SBP_RESET_DEFAULT_SETTINGS_SHIFT) & \
   SBP_RESET_DEFAULT_SETTINGS_MASK)
#define SBP_RESET_DEFAULT_SETTINGS_SET(flags, val)           \
  do {                                                       \
    ((flags) |= (((val) & (SBP_RESET_DEFAULT_SETTINGS_MASK)) \
                 << (SBP_RESET_DEFAULT_SETTINGS_SHIFT)));    \
  } while (0)

#define SBP_RESET_DEFAULT_SETTINGS_PRESERVE_EXISTING_SETTINGS (0)
#define SBP_RESET_DEFAULT_SETTINGS_RESORE_DEFAULT_SETTINGS (1)
#define SBP_MSG_RESET_DEP 0x00B2
#define SBP_MSG_CW_RESULTS 0x00C0
#define SBP_MSG_CW_START 0x00C1
#define SBP_MSG_RESET_FILTERS 0x0022
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK (0x3)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT (0u)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_GET(flags)      \
  (((flags) >> SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT) & \
   SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SET(flags, val)           \
  do {                                                                         \
    ((flags) |= (((val) & (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_MASK)) \
                 << (SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_SHIFT)));    \
  } while (0)

#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_DGNSS_FILTER (0)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_IAR_PROCESS (1)
#define SBP_RESET_FILTERS_FILTER_OR_PROCESS_TO_RESET_INERTIAL_FILTER (2)
#define SBP_MSG_INIT_BASE_DEP 0x0023
#define SBP_MSG_THREAD_STATE 0x0017
#define SBP_MSG_UART_STATE 0x001D
#define SBP_MSG_UART_STATE_DEPA 0x0018
#define SBP_MSG_IAR_STATE 0x0019
#define SBP_MSG_MASK_SATELLITE 0x002B
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_GET(flags)      \
  (((flags) >> SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT) & \
   SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_TRACKING_CHANNELS_MASK)) \
                 << (SBP_MASK_SATELLITE_TRACKING_CHANNELS_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING \
  (1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_GET(flags)      \
  (((flags) >> SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT) & \
   SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SET(flags, val)           \
  do {                                                                   \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_MASK)) \
                 << (SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS \
  (1)
#define SBP_MSG_MASK_SATELLITE_DEP 0x001B
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_GET(flags)      \
  (((flags) >> SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT) & \
   SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_MASK)) \
                 << (SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING \
  (1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_GET(flags)      \
  (((flags) >> SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT) & \
   SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SET(flags, val)           \
  do {                                                                       \
    ((flags) |= (((val) & (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_MASK)) \
                 << (SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SHIFT)));    \
  } while (0)

#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS \
  (1)
#define SBP_MSG_DEVICE_MONITOR 0x00B5
#define SBP_MSG_COMMAND_REQ 0x00B8
#define SBP_MSG_COMMAND_RESP 0x00B9
#define SBP_MSG_COMMAND_OUTPUT 0x00BC
#define SBP_MSG_NETWORK_STATE_REQ 0x00BA
#define SBP_MSG_NETWORK_STATE_RESP 0x00BB
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT (15u)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_GET(flags) \
  (((flags) >>                                                              \
    SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT) &       \
   SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SET(flags,  \
                                                                     val)    \
  do {                                                                       \
    ((flags) |=                                                              \
     (((val) &                                                               \
       (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT (14u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_GET( \
    flags)                                                                \
  (((flags) >>                                                            \
    SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SET(        \
    flags, val)                                                                  \
  do {                                                                           \
    ((flags) |=                                                                  \
     (((val) &                                                                   \
       (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT (13u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_GET( \
    flags)                                                                \
  (((flags) >>                                                            \
    SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SET(        \
    flags, val)                                                                  \
  do {                                                                           \
    ((flags) |=                                                                  \
     (((val) &                                                                   \
       (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT (12u)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_GET( \
    flags)                                                                \
  (((flags) >>                                                            \
    SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SET(        \
    flags, val)                                                                  \
  do {                                                                           \
    ((flags) |=                                                                  \
     (((val) &                                                                   \
       (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT \
  (11u)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_GET( \
    flags)                                                                   \
  (((flags) >>                                                               \
    SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SET(        \
    flags, val)                                                                     \
  do {                                                                              \
    ((flags) |=                                                                     \
     (((val) &                                                                      \
       (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT (10u)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_GET( \
    flags)                                                                \
  (((flags) >>                                                            \
    SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SET(        \
    flags, val)                                                                  \
  do {                                                                           \
    ((flags) |=                                                                  \
     (((val) &                                                                   \
       (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT \
  (9u)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_GET( \
    flags)                                                                      \
  (((flags) >>                                                                  \
    SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SET(        \
    flags, val)                                                                        \
  do {                                                                                 \
    ((flags) |=                                                                        \
     (((val) &                                                                         \
       (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT (8u)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_GET(flags) \
  (((flags) >>                                                             \
    SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT) &       \
   SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)) \
      << (SBP_NETWORK_STATE_RESP_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT)));    \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT \
  (7u)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_GET( \
    flags)                                                                    \
  (((flags) >>                                                                \
    SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SET(        \
    flags, val)                                                                      \
  do {                                                                               \
    ((flags) |=                                                                      \
     (((val) &                                                                       \
       (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT (6u)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_GET(flags) \
  (((flags) >>                                                             \
    SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT) &       \
   SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SET(flags,     \
                                                                    val)       \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)) \
      << (SBP_NETWORK_STATE_RESP_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT)));    \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT (5u)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_GET( \
    flags)                                                                \
  (((flags) >>                                                            \
    SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SET(        \
    flags, val)                                                                  \
  do {                                                                           \
    ((flags) |=                                                                  \
     (((val) &                                                                   \
       (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK \
  (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT \
  (4u)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_GET( \
    flags)                                                                          \
  (((flags) >>                                                                      \
    SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SET(        \
    flags, val)                                                                            \
  do {                                                                                     \
    ((flags) |=                                                                            \
     (((val) &                                                                             \
       (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT (3u)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_GET(flags)      \
  (((flags) >> SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SET(flags, val) \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) & (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK))  \
      << (SBP_NETWORK_STATE_RESP_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT)));     \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT (2u)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_GET(flags) \
  (((flags) >>                                                               \
    SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT) &       \
   SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SET(flags,  \
                                                                      val)    \
  do {                                                                        \
    ((flags) |=                                                               \
     (((val) &                                                                \
       (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT (1u)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_GET( \
    flags)                                                                 \
  (((flags) >>                                                             \
    SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SET(        \
    flags, val)                                                                   \
  do {                                                                            \
    ((flags) |=                                                                   \
     (((val) &                                                                    \
       (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK))      \
      << (SBP_NETWORK_STATE_RESP_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT))); \
  } while (0)

#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT (0u)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_GET(flags)      \
  (((flags) >> SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT) & \
   SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK)
#define SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SET(flags, val) \
  do {                                                                 \
    ((flags) |=                                                        \
     (((val) & (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_MASK))  \
      << (SBP_NETWORK_STATE_RESP_IFF_UP__INTERFACE_IS_UP_SHIFT)));     \
  } while (0)

#define SBP_MSG_NETWORK_BANDWIDTH_USAGE 0x00BD
#define SBP_MSG_CELL_MODEM_STATUS 0x00BE
#define SBP_MSG_SPECAN_DEP 0x0050
#define SBP_MSG_SPECAN 0x0051
#define SBP_MSG_FRONT_END_GAIN 0x00BF

#endif
