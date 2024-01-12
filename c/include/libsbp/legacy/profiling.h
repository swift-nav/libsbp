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
 * Automatically generated from yaml/swiftnav/sbp/profiling.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup profiling Profiling
 *
 * Standardized profiling messages from Swift Navigation devices.
 * \{ */

#ifndef LIBSBP_LEGACY_PROFILING_MESSAGES_H
#define LIBSBP_LEGACY_PROFILING_MESSAGES_H

#include <libsbp/common.h>

SBP_MESSAGE(
    "The legacy libsbp API has been deprecated. This file and all symbols "
    "contained will "
    "be removed in version 6. You should immediately switch over to the modern "
    "libsbp API.")

#include <libsbp/profiling_macros.h>

SBP_PACK_START

/** Profiling Measurement Point
 *
 * Tracks execution time of certain code paths in specially built products.
 * This message should only be expected and processed on the direction of
 * Swift's engineering teams.
 */

typedef struct SBP_ATTR_PACKED SBP_DEPRECATED {
  u32 total_time;     /**< Total time spent in measurement point
                           (microseconds) */
  u16 num_executions; /**< Number of times measurement point has executed */
  u32 min;            /**< Minimum execution time (microseconds) */
  u32 max;            /**< Maximum execution time (microseconds) */
  u64 return_addr;    /**< Return address */
  u64 id;             /**< Unique ID */
  u64 slice_time;     /**< CPU slice time (milliseconds) */
  u16 line;           /**< Line number */
  char func[0];       /**< Function name */
} msg_measurement_point_t;

/** System Profiling Information
 *
 * Contains basic information about system resource usage. System is defined
 * in terms of the source of this message and may vary from  sender to sender.
 * Refer to product documentation to understand the exact scope and meaning of
 * this message.
 */

typedef struct SBP_ATTR_PACKED SBP_DEPRECATED {
  u64 total_cpu_time; /**< Total cpu time in microseconds consumed by this
                           system */
  u64 age;            /**< Age of the producing system in microseconds */
  u8 n_threads;       /**< Number of threads being tracked by this system */
} msg_profiling_system_info_t;

/** Thread Profiling Information
 *
 * Contains profiling information related to a single thread being tracked by
 * the producing system. Refer to product documentation to understand the
 * exact scope and meaning of this message.
 */

typedef struct SBP_ATTR_PACKED SBP_DEPRECATED {
  u64 total_cpu_time; /**< Total cpu time in microseconds consumed by this
                           thread */
  u64 age;            /**< Age of the thread in microseconds */
  u8 state;           /**< Thread state */
  u32 stack_size;     /**< Stack size in bytes */
  u32 stack_usage;    /**< Stack highwater usage in bytes */
  char name[0];       /**< Thread name */
} msg_profiling_thread_info_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_PROFILING_MESSAGES_H */