#ifndef LIBSBP_PIKSI_MESSAGES_H
#define LIBSBP_PIKSI_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/gnss.h>
  /** Legacy message to load satellite almanac (host => Piksi)
   *
 * This is a legacy message for sending and loading a satellite
 * alamanac onto the Piksi's flash memory from the host.
   */
#define SBP_MSG_ALMANAC                 0x0069

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_almanac_t;

static inline size_t sbp_packed_size_sbp_msg_almanac_t(const sbp_msg_almanac_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_almanac_t(u8 *buf, size_t len, const sbp_msg_almanac_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_almanac_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_almanac_t(const u8 *buf, size_t len, sbp_msg_almanac_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_almanac_t &a, const sbp_msg_almanac_t &b) {
  return !(a == b);
}
#endif
  /** Send GPS time from host (host => Piksi)
   *
 * This message sets up timing functionality using a coarse GPS
 * time estimate sent by the host.
   */
#define SBP_MSG_SET_TIME                0x0068

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_set_time_t;

static inline size_t sbp_packed_size_sbp_msg_set_time_t(const sbp_msg_set_time_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_set_time_t(u8 *buf, size_t len, const sbp_msg_set_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_set_time_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_set_time_t(const u8 *buf, size_t len, sbp_msg_set_time_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_set_time_t &a, const sbp_msg_set_time_t &b) {
  return !(a == b);
}
#endif
  /** Reset the device (host => Piksi)
   *
 * This message from the host resets the Piksi back into the
 * bootloader.
   */
#define SBP_MSG_RESET                   0x00B6

	#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_MASK (0x1)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_SHIFT (0u)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_GET(flags) \
                             (((flags) >> SBP_RESET_FLAGS_DEFAULT_SETTINGS_SHIFT) \
                             & SBP_RESET_FLAGS_DEFAULT_SETTINGS_MASK)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_RESET_FLAGS_DEFAULT_SETTINGS_MASK)) \
                             << (SBP_RESET_FLAGS_DEFAULT_SETTINGS_SHIFT)));} while(0)
                             

#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_PRESERVE_EXISTING_SETTINGS (0)
#define SBP_RESET_FLAGS_DEFAULT_SETTINGS_RESORE_DEFAULT_SETTINGS (1)
typedef struct {
  
  /**
* Reset flags
   */
    u32
  flags
  ;
} sbp_msg_reset_t;

