/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_BOOTLOAD_MACROS_H
#define LIBSBP_BOOTLOAD_MACROS_H

/**
 * Encoded length of sbp_msg_bootloader_handshake_req_t
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_REQ_ENCODED_LEN 0u

#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK \
  (0xffu)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT \
  (8u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(       \
    flags)                                                                         \
  ((u32)(                                                                          \
      (u32)(                                                                       \
          (flags) >>                                                               \
          SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
      SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK))
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(              \
    flags, val)                                                                           \
  do {                                                                                    \
    (flags) = (u32)(                                                                      \
        (flags &                                                                          \
         (~(SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK          \
            << SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))) | \
        (((val) &                                                                         \
          (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK))         \
         << (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));    \
  } while (0)

#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK \
  (0xffu)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT \
  (0u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(       \
    flags)                                                                         \
  ((u32)(                                                                          \
      (u32)(                                                                       \
          (flags) >>                                                               \
          SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
      SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK))
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(              \
    flags, val)                                                                           \
  do {                                                                                    \
    (flags) = (u32)(                                                                      \
        (flags &                                                                          \
         (~(SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK          \
            << SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))) | \
        (((val) &                                                                         \
          (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK))         \
         << (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));    \
  } while (0)

/**
 * The maximum number of items that can be stored in
 * sbp_msg_bootloader_handshake_resp_t::version before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_RESP_VERSION_MAX 251u

/**
 * Encoded length of sbp_msg_bootloader_handshake_resp_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_bootloader_handshake_resp_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_RESP_ENCODED_OVERHEAD 4u

/**
 * Encoded length of sbp_msg_bootloader_jump_to_app_t
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP_ENCODED_LEN 1u

/**
 * Encoded length of sbp_msg_nap_device_dna_req_t
 */
#define SBP_MSG_NAP_DEVICE_DNA_REQ_ENCODED_LEN 0u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_nap_device_dna_resp_t::dna before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP_DNA_MAX 8u

/**
 * Encoded length of sbp_msg_nap_device_dna_resp_t
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP_ENCODED_LEN 8u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_bootloader_handshake_dep_a_t::handshake before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A_HANDSHAKE_MAX 255u

/**
 * Encoded length of sbp_msg_bootloader_handshake_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_bootloader_handshake_dep_a_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_BOOTLOAD_MACROS_H */
