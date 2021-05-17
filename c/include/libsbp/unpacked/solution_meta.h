#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#define LIBSBP_SOLUTION_META_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_GET(flags) \
                             (((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT) \
                             & SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_MASK)) \
                             << (SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_SHIFT)));} while(0)
                             

#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GET(flags) \
                             (((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT) \
                             & SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_MASK)) \
                             << (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SHIFT)));} while(0)
                             

#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_IMU_SENSOR (6)
/** Flags for a given solution input type.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 sensor_type;
  u8 flags;
} sbp_solution_input_type_t;


#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK (0x7)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_GET(flags) \
                             (((flags) >> SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT) \
                             & SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_MASK)) \
                             << (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_UNKNOWN_REASON_OR_ALREADY_ALIGNED (0)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SEED_VALUES_LOADED_AND_ALIGNMENT_IN_PROGRESS (1)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_NO_SEED_VALUES_AND_ALIGNMENT_IN_PROGRESS (2)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_SEED_VALUES_LOADED_BUT_NO_GNSS_MEASUREMENTS (3)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_NO_SEED_VALUES_NOR_GNSS_MEASUREMENTS (4)
/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SOLN_META_DEP_A 0xFF0F
typedef struct {
  u16 pdop;
  u16 hdop;
  u16 vdop;
  u8 n_sats;
  u16 age_corrections;
  u8 alignment_status;
  u32 last_used_gnss_pos_tow;
  u32 last_used_gnss_vel_tow;
  sbp_solution_input_type_t sol_in[118];
  u8 n_sol_in;
} sbp_msg_soln_meta_dep_a_t;


#define SBP_SOLN_META_TIME_STATUS_MASK (0x3)
#define SBP_SOLN_META_TIME_STATUS_SHIFT (30u)
#define SBP_SOLN_META_TIME_STATUS_GET(flags) \
                             (((flags) >> SBP_SOLN_META_TIME_STATUS_SHIFT) \
                             & SBP_SOLN_META_TIME_STATUS_MASK)
#define SBP_SOLN_META_TIME_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_TIME_STATUS_MASK)) \
                             << (SBP_SOLN_META_TIME_STATUS_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_TIME_STATUS_AGE_CAN_NOT_BE_USED_TO_RETRIEVE_TOM (0)
#define SBP_SOLN_META_TIME_STATUS_AGE_CAN_BE_USED_TO_RETRIEVE_TOM (1)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK (0x3fffffff)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT (0u)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_GET(flags) \
                             (((flags) >> SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT) \
                             & SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK)
#define SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK)) \
                             << (SBP_SOLN_META_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT)));} while(0)
                             

/** Solution Sensors Metadata
 *
((m.desc|commentify)))
 */
#define SBP_MSG_SOLN_META       0xFF0E
typedef struct {
  u32 tow;
  u16 pdop;
  u16 hdop;
  u16 vdop;
  u16 age_corrections;
  u32 age_gnss;
  sbp_solution_input_type_t sol_in[119];
  u8 n_sol_in;
} sbp_msg_soln_meta_t;


#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK (0x3)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT (0u)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GET(flags) \
                             (((flags) >> SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT) \
                             & SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_MASK)) \
                             << (SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_SHIFT)));} while(0)
                             

