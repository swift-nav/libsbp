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

#define SBP_MSG_ED25519_SIGNATURE 0x0C01
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_signature_t::stub (V4 API) or msg_ed25519_signature_t::stub
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_ED25519_SIGNATURE_STUB_MAX 255u

/**
 * Encoded length of sbp_msg_ed25519_signature_t (V4 API) and
 * msg_ed25519_signature_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ed25519_signature_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ED25519_SIGNATURE_ENCODED_OVERHEAD 0u

#define SBP_MSG_ED25519_CERTIFICATE 0x0C02
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ed25519_certificate_t::stub (V4 API) or
 * msg_ed25519_certificate_t::stub (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_ED25519_CERTIFICATE_STUB_MAX 255u

/**
 * Encoded length of sbp_msg_ed25519_certificate_t (V4 API) and
 * msg_ed25519_certificate_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ed25519_certificate_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ED25519_CERTIFICATE_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_SIGNING_MACROS_H */
