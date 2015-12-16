In order to support backwards and forwards compatibility, SBP messages
are versioned and follow a small number of conventions, enabling
devices to indicate understood message formats, capabilities and
features.

SBP uses a major, minor numbering scheme to indicate versions, where
major and minor are represented by 8-bit values:

- **Major version**. The major number is incremented when the format
  of a stable message is changed, or the addition or deprecation of
  stable messages. Message ID's are not guaranteed to be unique
  between major versions. Stable messages are guaranteed to be
  available for all minor versions in a major version.
- **Minor version**. The minor number is incremented by each
  non-stable message addition and deprecation. Changes to a message in
  a major version are manifest by incrementing the minor version,
  adding a new message with the changes, and deprecating the old
  message.

By convention, we refer to messages as **stable** and
**draft**. Stable messages are intended for broad use, like
`MsgBaselineECEF`, while draft ones are intended for internal
development. Stable messages are guaranteed to be available for all
minor versions in a major version. The addition or deprecation of
stable messages results in the incrementing of the major version.
