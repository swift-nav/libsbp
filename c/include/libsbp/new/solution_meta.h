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
 * Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_SOLUTION_META_MESSAGES_H
#define LIBSBP_NEW_SOLUTION_META_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/solution_meta_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/** Flags for a given solution input type
 *
 * Metadata describing which sensors were involved in the solution. The
 * structure is fixed no matter what the actual sensor type is. The sensor_type
 * field tells you which sensor we are talking about. It also tells you whether
 * the sensor data was actually used or not. The flags field, always a u8,
 * contains the sensor-specific data. The content of flags, for each sensor
 * type, is described in the relevant structures in this section.
 */
typedef struct {
  /**
   * The type of sensor
   */
  u8 sensor_type;

  /**
   * Refer to each InputType description [(XX)InputType]
   */
  u8 flags;
} sbp_solution_input_type_t;

/**
 * Get encoded size of an instance of sbp_solution_input_type_t
 *
 * @param msg sbp_solution_input_type_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_solution_input_type_t(
    const sbp_solution_input_type_t *msg);

/**
 * Encode an instance of sbp_solution_input_type_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_solution_input_type_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_solution_input_type_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_solution_input_type_t *msg);

/**
 * Decode an instance of sbp_solution_input_type_t from wire representation
 *
 * This function decodes the wire representation of a sbp_solution_input_type_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_solution_input_type_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_solution_input_type_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_solution_input_type_t *msg);

/**
 * Compare two instances of sbp_solution_input_type_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_solution_input_type_t instance
 * @param b sbp_solution_input_type_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_solution_input_type_t(const sbp_solution_input_type_t *a,
                                      const sbp_solution_input_type_t *b);

/** Deprecated
 *
 * Deprecated.
 *
 */
typedef struct {
  /**
   * Position Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 pdop;

  /**
   * Horizontal Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 hdop;

  /**
   * Vertical Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 vdop;

  /**
   * Number of satellites as per last available solution from PVT engine
   */
  u8 n_sats;

  /**
   * Age of corrections as per last available AGE_CORRECTIONS from PVT engine
   * (0xFFFF indicates invalid) [deciseconds]
   */
  u16 age_corrections;

  /**
   * State of alignment and the status and receipt of the alignment inputs
   */
  u8 alignment_status;

  /**
   * Tow of last-used GNSS position measurement [ms]
   */
  u32 last_used_gnss_pos_tow;

  /**
   * Tow of last-used GNSS velocity measurement [ms]
   */
  u32 last_used_gnss_vel_tow;

  /**
   * Array of Metadata describing the sensors potentially involved in the
   * solution. Each element in the array represents a single sensor type and
   * consists of flags containing (meta)data pertaining to that specific single
   * sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  sbp_solution_input_type_t sol_in[118];
  /**
   * Number of elements in sol_in
   *
   * When sending a message fill in this field with the number elements set in
   * sol_in before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * sol_in. The value of any elements beyond the index specified in this field
   * is undefined
   */
  u8 n_sol_in;
} sbp_msg_soln_meta_dep_a_t;

