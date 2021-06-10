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

#ifndef LIBSBP_EXT_EVENTS_MACROS_H
#define LIBSBP_EXT_EVENTS_MACROS_H


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

#endif