/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
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
 * * SBAS data
 * \{ */

#ifndef LIBSBP_SBAS_MESSAGES_H
#define LIBSBP_SBAS_MESSAGES_H

#include "common.h"
#include "gnss.h"


/** Raw SBAS data
 *
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */
#define SBP_MSG_SBAS_RAW 0x7777
typedef struct __attribute__((packed)) {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier. */
  u32 tow;             /**< GPS time-of-week at the start of the data block. [ms] */
  u8 message_type;    /**< SBAS message type (0-63) */
  u8 data[27];        /**< Raw SBAS data field of 212 bits (last byte padded with zeros). */
} msg_sbas_raw_t;


/** \} */

#endif /* LIBSBP_SBAS_MESSAGES_H */