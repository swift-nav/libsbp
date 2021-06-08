/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * Messages reporting accurately-timestamped external events, e.g. camera
 * shutter time.
 * \{ */

#ifndef LIBSBP_LEGACY_EXT_EVENTS_MESSAGES_H
#define LIBSBP_LEGACY_EXT_EVENTS_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/ext_events_macros.h>

SBP_PACK_START

/** Reports timestamped external pin event
 *
 * Reports detection of an external event, the GPS time it occurred, which pin
 * it was and whether it was rising or falling.
 */

typedef struct SBP_ATTR_PACKED {
  u16 wn;  /**< GPS week number [weeks] */
  u32 tow; /**< GPS time of week rounded to the nearest millisecond [ms] */
  s32 ns_residual; /**< Nanosecond residual of millisecond-rounded TOW
                        (ranges from -500000 to 500000) [ns] */
  u8 flags;        /**< Flags */
  u8 pin;          /**< Pin number.  0..9 = DEBUG0..9. */
} msg_ext_event_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_EXT_EVENTS_MESSAGES_H */