/*
 * Copyright (C) 2010-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSBP_EDC_H
#define LIBSBP_EDC_H

#include <libsbp/common.h>

#ifdef __cplusplus
extern "C" {
#endif

SBP_EXPORT u16 crc16_ccitt(const u8 *buf, u32 len, u16 crc);

#ifdef __cplusplus
}
#endif

#endif /* LIBSBP_EDC_H */
