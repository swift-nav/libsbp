# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
#
# Messages for the bootloading configuration of a Piksi 2.3.1.  This message group
# does not apply to Piksi Multi.  Note that some of these messages share the same
# message type ID for both the host request and the device response.
#
# Automatically generated from spec/yaml/swiftnav/sbp/bootload.yaml with generate.py.
# Do not modify by hand!

meta:
  id: bootload
  endian: le
  imports: [  ]

types:

  msg_bootloader_handshake_req:
    doc: |
      The handshake message request from the host establishes a handshake
      between the device bootloader and the host. The response from the device
      is MSG_BOOTLOADER_HANDSHAKE_RESP.
    seq: []
  
  msg_bootloader_handshake_resp:
    doc: |
      The handshake message response from the device establishes a handshake
      between the device bootloader and the host. The request from the host is
      MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
      version number and the SBP protocol version number.
    seq:
      - id: flags
        doc: |
          Bootloader flags
        type: u4
      - id: version
        doc: |
          Bootloader version number
        type: str
        encoding: ascii
        size-eos: true
  
  msg_bootloader_jump_to_app:
    doc: |
      The host initiates the bootloader to jump to the application.
    seq:
      - id: jump
        doc: |
          Ignored by the device
        type: u1
  
  msg_nap_device_dna_req:
    doc: |
      The device message from the host reads a unique device identifier from
      the SwiftNAP, an FPGA. The host requests the ID by sending a
      MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
      MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
      that this ID is tied to the FPGA, and not related to the Piksi's serial
      number.
    seq: []
  
  msg_nap_device_dna_resp:
    doc: |
      The device message from the host reads a unique device identifier from
      the SwiftNAP, an FPGA. The host requests the ID by sending a
      MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
      MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
      that this ID is tied to the FPGA, and not related to the Piksi's serial
      number.
    seq:
      - id: dna
        doc: |
          57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
          right.
        type: u1
        repeat: expr
        repeat-expr: 8
  
  msg_bootloader_handshake_dep_a:
    doc: |
      Deprecated.
    seq:
      - id: handshake
        doc: |
          Version number string (not NULL terminated)
        type: u1
        repeat: eos
  
