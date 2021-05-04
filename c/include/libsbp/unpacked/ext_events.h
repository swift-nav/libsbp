#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_EXT_EVENTS_MESSAGES_H

#include <endian.h>
#include <math.h>
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
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_GET(flags) \
  (((flags) >> SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SHIFT) & SBP_EXT_EVENT_FLAGS_TIME_QUALITY_MASK)
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_EXT_EVENT_FLAGS_TIME_QUALITY_MASK)) << (SBP_EXT_EVENT_FLAGS_TIME_QUALITY_SHIFT))); \
  } while (0)

#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_UNKNOWN_DONT_HAVE_NAV_SOLUTION (0)
#define SBP_EXT_EVENT_FLAGS_TIME_QUALITY_GOOD (1)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_MASK (0x1)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SHIFT (0u)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_GET(flags) \
  (((flags) >> SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SHIFT) & SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_MASK)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_MASK)) << (SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_SHIFT))); \
  } while (0)

#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_LOW (0)
#define SBP_EXT_EVENT_FLAGS_NEW_LEVEL_OF_PIN_HIGH (1)
typedef struct
{

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

#include <libsbp/unpacked/ext_events_operators.h>
#include <libsbp/unpacked/ext_events_packers.h>

#endif /* LIBSBP_EXT_EVENTS_MESSAGES_H */
