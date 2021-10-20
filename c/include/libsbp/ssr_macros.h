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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SSR_MACROS_H
#define LIBSBP_SSR_MACROS_H

/**
 * Encoded length of sbp_code_biases_content_t (V4 API) and
 * code_biases_content_t (legacy API)
 */
#define SBP_CODE_BIASES_CONTENT_ENCODED_LEN 3u

/**
 * Encoded length of sbp_phase_biases_content_t (V4 API) and
 * phase_biases_content_t (legacy API)
 */
#define SBP_PHASE_BIASES_CONTENT_ENCODED_LEN 8u

/**
 * Encoded length of sbp_stec_header_t (V4 API) and
 * stec_header_t (legacy API)
 */
#define SBP_STEC_HEADER_ENCODED_LEN 14u

/**
 * Encoded length of sbp_gridded_correction_header_t (V4 API) and
 * gridded_correction_header_t (legacy API)
 */
#define SBP_GRIDDED_CORRECTION_HEADER_ENCODED_LEN 17u

/**
 * The maximum number of items that can be stored in
 * sbp_stec_sat_element_t::stec_coeff (V4 API) or stec_sat_element_t::stec_coeff
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_STEC_SAT_ELEMENT_STEC_COEFF_MAX 4u

/**
 * Encoded length of sbp_stec_sat_element_t (V4 API) and
 * stec_sat_element_t (legacy API)
 */
#define SBP_STEC_SAT_ELEMENT_ENCODED_LEN 11u

/**
 * Encoded length of sbp_tropospheric_delay_correction_no_std_t (V4 API) and
 * tropospheric_delay_correction_no_std_t (legacy API)
 */
#define SBP_TROPOSPHERIC_DELAY_CORRECTION_NO_STD_ENCODED_LEN 3u

/**
 * Encoded length of sbp_tropospheric_delay_correction_t (V4 API) and
 * tropospheric_delay_correction_t (legacy API)
 */
#define SBP_TROPOSPHERIC_DELAY_CORRECTION_ENCODED_LEN 4u

/**
 * Encoded length of sbp_stec_residual_no_std_t (V4 API) and
 * stec_residual_no_std_t (legacy API)
 */
#define SBP_STEC_RESIDUAL_NO_STD_ENCODED_LEN 4u

/**
 * Encoded length of sbp_stec_residual_t (V4 API) and
 * stec_residual_t (legacy API)
 */
#define SBP_STEC_RESIDUAL_ENCODED_LEN 5u

#define SBP_MSG_SSR_ORBIT_CLOCK 0x05DD
/**
 * Encoded length of sbp_msg_ssr_orbit_clock_t (V4 API) and
 * msg_ssr_orbit_clock_t (legacy API)
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_ENCODED_LEN 50u

#define SBP_MSG_SSR_CODE_BIASES 0x05E1
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_code_biases_t::biases (V4 API) or msg_ssr_code_biases_t::biases
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_CODE_BIASES_BIASES_MAX 81u

/**
 * Encoded length of sbp_msg_ssr_code_biases_t (V4 API) and
 * msg_ssr_code_biases_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_code_biases_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_CODE_BIASES_ENCODED_OVERHEAD 10u

#define SBP_MSG_SSR_PHASE_BIASES 0x05E6
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_phase_biases_t::biases (V4 API) or msg_ssr_phase_biases_t::biases
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_PHASE_BIASES_BIASES_MAX 30u

/**
 * Encoded length of sbp_msg_ssr_phase_biases_t (V4 API) and
 * msg_ssr_phase_biases_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_phase_biases_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_PHASE_BIASES_ENCODED_OVERHEAD 15u

#define SBP_MSG_SSR_STEC_CORRECTION 0x05FB
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_stec_correction_t::stec_sat_list (V4 API) or
 * msg_ssr_stec_correction_t::stec_sat_list (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_STEC_CORRECTION_STEC_SAT_LIST_MAX 21u

/**
 * Encoded length of sbp_msg_ssr_stec_correction_t (V4 API) and
 * msg_ssr_stec_correction_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_stec_correction_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_STEC_CORRECTION_ENCODED_OVERHEAD 14u

#define SBP_MSG_SSR_GRIDDED_CORRECTION 0x05FC
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_t::stec_residuals (V4 API) or
 * msg_ssr_gridded_correction_t::stec_residuals (legacy API) before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_STEC_RESIDUALS_MAX 46u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_t (V4 API) and
 * msg_ssr_gridded_correction_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_gridded_correction_encoded_len to determine the actual size of
 * an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_ENCODED_OVERHEAD 23u

#define SBP_MSG_SSR_TILE_DEFINITION 0x05F6
/**
 * Encoded length of sbp_msg_ssr_tile_definition_t (V4 API) and
 * msg_ssr_tile_definition_t (legacy API)
 */
#define SBP_MSG_SSR_TILE_DEFINITION_ENCODED_LEN 24u

#define SBP_SATELLITEAPC_SATELLITE_TYPE_MASK (0x1f)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT (0u)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GET(flags)           \
  ((u8)(((flags) >> SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT) & \
        SBP_SATELLITEAPC_SATELLITE_TYPE_MASK))
