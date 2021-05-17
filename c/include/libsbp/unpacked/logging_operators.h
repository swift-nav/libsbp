#ifndef LIBSBP_LOGGING_OPERATORS_H
#define LIBSBP_LOGGING_OPERATORS_H

#ifndef LIBSBP_LOGGING_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/logging.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/base.h>
static inline int sbp_cmp_sbp_msg_log_t(const sbp_msg_log_t *a, const sbp_msg_log_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->level, &b->level);
  if (ret != 0) { return ret; }
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, 254
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_log_t &a, const sbp_msg_log_t &b) {
  return sbp_cmp_sbp_msg_log_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fwd_t(const sbp_msg_fwd_t *a, const sbp_msg_fwd_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->source, &b->source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->protocol, &b->protocol);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_fwd_payload, &b->n_fwd_payload);
  for (uint8_t i = 0; i < a->n_fwd_payload && ret == 0; i++)
  {
    ret = sbp_cmp_char(&a->fwd_payload[i], &b->fwd_payload[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fwd_t &a, const sbp_msg_fwd_t &b) {
  return sbp_cmp_sbp_msg_fwd_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_print_dep_t(const sbp_msg_print_dep_t *a, const sbp_msg_print_dep_t *b) {
  int ret = 0;
  
  ret = sbp_unterminated_string_strcmp(&a->text, &b->text, 255
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_print_dep_t &a, const sbp_msg_print_dep_t &b) {
  return sbp_cmp_sbp_msg_print_dep_t(&a, &b) >= 0;
}
#endif

#endif
