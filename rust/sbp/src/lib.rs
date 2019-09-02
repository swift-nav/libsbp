pub mod messages;
pub mod parser;

#[derive(Debug)]
pub enum Error {
    ParseError,
    NotEnoughData,
    UnrecoverableFailure,
    IoError(std::io::Error),
}

#[cfg(test)]
mod tests {
    #[test]
    fn baseline_ecef() {
        let baseline_ecef_payload = [
            0x28u8,
            0xf4,
            0x7a,
            0x13,
            0x96,
            0x62,
            0xee,
            0xff,
            0xbe,
            0x40,
            0x14,
            0x00,
            0xf6,
            0xa3,
            0x09,
            0x00,
            0x00,
            0x00,
            0x0e,
            0x00,
        ];
        let baseline_ecef_expectation = ::messages::navigation::MsgBaselineECEF {
            sender_id: Some(1234),
            accuracy: 0,
            flags: 0,
            n_sats: 14,
            tow: 326825000,
            x: -1154410,
            y: 1327294,
            z: 631798,
        };
        let sbp_result = ::messages::SBP::parse(0x20b, 1234, &mut &baseline_ecef_payload[..]);
        assert!(sbp_result.is_ok());
        if let ::messages::SBP::MsgBaselineECEF(msg) = sbp_result.unwrap() {
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
            0x55u8,
            0x0b,
            0x02,
            0xd3,
            0x88,
            0x14,
            0x28,
            0xf4,
            0x7a,
            0x13,
            0x96,
            0x62,
            0xee,
            0xff,
            0xbe,
            0x40,
            0x14,
            0x00,
            0xf6,
            0xa3,
            0x09,
            0x00,
            0x00,
            0x00,
            0x0e,
            0x00,
            0xdb,
            0xbf,
        ];
        let baseline_ecef_expectation = ::messages::navigation::MsgBaselineECEF {
            sender_id: Some(0x88d3),
            accuracy: 0,
            flags: 0,
            n_sats: 14,
            tow: 326825000,
            x: -1154410,
            y: 1327294,
            z: 631798,
        };
        let (sbp_result, _remaining_data) = ::parser::frame(&packet[..]);
        assert!(sbp_result.is_ok());
        if let ::messages::SBP::MsgBaselineECEF(msg) = sbp_result.unwrap() {
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
    fn parser() {
        let packet = vec![
            0x00,
            0x11,
            0x22,
            0x55u8,
            0x0b,
            0x02,
            0xd3,
            0x88,
            0x14,
            0x28,
            0xf4,
            0x7a,
            0x13,
            0x96,
            0x62,
            0xee,
            0xff,
            0xbe,
            0x40,
            0x14,
            0x00,
            0xf6,
            0xa3,
            0x09,
            0x00,
            0x00,
            0x00,
            0x0e,
            0x00,
            0xdb,
            0xbf,
            0xde,
            0xad,
            0xbe,
            0xef,
        ];
        let mut reader = std::io::Cursor::new(packet);
        let baseline_ecef_expectation = ::messages::navigation::MsgBaselineECEF {
            sender_id: Some(0x88d3),
            accuracy: 0,
            flags: 0,
            n_sats: 14,
            tow: 326825000,
            x: -1154410,
            y: 1327294,
            z: 631798,
        };
        let mut parser = ::parser::Parser::new();
        // Iterate through the data until we hit something that is
        // parsable
        let sbp_result = parser.parse(&mut reader);
        assert!(sbp_result.is_ok());
        if let ::messages::SBP::MsgBaselineECEF(msg) = sbp_result.unwrap() {
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
}