static inline size_t sbp_packed_size_sbp_msg_reset_t(const sbp_msg_reset_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_reset_t(u8 *buf, size_t len, const sbp_msg_reset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgflags = htole32( msg->flags );
  memcpy(buf + offset, & msgflags , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_t(const u8 *buf, size_t len, sbp_msg_reset_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh( msg->flags );
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_reset_t &a, const sbp_msg_reset_t &b) {
  return !(a == b);
}
#endif
  /** Reset the device (host => Piksi)
   *
 * This message from the host resets the Piksi back into the
 * bootloader.
   */
#define SBP_MSG_RESET_DEP               0x00B2

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_reset_dep_t;

static inline size_t sbp_packed_size_sbp_msg_reset_dep_t(const sbp_msg_reset_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_reset_dep_t(u8 *buf, size_t len, const sbp_msg_reset_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_dep_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_dep_t(const u8 *buf, size_t len, sbp_msg_reset_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_reset_dep_t &a, const sbp_msg_reset_dep_t &b) {
  return !(a == b);
}
#endif
  /** Legacy message for CW interference channel (Piksi => host)
   *
 * This is an unused legacy message for result reporting from the
 * CW interference channel on the SwiftNAP. This message will be
 * removed in a future release.
   */
#define SBP_MSG_CW_RESULTS              0x00C0

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_cw_results_t;

static inline size_t sbp_packed_size_sbp_msg_cw_results_t(const sbp_msg_cw_results_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_cw_results_t(u8 *buf, size_t len, const sbp_msg_cw_results_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cw_results_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_results_t(const u8 *buf, size_t len, sbp_msg_cw_results_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_cw_results_t &a, const sbp_msg_cw_results_t &b) {
  return !(a == b);
}
#endif
  /** Legacy message for CW interference channel (host => Piksi)
   *
 * This is an unused legacy message from the host for starting
 * the CW interference channel on the SwiftNAP. This message will
 * be removed in a future release.
   */
#define SBP_MSG_CW_START                0x00C1

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_cw_start_t;

static inline size_t sbp_packed_size_sbp_msg_cw_start_t(const sbp_msg_cw_start_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_cw_start_t(u8 *buf, size_t len, const sbp_msg_cw_start_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cw_start_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_cw_start_t(const u8 *buf, size_t len, sbp_msg_cw_start_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_cw_start_t &a, const sbp_msg_cw_start_t &b) {
  return !(a == b);
}
#endif
  /** Reset IAR filters (host => Piksi)
   *
 * This message resets either the DGNSS Kalman filters or Integer
 * Ambiguity Resolution (IAR) process.
   */
#define SBP_MSG_RESET_FILTERS           0x0022

	#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_MASK (0x3)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SHIFT (0u)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_GET(flags) \
                             (((flags) >> SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SHIFT) \
                             & SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_MASK)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_MASK)) \
                             << (SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_SHIFT)));} while(0)
                             

#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_DGNSS_FILTER (0)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_IAR_PROCESS (1)
#define SBP_RESET_FILTERS_FILTER_FILTER_OR_PROCESS_TO_RESET_INERTIAL_FILTER (2)
typedef struct {
  
  /**
* Filter flags
   */
    u8
  filter
  ;
} sbp_msg_reset_filters_t;

static inline size_t sbp_packed_size_sbp_msg_reset_filters_t(const sbp_msg_reset_filters_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->filter );
}

static inline bool sbp_pack_sbp_msg_reset_filters_t(u8 *buf, size_t len, const sbp_msg_reset_filters_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_reset_filters_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  u8 msgfilter = msg->filter;
  memcpy(buf + offset, & msgfilter , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_reset_filters_t(const u8 *buf, size_t len, sbp_msg_reset_filters_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->filter, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.filter != b.filter) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_reset_filters_t &a, const sbp_msg_reset_filters_t &b) {
  return !(a == b);
}
#endif
  /** Deprecated
   *
* Deprecated
   */
#define SBP_MSG_INIT_BASE_DEP           0x0023

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_init_base_dep_t;

static inline size_t sbp_packed_size_sbp_msg_init_base_dep_t(const sbp_msg_init_base_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_init_base_dep_t(u8 *buf, size_t len, const sbp_msg_init_base_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_init_base_dep_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_init_base_dep_t(const u8 *buf, size_t len, sbp_msg_init_base_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_init_base_dep_t &a, const sbp_msg_init_base_dep_t &b) {
  return !(a == b);
}
#endif
  /** State of an RTOS thread
   *
 * The thread usage message from the device reports real-time
 * operating system (RTOS) thread usage statistics for the named
 * thread. The reported percentage values must be normalized.
   */
#define SBP_MSG_THREAD_STATE            0x0017

typedef struct {
  
  /**
* Thread name (NULL terminated)
   */
    char
  name
    [20]
  ;
  /**
 * Percentage cpu use for this thread. Values range from 0
 * - 1000 and needs to be renormalized to 100
   */
    u16
  cpu
  ;
  /**
* Free stack space for this thread[bytes]
   */
    u32
  stack_free
  ;
} sbp_msg_thread_state_t;

static inline size_t sbp_packed_size_sbp_msg_thread_state_t(const sbp_msg_thread_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 20 *
        sizeof( msg->name[0] )
		)                                                                          
	  +
				sizeof( msg->cpu )                                                                          
	  +
				sizeof( msg->stack_free );
}

static inline bool sbp_pack_sbp_msg_thread_state_t(u8 *buf, size_t len, const sbp_msg_thread_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_thread_state_t(msg) > len) { return false; }
  
		  for(size_t msgname_idx = 0; msgname_idx < 20; msgname_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  char msgnamemsgname_idx = msg->name[msgname_idx];
  memcpy(buf + offset, & msgnamemsgname_idx , 1);
  offset += 1;
			}
        
  if (offset + 2 > len) { return false; }
  u16 msgcpu = htole16( msg->cpu );
  memcpy(buf + offset, & msgcpu , 2);
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgstack_free = htole32( msg->stack_free );
  memcpy(buf + offset, & msgstack_free , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_thread_state_t(const u8 *buf, size_t len, sbp_msg_thread_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgname_idx = 0; msgname_idx < 20; msgname_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->name[msgname_idx], buf + offset, 1);
  offset += 1;
		}
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->cpu, buf + offset, 2);
  msg->cpu = le16toh( msg->cpu );
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->stack_free, buf + offset, 4);
  msg->stack_free = le32toh( msg->stack_free );
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  (void)a;
  (void)b;
  
        for (size_t name_idx = 0; name_idx < 20; name_idx++)
        {
            
    if (a.name[name_idx] != b.name[name_idx]) { return false; }
        }
        
    if (a.cpu != b.cpu) { return false; }
        
    if (a.stack_free != b.stack_free) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_thread_state_t &a, const sbp_msg_thread_state_t &b) {
  return !(a == b);
}
#endif
  /** State of the UART channels
   *
 * The UART message reports data latency and throughput of the UART
 * channels providing SBP I/O. On the default Piksi configuration,
 * UARTs A and B are used for telemetry radios, but can also be
 * host access ports for embedded hosts, or other interfaces in
 * future. The reported percentage values must be normalized.
 * Observations latency and period can be used to assess the
 * health of the differential corrections link. Latency provides
 * the timeliness of received base observations while the
 * period indicates their likelihood of transmission.
   */
#define SBP_MSG_UART_STATE              0x001D

	
	
	
	
	
typedef struct {
  
  /**
* State of UART A
   */
  struct {
    
  /**
* UART transmit throughput[kB/s]
   */
    float
  tx_throughput
  ;
  /**
* UART receive throughput[kB/s]
   */
    float
  rx_throughput
  ;
  /**
* UART CRC error count
   */
    u16
  crc_error_count
  ;
  /**
* UART IO error count
   */
    u16
  io_error_count
  ;
  /**
 * UART transmit buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  tx_buffer_level
  ;
  /**
 * UART receive buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  rx_buffer_level
  ;
  }
  uart_a
  ;
  /**
* State of UART B
   */
  struct {
    
  /**
* UART transmit throughput[kB/s]
   */
    float
  tx_throughput
  ;
  /**
* UART receive throughput[kB/s]
   */
    float
  rx_throughput
  ;
  /**
* UART CRC error count
   */
    u16
  crc_error_count
  ;
  /**
* UART IO error count
   */
    u16
  io_error_count
  ;
  /**
 * UART transmit buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  tx_buffer_level
  ;
  /**
 * UART receive buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  rx_buffer_level
  ;
  }
  uart_b
  ;
  /**
* State of UART FTDI (USB logger)
   */
  struct {
    
  /**
* UART transmit throughput[kB/s]
   */
    float
  tx_throughput
  ;
  /**
* UART receive throughput[kB/s]
   */
    float
  rx_throughput
  ;
  /**
* UART CRC error count
   */
    u16
  crc_error_count
  ;
  /**
* UART IO error count
   */
    u16
  io_error_count
  ;
  /**
 * UART transmit buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  tx_buffer_level
  ;
  /**
 * UART receive buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  rx_buffer_level
  ;
  }
  uart_ftdi
  ;
  /**
* UART communication latency
   */
  struct {
    
  /**
* Average latency[ms]
   */
    s32
  avg
  ;
  /**
* Minimum latency[ms]
   */
    s32
  lmin
  ;
  /**
* Maximum latency[ms]
   */
    s32
  lmax
  ;
  /**
* Smoothed estimate of the current latency[ms]
   */
    s32
  current
  ;
  }
  latency
  ;
  /**
* Observation receipt period
   */
  struct {
    
  /**
* Average period[ms]
   */
    s32
  avg
  ;
  /**
* Minimum period[ms]
   */
    s32
  pmin
  ;
  /**
* Maximum period[ms]
   */
    s32
  pmax
  ;
  /**
* Smoothed estimate of the current period[ms]
   */
    s32
  current
  ;
  }
  obs_period
  ;
} sbp_msg_uart_state_t;

static inline size_t sbp_packed_size_sbp_msg_uart_state_t(const sbp_msg_uart_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_a.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_a.io_error_count )                                                                          
	  +
				sizeof( msg->uart_a.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_a.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_b.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_b.io_error_count )                                                                          
	  +
				sizeof( msg->uart_b.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_b.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.io_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->latency.avg )                                                                          
	  +
				sizeof( msg->latency.lmin )                                                                          
	  +
				sizeof( msg->latency.lmax )                                                                          
	  +
				sizeof( msg->latency.current ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->obs_period.avg )                                                                          
	  +
				sizeof( msg->obs_period.pmin )                                                                          
	  +
				sizeof( msg->obs_period.pmax )                                                                          
	  +
				sizeof( msg->obs_period.current ) );
}

static inline bool sbp_pack_sbp_msg_uart_state_t(u8 *buf, size_t len, const sbp_msg_uart_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_uart_state_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  float msguart_atx_throughput = msg->uart_a.tx_throughput;
  memcpy(buf + offset, & msguart_atx_throughput , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msguart_arx_throughput = msg->uart_a.rx_throughput;
  memcpy(buf + offset, & msguart_arx_throughput , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_acrc_error_count = htole16( msg->uart_a.crc_error_count );
  memcpy(buf + offset, & msguart_acrc_error_count , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_aio_error_count = htole16( msg->uart_a.io_error_count );
  memcpy(buf + offset, & msguart_aio_error_count , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_atx_buffer_level = msg->uart_a.tx_buffer_level;
  memcpy(buf + offset, & msguart_atx_buffer_level , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_arx_buffer_level = msg->uart_a.rx_buffer_level;
  memcpy(buf + offset, & msguart_arx_buffer_level , 1);
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  float msguart_btx_throughput = msg->uart_b.tx_throughput;
  memcpy(buf + offset, & msguart_btx_throughput , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msguart_brx_throughput = msg->uart_b.rx_throughput;
  memcpy(buf + offset, & msguart_brx_throughput , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_bcrc_error_count = htole16( msg->uart_b.crc_error_count );
  memcpy(buf + offset, & msguart_bcrc_error_count , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_bio_error_count = htole16( msg->uart_b.io_error_count );
  memcpy(buf + offset, & msguart_bio_error_count , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_btx_buffer_level = msg->uart_b.tx_buffer_level;
  memcpy(buf + offset, & msguart_btx_buffer_level , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_brx_buffer_level = msg->uart_b.rx_buffer_level;
  memcpy(buf + offset, & msguart_brx_buffer_level , 1);
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  float msguart_ftditx_throughput = msg->uart_ftdi.tx_throughput;
  memcpy(buf + offset, & msguart_ftditx_throughput , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msguart_ftdirx_throughput = msg->uart_ftdi.rx_throughput;
  memcpy(buf + offset, & msguart_ftdirx_throughput , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_ftdicrc_error_count = htole16( msg->uart_ftdi.crc_error_count );
  memcpy(buf + offset, & msguart_ftdicrc_error_count , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_ftdiio_error_count = htole16( msg->uart_ftdi.io_error_count );
  memcpy(buf + offset, & msguart_ftdiio_error_count , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_ftditx_buffer_level = msg->uart_ftdi.tx_buffer_level;
  memcpy(buf + offset, & msguart_ftditx_buffer_level , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_ftdirx_buffer_level = msg->uart_ftdi.rx_buffer_level;
  memcpy(buf + offset, & msguart_ftdirx_buffer_level , 1);
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  u32 msglatencyavg = htole32( *(const u32*)&msg->latency.avg );
  memcpy(buf + offset, & msglatencyavg , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglatencylmin = htole32( *(const u32*)&msg->latency.lmin );
  memcpy(buf + offset, & msglatencylmin , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglatencylmax = htole32( *(const u32*)&msg->latency.lmax );
  memcpy(buf + offset, & msglatencylmax , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglatencycurrent = htole32( *(const u32*)&msg->latency.current );
  memcpy(buf + offset, & msglatencycurrent , 4);
  offset += 4;
				
        
  if (offset + 4 > len) { return false; }
  u32 msgobs_periodavg = htole32( *(const u32*)&msg->obs_period.avg );
  memcpy(buf + offset, & msgobs_periodavg , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgobs_periodpmin = htole32( *(const u32*)&msg->obs_period.pmin );
  memcpy(buf + offset, & msgobs_periodpmin , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgobs_periodpmax = htole32( *(const u32*)&msg->obs_period.pmax );
  memcpy(buf + offset, & msgobs_periodpmax , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgobs_periodcurrent = htole32( *(const u32*)&msg->obs_period.current );
  memcpy(buf + offset, & msgobs_periodcurrent , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_t(const u8 *buf, size_t len, sbp_msg_uart_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.tx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.rx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_a.crc_error_count, buf + offset, 2);
  msg->uart_a.crc_error_count = le16toh( msg->uart_a.crc_error_count );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_a.io_error_count, buf + offset, 2);
  msg->uart_a.io_error_count = le16toh( msg->uart_a.io_error_count );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.tx_buffer_level, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.rx_buffer_level, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.tx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.rx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_b.crc_error_count, buf + offset, 2);
  msg->uart_b.crc_error_count = le16toh( msg->uart_b.crc_error_count );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_b.io_error_count, buf + offset, 2);
  msg->uart_b.io_error_count = le16toh( msg->uart_b.io_error_count );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.tx_buffer_level, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.rx_buffer_level, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_ftdi.crc_error_count, buf + offset, 2);
  msg->uart_ftdi.crc_error_count = le16toh( msg->uart_ftdi.crc_error_count );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_ftdi.io_error_count, buf + offset, 2);
  msg->uart_ftdi.io_error_count = le16toh( msg->uart_ftdi.io_error_count );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_buffer_level, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_buffer_level, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.avg, buf + offset, 4);
  u32 msglatencyavg = *(const u32*)&msg->latency.avg;
  msglatencyavg = le32toh( msglatencyavg );
  msg->latency.avg = *(const s32*)&msglatencyavg;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.lmin, buf + offset, 4);
  u32 msglatencylmin = *(const u32*)&msg->latency.lmin;
  msglatencylmin = le32toh( msglatencylmin );
  msg->latency.lmin = *(const s32*)&msglatencylmin;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.lmax, buf + offset, 4);
  u32 msglatencylmax = *(const u32*)&msg->latency.lmax;
  msglatencylmax = le32toh( msglatencylmax );
  msg->latency.lmax = *(const s32*)&msglatencylmax;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.current, buf + offset, 4);
  u32 msglatencycurrent = *(const u32*)&msg->latency.current;
  msglatencycurrent = le32toh( msglatencycurrent );
  msg->latency.current = *(const s32*)&msglatencycurrent;
  offset += 4;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->obs_period.avg, buf + offset, 4);
  u32 msgobs_periodavg = *(const u32*)&msg->obs_period.avg;
  msgobs_periodavg = le32toh( msgobs_periodavg );
  msg->obs_period.avg = *(const s32*)&msgobs_periodavg;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->obs_period.pmin, buf + offset, 4);
  u32 msgobs_periodpmin = *(const u32*)&msg->obs_period.pmin;
  msgobs_periodpmin = le32toh( msgobs_periodpmin );
  msg->obs_period.pmin = *(const s32*)&msgobs_periodpmin;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->obs_period.pmax, buf + offset, 4);
  u32 msgobs_periodpmax = *(const u32*)&msg->obs_period.pmax;
  msgobs_periodpmax = le32toh( msgobs_periodpmax );
  msg->obs_period.pmax = *(const s32*)&msgobs_periodpmax;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->obs_period.current, buf + offset, 4);
  u32 msgobs_periodcurrent = *(const u32*)&msg->obs_period.current;
  msgobs_periodcurrent = le32toh( msgobs_periodcurrent );
  msg->obs_period.current = *(const s32*)&msgobs_periodcurrent;
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (fabs( a.uart_a.tx_throughput - b.uart_a.tx_throughput ) > 0.001) { return false; }
        
    if (fabs( a.uart_a.rx_throughput - b.uart_a.rx_throughput ) > 0.001) { return false; }
        
    if (a.uart_a.crc_error_count != b.uart_a.crc_error_count) { return false; }
        
    if (a.uart_a.io_error_count != b.uart_a.io_error_count) { return false; }
        
    if (a.uart_a.tx_buffer_level != b.uart_a.tx_buffer_level) { return false; }
        
    if (a.uart_a.rx_buffer_level != b.uart_a.rx_buffer_level) { return false; }
        
        
    if (fabs( a.uart_b.tx_throughput - b.uart_b.tx_throughput ) > 0.001) { return false; }
        
    if (fabs( a.uart_b.rx_throughput - b.uart_b.rx_throughput ) > 0.001) { return false; }
        
    if (a.uart_b.crc_error_count != b.uart_b.crc_error_count) { return false; }
        
    if (a.uart_b.io_error_count != b.uart_b.io_error_count) { return false; }
        
    if (a.uart_b.tx_buffer_level != b.uart_b.tx_buffer_level) { return false; }
        
    if (a.uart_b.rx_buffer_level != b.uart_b.rx_buffer_level) { return false; }
        
        
    if (fabs( a.uart_ftdi.tx_throughput - b.uart_ftdi.tx_throughput ) > 0.001) { return false; }
        
    if (fabs( a.uart_ftdi.rx_throughput - b.uart_ftdi.rx_throughput ) > 0.001) { return false; }
        
    if (a.uart_ftdi.crc_error_count != b.uart_ftdi.crc_error_count) { return false; }
        
    if (a.uart_ftdi.io_error_count != b.uart_ftdi.io_error_count) { return false; }
        
    if (a.uart_ftdi.tx_buffer_level != b.uart_ftdi.tx_buffer_level) { return false; }
        
    if (a.uart_ftdi.rx_buffer_level != b.uart_ftdi.rx_buffer_level) { return false; }
        
        
    if (a.latency.avg != b.latency.avg) { return false; }
        
    if (a.latency.lmin != b.latency.lmin) { return false; }
        
    if (a.latency.lmax != b.latency.lmax) { return false; }
        
    if (a.latency.current != b.latency.current) { return false; }
        
        
    if (a.obs_period.avg != b.obs_period.avg) { return false; }
        
    if (a.obs_period.pmin != b.obs_period.pmin) { return false; }
        
    if (a.obs_period.pmax != b.obs_period.pmax) { return false; }
        
    if (a.obs_period.current != b.obs_period.current) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_uart_state_t &a, const sbp_msg_uart_state_t &b) {
  return !(a == b);
}
#endif
  /** Deprecated
   *
* Deprecated
   */
#define SBP_MSG_UART_STATE_DEPA         0x0018

	
	
	
	
typedef struct {
  
  /**
* State of UART A
   */
  struct {
    
  /**
* UART transmit throughput[kB/s]
   */
    float
  tx_throughput
  ;
  /**
* UART receive throughput[kB/s]
   */
    float
  rx_throughput
  ;
  /**
* UART CRC error count
   */
    u16
  crc_error_count
  ;
  /**
* UART IO error count
   */
    u16
  io_error_count
  ;
  /**
 * UART transmit buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  tx_buffer_level
  ;
  /**
 * UART receive buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  rx_buffer_level
  ;
  }
  uart_a
  ;
  /**
* State of UART B
   */
  struct {
    
  /**
* UART transmit throughput[kB/s]
   */
    float
  tx_throughput
  ;
  /**
* UART receive throughput[kB/s]
   */
    float
  rx_throughput
  ;
  /**
* UART CRC error count
   */
    u16
  crc_error_count
  ;
  /**
* UART IO error count
   */
    u16
  io_error_count
  ;
  /**
 * UART transmit buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  tx_buffer_level
  ;
  /**
 * UART receive buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  rx_buffer_level
  ;
  }
  uart_b
  ;
  /**
* State of UART FTDI (USB logger)
   */
  struct {
    
  /**
* UART transmit throughput[kB/s]
   */
    float
  tx_throughput
  ;
  /**
* UART receive throughput[kB/s]
   */
    float
  rx_throughput
  ;
  /**
* UART CRC error count
   */
    u16
  crc_error_count
  ;
  /**
* UART IO error count
   */
    u16
  io_error_count
  ;
  /**
 * UART transmit buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  tx_buffer_level
  ;
  /**
 * UART receive buffer percentage utilization (ranges from
 * 0 to 255)
   */
    u8
  rx_buffer_level
  ;
  }
  uart_ftdi
  ;
  /**
* UART communication latency
   */
  struct {
    
  /**
* Average latency[ms]
   */
    s32
  avg
  ;
  /**
* Minimum latency[ms]
   */
    s32
  lmin
  ;
  /**
* Maximum latency[ms]
   */
    s32
  lmax
  ;
  /**
* Smoothed estimate of the current latency[ms]
   */
    s32
  current
  ;
  }
  latency
  ;
} sbp_msg_uart_state_depa_t;

static inline size_t sbp_packed_size_sbp_msg_uart_state_depa_t(const sbp_msg_uart_state_depa_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_a.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_a.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_a.io_error_count )                                                                          
	  +
				sizeof( msg->uart_a.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_a.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_b.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_b.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_b.io_error_count )                                                                          
	  +
				sizeof( msg->uart_b.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_b.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_throughput )                                                                          
	  +
				sizeof( msg->uart_ftdi.crc_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.io_error_count )                                                                          
	  +
				sizeof( msg->uart_ftdi.tx_buffer_level )                                                                          
	  +
				sizeof( msg->uart_ftdi.rx_buffer_level ) )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->latency.avg )                                                                          
	  +
				sizeof( msg->latency.lmin )                                                                          
	  +
				sizeof( msg->latency.lmax )                                                                          
	  +
				sizeof( msg->latency.current ) );
}

static inline bool sbp_pack_sbp_msg_uart_state_depa_t(u8 *buf, size_t len, const sbp_msg_uart_state_depa_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_uart_state_depa_t(msg) > len) { return false; }
  
				
        
  if (offset + 4 > len) { return false; }
  float msguart_atx_throughput = msg->uart_a.tx_throughput;
  memcpy(buf + offset, & msguart_atx_throughput , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msguart_arx_throughput = msg->uart_a.rx_throughput;
  memcpy(buf + offset, & msguart_arx_throughput , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_acrc_error_count = htole16( msg->uart_a.crc_error_count );
  memcpy(buf + offset, & msguart_acrc_error_count , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_aio_error_count = htole16( msg->uart_a.io_error_count );
  memcpy(buf + offset, & msguart_aio_error_count , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_atx_buffer_level = msg->uart_a.tx_buffer_level;
  memcpy(buf + offset, & msguart_atx_buffer_level , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_arx_buffer_level = msg->uart_a.rx_buffer_level;
  memcpy(buf + offset, & msguart_arx_buffer_level , 1);
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  float msguart_btx_throughput = msg->uart_b.tx_throughput;
  memcpy(buf + offset, & msguart_btx_throughput , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msguart_brx_throughput = msg->uart_b.rx_throughput;
  memcpy(buf + offset, & msguart_brx_throughput , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_bcrc_error_count = htole16( msg->uart_b.crc_error_count );
  memcpy(buf + offset, & msguart_bcrc_error_count , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_bio_error_count = htole16( msg->uart_b.io_error_count );
  memcpy(buf + offset, & msguart_bio_error_count , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_btx_buffer_level = msg->uart_b.tx_buffer_level;
  memcpy(buf + offset, & msguart_btx_buffer_level , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_brx_buffer_level = msg->uart_b.rx_buffer_level;
  memcpy(buf + offset, & msguart_brx_buffer_level , 1);
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  float msguart_ftditx_throughput = msg->uart_ftdi.tx_throughput;
  memcpy(buf + offset, & msguart_ftditx_throughput , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msguart_ftdirx_throughput = msg->uart_ftdi.rx_throughput;
  memcpy(buf + offset, & msguart_ftdirx_throughput , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_ftdicrc_error_count = htole16( msg->uart_ftdi.crc_error_count );
  memcpy(buf + offset, & msguart_ftdicrc_error_count , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msguart_ftdiio_error_count = htole16( msg->uart_ftdi.io_error_count );
  memcpy(buf + offset, & msguart_ftdiio_error_count , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_ftditx_buffer_level = msg->uart_ftdi.tx_buffer_level;
  memcpy(buf + offset, & msguart_ftditx_buffer_level , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msguart_ftdirx_buffer_level = msg->uart_ftdi.rx_buffer_level;
  memcpy(buf + offset, & msguart_ftdirx_buffer_level , 1);
  offset += 1;
				
        
  if (offset + 4 > len) { return false; }
  u32 msglatencyavg = htole32( *(const u32*)&msg->latency.avg );
  memcpy(buf + offset, & msglatencyavg , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglatencylmin = htole32( *(const u32*)&msg->latency.lmin );
  memcpy(buf + offset, & msglatencylmin , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglatencylmax = htole32( *(const u32*)&msg->latency.lmax );
  memcpy(buf + offset, & msglatencylmax , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglatencycurrent = htole32( *(const u32*)&msg->latency.current );
  memcpy(buf + offset, & msglatencycurrent , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_uart_state_depa_t(const u8 *buf, size_t len, sbp_msg_uart_state_depa_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.tx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_a.rx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_a.crc_error_count, buf + offset, 2);
  msg->uart_a.crc_error_count = le16toh( msg->uart_a.crc_error_count );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_a.io_error_count, buf + offset, 2);
  msg->uart_a.io_error_count = le16toh( msg->uart_a.io_error_count );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.tx_buffer_level, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_a.rx_buffer_level, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.tx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_b.rx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_b.crc_error_count, buf + offset, 2);
  msg->uart_b.crc_error_count = le16toh( msg->uart_b.crc_error_count );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_b.io_error_count, buf + offset, 2);
  msg->uart_b.io_error_count = le16toh( msg->uart_b.io_error_count );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.tx_buffer_level, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_b.rx_buffer_level, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_throughput, buf + offset, 4);
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_ftdi.crc_error_count, buf + offset, 2);
  msg->uart_ftdi.crc_error_count = le16toh( msg->uart_ftdi.crc_error_count );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->uart_ftdi.io_error_count, buf + offset, 2);
  msg->uart_ftdi.io_error_count = le16toh( msg->uart_ftdi.io_error_count );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.tx_buffer_level, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->uart_ftdi.rx_buffer_level, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.avg, buf + offset, 4);
  u32 msglatencyavg = *(const u32*)&msg->latency.avg;
  msglatencyavg = le32toh( msglatencyavg );
  msg->latency.avg = *(const s32*)&msglatencyavg;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.lmin, buf + offset, 4);
  u32 msglatencylmin = *(const u32*)&msg->latency.lmin;
  msglatencylmin = le32toh( msglatencylmin );
  msg->latency.lmin = *(const s32*)&msglatencylmin;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.lmax, buf + offset, 4);
  u32 msglatencylmax = *(const u32*)&msg->latency.lmax;
  msglatencylmax = le32toh( msglatencylmax );
  msg->latency.lmax = *(const s32*)&msglatencylmax;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->latency.current, buf + offset, 4);
  u32 msglatencycurrent = *(const u32*)&msg->latency.current;
  msglatencycurrent = le32toh( msglatencycurrent );
  msg->latency.current = *(const s32*)&msglatencycurrent;
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  (void)a;
  (void)b;
  
        
        
    if (fabs( a.uart_a.tx_throughput - b.uart_a.tx_throughput ) > 0.001) { return false; }
        
    if (fabs( a.uart_a.rx_throughput - b.uart_a.rx_throughput ) > 0.001) { return false; }
        
    if (a.uart_a.crc_error_count != b.uart_a.crc_error_count) { return false; }
        
    if (a.uart_a.io_error_count != b.uart_a.io_error_count) { return false; }
        
    if (a.uart_a.tx_buffer_level != b.uart_a.tx_buffer_level) { return false; }
        
    if (a.uart_a.rx_buffer_level != b.uart_a.rx_buffer_level) { return false; }
        
        
    if (fabs( a.uart_b.tx_throughput - b.uart_b.tx_throughput ) > 0.001) { return false; }
        
    if (fabs( a.uart_b.rx_throughput - b.uart_b.rx_throughput ) > 0.001) { return false; }
        
    if (a.uart_b.crc_error_count != b.uart_b.crc_error_count) { return false; }
        
    if (a.uart_b.io_error_count != b.uart_b.io_error_count) { return false; }
        
    if (a.uart_b.tx_buffer_level != b.uart_b.tx_buffer_level) { return false; }
        
    if (a.uart_b.rx_buffer_level != b.uart_b.rx_buffer_level) { return false; }
        
        
    if (fabs( a.uart_ftdi.tx_throughput - b.uart_ftdi.tx_throughput ) > 0.001) { return false; }
        
    if (fabs( a.uart_ftdi.rx_throughput - b.uart_ftdi.rx_throughput ) > 0.001) { return false; }
        
    if (a.uart_ftdi.crc_error_count != b.uart_ftdi.crc_error_count) { return false; }
        
    if (a.uart_ftdi.io_error_count != b.uart_ftdi.io_error_count) { return false; }
        
    if (a.uart_ftdi.tx_buffer_level != b.uart_ftdi.tx_buffer_level) { return false; }
        
    if (a.uart_ftdi.rx_buffer_level != b.uart_ftdi.rx_buffer_level) { return false; }
        
        
    if (a.latency.avg != b.latency.avg) { return false; }
        
    if (a.latency.lmin != b.latency.lmin) { return false; }
        
    if (a.latency.lmax != b.latency.lmax) { return false; }
        
    if (a.latency.current != b.latency.current) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_uart_state_depa_t &a, const sbp_msg_uart_state_depa_t &b) {
  return !(a == b);
}
#endif
  /** State of the Integer Ambiguity Resolution (IAR) process
   *
 * This message reports the state of the Integer Ambiguity
 * Resolution (IAR) process, which resolves unknown integer
 * ambiguities from double-differenced carrier-phase measurements
 * from satellite observations.
   */
#define SBP_MSG_IAR_STATE               0x0019

typedef struct {
  
  /**
* Number of integer ambiguity hypotheses remaining
   */
    u32
  num_hyps
  ;
} sbp_msg_iar_state_t;

static inline size_t sbp_packed_size_sbp_msg_iar_state_t(const sbp_msg_iar_state_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->num_hyps );
}

static inline bool sbp_pack_sbp_msg_iar_state_t(u8 *buf, size_t len, const sbp_msg_iar_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_iar_state_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgnum_hyps = htole32( msg->num_hyps );
  memcpy(buf + offset, & msgnum_hyps , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_iar_state_t(const u8 *buf, size_t len, sbp_msg_iar_state_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->num_hyps, buf + offset, 4);
  msg->num_hyps = le32toh( msg->num_hyps );
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.num_hyps != b.num_hyps) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_iar_state_t &a, const sbp_msg_iar_state_t &b) {
  return !(a == b);
}
#endif
  /** Mask a satellite from use in Piksi subsystems
   *
 * This message allows setting a mask to prevent a particular satellite
 * from being used in various Piksi subsystems.
   */
#define SBP_MSG_MASK_SATELLITE          0x002B

	#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SHIFT) \
                             & SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_MASK)) \
                             << (SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_MASK_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SHIFT) \
                             & SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_MASK)) \
                             << (SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_MASK_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)
	
	#define SBP_MASK_SATELLITE_SID_CODE__MASK (0xff)
#define SBP_MASK_SATELLITE_SID_CODE__SHIFT (0u)
#define SBP_MASK_SATELLITE_SID_CODE__GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_SID_CODE__SHIFT) \
                             & SBP_MASK_SATELLITE_SID_CODE__MASK)
#define SBP_MASK_SATELLITE_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_SID_CODE__MASK)) \
                             << (SBP_MASK_SATELLITE_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_SID_CODE__GPS_L1CA (0)
#define SBP_MASK_SATELLITE_SID_CODE__GPS_L2CM (1)
#define SBP_MASK_SATELLITE_SID_CODE__SBAS_L1CA (2)
#define SBP_MASK_SATELLITE_SID_CODE__GLO_L1CA (3)
#define SBP_MASK_SATELLITE_SID_CODE__GLO_L2CA (4)
#define SBP_MASK_SATELLITE_SID_CODE__GPS_L1P (5)
#define SBP_MASK_SATELLITE_SID_CODE__GPS_L2P (6)
#define SBP_MASK_SATELLITE_SID_CODE__BDS2_B1 (12)
#define SBP_MASK_SATELLITE_SID_CODE__BDS2_B2 (13)
#define SBP_MASK_SATELLITE_SID_CODE__GAL_E1B (14)
#define SBP_MASK_SATELLITE_SID_CODE__GAL_E7I (20)
#define SBP_MASK_SATELLITE_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* Mask of systems that should ignore this satellite.
   */
    u8
  mask
  ;
  /**
* GNSS signal for which the mask is applied
   */
  struct {
    
  /**
 * Constellation-specific satellite identifier. This field for Glonass can  
 * either be (100+FCN) where FCN is in [-7,+6] or 
 * the Slot ID in [1,28]
   */
    u8
  sat
  ;
  /**
* Signal constellation, band and code
   */
    u8
  code
  ;
  }
  sid
  ;
} sbp_msg_mask_satellite_t;

static inline size_t sbp_packed_size_sbp_msg_mask_satellite_t(const sbp_msg_mask_satellite_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mask )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) );
}

static inline bool sbp_pack_sbp_msg_mask_satellite_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mask_satellite_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  u8 msgmask = msg->mask;
  memcpy(buf + offset, & msgmask , 1);
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  u8 msgsidsat = msg->sid.sat;
  memcpy(buf + offset, & msgsidsat , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_t(const u8 *buf, size_t len, sbp_msg_mask_satellite_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mask, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.mask != b.mask) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_mask_satellite_t &a, const sbp_msg_mask_satellite_t &b) {
  return !(a == b);
}
#endif
  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_MASK_SATELLITE_DEP      0x001B

	#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SHIFT (1u)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_MASK)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_MASK_TRACKING_CHANNELS_DROP_THIS_PRN_IF_CURRENTLY_TRACKING (1)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_MASK (0x1)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_MASK)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_ENABLED (0)
#define SBP_MASK_SATELLITE_DEP_MASK_ACQUISITION_CHANNEL_SKIP_THIS_SATELLITE_ON_FUTURE_ACQUISITIONS (1)
	
	#define SBP_MASK_SATELLITE_DEP_SID_CODE__MASK (0xff)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__SHIFT (0u)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GET(flags) \
                             (((flags) >> SBP_MASK_SATELLITE_DEP_SID_CODE__SHIFT) \
                             & SBP_MASK_SATELLITE_DEP_SID_CODE__MASK)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_MASK_SATELLITE_DEP_SID_CODE__MASK)) \
                             << (SBP_MASK_SATELLITE_DEP_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L1CA (0)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L2CM (1)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__SBAS_L1CA (2)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GLO_L1CA (3)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GLO_L2CA (4)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L1P (5)
#define SBP_MASK_SATELLITE_DEP_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* Mask of systems that should ignore this satellite.
   */
    u8
  mask
  ;
  /**
* GNSS signal for which the mask is applied
   */
  struct {
    
  /**
 * Constellation-specific satellite identifier.
 * 
 * Note: unlike GnssSignal, GPS satellites are encoded as
 * (PRN - 1). Other constellations do not have this offset.
   */
    u16
  sat
  ;
  /**
* Signal constellation, band and code
   */
    u8
  code
  ;
  /**
* Reserved
   */
    u8
  reserved
  ;
  }
  sid
  ;
} sbp_msg_mask_satellite_dep_t;

static inline size_t sbp_packed_size_sbp_msg_mask_satellite_dep_t(const sbp_msg_mask_satellite_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->mask )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code )                                                                          
	  +
				sizeof( msg->sid.reserved ) );
}

static inline bool sbp_pack_sbp_msg_mask_satellite_dep_t(u8 *buf, size_t len, const sbp_msg_mask_satellite_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_mask_satellite_dep_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  u8 msgmask = msg->mask;
  memcpy(buf + offset, & msgmask , 1);
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  u16 msgsidsat = htole16( msg->sid.sat );
  memcpy(buf + offset, & msgsidsat , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidcode = msg->sid.code;
  memcpy(buf + offset, & msgsidcode , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsidreserved = msg->sid.reserved;
  memcpy(buf + offset, & msgsidreserved , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_mask_satellite_dep_t(const u8 *buf, size_t len, sbp_msg_mask_satellite_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->mask, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 2);
  msg->sid.sat = le16toh( msg->sid.sat );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.reserved, buf + offset, 1);
  offset += 1;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.mask != b.mask) { return false; }
        
        
    if (a.sid.sat != b.sid.sat) { return false; }
        
    if (a.sid.code != b.sid.code) { return false; }
        
    if (a.sid.reserved != b.sid.reserved) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_mask_satellite_dep_t &a, const sbp_msg_mask_satellite_dep_t &b) {
  return !(a == b);
}
#endif
  /** Device temperature and voltage levels
   *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if
 * available.
   */
#define SBP_MSG_DEVICE_MONITOR          0x00B5

typedef struct {
  
  /**
* Device V_in[V / 1000]
   */
    s16
  dev_vin
  ;
  /**
* Processor V_int[V / 1000]
   */
    s16
  cpu_vint
  ;
  /**
* Processor V_aux[V / 1000]
   */
    s16
  cpu_vaux
  ;
  /**
* Processor temperature[degrees C / 100]
   */
    s16
  cpu_temperature
  ;
  /**
* Frontend temperature (if available)[degrees C / 100]
   */
    s16
  fe_temperature
  ;
} sbp_msg_device_monitor_t;

static inline size_t sbp_packed_size_sbp_msg_device_monitor_t(const sbp_msg_device_monitor_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->dev_vin )                                                                          
	  +
				sizeof( msg->cpu_vint )                                                                          
	  +
				sizeof( msg->cpu_vaux )                                                                          
	  +
				sizeof( msg->cpu_temperature )                                                                          
	  +
				sizeof( msg->fe_temperature );
}

static inline bool sbp_pack_sbp_msg_device_monitor_t(u8 *buf, size_t len, const sbp_msg_device_monitor_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_device_monitor_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  u16 msgdev_vin = htole16( *(const u16*)&msg->dev_vin );
  memcpy(buf + offset, & msgdev_vin , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgcpu_vint = htole16( *(const u16*)&msg->cpu_vint );
  memcpy(buf + offset, & msgcpu_vint , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgcpu_vaux = htole16( *(const u16*)&msg->cpu_vaux );
  memcpy(buf + offset, & msgcpu_vaux , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgcpu_temperature = htole16( *(const u16*)&msg->cpu_temperature );
  memcpy(buf + offset, & msgcpu_temperature , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgfe_temperature = htole16( *(const u16*)&msg->fe_temperature );
  memcpy(buf + offset, & msgfe_temperature , 2);
  offset += 2;
  return true;
}

static inline bool sbp_unpack_sbp_msg_device_monitor_t(const u8 *buf, size_t len, sbp_msg_device_monitor_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->dev_vin, buf + offset, 2);
  u16 msgdev_vin = *(const u16*)&msg->dev_vin;
  msgdev_vin = le16toh( msgdev_vin );
  msg->dev_vin = *(const s16*)&msgdev_vin;
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->cpu_vint, buf + offset, 2);
  u16 msgcpu_vint = *(const u16*)&msg->cpu_vint;
  msgcpu_vint = le16toh( msgcpu_vint );
  msg->cpu_vint = *(const s16*)&msgcpu_vint;
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->cpu_vaux, buf + offset, 2);
  u16 msgcpu_vaux = *(const u16*)&msg->cpu_vaux;
  msgcpu_vaux = le16toh( msgcpu_vaux );
  msg->cpu_vaux = *(const s16*)&msgcpu_vaux;
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->cpu_temperature, buf + offset, 2);
  u16 msgcpu_temperature = *(const u16*)&msg->cpu_temperature;
  msgcpu_temperature = le16toh( msgcpu_temperature );
  msg->cpu_temperature = *(const s16*)&msgcpu_temperature;
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->fe_temperature, buf + offset, 2);
  u16 msgfe_temperature = *(const u16*)&msg->fe_temperature;
  msgfe_temperature = le16toh( msgfe_temperature );
  msg->fe_temperature = *(const s16*)&msgfe_temperature;
  offset += 2;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.dev_vin != b.dev_vin) { return false; }
        
    if (a.cpu_vint != b.cpu_vint) { return false; }
        
    if (a.cpu_vaux != b.cpu_vaux) { return false; }
        
    if (a.cpu_temperature != b.cpu_temperature) { return false; }
        
    if (a.fe_temperature != b.fe_temperature) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_device_monitor_t &a, const sbp_msg_device_monitor_t &b) {
  return !(a == b);
}
#endif
  /** Execute a command (host => device)
   *
 * Request the recipient to execute an command.
 * Output will be sent in MSG_LOG messages, and the exit
 * code will be returned with MSG_COMMAND_RESP.
   */
#define SBP_MSG_COMMAND_REQ             0x00B8

typedef struct {
  
  /**
* Sequence number
   */
    u32
  sequence
  ;
  /**
* Command line to execute
   */
    char
  command
    [251]
  ;
} sbp_msg_command_req_t;

static inline size_t sbp_packed_size_sbp_msg_command_req_t(const sbp_msg_command_req_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
      sbp_strlen( msg->command, "nul" );
}

static inline bool sbp_pack_sbp_msg_command_req_t(u8 *buf, size_t len, const sbp_msg_command_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_req_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgsequence = htole32( msg->sequence );
  memcpy(buf + offset, & msgsequence , 4);
  offset += 4;
      if (offset + sbp_strlen( msg->command, "nul") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->command, "nul");
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_req_t(const u8 *buf, size_t len, sbp_msg_command_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh( msg->sequence );
  offset += 4;
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->command, "nul");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.sequence != b.sequence) { return false; }
        if (sbp_strcmp(a.command, b.command, "nul") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_command_req_t &a, const sbp_msg_command_req_t &b) {
  return !(a == b);
}
#endif
  /** Exit code from executed command (device => host)
   *
 * The response to MSG_COMMAND_REQ with the return code of
 * the command.  A return code of zero indicates success.
   */
#define SBP_MSG_COMMAND_RESP            0x00B9

typedef struct {
  
  /**
* Sequence number
   */
    u32
  sequence
  ;
  /**
* Exit code
   */
    s32
  code
  ;
} sbp_msg_command_resp_t;

static inline size_t sbp_packed_size_sbp_msg_command_resp_t(const sbp_msg_command_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
				sizeof( msg->code );
}

static inline bool sbp_pack_sbp_msg_command_resp_t(u8 *buf, size_t len, const sbp_msg_command_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_resp_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgsequence = htole32( msg->sequence );
  memcpy(buf + offset, & msgsequence , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgcode = htole32( *(const u32*)&msg->code );
  memcpy(buf + offset, & msgcode , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_resp_t(const u8 *buf, size_t len, sbp_msg_command_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh( msg->sequence );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->code, buf + offset, 4);
  u32 msgcode = *(const u32*)&msg->code;
  msgcode = le32toh( msgcode );
  msg->code = *(const s32*)&msgcode;
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.sequence != b.sequence) { return false; }
        
    if (a.code != b.code) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_command_resp_t &a, const sbp_msg_command_resp_t &b) {
  return !(a == b);
}
#endif
  /** Command output
   *
 * Returns the standard output and standard error of the
 * command requested by MSG_COMMAND_REQ.
 * The sequence number can be used to filter for filtering
 * the correct command.
   */
#define SBP_MSG_COMMAND_OUTPUT          0x00BC

typedef struct {
  
  /**
* Sequence number
   */
    u32
  sequence
  ;
  /**
* Line of standard output or standard error
   */
    char
  line
    [251]
  ;
} sbp_msg_command_output_t;

static inline size_t sbp_packed_size_sbp_msg_command_output_t(const sbp_msg_command_output_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->sequence )                                                                          
	  +
      sbp_strlen( msg->line, "none" );
}

static inline bool sbp_pack_sbp_msg_command_output_t(u8 *buf, size_t len, const sbp_msg_command_output_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_command_output_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgsequence = htole32( msg->sequence );
  memcpy(buf + offset, & msgsequence , 4);
  offset += 4;
      if (offset + sbp_strlen( msg->line, "none") > len) { return false; }
      offset += sbp_pack_string( buf + offset, msg->line, "none");
  return true;
}

static inline bool sbp_unpack_sbp_msg_command_output_t(const u8 *buf, size_t len, sbp_msg_command_output_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->sequence, buf + offset, 4);
  msg->sequence = le32toh( msg->sequence );
  offset += 4;
    offset += sbp_unpack_string((const char *)buf + offset, len - offset, msg->line, "none");
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.sequence != b.sequence) { return false; }
        if (sbp_strcmp(a.line, b.line, "none") != 0) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_command_output_t &a, const sbp_msg_command_output_t &b) {
  return !(a == b);
}
#endif
  /** Request state of Piksi network interfaces
   *
 * Request state of Piksi network interfaces.
 * Output will be sent in MSG_NETWORK_STATE_RESP messages
   */
