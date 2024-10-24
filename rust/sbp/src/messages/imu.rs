// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/swiftnav/sbp/imu.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Inertial Measurement Unit (IMU) messages.
pub use msg_imu_aux::MsgImuAux;
pub use msg_imu_comp::MsgImuComp;
pub use msg_imu_raw::MsgImuRaw;

pub mod msg_imu_aux {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Auxiliary IMU data
    ///
    /// Auxiliary data specific to a particular IMU. The `imu_type` field will
    /// always be consistent but the rest of the payload is device specific and
    /// depends on the value of `imu_type`.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgImuAux {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// IMU type
        #[cfg_attr(feature = "serde", serde(rename = "imu_type"))]
        pub imu_type: u8,
        /// Raw IMU temperature
        #[cfg_attr(feature = "serde", serde(rename = "temp"))]
        pub temp: i16,
        /// IMU configuration
        #[cfg_attr(feature = "serde", serde(rename = "imu_conf"))]
        pub imu_conf: u8,
    }

    impl MsgImuAux {
        /// Gets the [ImuType][self::ImuType] stored in the `imu_type` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ImuType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ImuType` were added.
        pub fn imu_type(&self) -> Result<ImuType, u8> {
            get_bit_range!(self.imu_type, u8, u8, 7, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ImuType][ImuType] of the `imu_type` bitfield.
        pub fn set_imu_type(&mut self, imu_type: ImuType) {
            set_bit_range!(&mut self.imu_type, imu_type, u8, u8, 7, 0);
        }

        /// Gets the [GyroscopeRange][self::GyroscopeRange] stored in the `imu_conf` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `GyroscopeRange` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `GyroscopeRange` were added.
        pub fn gyroscope_range(&self) -> Result<GyroscopeRange, u8> {
            get_bit_range!(self.imu_conf, u8, u8, 7, 4).try_into()
        }

        /// Set the bitrange corresponding to the [GyroscopeRange][GyroscopeRange] of the `imu_conf` bitfield.
        pub fn set_gyroscope_range(&mut self, gyroscope_range: GyroscopeRange) {
            set_bit_range!(&mut self.imu_conf, gyroscope_range, u8, u8, 7, 4);
        }

        /// Gets the [AccelerometerRange][self::AccelerometerRange] stored in the `imu_conf` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AccelerometerRange` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AccelerometerRange` were added.
        pub fn accelerometer_range(&self) -> Result<AccelerometerRange, u8> {
            get_bit_range!(self.imu_conf, u8, u8, 3, 0).try_into()
        }

        /// Set the bitrange corresponding to the [AccelerometerRange][AccelerometerRange] of the `imu_conf` bitfield.
        pub fn set_accelerometer_range(&mut self, accelerometer_range: AccelerometerRange) {
            set_bit_range!(&mut self.imu_conf, accelerometer_range, u8, u8, 3, 0);
        }
    }

    impl ConcreteMessage for MsgImuAux {
        const MESSAGE_TYPE: u16 = 2305;
        const MESSAGE_NAME: &'static str = "MSG_IMU_AUX";
    }

    impl SbpMessage for MsgImuAux {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }
    }

    impl FriendlyName for MsgImuAux {
        fn friendly_name() -> &'static str {
            "IMU AUX"
        }
    }

    impl TryFrom<Sbp> for MsgImuAux {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgImuAux(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgImuAux {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.imu_type)
                + WireFormat::len(&self.temp)
                + WireFormat::len(&self.imu_conf)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.imu_type, buf);
            WireFormat::write(&self.temp, buf);
            WireFormat::write(&self.imu_conf, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgImuAux {
                sender_id: None,
                imu_type: WireFormat::parse_unchecked(buf),
                temp: WireFormat::parse_unchecked(buf),
                imu_conf: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// IMU Type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ImuType {
        /// Bosch BMI160
        BoschBmi160 = 0,

        /// ST Microelectronics ASM330LLH
        StMicroelectronicsAsm330Llh = 1,

        /// TDK ICM-42670
        TdkIcm42670 = 3,

        /// Murata SCHA634-D03
        MurataScha634D03 = 4,

        /// TDK IAM-20680HP
        TdkIam20680Hp = 5,
    }

    impl std::fmt::Display for ImuType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ImuType::BoschBmi160 => f.write_str("Bosch BMI160"),
                ImuType::StMicroelectronicsAsm330Llh => {
                    f.write_str("ST Microelectronics ASM330LLH")
                }
                ImuType::TdkIcm42670 => f.write_str("TDK ICM-42670"),
                ImuType::MurataScha634D03 => f.write_str("Murata SCHA634-D03"),
                ImuType::TdkIam20680Hp => f.write_str("TDK IAM-20680HP"),
            }
        }
    }

    impl TryFrom<u8> for ImuType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ImuType::BoschBmi160),
                1 => Ok(ImuType::StMicroelectronicsAsm330Llh),
                3 => Ok(ImuType::TdkIcm42670),
                4 => Ok(ImuType::MurataScha634D03),
                5 => Ok(ImuType::TdkIam20680Hp),
                i => Err(i),
            }
        }
    }

    /// Gyroscope Range
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum GyroscopeRange {
        /// +/- 2000 deg / s
        _2000DegS = 0,

        /// +/- 1000 deg / s
        _1000DegS = 1,

        /// +/- 500 deg / s
        _500DegS = 2,

        /// +/- 250 deg / s
        _250DegS = 3,

        /// +/- 125 deg / s
        _125DegS = 4,

        /// +/- 300 deg / s
        _300DegS = 5,
    }

    impl std::fmt::Display for GyroscopeRange {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                GyroscopeRange::_2000DegS => f.write_str("+/- 2000 deg / s"),
                GyroscopeRange::_1000DegS => f.write_str("+/- 1000 deg / s"),
                GyroscopeRange::_500DegS => f.write_str("+/- 500 deg / s"),
                GyroscopeRange::_250DegS => f.write_str("+/- 250 deg / s"),
                GyroscopeRange::_125DegS => f.write_str("+/- 125 deg / s"),
                GyroscopeRange::_300DegS => f.write_str("+/- 300 deg / s"),
            }
        }
    }

    impl TryFrom<u8> for GyroscopeRange {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(GyroscopeRange::_2000DegS),
                1 => Ok(GyroscopeRange::_1000DegS),
                2 => Ok(GyroscopeRange::_500DegS),
                3 => Ok(GyroscopeRange::_250DegS),
                4 => Ok(GyroscopeRange::_125DegS),
                5 => Ok(GyroscopeRange::_300DegS),
                i => Err(i),
            }
        }
    }

    /// Accelerometer Range
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum AccelerometerRange {
        /// +/- 2g
        _2G = 0,

        /// +/- 4g
        _4G = 1,

        /// +/- 8g
        _8G = 2,

        /// +/- 16g
        _16G = 3,

        /// +/- 6g
        _6G = 4,
    }

    impl std::fmt::Display for AccelerometerRange {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AccelerometerRange::_2G => f.write_str("+/- 2g"),
                AccelerometerRange::_4G => f.write_str("+/- 4g"),
                AccelerometerRange::_8G => f.write_str("+/- 8g"),
                AccelerometerRange::_16G => f.write_str("+/- 16g"),
                AccelerometerRange::_6G => f.write_str("+/- 6g"),
            }
        }
    }

    impl TryFrom<u8> for AccelerometerRange {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AccelerometerRange::_2G),
                1 => Ok(AccelerometerRange::_4G),
                2 => Ok(AccelerometerRange::_8G),
                3 => Ok(AccelerometerRange::_16G),
                4 => Ok(AccelerometerRange::_6G),
                i => Err(i),
            }
        }
    }
}

