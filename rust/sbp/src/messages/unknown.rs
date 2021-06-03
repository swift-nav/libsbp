use crate::{messages::SBPMessage, serialize::SbpSerialize};

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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
    fn get_message_name(&self) -> &'static str {
        "UNKNOWN"
    }

    fn get_message_type(&self) -> u16 {
        self.msg_id
    }

    fn get_sender_id(&self) -> Option<u16> {
        Some(self.sender_id)
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = new_id;
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