#define SBP_SATELLITEAPC_SATELLITE_TYPE_SET(flags, val)                        \
  do {                                                                         \
    (flags) = (u8)((flags) | (((val) & (SBP_SATELLITEAPC_SATELLITE_TYPE_MASK)) \
                              << (SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT)));    \
  } while (0)

#define SBP_SATELLITEAPC_SATELLITE_TYPE_UNKNOWN_TYPE (0)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_I (1)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_II (2)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_IIA (3)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_IIR (4)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_IIF (5)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GPS_III (6)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GLONASS (7)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GLONASS_M (8)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GLONASS_K1 (9)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GALILEO (10)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_2G (11)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_2I (12)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_2M (13)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3M_SECM (14)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3G_SECM (15)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3M_CAST (16)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3G_CAST (17)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3I_CAST (18)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_QZSS (19)
/**
 * The maximum number of items that can be stored in sbp_satellite_apc_t::pco
 * (V4 API) or satellite_apc_t::pco (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_SATELLITE_APC_PCO_MAX 3u

/**
 * The maximum number of items that can be stored in sbp_satellite_apc_t::pcv
 * (V4 API) or satellite_apc_t::pcv (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_SATELLITE_APC_PCV_MAX 21u

/**
 * Encoded length of sbp_satellite_apc_t (V4 API) and
 * satellite_apc_t (legacy API)
 */
#define SBP_SATELLITE_APC_ENCODED_LEN 32u

#define SBP_MSG_SSR_SATELLITE_APC 0x0604
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_satellite_apc_t::apc (V4 API) or msg_ssr_satellite_apc_t::apc
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_SATELLITE_APC_APC_MAX 7u

/**
 * Encoded length of sbp_msg_ssr_satellite_apc_t (V4 API) and
 * msg_ssr_satellite_apc_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_satellite_apc_encoded_len to determine the actual size of an
 * instance of this message. Users of the legacy API are required to track the
 * encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_SATELLITE_APC_ENCODED_OVERHEAD 0u

#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A 0x05DC
/**
 * Encoded length of sbp_msg_ssr_orbit_clock_dep_a_t (V4 API) and
 * msg_ssr_orbit_clock_dep_a_t (legacy API)
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A_ENCODED_LEN 47u

/**
 * Encoded length of sbp_stec_header_dep_a_t (V4 API) and
 * stec_header_dep_a_t (legacy API)
 */
#define SBP_STEC_HEADER_DEP_A_ENCODED_LEN 10u

/**
 * Encoded length of sbp_gridded_correction_header_dep_a_t (V4 API) and
 * gridded_correction_header_dep_a_t (legacy API)
 */
#define SBP_GRIDDED_CORRECTION_HEADER_DEP_A_ENCODED_LEN 13u

/**
 * Encoded length of sbp_grid_definition_header_dep_a_t (V4 API) and
 * grid_definition_header_dep_a_t (legacy API)
 */
#define SBP_GRID_DEFINITION_HEADER_DEP_A_ENCODED_LEN 9u

#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A 0x05EB
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_stec_correction_dep_a_t::stec_sat_list (V4 API) or
 * msg_ssr_stec_correction_dep_a_t::stec_sat_list (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A_STEC_SAT_LIST_MAX 22u

/**
 * Encoded length of sbp_msg_ssr_stec_correction_dep_a_t (V4 API) and
 * msg_ssr_stec_correction_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_stec_correction_dep_a_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A_ENCODED_OVERHEAD 10u

#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A 0x05F0
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_no_std_dep_a_t::stec_residuals (V4 API) or
 * msg_ssr_gridded_correction_no_std_dep_a_t::stec_residuals (legacy API) before
 * the maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A_STEC_RESIDUALS_MAX 59u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_no_std_dep_a_t (V4 API) and
 * msg_ssr_gridded_correction_no_std_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len to determine the
 * actual size of an instance of this message. Users of the legacy API are
 * required to track the encoded message length when interacting with the legacy
 * type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A_ENCODED_OVERHEAD 18u

#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A 0x05FA
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_dep_a_t::stec_residuals (V4 API) or
 * msg_ssr_gridded_correction_dep_a_t::stec_residuals (legacy API) before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A_STEC_RESIDUALS_MAX 47u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_dep_a_t (V4 API) and
 * msg_ssr_gridded_correction_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_gridded_correction_dep_a_encoded_len to determine the actual
 * size of an instance of this message. Users of the legacy API are required to
 * track the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A_ENCODED_OVERHEAD 19u

#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A 0x05F5
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_grid_definition_dep_a_t::rle_list (V4 API) or
 * msg_ssr_grid_definition_dep_a_t::rle_list (legacy API) before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A_RLE_LIST_MAX 246u

/**
 * Encoded length of sbp_msg_ssr_grid_definition_dep_a_t (V4 API) and
 * msg_ssr_grid_definition_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_ssr_grid_definition_dep_a_encoded_len to determine the actual size
 * of an instance of this message. Users of the legacy API are required to track
 * the encoded message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A_ENCODED_OVERHEAD 9u

#endif /* LIBSBP_SSR_MACROS_H */
