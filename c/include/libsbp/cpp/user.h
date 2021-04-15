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
 * Automatically generated from yaml/swiftnav/sbp/user.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_USER_MESSAGES_H
#define LIBSBP_CPP_USER_MESSAGES_H

#include <cstddef>
#include <libsbp/common.h>
#include <libsbp/sbp.h>

namespace sbp {
  
  /**
   * User data
   *
   * This message can contain any application specific user data up to a
   * maximum length of 255 bytes per message.
   */
  constexpr u16 MSG_USER_DATA = 0x0800;

  template<size_t CONTENTS_COUNT = (SBP_MAX_PAYLOAD_LEN - 0) / sizeof(u8)>
  struct SBP_ATTR_PACKED MsgUserData {
    u8 contents[CONTENTS_COUNT]; /** User data payload */
  };

  

}  // namespace sbp

#endif /* LIBSBP_CPP_USER_MESSAGES_H */