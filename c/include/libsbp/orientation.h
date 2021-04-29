#ifndef LIBSBP_ORIENTATION_MESSAGES_H
#define LIBSBP_ORIENTATION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

#include <libsbp/common.h>
  /** Heading relative to True North
   *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
 * that time-matched RTK mode is used when the base station is moving.
   */
#define SBP_MSG_BASELINE_HEADING 0x020F

	#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_MASK (0x7)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SHIFT (0u)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_GET(flags) \
                             (((flags) >> SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SHIFT) \
                             & SBP_BASELINE_HEADING_FLAGS_FIX_MODE_MASK)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_BASELINE_HEADING_FLAGS_FIX_MODE_MASK)) \
                             << (SBP_BASELINE_HEADING_FLAGS_FIX_MODE_SHIFT)));} while(0)
                             

#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_INVALID (0)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_DIFFERENTIAL_GNSS (2)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_FLOAT_RTK (3)
#define SBP_BASELINE_HEADING_FLAGS_FIX_MODE_FIXED_RTK (4)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Heading[mdeg]
   */
    u32
  heading
  ;
  /**
* Number of satellites used in solution
   */
    u8
  n_sats
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_baseline_heading_t;

static inline size_t sbp_packed_size_sbp_msg_baseline_heading_t(const sbp_msg_baseline_heading_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->heading )                                                                          
	  +
				sizeof( msg->n_sats )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_baseline_heading_t(u8 *buf, size_t len, const sbp_msg_baseline_heading_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_baseline_heading_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgheading = htole32( msg->heading );
  memcpy(buf + offset, & msgheading , 4);
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgn_sats = msg->n_sats;
  memcpy(buf + offset, & msgn_sats , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_baseline_heading_t(const u8 *buf, size_t len, sbp_msg_baseline_heading_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->heading, buf + offset, 4);
  msg->heading = le32toh( msg->heading );
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->n_sats, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}
  /** Quaternion 4 component vector
   *
 * This message reports the quaternion vector describing the vehicle body frame's orientation
 * with respect to a local-level NED frame. The components of the vector should sum to a unit
 * vector assuming that the LSB of each component as a value of 2^-31. This message will only
 * be available in future INS versions of Swift Products and is not produced by Piksi Multi 
 * or Duro.
   */
#define SBP_MSG_ORIENT_QUAT      0x0220

	#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_QUAT_FLAGS_INS_NAVIGATION_MODE_VALID (1)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* Real component[2^-31]
   */
    s32
  w
  ;
  /**
* 1st imaginary component[2^-31]
   */
    s32
  x
  ;
  /**
* 2nd imaginary component[2^-31]
   */
    s32
  y
  ;
  /**
* 3rd imaginary component[2^-31]
   */
    s32
  z
  ;
  /**
* Estimated standard deviation of w[N/A]
   */
    float
  w_accuracy
  ;
  /**
* Estimated standard deviation of x[N/A]
   */
    float
  x_accuracy
  ;
  /**
* Estimated standard deviation of y[N/A]
   */
    float
  y_accuracy
  ;
  /**
* Estimated standard deviation of z[N/A]
   */
    float
  z_accuracy
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_orient_quat_t;

static inline size_t sbp_packed_size_sbp_msg_orient_quat_t(const sbp_msg_orient_quat_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->w )                                                                          
	  +
				sizeof( msg->x )                                                                          
	  +
				sizeof( msg->y )                                                                          
	  +
				sizeof( msg->z )                                                                          
	  +
				sizeof( msg->w_accuracy )                                                                          
	  +
				sizeof( msg->x_accuracy )                                                                          
	  +
				sizeof( msg->y_accuracy )                                                                          
	  +
				sizeof( msg->z_accuracy )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_orient_quat_t(u8 *buf, size_t len, const sbp_msg_orient_quat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_orient_quat_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgw = htole32( *(const u32*)&msg->w );
  memcpy(buf + offset, & msgw , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgx = htole32( *(const u32*)&msg->x );
  memcpy(buf + offset, & msgx , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgy = htole32( *(const u32*)&msg->y );
  memcpy(buf + offset, & msgy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgz = htole32( *(const u32*)&msg->z );
  memcpy(buf + offset, & msgz , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgw_accuracy = msg->w_accuracy;
  memcpy(buf + offset, & msgw_accuracy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgx_accuracy = msg->x_accuracy;
  memcpy(buf + offset, & msgx_accuracy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgy_accuracy = msg->y_accuracy;
  memcpy(buf + offset, & msgy_accuracy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgz_accuracy = msg->z_accuracy;
  memcpy(buf + offset, & msgz_accuracy , 4);
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_quat_t(const u8 *buf, size_t len, sbp_msg_orient_quat_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->w, buf + offset, 4);
  u32 msgw = *(const u32*)&msg->w;
  msgw = le32toh( msgw );
  msg->w = *(const s32*)&msgw;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32*)&msg->x;
  msgx = le32toh( msgx );
  msg->x = *(const s32*)&msgx;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32*)&msg->y;
  msgy = le32toh( msgy );
  msg->y = *(const s32*)&msgy;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32*)&msg->z;
  msgz = le32toh( msgz );
  msg->z = *(const s32*)&msgz;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->w_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->x_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->y_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->z_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}
  /** Euler angles
   *
 * This message reports the yaw, pitch, and roll angles of the vehicle body frame.
 * The rotations should applied intrinsically in the order yaw, pitch, and roll 
 * in order to rotate the from a frame aligned with the local-level NED frame 
 * to the vehicle body frame.  This message will only be available in future 
 * INS versions of Swift Products and is not produced by Piksi Multi or Duro.
   */
#define SBP_MSG_ORIENT_EULER     0x0221

	#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ORIENT_EULER_FLAGS_INS_NAVIGATION_MODE_VALID (1)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* rotation about the forward axis of the vehicle[microdegrees]
   */
    s32
  roll
  ;
  /**
* rotation about the rightward axis of the vehicle[microdegrees]
   */
    s32
  pitch
  ;
  /**
* rotation about the downward axis of the vehicle[microdegrees]
   */
    s32
  yaw
  ;
  /**
* Estimated standard deviation of roll[degrees]
   */
    float
  roll_accuracy
  ;
  /**
* Estimated standard deviation of pitch[degrees]
   */
    float
  pitch_accuracy
  ;
  /**
* Estimated standard deviation of yaw[degrees]
   */
    float
  yaw_accuracy
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_orient_euler_t;

static inline size_t sbp_packed_size_sbp_msg_orient_euler_t(const sbp_msg_orient_euler_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->roll )                                                                          
	  +
				sizeof( msg->pitch )                                                                          
	  +
				sizeof( msg->yaw )                                                                          
	  +
				sizeof( msg->roll_accuracy )                                                                          
	  +
				sizeof( msg->pitch_accuracy )                                                                          
	  +
				sizeof( msg->yaw_accuracy )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_orient_euler_t(u8 *buf, size_t len, const sbp_msg_orient_euler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_orient_euler_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgroll = htole32( *(const u32*)&msg->roll );
  memcpy(buf + offset, & msgroll , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgpitch = htole32( *(const u32*)&msg->pitch );
  memcpy(buf + offset, & msgpitch , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgyaw = htole32( *(const u32*)&msg->yaw );
  memcpy(buf + offset, & msgyaw , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgroll_accuracy = msg->roll_accuracy;
  memcpy(buf + offset, & msgroll_accuracy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgpitch_accuracy = msg->pitch_accuracy;
  memcpy(buf + offset, & msgpitch_accuracy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgyaw_accuracy = msg->yaw_accuracy;
  memcpy(buf + offset, & msgyaw_accuracy , 4);
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_orient_euler_t(const u8 *buf, size_t len, sbp_msg_orient_euler_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->roll, buf + offset, 4);
  u32 msgroll = *(const u32*)&msg->roll;
  msgroll = le32toh( msgroll );
  msg->roll = *(const s32*)&msgroll;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->pitch, buf + offset, 4);
  u32 msgpitch = *(const u32*)&msg->pitch;
  msgpitch = le32toh( msgpitch );
  msg->pitch = *(const s32*)&msgpitch;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->yaw, buf + offset, 4);
  u32 msgyaw = *(const u32*)&msg->yaw;
  msgyaw = le32toh( msgyaw );
  msg->yaw = *(const s32*)&msgyaw;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->roll_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->pitch_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->yaw_accuracy, buf + offset, 4);
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}
  /** Vehicle Body Frame instantaneous angular rates
   *
 * This message reports the orientation rates in the vehicle body frame. 
 * The values represent the measurements a strapped down gyroscope would 
 * make and are not equivalent to the time derivative of the Euler angles.
 * The orientation and origin of the user frame is specified via device settings.
 * By convention, the vehicle x-axis is expected to be aligned with the forward
 * direction, while the vehicle y-axis is expected to be aligned with the right
 * direction, and the vehicle z-axis should be aligned with the down direction.
 * This message will only be available in future INS versions of Swift Products 
 * and is not produced by Piksi Multi or Duro.
   */
#define SBP_MSG_ANGULAR_RATE     0x0222

	#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_MASK (0x7)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SHIFT (0u)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_GET(flags) \
                             (((flags) >> SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SHIFT) \
                             & SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_MASK)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_MASK)) \
                             << (SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_SHIFT)));} while(0)
                             

#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_INVALID (0)
#define SBP_ANGULAR_RATE_FLAGS_INS_NAVIGATION_MODE_VALID (1)
typedef struct {
  
  /**
* GPS Time of Week[ms]
   */
    u32
  tow
  ;
  /**
* angular rate about x axis[microdegrees/s]
   */
    s32
  x
  ;
  /**
* angular rate about y axis[microdegrees/s]
   */
    s32
  y
  ;
  /**
* angular rate about z axis[microdegrees/s]
   */
    s32
  z
  ;
  /**
* Status flags
   */
    u8
  flags
  ;
} sbp_msg_angular_rate_t;

static inline size_t sbp_packed_size_sbp_msg_angular_rate_t(const sbp_msg_angular_rate_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->tow )                                                                          
	  +
				sizeof( msg->x )                                                                          
	  +
				sizeof( msg->y )                                                                          
	  +
				sizeof( msg->z )                                                                          
	  +
				sizeof( msg->flags );
}

static inline bool sbp_pack_sbp_msg_angular_rate_t(u8 *buf, size_t len, const sbp_msg_angular_rate_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_angular_rate_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  u32 msgtow = htole32( msg->tow );
  memcpy(buf + offset, & msgtow , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgx = htole32( *(const u32*)&msg->x );
  memcpy(buf + offset, & msgx , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgy = htole32( *(const u32*)&msg->y );
  memcpy(buf + offset, & msgy , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgz = htole32( *(const u32*)&msg->z );
  memcpy(buf + offset, & msgz , 4);
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgflags = msg->flags;
  memcpy(buf + offset, & msgflags , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_angular_rate_t(const u8 *buf, size_t len, sbp_msg_angular_rate_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->tow, buf + offset, 4);
  msg->tow = le32toh( msg->tow );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->x, buf + offset, 4);
  u32 msgx = *(const u32*)&msg->x;
  msgx = le32toh( msgx );
  msg->x = *(const s32*)&msgx;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->y, buf + offset, 4);
  u32 msgy = *(const u32*)&msg->y;
  msgy = le32toh( msgy );
  msg->y = *(const s32*)&msgy;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->z, buf + offset, 4);
  u32 msgz = *(const u32*)&msg->z;
  msgz = le32toh( msgz );
  msg->z = *(const s32*)&msgz;
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->flags, buf + offset, 1);
  offset += 1;
  return true;
}


#endif /* LIBSBP_ORIENTATION_MESSAGES_H */