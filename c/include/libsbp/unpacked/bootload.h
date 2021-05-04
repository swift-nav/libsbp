#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Bootloading handshake request (host => device)
 *
 * The handshake message request from the host establishes a
 * handshake between the device bootloader and the host. The
 * response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_REQ 0x00B3

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_bootloader_handshake_req_t;
/** Bootloading handshake response (host <= device)
 *
 * The handshake message response from the device establishes a
 * handshake between the device bootloader and the host. The
 * request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
 * payload contains the bootloader version number and the SBP
 * protocol version number.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_RESP 0x00B4

#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_BOOTLOADER_HANDSHAKE_RESP_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

typedef struct
{

  /**
   * Bootloader flags
   */
  u32 flags;
  /**
   * Bootloader version number
   */
  char version[252];
} sbp_msg_bootloader_handshake_resp_t;
/** Bootloader jump to application (host => device)
 *
 * The host initiates the bootloader to jump to the application.
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP 0x00B1

typedef struct
{

  /**
   * Ignored by the device
   */
  u8 jump;
} sbp_msg_bootloader_jump_to_app_t;
/** Read FPGA device ID over UART request (host => device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP message with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA_REQ 0x00DE

typedef struct
{
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_nap_device_dna_req_t;
/** Read FPGA device ID over UART response (host <= device)
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number.
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP 0x00DD

typedef struct
{

  /**
   * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded
   * on the right.
   */
  u8 dna[8];
} sbp_msg_nap_device_dna_resp_t;
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A 0x00B0

typedef struct
{

  /**
   * Version number string (not NULL terminated)
   */
  u8 handshake[255];
  /**
   * Number of items in handshake
   */
  u8 n_handshake;
} sbp_msg_bootloader_handshake_dep_a_t;

#include <libsbp/unpacked/bootload_operators.h>
#include <libsbp/unpacked/bootload_packers.h>

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */
