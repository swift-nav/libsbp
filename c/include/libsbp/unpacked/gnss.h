#ifndef LIBSBP_GNSS_MESSAGES_H
#define LIBSBP_GNSS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/string.h>
#define SBP_GNSSSIGNAL__MASK (0xff)
#define SBP_GNSSSIGNAL__SHIFT (0u)
#define SBP_GNSSSIGNAL__GET(flags) \
                             (((flags) >> SBP_GNSSSIGNAL__SHIFT) \
                             & SBP_GNSSSIGNAL__MASK)
#define SBP_GNSSSIGNAL__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GNSSSIGNAL__MASK)) \
                             << (SBP_GNSSSIGNAL__SHIFT)));} while(0)
                             

#define SBP_GNSSSIGNAL__GPS_L1CA (0)
#define SBP_GNSSSIGNAL__GPS_L2CM (1)
#define SBP_GNSSSIGNAL__SBAS_L1CA (2)
#define SBP_GNSSSIGNAL__GLO_L1CA (3)
#define SBP_GNSSSIGNAL__GLO_L2CA (4)
#define SBP_GNSSSIGNAL__GPS_L1P (5)
#define SBP_GNSSSIGNAL__GPS_L2P (6)
#define SBP_GNSSSIGNAL__BDS2_B1 (12)
#define SBP_GNSSSIGNAL__BDS2_B2 (13)
#define SBP_GNSSSIGNAL__GAL_E1B (14)
#define SBP_GNSSSIGNAL__GAL_E7I (20)
#define SBP_GNSSSIGNAL__BDS3_B2A (47)
/** Represents all the relevant information about the signal
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 sat;
  u8 code;
} sbp_sbp_gnss_signal_t;


/** Space vehicle identifier
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 satId;
  u8 constellation;
} sbp_sv_id_t;


#define SBP_GNSSSIGNALDEP__MASK (0xff)
#define SBP_GNSSSIGNALDEP__SHIFT (0u)
#define SBP_GNSSSIGNALDEP__GET(flags) \
                             (((flags) >> SBP_GNSSSIGNALDEP__SHIFT) \
                             & SBP_GNSSSIGNALDEP__MASK)
#define SBP_GNSSSIGNALDEP__SET(flags, val) \
                             do {((flags) |= \
                             (((val) & (SBP_GNSSSIGNALDEP__MASK)) \
                             << (SBP_GNSSSIGNALDEP__SHIFT)));} while(0)
                             

#define SBP_GNSSSIGNALDEP__GPS_L1CA (0)
#define SBP_GNSSSIGNALDEP__GPS_L2CM (1)
#define SBP_GNSSSIGNALDEP__SBAS_L1CA (2)
#define SBP_GNSSSIGNALDEP__GLO_L1CA (3)
#define SBP_GNSSSIGNALDEP__GLO_L2CA (4)
#define SBP_GNSSSIGNALDEP__GPS_L1P (5)
#define SBP_GNSSSIGNALDEP__GPS_L2P (6)
/** Deprecated
 *
((m.desc|commentify)))
 */
typedef struct {
  u16 sat;
  u8 code;
  u8 reserved;
} sbp_gnss_signal_dep_t;


/** Millisecond-accurate GPS time
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 tow;
  u16 wn;
} sbp_gps_time_dep_t;


/** Whole second accurate GPS time
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 tow;
  u16 wn;
} sbp_gps_time_sec_t;


/** Nanosecond-accurate receiver clock time
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 tow;
  s32 ns_residual;
  u16 wn;
} sbp_sbp_gps_time_t;


/** GNSS carrier phase measurement.
 *
((m.desc|commentify)))
 */
typedef struct {
  s32 i;
  u8 f;
} sbp_carrier_phase_t;



#include <libsbp/unpacked/gnss_operators.h>
#include <libsbp/unpacked/gnss_packers.h>

#endif /* LIBSBP_GNSS_MESSAGES_H */
