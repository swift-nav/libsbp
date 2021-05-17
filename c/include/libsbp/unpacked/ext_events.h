#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_EXT_EVENTS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
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




#include <libsbp/unpacked/ext_events_operators.h>
#include <libsbp/unpacked/ext_events_packers.h>

#endif /* LIBSBP_EXT_EVENTS_MESSAGES_H */
