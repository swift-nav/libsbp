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

use super::lib::*;

/// Finished reading settings (host <= device)
///
/// The settings message for indicating end of the settings values.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsReadByIndexDone {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgSettingsReadByIndexDone {
    const MESSAGE_TYPE: u16 = 166;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_BY_INDEX_DONE";
}

impl SbpMessage for MsgSettingsReadByIndexDone {
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

impl TryFrom<Sbp> for MsgSettingsReadByIndexDone {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsReadByIndexDone(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsReadByIndexDone {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgSettingsReadByIndexDone { sender_id: None }
    }
}

/// Read setting by direct index (host => device)
///
/// The settings message for iterating through the settings values. A device
/// will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsReadByIndexReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// An index into the device settings, with values ranging from 0 to
    /// length(settings).
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u16,
}

impl ConcreteMessage for MsgSettingsReadByIndexReq {
    const MESSAGE_TYPE: u16 = 162;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_BY_INDEX_REQ";
}

impl SbpMessage for MsgSettingsReadByIndexReq {
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

impl TryFrom<Sbp> for MsgSettingsReadByIndexReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsReadByIndexReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsReadByIndexReq {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsReadByIndexReq {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsReadByIndexResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// An index into the device settings, with values ranging from 0 to
    /// length(settings)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u16,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsReadByIndexResp {
    const MESSAGE_TYPE: u16 = 167;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_BY_INDEX_RESP";
}

impl SbpMessage for MsgSettingsReadByIndexResp {
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

impl TryFrom<Sbp> for MsgSettingsReadByIndexResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsReadByIndexResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsReadByIndexResp {
    const MIN_LEN: usize =
        <u16 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index) + WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsReadByIndexResp {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            setting: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsReadReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and NULL-delimited string with contents
    /// "SECTION_SETTING\0SETTING\0"
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsReadReq {
    const MESSAGE_TYPE: u16 = 164;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_REQ";
}

impl SbpMessage for MsgSettingsReadReq {
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

impl TryFrom<Sbp> for MsgSettingsReadReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsReadReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsReadReq {
    const MIN_LEN: usize = <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsReadReq {
            sender_id: None,
            setting: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Read device configuration settings (host <= device)
///
/// The setting message with which the device responds after a
/// MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
/// terminated and NULL-delimited string with contents
/// "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
/// the NULL character and where quotation marks are omitted. An example
/// string that could be sent from device is "solution\0soln_freq\010\0".
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsReadResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and NULL-delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0"
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsReadResp {
    const MESSAGE_TYPE: u16 = 165;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_READ_RESP";
}

impl SbpMessage for MsgSettingsReadResp {
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

impl TryFrom<Sbp> for MsgSettingsReadResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsReadResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsReadResp {
    const MIN_LEN: usize = <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsReadResp {
            sender_id: None,
            setting: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Register setting and default value (device => host)
///
/// This message registers the presence and default value of a setting with a
/// settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this
/// setting to set the initial value.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsRegister {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE".
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsRegister {
    const MESSAGE_TYPE: u16 = 174;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_REGISTER";
}

impl SbpMessage for MsgSettingsRegister {
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

impl TryFrom<Sbp> for MsgSettingsRegister {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsRegister(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsRegister {
    const MIN_LEN: usize = <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsRegister {
            sender_id: None,
            setting: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Register setting and default value (device <= host)
///
/// This message responds to setting registration with the effective value.
/// The effective value shall differ from the given default value if setting
/// was already registered or is available in the permanent setting storage
/// and had a different value.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsRegisterResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Register status
    #[cfg_attr(feature = "serde", serde(rename(serialize = "status")))]
    pub status: u8,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
    /// according to the status field.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsRegisterResp {
    const MESSAGE_TYPE: u16 = 431;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_REGISTER_RESP";
}

impl SbpMessage for MsgSettingsRegisterResp {
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

impl TryFrom<Sbp> for MsgSettingsRegisterResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsRegisterResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsRegisterResp {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.status) + WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.status, buf);
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsRegisterResp {
            sender_id: None,
            status: WireFormat::parse_unchecked(buf),
            setting: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Save settings to flash (host => device)
///
/// The save settings message persists the device's current settings
/// configuration to its onboard flash memory file system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsSave {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgSettingsSave {
    const MESSAGE_TYPE: u16 = 161;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_SAVE";
}

impl SbpMessage for MsgSettingsSave {
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

impl TryFrom<Sbp> for MsgSettingsSave {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsSave(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsSave {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgSettingsSave { sender_id: None }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsWrite {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// A NULL-terminated and NULL-delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0"
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsWrite {
    const MESSAGE_TYPE: u16 = 160;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_WRITE";
}

impl SbpMessage for MsgSettingsWrite {
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

impl TryFrom<Sbp> for MsgSettingsWrite {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsWrite(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsWrite {
    const MIN_LEN: usize = <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsWrite {
            sender_id: None,
            setting: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSettingsWriteResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Write status
    #[cfg_attr(feature = "serde", serde(rename(serialize = "status")))]
    pub status: u8,
    /// A NULL-terminated and delimited string with contents
    /// "SECTION_SETTING\0SETTING\0VALUE\0"
    #[cfg_attr(feature = "serde", serde(rename(serialize = "setting")))]
    pub setting: SbpString<Vec<u8>, Multipart>,
}

impl ConcreteMessage for MsgSettingsWriteResp {
    const MESSAGE_TYPE: u16 = 175;
    const MESSAGE_NAME: &'static str = "MSG_SETTINGS_WRITE_RESP";
}

impl SbpMessage for MsgSettingsWriteResp {
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

impl TryFrom<Sbp> for MsgSettingsWriteResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSettingsWriteResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSettingsWriteResp {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Multipart> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.status) + WireFormat::len(&self.setting)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.status, buf);
        WireFormat::write(&self.setting, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSettingsWriteResp {
            sender_id: None,
            status: WireFormat::parse_unchecked(buf),
            setting: WireFormat::parse_unchecked(buf),
        }
    }
}
