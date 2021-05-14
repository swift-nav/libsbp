#ifndef LIBSBP_SETTINGS_OPERATORS_H
#define LIBSBP_SETTINGS_OPERATORS_H

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/settings.h instead"
#endif

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <libsbp/common.h>
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  (void)a;
  (void)b;
  
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 255, 3, 3)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.status != b.status) { return false; }
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 254, 3, 3)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  (void)a;
  (void)b;
  
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 255, 2, 2)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  (void)a;
  (void)b;
  
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 255, 3, 3)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.index != b.index) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.index != b.index) { return false; }
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 253, 3, 4)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  (void)a;
  (void)b;
  
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 255, 3, 3)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return !(a == b);
}
#endif
#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.status != b.status) { return false; }
    if (0 != sbp_multipart_string_strcmp(&a.setting, &b.setting, 254, 3, 3)) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return !(a == b);
}
#endif

#endif
