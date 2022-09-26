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
// Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages from a vehicle.
pub use msg_odometry::MsgOdometry;
pub use msg_wheeltick::MsgWheeltick;

pub mod msg_odometry {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Vehicle forward (x-axis) velocity
    ///
    /// Message representing the x component of vehicle velocity in the user frame
    /// at the odometry reference point(s) specified by the user. The offset for
    /// the odometry reference point and the definition and origin of the user
    /// frame are defined through the device settings interface. There are 4
    /// possible user-defined sources of this message which are labeled
    /// arbitrarily source 0 through 3. If using "processor time" time tags, the
    /// receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes
    /// available to synchronise odometry measurements with GNSS. Processor time
    /// shall roll over to zero after one week.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgOdometry {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Time field representing either milliseconds in the GPS Week or local CPU
        /// time from the producing system in milliseconds.  See the tow_source flag
        /// for the exact source of this timestamp.
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// The signed forward component of vehicle velocity.
        #[cfg_attr(feature = "serde", serde(rename = "velocity"))]
        pub velocity: i32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgOdometry {
        /// Gets the [VehicleMetadata][self::VehicleMetadata] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VehicleMetadata` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VehicleMetadata` were added.
        pub fn vehicle_metadata(&self) -> Result<VehicleMetadata, u8> {
            get_bit_range!(self.flags, u8, u8, 6, 5).try_into()
        }

        /// Set the bitrange corresponding to the [VehicleMetadata][VehicleMetadata] of the `flags` bitfield.
        pub fn set_vehicle_metadata(&mut self, vehicle_metadata: VehicleMetadata) {
            set_bit_range!(&mut self.flags, vehicle_metadata, u8, u8, 6, 5);
        }

        /// Gets the [VelocitySource][self::VelocitySource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocitySource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocitySource` were added.
        pub fn velocity_source(&self) -> Result<VelocitySource, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [VelocitySource][VelocitySource] of the `flags` bitfield.
        pub fn set_velocity_source(&mut self, velocity_source: VelocitySource) {
            set_bit_range!(&mut self.flags, velocity_source, u8, u8, 4, 3);
        }

        /// Gets the [TimeSource][self::TimeSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeSource` were added.
        pub fn time_source(&self) -> Result<TimeSource, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TimeSource][TimeSource] of the `flags` bitfield.
        pub fn set_time_source(&mut self, time_source: TimeSource) {
            set_bit_range!(&mut self.flags, time_source, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgOdometry {
        const MESSAGE_TYPE: u16 = 2307;
        const MESSAGE_NAME: &'static str = "MSG_ODOMETRY";
    }

    impl SbpMessage for MsgOdometry {
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
            let gps_time = match time::GpsTime::new(0, tow_s) {
                Ok(gps_time) => gps_time.tow(),
                Err(e) => return Some(Err(e.into())),
            };
            Some(Ok(time::MessageTime::Rover(gps_time.into())))
        }
    }

    impl TryFrom<Sbp> for MsgOdometry {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgOdometry(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgOdometry {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.velocity)
                + WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.velocity, buf);
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgOdometry {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                velocity: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Vehicle Metadata
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VehicleMetadata {
        /// Unavailable
        Unavailable = 0,

        /// Forward
        Forward = 1,

        /// Reverse
        Reverse = 2,

        /// Park
        Park = 3,
    }

    impl std::fmt::Display for VehicleMetadata {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VehicleMetadata::Unavailable => f.write_str("Unavailable"),
                VehicleMetadata::Forward => f.write_str("Forward"),
                VehicleMetadata::Reverse => f.write_str("Reverse"),
                VehicleMetadata::Park => f.write_str("Park"),
            }
        }
    }

    impl TryFrom<u8> for VehicleMetadata {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VehicleMetadata::Unavailable),
                1 => Ok(VehicleMetadata::Forward),
                2 => Ok(VehicleMetadata::Reverse),
                3 => Ok(VehicleMetadata::Park),
                i => Err(i),
            }
        }
    }

    /// Velocity Source
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocitySource {
        /// Source 0
        Source0 = 0,

        /// Source 1
        Source1 = 1,

        /// Source 2
        Source2 = 2,

        /// Source 3
        Source3 = 3,
    }

    impl std::fmt::Display for VelocitySource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocitySource::Source0 => f.write_str("Source 0"),
                VelocitySource::Source1 => f.write_str("Source 1"),
                VelocitySource::Source2 => f.write_str("Source 2"),
                VelocitySource::Source3 => f.write_str("Source 3"),
            }
        }
    }

    impl TryFrom<u8> for VelocitySource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocitySource::Source0),
                1 => Ok(VelocitySource::Source1),
                2 => Ok(VelocitySource::Source2),
                3 => Ok(VelocitySource::Source3),
                i => Err(i),
            }
        }
    }

    /// Time source
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeSource {
        /// None (invalid)
        None = 0,

        /// GPS Solution (ms in week)
        GpsSolution = 1,

        /// Processor Time
        ProcessorTime = 2,
    }

    impl std::fmt::Display for TimeSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeSource::None => f.write_str("None (invalid)"),
                TimeSource::GpsSolution => f.write_str("GPS Solution (ms in week)"),
                TimeSource::ProcessorTime => f.write_str("Processor Time"),
            }
        }
    }

    impl TryFrom<u8> for TimeSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeSource::None),
                1 => Ok(TimeSource::GpsSolution),
                2 => Ok(TimeSource::ProcessorTime),
                i => Err(i),
            }
        }
    }
}

