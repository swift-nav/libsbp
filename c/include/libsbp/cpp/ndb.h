/*
 * Copyright (C) 2021 Swift Navigation Inc.
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
 * Automatically generated from yaml/swiftnav/sbp/ndb.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_NDB_MESSAGES_H
#define LIBSBP_CPP_NDB_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>
#include <libsbp/cpp/gnss.h>

namespace sbp {
  
  /**
   * Navigation DataBase Event
   *
   * This message is sent out when an object is stored into NDB. If needed
   * message could also be sent out when fetching an object from NDB.
   */
  
  struct SBP_ATTR_PACKED MsgNdbEvent {
    u64 recv_time; /** HW time in milliseconds. [ms] */
    u8 event; /** Event type. */
    u8 object_type; /** Event object type. */
    u8 result; /** Event result. */
    u8 data_source; /** Data source for STORE event, reserved for other events. */
    GnssSignal object_sid; /** GNSS signal identifier,
If object_type is Ephemeris OR Almanac, sid indicates for which
signal the object belongs to. Reserved in other cases.
 */
    GnssSignal src_sid; /** GNSS signal identifier,
If object_type is Almanac, Almanac WN, Iono OR L2C capabilities
AND data_source is NDB_DS_RECEIVER sid indicates from which SV
data was decoded. Reserved in other cases.
 */
    u16 original_sender; /** A unique identifier of the sending hardware. For v1.0,
set to the 2 least significant bytes of the device serial
number, valid only if data_source is NDB_DS_SBP. Reserved in case
of other data_source.
 */
  };
  

}  // namespace sbp

#endif /* LIBSBP_CPP_NDB_MESSAGES_H */