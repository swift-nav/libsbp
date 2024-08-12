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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SSR_MACROS_H
#define LIBSBP_SSR_MACROS_H

/**
 * Encoded length of sbp_code_biases_content_t
 */
#define SBP_CODE_BIASES_CONTENT_ENCODED_LEN 3u

/**
 * Encoded length of sbp_phase_biases_content_t
 */
#define SBP_PHASE_BIASES_CONTENT_ENCODED_LEN 8u

/**
 * Encoded length of sbp_stec_header_t
 */
#define SBP_STEC_HEADER_ENCODED_LEN 14u

/**
 * Encoded length of sbp_gridded_correction_header_t
 */
#define SBP_GRIDDED_CORRECTION_HEADER_ENCODED_LEN 17u

/**
 * The maximum number of items that can be stored in
 * sbp_stec_sat_element_t::stec_coeff before the maximum SBP message size is
 * exceeded
 */
#define SBP_STEC_SAT_ELEMENT_STEC_COEFF_MAX 4u

/**
 * Encoded length of sbp_stec_sat_element_t
 */
#define SBP_STEC_SAT_ELEMENT_ENCODED_LEN 11u

/**
 * Encoded length of sbp_tropospheric_delay_correction_no_std_t
 */
#define SBP_TROPOSPHERIC_DELAY_CORRECTION_NO_STD_ENCODED_LEN 3u

/**
 * Encoded length of sbp_tropospheric_delay_correction_t
 */
#define SBP_TROPOSPHERIC_DELAY_CORRECTION_ENCODED_LEN 4u

/**
 * Encoded length of sbp_stec_residual_no_std_t
 */
#define SBP_STEC_RESIDUAL_NO_STD_ENCODED_LEN 4u

/**
 * Encoded length of sbp_stec_residual_t
 */
#define SBP_STEC_RESIDUAL_ENCODED_LEN 5u

/**
 * Encoded length of sbp_msg_ssr_orbit_clock_t
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_ENCODED_LEN 50u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_code_biases_t::biases before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_SSR_CODE_BIASES_BIASES_MAX 81u

/**
 * Encoded length of sbp_msg_ssr_code_biases_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_code_biases_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_CODE_BIASES_ENCODED_OVERHEAD 10u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_phase_biases_t::biases before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_SSR_PHASE_BIASES_BIASES_MAX 30u

/**
 * Encoded length of sbp_msg_ssr_phase_biases_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_phase_biases_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_PHASE_BIASES_ENCODED_OVERHEAD 15u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_stec_correction_dep_t::stec_sat_list before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_STEC_SAT_LIST_MAX 21u

/**
 * Encoded length of sbp_msg_ssr_stec_correction_dep_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_stec_correction_dep_encoded_len to determine the actual size of
 * an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_ENCODED_OVERHEAD 14u

/**
 * Encoded length of sbp_bounds_header_t
 */
#define SBP_BOUNDS_HEADER_ENCODED_LEN 10u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_stec_correction_t::stec_sat_list before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SSR_STEC_CORRECTION_STEC_SAT_LIST_MAX 21u

/**
 * Encoded length of sbp_msg_ssr_stec_correction_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_stec_correction_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_STEC_CORRECTION_ENCODED_OVERHEAD 16u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_t::stec_residuals before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_STEC_RESIDUALS_MAX 46u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_gridded_correction_encoded_len to determine the actual size of
 * an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_ENCODED_OVERHEAD 23u

/**
 * Encoded length of sbp_stec_sat_element_integrity_t
 */
#define SBP_STEC_SAT_ELEMENT_INTEGRITY_ENCODED_LEN 9u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_bounds_t::stec_sat_list before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_STEC_SAT_LIST_MAX 25u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_bounds_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_gridded_correction_bounds_encoded_len to determine the actual
 * size of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_BOUNDS_ENCODED_OVERHEAD 27u

/**
 * Encoded length of sbp_msg_ssr_tile_definition_dep_a_t
 */
#define SBP_MSG_SSR_TILE_DEFINITION_DEP_A_ENCODED_LEN 24u

/**
 * Encoded length of sbp_msg_ssr_tile_definition_dep_b_t
 */
