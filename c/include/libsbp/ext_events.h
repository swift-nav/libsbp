#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_EXT_EVENTS_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Reports timestamped external pin event
 *
 * Reports detection of an external event, the GPS time it occurred,
 * which pin it was and whether it was rising or falling.
 */
#define SBP_MSG_EXT_EVENT 0x0101

#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_MASK (0x1)
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SHIFT (1u)
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_GET(flags)      \
  (((flags) >> SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SHIFT) & \
   SBP_EXT_EVENT_FLAGS_TIME_QUALITY_MASK)
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_EXT_EVENT_FLAGS_TIME_QUALITY_MASK)) \
                 << (SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SHIFT)));    \
  } while (0)

#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_UNKNOWN_DONT_HAVE_NAV_SOLUTION (0)
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_GOOD (1)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_MASK (0x1)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SHIFT (0u)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_GET(flags)      \
  (((flags) >> SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SHIFT) & \
   SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_MASK)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_MASK)) \
                 << (SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SHIFT)));    \
  } while (0)

#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_LOW (0)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_HIGH (1)
typedef struct {
  /**
   * GPS week number[weeks]
   */
  u16 wn;
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges
   * from -500000 to 500000)[ns]
   */
  s32 ns_residual;
  /**
   * Flags
   */
  u8 flags;
  /**
   * Pin number.  0..9 = DEBUG0..9.
   */
  u8 pin;
} sbp_msg_ext_event_t;

static inline size_t sbp_packed_size_sbp_msg_ext_event_t(
    const sbp_msg_ext_event_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) +
         sizeof(msg->flags) + sizeof(msg->pin);
}

static inline bool sbp_pack_sbp_msg_ext_event_t(
    u8 *buf, size_t len, const sbp_msg_ext_event_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ext_event_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgwn = msg->wn;
  msgwn = htole16(msgwn);
  memcpy(buf + offset, &msgwn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtow = msg->tow;
  msgtow = htole32(msgtow);
  memcpy(buf + offset, &msgtow, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgns_residual = msg->ns_residual;
  msgns_residual = htole32(msgns_residual);
  memcpy(buf + offset, &msgns_residual, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgpin = msg->pin;
  memcpy(buf + offset, &msgpin, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ext_event_t(const u8 *buf, size_t len,
                                                  sbp_msg_ext_event_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->ns_residual, buf + offset, 4);
  msg->ns_residual = le32toh(msg->ns_residual);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->pin, buf + offset, 1);
  offset += 1;
  return true;
}

#endif /* LIBSBP_EXT_EVENTS_MESSAGES_H */