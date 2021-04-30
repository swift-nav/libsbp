#ifndef LIBSBP_SYSTEM_MESSAGES_H
#define LIBSBP_SYSTEM_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
/** System start-up message
 *
 * The system start-up message is sent once on system
 * start-up. It notifies the host or other attached devices that
 * the system has started and is now ready to respond to commands
 * or configuration requests.
 */
#define SBP_MSG_STARTUP 0xFF00

#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_MASK (0x1ff)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SHIFT (0u)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_GET(flags) \
  (((flags) >> SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SHIFT) & SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_MASK)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_MASK)) << (SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SHIFT))); \
  } while (0)

#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_POWER_ON (0)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_SOFTWARE_RESET (1)
#define SBP_STARTUP_CAUSE_CAUSE_OF_STARTUP_WATCHDOG_RESET (2)
#define SBP_STARTUP_STARTUP_TYPE__MASK (0x1ff)
#define SBP_STARTUP_STARTUP_TYPE__SHIFT (0u)
#define SBP_STARTUP_STARTUP_TYPE__GET(flags) \
  (((flags) >> SBP_STARTUP_STARTUP_TYPE__SHIFT) & SBP_STARTUP_STARTUP_TYPE__MASK)
#define SBP_STARTUP_STARTUP_TYPE__SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STARTUP_STARTUP_TYPE__MASK)) << (SBP_STARTUP_STARTUP_TYPE__SHIFT))); \
  } while (0)

#define SBP_STARTUP_STARTUP_TYPE__COLD_START (0)
#define SBP_STARTUP_STARTUP_TYPE__WARM_START (1)
#define SBP_STARTUP_STARTUP_TYPE__HOT_START (2)
typedef struct
{

  /**
   * Cause of startup
   */
  u8 cause;
  /**
   * Startup type
   */
  u8 startup_type;
  /**
   * Reserved
   */
  u16 reserved;
} sbp_msg_startup_t;

static inline size_t sbp_packed_size_sbp_msg_startup_t(const sbp_msg_startup_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->cause) + sizeof(msg->startup_type) + sizeof(msg->reserved);
}

static inline bool sbp_pack_sbp_msg_startup_t(u8 *buf, size_t len, const sbp_msg_startup_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_startup_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgcause = msg->cause;
  memcpy(buf + offset, &msgcause, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgstartup_type = msg->startup_type;
  memcpy(buf + offset, &msgstartup_type, 1);
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgreserved = htole16(msg->reserved);
  memcpy(buf + offset, &msgreserved, 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_startup_t(const u8 *buf, size_t len, sbp_msg_startup_t *msg)
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
  memcpy(&msg->cause, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->startup_type, buf + offset, 1);
  offset += 1;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->reserved, buf + offset, 2);
  msg->reserved = le16toh(msg->reserved);
  offset += 2;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b)
{
  (void)a;
  (void)b;

  if (a.cause != b.cause)
  {
    return false;
  }

  if (a.startup_type != b.startup_type)
  {
    return false;
  }

  if (a.reserved != b.reserved)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_startup_t &a, const sbp_msg_startup_t &b)
{
  return !(a == b);
}
#endif
/** Status of received corrections
 *
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet.
 */
#define SBP_MSG_DGNSS_STATUS 0xFF02

#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_MASK (0xf)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SHIFT (0u)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_GET(flags) \
  (((flags) >> SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SHIFT) & SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_MASK)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_MASK)) << (SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_SHIFT))); \
  } while (0)

#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_INVALID (0)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_CODE_DIFFERENCE (1)
#define SBP_DGNSS_STATUS_FLAGS_DIFFERENTIAL_TYPE_RTK (2)
typedef struct
{

  /**
   * Status flags
   */
  u8 flags;
  /**
   * Latency of observation receipt[deci-seconds]
   */
  u16 latency;
  /**
   * Number of signals from base station
   */
  u8 num_signals;
  /**
   * Corrections source string
   */
  char source[251];
} sbp_msg_dgnss_status_t;

static inline size_t sbp_packed_size_sbp_msg_dgnss_status_t(const sbp_msg_dgnss_status_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags) + sizeof(msg->latency) + sizeof(msg->num_signals) + sbp_strlen(msg->source, "none");
}

