#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#define LIBSBP_ACQUISITION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>

#include <libsbp/common.h>
#include <libsbp/gnss.h>
  /** Satellite acquisition result
   *
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best carrier-to-noise (CN/0)
 * ratio.
   */
#define SBP_MSG_ACQ_RESULT         0x002F

	
	#define SBP_ACQ_RESULT_SID_CODE__MASK (0xff)
#define SBP_ACQ_RESULT_SID_CODE__SHIFT (0u)
#define SBP_ACQ_RESULT_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ACQ_RESULT_SID_CODE__SHIFT) \
                             & SBP_ACQ_RESULT_SID_CODE__MASK)
#define SBP_ACQ_RESULT_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ACQ_RESULT_SID_CODE__MASK)) \
                             << (SBP_ACQ_RESULT_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ACQ_RESULT_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_RESULT_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_RESULT_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_RESULT_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_RESULT_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_RESULT_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_RESULT_SID_CODE__GPS_L2P (6)
#define SBP_ACQ_RESULT_SID_CODE__BDS2_B1 (12)
#define SBP_ACQ_RESULT_SID_CODE__BDS2_B2 (13)
#define SBP_ACQ_RESULT_SID_CODE__GAL_E1B (14)
#define SBP_ACQ_RESULT_SID_CODE__GAL_E7I (20)
#define SBP_ACQ_RESULT_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* CN/0 of best point[dB Hz]
   */
    float
  cn0
  ;
  /**
* Code phase of best point[chips]
   */
    float
  cp
  ;
  /**
* Carrier frequency of best point[hz]
   */
    float
  cf
  ;
  /**
* GNSS signal for which acquisition was attempted
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
} sbp_msg_acq_result_t;

static inline size_t sbp_packed_size_sbp_msg_acq_result_t(const sbp_msg_acq_result_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->sid.sat )                                                                          
	  +
				sizeof( msg->sid.code ) );
}

static inline bool sbp_pack_sbp_msg_acq_result_t(u8 *buf, size_t len, const sbp_msg_acq_result_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  float msgcn0 = msg->cn0;
  memcpy(buf + offset, & msgcn0 , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  offset += 4;
				
        
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

static inline bool sbp_unpack_sbp_msg_acq_result_t(const u8 *buf, size_t len, sbp_msg_acq_result_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  offset += 4;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.sat, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->sid.code, buf + offset, 1);
  offset += 1;
  return true;
}
  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_ACQ_RESULT_DEP_C   0x001F

	
	#define SBP_ACQ_RESULT_DEP_C_SID_CODE__MASK (0xff)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__SHIFT (0u)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ACQ_RESULT_DEP_C_SID_CODE__SHIFT) \
                             & SBP_ACQ_RESULT_DEP_C_SID_CODE__MASK)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ACQ_RESULT_DEP_C_SID_CODE__MASK)) \
                             << (SBP_ACQ_RESULT_DEP_C_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_RESULT_DEP_C_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* CN/0 of best point[dB Hz]
   */
    float
  cn0
  ;
  /**
* Code phase of best point[chips]
   */
    float
  cp
  ;
  /**
* Carrier frequency of best point[hz]
   */
    float
  cf
  ;
  /**
* GNSS signal for which acquisition was attempted
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
} sbp_msg_acq_result_dep_c_t;

static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_c_t(const sbp_msg_acq_result_dep_c_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->cn0 )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
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

static inline bool sbp_pack_sbp_msg_acq_result_dep_c_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_c_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  float msgcn0 = msg->cn0;
  memcpy(buf + offset, & msgcn0 , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  offset += 4;
				
        
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

static inline bool sbp_unpack_sbp_msg_acq_result_dep_c_t(const u8 *buf, size_t len, sbp_msg_acq_result_dep_c_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cn0, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  offset += 4;
			
      
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
  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_ACQ_RESULT_DEP_B   0x0014

	
	#define SBP_ACQ_RESULT_DEP_B_SID_CODE__MASK (0xff)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__SHIFT (0u)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ACQ_RESULT_DEP_B_SID_CODE__SHIFT) \
                             & SBP_ACQ_RESULT_DEP_B_SID_CODE__MASK)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ACQ_RESULT_DEP_B_SID_CODE__MASK)) \
                             << (SBP_ACQ_RESULT_DEP_B_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_RESULT_DEP_B_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
 * SNR of best point. Currently in arbitrary SNR points, but will
 * be in units of dB Hz in a later revision of this message.
   */
    float
  snr
  ;
  /**
* Code phase of best point[chips]
   */
    float
  cp
  ;
  /**
* Carrier frequency of best point[hz]
   */
    float
  cf
  ;
  /**
* GNSS signal for which acquisition was attempted
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
} sbp_msg_acq_result_dep_b_t;

static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_b_t(const sbp_msg_acq_result_dep_b_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->snr )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
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

static inline bool sbp_pack_sbp_msg_acq_result_dep_b_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_b_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  float msgsnr = msg->snr;
  memcpy(buf + offset, & msgsnr , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  offset += 4;
				
        
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

static inline bool sbp_unpack_sbp_msg_acq_result_dep_b_t(const u8 *buf, size_t len, sbp_msg_acq_result_dep_b_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->snr, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  offset += 4;
			
      
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
  /** Deprecated
   *
* Deprecated.
   */
#define SBP_MSG_ACQ_RESULT_DEP_A   0x0015

typedef struct {
  
  /**
 * SNR of best point. Currently dimensonless, but will have
 * units of dB Hz in the revision of this message.
   */
    float
  snr
  ;
  /**
* Code phase of best point[chips]
   */
    float
  cp
  ;
  /**
* Carrier frequency of best point[hz]
   */
    float
  cf
  ;
  /**
 * PRN-1 identifier of the satellite signal for which
 * acquisition was attempted
   */
    u8
  prn
  ;
} sbp_msg_acq_result_dep_a_t;

static inline size_t sbp_packed_size_sbp_msg_acq_result_dep_a_t(const sbp_msg_acq_result_dep_a_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
				sizeof( msg->snr )                                                                          
	  +
				sizeof( msg->cp )                                                                          
	  +
				sizeof( msg->cf )                                                                          
	  +
				sizeof( msg->prn );
}

static inline bool sbp_pack_sbp_msg_acq_result_dep_a_t(u8 *buf, size_t len, const sbp_msg_acq_result_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_result_dep_a_t(msg) > len) { return false; }
  
        
  if (offset + 4 > len) { return false; }
  float msgsnr = msg->snr;
  memcpy(buf + offset, & msgsnr , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcp = msg->cp;
  memcpy(buf + offset, & msgcp , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  float msgcf = msg->cf;
  memcpy(buf + offset, & msgcf , 4);
  offset += 4;
        
  if (offset + 1 > len) { return false; }
  u8 msgprn = msg->prn;
  memcpy(buf + offset, & msgprn , 1);
  offset += 1;
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_result_dep_a_t(const u8 *buf, size_t len, sbp_msg_acq_result_dep_a_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->snr, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cp, buf + offset, 4);
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->cf, buf + offset, 4);
  offset += 4;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->prn, buf + offset, 1);
  offset += 1;
  return true;
}
  /** Acquisition perfomance measurement and debug
   *
 * The message describes all SV profiles during acquisition time.
 * The message is used to debug and measure the performance.
   */