pub mod msg_wheeltick {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Accumulated wheeltick count message
    ///
    /// Message containing the accumulated distance travelled by a wheel located
    /// at an odometry reference point defined by the user. The offset for the
    /// odometry reference point and the definition and origin of the user frame
    /// are defined through the device settings interface. The source of this
    /// message is identified by the source field, which is an integer ranging
    /// from 0 to 255. The timestamp associated with this message should represent
    /// the time when the accumulated tick count reached the value given by the
    /// contents of this message as accurately as possible. If using "local CPU
    /// time" time tags, the receiving end will expect a `MSG_GNSS_TIME_OFFSET`
    /// when a PVT fix becomes available to synchronise wheeltick measurements
    /// with GNSS. Local CPU time shall roll over to zero after one week.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgWheeltick {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Time field representing either microseconds since the last PPS,
        /// microseconds in the GPS Week or local CPU time from the producing system
        /// in microseconds. See the synch_type field for the exact meaning of this
        /// timestamp.
        #[cfg_attr(feature = "serde", serde(rename = "time"))]
        pub time: u64,
        /// Field indicating the type of timestamp contained in the time field.
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// ID of the sensor producing this message
        #[cfg_attr(feature = "serde", serde(rename = "source"))]
        pub source: u8,
        /// Free-running counter of the accumulated distance for this sensor. The
        /// counter should be incrementing if travelling into one direction and
        /// decrementing when travelling in the opposite direction.
        #[cfg_attr(feature = "serde", serde(rename = "ticks"))]
        pub ticks: i32,
    }

    impl MsgWheeltick {
        /// Gets the [VehicleMetadata][self::VehicleMetadata] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VehicleMetadata` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VehicleMetadata` were added.
        pub fn vehicle_metadata(&self) -> Result<VehicleMetadata, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 2).try_into()
        }

        /// Set the bitrange corresponding to the [VehicleMetadata][VehicleMetadata] of the `flags` bitfield.
        pub fn set_vehicle_metadata(&mut self, vehicle_metadata: VehicleMetadata) {
            set_bit_range!(&mut self.flags, vehicle_metadata, u8, u8, 3, 2);
        }

        /// Gets the [SynchronizationType][self::SynchronizationType] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SynchronizationType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SynchronizationType` were added.
        pub fn synchronization_type(&self) -> Result<SynchronizationType, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [SynchronizationType][SynchronizationType] of the `flags` bitfield.
        pub fn set_synchronization_type(&mut self, synchronization_type: SynchronizationType) {
            set_bit_range!(&mut self.flags, synchronization_type, u8, u8, 1, 0);
        }
    }

    impl ConcreteMessage for MsgWheeltick {
        const MESSAGE_TYPE: u16 = 2308;
        const MESSAGE_NAME: &'static str = "MSG_WHEELTICK";
    }

    impl SbpMessage for MsgWheeltick {
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
            // only consider wheelticks with synchronization type value "microsec in GPS week"
            if self.flags != 1 {
                return None;
            }
            let tow_s = (self.time as f64) / 1000000.0;
            let gps_time = match time::GpsTime::new(0, tow_s) {
                Ok(gps_time) => gps_time.tow(),
                Err(e) => return Some(Err(e.into())),
            };
            Some(Ok(time::MessageTime::Rover(gps_time.into())))
        }
    }

    impl TryFrom<Sbp> for MsgWheeltick {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgWheeltick(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgWheeltick {
        const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.time)
                + WireFormat::len(&self.flags)
                + WireFormat::len(&self.source)
                + WireFormat::len(&self.ticks)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.time, buf);
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.source, buf);
            WireFormat::write(&self.ticks, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgWheeltick {
                sender_id: None,
                time: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
                source: WireFormat::parse_unchecked(buf),
                ticks: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Vehicle Metadata
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VehicleMetadata {
        /// Unavailable
        Unavailable = 0,

        /// Forward
        Forward = 1,

        /// Reverse
        Reverse = 2,

        /// Park
        Park = 3,
    }

    impl std::fmt::Display for VehicleMetadata {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VehicleMetadata::Unavailable => f.write_str("Unavailable"),
                VehicleMetadata::Forward => f.write_str("Forward"),
                VehicleMetadata::Reverse => f.write_str("Reverse"),
                VehicleMetadata::Park => f.write_str("Park"),
            }
        }
    }

    impl TryFrom<u8> for VehicleMetadata {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VehicleMetadata::Unavailable),
                1 => Ok(VehicleMetadata::Forward),
                2 => Ok(VehicleMetadata::Reverse),
                3 => Ok(VehicleMetadata::Park),
                i => Err(i),
            }
        }
    }

    /// Synchronization type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum SynchronizationType {
        /// microseconds since last PPS
        MicrosecondsSinceLastPps = 0,

        /// microseconds in GPS week
        MicrosecondsInGpsWeek = 1,

        /// local CPU time in nominal microseconds
        LocalCpuTimeInNominalMicroseconds = 2,
    }

    impl std::fmt::Display for SynchronizationType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SynchronizationType::MicrosecondsSinceLastPps => {
                    f.write_str("microseconds since last PPS")
                }
                SynchronizationType::MicrosecondsInGpsWeek => {
                    f.write_str("microseconds in GPS week")
                }
                SynchronizationType::LocalCpuTimeInNominalMicroseconds => {
                    f.write_str("local CPU time in nominal microseconds")
                }
            }
        }
    }

    impl TryFrom<u8> for SynchronizationType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(SynchronizationType::MicrosecondsSinceLastPps),
                1 => Ok(SynchronizationType::MicrosecondsInGpsWeek),
                2 => Ok(SynchronizationType::LocalCpuTimeInNominalMicroseconds),
                i => Err(i),
            }
        }
    }
}