#define SBP_MSG_NETWORK_STATE_REQ       0x00BA

typedef struct {
  char dummy_to_avoid_empty_struct___do_not_use;
} sbp_msg_network_state_req_t;

static inline size_t sbp_packed_size_sbp_msg_network_state_req_t(const sbp_msg_network_state_req_t *msg) {                                
	(void)msg;
  return                                                          
	0;
}

static inline bool sbp_pack_sbp_msg_network_state_req_t(u8 *buf, size_t len, const sbp_msg_network_state_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_state_req_t(msg) > len) { return false; }
  
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_req_t(const u8 *buf, size_t len, sbp_msg_network_state_req_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  (void)a;
  (void)b;
  

  return true;
}

static inline bool operator!=(const sbp_msg_network_state_req_t &a, const sbp_msg_network_state_req_t &b) {
  return !(a == b);
}
#endif
  /** State of network interface
   *
 * The state of a network interface on the Piksi.
 * Data is made to reflect output of ifaddrs struct returned by getifaddrs
 * in c.
   */
#define SBP_MSG_NETWORK_STATE_RESP      0x00BB

	#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT (15u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_MULTICAST__SUPPORTS_MULTICAST_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT (14u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK2__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT (13u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK1__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT (12u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LINK0__PER_LINK_LAYER_DEFINED_BIT_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT (11u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_SIMPLEX__CANT_HEAR_OWN_TRANSMISSIONS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT (10u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_OACTIVE__TRANSMISSION_IN_PROGRESS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT (9u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_ALLMULTI__RECEIVE_ALL_MULTICAST_PACKETS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT (8u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_PROMISC__RECEIVE_ALL_PACKETS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT (7u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOARP__NO_ADDRESS_RESOLUTION_PROTOCOL_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT (6u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_RUNNING__RESOURCES_ALLOCATED_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT (5u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_NOTRAILERS__AVOID_USE_OF_TRAILERS_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT (4u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_POINTOPOINT__INTERFACE_IS_POINTTOPOINT_LINK_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT (3u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_LOOPBACK__IS_A_LOOPBACK_NET_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT (2u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_DEBUG__BROADCAST_ADDRESS_VALID_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT (1u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_BROADCAST__BROADCAST_ADDRESS_VALID_SHIFT)));} while(0)
                             

