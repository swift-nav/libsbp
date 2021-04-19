#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#define LIBSBP_SOLUTION_META_MESSAGES_H

#include "common.h"

SBP_PACK_START
/** Deprecated
 *
 * This message contains all metadata about the sensors received and/or used in
 * computing the Fuzed Solution. It focuses primarly, but not only, on GNSS
 * metadata.
 */
#define SBP_MSG_SOLN_META_DEP_A 0xFF0F

#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_MASK (0x7)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_GET(flags)      \
  (((flags) >> SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SHIFT) & \
   SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_MASK)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SET(flags, val) \
  do {                                                                        \
    ((flags) |=                                                               \
     (((val) & (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_MASK))  \
      << (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SHIFT)));     \
  } while (0)

#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_UNKNOWN_REASON_OR_ALREADY_ALIGNED \
  (0)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SEED_VALUES_LOADED_AND_ALIGNMENT_IN_PROGRESS \
  (1)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_NO_SEED_VALUES_AND_ALIGNMENT_IN_PROGRESS \
  (2)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SEED_VALUES_LOADED_BUT_NO_GNSS_MEASUREMENTS \
  (3)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_NO_SEED_VALUES_NOR_GNSS_MEASUREMENTS \
  (4)

#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_GET(flags)      \
  (((flags) >> SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT) & \
   SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SET(flags, val) \
  do {                                                                      \
    ((flags) |=                                                             \
     (((val) & (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK))  \
      << (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT)));     \
  } while (0)

#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_AND_USED \
  (1)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED \
  (2)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GET(flags)      \
  (((flags) >> SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT) & \
   SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SET(flags, val) \
  do {                                                                     \
    ((flags) |=                                                            \
     (((val) & (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK))  \
      << (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT)));     \
  } while (0)

#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT \
  (2)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER \
  (3)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_IMU_SENSOR (6)
typedef struct SBP_ATTR_PACKED {
  /**
   * Position Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid)[0.01]
   */
  u16 pdop;
  /**
   * Horizontal Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid)[0.01]
   */
  u16 hdop;
  /**
   * Vertical Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid)[0.01]
   */
  u16 vdop;
  /**
   * Number of satellites as per last available solution from PVT engine
   */
  u8 n_sats;
  /**
   * Age of corrections as per last available AGE_CORRECTIONS from PVT engine
   * (0xFFFF indicates invalid)[deciseconds]
   */
  u16 age_corrections;
  /**
   * State of alignment and the status and receipt of the alignment inputs
   */
  u8 alignment_status;
  /**
   * Tow of last-used GNSS position measurement[ms]
   */
  u32 last_used_gnss_pos_tow;
  /**
   * Tow of last-used GNSS velocity measurement[ms]
   */
  u32 last_used_gnss_vel_tow;
  /**
   * Array of Metadata describing the sensors potentially involved in the
   * solution. Each element in the array represents a single sensor type and
   * consists of flags containing (meta)data pertaining to that specific single
   * sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  struct SBP_ATTR_PACKED {
    /**
     * The type of sensor
     */
    u8 sensor_type;
    /**
     * Refer to each InputType description[(XX)InputType]
     */
    u8 flags;
  } sol_in[118];
} sbp_msg_soln_meta_dep_a_t;
/** Solution Sensors Metadata
 *
 * This message contains all metadata about the sensors received and/or used in
 * computing the sensorfusion solution. It focuses primarly, but not only, on
 * GNSS metadata. Regarding the age of the last received valid GNSS solution,
 * the highest two bits are time status, indicating whether age gnss can or can
 * not be used to retrieve time of measurement (noted TOM, also known as time of
 * validity) If it can, substract 'age gnss' from 'tow' in navigation messages
 * to get TOM. Can be used before alignment is complete in the Fusion Engine,
 * when output solution is the last received valid GNSS solution and its tow is
 * not a TOM.
 */
#define SBP_MSG_SOLN_META 0xFF0E

#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_MASK (0x3)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SHIFT (30u)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_GET(flags)      \
  (((flags) >> SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SHIFT) & \
   SBP_SOLN_META_AGE_GNSS_TIME_STATUS_MASK)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SET(flags, val)           \
  do {                                                               \
    ((flags) |= (((val) & (SBP_SOLN_META_AGE_GNSS_TIME_STATUS_MASK)) \
                 << (SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_AGE_CAN_NOT_BE_USED_TO_RETRIEVE_TOM \
  (0)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_AGE_CAN_BE_USED_TO_RETRIEVE_TOM (1)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK \
  (0x3fffffff)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT \
  (0u)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_GET( \
    flags)                                                                       \
  (((flags) >>                                                                   \
    SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT) & \
   SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SET(        \
    flags, val)                                                                         \
  do {                                                                                  \
    ((flags) |=                                                                         \
     (((val) &                                                                          \
       (SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK))      \
      << (SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT))); \
  } while (0)

#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_GET(flags)      \
  (((flags) >> SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT) & \
   SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SET(flags, val) \
  do {                                                                \
    ((flags) |=                                                       \
     (((val) & (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK))  \
      << (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT)));     \
  } while (0)

#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GET(flags)      \
  (((flags) >> SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT) & \
   SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SET(flags, val)           \
  do {                                                                         \
    ((flags) |= (((val) & (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)) \
                 << (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT)));    \
  } while (0)

#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT \
  (2)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_IMU_SENSOR (6)
typedef struct SBP_ATTR_PACKED {
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Position Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid)[0.01]
   */
  u16 pdop;
  /**
   * Horizontal Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid)[0.01]
   */
  u16 hdop;
  /**
   * Vertical Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid)[0.01]
   */
  u16 vdop;
  /**
   * Age of corrections as per last available AGE_CORRECTIONS from PVT engine
   * (0xFFFF indicates invalid)[deciseconds]
   */
  u16 age_corrections;
  /**
   * Age and Time Status of the last received valid GNSS solution.[ms]
   */
  u32 age_gnss;
  /**
   * Array of Metadata describing the sensors potentially involved in the
   * solution. Each element in the array represents a single sensor type and
   * consists of flags containing (meta)data pertaining to that specific single
   * sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  struct SBP_ATTR_PACKED {
    /**
     * The type of sensor
     */
    u8 sensor_type;
    /**
     * Refer to each InputType description[(XX)InputType]
     */
    u8 flags;
  } sol_in[119];
} sbp_msg_soln_meta_t;

SBP_PACK_END

#endif /* LIBSBP_SOLUTION_META_MESSAGES_H */