/**
 * Get encoded size of an instance of sbp_msg_soln_meta_dep_a_t
 *
 * @param msg sbp_msg_soln_meta_dep_a_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_soln_meta_dep_a_t(
    const sbp_msg_soln_meta_dep_a_t *msg);

/**
 * Encode an instance of sbp_msg_soln_meta_dep_a_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_soln_meta_dep_a_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_soln_meta_dep_a_t(uint8_t *buf, uint8_t len,
                                        uint8_t *n_written,
                                        const sbp_msg_soln_meta_dep_a_t *msg);

/**
 * Decode an instance of sbp_msg_soln_meta_dep_a_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_soln_meta_dep_a_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_soln_meta_dep_a_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_soln_meta_dep_a_t(const uint8_t *buf, uint8_t len,
                                        uint8_t *n_read,
                                        sbp_msg_soln_meta_dep_a_t *msg);
/**
 * Send an instance of sbp_msg_soln_meta_dep_a_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_soln_meta_dep_a_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_soln_meta_dep_a_t(struct sbp_state *s, u16 sender_id,
                                      const sbp_msg_soln_meta_dep_a_t *msg,
                                      s32 (*write)(u8 *buff, u32 n,
                                                   void *context));

/**
 * Compare two instances of sbp_msg_soln_meta_dep_a_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_soln_meta_dep_a_t instance
 * @param b sbp_msg_soln_meta_dep_a_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_soln_meta_dep_a_t(const sbp_msg_soln_meta_dep_a_t *a,
                                      const sbp_msg_soln_meta_dep_a_t *b);

/** Solution Sensors Metadata
 *
 * This message contains all metadata about the sensors received and/or used in
 * computing the sensorfusion solution. It focuses primarly, but not only, on
 * GNSS metadata. Regarding the age of the last received valid GNSS solution,
 * the highest two bits are time status, indicating whether age gnss can or can
 * not be used to retrieve time of measurement (noted TOM, also known as time of
 * validity) If it can, substract 'age gnss' from 'tow' in navigation messages
 * to get TOM. Can be used before alignment is complete in the Fusion Engine,
 * when output solution is the last received valid GNSS solution and its tow is
 * not a TOM.
 */
typedef struct {
  /**
   * GPS time of week rounded to the nearest millisecond [ms]
   */
  u32 tow;

  /**
   * Position Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 pdop;

  /**
   * Horizontal Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 hdop;

  /**
   * Vertical Dilution of Precision as per last available DOPS from PVT engine
   * (0xFFFF indicates invalid) [0.01]
   */
  u16 vdop;

  /**
   * Age of corrections as per last available AGE_CORRECTIONS from PVT engine
   * (0xFFFF indicates invalid) [deciseconds]
   */
  u16 age_corrections;

  /**
   * Age and Time Status of the last received valid GNSS solution. [ms]
   */
  u32 age_gnss;

  /**
   * Array of Metadata describing the sensors potentially involved in the
   * solution. Each element in the array represents a single sensor type and
   * consists of flags containing (meta)data pertaining to that specific single
   * sensor. Refer to each (XX)InputType descriptor in the present doc.
   */
  sbp_solution_input_type_t sol_in[119];
  /**
   * Number of elements in sol_in
   *
   * When sending a message fill in this field with the number elements set in
   * sol_in before calling an appropriate libsbp send function
   *
   * When receiving a message query this field for the number of elements in
   * sol_in. The value of any elements beyond the index specified in this field
   * is undefined
   */
  u8 n_sol_in;
} sbp_msg_soln_meta_t;

/**
 * Get encoded size of an instance of sbp_msg_soln_meta_t
 *
 * @param msg sbp_msg_soln_meta_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *msg);

/**
 * Encode an instance of sbp_msg_soln_meta_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_msg_soln_meta_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_soln_meta_t(uint8_t *buf, uint8_t len, uint8_t *n_written,
                                  const sbp_msg_soln_meta_t *msg);

/**
 * Decode an instance of sbp_msg_soln_meta_t from wire representation
 *
 * This function decodes the wire representation of a sbp_msg_soln_meta_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_msg_soln_meta_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_soln_meta_t(const uint8_t *buf, uint8_t len,
                                  uint8_t *n_read, sbp_msg_soln_meta_t *msg);
/**
 * Send an instance of sbp_msg_soln_meta_t with the given write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_soln_meta_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_soln_meta_t(struct sbp_state *s, u16 sender_id,
                                const sbp_msg_soln_meta_t *msg,
                                s32 (*write)(u8 *buff, u32 n, void *context));

/**
 * Compare two instances of sbp_msg_soln_meta_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_soln_meta_t instance
 * @param b sbp_msg_soln_meta_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_soln_meta_t(const sbp_msg_soln_meta_t *a,
                                const sbp_msg_soln_meta_t *b);

/** Instruments the physical type of GNSS sensor input to the fuzed solution
 *
 * Metadata around the GNSS sensors involved in the fuzed solution. Accessible
 * through sol_in[N].flags in a MSG_SOLN_META.
 */