#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_MASK (0x1)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SHIFT (0u)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_GET(flags) \
                             (((flags) >> SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SHIFT) \
                             & SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_MASK)
#define SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_MASK)) \
                             << (SBP_NETWORK_STATE_RESP_FLAGS_IFF_UP__INTERFACE_IS_UP_SHIFT)));} while(0)
                             

typedef struct {
  
  /**
* IPv4 address (all zero when unavailable)
   */
    u8
  ipv4_address
    [4]
  ;
  /**
* IPv4 netmask CIDR notation
   */
    u8
  ipv4_mask_size
  ;
  /**
* IPv6 address (all zero when unavailable)
   */
    u8
  ipv6_address
    [16]
  ;
  /**
* IPv6 netmask CIDR notation
   */
    u8
  ipv6_mask_size
  ;
  /**
* Number of Rx bytes
   */
    u32
  rx_bytes
  ;
  /**
* Number of Tx bytes
   */
    u32
  tx_bytes
  ;
  /**
* Interface Name
   */
    char
  interface_name
    [16]
  ;
  /**
* Interface flags from SIOCGIFFLAGS
   */
    u32
  flags
  ;
} sbp_msg_network_state_resp_t;

static inline size_t sbp_packed_size_sbp_msg_network_state_resp_t(const sbp_msg_network_state_resp_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 4 *
        sizeof( msg->ipv4_address[0] )
		)                                                                          
	  +
				sizeof( msg->ipv4_mask_size )                                                                          
	  +
		  ( 16 *
        sizeof( msg->ipv6_address[0] )
		)                                                                          
	  +
				sizeof( msg->ipv6_mask_size )                                                                          
	  +
				sizeof( msg->rx_bytes )                                                                          
	  +
				sizeof( msg->tx_bytes )                                                                          
	  +
		  ( 16 *
        sizeof( msg->interface_name[0] )
		)                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_network_state_resp_t(u8 *buf, size_t len, const sbp_msg_network_state_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_state_resp_t(msg) > len) { return false; }
  
		  for(size_t msgipv4_address_idx = 0; msgipv4_address_idx < 4; msgipv4_address_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  u8 msgipv4_addressmsgipv4_address_idx = msg->ipv4_address[msgipv4_address_idx];
  memcpy(buf + offset, & msgipv4_addressmsgipv4_address_idx , 1);
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  u8 msgipv4_mask_size = msg->ipv4_mask_size;
  memcpy(buf + offset, & msgipv4_mask_size , 1);
  offset += 1;
		  for(size_t msgipv6_address_idx = 0; msgipv6_address_idx < 16; msgipv6_address_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  u8 msgipv6_addressmsgipv6_address_idx = msg->ipv6_address[msgipv6_address_idx];
  memcpy(buf + offset, & msgipv6_addressmsgipv6_address_idx , 1);
  offset += 1;
			}
        
  if (offset + 1 > len) { return false; }
  u8 msgipv6_mask_size = msg->ipv6_mask_size;
  memcpy(buf + offset, & msgipv6_mask_size , 1);
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  u32 msgrx_bytes = htole32( msg->rx_bytes );
  memcpy(buf + offset, & msgrx_bytes , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgtx_bytes = htole32( msg->tx_bytes );
  memcpy(buf + offset, & msgtx_bytes , 4);
  offset += 4;
		  for(size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  char msginterface_namemsginterface_name_idx = msg->interface_name[msginterface_name_idx];
  memcpy(buf + offset, & msginterface_namemsginterface_name_idx , 1);
  offset += 1;
			}
        
  if (offset + 4 > len) { return false; }
  u32 msgflags = htole32( msg->flags );
  memcpy(buf + offset, & msgflags , 4);
  offset += 4;
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_state_resp_t(const u8 *buf, size_t len, sbp_msg_network_state_resp_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgipv4_address_idx = 0; msgipv4_address_idx < 4; msgipv4_address_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv4_address[msgipv4_address_idx], buf + offset, 1);
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv4_mask_size, buf + offset, 1);
  offset += 1;
		for (size_t msgipv6_address_idx = 0; msgipv6_address_idx < 16; msgipv6_address_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv6_address[msgipv6_address_idx], buf + offset, 1);
  offset += 1;
		}
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->ipv6_mask_size, buf + offset, 1);
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->rx_bytes, buf + offset, 4);
  msg->rx_bytes = le32toh( msg->rx_bytes );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tx_bytes, buf + offset, 4);
  msg->tx_bytes = le32toh( msg->tx_bytes );
  offset += 4;
		for (size_t msginterface_name_idx = 0; msginterface_name_idx < 16; msginterface_name_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->interface_name[msginterface_name_idx], buf + offset, 1);
  offset += 1;
		}
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 4);
  msg->flags = le32toh( msg->flags );
  offset += 4;
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  (void)a;
  (void)b;
  
        for (size_t ipv4_address_idx = 0; ipv4_address_idx < 4; ipv4_address_idx++)
        {
            
    if (a.ipv4_address[ipv4_address_idx] != b.ipv4_address[ipv4_address_idx]) { return false; }
        }
        
    if (a.ipv4_mask_size != b.ipv4_mask_size) { return false; }
        for (size_t ipv6_address_idx = 0; ipv6_address_idx < 16; ipv6_address_idx++)
        {
            
    if (a.ipv6_address[ipv6_address_idx] != b.ipv6_address[ipv6_address_idx]) { return false; }
        }
        
    if (a.ipv6_mask_size != b.ipv6_mask_size) { return false; }
        
    if (a.rx_bytes != b.rx_bytes) { return false; }
        
    if (a.tx_bytes != b.tx_bytes) { return false; }
        for (size_t interface_name_idx = 0; interface_name_idx < 16; interface_name_idx++)
        {
            
    if (a.interface_name[interface_name_idx] != b.interface_name[interface_name_idx]) { return false; }
        }
        
    if (a.flags != b.flags) { return false; }

  return true;
}

