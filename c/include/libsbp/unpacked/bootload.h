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
#include <libsbp/unpacked/string/double_null_terminated.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
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
s8 sbp_send_sbp_msg_bootloader_handshake_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_bootloader_handshake_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

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
  void sbp_msg_bootloader_handshake_resp_t_version_init(sbp_unterminated_string_t *s);
  bool sbp_msg_bootloader_handshake_resp_t_version_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_bootloader_handshake_resp_t_version_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_bootloader_handshake_resp_t_version_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_bootloader_handshake_resp_t_version_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_bootloader_handshake_resp_t_version_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_bootloader_handshake_resp_t_version_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_bootloader_handshake_resp_t_version_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_bootloader_handshake_resp_t_version_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_bootloader_handshake_resp_t_version_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_bootloader_handshake_resp_t_version_get(const sbp_unterminated_string_t *s);

size_t sbp_packed_size_sbp_msg_bootloader_handshake_resp_t(const sbp_msg_bootloader_handshake_resp_t *msg);
s8 sbp_pack_sbp_msg_bootloader_handshake_resp_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_resp_t *msg);
s8 sbp_unpack_sbp_msg_bootloader_handshake_resp_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_resp_t *msg);
s8 sbp_send_sbp_msg_bootloader_handshake_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_bootloader_handshake_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

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
s8 sbp_send_sbp_msg_bootloader_jump_to_app_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_bootloader_jump_to_app_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

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
s8 sbp_send_sbp_msg_nap_device_dna_req_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_nap_device_dna_req_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

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
s8 sbp_send_sbp_msg_nap_device_dna_resp_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_nap_device_dna_resp_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_nap_device_dna_resp_t(const sbp_msg_nap_device_dna_resp_t *a, const sbp_msg_nap_device_dna_resp_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BOOTLOADER_HANDSHAKE_DEP_A 0x00B0
typedef struct {
  sbp_unterminated_string_t handshake;
} sbp_msg_bootloader_handshake_dep_a_t;
  void sbp_msg_bootloader_handshake_dep_a_t_handshake_init(sbp_unterminated_string_t *s);
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_valid(const sbp_unterminated_string_t *s);
  int sbp_msg_bootloader_handshake_dep_a_t_handshake_strcmp(const sbp_unterminated_string_t *a, const sbp_unterminated_string_t *b);
  uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_packed_len(const sbp_unterminated_string_t *s);
  uint8_t sbp_msg_bootloader_handshake_dep_a_t_handshake_space_remaining(const sbp_unterminated_string_t *s);
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_set(sbp_unterminated_string_t *s, const char *new_str);
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_printf(sbp_unterminated_string_t *s, const char *fmt, ...) SBP_ATTR_FORMAT(2,3);
  bool sbp_msg_bootloader_handshake_dep_a_t_handshake_append_vprintf(sbp_unterminated_string_t *s, const char *fmt, va_list ap);
  const char *sbp_msg_bootloader_handshake_dep_a_t_handshake_get(const sbp_unterminated_string_t *s);

size_t sbp_packed_size_sbp_msg_bootloader_handshake_dep_a_t(const sbp_msg_bootloader_handshake_dep_a_t *msg);
s8 sbp_pack_sbp_msg_bootloader_handshake_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_bootloader_handshake_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_bootloader_handshake_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_bootloader_handshake_dep_a_t *msg);
s8 sbp_send_sbp_msg_bootloader_handshake_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_bootloader_handshake_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

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
