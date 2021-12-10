/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

/** \defgroup solution_meta Solution_meta
 *
 * Standardized Metadata messages for Fuzed Solution from Swift Navigation
 * devices.
 * \{ */

#ifndef LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H
#define LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H

#include <libsbp/common.h>

#include <libsbp/solution_meta_macros.h>

SBP_PACK_START

/** Flags for a given solution input type
 *
 * Metadata describing which sensors were involved in the solution. The
 * structure is fixed no matter what the actual sensor type is. The
 * sensor_type field tells you which sensor we are talking about. It also
 * tells you whether the sensor data was actually used or not. The flags
 * field, always a u8, contains the sensor-specific data. The content of
 * flags, for each sensor type, is described in the relevant structures in
 * this section.
 */

typedef struct SBP_ATTR_PACKED {
  u8 sensor_type; /**< The type of sensor */
  u8 flags;       /**< Refer to each InputType description [(XX)InputType] */
} solution_input_type_t;

/** Deprecated
 *
 * Deprecated.
 *
 * This message contains all metadata about the sensors received and/or used
 * in computing the Fuzed Solution. It focuses primarily, but not only, on
 * GNSS metadata.
 */

typedef struct SBP_ATTR_PACKED {
  u16 pdop;                        /**< Position Dilution of Precision as per
                                        last available DOPS from PVT engine
                                        (0xFFFF indicates invalid) [0.01] */
  u16 hdop;                        /**< Horizontal Dilution of Precision as per
                                        last available DOPS from PVT engine
                                        (0xFFFF indicates invalid) [0.01] */
  u16 vdop;                        /**< Vertical Dilution of Precision as per
                                        last available DOPS from PVT engine
                                        (0xFFFF indicates invalid) [0.01] */
  u8 n_sats;                       /**< Number of satellites as per last
                                        available solution from PVT engine */
  u16 age_corrections;             /**< Age of corrections as per last available
                                        AGE_CORRECTIONS from PVT engine (0xFFFF
                                        indicates invalid) [deciseconds] */
  u8 alignment_status;             /**< State of alignment and the status and
                                        receipt of the alignment inputs */
  u32 last_used_gnss_pos_tow;      /**< Tow of last-used GNSS position
                                        measurement [ms] */
  u32 last_used_gnss_vel_tow;      /**< Tow of last-used GNSS velocity
                                        measurement [ms] */
  solution_input_type_t sol_in[0]; /**< Array of Metadata
                                        describing the sensors
                                        potentially involved
                                        in the solution. Each
                                        element in the array
                                        represents a single
                                        sensor type and
                                        consists of flags
                                        containing (meta)data
                                        pertaining to that
                                        specific single
                                        sensor. Refer to each
                                        (XX)InputType
                                        descriptor in the
                                        present doc. */
} msg_soln_meta_dep_a_t;

/** Solution Sensors Metadata
 *
 * This message contains all metadata about the sensors received and/or used
 * in computing the sensorfusion solution. It focuses primarily, but not only,
 * on GNSS metadata. Regarding the age of the last received valid GNSS
 * solution, the highest two bits are time status, indicating whether age gnss
 * can or can not be used to retrieve time of measurement (noted TOM, also
 * known as time of validity) If it can, subtract 'age gnss' from 'tow' in
 * navigation messages to get TOM. Can be used before alignment is complete in
 * the Fusion Engine, when output solution is the last received valid GNSS
 * solution and its tow is not a TOM.
 */

typedef struct SBP_ATTR_PACKED {
  u32 tow;             /**< GPS time of week rounded to the nearest
                            millisecond [ms] */
  u16 pdop;            /**< Position Dilution of Precision as per last
                            available DOPS from PVT engine (0xFFFF
                            indicates invalid) [0.01] */
  u16 hdop;            /**< Horizontal Dilution of Precision as per last
                            available DOPS from PVT engine (0xFFFF
                            indicates invalid) [0.01] */
  u16 vdop;            /**< Vertical Dilution of Precision as per last
                            available DOPS from PVT engine (0xFFFF
                            indicates invalid) [0.01] */
  u16 age_corrections; /**< Age of corrections as per last available
                            AGE_CORRECTIONS from PVT engine (0xFFFF
                            indicates invalid) [deciseconds] */
  u32 age_gnss;        /**< Age and Time Status of the last received valid
                            GNSS solution. [ms] */
  solution_input_type_t sol_in[0]; /**< Array of Metadata describing
                                        the sensors potentially
                                        involved in the solution.
                                        Each element in the array
                                        represents a single sensor
                                        type and consists of flags
                                        containing (meta)data
                                        pertaining to that specific
                                        single sensor. Refer to each
                                        (XX)InputType descriptor in
                                        the present doc. */
} msg_soln_meta_t;

/** Instruments the physical type of GNSS sensor input to the fuzed solution
 *
 * Metadata around the GNSS sensors involved in the fuzed solution. Accessible
 * through sol_in[N].flags in a MSG_SOLN_META.
 */

typedef struct SBP_ATTR_PACKED {
  u8 flags; /**< flags that store all relevant info specific to this sensor
                 type. */
} gnss_input_type_t;

/** Provides detail about the IMU sensor, its timestamping mode, and its quality
 for input to the fuzed solution

 *
 * Metadata around the IMU sensors involved in the fuzed solution. Accessible
 * through sol_in[N].flags in a MSG_SOLN_META.
 */

typedef struct SBP_ATTR_PACKED {
  u8 flags; /**< Instrument time, grade, and architecture for a sensor. */
} imu_input_type_t;

/** Provides detail about the Odometry sensor, its timestamping mode, and its
 quality for input to the fuzed solution

 *
 * Metadata around the Odometry sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
 */

typedef struct SBP_ATTR_PACKED {
  u8 flags; /**< Instrument ODO rate, grade, and quality. */
} odo_input_type_t;

/** \} */

SBP_PACK_END

#endif /* LIBSBP_LEGACY_SOLUTION_META_MESSAGES_H */