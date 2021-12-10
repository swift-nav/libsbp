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

