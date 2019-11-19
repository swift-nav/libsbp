use crate::messages::SBPMessage;
use crate::serialize::SbpSerialize;
use std::error;
use std::fmt;

#[derive(Debug)]
pub enum FramerError {
    TooLarge,
    NoSenderId,
}

impl fmt::Display for FramerError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            FramerError::TooLarge => write!(f, "Message is too large"),
            FramerError::NoSenderId => write!(f, "No Sender ID Error"),
        }
    }
}

impl error::Error for FramerError {
    fn description(&self) -> &str {
        match self {
            FramerError::TooLarge => "Message is too large to fit into an SBP frame",
            FramerError::NoSenderId => "No sender ID is present in the message bring framed",
        }
    }
}

pub fn to_frame(msg: &dyn SBPMessage) -> std::result::Result<Vec<u8>, FramerError> {
    let len = msg.sbp_size();
    if len > 255 {
        return Err(FramerError::TooLarge);
    }

    let mut frame = Vec::new();

    frame.reserve(len);
    frame.push(0x55);
    msg.get_message_type().append_to_sbp_buffer(&mut frame);
    msg.get_sender_id()
        .ok_or(FramerError::NoSenderId)?
        .append_to_sbp_buffer(&mut frame);

    frame.push(len as u8);

    msg.append_to_sbp_buffer(&mut frame);

    let mut crc = crc16::State::<crc16::XMODEM>::new();
    crc.update(&frame[1..]);
    crc.get().append_to_sbp_buffer(&mut frame);

    Ok(frame)
}
