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

((*- for p in packages *))
((*- for m in p.definitions *))
((*- if m.sbp_id *))
use self::(((p.identifier|mod_name)))::(((m.identifier|camel_case)));
((*- endif *))
((*- endfor *))
((*- endfor *))

#[cfg(feature = "serialize")]
use serde::{Serialize, Deserialize};

pub trait SBPMessage {
    const MSG_ID: u16;

    fn get_sender_id(&self) -> Option<u16>;
    fn set_sender_id(&mut self, new_id: u16);
}

#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
pub enum SBP {
    Unknown { msg_id: u16, sender_id: u16, payload: Vec<u8> },
    ((*- for m in msgs *))
    (((m.identifier|camel_case)))( (((m.identifier|camel_case))) ),
    ((*- endfor *))
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
            _ => Ok(SBP::Unknown { msg_id: msg_id, sender_id: sender_id, payload: payload.to_vec() })
        };
        match x {
            Ok(x) => Ok(x),
            Err(_) => Err(crate::Error::ParseError),
        }
    }
}
