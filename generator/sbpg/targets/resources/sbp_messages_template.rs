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
extern crate byteorder;
use std::io::Read;
use self::byteorder::{LittleEndian,ReadBytesExt};

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
#[derive(Debug)]
pub struct (((m.identifier|camel_case))) {
    ((*- for f in m.fields *))
    pub (((f.identifier))): (((f|type_map))),
        ((*- if f.desc *))
        // ^ (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n        // "))))
        ((*- endif *))
    ((*- endfor *))
}

impl (((m.identifier|camel_case))) {
    ((*- if m.sbp_id *))
    pub const TYPE: u16 = (((m.sbp_id)));
    ((*- endif *))
    pub fn parse(buf: &mut Read) -> (((m.identifier|camel_case))) {
        (((m.identifier|camel_case))){
            ((*- for f in m.fields *))
            (((f.identifier))): (((f|parse_type))),
            ((*- endfor *))
        }
    }
    ((*- if not m.sbp_id *))
    pub fn parse_array(buf: &mut Read) -> Vec<(((m.identifier|camel_case)))> {
        Vec::new()
    }
    ((*- endif *))
}

((* endfor *))
