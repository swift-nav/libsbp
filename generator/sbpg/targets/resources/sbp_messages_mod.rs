// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
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
((*- if m.is_real_message *))
use self::(((p.identifier|mod_name)))::(((m.identifier|camel_case)));
((*- endif *))
((*- endfor *))
((*- endfor *))
use self::unknown::Unknown;

use crate::serialize::SbpSerialize;

#[enum_dispatch::enum_dispatch]
pub trait SBPMessage: SbpSerialize {
    fn get_message_type(&self) -> u16;
    fn get_sender_id(&self) -> Option<u16>;
    fn set_sender_id(&mut self, new_id: u16);
    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError>;
    fn write_frame(&self, buf: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError>;
}

#[enum_dispatch::enum_dispatch(SbpSerialize, SBPMessage)]
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize), serde(untagged))]
#[derive(Debug, Clone)]
pub enum SBP {
    ((*- for m in msgs *))
    (((m.identifier|camel_case)))( (((m.identifier|camel_case))) ),
    ((*- endfor *))
    Unknown( Unknown ),
}

impl SBP {
    pub fn parse(msg_id: u16, sender_id: u16, payload: &mut &[u8]) -> Result<SBP, crate::Error> {
        match msg_id {
            ((*- for m in msgs *))
            (((m.sbp_id))) => {
                let mut msg = (((m.identifier|camel_case)))::parse(payload)?;
                msg.set_sender_id(sender_id);
                Ok(SBP::(((m.identifier|camel_case)))(msg))
            },
            ((*- endfor *))
            _ => Ok(SBP::Unknown( Unknown{ msg_id: msg_id, sender_id: sender_id, payload: payload.to_vec() } ))
        }
    }
}

