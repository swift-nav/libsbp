// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/swiftnav/sbp/navigation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
// Geodetic navigation messages reporting GPS time, position, velocity,
// and baseline position solutions. For position solutions, these
// messages define several different position solutions: single-point
// (SPP), RTK, and pseudo-absolute position solutions.
//
// The SPP is the standalone, absolute GPS position solution using only
// a single receiver. The RTK solution is the differential GPS
// solution, which can use either a fixed/integer or floating carrier
// phase ambiguity. The pseudo-absolute position solution uses a
// user-provided, well-surveyed base station position (if available)
// and the RTK solution in tandem.
//
// When the inertial navigation mode indicates that the IMU is used,
// all messages are reported in the vehicle body frame as defined by
// device settings.  By default, the vehicle body frame is configured to be
// coincident with the antenna phase center.  When there is no inertial
// navigation, the solution will be reported at the phase center of the antenna.
// There is no inertial navigation capability on Piksi Multi or Duro.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// GPS Time
//
// This message reports the GPS time, representing the time since
// the GPS epoch began on midnight January 6, 1980 UTC. GPS time
// counts the weeks and seconds of the week. The weeks begin at the
// Saturday/Sunday transition. GPS week 0 began at the beginning of
// the GPS time scale.
//
// Within each week number, the GPS time of the week is between
// between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
// does not accumulate leap seconds, and as of now, has a small
// offset from UTC. In a message stream, this message precedes a
// set of other navigation messages referenced to the same time
// (but lacking the ns field) and indicates a more precise time of
// these messages.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGPSTime {
    pub sender_id: Option<u16>,
    pub wn: u16,
    // ^ GPS week number
    pub tow: u32,
    // ^ GPS time of week rounded to the nearest millisecond
    pub ns_residual: i32,
    // ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    // 500000)
    pub flags: u8,
    // ^ Status flags (reserved)
}