static inline bool sbp_pack_sbp_msg_dgnss_status_t(u8 *buf, size_t len, const sbp_msg_dgnss_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_dgnss_status_t(msg) > len)
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

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msglatency = htole16(msg->latency);
  memcpy(buf + offset, &msglatency, 2);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnum_signals = msg->num_signals;
  memcpy(buf + offset, &msgnum_signals, 1);
  offset += 1;
  if (offset + sbp_strlen(msg->source, "none") > len)
  {
    return false;
  }
  offset += sbp_pack_string(buf + offset, msg->source, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_dgnss_status_t(const u8 *buf, size_t len, sbp_msg_dgnss_status_t *msg)
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

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->latency, buf + offset, 2);
  msg->latency = le16toh(msg->latency);
  offset += 2;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->num_signals, buf + offset, 1);
  offset += 1;
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->source, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.latency != b.latency)
  {
    return false;
  }

  if (a.num_signals != b.num_signals)
  {
    return false;
  }
  if (sbp_strcmp(a.source, b.source, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_dgnss_status_t &a, const sbp_msg_dgnss_status_t &b)
{
  return !(a == b);
}
#endif
/** System heartbeat message
 *
 * The heartbeat message is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * used to monitor system malfunctions. It also contains status
 * flags that indicate to the host the status of the system and
 * whether it is operating correctly. Currently, the expected
 * heartbeat interval is 1 sec.
 *
 * The system error flag is used to indicate that an error has
 * occurred in the system. To determine the source of the error,
 * the remaining error flags should be inspected.
 */
#define SBP_MSG_HEARTBEAT 0xFFFF

#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SHIFT (31u)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SHIFT) & SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_MASK)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_NO_EXTERNAL_ANTENNA_DETECTED (0)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_PRESENT_EXTERNAL_ANTENNA_IS_PRESENT (1)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHIFT (30u)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHIFT) & SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_MASK)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_NO_SHORT_DETECTED (0)
#define SBP_HEARTBEAT_FLAGS_EXTERNAL_ANTENNA_SHORT_SHORT_DETECTED (1)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (16u)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_HEARTBEAT_FLAGS_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SHIFT (2u)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SHIFT) & SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_MASK)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_MASK)) << (SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_FLAGS_SWIFTNAP_ERROR_AN_ERROR_HAS_OCCURRED_IN_THE_SWIFTNAP (1)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_SHIFT (1u)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_IO_ERROR_SHIFT) & SBP_HEARTBEAT_FLAGS_IO_ERROR_MASK)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_HEARTBEAT_FLAGS_IO_ERROR_MASK)) << (SBP_HEARTBEAT_FLAGS_IO_ERROR_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_IO_ERROR_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_FLAGS_IO_ERROR_AN_IO_ERROR_HAS_OCCURRED (1)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_MASK (0x1)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SHIFT (0u)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_GET(flags) \
  (((flags) >> SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SHIFT) & SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_MASK)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_MASK)) << (SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SHIFT))); \
  } while (0)

#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_SYSTEM_HEALTHY (0)
#define SBP_HEARTBEAT_FLAGS_SYSTEM_ERROR_FLAG_AN_ERROR_HAS_OCCURRED (1)
typedef struct
{

  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_heartbeat_t;

static inline size_t sbp_packed_size_sbp_msg_heartbeat_t(const sbp_msg_heartbeat_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_heartbeat_t(u8 *buf, size_t len, const sbp_msg_heartbeat_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_heartbeat_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_heartbeat_t(const u8 *buf, size_t len, sbp_msg_heartbeat_t *msg)
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
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_heartbeat_t &a, const sbp_msg_heartbeat_t &b)
{
  return !(a == b);
}
#endif
/** Status report message
 *
 * The status report is sent periodically to inform the host
 * or other attached devices that the system is running. It is
 * used to monitor system malfunctions. It contains status
 * reports that indicate to the host the status of each sub-system and
 * whether it is operating correctly.
 *
 * Interpretation of the subsystem specific status code is product
 * dependent, but if the generic status code is initializing, it should
 * be ignored.  Refer to product documentation for details.
 */
#define SBP_MSG_STATUS_REPORT 0xFFFE

#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SHIFT) & SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_MASK)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_MASK)) \
                 << (SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_STARLING (0)
#define SBP_STATUS_REPORT_REPORTING_SYSTEM_SYSTEM_PRECISION_GNSS_MODULE (1)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK (0x1ff)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT (8u)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_STATUS_REPORT_SBP_VERSION_SBP_MAJOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK (0xff)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT (0u)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT) & \
   SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)
#define SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_MASK)) \
                 << (SBP_STATUS_REPORT_SBP_VERSION_SBP_MINOR_PROTOCOL_VERSION_NUMBER_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MASK (0xffff)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SHIFT (0u)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SHIFT) & SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MASK)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MASK)) \
                 << (SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_PRIMARY_GNSS_ANTENNA (0)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_MEASUREMENT_ENGINE (1)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_CORRECTIONS_CLIENT (2)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_DIFFERENTIAL_GNSS_ENGINE (3)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_CAN (4)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_WHEEL_ODOMETRY (5)
#define SBP_STATUS_REPORT_STATUS_COMPONENT_SUBSYSTEM_SENSOR_FUSION_ENGINE (6)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_MASK (0xff)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SHIFT (0u)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_GET(flags) \
  (((flags) >> SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SHIFT) & SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_MASK)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_MASK)) << (SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_SHIFT))); \
  } while (0)

