// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/(((filepath)))
// with generate.py. Please do not hand edit!
//****************************************************************************/

(((description|commentify)))

((*- for i in includes *))
use super::(((i)))::*;
((*- endfor *))

((* for m in msgs *))
((*- if m.desc *))
// (((m.short_desc)))
//
(((m.desc|commentify)))
//
((*- endif *))
((*- if m.fields *))
((*- if m.sbp_id *))
pub struct (((m.identifier|camel_case))) {
((*- else *))
pub struct (((m.identifier))) {
((*- endif *))
    ((*- for f in m.fields *))
    pub (((f.identifier))): (((f|type_map))),
        ((*- if f.desc *))
        // ^ (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n        // "))))
        ((*- endif *))
    ((*- endfor *))
}
((*- endif *))

((* endfor *))
