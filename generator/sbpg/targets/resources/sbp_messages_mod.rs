// Copyright (C) 2015-2021 Swift Navigation Inc.
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

pub trait SBPMessage: SbpSerialize {
    fn get_message_name(&self) -> &'static str;
    fn get_message_type(&self) -> u16;
    fn get_sender_id(&self) -> Option<u16>;
    fn set_sender_id(&mut self, new_id: u16);
    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError>;
    fn write_frame(&self, buf: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError>;
    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(&self) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        None
    }
}

pub trait ConcreteMessage: SBPMessage + std::convert::TryFrom<SBP, Error = TryFromSBPError> + Clone + Sized {
    const MESSAGE_TYPE: u16;
    const MESSAGE_NAME: &'static str;
}

#[derive(Debug, Clone)]
pub struct TryFromSBPError;

impl std::fmt::Display for TryFromSBPError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "invalid message type for conversion")
    }
}

impl std::error::Error for TryFromSBPError {}

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

impl crate::SBPMessage for SBP {
    fn get_message_name(&self) -> &'static str {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.get_message_name()
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.get_message_name()
            },
        }
    }

    fn get_message_type(&self) -> u16 {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.get_message_type()
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.get_message_type()
            },
        }
    }

    fn get_sender_id(&self) -> Option<u16> {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.get_sender_id()
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.get_sender_id()
            },
        }
    }

    fn set_sender_id(&mut self, new_id: u16) {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.set_sender_id(new_id)
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.set_sender_id(new_id)
            },
        }
    }

    fn to_frame(&self) -> Result<Vec<u8>, crate::FramerError> {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.to_frame()
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.to_frame()
            },
        }
    }

    fn write_frame(&self, buf: &mut Vec<u8>) -> Result<(), crate::FramerError> {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.write_frame(buf)
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.write_frame(buf)
            },
        }
    }

    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(&self) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.gps_time()
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.gps_time()
            },
        }
    }
}


impl crate::SbpSerialize for SBP {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.append_to_sbp_buffer(buf)
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.append_to_sbp_buffer(buf)
            },
        }
    }

    fn sbp_size(&self) -> usize {
        match self {
            ((*- for m in msgs *))
            SBP::(((m.identifier|camel_case)))(msg) => {
                msg.sbp_size()
            },
            ((*- endfor *))
            SBP::Unknown(msg) => {
                msg.sbp_size()
            },
        }
    }
}

((*- for m in msgs *))
impl From<(((m.identifier|camel_case)))> for SBP {
    fn from(msg: (((m.identifier|camel_case)))) -> Self {
        SBP::(((m.identifier|camel_case)))(msg)
    }
}
((*- endfor *))

impl From<Unknown> for SBP {
    fn from(msg: Unknown) -> Self {
        SBP::Unknown(msg)
    }
}