#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_OKNOMINAL (0)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_INITIALIZING (1)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_UNKNOWN (2)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_DEGRADED (3)
#define SBP_STATUS_REPORT_STATUS_GENERIC_GENERIC_UNUSABLE (4)
typedef struct
{

  /**
   * Identity of reporting system
   */
  u16 reporting_system;
  /**
   * SBP protocol version
   */
  u16 sbp_version;
  /**
   * Increments on each status report sent
   */
  u32 sequence;
  /**
   * Number of seconds since system start-up
   */
  u32 uptime;
  /**
   * Reported status of individual subsystems
   */
  struct
  {

    /**
     * Identity of reporting subsystem
     */
    u16 component;
    /**
     * Generic form status report
     */
    u8 generic;
    /**
     * Subsystem specific status code
     */
    u8 specific;
  } status[60];
  /**
   * Number of items in status
   */
  u8 n_status;
} sbp_msg_status_report_t;

static inline size_t sbp_packed_size_sbp_msg_status_report_t(const sbp_msg_status_report_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->reporting_system) + sizeof(msg->sbp_version) + sizeof(msg->sequence) + sizeof(msg->uptime) +
         (msg->n_status *
          (0 + sizeof(msg->status[0].component) + sizeof(msg->status[0].generic) + sizeof(msg->status[0].specific)));
}

