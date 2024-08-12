/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/profiling.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_PROFILING_RESOURCEBUCKET_H
#define LIBSBP_PROFILING_RESOURCEBUCKET_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/profiling_macros.h>
#include <libsbp/string/sbp_string.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *
 * SBP_RESOURCEBUCKET
 *
 *****************************************************************************/
/** A bucket containing various resources
 *
 * Information about allocation of various resources grouped by buckets. Refer
 * to product documentation to understand the meaning and values in this
 * message.
 */
typedef struct {
  /**
   * Bucket name
   */
  char name[SBP_RESOURCE_BUCKET_NAME_MAX];

  /**
   * Number of threads
   */
  u8 thread;

  /**
   * Number of mutexes
   */
  u8 mutex;

  /**
   * Number of condition variables
   */
  u8 cv;

  /**
   * Number of IO handles
   */
  u8 io;

  /**
   * Number of bytes allocated on the heap
   */
  u32 heap_bytes_alloc;

  /**
   * Number of bytes freed on the heap
   */
  u32 heap_bytes_free;

  /**
   * Number of bytes written to IO handles
   */
  u32 io_write;

  /**
   * Number of bytes read from IO handles
   */
  u32 io_read;
} sbp_resource_bucket_t;

/**
 * Get encoded size of an instance of sbp_resource_bucket_t
 *
 * @param msg sbp_resource_bucket_t instance
 * @return Length of on-wire representation
 */
static inline size_t sbp_resource_bucket_encoded_len(
    const sbp_resource_bucket_t *msg) {
  (void)msg;
  return SBP_RESOURCE_BUCKET_ENCODED_LEN;
}

/**
 * Encode an instance of sbp_resource_bucket_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_resource_bucket_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_resource_bucket_encode(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_resource_bucket_t *msg);

/**
 * Decode an instance of sbp_resource_bucket_t from wire representation
 *
 * This function decodes the wire representation of a sbp_resource_bucket_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_resource_bucket_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
SBP_EXPORT s8 sbp_resource_bucket_decode(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_resource_bucket_t *msg);

/**
 * Compare two instances of sbp_resource_bucket_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_resource_bucket_t instance
 * @param b sbp_resource_bucket_t instance
 * @return 0, <0, >0
 */
SBP_EXPORT int sbp_resource_bucket_cmp(const sbp_resource_bucket_t *a,
                                       const sbp_resource_bucket_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_resource_bucket_t &lhs,
                              const sbp_resource_bucket_t &rhs) {
  return sbp_resource_bucket_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_resource_bucket_t &lhs,
                              const sbp_resource_bucket_t &rhs) {
  return sbp_resource_bucket_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_resource_bucket_t &lhs,
                             const sbp_resource_bucket_t &rhs) {
  return sbp_resource_bucket_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_resource_bucket_t &lhs,
                              const sbp_resource_bucket_t &rhs) {
  return sbp_resource_bucket_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_resource_bucket_t &lhs,
                             const sbp_resource_bucket_t &rhs) {
  return sbp_resource_bucket_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_resource_bucket_t &lhs,
                              const sbp_resource_bucket_t &rhs) {
  return sbp_resource_bucket_cmp(&lhs, &rhs) >= 0;
}

#endif  // ifdef __cplusplus

#endif /* LIBSBP_PROFILING_RESOURCEBUCKET_H */
