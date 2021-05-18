#ifndef LIBSBP_BOOTLOAD_MESSAGES_H
#define LIBSBP_BOOTLOAD_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif
/** Bootloading handshake request (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_REQ   0x00B3
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_bootloader_handshake_req_t;

size_t sbp_packed_size_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *msg);
s8 sbp_pack_sbp_msg_bootloader_handshake_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_req_t *msg);
s8 sbp_unpack_sbp_msg_bootloader_handshake_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_req_t *msg);

int sbp_cmp_sbp_msg_bootloader_handshake_req_t(const sbp_msg_bootloader_handshake_req_t *a, const sbp_msg_bootloader_handshake_req_t *b);


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

size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg);
s8 sbp_pack_sbp_msg_bootloader_handshake_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_resp_t *msg);
s8 sbp_unpack_sbp_msg_bootloader_handshake_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_resp_t *msg);

int sbp_cmp_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *a, const sbp_msg_bootloader_handshake_resp_t *b);


/** Bootloader jump to application (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_JUMP_TO_APP     0x00B1
typedef struct {
  u8 jump;
} sbp_msg_bootloader_jump_to_app_t;

size_t sbp_packed_size_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *msg);
s8 sbp_pack_sbp_msg_bootloader_jump_to_app_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_jump_to_app_t *msg);
s8 sbp_unpack_sbp_msg_bootloader_jump_to_app_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_jump_to_app_t *msg);

int sbp_cmp_sbp_msg_bootloader_jump_to_app_t(const sbp_msg_bootloader_jump_to_app_t *a, const sbp_msg_bootloader_jump_to_app_t *b);


/** Read FPGA device ID over UART request (host => device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_NAP_DEVICE_DNA_REQ         0x00DE
typedef struct {
  char DO_NOT_USE_dummy_field_to_prevent_empty_struct;
} sbp_msg_nap_device_dna_req_t;

size_t sbp_packed_size_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *msg);
s8 sbp_pack_sbp_msg_nap_device_dna_req_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_nap_device_dna_req_t *msg);
s8 sbp_unpack_sbp_msg_nap_device_dna_req_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_nap_device_dna_req_t *msg);

int sbp_cmp_sbp_msg_nap_device_dna_req_t(const sbp_msg_nap_device_dna_req_t *a, const sbp_msg_nap_device_dna_req_t *b);


/** Read FPGA device ID over UART response (host <= device)
 *
((m.desc|commentify)))
 */
#define SBP_MSG_NAP_DEVICE_DNA_RESP        0x00DD
typedef struct {
  u8 dna[8];
} sbp_msg_nap_device_dna_resp_t;

size_t sbp_packed_size_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *msg);
s8 sbp_pack_sbp_msg_nap_device_dna_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_nap_device_dna_resp_t *msg);
s8 sbp_unpack_sbp_msg_nap_device_dna_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_nap_device_dna_resp_t *msg);

int sbp_cmp_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *a, const sbp_msg_nap_device_dna_resp_t *b);


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

size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg);
s8 sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_dep_a_t *msg);

int sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *a, const sbp_msg_bootloader_handshake_dep_a_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_req_t &a, const sbp_msg_bootloader_handshake_req_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_resp_t &a, const sbp_msg_bootloader_handshake_resp_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_jump_to_app_t &a, const sbp_msg_bootloader_jump_to_app_t &b) {
  return sbp_cmp_sbp_msg_bootloader_jump_to_app_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_nap_device_dna_req_t &a, const sbp_msg_nap_device_dna_req_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_req_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_nap_device_dna_resp_t &a, const sbp_msg_nap_device_dna_resp_t &b) {
  return sbp_cmp_sbp_msg_nap_device_dna_resp_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_bootloader_handshake_dep_a_t &a, const sbp_msg_bootloader_handshake_dep_a_t &b) {
  return sbp_cmp_sbp_msg_bootloader_handshake_dep_a_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_BOOTLOAD_MESSAGES_H */