static inline bool sbp_pack_sbp_msg_status_report_t(u8 *buf, size_t len, const sbp_msg_status_report_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_status_report_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgreporting_system = htole16(msg->reporting_system);
  memcpy(buf + offset, &msgreporting_system, 2);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgsbp_version = htole16(msg->sbp_version);
  memcpy(buf + offset, &msgsbp_version, 2);
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgsequence = htole32(msg->sequence);
  memcpy(buf + offset, &msgsequence, 4);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msguptime = htole32(msg->uptime);
  memcpy(buf + offset, &msguptime, 4);
  offset += 4;
  for (size_t msgstatus_idx = 0; msgstatus_idx < (size_t)msg->n_status; msgstatus_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msgstatusmsgstatus_idxcomponent = htole16(msg->status[msgstatus_idx].component);
    memcpy(buf + offset, &msgstatusmsgstatus_idxcomponent, 2);
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatusmsgstatus_idxgeneric = msg->status[msgstatus_idx].generic;
    memcpy(buf + offset, &msgstatusmsgstatus_idxgeneric, 1);
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    u8 msgstatusmsgstatus_idxspecific = msg->status[msgstatus_idx].specific;
    memcpy(buf + offset, &msgstatusmsgstatus_idxspecific, 1);
    offset += 1;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_status_report_t(const u8 *buf, size_t len, sbp_msg_status_report_t *msg)
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
  memcpy(&msg->reporting_system, buf + offset, 2);
  msg->reporting_system = le16toh(msg->reporting_system);
  offset += 2;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->sbp_version, buf + offset, 2);
  msg->sbp_version = le16toh(msg->sbp_version);
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh(msg->sequence);
  offset += 4;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->uptime, buf + offset, 4);
  msg->uptime = le32toh(msg->uptime);
  offset += 4;
  msg->n_status = (u8)((len - offset) / 4);

  for (size_t msgstatus_idx = 0; msgstatus_idx < msg->n_status; msgstatus_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx].component, buf + offset, 2);
    msg->status[msgstatus_idx].component = le16toh(msg->status[msgstatus_idx].component);
    offset += 2;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx].generic, buf + offset, 1);
    offset += 1;

    if (offset + 1 > len)
    {
      return false;
    }
    memcpy(&msg->status[msgstatus_idx].specific, buf + offset, 1);
    offset += 1;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b)
{
  (void)a;
  (void)b;

  if (a.reporting_system != b.reporting_system)
  {
    return false;
  }

  if (a.sbp_version != b.sbp_version)
  {
    return false;
  }

  if (a.sequence != b.sequence)
  {
    return false;
  }

  if (a.uptime != b.uptime)
  {
    return false;
  }
  if (a.n_status != b.n_status)
  {
    return false;
  }
  for (size_t status_idx = 0; status_idx < (size_t)a.n_status; status_idx++)
  {

    if (a.status[status_idx].component != b.status[status_idx].component)
    {
      return false;
    }

    if (a.status[status_idx].generic != b.status[status_idx].generic)
    {
      return false;
    }

    if (a.status[status_idx].specific != b.status[status_idx].specific)
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_status_report_t &a, const sbp_msg_status_report_t &b)
{
  return !(a == b);
}
#endif
/** Inertial Navigation System status message
 *
 * The INS status message describes the state of the operation
 * and initialization of the inertial navigation system.
 */
#define SBP_MSG_INS_STATUS 0xFF03

#define SBP_INS_STATUS_FLAGS_INS_TYPE_MASK (0x7)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_SHIFT (29u)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_INS_TYPE_SHIFT) & SBP_INS_STATUS_FLAGS_INS_TYPE_MASK)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_INS_TYPE_MASK)) << (SBP_INS_STATUS_FLAGS_INS_TYPE_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_INS_TYPE_SMOOTHPOSE_LOOSELY_COUPLED (0)
#define SBP_INS_STATUS_FLAGS_INS_TYPE_STARLING (1)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_MASK (0x7)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_SHIFT (11u)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_MOTION_STATE_SHIFT) & SBP_INS_STATUS_FLAGS_MOTION_STATE_MASK)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_MOTION_STATE_MASK)) << (SBP_INS_STATUS_FLAGS_MOTION_STATE_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_MOTION_STATE_UNKNOWN_OR_INIT (0)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_ARBITRARY_MOTION (1)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_STRAIGHT_MOTION (2)
#define SBP_INS_STATUS_FLAGS_MOTION_STATE_STATIONARY (3)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_MASK (0x1)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SHIFT (10u)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SHIFT) & SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_MASK)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_MASK)) << (SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_NOMINAL (0)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_SYNCH_ODOMETRY_TIMESTAMP_OUT_OF_BOUNDS (1)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_MASK (0x3)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SHIFT (8u)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SHIFT) & SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_MASK)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_MASK)) << (SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_NO_ODOMETRY (0)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_ODOMETRY_RECEIVED_WITHIN_LAST_SECOND (1)
#define SBP_INS_STATUS_FLAGS_ODOMETRY_STATUS_ODOMETRY_NOT_RECEIVED_WITHIN_LAST_SECOND (2)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_MASK (0xf)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_SHIFT (4u)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_INS_ERROR_SHIFT) & SBP_INS_STATUS_FLAGS_INS_ERROR_MASK)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_INS_ERROR_MASK)) << (SBP_INS_STATUS_FLAGS_INS_ERROR_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_INS_ERROR_IMU_DATA_ERROR (1)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_INS_LICENSE_ERROR (2)
#define SBP_INS_STATUS_FLAGS_INS_ERROR_IMU_CALIBRATION_DATA_ERROR (3)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_MASK (0x1)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_SHIFT (3u)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_GNSS_FIX_SHIFT) & SBP_INS_STATUS_FLAGS_GNSS_FIX_MASK)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_GNSS_FIX_MASK)) << (SBP_INS_STATUS_FLAGS_GNSS_FIX_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_GNSS_FIX_NO_GNSS_FIX_AVAILABLE (0)
#define SBP_INS_STATUS_FLAGS_GNSS_FIX_GNSS_FIX (1)
#define SBP_INS_STATUS_FLAGS_MODE_MASK (0x7)
#define SBP_INS_STATUS_FLAGS_MODE_SHIFT (0u)
#define SBP_INS_STATUS_FLAGS_MODE_GET(flags) \
  (((flags) >> SBP_INS_STATUS_FLAGS_MODE_SHIFT) & SBP_INS_STATUS_FLAGS_MODE_MASK)
#define SBP_INS_STATUS_FLAGS_MODE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_STATUS_FLAGS_MODE_MASK)) << (SBP_INS_STATUS_FLAGS_MODE_SHIFT))); \
  } while (0)