static inline bool operator!=(const sbp_msg_network_state_resp_t &a, const sbp_msg_network_state_resp_t &b) {
  return !(a == b);
}
#endif
  /** Bandwidth usage reporting message
   *
 * The bandwidth usage, a list of usage by interface. 
   */
#define SBP_MSG_NETWORK_BANDWIDTH_USAGE 0x00BD

	
typedef struct {
  
  /**
* Usage measurement array
   */
  struct {
    
  /**
* Duration over which the measurement was collected[ms]
   */
    u64
  duration
  ;
  /**
* Number of bytes handled in total within period
   */
    u64
  total_bytes
  ;
  /**
* Number of bytes transmitted within period
   */
    u32
  rx_bytes
  ;
  /**
* Number of bytes received within period
   */
    u32
  tx_bytes
  ;
  /**
* Interface Name
   */
    char
  interface_name
    [16]
  ;
  }
  interfaces
    [6]
  ;
  /**
   * Number of items in interfaces
   */
  u8 n_interfaces;
} sbp_msg_network_bandwidth_usage_t;

static inline size_t sbp_packed_size_sbp_msg_network_bandwidth_usage_t(const sbp_msg_network_bandwidth_usage_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_interfaces
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->interfaces[0].duration )                                                                          
	  +
				sizeof( msg->interfaces[0].total_bytes )                                                                          
	  +
				sizeof( msg->interfaces[0].rx_bytes )                                                                          
	  +
				sizeof( msg->interfaces[0].tx_bytes )                                                                          
	  +
		  ( 16 *
        sizeof( msg->interfaces[0].interface_name[0] )
		) )
			);
}

