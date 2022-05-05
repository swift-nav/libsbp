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
 * Automatically generated from yaml/(((package.filepath)))
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_(((package.name|upper)))_MACROS_H
#define LIBSBP_(((package.name|upper)))_MACROS_H

((* for m in package.msgs *))
((*- if m.is_real_message *))
#define SBP_(((m.name))) ((('0x%04X'|format(m.sbp_id))))
((*- endif *))
((*- for f in m.fields *))
((*- if f.options.fields *))
(((f|create_bitfield_macros(m.name))))
((*- endif*))
((*- if f.packing != "single" *))
/**
 * The maximum number of items that can be stored in (((m.type_name)))::(((f.name))) (V4 API) or (((m.legacy_type_name)))::(((f.name))) (legacy API) before the maximum SBP message size is exceeded
 */
#define (((f.max_items_macro))) (((f.max_items)))u

((* endif *))
((*- endfor *))
/**
 * Encoded length of (((m.type_name))) (V4 API) and 
 * (((m.legacy_type_name))) (legacy API)
((*- if not m.is_fixed_size *))
 *
 * This type is not fixed size and an instance of this message may be longer 
 * than the value indicated by this symbol. Users of the V4 API should call 
 * #(((m.encoded_len_fn))) to determine the actual size of an instance 
 * of this message. Users of the legacy API are required to track the encoded 
 * message length when interacting with the legacy type.
 *
 * See the documentation for libsbp for more details regarding the message 
 * structure and its variable length component(s)
((*- endif *))
 */
#define (((m.encoded_len_macro))) (((m.encoded_len_value)))u

((* endfor *))

#endif /* LIBSBP_(((package.name|upper)))_MACROS_H */

