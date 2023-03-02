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
 * Automatically generated from yaml/swiftnav/sbp/signing.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SIGNING_MACROS_H
#define LIBSBP_SIGNING_MACROS_H

/**
 * Encoded length of sbp_utc_time_t (V4 API) and
 * utc_time_t (legacy API)
 */
#define SBP_UTC_TIME_ENCODED_LEN 11u

#define SBP_MSG_ECDSA_CERTIFICATE 0x0C04
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ecdsa_certificate_t::certificate_id (V4 API) or
 * msg_ecdsa_certificate_t::certificate_id (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_ECDSA_CERTIFICATE_CERTIFICATE_ID_MAX 4u

#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_MASK (0x7u)
#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_SHIFT (0u)
#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_SHIFT) & \
        SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_MASK))
#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_SET(flags, val)                \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags & (~(SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_MASK          \
                         << SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_SHIFT))) | \
             (((val) & (SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_MASK))         \
              << (SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_SHIFT)));            \
  } while (0)

#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_CORRECTIONS_CERTIFICATE (0)
#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_ROOT_CERTIFICATE (1)
#define SBP_ECDSA_CERTIFICATE_CERTIFICATE_TYPE_INTERMEDIATE_CERTIFICATE (2)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ecdsa_certificate_t::certificate_bytes (V4 API) or
 * msg_ecdsa_certificate_t::certificate_bytes (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_ECDSA_CERTIFICATE_CERTIFICATE_BYTES_MAX 249u

/**
 * Encoded length of sbp_msg_ecdsa_certificate_t (V4 API) and
 * msg_ecdsa_certificate_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ecdsa_certificate_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ECDSA_CERTIFICATE_ENCODED_OVERHEAD 6u

#define SBP_MSG_CERTIFICATE_CHAIN 0x0C05
/**
 * The maximum number of items that can be stored in
 * sbp_msg_certificate_chain_t::root_certificate (V4 API) or
 * msg_certificate_chain_t::root_certificate (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_CERTIFICATE_CHAIN_ROOT_CERTIFICATE_MAX 20u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_certificate_chain_t::intermediate_certificate (V4 API) or
 * msg_certificate_chain_t::intermediate_certificate (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_CERTIFICATE_CHAIN_INTERMEDIATE_CERTIFICATE_MAX 20u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_certificate_chain_t::corrections_certificate (V4 API) or
 * msg_certificate_chain_t::corrections_certificate (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_CERTIFICATE_CHAIN_CORRECTIONS_CERTIFICATE_MAX 20u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_certificate_chain_t::signature (V4 API) or
 * msg_certificate_chain_t::signature (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_CERTIFICATE_CHAIN_SIGNATURE_MAX 64u

/**
 * Encoded length of sbp_msg_certificate_chain_t (V4 API) and
 * msg_certificate_chain_t (legacy API)
 */
#define SBP_MSG_CERTIFICATE_CHAIN_ENCODED_LEN 135u

#define SBP_MSG_ECDSA_SIGNATURE 0x0C06
#define SBP_ECDSA_SIGNATURE_CRC_TYPE_MASK (0x3u)
#define SBP_ECDSA_SIGNATURE_CRC_TYPE_SHIFT (0u)
#define SBP_ECDSA_SIGNATURE_CRC_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_ECDSA_SIGNATURE_CRC_TYPE_SHIFT) & \
        SBP_ECDSA_SIGNATURE_CRC_TYPE_MASK))
#define SBP_ECDSA_SIGNATURE_CRC_TYPE_SET(flags, val)                      \
  do {                                                                    \
    (flags) = (u8)((flags & (~(SBP_ECDSA_SIGNATURE_CRC_TYPE_MASK          \
                               << SBP_ECDSA_SIGNATURE_CRC_TYPE_SHIFT))) | \
                   (((val) & (SBP_ECDSA_SIGNATURE_CRC_TYPE_MASK))         \
                    << (SBP_ECDSA_SIGNATURE_CRC_TYPE_SHIFT)));            \
  } while (0)

#define SBP_ECDSA_SIGNATURE_CRC_TYPE_24_BIT_CRCS_FROM_RTCM_FRAMING (0)
#define SBP_ECDSA_SIGNATURE_CRC_TYPE_16_BIT_CRCS_FROM_SBP_FRAMING (1)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ecdsa_signature_t::certificate_id (V4 API) or
 * msg_ecdsa_signature_t::certificate_id (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_ECDSA_SIGNATURE_CERTIFICATE_ID_MAX 4u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ecdsa_signature_t::signature (V4 API) or
 * msg_ecdsa_signature_t::signature (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_ECDSA_SIGNATURE_SIGNATURE_MAX 64u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ecdsa_signature_t::signed_messages (V4 API) or
 * msg_ecdsa_signature_t::signed_messages (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_ECDSA_SIGNATURE_SIGNED_MESSAGES_MAX 184u

/**
 * Encoded length of sbp_msg_ecdsa_signature_t (V4 API) and
 * msg_ecdsa_signature_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ecdsa_signature_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ECDSA_SIGNATURE_ENCODED_OVERHEAD 71u

#define SBP_MSG_ED25519_CERTIFICATE_DEP 0x0C02
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_certificate_dep_t::fingerprint (V4 API) or
 * msg_ed25519_certificate_dep_t::fingerprint (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_ED25519_CERTIFICATE_DEP_FINGERPRINT_MAX 20u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_certificate_dep_t::certificate_bytes (V4 API) or
 * msg_ed25519_certificate_dep_t::certificate_bytes (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_ED25519_CERTIFICATE_DEP_CERTIFICATE_BYTES_MAX 234u

/**
 * Encoded length of sbp_msg_ed25519_certificate_dep_t (V4 API) and
 * msg_ed25519_certificate_dep_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ed25519_certificate_dep_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ED25519_CERTIFICATE_DEP_ENCODED_OVERHEAD 21u

#define SBP_MSG_ED25519_SIGNATURE_DEP_A 0x0C01
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_dep_a_t::signature (V4 API) or
 * msg_ed25519_signature_dep_a_t::signature (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_A_SIGNATURE_MAX 64u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_dep_a_t::fingerprint (V4 API) or
 * msg_ed25519_signature_dep_a_t::fingerprint (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_A_FINGERPRINT_MAX 20u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_dep_a_t::signed_messages (V4 API) or
 * msg_ed25519_signature_dep_a_t::signed_messages (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_A_SIGNED_MESSAGES_MAX 42u

/**
 * Encoded length of sbp_msg_ed25519_signature_dep_a_t (V4 API) and
 * msg_ed25519_signature_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ed25519_signature_dep_a_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_A_ENCODED_OVERHEAD 84u

#define SBP_MSG_ED25519_SIGNATURE_DEP_B 0x0C03
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_dep_b_t::signature (V4 API) or
 * msg_ed25519_signature_dep_b_t::signature (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_B_SIGNATURE_MAX 64u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_dep_b_t::fingerprint (V4 API) or
 * msg_ed25519_signature_dep_b_t::fingerprint (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_B_FINGERPRINT_MAX 20u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_dep_b_t::signed_messages (V4 API) or
 * msg_ed25519_signature_dep_b_t::signed_messages (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_B_SIGNED_MESSAGES_MAX 42u

/**
 * Encoded length of sbp_msg_ed25519_signature_dep_b_t (V4 API) and
 * msg_ed25519_signature_dep_b_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ed25519_signature_dep_b_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ED25519_SIGNATURE_DEP_B_ENCODED_OVERHEAD 86u

#endif /* LIBSBP_SIGNING_MACROS_H */
