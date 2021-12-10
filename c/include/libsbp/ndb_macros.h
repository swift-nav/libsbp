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
 * Automatically generated from yaml/swiftnav/sbp/ndb.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NDB_MACROS_H
#define LIBSBP_NDB_MACROS_H

#define SBP_MSG_NDB_EVENT 0x0400
#define SBP_NDB_EVENT_EVENT_TYPE_MASK (0x3)
#define SBP_NDB_EVENT_EVENT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_NDB_EVENT_EVENT_TYPE_SHIFT) & \
        SBP_NDB_EVENT_EVENT_TYPE_MASK))
#define SBP_NDB_EVENT_EVENT_TYPE_SET(flags, val)                        \
  do {                                                                  \
    (flags) = (u8)((flags) | (((val) & (SBP_NDB_EVENT_EVENT_TYPE_MASK)) \
                              << (SBP_NDB_EVENT_EVENT_TYPE_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_EVENT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_TYPE_STORE (1)
#define SBP_NDB_EVENT_EVENT_TYPE_FETCH (2)
#define SBP_NDB_EVENT_EVENT_TYPE_ERASE (3)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK (0x7)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT) & \
        SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK))
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SET(flags, val)                        \
  do {                                                                         \
    (flags) = (u8)((flags) | (((val) & (SBP_NDB_EVENT_EVENT_OBJECT_TYPE_MASK)) \
                              << (SBP_NDB_EVENT_EVENT_OBJECT_TYPE_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_UNKNOWN (0)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_EPHEMERIS (1)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_ALMANAC (2)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_ALMANAC_WN (3)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_IONO (4)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_L2C_CAP (5)
#define SBP_NDB_EVENT_EVENT_OBJECT_TYPE_LGF (6)
#define SBP_NDB_EVENT_EVENT_RESULT_MASK (0xf)
#define SBP_NDB_EVENT_EVENT_RESULT_SHIFT (0u)
#define SBP_NDB_EVENT_EVENT_RESULT_GET(flags)           \
  ((u8)(((flags) >> SBP_NDB_EVENT_EVENT_RESULT_SHIFT) & \
        SBP_NDB_EVENT_EVENT_RESULT_MASK))
#define SBP_NDB_EVENT_EVENT_RESULT_SET(flags, val)                        \
  do {                                                                    \
    (flags) = (u8)((flags) | (((val) & (SBP_NDB_EVENT_EVENT_RESULT_MASK)) \
                              << (SBP_NDB_EVENT_EVENT_RESULT_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NONE (0)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_MISSING_IE (1)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_UNSUPPORTED (2)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_FILE_IO (3)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_INIT_DONE (4)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_BAD_PARAM (5)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_UNRELIABLE_DATA (6)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_ALGORITHM_ERROR (7)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NO_DATA (8)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_NO_CHANGE (9)
#define SBP_NDB_EVENT_EVENT_RESULT_NDB_ERR_OLDER_DATA (10)
#define SBP_NDB_EVENT_DATA_SOURCE_MASK (0x3)
#define SBP_NDB_EVENT_DATA_SOURCE_SHIFT (0u)
#define SBP_NDB_EVENT_DATA_SOURCE_GET(flags)           \
  ((u8)(((flags) >> SBP_NDB_EVENT_DATA_SOURCE_SHIFT) & \
        SBP_NDB_EVENT_DATA_SOURCE_MASK))
#define SBP_NDB_EVENT_DATA_SOURCE_SET(flags, val)                        \
  do {                                                                   \
    (flags) = (u8)((flags) | (((val) & (SBP_NDB_EVENT_DATA_SOURCE_MASK)) \
                              << (SBP_NDB_EVENT_DATA_SOURCE_SHIFT)));    \
  } while (0)

#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_UNDEFINED (0)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_INIT (1)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_RECEIVER (2)
#define SBP_NDB_EVENT_DATA_SOURCE_NDB_DS_SBP (3)
/**
 * Encoded length of sbp_msg_ndb_event_t (V4 API) and
 * msg_ndb_event_t (legacy API)
 */
#define SBP_MSG_NDB_EVENT_ENCODED_LEN 18u

#endif /* LIBSBP_NDB_MACROS_H */