typedef struct {
  /**
   * flags that store all relevant info specific to this sensor type.
   */
  u8 flags;
} sbp_gnss_input_type_t;

/**
 * Get encoded size of an instance of sbp_gnss_input_type_t
 *
 * @param msg sbp_gnss_input_type_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *msg);

/**
 * Encode an instance of sbp_gnss_input_type_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_gnss_input_type_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_gnss_input_type_t(uint8_t *buf, uint8_t len,
                                    uint8_t *n_written,
                                    const sbp_gnss_input_type_t *msg);

/**
 * Decode an instance of sbp_gnss_input_type_t from wire representation
 *
 * This function decodes the wire representation of a sbp_gnss_input_type_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_gnss_input_type_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_gnss_input_type_t(const uint8_t *buf, uint8_t len,
                                    uint8_t *n_read,
                                    sbp_gnss_input_type_t *msg);

/**
 * Compare two instances of sbp_gnss_input_type_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_gnss_input_type_t instance
 * @param b sbp_gnss_input_type_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_gnss_input_type_t(const sbp_gnss_input_type_t *a,
                                  const sbp_gnss_input_type_t *b);

/** Provides detail about the IMU sensor, its timestamping mode, and its quality
for input to the fuzed solution

 *
* Metadata around the IMU sensors involved in the fuzed solution. Accessible
through sol_in[N].flags in a MSG_SOLN_META.
 */
typedef struct {
  /**
   * Instrument time, grade, and architecture for a sensor.
   */
  u8 flags;
} sbp_imu_input_type_t;

/**
 * Get encoded size of an instance of sbp_imu_input_type_t
 *
 * @param msg sbp_imu_input_type_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_imu_input_type_t(const sbp_imu_input_type_t *msg);

/**
 * Encode an instance of sbp_imu_input_type_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_imu_input_type_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_imu_input_type_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_imu_input_type_t *msg);

/**
 * Decode an instance of sbp_imu_input_type_t from wire representation
 *
 * This function decodes the wire representation of a sbp_imu_input_type_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_imu_input_type_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_imu_input_type_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_imu_input_type_t *msg);

/**
 * Compare two instances of sbp_imu_input_type_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_imu_input_type_t instance
 * @param b sbp_imu_input_type_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_imu_input_type_t(const sbp_imu_input_type_t *a,
                                 const sbp_imu_input_type_t *b);

/** Provides detail about the Odometry sensor, its timestamping mode, and its
quality for input to the fuzed solution

 *
* Metadata around the Odometry sensors involved in the fuzed solution.
Accessible through sol_in[N].flags in a MSG_SOLN_META.
 */
typedef struct {
  /**
   * Instrument ODO rate, grade, and quality.
   */
  u8 flags;
} sbp_odo_input_type_t;

