#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#define LIBSBP_ACQUISITION_MESSAGES_H

#include "common.h"
#include "gnss.h"

SBP_PACK_START
/** Satellite acquisition result
 *
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best carrier-to-noise (CN/0)
 * ratio.
 */
#define SBP_MSG_ACQ_RESULT 0x002F

#define SBP_ACQ_RESULT_SID_CODE__MASK (0xff)
#define SBP_ACQ_RESULT_SID_CODE__SHIFT (0u)
#define SBP_ACQ_RESULT_SID_CODE__GET(flags) \
  (((flags) >> SBP_ACQ_RESULT_SID_CODE__SHIFT) & SBP_ACQ_RESULT_SID_CODE__MASK)
#define SBP_ACQ_RESULT_SID_CODE__SET(flags, val)           \
  do {                                                     \
    ((flags) |= (((val) & (SBP_ACQ_RESULT_SID_CODE__MASK)) \
                 << (SBP_ACQ_RESULT_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ACQ_RESULT_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_RESULT_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_RESULT_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_RESULT_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_RESULT_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_RESULT_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_RESULT_SID_CODE__GPS_L2P (6)
#define SBP_ACQ_RESULT_SID_CODE__BDS2_B1 (12)
#define SBP_ACQ_RESULT_SID_CODE__BDS2_B2 (13)
#define SBP_ACQ_RESULT_SID_CODE__GAL_E1B (14)
#define SBP_ACQ_RESULT_SID_CODE__GAL_E7I (20)
#define SBP_ACQ_RESULT_SID_CODE__BDS3_B2A (47)
typedef struct SBP_ATTR_PACKED {
  /**
   * CN/0 of best point[dB Hz]
   */
  float cn0;
  /**
   * Code phase of best point[chips]
   */
  float cp;
  /**
   * Carrier frequency of best point[hz]
   */
  float cf;
  /**
   * GNSS signal for which acquisition was attempted
   */
  struct SBP_ATTR_PACKED {
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
} sbp_msg_acq_result_t;
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_C 0x001F

#define SBP_ACQ_RESULT_DEP_C_SID_CODE__MASK (0xff)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__SHIFT (0u)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ACQ_RESULT_DEP_C_SID_CODE__SHIFT) & \
   SBP_ACQ_RESULT_DEP_C_SID_CODE__MASK)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_ACQ_RESULT_DEP_C_SID_CODE__MASK)) \
                 << (SBP_ACQ_RESULT_DEP_C_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L2P (6)
typedef struct SBP_ATTR_PACKED {
  /**
   * CN/0 of best point[dB Hz]
   */
  float cn0;
  /**
   * Code phase of best point[chips]
   */
  float cp;
  /**
   * Carrier frequency of best point[hz]
   */
  float cf;
  /**
   * GNSS signal for which acquisition was attempted
   */
  struct SBP_ATTR_PACKED {
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
} sbp_msg_acq_result_dep_c_t;
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_B 0x0014

#define SBP_ACQ_RESULT_DEP_B_SID_CODE__MASK (0xff)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__SHIFT (0u)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ACQ_RESULT_DEP_B_SID_CODE__SHIFT) & \
   SBP_ACQ_RESULT_DEP_B_SID_CODE__MASK)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__SET(flags, val)           \
  do {                                                           \
    ((flags) |= (((val) & (SBP_ACQ_RESULT_DEP_B_SID_CODE__MASK)) \
                 << (SBP_ACQ_RESULT_DEP_B_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L2P (6)
typedef struct SBP_ATTR_PACKED {
  /**
   * SNR of best point. Currently in arbitrary SNR points, but will
   * be in units of dB Hz in a later revision of this message.
   */
  float snr;
  /**
   * Code phase of best point[chips]
   */
  float cp;
  /**
   * Carrier frequency of best point[hz]
   */
  float cf;
  /**
   * GNSS signal for which acquisition was attempted
   */
  struct SBP_ATTR_PACKED {
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
} sbp_msg_acq_result_dep_b_t;
/** Deprecated
 *
 * Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_A 0x0015

typedef struct SBP_ATTR_PACKED {
  /**
   * SNR of best point. Currently dimensonless, but will have
   * units of dB Hz in the revision of this message.
   */
  float snr;
  /**
   * Code phase of best point[chips]
   */
  float cp;
  /**
   * Carrier frequency of best point[hz]
   */
  float cf;
  /**
   * PRN-1 identifier of the satellite signal for which
   * acquisition was attempted
   */
  u8 prn;
} sbp_msg_acq_result_dep_a_t;
/** Acquisition perfomance measurement and debug
 *
 * The message describes all SV profiles during acquisition time.
 * The message is used to debug and measure the performance.
 */
#define SBP_MSG_ACQ_SV_PROFILE 0x002E

#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__MASK (0xff)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SHIFT (0u)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SHIFT) & \
   SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__MASK)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SET(flags, val)           \
  do {                                                                        \
    ((flags) |= (((val) & (SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__MASK)) \
                 << (SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SHIFT)));    \
  } while (0)

#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L2P (6)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__BDS2_B1 (12)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__BDS2_B2 (13)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GAL_E1B (14)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GAL_E7I (20)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__BDS3_B2A (47)
typedef struct SBP_ATTR_PACKED {
  /**
   * SV profiles during acquisition time
   */
  struct SBP_ATTR_PACKED {
    /**
     * SV search job type (deep, fallback, etc)
     */
    u8 job_type;
    /**
     * Acquisition status 1 is Success, 0 is Failure
     */
    u8 status;
    /**
     * CN0 value. Only valid if status is '1'[dB-Hz*10]
     */
    u16 cn0;
    /**
     * Acquisition integration time[ms]
     */
    u8 int_time;
    /**
     * GNSS signal for which acquisition was attempted
     */
    struct SBP_ATTR_PACKED {
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
     * Acq frequency bin width[Hz]
     */
    u16 bin_width;
    /**
     * Timestamp of the job complete event[ms]
     */
    u32 timestamp;
    /**
     * Time spent to search for sid.code[us]
     */
    u32 time_spent;
    /**
     * Doppler range lowest frequency[Hz]
     */
    s32 cf_min;
    /**
     * Doppler range highest frequency[Hz]
     */
    s32 cf_max;
    /**
     * Doppler value of detected peak. Only valid if status is '1'[Hz]
     */
    s32 cf;
    /**
     * Codephase of detected peak. Only valid if status is '1'[chips*10]
     */
    u32 cp;
  } acq_sv_profile[7];
} sbp_msg_acq_sv_profile_t;
/** Deprecated.
 *
 * Deprecated.
 */
#define SBP_MSG_ACQ_SV_PROFILE_DEP 0x001E

#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__MASK (0xff)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SHIFT (0u)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GET(flags)      \
  (((flags) >> SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SHIFT) & \
   SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__MASK)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SET(flags, val) \
  do {                                                                  \
    ((flags) |=                                                         \
     (((val) & (SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__MASK))  \
      << (SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SHIFT)));     \
  } while (0)

#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L2P (6)
typedef struct SBP_ATTR_PACKED {
  /**
   * SV profiles during acquisition time
   */
  struct SBP_ATTR_PACKED {
    /**
     * SV search job type (deep, fallback, etc)
     */
    u8 job_type;
    /**
     * Acquisition status 1 is Success, 0 is Failure
     */
    u8 status;
    /**
     * CN0 value. Only valid if status is '1'[dB-Hz*10]
     */
    u16 cn0;
    /**
     * Acquisition integration time[ms]
     */
    u8 int_time;
    /**
     * GNSS signal for which acquisition was attempted
     */
    struct SBP_ATTR_PACKED {
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
     * Acq frequency bin width[Hz]
     */
    u16 bin_width;
    /**
     * Timestamp of the job complete event[ms]
     */
    u32 timestamp;
    /**
     * Time spent to search for sid.code[us]
     */
    u32 time_spent;
    /**
     * Doppler range lowest frequency[Hz]
     */
    s32 cf_min;
    /**
     * Doppler range highest frequency[Hz]
     */
    s32 cf_max;
    /**
     * Doppler value of detected peak. Only valid if status is '1'[Hz]
     */
    s32 cf;
    /**
     * Codephase of detected peak. Only valid if status is '1'[chips*10]
     */
    u32 cp;
  } acq_sv_profile[7];
} sbp_msg_acq_sv_profile_dep_t;

SBP_PACK_END

#endif /* LIBSBP_ACQUISITION_MESSAGES_H */