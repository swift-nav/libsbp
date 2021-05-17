#ifndef LIBSBP_NDB_OPERATORS_H
#define LIBSBP_NDB_OPERATORS_H

#ifndef LIBSBP_NDB_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ndb.h instead"
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
static inline int sbp_cmp_sbp_msg_ndb_event_t(const sbp_msg_ndb_event_t *a, const sbp_msg_ndb_event_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u64(&a->recv_time, &b->recv_time);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->event, &b->event);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->object_type, &b->object_type);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->result, &b->result);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->data_source, &b->data_source);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->object_sid, &b->object_sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_sbp_sbp_gnss_signal_t(&a->src_sid, &b->src_sid);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u16(&a->original_sender, &b->original_sender);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return sbp_cmp_sbp_msg_ndb_event_t(&a, &b) >= 0;
}
#endif

#endif
