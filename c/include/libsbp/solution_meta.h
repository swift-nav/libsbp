/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
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
 * * Standardized Metadata messages for Fuzed Solution from Swift Navigation devices.
 * \{ */

#ifndef LIBSBP_SOLUTION_META_MESSAGES_H
#define LIBSBP_SOLUTION_META_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** Flags for a given solution input type.
 *
 * Metadata describing which sensors were involved in the solution.
 * The structure is fixed no matter what the actual sensor type is.
 * The sensor_type field tells you which sensor we are talking about. It also tells you
 * whether the sensor data was actually used or not.
 * The flags field, always a u8, contains the sensor-specific data.
 * The content of flags, for each sensor type, is described in the relevant structures in this section.
 */
typedef struct SBP_ATTR_PACKED {
  u8 sensor_type;    /**< The type of sensor */
  u8 flags;          /**< Refer to each InputType description [(XX)InputType] */
} solution_input_type_t;


/** Solution Sensors Metadata
 *
 * This message contains all metadata about the sensors received and/or used in computing the Fuzed Solution.
 * It focuses primarly, but not only, on GNSS metadata.
 */
#define SBP_MSG_SOLN_META 0xFF0F
typedef struct SBP_ATTR_PACKED {
  u16 pdop;                      /**< Position Dilution of Precision, as per last available DOPS from Starling GNSS engine [0.01] */
  u16 hdop;                      /**< Horizontal Dilution of Precision, as per last available DOPS from Starling GNSS engine [0.01] */
  u16 vdop;                      /**< Vertical Dilution of Precision, as per last available DOPS from Starling GNSS engine [0.01] */
  u8 n_sats;                    /**< Number of satellites used in solution, as per last available DOPS from Starling GNSS engine */
  u16 age_corrections;           /**< Age of the corrections (0xFFFF indicates invalid), as per last available AGE_CORRECTIONS from Starling GNSS engine [deciseconds] */
  u8 alignment_status;          /**< Bits for reason why it cannot align (yet) */
  u32 last_used_gnss_pos_tow;    /**< Tow of last-used GNSS position measurement [ms] */
  u32 last_used_gnss_vel_tow;    /**< Tow of last-used GNSS velocity measurement [ms] */
  solution_input_type_t sol_in[0];                 /**< Array of Metadata describing the sensors potentially involved in the solution. Each element in the array represents a single sensor type and consists of flags containing (meta)data pertaining to that specific single sensor. Refer to each (XX)InputType descriptor in the present doc. */
} msg_soln_meta_t;


/** Flags for a given GNSS sensor used as input for the fuzed solution.
 *
 * Metadata around the GNSS sensors involved in the fuzed solution. Accessible through sol_in[N].flags
 *                                                                         in a MSG_SOLN_META.
 * Note: Just to build descriptive tables in documentation and not actually used.
 */
#define SBP_GNSSInputType 0xFFE7
typedef struct SBP_ATTR_PACKED {
  u8 flags;    /**< flags that store all relevant info specific to this sensor type. */
} gnss_input_type_t;


/** Flags for a given IMU sensor used as input for the fuzed solution.
 *
 * Metadata around the IMU sensors involved in the fuzed solution. Accessible through sol_in[N].flags
 *                                                                        in a MSG_SOLN_META.
 * Note: Just to build descriptive tables in documentation and not actually used.
 */
#define SBP_IMUInputType  0xFFE8
typedef struct SBP_ATTR_PACKED {
  u8 flags;    /**< flags that store all relevant info specific to this sensor type. */
} imu_input_type_t;


/** Flags for a given Odometry sensor used as input for the fuzed solution.
 *
 * Metadata around the Odometry sensors involved in the fuzed solution. Accessible through sol_in[N].flags
 *                                                                             in a MSG_SOLN_META.
 * Note: Just to build descriptive tables in documentation and not actually used.
 */
#define SBP_OdoInputType  0xFFE9
typedef struct SBP_ATTR_PACKED {
  u8 flags;    /**< flags that store all relevant info specific to this sensor type. */
} odo_input_type_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_SOLUTION_META_MESSAGES_H */