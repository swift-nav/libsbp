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
 * Automatically generated from yaml/swiftnav/sbp/raw.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup raw Raw
 *
 * * Raw GNSS navigation data
 * \{ */

#ifndef LIBSBP_RAW_MESSAGES_H
#define LIBSBP_RAW_MESSAGES_H

#include "common.h"
#include "gnss.h"


/** Raw GPS L1CA LNAV data
 *
 * This message is sent once per 6 seconds per GPS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */
#define SBP_MSG_GPS_L1CA_RAW 0x7778
typedef struct __attribute__((packed)) {
  sbp_gnss_signal_t sid;            /**< GNSS signal identifier. */
  u32 tow;            /**< GPS time-of-week at the start of the subframe. [ms] */
  u8 subframe_id;    /**< Subframe ID (1-5). */
  u8 data[38];       /**< Raw subframe data field of 300 bits (last byte padded with zeros). */
} msg_gps_l1_ca_raw_t;


/** Raw GLONASS L1OF navigation data
 *
 * This message is sent once per 2 seconds per GLONASS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */
#define SBP_MSG_GLO_L1OF_RAW 0x7779
typedef struct __attribute__((packed)) {
  sbp_gnss_signal_t sid;              /**< GNSS signal identifier. */
  u32 tow;              /**< GPS time-of-week at the start of the subframe. [ms] */
  u8 string_number;    /**< String number (1-15). */
  u8 data[11];         /**< Raw string data field of 85 bits (last byte padded with zeros). */
} msg_glo_l1_of_raw_t;


/** \} */

#endif /* LIBSBP_RAW_MESSAGES_H */