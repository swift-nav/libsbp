#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_EXT_EVENTS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>

#ifdef __cplusplus
  extern "C" {
#endif
#define SBP_EXT_EVENT_TIME_QUALITY_MASK (0x1)
#define SBP_EXT_EVENT_TIME_QUALITY_SHIFT (1u)
#define SBP_EXT_EVENT_TIME_QUALITY_GET(flags) \
                             (((flags) >> SBP_EXT_EVENT_TIME_QUALITY_SHIFT) \
                             & SBP_EXT_EVENT_TIME_QUALITY_MASK)
#define SBP_EXT_EVENT_TIME_QUALITY_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EXT_EVENT_TIME_QUALITY_MASK)) \
                             << (SBP_EXT_EVENT_TIME_QUALITY_SHIFT)));} while(0)
                             

#define SBP_EXT_EVENT_TIME_QUALITY_UNKNOWN_DONT_HAVE_NAV_SOLUTION (0)
#define SBP_EXT_EVENT_TIME_QUALITY_GOOD (1)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_MASK (0x1)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SHIFT (0u)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_GET(flags) \
                             (((flags) >> SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SHIFT) \
                             & SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_MASK)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_MASK)) \
                             << (SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_SHIFT)));} while(0)
                             

#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_LOW (0)
#define SBP_EXT_EVENT_NEW_LEVEL_OF_PIN_HIGH (1)
/** Reports timestamped external pin event
 *
((m.desc|commentify)))
 */
#define SBP_MSG_EXT_EVENT 0x0101
typedef struct {
  u16 wn;
  u32 tow;
  s32 ns_residual;
  u8 flags;
  u8 pin;
} sbp_msg_ext_event_t;

size_t sbp_packed_size_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *msg);
s8 sbp_pack_sbp_msg_ext_event_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_ext_event_t *msg);
s8 sbp_unpack_sbp_msg_ext_event_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_ext_event_t *msg);

int sbp_cmp_sbp_msg_ext_event_t(const sbp_msg_ext_event_t *a, const sbp_msg_ext_event_t *b);



#ifdef __cplusplus
  }
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

#endif /* LIBSBP_EXT_EVENTS_MESSAGES_H */
