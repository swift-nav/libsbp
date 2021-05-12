#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#define LIBSBP_SOLUTION_META_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string2.h>
  /** Flags for a given solution input type.
   *
 * Metadata describing which sensors were involved in the solution.
 * The structure is fixed no matter what the actual sensor type is.
 * The sensor_type field tells you which sensor we are talking about. It also tells you
 * whether the sensor data was actually used or not.
 * The flags field, always a u8, contains the sensor-specific data.
 * The content of flags, for each sensor type, is described in the relevant structures in this section.
   */

	#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_GET(flags) \
                             (((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_SHIFT) \
                             & SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_MASK)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_MASK)) \
                             << (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_SHIFT)));} while(0)
                             

#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_GET(flags) \
                             (((flags) >> SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_SHIFT) \
                             & SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_MASK)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_MASK)) \
                             << (SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_SHIFT)));} while(0)
                             

#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT (2)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLUTIONINPUTTYPE_SENSOR_TYPE_SENSOR_TYPE_IMU_SENSOR (6)
typedef struct {
  
  /**
* The type of sensor
   */
    u8
  sensor_type
  ;
  /**
* Refer to each InputType description[(XX)InputType]
   */
    u8
  flags
  ;
} sbp_solution_input_type_t;


  /** Deprecated
   *
 * This message contains all metadata about the sensors received and/or used in computing the Fuzed Solution.
 * It focuses primarly, but not only, on GNSS metadata.
   */
#define SBP_MSG_SOLN_META_DEP_A 0xFF0F

	#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_MASK (0x7)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_GET(flags) \
                             (((flags) >> SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SHIFT) \
                             & SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_MASK)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_MASK)) \
                             << (SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_UNKNOWN_REASON_OR_ALREADY_ALIGNED (0)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SEED_VALUES_LOADED_AND_ALIGNMENT_IN_PROGRESS (1)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_NO_SEED_VALUES_AND_ALIGNMENT_IN_PROGRESS (2)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_SEED_VALUES_LOADED_BUT_NO_GNSS_MEASUREMENTS (3)
#define SBP_SOLN_META_DEP_A_ALIGNMENT_STATUS_ALIGNMENT_STATUS_NO_SEED_VALUES_NOR_GNSS_MEASUREMENTS (4)
	
	#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_GET(flags) \
                             (((flags) >> SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT) \
                             & SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK)) \
                             << (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GET(flags) \
                             (((flags) >> SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT) \
                             & SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)) \
                             << (SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT (2)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLN_META_DEP_A_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_IMU_SENSOR (6)
typedef struct {
  
  /**
* Position Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates invalid)[0.01]
   */
    u16
  pdop
  ;
  /**
* Horizontal Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates invalid)[0.01]
   */
    u16
  hdop
  ;
  /**
* Vertical Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates invalid)[0.01]
   */
    u16
  vdop
  ;
  /**
* Number of satellites as per last available solution from PVT engine
   */
    u8
  n_sats
  ;
  /**
* Age of corrections as per last available AGE_CORRECTIONS from PVT engine (0xFFFF indicates invalid)[deciseconds]
   */
    u16
  age_corrections
  ;
  /**
* State of alignment and the status and receipt of the alignment inputs
   */
    u8
  alignment_status
  ;
  /**
* Tow of last-used GNSS position measurement[ms]
   */
    u32
  last_used_gnss_pos_tow
  ;
  /**
* Tow of last-used GNSS velocity measurement[ms]
   */
    u32
  last_used_gnss_vel_tow
  ;
  /**
* Array of Metadata describing the sensors potentially involved in the solution. Each element in the array represents a single sensor type and consists of flags containing (meta)data pertaining to that specific single sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  sbp_solution_input_type_t
  sol_in
    [118]
  ;
  /**
   * Number of items in sol_in
   */
  u8 sol_in_count;
} sbp_msg_soln_meta_dep_a_t;


  /** Solution Sensors Metadata
   *
 * This message contains all metadata about the sensors received and/or used in computing the sensorfusion solution.
 * It focuses primarly, but not only, on GNSS metadata.
 * Regarding the age of the last received valid GNSS solution, the highest two bits are time status, indicating
 * whether age gnss can or can not be used to retrieve time of measurement (noted TOM, also known as time of validity)
 * If it can, substract 'age gnss' from 'tow' in navigation messages to get TOM. Can be used before alignment is
 * complete in the Fusion Engine, when output solution is the last received valid GNSS solution and its tow is not a TOM.
   */
#define SBP_MSG_SOLN_META       0xFF0E

	#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_MASK (0x3)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SHIFT (30u)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_GET(flags) \
                             (((flags) >> SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SHIFT) \
                             & SBP_SOLN_META_AGE_GNSS_TIME_STATUS_MASK)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_AGE_GNSS_TIME_STATUS_MASK)) \
                             << (SBP_SOLN_META_AGE_GNSS_TIME_STATUS_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_AGE_CAN_NOT_BE_USED_TO_RETRIEVE_TOM (0)
#define SBP_SOLN_META_AGE_GNSS_TIME_STATUS_AGE_CAN_BE_USED_TO_RETRIEVE_TOM (1)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK (0x3fffffff)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT (0u)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_GET(flags) \
                             (((flags) >> SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT) \
                             & SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK)
#define SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_MASK)) \
                             << (SBP_SOLN_META_AGE_GNSS_AGE_OF_THE_LAST_RECEIVED_VALID_GNSS_SOLUTION_SHIFT)));} while(0)
                             

	
	#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK (0x3)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT (3u)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_GET(flags) \
                             (((flags) >> SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT) \
                             & SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_MASK)) \
                             << (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_UNKNOWN (0)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_AND_USED (1)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_USAGE_RECEIVED_BUT_NOT_USED (2)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK (0x7)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT (0u)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GET(flags) \
                             (((flags) >> SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT) \
                             & SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_MASK)) \
                             << (SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_SHIFT)));} while(0)
                             

#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_INVALID (0)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_POSITION (1)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DISPLACEMENT (2)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_GNSS_VELOCITY_DOPPLER (3)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_TICKS (4)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_ODOMETRY_SPEED (5)
#define SBP_SOLN_META_SOL_IN_SENSOR_TYPE_SENSOR_TYPE_IMU_SENSOR (6)
typedef struct {
  
  /**
* GPS time of week rounded to the nearest millisecond[ms]
   */
    u32
  tow
  ;
  /**
* Position Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates invalid)[0.01]
   */
    u16
  pdop
  ;
  /**
* Horizontal Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates invalid)[0.01]
   */
    u16
  hdop
  ;
  /**
* Vertical Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates invalid)[0.01]
   */
    u16
  vdop
  ;
  /**
* Age of corrections as per last available AGE_CORRECTIONS from PVT engine (0xFFFF indicates invalid)[deciseconds]
   */
    u16
  age_corrections
  ;
  /**
* Age and Time Status of the last received valid GNSS solution.[ms]
   */
    u32
  age_gnss
  ;
  /**
* Array of Metadata describing the sensors potentially involved in the solution. Each element in the array represents a single sensor type and consists of flags containing (meta)data pertaining to that specific single sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  sbp_solution_input_type_t
  sol_in
    [119]
  ;
  /**
   * Number of items in sol_in
   */
  u8 sol_in_count;
} sbp_msg_soln_meta_t;


  /** Instruments the physical type of GNSS sensor input to the fuzed solution.
   *
 * Metadata around the GNSS sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
   */

	#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_MASK (0x3)
#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_SHIFT (0u)
#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_GET(flags) \
                             (((flags) >> SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_SHIFT) \
                             & SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_MASK)
#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_MASK)) \
                             << (SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_SHIFT)));} while(0)
                             

#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_GNSS_POSITION (0)
#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DOPPLER (1)
#define SBP_GNSSINPUTTYPE_FLAGS_TYPE_OF_GNSS_MEASUREMENT_GNSS_VELOCITY_DISPLACEMENT (2)
typedef struct {
  
  /**
* flags that store all relevant info specific to this sensor type.
   */
    u8
  flags
  ;
} sbp_gnss_input_type_t;


  /** Provides detail about the IMU sensor, its timestamping mode, and its quality for input to the fuzed solution.
   *
 * Metadata around the IMU sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
   */

	#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_MASK (0x3)
#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_SHIFT (4u)
#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_GET(flags) \
                             (((flags) >> SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_SHIFT) \
                             & SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_MASK)
#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_MASK)) \
                             << (SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_SHIFT)));} while(0)
                             

#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK (0)
#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP (1)
#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMUINPUTTYPE_FLAGS_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_MASK (0x3)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_SHIFT (2u)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_GET(flags) \
                             (((flags) >> SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_SHIFT) \
                             & SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_MASK)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_MASK)) \
                             << (SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_SHIFT)));} while(0)
                             

#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_CONSUMER_GRADE (0)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_TACTICAL_GRADE (1)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_INTERMEDIATE_GRADE (2)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_GRADE_SUPERIOR_GRADE (3)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_MASK (0x3)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_SHIFT (0u)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_GET(flags) \
                             (((flags) >> SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_SHIFT) \
                             & SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_MASK)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_MASK)) \
                             << (SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_SHIFT)));} while(0)
                             

#define SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_6_AXIS_MEMS (0)
#define SBP_IMUINPUTTYPE_FLAGS_IMU_ARCHITECTURE_OTHER_TYPE (1)
typedef struct {
  
  /**
* Instrument time, grade, and architecture for a sensor.
   */
    u8
  flags
  ;
} sbp_imu_input_type_t;


  /** Provides detail about the Odometry sensor, its timestamping mode, and its quality for input to the fuzed solution.
   *
 * Metadata around the Odometry sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
   */

	#define SBP_ODOINPUTTYPE_FLAGS_RATE_MASK (0x3)
#define SBP_ODOINPUTTYPE_FLAGS_RATE_SHIFT (4u)
#define SBP_ODOINPUTTYPE_FLAGS_RATE_GET(flags) \
                             (((flags) >> SBP_ODOINPUTTYPE_FLAGS_RATE_SHIFT) \
                             & SBP_ODOINPUTTYPE_FLAGS_RATE_MASK)
#define SBP_ODOINPUTTYPE_FLAGS_RATE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOINPUTTYPE_FLAGS_RATE_MASK)) \
                             << (SBP_ODOINPUTTYPE_FLAGS_RATE_SHIFT)));} while(0)
                             

#define SBP_ODOINPUTTYPE_FLAGS_RATE_FIXED_INCOMING_RATE (0)
#define SBP_ODOINPUTTYPE_FLAGS_RATE_TRIGGERED_BY_MINIMUM_DISTANCE_OR_SPEED (1)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_MASK (0x3)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_SHIFT (2u)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_GET(flags) \
                             (((flags) >> SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_SHIFT) \
                             & SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_MASK)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_MASK)) \
                             << (SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_SHIFT)));} while(0)
                             

#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_LOW_GRADE (0)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_MEDIUM_GRADE (1)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_GRADE_SUPERIOR_GRADE (2)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_MASK (0x3)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_SHIFT (0u)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_GET(flags) \
                             (((flags) >> SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_SHIFT) \
                             & SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_MASK)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_MASK)) \
                             << (SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_SHIFT)));} while(0)
                             

#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_SINGLE_OR_AVERAGED_TICKS (0)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_SINGLE_OR_AVERAGED_SPEED (1)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_MULTI_DIMENSIONAL_TICKS (2)
#define SBP_ODOINPUTTYPE_FLAGS_ODOMETER_CLASS_MULTI_DIMENSIONAL_SPEED (3)
typedef struct {
  
  /**
* Instrument ODO rate, grade, and quality.
   */
    u8
  flags
  ;
} sbp_odo_input_type_t;



#include <libsbp/unpacked/solution_meta_operators.h>
#include <libsbp/unpacked/solution_meta_packers.h>

#endif /* LIBSBP_SOLUTION_META_MESSAGES_H */