#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_POSITION (0)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DOPPLER (1)
#define SBP_GNSSINPUTTYPE_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DISPLACEMENT (2)
/** Instruments the physical type of GNSS sensor input to the fuzed solution.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 flags;
} sbp_gnss_input_type_t;


#define SBP_IMUINPUTTYPE_TIME_STATUS_MASK (0x3)
#define SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT (4u)
#define SBP_IMUINPUTTYPE_TIME_STATUS_GET(flags) \
                             (((flags) >> SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT) \
                             & SBP_IMUINPUTTYPE_TIME_STATUS_MASK)
#define SBP_IMUINPUTTYPE_TIME_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMUINPUTTYPE_TIME_STATUS_MASK)) \
                             << (SBP_IMUINPUTTYPE_TIME_STATUS_SHIFT)));} while(0)
                             

#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK (0)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP (1)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMUINPUTTYPE_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMUINPUTTYPE_IMU_GRADE_MASK (0x3)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT (2u)
#define SBP_IMUINPUTTYPE_IMU_GRADE_GET(flags) \
                             (((flags) >> SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT) \
                             & SBP_IMUINPUTTYPE_IMU_GRADE_MASK)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMUINPUTTYPE_IMU_GRADE_MASK)) \
                             << (SBP_IMUINPUTTYPE_IMU_GRADE_SHIFT)));} while(0)
                             

#define SBP_IMUINPUTTYPE_IMU_GRADE_CONSUMER_GRADE (0)
#define SBP_IMUINPUTTYPE_IMU_GRADE_TACTICAL_GRADE (1)
#define SBP_IMUINPUTTYPE_IMU_GRADE_INTERMEDIATE_GRADE (2)
#define SBP_IMUINPUTTYPE_IMU_GRADE_SUPERIOR_GRADE (3)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK (0x3)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT (0u)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_GET(flags) \
                             (((flags) >> SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT) \
                             & SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_MASK)) \
                             << (SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_SHIFT)));} while(0)
                             

#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_6_AXIS_MEMS (0)
#define SBP_IMUINPUTTYPE_IMU_ARCHITECTURE_OTHER_TYPE (1)
/** Provides detail about the IMU sensor, its timestamping mode, and its quality for input to the fuzed solution.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 flags;
} sbp_imu_input_type_t;


#define SBP_ODOINPUTTYPE_RATE_MASK (0x3)
#define SBP_ODOINPUTTYPE_RATE_SHIFT (4u)
#define SBP_ODOINPUTTYPE_RATE_GET(flags) \
                             (((flags) >> SBP_ODOINPUTTYPE_RATE_SHIFT) \
                             & SBP_ODOINPUTTYPE_RATE_MASK)
#define SBP_ODOINPUTTYPE_RATE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOINPUTTYPE_RATE_MASK)) \
                             << (SBP_ODOINPUTTYPE_RATE_SHIFT)));} while(0)
                             

#define SBP_ODOINPUTTYPE_RATE_FIXED_INCOMING_RATE (0)
#define SBP_ODOINPUTTYPE_RATE_TRIGGERED_BY_MINIMUM_DISTANCE_OR_SPEED (1)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK (0x3)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT (2u)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_GET(flags) \
                             (((flags) >> SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT) \
                             & SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOINPUTTYPE_ODOMETER_GRADE_MASK)) \
                             << (SBP_ODOINPUTTYPE_ODOMETER_GRADE_SHIFT)));} while(0)
                             

#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_LOW_GRADE (0)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_MEDIUM_GRADE (1)
#define SBP_ODOINPUTTYPE_ODOMETER_GRADE_SUPERIOR_GRADE (2)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK (0x3)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT (0u)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_GET(flags) \
                             (((flags) >> SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT) \
                             & SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOINPUTTYPE_ODOMETER_CLASS_MASK)) \
                             << (SBP_ODOINPUTTYPE_ODOMETER_CLASS_SHIFT)));} while(0)
                             

#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SINGLE_OR_AVERAGED_TICKS (0)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_SINGLE_OR_AVERAGED_SPEED (1)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MULTI_DIMENSIONAL_TICKS (2)
#define SBP_ODOINPUTTYPE_ODOMETER_CLASS_MULTI_DIMENSIONAL_SPEED (3)
/** Provides detail about the Odometry sensor, its timestamping mode, and its quality for input to the fuzed solution.
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 flags;
} sbp_odo_input_type_t;



#include <libsbp/unpacked/solution_meta_operators.h>
#include <libsbp/unpacked/solution_meta_packers.h>

#endif /* LIBSBP_SOLUTION_META_MESSAGES_H */