impl MsgGPSTime {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGPSTime, ::parser::MessageError> {
        Ok(MsgGPSTime {
            sender_id: None,
            wn: _buf.read_u16::<LittleEndian>()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgGPSTime {
    const MSG_ID: u16 = 258;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// UTC Time
//
// This message reports the Universal Coordinated Time (UTC).  Note the flags
// which indicate the source of the UTC offset value and source of the time fix.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgUtcTime {
    pub sender_id: Option<u16>,
    pub flags: u8,
    // ^ Indicates source and time validity
    pub tow: u32,
    // ^ GPS time of week rounded to the nearest millisecond
    pub year: u16,
    // ^ Year
    pub month: u8,
    // ^ Month (range 1 .. 12)
    pub day: u8,
    // ^ days in the month (range 1-31)
    pub hours: u8,
    // ^ hours of day (range 0-23)
    pub minutes: u8,
    // ^ minutes of hour (range 0-59)
    pub seconds: u8,
    // ^ seconds of minute (range 0-60) rounded down
    pub ns: u32,
    // ^ nanoseconds of second (range 0-999999999)
}

impl MsgUtcTime {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUtcTime, ::parser::MessageError> {
        Ok(MsgUtcTime {
            sender_id: None,
            flags: _buf.read_u8()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            year: _buf.read_u16::<LittleEndian>()?,
            month: _buf.read_u8()?,
            day: _buf.read_u8()?,
            hours: _buf.read_u8()?,
            minutes: _buf.read_u8()?,
            seconds: _buf.read_u8()?,
            ns: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgUtcTime {
    const MSG_ID: u16 = 259;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Dilution of Precision
//
// This dilution of precision (DOP) message describes the effect of
// navigation satellite geometry on positional measurement
// precision.  The flags field indicated whether the DOP reported
// corresponds to differential or SPP solution.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgDops {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub gdop: u16,
    // ^ Geometric Dilution of Precision
    pub pdop: u16,
    // ^ Position Dilution of Precision
    pub tdop: u16,
    // ^ Time Dilution of Precision
    pub hdop: u16,
    // ^ Horizontal Dilution of Precision
    pub vdop: u16,
    // ^ Vertical Dilution of Precision
    pub flags: u8,
    // ^ Indicates the position solution with which the DOPS message corresponds
}

impl MsgDops {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDops, ::parser::MessageError> {
        Ok(MsgDops {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            gdop: _buf.read_u16::<LittleEndian>()?,
            pdop: _buf.read_u16::<LittleEndian>()?,
            tdop: _buf.read_u16::<LittleEndian>()?,
            hdop: _buf.read_u16::<LittleEndian>()?,
            vdop: _buf.read_u16::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgDops {
    const MSG_ID: u16 = 520;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Single-point position in ECEF
//
// The position solution message reports absolute Earth Centered
// Earth Fixed (ECEF) coordinates and the status (single point vs
// pseudo-absolute RTK) of the position solution. If the rover
// receiver knows the surveyed position of the base station and has
// an RTK solution, this reports a pseudo-absolute position
// solution using the base station position and the rover's RTK
// baseline vector. The full GPS time is given by the preceding
// MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPosECEF {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: f64,
    // ^ ECEF X coordinate
    pub y: f64,
    // ^ ECEF Y coordinate
    pub z: f64,
    // ^ ECEF Z coordinate
    pub accuracy: u16,
    // ^ Position estimated standard deviation
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgPosECEF {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosECEF, ::parser::MessageError> {
        Ok(MsgPosECEF {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgPosECEF {
    const MSG_ID: u16 = 521;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Single-point position in ECEF
//
// The position solution message reports absolute Earth Centered
// Earth Fixed (ECEF) coordinates and the status (single point vs
// pseudo-absolute RTK) of the position solution. The message also
// reports the upper triangular portion of the 3x3 covariance matrix.
// If the receiver knows the surveyed position of the base station and has
// an RTK solution, this reports a pseudo-absolute position
// solution using the base station position and the rover's RTK
// baseline vector. The full GPS time is given by the preceding
// MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPosECEFCov {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: f64,
    // ^ ECEF X coordinate
    pub y: f64,
    // ^ ECEF Y coordinate
    pub z: f64,
    // ^ ECEF Z coordinate
    pub cov_x_x: f32,
    // ^ Estimated variance of x
    pub cov_x_y: f32,
    // ^ Estimated covariance of x and y
    pub cov_x_z: f32,
    // ^ Estimated covariance of x and z
    pub cov_y_y: f32,
    // ^ Estimated variance of y
    pub cov_y_z: f32,
    // ^ Estimated covariance of y and z
    pub cov_z_z: f32,
    // ^ Estimated variance of z
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgPosECEFCov {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosECEFCov, ::parser::MessageError> {
        Ok(MsgPosECEFCov {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgPosECEFCov {
    const MSG_ID: u16 = 532;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Geodetic Position
//
// This position solution message reports the absolute geodetic
// coordinates and the status (single point vs pseudo-absolute RTK)
// of the position solution. If the rover receiver knows the
// surveyed position of the base station and has an RTK solution,
// this reports a pseudo-absolute position solution using the base
// station position and the rover's RTK baseline vector. The full
// GPS time is given by the preceding MSG_GPS_TIME with the
// matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPosLLH {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub lat: f64,
    // ^ Latitude
    pub lon: f64,
    // ^ Longitude
    pub height: f64,
    // ^ Height above WGS84 ellipsoid
    pub h_accuracy: u16,
    // ^ Horizontal position estimated standard deviation
    pub v_accuracy: u16,
    // ^ Vertical position estimated standard deviation
    pub n_sats: u8,
    // ^ Number of satellites used in solution.
    pub flags: u8,
    // ^ Status flags
}

impl MsgPosLLH {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLLH, ::parser::MessageError> {
        Ok(MsgPosLLH {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgPosLLH {
    const MSG_ID: u16 = 522;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Geodetic Position
//
// This position solution message reports the absolute geodetic
// coordinates and the status (single point vs pseudo-absolute RTK)
// of the position solution as well as the upper triangle of the 3x3
// covariance matrix.  The position information and Fix Mode flags should
// follow the MSG_POS_LLH message.  Since the covariance matrix is computed
// in the local-level North, East, Down frame, the covariance terms follow
// with that convention. Thus, covariances are reported against the "downward"
// measurement and care should be taken with the sign convention.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPosLLHCov {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub lat: f64,
    // ^ Latitude
    pub lon: f64,
    // ^ Longitude
    pub height: f64,
    // ^ Height above WGS84 ellipsoid
    pub cov_n_n: f32,
    // ^ Estimated variance of northing
    pub cov_n_e: f32,
    // ^ Covariance of northing and easting
    pub cov_n_d: f32,
    // ^ Covariance of northing and downward measurement
    pub cov_e_e: f32,
    // ^ Estimated variance of easting
    pub cov_e_d: f32,
    // ^ Covariance of easting and downward measurement
    pub cov_d_d: f32,
    // ^ Estimated variance of downward measurement
    pub n_sats: u8,
    // ^ Number of satellites used in solution.
    pub flags: u8,
    // ^ Status flags
}

impl MsgPosLLHCov {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLLHCov, ::parser::MessageError> {
        Ok(MsgPosLLHCov {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            cov_n_n: _buf.read_f32::<LittleEndian>()?,
            cov_n_e: _buf.read_f32::<LittleEndian>()?,
            cov_n_d: _buf.read_f32::<LittleEndian>()?,
            cov_e_e: _buf.read_f32::<LittleEndian>()?,
            cov_e_d: _buf.read_f32::<LittleEndian>()?,
            cov_d_d: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgPosLLHCov {
    const MSG_ID: u16 = 529;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Baseline Position in ECEF
//
// This message reports the baseline solution in Earth Centered
// Earth Fixed (ECEF) coordinates. This baseline is the relative
// vector distance from the base station to the rover receiver. The
// full GPS time is given by the preceding MSG_GPS_TIME with the
// matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineECEF {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: i32,
    // ^ Baseline ECEF X coordinate
    pub y: i32,
    // ^ Baseline ECEF Y coordinate
    pub z: i32,
    // ^ Baseline ECEF Z coordinate
    pub accuracy: u16,
    // ^ Position estimated standard deviation
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgBaselineECEF {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineECEF, ::parser::MessageError> {
        Ok(MsgBaselineECEF {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBaselineECEF {
    const MSG_ID: u16 = 523;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Baseline in NED
//
// This message reports the baseline solution in North East Down
// (NED) coordinates. This baseline is the relative vector distance
// from the base station to the rover receiver, and NED coordinate
// system is defined at the local WGS84 tangent plane centered at the
// base station position.  The full GPS time is given by the
// preceding MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineNED {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub n: i32,
    // ^ Baseline North coordinate
    pub e: i32,
    // ^ Baseline East coordinate
    pub d: i32,
    // ^ Baseline Down coordinate
    pub h_accuracy: u16,
    // ^ Horizontal position estimated standard deviation
    pub v_accuracy: u16,
    // ^ Vertical position estimated standard deviation
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgBaselineNED {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineNED, ::parser::MessageError> {
        Ok(MsgBaselineNED {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBaselineNED {
    const MSG_ID: u16 = 524;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in ECEF
//
// This message reports the velocity in Earth Centered Earth Fixed
// (ECEF) coordinates. The full GPS time is given by the preceding
// MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelECEF {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: i32,
    // ^ Velocity ECEF X coordinate
    pub y: i32,
    // ^ Velocity ECEF Y coordinate
    pub z: i32,
    // ^ Velocity ECEF Z coordinate
    pub accuracy: u16,
    // ^ Velocity estimated standard deviation
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgVelECEF {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelECEF, ::parser::MessageError> {
        Ok(MsgVelECEF {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelECEF {
    const MSG_ID: u16 = 525;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in ECEF
//
// This message reports the velocity in Earth Centered Earth Fixed
// (ECEF) coordinates. The full GPS time is given by the preceding
// MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelECEFCov {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: i32,
    // ^ Velocity ECEF X coordinate
    pub y: i32,
    // ^ Velocity ECEF Y coordinate
    pub z: i32,
    // ^ Velocity ECEF Z coordinate
    pub cov_x_x: f32,
    // ^ Estimated variance of x
    pub cov_x_y: f32,
    // ^ Estimated covariance of x and y
    pub cov_x_z: f32,
    // ^ Estimated covariance of x and z
    pub cov_y_y: f32,
    // ^ Estimated variance of y
    pub cov_y_z: f32,
    // ^ Estimated covariance of y and z
    pub cov_z_z: f32,
    // ^ Estimated variance of z
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgVelECEFCov {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelECEFCov, ::parser::MessageError> {
        Ok(MsgVelECEFCov {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelECEFCov {
    const MSG_ID: u16 = 533;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in NED
//
// This message reports the velocity in local North East Down (NED)
// coordinates. The NED coordinate system is defined as the local WGS84
// tangent plane centered at the current position. The full GPS time is
// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelNED {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub n: i32,
    // ^ Velocity North coordinate
    pub e: i32,
    // ^ Velocity East coordinate
    pub d: i32,
    // ^ Velocity Down coordinate
    pub h_accuracy: u16,
    // ^ Horizontal velocity estimated standard deviation
    pub v_accuracy: u16,
    // ^ Vertical velocity estimated standard deviation
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgVelNED {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNED, ::parser::MessageError> {
        Ok(MsgVelNED {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelNED {
    const MSG_ID: u16 = 526;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in NED
//
// This message reports the velocity in local North East Down (NED)
// coordinates. The NED coordinate system is defined as the local WGS84
// tangent plane centered at the current position. The full GPS time is
// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
// This message is similar to the MSG_VEL_NED, but it includes the upper triangular
// portion of the 3x3 covariance matrix.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelNEDCov {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub n: i32,
    // ^ Velocity North coordinate
    pub e: i32,
    // ^ Velocity East coordinate
    pub d: i32,
    // ^ Velocity Down coordinate
    pub cov_n_n: f32,
    // ^ Estimated variance of northward measurement
    pub cov_n_e: f32,
    // ^ Covariance of northward and eastward measurement
    pub cov_n_d: f32,
    // ^ Covariance of northward and downward measurement
    pub cov_e_e: f32,
    // ^ Estimated variance of eastward measurement
    pub cov_e_d: f32,
    // ^ Covariance of eastward and downward measurement
    pub cov_d_d: f32,
    // ^ Estimated variance of downward measurement
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgVelNEDCov {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNEDCov, ::parser::MessageError> {
        Ok(MsgVelNEDCov {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            cov_n_n: _buf.read_f32::<LittleEndian>()?,
            cov_n_e: _buf.read_f32::<LittleEndian>()?,
            cov_n_d: _buf.read_f32::<LittleEndian>()?,
            cov_e_e: _buf.read_f32::<LittleEndian>()?,
            cov_e_d: _buf.read_f32::<LittleEndian>()?,
            cov_d_d: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelNEDCov {
    const MSG_ID: u16 = 530;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in User Frame
//
// This message reports the velocity in the Vehicle Body Frame. By convention,
// the x-axis should point out the nose of the vehicle and represent the forward
// direction, while as the y-axis should point out the right hand side of the vehicle.
// Since this is a right handed system, z should point out the bottom of the vehicle.
// The orientation and origin of the Vehicle Body Frame are specified via the device settings.
// The full GPS time is given by the preceding MSG_GPS_TIME with the
// matching time-of-week (tow). This message is only produced by inertial versions of Swift
// products and is not available from Piksi Multi or Duro.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelBody {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: i32,
    // ^ Velocity in x direction
    pub y: i32,
    // ^ Velocity in y direction
    pub z: i32,
    // ^ Velocity in z direction
    pub cov_x_x: f32,
    // ^ Estimated variance of x
    pub cov_x_y: f32,
    // ^ Covariance of x and y
    pub cov_x_z: f32,
    // ^ Covariance of x and z
    pub cov_y_y: f32,
    // ^ Estimated variance of y
    pub cov_y_z: f32,
    // ^ Covariance of y and z
    pub cov_z_z: f32,
    // ^ Estimated variance of z
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgVelBody {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelBody, ::parser::MessageError> {
        Ok(MsgVelBody {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelBody {
    const MSG_ID: u16 = 531;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Age of corrections
//
// This message reports the Age of the corrections used for the current
// Differential solution
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAgeCorrections {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub age: u16,
    // ^ Age of the corrections (0xFFFF indicates invalid)
}

impl MsgAgeCorrections {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAgeCorrections, ::parser::MessageError> {
        Ok(MsgAgeCorrections {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            age: _buf.read_u16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgAgeCorrections {
    const MSG_ID: u16 = 528;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// GPS Time (v1.0)
//
// This message reports the GPS time, representing the time since
// the GPS epoch began on midnight January 6, 1980 UTC. GPS time
// counts the weeks and seconds of the week. The weeks begin at the
// Saturday/Sunday transition. GPS week 0 began at the beginning of
// the GPS time scale.
//
// Within each week number, the GPS time of the week is between
// between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
// does not accumulate leap seconds, and as of now, has a small
// offset from UTC. In a message stream, this message precedes a
// set of other navigation messages referenced to the same time
// (but lacking the ns field) and indicates a more precise time of
// these messages.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGPSTimeDepA {
    pub sender_id: Option<u16>,
    pub wn: u16,
    // ^ GPS week number
    pub tow: u32,
    // ^ GPS time of week rounded to the nearest millisecond
    pub ns_residual: i32,
    // ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    // 500000)
    pub flags: u8,
    // ^ Status flags (reserved)
}

impl MsgGPSTimeDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGPSTimeDepA, ::parser::MessageError> {
        Ok(MsgGPSTimeDepA {
            sender_id: None,
            wn: _buf.read_u16::<LittleEndian>()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgGPSTimeDepA {
    const MSG_ID: u16 = 256;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Dilution of Precision
//
// This dilution of precision (DOP) message describes the effect of
// navigation satellite geometry on positional measurement
// precision.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgDopsDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub gdop: u16,
    // ^ Geometric Dilution of Precision
    pub pdop: u16,
    // ^ Position Dilution of Precision
    pub tdop: u16,
    // ^ Time Dilution of Precision
    pub hdop: u16,
    // ^ Horizontal Dilution of Precision
    pub vdop: u16,
    // ^ Vertical Dilution of Precision
}

impl MsgDopsDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDopsDepA, ::parser::MessageError> {
        Ok(MsgDopsDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            gdop: _buf.read_u16::<LittleEndian>()?,
            pdop: _buf.read_u16::<LittleEndian>()?,
            tdop: _buf.read_u16::<LittleEndian>()?,
            hdop: _buf.read_u16::<LittleEndian>()?,
            vdop: _buf.read_u16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgDopsDepA {
    const MSG_ID: u16 = 518;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Single-point position in ECEF
//
// The position solution message reports absolute Earth Centered
// Earth Fixed (ECEF) coordinates and the status (single point vs
// pseudo-absolute RTK) of the position solution. If the rover
// receiver knows the surveyed position of the base station and has
// an RTK solution, this reports a pseudo-absolute position
// solution using the base station position and the rover's RTK
// baseline vector. The full GPS time is given by the preceding
// MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPosECEFDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: f64,
    // ^ ECEF X coordinate
    pub y: f64,
    // ^ ECEF Y coordinate
    pub z: f64,
    // ^ ECEF Z coordinate
    pub accuracy: u16,
    // ^ Position accuracy estimate (not implemented). Defaults to 0.
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgPosECEFDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosECEFDepA, ::parser::MessageError> {
        Ok(MsgPosECEFDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgPosECEFDepA {
    const MSG_ID: u16 = 512;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Geodetic Position
//
// This position solution message reports the absolute geodetic
// coordinates and the status (single point vs pseudo-absolute RTK)
// of the position solution. If the rover receiver knows the
// surveyed position of the base station and has an RTK solution,
// this reports a pseudo-absolute position solution using the base
// station position and the rover's RTK baseline vector. The full
// GPS time is given by the preceding MSG_GPS_TIME with the
// matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPosLLHDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub lat: f64,
    // ^ Latitude
    pub lon: f64,
    // ^ Longitude
    pub height: f64,
    // ^ Height
    pub h_accuracy: u16,
    // ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
    pub v_accuracy: u16,
    // ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
    pub n_sats: u8,
    // ^ Number of satellites used in solution.
    pub flags: u8,
    // ^ Status flags
}

impl MsgPosLLHDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLLHDepA, ::parser::MessageError> {
        Ok(MsgPosLLHDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgPosLLHDepA {
    const MSG_ID: u16 = 513;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Baseline Position in ECEF
//
// This message reports the baseline solution in Earth Centered
// Earth Fixed (ECEF) coordinates. This baseline is the relative
// vector distance from the base station to the rover receiver. The
// full GPS time is given by the preceding MSG_GPS_TIME with the
// matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineECEFDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: i32,
    // ^ Baseline ECEF X coordinate
    pub y: i32,
    // ^ Baseline ECEF Y coordinate
    pub z: i32,
    // ^ Baseline ECEF Z coordinate
    pub accuracy: u16,
    // ^ Position accuracy estimate
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgBaselineECEFDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineECEFDepA, ::parser::MessageError> {
        Ok(MsgBaselineECEFDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBaselineECEFDepA {
    const MSG_ID: u16 = 514;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Baseline in NED
//
// This message reports the baseline solution in North East Down
// (NED) coordinates. This baseline is the relative vector distance
// from the base station to the rover receiver, and NED coordinate
// system is defined at the local WGS84 tangent plane centered at the
// base station position.  The full GPS time is given by the
// preceding MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineNEDDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub n: i32,
    // ^ Baseline North coordinate
    pub e: i32,
    // ^ Baseline East coordinate
    pub d: i32,
    // ^ Baseline Down coordinate
    pub h_accuracy: u16,
    // ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
    pub v_accuracy: u16,
    // ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgBaselineNEDDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineNEDDepA, ::parser::MessageError> {
        Ok(MsgBaselineNEDDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBaselineNEDDepA {
    const MSG_ID: u16 = 515;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in ECEF
//
// This message reports the velocity in Earth Centered Earth Fixed
// (ECEF) coordinates. The full GPS time is given by the preceding
// MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelECEFDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub x: i32,
    // ^ Velocity ECEF X coordinate
    pub y: i32,
    // ^ Velocity ECEF Y coordinate
    pub z: i32,
    // ^ Velocity ECEF Z coordinate
    pub accuracy: u16,
    // ^ Velocity accuracy estimate (not implemented). Defaults to 0.
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags (reserved)
}

impl MsgVelECEFDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelECEFDepA, ::parser::MessageError> {
        Ok(MsgVelECEFDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelECEFDepA {
    const MSG_ID: u16 = 516;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Velocity in NED
//
// This message reports the velocity in local North East Down (NED)
// coordinates. The NED coordinate system is defined as the local WGS84
// tangent plane centered at the current position. The full GPS time is
// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgVelNEDDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub n: i32,
    // ^ Velocity North coordinate
    pub e: i32,
    // ^ Velocity East coordinate
    pub d: i32,
    // ^ Velocity Down coordinate
    pub h_accuracy: u16,
    // ^ Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
    pub v_accuracy: u16,
    // ^ Vertical velocity accuracy estimate (not implemented). Defaults to 0.
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags (reserved)
}

impl MsgVelNEDDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNEDDepA, ::parser::MessageError> {
        Ok(MsgVelNEDDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgVelNEDDepA {
    const MSG_ID: u16 = 517;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Heading relative to True North
//
// This message reports the baseline heading pointing from the base station
// to the rover relative to True North. The full GPS time is given by the
// preceding MSG_GPS_TIME with the matching time-of-week (tow).
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineHeadingDepA {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ GPS Time of Week
    pub heading: u32,
    // ^ Heading
    pub n_sats: u8,
    // ^ Number of satellites used in solution
    pub flags: u8,
    // ^ Status flags
}

impl MsgBaselineHeadingDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineHeadingDepA, ::parser::MessageError> {
        Ok(MsgBaselineHeadingDepA {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            heading: _buf.read_u32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBaselineHeadingDepA {
    const MSG_ID: u16 = 519;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
