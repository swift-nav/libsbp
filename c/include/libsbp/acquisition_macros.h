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
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_ACQUISITION_MACROS_H
#define LIBSBP_ACQUISITION_MACROS_H

/**
 * Encoded length of sbp_msg_acq_result_t
 */
#define SBP_MSG_ACQ_RESULT_ENCODED_LEN 14u

/**
 * Encoded length of sbp_msg_acq_result_dep_c_t
 */
#define SBP_MSG_ACQ_RESULT_DEP_C_ENCODED_LEN 16u

/**
 * Encoded length of sbp_msg_acq_result_dep_b_t
 */
#define SBP_MSG_ACQ_RESULT_DEP_B_ENCODED_LEN 16u

/**
 * Encoded length of sbp_msg_acq_result_dep_a_t
 */
#define SBP_MSG_ACQ_RESULT_DEP_A_ENCODED_LEN 13u

/**
 * Encoded length of sbp_acq_sv_profile_t
 */
#define SBP_ACQ_SV_PROFILE_ENCODED_LEN 33u

/**
 * Encoded length of sbp_acq_sv_profile_dep_t
 */
#define SBP_ACQ_SV_PROFILE_DEP_ENCODED_LEN 35u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_acq_sv_profile_t::acq_sv_profile before the maximum SBP message size
 * is exceeded
 */
#define SBP_MSG_ACQ_SV_PROFILE_ACQ_SV_PROFILE_MAX 7u

/**
 * Encoded length of sbp_msg_acq_sv_profile_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_acq_sv_profile_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ACQ_SV_PROFILE_ENCODED_OVERHEAD 0u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_acq_sv_profile_dep_t::acq_sv_profile before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_MAX 7u

/**
 * Encoded length of sbp_msg_acq_sv_profile_dep_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_acq_sv_profile_dep_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_ACQ_SV_PROFILE_DEP_ENCODED_OVERHEAD 0u

#endif /* LIBSBP_ACQUISITION_MACROS_H */
