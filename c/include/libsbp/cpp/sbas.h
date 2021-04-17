/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_SBAS_MESSAGES_H
#define LIBSBP_CPP_SBAS_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * Raw SBAS data
   *
   * This message is sent once per second per SBAS satellite. ME checks the
   * parity of the data block and sends only blocks that pass the check.
   */
  
  struct SBP_ATTR_PACKED MsgSbasRaw {
    GnssSignal sid; /** GNSS signal identifier. */
    u32 tow; /** GPS time-of-week at the start of the data block. [ms] */
    u8 message_type; /** SBAS message type (0-63) */
    u8 data[27]; /** Raw SBAS data field of 212 bits (last byte padded with zeros). */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_SBAS_MESSAGES_H */