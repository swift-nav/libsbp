//! Native implementation of decoding of SBP (Swift Binary Protocol) used by products
//! made by Swift Navigation. For language agnostic description of the protocol please
//! see the protocol specification documentation at https://github.com/swift-nav/libsbp/tree/master/docs

pub mod framer;
pub mod messages;
pub mod parser;
pub mod serialize;

#[cfg(feature = "sbp2json")]
pub mod sbp2json;

use std::error;
use std::fmt;
use std::result;

pub type Result<T> = result::Result<T, Error>;

pub const SBP_MAX_PAYLOAD: usize = 256;

#[derive(Debug)]
pub enum Error {
    ParseError,
    CrcError,
    NotEnoughData,
    UnrecoverableFailure,
    IoError(std::io::Error),
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Error::ParseError => write!(f, "Parse error"),
            Error::CrcError => write!(f, "CRC error"),
            Error::NotEnoughData => write!(f, "Not enough data"),
            Error::UnrecoverableFailure => write!(f, "Unrecoverage failure"),
            Error::IoError(err) => write!(f, "IO Error: {}", err),
        }
    }
}

impl error::Error for Error {
    fn description(&self) -> &str {
        match self {
            Error::ParseError => "An error occured during parsing",
            Error::CrcError => "CRC validation failed",
            Error::NotEnoughData => "Not enough data available to parse a message",
            Error::UnrecoverableFailure => "An unrecoverage failure was encountered",
            #[allow(deprecated)]
            Error::IoError(err) => err.description(),
        }
    }
}

