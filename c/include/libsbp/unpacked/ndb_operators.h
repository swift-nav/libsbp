#ifndef LIBSBP_NDB_OPERATORS_H
#define LIBSBP_NDB_OPERATORS_H

#ifndef LIBSBP_NDB_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/ndb.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.recv_time != b.recv_time) { return false; }
        
    if (a.event != b.event) { return false; }
        
    if (a.object_type != b.object_type) { return false; }
        
    if (a.result != b.result) { return false; }
        
    if (a.data_source != b.data_source) { return false; }
        
        
    if (a.object_sid.sat != b.object_sid.sat) { return false; }
        
    if (a.object_sid.code != b.object_sid.code) { return false; }
        
        
    if (a.src_sid.sat != b.src_sid.sat) { return false; }
        
    if (a.src_sid.code != b.src_sid.code) { return false; }
        
    if (a.original_sender != b.original_sender) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_ndb_event_t &a, const sbp_msg_ndb_event_t &b) {
  return !(a == b);
}
#endif

#endif
