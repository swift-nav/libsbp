/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
 * * SBAS data
 * \{ */

#ifndef LIBSBP_SBAS_MESSAGES_H
#define LIBSBP_SBAS_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START


/** Raw SBAS data
 *
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */
#define SBP_MSG_SBAS_RAW 0x7777

typedef struct SBP_ATTR_PACKED {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier. */
  u32 tow;             /**< GPS time-of-week at the start of the data block. [ms] */
  u8 message_type;    /**< SBAS message type (0-63) */
  u8 data[27];        /**< Raw SBAS data field of 212 bits (last byte padded with zeros). */
} msg_sbas_raw_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_SBAS_RAW(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_sbas_raw_t, sid ) == 0, "Offset of sid in msg_sbas_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sbas_raw_t, sid ) == 0, offset_of_sid_in_msg_sbas_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_sbas_raw_t, tow ) == 0 + sizeof(sbp_gnss_signal_t), "Offset of tow in msg_sbas_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sbas_raw_t, tow ) == 0 + sizeof(sbp_gnss_signal_t), offset_of_tow_in_msg_sbas_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_sbas_raw_t, message_type ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u32), "Offset of message_type in msg_sbas_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sbas_raw_t, message_type ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u32), offset_of_message_type_in_msg_sbas_raw_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_sbas_raw_t, data ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u32) + sizeof(u8), "Offset of data in msg_sbas_raw_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_sbas_raw_t, data ) == 0 + sizeof(sbp_gnss_signal_t) + sizeof(u32) + sizeof(u8), offset_of_data_in_msg_sbas_raw_t_is_incorrect)
#endif
}


SBP_PACK_END

#endif /* LIBSBP_SBAS_MESSAGES_H */