static inline bool sbp_pack_sbp_msg_network_bandwidth_usage_t(u8 *buf, size_t len, const sbp_msg_network_bandwidth_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_network_bandwidth_usage_t(msg) > len) { return false; }
  
			for(size_t msginterfaces_idx = 0; msginterfaces_idx < (size_t)msg->n_interfaces; msginterfaces_idx++)
			{
					
        
  if (offset + 8 > len) { return false; }
  u64 msginterfacesmsginterfaces_idxduration = htole64( msg->interfaces[msginterfaces_idx].duration );
  memcpy(buf + offset, & msginterfacesmsginterfaces_idxduration , 8);
  offset += 8;
        
  if (offset + 8 > len) { return false; }
  u64 msginterfacesmsginterfaces_idxtotal_bytes = htole64( msg->interfaces[msginterfaces_idx].total_bytes );
  memcpy(buf + offset, & msginterfacesmsginterfaces_idxtotal_bytes , 8);
  offset += 8;
        
  if (offset + 4 > len) { return false; }
  u32 msginterfacesmsginterfaces_idxrx_bytes = htole32( msg->interfaces[msginterfaces_idx].rx_bytes );
  memcpy(buf + offset, & msginterfacesmsginterfaces_idxrx_bytes , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msginterfacesmsginterfaces_idxtx_bytes = htole32( msg->interfaces[msginterfaces_idx].tx_bytes );
  memcpy(buf + offset, & msginterfacesmsginterfaces_idxtx_bytes , 4);
  offset += 4;
		  for(size_t msginterfacesmsginterfaces_idxinterface_name_idx = 0; msginterfacesmsginterfaces_idxinterface_name_idx < 16; msginterfacesmsginterfaces_idxinterface_name_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  char msginterfacesmsginterfaces_idxinterface_namemsginterfacesmsginterfaces_idxinterface_name_idx = msg->interfaces[msginterfaces_idx].interface_name[msginterfacesmsginterfaces_idxinterface_name_idx];
  memcpy(buf + offset, & msginterfacesmsginterfaces_idxinterface_namemsginterfacesmsginterfaces_idxinterface_name_idx , 1);
  offset += 1;
			}
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_network_bandwidth_usage_t(const u8 *buf, size_t len, sbp_msg_network_bandwidth_usage_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_interfaces = (u8)((len - offset) / 40);

	  for (size_t msginterfaces_idx = 0; msginterfaces_idx <
				msg->n_interfaces;
				msginterfaces_idx++) 
		{
				
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->interfaces[msginterfaces_idx].duration, buf + offset, 8);
  msg->interfaces[msginterfaces_idx].duration = le64toh( msg->interfaces[msginterfaces_idx].duration );
  offset += 8;
      
  if (offset + 8 > len) { return false; }
  memcpy(&msg->interfaces[msginterfaces_idx].total_bytes, buf + offset, 8);
  msg->interfaces[msginterfaces_idx].total_bytes = le64toh( msg->interfaces[msginterfaces_idx].total_bytes );
  offset += 8;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->interfaces[msginterfaces_idx].rx_bytes, buf + offset, 4);
  msg->interfaces[msginterfaces_idx].rx_bytes = le32toh( msg->interfaces[msginterfaces_idx].rx_bytes );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->interfaces[msginterfaces_idx].tx_bytes, buf + offset, 4);
  msg->interfaces[msginterfaces_idx].tx_bytes = le32toh( msg->interfaces[msginterfaces_idx].tx_bytes );
  offset += 4;
		for (size_t msginterfacesmsginterfaces_idxinterface_name_idx = 0; msginterfacesmsginterfaces_idxinterface_name_idx < 16; msginterfacesmsginterfaces_idxinterface_name_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->interfaces[msginterfaces_idx].interface_name[msginterfacesmsginterfaces_idxinterface_name_idx], buf + offset, 1);
  offset += 1;
		}
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  (void)a;
  (void)b;
  
          if (a.n_interfaces != b.n_interfaces) { return false; }
        for (size_t interfaces_idx = 0; interfaces_idx < (size_t)a.n_interfaces; interfaces_idx++)
        {
            
        
    if (a.interfaces[interfaces_idx].duration != b.interfaces[interfaces_idx].duration) { return false; }
        
    if (a.interfaces[interfaces_idx].total_bytes != b.interfaces[interfaces_idx].total_bytes) { return false; }
        
    if (a.interfaces[interfaces_idx].rx_bytes != b.interfaces[interfaces_idx].rx_bytes) { return false; }
        
    if (a.interfaces[interfaces_idx].tx_bytes != b.interfaces[interfaces_idx].tx_bytes) { return false; }
        for (size_t interfacesinterfaces_idxinterface_name_idx = 0; interfacesinterfaces_idxinterface_name_idx < 16; interfacesinterfaces_idxinterface_name_idx++)
        {
            
    if (a.interfaces[interfaces_idx].interface_name[interfacesinterfaces_idxinterface_name_idx] != b.interfaces[interfaces_idx].interface_name[interfacesinterfaces_idxinterface_name_idx]) { return false; }
        }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_network_bandwidth_usage_t &a, const sbp_msg_network_bandwidth_usage_t &b) {
  return !(a == b);
}
#endif
  /** Cell modem information update message
   *
 * If a cell modem is present on a piksi device, this message
 * will be send periodically to update the host on the status
 * of the modem and its various parameters.
   */
