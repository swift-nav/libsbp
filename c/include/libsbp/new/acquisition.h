/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_ACQUISITION_MESSAGES_H
#define LIBSBP_NEW_ACQUISITION_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
/** Satellite acquisition result
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_ACQUISITION_MESSAGES_H
#define SBP_MSG_ACQ_RESULT 0x002F
#endif
typedef struct {
  float cn0;
  float cp;
  float cf;
  sbp_sbp_gnss_signal_t sid;
} sbp_msg_acq_result_t;

size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg);
s8 sbp_encode_sbp_msg_acq_result_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_msg_acq_result_t *msg);
s8 sbp_decode_sbp_msg_acq_result_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_msg_acq_result_t *msg);
s8 sbp_send_sbp_msg_acq_result_t(struct sbp_state *s, u16 sender_id,
                                 const sbp_msg_acq_result_t *msg,
                                 s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *a,
                                 const sbp_msg_acq_result_t *b);

/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_ACQUISITION_MESSAGES_H
#define SBP_MSG_ACQ_RESULT_DEP_C 0x001F
#endif
typedef struct {
  float cn0;
  float cp;
  float cf;
  sbp_gnss_signal_dep_t sid;
} sbp_msg_acq_result_dep_c_t;

size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(
    const sbp_msg_acq_result_dep_c_t *msg);
s8 sbp_encode_sbp_msg_acq_result_dep_c_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_acq_result_dep_c_t *msg);
s8 sbp_decode_sbp_msg_acq_result_dep_c_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_acq_result_dep_c_t *msg);
s8 sbp_send_sbp_msg_acq_result_dep_c_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_acq_result_dep_c_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

int sbp_cmp_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *a,
                                       const sbp_msg_acq_result_dep_c_t *b);

/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_ACQUISITION_MESSAGES_H
#define SBP_MSG_ACQ_RESULT_DEP_B 0x0014
#endif
typedef struct {
  float snr;
  float cp;
  float cf;
  sbp_gnss_signal_dep_t sid;
} sbp_msg_acq_result_dep_b_t;

size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(
    const sbp_msg_acq_result_dep_b_t *msg);
s8 sbp_encode_sbp_msg_acq_result_dep_b_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_acq_result_dep_b_t *msg);
s8 sbp_decode_sbp_msg_acq_result_dep_b_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_acq_result_dep_b_t *msg);
s8 sbp_send_sbp_msg_acq_result_dep_b_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_acq_result_dep_b_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

int sbp_cmp_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *a,
                                       const sbp_msg_acq_result_dep_b_t *b);

/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_ACQUISITION_MESSAGES_H
#define SBP_MSG_ACQ_RESULT_DEP_A 0x0015
#endif
typedef struct {
  float snr;
  float cp;
  float cf;
  u8 prn;
} sbp_msg_acq_result_dep_a_t;

size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(
    const sbp_msg_acq_result_dep_a_t *msg);
s8 sbp_encode_sbp_msg_acq_result_dep_a_t(uint8_t *buf, uint8_t len,
                                         uint8_t *n_written,
                                         const sbp_msg_acq_result_dep_a_t *msg);
s8 sbp_decode_sbp_msg_acq_result_dep_a_t(const uint8_t *buf, uint8_t len,
                                         uint8_t *n_read,
                                         sbp_msg_acq_result_dep_a_t *msg);
s8 sbp_send_sbp_msg_acq_result_dep_a_t(struct sbp_state *s, u16 sender_id,
                                       const sbp_msg_acq_result_dep_a_t *msg,
                                       s32 (*write)(u8 *buff, u32 n,
                                                    void *context));

int sbp_cmp_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *a,
                                       const sbp_msg_acq_result_dep_a_t *b);

/** Acq perfomance measurement and debug
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 job_type;
  u8 status;
  u16 cn0;
  u8 int_time;
  sbp_sbp_gnss_signal_t sid;
  u16 bin_width;
  u32 timestamp;
  u32 time_spent;
  s32 cf_min;
  s32 cf_max;
  s32 cf;
  u32 cp;
} sbp_acq_sv_profile_t;

size_t sbp_packed_size_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *msg);
s8 sbp_encode_sbp_acq_sv_profile_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_acq_sv_profile_t *msg);
s8 sbp_decode_sbp_acq_sv_profile_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_acq_sv_profile_t *msg);

int sbp_cmp_sbp_acq_sv_profile_t(const sbp_acq_sv_profile_t *a,
                                 const sbp_acq_sv_profile_t *b);

/** Deprecated
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 job_type;
  u8 status;
  u16 cn0;
  u8 int_time;
  sbp_gnss_signal_dep_t sid;
  u16 bin_width;
  u32 timestamp;
  u32 time_spent;
  s32 cf_min;
  s32 cf_max;
  s32 cf;
  u32 cp;
} sbp_acq_sv_profile_dep_t;

size_t sbp_packed_size_sbp_acq_sv_profile_dep_t(
    const sbp_acq_sv_profile_dep_t *msg);
s8 sbp_encode_sbp_acq_sv_profile_dep_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_acq_sv_profile_dep_t *msg);
s8 sbp_decode_sbp_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_acq_sv_profile_dep_t *msg);

int sbp_cmp_sbp_acq_sv_profile_dep_t(const sbp_acq_sv_profile_dep_t *a,
                                     const sbp_acq_sv_profile_dep_t *b);

/** Acquisition perfomance measurement and debug
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_ACQUISITION_MESSAGES_H
#define SBP_MSG_ACQ_SV_PROFILE 0x002E
#endif
typedef struct {
  sbp_acq_sv_profile_t acq_sv_profile[7];
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_t;

size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(
    const sbp_msg_acq_sv_profile_t *msg);
s8 sbp_encode_sbp_msg_acq_sv_profile_t(uint8_t *buf, uint8_t len,
                                       uint8_t *n_written,
                                       const sbp_msg_acq_sv_profile_t *msg);
s8 sbp_decode_sbp_msg_acq_sv_profile_t(const uint8_t *buf, uint8_t len,
                                       uint8_t *n_read,
                                       sbp_msg_acq_sv_profile_t *msg);
s8 sbp_send_sbp_msg_acq_sv_profile_t(struct sbp_state *s, u16 sender_id,
                                     const sbp_msg_acq_sv_profile_t *msg,
                                     s32 (*write)(u8 *buff, u32 n,
                                                  void *context));

int sbp_cmp_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *a,
                                     const sbp_msg_acq_sv_profile_t *b);

/** Deprecated
 *
((m.desc|commentify)))
 */
