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
// Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized Metadata messages for Fuzed Solution from Swift Navigation
//! devices.
pub use gnss_input_type::GnssInputType;
pub use imu_input_type::ImuInputType;
pub use msg_soln_meta::MsgSolnMeta;
pub use msg_soln_meta_dep_a::MsgSolnMetaDepA;
pub use odo_input_type::OdoInputType;
pub use solution_input_type::SolutionInputType;

pub mod gnss_input_type {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Instruments the physical type of GNSS sensor input to the fuzed solution
    ///
    /// Metadata around the GNSS sensors involved in the fuzed solution.
    /// Accessible through sol_in\[N\].flags in a MSG_SOLN_META.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct GnssInputType {
        /// flags that store all relevant info specific to this sensor type.
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl GnssInputType {
        /// Gets the [TypeOfGnssMeasurement][self::TypeOfGnssMeasurement] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfGnssMeasurement` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfGnssMeasurement` were added.
        pub fn type_of_gnss_measurement(&self) -> Result<TypeOfGnssMeasurement, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfGnssMeasurement][TypeOfGnssMeasurement] of the `flags` bitfield.
        pub fn set_type_of_gnss_measurement(
            &mut self,
            type_of_gnss_measurement: TypeOfGnssMeasurement,
        ) {
            set_bit_range!(&mut self.flags, type_of_gnss_measurement, u8, u8, 1, 0);
        }
    }

    impl WireFormat for GnssInputType {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            GnssInputType {
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Type of GNSS measurement
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfGnssMeasurement {
        /// GNSS Position
        GnssPosition = 0,

        /// GNSS Velocity Doppler
        GnssVelocityDoppler = 1,

        /// GNSS Velocity Displacement
        GnssVelocityDisplacement = 2,
    }

    impl std::fmt::Display for TypeOfGnssMeasurement {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfGnssMeasurement::GnssPosition => f.write_str("GNSS Position"),
                TypeOfGnssMeasurement::GnssVelocityDoppler => f.write_str("GNSS Velocity Doppler"),
                TypeOfGnssMeasurement::GnssVelocityDisplacement => {
                    f.write_str("GNSS Velocity Displacement")
                }
            }
        }
    }

    impl TryFrom<u8> for TypeOfGnssMeasurement {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfGnssMeasurement::GnssPosition),
                1 => Ok(TypeOfGnssMeasurement::GnssVelocityDoppler),
                2 => Ok(TypeOfGnssMeasurement::GnssVelocityDisplacement),
                i => Err(i),
            }
        }
    }
}

pub mod imu_input_type {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Provides detail about the IMU sensor, its timestamping mode, and its quality for input to the fuzed solution