#define SBP_MSG_CELL_MODEM_STATUS       0x00BE

typedef struct {
  
  /**
* Received cell signal strength in dBm, zero translates to unknown[dBm]
   */
    s8
  signal_strength
  ;
  /**
* BER as reported by the modem, zero translates to unknown
   */
    float
  signal_error_rate
  ;
  /**
* Unspecified data TBD for this schema
   */
    u8
  reserved
    [250]
  ;
  /**
   * Number of items in reserved
   */
  u8 n_reserved;
} sbp_msg_cell_modem_status_t;

static inline size_t sbp_packed_size_sbp_msg_cell_modem_status_t(const sbp_msg_cell_modem_status_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->signal_strength )                                                                          
	  +
				sizeof( msg->signal_error_rate )                                                                          
	  +
	    (
			  msg->n_reserved
			*
        sizeof( msg->reserved[0] )
			);
}

static inline bool sbp_pack_sbp_msg_cell_modem_status_t(u8 *buf, size_t len, const sbp_msg_cell_modem_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_cell_modem_status_t(msg) > len) { return false; }
  
        
  if (offset + 1 > len) { return false; }
  s8 msgsignal_strength = msg->signal_strength;
  memcpy(buf + offset, & msgsignal_strength , 1);
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  float msgsignal_error_rate = msg->signal_error_rate;
  memcpy(buf + offset, & msgsignal_error_rate , 4);
  offset += 4;
			for(size_t msgreserved_idx = 0; msgreserved_idx < (size_t)msg->n_reserved; msgreserved_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  u8 msgreservedmsgreserved_idx = msg->reserved[msgreserved_idx];
  memcpy(buf + offset, & msgreservedmsgreserved_idx , 1);
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_cell_modem_status_t(const u8 *buf, size_t len, sbp_msg_cell_modem_status_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->signal_strength, buf + offset, 1);
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->signal_error_rate, buf + offset, 4);
  offset += 4;
      msg->n_reserved = (u8)((len - offset) / 1);

	  for (size_t msgreserved_idx = 0; msgreserved_idx <
				msg->n_reserved;
				msgreserved_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->reserved[msgreserved_idx], buf + offset, 1);
  offset += 1;
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.signal_strength != b.signal_strength) { return false; }
        
    if (fabs( a.signal_error_rate - b.signal_error_rate ) > 0.001) { return false; }
          if (a.n_reserved != b.n_reserved) { return false; }
        for (size_t reserved_idx = 0; reserved_idx < (size_t)a.n_reserved; reserved_idx++)
        {
            
    if (a.reserved[reserved_idx] != b.reserved[reserved_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_cell_modem_status_t &a, const sbp_msg_cell_modem_status_t &b) {
  return !(a == b);
}
#endif
  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_SPECAN_DEP              0x0050

	
typedef struct {
  
  /**
* Channel ID
   */
    u16
  channel_tag
  ;
  /**
* Receiver time of this observation
   */
  struct {
    
  /**
* Milliseconds since start of GPS week[ms]
   */
    u32
  tow
  ;
  /**
* GPS week number[week]
   */
    u16
  wn
  ;
  }
  t
  ;
  /**
 * Reference frequency of this packet[MHz]
   */
    float
  freq_ref
  ;
  /**
 * Frequency step of points in this packet[MHz]
   */
    float
  freq_step
  ;
  /**
 * Reference amplitude of this packet[dB]
   */
    float
  amplitude_ref
  ;
  /**
 * Amplitude unit value of points in this packet[dB]
   */
    float
  amplitude_unit
  ;
  /**
 * Amplitude values (in the above units) of points in this packet
   */
    u8
  amplitude_value
    [231]
  ;
  /**
   * Number of items in amplitude_value
   */
  u8 n_amplitude_value;
} sbp_msg_specan_dep_t;

static inline size_t sbp_packed_size_sbp_msg_specan_dep_t(const sbp_msg_specan_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel_tag )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t.tow )                                                                          
	  +
				sizeof( msg->t.wn ) )                                                                          
	  +
				sizeof( msg->freq_ref )                                                                          
	  +
				sizeof( msg->freq_step )                                                                          
	  +
				sizeof( msg->amplitude_ref )                                                                          
	  +
				sizeof( msg->amplitude_unit )                                                                          
	  +
	    (
			  msg->n_amplitude_value
			*
        sizeof( msg->amplitude_value[0] )
			);
}