#define SBP_MSG_ACQ_SV_PROFILE     0x002E

	
	
	#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__MASK (0xff)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SHIFT (0u)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SHIFT) \
                             & SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__MASK)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__MASK)) \
                             << (SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GPS_L2P (6)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__BDS2_B1 (12)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__BDS2_B2 (13)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GAL_E1B (14)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__GAL_E7I (20)
#define SBP_ACQ_SV_PROFILE_ACQ_SV_PROFILE_SID_CODE__BDS3_B2A (47)
typedef struct {
  
  /**
* SV profiles during acquisition time
   */
  struct {
    
  /**
* SV search job type (deep, fallback, etc)
   */
    u8
  job_type
  ;
  /**
* Acquisition status 1 is Success, 0 is Failure
   */
    u8
  status
  ;
  /**
* CN0 value. Only valid if status is '1'[dB-Hz*10]
   */
    u16
  cn0
  ;
  /**
* Acquisition integration time[ms]
   */
    u8
  int_time
  ;
  /**
* GNSS signal for which acquisition was attempted
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
  /**
* Acq frequency bin width[Hz]
   */
    u16
  bin_width
  ;
  /**
* Timestamp of the job complete event[ms]
   */
    u32
  timestamp
  ;
  /**
* Time spent to search for sid.code[us]
   */
    u32
  time_spent
  ;
  /**
* Doppler range lowest frequency[Hz]
   */
    s32
  cf_min
  ;
  /**
* Doppler range highest frequency[Hz]
   */
    s32
  cf_max
  ;
  /**
* Doppler value of detected peak. Only valid if status is '1'[Hz]
   */
    s32
  cf
  ;
  /**
* Codephase of detected peak. Only valid if status is '1'[chips*10]
   */
    u32
  cp
  ;
  }
  acq_sv_profile
    [7]
  ;
  /**
   * Number of items in acq_sv_profile
   */
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_t;

static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_t(const sbp_msg_acq_sv_profile_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_acq_sv_profile
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].job_type )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].status )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cn0 )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].int_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.sat )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.code ) )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].bin_width )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].timestamp )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].time_spent )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_min )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_max )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cp ) )
			);
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_t(u8 *buf, size_t len, const sbp_msg_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_sv_profile_t(msg) > len) { return false; }
  
			for(size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx < (size_t)msg->n_acq_sv_profile; msgacq_sv_profile_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxjob_type = msg->acq_sv_profile[msgacq_sv_profile_idx].job_type;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxjob_type , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxstatus = msg->acq_sv_profile[msgacq_sv_profile_idx].status;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxstatus , 1);
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxcn0 = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcn0 , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxint_time = msg->acq_sv_profile[msgacq_sv_profile_idx].int_time;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxint_time , 1);
  offset += 1;
				
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidsat = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidsat , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidcode = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidcode , 1);
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxbin_width = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxbin_width , 2);
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtimestamp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtimestamp , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtime_spent = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtime_spent , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_min , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_max , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcp , 4);
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_t(const u8 *buf, size_t len, sbp_msg_acq_sv_profile_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_acq_sv_profile = (u8)((len - offset) / 33);

	  for (size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx <
				msg->n_acq_sv_profile;
				msgacq_sv_profile_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].job_type, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].status, buf + offset, 1);
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cn0, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].int_time, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code, buf + offset, 1);
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_min = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_min );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_min;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_max = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_max );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_max;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf;
  msgacq_sv_profilemsgacq_sv_profile_idxcf = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  offset += 4;
		}
  return true;
}
  /** Deprecated.
   *
* Deprecated.
   */
