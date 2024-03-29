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
 * Automatically generated from yaml/swiftnav/sbp/sbas.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup sbas Sbas
 *
 * SBAS data
 * \{ */

#ifndef LIBSBP_LEGACY_SBAS_MESSAGES_H
#define LIBSBP_LEGACY_SBAS_MESSAGES_H

#include <libsbp/common.h>

SBP_MESSAGE(
    "The legacy libsbp API has been deprecated. This file and all symbols "
    "contained will "
    "be removed in version 6. You should immediately switch over to the modern "
    "libsbp API.")

#include <libsbp/legacy/gnss.h>
#include <libsbp/sbas_macros.h>

SBP_PACK_START

/** Raw SBAS data
 *
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */

typedef struct SBP_ATTR_PACKED SBP_DEPRECATED {
  sbp_gnss_signal_t sid; /**< GNSS signal identifier. */
  u32 tow;         /**< GPS time-of-week at the start of the data block. [ms] */
  u8 message_type; /**< SBAS message type (0-63) */
  u8 data[27];     /**< Raw SBAS data field of 212 bits (last byte padded
                        with zeros). */
} msg_sbas_raw_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SBAS_MESSAGES_H */