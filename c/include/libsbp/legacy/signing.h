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

#include <libsbp/signing_macros.h>

SBP_PACK_START

typedef struct SBP_ATTR_PACKED {
  u16 year;   /**< Year [year] */
  u8 month;   /**< Month (range 1 .. 12) [months] */
  u8 day;     /**< days in the month (range 1-31) [day] */
  u8 hours;   /**< hours of day (range 0-23) [hours] */
  u8 minutes; /**< minutes of hour (range 0-59) [minutes] */
  u8 seconds; /**< seconds of minute (range 0-60) rounded down [seconds] */
  u32 ns;     /**< nanoseconds of second (range 0-999999999) [nanoseconds] */
} utc_time_t;

/** An ECDSA certificate split over multiple messages
 *
 * A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
 */

typedef struct SBP_ATTR_PACKED {
  u8 n_msg;             /**< Total number messages that make up the
                             certificate. The first nibble (mask 0xF0 or
                             left shifted by 4 bits) is the size of the
                             sequence (n), second nibble (mask 0x0F) is the
                             zero-indexed counter (ith packet of n). */
  u8 certificate_id[4]; /**< The last 4 bytes of the certificate's SHA-1
                             fingerprint */
  u8 flags;
  u8 certificate_bytes[0]; /**< DER encoded x.509 ECDSA certificate bytes */
} msg_ecdsa_certificate_t;

typedef struct SBP_ATTR_PACKED {
  u8 root_certificate[20];         /**< SHA-1 fingerprint of the root
                                        certificate */
  u8 intermediate_certificate[20]; /**< SHA-1 fingerprint of the intermediate
                                        certificate */
  u8 corrections_certificate[20];  /**< SHA-1 fingerprint of the corrections
                                        certificate */
  utc_time_t expiration;           /**< The certificate chain comprised
                                        of three fingerprints: root
                                        certificate, intermediate
                                        certificate and corrections
                                        certificate. */
  u8 signature[64];                /**< An ECDSA signature (created by the root
                                        certificate) over the concatenation of
                                        the SBP payload bytes preceding this
                                        field. That is, the concatenation of
                                        `root_certificate`,
                                        `intermediate_certificate`,
                                        `corrections_certificate` and
                                        `expiration`.  This certificate chain
                                        (allow list) can also be validated by
                                        fetching it from
                                        `http(s)://certs.swiftnav.com/chain`. */
} msg_certificate_chain_t;

/** An ECDSA signature
 *
 * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 */

typedef struct SBP_ATTR_PACKED {
  u8 flags;              /**< Describes the format of the `signed\_messages`
                              field below. */
  u8 stream_counter;     /**< Signature message counter. Zero indexed and
                              incremented with each signature message.  The
                              counter will not increment if this message was
                              in response to an on demand request.  The
                              counter will roll over after 256 messages.
                              Upon connection, the value of the counter may
                              not initially be zero. */
  u8 on_demand_counter;  /**< On demand message counter. Zero indexed and
                              incremented with each signature message sent
                              in response to an on demand message. The
                              counter will roll over after 256 messages.
                              Upon connection, the value of the counter may
                              not initially be zero. */
  u8 certificate_id[4];  /**< The last 4 bytes of the certificate's SHA-1
                              fingerprint */
  u8 n_signature_bytes;  /**< Number of bytes to use of the signature field.
                              The DER encoded signature has a maximum size
                              of 72 bytes but can vary between 70 and 72
                              bytes in length. */
  u8 signature[72];      /**< DER encoded ECDSA signature for the messages
                              using SHA-256 as the digest algorithm. */
  u8 signed_messages[0]; /**< CRCs of the messages covered by this
                              signature.  For Skylark, which delivers SBP
                              messages wrapped in Swift's proprietary RTCM
                              message, these are the 24-bit CRCs from the
                              RTCM message framing. For SBP only streams,
                              this will be 16-bit CRCs from the SBP framing.
                              See the `flags` field to determine the type of
                              CRCs covered. */
} msg_ecdsa_signature_t;

/** An ECDSA signature
 *
 * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 */

typedef struct SBP_ATTR_PACKED {
  u8 flags;              /**< Describes the format of the `signed\_messages`
                              field below. */
  u8 stream_counter;     /**< Signature message counter. Zero indexed and
                              incremented with each signature message.  The
                              counter will not increment if this message was
                              in response to an on demand request.  The
                              counter will roll over after 256 messages.
                              Upon connection, the value of the counter may
                              not initially be zero. */
  u8 on_demand_counter;  /**< On demand message counter. Zero indexed and
                              incremented with each signature message sent
                              in response to an on demand message. The
                              counter will roll over after 256 messages.
                              Upon connection, the value of the counter may
                              not initially be zero. */
  u8 certificate_id[4];  /**< The last 4 bytes of the certificate's SHA-1
                              fingerprint */
  u8 signature[64];      /**< ECDSA signature for the messages using SHA-256
                              as the digest algorithm. */
  u8 signed_messages[0]; /**< CRCs of the messages covered by this
                              signature.  For Skylark, which delivers SBP
                              messages wrapped in Swift's proprietary RTCM
                              message, these are the 24-bit CRCs from the
                              RTCM message framing. For SBP only streams,
                              this will be 16-bit CRCs from the SBP framing.
                              See the `flags` field to determine the type of
                              CRCs covered. */
} msg_ecdsa_signature_dep_t;

typedef struct SBP_ATTR_PACKED {
  u8 n_msg;                /**< Total number messages that make up the
                                certificate. First nibble is the size of the
                                sequence (n), second nibble is the zero-
                                indexed counter (ith packet of n) */
  u8 fingerprint[20];      /**< SHA-1 fingerprint of the associated
                                certificate. */
  u8 certificate_bytes[0]; /**< ED25519 certificate bytes. */
} msg_ed25519_certificate_dep_t;

typedef struct SBP_ATTR_PACKED {
  u8 signature[64];   /**< ED25519 signature for messages. */
  u8 fingerprint[20]; /**< SHA-1 fingerprint of the associated certificate. */
  u32 signed_messages[0]; /**< CRCs of signed messages. */
} msg_ed25519_signature_dep_a_t;

typedef struct SBP_ATTR_PACKED {
  u8 stream_counter;      /**< Signature message counter. Zero indexed and
                               incremented with each signature message.  The
                               counter will not increment if this message was
                               in response to an on demand request.  The
                               counter will roll over after 256 messages.
                               Upon connection, the value of the counter may
                               not initially be zero. */
  u8 on_demand_counter;   /**< On demand message counter. Zero indexed and
                               incremented with each signature message sent
                               in response to an on demand message. The
                               counter will roll over after 256 messages.
                               Upon connection, the value of the counter may
                               not initially be zero. */
  u8 signature[64];       /**< ED25519 signature for messages. */
  u8 fingerprint[20];     /**< SHA-1 fingerprint of the associated
                               certificate. */
  u32 signed_messages[0]; /**< CRCs of signed messages. */
} msg_ed25519_signature_dep_b_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SIGNING_MESSAGES_H */