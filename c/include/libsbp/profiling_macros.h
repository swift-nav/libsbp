/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/profiling.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_PROFILING_MACROS_H
#define LIBSBP_PROFILING_MACROS_H

/**
 * The maximum number of items that can be stored in
 * sbp_msg_measurement_point_t::func before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_MEASUREMENT_POINT_FUNC_MAX 215u

/**
 * Encoded length of sbp_msg_measurement_point_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_measurement_point_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_MEASUREMENT_POINT_ENCODED_OVERHEAD 40u

/**
 * Encoded length of sbp_msg_profiling_system_info_t
 */
#define SBP_MSG_PROFILING_SYSTEM_INFO_ENCODED_LEN 21u

#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_MASK (0x3u)
#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_SHIFT (0u)
#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_PROFILING_THREAD_INFO_THREAD_STATE_SHIFT) & \
        SBP_PROFILING_THREAD_INFO_THREAD_STATE_MASK))
#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_SET(flags, val)                \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags & (~(SBP_PROFILING_THREAD_INFO_THREAD_STATE_MASK          \
                         << SBP_PROFILING_THREAD_INFO_THREAD_STATE_SHIFT))) | \
             (((val) & (SBP_PROFILING_THREAD_INFO_THREAD_STATE_MASK))         \
              << (SBP_PROFILING_THREAD_INFO_THREAD_STATE_SHIFT)));            \
  } while (0)

#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_EXTERNAL (0)
#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_RUNNING (1)
#define SBP_PROFILING_THREAD_INFO_THREAD_STATE_STOPPED (2)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_profiling_thread_info_t::name before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_PROFILING_THREAD_INFO_NAME_MAX 230u

/**
 * Encoded length of sbp_msg_profiling_thread_info_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_profiling_thread_info_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_PROFILING_THREAD_INFO_ENCODED_OVERHEAD 25u

/**
 * The maximum number of items that can be stored in sbp_resource_bucket_t::name
 * before the maximum SBP message size is exceeded
 */
#define SBP_RESOURCE_BUCKET_NAME_MAX 21u

/**
 * Encoded length of sbp_resource_bucket_t
 */
#define SBP_RESOURCE_BUCKET_ENCODED_LEN 41u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_profiling_resource_counter_t::buckets before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_PROFILING_RESOURCE_COUNTER_BUCKETS_MAX 6u

/**
 * Encoded length of sbp_msg_profiling_resource_counter_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_profiling_resource_counter_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_PROFILING_RESOURCE_COUNTER_ENCODED_OVERHEAD 2u

#endif /* LIBSBP_PROFILING_MACROS_H */
