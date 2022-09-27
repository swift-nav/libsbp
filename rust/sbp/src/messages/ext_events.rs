// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/swiftnav/sbp/ext_events.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages reporting accurately-timestamped external events, e.g. camera
//! shutter time.
pub use msg_ext_event::MsgExtEvent;

pub mod msg_ext_event {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Reports timestamped external pin event
    ///
    /// Reports detection of an external event, the GPS time it occurred, which
    /// pin it was and whether it was rising or falling.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgExtEvent {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
        /// 500000)
        #[cfg_attr(feature = "serde", serde(rename = "ns_residual"))]
        pub ns_residual: i32,
        /// Flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// Pin number.  0..9 = DEBUG0..9.
        #[cfg_attr(feature = "serde", serde(rename = "pin"))]
        pub pin: u8,
    }

    impl MsgExtEvent {
        /// Gets the [TimeQuality][self::TimeQuality] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeQuality` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeQuality` were added.
        pub fn time_quality(&self) -> Result<TimeQuality, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 1).try_into()
        }

        /// Set the bitrange corresponding to the [TimeQuality][TimeQuality] of the `flags` bitfield.
        pub fn set_time_quality(&mut self, time_quality: TimeQuality) {
            set_bit_range!(&mut self.flags, time_quality, u8, u8, 1, 1);
        }

        /// Gets the [NewLevelOfPin][self::NewLevelOfPin] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `NewLevelOfPin` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `NewLevelOfPin` were added.
        pub fn new_level_of_pin(&self) -> Result<NewLevelOfPin, u8> {
            get_bit_range!(self.flags, u8, u8, 0, 0).try_into()
        }

        /// Set the bitrange corresponding to the [NewLevelOfPin][NewLevelOfPin] of the `flags` bitfield.
        pub fn set_new_level_of_pin(&mut self, new_level_of_pin: NewLevelOfPin) {
            set_bit_range!(&mut self.flags, new_level_of_pin, u8, u8, 0, 0);
        }
    }

    impl ConcreteMessage for MsgExtEvent {
        const MESSAGE_TYPE: u16 = 257;
        const MESSAGE_NAME: &'static str = "MSG_EXT_EVENT";
    }

    impl SbpMessage for MsgExtEvent {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> u16 {
            <Self as ConcreteMessage>::MESSAGE_TYPE
        }
        fn sender_id(&self) -> Option<u16> {
            self.sender_id
        }
        fn set_sender_id(&mut self, new_id: u16) {
            self.sender_id = Some(new_id);
        }
        fn encoded_len(&self) -> usize {
            WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
        }
        #[cfg(feature = "swiftnav")]
        fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
            let tow_s = (self.tow as f64) / 1000.0;
            #[allow(clippy::useless_conversion)]
            let wn: i16 = match self.wn.try_into() {
                Ok(wn) => wn,
                Err(e) => return Some(Err(e.into())),
            };
            let gps_time = match time::GpsTime::new(wn, tow_s) {
                Ok(gps_time) => gps_time,
                Err(e) => return Some(Err(e.into())),
            };
            Some(Ok(time::MessageTime::Rover(gps_time.into())))
        }
    }

    impl TryFrom<Sbp> for MsgExtEvent {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgExtEvent(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgExtEvent {
        const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.wn)
                + WireFormat::len(&self.tow)
                + WireFormat::len(&self.ns_residual)
                + WireFormat::len(&self.flags)
                + WireFormat::len(&self.pin)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.wn, buf);
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.ns_residual, buf);
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.pin, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgExtEvent {
                sender_id: None,
                wn: WireFormat::parse_unchecked(buf),
                tow: WireFormat::parse_unchecked(buf),
                ns_residual: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
                pin: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Time quality
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeQuality {
        /// Unknown - don't have nav solution
        UnknownDontHaveNavSolution = 0,

        /// Good (< 1 microsecond)
        Good = 1,
    }

    impl std::fmt::Display for TimeQuality {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeQuality::UnknownDontHaveNavSolution => {
                    f.write_str("Unknown - don't have nav solution")
                }
                TimeQuality::Good => f.write_str("Good (< 1 microsecond)"),
            }
        }
    }

    impl TryFrom<u8> for TimeQuality {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeQuality::UnknownDontHaveNavSolution),
                1 => Ok(TimeQuality::Good),
                i => Err(i),
            }
        }
    }

    /// New level of pin
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum NewLevelOfPin {
        /// Low (falling edge)
        Low = 0,

        /// High (rising edge)
        High = 1,
    }

    impl std::fmt::Display for NewLevelOfPin {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                NewLevelOfPin::Low => f.write_str("Low (falling edge)"),
                NewLevelOfPin::High => f.write_str("High (rising edge)"),
            }
        }
    }

    impl TryFrom<u8> for NewLevelOfPin {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(NewLevelOfPin::Low),
                1 => Ok(NewLevelOfPin::High),
                i => Err(i),
            }
        }
    }
}
