#ifndef LIBSBP_USER_OPERATORS_H
#define LIBSBP_USER_OPERATORS_H

#ifndef LIBSBP_USER_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/user.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_user_data_t(const sbp_msg_user_data_t *a, const sbp_msg_user_data_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->n_contents, &b->n_contents);
  for (uint8_t i = 0; i < a->n_contents && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->contents[i], &b->contents[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
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

#endif
