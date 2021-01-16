// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
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

//! (((description | replace("\n", "\n//! "))))

#[cfg(feature = "sbp_serde")]
use serde::{Serialize, Deserialize};

#[allow(unused_imports)]
use crate::{parser::SbpParse, UnboundedSbpString, BoundedSbpString};

((*- for i in includes *))
use super::(((i)))::*;
((*- endfor *))

((* for m in msgs *))
((*- if m.desc *))
/// (((m.short_desc)))
///
(((m.desc|commentify)))
///
((*- endif *))
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct (((m.identifier|camel_case))) {
    ((*- if m.is_real_message *))
    pub sender_id: Option<u16>,
    ((*- endif *))
    ((*- for f in m.fields *))
    ((*- if f.desc *))
    /// (((f.desc | replace("\n", " ") | wordwrap(width=72, wrapstring="\n    /// "))))
    ((*- endif *))
    pub (((f.identifier))): (((f|type_map))),
    ((*- endfor *))
}

impl SbpParse<(((m.identifier|camel_case)))> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<(((m.identifier|camel_case)))> {
        Ok( (((m.identifier|camel_case))){
            ((*- if m.is_real_message *))
            sender_id: None,
            ((*- endif *))
            ((*- for f in m.fields *))
            (((f.identifier))): self.parse()?,
            ((*- endfor *))
        } )
    }
}

((*- if m.is_real_message *))
impl super::SBPMessage for (((m.identifier|camel_case))) {
    fn get_message_type(&self) -> u16 {
        (((m.sbp_id)))
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}
((*- endif *))

impl crate::serialize::SbpSerialize for (((m.identifier|camel_case))) {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        ((*- for f in m.fields *))
        self.(((f.identifier))).append_to_sbp_buffer(buf);
        ((*- endfor *))
    }

    fn sbp_size(&self) -> usize {
        ((*- if not m.fields *))
        0
        ((*- else *))
        let mut size = 0;
        ((*- for f in m.fields *))
        size += self.(((f.identifier))).sbp_size();
        ((*- endfor *))
        size
        ((*- endif *))
    }
}
((* endfor *))
