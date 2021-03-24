//! Simple parsing functionality for extracting SBP
//! messages from binary streams

use byteorder::{LittleEndian, ReadBytesExt};
use nom::Err as NomErr;

use crate::{messages::SBP, Error, Result, SbpString};

pub fn read_string(buf: &mut &[u8]) -> Result<SbpString> {
    let amount = buf.len();
    let (head, tail) = buf.split_at(amount);
    *buf = tail;
    Ok(SbpString(head.to_vec()))
}

pub fn read_string_limit(buf: &mut &[u8], n: usize) -> Result<SbpString> {
    let n = std::cmp::min(n, buf.len());
    let (mut head, tail) = buf.split_at(n);
    read_string(&mut head).map(|sbp_string| {
        *buf = tail;
        sbp_string
    })
}

pub fn read_u16_array(buf: &mut &[u8]) -> Result<Vec<u16>> {
    // buf is in fact an array of u16, so at least 2 u8 elem, unless buf is empty
    let iter = buf.chunks_exact(2);
    // collect() guarantees that it will return Err if at least one Err is found while iterating
    // over the Vec https://doc.rust-lang.org/std/iter/trait.FromIterator.html#method.from_iter-14
    // map_err necessary to convert the generic read_u16's Error into our Error enum type
    // LittleEndian means chunks are read from right-to-left
    let v = iter
        .map(|mut x| x.read_u16::<LittleEndian>().map_err(|e| e.into()))
        .collect();
    v
}

pub fn read_u8_array(buf: &mut &[u8]) -> Result<Vec<u8>> {
    Ok(buf.to_vec())
}

pub fn read_u8_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<u8>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u8()?);
    }
    Ok(v)
}

pub fn read_s8_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<i8>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_i8()?);
    }
    Ok(v)
}

pub fn read_s16_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<i16>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_i16::<LittleEndian>()?);
    }
    Ok(v)
}

pub fn read_u16_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<u16>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_u16::<LittleEndian>()?);
    }
    Ok(v)
}

pub fn read_float_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<f32>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f32::<LittleEndian>()?);
    }
    Ok(v)
}

pub fn read_double_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<f64>> {
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(buf.read_f64::<LittleEndian>()?);
    }
    Ok(v)
}

#[derive(Debug)]
pub enum ParseResult {
    Ok((usize, SBP)),
    Err((usize, Error)),
    Incomplete,
}

pub fn parse_sbp<'a>(input: &'a [u8]) -> ParseResult {
    let (new_input, mut frame) = match frame::parse(input) {
        Ok(res) => res,
        Err(e) => match e {
            NomErr::Incomplete(_) => return ParseResult::Incomplete,
            NomErr::Error((_, kind)) | NomErr::Failure((_, kind)) => {
                return ParseResult::Err((1, Error::ParseError { kind }))
            }
        },
    };

    let bytes_read = input.len() - new_input.len();

    if !frame::check_crc(&frame) {
        return ParseResult::Err((
            bytes_read,
            Error::CrcError {
                msg_type: frame.1,
                sender_id: frame.2,
                crc: frame.4,
            },
        ));
    }

    let msg = match SBP::parse(frame.1, frame.2, &mut frame.3) {
        Ok(msg) => msg,
        Err(err) => return ParseResult::Err((bytes_read, err)),
    };

    ParseResult::Ok((bytes_read, msg))
}

pub mod frame {
    use nom::{bytes, error::ErrorKind, number, sequence::tuple, IResult};

    pub type Frame<'a> = (&'a [u8], u16, u16, &'a [u8], u16);

    pub type Error<'a> = (&'a [u8], ErrorKind);

    pub fn parse(i: &[u8]) -> IResult<&[u8], Frame, Error> {
        let (i, _) = bytes::streaming::take_while(is_not_preamble)(i)?;

        tuple((
            parse_preamble,
            parse_msg_type,
            parse_sender_id,
            parse_payload,
            parse_crc,
        ))(i)
    }

    pub fn check_crc((_preamble, msg_type, sender_id, payload, crc_in): &Frame) -> bool {
        let mut crc = crc16::State::<crc16::XMODEM>::new();

        crc.update(&msg_type.to_le_bytes());
        crc.update(&sender_id.to_le_bytes());
        crc.update(&[payload.len() as u8]);
        crc.update(payload);

        crc.get() == *crc_in
    }

    fn is_not_preamble(b: u8) -> bool {
        b != 0x55
    }

    fn parse_preamble(i: &[u8]) -> IResult<&[u8], &[u8], Error> {
        bytes::streaming::is_a("\x55")(i)
    }

    fn parse_msg_type(i: &[u8]) -> IResult<&[u8], u16, Error> {
        number::streaming::le_u16(i)
    }

    fn parse_sender_id(i: &[u8]) -> IResult<&[u8], u16, Error> {
        number::streaming::le_u16(i)
    }

    fn parse_payload(i: &[u8]) -> IResult<&[u8], &[u8], Error> {
        let (i, length) = number::streaming::le_u8(i)?;
        bytes::streaming::take(length)(i)
    }

    fn parse_crc(i: &[u8]) -> IResult<&[u8], u16, Error> {
        number::streaming::le_u16(i)
    }
}

#[cfg(test)]
mod tests {
    use std::io::Cursor;

