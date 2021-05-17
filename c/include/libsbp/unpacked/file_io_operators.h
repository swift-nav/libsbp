#ifndef LIBSBP_FILE_IO_OPERATORS_H
#define LIBSBP_FILE_IO_OPERATORS_H

#ifndef LIBSBP_FILE_IO_MESSAGES_H
#error "Do not include this file directly, include libsbp/unpacked/file_io.h instead"
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
static inline int sbp_cmp_sbp_msg_fileio_read_req_t(const sbp_msg_fileio_read_req_t *a, const sbp_msg_fileio_read_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->offset, &b->offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->chunk_size, &b->chunk_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, 246
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_req_t &a, const sbp_msg_fileio_read_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_read_resp_t(const sbp_msg_fileio_read_resp_t *a, const sbp_msg_fileio_read_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_contents, &b->n_contents);
  for (uint8_t i = 0; i < a->n_contents && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->contents[i], &b->contents[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_resp_t &a, const sbp_msg_fileio_read_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_read_dir_req_t(const sbp_msg_fileio_read_dir_req_t *a, const sbp_msg_fileio_read_dir_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->offset, &b->offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->dirname, &b->dirname, 247
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_req_t &a, const sbp_msg_fileio_read_dir_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_read_dir_resp_t(const sbp_msg_fileio_read_dir_resp_t *a, const sbp_msg_fileio_read_dir_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_sequence_string_strcmp(&a->contents, &b->contents, 251,255
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_read_dir_resp_t &a, const sbp_msg_fileio_read_dir_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_read_dir_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_remove_t(const sbp_msg_fileio_remove_t *a, const sbp_msg_fileio_remove_t *b) {
  int ret = 0;
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, 255
    );
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_remove_t &a, const sbp_msg_fileio_remove_t &b) {
  return sbp_cmp_sbp_msg_fileio_remove_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_write_req_t(const sbp_msg_fileio_write_req_t *a, const sbp_msg_fileio_write_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->offset, &b->offset);
  if (ret != 0) { return ret; }
  
  ret = sbp_null_terminated_string_strcmp(&a->filename, &b->filename, 247
    );
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u8(&a->n_data, &b->n_data);
  for (uint8_t i = 0; i < a->n_data && ret == 0; i++)
  {
    ret = sbp_cmp_u8(&a->data[i], &b->data[i]);
  }
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_write_req_t &a, const sbp_msg_fileio_write_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_write_resp_t(const sbp_msg_fileio_write_resp_t *a, const sbp_msg_fileio_write_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_write_resp_t &a, const sbp_msg_fileio_write_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_write_resp_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_config_req_t(const sbp_msg_fileio_config_req_t *a, const sbp_msg_fileio_config_req_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_config_req_t &a, const sbp_msg_fileio_config_req_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_req_t(&a, &b) >= 0;
}
#endif
static inline int sbp_cmp_sbp_msg_fileio_config_resp_t(const sbp_msg_fileio_config_resp_t *a, const sbp_msg_fileio_config_resp_t *b) {
  int ret = 0;
  
  ret = sbp_cmp_u32(&a->sequence, &b->sequence);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->window_size, &b->window_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->batch_size, &b->batch_size);
  if (ret != 0) { return ret; }
  
  ret = sbp_cmp_u32(&a->fileio_version, &b->fileio_version);
  if (ret != 0) { return ret; }
  return ret;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_fileio_config_resp_t &a, const sbp_msg_fileio_config_resp_t &b) {
  return sbp_cmp_sbp_msg_fileio_config_resp_t(&a, &b) >= 0;
}
#endif

#endif
