#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#define LIBSBP_SOLUTION_META_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
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
  struct {
    
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
  }
  sol_in
    [118]
  ;
  /**
   * Number of items in sol_in
   */
  u8 n_sol_in;
} sbp_msg_soln_meta_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->pdop )                                                                          
	  +
				sizeof( msg->hdop )                                                                          
	  +
				sizeof( msg->vdop )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->age_corrections )                                                                          
	  +
				sizeof( msg->alignment_status )                                                                          
	  +
				sizeof( msg->last_used_gnss_pos_tow )                                                                          
	  +
				sizeof( msg->last_used_gnss_vel_tow )                                                                          
	  +
	    (
			  msg->n_sol_in
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sol_in[0].sensor_type )                                                                          
	  +
				sizeof( msg->sol_in[0].flags ) )
			);
}

static inline bool sbp_pack_sbp_msg_soln_meta_dep_a_t(u8 *buf, size_t len, const sbp_msg_soln_meta_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_soln_meta_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 2 > len) { return false; }
  u16 msgpdop = htole16( msg->pdop );
  memcpy(buf + offset, & msgpdop , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msghdop = htole16( msg->hdop );
  memcpy(buf + offset, & msghdop , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgvdop = htole16( msg->vdop );
  memcpy(buf + offset, & msgvdop , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, & msgn_sats , 1);
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgage_corrections = htole16( msg->age_corrections );
  memcpy(buf + offset, & msgage_corrections , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgalignment_status = msg->alignment_status;
  memcpy(buf + offset, & msgalignment_status , 1);
  offset += 1;
        
  if (offset + 4 > len) { return false; }
  u32 msglast_used_gnss_pos_tow = htole32( msg->last_used_gnss_pos_tow );
  memcpy(buf + offset, & msglast_used_gnss_pos_tow , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msglast_used_gnss_vel_tow = htole32( msg->last_used_gnss_vel_tow );
  memcpy(buf + offset, & msglast_used_gnss_vel_tow , 4);
  offset += 4;
			for(size_t msgsol_in_idx = 0; msgsol_in_idx < (size_t)msg->n_sol_in; msgsol_in_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  u8 msgsol_inmsgsol_in_idxsensor_type = msg->sol_in[msgsol_in_idx].sensor_type;
  memcpy(buf + offset, & msgsol_inmsgsol_in_idxsensor_type , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsol_inmsgsol_in_idxflags = msg->sol_in[msgsol_in_idx].flags;
  memcpy(buf + offset, & msgsol_inmsgsol_in_idxflags , 1);
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_dep_a_t(const u8 *buf, size_t len, sbp_msg_soln_meta_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh( msg->pdop );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh( msg->hdop );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh( msg->vdop );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->age_corrections, buf + offset, 2);
  msg->age_corrections = le16toh( msg->age_corrections );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->alignment_status, buf + offset, 1);
  offset += 1;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->last_used_gnss_pos_tow, buf + offset, 4);
  msg->last_used_gnss_pos_tow = le32toh( msg->last_used_gnss_pos_tow );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->last_used_gnss_vel_tow, buf + offset, 4);
  msg->last_used_gnss_vel_tow = le32toh( msg->last_used_gnss_vel_tow );
  offset += 4;
      msg->n_sol_in = (u8)((len - offset) / 2);

	  for (size_t msgsol_in_idx = 0; msgsol_in_idx <
				msg->n_sol_in;
				msgsol_in_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].sensor_type, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].flags, buf + offset, 1);
  offset += 1;
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.pdop != b.pdop) { return false; }
        
    if (a.hdop != b.hdop) { return false; }
        
    if (a.vdop != b.vdop) { return false; }
        
    if (a.n_sats != b.n_sats) { return false; }
        
    if (a.age_corrections != b.age_corrections) { return false; }
        
    if (a.alignment_status != b.alignment_status) { return false; }
        
    if (a.last_used_gnss_pos_tow != b.last_used_gnss_pos_tow) { return false; }
        
    if (a.last_used_gnss_vel_tow != b.last_used_gnss_vel_tow) { return false; }
          if (a.n_sol_in != b.n_sol_in) { return false; }
        for (size_t sol_in_idx = 0; sol_in_idx < (size_t)a.n_sol_in; sol_in_idx++)
        {
            
        
    if (a.sol_in[sol_in_idx].sensor_type != b.sol_in[sol_in_idx].sensor_type) { return false; }
        
    if (a.sol_in[sol_in_idx].flags != b.sol_in[sol_in_idx].flags) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_soln_meta_dep_a_t &a, const sbp_msg_soln_meta_dep_a_t &b) {
  return !(a == b);
}
#endif
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
  struct {
    
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
  }
  sol_in
    [119]
  ;
  /**
   * Number of items in sol_in
   */
  u8 n_sol_in;
} sbp_msg_soln_meta_t;

