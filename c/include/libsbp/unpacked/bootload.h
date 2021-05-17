#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
/** Bootloading handshake request (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_REQ   0x00B3
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_bootloader_handshake_req_t;



#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
                             (((flags) >> SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) \
                             & SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                             << (SBP_BOOTLOADER_HANDSHAKE_RESP_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT)));} while(0)
                             

/** Bootloading handshake response (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_RESP  0x00B4
typedef struct {
  u32 flags;
  sbp_unterminated_string_t version;
} sbp_msg_bootloader_handshake_resp_t;
#define sbp_msg_bootloader_handshake_resp_t_version_init(f) sbp_unterminated_string_init(f, 251)
#define sbp_msg_bootloader_handshake_resp_t_version_valid(f) sbp_unterminated_string_valid(f, 251)
#define sbp_msg_bootloader_handshake_resp_t_version_set(f,s) sbp_unterminated_string_set(f,s,251)
#define sbp_msg_bootloader_handshake_resp_t_version_printf(f,...) sbp_unterminated_string_printf(f,251,__VA_ARGS__)
#define sbp_msg_bootloader_handshake_resp_t_version_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,251,fmt,ap)
#define sbp_msg_bootloader_handshake_resp_t_version_packed_len(f) sbp_unterminated_string_packed_len(f,251)
#define sbp_msg_bootloader_handshake_resp_t_version_get(f) sbp_unterminated_string_get(f,251)
#define sbp_msg_bootloader_handshake_resp_t_version_len(f) ( sbp_msg_bootloader_handshake_resp_t_version_packed_len(f))
#define sbp_msg_bootloader_handshake_resp_t_version_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,251)



/** Bootloader jump to application (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP     0x00B1
typedef struct {
  u8 jump;
} sbp_msg_bootloader_jump_to_app_t;



/** Read FPGA device ID over UART request (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_NAP_DEVICE_DNA_REQ         0x00DE
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_nap_device_dna_req_t;



/** Read FPGA device ID over UART response (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP        0x00DD
typedef struct {
  u8 dna[8];
} sbp_msg_nap_device_dna_resp_t;



/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A 0x00B0
typedef struct {
  sbp_unterminated_string_t handshake;
} sbp_msg_bootloader_handshake_dep_a_t;
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_init(f) sbp_unterminated_string_init(f, 255)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_valid(f) sbp_unterminated_string_valid(f, 255)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_set(f,s) sbp_unterminated_string_set(f,s,255)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_printf(f,...) sbp_unterminated_string_printf(f,255,__VA_ARGS__)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_vprintf(f,fmt,ap) sbp_unterminated_string_vprintf(f,255,fmt,ap)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(f) sbp_unterminated_string_packed_len(f,255)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_get(f) sbp_unterminated_string_get(f,255)
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_len(f) ( sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(f))
#define sbp_msg_bootloader_handshake_dep_a_t_handshake_strcmp(a,b) sbp_unterminated_string_strcmp(a,b,255)




#include <libsbp/unpacked/bootload_operators.h>
#include <libsbp/unpacked/bootload_packers.h>

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */
