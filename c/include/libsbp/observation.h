#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss.h>
/** GPS satellite observations
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are be interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
#define SBP_MSG_OBS 0x004A

#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SHIFT (7u)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_GET(flags)      \
  (((flags) >> SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SHIFT) & \
   SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MASK)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MASK)) \
                 << (SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_SHIFT)));    \
  } while (0)

#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_NO_EXCLUSION (0)
#define SBP_OBS_OBS_FLAGS_RAIM_EXCLUSION_MEASUREMENT_WAS_EXCLUDED_BY_SPP_RAIM_USE_WITH_CARE \
  (1)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SHIFT (3u)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_GET(flags)      \
  (((flags) >> SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SHIFT) & \
   SBP_OBS_OBS_FLAGS_DOPPLER_VALID_MASK)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_OBS_OBS_FLAGS_DOPPLER_VALID_MASK)) \
                 << (SBP_OBS_OBS_FLAGS_DOPPLER_VALID_SHIFT)));    \
  } while (0)

#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_INVALID_DOPPLER_MEASUREMENT (0)
#define SBP_OBS_OBS_FLAGS_DOPPLER_VALID_VALID_DOPPLER_MEASUREMENT (1)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT (2u)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_GET(flags)      \
  (((flags) >> SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT) & \
   SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_MASK)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_MASK)) \
                 << (SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_SHIFT)));    \
  } while (0)

#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_UNRESOLVED \
  (0)
#define SBP_OBS_OBS_FLAGS_HALFCYCLE_AMBIGUITY_HALF_CYCLE_PHASE_AMBIGUITY_RESOLVED \
  (1)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SHIFT (1u)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_GET(flags)      \
  (((flags) >> SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SHIFT) & \
   SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_MASK)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_MASK)) \
                 << (SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_SHIFT)));    \
  } while (0)

#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_INVALID_CARRIER_PHASE_MEASUREMENT \
  (0)
#define SBP_OBS_OBS_FLAGS_CARRIER_PHASE_VALID_VALID_CARRIER_PHASE_MEASUREMENT \
  (1)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_MASK (0x1)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SHIFT (0u)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_GET(flags)      \
  (((flags) >> SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SHIFT) & \
   SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_MASK)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_MASK)) \
                 << (SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_SHIFT)));    \
  } while (0)

#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_INVALID_PSEUDORANGE_MEASUREMENT (0)
#define SBP_OBS_OBS_FLAGS_PSEUDORANGE_VALID_VALID_PSEUDORANGE_MEASUREMENT_AND_COARSE_TOW_DECODED \
  (1)

#define SBP_OBS_OBS_SID_CODE__MASK (0xff)
#define SBP_OBS_OBS_SID_CODE__SHIFT (0u)
#define SBP_OBS_OBS_SID_CODE__GET(flags) \
  (((flags) >> SBP_OBS_OBS_SID_CODE__SHIFT) & SBP_OBS_OBS_SID_CODE__MASK)
#define SBP_OBS_OBS_SID_CODE__SET(flags, val)           \
  do {                                                  \
    ((flags) |= (((val) & (SBP_OBS_OBS_SID_CODE__MASK)) \
                 << (SBP_OBS_OBS_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_OBS_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OBS_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OBS_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OBS_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OBS_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OBS_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OBS_OBS_SID_CODE__GPS_L2P (6)
#define SBP_OBS_OBS_SID_CODE__BDS2_B1 (12)
#define SBP_OBS_OBS_SID_CODE__BDS2_B2 (13)
#define SBP_OBS_OBS_SID_CODE__GAL_E1B (14)
#define SBP_OBS_OBS_SID_CODE__GAL_E7I (20)
#define SBP_OBS_OBS_SID_CODE__BDS3_B2A (47)
typedef struct {
  /**
   * Header of a GPS observation message
   */
  struct {
    /**
     * GNSS time of this observation
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * Nanosecond residual of millisecond-rounded TOW (ranges
       * from -500000 to 500000)[ns]
       */
      s32 ns_residual;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } t;
    /**
     * Total number of observations. First nibble is the size
     * of the sequence (n), second nibble is the zero-indexed
     * counter (ith packet of n)
     */
    u8 n_obs;
  } header;
  /**
   * Pseudorange and carrier phase observation for a
   * satellite being tracked.
   */
  struct {
    /**
     * Pseudorange observation[2 cm]
     */
    u32 P;
    /**
     * Carrier phase observation with typical sign convention.[cycles]
     */
    struct {
      /**
       * Carrier phase whole cycles[cycles]
       */
      s32 i;
      /**
       * Carrier phase fractional part[cycles / 256]
       */
      u8 f;
    } L;
    /**
     * Doppler observation with typical sign convention.[Hz]
     */
    struct {
      /**
       * Doppler whole Hz[Hz]
       */
      s16 i;
      /**
       * Doppler fractional part[Hz / 256]
       */
      u8 f;
    } D;
    /**
     * Carrier-to-Noise density.  Zero implies invalid cn0.[dB Hz / 4]
     */
    u8 cn0;
    /**
     * Lock timer. This value gives an indication of the time
     * for which a signal has maintained continuous phase lock.
     * Whenever a signal has lost and regained lock, this
     * value is reset to zero. It is encoded according to DF402 from
     * the RTCM 10403.2 Amendment 2 specification.  Valid values range
     * from 0 to 15 and the most significant nibble is reserved for future use.
     */
    u8 lock;
    /**
     * Measurement status flags. A bit field of flags providing the
     * status of this observation.  If this field is 0 it means only the Cn0
     * estimate for the signal is valid.
     */
    u8 flags;
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
  } obs[14];
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_t;

static inline size_t sbp_packed_size_sbp_msg_obs_t(const sbp_msg_obs_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.ns_residual) +
           sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->n_obs *
          (0 + sizeof(msg->obs[0].P) +
           (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           (0 + sizeof(msg->obs[0].D.i) + sizeof(msg->obs[0].D.f)) +
           sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) +
           sizeof(msg->obs[0].flags) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code))));
}

static inline bool sbp_pack_sbp_msg_obs_t(u8 *buf, size_t len,
                                          const sbp_msg_obs_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheaderttow = msg->header.t.tow;
  msgheaderttow = htole32(msgheaderttow);
  memcpy(buf + offset, &msgheaderttow, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgheadertns_residual = msg->header.t.ns_residual;
  msgheadertns_residual = htole32(msgheadertns_residual);
  memcpy(buf + offset, &msgheadertns_residual, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertwn = msg->header.t.wn;
  msgheadertwn = htole16(msgheadertwn);
  memcpy(buf + offset, &msgheadertwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    u32 msgobsmsgobs_idxP = msg->obs[msgobs_idx].P;
    msgobsmsgobs_idxP = htole32(msgobsmsgobs_idxP);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    s32 msgobsmsgobs_idxLi = msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = htole32(msgobsmsgobs_idxLi);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    s16 msgobsmsgobs_idxDi = msg->obs[msgobs_idx].D.i;
    msgobsmsgobs_idxDi = htole16(msgobsmsgobs_idxDi);
    memcpy(buf + offset, &msgobsmsgobs_idxDi, 2);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxDf = msg->obs[msgobs_idx].D.f;
    memcpy(buf + offset, &msgobsmsgobs_idxDf, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxflags = msg->obs[msgobs_idx].flags;
    memcpy(buf + offset, &msgobsmsgobs_idxflags, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidsat = msg->obs[msgobs_idx].sid.sat;
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_t(const u8 *buf, size_t len,
                                            sbp_msg_obs_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.ns_residual, buf + offset, 4);
  msg->header.t.ns_residual = le32toh(msg->header.t.ns_residual);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  offset += 1;
  msg->n_obs = (u8)((len - offset) / 17);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    msg->obs[msgobs_idx].L.i = le32toh(msg->obs[msgobs_idx].L.i);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].D.i, buf + offset, 2);
    msg->obs[msgobs_idx].D.i = le16toh(msg->obs[msgobs_idx].D.i);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].D.f, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].flags, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Base station position
 *
 * The base station position message is the position reported by
 * the base station itself. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an
 * error in the pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_LLH 0x0044

typedef struct {
  /**
   * Latitude[deg]
   */
  double lat;
  /**
   * Longitude[deg]
   */
  double lon;
  /**
   * Height[m]
   */
  double height;
} sbp_msg_base_pos_llh_t;

static inline size_t sbp_packed_size_sbp_msg_base_pos_llh_t(
    const sbp_msg_base_pos_llh_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height);
}

static inline bool sbp_pack_sbp_msg_base_pos_llh_t(
    u8 *buf, size_t len, const sbp_msg_base_pos_llh_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_base_pos_llh_t(msg) > len) {
    return false;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_llh_t(
    const u8 *buf, size_t len, sbp_msg_base_pos_llh_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;
  return true;
}
/** Base station position in ECEF
 *
 * The base station position message is the position reported by
 * the base station itself in absolute Earth Centered Earth Fixed
 * coordinates. It is used for pseudo-absolute RTK positioning, and
 * is required to be a high-accuracy surveyed location of the base
 * station. Any error here will result in an error in the
 * pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_ECEF 0x0048

typedef struct {
  /**
   * ECEF X coodinate[m]
   */
  double x;
  /**
   * ECEF Y coordinate[m]
   */
  double y;
  /**
   * ECEF Z coordinate[m]
   */
  double z;
} sbp_msg_base_pos_ecef_t;

static inline size_t sbp_packed_size_sbp_msg_base_pos_ecef_t(
    const sbp_msg_base_pos_ecef_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z);
}

static inline bool sbp_pack_sbp_msg_base_pos_ecef_t(
    u8 *buf, size_t len, const sbp_msg_base_pos_ecef_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_base_pos_ecef_t(msg) > len) {
    return false;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_base_pos_ecef_t(
    const u8 *buf, size_t len, sbp_msg_base_pos_ecef_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  offset += 8;
  return true;
}
/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_E 0x0081

#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GPS_DEP_E_COMMON_SID_CODE__GPS_L2P (6)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
    /**
     * Time of Ephemerides
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Group delay differential between L1 and L2[s]
   */
  double tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  double c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  double c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  double af2;
  /**
   * Clock reference
   */
  struct {
    /**
     * Milliseconds since start of GPS week[ms]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } toc;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_gps_dep_e_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(
    const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) +
           sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) +
         sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_e_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gps_dep_e_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommonsidsat = msg->common.sid.sat;
  msgcommonsidsat = htole16(msgcommonsidsat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_e_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_gps_dep_e_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;
  return true;
}
/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_F 0x0086

#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GPS_DEP_F_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * Others: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Group delay differential between L1 and L2[s]
   */
  double tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  double c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  double c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  double af2;
  /**
   * Clock reference
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
  } toc;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_gps_dep_f_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(
    const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) +
         sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_dep_f_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gps_dep_f_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_dep_f_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_gps_dep_f_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;
  return true;
}
/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_GPS 0x008A

#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GPS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GPS_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GPS_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Group delay differential between L1 and L2[s]
   */
  float tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  float c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  float c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  float af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  float af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  float af2;
  /**
   * Clock reference
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
  } toc;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_gps_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gps_t(
    const sbp_msg_ephemeris_gps_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) +
         sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gps_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_gps_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gps_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  float msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gps_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_gps_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;
  return true;
}
/** Satellite broadcast ephemeris for QZSS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate QZSS satellite position,
 * velocity, and clock offset.
 */
#define SBP_MSG_EPHEMERIS_QZSS 0x008E

#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_QZSS_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Group delay differential between L1 and L2[s]
   */
  float tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  float c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  float c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  float af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  float af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  float af2;
  /**
   * Clock reference
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
  } toc;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
  /**
   * Issue of clock data
   */
  u16 iodc;
} sbp_msg_ephemeris_qzss_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_qzss_t(
    const sbp_msg_ephemeris_qzss_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) +
         sizeof(msg->iode) + sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_qzss_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_qzss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_qzss_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  float msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_qzss_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_qzss_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;
  return true;
}
/** Satellite broadcast ephemeris for BDS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate BDS satellite position,
 * velocity, and clock offset. Please see the BeiDou Navigation
 * Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
 */
#define SBP_MSG_EPHEMERIS_BDS 0x0089

#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_BDS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_EPHEMERIS_BDS_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_BDS_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Group delay differential for B1[s]
   */
  float tgd1;
  /**
   * Group delay differential for B2[s]
   */
  float tgd2;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  float c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  float c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  float af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  float af2;
  /**
   * Clock reference
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
  } toc;
  /**
   * Issue of ephemeris data
   *
   * Calculated from the navigation data parameter t_oe per RTCM/CSNO
   * recommendation: IODE = mod (t_oe / 720, 240)
   */
  u8 iode;
  /**
   * Issue of clock data
   *
   * Calculated from the navigation data parameter t_oe per RTCM/CSNO
   * recommendation: IODE = mod (t_oc / 720, 240)
   */
  u16 iodc;
} sbp_msg_ephemeris_bds_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_bds_t(
    const sbp_msg_ephemeris_bds_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->tgd1) + sizeof(msg->tgd2) + sizeof(msg->c_rs) +
         sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) +
         sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->inc_dot) + sizeof(msg->af0) +
         sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) +
         sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_bds_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_bds_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_bds_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  float msgtgd1 = msg->tgd1;
  memcpy(buf + offset, &msgtgd1, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgtgd2 = msg->tgd2;
  memcpy(buf + offset, &msgtgd2, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_bds_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_bds_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tgd1, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tgd2, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;
  return true;
}
/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * an ephemeris message with explicit source of NAV data.
 */
#define SBP_MSG_EPHEMERIS_GAL_DEP_A 0x0095

#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GAL_DEP_A_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * E1-E5a Broadcast Group Delay[s]
   */
  float bgd_e1e5a;
  /**
   * E1-E5b Broadcast Group Delay[s]
   */
  float bgd_e1e5b;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  float c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  float c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  float af2;
  /**
   * Clock reference
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
  } toc;
  /**
   * Issue of data (IODnav)
   */
  u16 iode;
  /**
   * Issue of data (IODnav). Always equal to iode
   */
  u16 iodc;
} sbp_msg_ephemeris_gal_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(
    const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->bgd_e1e5a) + sizeof(msg->bgd_e1e5b) + sizeof(msg->c_rs) +
         sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) +
         sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->inc_dot) + sizeof(msg->af0) +
         sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) +
         sizeof(msg->iodc);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gal_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  float msgbgd_e1e5a = msg->bgd_e1e5a;
  memcpy(buf + offset, &msgbgd_e1e5a, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgbgd_e1e5b = msg->bgd_e1e5b;
  memcpy(buf + offset, &msgbgd_e1e5b, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiode = msg->iode;
  msgiode = htole16(msgiode);
  memcpy(buf + offset, &msgiode, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_gal_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->bgd_e1e5a, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->bgd_e1e5b, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 2);
  msg->iode = le16toh(msg->iode);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;
  return true;
}
/** Satellite broadcast ephemeris for Galileo
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate Galileo satellite position,
 * velocity, and clock offset. Please see the Signal In Space ICD
 * OS SIS ICD, Issue 1.3, December 2016 for more details.
 */
#define SBP_MSG_EPHEMERIS_GAL 0x008D

#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GAL_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GAL_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GAL_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * E1-E5a Broadcast Group Delay[s]
   */
  float bgd_e1e5a;
  /**
   * E1-E5b Broadcast Group Delay[s]
   */
  float bgd_e1e5b;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  float c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  float c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  float c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  float c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  float af2;
  /**
   * Clock reference
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
  } toc;
  /**
   * Issue of data (IODnav)
   */
  u16 iode;
  /**
   * Issue of data (IODnav). Always equal to iode
   */
  u16 iodc;
  /**
   * 0=I/NAV, 1=F/NAV
   */
  u8 source;
} sbp_msg_ephemeris_gal_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_gal_t(
    const sbp_msg_ephemeris_gal_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->bgd_e1e5a) + sizeof(msg->bgd_e1e5b) + sizeof(msg->c_rs) +
         sizeof(msg->c_rc) + sizeof(msg->c_uc) + sizeof(msg->c_us) +
         sizeof(msg->c_ic) + sizeof(msg->c_is) + sizeof(msg->dn) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) +
         sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->inc_dot) + sizeof(msg->af0) +
         sizeof(msg->af1) + sizeof(msg->af2) +
         (0 + sizeof(msg->toc.tow) + sizeof(msg->toc.wn)) + sizeof(msg->iode) +
         sizeof(msg->iodc) + sizeof(msg->source);
}

static inline bool sbp_pack_sbp_msg_ephemeris_gal_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_gal_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_gal_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  float msgbgd_e1e5a = msg->bgd_e1e5a;
  memcpy(buf + offset, &msgbgd_e1e5a, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgbgd_e1e5b = msg->bgd_e1e5b;
  memcpy(buf + offset, &msgbgd_e1e5b, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  float msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtoctow = msg->toc.tow;
  msgtoctow = htole32(msgtoctow);
  memcpy(buf + offset, &msgtoctow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtocwn = msg->toc.wn;
  msgtocwn = htole16(msgtocwn);
  memcpy(buf + offset, &msgtocwn, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiode = msg->iode;
  msgiode = htole16(msgiode);
  memcpy(buf + offset, &msgiode, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsource = msg->source;
  memcpy(buf + offset, &msgsource, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_gal_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_gal_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->bgd_e1e5a, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->bgd_e1e5b, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->toc.tow, buf + offset, 4);
  msg->toc.tow = le32toh(msg->toc.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc.wn, buf + offset, 2);
  msg->toc.wn = le16toh(msg->toc.wn);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 2);
  msg->iode = le16toh(msg->iode);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->source, buf + offset, 1);
  offset += 1;
  return true;
}
#define SBP_MSG_EPHEMERIS_SBAS_DEP_A 0x0082

#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_SBAS_DEP_A_COMMON_SID_CODE__GPS_L2P (6)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
    /**
     * Time of Ephemerides
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Position of the GEO at time toe[m]
   */
  double pos[3];
  /**
   * Velocity of the GEO at time toe[m/s]
   */
  double vel[3];
  /**
   * Acceleration of the GEO at time toe[m/s^2]
   */
  double acc[3];
  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time[s]
   */
  double a_gf0;
  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time[s/s]
   */
  double a_gf1;
} sbp_msg_ephemeris_sbas_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(
    const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) +
           sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         (3 * sizeof(msg->pos)) + (3 * sizeof(msg->vel)) +
         (3 * sizeof(msg->acc)) + sizeof(msg->a_gf0) + sizeof(msg->a_gf1);
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_sbas_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommonsidsat = msg->common.sid.sat;
  msgcommonsidsat = htole16(msgcommonsidsat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    offset += 8;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msga_gf0 = msg->a_gf0;
  memcpy(buf + offset, &msga_gf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msga_gf1 = msg->a_gf1;
  memcpy(buf + offset, &msga_gf1, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    offset += 8;
  }

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a_gf0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a_gf1, buf + offset, 8);
  offset += 8;
  return true;
}
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A 0x0083

#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_A_COMMON_SID_CODE__GPS_L2P (6)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
    /**
     * Time of Ephemerides
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;
  /**
   * Correction to the SV time[s]
   */
  double tau;
  /**
   * Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
  double pos[3];
  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
  double vel[3];
  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
  double acc[3];
} sbp_msg_ephemeris_glo_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(
    const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) +
           sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + (3 * sizeof(msg->pos)) +
         (3 * sizeof(msg->vel)) + (3 * sizeof(msg->acc));
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommonsidsat = msg->common.sid.sat;
  msgcommonsidsat = htole16(msgcommonsidsat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    offset += 8;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    offset += 8;
  }
  return true;
}
/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
 */
#define SBP_MSG_EPHEMERIS_SBAS_DEP_B 0x0084

#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                      \
    ((flags) |= (((val) & (SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_SBAS_DEP_B_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * Others: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Position of the GEO at time toe[m]
   */
  double pos[3];
  /**
   * Velocity of the GEO at time toe[m/s]
   */
  double vel[3];
  /**
   * Acceleration of the GEO at time toe[m/s^2]
   */
  double acc[3];
  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time[s]
   */
  double a_gf0;
  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time[s/s]
   */
  double a_gf1;
} sbp_msg_ephemeris_sbas_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(
    const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         (3 * sizeof(msg->pos)) + (3 * sizeof(msg->vel)) +
         (3 * sizeof(msg->acc)) + sizeof(msg->a_gf0) + sizeof(msg->a_gf1);
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_dep_b_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_sbas_dep_b_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    offset += 8;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msga_gf0 = msg->a_gf0;
  memcpy(buf + offset, &msga_gf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msga_gf1 = msg->a_gf1;
  memcpy(buf + offset, &msga_gf1, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_dep_b_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    offset += 8;
  }

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a_gf0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a_gf1, buf + offset, 8);
  offset += 8;
  return true;
}
#define SBP_MSG_EPHEMERIS_SBAS 0x008C

#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                \
    ((flags) |= (((val) & (SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_SBAS_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Position of the GEO at time toe[m]
   */
  double pos[3];
  /**
   * Velocity of the GEO at time toe[m/s]
   */
  float vel[3];
  /**
   * Acceleration of the GEO at time toe[m/s^2]
   */
  float acc[3];
  /**
   * Time offset of the GEO clock w.r.t. SBAS Network Time[s]
   */
  float a_gf0;
  /**
   * Drift of the GEO clock w.r.t. SBAS Network Time[s/s]
   */
  float a_gf1;
} sbp_msg_ephemeris_sbas_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_sbas_t(
    const sbp_msg_ephemeris_sbas_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         (3 * sizeof(msg->pos)) + (3 * sizeof(msg->vel)) +
         (3 * sizeof(msg->acc)) + sizeof(msg->a_gf0) + sizeof(msg->a_gf1);
}

static inline bool sbp_pack_sbp_msg_ephemeris_sbas_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_sbas_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_sbas_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    float msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 4);
    offset += 4;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    float msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 4);
    offset += 4;
  }

  if (offset + 4 > len) {
    return false;
  }
  float msga_gf0 = msg->a_gf0;
  memcpy(buf + offset, &msga_gf0, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msga_gf1 = msg->a_gf1;
  memcpy(buf + offset, &msga_gf1, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_sbas_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_sbas_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 4);
    offset += 4;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 4);
    offset += 4;
  }

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->a_gf0, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->a_gf1, buf + offset, 4);
  offset += 4;
  return true;
}
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B 0x0085

#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_DEP_B_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * Others: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;
  /**
   * Correction to the SV time[s]
   */
  double tau;
  /**
   * Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
  double pos[3];
  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
  double vel[3];
  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
  double acc[3];
} sbp_msg_ephemeris_glo_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(
    const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + (3 * sizeof(msg->pos)) +
         (3 * sizeof(msg->vel)) + (3 * sizeof(msg->acc));
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_b_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_b_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    offset += 8;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_b_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    offset += 8;
  }
  return true;
}
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C 0x0087

#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_DEP_C_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * Others: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;
  /**
   * Correction to the SV time[s]
   */
  double tau;
  /**
   * Equipment delay between L1 and L2[s]
   */
  double d_tau;
  /**
   * Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
  double pos[3];
  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
  double vel[3];
  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
  double acc[3];
  /**
   * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
  u8 fcn;
} sbp_msg_ephemeris_glo_dep_c_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(
    const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + sizeof(msg->d_tau) +
         (3 * sizeof(msg->pos)) + (3 * sizeof(msg->vel)) +
         (3 * sizeof(msg->acc)) + sizeof(msg->fcn);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_c_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_c_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgd_tau = msg->d_tau;
  memcpy(buf + offset, &msgd_tau, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    offset += 8;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_c_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->d_tau, buf + offset, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    offset += 8;
  }

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->fcn, buf + offset, 1);
  offset += 1;
  return true;
}
/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_D 0x0088

#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_DEP_D_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * Others: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  double gamma;
  /**
   * Correction to the SV time[s]
   */
  double tau;
  /**
   * Equipment delay between L1 and L2[s]
   */
  double d_tau;
  /**
   * Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
  double pos[3];
  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
  double vel[3];
  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
  double acc[3];
  /**
   * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
  u8 fcn;
  /**
   * Issue of data. Equal to the 7 bits of the immediate data word t_b
   */
  u8 iod;
} sbp_msg_ephemeris_glo_dep_d_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(
    const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + sizeof(msg->d_tau) +
         (3 * sizeof(msg->pos)) + (3 * sizeof(msg->vel)) +
         (3 * sizeof(msg->acc)) + sizeof(msg->fcn) + sizeof(msg->iod);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_dep_d_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_dep_d_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgd_tau = msg->d_tau;
  memcpy(buf + offset, &msgd_tau, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 8);
    offset += 8;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod = msg->iod;
  memcpy(buf + offset, &msgiod, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_dep_d_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_glo_dep_d_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->d_tau, buf + offset, 8);
  offset += 8;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 8);
    offset += 8;
  }

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->fcn, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 1);
  offset += 1;
  return true;
}
/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO 0x008B

#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_GLO_COMMON_SID_CODE__MASK)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_EPHEMERIS_GLO_COMMON_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_EPHEMERIS_GLO_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all ephemeris types
   */
  struct {
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
     * Time of Ephemerides
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
    } toe;
    /**
     * User Range Accuracy[m]
     */
    float ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */
    u8 health_bits;
  } common;
  /**
   * Relative deviation of predicted carrier frequency from nominal
   */
  float gamma;
  /**
   * Correction to the SV time[s]
   */
  float tau;
  /**
   * Equipment delay between L1 and L2[s]
   */
  float d_tau;
  /**
   * Position of the SV at tb in PZ-90.02 coordinates system[m]
   */
  double pos[3];
  /**
   * Velocity vector of the SV at tb in PZ-90.02 coordinates system[m/s]
   */
  double vel[3];
  /**
   * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys[m/s^2]
   */
  float acc[3];
  /**
   * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
   */
  u8 fcn;
  /**
   * Issue of data. Equal to the 7 bits of the immediate data word t_b
   */
  u8 iod;
} sbp_msg_ephemeris_glo_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_glo_t(
    const sbp_msg_ephemeris_glo_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toe.tow) + sizeof(msg->common.toe.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->gamma) + sizeof(msg->tau) + sizeof(msg->d_tau) +
         (3 * sizeof(msg->pos)) + (3 * sizeof(msg->vel)) +
         (3 * sizeof(msg->acc)) + sizeof(msg->fcn) + sizeof(msg->iod);
}

static inline bool sbp_pack_sbp_msg_ephemeris_glo_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_glo_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_glo_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoetow = msg->common.toe.tow;
  msgcommontoetow = htole32(msgcommontoetow);
  memcpy(buf + offset, &msgcommontoetow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoewn = msg->common.toe.wn;
  msgcommontoewn = htole16(msgcommontoewn);
  memcpy(buf + offset, &msgcommontoewn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  float msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  float msggamma = msg->gamma;
  memcpy(buf + offset, &msggamma, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgtau = msg->tau;
  memcpy(buf + offset, &msgtau, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  float msgd_tau = msg->d_tau;
  memcpy(buf + offset, &msgd_tau, 4);
  offset += 4;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgposmsgpos_idx = msg->pos[msgpos_idx];
    memcpy(buf + offset, &msgposmsgpos_idx, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    double msgvelmsgvel_idx = msg->vel[msgvel_idx];
    memcpy(buf + offset, &msgvelmsgvel_idx, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    float msgaccmsgacc_idx = msg->acc[msgacc_idx];
    memcpy(buf + offset, &msgaccmsgacc_idx, 4);
    offset += 4;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgfcn = msg->fcn;
  memcpy(buf + offset, &msgfcn, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiod = msg->iod;
  memcpy(buf + offset, &msgiod, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_glo_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_glo_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toe.tow, buf + offset, 4);
  msg->common.toe.tow = le32toh(msg->common.toe.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toe.wn, buf + offset, 2);
  msg->common.toe.wn = le16toh(msg->common.toe.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->gamma, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tau, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->d_tau, buf + offset, 4);
  offset += 4;
  for (size_t msgpos_idx = 0; msgpos_idx < 3; msgpos_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->pos[msgpos_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgvel_idx = 0; msgvel_idx < 3; msgvel_idx++) {
    if (offset + 8 > len) {
      return false;
    }
    memcpy(&msg->vel[msgvel_idx], buf + offset, 8);
    offset += 8;
  }
  for (size_t msgacc_idx = 0; msgacc_idx < 3; msgacc_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->acc[msgacc_idx], buf + offset, 4);
    offset += 4;
  }

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->fcn, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iod, buf + offset, 1);
  offset += 1;
  return true;
}
/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_DEP_D 0x0080

#define SBP_EPHEMERIS_DEP_D_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_DEP_D_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_DEP_D_SID_CODE__MASK)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_EPHEMERIS_DEP_D_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_DEP_D_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_DEP_D_SID_CODE__GPS_L2P (6)
typedef struct {
  /**
   * Group delay differential between L1 and L2[s]
   */
  double tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  double c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  double c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  double af2;
  /**
   * Time of week[s]
   */
  double toe_tow;
  /**
   * Week number[week]
   */
  u16 toe_wn;
  /**
   * Clock reference time of week[s]
   */
  double toc_tow;
  /**
   * Clock reference week number[week]
   */
  u16 toc_wn;
  /**
   * Is valid?
   */
  u8 valid;
  /**
   * Satellite is healthy?
   */
  u8 healthy;
  /**
   * GNSS signal identifier
   */
  struct {
    /**
     * Constellation-specific satellite identifier.
     *
     * Note: unlike GnssSignal, GPS satellites are encoded as
     * (PRN - 1). Other constellations do not have this offset.
     */
    u16 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
    /**
     * Reserved
     */
    u8 reserved;
  } sid;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
  /**
   * Issue of clock data
   */
  u16 iodc;
  /**
   * Reserved field
   */
  u32 reserved;
} sbp_msg_ephemeris_dep_d_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_d_t(
    const sbp_msg_ephemeris_dep_d_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + sizeof(msg->toe_tow) + sizeof(msg->toe_wn) +
         sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) +
         sizeof(msg->healthy) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) +
          sizeof(msg->sid.reserved)) +
         sizeof(msg->iode) + sizeof(msg->iodc) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_d_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_dep_d_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_d_t(msg) > len) {
    return false;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoe_wn = msg->toe_wn;
  msgtoe_wn = htole16(msgtoe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoc_wn = msg->toc_wn;
  msgtoc_wn = htole16(msgtoc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsidsat = msg->sid.sat;
  msgsidsat = htole16(msgsidsat);
  memcpy(buf + offset, &msgsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgreserved = msg->reserved;
  msgreserved = htole32(msgreserved);
  memcpy(buf + offset, &msgreserved, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_d_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_dep_d_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 4);
  msg->reserved = le32toh(msg->reserved);
  offset += 4;
  return true;
}
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_A 0x001A

typedef struct {
  /**
   * Group delay differential between L1 and L2[s]
   */
  double tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  double c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  double c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  double af2;
  /**
   * Time of week[s]
   */
  double toe_tow;
  /**
   * Week number[week]
   */
  u16 toe_wn;
  /**
   * Clock reference time of week[s]
   */
  double toc_tow;
  /**
   * Clock reference week number[week]
   */
  u16 toc_wn;
  /**
   * Is valid?
   */
  u8 valid;
  /**
   * Satellite is healthy?
   */
  u8 healthy;
  /**
   * PRN being tracked
   */
  u8 prn;
} sbp_msg_ephemeris_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_a_t(
    const sbp_msg_ephemeris_dep_a_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + sizeof(msg->toe_tow) + sizeof(msg->toe_wn) +
         sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) +
         sizeof(msg->healthy) + sizeof(msg->prn);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoe_wn = msg->toe_wn;
  msgtoe_wn = htole16(msgtoe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoc_wn = msg->toc_wn;
  msgtoc_wn = htole16(msgtoc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  offset += 1;
  return true;
}
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_B 0x0046

typedef struct {
  /**
   * Group delay differential between L1 and L2[s]
   */
  double tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  double c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  double c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  double af2;
  /**
   * Time of week[s]
   */
  double toe_tow;
  /**
   * Week number[week]
   */
  u16 toe_wn;
  /**
   * Clock reference time of week[s]
   */
  double toc_tow;
  /**
   * Clock reference week number[week]
   */
  u16 toc_wn;
  /**
   * Is valid?
   */
  u8 valid;
  /**
   * Satellite is healthy?
   */
  u8 healthy;
  /**
   * PRN being tracked
   */
  u8 prn;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
} sbp_msg_ephemeris_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_b_t(
    const sbp_msg_ephemeris_dep_b_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + sizeof(msg->toe_tow) + sizeof(msg->toe_wn) +
         sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) +
         sizeof(msg->healthy) + sizeof(msg->prn) + sizeof(msg->iode);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_b_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_b_t(msg) > len) {
    return false;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoe_wn = msg->toe_wn;
  msgtoe_wn = htole16(msgtoe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoc_wn = msg->toc_wn;
  msgtoc_wn = htole16(msgtoc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_b_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;
  return true;
}
/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_DEP_C 0x0047

#define SBP_EPHEMERIS_DEP_C_SID_CODE__MASK (0xff)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__SHIFT (0u)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GET(flags)      \
  (((flags) >> SBP_EPHEMERIS_DEP_C_SID_CODE__SHIFT) & \
   SBP_EPHEMERIS_DEP_C_SID_CODE__MASK)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_EPHEMERIS_DEP_C_SID_CODE__MASK)) \
                 << (SBP_EPHEMERIS_DEP_C_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L1CA (0)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L2CM (1)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__SBAS_L1CA (2)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GLO_L1CA (3)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GLO_L2CA (4)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L1P (5)
#define SBP_EPHEMERIS_DEP_C_SID_CODE__GPS_L2P (6)
typedef struct {
  /**
   * Group delay differential between L1 and L2[s]
   */
  double tgd;
  /**
   * Amplitude of the sine harmonic correction term to the orbit radius[m]
   */
  double c_rs;
  /**
   * Amplitude of the cosine harmonic correction term to the orbit radius[m]
   */
  double c_rc;
  /**
   * Amplitude of the cosine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_uc;
  /**
   * Amplitude of the sine harmonic correction term to the argument of
   * latitude[rad]
   */
  double c_us;
  /**
   * Amplitude of the cosine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_ic;
  /**
   * Amplitude of the sine harmonic correction term to the angle of
   * inclination[rad]
   */
  double c_is;
  /**
   * Mean motion difference[rad/s]
   */
  double dn;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Inclination first derivative[rad/s]
   */
  double inc_dot;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
  /**
   * Polynomial clock correction coefficient (rate of clock drift)[s/s^2]
   */
  double af2;
  /**
   * Time of week[s]
   */
  double toe_tow;
  /**
   * Week number[week]
   */
  u16 toe_wn;
  /**
   * Clock reference time of week[s]
   */
  double toc_tow;
  /**
   * Clock reference week number[week]
   */
  u16 toc_wn;
  /**
   * Is valid?
   */
  u8 valid;
  /**
   * Satellite is healthy?
   */
  u8 healthy;
  /**
   * GNSS signal identifier
   */
  struct {
    /**
     * Constellation-specific satellite identifier.
     *
     * Note: unlike GnssSignal, GPS satellites are encoded as
     * (PRN - 1). Other constellations do not have this offset.
     */
    u16 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
    /**
     * Reserved
     */
    u8 reserved;
  } sid;
  /**
   * Issue of ephemeris data
   */
  u8 iode;
  /**
   * Issue of clock data
   */
  u16 iodc;
  /**
   * Reserved field
   */
  u32 reserved;
} sbp_msg_ephemeris_dep_c_t;

static inline size_t sbp_packed_size_sbp_msg_ephemeris_dep_c_t(
    const sbp_msg_ephemeris_dep_c_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->tgd) + sizeof(msg->c_rs) + sizeof(msg->c_rc) +
         sizeof(msg->c_uc) + sizeof(msg->c_us) + sizeof(msg->c_ic) +
         sizeof(msg->c_is) + sizeof(msg->dn) + sizeof(msg->m0) +
         sizeof(msg->ecc) + sizeof(msg->sqrta) + sizeof(msg->omega0) +
         sizeof(msg->omegadot) + sizeof(msg->w) + sizeof(msg->inc) +
         sizeof(msg->inc_dot) + sizeof(msg->af0) + sizeof(msg->af1) +
         sizeof(msg->af2) + sizeof(msg->toe_tow) + sizeof(msg->toe_wn) +
         sizeof(msg->toc_tow) + sizeof(msg->toc_wn) + sizeof(msg->valid) +
         sizeof(msg->healthy) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) +
          sizeof(msg->sid.reserved)) +
         sizeof(msg->iode) + sizeof(msg->iodc) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_msg_ephemeris_dep_c_t(
    u8 *buf, size_t len, const sbp_msg_ephemeris_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ephemeris_dep_c_t(msg) > len) {
    return false;
  }

  if (offset + 8 > len) {
    return false;
  }
  double msgtgd = msg->tgd;
  memcpy(buf + offset, &msgtgd, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rs = msg->c_rs;
  memcpy(buf + offset, &msgc_rs, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_rc = msg->c_rc;
  memcpy(buf + offset, &msgc_rc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_uc = msg->c_uc;
  memcpy(buf + offset, &msgc_uc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_us = msg->c_us;
  memcpy(buf + offset, &msgc_us, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_ic = msg->c_ic;
  memcpy(buf + offset, &msgc_ic, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgc_is = msg->c_is;
  memcpy(buf + offset, &msgc_is, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgdn = msg->dn;
  memcpy(buf + offset, &msgdn, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc_dot = msg->inc_dot;
  memcpy(buf + offset, &msginc_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf2 = msg->af2;
  memcpy(buf + offset, &msgaf2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoe_tow = msg->toe_tow;
  memcpy(buf + offset, &msgtoe_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoe_wn = msg->toe_wn;
  msgtoe_wn = htole16(msgtoe_wn);
  memcpy(buf + offset, &msgtoe_wn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgtoc_tow = msg->toc_tow;
  memcpy(buf + offset, &msgtoc_tow, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgtoc_wn = msg->toc_wn;
  msgtoc_wn = htole16(msgtoc_wn);
  memcpy(buf + offset, &msgtoc_wn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msghealthy = msg->healthy;
  memcpy(buf + offset, &msghealthy, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsidsat = msg->sid.sat;
  msgsidsat = htole16(msgsidsat);
  memcpy(buf + offset, &msgsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgiode = msg->iode;
  memcpy(buf + offset, &msgiode, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgiodc = msg->iodc;
  msgiodc = htole16(msgiodc);
  memcpy(buf + offset, &msgiodc, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgreserved = msg->reserved;
  msgreserved = htole32(msgreserved);
  memcpy(buf + offset, &msgreserved, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ephemeris_dep_c_t(
    const u8 *buf, size_t len, sbp_msg_ephemeris_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rs, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_rc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_uc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_us, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_ic, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->c_is, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->dn, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af2, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toe_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toe_wn, buf + offset, 2);
  msg->toe_wn = le16toh(msg->toe_wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->toc_tow, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->toc_wn, buf + offset, 2);
  msg->toc_wn = le16toh(msg->toc_wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->healthy, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->iode, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->iodc, buf + offset, 2);
  msg->iodc = le16toh(msg->iodc);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 4);
  msg->reserved = le32toh(msg->reserved);
  offset += 4;
  return true;
}
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_OBS_DEP_A 0x0045

typedef struct {
  /**
   * Header of a GPS observation message
   */
  struct {
    /**
     * GPS time of this observation
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } t;
    /**
     * Total number of observations. First nibble is the size
     * of the sequence (n), second nibble is the zero-indexed
     * counter (ith packet of n)
     */
    u8 n_obs;
  } header;
  /**
   * Pseudorange and carrier phase observation for a
   * satellite being tracked.
   */
  struct {
    /**
     * Pseudorange observation[cm]
     */
    u32 P;
    /**
     * Carrier phase observation with opposite sign from typical convention
     */
    struct {
      /**
       * Carrier phase whole cycles[cycles]
       */
      s32 i;
      /**
       * Carrier phase fractional part[cycles / 256]
       */
      u8 f;
    } L;
    /**
     * Carrier-to-Noise density[dB Hz / 4]
     */
    u8 cn0;
    /**
     * Lock indicator. This value changes whenever a satellite
     * signal has lost and regained lock, indicating that the
     * carrier phase ambiguity may have changed.
     */
    u16 lock;
    /**
     * PRN-1 identifier of the satellite signal
     */
    u8 prn;
  } obs[19];
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_obs_dep_a_t(
    const sbp_msg_obs_dep_a_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->n_obs *
          (0 + sizeof(msg->obs[0].P) +
           (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) +
           sizeof(msg->obs[0].prn)));
}

static inline bool sbp_pack_sbp_msg_obs_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_obs_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheaderttow = msg->header.t.tow;
  msgheaderttow = htole32(msgheaderttow);
  memcpy(buf + offset, &msgheaderttow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertwn = msg->header.t.wn;
  msgheadertwn = htole16(msgheadertwn);
  memcpy(buf + offset, &msgheadertwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    u32 msgobsmsgobs_idxP = msg->obs[msgobs_idx].P;
    msgobsmsgobs_idxP = htole32(msgobsmsgobs_idxP);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    s32 msgobsmsgobs_idxLi = msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = htole32(msgobsmsgobs_idxLi);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    msgobsmsgobs_idxlock = htole16(msgobsmsgobs_idxlock);
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 2);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxprn = msg->obs[msgobs_idx].prn;
    memcpy(buf + offset, &msgobsmsgobs_idxprn, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_a_t(const u8 *buf, size_t len,
                                                  sbp_msg_obs_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  offset += 1;
  msg->n_obs = (u8)((len - offset) / 13);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    msg->obs[msgobs_idx].L.i = le32toh(msg->obs[msgobs_idx].L.i);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 2);
    msg->obs[msgobs_idx].lock = le16toh(msg->obs[msgobs_idx].lock);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].prn, buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * observations that are more interoperable. This message
 * should be used for observations referenced to
 * a nominal pseudorange which are not interoperable with
 * most 3rd party GNSS receievers or typical RTCMv3
 * observations.
 */
#define SBP_MSG_OBS_DEP_B 0x0043

#define SBP_OBS_DEP_B_OBS_SID_CODE__MASK (0xff)
#define SBP_OBS_DEP_B_OBS_SID_CODE__SHIFT (0u)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GET(flags)      \
  (((flags) >> SBP_OBS_DEP_B_OBS_SID_CODE__SHIFT) & \
   SBP_OBS_DEP_B_OBS_SID_CODE__MASK)
#define SBP_OBS_DEP_B_OBS_SID_CODE__SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_OBS_DEP_B_OBS_SID_CODE__MASK)) \
                 << (SBP_OBS_DEP_B_OBS_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OBS_DEP_B_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OBS_DEP_B_OBS_SID_CODE__GPS_L2P (6)
typedef struct {
  /**
   * Header of a GPS observation message
   */
  struct {
    /**
     * GPS time of this observation
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } t;
    /**
     * Total number of observations. First nibble is the size
     * of the sequence (n), second nibble is the zero-indexed
     * counter (ith packet of n)
     */
    u8 n_obs;
  } header;
  /**
   * Pseudorange and carrier phase observation for a
   * satellite being tracked.
   */
  struct {
    /**
     * Pseudorange observation[cm]
     */
    u32 P;
    /**
     * Carrier phase observation with opposite sign from typical convention.
     */
    struct {
      /**
       * Carrier phase whole cycles[cycles]
       */
      s32 i;
      /**
       * Carrier phase fractional part[cycles / 256]
       */
      u8 f;
    } L;
    /**
     * Carrier-to-Noise density[dB Hz / 4]
     */
    u8 cn0;
    /**
     * Lock indicator. This value changes whenever a satellite
     * signal has lost and regained lock, indicating that the
     * carrier phase ambiguity may have changed.
     */
    u16 lock;
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
  } obs[15];
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_obs_dep_b_t(
    const sbp_msg_obs_dep_b_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->n_obs *
          (0 + sizeof(msg->obs[0].P) +
           (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code) +
            sizeof(msg->obs[0].sid.reserved))));
}

static inline bool sbp_pack_sbp_msg_obs_dep_b_t(
    u8 *buf, size_t len, const sbp_msg_obs_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_dep_b_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheaderttow = msg->header.t.tow;
  msgheaderttow = htole32(msgheaderttow);
  memcpy(buf + offset, &msgheaderttow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertwn = msg->header.t.wn;
  msgheadertwn = htole16(msgheadertwn);
  memcpy(buf + offset, &msgheadertwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    u32 msgobsmsgobs_idxP = msg->obs[msgobs_idx].P;
    msgobsmsgobs_idxP = htole32(msgobsmsgobs_idxP);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    s32 msgobsmsgobs_idxLi = msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = htole32(msgobsmsgobs_idxLi);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    msgobsmsgobs_idxlock = htole16(msgobsmsgobs_idxlock);
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 2);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxsidsat = msg->obs[msgobs_idx].sid.sat;
    msgobsmsgobs_idxsidsat = htole16(msgobsmsgobs_idxsidsat);
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 2);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidreserved = msg->obs[msgobs_idx].sid.reserved;
    memcpy(buf + offset, &msgobsmsgobs_idxsidreserved, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_b_t(const u8 *buf, size_t len,
                                                  sbp_msg_obs_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  offset += 1;
  msg->n_obs = (u8)((len - offset) / 16);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    msg->obs[msgobs_idx].L.i = le32toh(msg->obs[msgobs_idx].L.i);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 2);
    msg->obs[msgobs_idx].lock = le16toh(msg->obs[msgobs_idx].lock);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 2);
    msg->obs[msgobs_idx].sid.sat = le16toh(msg->obs[msgobs_idx].sid.sat);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.reserved, buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Deprecated
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
#define SBP_MSG_OBS_DEP_C 0x0049

#define SBP_OBS_DEP_C_OBS_SID_CODE__MASK (0xff)
#define SBP_OBS_DEP_C_OBS_SID_CODE__SHIFT (0u)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GET(flags)      \
  (((flags) >> SBP_OBS_DEP_C_OBS_SID_CODE__SHIFT) & \
   SBP_OBS_DEP_C_OBS_SID_CODE__MASK)
#define SBP_OBS_DEP_C_OBS_SID_CODE__SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_OBS_DEP_C_OBS_SID_CODE__MASK)) \
                 << (SBP_OBS_DEP_C_OBS_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OBS_DEP_C_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OBS_DEP_C_OBS_SID_CODE__GPS_L2P (6)
typedef struct {
  /**
   * Header of a GPS observation message
   */
  struct {
    /**
     * GPS time of this observation
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } t;
    /**
     * Total number of observations. First nibble is the size
     * of the sequence (n), second nibble is the zero-indexed
     * counter (ith packet of n)
     */
    u8 n_obs;
  } header;
  /**
   * Pseudorange and carrier phase observation for a
   * satellite being tracked.
   */
  struct {
    /**
     * Pseudorange observation[2 cm]
     */
    u32 P;
    /**
     * Carrier phase observation with typical sign convention.[cycles]
     */
    struct {
      /**
       * Carrier phase whole cycles[cycles]
       */
      s32 i;
      /**
       * Carrier phase fractional part[cycles / 256]
       */
      u8 f;
    } L;
    /**
     * Carrier-to-Noise density[dB Hz / 4]
     */
    u8 cn0;
    /**
     * Lock indicator. This value changes whenever a satellite
     * signal has lost and regained lock, indicating that the
     * carrier phase ambiguity may have changed.
     */
    u16 lock;
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
  } obs[15];
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_obs_dep_c_t;

static inline size_t sbp_packed_size_sbp_msg_obs_dep_c_t(
    const sbp_msg_obs_dep_c_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->n_obs *
          (0 + sizeof(msg->obs[0].P) +
           (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].cn0) + sizeof(msg->obs[0].lock) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code) +
            sizeof(msg->obs[0].sid.reserved))));
}

static inline bool sbp_pack_sbp_msg_obs_dep_c_t(
    u8 *buf, size_t len, const sbp_msg_obs_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_obs_dep_c_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheaderttow = msg->header.t.tow;
  msgheaderttow = htole32(msgheaderttow);
  memcpy(buf + offset, &msgheaderttow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertwn = msg->header.t.wn;
  msgheadertwn = htole16(msgheadertwn);
  memcpy(buf + offset, &msgheadertwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    u32 msgobsmsgobs_idxP = msg->obs[msgobs_idx].P;
    msgobsmsgobs_idxP = htole32(msgobsmsgobs_idxP);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    s32 msgobsmsgobs_idxLi = msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = htole32(msgobsmsgobs_idxLi);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxcn0 = msg->obs[msgobs_idx].cn0;
    memcpy(buf + offset, &msgobsmsgobs_idxcn0, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    msgobsmsgobs_idxlock = htole16(msgobsmsgobs_idxlock);
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 2);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxsidsat = msg->obs[msgobs_idx].sid.sat;
    msgobsmsgobs_idxsidsat = htole16(msgobsmsgobs_idxsidsat);
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 2);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidreserved = msg->obs[msgobs_idx].sid.reserved;
    memcpy(buf + offset, &msgobsmsgobs_idxsidreserved, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_obs_dep_c_t(const u8 *buf, size_t len,
                                                  sbp_msg_obs_dep_c_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  offset += 1;
  msg->n_obs = (u8)((len - offset) / 16);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    msg->obs[msgobs_idx].L.i = le32toh(msg->obs[msgobs_idx].L.i);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].cn0, buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 2);
    msg->obs[msgobs_idx].lock = le16toh(msg->obs[msgobs_idx].lock);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 2);
    msg->obs[msgobs_idx].sid.sat = le16toh(msg->obs[msgobs_idx].sid.sat);
    offset += 2;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.reserved, buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** Iono corrections
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay.
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 */
#define SBP_MSG_IONO 0x0090

typedef struct {
  /**
   * Navigation Message Correction Table Valitidy Time
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
  } t_nmct;
  double a0;
  double a1;
  double a2;
  double a3;
  double b0;
  double b1;
  double b2;
  double b3;
} sbp_msg_iono_t;

static inline size_t sbp_packed_size_sbp_msg_iono_t(const sbp_msg_iono_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->t_nmct.tow) + sizeof(msg->t_nmct.wn)) +
         sizeof(msg->a0) + sizeof(msg->a1) + sizeof(msg->a2) + sizeof(msg->a3) +
         sizeof(msg->b0) + sizeof(msg->b1) + sizeof(msg->b2) + sizeof(msg->b3);
}

static inline bool sbp_pack_sbp_msg_iono_t(u8 *buf, size_t len,
                                           const sbp_msg_iono_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_iono_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgt_nmcttow = msg->t_nmct.tow;
  msgt_nmcttow = htole32(msgt_nmcttow);
  memcpy(buf + offset, &msgt_nmcttow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgt_nmctwn = msg->t_nmct.wn;
  msgt_nmctwn = htole16(msgt_nmctwn);
  memcpy(buf + offset, &msgt_nmctwn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msga0 = msg->a0;
  memcpy(buf + offset, &msga0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msga1 = msg->a1;
  memcpy(buf + offset, &msga1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msga2 = msg->a2;
  memcpy(buf + offset, &msga2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msga3 = msg->a3;
  memcpy(buf + offset, &msga3, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgb0 = msg->b0;
  memcpy(buf + offset, &msgb0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgb1 = msg->b1;
  memcpy(buf + offset, &msgb1, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgb2 = msg->b2;
  memcpy(buf + offset, &msgb2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgb3 = msg->b3;
  memcpy(buf + offset, &msgb3, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_iono_t(const u8 *buf, size_t len,
                                             sbp_msg_iono_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->t_nmct.tow, buf + offset, 4);
  msg->t_nmct.tow = le32toh(msg->t_nmct.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->t_nmct.wn, buf + offset, 2);
  msg->t_nmct.wn = le16toh(msg->t_nmct.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a2, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->a3, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->b0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->b1, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->b2, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->b3, buf + offset, 8);
  offset += 8;
  return true;
}
/** L2C capability mask
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 */
#define SBP_MSG_SV_CONFIGURATION_GPS_DEP 0x0091

typedef struct {
  /**
   * Navigation Message Correction Table Valitidy Time
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
  } t_nmct;
  /**
   * L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
   */
  u32 l2c_mask;
} sbp_msg_sv_configuration_gps_dep_t;

static inline size_t sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(
    const sbp_msg_sv_configuration_gps_dep_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->t_nmct.tow) + sizeof(msg->t_nmct.wn)) +
         sizeof(msg->l2c_mask);
}

static inline bool sbp_pack_sbp_msg_sv_configuration_gps_dep_t(
    u8 *buf, size_t len, const sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_sv_configuration_gps_dep_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgt_nmcttow = msg->t_nmct.tow;
  msgt_nmcttow = htole32(msgt_nmcttow);
  memcpy(buf + offset, &msgt_nmcttow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgt_nmctwn = msg->t_nmct.wn;
  msgt_nmctwn = htole16(msgt_nmctwn);
  memcpy(buf + offset, &msgt_nmctwn, 2);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgl2c_mask = msg->l2c_mask;
  msgl2c_mask = htole32(msgl2c_mask);
  memcpy(buf + offset, &msgl2c_mask, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_configuration_gps_dep_t(
    const u8 *buf, size_t len, sbp_msg_sv_configuration_gps_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->t_nmct.tow, buf + offset, 4);
  msg->t_nmct.tow = le32toh(msg->t_nmct.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->t_nmct.wn, buf + offset, 2);
  msg->t_nmct.wn = le16toh(msg->t_nmct.wn);
  offset += 2;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->l2c_mask, buf + offset, 4);
  msg->l2c_mask = le32toh(msg->l2c_mask);
  offset += 4;
  return true;
}
#define SBP_MSG_GNSS_CAPB 0x0096

typedef struct {
  /**
   * Navigation Message Correction Table Validity Time
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
  } t_nmct;
  /**
   * GNSS capabilities masks
   */
  struct {
    /**
     * GPS SV active mask
     */
    u64 gps_active;
    /**
     * GPS L2C active mask
     */
    u64 gps_l2c;
    /**
     * GPS L5 active mask
     */
    u64 gps_l5;
    /**
     * GLO active mask
     */
    u32 glo_active;
    /**
     * GLO L2OF active mask
     */
    u32 glo_l2of;
    /**
     * GLO L3 active mask
     */
    u32 glo_l3;
    /**
     * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
     * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
     */
    u64 sbas_active;
    /**
     * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
     * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
     */
    u64 sbas_l5;
    /**
     * BDS active mask
     */
    u64 bds_active;
    /**
     * BDS D2NAV active mask
     */
    u64 bds_d2nav;
    /**
     * BDS B2 active mask
     */
    u64 bds_b2;
    /**
     * BDS B2A active mask
     */
    u64 bds_b2a;
    /**
     * QZSS active mask
     */
    u32 qzss_active;
    /**
     * GAL active mask
     */
    u64 gal_active;
    /**
     * GAL E5 active mask
     */
    u64 gal_e5;
  } gc;
} sbp_msg_gnss_capb_t;

static inline size_t sbp_packed_size_sbp_msg_gnss_capb_t(
    const sbp_msg_gnss_capb_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->t_nmct.tow) + sizeof(msg->t_nmct.wn)) +
         (0 + sizeof(msg->gc.gps_active) + sizeof(msg->gc.gps_l2c) +
          sizeof(msg->gc.gps_l5) + sizeof(msg->gc.glo_active) +
          sizeof(msg->gc.glo_l2of) + sizeof(msg->gc.glo_l3) +
          sizeof(msg->gc.sbas_active) + sizeof(msg->gc.sbas_l5) +
          sizeof(msg->gc.bds_active) + sizeof(msg->gc.bds_d2nav) +
          sizeof(msg->gc.bds_b2) + sizeof(msg->gc.bds_b2a) +
          sizeof(msg->gc.qzss_active) + sizeof(msg->gc.gal_active) +
          sizeof(msg->gc.gal_e5));
}

static inline bool sbp_pack_sbp_msg_gnss_capb_t(
    u8 *buf, size_t len, const sbp_msg_gnss_capb_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gnss_capb_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgt_nmcttow = msg->t_nmct.tow;
  msgt_nmcttow = htole32(msgt_nmcttow);
  memcpy(buf + offset, &msgt_nmcttow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgt_nmctwn = msg->t_nmct.wn;
  msgt_nmctwn = htole16(msgt_nmctwn);
  memcpy(buf + offset, &msgt_nmctwn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcgps_active = msg->gc.gps_active;
  msggcgps_active = htole64(msggcgps_active);
  memcpy(buf + offset, &msggcgps_active, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcgps_l2c = msg->gc.gps_l2c;
  msggcgps_l2c = htole64(msggcgps_l2c);
  memcpy(buf + offset, &msggcgps_l2c, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcgps_l5 = msg->gc.gps_l5;
  msggcgps_l5 = htole64(msggcgps_l5);
  memcpy(buf + offset, &msggcgps_l5, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msggcglo_active = msg->gc.glo_active;
  msggcglo_active = htole32(msggcglo_active);
  memcpy(buf + offset, &msggcglo_active, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msggcglo_l2of = msg->gc.glo_l2of;
  msggcglo_l2of = htole32(msggcglo_l2of);
  memcpy(buf + offset, &msggcglo_l2of, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  u32 msggcglo_l3 = msg->gc.glo_l3;
  msggcglo_l3 = htole32(msggcglo_l3);
  memcpy(buf + offset, &msggcglo_l3, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcsbas_active = msg->gc.sbas_active;
  msggcsbas_active = htole64(msggcsbas_active);
  memcpy(buf + offset, &msggcsbas_active, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcsbas_l5 = msg->gc.sbas_l5;
  msggcsbas_l5 = htole64(msggcsbas_l5);
  memcpy(buf + offset, &msggcsbas_l5, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcbds_active = msg->gc.bds_active;
  msggcbds_active = htole64(msggcbds_active);
  memcpy(buf + offset, &msggcbds_active, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcbds_d2nav = msg->gc.bds_d2nav;
  msggcbds_d2nav = htole64(msggcbds_d2nav);
  memcpy(buf + offset, &msggcbds_d2nav, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcbds_b2 = msg->gc.bds_b2;
  msggcbds_b2 = htole64(msggcbds_b2);
  memcpy(buf + offset, &msggcbds_b2, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcbds_b2a = msg->gc.bds_b2a;
  msggcbds_b2a = htole64(msggcbds_b2a);
  memcpy(buf + offset, &msggcbds_b2a, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msggcqzss_active = msg->gc.qzss_active;
  msggcqzss_active = htole32(msggcqzss_active);
  memcpy(buf + offset, &msggcqzss_active, 4);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcgal_active = msg->gc.gal_active;
  msggcgal_active = htole64(msggcgal_active);
  memcpy(buf + offset, &msggcgal_active, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  u64 msggcgal_e5 = msg->gc.gal_e5;
  msggcgal_e5 = htole64(msggcgal_e5);
  memcpy(buf + offset, &msggcgal_e5, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_gnss_capb_t(const u8 *buf, size_t len,
                                                  sbp_msg_gnss_capb_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->t_nmct.tow, buf + offset, 4);
  msg->t_nmct.tow = le32toh(msg->t_nmct.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->t_nmct.wn, buf + offset, 2);
  msg->t_nmct.wn = le16toh(msg->t_nmct.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.gps_active, buf + offset, 8);
  msg->gc.gps_active = le64toh(msg->gc.gps_active);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.gps_l2c, buf + offset, 8);
  msg->gc.gps_l2c = le64toh(msg->gc.gps_l2c);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.gps_l5, buf + offset, 8);
  msg->gc.gps_l5 = le64toh(msg->gc.gps_l5);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->gc.glo_active, buf + offset, 4);
  msg->gc.glo_active = le32toh(msg->gc.glo_active);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->gc.glo_l2of, buf + offset, 4);
  msg->gc.glo_l2of = le32toh(msg->gc.glo_l2of);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->gc.glo_l3, buf + offset, 4);
  msg->gc.glo_l3 = le32toh(msg->gc.glo_l3);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.sbas_active, buf + offset, 8);
  msg->gc.sbas_active = le64toh(msg->gc.sbas_active);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.sbas_l5, buf + offset, 8);
  msg->gc.sbas_l5 = le64toh(msg->gc.sbas_l5);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.bds_active, buf + offset, 8);
  msg->gc.bds_active = le64toh(msg->gc.bds_active);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.bds_d2nav, buf + offset, 8);
  msg->gc.bds_d2nav = le64toh(msg->gc.bds_d2nav);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.bds_b2, buf + offset, 8);
  msg->gc.bds_b2 = le64toh(msg->gc.bds_b2);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.bds_b2a, buf + offset, 8);
  msg->gc.bds_b2a = le64toh(msg->gc.bds_b2a);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->gc.qzss_active, buf + offset, 4);
  msg->gc.qzss_active = le32toh(msg->gc.qzss_active);
  offset += 4;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.gal_active, buf + offset, 8);
  msg->gc.gal_active = le64toh(msg->gc.gal_active);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->gc.gal_e5, buf + offset, 8);
  msg->gc.gal_e5 = le64toh(msg->gc.gal_e5);
  offset += 8;
  return true;
}
/** Group Delay
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY_DEP_A 0x0092

typedef struct {
  /**
   * Data Predict Time of Week
   */
  struct {
    /**
     * Milliseconds since start of GPS week[ms]
     */
    u32 tow;
    /**
     * GPS week number[week]
     */
    u16 wn;
  } t_op;
  /**
   * Satellite number
   */
  u8 prn;
  /**
   * bit-field indicating validity of the values,
   * LSB indicating tgd validity etc.
   * 1 = value is valid, 0 = value is not valid.
   */
  u8 valid;
  s16 tgd;
  s16 isc_l1ca;
  s16 isc_l2c;
} sbp_msg_group_delay_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_a_t(
    const sbp_msg_group_delay_dep_a_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->t_op.tow) + sizeof(msg->t_op.wn)) +
         sizeof(msg->prn) + sizeof(msg->valid) + sizeof(msg->tgd) +
         sizeof(msg->isc_l1ca) + sizeof(msg->isc_l2c);
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_a_t(
    u8 *buf, size_t len, const sbp_msg_group_delay_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_delay_dep_a_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgt_optow = msg->t_op.tow;
  msgt_optow = htole32(msgt_optow);
  memcpy(buf + offset, &msgt_optow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgt_opwn = msg->t_op.wn;
  msgt_opwn = htole16(msgt_opwn);
  memcpy(buf + offset, &msgt_opwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, &msgprn, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgtgd = msg->tgd;
  msgtgd = htole16(msgtgd);
  memcpy(buf + offset, &msgtgd, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgisc_l1ca = msg->isc_l1ca;
  msgisc_l1ca = htole16(msgisc_l1ca);
  memcpy(buf + offset, &msgisc_l1ca, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgisc_l2c = msg->isc_l2c;
  msgisc_l2c = htole16(msgisc_l2c);
  memcpy(buf + offset, &msgisc_l2c, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_a_t(
    const u8 *buf, size_t len, sbp_msg_group_delay_dep_a_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->t_op.tow, buf + offset, 4);
  msg->t_op.tow = le32toh(msg->t_op.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->t_op.wn, buf + offset, 2);
  msg->t_op.wn = le16toh(msg->t_op.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->prn, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 2);
  msg->tgd = le16toh(msg->tgd);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->isc_l1ca, buf + offset, 2);
  msg->isc_l1ca = le16toh(msg->isc_l1ca);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->isc_l2c, buf + offset, 2);
  msg->isc_l2c = le16toh(msg->isc_l2c);
  offset += 2;
  return true;
}
/** Group Delay
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY_DEP_B 0x0093

#define SBP_GROUP_DELAY_DEP_B_SID_CODE__MASK (0xff)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__SHIFT (0u)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GET(flags)      \
  (((flags) >> SBP_GROUP_DELAY_DEP_B_SID_CODE__SHIFT) & \
   SBP_GROUP_DELAY_DEP_B_SID_CODE__MASK)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__SET(flags, val)           \
  do {                                                            \
    ((flags) |= (((val) & (SBP_GROUP_DELAY_DEP_B_SID_CODE__MASK)) \
                 << (SBP_GROUP_DELAY_DEP_B_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L1CA (0)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L2CM (1)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__SBAS_L1CA (2)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GLO_L1CA (3)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GLO_L2CA (4)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L1P (5)
#define SBP_GROUP_DELAY_DEP_B_SID_CODE__GPS_L2P (6)
typedef struct {
  /**
   * Data Predict Time of Week
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
  } t_op;
  /**
   * GNSS signal identifier
   */
  struct {
    /**
     * Constellation-specific satellite identifier.
     *
     * Note: unlike GnssSignal, GPS satellites are encoded as
     * (PRN - 1). Other constellations do not have this offset.
     */
    u16 sat;
    /**
     * Signal constellation, band and code
     */
    u8 code;
    /**
     * Reserved
     */
    u8 reserved;
  } sid;
  /**
   * bit-field indicating validity of the values,
   * LSB indicating tgd validity etc.
   * 1 = value is valid, 0 = value is not valid.
   */
  u8 valid;
  s16 tgd;
  s16 isc_l1ca;
  s16 isc_l2c;
} sbp_msg_group_delay_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_group_delay_dep_b_t(
    const sbp_msg_group_delay_dep_b_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->t_op.tow) + sizeof(msg->t_op.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code) +
          sizeof(msg->sid.reserved)) +
         sizeof(msg->valid) + sizeof(msg->tgd) + sizeof(msg->isc_l1ca) +
         sizeof(msg->isc_l2c);
}

static inline bool sbp_pack_sbp_msg_group_delay_dep_b_t(
    u8 *buf, size_t len, const sbp_msg_group_delay_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_delay_dep_b_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgt_optow = msg->t_op.tow;
  msgt_optow = htole32(msgt_optow);
  memcpy(buf + offset, &msgt_optow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgt_opwn = msg->t_op.wn;
  msgt_opwn = htole16(msgt_opwn);
  memcpy(buf + offset, &msgt_opwn, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgsidsat = msg->sid.sat;
  msgsidsat = htole16(msgsidsat);
  memcpy(buf + offset, &msgsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, &msgsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, &msgsidreserved, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgtgd = msg->tgd;
  msgtgd = htole16(msgtgd);
  memcpy(buf + offset, &msgtgd, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgisc_l1ca = msg->isc_l1ca;
  msgisc_l1ca = htole16(msgisc_l1ca);
  memcpy(buf + offset, &msgisc_l1ca, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgisc_l2c = msg->isc_l2c;
  msgisc_l2c = htole16(msgisc_l2c);
  memcpy(buf + offset, &msgisc_l2c, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_dep_b_t(
    const u8 *buf, size_t len, sbp_msg_group_delay_dep_b_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->t_op.tow, buf + offset, 4);
  msg->t_op.tow = le32toh(msg->t_op.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->t_op.wn, buf + offset, 2);
  msg->t_op.wn = le16toh(msg->t_op.wn);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh(msg->sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 2);
  msg->tgd = le16toh(msg->tgd);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->isc_l1ca, buf + offset, 2);
  msg->isc_l1ca = le16toh(msg->isc_l1ca);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->isc_l2c, buf + offset, 2);
  msg->isc_l2c = le16toh(msg->isc_l2c);
  offset += 2;
  return true;
}
/** Group Delay
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY 0x0094

#define SBP_GROUP_DELAY_SID_CODE__MASK (0xff)
#define SBP_GROUP_DELAY_SID_CODE__SHIFT (0u)
#define SBP_GROUP_DELAY_SID_CODE__GET(flags)      \
  (((flags) >> SBP_GROUP_DELAY_SID_CODE__SHIFT) & \
   SBP_GROUP_DELAY_SID_CODE__MASK)
#define SBP_GROUP_DELAY_SID_CODE__SET(flags, val)           \
  do {                                                      \
    ((flags) |= (((val) & (SBP_GROUP_DELAY_SID_CODE__MASK)) \
                 << (SBP_GROUP_DELAY_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_GROUP_DELAY_SID_CODE__GPS_L1CA (0)
#define SBP_GROUP_DELAY_SID_CODE__GPS_L2CM (1)
#define SBP_GROUP_DELAY_SID_CODE__SBAS_L1CA (2)
#define SBP_GROUP_DELAY_SID_CODE__GLO_L1CA (3)
#define SBP_GROUP_DELAY_SID_CODE__GLO_L2CA (4)
#define SBP_GROUP_DELAY_SID_CODE__GPS_L1P (5)
#define SBP_GROUP_DELAY_SID_CODE__GPS_L2P (6)
#define SBP_GROUP_DELAY_SID_CODE__BDS2_B1 (12)
#define SBP_GROUP_DELAY_SID_CODE__BDS2_B2 (13)
#define SBP_GROUP_DELAY_SID_CODE__GAL_E1B (14)
#define SBP_GROUP_DELAY_SID_CODE__GAL_E7I (20)
#define SBP_GROUP_DELAY_SID_CODE__BDS3_B2A (47)
typedef struct {
  /**
   * Data Predict Time of Week
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
  } t_op;
  /**
   * GNSS signal identifier
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
   * bit-field indicating validity of the values,
   * LSB indicating tgd validity etc.
   * 1 = value is valid, 0 = value is not valid.
   */
  u8 valid;
  s16 tgd;
  s16 isc_l1ca;
  s16 isc_l2c;
} sbp_msg_group_delay_t;

static inline size_t sbp_packed_size_sbp_msg_group_delay_t(
    const sbp_msg_group_delay_t *msg) {
  (void)msg;
  return 0 + (0 + sizeof(msg->t_op.tow) + sizeof(msg->t_op.wn)) +
         (0 + sizeof(msg->sid.sat) + sizeof(msg->sid.code)) +
         sizeof(msg->valid) + sizeof(msg->tgd) + sizeof(msg->isc_l1ca) +
         sizeof(msg->isc_l2c);
}

static inline bool sbp_pack_sbp_msg_group_delay_t(
    u8 *buf, size_t len, const sbp_msg_group_delay_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_delay_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgt_optow = msg->t_op.tow;
  msgt_optow = htole32(msgt_optow);
  memcpy(buf + offset, &msgt_optow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgt_opwn = msg->t_op.wn;
  msgt_opwn = htole16(msgt_opwn);
  memcpy(buf + offset, &msgt_opwn, 2);
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
  u8 msgvalid = msg->valid;
  memcpy(buf + offset, &msgvalid, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgtgd = msg->tgd;
  msgtgd = htole16(msgtgd);
  memcpy(buf + offset, &msgtgd, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgisc_l1ca = msg->isc_l1ca;
  msgisc_l1ca = htole16(msgisc_l1ca);
  memcpy(buf + offset, &msgisc_l1ca, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgisc_l2c = msg->isc_l2c;
  msgisc_l2c = htole16(msgisc_l2c);
  memcpy(buf + offset, &msgisc_l2c, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_delay_t(
    const u8 *buf, size_t len, sbp_msg_group_delay_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->t_op.tow, buf + offset, 4);
  msg->t_op.tow = le32toh(msg->t_op.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->t_op.wn, buf + offset, 2);
  msg->t_op.wn = le16toh(msg->t_op.wn);
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
  memcpy(&msg->valid, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->tgd, buf + offset, 2);
  msg->tgd = le16toh(msg->tgd);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->isc_l1ca, buf + offset, 2);
  msg->isc_l1ca = le16toh(msg->isc_l1ca);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->isc_l2c, buf + offset, 2);
  msg->isc_l2c = le16toh(msg->isc_l2c);
  offset += 2;
  return true;
}
/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
#define SBP_MSG_ALMANAC_GPS_DEP 0x0070

#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SHIFT) & \
   SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__MASK)) \
                 << (SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GPS_DEP_COMMON_SID_CODE__GPS_L2P (6)

typedef struct {
  /**
   * Values common for all almanac types
   */
  struct {
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
    /**
     * Reference time of almanac
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
    } toa;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of almanac, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status for GPS:
     *   - bits 5-7: NAV data health status. See IS-GPS-200H
     *     Table 20-VII: NAV Data Health Indications.
     *   - bits 0-4: Signal health status. See IS-GPS-200H
     *     Table 20-VIII. Codes for Health of SV Signal
     *     Components.
     * Satellite health status for GLO:
     *   See GLO ICD 5.1 table 5.1 for details
     *   - bit 0: C(n), "unhealthy" flag that is transmitted within
     *     non-immediate data and indicates overall constellation status
     *     at the moment of almanac uploading.
     *     '0' indicates malfunction of n-satellite.
     *     '1' indicates that n-satellite is operational.
     *   - bit 1: Bn(ln), '0' indicates the satellite is operational
     *     and suitable for navigation.
     */
    u8 health_bits;
  } common;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
} sbp_msg_almanac_gps_dep_t;

static inline size_t sbp_packed_size_sbp_msg_almanac_gps_dep_t(
    const sbp_msg_almanac_gps_dep_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) +
           sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) +
         sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->af0) + sizeof(msg->af1);
}

static inline bool sbp_pack_sbp_msg_almanac_gps_dep_t(
    u8 *buf, size_t len, const sbp_msg_almanac_gps_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_gps_dep_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommonsidsat = msg->common.sid.sat;
  msgcommonsidsat = htole16(msgcommonsidsat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoatow = msg->common.toa.tow;
  msgcommontoatow = htole32(msgcommontoatow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoawn = msg->common.toa.wn;
  msgcommontoawn = htole16(msgcommontoawn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_dep_t(
    const u8 *buf, size_t len, sbp_msg_almanac_gps_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;
  return true;
}
/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
#define SBP_MSG_ALMANAC_GPS 0x0072

#define SBP_ALMANAC_GPS_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ALMANAC_GPS_COMMON_SID_CODE__SHIFT) & \
   SBP_ALMANAC_GPS_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_ALMANAC_GPS_COMMON_SID_CODE__MASK)) \
                 << (SBP_ALMANAC_GPS_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_ALMANAC_GPS_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all almanac types
   */
  struct {
    /**
     * GNSS signal identifier
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
     * Reference time of almanac
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
    } toa;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of almanac, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status for GPS:
     *   - bits 5-7: NAV data health status. See IS-GPS-200H
     *     Table 20-VII: NAV Data Health Indications.
     *   - bits 0-4: Signal health status. See IS-GPS-200H
     *     Table 20-VIII. Codes for Health of SV Signal
     *     Components.
     * Satellite health status for GLO:
     *   See GLO ICD 5.1 table 5.1 for details
     *   - bit 0: C(n), "unhealthy" flag that is transmitted within
     *     non-immediate data and indicates overall constellation status
     *     at the moment of almanac uploading.
     *     '0' indicates malfunction of n-satellite.
     *     '1' indicates that n-satellite is operational.
     *   - bit 1: Bn(ln), '0' indicates the satellite is operational
     *     and suitable for navigation.
     */
    u8 health_bits;
  } common;
  /**
   * Mean anomaly at reference time[rad]
   */
  double m0;
  /**
   * Eccentricity of satellite orbit
   */
  double ecc;
  /**
   * Square root of the semi-major axis of orbit[m^(1/2)]
   */
  double sqrta;
  /**
   * Longitude of ascending node of orbit plane at weekly epoch[rad]
   */
  double omega0;
  /**
   * Rate of right ascension[rad/s]
   */
  double omegadot;
  /**
   * Argument of perigee[rad]
   */
  double w;
  /**
   * Inclination[rad]
   */
  double inc;
  /**
   * Polynomial clock correction coefficient (clock bias)[s]
   */
  double af0;
  /**
   * Polynomial clock correction coefficient (clock drift)[s/s]
   */
  double af1;
} sbp_msg_almanac_gps_t;

static inline size_t sbp_packed_size_sbp_msg_almanac_gps_t(
    const sbp_msg_almanac_gps_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->m0) + sizeof(msg->ecc) + sizeof(msg->sqrta) +
         sizeof(msg->omega0) + sizeof(msg->omegadot) + sizeof(msg->w) +
         sizeof(msg->inc) + sizeof(msg->af0) + sizeof(msg->af1);
}

static inline bool sbp_pack_sbp_msg_almanac_gps_t(
    u8 *buf, size_t len, const sbp_msg_almanac_gps_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_gps_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoatow = msg->common.toa.tow;
  msgcommontoatow = htole32(msgcommontoatow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoawn = msg->common.toa.wn;
  msgcommontoawn = htole16(msgcommontoawn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msgm0 = msg->m0;
  memcpy(buf + offset, &msgm0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgecc = msg->ecc;
  memcpy(buf + offset, &msgecc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgsqrta = msg->sqrta;
  memcpy(buf + offset, &msgsqrta, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega0 = msg->omega0;
  memcpy(buf + offset, &msgomega0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomegadot = msg->omegadot;
  memcpy(buf + offset, &msgomegadot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgw = msg->w;
  memcpy(buf + offset, &msgw, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msginc = msg->inc;
  memcpy(buf + offset, &msginc, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf0 = msg->af0;
  memcpy(buf + offset, &msgaf0, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgaf1 = msg->af1;
  memcpy(buf + offset, &msgaf1, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_gps_t(
    const u8 *buf, size_t len, sbp_msg_almanac_gps_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->m0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->ecc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->sqrta, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omegadot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->w, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->inc, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af0, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->af1, buf + offset, 8);
  offset += 8;
  return true;
}
/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
 */
#define SBP_MSG_ALMANAC_GLO_DEP 0x0071

#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SHIFT) & \
   SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__MASK)) \
                 << (SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GLO_DEP_COMMON_SID_CODE__GPS_L2P (6)

typedef struct {
  /**
   * Values common for all almanac types
   */
  struct {
    /**
     * GNSS signal identifier
     */
    struct {
      /**
       * Constellation-specific satellite identifier.
       *
       * Note: unlike GnssSignal, GPS satellites are encoded as
       * (PRN - 1). Other constellations do not have this offset.
       */
      u16 sat;
      /**
       * Signal constellation, band and code
       */
      u8 code;
      /**
       * Reserved
       */
      u8 reserved;
    } sid;
    /**
     * Reference time of almanac
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
    } toa;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of almanac, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status for GPS:
     *   - bits 5-7: NAV data health status. See IS-GPS-200H
     *     Table 20-VII: NAV Data Health Indications.
     *   - bits 0-4: Signal health status. See IS-GPS-200H
     *     Table 20-VIII. Codes for Health of SV Signal
     *     Components.
     * Satellite health status for GLO:
     *   See GLO ICD 5.1 table 5.1 for details
     *   - bit 0: C(n), "unhealthy" flag that is transmitted within
     *     non-immediate data and indicates overall constellation status
     *     at the moment of almanac uploading.
     *     '0' indicates malfunction of n-satellite.
     *     '1' indicates that n-satellite is operational.
     *   - bit 1: Bn(ln), '0' indicates the satellite is operational
     *     and suitable for navigation.
     */
    u8 health_bits;
  } common;
  /**
   * Longitude of the first ascending node of the orbit in PZ-90.02
   * coordinate system[rad]
   */
  double lambda_na;
  /**
   * Time of the first ascending node passage[s]
   */
  double t_lambda_na;
  /**
   * Value of inclination at instant of t_lambda[rad]
   */
  double i;
  /**
   * Value of Draconian period at instant of t_lambda[s/orbital period]
   */
  double t;
  /**
   * Rate of change of the Draconian period[s/(orbital period^2)]
   */
  double t_dot;
  /**
   * Eccentricity at instant of t_lambda
   */
  double epsilon;
  /**
   * Argument of perigee at instant of t_lambda[rad]
   */
  double omega;
} sbp_msg_almanac_glo_dep_t;

static inline size_t sbp_packed_size_sbp_msg_almanac_glo_dep_t(
    const sbp_msg_almanac_glo_dep_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code) +
           sizeof(msg->common.sid.reserved)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->lambda_na) + sizeof(msg->t_lambda_na) + sizeof(msg->i) +
         sizeof(msg->t) + sizeof(msg->t_dot) + sizeof(msg->epsilon) +
         sizeof(msg->omega);
}

static inline bool sbp_pack_sbp_msg_almanac_glo_dep_t(
    u8 *buf, size_t len, const sbp_msg_almanac_glo_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_glo_dep_t(msg) > len) {
    return false;
  }

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommonsidsat = msg->common.sid.sat;
  msgcommonsidsat = htole16(msgcommonsidsat);
  memcpy(buf + offset, &msgcommonsidsat, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidreserved = msg->common.sid.reserved;
  memcpy(buf + offset, &msgcommonsidreserved, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoatow = msg->common.toa.tow;
  msgcommontoatow = htole32(msgcommontoatow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoawn = msg->common.toa.wn;
  msgcommontoawn = htole16(msgcommontoawn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msglambda_na = msg->lambda_na;
  memcpy(buf + offset, &msglambda_na, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgt_lambda_na = msg->t_lambda_na;
  memcpy(buf + offset, &msgt_lambda_na, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgi = msg->i;
  memcpy(buf + offset, &msgi, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgt = msg->t;
  memcpy(buf + offset, &msgt, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgt_dot = msg->t_dot;
  memcpy(buf + offset, &msgt_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgepsilon = msg->epsilon;
  memcpy(buf + offset, &msgepsilon, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega = msg->omega;
  memcpy(buf + offset, &msgomega, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_dep_t(
    const u8 *buf, size_t len, sbp_msg_almanac_glo_dep_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 2);
  msg->common.sid.sat = le16toh(msg->common.sid.sat);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.reserved, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->lambda_na, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->t_lambda_na, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->i, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->t, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->t_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->epsilon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega, buf + offset, 8);
  offset += 8;
  return true;
}
/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
 */
#define SBP_MSG_ALMANAC_GLO 0x0073

#define SBP_ALMANAC_GLO_COMMON_SID_CODE__MASK (0xff)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__SHIFT (0u)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ALMANAC_GLO_COMMON_SID_CODE__SHIFT) & \
   SBP_ALMANAC_GLO_COMMON_SID_CODE__MASK)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__SET(flags, val)           \
  do {                                                             \
    ((flags) |= (((val) & (SBP_ALMANAC_GLO_COMMON_SID_CODE__MASK)) \
                 << (SBP_ALMANAC_GLO_COMMON_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L1CA (0)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L2CM (1)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__SBAS_L1CA (2)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GLO_L1CA (3)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GLO_L2CA (4)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L1P (5)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GPS_L2P (6)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__BDS2_B1 (12)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__BDS2_B2 (13)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GAL_E1B (14)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__GAL_E7I (20)
#define SBP_ALMANAC_GLO_COMMON_SID_CODE__BDS3_B2A (47)

typedef struct {
  /**
   * Values common for all almanac types
   */
  struct {
    /**
     * GNSS signal identifier
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
     * Reference time of almanac
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
    } toa;
    /**
     * User Range Accuracy[m]
     */
    double ura;
    /**
     * Curve fit interval[s]
     */
    u32 fit_interval;
    /**
     * Status of almanac, 1 = valid, 0 = invalid
     */
    u8 valid;
    /**
     * Satellite health status for GPS:
     *   - bits 5-7: NAV data health status. See IS-GPS-200H
     *     Table 20-VII: NAV Data Health Indications.
     *   - bits 0-4: Signal health status. See IS-GPS-200H
     *     Table 20-VIII. Codes for Health of SV Signal
     *     Components.
     * Satellite health status for GLO:
     *   See GLO ICD 5.1 table 5.1 for details
     *   - bit 0: C(n), "unhealthy" flag that is transmitted within
     *     non-immediate data and indicates overall constellation status
     *     at the moment of almanac uploading.
     *     '0' indicates malfunction of n-satellite.
     *     '1' indicates that n-satellite is operational.
     *   - bit 1: Bn(ln), '0' indicates the satellite is operational
     *     and suitable for navigation.
     */
    u8 health_bits;
  } common;
  /**
   * Longitude of the first ascending node of the orbit in PZ-90.02
   * coordinate system[rad]
   */
  double lambda_na;
  /**
   * Time of the first ascending node passage[s]
   */
  double t_lambda_na;
  /**
   * Value of inclination at instant of t_lambda[rad]
   */
  double i;
  /**
   * Value of Draconian period at instant of t_lambda[s/orbital period]
   */
  double t;
  /**
   * Rate of change of the Draconian period[s/(orbital period^2)]
   */
  double t_dot;
  /**
   * Eccentricity at instant of t_lambda
   */
  double epsilon;
  /**
   * Argument of perigee at instant of t_lambda[rad]
   */
  double omega;
} sbp_msg_almanac_glo_t;

static inline size_t sbp_packed_size_sbp_msg_almanac_glo_t(
    const sbp_msg_almanac_glo_t *msg) {
  (void)msg;
  return 0 +
         (0 + (0 + sizeof(msg->common.sid.sat) + sizeof(msg->common.sid.code)) +
          (0 + sizeof(msg->common.toa.tow) + sizeof(msg->common.toa.wn)) +
          sizeof(msg->common.ura) + sizeof(msg->common.fit_interval) +
          sizeof(msg->common.valid) + sizeof(msg->common.health_bits)) +
         sizeof(msg->lambda_na) + sizeof(msg->t_lambda_na) + sizeof(msg->i) +
         sizeof(msg->t) + sizeof(msg->t_dot) + sizeof(msg->epsilon) +
         sizeof(msg->omega);
}

static inline bool sbp_pack_sbp_msg_almanac_glo_t(
    u8 *buf, size_t len, const sbp_msg_almanac_glo_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_almanac_glo_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidsat = msg->common.sid.sat;
  memcpy(buf + offset, &msgcommonsidsat, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonsidcode = msg->common.sid.code;
  memcpy(buf + offset, &msgcommonsidcode, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommontoatow = msg->common.toa.tow;
  msgcommontoatow = htole32(msgcommontoatow);
  memcpy(buf + offset, &msgcommontoatow, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgcommontoawn = msg->common.toa.wn;
  msgcommontoawn = htole16(msgcommontoawn);
  memcpy(buf + offset, &msgcommontoawn, 2);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  double msgcommonura = msg->common.ura;
  memcpy(buf + offset, &msgcommonura, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  u32 msgcommonfit_interval = msg->common.fit_interval;
  msgcommonfit_interval = htole32(msgcommonfit_interval);
  memcpy(buf + offset, &msgcommonfit_interval, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonvalid = msg->common.valid;
  memcpy(buf + offset, &msgcommonvalid, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgcommonhealth_bits = msg->common.health_bits;
  memcpy(buf + offset, &msgcommonhealth_bits, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  double msglambda_na = msg->lambda_na;
  memcpy(buf + offset, &msglambda_na, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgt_lambda_na = msg->t_lambda_na;
  memcpy(buf + offset, &msgt_lambda_na, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgi = msg->i;
  memcpy(buf + offset, &msgi, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgt = msg->t;
  memcpy(buf + offset, &msgt, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgt_dot = msg->t_dot;
  memcpy(buf + offset, &msgt_dot, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgepsilon = msg->epsilon;
  memcpy(buf + offset, &msgepsilon, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  double msgomega = msg->omega;
  memcpy(buf + offset, &msgomega, 8);
  offset += 8;
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_glo_t(
    const u8 *buf, size_t len, sbp_msg_almanac_glo_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.sat, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.sid.code, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.toa.tow, buf + offset, 4);
  msg->common.toa.tow = le32toh(msg->common.toa.tow);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->common.toa.wn, buf + offset, 2);
  msg->common.toa.wn = le16toh(msg->common.toa.wn);
  offset += 2;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->common.ura, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->common.fit_interval, buf + offset, 4);
  msg->common.fit_interval = le32toh(msg->common.fit_interval);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.valid, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->common.health_bits, buf + offset, 1);
  offset += 1;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->lambda_na, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->t_lambda_na, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->i, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->t, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->t_dot, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->epsilon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len) {
    return false;
  }
  memcpy(&msg->omega, buf + offset, 8);
  offset += 8;
  return true;
}
/** GLONASS L1/L2 Code-Phase biases
 *
 * The GLONASS L1/L2 Code-Phase biases allows to perform
 * GPS+GLONASS integer ambiguity resolution for baselines
 * with mixed receiver types (e.g. receiver of different
 * manufacturers)
 */
#define SBP_MSG_GLO_BIASES 0x0075

typedef struct {
  /**
   * GLONASS FDMA signals mask[boolean]
   */
  u8 mask;
  /**
   * GLONASS L1 C/A Code-Phase Bias[m * 0.02]
   */
  s16 l1ca_bias;
  /**
   * GLONASS L1 P Code-Phase Bias[m * 0.02]
   */
  s16 l1p_bias;
  /**
   * GLONASS L2 C/A Code-Phase Bias[m * 0.02]
   */
  s16 l2ca_bias;
  /**
   * GLONASS L2 P Code-Phase Bias[m * 0.02]
   */
  s16 l2p_bias;
} sbp_msg_glo_biases_t;

static inline size_t sbp_packed_size_sbp_msg_glo_biases_t(
    const sbp_msg_glo_biases_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->mask) + sizeof(msg->l1ca_bias) +
         sizeof(msg->l1p_bias) + sizeof(msg->l2ca_bias) + sizeof(msg->l2p_bias);
}

static inline bool sbp_pack_sbp_msg_glo_biases_t(
    u8 *buf, size_t len, const sbp_msg_glo_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_glo_biases_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgmask = msg->mask;
  memcpy(buf + offset, &msgmask, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgl1ca_bias = msg->l1ca_bias;
  msgl1ca_bias = htole16(msgl1ca_bias);
  memcpy(buf + offset, &msgl1ca_bias, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgl1p_bias = msg->l1p_bias;
  msgl1p_bias = htole16(msgl1p_bias);
  memcpy(buf + offset, &msgl1p_bias, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgl2ca_bias = msg->l2ca_bias;
  msgl2ca_bias = htole16(msgl2ca_bias);
  memcpy(buf + offset, &msgl2ca_bias, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgl2p_bias = msg->l2p_bias;
  msgl2p_bias = htole16(msgl2p_bias);
  memcpy(buf + offset, &msgl2p_bias, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_glo_biases_t(const u8 *buf, size_t len,
                                                   sbp_msg_glo_biases_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->mask, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->l1ca_bias, buf + offset, 2);
  msg->l1ca_bias = le16toh(msg->l1ca_bias);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->l1p_bias, buf + offset, 2);
  msg->l1p_bias = le16toh(msg->l1p_bias);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->l2ca_bias, buf + offset, 2);
  msg->l2ca_bias = le16toh(msg->l2ca_bias);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->l2p_bias, buf + offset, 2);
  msg->l2p_bias = le16toh(msg->l2p_bias);
  offset += 2;
  return true;
}
/** Satellite azimuths and elevations
 *
 * Azimuth and elevation angles of all the visible satellites
 * that the device does have ephemeris or almanac for.
 */
#define SBP_MSG_SV_AZ_EL 0x0097

#define SBP_SV_AZ_EL_AZEL_SID_CODE__MASK (0xff)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__SHIFT (0u)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GET(flags)      \
  (((flags) >> SBP_SV_AZ_EL_AZEL_SID_CODE__SHIFT) & \
   SBP_SV_AZ_EL_AZEL_SID_CODE__MASK)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_SV_AZ_EL_AZEL_SID_CODE__MASK)) \
                 << (SBP_SV_AZ_EL_AZEL_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L1CA (0)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L2CM (1)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__SBAS_L1CA (2)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GLO_L1CA (3)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GLO_L2CA (4)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L1P (5)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GPS_L2P (6)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__BDS2_B1 (12)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__BDS2_B2 (13)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GAL_E1B (14)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__GAL_E7I (20)
#define SBP_SV_AZ_EL_AZEL_SID_CODE__BDS3_B2A (47)
typedef struct {
  /**
   * Azimuth and elevation per satellite
   */
  struct {
    /**
     * GNSS signal identifier
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
     * Azimuth angle (range 0..179)[deg * 2]
     */
    u8 az;
    /**
     * Elevation angle (range -90..90)[deg]
     */
    s8 el;
  } azel[63];
  /**
   * Number of items in azel
   */
  u8 n_azel;
} sbp_msg_sv_az_el_t;

static inline size_t sbp_packed_size_sbp_msg_sv_az_el_t(
    const sbp_msg_sv_az_el_t *msg) {
  (void)msg;
  return 0 +
         (msg->n_azel *
          (0 +
           (0 + sizeof(msg->azel[0].sid.sat) + sizeof(msg->azel[0].sid.code)) +
           sizeof(msg->azel[0].az) + sizeof(msg->azel[0].el)));
}

static inline bool sbp_pack_sbp_msg_sv_az_el_t(u8 *buf, size_t len,
                                               const sbp_msg_sv_az_el_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_sv_az_el_t(msg) > len) {
    return false;
  }

  for (size_t msgazel_idx = 0; msgazel_idx < (size_t)msg->n_azel;
       msgazel_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    u8 msgazelmsgazel_idxsidsat = msg->azel[msgazel_idx].sid.sat;
    memcpy(buf + offset, &msgazelmsgazel_idxsidsat, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgazelmsgazel_idxsidcode = msg->azel[msgazel_idx].sid.code;
    memcpy(buf + offset, &msgazelmsgazel_idxsidcode, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgazelmsgazel_idxaz = msg->azel[msgazel_idx].az;
    memcpy(buf + offset, &msgazelmsgazel_idxaz, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    s8 msgazelmsgazel_idxel = msg->azel[msgazel_idx].el;
    memcpy(buf + offset, &msgazelmsgazel_idxel, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_sv_az_el_t(const u8 *buf, size_t len,
                                                 sbp_msg_sv_az_el_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  msg->n_azel = (u8)((len - offset) / 4);

  for (size_t msgazel_idx = 0; msgazel_idx < msg->n_azel; msgazel_idx++) {
    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].sid.sat, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].sid.code, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].az, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->azel[msgazel_idx].el, buf + offset, 1);
    offset += 1;
  }
  return true;
}
/** OSR corrections
 *
 * The OSR message contains network corrections in an observation-like format
 */
#define SBP_MSG_OSR 0x0640

#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT (4u)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_GET(flags)      \
  (((flags) >> SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT) & \
   SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_MASK)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SET(flags, val)           \
  do {                                                                        \
    ((flags) |= (((val) & (SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_MASK)) \
                 << (SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_SHIFT)));    \
  } while (0)

#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_VALID_PHASE_CORRECTIONS (0)
#define SBP_OSR_OBS_FLAGS_INVALID_PHASE_CORRECTIONS_DO_NOT_USE_PHASE_CORRECTIONS \
  (1)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT (3u)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_GET(flags)      \
  (((flags) >> SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT) & \
   SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_MASK)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SET(flags, val)           \
  do {                                                                       \
    ((flags) |= (((val) & (SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_MASK)) \
                 << (SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_SHIFT)));    \
  } while (0)

#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_VALID_CODE_CORRECTIONS (0)
#define SBP_OSR_OBS_FLAGS_INVALID_CODE_CORRECTIONS_DO_NOT_USE_CODE_CORRECTIONS \
  (1)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SHIFT (2u)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_GET(flags)      \
  (((flags) >> SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SHIFT) & \
   SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_MASK)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_MASK)) \
                 << (SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_SHIFT)));    \
  } while (0)

#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_FULL_FIXING_UNAVAILABLE (0)
#define SBP_OSR_OBS_FLAGS_FULL_FIXING_FLAG_FULL_FIXING_AVAILABLE (1)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SHIFT (1u)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_GET(flags)      \
  (((flags) >> SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SHIFT) & \
   SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_MASK)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_MASK)) \
                 << (SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_SHIFT)));    \
  } while (0)

#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_UNAVAILABLE (0)
#define SBP_OSR_OBS_FLAGS_PARTIAL_FIXING_FLAG_PARTIAL_FIXING_AVAILABLE (1)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_MASK (0x1)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SHIFT (0u)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_GET(flags)      \
  (((flags) >> SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SHIFT) & \
   SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_MASK)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SET(flags, val)           \
  do {                                                                  \
    ((flags) |= (((val) & (SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_MASK)) \
                 << (SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_SHIFT)));    \
  } while (0)

#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_DO_NOT_USE_SIGNAL (0)
#define SBP_OSR_OBS_FLAGS_CORRECTION_VALIDITY_VALID_SIGNAL (1)

#define SBP_OSR_OBS_SID_CODE__MASK (0xff)
#define SBP_OSR_OBS_SID_CODE__SHIFT (0u)
#define SBP_OSR_OBS_SID_CODE__GET(flags) \
  (((flags) >> SBP_OSR_OBS_SID_CODE__SHIFT) & SBP_OSR_OBS_SID_CODE__MASK)
#define SBP_OSR_OBS_SID_CODE__SET(flags, val)           \
  do {                                                  \
    ((flags) |= (((val) & (SBP_OSR_OBS_SID_CODE__MASK)) \
                 << (SBP_OSR_OBS_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_OSR_OBS_SID_CODE__GPS_L1CA (0)
#define SBP_OSR_OBS_SID_CODE__GPS_L2CM (1)
#define SBP_OSR_OBS_SID_CODE__SBAS_L1CA (2)
#define SBP_OSR_OBS_SID_CODE__GLO_L1CA (3)
#define SBP_OSR_OBS_SID_CODE__GLO_L2CA (4)
#define SBP_OSR_OBS_SID_CODE__GPS_L1P (5)
#define SBP_OSR_OBS_SID_CODE__GPS_L2P (6)
#define SBP_OSR_OBS_SID_CODE__BDS2_B1 (12)
#define SBP_OSR_OBS_SID_CODE__BDS2_B2 (13)
#define SBP_OSR_OBS_SID_CODE__GAL_E1B (14)
#define SBP_OSR_OBS_SID_CODE__GAL_E7I (20)
#define SBP_OSR_OBS_SID_CODE__BDS3_B2A (47)
typedef struct {
  /**
   * Header of a GPS observation message
   */
  struct {
    /**
     * GNSS time of this observation
     */
    struct {
      /**
       * Milliseconds since start of GPS week[ms]
       */
      u32 tow;
      /**
       * Nanosecond residual of millisecond-rounded TOW (ranges
       * from -500000 to 500000)[ns]
       */
      s32 ns_residual;
      /**
       * GPS week number[week]
       */
      u16 wn;
    } t;
    /**
     * Total number of observations. First nibble is the size
     * of the sequence (n), second nibble is the zero-indexed
     * counter (ith packet of n)
     */
    u8 n_obs;
  } header;
  /**
   * Network correction for a
   * satellite signal.
   */
  struct {
    /**
     * Pseudorange observation[2 cm]
     */
    u32 P;
    /**
     * Carrier phase observation with typical sign convention.[cycles]
     */
    struct {
      /**
       * Carrier phase whole cycles[cycles]
       */
      s32 i;
      /**
       * Carrier phase fractional part[cycles / 256]
       */
      u8 f;
    } L;
    /**
     * Lock timer. This value gives an indication of the time
     * for which a signal has maintained continuous phase lock.
     * Whenever a signal has lost and regained lock, this
     * value is reset to zero. It is encoded according to DF402 from
     * the RTCM 10403.2 Amendment 2 specification.  Valid values range
     * from 0 to 15 and the most significant nibble is reserved for future use.
     */
    u8 lock;
    /**
     * Correction flags.
     */
    u8 flags;
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
     * Slant ionospheric correction standard deviation[5 mm]
     */
    u16 iono_std;
    /**
     * Slant tropospheric correction standard deviation[5 mm]
     */
    u16 tropo_std;
    /**
     * Orbit/clock/bias correction projected on range standard deviation[5 mm]
     */
    u16 range_std;
  } obs[12];
  /**
   * Number of items in obs
   */
  u8 n_obs;
} sbp_msg_osr_t;

static inline size_t sbp_packed_size_sbp_msg_osr_t(const sbp_msg_osr_t *msg) {
  (void)msg;
  return 0 +
         (0 +
          (0 + sizeof(msg->header.t.tow) + sizeof(msg->header.t.ns_residual) +
           sizeof(msg->header.t.wn)) +
          sizeof(msg->header.n_obs)) +
         (msg->n_obs *
          (0 + sizeof(msg->obs[0].P) +
           (0 + sizeof(msg->obs[0].L.i) + sizeof(msg->obs[0].L.f)) +
           sizeof(msg->obs[0].lock) + sizeof(msg->obs[0].flags) +
           (0 + sizeof(msg->obs[0].sid.sat) + sizeof(msg->obs[0].sid.code)) +
           sizeof(msg->obs[0].iono_std) + sizeof(msg->obs[0].tropo_std) +
           sizeof(msg->obs[0].range_std)));
}

static inline bool sbp_pack_sbp_msg_osr_t(u8 *buf, size_t len,
                                          const sbp_msg_osr_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_osr_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgheaderttow = msg->header.t.tow;
  msgheaderttow = htole32(msgheaderttow);
  memcpy(buf + offset, &msgheaderttow, 4);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  s32 msgheadertns_residual = msg->header.t.ns_residual;
  msgheadertns_residual = htole32(msgheadertns_residual);
  memcpy(buf + offset, &msgheadertns_residual, 4);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  u16 msgheadertwn = msg->header.t.wn;
  msgheadertwn = htole16(msgheadertwn);
  memcpy(buf + offset, &msgheadertwn, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgheadern_obs = msg->header.n_obs;
  memcpy(buf + offset, &msgheadern_obs, 1);
  offset += 1;
  for (size_t msgobs_idx = 0; msgobs_idx < (size_t)msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    u32 msgobsmsgobs_idxP = msg->obs[msgobs_idx].P;
    msgobsmsgobs_idxP = htole32(msgobsmsgobs_idxP);
    memcpy(buf + offset, &msgobsmsgobs_idxP, 4);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    s32 msgobsmsgobs_idxLi = msg->obs[msgobs_idx].L.i;
    msgobsmsgobs_idxLi = htole32(msgobsmsgobs_idxLi);
    memcpy(buf + offset, &msgobsmsgobs_idxLi, 4);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxLf = msg->obs[msgobs_idx].L.f;
    memcpy(buf + offset, &msgobsmsgobs_idxLf, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxlock = msg->obs[msgobs_idx].lock;
    memcpy(buf + offset, &msgobsmsgobs_idxlock, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxflags = msg->obs[msgobs_idx].flags;
    memcpy(buf + offset, &msgobsmsgobs_idxflags, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidsat = msg->obs[msgobs_idx].sid.sat;
    memcpy(buf + offset, &msgobsmsgobs_idxsidsat, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    u8 msgobsmsgobs_idxsidcode = msg->obs[msgobs_idx].sid.code;
    memcpy(buf + offset, &msgobsmsgobs_idxsidcode, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxiono_std = msg->obs[msgobs_idx].iono_std;
    msgobsmsgobs_idxiono_std = htole16(msgobsmsgobs_idxiono_std);
    memcpy(buf + offset, &msgobsmsgobs_idxiono_std, 2);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxtropo_std = msg->obs[msgobs_idx].tropo_std;
    msgobsmsgobs_idxtropo_std = htole16(msgobsmsgobs_idxtropo_std);
    memcpy(buf + offset, &msgobsmsgobs_idxtropo_std, 2);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    u16 msgobsmsgobs_idxrange_std = msg->obs[msgobs_idx].range_std;
    msgobsmsgobs_idxrange_std = htole16(msgobsmsgobs_idxrange_std);
    memcpy(buf + offset, &msgobsmsgobs_idxrange_std, 2);
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_osr_t(const u8 *buf, size_t len,
                                            sbp_msg_osr_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.tow, buf + offset, 4);
  msg->header.t.tow = le32toh(msg->header.t.tow);
  offset += 4;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->header.t.ns_residual, buf + offset, 4);
  msg->header.t.ns_residual = le32toh(msg->header.t.ns_residual);
  offset += 4;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->header.t.wn, buf + offset, 2);
  msg->header.t.wn = le16toh(msg->header.t.wn);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->header.n_obs, buf + offset, 1);
  offset += 1;
  msg->n_obs = (u8)((len - offset) / 19);

  for (size_t msgobs_idx = 0; msgobs_idx < msg->n_obs; msgobs_idx++) {
    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].P, buf + offset, 4);
    msg->obs[msgobs_idx].P = le32toh(msg->obs[msgobs_idx].P);
    offset += 4;

    if (offset + 4 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.i, buf + offset, 4);
    msg->obs[msgobs_idx].L.i = le32toh(msg->obs[msgobs_idx].L.i);
    offset += 4;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].L.f, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].lock, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].flags, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.sat, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].sid.code, buf + offset, 1);
    offset += 1;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].iono_std, buf + offset, 2);
    msg->obs[msgobs_idx].iono_std = le16toh(msg->obs[msgobs_idx].iono_std);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].tropo_std, buf + offset, 2);
    msg->obs[msgobs_idx].tropo_std = le16toh(msg->obs[msgobs_idx].tropo_std);
    offset += 2;

    if (offset + 2 > len) {
      return false;
    }
    memcpy(&msg->obs[msgobs_idx].range_std, buf + offset, 2);
    msg->obs[msgobs_idx].range_std = le16toh(msg->obs[msgobs_idx].range_std);
    offset += 2;
  }
  return true;
}

#endif /* LIBSBP_OBSERVATION_MESSAGES_H */