static inline bool sbp_pack_sbp_msg_specan_dep_t(u8 *buf, size_t len, const sbp_msg_specan_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_specan_dep_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  u16 msgchannel_tag = htole16( msg->channel_tag );
  memcpy(buf + offset, & msgchannel_tag , 2);
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  u32 msgttow = htole32( msg->t.tow );
  memcpy(buf + offset, & msgttow , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msgtwn = htole16( msg->t.wn );
  memcpy(buf + offset, & msgtwn , 2);
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  float msgfreq_ref = msg->freq_ref;
  memcpy(buf + offset, & msgfreq_ref , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgfreq_step = msg->freq_step;
  memcpy(buf + offset, & msgfreq_step , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgamplitude_ref = msg->amplitude_ref;
  memcpy(buf + offset, & msgamplitude_ref , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgamplitude_unit = msg->amplitude_unit;
  memcpy(buf + offset, & msgamplitude_unit , 4);
  offset += 4;
			for(size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < (size_t)msg->n_amplitude_value; msgamplitude_value_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  u8 msgamplitude_valuemsgamplitude_value_idx = msg->amplitude_value[msgamplitude_value_idx];
  memcpy(buf + offset, & msgamplitude_valuemsgamplitude_value_idx , 1);
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_dep_t(const u8 *buf, size_t len, sbp_msg_specan_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->channel_tag, buf + offset, 2);
  msg->channel_tag = le16toh( msg->channel_tag );
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->t.tow, buf + offset, 4);
  msg->t.tow = le32toh( msg->t.tow );
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->t.wn, buf + offset, 2);
  msg->t.wn = le16toh( msg->t.wn );
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_ref, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_step, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_ref, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_unit, buf + offset, 4);
  offset += 4;
      msg->n_amplitude_value = (u8)((len - offset) / 1);

	  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx <
				msg->n_amplitude_value;
				msgamplitude_value_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->amplitude_value[msgamplitude_value_idx], buf + offset, 1);
  offset += 1;
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.channel_tag != b.channel_tag) { return false; }
        
        
    if (a.t.tow != b.t.tow) { return false; }
        
    if (a.t.wn != b.t.wn) { return false; }
        
    if (fabs( a.freq_ref - b.freq_ref ) > 0.001) { return false; }
        
    if (fabs( a.freq_step - b.freq_step ) > 0.001) { return false; }
        
    if (fabs( a.amplitude_ref - b.amplitude_ref ) > 0.001) { return false; }
        
    if (fabs( a.amplitude_unit - b.amplitude_unit ) > 0.001) { return false; }
          if (a.n_amplitude_value != b.n_amplitude_value) { return false; }
        for (size_t amplitude_value_idx = 0; amplitude_value_idx < (size_t)a.n_amplitude_value; amplitude_value_idx++)
        {
            
    if (a.amplitude_value[amplitude_value_idx] != b.amplitude_value[amplitude_value_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_specan_dep_t &a, const sbp_msg_specan_dep_t &b) {
  return !(a == b);
}
#endif
  /** Spectrum analyzer
   *
 * Spectrum analyzer packet.
   */
#define SBP_MSG_SPECAN                  0x0051

	
typedef struct {
  
  /**
* Channel ID
   */
    u16
  channel_tag
  ;
  /**
* Receiver time of this observation
   */
  struct {
    
  /**
* Milliseconds since start of GPS week[ms]
   */
    u32
  tow
  ;
  /**
 * Nanosecond residual of millisecond-rounded TOW (ranges
 * from -500000 to 500000)[ns]
   */
    s32
  ns_residual
  ;
  /**
* GPS week number[week]
   */
    u16
  wn
  ;
  }
  t
  ;
  /**
 * Reference frequency of this packet[MHz]
   */
    float
  freq_ref
  ;
  /**
 * Frequency step of points in this packet[MHz]
   */
    float
  freq_step
  ;
  /**
 * Reference amplitude of this packet[dB]
   */
    float
  amplitude_ref
  ;
  /**
 * Amplitude unit value of points in this packet[dB]
   */
    float
  amplitude_unit
  ;
  /**
 * Amplitude values (in the above units) of points in this packet
   */
    u8
  amplitude_value
    [227]
  ;
  /**
   * Number of items in amplitude_value
   */
  u8 n_amplitude_value;
} sbp_msg_specan_t;

static inline size_t sbp_packed_size_sbp_msg_specan_t(const sbp_msg_specan_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->channel_tag )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->t.tow )                                                                          
	  +
				sizeof( msg->t.ns_residual )                                                                          
	  +
				sizeof( msg->t.wn ) )                                                                          
	  +
				sizeof( msg->freq_ref )                                                                          
	  +
				sizeof( msg->freq_step )                                                                          
	  +
				sizeof( msg->amplitude_ref )                                                                          
	  +
				sizeof( msg->amplitude_unit )                                                                          
	  +
	    (
			  msg->n_amplitude_value
			*
        sizeof( msg->amplitude_value[0] )
			);
}

static inline bool sbp_pack_sbp_msg_specan_t(u8 *buf, size_t len, const sbp_msg_specan_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_specan_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  u16 msgchannel_tag = htole16( msg->channel_tag );
  memcpy(buf + offset, & msgchannel_tag , 2);
  offset += 2;
				
        
  if (offset + 4 > len) { return false; }
  u32 msgttow = htole32( msg->t.tow );
  memcpy(buf + offset, & msgttow , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgtns_residual = htole32( *(const u32*)&msg->t.ns_residual );
  memcpy(buf + offset, & msgtns_residual , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msgtwn = htole16( msg->t.wn );
  memcpy(buf + offset, & msgtwn , 2);
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  float msgfreq_ref = msg->freq_ref;
  memcpy(buf + offset, & msgfreq_ref , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgfreq_step = msg->freq_step;
  memcpy(buf + offset, & msgfreq_step , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgamplitude_ref = msg->amplitude_ref;
  memcpy(buf + offset, & msgamplitude_ref , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgamplitude_unit = msg->amplitude_unit;
  memcpy(buf + offset, & msgamplitude_unit , 4);
  offset += 4;
			for(size_t msgamplitude_value_idx = 0; msgamplitude_value_idx < (size_t)msg->n_amplitude_value; msgamplitude_value_idx++)
			{
          
  if (offset + 1 > len) { return false; }
  u8 msgamplitude_valuemsgamplitude_value_idx = msg->amplitude_value[msgamplitude_value_idx];
  memcpy(buf + offset, & msgamplitude_valuemsgamplitude_value_idx , 1);
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_specan_t(const u8 *buf, size_t len, sbp_msg_specan_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->channel_tag, buf + offset, 2);
  msg->channel_tag = le16toh( msg->channel_tag );
  offset += 2;
			
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->t.tow, buf + offset, 4);
  msg->t.tow = le32toh( msg->t.tow );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->t.ns_residual, buf + offset, 4);
  u32 msgtns_residual = *(const u32*)&msg->t.ns_residual;
  msgtns_residual = le32toh( msgtns_residual );
  msg->t.ns_residual = *(const s32*)&msgtns_residual;
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->t.wn, buf + offset, 2);
  msg->t.wn = le16toh( msg->t.wn );
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_ref, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->freq_step, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_ref, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->amplitude_unit, buf + offset, 4);
  offset += 4;
      msg->n_amplitude_value = (u8)((len - offset) / 1);

	  for (size_t msgamplitude_value_idx = 0; msgamplitude_value_idx <
				msg->n_amplitude_value;
				msgamplitude_value_idx++) 
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->amplitude_value[msgamplitude_value_idx], buf + offset, 1);
  offset += 1;
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.channel_tag != b.channel_tag) { return false; }
        
        
    if (a.t.tow != b.t.tow) { return false; }
        
    if (a.t.ns_residual != b.t.ns_residual) { return false; }
        
    if (a.t.wn != b.t.wn) { return false; }
        
    if (fabs( a.freq_ref - b.freq_ref ) > 0.001) { return false; }
        
    if (fabs( a.freq_step - b.freq_step ) > 0.001) { return false; }
        
    if (fabs( a.amplitude_ref - b.amplitude_ref ) > 0.001) { return false; }
        
    if (fabs( a.amplitude_unit - b.amplitude_unit ) > 0.001) { return false; }
          if (a.n_amplitude_value != b.n_amplitude_value) { return false; }
        for (size_t amplitude_value_idx = 0; amplitude_value_idx < (size_t)a.n_amplitude_value; amplitude_value_idx++)
        {
            
    if (a.amplitude_value[amplitude_value_idx] != b.amplitude_value[amplitude_value_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_specan_t &a, const sbp_msg_specan_t &b) {
  return !(a == b);
}
#endif
  /** RF AGC status
   *
 * This message describes the gain of each channel in the receiver frontend. Each 
 * gain is encoded as a non-dimensional percentage relative to the maximum range  
 * possible for the gain stage of the frontend. By convention, each gain array 
 * has 8 entries and the index of the array corresponding to the index of the rf channel 
 * in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
 * A negative value implies an error for the particular gain stage as reported by the frontend.
   */
#define SBP_MSG_FRONT_END_GAIN          0x00BF

typedef struct {
  
  /**
* RF gain for each frontend channel[percent]
   */
    s8
  rf_gain
    [8]
  ;
  /**
* Intermediate frequency gain for each frontend channel[percent]
   */
    s8
  if_gain
    [8]
  ;
} sbp_msg_front_end_gain_t;

static inline size_t sbp_packed_size_sbp_msg_front_end_gain_t(const sbp_msg_front_end_gain_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
		  ( 8 *
        sizeof( msg->rf_gain[0] )
		)                                                                          
	  +
		  ( 8 *
        sizeof( msg->if_gain[0] )
		);
}

static inline bool sbp_pack_sbp_msg_front_end_gain_t(u8 *buf, size_t len, const sbp_msg_front_end_gain_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_front_end_gain_t(msg) > len) { return false; }
  
		  for(size_t msgrf_gain_idx = 0; msgrf_gain_idx < 8; msgrf_gain_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  s8 msgrf_gainmsgrf_gain_idx = msg->rf_gain[msgrf_gain_idx];
  memcpy(buf + offset, & msgrf_gainmsgrf_gain_idx , 1);
  offset += 1;
			}
		  for(size_t msgif_gain_idx = 0; msgif_gain_idx < 8; msgif_gain_idx++)
			{
        
  if (offset + 1 > len) { return false; }
  s8 msgif_gainmsgif_gain_idx = msg->if_gain[msgif_gain_idx];
  memcpy(buf + offset, & msgif_gainmsgif_gain_idx , 1);
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_front_end_gain_t(const u8 *buf, size_t len, sbp_msg_front_end_gain_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
		for (size_t msgrf_gain_idx = 0; msgrf_gain_idx < 8; msgrf_gain_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->rf_gain[msgrf_gain_idx], buf + offset, 1);
  offset += 1;
		}
		for (size_t msgif_gain_idx = 0; msgif_gain_idx < 8; msgif_gain_idx++)
		{
        
  if (offset + 1 > len) { return false; }
  memcpy(&msg->if_gain[msgif_gain_idx], buf + offset, 1);
  offset += 1;
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  (void)a;
  (void)b;
  
        for (size_t rf_gain_idx = 0; rf_gain_idx < 8; rf_gain_idx++)
        {
            
    if (a.rf_gain[rf_gain_idx] != b.rf_gain[rf_gain_idx]) { return false; }
        }
        for (size_t if_gain_idx = 0; if_gain_idx < 8; if_gain_idx++)
        {
            
    if (a.if_gain[if_gain_idx] != b.if_gain[if_gain_idx]) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_front_end_gain_t &a, const sbp_msg_front_end_gain_t &b) {
  return !(a == b);
}
#endif


#endif /* LIBSBP_PIKSI_MESSAGES_H */