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


((*- for m in msgs *))
pub use (((m.mod_name)))::(((m.msg_name)));
((*- endfor *))



((* for m in msgs *))
pub mod (((m.mod_name))) {
#![allow(unused_imports)]

use super::*;
use crate::messages::lib::*;
((*- for i in includes *))
use crate::messages::(((i)))::*;
((*- endfor *))

((*- if m.desc *))

/// (((m.short_desc)))
///
/// (((m.desc | commentify)))
///
((*- elif m.short_desc *))
/// (((m.short_desc)))
((*- endif *))
#[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
#[derive(Debug, PartialEq, Clone)]
pub struct (((m.msg_name))) {
    ((*- if m.is_real_message *))
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
    pub sender_id: Option<u16>,
    ((*- endif *))
    ((*- for f in m.fields *))
    ((*- if f.desc *))
    /// (((f.desc | commentify(indent=2) )))
    ((*- endif *))
    ((*- if f.type_id == "array" and "size" in f.options and f.options["size"].value >= 32 *))
    #[cfg_attr(feature = "serde", serde(with="BigArray", rename = "(((f.identifier)))"))]
    ((*- else *))
    #[cfg_attr(feature = "serde", serde(rename = "(((f.identifier)))"))]
    ((*- endif *))

    pub (((f.field_name))): (((f.type))),
    ((*- endfor *))
}

((= create getters/setters for bitfields if appropriate =))

((* if m.has_bitfield *))
impl (((m.msg_name))) {
((* for f in m.fields *))
((* for b in f.bitfield *))

((* if b.vals|length > 0 *))
    /// Gets the [(((b.type_name)))][self::(((b.type_name)))] stored in the `(((b.field)))` bitfield.
    ///
    /// Returns `Ok` if the bitrange contains a known `(((b.type_name)))` variant.
    /// Otherwise the value of the bitrange is returned as an `Err((( '(' )))(((b.type)))((( ')' )))`. This may be because of a malformed message,
    /// or because new variants of `(((b.type_name)))` were added.
    pub fn (((b.bitrange_name))) (&self) -> Result<(((b.type_name))), (((b.type)))> {
        get_bit_range!( self.(((b.field))),  (((f.type))), (((b.type))), (((b.msb))), (((b.lsb))) ).try_into()
    }

    /// Set the bitrange corresponding to the [(((b.type_name)))][(((b.type_name)))] of the `(((b.field)))` bitfield.
    pub fn set_(((b.bitrange_name))) (&mut self, (((b.bitrange_name))): (((b.type_name)))) {
        set_bit_range!(&mut self.(((b.field))), (((b.bitrange_name))),  (((f.type))), (((b.type))), (((b.msb))), (((b.lsb))) );
    }
((* elif b.type == "bool" *))
    /// Gets the `(((b.bitrange_name)))` flag.
    pub fn (((b.bitrange_name))) (&self) -> bool {
        ( ( self.(((b.field))) >> (((b.msb))) ) & 1) == 1
    }

    /// Sets the `(((b.bitrange_name)))` flag.
    pub fn set_(((b.bitrange_name))) (&mut self, (((b.bitrange_name))): (((b.type)))) {
        self.(((b.field))) ^= ( !( (((b.bitrange_name))) as (((f.type))) ) ) & (1 << (((b.msb))) )
    }
((* else *))
    /// Gets the `(((b.bitrange_name)))` stored in `(((b.field)))`.
    pub fn (((b.bitrange_name))) (&self) -> (((b.type))) {
        get_bit_range!( self.(((b.field))),  (((f.type))), (((b.type))), (((b.msb))), (((b.lsb))) )
    }

    /// Sets the `(((b.bitrange_name)))` bitrange of `(((b.field)))`.
    pub fn set_(((b.bitrange_name))) (&mut self, (((b.bitrange_name))): (((b.type)))) {
        set_bit_range!(&mut self.(((b.field))), (((b.bitrange_name))),  (((f.type))), (((b.type))), (((b.msb))), (((b.lsb))) );
    }
((* endif *))

((* endfor *))
((* endfor *))
}
((* endif *))

((= implement various traits for the message  =))

((* if m.is_real_message *))
impl ConcreteMessage for (((m.msg_name))) {
    const MESSAGE_TYPE: u16 = (((m.sbp_id)));
    const MESSAGE_NAME: &'static str = "(((m.identifier)))";
}

impl SbpMessage for (((m.msg_name))) {
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
    (((m.gps_time_fn)))
}

impl TryFrom<Sbp> for (((m.msg_name))) {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::(((m.msg_name)))(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}
((* endif *))

impl WireFormat for (((m.msg_name))) {
    const MIN_LEN: usize =
    ((*- if not m.fields *))
    0
    ((*- else *))
    < (((m.fields[0].type))) as WireFormat>::MIN_LEN
    ((*- for f in m.fields[1:] *))
    + < (((f.type))) as WireFormat>::MIN_LEN
    ((*- endfor *))
    ((*- endif *));
    fn len(&self) -> usize {
        ((*- if not m.fields *))
        0
        ((*- else *))
        WireFormat::len( &self.(((m.fields[0].field_name))) )
        ((*- for f in m.fields[1:] *))
        + WireFormat::len( &self.(((f.field_name))) )
        ((*- endfor *))
        ((*- endif *))
    }
    fn write<B: BufMut>(&self, ((*- if not m.fields *)) _buf ((*- else *)) buf ((*- endif *)): &mut B) {
        ((*- for f in m.fields *))
        WireFormat::write( &self.(((f.field_name))), buf);
        ((*- endfor *))
    }
    fn parse_unchecked<B: Buf>( ((*- if not m.fields *)) _buf ((*- else *)) buf ((*- endif *)): &mut B) -> Self {
        (((m.msg_name))) {
        ((*- if m.is_real_message *))
        sender_id: None,
        ((*- endif *))
        ((*- for f in m.fields *))
        (((f.field_name))): WireFormat::parse_unchecked(buf),
        ((*- endfor *))
        }
    }
}

((= create types for bitfields if appropriate =))

((* if m.has_bitfield *))
((* for f in m.fields *))

((* for b in f.bitfield *))

((* if b.vals|length > 0 *))
((*- if b.desc *))
/// (((b.desc | commentify)))
((*- endif *))
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum (((b.type_name))) {
    ((* for v in b.vals *))
    /// (((v.desc | commentify(indent=2) )))
    (((v.name))) = (((v.value))),
    ((* endfor *))
}

impl std::fmt::Display for (((b.type_name))) {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ((*- for v in b.vals *))
            (((b.type_name)))::(((v.name))) => f.write_str("(((v.desc)))"),
            ((*- endfor *))
        }
    }
}

impl TryFrom<(((b.type)))> for (((b.type_name))) {
    type Error = (((b.type)));
    fn try_from(i: (((b.type))) ) -> Result<Self, (((b.type)))> {
        match i {
            ((*- for v in b.vals *))
            (((v.value))) => Ok( (((b.type_name))) :: (((v.name))) ),
            ((*- endfor *))
            i => Err(i),
        }
    }
}
((* endif *))

((* endfor *))

((* endfor *))
((* endif *))

}

((* endfor *))