#define SBP_INS_STATUS_FLAGS_MODE_AWAITING_INITIALIZATION (0)
#define SBP_INS_STATUS_FLAGS_MODE_DYNAMICALLY_ALIGNING (1)
#define SBP_INS_STATUS_FLAGS_MODE_READY (2)
#define SBP_INS_STATUS_FLAGS_MODE_GNSS_OUTAGE_EXCEEDS_MAX_DURATION (3)
#define SBP_INS_STATUS_FLAGS_MODE_FASTSTART_SEEDING (4)
#define SBP_INS_STATUS_FLAGS_MODE_FASTSTART_VALIDATING (5)
#define SBP_INS_STATUS_FLAGS_MODE_VALIDATING_UNSAFE_FAST_START_SEED (6)
typedef struct
{

  /**
   * Status flags
   */
  u32 flags;
} sbp_msg_ins_status_t;

static inline size_t sbp_packed_size_sbp_msg_ins_status_t(const sbp_msg_ins_status_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_ins_status_t(u8 *buf, size_t len, const sbp_msg_ins_status_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ins_status_t(msg) > len)
  {
    return false;
  }

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgflags = htole32(msg->flags);
  memcpy(buf + offset, &msgflags, 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_status_t(const u8 *buf, size_t len, sbp_msg_ins_status_t *msg)
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
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh(msg->flags);
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b)
{
  (void)a;
  (void)b;

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_ins_status_t &a, const sbp_msg_ins_status_t &b)
{
  return !(a == b);
}
#endif
/** Experimental telemetry message
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products.
 * It is intended to be a low rate message for status purposes.
 */
#define SBP_MSG_CSAC_TELEMETRY 0xFF04

typedef struct
{

  /**
   * Index representing the type of telemetry in use.  It is implemention defined.
   */
  u8 id;
  /**
   * Comma separated list of values as defined by the index
   */
  char telemetry[254];
} sbp_msg_csac_telemetry_t;

static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_t(const sbp_msg_csac_telemetry_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->id) + sbp_strlen(msg->telemetry, "none");
}

