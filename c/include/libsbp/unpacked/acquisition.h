#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#define LIBSBP_ACQUISITION_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#include <libsbp/unpacked/gnss.h>
/** Satellite acquisition result
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ACQ_RESULT         0x002F
typedef struct {
  float cn0;
  float cp;
  float cf;
  sbp_sbp_gnss_signal_t sid;
} sbp_msg_acq_result_t;


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ACQ_RESULT_DEP_C   0x001F
typedef struct {
  float cn0;
  float cp;
  float cf;
  sbp_gnss_signal_dep_t sid;
} sbp_msg_acq_result_dep_c_t;


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ACQ_RESULT_DEP_B   0x0014
typedef struct {
  float snr;
  float cp;
  float cf;
  sbp_gnss_signal_dep_t sid;
} sbp_msg_acq_result_dep_b_t;


/** Deprecated
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ACQ_RESULT_DEP_A   0x0015
typedef struct {
  float snr;
  float cp;
  float cf;
  u8 prn;
} sbp_msg_acq_result_dep_a_t;


/** Acq perfomance measurement and debug
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 job_type;
  u8 status;
  u16 cn0;
  u8 int_time;
  sbp_sbp_gnss_signal_t sid;
  u16 bin_width;
  u32 timestamp;
  u32 time_spent;
  s32 cf_min;
  s32 cf_max;
  s32 cf;
  u32 cp;
} sbp_acq_sv_profile_t;


/** Deprecated
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 job_type;
  u8 status;
  u16 cn0;
  u8 int_time;
  sbp_gnss_signal_dep_t sid;
  u16 bin_width;
  u32 timestamp;
  u32 time_spent;
  s32 cf_min;
  s32 cf_max;
  s32 cf;
  u32 cp;
} sbp_acq_sv_profile_dep_t;


/** Acquisition perfomance measurement and debug
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ACQ_SV_PROFILE     0x002E
typedef struct {
  sbp_acq_sv_profile_t acq_sv_profile[7];
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_t;


/** Deprecated.
 *
((m.desc|commentify)))
 */
#define SBP_MSG_ACQ_SV_PROFILE_DEP 0x001E
typedef struct {
  sbp_acq_sv_profile_dep_t acq_sv_profile[7];
  u8 n_acq_sv_profile;
} sbp_msg_acq_sv_profile_dep_t;



#include <libsbp/unpacked/acquisition_operators.h>
#include <libsbp/unpacked/acquisition_packers.h>

#endif /* LIBSBP_ACQUISITION_MESSAGES_H */