/**
 * Get encoded size of an instance of sbp_odo_input_type_t
 *
 * @param msg sbp_odo_input_type_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_odo_input_type_t(const sbp_odo_input_type_t *msg);

/**
 * Encode an instance of sbp_odo_input_type_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_odo_input_type_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_odo_input_type_t(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_odo_input_type_t *msg);

/**
 * Decode an instance of sbp_odo_input_type_t from wire representation
 *
 * This function decodes the wire representation of a sbp_odo_input_type_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_odo_input_type_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_odo_input_type_t(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read, sbp_odo_input_type_t *msg);

/**
 * Compare two instances of sbp_odo_input_type_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_odo_input_type_t instance
 * @param b sbp_odo_input_type_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_odo_input_type_t(const sbp_odo_input_type_t *a,
                                 const sbp_odo_input_type_t *b);

#ifdef __cplusplus
}
static inline bool operator==(const sbp_solution_input_type_t &lhs,
                              const sbp_solution_input_type_t &rhs) {
  return sbp_cmp_sbp_solution_input_type_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_solution_input_type_t &lhs,
                              const sbp_solution_input_type_t &rhs) {
  return sbp_cmp_sbp_solution_input_type_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_solution_input_type_t &lhs,
                             const sbp_solution_input_type_t &rhs) {
  return sbp_cmp_sbp_solution_input_type_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_solution_input_type_t &lhs,
                              const sbp_solution_input_type_t &rhs) {
  return sbp_cmp_sbp_solution_input_type_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_solution_input_type_t &lhs,
                             const sbp_solution_input_type_t &rhs) {
  return sbp_cmp_sbp_solution_input_type_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_solution_input_type_t &lhs,
                              const sbp_solution_input_type_t &rhs) {
  return sbp_cmp_sbp_solution_input_type_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_soln_meta_dep_a_t &lhs,
                              const sbp_msg_soln_meta_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_dep_a_t &lhs,
                              const sbp_msg_soln_meta_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_dep_a_t &lhs,
                             const sbp_msg_soln_meta_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_dep_a_t &lhs,
                              const sbp_msg_soln_meta_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_dep_a_t &lhs,
                             const sbp_msg_soln_meta_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_dep_a_t &lhs,
                              const sbp_msg_soln_meta_dep_a_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_dep_a_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_soln_meta_t &lhs,
                             const sbp_msg_soln_meta_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_soln_meta_t &lhs,
                             const sbp_msg_soln_meta_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_msg_soln_meta_t &lhs,
                              const sbp_msg_soln_meta_t &rhs) {
  return sbp_cmp_sbp_msg_soln_meta_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_gnss_input_type_t &lhs,
                              const sbp_gnss_input_type_t &rhs) {
  return sbp_cmp_sbp_gnss_input_type_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_gnss_input_type_t &lhs,
                              const sbp_gnss_input_type_t &rhs) {
  return sbp_cmp_sbp_gnss_input_type_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_gnss_input_type_t &lhs,
                             const sbp_gnss_input_type_t &rhs) {
  return sbp_cmp_sbp_gnss_input_type_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_gnss_input_type_t &lhs,
                              const sbp_gnss_input_type_t &rhs) {
  return sbp_cmp_sbp_gnss_input_type_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_gnss_input_type_t &lhs,
                             const sbp_gnss_input_type_t &rhs) {
  return sbp_cmp_sbp_gnss_input_type_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_gnss_input_type_t &lhs,
                              const sbp_gnss_input_type_t &rhs) {
  return sbp_cmp_sbp_gnss_input_type_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_imu_input_type_t &lhs,
                              const sbp_imu_input_type_t &rhs) {
  return sbp_cmp_sbp_imu_input_type_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_imu_input_type_t &lhs,
                              const sbp_imu_input_type_t &rhs) {
  return sbp_cmp_sbp_imu_input_type_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_imu_input_type_t &lhs,
                             const sbp_imu_input_type_t &rhs) {
  return sbp_cmp_sbp_imu_input_type_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_imu_input_type_t &lhs,
                              const sbp_imu_input_type_t &rhs) {
  return sbp_cmp_sbp_imu_input_type_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_imu_input_type_t &lhs,
                             const sbp_imu_input_type_t &rhs) {
  return sbp_cmp_sbp_imu_input_type_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_imu_input_type_t &lhs,
                              const sbp_imu_input_type_t &rhs) {
  return sbp_cmp_sbp_imu_input_type_t(&lhs, &rhs) >= 0;
}
static inline bool operator==(const sbp_odo_input_type_t &lhs,
                              const sbp_odo_input_type_t &rhs) {
  return sbp_cmp_sbp_odo_input_type_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_odo_input_type_t &lhs,
                              const sbp_odo_input_type_t &rhs) {
  return sbp_cmp_sbp_odo_input_type_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_odo_input_type_t &lhs,
                             const sbp_odo_input_type_t &rhs) {
  return sbp_cmp_sbp_odo_input_type_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_odo_input_type_t &lhs,
                              const sbp_odo_input_type_t &rhs) {
  return sbp_cmp_sbp_odo_input_type_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_odo_input_type_t &lhs,
                             const sbp_odo_input_type_t &rhs) {
  return sbp_cmp_sbp_odo_input_type_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_odo_input_type_t &lhs,
                              const sbp_odo_input_type_t &rhs) {
  return sbp_cmp_sbp_odo_input_type_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_SOLUTION_META_MESSAGES_H */