#define SBP_MSG_ACQ_SV_PROFILE_DEP 0x001E

	
	
	#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__MASK (0xff)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SHIFT (0u)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GET(flags) \
                             (((flags) >> SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SHIFT) \
                             & SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__MASK)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__MASK)) \
                             << (SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SHIFT)));} while(0)
                             

#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L1CA (0)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L2CM (1)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__SBAS_L1CA (2)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GLO_L1CA (3)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GLO_L2CA (4)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L1P (5)
#define SBP_ACQ_SV_PROFILE_DEP_ACQ_SV_PROFILE_SID_CODE__GPS_L2P (6)
typedef struct {
  
  /**
* SV profiles during acquisition time
   */
  struct {
    
  /**
* SV search job type (deep, fallback, etc)
   */
    u8
  job_type
  ;
  /**
* Acquisition status 1 is Success, 0 is Failure
   */
    u8
  status
  ;
  /**
* CN0 value. Only valid if status is '1'[dB-Hz*10]
   */
    u16
  cn0
  ;
  /**
* Acquisition integration time[ms]
   */
    u8
  int_time
  ;
  /**
* GNSS signal for which acquisition was attempted
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
  /**
* Acq frequency bin width[Hz]
   */
    u16
  bin_width
  ;
  /**
* Timestamp of the job complete event[ms]
   */
    u32
  timestamp
  ;
  /**
* Time spent to search for sid.code[us]
   */
    u32
  time_spent
  ;
  /**
* Doppler range lowest frequency[Hz]
   */
    s32
  cf_min
  ;
  /**
* Doppler range highest frequency[Hz]
   */
    s32
  cf_max
  ;
  /**
* Doppler value of detected peak. Only valid if status is '1'[Hz]
   */
    s32
  cf
  ;
  /**
* Codephase of detected peak. Only valid if status is '1'[chips*10]
   */
    u32
  cp
  ;
  }
  acq_sv_profile
    [7]
  ;
  /**
   * Number of items in acq_sv_profile
   */
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_dep_t;

static inline size_t sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(const sbp_msg_acq_sv_profile_dep_t *msg) {                                
	(void)msg;
  return                                                          
	0                                                                          
	  +
	    (
			  msg->n_acq_sv_profile
			*
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].job_type )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].status )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cn0 )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].int_time )                                                                          
	  +
				(                                                          
	0                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.sat )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.code )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].sid.reserved ) )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].bin_width )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].timestamp )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].time_spent )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_min )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf_max )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cf )                                                                          
	  +
				sizeof( msg->acq_sv_profile[0].cp ) )
			);
}

