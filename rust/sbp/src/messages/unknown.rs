use super::SBPMessage;
use crate::framer;
use crate::serialize::SbpSerialize;

#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
pub struct Unknown {
    pub msg_id: u16,
    pub sender_id: u16,
    pub payload: Vec<u8>,
}

impl SbpSerialize for Unknown {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.payload);
    }

    fn sbp_size(&self) -> usize {
        self.payload.len()
    }
}

impl SBPMessage for Unknown {
    fn get_message_type(&self) -> u16 {
        self.msg_id
    }

    fn get_sender_id(&self) -> Option<u16> {
        Some(self.sender_id)
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = new_id;
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        framer::to_frame(trait_object)
    }
}
