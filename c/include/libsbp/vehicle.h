#ifndef LIBSBP_VEHICLE_MESSAGES_H
#define LIBSBP_VEHICLE_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** Vehicle forward (x-axis) velocity
 *
 * Message representing the x component of vehicle velocity in the user frame at the odometry
 * reference point(s) specified by the user. The offset for the odometry reference point and
 * the definition and origin of the user frame are defined through the device settings interface.
 * There are 4 possible user-defined sources of this message  which are labeled arbitrarily
 * source 0 through 3.
 * If using "processor time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise odometry measurements
 * with GNSS. Processor time shall roll over to zero after one week.
 */
#define SBP_MSG_ODOMETRY 0x0903

#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_MASK (0x3)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SHIFT (5u)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_GET(flags) \
  (((flags) >> SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SHIFT) & SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_MASK)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_MASK)) << (SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_SHIFT))); \
  } while (0)

#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_FORWARD (1)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_REVERSE (2)
#define SBP_ODOMETRY_FLAGS_VEHICLE_METADATA_PARK (3)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_MASK (0x3)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SHIFT (3u)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_GET(flags) \
  (((flags) >> SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SHIFT) & SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_MASK)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_MASK)) << (SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SHIFT))); \
  } while (0)

#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_0 (0)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_1 (1)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_2 (2)
#define SBP_ODOMETRY_FLAGS_VELOCITY_SOURCE_SOURCE_3 (3)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_ODOMETRY_FLAGS_TIME_SOURCE_SHIFT) & SBP_ODOMETRY_FLAGS_TIME_SOURCE_MASK)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_ODOMETRY_FLAGS_TIME_SOURCE_MASK)) << (SBP_ODOMETRY_FLAGS_TIME_SOURCE_SHIFT))); \
  } while (0)

#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_GPS_SOLUTION (1)
#define SBP_ODOMETRY_FLAGS_TIME_SOURCE_PROCESSOR_TIME (2)
typedef struct
{

  /**
   * Time field representing either milliseconds in the GPS Week or local CPU
   * time from the producing system in milliseconds.  See the tow_source flag
   * for the exact source of this timestamp.[ms]
   */
  u32 tow;
  /**
   * The signed forward component of vehicle velocity.[mm/s]
   */
  s32 velocity;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_odometry_t;

static inline size_t sbp_packed_size_sbp_msg_odometry_t(const sbp_msg_odometry_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->velocity) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_odometry_t(u8 *buf, size_t len, const sbp_msg_odometry_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_odometry_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtow = htole32(msg->tow);
  memcpy(buf + offset, &msgtow, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgvelocity = htole32(*(const u32 *)&msg->velocity);
  memcpy(buf + offset, &msgvelocity, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_odometry_t(const u8 *buf, size_t len, sbp_msg_odometry_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->velocity, buf + offset, 4);
  u32 msgvelocity = *(const u32 *)&msg->velocity;
  msgvelocity = le32toh(msgvelocity);
  msg->velocity = *(const s32 *)&msgvelocity;
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.velocity != b.velocity)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_odometry_t &a, const sbp_msg_odometry_t &b)
{
  return !(a == b);
}
#endif
/** Accumulated wheeltick count message
 *
 * Message containing the accumulated distance travelled by a wheel located at an odometry
 * reference point defined by the user. The offset for the odometry reference point and the
 * definition and origin of the user frame are defined through the device settings interface.
 * The source of this message is identified by the source field, which is an integer ranging
 * from 0 to 255.
 * The timestamp associated with this message should represent the time when the accumulated
 * tick count reached the value given by the contents of this message as accurately as possible.
 * If using "local CPU time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise wheeltick measurements
 * with GNSS. Local CPU time shall roll over to zero after one week.
 */
#define SBP_MSG_WHEELTICK 0x0904

#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_MASK (0x3)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SHIFT (2u)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_GET(flags) \
  (((flags) >> SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SHIFT) & SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_MASK)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_MASK)) << (SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_SHIFT))); \
  } while (0)

#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_UNAVAILABLE (0)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_FORWARD (1)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_REVERSE (2)
#define SBP_WHEELTICK_FLAGS_VEHICLE_METADATA_PARK (3)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MASK (0x3)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SHIFT (0u)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_GET(flags) \
  (((flags) >> SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SHIFT) & SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MASK)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MASK)) << (SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_SHIFT))); \
  } while (0)

#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MICROSECONDS_SINCE_LAST_PPS (0)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_MICROSECONDS_IN_GPS_WEEK (1)
#define SBP_WHEELTICK_FLAGS_SYNCHRONIZATION_TYPE_LOCAL_CPU_TIME_IN_NOMINAL_MICROSECONDS (2)
typedef struct
{

  /**
   * Time field representing either microseconds since the last PPS, microseconds in the GPS
   * Week or local CPU time from the producing system in microseconds. See the synch_type
   * field for the exact meaning of this timestamp.[us]
   */
  u64 time;
  /**
   * Field indicating the type of timestamp contained in the time field.
   */
  u8 flags;
  /**
   * ID of the sensor producing this message
   */
  u8 source;
  /**
   * Free-running counter of the accumulated distance for this sensor. The counter should be
   * incrementing if travelling into one direction and decrementing when travelling in the
   * opposite direction.[arbitrary distance units]
   */
  s32 ticks;
} sbp_msg_wheeltick_t;

static inline size_t sbp_packed_size_sbp_msg_wheeltick_t(const sbp_msg_wheeltick_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->time) + sizeof(msg->flags) + sizeof(msg->source) + sizeof(msg->ticks);
}

static inline bool sbp_pack_sbp_msg_wheeltick_t(u8 *buf, size_t len, const sbp_msg_wheeltick_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_wheeltick_t(msg) > len)
  {
    return false;
  }

  if (offset + 8 > len)
  {
    return false;
  }
  u64 msgtime = htole64(msg->time);
  memcpy(buf + offset, &msgtime, 8);
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgsource = msg->source;
  memcpy(buf + offset, &msgsource, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgticks = htole32(*(const u32 *)&msg->ticks);
  memcpy(buf + offset, &msgticks, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_wheeltick_t(const u8 *buf, size_t len, sbp_msg_wheeltick_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->time, buf + offset, 8);
  msg->time = le64toh(msg->time);
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->source, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ticks, buf + offset, 4);
  u32 msgticks = *(const u32 *)&msg->ticks;
  msgticks = le32toh(msgticks);
  msg->ticks = *(const s32 *)&msgticks;
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b)
{
  (void)a;
  (void)b;

  if (a.time != b.time)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.source != b.source)
  {
    return false;
  }

  if (a.ticks != b.ticks)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_wheeltick_t &a, const sbp_msg_wheeltick_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_VEHICLE_MESSAGES_H */