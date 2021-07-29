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
// Automatically generated from yaml/swiftnav/sbp/settings.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for reading, writing, and discovering device settings. Settings
//! with a "string" field have multiple values in this field delimited with a
//! null character (the c style null terminator).  For instance, when querying
//! the 'firmware_version' setting in the 'system_info' section, the following
//! array of characters needs to be sent for the string field in
//! MSG_SETTINGS_READ: "system_info\0firmware_version\0", where the delimiting
//! null characters are specified with the escape sequence '\0' and all
//! quotation marks should be omitted.
//!
//! In the message descriptions below, the generic strings SECTION_SETTING and
//! SETTING are used to refer to the two strings that comprise the identifier
//! of an individual setting.In firmware_version example above,
//! SECTION_SETTING is the 'system_info', and the SETTING portion is
//! 'firmware_version'.
//! See the "Software Settings Manual" on support.swiftnav.com for detailed
//! documentation about all settings and sections available for each Swift
//! firmware version. Settings manuals are available for each firmware version
//! at the following link: [Piksi Multi
//! Specifications](https://support.swiftnav.com/support/solutions/articles/44001850753-piksi-multi-specification).
//! The latest settings document is also available at the following link:
//! [Latest settings
//! document](http://swiftnav.com/latest/piksi-multi-settings) . See lastly
//! [settings.py](https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py)
//! , the open source python command line utility for reading, writing, and
//! saving settings in the piksi_tools repository on github as a helpful
//! reference and example.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Finished reading settings (host <= device)
///
/// The settings message for indicating end of the settings values.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsReadByIndexDone {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl MsgSettingsReadByIndexDone {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsReadByIndexDone, crate::Error> {
        Ok( MsgSettingsReadByIndexDone{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgSettingsReadByIndexDone {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_READ_BY_INDEX_DONE"
    }

    fn get_message_type(&self) -> u16 {
        166
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsReadByIndexDone {
    const MESSAGE_TYPE: u16 = 166;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_BY_INDEX_DONE";
}
impl TryFrom<super::SBP> for MsgSettingsReadByIndexDone {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsReadByIndexDone(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsReadByIndexDone {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Read setting by direct index (host => device)
///
/// The settings message for iterating through the settings values. A device
/// will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsReadByIndexReq {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// An index into the device settings, with values ranging from 0 to
    /// length(settings).
    pub index: u16,
}

impl MsgSettingsReadByIndexReq {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsReadByIndexReq, crate::Error> {
        Ok( MsgSettingsReadByIndexReq{
            sender_id: None,
            index: _buf.read_u16::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsReadByIndexReq {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_READ_BY_INDEX_REQ"
    }

    fn get_message_type(&self) -> u16 {
        162
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsReadByIndexReq {
    const MESSAGE_TYPE: u16 = 162;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_BY_INDEX_REQ";
}
impl TryFrom<super::SBP> for MsgSettingsReadByIndexReq {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsReadByIndexReq(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsReadByIndexReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size
    }
}

/// Read setting by direct index (host <= device)
///
/// The settings message that reports the value of a setting at an index.
///
/// In the string field, it reports NULL-terminated and delimited string with
/// contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where the '\0'
/// escape sequence denotes the NULL character and where quotation marks are
/// omitted. The FORMAT_TYPE field is optional and denotes possible string
/// values of the setting as a hint to the user. If included, the format type
/// portion of the string has the format "enum:value1,value2,value3". An
/// example string that could be sent from the device is
/// "simulator\0enabled\0True\0enum:True,False\0".
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsReadByIndexResp {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// An index into the device settings, with values ranging from 0 to
    /// length(settings)
    pub index: u16,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
    pub setting: SbpString,
}

impl MsgSettingsReadByIndexResp {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsReadByIndexResp, crate::Error> {
        Ok( MsgSettingsReadByIndexResp{
            sender_id: None,
            index: _buf.read_u16::<LittleEndian>()?,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsReadByIndexResp {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_READ_BY_INDEX_RESP"
    }

    fn get_message_type(&self) -> u16 {
        167
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsReadByIndexResp {
    const MESSAGE_TYPE: u16 = 167;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_BY_INDEX_RESP";
}
impl TryFrom<super::SBP> for MsgSettingsReadByIndexResp {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsReadByIndexResp(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsReadByIndexResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.setting.sbp_size();
        size
    }
}

/// Read device configuration settings (host => device)
///
/// The setting message that reads the device configuration. The string field
/// is a NULL-terminated and NULL-delimited string with contents
/// "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
/// NULL character and where quotation marks are omitted. An example string
/// that could be sent to a device is "solution\0soln_freq\0". A device will
/// only respond to this message when it is received from sender ID 0x42. A
/// device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
/// 0x00A5).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsReadReq {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and NULL-delimited string with contents
    /// "SECTION_SETTING\0SETTING\0"
    pub setting: SbpString,
}

impl MsgSettingsReadReq {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsReadReq, crate::Error> {
        Ok( MsgSettingsReadReq{
            sender_id: None,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsReadReq {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_READ_REQ"
    }

    fn get_message_type(&self) -> u16 {
        164
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsReadReq {
    const MESSAGE_TYPE: u16 = 164;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_REQ";
}
impl TryFrom<super::SBP> for MsgSettingsReadReq {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsReadReq(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsReadReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.setting.sbp_size();
        size
    }
}

/// Read device configuration settings (host <= device)
///
/// The setting message which which the device responds after a
/// MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
/// terminated and NULL-delimited string with contents
/// "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
/// the NULL character and where quotation marks are omitted. An example
/// string that could be sent from device is "solution\0soln_freq\010\0".
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsReadResp {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and NULL-delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0"
    pub setting: SbpString,
}

impl MsgSettingsReadResp {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsReadResp, crate::Error> {
        Ok( MsgSettingsReadResp{
            sender_id: None,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsReadResp {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_READ_RESP"
    }

    fn get_message_type(&self) -> u16 {
        165
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsReadResp {
    const MESSAGE_TYPE: u16 = 165;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_RESP";
}
impl TryFrom<super::SBP> for MsgSettingsReadResp {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsReadResp(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsReadResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.setting.sbp_size();
        size
    }
}

/// Register setting and default value (device => host)
///
/// This message registers the presence and default value of a setting with a
/// settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this
/// setting to set the initial value.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsRegister {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE".
    pub setting: SbpString,
}

impl MsgSettingsRegister {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsRegister, crate::Error> {
        Ok( MsgSettingsRegister{
            sender_id: None,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsRegister {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_REGISTER"
    }

    fn get_message_type(&self) -> u16 {
        174
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsRegister {
    const MESSAGE_TYPE: u16 = 174;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_REGISTER";
}
impl TryFrom<super::SBP> for MsgSettingsRegister {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsRegister(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsRegister {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.setting.sbp_size();
        size
    }
}

/// Register setting and default value (device <= host)
///
/// This message responds to setting registration with the effective value.
/// The effective value shall differ from the given default value if setting
/// was already registered or is available in the permanent setting storage
/// and had a different value.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsRegisterResp {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Register status
    pub status: u8,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
    /// according to the status field.
    pub setting: SbpString,
}

impl MsgSettingsRegisterResp {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsRegisterResp, crate::Error> {
        Ok( MsgSettingsRegisterResp{
            sender_id: None,
            status: _buf.read_u8()?,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsRegisterResp {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_REGISTER_RESP"
    }

    fn get_message_type(&self) -> u16 {
        431
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsRegisterResp {
    const MESSAGE_TYPE: u16 = 431;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_REGISTER_RESP";
}
impl TryFrom<super::SBP> for MsgSettingsRegisterResp {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsRegisterResp(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsRegisterResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.status.append_to_sbp_buffer(buf);
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.status.sbp_size();
        size += self.setting.sbp_size();
        size
    }
}

/// Save settings to flash (host => device)
///
/// The save settings message persists the device's current settings
/// configuration to its onboard flash memory file system.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsSave {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl MsgSettingsSave {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsSave, crate::Error> {
        Ok( MsgSettingsSave{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgSettingsSave {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_SAVE"
    }

    fn get_message_type(&self) -> u16 {
        161
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsSave {
    const MESSAGE_TYPE: u16 = 161;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_SAVE";
}
impl TryFrom<super::SBP> for MsgSettingsSave {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsSave(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsSave {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Write device configuration settings (host => device)
///
/// The setting message writes the device configuration for a particular
/// setting via A NULL-terminated and NULL-delimited string with contents
/// "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
/// the NULL character and where quotation marks are omitted. A device will
/// only process to this message when it is received from sender ID 0x42. An
/// example string that could be sent to a device is
/// "solution\0soln_freq\010\0".
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsWrite {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and NULL-delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0"
    pub setting: SbpString,
}

impl MsgSettingsWrite {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsWrite, crate::Error> {
        Ok( MsgSettingsWrite{
            sender_id: None,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsWrite {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_WRITE"
    }

    fn get_message_type(&self) -> u16 {
        160
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsWrite {
    const MESSAGE_TYPE: u16 = 160;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_WRITE";
}
impl TryFrom<super::SBP> for MsgSettingsWrite {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsWrite(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsWrite {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.setting.sbp_size();
        size
    }
}

/// Acknowledgement with status of MSG_SETTINGS_WRITE
///
/// Return the status of a write request with the new value of the setting.
/// If the requested value is rejected, the current value will be returned.
/// The string field is a NULL-terminated and NULL-delimited string with
/// contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
/// sequence denotes the NULL character and where quotation marks are omitted.
/// An example string that could be sent from device is
/// "solution\0soln_freq\010\0".
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSettingsWriteResp {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Write status
    pub status: u8,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0"
    pub setting: SbpString,
}

impl MsgSettingsWriteResp {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSettingsWriteResp, crate::Error> {
        Ok( MsgSettingsWriteResp{
            sender_id: None,
            status: _buf.read_u8()?,
            setting: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSettingsWriteResp {
    fn get_message_name(&self) -> &'static str {
        "MSG_SETTINGS_WRITE_RESP"
    }

    fn get_message_type(&self) -> u16 {
        175
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSettingsWriteResp {
    const MESSAGE_TYPE: u16 = 175;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_WRITE_RESP";
}
impl TryFrom<super::SBP> for MsgSettingsWriteResp {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSettingsWriteResp(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSettingsWriteResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.status.append_to_sbp_buffer(buf);
        self.setting.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.status.sbp_size();
        size += self.setting.sbp_size();
        size
    }
}