    use crate::serialize::SbpSerialize;

    use super::*;

    #[test]
    fn test_parse_sbp() {
        let packet = [
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        ];
        let baseline_ecef_expectation = crate::messages::navigation::MsgBaselineECEF {
            sender_id: Some(0x88d3),
            accuracy: 0,
            flags: 0,
            n_sats: 14,
            tow: 326825000,
            x: -1154410,
            y: 1327294,
            z: 631798,
        };

        let (consumed, msg) = match parse_sbp(&packet[..]) {
            ParseResult::Ok((consumed, SBP::MsgBaselineECEF(msg))) => (consumed, msg),
            err => panic!("unexpected parse result: {:?}", err),
        };

        assert_eq!(packet.len(), consumed);

        assert_eq!(msg.sender_id, baseline_ecef_expectation.sender_id);
        assert_eq!(msg.accuracy, baseline_ecef_expectation.accuracy);
        assert_eq!(msg.flags, baseline_ecef_expectation.flags);
        assert_eq!(msg.n_sats, baseline_ecef_expectation.n_sats);
        assert_eq!(msg.tow, baseline_ecef_expectation.tow);
        assert_eq!(msg.x, baseline_ecef_expectation.x);
        assert_eq!(msg.y, baseline_ecef_expectation.y);
        assert_eq!(msg.z, baseline_ecef_expectation.z);
    }

    /// Test parsing when we don't have enough data for a frame message
    #[test]
    fn test_parse_sbp_eof() {
        let packet = [
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        ];

        let res = parse_sbp(&packet[..packet.len() - 1]);

        assert!(matches!(res, ParseResult::Incomplete));

        let res = parse_sbp(&packet[..]);

        assert!(matches!(
            res,
            ParseResult::Ok((28, SBP::MsgBaselineECEF(_)))
        ));
    }

    #[test]
    fn test_parse_sbp_crc_error() {
        let packet = vec![
            // Start with a mostly valid message, with a single byte error
            0x55, 0x0c, // This byte should be 0x0b, changed to intentionally cause a CRC error
            0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff, 0xbe, 0x40,
            0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf, 0xde, 0xad,
            0xbe, 0xef, // Include another valid message to properly parse
            0x55, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
            0xde, 0xad, 0xbe, 0xef,
        ];

        let reader = Cursor::new(packet);
        let mut msgs = crate::iter_messages(reader);

        let res = msgs.next().unwrap().unwrap_err();
        assert!(matches!(res, Error::CrcError { .. }));

        let res = msgs.next().unwrap();
        assert!(res.is_ok());
    }

    #[test]
    fn test_parser_iter() {
        let mut payload = vec![
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        ];
        payload.append(&mut payload.clone());

        let input = Cursor::new(payload);

        let mut count = 0;

        for msg in crate::iter_messages(input) {
            assert!(msg.is_ok());
            count += 1;
        }

        assert_eq!(count, 2);
    }

    #[test]
    fn test_invalid_utf8() {
        let packet = vec![
            0x55, 0xa7, 0x0, 0x0, 0x10, 0x48, 0x8, 0x0, 0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f,
            0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb6, 0xe8, 0xab,
        ];

        let reader = Cursor::new(packet);
        let mut msgs = crate::iter_messages(reader);

        let sbp_result = msgs.next().unwrap();

        assert!(sbp_result.is_ok());

        let sbp_message = sbp_result.unwrap();

        assert_eq!(sbp_message.sbp_size(), 72);
    }
    #[test]
    fn test_read_string_invalid_utf8() {
        // (9 * 8) - 2 = 70
        let buf = vec![
            0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0xb6,
        ];

        let mut slice = &buf[..];

        let sbp_string = read_string(&mut slice).unwrap();

        let string: String = sbp_string.clone().into();
        let vec: Vec<u8> = sbp_string.into();

        // The last 0xb6 get's transformed into 3 UTF-8 bytes (� aka U+FFFD REPLACEMENT CHARACTER)
        assert_eq!(string.len(), 69 + 3);
        assert_eq!(vec.len(), 70);
    }

    #[test]
    fn test_read_string() {
        let v = b"hi, imma string";
        let mut slice = &v[..];

        let string: String = read_string(&mut slice).unwrap().into();
        assert_eq!(string, "hi, imma string".to_string());

        let string: String = read_string(&mut slice).unwrap().into();
        assert_eq!(string, "".to_string());

        let v = b"hi, imma string";
        let mut slice = &v[..];

        let string: String = read_string_limit(&mut slice, 8).unwrap().into();
        assert_eq!(string, "hi, imma".to_string());

        let string: String = read_string_limit(&mut slice, 8).unwrap().into();
        assert_eq!(string, " string".to_string());
    }

    #[test]
    fn test_read_u16_array() {
        // A basic unit test for read_u16_array, LittleEndian convention assumed everywhere
        let mock_data: [u8; 4] = [0b00000001, 0b00010000, 0b00000010, 0b00000001];
        let mut expected_vec = Vec::with_capacity(2);
        // 0b00010000+0b00000001
        expected_vec.push(4097);
        expected_vec.push(258);
        let returned_vec = read_u16_array(&mut &mock_data[..]).unwrap();
        assert_eq!(expected_vec, returned_vec);
    }
}
