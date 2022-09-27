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
// Automatically generated from yaml/swiftnav/sbp/ndb.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for logging NDB events.
pub use msg_ndb_event::MsgNdbEvent;

pub mod msg_ndb_event {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Navigation DataBase Event
    ///
    /// This message is sent out when an object is stored into NDB. If needed
    /// message could also be sent out when fetching an object from NDB.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgNdbEvent {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// HW time in milliseconds.
        #[cfg_attr(feature = "serde", serde(rename = "recv_time"))]
        pub recv_time: u64,
        /// Event type.
        #[cfg_attr(feature = "serde", serde(rename = "event"))]
        pub event: u8,
        /// Event object type.
        #[cfg_attr(feature = "serde", serde(rename = "object_type"))]
        pub object_type: u8,
        /// Event result.
        #[cfg_attr(feature = "serde", serde(rename = "result"))]
        pub result: u8,
        /// Data source for STORE event, reserved for other events.
        #[cfg_attr(feature = "serde", serde(rename = "data_source"))]
        pub data_source: u8,
        /// GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
        /// indicates for which signal the object belongs to. Reserved in other
        /// cases.
        #[cfg_attr(feature = "serde", serde(rename = "object_sid"))]
        pub object_sid: GnssSignal,
        /// GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR
        /// L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates from
        /// which SV data was decoded. Reserved in other cases.
        #[cfg_attr(feature = "serde", serde(rename = "src_sid"))]
        pub src_sid: GnssSignal,
        /// A unique identifier of the sending hardware. For v1.0, set to the 2
        /// least significant bytes of the device serial number, valid only if
        /// data_source is NDB_DS_SBP. Reserved in case of other data_source.
        #[cfg_attr(feature = "serde", serde(rename = "original_sender"))]
        pub original_sender: u16,
    }

    impl MsgNdbEvent {
        /// Gets the [EventType][self::EventType] stored in the `event` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `EventType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `EventType` were added.
        pub fn event_type(&self) -> Result<EventType, u8> {
            get_bit_range!(self.event, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [EventType][EventType] of the `event` bitfield.
        pub fn set_event_type(&mut self, event_type: EventType) {
            set_bit_range!(&mut self.event, event_type, u8, u8, 1, 0);
        }

        /// Gets the [EventObjectType][self::EventObjectType] stored in the `object_type` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `EventObjectType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `EventObjectType` were added.
        pub fn event_object_type(&self) -> Result<EventObjectType, u8> {
            get_bit_range!(self.object_type, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [EventObjectType][EventObjectType] of the `object_type` bitfield.
        pub fn set_event_object_type(&mut self, event_object_type: EventObjectType) {
            set_bit_range!(&mut self.object_type, event_object_type, u8, u8, 2, 0);
        }

        /// Gets the [EventResult][self::EventResult] stored in the `result` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `EventResult` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `EventResult` were added.
        pub fn event_result(&self) -> Result<EventResult, u8> {
            get_bit_range!(self.result, u8, u8, 3, 0).try_into()
        }

        /// Set the bitrange corresponding to the [EventResult][EventResult] of the `result` bitfield.
        pub fn set_event_result(&mut self, event_result: EventResult) {
            set_bit_range!(&mut self.result, event_result, u8, u8, 3, 0);
        }

        /// Gets the [DataSource][self::DataSource] stored in the `data_source` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `DataSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `DataSource` were added.
        pub fn data_source(&self) -> Result<DataSource, u8> {
            get_bit_range!(self.data_source, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [DataSource][DataSource] of the `data_source` bitfield.
        pub fn set_data_source(&mut self, data_source: DataSource) {
            set_bit_range!(&mut self.data_source, data_source, u8, u8, 1, 0);
        }
    }

    impl ConcreteMessage for MsgNdbEvent {
        const MESSAGE_TYPE: u16 = 1024;
        const MESSAGE_NAME: &'static str = "MSG_NDB_EVENT";
    }

    impl SbpMessage for MsgNdbEvent {
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
    }

    impl TryFrom<Sbp> for MsgNdbEvent {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgNdbEvent(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgNdbEvent {
        const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <GnssSignal as WireFormat>::MIN_LEN
            + <GnssSignal as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.recv_time)
                + WireFormat::len(&self.event)
                + WireFormat::len(&self.object_type)
                + WireFormat::len(&self.result)
                + WireFormat::len(&self.data_source)
                + WireFormat::len(&self.object_sid)
                + WireFormat::len(&self.src_sid)
                + WireFormat::len(&self.original_sender)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.recv_time, buf);
            WireFormat::write(&self.event, buf);
            WireFormat::write(&self.object_type, buf);
            WireFormat::write(&self.result, buf);
            WireFormat::write(&self.data_source, buf);
            WireFormat::write(&self.object_sid, buf);
            WireFormat::write(&self.src_sid, buf);
            WireFormat::write(&self.original_sender, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgNdbEvent {
                sender_id: None,
                recv_time: WireFormat::parse_unchecked(buf),
                event: WireFormat::parse_unchecked(buf),
                object_type: WireFormat::parse_unchecked(buf),
                result: WireFormat::parse_unchecked(buf),
                data_source: WireFormat::parse_unchecked(buf),
                object_sid: WireFormat::parse_unchecked(buf),
                src_sid: WireFormat::parse_unchecked(buf),
                original_sender: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Event type.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum EventType {
        /// UNKNOWN
        Unknown = 0,

        /// STORE
        Store = 1,

        /// FETCH
        Fetch = 2,

        /// ERASE
        Erase = 3,
    }

    impl std::fmt::Display for EventType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                EventType::Unknown => f.write_str("UNKNOWN"),
                EventType::Store => f.write_str("STORE"),
                EventType::Fetch => f.write_str("FETCH"),
                EventType::Erase => f.write_str("ERASE"),
            }
        }
    }

    impl TryFrom<u8> for EventType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(EventType::Unknown),
                1 => Ok(EventType::Store),
                2 => Ok(EventType::Fetch),
                3 => Ok(EventType::Erase),
                i => Err(i),
            }
        }
    }

    /// Event object type.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum EventObjectType {
        /// UNKNOWN
        Unknown = 0,

        /// EPHEMERIS
        Ephemeris = 1,

        /// ALMANAC
        Almanac = 2,

        /// ALMANAC_WN
        AlmanacWn = 3,

        /// IONO
        Iono = 4,

        /// L2C_CAP
        L2CCap = 5,

        /// LGF
        Lgf = 6,
    }

    impl std::fmt::Display for EventObjectType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                EventObjectType::Unknown => f.write_str("UNKNOWN"),
                EventObjectType::Ephemeris => f.write_str("EPHEMERIS"),
                EventObjectType::Almanac => f.write_str("ALMANAC"),
                EventObjectType::AlmanacWn => f.write_str("ALMANAC_WN"),
                EventObjectType::Iono => f.write_str("IONO"),
                EventObjectType::L2CCap => f.write_str("L2C_CAP"),
                EventObjectType::Lgf => f.write_str("LGF"),
            }
        }
    }

    impl TryFrom<u8> for EventObjectType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(EventObjectType::Unknown),
                1 => Ok(EventObjectType::Ephemeris),
                2 => Ok(EventObjectType::Almanac),
                3 => Ok(EventObjectType::AlmanacWn),
                4 => Ok(EventObjectType::Iono),
                5 => Ok(EventObjectType::L2CCap),
                6 => Ok(EventObjectType::Lgf),
                i => Err(i),
            }
        }
    }

    /// Event result.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum EventResult {
        /// NDB_ERR_NONE
        NdbErrNone = 0,

        /// NDB_ERR_MISSING_IE
        NdbErrMissingIe = 1,

        /// NDB_ERR_UNSUPPORTED
        NdbErrUnsupported = 2,

        /// NDB_ERR_FILE_IO
        NdbErrFileIo = 3,

        /// NDB_ERR_INIT_DONE
        NdbErrInitDone = 4,

        /// NDB_ERR_BAD_PARAM
        NdbErrBadParam = 5,

        /// NDB_ERR_UNRELIABLE_DATA
        NdbErrUnreliableData = 6,

        /// NDB_ERR_ALGORITHM_ERROR
        NdbErrAlgorithmError = 7,

        /// NDB_ERR_NO_DATA
        NdbErrNoData = 8,

        /// NDB_ERR_NO_CHANGE
        NdbErrNoChange = 9,

        /// NDB_ERR_OLDER_DATA
        NdbErrOlderData = 10,
    }

    impl std::fmt::Display for EventResult {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                EventResult::NdbErrNone => f.write_str("NDB_ERR_NONE"),
                EventResult::NdbErrMissingIe => f.write_str("NDB_ERR_MISSING_IE"),
                EventResult::NdbErrUnsupported => f.write_str("NDB_ERR_UNSUPPORTED"),
                EventResult::NdbErrFileIo => f.write_str("NDB_ERR_FILE_IO"),
                EventResult::NdbErrInitDone => f.write_str("NDB_ERR_INIT_DONE"),
                EventResult::NdbErrBadParam => f.write_str("NDB_ERR_BAD_PARAM"),
                EventResult::NdbErrUnreliableData => f.write_str("NDB_ERR_UNRELIABLE_DATA"),
                EventResult::NdbErrAlgorithmError => f.write_str("NDB_ERR_ALGORITHM_ERROR"),
                EventResult::NdbErrNoData => f.write_str("NDB_ERR_NO_DATA"),
                EventResult::NdbErrNoChange => f.write_str("NDB_ERR_NO_CHANGE"),
                EventResult::NdbErrOlderData => f.write_str("NDB_ERR_OLDER_DATA"),
            }
        }
    }

    impl TryFrom<u8> for EventResult {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(EventResult::NdbErrNone),
                1 => Ok(EventResult::NdbErrMissingIe),
                2 => Ok(EventResult::NdbErrUnsupported),
                3 => Ok(EventResult::NdbErrFileIo),
                4 => Ok(EventResult::NdbErrInitDone),
                5 => Ok(EventResult::NdbErrBadParam),
                6 => Ok(EventResult::NdbErrUnreliableData),
                7 => Ok(EventResult::NdbErrAlgorithmError),
                8 => Ok(EventResult::NdbErrNoData),
                9 => Ok(EventResult::NdbErrNoChange),
                10 => Ok(EventResult::NdbErrOlderData),
                i => Err(i),
            }
        }
    }

    /// Data source.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum DataSource {
        /// NDB_DS_UNDEFINED
        NdbDsUndefined = 0,

        /// NDB_DS_INIT
        NdbDsInit = 1,

        /// NDB_DS_RECEIVER
        NdbDsReceiver = 2,

        /// NDB_DS_SBP
        NdbDsSbp = 3,
    }

    impl std::fmt::Display for DataSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                DataSource::NdbDsUndefined => f.write_str("NDB_DS_UNDEFINED"),
                DataSource::NdbDsInit => f.write_str("NDB_DS_INIT"),
                DataSource::NdbDsReceiver => f.write_str("NDB_DS_RECEIVER"),
                DataSource::NdbDsSbp => f.write_str("NDB_DS_SBP"),
            }
        }
    }

    impl TryFrom<u8> for DataSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(DataSource::NdbDsUndefined),
                1 => Ok(DataSource::NdbDsInit),
                2 => Ok(DataSource::NdbDsReceiver),
                3 => Ok(DataSource::NdbDsSbp),
                i => Err(i),
            }
        }
    }
}
