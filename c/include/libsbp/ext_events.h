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
 * Automatically generated from yaml/swiftnav/sbp/ext_events.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup ext_events Ext_events
 *
 *  * Messages reporting accurately-timestamped external events,
 * e.g. camera shutter time.
 * \{ */

#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_EXT_EVENTS_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** Reports timestamped external pin event
 *
 * Reports detection of an external event, the GPS time it occurred,
 * which pin it was and whether it was rising or falling.
 */
#define SBP_MSG_EXT_EVENT 0x0101
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

typedef struct SBP_ATTR_PACKED {
  u16 wn;             /**< GPS week number [weeks] */
  u32 tow;            /**< GPS time of week rounded to the nearest millisecond [ms] */
  s32 ns_residual;    /**< Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
  u8 flags;          /**< Flags */
  u8 pin;            /**< Pin number.  0..9 = DEBUG0..9. */
} msg_ext_event_t;
 

/** \} */
static inline void static_asserts_for_module_MSG_EXT_EVENT(void) {
#ifdef __cplusplus
static_assert(offsetof(msg_ext_event_t, wn ) == 0, "Offset of wn in msg_ext_event_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ext_event_t, wn ) == 0, offset_of_wn_in_msg_ext_event_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ext_event_t, tow ) == 0 + sizeof(u16), "Offset of tow in msg_ext_event_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ext_event_t, tow ) == 0 + sizeof(u16), offset_of_tow_in_msg_ext_event_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ext_event_t, ns_residual ) == 0 + sizeof(u16) + sizeof(u32), "Offset of ns_residual in msg_ext_event_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ext_event_t, ns_residual ) == 0 + sizeof(u16) + sizeof(u32), offset_of_ns_residual_in_msg_ext_event_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ext_event_t, flags ) == 0 + sizeof(u16) + sizeof(u32) + sizeof(s32), "Offset of flags in msg_ext_event_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ext_event_t, flags ) == 0 + sizeof(u16) + sizeof(u32) + sizeof(s32), offset_of_flags_in_msg_ext_event_t_is_incorrect)
#endif
#ifdef __cplusplus
static_assert(offsetof(msg_ext_event_t, pin ) == 0 + sizeof(u16) + sizeof(u32) + sizeof(s32) + sizeof(u8), "Offset of pin in msg_ext_event_t is incorrect");
#else
SBP_STATIC_ASSERT(SBP_OFFSET_OF(msg_ext_event_t, pin ) == 0 + sizeof(u16) + sizeof(u32) + sizeof(s32) + sizeof(u8), offset_of_pin_in_msg_ext_event_t_is_incorrect)
#endif
}


SBP_PACK_END

#endif /* LIBSBP_EXT_EVENTS_MESSAGES_H */