#define SBP_MSG_SSR_TILE_DEFINITION_DEP_B_ENCODED_LEN 25u

/**
 * Encoded length of sbp_msg_ssr_tile_definition_t
 */
#define SBP_MSG_SSR_TILE_DEFINITION_ENCODED_LEN 33u

#define SBP_SATELLITEAPC_SATELLITE_TYPE_MASK (0x1fu)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT (0u)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT) & \
        SBP_SATELLITEAPC_SATELLITE_TYPE_MASK))
#define SBP_SATELLITEAPC_SATELLITE_TYPE_SET(flags, val)                      \
  do {                                                                       \
    (flags) = (u8)((flags & (~(SBP_SATELLITEAPC_SATELLITE_TYPE_MASK          \
                               << SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT))) | \
                   (((val) & (SBP_SATELLITEAPC_SATELLITE_TYPE_MASK))         \
                    << (SBP_SATELLITEAPC_SATELLITE_TYPE_SHIFT)));            \
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
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3I (20)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3SM_CAST (21)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3SI_CAST (22)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3SM_SECM (23)
#define SBP_SATELLITEAPC_SATELLITE_TYPE_BEIDOU_3SI_SECM (24)
/**
 * The maximum number of items that can be stored in sbp_satellite_apc_t::pco
 * before the maximum SBP message size is exceeded
 */
#define SBP_SATELLITE_APC_PCO_MAX 3u

/**
 * The maximum number of items that can be stored in sbp_satellite_apc_t::pcv
 * before the maximum SBP message size is exceeded
 */
#define SBP_SATELLITE_APC_PCV_MAX 21u

/**
 * Encoded length of sbp_satellite_apc_t
 */
#define SBP_SATELLITE_APC_ENCODED_LEN 32u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_satellite_apc_dep_t::apc before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_SSR_SATELLITE_APC_DEP_APC_MAX 7u

/**
 * Encoded length of sbp_msg_ssr_satellite_apc_dep_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_satellite_apc_dep_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_SATELLITE_APC_DEP_ENCODED_OVERHEAD 0u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_satellite_apc_t::apc before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_SSR_SATELLITE_APC_APC_MAX 7u

/**
 * Encoded length of sbp_msg_ssr_satellite_apc_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_satellite_apc_encoded_len to determine the actual size of an
 * instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_SATELLITE_APC_ENCODED_OVERHEAD 9u

/**
 * Encoded length of sbp_msg_ssr_orbit_clock_dep_a_t
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A_ENCODED_LEN 47u

/**
 * Encoded length of sbp_stec_header_dep_a_t
 */
#define SBP_STEC_HEADER_DEP_A_ENCODED_LEN 10u

/**
 * Encoded length of sbp_gridded_correction_header_dep_a_t
 */
#define SBP_GRIDDED_CORRECTION_HEADER_DEP_A_ENCODED_LEN 13u

/**
 * Encoded length of sbp_grid_definition_header_dep_a_t
 */
#define SBP_GRID_DEFINITION_HEADER_DEP_A_ENCODED_LEN 9u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_stec_correction_dep_a_t::stec_sat_list before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A_STEC_SAT_LIST_MAX 22u

/**
 * Encoded length of sbp_msg_ssr_stec_correction_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_stec_correction_dep_a_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A_ENCODED_OVERHEAD 10u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_no_std_dep_a_t::stec_residuals before the
 * maximum SBP message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A_STEC_RESIDUALS_MAX 59u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_no_std_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len to determine the
 * actual size of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A_ENCODED_OVERHEAD 18u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_gridded_correction_dep_a_t::stec_residuals before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A_STEC_RESIDUALS_MAX 47u

/**
 * Encoded length of sbp_msg_ssr_gridded_correction_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_gridded_correction_dep_a_encoded_len to determine the actual
 * size of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A_ENCODED_OVERHEAD 19u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_grid_definition_dep_a_t::rle_list before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A_RLE_LIST_MAX 246u

/**
 * Encoded length of sbp_msg_ssr_grid_definition_dep_a_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_grid_definition_dep_a_encoded_len to determine the actual size
 * of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A_ENCODED_OVERHEAD 9u

/**
 * Encoded length of sbp_orbit_clock_bound_t
 */
#define SBP_ORBIT_CLOCK_BOUND_ENCODED_LEN 9u

#define SBP_SSR_ORBIT_CLOCK_BOUNDS__MASK (0xffu)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS__SHIFT (0u)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS__GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_ORBIT_CLOCK_BOUNDS__SHIFT) & \
        SBP_SSR_ORBIT_CLOCK_BOUNDS__MASK))
