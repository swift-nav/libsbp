/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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
 *  * Messages for the bootloading configuration on the device.
 * 
 * These are in the implementation-defined range (0x0000-0x00FF), and
 * are intended for internal use only. Note that some of these messages
 * share the same message type ID for both the host request and the
 * device response.
 * \{ */

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include "common.h"


/** Bootloading handshake (host <=> device)
 *
 * The handshake message establishes a handshake between the device
 * bootloader and the host.  The payload string contains the
 * bootloader version number, but returns an empty string for
 * earlier versions.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE   0x00B0
typedef struct __attribute__((packed)) {
  u8 handshake[0]; /**< Version number string (not NULL terminated) */
} msg_bootloader_handshake_t;


/** Bootloader jump to application (host => device)
 *
 * The host initiates the bootloader to jump to the application.
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP 0x00B1
typedef struct __attribute__((packed)) {
  u8 jump;    /**< Ignored by the device */
} msg_bootloader_jump_to_app_t;


/** Read FPGA device ID over UART (host <=> device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA with an empty payload. The
 * device responds with the same message with the device ID in the
 * payload. Note that this ID is tied to the FPGA, and not related
 * to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA         0x00DD
typedef struct __attribute__((packed)) {
  u8 dna[8]; /**< 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
on the right.
 */
} msg_nap_device_dna_t;


/** \} */

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */