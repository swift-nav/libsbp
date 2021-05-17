#ifndef LIBSBP_IMU_MESSAGES_H
#define LIBSBP_IMU_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>
#define SBP_IMU_RAW_TIME_STATUS_MASK (0x3)
#define SBP_IMU_RAW_TIME_STATUS_SHIFT (30u)
#define SBP_IMU_RAW_TIME_STATUS_GET(flags) \
                             (((flags) >> SBP_IMU_RAW_TIME_STATUS_SHIFT) \
                             & SBP_IMU_RAW_TIME_STATUS_MASK)
#define SBP_IMU_RAW_TIME_STATUS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMU_RAW_TIME_STATUS_MASK)) \
                             << (SBP_IMU_RAW_TIME_STATUS_SHIFT)));} while(0)
                             

#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK (0)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP (1)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMU_RAW_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK (0x3fffffff)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT (0u)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_GET(flags) \
                             (((flags) >> SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT) \
                             & SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK)
#define SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK)) \
                             << (SBP_IMU_RAW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT)));} while(0)
                             

/** Raw IMU data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_IMU_RAW 0x0900
typedef struct {
  u32 tow;
  u8 tow_f;
  s16 acc_x;
  s16 acc_y;
  s16 acc_z;
  s16 gyr_x;
  s16 gyr_y;
  s16 gyr_z;
} sbp_msg_imu_raw_t;



#define SBP_IMU_AUX_IMU_TYPE_MASK (0xff)
#define SBP_IMU_AUX_IMU_TYPE_SHIFT (0u)
#define SBP_IMU_AUX_IMU_TYPE_GET(flags) \
                             (((flags) >> SBP_IMU_AUX_IMU_TYPE_SHIFT) \
                             & SBP_IMU_AUX_IMU_TYPE_MASK)
#define SBP_IMU_AUX_IMU_TYPE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMU_AUX_IMU_TYPE_MASK)) \
                             << (SBP_IMU_AUX_IMU_TYPE_SHIFT)));} while(0)
                             

#define SBP_IMU_AUX_IMU_TYPE_BOSCH_BMI160 (0)
#define SBP_IMU_AUX_IMU_TYPE_ST_MICROELECTRONICS_ASM330LLH (1)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_MASK (0xf)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT (4u)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_GET(flags) \
                             (((flags) >> SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT) \
                             & SBP_IMU_AUX_GYROSCOPE_RANGE_MASK)
#define SBP_IMU_AUX_GYROSCOPE_RANGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMU_AUX_GYROSCOPE_RANGE_MASK)) \
                             << (SBP_IMU_AUX_GYROSCOPE_RANGE_SHIFT)));} while(0)
                             

#define SBP_IMU_AUX_GYROSCOPE_RANGE__2000_DEG__S (0)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__1000_DEG__S (1)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__500_DEG__S (2)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__250_DEG__S (3)
#define SBP_IMU_AUX_GYROSCOPE_RANGE__125_DEG__S (4)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK (0xf)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT (0u)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_GET(flags) \
                             (((flags) >> SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT) \
                             & SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_IMU_AUX_ACCELEROMETER_RANGE_MASK)) \
                             << (SBP_IMU_AUX_ACCELEROMETER_RANGE_SHIFT)));} while(0)
                             

#define SBP_IMU_AUX_ACCELEROMETER_RANGE__2G (0)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__4G (1)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__8G (2)
#define SBP_IMU_AUX_ACCELEROMETER_RANGE__16G (3)
/** Auxiliary IMU data
 *
((m.desc|commentify)))
 */
#define SBP_MSG_IMU_AUX 0x0901
typedef struct {
  u8 imu_type;
  s16 temp;
  u8 imu_conf;
} sbp_msg_imu_aux_t;




#include <libsbp/unpacked/imu_operators.h>
#include <libsbp/unpacked/imu_packers.h>

#endif /* LIBSBP_IMU_MESSAGES_H */
