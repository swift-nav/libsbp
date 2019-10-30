//
// Copyright (C) 2015-2018 Swift Navigation Inc.
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

trait AlmostEq {
    fn almost_eq(self, rhs: Self) -> bool;
}

impl AlmostEq for f32 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f32 = 5.0;
        ((self - rhs).abs() <= (std::f32::EPSILON * (self + rhs).abs() * ULP)) || ((self - rhs).abs() < std::f32::MIN)
    }
}

impl AlmostEq for f64 {
    fn almost_eq(self, rhs: Self) -> bool {
        const ULP: f64 = 5.0;
        ((self - rhs).abs() <= (std::f64::EPSILON * (self + rhs).abs() * ULP)) || ((self - rhs).abs() < std::f64::MIN)
    }
}

((*- macro compare_value(prefix, value) *))
((*- if value is stringType *))
assert_eq!(msg.(((prefix))), (((value|str_escape))), "incorrect value for msg.(((prefix))), expected string '{}', is '{}'", (((value|str_escape))), msg.(((prefix))));
((*- elif value is arrayType *))
((*- for ff in value *))((( compare_value( (((prefix))) + '[' + (((loop.index0|toStr))) + ']', (((ff))) ) )))((*- endfor *))
((*- elif value is dictType *))
((*- for k in (((value|sorted))) *))((( compare_value( (((prefix))) + '.' + (((k))), (((value[k]))) ) )))((*- endfor *))
((*- elif value is floatType *))((=
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
        use sbp::messages::(((t.msg.module|modName)))::(((t.msg.name)));
        let payload : Vec<u8> = vec![ ((*- for p in t.packet_as_byte_array *))(((p))),((*- endfor *)) ];

        assert_eq!( (((t.msg.name)))::MSG_ID, (((t.msg_type))), "Incorrect message type, expected (((t.msg_type))), is {}", (((t.msg.name)))::MSG_ID);

        // Test the round trip payload parsing
        let mut parser = sbp::parser::Parser::new();
        let msg_result = parser.parse(&mut &payload[..]);
        assert!(msg_result.is_ok());
        let sbp_msg = msg_result.unwrap();
        match sbp_msg {
            sbp::messages::SBP::(((t.msg.name)))(msg) => {
                let sender_id = msg.get_sender_id().unwrap();
                assert_eq!(sender_id, (((t.sbp.sender))), "incorrect sender id, expected (((t.sbp.sender))), is {}", sender_id);
                ((*- for f in t.fieldskeys *))(((compare_value( (((f))), (((t.fields[f]))) ))))((*- endfor *))
            },
            _ => assert!(false, "Invalid message type! Expected a (((t.msg.name)))"),
        };
    }
    ((*- endfor *))
}
