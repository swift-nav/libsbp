#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#define LIBSBP_NAVIGATION_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** GPS Time
 *
 * This message reports the GPS time, representing the time since
 * the GPS epoch began on midnight January 6, 1980 UTC. GPS time
 * counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of
 * the GPS time scale.
 *
 * Within each week number, the GPS time of the week is between
 * between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
 * does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a
 * set of other navigation messages referenced to the same time
 * (but lacking the ns field) and indicates a more precise time of
 * these messages.
 */
#define SBP_MSG_GPS_TIME 0x0102

#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_GPS_TIME_FLAGS_TIME_SOURCE_SHIFT) & SBP_GPS_TIME_FLAGS_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_GPS_TIME_FLAGS_TIME_SOURCE_MASK)) << (SBP_GPS_TIME_FLAGS_TIME_SOURCE_SHIFT))); \
  } while (0)

#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct
{

  /**
   * GPS week number[weeks]
   */
  u16 wn;
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges
   * from -500000 to 500000)[ns]
   */
  s32 ns_residual;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gps_time_t;

static inline size_t sbp_packed_size_sbp_msg_gps_time_t(const sbp_msg_gps_time_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gps_time_t(u8 *buf, size_t len, const sbp_msg_gps_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gps_time_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  offset += 2;

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
  u32 msgns_residual = htole32(*(const u32 *)&msg->ns_residual);
  memcpy(buf + offset, &msgns_residual, 4);
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

static inline bool sbp_unpack_sbp_msg_gps_time_t(const u8 *buf, size_t len, sbp_msg_gps_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  offset += 2;

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
  memcpy(&msg->ns_residual, buf + offset, 4);
  u32 msgns_residual = *(const u32 *)&msg->ns_residual;
  msgns_residual = le32toh(msgns_residual);
  msg->ns_residual = *(const s32 *)&msgns_residual;
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
static inline bool operator==(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b)
{
  (void)a;
  (void)b;

  if (a.wn != b.wn)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.ns_residual != b.ns_residual)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_gps_time_t &a, const sbp_msg_gps_time_t &b)
{
  return !(a == b);
}
#endif
/** GPS Time
 *
 * This message reports the GPS time, representing the time since
 * the GPS epoch began on midnight January 6, 1980 UTC. GPS time
 * counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of
 * the GPS time scale.
 *
 * Within each week number, the GPS time of the week is between
 * between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
 * does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a
 * set of other navigation messages referenced to the same time
 * (but lacking the ns field) and indicates a more precise time of
 * these messages.
 */
#define SBP_MSG_GPS_TIME_GNSS 0x0104

#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT) & SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)) << (SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT))); \
  } while (0)

#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_GPS_TIME_GNSS_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct
{

  /**
   * GPS week number[weeks]
   */
  u16 wn;
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges
   * from -500000 to 500000)[ns]
   */
  s32 ns_residual;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gps_time_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_gps_time_gnss_t(const sbp_msg_gps_time_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gps_time_gnss_t(u8 *buf, size_t len, const sbp_msg_gps_time_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gps_time_gnss_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  offset += 2;

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
  u32 msgns_residual = htole32(*(const u32 *)&msg->ns_residual);
  memcpy(buf + offset, &msgns_residual, 4);
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

static inline bool sbp_unpack_sbp_msg_gps_time_gnss_t(const u8 *buf, size_t len, sbp_msg_gps_time_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  offset += 2;

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
  memcpy(&msg->ns_residual, buf + offset, 4);
  u32 msgns_residual = *(const u32 *)&msg->ns_residual;
  msgns_residual = le32toh(msgns_residual);
  msg->ns_residual = *(const s32 *)&msgns_residual;
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
static inline bool operator==(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.wn != b.wn)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.ns_residual != b.ns_residual)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_gps_time_gnss_t &a, const sbp_msg_gps_time_gnss_t &b)
{
  return !(a == b);
}
#endif
/** UTC Time
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
 */
#define SBP_MSG_UTC_TIME 0x0103

#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_GET(flags) \
  (((flags) >> SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SHIFT) & SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_MASK)) << (SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_SHIFT))); \
  } while (0)

#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_FLAGS_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_UTC_TIME_FLAGS_TIME_SOURCE_SHIFT) & SBP_UTC_TIME_FLAGS_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_UTC_TIME_FLAGS_TIME_SOURCE_MASK)) << (SBP_UTC_TIME_FLAGS_TIME_SOURCE_SHIFT))); \
  } while (0)

#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct
{

  /**
   * Indicates source and time validity
   */
  u8 flags;
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Year[year]
   */
  u16 year;
  /**
   * Month (range 1 .. 12)[months]
   */
  u8 month;
  /**
   * days in the month (range 1-31)[day]
   */
  u8 day;
  /**
   * hours of day (range 0-23)[hours]
   */
  u8 hours;
  /**
   * minutes of hour (range 0-59)[minutes]
   */
  u8 minutes;
  /**
   * seconds of minute (range 0-60) rounded down[seconds]
   */
  u8 seconds;
  /**
   * nanoseconds of second (range 0-999999999)[nanoseconds]
   */
  u32 ns;
} sbp_msg_utc_time_t;

static inline size_t sbp_packed_size_sbp_msg_utc_time_t(const sbp_msg_utc_time_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sizeof(msg->tow) + sizeof(msg->year) + sizeof(msg->month) + sizeof(msg->day) +
         sizeof(msg->hours) + sizeof(msg->minutes) + sizeof(msg->seconds) + sizeof(msg->ns);
}

static inline bool sbp_pack_sbp_msg_utc_time_t(u8 *buf, size_t len, const sbp_msg_utc_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_utc_time_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtow = htole32(msg->tow);
  memcpy(buf + offset, &msgtow, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgyear = htole16(msg->year);
  memcpy(buf + offset, &msgyear, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmonth = msg->month;
  memcpy(buf + offset, &msgmonth, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgday = msg->day;
  memcpy(buf + offset, &msgday, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghours = msg->hours;
  memcpy(buf + offset, &msghours, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgminutes = msg->minutes;
  memcpy(buf + offset, &msgminutes, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseconds = msg->seconds;
  memcpy(buf + offset, &msgseconds, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgns = htole32(msg->ns);
  memcpy(buf + offset, &msgns, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_t(const u8 *buf, size_t len, sbp_msg_utc_time_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->year, buf + offset, 2);
  msg->year = le16toh(msg->year);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->month, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->day, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->hours, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->minutes, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seconds, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ns, buf + offset, 4);
  msg->ns = le32toh(msg->ns);
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.year != b.year)
  {
    return false;
  }

  if (a.month != b.month)
  {
    return false;
  }

  if (a.day != b.day)
  {
    return false;
  }

  if (a.hours != b.hours)
  {
    return false;
  }

  if (a.minutes != b.minutes)
  {
    return false;
  }

  if (a.seconds != b.seconds)
  {
    return false;
  }

  if (a.ns != b.ns)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_utc_time_t &a, const sbp_msg_utc_time_t &b)
{
  return !(a == b);
}
#endif
/** UTC Time
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
 */
#define SBP_MSG_UTC_TIME_GNSS 0x0105

#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_MASK (0x3)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SHIFT (3u)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_GET(flags) \
  (((flags) >> SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SHIFT) & SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_MASK)) \
                 << (SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_SHIFT))); \
  } while (0)

#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_FACTORY_DEFAULT (0)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_NON_VOLATILE_MEMORY (1)
#define SBP_UTC_TIME_GNSS_FLAGS_UTC_OFFSET_SOURCE_DECODED_THIS_SESSION (2)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_MASK (0x7)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT (0u)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_GET(flags) \
  (((flags) >> SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT) & SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_MASK)) << (SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_SHIFT))); \
  } while (0)

