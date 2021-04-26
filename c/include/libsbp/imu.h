#ifndef LIBSBP_IMU_MESSAGES_H
#define LIBSBP_IMU_MESSAGES_H

#include <endian.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Raw IMU data
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings. The sense of the measurements are to be aligned with
 * the indications on the device itself. Measurement units, which are specific
 * to the device hardware and settings, are communicated via the MSG_IMU_AUX
 * message. If using "time since startup" time tags, the receiving end will
 * expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to
 * synchronise IMU measurements with GNSS. The timestamp must wrap around to
 * zero when reaching one week (604800 seconds).
 *
 * The time-tagging mode should not change throughout a run.
 */
#define SBP_MSG_IMU_RAW 0x0900

#define SBP_IMU_RAW_TOW_TIME_STATUS_MASK (0x3)
#define SBP_IMU_RAW_TOW_TIME_STATUS_SHIFT (30u)
#define SBP_IMU_RAW_TOW_TIME_STATUS_GET(flags)      \
  (((flags) >> SBP_IMU_RAW_TOW_TIME_STATUS_SHIFT) & \
   SBP_IMU_RAW_TOW_TIME_STATUS_MASK)
#define SBP_IMU_RAW_TOW_TIME_STATUS_SET(flags, val)           \
  do {                                                        \
    ((flags) |= (((val) & (SBP_IMU_RAW_TOW_TIME_STATUS_MASK)) \
                 << (SBP_IMU_RAW_TOW_TIME_STATUS_SHIFT)));    \
  } while (0)

#define SBP_IMU_RAW_TOW_TIME_STATUS_REFERENCE_EPOCH_IS_START_OF_CURRENT_GPS_WEEK \
  (0)
#define SBP_IMU_RAW_TOW_TIME_STATUS_REFERENCE_EPOCH_IS_TIME_OF_SYSTEM_STARTUP \
  (1)
#define SBP_IMU_RAW_TOW_TIME_STATUS_REFERENCE_EPOCH_IS_UNKNOWN (2)
#define SBP_IMU_RAW_TOW_TIME_STATUS_REFERENCE_EPOCH_IS_LAST_PPS (3)
#define SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK \
  (0x3fffffff)
#define SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT (0u)
#define SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_GET(flags) \
  (((flags) >>                                                                \
    SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT) &       \
   SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK)
#define SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SET(flags,  \
                                                                       val)    \
  do {                                                                         \
    ((flags) |=                                                                \
     (((val) &                                                                 \
       (SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_MASK))      \
      << (SBP_IMU_RAW_TOW_TIME_SINCE_REFERENCE_EPOCH_IN_MILLISECONDS_SHIFT))); \
  } while (0)

typedef struct {
  /**
   * Milliseconds since reference epoch and time status.
   */
  u32 tow;
  /**
   * Milliseconds since reference epoch, fractional part[ms / 256]
   */
  u8 tow_f;
  /**
   * Acceleration in the IMU frame X axis
   */
  s16 acc_x;
  /**
   * Acceleration in the IMU frame Y axis
   */
  s16 acc_y;
  /**
   * Acceleration in the IMU frame Z axis
   */
  s16 acc_z;
  /**
   * Angular rate around IMU frame X axis
   */
  s16 gyr_x;
  /**
   * Angular rate around IMU frame Y axis
   */
  s16 gyr_y;
  /**
   * Angular rate around IMU frame Z axis
   */
  s16 gyr_z;
} sbp_msg_imu_raw_t;

static inline size_t sbp_packed_size_sbp_msg_imu_raw_t(
    const sbp_msg_imu_raw_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->tow_f) + sizeof(msg->acc_x) +
         sizeof(msg->acc_y) + sizeof(msg->acc_z) + sizeof(msg->gyr_x) +
         sizeof(msg->gyr_y) + sizeof(msg->gyr_z);
}

static inline bool sbp_pack_sbp_msg_imu_raw_t(u8 *buf, size_t len,
                                              const sbp_msg_imu_raw_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_imu_raw_t(msg) > len) {
    return false;
  }

  if (offset + 4 > len) {
    return false;
  }
  u32 msgtow = msg->tow;
  msgtow = htole32(msgtow);
  memcpy(buf + offset, &msgtow, 4);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgtow_f = msg->tow_f;
  memcpy(buf + offset, &msgtow_f, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgacc_x = msg->acc_x;
  msgacc_x = htole16(msgacc_x);
  memcpy(buf + offset, &msgacc_x, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgacc_y = msg->acc_y;
  msgacc_y = htole16(msgacc_y);
  memcpy(buf + offset, &msgacc_y, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgacc_z = msg->acc_z;
  msgacc_z = htole16(msgacc_z);
  memcpy(buf + offset, &msgacc_z, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msggyr_x = msg->gyr_x;
  msggyr_x = htole16(msggyr_x);
  memcpy(buf + offset, &msggyr_x, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msggyr_y = msg->gyr_y;
  msggyr_y = htole16(msggyr_y);
  memcpy(buf + offset, &msggyr_y, 2);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  s16 msggyr_z = msg->gyr_z;
  msggyr_z = htole16(msggyr_z);
  memcpy(buf + offset, &msggyr_z, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_raw_t(const u8 *buf, size_t len,
                                                sbp_msg_imu_raw_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len) {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  offset += 4;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->tow_f, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->acc_x, buf + offset, 2);
  msg->acc_x = le16toh(msg->acc_x);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->acc_y, buf + offset, 2);
  msg->acc_y = le16toh(msg->acc_y);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->acc_z, buf + offset, 2);
  msg->acc_z = le16toh(msg->acc_z);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->gyr_x, buf + offset, 2);
  msg->gyr_x = le16toh(msg->gyr_x);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->gyr_y, buf + offset, 2);
  msg->gyr_y = le16toh(msg->gyr_y);
  offset += 2;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->gyr_z, buf + offset, 2);
  msg->gyr_z = le16toh(msg->gyr_z);
  offset += 2;
  return true;
}
/** Auxiliary IMU data
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will
 * always be consistent but the rest of the payload is device specific and
 * depends on the value of `imu_type`.
 */
#define SBP_MSG_IMU_AUX 0x0901

#define SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_MASK (0xff)
#define SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_SHIFT (0u)
#define SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_GET(flags)      \
  (((flags) >> SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_SHIFT) & \
   SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_MASK)
#define SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_SET(flags, val)           \
  do {                                                          \
    ((flags) |= (((val) & (SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_MASK)) \
                 << (SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_SHIFT)));    \
  } while (0)

#define SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_BOSCH_BMI160 (0)
#define SBP_IMU_AUX_IMU_TYPE_IMU_TYPE_ST_MICROELECTRONICS_ASM330LLH (1)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_MASK (0xf)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_SHIFT (4u)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_GET(flags)      \
  (((flags) >> SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_SHIFT) & \
   SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_MASK)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_SET(flags, val)           \
  do {                                                                 \
    ((flags) |= (((val) & (SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_MASK)) \
                 << (SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE_SHIFT)));    \
  } while (0)

#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE__2000_DEG__S (0)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE__1000_DEG__S (1)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE__500_DEG__S (2)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE__250_DEG__S (3)
#define SBP_IMU_AUX_IMU_CONF_GYROSCOPE_RANGE__125_DEG__S (4)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_MASK (0xf)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_SHIFT (0u)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_GET(flags)      \
  (((flags) >> SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_SHIFT) & \
   SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_MASK)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_SET(flags, val)           \
  do {                                                                     \
    ((flags) |= (((val) & (SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_MASK)) \
                 << (SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE_SHIFT)));    \
  } while (0)

#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE__2G (0)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE__4G (1)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE__8G (2)
#define SBP_IMU_AUX_IMU_CONF_ACCELEROMETER_RANGE__16G (3)
typedef struct {
  /**
   * IMU type
   */
  u8 imu_type;
  /**
   * Raw IMU temperature
   */
  s16 temp;
  /**
   * IMU configuration
   */
  u8 imu_conf;
} sbp_msg_imu_aux_t;

static inline size_t sbp_packed_size_sbp_msg_imu_aux_t(
    const sbp_msg_imu_aux_t *msg) {
  (void)msg;
  return 0 + sizeof(msg->imu_type) + sizeof(msg->temp) + sizeof(msg->imu_conf);
}

static inline bool sbp_pack_sbp_msg_imu_aux_t(u8 *buf, size_t len,
                                              const sbp_msg_imu_aux_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_imu_aux_t(msg) > len) {
    return false;
  }

  if (offset + 1 > len) {
    return false;
  }
  u8 msgimu_type = msg->imu_type;
  memcpy(buf + offset, &msgimu_type, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  s16 msgtemp = msg->temp;
  msgtemp = htole16(msgtemp);
  memcpy(buf + offset, &msgtemp, 2);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  u8 msgimu_conf = msg->imu_conf;
  memcpy(buf + offset, &msgimu_conf, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_imu_aux_t(const u8 *buf, size_t len,
                                                sbp_msg_imu_aux_t *msg) {
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->imu_type, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len) {
    return false;
  }
  memcpy(&msg->temp, buf + offset, 2);
  msg->temp = le16toh(msg->temp);
  offset += 2;

  if (offset + 1 > len) {
    return false;
  }
  memcpy(&msg->imu_conf, buf + offset, 1);
  offset += 1;
  return true;
}

#endif /* LIBSBP_IMU_MESSAGES_H */