#ifndef LIBSBP_LEGACY_ACQUISITION_MESSAGES_H
#define SBP_MSG_ACQ_SV_PROFILE_DEP 0x001E
#endif
typedef struct {
  sbp_acq_sv_profile_dep_t acq_sv_profile[7];
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_dep_t;

size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(
    const sbp_msg_acq_sv_profile_dep_t *msg);
s8 sbp_encode_sbp_msg_acq_sv_profile_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_acq_sv_profile_dep_t *msg);
s8 sbp_decode_sbp_msg_acq_sv_profile_dep_t(const uint8_t *buf, uint8_t len,
                                           uint8_t *n_read,
                                           sbp_msg_acq_sv_profile_dep_t *msg);
s8 sbp_send_sbp_msg_acq_sv_profile_dep_t(
    struct sbp_state *s, u16 sender_id, const sbp_msg_acq_sv_profile_dep_t *msg,
    s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *a,
                                         const sbp_msg_acq_sv_profile_dep_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_msg_acq_result_t &a,
                              const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_t &a,
                              const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_t &a,
                             const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_t &a,
                              const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_t &a,
                             const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_t &a,
                              const sbp_msg_acq_result_t &b) {
  return sbp_cmp_sbp_msg_acq_result_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_acq_result_dep_c_t &a,
                              const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_c_t &a,
                              const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_c_t &a,
                             const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_c_t &a,
                              const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_c_t &a,
                             const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_c_t &a,
                              const sbp_msg_acq_result_dep_c_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_c_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_acq_result_dep_b_t &a,
                              const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_b_t &a,
                              const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_b_t &a,
                             const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_b_t &a,
                              const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_b_t &a,
                             const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_b_t &a,
                              const sbp_msg_acq_result_dep_b_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_b_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_acq_result_dep_a_t &a,
                              const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_result_dep_a_t &a,
                              const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_result_dep_a_t &a,
                             const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_result_dep_a_t &a,
                              const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_result_dep_a_t &a,
                             const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_result_dep_a_t &a,
                              const sbp_msg_acq_result_dep_a_t &b) {
  return sbp_cmp_sbp_msg_acq_result_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_acq_sv_profile_t &a,
                              const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_t &a,
                              const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_t &a,
                             const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_t &a,
                              const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_t &a,
                             const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_t &a,
                              const sbp_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_acq_sv_profile_dep_t &a,
                              const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_acq_sv_profile_dep_t &a,
                              const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_acq_sv_profile_dep_t &a,
                             const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_acq_sv_profile_dep_t &a,
                              const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_acq_sv_profile_dep_t &a,
                             const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_acq_sv_profile_dep_t &a,
                              const sbp_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_acq_sv_profile_dep_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_acq_sv_profile_t &a,
                              const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_t &a,
                              const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_sv_profile_t &a,
                             const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_sv_profile_t &a,
                              const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_sv_profile_t &a,
                             const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_sv_profile_t &a,
                              const sbp_msg_acq_sv_profile_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_acq_sv_profile_dep_t &a,
                              const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_acq_sv_profile_dep_t &a,
                              const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_acq_sv_profile_dep_t &a,
                             const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_acq_sv_profile_dep_t &a,
                              const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_acq_sv_profile_dep_t &a,
                             const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_acq_sv_profile_dep_t &a,
                              const sbp_msg_acq_sv_profile_dep_t &b) {
  return sbp_cmp_sbp_msg_acq_sv_profile_dep_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_NEW_ACQUISITION_MESSAGES_H */
