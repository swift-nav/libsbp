//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from (((s.src_filename))) by generate.py. Do not modify by hand!

use crate::*;

((*- macro compare_value(prefix, value) *))
((*- if value is string_type *))
assert_eq!(msg.(((prefix|snake_case))).to_string(), (((value|str_escape))), "incorrect value for msg.(((prefix|snake_case))), expected string '{}', is '{}'", (((value|str_escape))), msg.(((prefix|snake_case))));
((*- elif value is array_type *))
((*- for ff in value *))((( compare_value( (((prefix|snake_case))) + '[' + (((loop.index0|to_str))) + ']', (((ff))) ) )))((*- endfor *))
((*- elif value is dict_type *))
((*- for k in (((value|sorted))) *))((( compare_value( (((prefix))) + '.' + (((k))), (((value[k]))) ) )))((*- endfor *))
((*- elif value is float_type *))((=
    Note: the ("%.17e"|format(value)) filter is intended to preserve float
    literal precision accross all value ranges. =))
assert!(msg.(((prefix|snake_case))).almost_eq( ((("%.17e"|format(value)))) ), "incorrect value for (((prefix|snake_case))), expected ((("%.17e"|format(value)))), is {:e}", msg.(((prefix|snake_case))));
((*- else *))
assert_eq!(msg.(((prefix|snake_case))), (((value))), "incorrect value for (((prefix|snake_case))), expected (((value))), is {}", msg.(((prefix|snake_case))));
((*- endif *))
((*- endmacro *))

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_(((s.suite_name|snake_case)))()
{
    ((*- for t in s.tests *))
    {
        let mut payload = Cursor::new(vec![ ((*- for p in t.packet_as_byte_array *))(((p))),((*- endfor *)) ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::(((t.msg.name|lower_acronyms)))(msg) => {
                assert_eq!( msg.message_type(), (((t.msg_type))), "Incorrect message type, expected (((t.msg_type))), is {}", msg.message_type());
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(sender_id, (((t.sbp.sender))), "incorrect sender id, expected (((t.sbp.sender))), is {}", sender_id);
                ((*- for f in t.fieldskeys *))(((compare_value( (((f))), (((t.fields[f]))) ))))((*- endfor *))
            },
            _ => panic!("Invalid message type! Expected a (((t.msg.name)))"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    ((*- endfor *))
}

/// Tests [`sbp::json::iter_messages`] for JSON payload -> SBP message
/// and [`sbp::json::iter_messages_from_fields`] for JSON fields -> SBP message.
///
/// Asserts:
/// -   SBP message constructed via payload is identical to from fields
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_json2sbp_(((s.suite_name|snake_case)))()
{
    ((*- for t in s.tests *))
    {
        let json_input = r#"((( t.raw_json )))"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter.next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter.next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::(((t.msg.name|lower_acronyms)))(msg) => {
                assert_eq!( msg.message_type(), (((t.msg_type))), "Incorrect message type, expected (((t.msg_type))), is {}", msg.message_type());
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(sender_id, (((t.sbp.sender))), "incorrect sender id, expected (((t.sbp.sender))), is {}", sender_id);
                ((*- for f in t.fieldskeys *))(((compare_value( (((f))), (((t.fields[f]))) ))))((*- endfor *))
            },
            _ => panic!("Invalid message type! Expected a (((t.msg.name)))"),
        };
    }
    ((*- endfor *))
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_(((s.suite_name|snake_case)))`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_(((s.suite_name|snake_case)))()
{
    ((*- for t in s.tests *))
    {
        let mut payload = Cursor::new(vec![ ((*- for p in t.packet_as_byte_array *))(((p))),((*- endfor *)) ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {}).send(&sbp_msg).unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::(((t.msg.name|lower_acronyms)))(serde_json::from_str(std::str::from_utf8(json_buffer.as_slice()).unwrap().to_string().as_str()).unwrap());
        match &sbp_msg {
            sbp::messages::Sbp::(((t.msg.name|lower_acronyms)))(msg) => {
                assert_eq!( msg.message_type(), (((t.msg_type))), "Incorrect message type, expected (((t.msg_type))), is {}", msg.message_type());
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(sender_id, (((t.sbp.sender))), "incorrect sender id, expected (((t.sbp.sender))), is {}", sender_id);
                ((*- for f in t.fieldskeys *))(((compare_value( (((f))), (((t.fields[f]))) ))))((*- endfor *))
            },
            _ => panic!("Invalid message type! Expected a (((t.msg.name)))"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
    ((*- endfor *))
}

