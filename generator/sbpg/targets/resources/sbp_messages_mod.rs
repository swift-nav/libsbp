// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

((*- for m in mods *))
pub mod (((m)));
((*- endfor *))
pub mod unknown;

((*- for p in packages *))
((*- for m in p.definitions *))
((*- if m.sbp_id *))
use self::(((p.identifier|mod_name)))::(((m.identifier|camel_case)));
((*- endif *))
((*- endfor *))
((*- endfor *))
use self::unknown::Unknown;

#[cfg(feature = "serialize")]
use serde::{Serialize, Deserialize};
use crate::serialize::SbpSerialize;
use crate::framer::FramerError;

pub trait SBPMessage: SbpSerialize {
    fn get_message_type(&self) -> u16;
    fn get_sender_id(&self) -> Option<u16>;
    fn set_sender_id(&mut self, new_id: u16);
    fn to_frame(&self) -> std::result::Result<Vec<u8>, FramerError>;
}

#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
pub enum SBP {
    ((*- for m in msgs *))
    (((m.identifier|camel_case)))( (((m.identifier|camel_case))) ),
    ((*- endfor *))
    Unknown( Unknown ),
}

impl SBP {
    pub fn parse(msg_id: u16, sender_id: u16, payload: &mut &[u8]) -> Result<SBP, crate::Error> {
        let x: Result<SBP, crate::Error> = match msg_id {
            ((*- for m in msgs *))
            (((m.sbp_id))) => {
                let mut msg = (((m.identifier|camel_case)))::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::(((m.identifier|camel_case)))(msg))
            },
            ((*- endfor *))
            _ => Ok(SBP::Unknown( Unknown{ msg_id: msg_id, sender_id: sender_id, payload: payload.to_vec() } ))
        };
        match x {
            Ok(x) => Ok(x),
            Err(_) => Err(crate::Error::ParseError),
        }
    }

    pub fn as_sbp_message<'a>(&'a self) -> &dyn SBPMessage {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))( msg ) => msg,
            ((*- endfor *))
            SBP::Unknown(msg) => msg,
        }
    }
}

