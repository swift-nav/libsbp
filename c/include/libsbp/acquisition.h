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
 * Automatically generated from piksi/yaml/
 * with generate.py at 2015-03-21 14:15:30.547636. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_ACQUISITION_MESSAGES_H
#define LIBSBP_ACQUISITION_MESSAGES_H

#include "common.h"


/** None
  * Results of an attempted GPS signal acquisition. Contains the
 * parameters of the point in the acquisition search space with the
 * best signal-to-noise ratio.
 */
#define SBP_MSG_ACQ_RESULT 0x0015
typedef struct __attribute__((packed)) {
  float snr;    /**< SNR of best point. */
  float cp;     /**< Code phase. [chips] */
  float cf;     /**< Carrier frequency. [hz] */
  u8 prn;    /**< PRN identifier of the satellite signal for which
acquisition was attempted.
 */
} msg_acq_result_t;


#endif /* LIBSBP_ACQUISITION_MESSAGES_H */