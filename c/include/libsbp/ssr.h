#ifndef LIBSBP_SSR_MESSAGES_H
#define LIBSBP_SSR_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss.h>
/** Precise orbit and clock correction
 *
 * The precise orbit and clock correction message is
 * to be applied as a delta correction to broadcast
 * ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types
 */
#define SBP_MSG_SSR_ORBIT_CLOCK 0x05DD

#define SBP_SSR_ORBIT_CLOCK_SID_CODE__MASK (0xff)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__SHIFT (0u)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GET(flags)      \
  (((flags) >> SBP_SSR_ORBIT_CLOCK_SID_CODE__SHIFT) & \
   SBP_SSR_ORBIT_CLOCK_SID_CODE__MASK)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_SSR_ORBIT_CLOCK_SID_CODE__MASK)) \
                 << (SBP_SSR_ORBIT_CLOCK_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L1P (5)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GPS_L2P (6)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GAL_E1B (14)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__GAL_E7I (20)
#define SBP_SSR_ORBIT_CLOCK_SID_CODE__BDS3_B2A (47)
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  struct {
    /**
     * Seconds since start of GPS week[s]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } time;
  /**
   * GNSS signal identifier (16 bit)
   */
  struct {
    /**
     * Constellation-specific satellite identifier. This field for Glonass can
     * either be (100+FCN) where FCN is in [-7,+6] or
     * the Slot ID in [1,28]
     */
    u8 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
  } sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Issue of broadcast ephemeris data or IODCRC (Beidou)
   */
  u32 iod;
  /**
   * Orbit radial delta correction[0.1 mm]
   */
  s32 radial;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 along;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 cross;
  /**
   * Velocity of orbit radial delta correction[0.001 mm/s]
   */
  s32 dot_radial;
  /**
   * Velocity of orbit along delta correction[0.004 mm/s]
   */
  s32 dot_along;
  /**
   * Velocity of orbit cross delta correction[0.004 mm/s]
   */
  s32 dot_cross;
  /**
   * C0 polynomial coefficient for correction of broadcast satellite clock[0.1
   * mm]
   */
  s32 c0;
  /**
   * C1 polynomial coefficient for correction of broadcast satellite clock[0.001
   * mm/s]
   */
  s32 c1;
  /**
   * C2 polynomial coefficient for correction of broadcast satellite
   * clock[0.00002 mm/s^-2]
   */
  s32 c2;
} sbp_msg_ssr_orbit_clock_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_t(
    const sbp_msg_ssr_orbit_clock_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) +
         sizeof(msg->iod) + sizeof(msg->radial) + sizeof(msg->along) +
         sizeof(msg->cross) + sizeof(msg->dot_radial) + sizeof(msg->dot_along) +
         sizeof(msg->dot_cross) + sizeof(msg->c0) + sizeof(msg->c1) +
         sizeof(msg->c2);
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_t(
    u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_orbit_clock_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtimetow = msg->time.tow;
  msgtimetow = htole32(msgtimetow);
  memcpy(buf + offset, &msgtimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtimewn = msg->time.wn;
  msgtimewn = htole16(msgtimewn);
  memcpy(buf + offset, &msgtimewn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgiod = msg->iod;
  msgiod = htole32(msgiod);
  memcpy(buf + offset, &msgiod, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgradial = msg->radial;
  msgradial = htole32(msgradial);
  memcpy(buf + offset, &msgradial, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgalong = msg->along;
  msgalong = htole32(msgalong);
  memcpy(buf + offset, &msgalong, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgcross = msg->cross;
  msgcross = htole32(msgcross);
  memcpy(buf + offset, &msgcross, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgdot_radial = msg->dot_radial;
  msgdot_radial = htole32(msgdot_radial);
  memcpy(buf + offset, &msgdot_radial, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgdot_along = msg->dot_along;
  msgdot_along = htole32(msgdot_along);
  memcpy(buf + offset, &msgdot_along, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgdot_cross = msg->dot_cross;
  msgdot_cross = htole32(msgdot_cross);
  memcpy(buf + offset, &msgdot_cross, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgc0 = msg->c0;
  msgc0 = htole32(msgc0);
  memcpy(buf + offset, &msgc0, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgc1 = msg->c1;
  msgc1 = htole32(msgc1);
  memcpy(buf + offset, &msgc1, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgc2 = msg->c2;
  msgc2 = htole32(msgc2);
  memcpy(buf + offset, &msgc2, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_t(
    const u8 *buf, size_t len, sbp_msg_ssr_orbit_clock_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 4);
  msg->iod = le32toh(msg->iod);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->radial, buf + offset, 4);
  msg->radial = le32toh(msg->radial);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->along, buf + offset, 4);
  msg->along = le32toh(msg->along);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->cross, buf + offset, 4);
  msg->cross = le32toh(msg->cross);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->dot_radial, buf + offset, 4);
  msg->dot_radial = le32toh(msg->dot_radial);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->dot_along, buf + offset, 4);
  msg->dot_along = le32toh(msg->dot_along);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->dot_cross, buf + offset, 4);
  msg->dot_cross = le32toh(msg->dot_cross);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c0, buf + offset, 4);
  msg->c0 = le32toh(msg->c0);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c1, buf + offset, 4);
  msg->c1 = le32toh(msg->c1);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c2, buf + offset, 4);
  msg->c2 = le32toh(msg->c2);
  offset += 4;
  return true;
}
/** Precise code biases correction
 *
 * The precise code biases message is to be added
 * to the pseudorange of the corresponding signal
 * to get corrected pseudorange. It is typically
 * an equivalent to the 1059 and 1065 RTCM message types
 */
#define SBP_MSG_SSR_CODE_BIASES 0x05E1

#define SBP_SSR_CODE_BIASES_SID_CODE__MASK (0xff)
#define SBP_SSR_CODE_BIASES_SID_CODE__SHIFT (0u)
#define SBP_SSR_CODE_BIASES_SID_CODE__GET(flags)      \
  (((flags) >> SBP_SSR_CODE_BIASES_SID_CODE__SHIFT) & \
   SBP_SSR_CODE_BIASES_SID_CODE__MASK)
#define SBP_SSR_CODE_BIASES_SID_CODE__SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_SSR_CODE_BIASES_SID_CODE__MASK)) \
                 << (SBP_SSR_CODE_BIASES_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_CODE_BIASES_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_CODE_BIASES_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_CODE_BIASES_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L1P (5)
#define SBP_SSR_CODE_BIASES_SID_CODE__GPS_L2P (6)
#define SBP_SSR_CODE_BIASES_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_CODE_BIASES_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_CODE_BIASES_SID_CODE__GAL_E1B (14)
#define SBP_SSR_CODE_BIASES_SID_CODE__GAL_E7I (20)
#define SBP_SSR_CODE_BIASES_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * GNSS reference time of the correction
   */
  struct {
    /**
     * Seconds since start of GPS week[s]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } time;
  /**
   * GNSS signal identifier (16 bit)
   */
  struct {
    /**
     * Constellation-specific satellite identifier. This field for Glonass can
     * either be (100+FCN) where FCN is in [-7,+6] or
     * the Slot ID in [1,28]
     */
    u8 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
  } sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Code biases for the different satellite signals
   */
  struct {
    /**
     * Signal constellation, band and code
     */
    u8 code;
    /**
     * Code bias value[0.01 m]
     */
    s16 value;
  } biases[81];
  /**
   * Number of items in biases
   */
  u8 n_biases;
} sbp_msg_ssr_code_biases_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_code_biases_t(
    const sbp_msg_ssr_code_biases_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) +
         (msg->n_biases *
          (0 + sizeof(msg->biases[0].code) + sizeof(msg->biases[0].value)));
}

static inline bool sbp_pack_sbp_msg_ssr_code_biases_t(
    u8 *buf, size_t len, const sbp_msg_ssr_code_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_code_biases_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtimetow = msg->time.tow;
  msgtimetow = htole32(msgtimetow);
  memcpy(buf + offset, &msgtimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtimewn = msg->time.wn;
  msgtimewn = htole16(msgtimewn);
  memcpy(buf + offset, &msgtimewn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  offset += 1;
  for (size_t msgbiases_idx = 0; msgbiases_idx < (size_t)msg->n_biases;
       msgbiases_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgbiasesmsgbiases_idxcode = msg->biases[msgbiases_idx].code;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxcode, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    s16 msgbiasesmsgbiases_idxvalue = msg->biases[msgbiases_idx].value;
    msgbiasesmsgbiases_idxvalue = htole16(msgbiasesmsgbiases_idxvalue);
    memcpy(buf + offset, &msgbiasesmsgbiases_idxvalue, 2);
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_code_biases_t(
    const u8 *buf, size_t len, sbp_msg_ssr_code_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  offset += 1;
  msg->n_biases = (u8)((len - offset) / 3);

  for (size_t msgbiases_idx = 0; msgbiases_idx < msg->n_biases;
       msgbiases_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].code, buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].value, buf + offset, 2);
    msg->biases[msgbiases_idx].value =
        le16toh(msg->biases[msgbiases_idx].value);
    offset += 2;
  }
  return true;
}
/** Precise phase biases correction
 *
 * The precise phase biases message contains the biases
 * to be added to the carrier phase of the corresponding
 * signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction.
 * It is typically an equivalent to the 1265 RTCM message types
 */
#define SBP_MSG_SSR_PHASE_BIASES 0x05E6

#define SBP_SSR_PHASE_BIASES_SID_CODE__MASK (0xff)
#define SBP_SSR_PHASE_BIASES_SID_CODE__SHIFT (0u)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GET(flags)      \
  (((flags) >> SBP_SSR_PHASE_BIASES_SID_CODE__SHIFT) & \
   SBP_SSR_PHASE_BIASES_SID_CODE__MASK)
#define SBP_SSR_PHASE_BIASES_SID_CODE__SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_SSR_PHASE_BIASES_SID_CODE__MASK)) \
                 << (SBP_SSR_PHASE_BIASES_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_PHASE_BIASES_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L1P (5)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GPS_L2P (6)
#define SBP_SSR_PHASE_BIASES_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_PHASE_BIASES_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GAL_E1B (14)
#define SBP_SSR_PHASE_BIASES_SID_CODE__GAL_E7I (20)
#define SBP_SSR_PHASE_BIASES_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * GNSS reference time of the correction
   */
  struct {
    /**
     * Seconds since start of GPS week[s]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } time;
  /**
   * GNSS signal identifier (16 bit)
   */
  struct {
    /**
     * Constellation-specific satellite identifier. This field for Glonass can
     * either be (100+FCN) where FCN is in [-7,+6] or
     * the Slot ID in [1,28]
     */
    u8 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
  } sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Indicator for the dispersive phase biases property.
   */
  u8 dispersive_bias;
  /**
   * Consistency indicator for Melbourne-Wubbena linear combinations
   */
  u8 mw_consistency;
  /**
   * Satellite yaw angle[1 / 256 semi-circle]
   */
  u16 yaw;
  /**
   * Satellite yaw angle rate[1 / 8192 semi-circle / s]
   */
  s8 yaw_rate;
  /**
   * Phase biases corrections for a
   * satellite being tracked.
   */
  struct {
    /**
     * Signal constellation, band and code
     */
    u8 code;
    /**
     * Indicator for integer property
     */
    u8 integer_indicator;
    /**
     * Indicator for two groups of Wide-Lane(s) integer property
     */
    u8 widelane_integer_indicator;
    /**
     * Signal phase discontinuity counter.
     * Increased for every discontinuity in phase.
     */
    u8 discontinuity_counter;
    /**
     * Phase bias for specified signal[0.1 mm]
     */
    s32 bias;
  } biases[30];
  /**
   * Number of items in biases
   */
  u8 n_biases;
} sbp_msg_ssr_phase_biases_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_phase_biases_t(
    const sbp_msg_ssr_phase_biases_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) +
         sizeof(msg->dispersive_bias) + sizeof(msg->mw_consistency) +
         sizeof(msg->yaw) + sizeof(msg->yaw_rate) +
         (msg->n_biases * (0 + sizeof(msg->biases[0].code) +
                           sizeof(msg->biases[0].integer_indicator) +
                           sizeof(msg->biases[0].widelane_integer_indicator) +
                           sizeof(msg->biases[0].discontinuity_counter) +
                           sizeof(msg->biases[0].bias)));
}

static inline bool sbp_pack_sbp_msg_ssr_phase_biases_t(
    u8 *buf, size_t len, const sbp_msg_ssr_phase_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_phase_biases_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtimetow = msg->time.tow;
  msgtimetow = htole32(msgtimetow);
  memcpy(buf + offset, &msgtimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtimewn = msg->time.wn;
  msgtimewn = htole16(msgtimewn);
  memcpy(buf + offset, &msgtimewn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgdispersive_bias = msg->dispersive_bias;
  memcpy(buf + offset, &msgdispersive_bias, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgmw_consistency = msg->mw_consistency;
  memcpy(buf + offset, &msgmw_consistency, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgyaw = msg->yaw;
  msgyaw = htole16(msgyaw);
  memcpy(buf + offset, &msgyaw, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  s8 msgyaw_rate = msg->yaw_rate;
  memcpy(buf + offset, &msgyaw_rate, 1);
  offset += 1;
  for (size_t msgbiases_idx = 0; msgbiases_idx < (size_t)msg->n_biases;
       msgbiases_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgbiasesmsgbiases_idxcode = msg->biases[msgbiases_idx].code;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxcode, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgbiasesmsgbiases_idxinteger_indicator =
        msg->biases[msgbiases_idx].integer_indicator;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxinteger_indicator, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgbiasesmsgbiases_idxwidelane_integer_indicator =
        msg->biases[msgbiases_idx].widelane_integer_indicator;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxwidelane_integer_indicator, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgbiasesmsgbiases_idxdiscontinuity_counter =
        msg->biases[msgbiases_idx].discontinuity_counter;
    memcpy(buf + offset, &msgbiasesmsgbiases_idxdiscontinuity_counter, 1);
    offset += 1;

    if (offset + 4 > len) {
      return false;
    }
    s32 msgbiasesmsgbiases_idxbias = msg->biases[msgbiases_idx].bias;
    msgbiasesmsgbiases_idxbias = htole32(msgbiasesmsgbiases_idxbias);
    memcpy(buf + offset, &msgbiasesmsgbiases_idxbias, 4);
    offset += 4;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_phase_biases_t(
    const u8 *buf, size_t len, sbp_msg_ssr_phase_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->dispersive_bias, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->mw_consistency, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->yaw, buf + offset, 2);
  msg->yaw = le16toh(msg->yaw);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->yaw_rate, buf + offset, 1);
  offset += 1;
  msg->n_biases = (u8)((len - offset) / 8);

  for (size_t msgbiases_idx = 0; msgbiases_idx < msg->n_biases;
       msgbiases_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].code, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].integer_indicator, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].widelane_integer_indicator, buf + offset,
           1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].discontinuity_counter, buf + offset, 1);
    offset += 1;

    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->biases[msgbiases_idx].bias, buf + offset, 4);
    msg->biases[msgbiases_idx].bias = le32toh(msg->biases[msgbiases_idx].bias);
    offset += 4;
  }
  return true;
}
/** STEC correction polynomial coeffcients.
 *
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
 * of the atmospheric delay.
 *
 * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
 */
#define SBP_MSG_SSR_STEC_CORRECTION 0x05FB

typedef struct {
  /**
   * Header of a STEC polynomial coeffcient message.
   */
  struct {
    /**
     * Unique identifier of the tile set this tile belongs to.
     */
    u16 tile_set_id;
    /**
     * Unique identifier of this tile in the tile set.
     */
    u16 tile_id;
    /**
     * GNSS reference time of the correction
     */
    struct {
      /**
       * Seconds since start of GPS week[s]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } time;
    /**
     * Number of messages in the dataset
     */
    u8 num_msgs;
    /**
     * Position of this message in the dataset
     */
    u8 seq_num;
    /**
     * Update interval between consecutive corrections. Encoded
     * following RTCM DF391 specification.
     */
    u8 update_interval;
    /**
     * IOD of the SSR atmospheric correction
     */
    u8 iod_atmo;
  } header;
  /**
   * Array of STEC polynomial coeffcients for each space vehicle.
   */
  struct {
    /**
     * Unique space vehicle identifier
     */
    struct {
      /**
       * ID of the space vehicle within its constellation
       */
      u8 satId;
      /**
       * Constellation ID to which the SV belongs
       */
      u8 constellation;
    } sv_id;
    /**
     * Quality of the STEC data. Encoded following RTCM DF389 specifcation
     * but in units of TECU instead of m.
     */
    u8 stec_quality_indicator;
    /**
     * Coefficents of the STEC polynomial in the order of C00, C01, C10, C11[C00
     * = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2]
     */
    s16 stec_coeff[4];
  } stec_sat_list[21];
  /**
   * Number of items in stec_sat_list
   */
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_t(
    const sbp_msg_ssr_stec_correction_t *msg) {
  (void)msg;
  return 0 +
         (0 + sizeof(msg->header.tile_set_id) + sizeof(msg->header.tile_id) +
          (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) +
          sizeof(msg->header.num_msgs) + sizeof(msg->header.seq_num) +
          sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo)) +
         (msg->n_stec_sat_list *
          (0 +
           (0 + sizeof(msg->stec_sat_list[0].sv_id.satId) +
            sizeof(msg->stec_sat_list[0].sv_id.constellation)) +
           sizeof(msg->stec_sat_list[0].stec_quality_indicator) +
           (4 * sizeof(msg->stec_sat_list[0].stec_coeff))));
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_t(
    u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_stec_correction_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertile_set_id = msg->header.tile_set_id;
  msgheadertile_set_id = htole16(msgheadertile_set_id);
  memcpy(buf + offset, &msgheadertile_set_id, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertile_id = msg->header.tile_id;
  msgheadertile_id = htole16(msgheadertile_id);
  memcpy(buf + offset, &msgheadertile_id, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheadertimetow = msg->header.time.tow;
  msgheadertimetow = htole32(msgheadertimetow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertimewn = msg->header.time.wn;
  msgheadertimewn = htole16(msgheadertimewn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadernum_msgs = msg->header.num_msgs;
  memcpy(buf + offset, &msgheadernum_msgs, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderseq_num = msg->header.seq_num;
  memcpy(buf + offset, &msgheaderseq_num, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  offset += 1;
  for (size_t msgstec_sat_list_idx = 0;
       msgstec_sat_list_idx < (size_t)msg->n_stec_sat_list;
       msgstec_sat_list_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idsatId =
        msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxsv_idsatId, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation =
        msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation;
    memcpy(buf + offset,
           &msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator =
        msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator;
    memcpy(buf + offset,
           &msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator, 1);
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++) {
      if (offset + 2 > len) {
        return false;
      }
      s16 msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          msg->stec_sat_list[msgstec_sat_list_idx]
              .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx];
      msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          htole16(
              msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx);
      memcpy(
          buf + offset,
          &msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx,
          2);
      offset += 2;
    }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_t(
    const u8 *buf, size_t len, sbp_msg_ssr_stec_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.tile_set_id, buf + offset, 2);
  msg->header.tile_set_id = le16toh(msg->header.tile_set_id);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.tile_id, buf + offset, 2);
  msg->header.tile_id = le16toh(msg->header.tile_id);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  offset += 1;
  msg->n_stec_sat_list = (u8)((len - offset) / 11);

  for (size_t msgstec_sat_list_idx = 0;
       msgstec_sat_list_idx < msg->n_stec_sat_list; msgstec_sat_list_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId, buf + offset,
           1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation,
           buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator,
           buf + offset, 1);
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++) {
      if (offset + 2 > len) {
        return false;
      }
      memcpy(
          &msg->stec_sat_list[msgstec_sat_list_idx]
               .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx],
          buf + offset, 2);
      msg->stec_sat_list[msgstec_sat_list_idx]
          .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx] =
          le16toh(msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff
                      [msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx]);
      offset += 2;
    }
  }
  return true;
}
/** Gridded troposphere and STEC correction residuals.
 *
 * STEC residuals are per space vehicle, troposphere is not.
 *
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages
 */
#define SBP_MSG_SSR_GRIDDED_CORRECTION 0x05FC

typedef struct {
  /**
   * Header of a gridded correction message
   */
  struct {
    /**
     * Unique identifier of the tile set this tile belongs to.
     */
    u16 tile_set_id;
    /**
     * Unique identifier of this tile in the tile set.
     */
    u16 tile_id;
    /**
     * GNSS reference time of the correction
     */
    struct {
      /**
       * Seconds since start of GPS week[s]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } time;
    /**
     * Number of messages in the dataset
     */
    u16 num_msgs;
    /**
     * Position of this message in the dataset
     */
    u16 seq_num;
    /**
     * Update interval between consecutive corrections. Encoded
     * following RTCM DF391 specification.
     */
    u8 update_interval;
    /**
     * IOD of the SSR atmospheric correction
     */
    u8 iod_atmo;
    /**
     * Quality of the troposphere data. Encoded following RTCM DF389
     * specifcation in units of m.
     */
    u8 tropo_quality_indicator;
  } header;
  /**
   * Tropo and STEC residuals for the given grid point.
   */
  struct {
    /**
     * Index of the grid point
     */
    u16 index;
    /**
     * Wet and hydrostatic vertical delays (mean, stddev)
     */
    struct {
      /**
       * Hydrostatic vertical delay[4 mm (add 2.3 m to get actual vertical hydro
       * delay)]
       */
      s16 hydro;
      /**
       * Wet vertical delay[4 mm (add 0.252 m to get actual vertical wet delay)]
       */
      s8 wet;
      /**
    * stddev[modified DF389 scale; class is upper 3 bits, value is lower 5
    stddev <= (3^class * (1 + value/16) - 1) mm
    ]
       */
      u8 stddev;
    } tropo_delay_correction;
    /**
     * STEC residuals for each satellite (mean, stddev)
     */
    struct {
      /**
       * space vehicle identifier
       */
      struct {
        /**
         * ID of the space vehicle within its constellation
         */
        u8 satId;
        /**
         * Constellation ID to which the SV belongs
         */
        u8 constellation;
      } sv_id;
      /**
       * STEC residual[0.04 TECU]
       */
      s16 residual;
      /**
    * stddev[modified DF389 scale; class is upper 3 bits, value is lower 5
    stddev <= (3^class * (1 + value/16) - 1) * 10 TECU
    ]
       */
      u8 stddev;
    } stec_residuals[46];
    /**
     * Number of items in stec_residuals
     */
    u8 n_stec_residuals;
  } element;
} sbp_msg_ssr_gridded_correction_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_t(
    const sbp_msg_ssr_gridded_correction_t *msg) {
  (void)msg;
  return 0 +
         (0 + sizeof(msg->header.tile_set_id) + sizeof(msg->header.tile_id) +
          (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) +
          sizeof(msg->header.num_msgs) + sizeof(msg->header.seq_num) +
          sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo) +
          sizeof(msg->header.tropo_quality_indicator)) +
         (0 + sizeof(msg->element.index) +
          (0 + sizeof(msg->element.tropo_delay_correction.hydro) +
           sizeof(msg->element.tropo_delay_correction.wet) +
           sizeof(msg->element.tropo_delay_correction.stddev)) +
          (msg->element.n_stec_residuals *
           (0 +
            (0 + sizeof(msg->element.stec_residuals[0].sv_id.satId) +
             sizeof(msg->element.stec_residuals[0].sv_id.constellation)) +
            sizeof(msg->element.stec_residuals[0].residual) +
            sizeof(msg->element.stec_residuals[0].stddev))));
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_t(
    u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_gridded_correction_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertile_set_id = msg->header.tile_set_id;
  msgheadertile_set_id = htole16(msgheadertile_set_id);
  memcpy(buf + offset, &msgheadertile_set_id, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertile_id = msg->header.tile_id;
  msgheadertile_id = htole16(msgheadertile_id);
  memcpy(buf + offset, &msgheadertile_id, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheadertimetow = msg->header.time.tow;
  msgheadertimetow = htole32(msgheadertimetow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertimewn = msg->header.time.wn;
  msgheadertimewn = htole16(msgheadertimewn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadernum_msgs = msg->header.num_msgs;
  msgheadernum_msgs = htole16(msgheadernum_msgs);
  memcpy(buf + offset, &msgheadernum_msgs, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheaderseq_num = msg->header.seq_num;
  msgheaderseq_num = htole16(msgheaderseq_num);
  memcpy(buf + offset, &msgheaderseq_num, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadertropo_quality_indicator = msg->header.tropo_quality_indicator;
  memcpy(buf + offset, &msgheadertropo_quality_indicator, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgelementindex = msg->element.index;
  msgelementindex = htole16(msgelementindex);
  memcpy(buf + offset, &msgelementindex, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgelementtropo_delay_correctionhydro =
      msg->element.tropo_delay_correction.hydro;
  msgelementtropo_delay_correctionhydro =
      htole16(msgelementtropo_delay_correctionhydro);
  memcpy(buf + offset, &msgelementtropo_delay_correctionhydro, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  s8 msgelementtropo_delay_correctionwet =
      msg->element.tropo_delay_correction.wet;
  memcpy(buf + offset, &msgelementtropo_delay_correctionwet, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgelementtropo_delay_correctionstddev =
      msg->element.tropo_delay_correction.stddev;
  memcpy(buf + offset, &msgelementtropo_delay_correctionstddev, 1);
  offset += 1;
  for (size_t msgelementstec_residuals_idx = 0;
       msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation =
        msg->element.stec_residuals[msgelementstec_residuals_idx]
            .sv_id.constellation;
    memcpy(
        buf + offset,
        &msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation,
        1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    s16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        msg->element.stec_residuals[msgelementstec_residuals_idx].residual;
    msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        htole16(msgelementstec_residualsmsgelementstec_residuals_idxresidual);
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxresidual, 2);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxstddev =
        msg->element.stec_residuals[msgelementstec_residuals_idx].stddev;
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxstddev, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_t(
    const u8 *buf, size_t len, sbp_msg_ssr_gridded_correction_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.tile_set_id, buf + offset, 2);
  msg->header.tile_set_id = le16toh(msg->header.tile_set_id);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.tile_id, buf + offset, 2);
  msg->header.tile_id = le16toh(msg->header.tile_id);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 2);
  msg->header.num_msgs = le16toh(msg->header.num_msgs);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 2);
  msg->header.seq_num = le16toh(msg->header.seq_num);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->element.index, buf + offset, 2);
  msg->element.index = le16toh(msg->element.index);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.hydro, buf + offset, 2);
  msg->element.tropo_delay_correction.hydro =
      le16toh(msg->element.tropo_delay_correction.hydro);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.stddev, buf + offset, 1);
  offset += 1;
  msg->element.n_stec_residuals = (u8)((len - offset) / 5);

  for (size_t msgelementstec_residuals_idx = 0;
       msgelementstec_residuals_idx < msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(
        &msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId,
        buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx]
                .sv_id.constellation,
           buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].residual,
           buf + offset, 2);
    msg->element.stec_residuals[msgelementstec_residuals_idx].residual =
        le16toh(
            msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].stddev,
           buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Definition of a SSR atmospheric correction tile.

 *
* Provides the correction point coordinates for the atmospheric correction
* values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
* messages.
*
* Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
* element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
* correction points, not lists of points.
 */
#define SBP_MSG_SSR_TILE_DEFINITION 0x05F6

typedef struct {
  /**
   * Unique identifier of the tile set this tile belongs to.
   */
  u16 tile_set_id;
  /**
   * Unique identifier of this tile in the tile set.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
   */
  u16 tile_id;
  /**
   * North-West corner correction point latitude.
   *
   * The relation between the latitude X in the range [-90, 90] and
   * the coded number N is:
   *
   * N = floor((X / 90) * 2^14)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.[encoded
   * degrees]
   */
  s16 corner_nw_lat;
  /**
   * North-West corner correction point longtitude.
   *
   * The relation between the longtitude X in the range [-180, 180]
   * and the coded number N is:
   *
   * N = floor((X / 180) * 2^15)
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.[encoded
   * degrees]
   */
  s16 corner_nw_lon;
  /**
   * Spacing of the correction points in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.[0.01 degrees]
   */
  u16 spacing_lat;
  /**
   * Spacing of the correction points in the longtitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongtitude.[0.01 degrees]
   */
  u16 spacing_lon;
  /**
   * Number of steps in the latitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
   */
  u16 rows;
  /**
   * Number of steps in the longtitude direction.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongtitude.
   */
  u16 cols;
  /**
   * Specifies the availability of correction data at the
   * correction points in the array.
   *
   * If a specific bit is enabled (set to 1), the correction is not
   * available. Only the first rows * cols bits are used, the remainder
   * are set to 0. If there are more then 64 correction points the
   * remaining corrections are always available.
   *
   * Starting with the northwest corner of the array (top left on a
   * north oriented map) the correction points are enumerated with row
   * precedence - first row west to east, second row west to east,
   * until last row west to east - ending with the southeast corner of
   * the array.
   *
   * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but
   * note the definition of the bits is inverted.
   */
  u64 bitmask;
} sbp_msg_ssr_tile_definition_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_tile_definition_t(
    const sbp_msg_ssr_tile_definition_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->tile_set_id) + sizeof(msg->tile_id) +
         sizeof(msg->corner_nw_lat) + sizeof(msg->corner_nw_lon) +
         sizeof(msg->spacing_lat) + sizeof(msg->spacing_lon) +
         sizeof(msg->rows) + sizeof(msg->cols) + sizeof(msg->bitmask);
}

static inline bool sbp_pack_sbp_msg_ssr_tile_definition_t(
    u8 *buf, size_t len, const sbp_msg_ssr_tile_definition_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_tile_definition_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtile_set_id = msg->tile_set_id;
  msgtile_set_id = htole16(msgtile_set_id);
  memcpy(buf + offset, &msgtile_set_id, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtile_id = msg->tile_id;
  msgtile_id = htole16(msgtile_id);
  memcpy(buf + offset, &msgtile_id, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgcorner_nw_lat = msg->corner_nw_lat;
  msgcorner_nw_lat = htole16(msgcorner_nw_lat);
  memcpy(buf + offset, &msgcorner_nw_lat, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgcorner_nw_lon = msg->corner_nw_lon;
  msgcorner_nw_lon = htole16(msgcorner_nw_lon);
  memcpy(buf + offset, &msgcorner_nw_lon, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgspacing_lat = msg->spacing_lat;
  msgspacing_lat = htole16(msgspacing_lat);
  memcpy(buf + offset, &msgspacing_lat, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgspacing_lon = msg->spacing_lon;
  msgspacing_lon = htole16(msgspacing_lon);
  memcpy(buf + offset, &msgspacing_lon, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgrows = msg->rows;
  msgrows = htole16(msgrows);
  memcpy(buf + offset, &msgrows, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcols = msg->cols;
  msgcols = htole16(msgcols);
  memcpy(buf + offset, &msgcols, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  u64 msgbitmask = msg->bitmask;
  msgbitmask = htole64(msgbitmask);
  memcpy(buf + offset, &msgbitmask, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_tile_definition_t(
    const u8 *buf, size_t len, sbp_msg_ssr_tile_definition_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->tile_set_id, buf + offset, 2);
  msg->tile_set_id = le16toh(msg->tile_set_id);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->tile_id, buf + offset, 2);
  msg->tile_id = le16toh(msg->tile_id);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->corner_nw_lat, buf + offset, 2);
  msg->corner_nw_lat = le16toh(msg->corner_nw_lat);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->corner_nw_lon, buf + offset, 2);
  msg->corner_nw_lon = le16toh(msg->corner_nw_lon);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->spacing_lat, buf + offset, 2);
  msg->spacing_lat = le16toh(msg->spacing_lat);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->spacing_lon, buf + offset, 2);
  msg->spacing_lon = le16toh(msg->spacing_lon);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->rows, buf + offset, 2);
  msg->rows = le16toh(msg->rows);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->cols, buf + offset, 2);
  msg->cols = le16toh(msg->cols);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->bitmask, buf + offset, 8);
  msg->bitmask = le64toh(msg->bitmask);
  offset += 8;
  return true;
}
#define SBP_MSG_SSR_ORBIT_CLOCK_DEP_A 0x05DC

#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__MASK (0xff)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SHIFT (0u)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GET(flags)      \
  (((flags) >> SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SHIFT) & \
   SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__MASK)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__MASK)) \
                 << (SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L1CA (0)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L2CM (1)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__SBAS_L1CA (2)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GLO_L1CA (3)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GLO_L2CA (4)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L1P (5)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GPS_L2P (6)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__BDS2_B1 (12)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__BDS2_B2 (13)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GAL_E1B (14)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__GAL_E7I (20)
#define SBP_SSR_ORBIT_CLOCK_DEP_A_SID_CODE__BDS3_B2A (47)
typedef struct {
  /**
   * GNSS reference time of the correction
   */
  struct {
    /**
     * Seconds since start of GPS week[s]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } time;
  /**
   * GNSS signal identifier (16 bit)
   */
  struct {
    /**
     * Constellation-specific satellite identifier. This field for Glonass can
     * either be (100+FCN) where FCN is in [-7,+6] or
     * the Slot ID in [1,28]
     */
    u8 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
  } sid;
  /**
   * Update interval between consecutive corrections. Encoded
   * following RTCM DF391 specification.
   */
  u8 update_interval;
  /**
   * IOD of the SSR correction. A change of Issue Of Data
   * SSR is used to indicate a change in the SSR
   * generating configuration
   */
  u8 iod_ssr;
  /**
   * Issue of broadcast ephemeris data
   */
  u8 iod;
  /**
   * Orbit radial delta correction[0.1 mm]
   */
  s32 radial;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 along;
  /**
   * Orbit along delta correction[0.4 mm]
   */
  s32 cross;
  /**
   * Velocity of orbit radial delta correction[0.001 mm/s]
   */
  s32 dot_radial;
  /**
   * Velocity of orbit along delta correction[0.004 mm/s]
   */
  s32 dot_along;
  /**
   * Velocity of orbit cross delta correction[0.004 mm/s]
   */
  s32 dot_cross;
  /**
   * C0 polynomial coefficient for correction of broadcast satellite clock[0.1
   * mm]
   */
  s32 c0;
  /**
   * C1 polynomial coefficient for correction of broadcast satellite clock[0.001
   * mm/s]
   */
  s32 c1;
  /**
   * C2 polynomial coefficient for correction of broadcast satellite
   * clock[0.00002 mm/s^-2]
   */
  s32 c2;
} sbp_msg_ssr_orbit_clock_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(
    const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->time.tow) + sizeof(msg->time.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->update_interval) + sizeof(msg->iod_ssr) +
         sizeof(msg->iod) + sizeof(msg->radial) + sizeof(msg->along) +
         sizeof(msg->cross) + sizeof(msg->dot_radial) + sizeof(msg->dot_along) +
         sizeof(msg->dot_cross) + sizeof(msg->c0) + sizeof(msg->c1) +
         sizeof(msg->c2);
}

static inline bool sbp_pack_sbp_msg_ssr_orbit_clock_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_orbit_clock_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtimetow = msg->time.tow;
  msgtimetow = htole32(msgtimetow);
  memcpy(buf + offset, &msgtimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtimewn = msg->time.wn;
  msgtimewn = htole16(msgtimewn);
  memcpy(buf + offset, &msgtimewn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, &msgsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgupdate_interval = msg->update_interval;
  memcpy(buf + offset, &msgupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod_ssr = msg->iod_ssr;
  memcpy(buf + offset, &msgiod_ssr, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod = msg->iod;
  memcpy(buf + offset, &msgiod, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgradial = msg->radial;
  msgradial = htole32(msgradial);
  memcpy(buf + offset, &msgradial, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgalong = msg->along;
  msgalong = htole32(msgalong);
  memcpy(buf + offset, &msgalong, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgcross = msg->cross;
  msgcross = htole32(msgcross);
  memcpy(buf + offset, &msgcross, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgdot_radial = msg->dot_radial;
  msgdot_radial = htole32(msgdot_radial);
  memcpy(buf + offset, &msgdot_radial, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgdot_along = msg->dot_along;
  msgdot_along = htole32(msgdot_along);
  memcpy(buf + offset, &msgdot_along, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgdot_cross = msg->dot_cross;
  msgdot_cross = htole32(msgdot_cross);
  memcpy(buf + offset, &msgdot_cross, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgc0 = msg->c0;
  msgc0 = htole32(msgc0);
  memcpy(buf + offset, &msgc0, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgc1 = msg->c1;
  msgc1 = htole32(msgc1);
  memcpy(buf + offset, &msgc1, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgc2 = msg->c2;
  msgc2 = htole32(msgc2);
  memcpy(buf + offset, &msgc2, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_orbit_clock_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ssr_orbit_clock_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->time.tow, buf + offset, 4);
  msg->time.tow = le32toh(msg->time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->time.wn, buf + offset, 2);
  msg->time.wn = le16toh(msg->time.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod_ssr, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->radial, buf + offset, 4);
  msg->radial = le32toh(msg->radial);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->along, buf + offset, 4);
  msg->along = le32toh(msg->along);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->cross, buf + offset, 4);
  msg->cross = le32toh(msg->cross);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->dot_radial, buf + offset, 4);
  msg->dot_radial = le32toh(msg->dot_radial);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->dot_along, buf + offset, 4);
  msg->dot_along = le32toh(msg->dot_along);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->dot_cross, buf + offset, 4);
  msg->dot_cross = le32toh(msg->dot_cross);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c0, buf + offset, 4);
  msg->c0 = le32toh(msg->c0);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c1, buf + offset, 4);
  msg->c1 = le32toh(msg->c1);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c2, buf + offset, 4);
  msg->c2 = le32toh(msg->c2);
  offset += 4;
  return true;
}
#define SBP_MSG_SSR_STEC_CORRECTION_DEP_A 0x05EB

typedef struct {
  /**
   * Header of a STEC message
   */
  struct {
    /**
     * GNSS reference time of the correction
     */
    struct {
      /**
       * Seconds since start of GPS week[s]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } time;
    /**
     * Number of messages in the dataset
     */
    u8 num_msgs;
    /**
     * Position of this message in the dataset
     */
    u8 seq_num;
    /**
     * Update interval between consecutive corrections. Encoded
     * following RTCM DF391 specification.
     */
    u8 update_interval;
    /**
     * IOD of the SSR atmospheric correction
     */
    u8 iod_atmo;
  } header;
  /**
   * Array of STEC information for each space vehicle
   */
  struct {
    /**
     * Unique space vehicle identifier
     */
    struct {
      /**
       * ID of the space vehicle within its constellation
       */
      u8 satId;
      /**
       * Constellation ID to which the SV belongs
       */
      u8 constellation;
    } sv_id;
    /**
     * Quality of the STEC data. Encoded following RTCM DF389 specifcation
     * but in units of TECU instead of m.
     */
    u8 stec_quality_indicator;
    /**
     * Coefficents of the STEC polynomial in the order of C00, C01, C10, C11[C00
     * = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2]
     */
    s16 stec_coeff[4];
  } stec_sat_list[22];
  /**
   * Number of items in stec_sat_list
   */
  u8 n_stec_sat_list;
} sbp_msg_ssr_stec_correction_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(
    const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) +
          sizeof(msg->header.num_msgs) + sizeof(msg->header.seq_num) +
          sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo)) +
         (msg->n_stec_sat_list *
          (0 +
           (0 + sizeof(msg->stec_sat_list[0].sv_id.satId) +
            sizeof(msg->stec_sat_list[0].sv_id.constellation)) +
           sizeof(msg->stec_sat_list[0].stec_quality_indicator) +
           (4 * sizeof(msg->stec_sat_list[0].stec_coeff))));
}

static inline bool sbp_pack_sbp_msg_ssr_stec_correction_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_stec_correction_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheadertimetow = msg->header.time.tow;
  msgheadertimetow = htole32(msgheadertimetow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertimewn = msg->header.time.wn;
  msgheadertimewn = htole16(msgheadertimewn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadernum_msgs = msg->header.num_msgs;
  memcpy(buf + offset, &msgheadernum_msgs, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderseq_num = msg->header.seq_num;
  memcpy(buf + offset, &msgheaderseq_num, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  offset += 1;
  for (size_t msgstec_sat_list_idx = 0;
       msgstec_sat_list_idx < (size_t)msg->n_stec_sat_list;
       msgstec_sat_list_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idsatId =
        msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId;
    memcpy(buf + offset, &msgstec_sat_listmsgstec_sat_list_idxsv_idsatId, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation =
        msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation;
    memcpy(buf + offset,
           &msgstec_sat_listmsgstec_sat_list_idxsv_idconstellation, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator =
        msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator;
    memcpy(buf + offset,
           &msgstec_sat_listmsgstec_sat_list_idxstec_quality_indicator, 1);
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++) {
      if (offset + 2 > len) {
        return false;
      }
      s16 msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          msg->stec_sat_list[msgstec_sat_list_idx]
              .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx];
      msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx =
          htole16(
              msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx);
      memcpy(
          buf + offset,
          &msgstec_sat_listmsgstec_sat_list_idxstec_coeffmsgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx,
          2);
      offset += 2;
    }
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_stec_correction_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ssr_stec_correction_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  offset += 1;
  msg->n_stec_sat_list = (u8)((len - offset) / 11);

  for (size_t msgstec_sat_list_idx = 0;
       msgstec_sat_list_idx < msg->n_stec_sat_list; msgstec_sat_list_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.satId, buf + offset,
           1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].sv_id.constellation,
           buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->stec_sat_list[msgstec_sat_list_idx].stec_quality_indicator,
           buf + offset, 1);
    offset += 1;
    for (size_t msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx = 0;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx < 4;
         msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx++) {
      if (offset + 2 > len) {
        return false;
      }
      memcpy(
          &msg->stec_sat_list[msgstec_sat_list_idx]
               .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx],
          buf + offset, 2);
      msg->stec_sat_list[msgstec_sat_list_idx]
          .stec_coeff[msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx] =
          le16toh(msg->stec_sat_list[msgstec_sat_list_idx].stec_coeff
                      [msgstec_sat_listmsgstec_sat_list_idxstec_coeff_idx]);
      offset += 2;
    }
  }
  return true;
}
#define SBP_MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A 0x05F0

typedef struct {
  /**
   * Header of a Gridded Correction message
   */
  struct {
    /**
     * GNSS reference time of the correction
     */
    struct {
      /**
       * Seconds since start of GPS week[s]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } time;
    /**
     * Number of messages in the dataset
     */
    u16 num_msgs;
    /**
     * Position of this message in the dataset
     */
    u16 seq_num;
    /**
     * Update interval between consecutive corrections. Encoded
     * following RTCM DF391 specification.
     */
    u8 update_interval;
    /**
     * IOD of the SSR atmospheric correction
     */
    u8 iod_atmo;
    /**
     * Quality of the troposphere data. Encoded following RTCM DF389
     * specifcation in units of m.
     */
    u8 tropo_quality_indicator;
  } header;
  /**
   * Tropo and STEC residuals for the given grid point
   */
  struct {
    /**
     * Index of the grid point
     */
    u16 index;
    /**
     * Wet and hydrostatic vertical delays
     */
    struct {
      /**
       * Hydrostatic vertical delay[4 mm (add 2.3 m to get actual vertical hydro
       * delay)]
       */
      s16 hydro;
      /**
       * Wet vertical delay[4 mm (add 0.252 m to get actual vertical wet delay)]
       */
      s8 wet;
    } tropo_delay_correction;
    /**
     * STEC residuals for each satellite
     */
    struct {
      /**
       * space vehicle identifier
       */
      struct {
        /**
         * ID of the space vehicle within its constellation
         */
        u8 satId;
        /**
         * Constellation ID to which the SV belongs
         */
        u8 constellation;
      } sv_id;
      /**
       * STEC residual[0.04 TECU]
       */
      s16 residual;
    } stec_residuals[59];
    /**
     * Number of items in stec_residuals
     */
    u8 n_stec_residuals;
  } element;
} sbp_msg_ssr_gridded_correction_no_std_dep_a_t;

static inline size_t
sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) +
          sizeof(msg->header.num_msgs) + sizeof(msg->header.seq_num) +
          sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo) +
          sizeof(msg->header.tropo_quality_indicator)) +
         (0 + sizeof(msg->element.index) +
          (0 + sizeof(msg->element.tropo_delay_correction.hydro) +
           sizeof(msg->element.tropo_delay_correction.wet)) +
          (msg->element.n_stec_residuals *
           (0 +
            (0 + sizeof(msg->element.stec_residuals[0].sv_id.satId) +
             sizeof(msg->element.stec_residuals[0].sv_id.constellation)) +
            sizeof(msg->element.stec_residuals[0].residual))));
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    u8 *buf, size_t len,
    const sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(msg) >
      len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheadertimetow = msg->header.time.tow;
  msgheadertimetow = htole32(msgheadertimetow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertimewn = msg->header.time.wn;
  msgheadertimewn = htole16(msgheadertimewn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadernum_msgs = msg->header.num_msgs;
  msgheadernum_msgs = htole16(msgheadernum_msgs);
  memcpy(buf + offset, &msgheadernum_msgs, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheaderseq_num = msg->header.seq_num;
  msgheaderseq_num = htole16(msgheaderseq_num);
  memcpy(buf + offset, &msgheaderseq_num, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadertropo_quality_indicator = msg->header.tropo_quality_indicator;
  memcpy(buf + offset, &msgheadertropo_quality_indicator, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgelementindex = msg->element.index;
  msgelementindex = htole16(msgelementindex);
  memcpy(buf + offset, &msgelementindex, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgelementtropo_delay_correctionhydro =
      msg->element.tropo_delay_correction.hydro;
  msgelementtropo_delay_correctionhydro =
      htole16(msgelementtropo_delay_correctionhydro);
  memcpy(buf + offset, &msgelementtropo_delay_correctionhydro, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  s8 msgelementtropo_delay_correctionwet =
      msg->element.tropo_delay_correction.wet;
  memcpy(buf + offset, &msgelementtropo_delay_correctionwet, 1);
  offset += 1;
  for (size_t msgelementstec_residuals_idx = 0;
       msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation =
        msg->element.stec_residuals[msgelementstec_residuals_idx]
            .sv_id.constellation;
    memcpy(
        buf + offset,
        &msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation,
        1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    s16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        msg->element.stec_residuals[msgelementstec_residuals_idx].residual;
    msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        htole16(msgelementstec_residualsmsgelementstec_residuals_idxresidual);
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxresidual, 2);
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_no_std_dep_a_t(
    const u8 *buf, size_t len,
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 2);
  msg->header.num_msgs = le16toh(msg->header.num_msgs);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 2);
  msg->header.seq_num = le16toh(msg->header.seq_num);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->element.index, buf + offset, 2);
  msg->element.index = le16toh(msg->element.index);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.hydro, buf + offset, 2);
  msg->element.tropo_delay_correction.hydro =
      le16toh(msg->element.tropo_delay_correction.hydro);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  offset += 1;
  msg->element.n_stec_residuals = (u8)((len - offset) / 4);

  for (size_t msgelementstec_residuals_idx = 0;
       msgelementstec_residuals_idx < msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(
        &msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId,
        buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx]
                .sv_id.constellation,
           buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].residual,
           buf + offset, 2);
    msg->element.stec_residuals[msgelementstec_residuals_idx].residual =
        le16toh(
            msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
    offset += 2;
  }
  return true;
}
#define SBP_MSG_SSR_GRIDDED_CORRECTION_DEP_A 0x05FA

typedef struct {
  /**
   * Header of a Gridded Correction message
   */
  struct {
    /**
     * GNSS reference time of the correction
     */
    struct {
      /**
       * Seconds since start of GPS week[s]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } time;
    /**
     * Number of messages in the dataset
     */
    u16 num_msgs;
    /**
     * Position of this message in the dataset
     */
    u16 seq_num;
    /**
     * Update interval between consecutive corrections. Encoded
     * following RTCM DF391 specification.
     */
    u8 update_interval;
    /**
     * IOD of the SSR atmospheric correction
     */
    u8 iod_atmo;
    /**
     * Quality of the troposphere data. Encoded following RTCM DF389
     * specifcation in units of m.
     */
    u8 tropo_quality_indicator;
  } header;
  /**
   * Tropo and STEC residuals for the given grid point (mean
   * and standard deviation)
   */
  struct {
    /**
     * Index of the grid point
     */
    u16 index;
    /**
     * Wet and hydrostatic vertical delays (mean, stddev)
     */
    struct {
      /**
       * Hydrostatic vertical delay[4 mm (add 2.3 m to get actual vertical hydro
       * delay)]
       */
      s16 hydro;
      /**
       * Wet vertical delay[4 mm (add 0.252 m to get actual vertical wet delay)]
       */
      s8 wet;
      /**
    * stddev[modified DF389 scale; class is upper 3 bits, value is lower 5
    stddev <= (3^class * (1 + value/16) - 1) mm
    ]
       */
      u8 stddev;
    } tropo_delay_correction;
    /**
     * STEC residuals for each satellite (mean, stddev)
     */
    struct {
      /**
       * space vehicle identifier
       */
      struct {
        /**
         * ID of the space vehicle within its constellation
         */
        u8 satId;
        /**
         * Constellation ID to which the SV belongs
         */
        u8 constellation;
      } sv_id;
      /**
       * STEC residual[0.04 TECU]
       */
      s16 residual;
      /**
    * stddev[modified DF389 scale; class is upper 3 bits, value is lower 5
    stddev <= (3^class * (1 + value/16) - 1) * 10 TECU
    ]
       */
      u8 stddev;
    } stec_residuals[47];
    /**
     * Number of items in stec_residuals
     */
    u8 n_stec_residuals;
  } element;
} sbp_msg_ssr_gridded_correction_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(
    const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.time.tow) + sizeof(msg->header.time.wn)) +
          sizeof(msg->header.num_msgs) + sizeof(msg->header.seq_num) +
          sizeof(msg->header.update_interval) + sizeof(msg->header.iod_atmo) +
          sizeof(msg->header.tropo_quality_indicator)) +
         (0 + sizeof(msg->element.index) +
          (0 + sizeof(msg->element.tropo_delay_correction.hydro) +
           sizeof(msg->element.tropo_delay_correction.wet) +
           sizeof(msg->element.tropo_delay_correction.stddev)) +
          (msg->element.n_stec_residuals *
           (0 +
            (0 + sizeof(msg->element.stec_residuals[0].sv_id.satId) +
             sizeof(msg->element.stec_residuals[0].sv_id.constellation)) +
            sizeof(msg->element.stec_residuals[0].residual) +
            sizeof(msg->element.stec_residuals[0].stddev))));
}

static inline bool sbp_pack_sbp_msg_ssr_gridded_correction_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_gridded_correction_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheadertimetow = msg->header.time.tow;
  msgheadertimetow = htole32(msgheadertimetow);
  memcpy(buf + offset, &msgheadertimetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertimewn = msg->header.time.wn;
  msgheadertimewn = htole16(msgheadertimewn);
  memcpy(buf + offset, &msgheadertimewn, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadernum_msgs = msg->header.num_msgs;
  msgheadernum_msgs = htole16(msgheadernum_msgs);
  memcpy(buf + offset, &msgheadernum_msgs, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheaderseq_num = msg->header.seq_num;
  msgheaderseq_num = htole16(msgheaderseq_num);
  memcpy(buf + offset, &msgheaderseq_num, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderupdate_interval = msg->header.update_interval;
  memcpy(buf + offset, &msgheaderupdate_interval, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderiod_atmo = msg->header.iod_atmo;
  memcpy(buf + offset, &msgheaderiod_atmo, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadertropo_quality_indicator = msg->header.tropo_quality_indicator;
  memcpy(buf + offset, &msgheadertropo_quality_indicator, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgelementindex = msg->element.index;
  msgelementindex = htole16(msgelementindex);
  memcpy(buf + offset, &msgelementindex, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgelementtropo_delay_correctionhydro =
      msg->element.tropo_delay_correction.hydro;
  msgelementtropo_delay_correctionhydro =
      htole16(msgelementtropo_delay_correctionhydro);
  memcpy(buf + offset, &msgelementtropo_delay_correctionhydro, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  s8 msgelementtropo_delay_correctionwet =
      msg->element.tropo_delay_correction.wet;
  memcpy(buf + offset, &msgelementtropo_delay_correctionwet, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgelementtropo_delay_correctionstddev =
      msg->element.tropo_delay_correction.stddev;
  memcpy(buf + offset, &msgelementtropo_delay_correctionstddev, 1);
  offset += 1;
  for (size_t msgelementstec_residuals_idx = 0;
       msgelementstec_residuals_idx < (size_t)msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId =
        msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId;
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxsv_idsatId, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation =
        msg->element.stec_residuals[msgelementstec_residuals_idx]
            .sv_id.constellation;
    memcpy(
        buf + offset,
        &msgelementstec_residualsmsgelementstec_residuals_idxsv_idconstellation,
        1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    s16 msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        msg->element.stec_residuals[msgelementstec_residuals_idx].residual;
    msgelementstec_residualsmsgelementstec_residuals_idxresidual =
        htole16(msgelementstec_residualsmsgelementstec_residuals_idxresidual);
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxresidual, 2);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgelementstec_residualsmsgelementstec_residuals_idxstddev =
        msg->element.stec_residuals[msgelementstec_residuals_idx].stddev;
    memcpy(buf + offset,
           &msgelementstec_residualsmsgelementstec_residuals_idxstddev, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_gridded_correction_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ssr_gridded_correction_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.time.tow, buf + offset, 4);
  msg->header.time.tow = le32toh(msg->header.time.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.time.wn, buf + offset, 2);
  msg->header.time.wn = le16toh(msg->header.time.wn);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 2);
  msg->header.num_msgs = le16toh(msg->header.num_msgs);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 2);
  msg->header.seq_num = le16toh(msg->header.seq_num);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.update_interval, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.iod_atmo, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.tropo_quality_indicator, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->element.index, buf + offset, 2);
  msg->element.index = le16toh(msg->element.index);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.hydro, buf + offset, 2);
  msg->element.tropo_delay_correction.hydro =
      le16toh(msg->element.tropo_delay_correction.hydro);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.wet, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->element.tropo_delay_correction.stddev, buf + offset, 1);
  offset += 1;
  msg->element.n_stec_residuals = (u8)((len - offset) / 5);

  for (size_t msgelementstec_residuals_idx = 0;
       msgelementstec_residuals_idx < msg->element.n_stec_residuals;
       msgelementstec_residuals_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(
        &msg->element.stec_residuals[msgelementstec_residuals_idx].sv_id.satId,
        buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx]
                .sv_id.constellation,
           buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].residual,
           buf + offset, 2);
    msg->element.stec_residuals[msgelementstec_residuals_idx].residual =
        le16toh(
            msg->element.stec_residuals[msgelementstec_residuals_idx].residual);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->element.stec_residuals[msgelementstec_residuals_idx].stddev,
           buf + offset, 1);
    offset += 1;
  }
  return true;
}
#define SBP_MSG_SSR_GRID_DEFINITION_DEP_A 0x05F5

typedef struct {
  /**
   * Header of a Gridded Correction message
   */
  struct {
    /**
     * region_size (deg) = 10 / region_size_inverse
     * 0 is an invalid value.[inverse degrees]
     */
    u8 region_size_inverse;
    /**
     * grid height (deg) = grid width (deg) = area_width / region_size
     * 0 is an invalid value.
     */
    u16 area_width;
    /**
     * North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
     */
    u16 lat_nw_corner_enc;
    /**
     * North-West corner longtitude (deg) = region_size * lon_nw_corner_enc -
     * 180
     */
    u16 lon_nw_corner_enc;
    /**
     * Number of messages in the dataset
     */
    u8 num_msgs;
    /**
     * Postion of this message in the dataset
     */
    u8 seq_num;
  } header;
  /**
   * Run Length Encode list of quadrants that contain valid data.
   * The spec describes the encoding scheme in detail, but
   * essentially the index of the quadrants that contain transitions between
   * valid and invalid (and vice versa) are encoded as u8 integers.
   */
  u8 rle_list[246];
  /**
   * Number of items in rle_list
   */
  u8 n_rle_list;
} sbp_msg_ssr_grid_definition_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(
    const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 + sizeof(msg->header.region_size_inverse) +
          sizeof(msg->header.area_width) +
          sizeof(msg->header.lat_nw_corner_enc) +
          sizeof(msg->header.lon_nw_corner_enc) + sizeof(msg->header.num_msgs) +
          sizeof(msg->header.seq_num)) +
         (msg->n_rle_list * sizeof(msg->rle_list));
}

static inline bool sbp_pack_sbp_msg_ssr_grid_definition_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ssr_grid_definition_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderregion_size_inverse = msg->header.region_size_inverse;
  memcpy(buf + offset, &msgheaderregion_size_inverse, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheaderarea_width = msg->header.area_width;
  msgheaderarea_width = htole16(msgheaderarea_width);
  memcpy(buf + offset, &msgheaderarea_width, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheaderlat_nw_corner_enc = msg->header.lat_nw_corner_enc;
  msgheaderlat_nw_corner_enc = htole16(msgheaderlat_nw_corner_enc);
  memcpy(buf + offset, &msgheaderlat_nw_corner_enc, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheaderlon_nw_corner_enc = msg->header.lon_nw_corner_enc;
  msgheaderlon_nw_corner_enc = htole16(msgheaderlon_nw_corner_enc);
  memcpy(buf + offset, &msgheaderlon_nw_corner_enc, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadernum_msgs = msg->header.num_msgs;
  memcpy(buf + offset, &msgheadernum_msgs, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheaderseq_num = msg->header.seq_num;
  memcpy(buf + offset, &msgheaderseq_num, 1);
  offset += 1;
  for (size_t msgrle_list_idx = 0; msgrle_list_idx < (size_t)msg->n_rle_list;
       msgrle_list_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgrle_listmsgrle_list_idx = msg->rle_list[msgrle_list_idx];
    memcpy(buf + offset, &msgrle_listmsgrle_list_idx, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ssr_grid_definition_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ssr_grid_definition_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.region_size_inverse, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.area_width, buf + offset, 2);
  msg->header.area_width = le16toh(msg->header.area_width);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.lat_nw_corner_enc, buf + offset, 2);
  msg->header.lat_nw_corner_enc = le16toh(msg->header.lat_nw_corner_enc);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.lon_nw_corner_enc, buf + offset, 2);
  msg->header.lon_nw_corner_enc = le16toh(msg->header.lon_nw_corner_enc);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.num_msgs, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.seq_num, buf + offset, 1);
  offset += 1;
  msg->n_rle_list = (u8)((len - offset) / 1);

  for (size_t msgrle_list_idx = 0; msgrle_list_idx < msg->n_rle_list;
       msgrle_list_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->rle_list[msgrle_list_idx], buf + offset, 1);
    offset += 1;
  }
  return true;
}

#endif /* LIBSBP_SSR_MESSAGES_H */