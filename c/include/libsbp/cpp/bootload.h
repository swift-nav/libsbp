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
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_BOOTLOAD_MESSAGES_H
#define LIBSBP_CPP_BOOTLOAD_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Bootloading handshake request (host => device)
   *
   * The handshake message request from the host establishes a
   * handshake between the device bootloader and the host. The
   * response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.
   */
  
  /**
   * Bootloading handshake response (host <= device)
   *
   * The handshake message response from the device establishes a
   * handshake between the device bootloader and the host. The
   * request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
   * payload contains the bootloader version number and the SBP
   * protocol version number.
   */
  template<size_t VERSION_COUNT = (SBP_MAX_PAYLOAD_LEN - (sizeof(u32) + 0)) / sizeof(char)>
  struct SBP_ATTR_PACKED MsgBootloaderHandshakeResp {
    u32 flags; /** Bootloader flags */
    char version[VERSION_COUNT]; /** Bootloader version number */
  };
  
  /**
   * Bootloader jump to application (host => device)
   *
   * The host initiates the bootloader to jump to the application.
   */
  
  struct SBP_ATTR_PACKED MsgBootloaderJumpToApp {
    u8 jump; /** Ignored by the device */
  };
  
  /**
   * Read FPGA device ID over UART request (host => device)
   *
   * The device message from the host reads a unique device
   * identifier from the SwiftNAP, an FPGA. The host requests the ID
   * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
   * responds with a MSG_NAP_DEVICE_DNA_RESP message with the
   * device ID in the payload. Note that this ID is tied to the FPGA,
   * and not related to the Piksi's serial number.
   */
  
  /**
   * Read FPGA device ID over UART response (host <= device)
   *
   * The device message from the host reads a unique device
   * identifier from the SwiftNAP, an FPGA. The host requests the ID
   * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
   * responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
   * device ID in the payload. Note that this ID is tied to the FPGA,
   * and not related to the Piksi's serial number.
   */
  
  struct SBP_ATTR_PACKED MsgNapDeviceDnaResp {
    u8 dna[8]; /** 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.
 */
  };
  
  /**
   * Deprecated
   *
   * Deprecated.
   */
  template<size_t HANDSHAKE_COUNT = (SBP_MAX_PAYLOAD_LEN - (0)) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgBootloaderHandshakeDepA {
    u8 handshake[HANDSHAKE_COUNT]; /** Version number string (not NULL terminated) */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_BOOTLOAD_MESSAGES_H */