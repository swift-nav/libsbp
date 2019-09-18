/*
 * Copyright (C) 2011-2014 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_SBP2JSON_H
#define LIBSBP_SBP2JSON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

int sbp2json(u16 sender_id, u16 msg_type, u8 msg_len, u8 payload[],
  uint64_t max_len, char* out_str);


#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_SBP2JSON_H */