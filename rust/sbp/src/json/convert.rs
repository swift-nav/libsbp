use std::convert::TryFrom;

use bytes::BytesMut;

use crate::Sbp;

use super::{JsonError, JsonOutput};

/// A JSON map holding all the fields and metadata of the
/// SBP message.  This is format used by the output of the
/// `sbp2json` tool, for example:
///
/// {
///   "crc": 49084,
///   "length": 52,
///   "msg_type": 1025,
///   "msg_name": "MSG_LOG",
///   "payload": "BHNicCBuZXcgY2xpZW50IGNvbm5lY3Rpb24gOjpmZmZmOjE5Mi4xNjguMC4xMDo2MTQ1MA==",
///   "preamble": 85,
///   "sender": 4096,
///   "level": 4,
///   "text": "sbp new client connection ::ffff:192.168.0.10:61450"
/// }
pub type JsonMap = serde_json::Map<String, serde_json::Value>;

impl TryFrom<crate::Sbp> for JsonMap {
    type Error = JsonError;

    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        let mut frame = BytesMut::with_capacity(crate::BUFLEN);
        let mut payload = String::with_capacity(crate::BUFLEN);
        let output = JsonOutput {
            common: super::ser::get_common_fields(&mut payload, &mut frame, &msg)?,
            msg: &msg,
        };
        let output = serde_json::to_value(output)?;
        let output: serde_json::Map<String, serde_json::Value> = serde_json::from_value(output)?;
        Ok(output)
    }
}
