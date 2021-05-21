#ifndef LIBSBP_USER_MESSAGES_H
#define LIBSBP_USER_MESSAGES_H

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
/** User data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_USER_DATA 0x0800
typedef struct {
  u8 contents[255];
  u8 n_contents;
} sbp_msg_user_data_t;

size_t sbp_packed_size_sbp_msg_user_data_t(const sbp_msg_user_data_t *msg);
s8 sbp_pack_sbp_msg_user_data_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_user_data_t *msg);
s8 sbp_unpack_sbp_msg_user_data_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_user_data_t *msg);

int sbp_cmp_sbp_msg_user_data_t(const sbp_msg_user_data_t *a, const sbp_msg_user_data_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b) {
  return sbp_cmp_sbp_msg_user_data_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b) {
  return sbp_cmp_sbp_msg_user_data_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b) {
  return sbp_cmp_sbp_msg_user_data_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b) {
  return sbp_cmp_sbp_msg_user_data_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b) {
  return sbp_cmp_sbp_msg_user_data_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_user_data_t &a, const sbp_msg_user_data_t &b) {
  return sbp_cmp_sbp_msg_user_data_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_USER_MESSAGES_H */