static inline bool sbp_pack_sbp_msg_csac_telemetry_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_csac_telemetry_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgid = msg->id;
  memcpy(buf + offset, &msgid, 1);
  offset += 1;
  if (offset + sbp_strlen(msg->telemetry, "none") > len)
  {
    return false;
  }
  offset += sbp_pack_string(buf + offset, msg->telemetry, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_csac_telemetry_t(const u8 *buf, size_t len, sbp_msg_csac_telemetry_t *msg)
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
  memcpy(&msg->id, buf + offset, 1);
  offset += 1;
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->telemetry, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b)
{
  (void)a;
  (void)b;

  if (a.id != b.id)
  {
    return false;
  }
  if (sbp_strcmp(a.telemetry, b.telemetry, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_t &a, const sbp_msg_csac_telemetry_t &b)
{
  return !(a == b);
}
#endif
/** Experimental telemetry message labels
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY.
 */
#define SBP_MSG_CSAC_TELEMETRY_LABELS 0xFF05

typedef struct
{

  /**
   * Index representing the type of telemetry in use.  It is implemention defined.
   */
  u8 id;
  /**
   * Comma separated list of telemetry field values
   */
  char telemetry_labels[254];
} sbp_msg_csac_telemetry_labels_t;

static inline size_t sbp_packed_size_sbp_msg_csac_telemetry_labels_t(const sbp_msg_csac_telemetry_labels_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->id) + sbp_strlen(msg->telemetry_labels, "none");
}

static inline bool
sbp_pack_sbp_msg_csac_telemetry_labels_t(u8 *buf, size_t len, const sbp_msg_csac_telemetry_labels_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_csac_telemetry_labels_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgid = msg->id;
  memcpy(buf + offset, &msgid, 1);
  offset += 1;
  if (offset + sbp_strlen(msg->telemetry_labels, "none") > len)
  {
    return false;
  }
  offset += sbp_pack_string(buf + offset, msg->telemetry_labels, "none");
  return true;
}

static inline bool
sbp_unpack_sbp_msg_csac_telemetry_labels_t(const u8 *buf, size_t len, sbp_msg_csac_telemetry_labels_t *msg)
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
  memcpy(&msg->id, buf + offset, 1);
  offset += 1;
  offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->telemetry_labels, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b)
{
  (void)a;
  (void)b;

  if (a.id != b.id)
  {
    return false;
  }
  if (sbp_strcmp(a.telemetry_labels, b.telemetry_labels, "none") != 0)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_csac_telemetry_labels_t &a, const sbp_msg_csac_telemetry_labels_t &b)
{
  return !(a == b);
}
#endif
/** Inertial Navigation System update status message
 *
 * The INS update status message contains informations about executed and rejected INS updates.
 * This message is expected to be extended in the future as new types of measurements are being added.
 */
#define SBP_MSG_INS_UPDATES 0xFF06

#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_ATTEMPTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSPOS_NUMBER_OF_REJECTED_GNSS_POSITION_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_ATTEMPTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_GNSSVEL_NUMBER_OF_REJECTED_GNSS_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_ATTEMPTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_WHEELTICKS_NUMBER_OF_REJECTED_WHEELTICK_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_SPEED_NUMBER_OF_ATTEMPTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_SPEED_NUMBER_OF_REJECTED_SPEED_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_NHC_NUMBER_OF_ATTEMPTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_NHC_NUMBER_OF_REJECTED_NHC_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (4u)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_ATTEMPTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK (0xf)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT (0u)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_GET(flags) \
  (((flags) >> SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT) & \
   SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)
#define SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SET(flags, val) \
  do \
  { \
    ((flags) |= (((val) & (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_MASK)) \
                 << (SBP_INS_UPDATES_ZEROVEL_NUMBER_OF_REJECTED_ZERO_VELOCITY_UPDATES_SINCE_LAST_MESSAGE_SHIFT))); \
  } while (0)

typedef struct
{

  /**
   * GPS Time of Week[ms]
   */
  u32 tow;
  /**
   * GNSS position update status flags
   */
  u8 gnsspos;
  /**
   * GNSS velocity update status flags
   */
  u8 gnssvel;
  /**
   * Wheelticks update status flags
   */
  u8 wheelticks;
  /**
   * Wheelticks update status flags
   */
  u8 speed;
  /**
   * NHC update status flags
   */
  u8 nhc;
  /**
   * Zero velocity update status flags
   */
  u8 zerovel;
} sbp_msg_ins_updates_t;

static inline size_t sbp_packed_size_sbp_msg_ins_updates_t(const sbp_msg_ins_updates_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->tow) + sizeof(msg->gnsspos) + sizeof(msg->gnssvel) + sizeof(msg->wheelticks) +
         sizeof(msg->speed) + sizeof(msg->nhc) + sizeof(msg->zerovel);
}

