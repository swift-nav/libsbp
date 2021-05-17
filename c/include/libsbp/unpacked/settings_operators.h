#ifndef LIBSBP_SETTINGS_OPERATORS_H
#define LIBSBP_SETTINGS_OPERATORS_H

#ifndef LIBSBP_SETTINGS_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/settings.h instead"
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
static inline int sbp_cmp_sbp_msg_settings_save_t(const sbp_msg_settings_save_t *a, const sbp_msg_settings_save_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_save_t &a, const sbp_msg_settings_save_t &b) {
  return sbp_cmp_sbp_msg_settings_save_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_write_t(const sbp_msg_settings_write_t *a, const sbp_msg_settings_write_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_t &a, const sbp_msg_settings_write_t &b) {
  return sbp_cmp_sbp_msg_settings_write_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_write_resp_t(const sbp_msg_settings_write_resp_t *a, const sbp_msg_settings_write_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 254,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_write_resp_t &a, const sbp_msg_settings_write_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_write_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_read_req_t(const sbp_msg_settings_read_req_t *a, const sbp_msg_settings_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,2,2
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_req_t &a, const sbp_msg_settings_read_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_read_resp_t(const sbp_msg_settings_read_resp_t *a, const sbp_msg_settings_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_resp_t &a, const sbp_msg_settings_read_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_read_by_index_req_t(const sbp_msg_settings_read_by_index_req_t *a, const sbp_msg_settings_read_by_index_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_req_t &a, const sbp_msg_settings_read_by_index_req_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_read_by_index_resp_t(const sbp_msg_settings_read_by_index_resp_t *a, const sbp_msg_settings_read_by_index_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u16(&a->index, &b->index);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 253,3,4
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_resp_t &a, const sbp_msg_settings_read_by_index_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_read_by_index_done_t(const sbp_msg_settings_read_by_index_done_t *a, const sbp_msg_settings_read_by_index_done_t *b) {
  (void)a;
  (void)b;
  int ret = 0;
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_read_by_index_done_t &a, const sbp_msg_settings_read_by_index_done_t &b) {
  return sbp_cmp_sbp_msg_settings_read_by_index_done_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_register_t(const sbp_msg_settings_register_t *a, const sbp_msg_settings_register_t *b) {
  int ret = 0;
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 255,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_t &a, const sbp_msg_settings_register_t &b) {
  return sbp_cmp_sbp_msg_settings_register_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_settings_register_resp_t(const sbp_msg_settings_register_resp_t *a, const sbp_msg_settings_register_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u8(&a->status, &b->status);
  if (ret != 0) { return ret; }
  
  ret = sbp_multipart_string_strcmp(&a->setting, &b->setting, 254,3,3
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_settings_register_resp_t &a, const sbp_msg_settings_register_resp_t &b) {
  return sbp_cmp_sbp_msg_settings_register_resp_t(&a, &b) >= 0;
}
#endif

#endif