#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_NONE (0)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_GNSS_SOLUTION (1)
#define SBP_UTC_TIME_GNSS_FLAGS_TIME_SOURCE_PROPAGATED (2)
typedef struct
{

  /**
   * Indicates source and time validity
   */
  u8 flags;
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Year[year]
   */
  u16 year;
  /**
   * Month (range 1 .. 12)[months]
   */
  u8 month;
  /**
   * days in the month (range 1-31)[day]
   */
  u8 day;
  /**
   * hours of day (range 0-23)[hours]
   */
  u8 hours;
  /**
   * minutes of hour (range 0-59)[minutes]
   */
  u8 minutes;
  /**
   * seconds of minute (range 0-60) rounded down[seconds]
   */
  u8 seconds;
  /**
   * nanoseconds of second (range 0-999999999)[nanoseconds]
   */
  u32 ns;
} sbp_msg_utc_time_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_utc_time_gnss_t(const sbp_msg_utc_time_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sizeof(msg->tow) + sizeof(msg->year) + sizeof(msg->month) + sizeof(msg->day) +
         sizeof(msg->hours) + sizeof(msg->minutes) + sizeof(msg->seconds) + sizeof(msg->ns);
}

static inline bool sbp_pack_sbp_msg_utc_time_gnss_t(u8 *buf, size_t len, const sbp_msg_utc_time_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_utc_time_gnss_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgtow = htole32(msg->tow);
  memcpy(buf + offset, &msgtow, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgyear = htole16(msg->year);
  memcpy(buf + offset, &msgyear, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgmonth = msg->month;
  memcpy(buf + offset, &msgmonth, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgday = msg->day;
  memcpy(buf + offset, &msgday, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msghours = msg->hours;
  memcpy(buf + offset, &msghours, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgminutes = msg->minutes;
  memcpy(buf + offset, &msgminutes, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgseconds = msg->seconds;
  memcpy(buf + offset, &msgseconds, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgns = htole32(msg->ns);
  memcpy(buf + offset, &msgns, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_utc_time_gnss_t(const u8 *buf, size_t len, sbp_msg_utc_time_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh(msg->tow);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->year, buf + offset, 2);
  msg->year = le16toh(msg->year);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->month, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->day, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->hours, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->minutes, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->seconds, buf + offset, 1);
  offset += 1;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->ns, buf + offset, 4);
  msg->ns = le32toh(msg->ns);
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.year != b.year)
  {
    return false;
  }

  if (a.month != b.month)
  {
    return false;
  }

  if (a.day != b.day)
  {
    return false;
  }

  if (a.hours != b.hours)
  {
    return false;
  }

  if (a.minutes != b.minutes)
  {
    return false;
  }

  if (a.seconds != b.seconds)
  {
    return false;
  }

  if (a.ns != b.ns)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_utc_time_gnss_t &a, const sbp_msg_utc_time_gnss_t &b)
{
  return !(a == b);
}
#endif
/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.  The flags field indicated whether the DOP reported
 * corresponds to differential or SPP solution.
 */
#define SBP_MSG_DOPS 0x0208

#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SHIFT (7u)
#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
  (((flags) >> SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SHIFT) & SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_MASK)) << (SBP_DOPS_FLAGS_RAIM_REPAIR_FLAG_SHIFT))); \
  } while (0)

#define SBP_DOPS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_DOPS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_DOPS_FLAGS_FIX_MODE_GET(flags) (((flags) >> SBP_DOPS_FLAGS_FIX_MODE_SHIFT) & SBP_DOPS_FLAGS_FIX_MODE_MASK)
#define SBP_DOPS_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_DOPS_FLAGS_FIX_MODE_MASK)) << (SBP_DOPS_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_DOPS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_DOPS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_DOPS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_DOPS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_DOPS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_DOPS_FLAGS_FIX_MODE_UNDEFINED (5)
#define SBP_DOPS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Geometric Dilution of Precision[0.01]
   */
  u16 gdop;
  /**
   * Position Dilution of Precision[0.01]
   */
  u16 pdop;
  /**
   * Time Dilution of Precision[0.01]
   */
  u16 tdop;
  /**
   * Horizontal Dilution of Precision[0.01]
   */
  u16 hdop;
  /**
   * Vertical Dilution of Precision[0.01]
   */
  u16 vdop;
  /**
   * Indicates the position solution with which the DOPS message corresponds
   */
  u8 flags;
} sbp_msg_dops_t;

static inline size_t sbp_packed_size_sbp_msg_dops_t(const sbp_msg_dops_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->gdop) + sizeof(msg->pdop) + sizeof(msg->tdop) + sizeof(msg->hdop) +
         sizeof(msg->vdop) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_dops_t(u8 *buf, size_t len, const sbp_msg_dops_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_dops_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msggdop = htole16(msg->gdop);
  memcpy(buf + offset, &msggdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpdop = htole16(msg->pdop);
  memcpy(buf + offset, &msgpdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtdop = htole16(msg->tdop);
  memcpy(buf + offset, &msgtdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghdop = htole16(msg->hdop);
  memcpy(buf + offset, &msghdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvdop = htole16(msg->vdop);
  memcpy(buf + offset, &msgvdop, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_t(const u8 *buf, size_t len, sbp_msg_dops_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->gdop, buf + offset, 2);
  msg->gdop = le16toh(msg->gdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh(msg->pdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tdop, buf + offset, 2);
  msg->tdop = le16toh(msg->tdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh(msg->hdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh(msg->vdop);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.gdop != b.gdop)
  {
    return false;
  }

  if (a.pdop != b.pdop)
  {
    return false;
  }

  if (a.tdop != b.tdop)
  {
    return false;
  }

  if (a.hdop != b.hdop)
  {
    return false;
  }

  if (a.vdop != b.vdop)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_dops_t &a, const sbp_msg_dops_t &b)
{
  return !(a == b);
}
#endif
/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF 0x0209

#define SBP_POS_ECEF_FLAGS_TOW_TYPE_MASK (0x1)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_SHIFT (5u)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_FLAGS_TOW_TYPE_SHIFT) & SBP_POS_ECEF_FLAGS_TOW_TYPE_MASK)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_FLAGS_TOW_TYPE_MASK)) << (SBP_POS_ECEF_FLAGS_TOW_TYPE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_FLAGS_TOW_TYPE_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_FLAGS_TOW_TYPE_OTHER (1)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) & SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_FLAGS_FIX_MODE_SHIFT) & SBP_POS_ECEF_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_FLAGS_FIX_MODE_MASK)) << (SBP_POS_ECEF_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * ECEF X coordinate[m]
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
  /**
   * Position estimated standard deviation[mm]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_t;

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_t(const sbp_msg_pos_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.x - b.x) > 0.001)
  {
    return false;
  }

  if (fabs(a.y - b.y) > 0.001)
  {
    return false;
  }

  if (fabs(a.z - b.z) > 0.001)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_t &a, const sbp_msg_pos_ecef_t &b)
{
  return !(a == b);
}
#endif
/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. The message also
 * reports the upper triangular portion of the 3x3 covariance matrix.
 * If the receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF_COV 0x0214

#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_ECEF_COV_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SHIFT) & SBP_POS_ECEF_COV_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_COV_FLAGS_FIX_MODE_MASK)) << (SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_ECEF_COV_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * ECEF X coordinate[m]
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
  /**
   * Estimated variance of x[m^2]
   */
  float cov_x_x;
  /**
   * Estimated covariance of x and y[m^2]
   */
  float cov_x_y;
  /**
   * Estimated covariance of x and z[m^2]
   */
  float cov_x_z;
  /**
   * Estimated variance of y[m^2]
   */
  float cov_y_y;
  /**
   * Estimated covariance of y and z[m^2]
   */
  float cov_y_z;
  /**
   * Estimated variance of z[m^2]
   */
  float cov_z_z;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_cov_t;

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_t(const sbp_msg_pos_ecef_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_cov_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_cov_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.x - b.x) > 0.001)
  {
    return false;
  }

  if (fabs(a.y - b.y) > 0.001)
  {
    return false;
  }

  if (fabs(a.z - b.z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_x - b.cov_x_x) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_y - b.cov_x_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_z - b.cov_x_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_y - b.cov_y_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_z - b.cov_y_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_z_z - b.cov_z_z) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_t &a, const sbp_msg_pos_ecef_cov_t &b)
{
  return !(a == b);
}
#endif
/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_POS_LLH 0x020A

#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) << (SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) & SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_FLAGS_FIX_MODE_SHIFT) & SBP_POS_LLH_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_FLAGS_FIX_MODE_MASK)) << (SBP_POS_LLH_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Latitude[deg]
   */
  double lat;
  /**
   * Longitude[deg]
   */
  double lon;
  /**
   * Height above WGS84 ellipsoid[m]
   */
  double height;
  /**
   * Horizontal position estimated standard deviation[mm]
   */
  u16 h_accuracy;
  /**
   * Vertical position estimated standard deviation[mm]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_t;

static inline size_t sbp_packed_size_sbp_msg_pos_llh_t(const sbp_msg_pos_llh_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_t(u8 *buf, size_t len, const sbp_msg_pos_llh_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_t(const u8 *buf, size_t len, sbp_msg_pos_llh_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.lat - b.lat) > 0.001)
  {
    return false;
  }

  if (fabs(a.lon - b.lon) > 0.001)
  {
    return false;
  }

  if (fabs(a.height - b.height) > 0.001)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_t &a, const sbp_msg_pos_llh_t &b)
{
  return !(a == b);
}
#endif
/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution as well as the upper triangle of the 3x3
 * covariance matrix.  The position information and Fix Mode flags should
 * follow the MSG_POS_LLH message.  Since the covariance matrix is computed
 * in the local-level North, East, Down frame, the covariance terms follow
 * with that convention. Thus, covariances are reported against the "downward"
 * measurement and care should be taken with the sign convention.
 */
#define SBP_MSG_POS_LLH_COV 0x0211

#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_POS_LLH_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK (0x3)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT (3u)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT) & \
   SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_MASK)) \
                 << (SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_NONE (0)
#define SBP_POS_LLH_COV_FLAGS_INERTIAL_NAVIGATION_MODE_INS_USED (1)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_COV_FLAGS_FIX_MODE_SHIFT) & SBP_POS_LLH_COV_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_COV_FLAGS_FIX_MODE_MASK)) << (SBP_POS_LLH_COV_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Latitude[deg]
   */
  double lat;
  /**
   * Longitude[deg]
   */
  double lon;
  /**
   * Height above WGS84 ellipsoid[m]
   */
  double height;
  /**
   * Estimated variance of northing[m^2]
   */
  float cov_n_n;
  /**
   * Covariance of northing and easting[m^2]
   */
  float cov_n_e;
  /**
   * Covariance of northing and downward measurement[m^2]
   */
  float cov_n_d;
  /**
   * Estimated variance of easting[m^2]
   */
  float cov_e_e;
  /**
   * Covariance of easting and downward measurement[m^2]
   */
  float cov_e_d;
  /**
   * Estimated variance of downward measurement[m^2]
   */
  float cov_d_d;
  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_cov_t;

static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_t(const sbp_msg_pos_llh_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_cov_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_t(const u8 *buf, size_t len, sbp_msg_pos_llh_cov_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.lat - b.lat) > 0.001)
  {
    return false;
  }

  if (fabs(a.lon - b.lon) > 0.001)
  {
    return false;
  }

  if (fabs(a.height - b.height) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_n - b.cov_n_n) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_e - b.cov_n_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_d - b.cov_n_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_e - b.cov_e_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_d - b.cov_e_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_d_d - b.cov_d_d) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_t &a, const sbp_msg_pos_llh_cov_t &b)
{
  return !(a == b);
}
#endif
/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_ECEF 0x020B

#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SHIFT) & SBP_BASELINE_ECEF_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_ECEF_FLAGS_FIX_MODE_MASK)) << (SBP_BASELINE_ECEF_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_INVALID (0)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_ECEF_FLAGS_FIX_MODE_FIXED_RTK (4)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Baseline ECEF X coordinate[mm]
   */
  s32 x;
  /**
   * Baseline ECEF Y coordinate[mm]
   */
  s32 y;
  /**
   * Baseline ECEF Z coordinate[mm]
   */
  s32 z;
  /**
   * Position estimated standard deviation[mm]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ecef_t;

static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_t(const sbp_msg_baseline_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ecef_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ecef_t(const u8 *buf, size_t len, sbp_msg_baseline_ecef_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_t &a, const sbp_msg_baseline_ecef_t &b)
{
  return !(a == b);
}
#endif
/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_NED 0x020C

#define SBP_BASELINE_NED_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_BASELINE_NED_FLAGS_FIX_MODE_SHIFT) & SBP_BASELINE_NED_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_NED_FLAGS_FIX_MODE_MASK)) << (SBP_BASELINE_NED_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_BASELINE_NED_FLAGS_FIX_MODE_INVALID (0)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_NED_FLAGS_FIX_MODE_FIXED_RTK (4)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Baseline North coordinate[mm]
   */
  s32 n;
  /**
   * Baseline East coordinate[mm]
   */
  s32 e;
  /**
   * Baseline Down coordinate[mm]
   */
  s32 d;
  /**
   * Horizontal position estimated standard deviation[mm]
   */
  u16 h_accuracy;
  /**
   * Vertical position estimated standard deviation[mm]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ned_t;

static inline size_t sbp_packed_size_sbp_msg_baseline_ned_t(const sbp_msg_baseline_ned_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ned_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ned_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_t(const u8 *buf, size_t len, sbp_msg_baseline_ned_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ned_t &a, const sbp_msg_baseline_ned_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF 0x020D

#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) << (SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SHIFT) & SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_MASK)) << (SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity ECEF X coordinate[mm/s]
   */
  s32 x;
  /**
   * Velocity ECEF Y coordinate[mm/s]
   */
  s32 y;
  /**
   * Velocity ECEF Z coordinate[mm/s]
   */
  s32 z;
  /**
   * Velocity estimated standard deviation[mm/s]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_t(const sbp_msg_vel_ecef_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_t &a, const sbp_msg_vel_ecef_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF_COV 0x0215

#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_ECEF_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT) & SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_ECEF_COV_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_ECEF_COV_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity ECEF X coordinate[mm/s]
   */
  s32 x;
  /**
   * Velocity ECEF Y coordinate[mm/s]
   */
  s32 y;
  /**
   * Velocity ECEF Z coordinate[mm/s]
   */
  s32 z;
  /**
   * Estimated variance of x[m^2/s^2]
   */
  float cov_x_x;
  /**
   * Estimated covariance of x and y[m^2/s^2]
   */
  float cov_x_y;
  /**
   * Estimated covariance of x and z[m^2/s^2]
   */
  float cov_x_z;
  /**
   * Estimated variance of y[m^2/s^2]
   */
  float cov_y_y;
  /**
   * Estimated covariance of y and z[m^2/s^2]
   */
  float cov_y_z;
  /**
   * Estimated variance of z[m^2/s^2]
   */
  float cov_z_z;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_cov_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_t(const sbp_msg_vel_ecef_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_cov_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_cov_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (fabs(a.cov_x_x - b.cov_x_x) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_y - b.cov_x_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_z - b.cov_x_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_y - b.cov_y_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_z - b.cov_y_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_z_z - b.cov_z_z) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_t &a, const sbp_msg_vel_ecef_cov_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_NED 0x020E

#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) << (SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SHIFT) & SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_MASK)) << (SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_NED_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_NED_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_NED_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_NED_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity North coordinate[mm/s]
   */
  s32 n;
  /**
   * Velocity East coordinate[mm/s]
   */
  s32 e;
  /**
   * Velocity Down coordinate[mm/s]
   */
  s32 d;
  /**
   * Horizontal velocity estimated standard deviation[mm/s]
   */
  u16 h_accuracy;
  /**
   * Vertical velocity estimated standard deviation[mm/s]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ned_t(const sbp_msg_vel_ned_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_t(u8 *buf, size_t len, const sbp_msg_vel_ned_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_t(const u8 *buf, size_t len, sbp_msg_vel_ned_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_t &a, const sbp_msg_vel_ned_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
 * portion of the 3x3 covariance matrix.
 */
#define SBP_MSG_VEL_NED_COV 0x0212

#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK (0x1)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT (5u)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_GET(flags) \
  (((flags) >> SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT) & SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_MASK)) \
                 << (SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_TIME_OF_MEASUREMENT (0)
#define SBP_VEL_NED_COV_FLAGS_TYPE_OF_REPORTED_TOW_OTHER (1)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT) & SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                 << (SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_NED_COV_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_NED_COV_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity North coordinate[mm/s]
   */
  s32 n;
  /**
   * Velocity East coordinate[mm/s]
   */
  s32 e;
  /**
   * Velocity Down coordinate[mm/s]
   */
  s32 d;
  /**
   * Estimated variance of northward measurement[m^2]
   */
  float cov_n_n;
  /**
   * Covariance of northward and eastward measurement[m^2]
   */
  float cov_n_e;
  /**
   * Covariance of northward and downward measurement[m^2]
   */
  float cov_n_d;
  /**
   * Estimated variance of eastward measurement[m^2]
   */
  float cov_e_e;
  /**
   * Covariance of eastward and downward measurement[m^2]
   */
  float cov_e_d;
  /**
   * Estimated variance of downward measurement[m^2]
   */
  float cov_d_d;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_cov_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_t(const sbp_msg_vel_ned_cov_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_cov_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_t(const u8 *buf, size_t len, sbp_msg_vel_ned_cov_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (fabs(a.cov_n_n - b.cov_n_n) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_e - b.cov_n_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_d - b.cov_n_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_e - b.cov_e_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_d - b.cov_e_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_d_d - b.cov_d_d) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_t &a, const sbp_msg_vel_ned_cov_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF_GNSS 0x0229

#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SHIFT) & SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_MASK)) << (SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * ECEF X coordinate[m]
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
  /**
   * Position estimated standard deviation[mm]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_gnss_t(const sbp_msg_pos_ecef_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.x - b.x) > 0.001)
  {
    return false;
  }

  if (fabs(a.y - b.y) > 0.001)
  {
    return false;
  }

  if (fabs(a.z - b.z) > 0.001)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_gnss_t &a, const sbp_msg_pos_ecef_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. The message also
 * reports the upper triangular portion of the 3x3 covariance matrix.
 * If the receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF_COV_GNSS 0x0234

#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SHIFT) & SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_MASK)) << (SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_ECEF_COV_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * ECEF X coordinate[m]
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
  /**
   * Estimated variance of x[m^2]
   */
  float cov_x_x;
  /**
   * Estimated covariance of x and y[m^2]
   */
  float cov_x_y;
  /**
   * Estimated covariance of x and z[m^2]
   */
  float cov_x_z;
  /**
   * Estimated variance of y[m^2]
   */
  float cov_y_y;
  /**
   * Estimated covariance of y and z[m^2]
   */
  float cov_y_z;
  /**
   * Estimated variance of z[m^2]
   */
  float cov_z_z;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_cov_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(const sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_cov_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_cov_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.x - b.x) > 0.001)
  {
    return false;
  }

  if (fabs(a.y - b.y) > 0.001)
  {
    return false;
  }

  if (fabs(a.z - b.z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_x - b.cov_x_x) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_y - b.cov_x_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_z - b.cov_x_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_y - b.cov_y_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_z - b.cov_y_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_z_z - b.cov_z_z) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_cov_gnss_t &a, const sbp_msg_pos_ecef_cov_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_POS_LLH_GNSS 0x022A

#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SHIFT) & SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_MASK)) << (SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Latitude[deg]
   */
  double lat;
  /**
   * Longitude[deg]
   */
  double lon;
  /**
   * Height above WGS84 ellipsoid[m]
   */
  double height;
  /**
   * Horizontal position estimated standard deviation[mm]
   */
  u16 h_accuracy;
  /**
   * Vertical position estimated standard deviation[mm]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_pos_llh_gnss_t(const sbp_msg_pos_llh_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_llh_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.lat - b.lat) > 0.001)
  {
    return false;
  }

  if (fabs(a.lon - b.lon) > 0.001)
  {
    return false;
  }

  if (fabs(a.height - b.height) > 0.001)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_gnss_t &a, const sbp_msg_pos_llh_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution as well as the upper triangle of the 3x3
 * covariance matrix.  The position information and Fix Mode flags should
 * follow the MSG_POS_LLH message.  Since the covariance matrix is computed
 * in the local-level North, East, Down frame, the covariance terms follow
 * with that convention. Thus, covariances are reported against the "downward"
 * measurement and care should be taken with the sign convention.
 */
#define SBP_MSG_POS_LLH_COV_GNSS 0x0231

#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SHIFT) & SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_MASK)) << (SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_INVALID (0)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SINGLE_POINT_POSITION (1)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_FIXED_RTK (4)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_DEAD_RECKONING (5)
#define SBP_POS_LLH_COV_GNSS_FLAGS_FIX_MODE_SBAS_POSITION (6)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Latitude[deg]
   */
  double lat;
  /**
   * Longitude[deg]
   */
  double lon;
  /**
   * Height above WGS84 ellipsoid[m]
   */
  double height;
  /**
   * Estimated variance of northing[m^2]
   */
  float cov_n_n;
  /**
   * Covariance of northing and easting[m^2]
   */
  float cov_n_e;
  /**
   * Covariance of northing and downward measurement[m^2]
   */
  float cov_n_d;
  /**
   * Estimated variance of easting[m^2]
   */
  float cov_e_e;
  /**
   * Covariance of easting and downward measurement[m^2]
   */
  float cov_e_d;
  /**
   * Estimated variance of downward measurement[m^2]
   */
  float cov_d_d;
  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_cov_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(const sbp_msg_pos_llh_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_pos_llh_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_cov_gnss_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_pos_llh_cov_gnss_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.lat - b.lat) > 0.001)
  {
    return false;
  }

  if (fabs(a.lon - b.lon) > 0.001)
  {
    return false;
  }

  if (fabs(a.height - b.height) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_n - b.cov_n_n) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_e - b.cov_n_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_d - b.cov_n_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_e - b.cov_e_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_d - b.cov_e_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_d_d - b.cov_d_d) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_cov_gnss_t &a, const sbp_msg_pos_llh_cov_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF_GNSS 0x022D

#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity ECEF X coordinate[mm/s]
   */
  s32 x;
  /**
   * Velocity ECEF Y coordinate[mm/s]
   */
  s32 y;
  /**
   * Velocity ECEF Z coordinate[mm/s]
   */
  s32 z;
  /**
   * Velocity estimated standard deviation[mm/s]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_gnss_t(const sbp_msg_vel_ecef_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_gnss_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_gnss_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_gnss_t &a, const sbp_msg_vel_ecef_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF_COV_GNSS 0x0235

#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)) \
                 << (SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_ECEF_COV_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity ECEF X coordinate[mm/s]
   */
  s32 x;
  /**
   * Velocity ECEF Y coordinate[mm/s]
   */
  s32 y;
  /**
   * Velocity ECEF Z coordinate[mm/s]
   */
  s32 z;
  /**
   * Estimated variance of x[m^2/s^2]
   */
  float cov_x_x;
  /**
   * Estimated covariance of x and y[m^2/s^2]
   */
  float cov_x_y;
  /**
   * Estimated covariance of x and z[m^2/s^2]
   */
  float cov_x_z;
  /**
   * Estimated variance of y[m^2/s^2]
   */
  float cov_y_y;
  /**
   * Estimated covariance of y and z[m^2/s^2]
   */
  float cov_y_z;
  /**
   * Estimated variance of z[m^2/s^2]
   */
  float cov_z_z;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ecef_cov_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(const sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_cov_gnss_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_cov_gnss_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (fabs(a.cov_x_x - b.cov_x_x) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_y - b.cov_x_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_z - b.cov_x_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_y - b.cov_y_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_z - b.cov_y_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_z_z - b.cov_z_z) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_cov_gnss_t &a, const sbp_msg_vel_ecef_cov_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_NED_GNSS 0x022E

#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity North coordinate[mm/s]
   */
  s32 n;
  /**
   * Velocity East coordinate[mm/s]
   */
  s32 e;
  /**
   * Velocity Down coordinate[mm/s]
   */
  s32 d;
  /**
   * Horizontal velocity estimated standard deviation[mm/s]
   */
  u16 h_accuracy;
  /**
   * Vertical velocity estimated standard deviation[mm/s]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ned_gnss_t(const sbp_msg_vel_ned_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_gnss_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ned_gnss_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_gnss_t &a, const sbp_msg_vel_ned_gnss_t &b)
{
  return !(a == b);
}
#endif
/** GNSS-only Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
 * portion of the 3x3 covariance matrix.
 */
#define SBP_MSG_VEL_NED_COV_GNSS 0x0232

#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_NED_COV_GNSS_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity North coordinate[mm/s]
   */
  s32 n;
  /**
   * Velocity East coordinate[mm/s]
   */
  s32 e;
  /**
   * Velocity Down coordinate[mm/s]
   */
  s32 d;
  /**
   * Estimated variance of northward measurement[m^2]
   */
  float cov_n_n;
  /**
   * Covariance of northward and eastward measurement[m^2]
   */
  float cov_n_e;
  /**
   * Covariance of northward and downward measurement[m^2]
   */
  float cov_n_d;
  /**
   * Estimated variance of eastward measurement[m^2]
   */
  float cov_e_e;
  /**
   * Covariance of eastward and downward measurement[m^2]
   */
  float cov_e_d;
  /**
   * Estimated variance of downward measurement[m^2]
   */
  float cov_d_d;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_ned_cov_gnss_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(const sbp_msg_vel_ned_cov_gnss_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->cov_n_n) +
         sizeof(msg->cov_n_e) + sizeof(msg->cov_n_d) + sizeof(msg->cov_e_e) + sizeof(msg->cov_e_d) +
         sizeof(msg->cov_d_d) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_cov_gnss_t(u8 *buf, size_t len, const sbp_msg_vel_ned_cov_gnss_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_cov_gnss_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_n = msg->cov_n_n;
  memcpy(buf + offset, &msgcov_n_n, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_e = msg->cov_n_e;
  memcpy(buf + offset, &msgcov_n_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_n_d = msg->cov_n_d;
  memcpy(buf + offset, &msgcov_n_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_e = msg->cov_e_e;
  memcpy(buf + offset, &msgcov_e_e, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_e_d = msg->cov_e_d;
  memcpy(buf + offset, &msgcov_e_d, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_d_d = msg->cov_d_d;
  memcpy(buf + offset, &msgcov_d_d, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_cov_gnss_t(const u8 *buf, size_t len, sbp_msg_vel_ned_cov_gnss_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_n, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_n_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_e, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_e_d, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_d_d, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (fabs(a.cov_n_n - b.cov_n_n) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_e - b.cov_n_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_n_d - b.cov_n_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_e - b.cov_e_e) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_e_d - b.cov_e_d) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_d_d - b.cov_d_d) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_cov_gnss_t &a, const sbp_msg_vel_ned_cov_gnss_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in User Frame
 *
 * This message reports the velocity in the Vehicle Body Frame. By convention,
 * the x-axis should point out the nose of the vehicle and represent the forward
 * direction, while as the y-axis should point out the right hand side of the vehicle.
 * Since this is a right handed system, z should point out the bottom of the vehicle.
 * The orientation and origin of the Vehicle Body Frame are specified via the device settings.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow). This message is only produced by inertial versions of Swift
 * products and is not available from Piksi Multi or Duro.
 */
#define SBP_MSG_VEL_BODY 0x0213

#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_MASK (0x3)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SHIFT (3u)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
  (((flags) >> SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SHIFT) & SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_MASK)) << (SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_NONE (0)
#define SBP_VEL_BODY_FLAGS_INS_NAVIGATION_MODE_INS_USED (1)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MASK (0x7)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SHIFT (0u)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_GET(flags) \
  (((flags) >> SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SHIFT) & SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MASK)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MASK)) << (SBP_VEL_BODY_FLAGS_VELOCITY_MODE_SHIFT))); \
  } while (0)

#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_INVALID (0)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_MEASURED_DOPPLER_DERIVED (1)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_COMPUTED_DOPPLER_DERIVED (2)
#define SBP_VEL_BODY_FLAGS_VELOCITY_MODE_DEAD_RECKONING (3)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity in x direction[mm/s]
   */
  s32 x;
  /**
   * Velocity in y direction[mm/s]
   */
  s32 y;
  /**
   * Velocity in z direction[mm/s]
   */
  s32 z;
  /**
   * Estimated variance of x[m^2]
   */
  float cov_x_x;
  /**
   * Covariance of x and y[m^2]
   */
  float cov_x_y;
  /**
   * Covariance of x and z[m^2]
   */
  float cov_x_z;
  /**
   * Estimated variance of y[m^2]
   */
  float cov_y_y;
  /**
   * Covariance of y and z[m^2]
   */
  float cov_y_z;
  /**
   * Estimated variance of z[m^2]
   */
  float cov_z_z;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_vel_body_t;

static inline size_t sbp_packed_size_sbp_msg_vel_body_t(const sbp_msg_vel_body_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->cov_x_x) +
         sizeof(msg->cov_x_y) + sizeof(msg->cov_x_z) + sizeof(msg->cov_y_y) + sizeof(msg->cov_y_z) +
         sizeof(msg->cov_z_z) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_body_t(u8 *buf, size_t len, const sbp_msg_vel_body_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_body_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_x = msg->cov_x_x;
  memcpy(buf + offset, &msgcov_x_x, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_y = msg->cov_x_y;
  memcpy(buf + offset, &msgcov_x_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_x_z = msg->cov_x_z;
  memcpy(buf + offset, &msgcov_x_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_y = msg->cov_y_y;
  memcpy(buf + offset, &msgcov_y_y, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_y_z = msg->cov_y_z;
  memcpy(buf + offset, &msgcov_y_z, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  float msgcov_z_z = msg->cov_z_z;
  memcpy(buf + offset, &msgcov_z_z, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_body_t(const u8 *buf, size_t len, sbp_msg_vel_body_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_x, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_x_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_y, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_y_z, buf + offset, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->cov_z_z, buf + offset, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (fabs(a.cov_x_x - b.cov_x_x) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_y - b.cov_x_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_x_z - b.cov_x_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_y - b.cov_y_y) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_y_z - b.cov_y_z) > 0.001)
  {
    return false;
  }

  if (fabs(a.cov_z_z - b.cov_z_z) > 0.001)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_body_t &a, const sbp_msg_vel_body_t &b)
{
  return !(a == b);
}
#endif
/** Age of corrections
 *
 * This message reports the Age of the corrections used for the current
 * Differential solution
 */
#define SBP_MSG_AGE_CORRECTIONS 0x0210

typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Age of the corrections (0xFFFF indicates invalid)[deciseconds]
   */
  u16 age;
} sbp_msg_age_corrections_t;

static inline size_t sbp_packed_size_sbp_msg_age_corrections_t(const sbp_msg_age_corrections_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->age);
}

static inline bool sbp_pack_sbp_msg_age_corrections_t(u8 *buf, size_t len, const sbp_msg_age_corrections_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_age_corrections_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgage = htole16(msg->age);
  memcpy(buf + offset, &msgage, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_age_corrections_t(const u8 *buf, size_t len, sbp_msg_age_corrections_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->age, buf + offset, 2);
  msg->age = le16toh(msg->age);
  offset += 2;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.age != b.age)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_age_corrections_t &a, const sbp_msg_age_corrections_t &b)
{
  return !(a == b);
}
#endif
/** GPS Time (v1.0)
 *
 * This message reports the GPS time, representing the time since
 * the GPS epoch began on midnight January 6, 1980 UTC. GPS time
 * counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of
 * the GPS time scale.
 *
 * Within each week number, the GPS time of the week is between
 * between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
 * does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a
 * set of other navigation messages referenced to the same time
 * (but lacking the ns field) and indicates a more precise time of
 * these messages.
 */
#define SBP_MSG_GPS_TIME_DEP_A 0x0100

typedef struct
{

  /**
   * GPS week number[weeks]
   */
  u16 wn;
  /**
   * GPS time of week rounded to the nearest millisecond[ms]
   */
  u32 tow;
  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges
   * from -500000 to 500000)[ns]
   */
  s32 ns_residual;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gps_time_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_gps_time_dep_a_t(const sbp_msg_gps_time_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->wn) + sizeof(msg->tow) + sizeof(msg->ns_residual) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gps_time_dep_a_t(u8 *buf, size_t len, const sbp_msg_gps_time_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gps_time_dep_a_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgwn = htole16(msg->wn);
  memcpy(buf + offset, &msgwn, 2);
  offset += 2;

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
  u32 msgns_residual = htole32(*(const u32 *)&msg->ns_residual);
  memcpy(buf + offset, &msgns_residual, 4);
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

static inline bool sbp_unpack_sbp_msg_gps_time_dep_a_t(const u8 *buf, size_t len, sbp_msg_gps_time_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->wn, buf + offset, 2);
  msg->wn = le16toh(msg->wn);
  offset += 2;

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
  memcpy(&msg->ns_residual, buf + offset, 4);
  u32 msgns_residual = *(const u32 *)&msg->ns_residual;
  msgns_residual = le32toh(msgns_residual);
  msg->ns_residual = *(const s32 *)&msgns_residual;
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
static inline bool operator==(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.wn != b.wn)
  {
    return false;
  }

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.ns_residual != b.ns_residual)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_gps_time_dep_a_t &a, const sbp_msg_gps_time_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.
 */
#define SBP_MSG_DOPS_DEP_A 0x0206

typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Geometric Dilution of Precision[0.01]
   */
  u16 gdop;
  /**
   * Position Dilution of Precision[0.01]
   */
  u16 pdop;
  /**
   * Time Dilution of Precision[0.01]
   */
  u16 tdop;
  /**
   * Horizontal Dilution of Precision[0.01]
   */
  u16 hdop;
  /**
   * Vertical Dilution of Precision[0.01]
   */
  u16 vdop;
} sbp_msg_dops_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_dops_dep_a_t(const sbp_msg_dops_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->gdop) + sizeof(msg->pdop) + sizeof(msg->tdop) + sizeof(msg->hdop) +
         sizeof(msg->vdop);
}

static inline bool sbp_pack_sbp_msg_dops_dep_a_t(u8 *buf, size_t len, const sbp_msg_dops_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_dops_dep_a_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msggdop = htole16(msg->gdop);
  memcpy(buf + offset, &msggdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgpdop = htole16(msg->pdop);
  memcpy(buf + offset, &msgpdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgtdop = htole16(msg->tdop);
  memcpy(buf + offset, &msgtdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghdop = htole16(msg->hdop);
  memcpy(buf + offset, &msghdop, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvdop = htole16(msg->vdop);
  memcpy(buf + offset, &msgvdop, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_dops_dep_a_t(const u8 *buf, size_t len, sbp_msg_dops_dep_a_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->gdop, buf + offset, 2);
  msg->gdop = le16toh(msg->gdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh(msg->pdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->tdop, buf + offset, 2);
  msg->tdop = le16toh(msg->tdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh(msg->hdop);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh(msg->vdop);
  offset += 2;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.gdop != b.gdop)
  {
    return false;
  }

  if (a.pdop != b.pdop)
  {
    return false;
  }

  if (a.tdop != b.tdop)
  {
    return false;
  }

  if (a.hdop != b.hdop)
  {
    return false;
  }

  if (a.vdop != b.vdop)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_dops_dep_a_t &a, const sbp_msg_dops_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF_DEP_A 0x0200

#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
  (((flags) >> SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) & SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
  (((flags) >> SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_POS_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT) & SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)) << (SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_ECEF_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (2)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * ECEF X coordinate[m]
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
  /**
   * Position accuracy estimate (not implemented). Defaults
   * to 0.[mm]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_ecef_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(const sbp_msg_pos_ecef_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_ecef_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_ecef_dep_a_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msgx = msg->x;
  memcpy(buf + offset, &msgx, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgy = msg->y;
  memcpy(buf + offset, &msgy, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgz = msg->z;
  memcpy(buf + offset, &msgz, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_pos_ecef_dep_a_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->x, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.x - b.x) > 0.001)
  {
    return false;
  }

  if (fabs(a.y - b.y) > 0.001)
  {
    return false;
  }

  if (fabs(a.z - b.z) > 0.001)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_ecef_dep_a_t &a, const sbp_msg_pos_ecef_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_POS_LLH_DEP_A 0x0201

#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (5u)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
  (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) & SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) << (SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (4u)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
  (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_POS_LLH_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_MASK (0x1)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SHIFT (3u)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SHIFT) & SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_MASK)) << (SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_HEIGHT_ABOVE_WGS84_ELLIPSOID (0)
#define SBP_POS_LLH_DEP_A_FLAGS_HEIGHT_MODE_HEIGHT_ABOVE_MEAN_SEA_LEVEL (1)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SHIFT) & SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_MASK)) << (SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_SINGLE_POINT_POSITIONING (0)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
#define SBP_POS_LLH_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (2)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
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
  /**
   * Horizontal position accuracy estimate (not
   * implemented). Defaults to 0.[mm]
   */
  u16 h_accuracy;
  /**
   * Vertical position accuracy estimate (not
   * implemented). Defaults to 0.[mm]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution.
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_pos_llh_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_pos_llh_dep_a_t(const sbp_msg_pos_llh_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->lat) + sizeof(msg->lon) + sizeof(msg->height) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_pos_llh_dep_a_t(u8 *buf, size_t len, const sbp_msg_pos_llh_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_pos_llh_dep_a_t(msg) > len)
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

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_pos_llh_dep_a_t(const u8 *buf, size_t len, sbp_msg_pos_llh_dep_a_t *msg)
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

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (fabs(a.lat - b.lat) > 0.001)
  {
    return false;
  }

  if (fabs(a.lon - b.lon) > 0.001)
  {
    return false;
  }

  if (fabs(a.height - b.height) > 0.001)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_pos_llh_dep_a_t &a, const sbp_msg_pos_llh_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_ECEF_DEP_A 0x0202

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
  (((flags) >> SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT))); \
  } while (0)

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
  (((flags) >> SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT))); \
  } while (0)

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT) & SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_MASK)) << (SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_ECEF_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Baseline ECEF X coordinate[mm]
   */
  s32 x;
  /**
   * Baseline ECEF Y coordinate[mm]
   */
  s32 y;
  /**
   * Baseline ECEF Z coordinate[mm]
   */
  s32 z;
  /**
   * Position accuracy estimate[mm]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ecef_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(const sbp_msg_baseline_ecef_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ecef_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ecef_dep_a_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_baseline_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_ecef_dep_a_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ecef_dep_a_t &a, const sbp_msg_baseline_ecef_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_NED_DEP_A 0x0203

#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
  (((flags) >> SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT))); \
  } while (0)

#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
  (((flags) >> SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT))); \
  } while (0)

#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_NED_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SHIFT) & SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_MASK)) << (SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_NED_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Baseline North coordinate[mm]
   */
  s32 n;
  /**
   * Baseline East coordinate[mm]
   */
  s32 e;
  /**
   * Baseline Down coordinate[mm]
   */
  s32 d;
  /**
   * Horizontal position accuracy estimate (not
   * implemented). Defaults to 0.[mm]
   */
  u16 h_accuracy;
  /**
   * Vertical position accuracy estimate (not
   * implemented). Defaults to 0.[mm]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_ned_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(const sbp_msg_baseline_ned_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_baseline_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_ned_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_ned_dep_a_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_ned_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_ned_dep_a_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_ned_dep_a_t &a, const sbp_msg_baseline_ned_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF_DEP_A 0x0204

typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity ECEF X coordinate[mm/s]
   */
  s32 x;
  /**
   * Velocity ECEF Y coordinate[mm/s]
   */
  s32 y;
  /**
   * Velocity ECEF Z coordinate[mm/s]
   */
  s32 z;
  /**
   * Velocity accuracy estimate (not implemented). Defaults
   * to 0.[mm/s]
   */
  u16 accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_vel_ecef_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(const sbp_msg_vel_ecef_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->x) + sizeof(msg->y) + sizeof(msg->z) + sizeof(msg->accuracy) +
         sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ecef_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ecef_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ecef_dep_a_t(msg) > len)
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
  u32 msgx = htole32(*(const u32 *)&msg->x);
  memcpy(buf + offset, &msgx, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgy = htole32(*(const u32 *)&msg->y);
  memcpy(buf + offset, &msgy, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgz = htole32(*(const u32 *)&msg->z);
  memcpy(buf + offset, &msgz, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgaccuracy = htole16(msg->accuracy);
  memcpy(buf + offset, &msgaccuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ecef_dep_a_t(const u8 *buf, size_t len, sbp_msg_vel_ecef_dep_a_t *msg)
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
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32 *)&msg->x;
  msgx = le32toh(msgx);
  msg->x = *(const s32 *)&msgx;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32 *)&msg->y;
  msgy = le32toh(msgy);
  msg->y = *(const s32 *)&msgy;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32 *)&msg->z;
  msgz = le32toh(msgz);
  msg->z = *(const s32 *)&msgz;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->accuracy, buf + offset, 2);
  msg->accuracy = le16toh(msg->accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.x != b.x)
  {
    return false;
  }

  if (a.y != b.y)
  {
    return false;
  }

  if (a.z != b.z)
  {
    return false;
  }

  if (a.accuracy != b.accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ecef_dep_a_t &a, const sbp_msg_vel_ecef_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_NED_DEP_A 0x0205

typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Velocity North coordinate[mm/s]
   */
  s32 n;
  /**
   * Velocity East coordinate[mm/s]
   */
  s32 e;
  /**
   * Velocity Down coordinate[mm/s]
   */
  s32 d;
  /**
   * Horizontal velocity accuracy estimate (not
   * implemented). Defaults to 0.[mm/s]
   */
  u16 h_accuracy;
  /**
   * Vertical velocity accuracy estimate (not
   * implemented). Defaults to 0.[mm/s]
   */
  u16 v_accuracy;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_vel_ned_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_vel_ned_dep_a_t(const sbp_msg_vel_ned_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->n) + sizeof(msg->e) + sizeof(msg->d) + sizeof(msg->h_accuracy) +
         sizeof(msg->v_accuracy) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_vel_ned_dep_a_t(u8 *buf, size_t len, const sbp_msg_vel_ned_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_vel_ned_dep_a_t(msg) > len)
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
  u32 msgn = htole32(*(const u32 *)&msg->n);
  memcpy(buf + offset, &msgn, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msge = htole32(*(const u32 *)&msg->e);
  memcpy(buf + offset, &msge, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgd = htole32(*(const u32 *)&msg->d);
  memcpy(buf + offset, &msgd, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgh_accuracy = htole16(msg->h_accuracy);
  memcpy(buf + offset, &msgh_accuracy, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgv_accuracy = htole16(msg->v_accuracy);
  memcpy(buf + offset, &msgv_accuracy, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_vel_ned_dep_a_t(const u8 *buf, size_t len, sbp_msg_vel_ned_dep_a_t *msg)
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
  memcpy(&msg->n, buf + offset, 4);
  u32 msgn = *(const u32 *)&msg->n;
  msgn = le32toh(msgn);
  msg->n = *(const s32 *)&msgn;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->e, buf + offset, 4);
  u32 msge = *(const u32 *)&msg->e;
  msge = le32toh(msge);
  msg->e = *(const s32 *)&msge;
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->d, buf + offset, 4);
  u32 msgd = *(const u32 *)&msg->d;
  msgd = le32toh(msgd);
  msg->d = *(const s32 *)&msgd;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->h_accuracy, buf + offset, 2);
  msg->h_accuracy = le16toh(msg->h_accuracy);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->v_accuracy, buf + offset, 2);
  msg->v_accuracy = le16toh(msg->v_accuracy);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.n != b.n)
  {
    return false;
  }

  if (a.e != b.e)
  {
    return false;
  }

  if (a.d != b.d)
  {
    return false;
  }

  if (a.h_accuracy != b.h_accuracy)
  {
    return false;
  }

  if (a.v_accuracy != b.v_accuracy)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_vel_ned_dep_a_t &a, const sbp_msg_vel_ned_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_HEADING_DEP_A 0x0207

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT (4u)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_GET(flags) \
  (((flags) >> SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT) & \
   SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_MASK)) \
                 << (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SHIFT))); \
  } while (0)

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_NO_REPAIR (0)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_REPAIR_FLAG_SOLUTION_CAME_FROM_RAIM_REPAIR (1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK (0x1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT (3u)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_GET(flags) \
  (((flags) >> SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT) & \
   SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_MASK)) \
                 << (SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_SHIFT))); \
  } while (0)

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_EXPLICITLY_DISABLED_OR_UNAVAILABLE (0)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_RAIM_AVAILABILITY_FLAG_RAIM_CHECK_WAS_AVAILABLE (1)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_GET(flags) \
  (((flags) >> SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SHIFT) & SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_MASK)) \
                 << (SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_SHIFT))); \
  } while (0)

#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_FLOAT_RTK (0)
#define SBP_BASELINE_HEADING_DEP_A_FLAGS_FIX_MODE_FIXED_RTK (1)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Heading[mdeg]
   */
  u32 heading;
  /**
   * Number of satellites used in solution
   */
  u8 n_sats;
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_baseline_heading_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(const sbp_msg_baseline_heading_dep_a_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->heading) + sizeof(msg->n_sats) + sizeof(msg->flags);
}

static inline bool
sbp_pack_sbp_msg_baseline_heading_dep_a_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_dep_a_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_baseline_heading_dep_a_t(msg) > len)
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
  u32 msgheading = htole32(msg->heading);
  memcpy(buf + offset, &msgheading, 4);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, &msgn_sats, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool
sbp_unpack_sbp_msg_baseline_heading_dep_a_t(const u8 *buf, size_t len, sbp_msg_baseline_heading_dep_a_t *msg)
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
  memcpy(&msg->heading, buf + offset, 4);
  msg->heading = le32toh(msg->heading);
  offset += 4;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.heading != b.heading)
  {
    return false;
  }

  if (a.n_sats != b.n_sats)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_baseline_heading_dep_a_t &a, const sbp_msg_baseline_heading_dep_a_t &b)
{
  return !(a == b);
}
#endif
/** Computed Position and Protection Level
 *
 * This message reports the local vertical and horizontal protection levels
 * associated with a given LLH position solution. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_PROTECTION_LEVEL 0x0216

#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK (0x7)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT (0u)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_GET(flags) \
  (((flags) >> SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT) & \
   SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_MASK)) \
                 << (SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SHIFT))); \
  } while (0)

#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_SAFE_STATE_PROTECTION_LEVEL_SHALL_NOT_BE_USED_FOR_SAFETY_CRITICAL_APPLICATION \
  (0)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_1 (1)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_2 (2)
#define SBP_PROTECTION_LEVEL_FLAGS_TARGET_INTEGRITY_RISK_TIR_LEVEL_TIR_LEVEL_3 (3)
typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * Vertical protection level[cm]
   */
  u16 vpl;
  /**
   * Horizontal protection level[cm]
   */
  u16 hpl;
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
  /**
   * Status flags
   */
  u8 flags;
} sbp_msg_protection_level_t;