static inline size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->pdop )                                                                          
	  +
				sizeof( msg->hdop )                                                                          
	  +
				sizeof( msg->vdop )                                                                          
	  +
				sizeof( msg->age_corrections )                                                                          
	  +
				sizeof( msg->age_gnss )                                                                          
	  +
	    (
			  msg->n_sol_in
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sol_in[0].sensor_type )                                                                          
	  +
				sizeof( msg->sol_in[0].flags ) )
			);
}

static inline bool sbp_pack_sbp_msg_soln_meta_t(u8 *buf, size_t len, const sbp_msg_soln_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_soln_meta_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  offset += 4;
        
  if (offset + 2 > len) { return false; }
  u16 msgpdop = htole16( msg->pdop );
  memcpy(buf + offset, & msgpdop , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msghdop = htole16( msg->hdop );
  memcpy(buf + offset, & msghdop , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgvdop = htole16( msg->vdop );
  memcpy(buf + offset, & msgvdop , 2);
  offset += 2;
        
  if (offset + 2 > len) { return false; }
  u16 msgage_corrections = htole16( msg->age_corrections );
  memcpy(buf + offset, & msgage_corrections , 2);
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgage_gnss = htole32( msg->age_gnss );
  memcpy(buf + offset, & msgage_gnss , 4);
  offset += 4;
			for(size_t msgsol_in_idx = 0; msgsol_in_idx < (size_t)msg->n_sol_in; msgsol_in_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  u8 msgsol_inmsgsol_in_idxsensor_type = msg->sol_in[msgsol_in_idx].sensor_type;
  memcpy(buf + offset, & msgsol_inmsgsol_in_idxsensor_type , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgsol_inmsgsol_in_idxflags = msg->sol_in[msgsol_in_idx].flags;
  memcpy(buf + offset, & msgsol_inmsgsol_in_idxflags , 1);
  offset += 1;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_soln_meta_t(const u8 *buf, size_t len, sbp_msg_soln_meta_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  offset += 4;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->pdop, buf + offset, 2);
  msg->pdop = le16toh( msg->pdop );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->hdop, buf + offset, 2);
  msg->hdop = le16toh( msg->hdop );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->vdop, buf + offset, 2);
  msg->vdop = le16toh( msg->vdop );
  offset += 2;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->age_corrections, buf + offset, 2);
  msg->age_corrections = le16toh( msg->age_corrections );
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->age_gnss, buf + offset, 4);
  msg->age_gnss = le32toh( msg->age_gnss );
  offset += 4;
      msg->n_sol_in = (u8)((len - offset) / 2);

	  for (size_t msgsol_in_idx = 0; msgsol_in_idx <
				msg->n_sol_in;
				msgsol_in_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].sensor_type, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sol_in[msgsol_in_idx].flags, buf + offset, 1);
  offset += 1;
		}
  return true;
}

#ifdef __cplusplus
static inline bool operator== ( const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  (void)a;
  (void)b;
  
        
    if (a.tow != b.tow) { return false; }
        
    if (a.pdop != b.pdop) { return false; }
        
    if (a.hdop != b.hdop) { return false; }
        
    if (a.vdop != b.vdop) { return false; }
        
    if (a.age_corrections != b.age_corrections) { return false; }
        
    if (a.age_gnss != b.age_gnss) { return false; }
          if (a.n_sol_in != b.n_sol_in) { return false; }
        for (size_t sol_in_idx = 0; sol_in_idx < (size_t)a.n_sol_in; sol_in_idx++)
        {
            
        
    if (a.sol_in[sol_in_idx].sensor_type != b.sol_in[sol_in_idx].sensor_type) { return false; }
        
    if (a.sol_in[sol_in_idx].flags != b.sol_in[sol_in_idx].flags) { return false; }
        }

  return true;
}

static inline bool operator!=(const sbp_msg_soln_meta_t &a, const sbp_msg_soln_meta_t &b) {
  return !(a == b);
}
#endif


#endif /* LIBSBP_SOLUTION_META_MESSAGES_H */