    ///
    /// Metadata around the IMU sensors involved in the fuzed solution. Accessible
    /// through sol_in\[N\].flags in a MSG_SOLN_META.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct ImuInputType {
        /// Instrument time, grade, and architecture for a sensor.
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl ImuInputType {
        /// Gets the [TimeStatus][self::TimeStatus] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeStatus` were added.
        pub fn time_status(&self) -> Result<TimeStatus, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 4).try_into()
        }

        /// Set the bitrange corresponding to the [TimeStatus][TimeStatus] of the `flags` bitfield.
        pub fn set_time_status(&mut self, time_status: TimeStatus) {
            set_bit_range!(&mut self.flags, time_status, u8, u8, 5, 4);
        }

        /// Gets the [ImuGrade][self::ImuGrade] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ImuGrade` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ImuGrade` were added.
        pub fn imu_grade(&self) -> Result<ImuGrade, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 2).try_into()
        }

        /// Set the bitrange corresponding to the [ImuGrade][ImuGrade] of the `flags` bitfield.
        pub fn set_imu_grade(&mut self, imu_grade: ImuGrade) {
            set_bit_range!(&mut self.flags, imu_grade, u8, u8, 3, 2);
        }

        /// Gets the [ImuArchitecture][self::ImuArchitecture] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ImuArchitecture` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ImuArchitecture` were added.
        pub fn imu_architecture(&self) -> Result<ImuArchitecture, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ImuArchitecture][ImuArchitecture] of the `flags` bitfield.
        pub fn set_imu_architecture(&mut self, imu_architecture: ImuArchitecture) {
            set_bit_range!(&mut self.flags, imu_architecture, u8, u8, 1, 0);
        }
    }

    impl WireFormat for ImuInputType {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            ImuInputType {
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Time status
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeStatus {
        /// Reference epoch is start of current GPS week
        ReferenceEpochIsStartOfCurrentGpsWeek = 0,

        /// Reference epoch is time of system startup
        ReferenceEpochIsTimeOfSystemStartup = 1,

        /// Reference epoch is unknown
        ReferenceEpochIsUnknown = 2,

        /// Reference epoch is last PPS
        ReferenceEpochIsLastPps = 3,
    }

    impl std::fmt::Display for TimeStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeStatus::ReferenceEpochIsStartOfCurrentGpsWeek => {
                    f.write_str("Reference epoch is start of current GPS week")
                }
                TimeStatus::ReferenceEpochIsTimeOfSystemStartup => {
                    f.write_str("Reference epoch is time of system startup")
                }
                TimeStatus::ReferenceEpochIsUnknown => f.write_str("Reference epoch is unknown"),
                TimeStatus::ReferenceEpochIsLastPps => f.write_str("Reference epoch is last PPS"),
            }
        }
    }

    impl TryFrom<u8> for TimeStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeStatus::ReferenceEpochIsStartOfCurrentGpsWeek),
                1 => Ok(TimeStatus::ReferenceEpochIsTimeOfSystemStartup),
                2 => Ok(TimeStatus::ReferenceEpochIsUnknown),
                3 => Ok(TimeStatus::ReferenceEpochIsLastPps),
                i => Err(i),
            }
        }
    }

    /// IMU Grade
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ImuGrade {
        /// Consumer Grade
        ConsumerGrade = 0,

        /// Tactical grade
        TacticalGrade = 1,

        /// Intermediate Grade
        IntermediateGrade = 2,

        /// Superior (Marine / Aviation) Grade
        SuperiorGrade = 3,
    }

    impl std::fmt::Display for ImuGrade {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ImuGrade::ConsumerGrade => f.write_str("Consumer Grade"),
                ImuGrade::TacticalGrade => f.write_str("Tactical grade"),
                ImuGrade::IntermediateGrade => f.write_str("Intermediate Grade"),
                ImuGrade::SuperiorGrade => f.write_str("Superior (Marine / Aviation) Grade"),
            }
        }
    }

    impl TryFrom<u8> for ImuGrade {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ImuGrade::ConsumerGrade),
                1 => Ok(ImuGrade::TacticalGrade),
                2 => Ok(ImuGrade::IntermediateGrade),
                3 => Ok(ImuGrade::SuperiorGrade),
                i => Err(i),
            }
        }
    }

    /// IMU architecture
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ImuArchitecture {
        /// 6-axis MEMS
        _6AxisMems = 0,

        /// Other type
        OtherType = 1,
    }

    impl std::fmt::Display for ImuArchitecture {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ImuArchitecture::_6AxisMems => f.write_str("6-axis MEMS"),
                ImuArchitecture::OtherType => f.write_str("Other type"),
            }
        }
    }

    impl TryFrom<u8> for ImuArchitecture {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ImuArchitecture::_6AxisMems),
                1 => Ok(ImuArchitecture::OtherType),
                i => Err(i),
            }
        }
    }
}