#define SBP_SSR_ORBIT_CLOCK_BOUNDS__SET(flags, val)                      \
  do {                                                                   \
    (flags) = (u8)((flags & (~(SBP_SSR_ORBIT_CLOCK_BOUNDS__MASK          \
                               << SBP_SSR_ORBIT_CLOCK_BOUNDS__SHIFT))) | \
                   (((val) & (SBP_SSR_ORBIT_CLOCK_BOUNDS__MASK))         \
                    << (SBP_SSR_ORBIT_CLOCK_BOUNDS__SHIFT)));            \
  } while (0)

#define SBP_SSR_ORBIT_CLOCK_BOUNDS_GPS (0)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_BDS (3)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_QZS (4)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_GAL (5)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_orbit_clock_bounds_t::orbit_clock_bounds before the maximum SBP
 * message size is exceeded
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS_ORBIT_CLOCK_BOUNDS_MAX 26u

/**
 * Encoded length of sbp_msg_ssr_orbit_clock_bounds_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_orbit_clock_bounds_encoded_len to determine the actual size of
 * an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS_ENCODED_OVERHEAD 13u

/**
 * Encoded length of sbp_code_phase_biases_sat_sig_t
 */
#define SBP_CODE_PHASE_BIASES_SAT_SIG_ENCODED_LEN 6u

#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS__MASK (0xffu)
#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS__SHIFT (0u)
#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS__GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_CODE_PHASE_BIASES_BOUNDS__SHIFT) & \
        SBP_SSR_CODE_PHASE_BIASES_BOUNDS__MASK))
#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS__SET(flags, val)                      \
  do {                                                                         \
    (flags) = (u8)((flags & (~(SBP_SSR_CODE_PHASE_BIASES_BOUNDS__MASK          \
                               << SBP_SSR_CODE_PHASE_BIASES_BOUNDS__SHIFT))) | \
                   (((val) & (SBP_SSR_CODE_PHASE_BIASES_BOUNDS__MASK))         \
                    << (SBP_SSR_CODE_PHASE_BIASES_BOUNDS__SHIFT)));            \
  } while (0)

#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS_GPS (0)
#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS_BDS (3)
#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS_QZS (4)
#define SBP_SSR_CODE_PHASE_BIASES_BOUNDS_GAL (5)
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ssr_code_phase_biases_bounds_t::satellites_signals before the maximum
 * SBP message size is exceeded
 */
#define SBP_MSG_SSR_CODE_PHASE_BIASES_BOUNDS_SATELLITES_SIGNALS_MAX 40u

/**
 * Encoded length of sbp_msg_ssr_code_phase_biases_bounds_t
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users call
 * #sbp_msg_ssr_code_phase_biases_bounds_encoded_len to determine the actual
 * size of an instance of this message.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SSR_CODE_PHASE_BIASES_BOUNDS_ENCODED_OVERHEAD 13u

/**
 * Encoded length of sbp_orbit_clock_bound_degradation_t
 */
#define SBP_ORBIT_CLOCK_BOUND_DEGRADATION_ENCODED_LEN 8u

#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__MASK (0xffu)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__SHIFT (0u)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__GET(flags)               \
  ((u8)((u8)((flags) >> SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__SHIFT) & \
        SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__MASK))
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__SET(flags, val)                \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags & (~(SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__MASK          \
                         << SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__SHIFT))) | \
             (((val) & (SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__MASK))         \
              << (SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION__SHIFT)));            \
  } while (0)

#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION_GPS (0)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION_BDS (3)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION_QZS (4)
#define SBP_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION_GAL (5)
/**
 * Encoded length of sbp_msg_ssr_orbit_clock_bounds_degradation_t
 */
#define SBP_MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION_ENCODED_LEN 28u

#endif /* LIBSBP_SSR_MACROS_H */
