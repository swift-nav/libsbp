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
 * Automatically generated with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_CPP_VERSION_H
#define LIBSBP_CPP_VERSION_H

#include <cstdint>

namespace sbp {
  /** Protocol major version. */
  constexpr u8 MAJOR_VERSION = (((major)));

  /** Protocol minor version. */
  constexpr u8 MINOR_VERSION = (((minor)));

  /** Protocol patch version. */
  constexpr u8 PATCH_VERSION = (((patch)));

  /** Full SBP version string. */
  constexpr const char *const VERSION = "(((full_version)))";
}  // namespace sbp

#endif /* LIBSBP_CPP_VERSION_H */
