#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
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

#if 0
#endif
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
  sbp_unterminated_string_t version;
} sbp_msg_bootloader_handshake_resp_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_bootloader_handshake_resp_t_version_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 251u
  };
  static inline void sbp_msg_bootloader_handshake_resp_t_version_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_bootloader_handshake_resp_t_version_format); }
  static inline uint8_t sbp_msg_bootloader_handshake_resp_t_version_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_bootloader_handshake_resp_t_version_format); }
  static inline uint8_t sbp_msg_bootloader_handshake_resp_t_version_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_bootloader_handshake_resp_t_version_format, buf, buf_len); }
  static inline uint8_t sbp_msg_bootloader_handshake_resp_t_version_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_bootloader_handshake_resp_t_version_format, buf, buf_len); }
  static inline uint8_t sbp_msg_bootloader_handshake_resp_t_version_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_bootloader_handshake_resp_t_version_format); }
  static inline const char *sbp_msg_bootloader_handshake_resp_t_version_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_bootloader_handshake_resp_t_version_format, 0); }
  static inline bool sbp_msg_bootloader_handshake_resp_t_version_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_bootloader_handshake_resp_t_version_format, new_str); }
#endif
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

#if 0
#endif
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

#if 0
#endif
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

#if 0
#endif
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
  sbp_unterminated_string_t handshake;
} sbp_msg_bootloader_handshake_dep_a_t;

#if 0
  static const sbp_unterminated_string_format_t sbp_msg_bootloader_handshake_dep_a_t_handshake_format = {
    /* .encoding = */ SBP_STRING_UNTERMINATED,
    /* .min_sections = */0u,
    /* .max_sections = */0u,
    /* .terminator = */0u,
    /* .max_encoded_len = */ 255u
  };
  static inline void sbp_msg_bootloader_handshake_dep_a_t_handshake_init(sbp_unterminated_string_t s) { sbp_unterminated_string_init(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format); }
  static inline uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(const sbp_unterminated_string_t s) { return sbp_unterminated_string_packed_len(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format); }
  static inline uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_pack(const sbp_unterminated_string_t s, uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_pack(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format, buf, buf_len); }
  static inline uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_unpack(sbp_unterminated_string_t s, const uint8_t *buf, uint8_t buf_len) { return sbp_unterminated_string_unpack(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format, buf, buf_len); }
  static inline uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_space_remaining(const sbp_unterminated_string_t s) { return sbp_unterminated_string_space_remaining(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format); }
  static inline const char *sbp_msg_bootloader_handshake_dep_a_t_handshake_get(sbp_unterminated_string_t s) { return sbp_unterminated_string_get_section(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format, 0); }
  static inline bool sbp_msg_bootloader_handshake_dep_a_t_handshake_set(sbp_unterminated_string_t s, const char *new_str) { return sbp_unterminated_string_set(s, &sbp_msg_bootloader_handshake_dep_a_t_handshake_format, new_str); }
#endif

#include <libsbp/unpacked/bootload_operators.h>
#include <libsbp/unpacked/bootload_packers.h>

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */
