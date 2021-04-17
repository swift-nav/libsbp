/*
 * Copyright (C) 2021 Swift Navigation Inc.
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

#ifndef LIBSBP_CPP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_CPP_EXT_EVENTS_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * Reports timestamped external pin event
   *
   * Reports detection of an external event, the GPS time it occurred,
   * which pin it was and whether it was rising or falling.
   */
  
  struct SBP_ATTR_PACKED MsgExtEvent {
    u16 wn; /** GPS week number [weeks] */
    u32 tow; /** GPS time of week rounded to the nearest millisecond [ms] */
    s32 ns_residual; /** Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
    u8 flags; /** Flags */
    u8 pin; /** Pin number.  0..9 = DEBUG0..9. */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_EXT_EVENTS_MESSAGES_H */