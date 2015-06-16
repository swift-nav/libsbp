In order to support backwards and forwards compatibility, SBP messages
are versioned and follow a small number of conventions, enabling
devices to indicate understood message formats, capabilities and
features. SBP uses a major, minor numbering scheme to indicate
versions, where major and minor are represented by 8-bit values. The
minor number is incremented by each message addition, deprecation. The
major number is incremented when the format of a message is
changed.

Message ID's are guaranteed to be unique for all minor versions in a
major version. Message ID's are not guaranteed to be unique between
major versions. Changes to a message in a major version are manifest
by incrementing the minor version, adding a new message with the
changes, and deprecating the old message.

Stable messages are guaranteed to be available for all minor versions
in a major version. The addition or deprecation of stable messages
results in the incrementing of the major version.

