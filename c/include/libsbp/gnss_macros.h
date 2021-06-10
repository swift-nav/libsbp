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
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_GNSS_MACROS_H
#define LIBSBP_GNSS_MACROS_H


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

#endif