pub mod msg_imu_comp {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Compensated IMU data
    ///
    /// Data from the Inertial Measurement Unit, containing accelerometer and
    /// gyroscope readings compensated for estimated errors and constant  physical
    /// effects. The output is valid for inertially referenced center  of
    /// navigation (IMU body frame) represented in vehicle body frame.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgImuComp {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Microseconds since reference epoch
        #[cfg_attr(feature = "serde", serde(rename = "time"))]
        pub time: u64,
        /// Contains the applied compensation parameters and time synchronization
        /// mode
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u16,
        /// Compensated acceleration X axis
        #[cfg_attr(feature = "serde", serde(rename = "acc_comp_x"))]
        pub acc_comp_x: i32,
        /// Compensated acceleration Y axis
        #[cfg_attr(feature = "serde", serde(rename = "acc_comp_y"))]
        pub acc_comp_y: i32,
        /// Compensated acceleration Z axis
        #[cfg_attr(feature = "serde", serde(rename = "acc_comp_z"))]
        pub acc_comp_z: i32,
        /// Compensated angular rate X axis
        #[cfg_attr(feature = "serde", serde(rename = "gyr_comp_x"))]
        pub gyr_comp_x: i32,
        /// Compensated angular rate Y axis
        #[cfg_attr(feature = "serde", serde(rename = "gyr_comp_y"))]
        pub gyr_comp_y: i32,
        /// Compensated angular rate Z axis
        #[cfg_attr(feature = "serde", serde(rename = "gyr_comp_z"))]
        pub gyr_comp_z: i32,
    }

    impl MsgImuComp {
        /// Gets the `gyroscopeerrorscompensated` flag.
        #[allow(clippy::identity_op)]
        pub fn gyroscopeerrorscompensated(&self) -> bool {
            ((self.flags >> 6) & 1) == 1
        }

        /// Sets the `gyroscopeerrorscompensated` flag.
        pub fn set_gyroscopeerrorscompensated(&mut self, gyroscopeerrorscompensated: bool) {
            self.flags ^= (!(gyroscopeerrorscompensated as u16)) & (1 << 6)
        }

        /// Gets the `accelerometererrorscompensated` flag.
        #[allow(clippy::identity_op)]
        pub fn accelerometererrorscompensated(&self) -> bool {
            ((self.flags >> 5) & 1) == 1
        }

        /// Sets the `accelerometererrorscompensated` flag.
        pub fn set_accelerometererrorscompensated(&mut self, accelerometererrorscompensated: bool) {
            self.flags ^= (!(accelerometererrorscompensated as u16)) & (1 << 5)
        }

        /// Gets the `corioliseffectcompensated` flag.
        #[allow(clippy::identity_op)]
        pub fn corioliseffectcompensated(&self) -> bool {
            ((self.flags >> 4) & 1) == 1
        }

        /// Sets the `corioliseffectcompensated` flag.
        pub fn set_corioliseffectcompensated(&mut self, corioliseffectcompensated: bool) {
            self.flags ^= (!(corioliseffectcompensated as u16)) & (1 << 4)
        }

        /// Gets the `earthrorationratecompensated` flag.
        #[allow(clippy::identity_op)]
        pub fn earthrorationratecompensated(&self) -> bool {
            ((self.flags >> 3) & 1) == 1
        }

        /// Sets the `earthrorationratecompensated` flag.
        pub fn set_earthrorationratecompensated(&mut self, earthrorationratecompensated: bool) {
            self.flags ^= (!(earthrorationratecompensated as u16)) & (1 << 3)
        }

        /// Gets the `earthgravitycompensated` flag.
        #[allow(clippy::identity_op)]
        pub fn earthgravitycompensated(&self) -> bool {
            ((self.flags >> 2) & 1) == 1
        }

        /// Sets the `earthgravitycompensated` flag.
        pub fn set_earthgravitycompensated(&mut self, earthgravitycompensated: bool) {
            self.flags ^= (!(earthgravitycompensated as u16)) & (1 << 2)
        }

        /// Gets the [TimeStatus][self::TimeStatus] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeStatus` were added.
        pub fn time_status(&self) -> Result<TimeStatus, u8> {
            get_bit_range!(self.flags, u16, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TimeStatus][TimeStatus] of the `flags` bitfield.
        pub fn set_time_status(&mut self, time_status: TimeStatus) {
            set_bit_range!(&mut self.flags, time_status, u16, u8, 1, 0);
        }
    }

    impl ConcreteMessage for MsgImuComp {
        const MESSAGE_TYPE: u16 = 2309;
        const MESSAGE_NAME: &'static str = "MSG_IMU_COMP";
    }

    impl SbpMessage for MsgImuComp {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }
    }

    impl FriendlyName for MsgImuComp {
        fn friendly_name() -> &'static str {
            "IMU COMP"
        }
    }

    impl TryFrom<Sbp> for MsgImuComp {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgImuComp(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgImuComp {
        const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.time)
                + WireFormat::len(&self.flags)
                + WireFormat::len(&self.acc_comp_x)
                + WireFormat::len(&self.acc_comp_y)
                + WireFormat::len(&self.acc_comp_z)
                + WireFormat::len(&self.gyr_comp_x)
                + WireFormat::len(&self.gyr_comp_y)
                + WireFormat::len(&self.gyr_comp_z)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.time, buf);
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.acc_comp_x, buf);
            WireFormat::write(&self.acc_comp_y, buf);
            WireFormat::write(&self.acc_comp_z, buf);
            WireFormat::write(&self.gyr_comp_x, buf);
            WireFormat::write(&self.gyr_comp_y, buf);
            WireFormat::write(&self.gyr_comp_z, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgImuComp {
                sender_id: None,
                time: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
                acc_comp_x: WireFormat::parse_unchecked(buf),
                acc_comp_y: WireFormat::parse_unchecked(buf),
                acc_comp_z: WireFormat::parse_unchecked(buf),
                gyr_comp_x: WireFormat::parse_unchecked(buf),
                gyr_comp_y: WireFormat::parse_unchecked(buf),
                gyr_comp_z: WireFormat::parse_unchecked(buf),
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
}

pub mod msg_imu_raw {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Raw IMU data
    ///
    /// Raw data from the Inertial Measurement Unit, containing accelerometer and
    /// gyroscope readings. The sense of the measurements are to be aligned with
    /// the indications on the device itself. Measurement units, which are
    /// specific to the device hardware and settings, are communicated via the
    /// MSG_IMU_AUX message. If using "time since startup" local time tags, the
    /// receiving end will expect either a MSG_GNSS_TIME_OFFSET or MSG_PPS_TIME to
    /// establish the relationship between IMU time and GNSS time.
    /// Regardless of the timestamping mode, the timestamp is required to roll
    /// over to zero when reaching one week (604800 seconds, or 604800000
    /// milliseconds).
    /// The time-tagging mode should not change throughout a run.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgImuRaw {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Milliseconds since reference epoch and time status.
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Milliseconds since reference epoch, fractional part
        #[cfg_attr(feature = "serde", serde(rename = "tow_f"))]
        pub tow_f: u8,
        /// Acceleration in the IMU frame X axis
        #[cfg_attr(feature = "serde", serde(rename = "acc_x"))]
        pub acc_x: i16,
        /// Acceleration in the IMU frame Y axis
        #[cfg_attr(feature = "serde", serde(rename = "acc_y"))]
        pub acc_y: i16,
        /// Acceleration in the IMU frame Z axis
        #[cfg_attr(feature = "serde", serde(rename = "acc_z"))]
        pub acc_z: i16,
        /// Angular rate around IMU frame X axis
        #[cfg_attr(feature = "serde", serde(rename = "gyr_x"))]
        pub gyr_x: i16,
        /// Angular rate around IMU frame Y axis
        #[cfg_attr(feature = "serde", serde(rename = "gyr_y"))]
        pub gyr_y: i16,
        /// Angular rate around IMU frame Z axis
        #[cfg_attr(feature = "serde", serde(rename = "gyr_z"))]
        pub gyr_z: i16,
    }

    impl MsgImuRaw {
        /// Gets the [TimeStatus][self::TimeStatus] stored in the `tow` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeStatus` were added.
        pub fn time_status(&self) -> Result<TimeStatus, u8> {
            get_bit_range!(self.tow, u32, u8, 31, 30).try_into()
        }

        /// Set the bitrange corresponding to the [TimeStatus][TimeStatus] of the `tow` bitfield.
        pub fn set_time_status(&mut self, time_status: TimeStatus) {
            set_bit_range!(&mut self.tow, time_status, u32, u8, 31, 30);
        }

        /// Gets the `time_since_reference_epoch_in_milliseconds` stored in `tow`.
        pub fn time_since_reference_epoch_in_milliseconds(&self) -> u32 {
            get_bit_range!(self.tow, u32, u32, 29, 0)
        }

        /// Sets the `time_since_reference_epoch_in_milliseconds` bitrange of `tow`.
        pub fn set_time_since_reference_epoch_in_milliseconds(
            &mut self,
            time_since_reference_epoch_in_milliseconds: u32,
        ) {
            set_bit_range!(
                &mut self.tow,
                time_since_reference_epoch_in_milliseconds,
                u32,
                u32,
                29,
                0
            );
        }
    }

    impl ConcreteMessage for MsgImuRaw {
        const MESSAGE_TYPE: u16 = 2304;
        const MESSAGE_NAME: &'static str = "MSG_IMU_RAW";
    }

    impl SbpMessage for MsgImuRaw {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }

        #[cfg(feature = "swiftnav")]
        fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
            const IMU_RAW_TIME_STATUS_MASK: u32 = (1 << 30) | (1 << 31);
            if self.tow & IMU_RAW_TIME_STATUS_MASK != 0 {
                return None;
            }
            let tow_s = (self.tow as f64) / 1000.0;
            let gps_time = match time::GpsTime::new(0, tow_s) {
                Ok(gps_time) => gps_time.tow(),
                Err(e) => return Some(Err(e.into())),
            };
            Some(Ok(time::MessageTime::Rover(gps_time.into())))
        }
    }

    impl FriendlyName for MsgImuRaw {
        fn friendly_name() -> &'static str {
            "IMU RAW"
        }
    }

    impl TryFrom<Sbp> for MsgImuRaw {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgImuRaw(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgImuRaw {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.tow_f)
                + WireFormat::len(&self.acc_x)
                + WireFormat::len(&self.acc_y)
                + WireFormat::len(&self.acc_z)
                + WireFormat::len(&self.gyr_x)
                + WireFormat::len(&self.gyr_y)
                + WireFormat::len(&self.gyr_z)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.tow_f, buf);
            WireFormat::write(&self.acc_x, buf);
            WireFormat::write(&self.acc_y, buf);
            WireFormat::write(&self.acc_z, buf);
            WireFormat::write(&self.gyr_x, buf);
            WireFormat::write(&self.gyr_y, buf);
            WireFormat::write(&self.gyr_z, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgImuRaw {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                tow_f: WireFormat::parse_unchecked(buf),
                acc_x: WireFormat::parse_unchecked(buf),
                acc_y: WireFormat::parse_unchecked(buf),
                acc_z: WireFormat::parse_unchecked(buf),
                gyr_x: WireFormat::parse_unchecked(buf),
                gyr_y: WireFormat::parse_unchecked(buf),
                gyr_z: WireFormat::parse_unchecked(buf),
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
}