pub mod msg_soln_meta {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Solution Sensors Metadata
    ///
    /// This message contains all metadata about the sensors received and/or used
    /// in computing the sensorfusion solution. It focuses primarily, but not
    /// only, on GNSS metadata. Regarding the age of the last received valid GNSS
    /// solution, the highest two bits are time status, indicating whether age
    /// gnss can or can not be used to retrieve time of measurement (noted TOM,
    /// also known as time of validity) If it can, subtract 'age gnss' from 'tow'
    /// in navigation messages to get TOM. Can be used before alignment is
    /// complete in the Fusion Engine, when output solution is the last received
    /// valid GNSS solution and its tow is not a TOM.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSolnMeta {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Position Dilution of Precision as per last available DOPS from PVT
        /// engine (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "pdop"))]
        pub pdop: u16,
        /// Horizontal Dilution of Precision as per last available DOPS from PVT
        /// engine (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "hdop"))]
        pub hdop: u16,
        /// Vertical Dilution of Precision as per last available DOPS from PVT
        /// engine (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "vdop"))]
        pub vdop: u16,
        /// Age of corrections as per last available AGE_CORRECTIONS from PVT engine
        /// (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "age_corrections"))]
        pub age_corrections: u16,
        /// Age and Time Status of the last received valid GNSS solution.
        #[cfg_attr(feature = "serde", serde(rename = "age_gnss"))]
        pub age_gnss: u32,
        /// Array of Metadata describing the sensors potentially involved in the
        /// solution. Each element in the array represents a single sensor type and
        /// consists of flags containing (meta)data pertaining to that specific
        /// single sensor. Refer to each (XX)InputType descriptor in the present
        /// doc.
        #[cfg_attr(feature = "serde", serde(rename = "sol_in"))]
        pub sol_in: Vec<SolutionInputType>,
    }

    impl MsgSolnMeta {
        /// Gets the [TimeStatus][self::TimeStatus] stored in the `age_gnss` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeStatus` were added.
        pub fn time_status(&self) -> Result<TimeStatus, u8> {
            get_bit_range!(self.age_gnss, u32, u8, 31, 30).try_into()
        }

        /// Set the bitrange corresponding to the [TimeStatus][TimeStatus] of the `age_gnss` bitfield.
        pub fn set_time_status(&mut self, time_status: TimeStatus) {
            set_bit_range!(&mut self.age_gnss, time_status, u32, u8, 31, 30);
        }

        /// Gets the `age_of_the_last_received_valid_gnss_solution` stored in `age_gnss`.
        pub fn age_of_the_last_received_valid_gnss_solution(&self) -> u32 {
            get_bit_range!(self.age_gnss, u32, u32, 29, 0)
        }

        /// Sets the `age_of_the_last_received_valid_gnss_solution` bitrange of `age_gnss`.
        pub fn set_age_of_the_last_received_valid_gnss_solution(
            &mut self,
            age_of_the_last_received_valid_gnss_solution: u32,
        ) {
            set_bit_range!(
                &mut self.age_gnss,
                age_of_the_last_received_valid_gnss_solution,
                u32,
                u32,
                29,
                0
            );
        }
    }

    impl ConcreteMessage for MsgSolnMeta {
        const MESSAGE_TYPE: u16 = 65294;
        const MESSAGE_NAME: &'static str = "MSG_SOLN_META";
    }

    impl SbpMessage for MsgSolnMeta {
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

    impl TryFrom<Sbp> for MsgSolnMeta {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSolnMeta(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSolnMeta {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <Vec<SolutionInputType> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.pdop)
                + WireFormat::len(&self.hdop)
                + WireFormat::len(&self.vdop)
                + WireFormat::len(&self.age_corrections)
                + WireFormat::len(&self.age_gnss)
                + WireFormat::len(&self.sol_in)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.pdop, buf);
            WireFormat::write(&self.hdop, buf);
            WireFormat::write(&self.vdop, buf);
            WireFormat::write(&self.age_corrections, buf);
            WireFormat::write(&self.age_gnss, buf);
            WireFormat::write(&self.sol_in, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSolnMeta {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                pdop: WireFormat::parse_unchecked(buf),
                hdop: WireFormat::parse_unchecked(buf),
                vdop: WireFormat::parse_unchecked(buf),
                age_corrections: WireFormat::parse_unchecked(buf),
                age_gnss: WireFormat::parse_unchecked(buf),
                sol_in: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Time status
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeStatus {
        /// Age can not be used to retrieve TOM
        AgeCanNotBeUsedToRetrieveTom = 0,

        /// Age can be used to retrieve TOM
        AgeCanBeUsedToRetrieveTom = 1,
    }

    impl std::fmt::Display for TimeStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeStatus::AgeCanNotBeUsedToRetrieveTom => {
                    f.write_str("Age can not be used to retrieve TOM")
                }
                TimeStatus::AgeCanBeUsedToRetrieveTom => {
                    f.write_str("Age can be used to retrieve TOM")
                }
            }
        }
    }

    impl TryFrom<u8> for TimeStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeStatus::AgeCanNotBeUsedToRetrieveTom),
                1 => Ok(TimeStatus::AgeCanBeUsedToRetrieveTom),
                i => Err(i),
            }
        }
    }
}

