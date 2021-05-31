#ifndef LIBSBP_SBAS_MESSAGES_H
#define LIBSBP_SBAS_MESSAGES_H

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
#include <libsbp/unpacked/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
/** Raw SBAS data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SBAS_RAW 0x7777
typedef struct {
  sbp_sbp_gnss_signal_t sid;
  u32 tow;
  u8 message_type;
  u8 data[27];
} sbp_msg_sbas_raw_t;

size_t sbp_packed_size_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *msg);
s8 sbp_pack_sbp_msg_sbas_raw_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_sbas_raw_t *msg);
s8 sbp_unpack_sbp_msg_sbas_raw_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_sbas_raw_t *msg);
s8 sbp_send_sbp_msg_sbas_raw_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_sbas_raw_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_sbas_raw_t(const sbp_msg_sbas_raw_t *a, const sbp_msg_sbas_raw_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_sbas_raw_t &a, const sbp_msg_sbas_raw_t &b) {
  return sbp_cmp_sbp_msg_sbas_raw_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_SBAS_MESSAGES_H */
