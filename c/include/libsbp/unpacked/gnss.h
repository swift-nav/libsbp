#ifndef LIBSBP_GNSS_MESSAGES_H
#define LIBSBP_GNSS_MESSAGES_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <math.h>

#include <libsbp/common.h>
#include <libsbp/unpacked/string/multipart.h>
#include <libsbp/unpacked/string/sequence.h>
#include <libsbp/unpacked/string/unterminated.h>
#include <libsbp/unpacked/string/null_terminated.h>

#ifdef __cplusplus
  extern "C" {
#endif
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

size_t sbp_packed_size_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *msg);
s8 sbp_pack_sbp_sbp_gnss_signal_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sbp_gnss_signal_t *msg);
s8 sbp_unpack_sbp_sbp_gnss_signal_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sbp_gnss_signal_t *msg);

int sbp_cmp_sbp_sbp_gnss_signal_t(const sbp_sbp_gnss_signal_t *a, const sbp_sbp_gnss_signal_t *b);


/** Space vehicle identifier
 *
((m.desc|commentify)))
 */
typedef struct {
  u8 satId;
  u8 constellation;
} sbp_sv_id_t;

size_t sbp_packed_size_sbp_sv_id_t(const sbp_sv_id_t *msg);
s8 sbp_pack_sbp_sv_id_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sv_id_t *msg);
s8 sbp_unpack_sbp_sv_id_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sv_id_t *msg);

int sbp_cmp_sbp_sv_id_t(const sbp_sv_id_t *a, const sbp_sv_id_t *b);


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

size_t sbp_packed_size_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *msg);
s8 sbp_pack_sbp_gnss_signal_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gnss_signal_dep_t *msg);
s8 sbp_unpack_sbp_gnss_signal_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gnss_signal_dep_t *msg);

int sbp_cmp_sbp_gnss_signal_dep_t(const sbp_gnss_signal_dep_t *a, const sbp_gnss_signal_dep_t *b);


/** Millisecond-accurate GPS time
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 tow;
  u16 wn;
} sbp_gps_time_dep_t;

size_t sbp_packed_size_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *msg);
s8 sbp_pack_sbp_gps_time_dep_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gps_time_dep_t *msg);
s8 sbp_unpack_sbp_gps_time_dep_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gps_time_dep_t *msg);

int sbp_cmp_sbp_gps_time_dep_t(const sbp_gps_time_dep_t *a, const sbp_gps_time_dep_t *b);


/** Whole second accurate GPS time
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 tow;
  u16 wn;
} sbp_gps_time_sec_t;

size_t sbp_packed_size_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *msg);
s8 sbp_pack_sbp_gps_time_sec_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_gps_time_sec_t *msg);
s8 sbp_unpack_sbp_gps_time_sec_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_gps_time_sec_t *msg);

int sbp_cmp_sbp_gps_time_sec_t(const sbp_gps_time_sec_t *a, const sbp_gps_time_sec_t *b);


/** Nanosecond-accurate receiver clock time
 *
((m.desc|commentify)))
 */
typedef struct {
  u32 tow;
  s32 ns_residual;
  u16 wn;
} sbp_sbp_gps_time_t;

size_t sbp_packed_size_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *msg);
s8 sbp_pack_sbp_sbp_gps_time_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_sbp_gps_time_t *msg);
s8 sbp_unpack_sbp_sbp_gps_time_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_sbp_gps_time_t *msg);

int sbp_cmp_sbp_sbp_gps_time_t(const sbp_sbp_gps_time_t *a, const sbp_sbp_gps_time_t *b);


/** GNSS carrier phase measurement.
 *
((m.desc|commentify)))
 */
typedef struct {
  s32 i;
  u8 f;
} sbp_carrier_phase_t;

size_t sbp_packed_size_sbp_carrier_phase_t(const sbp_carrier_phase_t *msg);
s8 sbp_pack_sbp_carrier_phase_t(uint8_t *buf, uint8_t len, uint8_t *n_written, const sbp_carrier_phase_t *msg);
s8 sbp_unpack_sbp_carrier_phase_t(const uint8_t *buf, uint8_t len, uint8_t *n_read, sbp_carrier_phase_t *msg);

int sbp_cmp_sbp_carrier_phase_t(const sbp_carrier_phase_t *a, const sbp_carrier_phase_t *b);



#ifdef __cplusplus
  }
static inline bool operator==(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sbp_gnss_signal_t &a, const sbp_sbp_gnss_signal_t &b) {
  return sbp_cmp_sbp_sbp_gnss_signal_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sv_id_t &a, const sbp_sv_id_t &b) {
  return sbp_cmp_sbp_sv_id_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gnss_signal_dep_t &a, const sbp_gnss_signal_dep_t &b) {
  return sbp_cmp_sbp_gnss_signal_dep_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gps_time_dep_t &a, const sbp_gps_time_dep_t &b) {
  return sbp_cmp_sbp_gps_time_dep_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_gps_time_sec_t &a, const sbp_gps_time_sec_t &b) {
  return sbp_cmp_sbp_gps_time_sec_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_sbp_gps_time_t &a, const sbp_sbp_gps_time_t &b) {
  return sbp_cmp_sbp_sbp_gps_time_t(&a, &b) >= 0;
}
static inline bool operator==(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) == 0;
}

static inline bool operator!=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) != 0;
}

static inline bool operator<(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) < 0;
}

static inline bool operator<=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) <= 0;
}

static inline bool operator>(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) > 0;
}

static inline bool operator>=(const sbp_carrier_phase_t &a, const sbp_carrier_phase_t &b) {
  return sbp_cmp_sbp_carrier_phase_t(&a, &b) >= 0;
}

#endif

#endif /* LIBSBP_GNSS_MESSAGES_H */