impl From<std::io::Error> for Error {
    fn from(err: std::io::Error) -> Error {
        Error::IoError(err)
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn baseline_ecef() {
        let baseline_ecef_payload = [
            0x28u8, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff, 0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3,
            0x09, 0x00, 0x00, 0x00, 0x0e, 0x00,
        ];
        let baseline_ecef_expectation = crate::messages::navigation::MsgBaselineECEF {
            sender_id: Some(1234),
            accuracy: 0,
            flags: 0,
            n_sats: 14,
            tow: 326825000,
            x: -1154410,
            y: 1327294,
            z: 631798,
        };
        let sbp_result = crate::messages::SBP::parse(0x20b, 1234, &mut &baseline_ecef_payload[..]);
        assert!(sbp_result.is_ok());
        if let crate::messages::SBP::MsgBaselineECEF(msg) = sbp_result.unwrap() {
            assert_eq!(msg.sender_id, baseline_ecef_expectation.sender_id);
            assert_eq!(msg.accuracy, baseline_ecef_expectation.accuracy);
            assert_eq!(msg.flags, baseline_ecef_expectation.flags);
            assert_eq!(msg.n_sats, baseline_ecef_expectation.n_sats);
            assert_eq!(msg.tow, baseline_ecef_expectation.tow);
            assert_eq!(msg.x, baseline_ecef_expectation.x);
            assert_eq!(msg.y, baseline_ecef_expectation.y);
            assert_eq!(msg.z, baseline_ecef_expectation.z);
        } else {
            assert!(false);
        }
    }

    #[test]
    fn frame() {
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
        let (sbp_result, consumed) = crate::parser::frame(&packet[..]);
        assert!(sbp_result.is_ok());
        if let crate::messages::SBP::MsgBaselineECEF(msg) = sbp_result.unwrap() {
            assert_eq!(msg.sender_id, baseline_ecef_expectation.sender_id);
            assert_eq!(msg.accuracy, baseline_ecef_expectation.accuracy);
            assert_eq!(msg.flags, baseline_ecef_expectation.flags);
            assert_eq!(msg.n_sats, baseline_ecef_expectation.n_sats);
            assert_eq!(msg.tow, baseline_ecef_expectation.tow);
            assert_eq!(msg.x, baseline_ecef_expectation.x);
            assert_eq!(msg.y, baseline_ecef_expectation.y);
            assert_eq!(msg.z, baseline_ecef_expectation.z);
        } else {
            assert!(false);
        }
        assert_eq!(packet.len(), consumed);
    }

    #[test]
    /// Test parsing when we don't have enough data for a frame message
    fn frame_eof() {
        let packet = [
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
        ];

        let (sbp_result, _remaining_data) = crate::parser::frame(&packet[..packet.len() - 1]);
        assert!(sbp_result.is_err());

        if let Err(err) = sbp_result {
            match err {
                crate::Error::NotEnoughData => { /* No-op */ }
                _ => {
                    assert!(false);
                }
            }
        }

        let (sbp_result, _remaining_data) = crate::parser::frame(&packet[..packet.len()]);

        if let crate::messages::SBP::MsgBaselineECEF(_msg) = sbp_result.unwrap() {
            /* No-op */
        } else {
            assert!(false);
        }
    }

    #[test]
    fn parser() {
        let packet = vec![
            0x00, 0x11, 0x22, 0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96,
            0x62, 0xee, 0xff, 0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e,
            0x00, 0xdb, 0xbf, 0xde, 0xad, 0xbe, 0xef,
        ];
        let mut reader = std::io::Cursor::new(packet);
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
        let mut parser = crate::parser::Parser::new();
        // Iterate through the data until we hit something that is
        // parsable
        let sbp_result = parser.parse(&mut reader);
        assert!(sbp_result.is_ok());
        if let crate::messages::SBP::MsgBaselineECEF(msg) = sbp_result.unwrap() {
            assert_eq!(msg.sender_id, baseline_ecef_expectation.sender_id);
            assert_eq!(msg.accuracy, baseline_ecef_expectation.accuracy);
            assert_eq!(msg.flags, baseline_ecef_expectation.flags);
            assert_eq!(msg.n_sats, baseline_ecef_expectation.n_sats);
            assert_eq!(msg.tow, baseline_ecef_expectation.tow);
            assert_eq!(msg.x, baseline_ecef_expectation.x);
            assert_eq!(msg.y, baseline_ecef_expectation.y);
            assert_eq!(msg.z, baseline_ecef_expectation.z);
        } else {
            assert!(false);
        }
    }

    #[test]
    fn parser_crc_error() {
        let packet = vec![
            // Start with a mostly valid message, with a single byte error
            0x55, 0x0c, // This byte should be 0x0b, changed to intentionally cause a CRC error
            0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff, 0xbe, 0x40,
            0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf, 0xde, 0xad,
            0xbe, 0xef, // Include another valid message to properly parse
            0x55u8, 0x0b, 0x02, 0xd3, 0x88, 0x14, 0x28, 0xf4, 0x7a, 0x13, 0x96, 0x62, 0xee, 0xff,
            0xbe, 0x40, 0x14, 0x00, 0xf6, 0xa3, 0x09, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xdb, 0xbf,
            0xde, 0xad, 0xbe, 0xef,
        ];
        let mut reader = std::io::Cursor::new(packet);
        let mut parser = crate::parser::Parser::new();
        // Iterate through the data until we hit something that is
        // parsable
        let sbp_result = parser.parse(&mut reader);
        assert!(sbp_result.is_err());
        match sbp_result.unwrap_err() {
            crate::Error::CrcError => {}
            e => {
                assert!(false, "Unexpected error: {:?}", e);
            }
        };

        let sbp_result = parser.parse(&mut reader);
        assert!(sbp_result.is_ok());
    }

    #[test]
    fn making_frame() {
        use crate::messages::SBPMessage;

        let msg = crate::messages::system::MsgStartup {
            sender_id: Some(250),
            cause: 1,
            startup_type: 45,
            reserved: 0,
        };

        let frame = msg.to_frame().unwrap();

        let expected_frame = b"\x55\x00\xFF\xFA\x00\x04\x01\x2D\x00\x00\xBC\x73";

        assert_eq!(frame, expected_frame);
    }
}
