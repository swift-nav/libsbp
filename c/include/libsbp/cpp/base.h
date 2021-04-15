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
 * Automatically generated from yaml/swiftnav/sbp/base.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_BASE_MESSAGES_H
#define LIBSBP_CPP_BASE_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * None
   *
   * Packet structure for Swift Navigation Binary Protocol (SBP).
   * Definition of the over-the-wire message framing format and packet
   * structure for Swift Navigation Binary Protocol (SBP), a minimal
   * binary protocol for communicating with Swift devices. It is used
   * to transmit solutions, observations, status and debugging
   * messages, as well as receive messages from the host operating
   * system.
   */

  
  struct SBP_ATTR_PACKED Sbp {
    u8 preamble; /** Denotes the start of frame transmission. For v1.0, always 0x55 */
    u16 msg_type; /** Uniquely identifies the type of the payload contents */
    u16 sender; /** A unique identifier of the sending hardware. For v1.0,
set to the 2 least significant bytes of the device serial
number
 */
    u8 length; /** Byte-length of the payload field [bytes] */
    bytes payload; /** Binary data of the message, as identified by Message Type and
Length. Usually contains the in-memory binary representation of
a C struct (see documentation on individual message types)
 */
    u16 crc; /** Cyclic Redundancy Check (CRC) of the packet's binary data from
the Message Type up to the end of Payload (does not include the
Preamble)
 */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_BASE_MESSAGES_H */