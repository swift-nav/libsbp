use std::convert::TryFrom;

use bytes::BytesMut;

use crate::Sbp;

use super::{JsonError, JsonOutput};

impl<'a> TryFrom<crate::Sbp> for serde_json::Map<String, serde_json::Value>
{
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