pub mod msg_soln_meta_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Deprecated
    ///
    /// Deprecated.
    ///
    /// This message contains all metadata about the sensors received and/or used
    /// in computing the Fuzed Solution. It focuses primarily, but not only, on
    /// GNSS metadata.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSolnMetaDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Position Dilution of Precision as per last available DOPS from PVT
        /// engine (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "pdop"))]
        pub pdop: u16,
        /// Horizontal Dilution of Precision as per last available DOPS from PVT
        /// engine (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "hdop"))]
        pub hdop: u16,
        /// Vertical Dilution of Precision as per last available DOPS from PVT
        /// engine (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "vdop"))]
        pub vdop: u16,
        /// Number of satellites as per last available solution from PVT engine
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Age of corrections as per last available AGE_CORRECTIONS from PVT engine
        /// (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "age_corrections"))]
        pub age_corrections: u16,
        /// State of alignment and the status and receipt of the alignment inputs
        #[cfg_attr(feature = "serde", serde(rename = "alignment_status"))]
        pub alignment_status: u8,
        /// Tow of last-used GNSS position measurement
        #[cfg_attr(feature = "serde", serde(rename = "last_used_gnss_pos_tow"))]
        pub last_used_gnss_pos_tow: u32,
        /// Tow of last-used GNSS velocity measurement
        #[cfg_attr(feature = "serde", serde(rename = "last_used_gnss_vel_tow"))]
        pub last_used_gnss_vel_tow: u32,
        /// Array of Metadata describing the sensors potentially involved in the
        /// solution. Each element in the array represents a single sensor type and
        /// consists of flags containing (meta)data pertaining to that specific
        /// single sensor. Refer to each (XX)InputType descriptor in the present
        /// doc.
        #[cfg_attr(feature = "serde", serde(rename = "sol_in"))]
        pub sol_in: Vec<SolutionInputType>,
    }

    impl MsgSolnMetaDepA {
        /// Gets the [AlignmentStatus][self::AlignmentStatus] stored in the `alignment_status` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AlignmentStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AlignmentStatus` were added.
        pub fn alignment_status(&self) -> Result<AlignmentStatus, u8> {
            get_bit_range!(self.alignment_status, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [AlignmentStatus][AlignmentStatus] of the `alignment_status` bitfield.
        pub fn set_alignment_status(&mut self, alignment_status: AlignmentStatus) {
            set_bit_range!(&mut self.alignment_status, alignment_status, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgSolnMetaDepA {
        const MESSAGE_TYPE: u16 = 65295;
        const MESSAGE_NAME: &'static str = "MSG_SOLN_META_DEP_A";
    }

    impl SbpMessage for MsgSolnMetaDepA {
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

    impl TryFrom<Sbp> for MsgSolnMetaDepA {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSolnMetaDepA(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSolnMetaDepA {
        const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <Vec<SolutionInputType> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.pdop)
                + WireFormat::len(&self.hdop)
                + WireFormat::len(&self.vdop)
                + WireFormat::len(&self.n_sats)
                + WireFormat::len(&self.age_corrections)
                + WireFormat::len(&self.alignment_status)
                + WireFormat::len(&self.last_used_gnss_pos_tow)
                + WireFormat::len(&self.last_used_gnss_vel_tow)
                + WireFormat::len(&self.sol_in)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.pdop, buf);
            WireFormat::write(&self.hdop, buf);
            WireFormat::write(&self.vdop, buf);
            WireFormat::write(&self.n_sats, buf);
            WireFormat::write(&self.age_corrections, buf);
            WireFormat::write(&self.alignment_status, buf);
            WireFormat::write(&self.last_used_gnss_pos_tow, buf);
            WireFormat::write(&self.last_used_gnss_vel_tow, buf);
            WireFormat::write(&self.sol_in, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSolnMetaDepA {
                sender_id: None,
                pdop: WireFormat::parse_unchecked(buf),
                hdop: WireFormat::parse_unchecked(buf),
                vdop: WireFormat::parse_unchecked(buf),
                n_sats: WireFormat::parse_unchecked(buf),
                age_corrections: WireFormat::parse_unchecked(buf),
                alignment_status: WireFormat::parse_unchecked(buf),
                last_used_gnss_pos_tow: WireFormat::parse_unchecked(buf),
                last_used_gnss_vel_tow: WireFormat::parse_unchecked(buf),
                sol_in: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Alignment status
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum AlignmentStatus {
        /// Unknown reason or already aligned
        UnknownReasonOrAlreadyAligned = 0,

        /// Seed values loaded and Alignment in progress
        SeedValuesLoadedAndAlignmentInProgress = 1,

        /// No seed values and Alignment in progress
        NoSeedValuesAndAlignmentInProgress = 2,

        /// Seed values loaded but no GNSS measurements
        SeedValuesLoadedButNoGnssMeasurements = 3,

        /// No seed values nor GNSS measurements
        NoSeedValuesNorGnssMeasurements = 4,
    }

    impl std::fmt::Display for AlignmentStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AlignmentStatus::UnknownReasonOrAlreadyAligned => {
                    f.write_str("Unknown reason or already aligned")
                }
                AlignmentStatus::SeedValuesLoadedAndAlignmentInProgress => {
                    f.write_str("Seed values loaded and Alignment in progress")
                }
                AlignmentStatus::NoSeedValuesAndAlignmentInProgress => {
                    f.write_str("No seed values and Alignment in progress")
                }
                AlignmentStatus::SeedValuesLoadedButNoGnssMeasurements => {
                    f.write_str("Seed values loaded but no GNSS measurements")
                }
                AlignmentStatus::NoSeedValuesNorGnssMeasurements => {
                    f.write_str("No seed values nor GNSS measurements")
                }
            }
        }
    }

    impl TryFrom<u8> for AlignmentStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AlignmentStatus::UnknownReasonOrAlreadyAligned),
                1 => Ok(AlignmentStatus::SeedValuesLoadedAndAlignmentInProgress),
                2 => Ok(AlignmentStatus::NoSeedValuesAndAlignmentInProgress),
                3 => Ok(AlignmentStatus::SeedValuesLoadedButNoGnssMeasurements),
                4 => Ok(AlignmentStatus::NoSeedValuesNorGnssMeasurements),
                i => Err(i),
            }
        }
    }
}

pub mod odo_input_type {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Provides detail about the Odometry sensor, its timestamping mode, and its quality for input to the fuzed solution

    ///
    /// Metadata around the Odometry sensors involved in the fuzed solution.
    /// Accessible through sol_in\[N\].flags in a MSG_SOLN_META.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct OdoInputType {
        /// Instrument ODO rate, grade, and quality.
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl OdoInputType {
        /// Gets the [Rate][self::Rate] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `Rate` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `Rate` were added.
        pub fn rate(&self) -> Result<Rate, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 4).try_into()
        }

        /// Set the bitrange corresponding to the [Rate][Rate] of the `flags` bitfield.
        pub fn set_rate(&mut self, rate: Rate) {
            set_bit_range!(&mut self.flags, rate, u8, u8, 5, 4);
        }

        /// Gets the [OdometerGrade][self::OdometerGrade] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `OdometerGrade` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `OdometerGrade` were added.
        pub fn odometer_grade(&self) -> Result<OdometerGrade, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 2).try_into()
        }

        /// Set the bitrange corresponding to the [OdometerGrade][OdometerGrade] of the `flags` bitfield.
        pub fn set_odometer_grade(&mut self, odometer_grade: OdometerGrade) {
            set_bit_range!(&mut self.flags, odometer_grade, u8, u8, 3, 2);
        }

        /// Gets the [OdometerClass][self::OdometerClass] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `OdometerClass` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `OdometerClass` were added.
        pub fn odometer_class(&self) -> Result<OdometerClass, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [OdometerClass][OdometerClass] of the `flags` bitfield.
        pub fn set_odometer_class(&mut self, odometer_class: OdometerClass) {
            set_bit_range!(&mut self.flags, odometer_class, u8, u8, 1, 0);
        }
    }

    impl WireFormat for OdoInputType {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            OdoInputType {
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Rate
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum Rate {
        /// Fixed incoming rate
        FixedIncomingRate = 0,

        /// Triggered by minimum distance or speed
        TriggeredByMinimumDistanceOrSpeed = 1,
    }

    impl std::fmt::Display for Rate {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                Rate::FixedIncomingRate => f.write_str("Fixed incoming rate"),
                Rate::TriggeredByMinimumDistanceOrSpeed => {
                    f.write_str("Triggered by minimum distance or speed")
                }
            }
        }
    }

    impl TryFrom<u8> for Rate {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(Rate::FixedIncomingRate),
                1 => Ok(Rate::TriggeredByMinimumDistanceOrSpeed),
                i => Err(i),
            }
        }
    }

    /// Odometer grade
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum OdometerGrade {
        /// Low Grade (e.g. quantized CAN)
        LowGrade = 0,

        /// Medium Grade
        MediumGrade = 1,

        /// Superior Grade
        SuperiorGrade = 2,
    }

    impl std::fmt::Display for OdometerGrade {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                OdometerGrade::LowGrade => f.write_str("Low Grade (e.g. quantized CAN)"),
                OdometerGrade::MediumGrade => f.write_str("Medium Grade"),
                OdometerGrade::SuperiorGrade => f.write_str("Superior Grade"),
            }
        }
    }

    impl TryFrom<u8> for OdometerGrade {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(OdometerGrade::LowGrade),
                1 => Ok(OdometerGrade::MediumGrade),
                2 => Ok(OdometerGrade::SuperiorGrade),
                i => Err(i),
            }
        }
    }

    /// Odometer class
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum OdometerClass {
        /// Single or averaged ticks
        SingleOrAveragedTicks = 0,

        /// Single or averaged speed
        SingleOrAveragedSpeed = 1,

        /// Multi-dimensional ticks
        MultiDimensionalTicks = 2,

        /// Multi-dimensional speed
        MultiDimensionalSpeed = 3,
    }

    impl std::fmt::Display for OdometerClass {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                OdometerClass::SingleOrAveragedTicks => f.write_str("Single or averaged ticks"),
                OdometerClass::SingleOrAveragedSpeed => f.write_str("Single or averaged speed"),
                OdometerClass::MultiDimensionalTicks => f.write_str("Multi-dimensional ticks"),
                OdometerClass::MultiDimensionalSpeed => f.write_str("Multi-dimensional speed"),
            }
        }
    }

    impl TryFrom<u8> for OdometerClass {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(OdometerClass::SingleOrAveragedTicks),
                1 => Ok(OdometerClass::SingleOrAveragedSpeed),
                2 => Ok(OdometerClass::MultiDimensionalTicks),
                3 => Ok(OdometerClass::MultiDimensionalSpeed),
                i => Err(i),
            }
        }
    }
}