static inline bool sbp_pack_sbp_msg_ins_updates_t(u8 *buf, size_t len, const sbp_msg_ins_updates_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_ins_updates_t(msg) > len)
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

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggnsspos = msg->gnsspos;
  memcpy(buf + offset, &msggnsspos, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggnssvel = msg->gnssvel;
  memcpy(buf + offset, &msggnssvel, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgwheelticks = msg->wheelticks;
  memcpy(buf + offset, &msgwheelticks, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgspeed = msg->speed;
  memcpy(buf + offset, &msgspeed, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgnhc = msg->nhc;
  memcpy(buf + offset, &msgnhc, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msgzerovel = msg->zerovel;
  memcpy(buf + offset, &msgzerovel, 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_ins_updates_t(const u8 *buf, size_t len, sbp_msg_ins_updates_t *msg)
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

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->gnsspos, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->gnssvel, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->wheelticks, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->speed, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->nhc, buf + offset, 1);
  offset += 1;

  if (offset + 1 > len)
  {
    return false;
  }
  memcpy(&msg->zerovel, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b)
{
  (void)a;
  (void)b;

  if (a.tow != b.tow)
  {
    return false;
  }

  if (a.gnsspos != b.gnsspos)
  {
    return false;
  }

  if (a.gnssvel != b.gnssvel)
  {
    return false;
  }

  if (a.wheelticks != b.wheelticks)
  {
    return false;
  }

  if (a.speed != b.speed)
  {
    return false;
  }

  if (a.nhc != b.nhc)
  {
    return false;
  }

  if (a.zerovel != b.zerovel)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_ins_updates_t &a, const sbp_msg_ins_updates_t &b)
{
  return !(a == b);
}
#endif
/** Offset of the local time with respect to GNSS time
 *
 * The GNSS time offset message contains the information that is needed to translate messages
 * tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for the sender
 * producing this message.
 */
#define SBP_MSG_GNSS_TIME_OFFSET 0xFF07

typedef struct
{

  /**
   * Weeks portion of the time offset[weeks]
   */
  s16 weeks;
  /**
   * Milliseconds portion of the time offset[ms]
   */
  s32 milliseconds;
  /**
   * Microseconds portion of the time offset[microseconds]
   */
  s16 microseconds;
  /**
   * Status flags (reserved)
   */
  u8 flags;
} sbp_msg_gnss_time_offset_t;

static inline size_t sbp_packed_size_sbp_msg_gnss_time_offset_t(const sbp_msg_gnss_time_offset_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->weeks) + sizeof(msg->milliseconds) + sizeof(msg->microseconds) + sizeof(msg->flags);
}

static inline bool sbp_pack_sbp_msg_gnss_time_offset_t(u8 *buf, size_t len, const sbp_msg_gnss_time_offset_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_gnss_time_offset_t(msg) > len)
  {
    return false;
  }

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgweeks = htole16(*(const u16 *)&msg->weeks);
  memcpy(buf + offset, &msgweeks, 2);
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  u32 msgmilliseconds = htole32(*(const u32 *)&msg->milliseconds);
  memcpy(buf + offset, &msgmilliseconds, 4);
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  u16 msgmicroseconds = htole16(*(const u16 *)&msg->microseconds);
  memcpy(buf + offset, &msgmicroseconds, 2);
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

static inline bool sbp_unpack_sbp_msg_gnss_time_offset_t(const u8 *buf, size_t len, sbp_msg_gnss_time_offset_t *msg)
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
  memcpy(&msg->weeks, buf + offset, 2);
  u16 msgweeks = *(const u16 *)&msg->weeks;
  msgweeks = le16toh(msgweeks);
  msg->weeks = *(const s16 *)&msgweeks;
  offset += 2;

  if (offset + 4 > len)
  {
    return false;
  }
  memcpy(&msg->milliseconds, buf + offset, 4);
  u32 msgmilliseconds = *(const u32 *)&msg->milliseconds;
  msgmilliseconds = le32toh(msgmilliseconds);
  msg->milliseconds = *(const s32 *)&msgmilliseconds;
  offset += 4;

  if (offset + 2 > len)
  {
    return false;
  }
  memcpy(&msg->microseconds, buf + offset, 2);
  u16 msgmicroseconds = *(const u16 *)&msg->microseconds;
  msgmicroseconds = le16toh(msgmicroseconds);
  msg->microseconds = *(const s16 *)&msgmicroseconds;
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
static inline bool operator==(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b)
{
  (void)a;
  (void)b;

  if (a.weeks != b.weeks)
  {
    return false;
  }

  if (a.milliseconds != b.milliseconds)
  {
    return false;
  }

  if (a.microseconds != b.microseconds)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  return true;
}

static inline bool operator!=(const sbp_msg_gnss_time_offset_t &a, const sbp_msg_gnss_time_offset_t &b)
{
  return !(a == b);
}
#endif
/** Solution Group Metadata
 *
 * This leading message lists the time metadata of the Solution Group.
 * It also lists the atomic contents (i.e. types of messages included) of the Solution Group.
 */
#define SBP_MSG_GROUP_META 0xFF0A

#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_MASK (0x3)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SHIFT (0u)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_GET(flags) \
  (((flags) >> SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SHIFT) & SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_MASK)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SET(flags, val) \
  do \
  { \
    ((flags) |= \
     (((val) & (SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_MASK)) << (SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_SHIFT))); \
  } while (0)

#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_NONE (0)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_GNSS_ONLY (1)
#define SBP_GROUP_META_FLAGS_SOLUTION_GROUP_TYPE_GNSSINS (2)
typedef struct
{

  /**
   * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
   */
  u8 group_id;
  /**
   * Status flags (reserved)
   */
  u8 flags;
  /**
   * Size of list group_msgs
   */
  u8 n_group_msgs;
  /**
   * An inorder list of message types included in the Solution Group,
   * including GROUP_META itself
   */
  u16 group_msgs[126];
} sbp_msg_group_meta_t;

static inline size_t sbp_packed_size_sbp_msg_group_meta_t(const sbp_msg_group_meta_t *msg)
{
  (void)msg;
  return 0 + sizeof(msg->group_id) + sizeof(msg->flags) + sizeof(msg->n_group_msgs) +
         (msg->n_group_msgs * sizeof(msg->group_msgs[0]));
}

static inline bool sbp_pack_sbp_msg_group_meta_t(u8 *buf, size_t len, const sbp_msg_group_meta_t *msg)
{
  size_t offset = 0;
  (void)offset;
  (void)buf;
  (void)len;
  (void)msg;
  if (sbp_packed_size_sbp_msg_group_meta_t(msg) > len)
  {
    return false;
  }

  if (offset + 1 > len)
  {
    return false;
  }
  u8 msggroup_id = msg->group_id;
  memcpy(buf + offset, &msggroup_id, 1);
  offset += 1;

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
  u8 msgn_group_msgs = msg->n_group_msgs;
  memcpy(buf + offset, &msgn_group_msgs, 1);
  offset += 1;
  for (size_t msggroup_msgs_idx = 0; msggroup_msgs_idx < (size_t)msg->n_group_msgs; msggroup_msgs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    u16 msggroup_msgsmsggroup_msgs_idx = htole16(msg->group_msgs[msggroup_msgs_idx]);
    memcpy(buf + offset, &msggroup_msgsmsggroup_msgs_idx, 2);
    offset += 2;
  }
  return true;
}

static inline bool sbp_unpack_sbp_msg_group_meta_t(const u8 *buf, size_t len, sbp_msg_group_meta_t *msg)
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
  memcpy(&msg->group_id, buf + offset, 1);
  offset += 1;

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
  memcpy(&msg->n_group_msgs, buf + offset, 1);
  offset += 1;

  for (size_t msggroup_msgs_idx = 0; msggroup_msgs_idx < msg->n_group_msgs; msggroup_msgs_idx++)
  {

    if (offset + 2 > len)
    {
      return false;
    }
    memcpy(&msg->group_msgs[msggroup_msgs_idx], buf + offset, 2);
    msg->group_msgs[msggroup_msgs_idx] = le16toh(msg->group_msgs[msggroup_msgs_idx]);
    offset += 2;
  }
  return true;
}

#ifdef __cplusplus
static inline bool operator==(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b)
{
  (void)a;
  (void)b;

  if (a.group_id != b.group_id)
  {
    return false;
  }

  if (a.flags != b.flags)
  {
    return false;
  }

  if (a.n_group_msgs != b.n_group_msgs)
  {
    return false;
  }
  if (a.n_group_msgs != b.n_group_msgs)
  {
    return false;
  }
  for (size_t group_msgs_idx = 0; group_msgs_idx < (size_t)a.n_group_msgs; group_msgs_idx++)
  {

    if (a.group_msgs[group_msgs_idx] != b.group_msgs[group_msgs_idx])
    {
      return false;
    }
  }

  return true;
}

static inline bool operator!=(const sbp_msg_group_meta_t &a, const sbp_msg_group_meta_t &b)
{
  return !(a == b);
}
#endif

#endif /* LIBSBP_SYSTEM_MESSAGES_H */