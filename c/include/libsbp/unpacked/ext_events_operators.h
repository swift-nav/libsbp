#ifndef LIBSBP_EXT_EVENTS_OPERATORS_H
#define LIBSBP_EXT_EVENTS_OPERATORS_H

#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ext_events.h instead"
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
static inline int sbp_cmp_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *a, const sbp_msg_ext_event_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->wn, &b->wn);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->tow, &b->tow);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_s32(&a->ns_residual, &b->ns_residual);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->flags, &b->flags);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->pin, &b->pin);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ext_event_t &a, const sbp_msg_ext_event_t &b) {
  return sbp_cmp_sbp_msg_ext_event_t(&a, &b) >= 0;
}
#endif

#endif
