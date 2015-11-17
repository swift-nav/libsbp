/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
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

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#define LIBSBP_ACQUISITION_MESSAGES_H

#include "common.h"
#include "gnss_signal.h"


/** Satellite acquisition result
 *
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best signal-to-noise (SNR)
 * ratio.
 */
#define SBP_MSG_ACQ_RESULT       0x0014
typedef struct __attribute__((packed)) {
  float snr;    /**< SNR of best point. Currently in arbitrary SNR points, but will
be in units of dB Hz in a later revision of this message.
 */
  float cp;     /**< Code phase of best point [chips] */
  float cf;     /**< Carrier frequency of best point [hz] */
  sbp_gnss_signal_t sid;    /**< GNSS signal for which acquisition was attempted */
} msg_acq_result_t;


/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_ACQ_RESULT_DEP_A 0x0015
typedef struct __attribute__((packed)) {
  float snr;    /**< SNR of best point. Currently dimensonless, but will have
units of dB Hz in the revision of this message.
 */
  float cp;     /**< Code phase of best point [chips] */
  float cf;     /**< Carrier frequency of best point [hz] */
  u8 prn;    /**< PRN-1 identifier of the satellite signal for which
acquisition was attempted
 */
} msg_acq_result_dep_a_t;


/** \} */

#endif /* LIBSBP_ACQUISITION_MESSAGES_H */