static inline size_t sbp_packed_size_sbp_msg_protection_level_t(const sbp_msg_protection_level_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->vpl) + sizeof(msg->hpl) + sizeof(msg->lat) + sizeof(msg->lon) +
         sizeof(msg->height) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_protection_level_t(u8 *buf, size_t len, const sbp_msg_protection_level_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_protection_level_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgvpl = htole16(msg->vpl);
  memcpy(buf + offset, &msgvpl, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msghpl = htole16(msg->hpl);
  memcpy(buf + offset, &msghpl, 2);
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglat = msg->lat;
  memcpy(buf + offset, &msglat, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msglon = msg->lon;
  memcpy(buf + offset, &msglon, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  double msgheight = msg->height;
  memcpy(buf + offset, &msgheight, 8);
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, &msgflags, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_protection_level_t(const u8 *buf, size_t len, sbp_msg_protection_level_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->vpl, buf + offset, 2);
  msg->vpl = le16toh(msg->vpl);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->hpl, buf + offset, 2);
  msg->hpl = le16toh(msg->hpl);
  offset += 2;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lat, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->lon, buf + offset, 8);
  offset += 8;

  if (offset + 8 > len)
  {
    return false;
  }
  memcpy(&msg->height, buf + offset, 8);
  offset += 8;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.vpl != b.vpl)
  {
    return false;
  }

  if (a.hpl != b.hpl)
  {
    return false;
  }

  if (fabs(a.lat - b.lat) > 0.001)
  {
    return false;
  }

  if (fabs(a.lon - b.lon) > 0.001)
  {
    return false;
  }

  if (fabs(a.height - b.height) > 0.001)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_protection_level_t &a, const sbp_msg_protection_level_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_NAVIGATION_MESSAGES_H */