pub mod solution_input_type {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Flags for a given solution input type
    ///
    /// Metadata describing which sensors were involved in the solution. The
    /// structure is fixed no matter what the actual sensor type is. The
    /// sensor_type field tells you which sensor we are talking about. It also
    /// tells you whether the sensor data was actually used or not. The flags
    /// field, always a u8, contains the sensor-specific data. The content of
    /// flags, for each sensor type, is described in the relevant structures in
    /// this section.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct SolutionInputType {
        /// The type of sensor
        #[cfg_attr(feature = "serde", serde(rename = "sensor_type"))]
        pub sensor_type: u8,
        /// Refer to each InputType description
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl SolutionInputType {
        /// Gets the [SensorUsage][self::SensorUsage] stored in the `sensor_type` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SensorUsage` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SensorUsage` were added.
        pub fn sensor_usage(&self) -> Result<SensorUsage, u8> {
            get_bit_range!(self.sensor_type, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [SensorUsage][SensorUsage] of the `sensor_type` bitfield.
        pub fn set_sensor_usage(&mut self, sensor_usage: SensorUsage) {
            set_bit_range!(&mut self.sensor_type, sensor_usage, u8, u8, 4, 3);
        }

        /// Gets the [SensorType][self::SensorType] stored in the `sensor_type` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SensorType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SensorType` were added.
        pub fn sensor_type(&self) -> Result<SensorType, u8> {
            get_bit_range!(self.sensor_type, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [SensorType][SensorType] of the `sensor_type` bitfield.
        pub fn set_sensor_type(&mut self, sensor_type: SensorType) {
            set_bit_range!(&mut self.sensor_type, sensor_type, u8, u8, 2, 0);
        }
    }

    impl WireFormat for SolutionInputType {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.sensor_type) + WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.sensor_type, buf);
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            SolutionInputType {
                sensor_type: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Sensor Usage
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum SensorUsage {
        /// Unknown
        Unknown = 0,

        /// Received and used
        ReceivedAndUsed = 1,

        /// Received but not used
        ReceivedButNotUsed = 2,
    }

    impl std::fmt::Display for SensorUsage {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SensorUsage::Unknown => f.write_str("Unknown"),
                SensorUsage::ReceivedAndUsed => f.write_str("Received and used"),
                SensorUsage::ReceivedButNotUsed => f.write_str("Received but not used"),
            }
        }
    }

    impl TryFrom<u8> for SensorUsage {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(SensorUsage::Unknown),
                1 => Ok(SensorUsage::ReceivedAndUsed),
                2 => Ok(SensorUsage::ReceivedButNotUsed),
                i => Err(i),
            }
        }
    }

