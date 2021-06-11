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
 * Automatically generated from yaml/
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_SBP_MSG_TYPE_H
#define LIBSBP_SBP_MSG_TYPE_H

#include <libsbp/acquisition_macros.h>
#include <libsbp/bootload_macros.h>
#include <libsbp/ext_events_macros.h>
#include <libsbp/file_io_macros.h>
#include <libsbp/flash_macros.h>
#include <libsbp/gnss_macros.h>
#include <libsbp/imu_macros.h>
#include <libsbp/linux_macros.h>
#include <libsbp/logging_macros.h>
#include <libsbp/mag_macros.h>
#include <libsbp/navigation_macros.h>
#include <libsbp/ndb_macros.h>
#include <libsbp/observation_macros.h>
#include <libsbp/orientation_macros.h>
#include <libsbp/piksi_macros.h>
#include <libsbp/sbas_macros.h>
#include <libsbp/settings_macros.h>
#include <libsbp/solution_meta_macros.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/system_macros.h>
#include <libsbp/tracking_macros.h>
#include <libsbp/user_macros.h>
#include <libsbp/vehicle_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  SbpMsgGroupMeta = SBP_MSG_GROUP_META,
  SbpMsgLog = SBP_MSG_LOG,
  SbpMsgObs = SBP_MSG_OBS,
  SbpMsgSettingsReadByIndexDone = SBP_MSG_SETTINGS_READ_BY_INDEX_DONE,
  SbpMsgSettingsReadByIndexResp = SBP_MSG_SETTINGS_READ_BY_INDEX_RESP,
  SbpMsgSvAzEl = SBP_MSG_SV_AZ_EL,
} sbp_msg_type_t;

#ifdef __cplusplus
}
#endif

#endif
