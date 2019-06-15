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
 * Automatically generated from yaml/swiftnav/sbp/bootload.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup bootload Bootload
 *
 *  * Messages for the bootloading configuration of a Piksi 2.3.1.  This message
 * group does not apply to Piksi Multi.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response.
 * \{ */

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** Bootloading handshake request (host => device)
 *
 * The handshake message request from the host establishes a
 * handshake between the device bootloader and the host. The
 * response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_REQ   0x00B3


/** Bootloading handshake response (host <= device)
 *
 * The handshake message response from the device establishes a
 * handshake between the device bootloader and the host. The
 * request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
 * payload contains the bootloader version number and the SBP
 * protocol version number.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_RESP  0x00B4
typedef struct SBP_ATTR_PACKED {
  u32 flags;      /**< Bootloader flags */
  char version[0]; /**< Bootloader version number */
} msg_bootloader_handshake_resp_t;


/** Bootloader jump to application (host => device)
 *
 * The host initiates the bootloader to jump to the application.
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP     0x00B1
typedef struct SBP_ATTR_PACKED {
  u8 jump;    /**< Ignored by the device */
} msg_bootloader_jump_to_app_t;


/** Read FPGA device ID over UART request (host => device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP message with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA_REQ         0x00DE


/** Read FPGA device ID over UART response (host <= device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP        0x00DD
typedef struct SBP_ATTR_PACKED {
  u8 dna[8]; /**< 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.
 */
} msg_nap_device_dna_resp_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A 0x00B0
typedef struct SBP_ATTR_PACKED {
  u8 handshake[0]; /**< Version number string (not NULL terminated) */
} msg_bootloader_handshake_dep_a_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */