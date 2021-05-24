#ifndef LIBSBP_TRACKING_MESSAGES_H
#define LIBSBP_TRACKING_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/double_null_terminated.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#include <libsbp/unpacked/string/binary.h>
#include <libsbp/unpacked/gnss.h>

#ifdef __cplusplus
  extern "C" {
#endif

struct sbp_state;
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_10_MS_INTEGRATION_TIME (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PARAMETER_SETS_20_MS_INTEGRATION_TIME (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_RE_ACQUISITION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_A_TRACKING_CHANNEL_STATUS_RUNNING (1)
/** Detailed signal tracking channel states. DEPRECATED.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP_A 0x0021
typedef struct {
  u64 recv_time;
  sbp_sbp_gps_time_t tot;
  u32 P;
  u16 P_std;
  sbp_carrier_phase_t L;
  u8 cn0;
  u16 lock;
  sbp_sbp_gnss_signal_t sid;
  s32 doppler;
  u16 doppler_std;
  u32 uptime;
  s16 clock_offset;
  s16 clock_drift;
  u16 corr_spacing;
  s8 acceleration;
  u8 sync_flags;
  u8 tow_flags;
  u8 track_flags;
  u8 nav_flags;
  u8 pset_flags;
  u8 misc_flags;
} sbp_msg_tracking_state_detailed_dep_a_t;

size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *msg);
s8 sbp_pack_sbp_msg_tracking_state_detailed_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_state_detailed_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_tracking_state_detailed_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_state_detailed_dep_a_t *msg);
s8 sbp_send_sbp_msg_tracking_state_detailed_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_state_detailed_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(const sbp_msg_tracking_state_detailed_dep_a_t *a, const sbp_msg_tracking_state_detailed_dep_a_t *b);


#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_NO_SYNCHRONIZATION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_BIT_SYNCHRONIZATION (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_WORD_SYNCHRONIZATION (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_SYNCHRONIZATION_STATUS_SUB_FRAME_SYNCHRONIZATION_MESSAGE_SYNCHRONIZATION (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_WEEK_NUMBER_VALIDITY_STATUS_WEEK_NUMBER_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_TOW_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_DECODED_TOW_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TOW_STATUS_PROPAGATED_TOW_IS_AVAILABLE (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_FLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_FLL_STATUS_FLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_PLL_IS_INACTIVE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PLL_STATUS_PLL_IS_ACTIVE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_NO_LOCKS (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_FLLDLL_LOCK (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_PLL_OPTIMISTIC_LOCK (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_LOOP_STATUS_PLL_PESSIMISTIC_LOCK (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_ALMANAC_AVAILABILITY_STATUS_ALMANAC_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_NOT_AVAILABLE (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_EPHEMERIS_AVAILABILITY_STATUS_EPHEMERIS_IS_AVAILABLE (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_HEALTH_IS_UNKNOWN (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SIGNAL_IS_UNHEALTHY (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_HEALTH_STATUS_SIGNAL_IS_HEALTHY (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK (0x7)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_1_MS_INTEGRATION_TIME (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_5_MS_INTEGRATION_TIME (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_10_MS_INTEGRATION_TIME (2)
#define SBP_TRACKING_STATE_DETAILED_DEP_PARAMETER_SETS_20_MS_INTEGRATION_TIME (3)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT (5u)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_CLOCK_VALIDITY_STATUS_CLOCK_OFFSET_AND_DRIFT_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT (4u)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_PSEUDORANGE_VALIDITY_STATUS_PSEUDORANGE_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT (3u)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_NOT_VALID (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_ACCELERATION_VALIDITY_STATUS_ACCELERATION_IS_VALID (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK (0x1)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT (2u)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_UNRESOLVED (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_CARRIER_HALF_CYCLE_AMBIGUITY_STATUS_RESOLVED (1)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK (0x3)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT (0u)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_GET(flags) \
                             (((flags) >> SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT) \
                             & SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_MASK)) \
                             << (SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_SHIFT)));} while(0)
                             

#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_RE_ACQUISITION (0)
#define SBP_TRACKING_STATE_DETAILED_DEP_TRACKING_CHANNEL_STATUS_RUNNING (1)
/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_STATE_DETAILED_DEP   0x0011
typedef struct {
  u64 recv_time;
  sbp_gps_time_dep_t tot;
  u32 P;
  u16 P_std;
  sbp_carrier_phase_t L;
  u8 cn0;
  u16 lock;
  sbp_gnss_signal_dep_t sid;
  s32 doppler;
  u16 doppler_std;
  u32 uptime;
  s16 clock_offset;
  s16 clock_drift;
  u16 corr_spacing;
  s8 acceleration;
  u8 sync_flags;
  u8 tow_flags;
  u8 track_flags;
  u8 nav_flags;
  u8 pset_flags;
  u8 misc_flags;
} sbp_msg_tracking_state_detailed_dep_t;

size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *msg);
s8 sbp_pack_sbp_msg_tracking_state_detailed_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_state_detailed_dep_t *msg);
s8 sbp_unpack_sbp_msg_tracking_state_detailed_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_state_detailed_dep_t *msg);
s8 sbp_send_sbp_msg_tracking_state_detailed_dep_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_state_detailed_dep_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(const sbp_msg_tracking_state_detailed_dep_t *a, const sbp_msg_tracking_state_detailed_dep_t *b);


/** Signal tracking channel state
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sbp_gnss_signal_t sid;
  u8 fcn;
  u8 cn0;
} sbp_tracking_channel_state_t;

size_t sbp_packed_size_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *msg);
s8 sbp_pack_sbp_tracking_channel_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tracking_channel_state_t *msg);
s8 sbp_unpack_sbp_tracking_channel_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tracking_channel_state_t *msg);

int sbp_cmp_sbp_tracking_channel_state_t(const sbp_tracking_channel_state_t *a, const sbp_tracking_channel_state_t *b);


/** Signal tracking channel states
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_STATE                0x0041
typedef struct {
  sbp_tracking_channel_state_t states[63];
  u8 n_states;
} sbp_msg_tracking_state_t;

size_t sbp_packed_size_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *msg);
s8 sbp_pack_sbp_msg_tracking_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_state_t *msg);
s8 sbp_unpack_sbp_msg_tracking_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_state_t *msg);
s8 sbp_send_sbp_msg_tracking_state_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_state_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_state_t(const sbp_msg_tracking_state_t *a, const sbp_msg_tracking_state_t *b);


/** Measurement Engine signal tracking channel state
 *
((m.desc|commentify)))
 */
typedef struct {
  sbp_sbp_gnss_signal_t mesid;
  u8 cn0;
} sbp_measurement_state_t;

size_t sbp_packed_size_sbp_measurement_state_t(const sbp_measurement_state_t *msg);
s8 sbp_pack_sbp_measurement_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_measurement_state_t *msg);
s8 sbp_unpack_sbp_measurement_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_measurement_state_t *msg);

int sbp_cmp_sbp_measurement_state_t(const sbp_measurement_state_t *a, const sbp_measurement_state_t *b);


/** Measurement Engine signal tracking channel states
 *
((m.desc|commentify)))
 */
#define SBP_MSG_MEASUREMENT_STATE             0x0061
typedef struct {
  sbp_measurement_state_t states[85];
  u8 n_states;
} sbp_msg_measurement_state_t;

size_t sbp_packed_size_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *msg);
s8 sbp_pack_sbp_msg_measurement_state_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_measurement_state_t *msg);
s8 sbp_unpack_sbp_msg_measurement_state_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_measurement_state_t *msg);
s8 sbp_send_sbp_msg_measurement_state_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_measurement_state_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_measurement_state_t(const sbp_msg_measurement_state_t *a, const sbp_msg_measurement_state_t *b);


/** Complex correlation structure
 *
((m.desc|commentify)))
 */
typedef struct {
  s16 I;
  s16 Q;
} sbp_tracking_channel_correlation_t;

size_t sbp_packed_size_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *msg);
s8 sbp_pack_sbp_tracking_channel_correlation_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tracking_channel_correlation_t *msg);
s8 sbp_unpack_sbp_tracking_channel_correlation_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tracking_channel_correlation_t *msg);

int sbp_cmp_sbp_tracking_channel_correlation_t(const sbp_tracking_channel_correlation_t *a, const sbp_tracking_channel_correlation_t *b);


/** Tracking channel correlations
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_IQ                   0x002D
typedef struct {
  u8 channel;
  sbp_sbp_gnss_signal_t sid;
  sbp_tracking_channel_correlation_t corrs[3];
} sbp_msg_tracking_iq_t;

size_t sbp_packed_size_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *msg);
s8 sbp_pack_sbp_msg_tracking_iq_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_iq_t *msg);
s8 sbp_unpack_sbp_msg_tracking_iq_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_iq_t *msg);
s8 sbp_send_sbp_msg_tracking_iq_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_iq_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_iq_t(const sbp_msg_tracking_iq_t *a, const sbp_msg_tracking_iq_t *b);


/** Complex correlation structure
 *
((m.desc|commentify)))
 */
typedef struct {
  s32 I;
  s32 Q;
} sbp_tracking_channel_correlation_dep_t;

size_t sbp_packed_size_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *msg);
s8 sbp_pack_sbp_tracking_channel_correlation_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tracking_channel_correlation_dep_t *msg);
s8 sbp_unpack_sbp_tracking_channel_correlation_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tracking_channel_correlation_dep_t *msg);

int sbp_cmp_sbp_tracking_channel_correlation_dep_t(const sbp_tracking_channel_correlation_dep_t *a, const sbp_tracking_channel_correlation_dep_t *b);


/** Tracking channel correlations
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_IQ_DEP_B             0x002C
typedef struct {
  u8 channel;
  sbp_sbp_gnss_signal_t sid;
  sbp_tracking_channel_correlation_dep_t corrs[3];
} sbp_msg_tracking_iq_dep_b_t;

size_t sbp_packed_size_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *msg);
s8 sbp_pack_sbp_msg_tracking_iq_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_iq_dep_b_t *msg);
s8 sbp_unpack_sbp_msg_tracking_iq_dep_b_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_iq_dep_b_t *msg);
s8 sbp_send_sbp_msg_tracking_iq_dep_b_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_iq_dep_b_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_iq_dep_b_t(const sbp_msg_tracking_iq_dep_b_t *a, const sbp_msg_tracking_iq_dep_b_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_IQ_DEP_A             0x001C
typedef struct {
  u8 channel;
  sbp_gnss_signal_dep_t sid;
  sbp_tracking_channel_correlation_dep_t corrs[3];
} sbp_msg_tracking_iq_dep_a_t;

size_t sbp_packed_size_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *msg);
s8 sbp_pack_sbp_msg_tracking_iq_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_iq_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_tracking_iq_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_iq_dep_a_t *msg);
s8 sbp_send_sbp_msg_tracking_iq_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_iq_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_iq_dep_a_t(const sbp_msg_tracking_iq_dep_a_t *a, const sbp_msg_tracking_iq_dep_a_t *b);


#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_GET(flags) \
                             (((flags) >> SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SHIFT) \
                             & SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_MASK)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_MASK)) \
                             << (SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_SHIFT)));} while(0)
                             

#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKINGCHANNELSTATEDEPA_TRACKING_MODE_RUNNING (1)
/** Deprecated
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 state;
  u8 prn;
  float cn0;
} sbp_tracking_channel_state_dep_a_t;

size_t sbp_packed_size_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *msg);
s8 sbp_pack_sbp_tracking_channel_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tracking_channel_state_dep_a_t *msg);
s8 sbp_unpack_sbp_tracking_channel_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tracking_channel_state_dep_a_t *msg);

int sbp_cmp_sbp_tracking_channel_state_dep_a_t(const sbp_tracking_channel_state_dep_a_t *a, const sbp_tracking_channel_state_dep_a_t *b);


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_STATE_DEP_A          0x0016
typedef struct {
  sbp_tracking_channel_state_dep_a_t states[42];
  u8 n_states;
} sbp_msg_tracking_state_dep_a_t;

size_t sbp_packed_size_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *msg);
s8 sbp_pack_sbp_msg_tracking_state_dep_a_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_state_dep_a_t *msg);
s8 sbp_unpack_sbp_msg_tracking_state_dep_a_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_state_dep_a_t *msg);
s8 sbp_send_sbp_msg_tracking_state_dep_a_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_state_dep_a_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_state_dep_a_t(const sbp_msg_tracking_state_dep_a_t *a, const sbp_msg_tracking_state_dep_a_t *b);


#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_MASK (0x3)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SHIFT (0u)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_GET(flags) \
                             (((flags) >> SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SHIFT) \
                             & SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_MASK)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_MASK)) \
                             << (SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_SHIFT)));} while(0)
                             

#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_DISABLED (0)
#define SBP_TRACKINGCHANNELSTATEDEPB_TRACKING_MODE_RUNNING (1)
/** Deprecated.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 state;
  sbp_gnss_signal_dep_t sid;
  float cn0;
} sbp_tracking_channel_state_dep_b_t;

size_t sbp_packed_size_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *msg);
s8 sbp_pack_sbp_tracking_channel_state_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_tracking_channel_state_dep_b_t *msg);
s8 sbp_unpack_sbp_tracking_channel_state_dep_b_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_tracking_channel_state_dep_b_t *msg);

int sbp_cmp_sbp_tracking_channel_state_dep_b_t(const sbp_tracking_channel_state_dep_b_t *a, const sbp_tracking_channel_state_dep_b_t *b);


/** Deprecated.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_TRACKING_STATE_DEP_B          0x0013
typedef struct {
  sbp_tracking_channel_state_dep_b_t states[28];
  u8 n_states;
} sbp_msg_tracking_state_dep_b_t;

size_t sbp_packed_size_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *msg);
s8 sbp_pack_sbp_msg_tracking_state_dep_b_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_msg_tracking_state_dep_b_t *msg);
s8 sbp_unpack_sbp_msg_tracking_state_dep_b_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_msg_tracking_state_dep_b_t *msg);
s8 sbp_send_sbp_msg_tracking_state_dep_b_t(struct sbp_state  *s, u16 sender_id, const sbp_msg_tracking_state_dep_b_t *msg, s32 (*write)(u8 *buff, u32 n, void *context));

int sbp_cmp_sbp_msg_tracking_state_dep_b_t(const sbp_msg_tracking_state_dep_b_t *a, const sbp_msg_tracking_state_dep_b_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_detailed_dep_a_t &a, const sbp_msg_tracking_state_detailed_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_detailed_dep_t &a, const sbp_msg_tracking_state_detailed_dep_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_state_t &a, const sbp_tracking_channel_state_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_t &a, const sbp_msg_tracking_state_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_measurement_state_t &a, const sbp_measurement_state_t &b) {
  return sbp_cmp_sbp_measurement_state_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_measurement_state_t &a, const sbp_msg_measurement_state_t &b) {
  return sbp_cmp_sbp_msg_measurement_state_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_correlation_t &a, const sbp_tracking_channel_correlation_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_iq_t &a, const sbp_msg_tracking_iq_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_correlation_dep_t &a, const sbp_tracking_channel_correlation_dep_t &b) {
  return sbp_cmp_sbp_tracking_channel_correlation_dep_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_iq_dep_b_t &a, const sbp_msg_tracking_iq_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_b_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_iq_dep_a_t &a, const sbp_msg_tracking_iq_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_iq_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_state_dep_a_t &a, const sbp_tracking_channel_state_dep_a_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_dep_a_t &a, const sbp_msg_tracking_state_dep_a_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_a_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_tracking_channel_state_dep_b_t &a, const sbp_tracking_channel_state_dep_b_t &b) {
  return sbp_cmp_sbp_tracking_channel_state_dep_b_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_msg_tracking_state_dep_b_t &a, const sbp_msg_tracking_state_dep_b_t &b) {
  return sbp_cmp_sbp_msg_tracking_state_dep_b_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_TRACKING_MESSAGES_H */
