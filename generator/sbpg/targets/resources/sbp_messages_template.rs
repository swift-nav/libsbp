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

((* for i in includes *))
use super::(((i)))::*;
((* endfor *))

use super::lib::*;

((* for m in msgs *))
((*- if m.desc *))
/// (((m.short_desc)))
///
/// (((m.desc | commentify)))
///
((*- elif m.short_desc *))
/// (((m.short_desc)))
((*- endif *))
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct (((m.identifier|camel_case))) {
    ((*- if m.is_real_message *))
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    ((*- endif *))
    ((*- for f in m.fields *))
    ((*- if f.desc *))
    /// (((f.desc | commentify(indent=2) )))
    ((*- endif *))
    #[cfg_attr(feature = "serde", serde(rename(serialize = "(((f.identifier)))")))]
    pub (((f.identifier|snake_case))): (((f|type_map))),
    ((*- endfor *))
}

((* if m.is_real_message *))
impl ConcreteMessage for (((m.identifier|camel_case))) {
    const MESSAGE_TYPE: u16 = (((m.sbp_id)));
    const MESSAGE_NAME: &'static str = "(((m.identifier)))";
}

impl SbpMessage for (((m.identifier|camel_case))) {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    (((m|gps_time(msgs))))
}

impl TryFrom<Sbp> for (((m.identifier|camel_case))) {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::(((m.identifier|camel_case)))(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}
((* endif *))

impl WireFormat for (((m.identifier|camel_case))) {
    const MIN_LEN: usize =
    ((*- if not m.fields *))
    0
    ((*- else *))
    < (((m.fields[0]|type_map))) as WireFormat>::MIN_LEN
    ((*- for f in m.fields[1:] *))
    + < (((f|type_map))) as WireFormat>::MIN_LEN
    ((*- endfor *))
    ((*- endif *));
    fn len(&self) -> usize {
        ((*- if not m.fields *))
        0
        ((*- else *))
        WireFormat::len( &self.(((m.fields[0].identifier|snake_case))) )
        ((*- for f in m.fields[1:] *))
        + WireFormat::len( &self.(((f.identifier|snake_case))) )
        ((*- endfor *))
        ((*- endif *))
    }
    fn write<B: BufMut>(&self, ((*- if not m.fields *)) _buf ((*- else *)) buf ((*- endif *)): &mut B) {
        ((*- for f in m.fields *))
        WireFormat::write( &self.(((f.identifier|snake_case))), buf);
        ((*- endfor *))
    }
    fn parse_unchecked<B: Buf>( ((*- if not m.fields *)) _buf ((*- else *)) buf ((*- endif *)): &mut B) -> Self {
        (((m.identifier|camel_case))) {
        ((*- if m.is_real_message *))
        sender_id: None,
        ((*- endif *))
        ((*- for f in m.fields *))
        (((f.identifier|snake_case))): WireFormat::parse_unchecked(buf),
        ((*- endfor *))
        }
    }
}
((* endfor *))
