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
 * Automatically generated from yaml/swiftnav/sbp/logging.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_LOGGING_MESSAGES_H
#define LIBSBP_CPP_LOGGING_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Plaintext logging messages with levels
   *
   * This message contains a human-readable payload string from the
   * device containing errors, warnings and informational messages at
   * ERROR, WARNING, DEBUG, INFO logging levels.
   */
  constexpr u16 MSG_LOG = 0x0401;

  template<size_t TEXT_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgLog {
    u8 level; /** Logging level */
    char text[TEXT_COUNT]; /** Human-readable string */
  };

  
  /**
   * Wrapper for FWD a separate stream of information over SBP
   *
   * This message provides the ability to forward messages over SBP.  This may take the form
   * of wrapping up SBP messages received by Piksi for logging purposes or wrapping 
   * another protocol with SBP.
   * 
   * The source identifier indicates from what interface a forwarded stream derived.
   * The protocol identifier identifies what the expected protocol the forwarded msg contains.
   * Protocol 0 represents SBP and the remaining values are implementation defined.
   */
  constexpr u16 MSG_FWD = 0x0402;

  template<size_t FWD_PAYLOAD_COUNT = (SBP_MAX_PAYLOAD_LEN - sizeof(u8) + sizeof(u8) + 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgFwd {
    u8 source; /** source identifier */
    u8 protocol; /** protocol identifier */
    char fwd_payload[FWD_PAYLOAD_COUNT]; /** variable length wrapped binary message */
  };

  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  constexpr u16 MSG_PRINT_DEP = 0x0010;

  template<size_t TEXT_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgPrintDep {
    char text[TEXT_COUNT]; /** Human-readable string */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_LOGGING_MESSAGES_H */