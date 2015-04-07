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
 * with generate.py at 2015-04-02 12:08:48.470750. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include "common.h"


/** Bootloading handshake (Host <=> Piksi).
 *
 * The bootloader continually sends a handshake message to the host
 * for a short period of time, and then jumps to the firmware if it
 * doesn't receive a handshake from the host. If the host replies
 * with a handshake the bootloader doesn't jump to the firmware and
 * nwaits for flash programming messages, and the host has to send a
 * MSG_BOOTLOADER_JUMP_TO_APP when it's done programming. On old
 * versions of the bootloader (<=v0.1), hardcoded u8=0. On new
 * versions, return the git describe string for the bootloader
 * build.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE   0x00B0
typedef struct __attribute__((packed)) {
  u8 handshake;    /**< Handshake value */
} msg_bootloader_handshake_t;


/** Bootloader jump to application (Host => Piksi)
 *
 * The host initiates the bootloader to jump to the application.
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP 0x00B1
typedef struct __attribute__((packed)) {
  u8 jump;    /**< Ignored by the Piksi. */
} msg_bootloader_jump_to_app_t;


/** Send FPGA device DNA over UART (Host <=> Piksi).
 *
 * The device DNA message from the host reads the unique device
 * DNA from the Swift Navigation Acceleration Peripheral
 * (SwiftNAP), a Spartan 6 FPGA. By convention, the host message
 * buffer is empty; the Piksi returns the device DNA in a
 * MSG_NAP_DEVICE_DNA message.
 */
#define SBP_MSG_NAP_DEVICE_DNA         0x00DD
typedef struct __attribute__((packed)) {
  u8 dna[8]; /**< 57-bit SwiftNAP FPGA Device DNA */
} msg_nap_device_dna_t;


#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */