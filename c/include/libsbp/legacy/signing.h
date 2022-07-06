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
  u8 stub[0];
} msg_ed25519_signature_t;

typedef struct SBP_ATTR_PACKED {
  u8 stub[0];
} msg_ed25519_certificate_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SIGNING_MESSAGES_H */