static inline bool sbp_pack_sbp_msg_acq_sv_profile_dep_t(u8 *buf, size_t len, const sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  if ( sbp_packed_size_sbp_msg_acq_sv_profile_dep_t(msg) > len) { return false; }
  
			for(size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx < (size_t)msg->n_acq_sv_profile; msgacq_sv_profile_idx++)
			{
					
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxjob_type = msg->acq_sv_profile[msgacq_sv_profile_idx].job_type;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxjob_type , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxstatus = msg->acq_sv_profile[msgacq_sv_profile_idx].status;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxstatus , 1);
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxcn0 = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcn0 , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxint_time = msg->acq_sv_profile[msgacq_sv_profile_idx].int_time;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxint_time , 1);
  offset += 1;
				
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxsidsat = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidsat , 2);
  offset += 2;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidcode = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidcode , 1);
  offset += 1;
        
  if (offset + 1 > len) { return false; }
  u8 msgacq_sv_profilemsgacq_sv_profile_idxsidreserved = msg->acq_sv_profile[msgacq_sv_profile_idx].sid.reserved;
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxsidreserved , 1);
  offset += 1;
        
  if (offset + 2 > len) { return false; }
  u16 msgacq_sv_profilemsgacq_sv_profile_idxbin_width = htole16( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxbin_width , 2);
  offset += 2;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtimestamp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtimestamp , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxtime_spent = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxtime_spent , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_min , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf_max , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = htole32( *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcf , 4);
  offset += 4;
        
  if (offset + 4 > len) { return false; }
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcp = htole32( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  memcpy(buf + offset, & msgacq_sv_profilemsgacq_sv_profile_idxcp , 4);
  offset += 4;
			}
  return true;
}

static inline bool sbp_unpack_sbp_msg_acq_sv_profile_dep_t(const u8 *buf, size_t len, sbp_msg_acq_sv_profile_dep_t *msg) {
  size_t offset = 0;
	(void)offset;
	(void)buf;
	(void)len;
	(void)msg;
  
      msg->n_acq_sv_profile = (u8)((len - offset) / 35);

	  for (size_t msgacq_sv_profile_idx = 0; msgacq_sv_profile_idx <
				msg->n_acq_sv_profile;
				msgacq_sv_profile_idx++) 
		{
				
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].job_type, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].status, buf + offset, 1);
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cn0, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cn0 );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].int_time, buf + offset, 1);
  offset += 1;
			
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].sid.sat );
  offset += 2;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.code, buf + offset, 1);
  offset += 1;
      
  if (offset + 1 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].sid.reserved, buf + offset, 1);
  offset += 1;
      
  if (offset + 2 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width, buf + offset, 2);
  msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width = le16toh( msg->acq_sv_profile[msgacq_sv_profile_idx].bin_width );
  offset += 2;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].timestamp );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].time_spent );
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_min = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_min = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_min );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_min = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_min;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf_max = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max;
  msgacq_sv_profilemsgacq_sv_profile_idxcf_max = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf_max );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf_max = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf_max;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cf, buf + offset, 4);
  u32 msgacq_sv_profilemsgacq_sv_profile_idxcf = *(const u32*)&msg->acq_sv_profile[msgacq_sv_profile_idx].cf;
  msgacq_sv_profilemsgacq_sv_profile_idxcf = le32toh( msgacq_sv_profilemsgacq_sv_profile_idxcf );
  msg->acq_sv_profile[msgacq_sv_profile_idx].cf = *(const s32*)&msgacq_sv_profilemsgacq_sv_profile_idxcf;
  offset += 4;
      
  if (offset + 4 > len) { return false; }
  memcpy(&msg->acq_sv_profile[msgacq_sv_profile_idx].cp, buf + offset, 4);
  msg->acq_sv_profile[msgacq_sv_profile_idx].cp = le32toh( msg->acq_sv_profile[msgacq_sv_profile_idx].cp );
  offset += 4;
		}
  return true;
}


#endif /* LIBSBP_ACQUISITION_MESSAGES_H */