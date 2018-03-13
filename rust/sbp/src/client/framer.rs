extern crate byteorder;
extern crate crc16;

use self::byteorder::{LittleEndian,ReadBytesExt};
use std::io::{Read, Error, ErrorKind};
use ::messages::SBP;

const SBP_PREAMBLE: u8 = 0x55;

pub fn receive(a: &mut Read) -> Result<SBP, Error> {
    let mut preamble = [0];
    a.read_exact(&mut preamble)?;
    if preamble[0] != SBP_PREAMBLE {
        return Err(Error::new(ErrorKind::Other, "invalid preamble"));
    }
    let mut crc_state = crc16::State::<crc16::XMODEM>::new();
    let mut header = [0; 5];
    a.read_exact(&mut header).expect("read failed");
    crc_state.update(&header);
    let mut header = &header[..];
    let msg_id = header.read_u16::<LittleEndian>().unwrap();
    let sender = header.read_u16::<LittleEndian>().unwrap();
    let len = header.read_u8().unwrap() as usize;

    let mut payload = [0; 256];
    let mut payload = &mut payload[..len];
    a.read_exact(&mut payload).expect("read failed");
    crc_state.update(&payload);

    let crc = a.read_u16::<LittleEndian>().unwrap();
    if crc != crc_state.get() {
        return Err(Error::new(ErrorKind::Other, "CRC error"))
    }

    Ok(SBP::parse(msg_id, &mut &payload[..]))
}
