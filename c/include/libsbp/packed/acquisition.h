/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup acquisition Acquisition
 *
 * * Satellite acquisition messages from the device.
 * \{ */

#ifndef LIBSBP_PACKED_ACQUISITION_MESSAGES_H
#define LIBSBP_PACKED_ACQUISITION_MESSAGES_H

#include <libsbp/common.h>
#include <libsbp/packed/gnss.h>

SBP_PACK_START


/** Satellite acquisition result
 *
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best carrier-to-noise (CN/0)
 * ratio.
 */
#define SBP_MSG_ACQ_RESULT         0x002F
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * CN/0 of best point [dB Hz] 
   */
  float cn0;   
  
  /** 
   * Code phase of best point [chips] 
   */
  float cp;    
  
  /** 
   * Carrier frequency of best point [hz] 
   */
  float cf;    
  
  /** 
   * GNSS signal for which acquisition was attempted 
   */
  sbp_gnss_signal_t sid;   
  
} msg_acq_result_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_C   0x001F
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * CN/0 of best point [dB Hz] 
   */
  float cn0;   
  
  /** 
   * Code phase of best point [chips] 
   */
  float cp;    
  
  /** 
   * Carrier frequency of best point [hz] 
   */
  float cf;    
  
  /** 
   * GNSS signal for which acquisition was attempted 
   */
  gnss_signal_dep_t sid;   
  
} msg_acq_result_dep_c_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_B   0x0014
typedef struct SBP_ATTR_PACKED {
  
  /** 
    * SNR of best point. Currently in arbitrary SNR points, but will
 * be in units of dB Hz in a later revision of this message. 
   */
  float snr;   
  
  /** 
   * Code phase of best point [chips] 
   */
  float cp;    
  
  /** 
   * Carrier frequency of best point [hz] 
   */
  float cf;    
  
  /** 
   * GNSS signal for which acquisition was attempted 
   */
  gnss_signal_dep_t sid;   
  
} msg_acq_result_dep_b_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_A   0x0015
typedef struct SBP_ATTR_PACKED {
  
  /** 
    * SNR of best point. Currently dimensonless, but will have
 * units of dB Hz in the revision of this message. 
   */
  float snr;   
  
  /** 
   * Code phase of best point [chips] 
   */
  float cp;    
  
  /** 
   * Carrier frequency of best point [hz] 
   */
  float cf;    
  
  /** 
    * PRN-1 identifier of the satellite signal for which
 * acquisition was attempted 
   */
  u8 prn;   
  
} msg_acq_result_dep_a_t;


/** Acq perfomance measurement and debug
 *
 * Profile for a specific SV for debugging purposes
 * The message describes SV profile during acquisition time.
 * The message is used to debug and measure the performance.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * SV search job type (deep, fallback, etc) 
   */
  u8 job_type;     
  
  /** 
   * Acquisition status 1 is Success, 0 is Failure 
   */
  u8 status;       
  
  /** 
   * CN0 value. Only valid if status is '1' [dB-Hz*10] 
   */
  u16 cn0;          
  
  /** 
   * Acquisition integration time [ms] 
   */
  u8 int_time;     
  
  /** 
   * GNSS signal for which acquisition was attempted 
   */
  sbp_gnss_signal_t sid;          
  
  /** 
   * Acq frequency bin width [Hz] 
   */
  u16 bin_width;    
  
  /** 
   * Timestamp of the job complete event [ms] 
   */
  u32 timestamp;    
  
  /** 
   * Time spent to search for sid.code [us] 
   */
  u32 time_spent;   
  
  /** 
   * Doppler range lowest frequency [Hz] 
   */
  s32 cf_min;       
  
  /** 
   * Doppler range highest frequency [Hz] 
   */
  s32 cf_max;       
  
  /** 
   * Doppler value of detected peak. Only valid if status is '1' [Hz] 
   */
  s32 cf;           
  
  /** 
   * Codephase of detected peak. Only valid if status is '1' [chips*10] 
   */
  u32 cp;           
  
} acq_sv_profile_t;


/** Deprecated
 *
* Deprecated.
 */
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * SV search job type (deep, fallback, etc) 
   */
  u8 job_type;     
  
  /** 
   * Acquisition status 1 is Success, 0 is Failure 
   */
  u8 status;       
  
  /** 
   * CN0 value. Only valid if status is '1' [dB-Hz*10] 
   */
  u16 cn0;          
  
  /** 
   * Acquisition integration time [ms] 
   */
  u8 int_time;     
  
  /** 
   * GNSS signal for which acquisition was attempted 
   */
  gnss_signal_dep_t sid;          
  
  /** 
   * Acq frequency bin width [Hz] 
   */
  u16 bin_width;    
  
  /** 
   * Timestamp of the job complete event [ms] 
   */
  u32 timestamp;    
  
  /** 
   * Time spent to search for sid.code [us] 
   */
  u32 time_spent;   
  
  /** 
   * Doppler range lowest frequency [Hz] 
   */
  s32 cf_min;       
  
  /** 
   * Doppler range highest frequency [Hz] 
   */
  s32 cf_max;       
  
  /** 
   * Doppler value of detected peak. Only valid if status is '1' [Hz] 
   */
  s32 cf;           
  
  /** 
   * Codephase of detected peak. Only valid if status is '1' [chips*10] 
   */
  u32 cp;           
  
} acq_sv_profile_dep_t;


/** Acquisition perfomance measurement and debug
 *
 * The message describes all SV profiles during acquisition time.
 * The message is used to debug and measure the performance.
 */
#define SBP_MSG_ACQ_SV_PROFILE     0x002E
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * SV profiles during acquisition time 
   */
  acq_sv_profile_t acq_sv_profile[0];
  
} msg_acq_sv_profile_t;


/** Deprecated.
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_SV_PROFILE_DEP 0x001E
typedef struct SBP_ATTR_PACKED {
  
  /** 
   * SV profiles during acquisition time 
   */
  acq_sv_profile_dep_t acq_sv_profile[0];
  
} msg_acq_sv_profile_dep_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_ACQUISITION_MESSAGES_H */