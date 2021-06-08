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
 * Automatically generated from yaml/swiftnav/sbp/system.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SYSTEM_MACROS_H
#define LIBSBP_SYSTEM_MACROS_H

#define SBP_MSG_GROUP_META 0xFF0A
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK (0x3)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT (0u)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GET(flags)      \
  (((flags) >> SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT) & \
   SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_GROUP_META_SOLUTION_GROUP_TYPE_MASK)) \
                 << (SBP_GROUP_META_SOLUTION_GROUP_TYPE_SHIFT)));    \
  } while (0)

#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_NONE (0)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSS_ONLY (1)
#define SBP_GROUP_META_SOLUTION_GROUP_TYPE_GNSSINS (2)

#endif