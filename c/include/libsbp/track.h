/*
 * Copyright (C) 2012 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_TRACK_H
#define LIBSBP_TRACK_H

#include "common.h"
#include "ephemeris.h"

/** \addtogroup track
 * \{ */

/** \addtogroup track_loop
 * \{ */

/** State structure for the I-aided loop filter.
 * Should be initialised with aided_lf_init().
 */
typedef struct {
  float pgain;         /**< Proportional gain. */
  float igain;         /**< Integral gain. */
  float aiding_igain;  /**< Aiding integral gain. */
  float prev_error;    /**< Previous error. */
  float y;             /**< Output variable. */
} aided_lf_state_t;

/** State structure for the simple loop filter.
 * Should be initialised with simple_lf_init().
 */
typedef struct {
  float pgain;      /**< Proportional gain. */
  float igain;      /**< Integral gain. */
  float prev_error; /**< Previous error. */
  float y;          /**< Output variable. */
} simple_lf_state_t;

typedef struct { //TODO, add carrier aiding to the code loop.
  float carr_freq;             /**< Code frequency. */
  aided_lf_state_t carr_filt ; /**< Carrier loop filter state. */
  float code_freq;             /**< Carrier frequenct. */
  simple_lf_state_t code_filt; /**< Code loop filter state. */
  float prev_I;                /**< Previous timestep's in-phase integration. */
  float prev_Q;                /**< Previous timestep's quadrature-phase integration. */
} aided_tl_state_t;

/** State structure for a simple tracking loop.
 * Should be initialised with simple_tl_init().
 */
typedef struct {
  float code_freq;             /**< Code phase rate (i.e. frequency). */
  float carr_freq;             /**< Carrier frequency. */
  simple_lf_state_t code_filt; /**< Code loop filter state. */
  simple_lf_state_t carr_filt; /**< Carrier loop filter state. */
} simple_tl_state_t;

/** State structure for a code/carrier phase complimentary filter tracking
 * loop.
 * Should be initialised with comp_tl_init().
 */
typedef struct {
  float code_freq;             /**< Code phase rate (i.e. frequency). */
  float carr_freq;             /**< Carrier frequency. */
  simple_lf_state_t code_filt; /**< Code loop filter state. */
  simple_lf_state_t carr_filt; /**< Carrier loop filter state. */
  u32 sched;                   /**< Gain scheduling count. */
  u32 n;                       /**< Iteration counter. */
  float A;                     /**< Complementary filter crossover gain. */
  float carr_to_code;          /**< Scale factor from carrier to code. */
} comp_tl_state_t;


/** \} */

/** Structure representing a complex valued correlation. */
typedef struct {
  float I; /**< In-phase correlation. */
  float Q; /**< Quadrature correlation. */
} correlation_t;

/** State structure for the \f$ C / N_0 \f$ estimator.
 * Should be initialised with cn0_est_init().
 */
typedef struct {
  float log_bw;     /**< Noise bandwidth in dBHz. */
  float A;          /**< IIR filter coeff. */
  float I_prev_abs; /**< Abs. value of the previous in-phase correlation. */
  float nsr;        /**< Noise-to-signal ratio (1 / SNR). */
} cn0_est_state_t;

/** \} */

/** This struct holds the state of a tracking channel at a given receiver time epoch.
 *
 * The struct contains the information necessary to calculate the pseudorange,
 * carrier phase and Doppler information needed for a PVT solution but is
 * formatted closer to the natural outputs from the tracking channels.
 *
 * \see calc_navigation_measurement()
 */
typedef struct {
  u8 prn;                  /**< Satellite PRN. */
  double code_phase_chips; /**< The code-phase in chips at `receiver_time`. */
  double code_phase_rate;  /**< Code phase rate in chips/s. */
  double carrier_phase;    /**< Carrier phase in cycles. */
  double carrier_freq;     /**< Carrier frequency in Hz. */
  u32 time_of_week_ms;     /**< Number of milliseconds since the start of the
                                GPS week corresponding to the last code rollover.  */
  double receiver_time;    /**< Receiver clock time at which this measurement
                                is valid in seconds. */
  double snr;              /**< Signal to noise ratio. */
  u16 lock_counter;        /**< This number is changed each time the tracking
                                channel is re-locked or a cycle slip is
                                detected and the carrier phase integer
                                ambiguity is reset.  If this number changes it
                                is an indication you should reset integer
                                ambiguity resolution for this channel. */
} channel_measurement_t;

typedef struct {
  double raw_pseudorange;
  double pseudorange;
  double carrier_phase;
  double raw_doppler;
  double doppler;
  double sat_pos[3];
  double sat_vel[3];
  double snr;
  double lock_time;
  gps_time_t tot;
  u8 prn;
  u16 lock_counter;
} navigation_measurement_t;

#endif /* LIBSBP_TRACK_H */