    /// Sensor Type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum SensorType {
        /// Invalid
        Invalid = 0,

        /// GNSS Position (see GNSSInputType)
        GnssPosition = 1,

        /// GNSS Velocity Displacement (see GNSSInputType)
        GnssVelocityDisplacement = 2,

        /// GNSS Velocity Doppler (see GNSSInputType)
        GnssVelocityDoppler = 3,

        /// Odometry Ticks (see OdoInputType)
        OdometryTicks = 4,

        /// Odometry Speed (see OdoInputType)
        OdometrySpeed = 5,

        /// IMU Sensor (see IMUInputType)
        ImuSensor = 6,
    }

    impl std::fmt::Display for SensorType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SensorType::Invalid => f.write_str("Invalid"),
                SensorType::GnssPosition => f.write_str("GNSS Position (see GNSSInputType)"),
                SensorType::GnssVelocityDisplacement => {
                    f.write_str("GNSS Velocity Displacement (see GNSSInputType)")
                }
                SensorType::GnssVelocityDoppler => {
                    f.write_str("GNSS Velocity Doppler (see GNSSInputType)")
                }
                SensorType::OdometryTicks => f.write_str("Odometry Ticks (see OdoInputType)"),
                SensorType::OdometrySpeed => f.write_str("Odometry Speed (see OdoInputType)"),
                SensorType::ImuSensor => f.write_str("IMU Sensor (see IMUInputType)"),
            }
        }
    }

    impl TryFrom<u8> for SensorType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(SensorType::Invalid),
                1 => Ok(SensorType::GnssPosition),
                2 => Ok(SensorType::GnssVelocityDisplacement),
                3 => Ok(SensorType::GnssVelocityDoppler),
                4 => Ok(SensorType::OdometryTicks),
                5 => Ok(SensorType::OdometrySpeed),
                6 => Ok(SensorType::ImuSensor),
                i => Err(i),
            }
        }
    }
}
