#ifndef LIBSBP_NEW_MAG_MESSAGES_H
#define LIBSBP_NEW_MAG_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/new/string/null_terminated.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
/** Raw magnetometer data
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_MAG_MESSAGES_H
#define SBP_MSG_MAG_RAW 0x0902
#endif
typedef struct {
  u32 tow;
  u8 tow_f;
  s16 mag_x;
  s16 mag_y;
  s16 mag_z;
} sbp_msg_mag_raw_t;

size_t sbp_packed_size_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *msg);
s8 sbp_encode_sbp_msg_mag_raw_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_mag_raw_t *msg);
s8 sbp_decode_sbp_msg_mag_raw_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_mag_raw_t *msg);
s8 sbp_send_sbp_msg_mag_raw_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_mag_raw_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_mag_raw_t(const sbp_msg_mag_raw_t *a, const sbp_msg_mag_raw_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_mag_raw_t &a, const sbp_msg_mag_raw_t &b) {
  return sbp_cmp_sbp_msg_mag_raw_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_MAG_MESSAGES_H */
