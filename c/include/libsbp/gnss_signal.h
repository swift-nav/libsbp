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
 * Automatically generated from yaml/swiftnav/sbp/gnss_signal.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup gnss_signal Gnss_signal
 *
 * * Struct to represent a signal (constellation, band, satellite identifier)
 * \{ */

#ifndef LIBSBP_GNSS_SIGNAL_MESSAGES_H
#define LIBSBP_GNSS_SIGNAL_MESSAGES_H

#include "common.h"


/** Represents all the relevant information about the signal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 */
typedef struct __attribute__((packed)) {
  u16 sat;         /**< Constellation-specific satellite identifier */
  u8 code;        /**< Signal constellation, band and code */
  u8 reserved;    /**< Reserved */
} sbp_gnss_signal_t;


/** \} */

#endif /* LIBSBP_GNSS_SIGNAL_MESSAGES_H */