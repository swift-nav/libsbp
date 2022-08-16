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

/** \defgroup signing Signing
 *
 * Messages relating to signatures
 * \{ */

#ifndef LIBSBP_LEGACY_SIGNING_MESSAGES_H
#define LIBSBP_LEGACY_SIGNING_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/legacy/gnss.h>
#include <libsbp/signing_macros.h>

SBP_PACK_START

typedef struct SBP_ATTR_PACKED {
  u8 signature[64];   /**< ED25519 signature for messages. */
  u8 fingerprint[20]; /**< SHA-1 fingerprint of the associated certificate. */
  u32 signed_messages[0]; /**< CRCs of signed messages. */
} msg_ed25519_signature_t;

typedef struct SBP_ATTR_PACKED {
  u8 n_msg;                /**< Total number messages that make up the
                                certificate. First nibble is the size of the
                                sequence (n), second nibble is the zero-
                                indexed counter (ith packet of n) */
  u8 fingerprint[20];      /**< SHA-1 fingerprint of the associated
                                certificate. */
  u8 certificate_bytes[0]; /**< ED25519 certificate bytes. */
} msg_ed25519_certificate_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SIGNING_MESSAGES_H */