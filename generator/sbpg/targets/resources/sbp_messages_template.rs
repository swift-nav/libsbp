// Copyright (C) 2015-2021 Swift Navigation Inc.
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

//! (((description | commentify(prefix="//! ") )))

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian,ReadBytesExt};

#[allow(unused_imports)]
use crate::SbpString;
#[allow(unused_imports)]
use crate::serialize::SbpSerialize;

((*- for i in includes *))
use super::(((i)))::*;
((*- endfor *))

((* for m in msgs *))
((*- if m.desc *))
/// (((m.short_desc)))
///
/// (((m.desc | commentify)))
///
((*- endif *))
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct (((m.identifier|camel_case))) {
    ((*- if m.is_real_message *))
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    ((*- endif *))
    ((*- for f in m.fields *))
    ((*- if f.desc *))
    /// (((f.desc | commentify(indent=2) )))
    ((*- endif *))
    pub (((f.identifier))): (((f|type_map))),
    ((*- endfor *))
}

impl (((m.identifier|camel_case))) {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<(((m.identifier|camel_case))), crate::Error> {
        Ok( (((m.identifier|camel_case))){
            ((*- if m.is_real_message *))
            sender_id: None,
            ((*- endif *))
            ((*- for f in m.fields *))
            (((f.identifier))): (((f|parse_type)))?,
            ((*- endfor *))
        } )
    }

    ((*- if not m.is_real_message *))
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<(((m.identifier|camel_case)))>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( (((m.identifier|camel_case)))::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<(((m.identifier|camel_case)))>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( (((m.identifier|camel_case)))::parse(buf)? );
        }
        Ok(v)
    }
    ((*- endif *))
}

((*- if m.is_real_message *))
impl super::SBPMessage for (((m.identifier|camel_case))) {
    fn get_message_name(&self) -> &'static str {
        "(((m.identifier)))"
    }

    fn get_message_type(&self) -> u16 {
        (((m.sbp_id)))
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(
        &self,
        frame: &mut Vec<u8>,
    ) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }

    (((m|gps_time(msgs))))
}
((*- endif *))

((*- if m.is_real_message *))
impl super::ConcreteMessage for (((m.identifier|camel_case))) {
    const MESSAGE_TYPE: u16 = (((m.sbp_id)));
    const MESSAGE_NAME: &'static str = "(((m.identifier)))";
}
((*- endif *))

((*- if m.is_real_message *))
impl TryFrom<super::SBP> for (((m.identifier|camel_case))) {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::(((m.identifier|camel_case)))(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
