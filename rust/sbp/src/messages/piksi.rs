// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/swiftnav/sbp/piksi.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! System health, configuration, and diagnostic messages specific to
//! the Piksi L1 receiver, including a variety of legacy messages that
//! may no longer be used.
//!

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

use super::gnss::*;
#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Receiver-to-base station latency
///
/// Statistics on the latency of observations received from the base
/// station. As observation packets are received their GPS time is
/// compared to the current GPS time calculated locally by the
/// receiver to give a precise measurement of the end-to-end
/// communication latency in the system.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct Latency {
    /// Average latency
    pub avg: i32,
    /// Minimum latency
    pub lmin: i32,
    /// Maximum latency
    pub lmax: i32,
    /// Smoothed estimate of the current latency
    pub current: i32,
}

impl SbpParse<Latency> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<Latency> {
        Ok( Latency{
            avg: self.parse()?,
            lmin: self.parse()?,
            lmax: self.parse()?,
            current: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for Latency {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.avg.append_to_sbp_buffer(buf);
        self.lmin.append_to_sbp_buffer(buf);
        self.lmax.append_to_sbp_buffer(buf);
        self.current.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.avg.sbp_size();
        size += self.lmin.sbp_size();
        size += self.lmax.sbp_size();
        size += self.current.sbp_size();
        size
    }
}

/// Legacy message to load satellite almanac (host => Piksi)
///
/// This is a legacy message for sending and loading a satellite
/// alamanac onto the Piksi's flash memory from the host.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAlmanac {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgAlmanac> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAlmanac> {
        Ok( MsgAlmanac{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgAlmanac {
    fn get_message_type(&self) -> u16 {
        105
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgAlmanac {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Cell modem information update message
///
/// If a cell modem is present on a piksi device, this message
/// will be send periodically to update the host on the status
/// of the modem and its various parameters.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCellModemStatus {
    pub sender_id: Option<u16>,
    /// Received cell signal strength in dBm, zero translates to unknown
    pub signal_strength: i8,
    /// BER as reported by the modem, zero translates to unknown
    pub signal_error_rate: f32,
    /// Unspecified data TBD for this schema
    pub reserved: Vec<u8>,
}

impl SbpParse<MsgCellModemStatus> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgCellModemStatus> {
        Ok( MsgCellModemStatus{
            sender_id: None,
            signal_strength: self.parse()?,
            signal_error_rate: self.parse()?,
            reserved: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgCellModemStatus {
    fn get_message_type(&self) -> u16 {
        190
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgCellModemStatus {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.signal_strength.append_to_sbp_buffer(buf);
        self.signal_error_rate.append_to_sbp_buffer(buf);
        self.reserved.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.signal_strength.sbp_size();
        size += self.signal_error_rate.sbp_size();
        size += self.reserved.sbp_size();
        size
    }
}

/// Command output
///
/// Returns the standard output and standard error of the
/// command requested by MSG_COMMAND_REQ.
/// The sequence number can be used to filter for filtering
/// the correct command.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCommandOutput {
    pub sender_id: Option<u16>,
    /// Sequence number
    pub sequence: u32,
    /// Line of standard output or standard error
    pub line: UnboundedSbpString,
}

impl SbpParse<MsgCommandOutput> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgCommandOutput> {
        Ok( MsgCommandOutput{
            sender_id: None,
            sequence: self.parse()?,
            line: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgCommandOutput {
    fn get_message_type(&self) -> u16 {
        188
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgCommandOutput {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sequence.append_to_sbp_buffer(buf);
        self.line.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sequence.sbp_size();
        size += self.line.sbp_size();
        size
    }
}

/// Execute a command (host => device)
///
/// Request the recipient to execute an command.
/// Output will be sent in MSG_LOG messages, and the exit
/// code will be returned with MSG_COMMAND_RESP.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCommandReq {
    pub sender_id: Option<u16>,
    /// Sequence number
    pub sequence: u32,
    /// Command line to execute
    pub command: UnboundedSbpString,
}

impl SbpParse<MsgCommandReq> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgCommandReq> {
        Ok( MsgCommandReq{
            sender_id: None,
            sequence: self.parse()?,
            command: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgCommandReq {
    fn get_message_type(&self) -> u16 {
        184
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgCommandReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sequence.append_to_sbp_buffer(buf);
        self.command.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sequence.sbp_size();
        size += self.command.sbp_size();
        size
    }
}

/// Exit code from executed command (device => host)
///
/// The response to MSG_COMMAND_REQ with the return code of
/// the command.  A return code of zero indicates success.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCommandResp {
    pub sender_id: Option<u16>,
    /// Sequence number
    pub sequence: u32,
    /// Exit code
    pub code: i32,
}

impl SbpParse<MsgCommandResp> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgCommandResp> {
        Ok( MsgCommandResp{
            sender_id: None,
            sequence: self.parse()?,
            code: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgCommandResp {
    fn get_message_type(&self) -> u16 {
        185
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgCommandResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sequence.append_to_sbp_buffer(buf);
        self.code.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sequence.sbp_size();
        size += self.code.sbp_size();
        size
    }
}

/// Legacy message for CW interference channel (Piksi => host)
///
/// This is an unused legacy message for result reporting from the
/// CW interference channel on the SwiftNAP. This message will be
/// removed in a future release.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCwResults {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgCwResults> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgCwResults> {
        Ok( MsgCwResults{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgCwResults {
    fn get_message_type(&self) -> u16 {
        192
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgCwResults {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Legacy message for CW interference channel (host => Piksi)
///
/// This is an unused legacy message from the host for starting
/// the CW interference channel on the SwiftNAP. This message will
/// be removed in a future release.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCwStart {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgCwStart> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgCwStart> {
        Ok( MsgCwStart{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgCwStart {
    fn get_message_type(&self) -> u16 {
        193
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgCwStart {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Device temperature and voltage levels
///
/// This message contains temperature and voltage level measurements from the
/// processor's monitoring system and the RF frontend die temperature if
/// available.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDeviceMonitor {
    pub sender_id: Option<u16>,
    /// Device V_in
    pub dev_vin: i16,
    /// Processor V_int
    pub cpu_vint: i16,
    /// Processor V_aux
    pub cpu_vaux: i16,
    /// Processor temperature
    pub cpu_temperature: i16,
    /// Frontend temperature (if available)
    pub fe_temperature: i16,
}

impl SbpParse<MsgDeviceMonitor> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgDeviceMonitor> {
        Ok( MsgDeviceMonitor{
            sender_id: None,
            dev_vin: self.parse()?,
            cpu_vint: self.parse()?,
            cpu_vaux: self.parse()?,
            cpu_temperature: self.parse()?,
            fe_temperature: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgDeviceMonitor {
    fn get_message_type(&self) -> u16 {
        181
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgDeviceMonitor {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.dev_vin.append_to_sbp_buffer(buf);
        self.cpu_vint.append_to_sbp_buffer(buf);
        self.cpu_vaux.append_to_sbp_buffer(buf);
        self.cpu_temperature.append_to_sbp_buffer(buf);
        self.fe_temperature.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.dev_vin.sbp_size();
        size += self.cpu_vint.sbp_size();
        size += self.cpu_vaux.sbp_size();
        size += self.cpu_temperature.sbp_size();
        size += self.fe_temperature.sbp_size();
        size
    }
}

/// RF AGC status
///
/// This message describes the gain of each channel in the receiver frontend. Each
/// gain is encoded as a non-dimensional percentage relative to the maximum range  
/// possible for the gain stage of the frontend. By convention, each gain array
/// has 8 entries and the index of the array corresponding to the index of the rf channel
/// in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
/// A negative value implies an error for the particular gain stage as reported by the frontend.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFrontEndGain {
    pub sender_id: Option<u16>,
    /// RF gain for each frontend channel
    pub rf_gain: [i8; 8],
    /// Intermediate frequency gain for each frontend channel
    pub if_gain: [i8; 8],
}

impl SbpParse<MsgFrontEndGain> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgFrontEndGain> {
        Ok( MsgFrontEndGain{
            sender_id: None,
            rf_gain: self.parse()?,
            if_gain: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgFrontEndGain {
    fn get_message_type(&self) -> u16 {
        191
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgFrontEndGain {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.rf_gain.append_to_sbp_buffer(buf);
        self.if_gain.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.rf_gain.sbp_size();
        size += self.if_gain.sbp_size();
        size
    }
}

/// State of the Integer Ambiguity Resolution (IAR) process
///
/// This message reports the state of the Integer Ambiguity
/// Resolution (IAR) process, which resolves unknown integer
/// ambiguities from double-differenced carrier-phase measurements
/// from satellite observations.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgIarState {
    pub sender_id: Option<u16>,
    /// Number of integer ambiguity hypotheses remaining
    pub num_hyps: u32,
}

impl SbpParse<MsgIarState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgIarState> {
        Ok( MsgIarState{
            sender_id: None,
            num_hyps: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgIarState {
    fn get_message_type(&self) -> u16 {
        25
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgIarState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.num_hyps.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.num_hyps.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgInitBaseDep {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgInitBaseDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgInitBaseDep> {
        Ok( MsgInitBaseDep{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgInitBaseDep {
    fn get_message_type(&self) -> u16 {
        35
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgInitBaseDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Mask a satellite from use in Piksi subsystems
///
/// This message allows setting a mask to prevent a particular satellite
/// from being used in various Piksi subsystems.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgMaskSatellite {
    pub sender_id: Option<u16>,
    /// Mask of systems that should ignore this satellite.
    pub mask: u8,
    /// GNSS signal for which the mask is applied
    pub sid: GnssSignal,
}

impl SbpParse<MsgMaskSatellite> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgMaskSatellite> {
        Ok( MsgMaskSatellite{
            sender_id: None,
            mask: self.parse()?,
            sid: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgMaskSatellite {
    fn get_message_type(&self) -> u16 {
        43
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgMaskSatellite {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.mask.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.mask.sbp_size();
        size += self.sid.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgMaskSatelliteDep {
    pub sender_id: Option<u16>,
    /// Mask of systems that should ignore this satellite.
    pub mask: u8,
    /// GNSS signal for which the mask is applied
    pub sid: GnssSignalDep,
}

impl SbpParse<MsgMaskSatelliteDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgMaskSatelliteDep> {
        Ok( MsgMaskSatelliteDep{
            sender_id: None,
            mask: self.parse()?,
            sid: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgMaskSatelliteDep {
    fn get_message_type(&self) -> u16 {
        27
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgMaskSatelliteDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.mask.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.mask.sbp_size();
        size += self.sid.sbp_size();
        size
    }
}

/// Bandwidth usage reporting message
///
/// The bandwidth usage, a list of usage by interface.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgNetworkBandwidthUsage {
    pub sender_id: Option<u16>,
    /// Usage measurement array
    pub interfaces: Vec<NetworkUsage>,
}

impl SbpParse<MsgNetworkBandwidthUsage> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgNetworkBandwidthUsage> {
        Ok( MsgNetworkBandwidthUsage{
            sender_id: None,
            interfaces: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgNetworkBandwidthUsage {
    fn get_message_type(&self) -> u16 {
        189
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgNetworkBandwidthUsage {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.interfaces.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.interfaces.sbp_size();
        size
    }
}

/// Request state of Piksi network interfaces
///
/// Request state of Piksi network interfaces.
/// Output will be sent in MSG_NETWORK_STATE_RESP messages
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgNetworkStateReq {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgNetworkStateReq> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgNetworkStateReq> {
        Ok( MsgNetworkStateReq{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgNetworkStateReq {
    fn get_message_type(&self) -> u16 {
        186
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgNetworkStateReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// State of network interface
///
/// The state of a network interface on the Piksi.
/// Data is made to reflect output of ifaddrs struct returned by getifaddrs
/// in c.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgNetworkStateResp {
    pub sender_id: Option<u16>,
    /// IPv4 address (all zero when unavailable)
    pub ipv4_address: [u8; 4],
    /// IPv4 netmask CIDR notation
    pub ipv4_mask_size: u8,
    /// IPv6 address (all zero when unavailable)
    pub ipv6_address: [u8; 16],
    /// IPv6 netmask CIDR notation
    pub ipv6_mask_size: u8,
    /// Number of Rx bytes
    pub rx_bytes: u32,
    /// Number of Tx bytes
    pub tx_bytes: u32,
    /// Interface Name
    pub interface_name: BoundedSbpString<16>,
    /// Interface flags from SIOCGIFFLAGS
    pub flags: u32,
}

impl SbpParse<MsgNetworkStateResp> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgNetworkStateResp> {
        Ok( MsgNetworkStateResp{
            sender_id: None,
            ipv4_address: self.parse()?,
            ipv4_mask_size: self.parse()?,
            ipv6_address: self.parse()?,
            ipv6_mask_size: self.parse()?,
            rx_bytes: self.parse()?,
            tx_bytes: self.parse()?,
            interface_name: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgNetworkStateResp {
    fn get_message_type(&self) -> u16 {
        187
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgNetworkStateResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.ipv4_address.append_to_sbp_buffer(buf);
        self.ipv4_mask_size.append_to_sbp_buffer(buf);
        self.ipv6_address.append_to_sbp_buffer(buf);
        self.ipv6_mask_size.append_to_sbp_buffer(buf);
        self.rx_bytes.append_to_sbp_buffer(buf);
        self.tx_bytes.append_to_sbp_buffer(buf);
        self.interface_name.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.ipv4_address.sbp_size();
        size += self.ipv4_mask_size.sbp_size();
        size += self.ipv6_address.sbp_size();
        size += self.ipv6_mask_size.sbp_size();
        size += self.rx_bytes.sbp_size();
        size += self.tx_bytes.sbp_size();
        size += self.interface_name.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Reset the device (host => Piksi)
///
/// This message from the host resets the Piksi back into the
/// bootloader.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgReset {
    pub sender_id: Option<u16>,
    /// Reset flags
    pub flags: u32,
}

impl SbpParse<MsgReset> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgReset> {
        Ok( MsgReset{
            sender_id: None,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgReset {
    fn get_message_type(&self) -> u16 {
        182
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgReset {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size
    }
}

/// Reset the device (host => Piksi)
///
/// This message from the host resets the Piksi back into the
/// bootloader.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgResetDep {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgResetDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgResetDep> {
        Ok( MsgResetDep{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgResetDep {
    fn get_message_type(&self) -> u16 {
        178
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgResetDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Reset IAR filters (host => Piksi)
///
/// This message resets either the DGNSS Kalman filters or Integer
/// Ambiguity Resolution (IAR) process.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgResetFilters {
    pub sender_id: Option<u16>,
    /// Filter flags
    pub filter: u8,
}

impl SbpParse<MsgResetFilters> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgResetFilters> {
        Ok( MsgResetFilters{
            sender_id: None,
            filter: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgResetFilters {
    fn get_message_type(&self) -> u16 {
        34
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgResetFilters {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.filter.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.filter.sbp_size();
        size
    }
}

/// Send GPS time from host (host => Piksi)
///
/// This message sets up timing functionality using a coarse GPS
/// time estimate sent by the host.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSetTime {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgSetTime> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSetTime> {
        Ok( MsgSetTime{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgSetTime {
    fn get_message_type(&self) -> u16 {
        104
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgSetTime {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Spectrum analyzer
///
/// Spectrum analyzer packet.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSpecan {
    pub sender_id: Option<u16>,
    /// Channel ID
    pub channel_tag: u16,
    /// Receiver time of this observation
    pub t: GPSTime,
    /// Reference frequency of this packet
    pub freq_ref: f32,
    /// Frequency step of points in this packet
    pub freq_step: f32,
    /// Reference amplitude of this packet
    pub amplitude_ref: f32,
    /// Amplitude unit value of points in this packet
    pub amplitude_unit: f32,
    /// Amplitude values (in the above units) of points in this packet
    pub amplitude_value: Vec<u8>,
}

impl SbpParse<MsgSpecan> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSpecan> {
        Ok( MsgSpecan{
            sender_id: None,
            channel_tag: self.parse()?,
            t: self.parse()?,
            freq_ref: self.parse()?,
            freq_step: self.parse()?,
            amplitude_ref: self.parse()?,
            amplitude_unit: self.parse()?,
            amplitude_value: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSpecan {
    fn get_message_type(&self) -> u16 {
        81
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgSpecan {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.channel_tag.append_to_sbp_buffer(buf);
        self.t.append_to_sbp_buffer(buf);
        self.freq_ref.append_to_sbp_buffer(buf);
        self.freq_step.append_to_sbp_buffer(buf);
        self.amplitude_ref.append_to_sbp_buffer(buf);
        self.amplitude_unit.append_to_sbp_buffer(buf);
        self.amplitude_value.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.channel_tag.sbp_size();
        size += self.t.sbp_size();
        size += self.freq_ref.sbp_size();
        size += self.freq_step.sbp_size();
        size += self.amplitude_ref.sbp_size();
        size += self.amplitude_unit.sbp_size();
        size += self.amplitude_value.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSpecanDep {
    pub sender_id: Option<u16>,
    /// Channel ID
    pub channel_tag: u16,
    /// Receiver time of this observation
    pub t: GPSTimeDep,
    /// Reference frequency of this packet
    pub freq_ref: f32,
    /// Frequency step of points in this packet
    pub freq_step: f32,
    /// Reference amplitude of this packet
    pub amplitude_ref: f32,
    /// Amplitude unit value of points in this packet
    pub amplitude_unit: f32,
    /// Amplitude values (in the above units) of points in this packet
    pub amplitude_value: Vec<u8>,
}

impl SbpParse<MsgSpecanDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSpecanDep> {
        Ok( MsgSpecanDep{
            sender_id: None,
            channel_tag: self.parse()?,
            t: self.parse()?,
            freq_ref: self.parse()?,
            freq_step: self.parse()?,
            amplitude_ref: self.parse()?,
            amplitude_unit: self.parse()?,
            amplitude_value: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSpecanDep {
    fn get_message_type(&self) -> u16 {
        80
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgSpecanDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.channel_tag.append_to_sbp_buffer(buf);
        self.t.append_to_sbp_buffer(buf);
        self.freq_ref.append_to_sbp_buffer(buf);
        self.freq_step.append_to_sbp_buffer(buf);
        self.amplitude_ref.append_to_sbp_buffer(buf);
        self.amplitude_unit.append_to_sbp_buffer(buf);
        self.amplitude_value.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.channel_tag.sbp_size();
        size += self.t.sbp_size();
        size += self.freq_ref.sbp_size();
        size += self.freq_step.sbp_size();
        size += self.amplitude_ref.sbp_size();
        size += self.amplitude_unit.sbp_size();
        size += self.amplitude_value.sbp_size();
        size
    }
}

/// State of an RTOS thread
///
/// The thread usage message from the device reports real-time
/// operating system (RTOS) thread usage statistics for the named
/// thread. The reported percentage values must be normalized.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgThreadState {
    pub sender_id: Option<u16>,
    /// Thread name (NULL terminated)
    pub name: BoundedSbpString<20>,
    /// Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    /// to be renormalized to 100
    pub cpu: u16,
    /// Free stack space for this thread
    pub stack_free: u32,
}

impl SbpParse<MsgThreadState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgThreadState> {
        Ok( MsgThreadState{
            sender_id: None,
            name: self.parse()?,
            cpu: self.parse()?,
            stack_free: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgThreadState {
    fn get_message_type(&self) -> u16 {
        23
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgThreadState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.name.append_to_sbp_buffer(buf);
        self.cpu.append_to_sbp_buffer(buf);
        self.stack_free.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.name.sbp_size();
        size += self.cpu.sbp_size();
        size += self.stack_free.sbp_size();
        size
    }
}

/// State of the UART channels
///
/// The UART message reports data latency and throughput of the UART
/// channels providing SBP I/O. On the default Piksi configuration,
/// UARTs A and B are used for telemetry radios, but can also be
/// host access ports for embedded hosts, or other interfaces in
/// future. The reported percentage values must be normalized.
/// Observations latency and period can be used to assess the
/// health of the differential corrections link. Latency provides
/// the timeliness of received base observations while the
/// period indicates their likelihood of transmission.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUartState {
    pub sender_id: Option<u16>,
    /// State of UART A
    pub uart_a: UARTChannel,
    /// State of UART B
    pub uart_b: UARTChannel,
    /// State of UART FTDI (USB logger)
    pub uart_ftdi: UARTChannel,
    /// UART communication latency
    pub latency: Latency,
    /// Observation receipt period
    pub obs_period: Period,
}

impl SbpParse<MsgUartState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgUartState> {
        Ok( MsgUartState{
            sender_id: None,
            uart_a: self.parse()?,
            uart_b: self.parse()?,
            uart_ftdi: self.parse()?,
            latency: self.parse()?,
            obs_period: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgUartState {
    fn get_message_type(&self) -> u16 {
        29
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgUartState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.uart_a.append_to_sbp_buffer(buf);
        self.uart_b.append_to_sbp_buffer(buf);
        self.uart_ftdi.append_to_sbp_buffer(buf);
        self.latency.append_to_sbp_buffer(buf);
        self.obs_period.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.uart_a.sbp_size();
        size += self.uart_b.sbp_size();
        size += self.uart_ftdi.sbp_size();
        size += self.latency.sbp_size();
        size += self.obs_period.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUartStateDepa {
    pub sender_id: Option<u16>,
    /// State of UART A
    pub uart_a: UARTChannel,
    /// State of UART B
    pub uart_b: UARTChannel,
    /// State of UART FTDI (USB logger)
    pub uart_ftdi: UARTChannel,
    /// UART communication latency
    pub latency: Latency,
}

impl SbpParse<MsgUartStateDepa> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgUartStateDepa> {
        Ok( MsgUartStateDepa{
            sender_id: None,
            uart_a: self.parse()?,
            uart_b: self.parse()?,
            uart_ftdi: self.parse()?,
            latency: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgUartStateDepa {
    fn get_message_type(&self) -> u16 {
        24
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgUartStateDepa {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.uart_a.append_to_sbp_buffer(buf);
        self.uart_b.append_to_sbp_buffer(buf);
        self.uart_ftdi.append_to_sbp_buffer(buf);
        self.latency.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.uart_a.sbp_size();
        size += self.uart_b.sbp_size();
        size += self.uart_ftdi.sbp_size();
        size += self.latency.sbp_size();
        size
    }
}

/// Bandwidth usage measurement for a single interface.
///
/// The bandwidth usage for each interface can be reported
/// within this struct and utilize multiple fields to fully
/// specify the type of traffic that is being tracked. As
/// either the interval of collection or the collection time
/// may vary, both a timestamp and period field is provided,
/// though may not necessarily be populated with a value.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct NetworkUsage {
    /// Duration over which the measurement was collected
    pub duration: u64,
    /// Number of bytes handled in total within period
    pub total_bytes: u64,
    /// Number of bytes transmitted within period
    pub rx_bytes: u32,
    /// Number of bytes received within period
    pub tx_bytes: u32,
    /// Interface Name
    pub interface_name: BoundedSbpString<16>,
}

impl SbpParse<NetworkUsage> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<NetworkUsage> {
        Ok( NetworkUsage{
            duration: self.parse()?,
            total_bytes: self.parse()?,
            rx_bytes: self.parse()?,
            tx_bytes: self.parse()?,
            interface_name: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for NetworkUsage {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.duration.append_to_sbp_buffer(buf);
        self.total_bytes.append_to_sbp_buffer(buf);
        self.rx_bytes.append_to_sbp_buffer(buf);
        self.tx_bytes.append_to_sbp_buffer(buf);
        self.interface_name.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.duration.sbp_size();
        size += self.total_bytes.sbp_size();
        size += self.rx_bytes.sbp_size();
        size += self.tx_bytes.sbp_size();
        size += self.interface_name.sbp_size();
        size
    }
}

/// base station observation message receipt period
///
/// Statistics on the period of observations received from the base
/// station. As complete observation sets are received, their time
/// of reception is compared with the prior set''s time of reception.
/// This measurement provides a proxy for link quality as incomplete
/// or missing sets will increase the period.  Long periods
/// can cause momentary RTK solution outages.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct Period {
    /// Average period
    pub avg: i32,
    /// Minimum period
    pub pmin: i32,
    /// Maximum period
    pub pmax: i32,
    /// Smoothed estimate of the current period
    pub current: i32,
}

impl SbpParse<Period> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<Period> {
        Ok( Period{
            avg: self.parse()?,
            pmin: self.parse()?,
            pmax: self.parse()?,
            current: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for Period {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.avg.append_to_sbp_buffer(buf);
        self.pmin.append_to_sbp_buffer(buf);
        self.pmax.append_to_sbp_buffer(buf);
        self.current.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.avg.sbp_size();
        size += self.pmin.sbp_size();
        size += self.pmax.sbp_size();
        size += self.current.sbp_size();
        size
    }
}

/// State of the UART channel
///
/// Throughput, utilization, and error counts on the RX/TX buffers
/// of this UART channel. The reported percentage values must
/// be normalized.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct UARTChannel {
    /// UART transmit throughput
    pub tx_throughput: f32,
    /// UART receive throughput
    pub rx_throughput: f32,
    /// UART CRC error count
    pub crc_error_count: u16,
    /// UART IO error count
    pub io_error_count: u16,
    /// UART transmit buffer percentage utilization (ranges from 0 to 255)
    pub tx_buffer_level: u8,
    /// UART receive buffer percentage utilization (ranges from 0 to 255)
    pub rx_buffer_level: u8,
}

impl SbpParse<UARTChannel> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<UARTChannel> {
        Ok( UARTChannel{
            tx_throughput: self.parse()?,
            rx_throughput: self.parse()?,
            crc_error_count: self.parse()?,
            io_error_count: self.parse()?,
            tx_buffer_level: self.parse()?,
            rx_buffer_level: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for UARTChannel {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tx_throughput.append_to_sbp_buffer(buf);
        self.rx_throughput.append_to_sbp_buffer(buf);
        self.crc_error_count.append_to_sbp_buffer(buf);
        self.io_error_count.append_to_sbp_buffer(buf);
        self.tx_buffer_level.append_to_sbp_buffer(buf);
        self.rx_buffer_level.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tx_throughput.sbp_size();
        size += self.rx_throughput.sbp_size();
        size += self.crc_error_count.sbp_size();
        size += self.io_error_count.sbp_size();
        size += self.tx_buffer_level.sbp_size();
        size += self.rx_buffer_level.sbp_size();
        size
    }
}
