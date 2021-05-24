#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#define LIBSBP_ORIENTATION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/double_null_terminated.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
#define SBP_BASELINE_HEADING_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_HEADING_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_HEADING_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_FIX_MODE_INVALID (0)
#define SBP_BASELINE_HEADING_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_HEADING_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_HEADING_FIX_MODE_FIXED_RTK (4)
/** Heading relative to True North
 *
((m.desc|commentify)))
 */
#define SBP_MSG_BASELINE_HEADING 0x020F
typedef struct {
  u32 tow;
  u32 heading;
  u8 n_sats;
  u8 flags;
} sbp_msg_baseline_heading_t;

size_t sbp_packed_size_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *msg);
s8 sbp_pack_sbp_msg_baseline_heading_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_baseline_heading_t *msg);
s8 sbp_unpack_sbp_msg_baseline_heading_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_baseline_heading_t *msg);
s8 sbp_send_sbp_msg_baseline_heading_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_baseline_heading_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *a, const sbp_msg_baseline_heading_t *b);


#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_INS_NAVIGATION_MODE_VALID (1)
/** Quaternion 4 component vector
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ORIENT_QUAT      0x0220
typedef struct {
  u32 tow;
  s32 w;
  s32 x;
  s32 y;
  s32 z;
  float w_accuracy;
  float x_accuracy;
  float y_accuracy;
  float z_accuracy;
  u8 flags;
} sbp_msg_orient_quat_t;

size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg);
s8 sbp_pack_sbp_msg_orient_quat_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_orient_quat_t *msg);
s8 sbp_unpack_sbp_msg_orient_quat_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_orient_quat_t *msg);
s8 sbp_send_sbp_msg_orient_quat_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_orient_quat_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *a, const sbp_msg_orient_quat_t *b);


#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ORIENT_EULER_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_EULER_INS_NAVIGATION_MODE_VALID (1)
/** Euler angles
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ORIENT_EULER     0x0221
typedef struct {
  u32 tow;
  s32 roll;
  s32 pitch;
  s32 yaw;
  float roll_accuracy;
  float pitch_accuracy;
  float yaw_accuracy;
  u8 flags;
} sbp_msg_orient_euler_t;

size_t sbp_packed_size_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *msg);
s8 sbp_pack_sbp_msg_orient_euler_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_orient_euler_t *msg);
s8 sbp_unpack_sbp_msg_orient_euler_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_orient_euler_t *msg);
s8 sbp_send_sbp_msg_orient_euler_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_orient_euler_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *a, const sbp_msg_orient_euler_t *b);


#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ANGULAR_RATE_INS_NAVIGATION_MODE_VALID (1)
/** Vehicle Body Frame instantaneous angular rates
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ANGULAR_RATE     0x0222
typedef struct {
  u32 tow;
  s32 x;
  s32 y;
  s32 z;
  u8 flags;
} sbp_msg_angular_rate_t;

size_t sbp_packed_size_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *msg);
s8 sbp_pack_sbp_msg_angular_rate_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_angular_rate_t *msg);
s8 sbp_unpack_sbp_msg_angular_rate_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_angular_rate_t *msg);
s8 sbp_send_sbp_msg_angular_rate_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_angular_rate_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *a, const sbp_msg_angular_rate_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_baseline_heading_t &a, const sbp_msg_baseline_heading_t &b) {
  return sbp_cmp_sbp_msg_baseline_heading_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_orient_quat_t &a, const sbp_msg_orient_quat_t &b) {
  return sbp_cmp_sbp_msg_orient_quat_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_orient_euler_t &a, const sbp_msg_orient_euler_t &b) {
  return sbp_cmp_sbp_msg_orient_euler_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_angular_rate_t &a, const sbp_msg_angular_rate_t &b) {
  return sbp_cmp_sbp_msg_angular_rate_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_ORIENTATION_MESSAGES_H */
