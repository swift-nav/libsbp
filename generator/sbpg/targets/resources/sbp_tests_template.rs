//
// Copyright (C) 2019 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from (((s.src_filename))) by generate.py. Do not modify by hand!

extern crate sbp;
use sbp::messages::SBPMessage;

mod common;
#[allow(unused_imports)]
use common::AlmostEq;

((*- macro compare_value(prefix, value) *))
((*- if value is string_type *))
assert_eq!(msg.(((prefix))), (((value|str_escape))), "incorrect value for msg.(((prefix))), expected string '{}', is '{}'", (((value|str_escape))), msg.(((prefix))));
((*- elif value is array_type *))
((*- for ff in value *))((( compare_value( (((prefix))) + '[' + (((loop.index0|to_str))) + ']', (((ff))) ) )))((*- endfor *))
((*- elif value is dict_type *))
((*- for k in (((value|sorted))) *))((( compare_value( (((prefix))) + '.' + (((k))), (((value[k]))) ) )))((*- endfor *))
((*- elif value is float_type *))((=
    Note: the ("%.17e"|format(value)) filter is intended to preserve float
    literal precision accross all value ranges. =))
assert!(msg.(((prefix))).almost_eq( ((("%.17e"|format(value)))) ), "incorrect value for (((prefix))), expected ((("%.17e"|format(value)))), is {:e}", msg.(((prefix))));
((*- else *))
assert_eq!(msg.(((prefix))), (((value))), "incorrect value for (((prefix))), expected (((value))), is {}", msg.(((prefix))));
((*- endif *))
((*- endmacro *))

#[test]
fn test_(((s.suite_name)))()
{
    ((*- for t in s.tests *))
    {
        let payload : Vec<u8> = vec![ ((*- for p in t.packet_as_byte_array *))(((p))),((*- endfor *)) ];

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match &sbp_msg {
            sbp::messages::SBP::(((t.msg.name)))(msg) => {
                assert_eq!( msg.get_message_type(), (((t.msg_type))), "Incorrect message type, expected (((t.msg_type))), is {}", msg.get_message_type());
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(sender_id, (((t.sbp.sender))), "incorrect sender id, expected (((t.sbp.sender))), is {}", sender_id);
                ((*- for f in t.fieldskeys *))(((compare_value( (((f))), (((t.fields[f]))) ))))((*- endfor *))
            },
            _ => panic!("Invalid message type! Expected a (((t.msg.name)))"),
        };

        let frame = sbp::framer::to_frame(sbp_msg.as_sbp_message()).unwrap();
        assert_eq!(frame, payload);
    }
    ((*- endfor *))
}

