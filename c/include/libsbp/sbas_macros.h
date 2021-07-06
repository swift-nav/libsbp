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
 * Automatically generated from yaml/swiftnav/sbp/sbas.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SBAS_MACROS_H
#define LIBSBP_SBAS_MACROS_H

#define SBP_MSG_SBAS_RAW 0x7777
/**
 * The maximum number of items that can be stored in sbp_msg_sbas_raw_t::data
 * (V4 API) or msg_sbas_raw_t::data (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SBAS_RAW_DATA_MAX 27u

/**
 * Encoded length of sbp_msg_sbas_raw_t (V4 API) and
 * msg_sbas_raw_t (legacy API)
 */
#define SBP_MSG_SBAS_RAW_ENCODED_LEN 34u

#endif /* LIBSBP_SBAS_MACROS_H */
