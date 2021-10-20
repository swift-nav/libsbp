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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_OBSERVATION_MACROS_H
#define LIBSBP_OBSERVATION_MACROS_H

/**
 * Encoded length of sbp_observation_header_t (V4 API) and
 * observation_header_t (legacy API)
 */
#define SBP_OBSERVATION_HEADER_ENCODED_LEN 11u

/**
 * Encoded length of sbp_doppler_t (V4 API) and
 * doppler_t (legacy API)
 */
#define SBP_DOPPLER_ENCODED_LEN 3u

#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SHIFT (7u)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SHIFT) & \
        SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MASK))
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SET(flags, val)                  \
  do {                                                                       \
    (flags) =                                                                \
        (u8)((flags) | (((val) & (SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MASK)) \
                        << (SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_NO_EXCLUSION (0)
#define SBP_PACKEDOBSCONTENT_RAIM_EXCLUSION_MEASUREMENT_WAS_EXCLUDED_BY_SPP_RAIM_USE_WITH_CARE \
  (1)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SHIFT (3u)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SHIFT) & \
        SBP_PACKEDOBSCONTENT_DOPPLER_VALID_MASK))
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SET(flags, val)                  \
  do {                                                                      \
    (flags) =                                                               \
        (u8)((flags) | (((val) & (SBP_PACKEDOBSCONTENT_DOPPLER_VALID_MASK)) \
                        << (SBP_PACKEDOBSCONTENT_DOPPLER_VALID_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_INVALID_DOPPLER_MEASUREMENT (0)
#define SBP_PACKEDOBSCONTENT_DOPPLER_VALID_VALID_DOPPLER_MEASUREMENT (1)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SHIFT (2u)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SHIFT) & \
        SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_MASK))
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SET(flags, val)              \
  do {                                                                        \
    (flags) = (u8)((flags) |                                                  \
                   (((val) & (SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_MASK)) \
                    << (SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_UNRESOLVED \
  (0)
#define SBP_PACKEDOBSCONTENT_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_RESOLVED \
  (1)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SHIFT (1u)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SHIFT) & \
        SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_MASK))
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SET(flags, val)              \
  do {                                                                        \
    (flags) = (u8)((flags) |                                                  \
                   (((val) & (SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_MASK)) \
                    << (SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_INVALID_CARRIER_PHASE_MEASUREMENT \
  (0)
#define SBP_PACKEDOBSCONTENT_CARRIER_PHASE_VALID_VALID_CARRIER_PHASE_MEASUREMENT \
  (1)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_MASK (0x1)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SHIFT (0u)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SHIFT) & \
        SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_MASK))
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SET(flags, val)              \
  do {                                                                      \
    (flags) = (u8)((flags) |                                                \
                   (((val) & (SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_MASK)) \
                    << (SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_INVALID_PSEUDORANGE_MEASUREMENT \
  (0)
#define SBP_PACKEDOBSCONTENT_PSEUDORANGE_VALID_VALID_PSEUDORANGE_MEASUREMENT_AND_COARSE_TOW_DECODED \
  (1)
/**
 * Encoded length of sbp_packed_obs_content_t (V4 API) and
 * packed_obs_content_t (legacy API)
 */
#define SBP_PACKED_OBS_CONTENT_ENCODED_LEN 17u

#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SHIFT (4u)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SHIFT) & \
        SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_MASK))
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SET(flags, val)        \
  do {                                                                        \
    (flags) =                                                                 \
        (u8)((flags) |                                                        \
             (((val) & (SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_MASK)) \
              << (SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_VALID_PHASE_CORRECTIONS \
  (0)
#define SBP_PACKEDOSRCONTENT_INVALID_PHASE_CORRECTIONS_DO_NOT_USE_PHASE_CORRECTIONS \
  (1)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SHIFT (3u)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SHIFT) & \
        SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_MASK))
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SET(flags, val)        \
  do {                                                                       \
    (flags) =                                                                \
        (u8)((flags) |                                                       \
             (((val) & (SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_MASK)) \
              << (SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_VALID_CODE_CORRECTIONS (0)
#define SBP_PACKEDOSRCONTENT_INVALID_CODE_CORRECTIONS_DO_NOT_USE_CODE_CORRECTIONS \
  (1)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SHIFT (2u)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SHIFT) & \
        SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_MASK))
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SET(flags, val)                  \
  do {                                                                         \
    (flags) =                                                                  \
        (u8)((flags) | (((val) & (SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_MASK)) \
                        << (SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_FULL_FIXING_UNAVAILABLE (0)
#define SBP_PACKEDOSRCONTENT_FULL_FIXING_FLAG_FULL_FIXING_AVAILABLE (1)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SHIFT (1u)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SHIFT) & \
        SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_MASK))
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SET(flags, val)              \
  do {                                                                        \
    (flags) = (u8)((flags) |                                                  \
                   (((val) & (SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_MASK)) \
                    << (SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_UNAVAILABLE (0)
#define SBP_PACKEDOSRCONTENT_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_AVAILABLE (1)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_MASK (0x1)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SHIFT (0u)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_GET(flags)           \
  ((u8)(((flags) >> SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SHIFT) & \
        SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_MASK))
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SET(flags, val)              \
  do {                                                                        \
    (flags) = (u8)((flags) |                                                  \
                   (((val) & (SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_MASK)) \
                    << (SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_SHIFT)));    \
  } while (0)

#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_DO_NOT_USE_SIGNAL (0)
#define SBP_PACKEDOSRCONTENT_CORRECTION_VALIDITY_VALID_SIGNAL (1)
/**
 * Encoded length of sbp_packed_osr_content_t (V4 API) and
 * packed_osr_content_t (legacy API)
 */
#define SBP_PACKED_OSR_CONTENT_ENCODED_LEN 19u

#define SBP_MSG_OBS 0x004A
/**
 * The maximum number of items that can be stored in sbp_msg_obs_t::obs (V4 API)
 * or msg_obs_t::obs (legacy API) before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_OBS_OBS_MAX 14u

/**
 * Encoded length of sbp_msg_obs_t (V4 API) and
 * msg_obs_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_obs_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_OBS_ENCODED_OVERHEAD 11u

#define SBP_MSG_BASE_POS_LLH 0x0044
/**
 * Encoded length of sbp_msg_base_pos_llh_t (V4 API) and
 * msg_base_pos_llh_t (legacy API)
 */
#define SBP_MSG_BASE_POS_LLH_ENCODED_LEN 24u

#define SBP_MSG_BASE_POS_ECEF 0x0048
/**
 * Encoded length of sbp_msg_base_pos_ecef_t (V4 API) and
 * msg_base_pos_ecef_t (legacy API)
 */
#define SBP_MSG_BASE_POS_ECEF_ENCODED_LEN 24u

/**
 * Encoded length of sbp_ephemeris_common_content_t (V4 API) and
 * ephemeris_common_content_t (legacy API)
 */
#define SBP_EPHEMERIS_COMMON_CONTENT_ENCODED_LEN 18u

/**
 * Encoded length of sbp_ephemeris_common_content_dep_b_t (V4 API) and
 * ephemeris_common_content_dep_b_t (legacy API)
 */
#define SBP_EPHEMERIS_COMMON_CONTENT_DEP_B_ENCODED_LEN 22u

/**
 * Encoded length of sbp_ephemeris_common_content_dep_a_t (V4 API) and
 * ephemeris_common_content_dep_a_t (legacy API)
 */
#define SBP_EPHEMERIS_COMMON_CONTENT_DEP_A_ENCODED_LEN 24u

#define SBP_MSG_EPHEMERIS_GPS_DEP_E 0x0081
/**
 * Encoded length of sbp_msg_ephemeris_gps_dep_e_t (V4 API) and
 * msg_ephemeris_gps_dep_e_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_E_ENCODED_LEN 185u

#define SBP_MSG_EPHEMERIS_GPS_DEP_F 0x0086
/**
 * Encoded length of sbp_msg_ephemeris_gps_dep_f_t (V4 API) and
 * msg_ephemeris_gps_dep_f_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_F_ENCODED_LEN 183u

#define SBP_MSG_EPHEMERIS_GPS 0x008A
/**
 * Encoded length of sbp_msg_ephemeris_gps_t (V4 API) and
 * msg_ephemeris_gps_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GPS_ENCODED_LEN 139u

#define SBP_MSG_EPHEMERIS_QZSS 0x008E
/**
 * Encoded length of sbp_msg_ephemeris_qzss_t (V4 API) and
 * msg_ephemeris_qzss_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_QZSS_ENCODED_LEN 139u

#define SBP_MSG_EPHEMERIS_BDS 0x0089
/**
 * Encoded length of sbp_msg_ephemeris_bds_t (V4 API) and
 * msg_ephemeris_bds_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_BDS_ENCODED_LEN 147u

#define SBP_MSG_EPHEMERIS_GAL_DEP_A 0x0095
/**
 * Encoded length of sbp_msg_ephemeris_gal_dep_a_t (V4 API) and
 * msg_ephemeris_gal_dep_a_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GAL_DEP_A_ENCODED_LEN 152u

#define SBP_MSG_EPHEMERIS_GAL 0x008D
/**
 * Encoded length of sbp_msg_ephemeris_gal_t (V4 API) and
 * msg_ephemeris_gal_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GAL_ENCODED_LEN 153u

#define SBP_MSG_EPHEMERIS_SBAS_DEP_A 0x0082
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_dep_a_t::pos (V4 API) or
 * msg_ephemeris_sbas_dep_a_t::pos (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_A_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_dep_a_t::vel (V4 API) or
 * msg_ephemeris_sbas_dep_a_t::vel (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_A_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_dep_a_t::acc (V4 API) or
 * msg_ephemeris_sbas_dep_a_t::acc (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_A_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_sbas_dep_a_t (V4 API) and
 * msg_ephemeris_sbas_dep_a_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_A_ENCODED_LEN 112u

#define SBP_MSG_EPHEMERIS_GLO_DEP_A 0x0083
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_a_t::pos (V4 API) or msg_ephemeris_glo_dep_a_t::pos
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_a_t::vel (V4 API) or msg_ephemeris_glo_dep_a_t::vel
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_a_t::acc (V4 API) or msg_ephemeris_glo_dep_a_t::acc
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_glo_dep_a_t (V4 API) and
 * msg_ephemeris_glo_dep_a_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A_ENCODED_LEN 112u

#define SBP_MSG_EPHEMERIS_SBAS_DEP_B 0x0084
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_dep_b_t::pos (V4 API) or
 * msg_ephemeris_sbas_dep_b_t::pos (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_dep_b_t::vel (V4 API) or
 * msg_ephemeris_sbas_dep_b_t::vel (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_dep_b_t::acc (V4 API) or
 * msg_ephemeris_sbas_dep_b_t::acc (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_sbas_dep_b_t (V4 API) and
 * msg_ephemeris_sbas_dep_b_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B_ENCODED_LEN 110u

#define SBP_MSG_EPHEMERIS_SBAS 0x008C
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_t::pos (V4 API) or msg_ephemeris_sbas_t::pos (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_t::vel (V4 API) or msg_ephemeris_sbas_t::vel (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_sbas_t::acc (V4 API) or msg_ephemeris_sbas_t::acc (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_SBAS_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_sbas_t (V4 API) and
 * msg_ephemeris_sbas_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_SBAS_ENCODED_LEN 74u

#define SBP_MSG_EPHEMERIS_GLO_DEP_B 0x0085
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_b_t::pos (V4 API) or msg_ephemeris_glo_dep_b_t::pos
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_b_t::vel (V4 API) or msg_ephemeris_glo_dep_b_t::vel
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_b_t::acc (V4 API) or msg_ephemeris_glo_dep_b_t::acc
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_glo_dep_b_t (V4 API) and
 * msg_ephemeris_glo_dep_b_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B_ENCODED_LEN 110u

#define SBP_MSG_EPHEMERIS_GLO_DEP_C 0x0087
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_c_t::pos (V4 API) or msg_ephemeris_glo_dep_c_t::pos
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_c_t::vel (V4 API) or msg_ephemeris_glo_dep_c_t::vel
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_c_t::acc (V4 API) or msg_ephemeris_glo_dep_c_t::acc
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_glo_dep_c_t (V4 API) and
 * msg_ephemeris_glo_dep_c_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C_ENCODED_LEN 119u

#define SBP_MSG_EPHEMERIS_GLO_DEP_D 0x0088
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_d_t::pos (V4 API) or msg_ephemeris_glo_dep_d_t::pos
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_d_t::vel (V4 API) or msg_ephemeris_glo_dep_d_t::vel
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_dep_d_t::acc (V4 API) or msg_ephemeris_glo_dep_d_t::acc
 * (legacy API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_glo_dep_d_t (V4 API) and
 * msg_ephemeris_glo_dep_d_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D_ENCODED_LEN 120u

#define SBP_MSG_EPHEMERIS_GLO 0x008B
/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_t::pos (V4 API) or msg_ephemeris_glo_t::pos (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_POS_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_t::vel (V4 API) or msg_ephemeris_glo_t::vel (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_VEL_MAX 3u

/**
 * The maximum number of items that can be stored in
 * sbp_msg_ephemeris_glo_t::acc (V4 API) or msg_ephemeris_glo_t::acc (legacy
 * API) before the maximum SBP message size is exceeded
 */
#define SBP_MSG_EPHEMERIS_GLO_ACC_MAX 3u

/**
 * Encoded length of sbp_msg_ephemeris_glo_t (V4 API) and
 * msg_ephemeris_glo_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_GLO_ENCODED_LEN 92u

#define SBP_MSG_EPHEMERIS_DEP_D 0x0080
/**
 * Encoded length of sbp_msg_ephemeris_dep_d_t (V4 API) and
 * msg_ephemeris_dep_d_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_DEP_D_ENCODED_LEN 185u

#define SBP_MSG_EPHEMERIS_DEP_A 0x001A
/**
 * Encoded length of sbp_msg_ephemeris_dep_a_t (V4 API) and
 * msg_ephemeris_dep_a_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_DEP_A_ENCODED_LEN 175u

#define SBP_MSG_EPHEMERIS_DEP_B 0x0046
/**
 * Encoded length of sbp_msg_ephemeris_dep_b_t (V4 API) and
 * msg_ephemeris_dep_b_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_DEP_B_ENCODED_LEN 176u

#define SBP_MSG_EPHEMERIS_DEP_C 0x0047
/**
 * Encoded length of sbp_msg_ephemeris_dep_c_t (V4 API) and
 * msg_ephemeris_dep_c_t (legacy API)
 */
#define SBP_MSG_EPHEMERIS_DEP_C_ENCODED_LEN 185u

/**
 * Encoded length of sbp_observation_header_dep_t (V4 API) and
 * observation_header_dep_t (legacy API)
 */
#define SBP_OBSERVATION_HEADER_DEP_ENCODED_LEN 7u

/**
 * Encoded length of sbp_carrier_phase_dep_a_t (V4 API) and
 * carrier_phase_dep_a_t (legacy API)
 */
#define SBP_CARRIER_PHASE_DEP_A_ENCODED_LEN 5u

/**
 * Encoded length of sbp_packed_obs_content_dep_a_t (V4 API) and
 * packed_obs_content_dep_a_t (legacy API)
 */
#define SBP_PACKED_OBS_CONTENT_DEP_A_ENCODED_LEN 13u

/**
 * Encoded length of sbp_packed_obs_content_dep_b_t (V4 API) and
 * packed_obs_content_dep_b_t (legacy API)
 */
#define SBP_PACKED_OBS_CONTENT_DEP_B_ENCODED_LEN 16u

/**
 * Encoded length of sbp_packed_obs_content_dep_c_t (V4 API) and
 * packed_obs_content_dep_c_t (legacy API)
 */
#define SBP_PACKED_OBS_CONTENT_DEP_C_ENCODED_LEN 16u

#define SBP_MSG_OBS_DEP_A 0x0045
/**
 * The maximum number of items that can be stored in sbp_msg_obs_dep_a_t::obs
 * (V4 API) or msg_obs_dep_a_t::obs (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_OBS_DEP_A_OBS_MAX 19u

/**
 * Encoded length of sbp_msg_obs_dep_a_t (V4 API) and
 * msg_obs_dep_a_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_obs_dep_a_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_OBS_DEP_A_ENCODED_OVERHEAD 7u

#define SBP_MSG_OBS_DEP_B 0x0043
/**
 * The maximum number of items that can be stored in sbp_msg_obs_dep_b_t::obs
 * (V4 API) or msg_obs_dep_b_t::obs (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_OBS_DEP_B_OBS_MAX 15u

/**
 * Encoded length of sbp_msg_obs_dep_b_t (V4 API) and
 * msg_obs_dep_b_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_obs_dep_b_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_OBS_DEP_B_ENCODED_OVERHEAD 7u

#define SBP_MSG_OBS_DEP_C 0x0049
/**
 * The maximum number of items that can be stored in sbp_msg_obs_dep_c_t::obs
 * (V4 API) or msg_obs_dep_c_t::obs (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_OBS_DEP_C_OBS_MAX 15u

/**
 * Encoded length of sbp_msg_obs_dep_c_t (V4 API) and
 * msg_obs_dep_c_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_obs_dep_c_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_OBS_DEP_C_ENCODED_OVERHEAD 7u

#define SBP_MSG_IONO 0x0090
/**
 * Encoded length of sbp_msg_iono_t (V4 API) and
 * msg_iono_t (legacy API)
 */
#define SBP_MSG_IONO_ENCODED_LEN 70u

#define SBP_MSG_SV_CONFIGURATION_GPS_DEP 0x0091
/**
 * Encoded length of sbp_msg_sv_configuration_gps_dep_t (V4 API) and
 * msg_sv_configuration_gps_dep_t (legacy API)
 */
#define SBP_MSG_SV_CONFIGURATION_GPS_DEP_ENCODED_LEN 10u

/**
 * Encoded length of sbp_gnss_capb_t (V4 API) and
 * gnss_capb_t (legacy API)
 */
#define SBP_GNSS_CAPB_ENCODED_LEN 104u

#define SBP_MSG_GNSS_CAPB 0x0096
/**
 * Encoded length of sbp_msg_gnss_capb_t (V4 API) and
 * msg_gnss_capb_t (legacy API)
 */
#define SBP_MSG_GNSS_CAPB_ENCODED_LEN 110u

#define SBP_MSG_GROUP_DELAY_DEP_A 0x0092
/**
 * Encoded length of sbp_msg_group_delay_dep_a_t (V4 API) and
 * msg_group_delay_dep_a_t (legacy API)
 */
#define SBP_MSG_GROUP_DELAY_DEP_A_ENCODED_LEN 14u

#define SBP_MSG_GROUP_DELAY_DEP_B 0x0093
/**
 * Encoded length of sbp_msg_group_delay_dep_b_t (V4 API) and
 * msg_group_delay_dep_b_t (legacy API)
 */
#define SBP_MSG_GROUP_DELAY_DEP_B_ENCODED_LEN 17u

#define SBP_MSG_GROUP_DELAY 0x0094
/**
 * Encoded length of sbp_msg_group_delay_t (V4 API) and
 * msg_group_delay_t (legacy API)
 */
#define SBP_MSG_GROUP_DELAY_ENCODED_LEN 15u

/**
 * Encoded length of sbp_almanac_common_content_t (V4 API) and
 * almanac_common_content_t (legacy API)
 */
#define SBP_ALMANAC_COMMON_CONTENT_ENCODED_LEN 22u

/**
 * Encoded length of sbp_almanac_common_content_dep_t (V4 API) and
 * almanac_common_content_dep_t (legacy API)
 */
#define SBP_ALMANAC_COMMON_CONTENT_DEP_ENCODED_LEN 24u

#define SBP_MSG_ALMANAC_GPS_DEP 0x0070
/**
 * Encoded length of sbp_msg_almanac_gps_dep_t (V4 API) and
 * msg_almanac_gps_dep_t (legacy API)
 */
#define SBP_MSG_ALMANAC_GPS_DEP_ENCODED_LEN 96u

#define SBP_MSG_ALMANAC_GPS 0x0072
/**
 * Encoded length of sbp_msg_almanac_gps_t (V4 API) and
 * msg_almanac_gps_t (legacy API)
 */
#define SBP_MSG_ALMANAC_GPS_ENCODED_LEN 94u

#define SBP_MSG_ALMANAC_GLO_DEP 0x0071
/**
 * Encoded length of sbp_msg_almanac_glo_dep_t (V4 API) and
 * msg_almanac_glo_dep_t (legacy API)
 */
#define SBP_MSG_ALMANAC_GLO_DEP_ENCODED_LEN 80u

#define SBP_MSG_ALMANAC_GLO 0x0073
/**
 * Encoded length of sbp_msg_almanac_glo_t (V4 API) and
 * msg_almanac_glo_t (legacy API)
 */
#define SBP_MSG_ALMANAC_GLO_ENCODED_LEN 78u

#define SBP_MSG_GLO_BIASES 0x0075
/**
 * Encoded length of sbp_msg_glo_biases_t (V4 API) and
 * msg_glo_biases_t (legacy API)
 */
#define SBP_MSG_GLO_BIASES_ENCODED_LEN 9u

/**
 * Encoded length of sbp_sv_az_el_t (V4 API) and
 * sv_az_el_t (legacy API)
 */
#define SBP_SV_AZ_EL_ENCODED_LEN 4u

#define SBP_MSG_SV_AZ_EL 0x0097
/**
 * The maximum number of items that can be stored in sbp_msg_sv_az_el_t::azel
 * (V4 API) or msg_sv_az_el_t::azel (legacy API) before the maximum SBP message
 * size is exceeded
 */
#define SBP_MSG_SV_AZ_EL_AZEL_MAX 63u

/**
 * Encoded length of sbp_msg_sv_az_el_t (V4 API) and
 * msg_sv_az_el_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_sv_az_el_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_SV_AZ_EL_ENCODED_OVERHEAD 0u

#define SBP_MSG_OSR 0x0640
/**
 * The maximum number of items that can be stored in sbp_msg_osr_t::obs (V4 API)
 * or msg_osr_t::obs (legacy API) before the maximum SBP message size is
 * exceeded
 */
#define SBP_MSG_OSR_OBS_MAX 12u

/**
 * Encoded length of sbp_msg_osr_t (V4 API) and
 * msg_osr_t (legacy API)
 *
 * This type is not fixed size and an instance of this message may be longer
 * than the value indicated by this symbol. Users of the V4 API should call
 * #sbp_msg_osr_encoded_len to determine the actual size of an instance
 * of this message. Users of the legacy API are required to track the encoded
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message
 * structure and its variable length component(s)
 */
#define SBP_MSG_OSR_ENCODED_OVERHEAD 11u

#endif /* LIBSBP_OBSERVATION_MACROS_H */
