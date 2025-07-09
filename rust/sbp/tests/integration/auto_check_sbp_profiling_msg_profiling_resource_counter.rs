//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml by generate.py. Do not modify by hand!

use crate::*;

/// Tests [`sbp::iter_messages`], from payload into SBP messages
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
fn test_auto_check_sbp_profiling_msg_profiling_resource_counter() {
    {
        let mut payload = Cursor::new(vec![
            85, 3, 207, 0, 16, 248, 1, 3, 70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110,
            101, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 0, 248, 38, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 230, 73, 1, 0, 0, 0, 0, 0, 111, 3, 0, 0, 64, 76, 0, 0, 83, 83, 82, 50, 79,
            83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 72, 13, 66, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 72, 197, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73,
            77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 129, 71, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 95, 102, 0, 0, 115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 5, 2, 2, 2, 243, 169, 0, 0, 0, 0, 0, 0, 187, 151, 3, 0, 242, 1,
            0, 0, 181, 153,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingResourceCounter(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf03,
                    "Incorrect message type, expected 0xcf03, is {msg_type}"
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.buckets[0].cv, 2,
                    "incorrect value for buckets[0].cv, expected 2, is {}",
                    msg.buckets[0].cv
                );
                assert_eq!(
                    msg.buckets[0].heap_bytes_alloc, 927480,
                    "incorrect value for buckets[0].heap_bytes_alloc, expected 927480, is {}",
                    msg.buckets[0].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[0].heap_bytes_free, 0,
                    "incorrect value for buckets[0].heap_bytes_free, expected 0, is {}",
                    msg.buckets[0].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[0].io, 0,
                    "incorrect value for buckets[0].io, expected 0, is {}",
                    msg.buckets[0].io
                );
                assert_eq!(
                    msg.buckets[0].io_read, 0,
                    "incorrect value for buckets[0].io_read, expected 0, is {}",
                    msg.buckets[0].io_read
                );
                assert_eq!(
                    msg.buckets[0].io_write, 0,
                    "incorrect value for buckets[0].io_write, expected 0, is {}",
                    msg.buckets[0].io_write
                );
                assert_eq!(
                    msg.buckets[0].mutex, 2,
                    "incorrect value for buckets[0].mutex, expected 2, is {}",
                    msg.buckets[0].mutex
                );
                assert_eq!(
                    msg.buckets[0].name.as_bytes(),
                    &[
                        70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0, 0, 0, 0,
                        0, 0, 0, 0
                    ],
                    "incorrect value for msg.buckets[0].name, expected string '{:?}', is '{:?}'",
                    &[
                        70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0, 0, 0, 0,
                        0, 0, 0, 0
                    ],
                    msg.buckets[0].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[0].thread, 1,
                    "incorrect value for buckets[0].thread, expected 1, is {}",
                    msg.buckets[0].thread
                );
                assert_eq!(
                    msg.buckets[1].cv, 1,
                    "incorrect value for buckets[1].cv, expected 1, is {}",
                    msg.buckets[1].cv
                );
                assert_eq!(
                    msg.buckets[1].heap_bytes_alloc, 84454,
                    "incorrect value for buckets[1].heap_bytes_alloc, expected 84454, is {}",
                    msg.buckets[1].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[1].heap_bytes_free, 0,
                    "incorrect value for buckets[1].heap_bytes_free, expected 0, is {}",
                    msg.buckets[1].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[1].io, 1,
                    "incorrect value for buckets[1].io, expected 1, is {}",
                    msg.buckets[1].io
                );
                assert_eq!(
                    msg.buckets[1].io_read, 19520,
                    "incorrect value for buckets[1].io_read, expected 19520, is {}",
                    msg.buckets[1].io_read
                );
                assert_eq!(
                    msg.buckets[1].io_write, 879,
                    "incorrect value for buckets[1].io_write, expected 879, is {}",
                    msg.buckets[1].io_write
                );
                assert_eq!(
                    msg.buckets[1].mutex, 1,
                    "incorrect value for buckets[1].mutex, expected 1, is {}",
                    msg.buckets[1].mutex
                );
                assert_eq!(
                    msg.buckets[1].name.as_bytes(),
                    &[
                        78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0,
                        0, 0
                    ],
                    "incorrect value for msg.buckets[1].name, expected string '{:?}', is '{:?}'",
                    &[
                        78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0,
                        0, 0
                    ],
                    msg.buckets[1].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[1].thread, 1,
                    "incorrect value for buckets[1].thread, expected 1, is {}",
                    msg.buckets[1].thread
                );
                assert_eq!(
                    msg.buckets[2].cv, 1,
                    "incorrect value for buckets[2].cv, expected 1, is {}",
                    msg.buckets[2].cv
                );
                assert_eq!(
                    msg.buckets[2].heap_bytes_alloc, 4328776,
                    "incorrect value for buckets[2].heap_bytes_alloc, expected 4328776, is {}",
                    msg.buckets[2].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[2].heap_bytes_free, 0,
                    "incorrect value for buckets[2].heap_bytes_free, expected 0, is {}",
                    msg.buckets[2].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[2].io, 0,
                    "incorrect value for buckets[2].io, expected 0, is {}",
                    msg.buckets[2].io
                );
                assert_eq!(
                    msg.buckets[2].io_read, 0,
                    "incorrect value for buckets[2].io_read, expected 0, is {}",
                    msg.buckets[2].io_read
                );
                assert_eq!(
                    msg.buckets[2].io_write, 0,
                    "incorrect value for buckets[2].io_write, expected 0, is {}",
                    msg.buckets[2].io_write
                );
                assert_eq!(
                    msg.buckets[2].mutex, 1,
                    "incorrect value for buckets[2].mutex, expected 1, is {}",
                    msg.buckets[2].mutex
                );
                assert_eq!(
                    msg.buckets[2].name.as_bytes(),
                    &[83, 83, 82, 50, 79, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[2].name, expected string '{:?}', is '{:?}'",
                    &[83, 83, 82, 50, 79, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[2].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[2].thread, 1,
                    "incorrect value for buckets[2].thread, expected 1, is {}",
                    msg.buckets[2].thread
                );
                assert_eq!(
                    msg.buckets[3].cv, 1,
                    "incorrect value for buckets[3].cv, expected 1, is {}",
                    msg.buckets[3].cv
                );
                assert_eq!(
                    msg.buckets[3].heap_bytes_alloc, 247112,
                    "incorrect value for buckets[3].heap_bytes_alloc, expected 247112, is {}",
                    msg.buckets[3].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[3].heap_bytes_free, 0,
                    "incorrect value for buckets[3].heap_bytes_free, expected 0, is {}",
                    msg.buckets[3].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[3].io, 0,
                    "incorrect value for buckets[3].io, expected 0, is {}",
                    msg.buckets[3].io
                );
                assert_eq!(
                    msg.buckets[3].io_read, 0,
                    "incorrect value for buckets[3].io_read, expected 0, is {}",
                    msg.buckets[3].io_read
                );
                assert_eq!(
                    msg.buckets[3].io_write, 0,
                    "incorrect value for buckets[3].io_write, expected 0, is {}",
                    msg.buckets[3].io_write
                );
                assert_eq!(
                    msg.buckets[3].mutex, 2,
                    "incorrect value for buckets[3].mutex, expected 2, is {}",
                    msg.buckets[3].mutex
                );
                assert_eq!(
                    msg.buckets[3].name.as_bytes(),
                    &[80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[3].name, expected string '{:?}', is '{:?}'",
                    &[80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[3].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[3].thread, 1,
                    "incorrect value for buckets[3].thread, expected 1, is {}",
                    msg.buckets[3].thread
                );
                assert_eq!(
                    msg.buckets[4].cv, 1,
                    "incorrect value for buckets[4].cv, expected 1, is {}",
                    msg.buckets[4].cv
                );
                assert_eq!(
                    msg.buckets[4].heap_bytes_alloc, 18305,
                    "incorrect value for buckets[4].heap_bytes_alloc, expected 18305, is {}",
                    msg.buckets[4].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[4].heap_bytes_free, 0,
                    "incorrect value for buckets[4].heap_bytes_free, expected 0, is {}",
                    msg.buckets[4].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[4].io, 1,
                    "incorrect value for buckets[4].io, expected 1, is {}",
                    msg.buckets[4].io
                );
                assert_eq!(
                    msg.buckets[4].io_read, 26207,
                    "incorrect value for buckets[4].io_read, expected 26207, is {}",
                    msg.buckets[4].io_read
                );
                assert_eq!(
                    msg.buckets[4].io_write, 0,
                    "incorrect value for buckets[4].io_write, expected 0, is {}",
                    msg.buckets[4].io_write
                );
                assert_eq!(
                    msg.buckets[4].mutex, 1,
                    "incorrect value for buckets[4].mutex, expected 1, is {}",
                    msg.buckets[4].mutex
                );
                assert_eq!(
                    msg.buckets[4].name.as_bytes(),
                    &[73, 77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[4].name, expected string '{:?}', is '{:?}'",
                    &[73, 77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[4].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[4].thread, 1,
                    "incorrect value for buckets[4].thread, expected 1, is {}",
                    msg.buckets[4].thread
                );
                assert_eq!(
                    msg.buckets[5].cv, 2,
                    "incorrect value for buckets[5].cv, expected 2, is {}",
                    msg.buckets[5].cv
                );
                assert_eq!(
                    msg.buckets[5].heap_bytes_alloc, 43507,
                    "incorrect value for buckets[5].heap_bytes_alloc, expected 43507, is {}",
                    msg.buckets[5].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[5].heap_bytes_free, 0,
                    "incorrect value for buckets[5].heap_bytes_free, expected 0, is {}",
                    msg.buckets[5].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[5].io, 2,
                    "incorrect value for buckets[5].io, expected 2, is {}",
                    msg.buckets[5].io
                );
                assert_eq!(
                    msg.buckets[5].io_read, 498,
                    "incorrect value for buckets[5].io_read, expected 498, is {}",
                    msg.buckets[5].io_read
                );
                assert_eq!(
                    msg.buckets[5].io_write, 235451,
                    "incorrect value for buckets[5].io_write, expected 235451, is {}",
                    msg.buckets[5].io_write
                );
                assert_eq!(
                    msg.buckets[5].mutex, 2,
                    "incorrect value for buckets[5].mutex, expected 2, is {}",
                    msg.buckets[5].mutex
                );
                assert_eq!(
                    msg.buckets[5].name.as_bytes(),
                    &[115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[5].name, expected string '{:?}', is '{:?}'",
                    &[115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[5].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[5].thread, 5,
                    "incorrect value for buckets[5].thread, expected 5, is {}",
                    msg.buckets[5].thread
                );
                assert_eq!(
                    msg.seq_len, 3,
                    "incorrect value for seq_len, expected 3, is {}",
                    msg.seq_len
                );
                assert_eq!(
                    msg.seq_no, 1,
                    "incorrect value for seq_no, expected 1, is {}",
                    msg.seq_no
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingResourceCounter"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
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
fn test_json2sbp_auto_check_sbp_profiling_msg_profiling_resource_counter() {
    {
        let json_input = r#"{"crc": 39349, "preamble": 85, "sender": 4096, "length": 248, "msg_type": 52995,  "seq_no": 1, "seq_len": 3, "buckets": [ {"name": "Fusion engine\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "thread": 1, "mutex": 2, "cv": 2, "io": 0, "heap_bytes_alloc": 927480, "heap_bytes_free": 0, "io_write": 0, "io_read": 0},  {"name": "NTRIP client\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "thread": 1, "mutex": 1, "cv": 1, "io": 1, "heap_bytes_alloc": 84454, "heap_bytes_free": 0, "io_write": 879, "io_read": 19520},  {"name": "SSR2OSR\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "thread": 1, "mutex": 1, "cv": 1, "io": 0, "heap_bytes_alloc": 4328776, "heap_bytes_free": 0, "io_write": 0, "io_read": 0},  {"name": "Periodic\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "thread": 1, "mutex": 2, "cv": 1, "io": 0, "heap_bytes_alloc": 247112, "heap_bytes_free": 0, "io_write": 0, "io_read": 0},  {"name": "IMU\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "thread": 1, "mutex": 1, "cv": 1, "io": 1, "heap_bytes_alloc": 18305, "heap_bytes_free": 0, "io_write": 0, "io_read": 26207},  {"name": "sbp\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000", "thread": 5, "mutex": 2, "cv": 2, "io": 2, "heap_bytes_alloc": 43507, "heap_bytes_free": 0, "io_write": 235451, "io_read": 498}], "payload": "AQNGdXNpb24gZW5naW5lAAAAAAAAAAABAgIA+CYOAAAAAAAAAAAAAAAAAE5UUklQIGNsaWVudAAAAAAAAAAAAAEBAQHmSQEAAAAAAG8DAABATAAAU1NSMk9TUgAAAAAAAAAAAAAAAAAAAQEBAEgNQgAAAAAAAAAAAAAAAABQZXJpb2RpYwAAAAAAAAAAAAAAAAABAgEASMUDAAAAAAAAAAAAAAAAAElNVQAAAAAAAAAAAAAAAAAAAAAAAAEBAQGBRwAAAAAAAAAAAABfZgAAc2JwAAAAAAAAAAAAAAAAAAAAAAAABQICAvOpAAAAAAAAu5cDAPIBAAA="}
"#.as_bytes();

        let sbp_msg = {
            // JSON to SBP message from payload
            let mut iter = json2sbp_iter_msg(json_input);
            let from_payload = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            // JSON to SBP message from fields
            let mut iter = iter_messages_from_fields(json_input);
            let from_fields = iter
                .next()
                .expect("no message found")
                .expect("failed to parse message");

            assert_eq!(from_fields, from_payload);
            from_fields
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingResourceCounter(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf03,
                    "Incorrect message type, expected 0xcf03, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.buckets[0].cv, 2,
                    "incorrect value for buckets[0].cv, expected 2, is {}",
                    msg.buckets[0].cv
                );
                assert_eq!(
                    msg.buckets[0].heap_bytes_alloc, 927480,
                    "incorrect value for buckets[0].heap_bytes_alloc, expected 927480, is {}",
                    msg.buckets[0].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[0].heap_bytes_free, 0,
                    "incorrect value for buckets[0].heap_bytes_free, expected 0, is {}",
                    msg.buckets[0].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[0].io, 0,
                    "incorrect value for buckets[0].io, expected 0, is {}",
                    msg.buckets[0].io
                );
                assert_eq!(
                    msg.buckets[0].io_read, 0,
                    "incorrect value for buckets[0].io_read, expected 0, is {}",
                    msg.buckets[0].io_read
                );
                assert_eq!(
                    msg.buckets[0].io_write, 0,
                    "incorrect value for buckets[0].io_write, expected 0, is {}",
                    msg.buckets[0].io_write
                );
                assert_eq!(
                    msg.buckets[0].mutex, 2,
                    "incorrect value for buckets[0].mutex, expected 2, is {}",
                    msg.buckets[0].mutex
                );
                assert_eq!(
                    msg.buckets[0].name.as_bytes(),
                    &[
                        70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0, 0, 0, 0,
                        0, 0, 0, 0
                    ],
                    "incorrect value for msg.buckets[0].name, expected string '{:?}', is '{:?}'",
                    &[
                        70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0, 0, 0, 0,
                        0, 0, 0, 0
                    ],
                    msg.buckets[0].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[0].thread, 1,
                    "incorrect value for buckets[0].thread, expected 1, is {}",
                    msg.buckets[0].thread
                );
                assert_eq!(
                    msg.buckets[1].cv, 1,
                    "incorrect value for buckets[1].cv, expected 1, is {}",
                    msg.buckets[1].cv
                );
                assert_eq!(
                    msg.buckets[1].heap_bytes_alloc, 84454,
                    "incorrect value for buckets[1].heap_bytes_alloc, expected 84454, is {}",
                    msg.buckets[1].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[1].heap_bytes_free, 0,
                    "incorrect value for buckets[1].heap_bytes_free, expected 0, is {}",
                    msg.buckets[1].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[1].io, 1,
                    "incorrect value for buckets[1].io, expected 1, is {}",
                    msg.buckets[1].io
                );
                assert_eq!(
                    msg.buckets[1].io_read, 19520,
                    "incorrect value for buckets[1].io_read, expected 19520, is {}",
                    msg.buckets[1].io_read
                );
                assert_eq!(
                    msg.buckets[1].io_write, 879,
                    "incorrect value for buckets[1].io_write, expected 879, is {}",
                    msg.buckets[1].io_write
                );
                assert_eq!(
                    msg.buckets[1].mutex, 1,
                    "incorrect value for buckets[1].mutex, expected 1, is {}",
                    msg.buckets[1].mutex
                );
                assert_eq!(
                    msg.buckets[1].name.as_bytes(),
                    &[
                        78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0,
                        0, 0
                    ],
                    "incorrect value for msg.buckets[1].name, expected string '{:?}', is '{:?}'",
                    &[
                        78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0,
                        0, 0
                    ],
                    msg.buckets[1].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[1].thread, 1,
                    "incorrect value for buckets[1].thread, expected 1, is {}",
                    msg.buckets[1].thread
                );
                assert_eq!(
                    msg.buckets[2].cv, 1,
                    "incorrect value for buckets[2].cv, expected 1, is {}",
                    msg.buckets[2].cv
                );
                assert_eq!(
                    msg.buckets[2].heap_bytes_alloc, 4328776,
                    "incorrect value for buckets[2].heap_bytes_alloc, expected 4328776, is {}",
                    msg.buckets[2].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[2].heap_bytes_free, 0,
                    "incorrect value for buckets[2].heap_bytes_free, expected 0, is {}",
                    msg.buckets[2].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[2].io, 0,
                    "incorrect value for buckets[2].io, expected 0, is {}",
                    msg.buckets[2].io
                );
                assert_eq!(
                    msg.buckets[2].io_read, 0,
                    "incorrect value for buckets[2].io_read, expected 0, is {}",
                    msg.buckets[2].io_read
                );
                assert_eq!(
                    msg.buckets[2].io_write, 0,
                    "incorrect value for buckets[2].io_write, expected 0, is {}",
                    msg.buckets[2].io_write
                );
                assert_eq!(
                    msg.buckets[2].mutex, 1,
                    "incorrect value for buckets[2].mutex, expected 1, is {}",
                    msg.buckets[2].mutex
                );
                assert_eq!(
                    msg.buckets[2].name.as_bytes(),
                    &[83, 83, 82, 50, 79, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[2].name, expected string '{:?}', is '{:?}'",
                    &[83, 83, 82, 50, 79, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[2].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[2].thread, 1,
                    "incorrect value for buckets[2].thread, expected 1, is {}",
                    msg.buckets[2].thread
                );
                assert_eq!(
                    msg.buckets[3].cv, 1,
                    "incorrect value for buckets[3].cv, expected 1, is {}",
                    msg.buckets[3].cv
                );
                assert_eq!(
                    msg.buckets[3].heap_bytes_alloc, 247112,
                    "incorrect value for buckets[3].heap_bytes_alloc, expected 247112, is {}",
                    msg.buckets[3].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[3].heap_bytes_free, 0,
                    "incorrect value for buckets[3].heap_bytes_free, expected 0, is {}",
                    msg.buckets[3].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[3].io, 0,
                    "incorrect value for buckets[3].io, expected 0, is {}",
                    msg.buckets[3].io
                );
                assert_eq!(
                    msg.buckets[3].io_read, 0,
                    "incorrect value for buckets[3].io_read, expected 0, is {}",
                    msg.buckets[3].io_read
                );
                assert_eq!(
                    msg.buckets[3].io_write, 0,
                    "incorrect value for buckets[3].io_write, expected 0, is {}",
                    msg.buckets[3].io_write
                );
                assert_eq!(
                    msg.buckets[3].mutex, 2,
                    "incorrect value for buckets[3].mutex, expected 2, is {}",
                    msg.buckets[3].mutex
                );
                assert_eq!(
                    msg.buckets[3].name.as_bytes(),
                    &[80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[3].name, expected string '{:?}', is '{:?}'",
                    &[80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[3].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[3].thread, 1,
                    "incorrect value for buckets[3].thread, expected 1, is {}",
                    msg.buckets[3].thread
                );
                assert_eq!(
                    msg.buckets[4].cv, 1,
                    "incorrect value for buckets[4].cv, expected 1, is {}",
                    msg.buckets[4].cv
                );
                assert_eq!(
                    msg.buckets[4].heap_bytes_alloc, 18305,
                    "incorrect value for buckets[4].heap_bytes_alloc, expected 18305, is {}",
                    msg.buckets[4].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[4].heap_bytes_free, 0,
                    "incorrect value for buckets[4].heap_bytes_free, expected 0, is {}",
                    msg.buckets[4].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[4].io, 1,
                    "incorrect value for buckets[4].io, expected 1, is {}",
                    msg.buckets[4].io
                );
                assert_eq!(
                    msg.buckets[4].io_read, 26207,
                    "incorrect value for buckets[4].io_read, expected 26207, is {}",
                    msg.buckets[4].io_read
                );
                assert_eq!(
                    msg.buckets[4].io_write, 0,
                    "incorrect value for buckets[4].io_write, expected 0, is {}",
                    msg.buckets[4].io_write
                );
                assert_eq!(
                    msg.buckets[4].mutex, 1,
                    "incorrect value for buckets[4].mutex, expected 1, is {}",
                    msg.buckets[4].mutex
                );
                assert_eq!(
                    msg.buckets[4].name.as_bytes(),
                    &[73, 77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[4].name, expected string '{:?}', is '{:?}'",
                    &[73, 77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[4].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[4].thread, 1,
                    "incorrect value for buckets[4].thread, expected 1, is {}",
                    msg.buckets[4].thread
                );
                assert_eq!(
                    msg.buckets[5].cv, 2,
                    "incorrect value for buckets[5].cv, expected 2, is {}",
                    msg.buckets[5].cv
                );
                assert_eq!(
                    msg.buckets[5].heap_bytes_alloc, 43507,
                    "incorrect value for buckets[5].heap_bytes_alloc, expected 43507, is {}",
                    msg.buckets[5].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[5].heap_bytes_free, 0,
                    "incorrect value for buckets[5].heap_bytes_free, expected 0, is {}",
                    msg.buckets[5].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[5].io, 2,
                    "incorrect value for buckets[5].io, expected 2, is {}",
                    msg.buckets[5].io
                );
                assert_eq!(
                    msg.buckets[5].io_read, 498,
                    "incorrect value for buckets[5].io_read, expected 498, is {}",
                    msg.buckets[5].io_read
                );
                assert_eq!(
                    msg.buckets[5].io_write, 235451,
                    "incorrect value for buckets[5].io_write, expected 235451, is {}",
                    msg.buckets[5].io_write
                );
                assert_eq!(
                    msg.buckets[5].mutex, 2,
                    "incorrect value for buckets[5].mutex, expected 2, is {}",
                    msg.buckets[5].mutex
                );
                assert_eq!(
                    msg.buckets[5].name.as_bytes(),
                    &[115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[5].name, expected string '{:?}', is '{:?}'",
                    &[115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[5].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[5].thread, 5,
                    "incorrect value for buckets[5].thread, expected 5, is {}",
                    msg.buckets[5].thread
                );
                assert_eq!(
                    msg.seq_len, 3,
                    "incorrect value for seq_len, expected 3, is {}",
                    msg.seq_len
                );
                assert_eq!(
                    msg.seq_no, 1,
                    "incorrect value for seq_no, expected 1, is {}",
                    msg.seq_no
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingResourceCounter"),
        };
    }
}

/// Tests [`sbp::json::JsonEncoder`] for roundtrip SBP message -> JSON
///
/// Assumes:
/// -   [`self::test_auto_check_sbp_profiling_msg_profiling_resource_counter`] passes
///
/// Asserts:
/// -   SBP fields equates to that of the field
/// -   Payload is identical
#[test]
#[cfg(feature = "json")]
fn test_sbp2json_auto_check_sbp_profiling_msg_profiling_resource_counter() {
    {
        let mut payload = Cursor::new(vec![
            85, 3, 207, 0, 16, 248, 1, 3, 70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110,
            101, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 0, 248, 38, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 230, 73, 1, 0, 0, 0, 0, 0, 111, 3, 0, 0, 64, 76, 0, 0, 83, 83, 82, 50, 79,
            83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 72, 13, 66, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 72, 197, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73,
            77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 129, 71, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 95, 102, 0, 0, 115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 5, 2, 2, 2, 243, 169, 0, 0, 0, 0, 0, 0, 187, 151, 3, 0, 242, 1,
            0, 0, 181, 153,
        ]);

        // Construct sbp message
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };

        let mut json_buffer = vec![];
        // Populate json buffer, CompactFormatter
        sbp::json::JsonEncoder::new(&mut json_buffer, sbp::json::CompactFormatter {})
            .send(&sbp_msg)
            .unwrap();

        // Reconstruct Sbp message from json fields, roundtrip
        let sbp_msg = sbp::messages::Sbp::MsgProfilingResourceCounter(
            serde_json::from_str(
                std::str::from_utf8(json_buffer.as_slice())
                    .unwrap()
                    .to_string()
                    .as_str(),
            )
            .unwrap(),
        );
        match &sbp_msg {
            sbp::messages::Sbp::MsgProfilingResourceCounter(msg) => {
                let msg_type = msg.message_type().unwrap();
                assert_eq!(
                    msg_type, 0xcf03,
                    "Incorrect message type, expected 0xcf03, is {}",
                    msg_type
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x1000,
                    "incorrect sender id, expected 0x1000, is {sender_id}"
                );
                assert_eq!(
                    msg.buckets[0].cv, 2,
                    "incorrect value for buckets[0].cv, expected 2, is {}",
                    msg.buckets[0].cv
                );
                assert_eq!(
                    msg.buckets[0].heap_bytes_alloc, 927480,
                    "incorrect value for buckets[0].heap_bytes_alloc, expected 927480, is {}",
                    msg.buckets[0].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[0].heap_bytes_free, 0,
                    "incorrect value for buckets[0].heap_bytes_free, expected 0, is {}",
                    msg.buckets[0].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[0].io, 0,
                    "incorrect value for buckets[0].io, expected 0, is {}",
                    msg.buckets[0].io
                );
                assert_eq!(
                    msg.buckets[0].io_read, 0,
                    "incorrect value for buckets[0].io_read, expected 0, is {}",
                    msg.buckets[0].io_read
                );
                assert_eq!(
                    msg.buckets[0].io_write, 0,
                    "incorrect value for buckets[0].io_write, expected 0, is {}",
                    msg.buckets[0].io_write
                );
                assert_eq!(
                    msg.buckets[0].mutex, 2,
                    "incorrect value for buckets[0].mutex, expected 2, is {}",
                    msg.buckets[0].mutex
                );
                assert_eq!(
                    msg.buckets[0].name.as_bytes(),
                    &[
                        70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0, 0, 0, 0,
                        0, 0, 0, 0
                    ],
                    "incorrect value for msg.buckets[0].name, expected string '{:?}', is '{:?}'",
                    &[
                        70, 117, 115, 105, 111, 110, 32, 101, 110, 103, 105, 110, 101, 0, 0, 0, 0,
                        0, 0, 0, 0
                    ],
                    msg.buckets[0].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[0].thread, 1,
                    "incorrect value for buckets[0].thread, expected 1, is {}",
                    msg.buckets[0].thread
                );
                assert_eq!(
                    msg.buckets[1].cv, 1,
                    "incorrect value for buckets[1].cv, expected 1, is {}",
                    msg.buckets[1].cv
                );
                assert_eq!(
                    msg.buckets[1].heap_bytes_alloc, 84454,
                    "incorrect value for buckets[1].heap_bytes_alloc, expected 84454, is {}",
                    msg.buckets[1].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[1].heap_bytes_free, 0,
                    "incorrect value for buckets[1].heap_bytes_free, expected 0, is {}",
                    msg.buckets[1].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[1].io, 1,
                    "incorrect value for buckets[1].io, expected 1, is {}",
                    msg.buckets[1].io
                );
                assert_eq!(
                    msg.buckets[1].io_read, 19520,
                    "incorrect value for buckets[1].io_read, expected 19520, is {}",
                    msg.buckets[1].io_read
                );
                assert_eq!(
                    msg.buckets[1].io_write, 879,
                    "incorrect value for buckets[1].io_write, expected 879, is {}",
                    msg.buckets[1].io_write
                );
                assert_eq!(
                    msg.buckets[1].mutex, 1,
                    "incorrect value for buckets[1].mutex, expected 1, is {}",
                    msg.buckets[1].mutex
                );
                assert_eq!(
                    msg.buckets[1].name.as_bytes(),
                    &[
                        78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0,
                        0, 0
                    ],
                    "incorrect value for msg.buckets[1].name, expected string '{:?}', is '{:?}'",
                    &[
                        78, 84, 82, 73, 80, 32, 99, 108, 105, 101, 110, 116, 0, 0, 0, 0, 0, 0, 0,
                        0, 0
                    ],
                    msg.buckets[1].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[1].thread, 1,
                    "incorrect value for buckets[1].thread, expected 1, is {}",
                    msg.buckets[1].thread
                );
                assert_eq!(
                    msg.buckets[2].cv, 1,
                    "incorrect value for buckets[2].cv, expected 1, is {}",
                    msg.buckets[2].cv
                );
                assert_eq!(
                    msg.buckets[2].heap_bytes_alloc, 4328776,
                    "incorrect value for buckets[2].heap_bytes_alloc, expected 4328776, is {}",
                    msg.buckets[2].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[2].heap_bytes_free, 0,
                    "incorrect value for buckets[2].heap_bytes_free, expected 0, is {}",
                    msg.buckets[2].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[2].io, 0,
                    "incorrect value for buckets[2].io, expected 0, is {}",
                    msg.buckets[2].io
                );
                assert_eq!(
                    msg.buckets[2].io_read, 0,
                    "incorrect value for buckets[2].io_read, expected 0, is {}",
                    msg.buckets[2].io_read
                );
                assert_eq!(
                    msg.buckets[2].io_write, 0,
                    "incorrect value for buckets[2].io_write, expected 0, is {}",
                    msg.buckets[2].io_write
                );
                assert_eq!(
                    msg.buckets[2].mutex, 1,
                    "incorrect value for buckets[2].mutex, expected 1, is {}",
                    msg.buckets[2].mutex
                );
                assert_eq!(
                    msg.buckets[2].name.as_bytes(),
                    &[83, 83, 82, 50, 79, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[2].name, expected string '{:?}', is '{:?}'",
                    &[83, 83, 82, 50, 79, 83, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[2].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[2].thread, 1,
                    "incorrect value for buckets[2].thread, expected 1, is {}",
                    msg.buckets[2].thread
                );
                assert_eq!(
                    msg.buckets[3].cv, 1,
                    "incorrect value for buckets[3].cv, expected 1, is {}",
                    msg.buckets[3].cv
                );
                assert_eq!(
                    msg.buckets[3].heap_bytes_alloc, 247112,
                    "incorrect value for buckets[3].heap_bytes_alloc, expected 247112, is {}",
                    msg.buckets[3].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[3].heap_bytes_free, 0,
                    "incorrect value for buckets[3].heap_bytes_free, expected 0, is {}",
                    msg.buckets[3].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[3].io, 0,
                    "incorrect value for buckets[3].io, expected 0, is {}",
                    msg.buckets[3].io
                );
                assert_eq!(
                    msg.buckets[3].io_read, 0,
                    "incorrect value for buckets[3].io_read, expected 0, is {}",
                    msg.buckets[3].io_read
                );
                assert_eq!(
                    msg.buckets[3].io_write, 0,
                    "incorrect value for buckets[3].io_write, expected 0, is {}",
                    msg.buckets[3].io_write
                );
                assert_eq!(
                    msg.buckets[3].mutex, 2,
                    "incorrect value for buckets[3].mutex, expected 2, is {}",
                    msg.buckets[3].mutex
                );
                assert_eq!(
                    msg.buckets[3].name.as_bytes(),
                    &[80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[3].name, expected string '{:?}', is '{:?}'",
                    &[80, 101, 114, 105, 111, 100, 105, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[3].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[3].thread, 1,
                    "incorrect value for buckets[3].thread, expected 1, is {}",
                    msg.buckets[3].thread
                );
                assert_eq!(
                    msg.buckets[4].cv, 1,
                    "incorrect value for buckets[4].cv, expected 1, is {}",
                    msg.buckets[4].cv
                );
                assert_eq!(
                    msg.buckets[4].heap_bytes_alloc, 18305,
                    "incorrect value for buckets[4].heap_bytes_alloc, expected 18305, is {}",
                    msg.buckets[4].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[4].heap_bytes_free, 0,
                    "incorrect value for buckets[4].heap_bytes_free, expected 0, is {}",
                    msg.buckets[4].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[4].io, 1,
                    "incorrect value for buckets[4].io, expected 1, is {}",
                    msg.buckets[4].io
                );
                assert_eq!(
                    msg.buckets[4].io_read, 26207,
                    "incorrect value for buckets[4].io_read, expected 26207, is {}",
                    msg.buckets[4].io_read
                );
                assert_eq!(
                    msg.buckets[4].io_write, 0,
                    "incorrect value for buckets[4].io_write, expected 0, is {}",
                    msg.buckets[4].io_write
                );
                assert_eq!(
                    msg.buckets[4].mutex, 1,
                    "incorrect value for buckets[4].mutex, expected 1, is {}",
                    msg.buckets[4].mutex
                );
                assert_eq!(
                    msg.buckets[4].name.as_bytes(),
                    &[73, 77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[4].name, expected string '{:?}', is '{:?}'",
                    &[73, 77, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[4].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[4].thread, 1,
                    "incorrect value for buckets[4].thread, expected 1, is {}",
                    msg.buckets[4].thread
                );
                assert_eq!(
                    msg.buckets[5].cv, 2,
                    "incorrect value for buckets[5].cv, expected 2, is {}",
                    msg.buckets[5].cv
                );
                assert_eq!(
                    msg.buckets[5].heap_bytes_alloc, 43507,
                    "incorrect value for buckets[5].heap_bytes_alloc, expected 43507, is {}",
                    msg.buckets[5].heap_bytes_alloc
                );
                assert_eq!(
                    msg.buckets[5].heap_bytes_free, 0,
                    "incorrect value for buckets[5].heap_bytes_free, expected 0, is {}",
                    msg.buckets[5].heap_bytes_free
                );
                assert_eq!(
                    msg.buckets[5].io, 2,
                    "incorrect value for buckets[5].io, expected 2, is {}",
                    msg.buckets[5].io
                );
                assert_eq!(
                    msg.buckets[5].io_read, 498,
                    "incorrect value for buckets[5].io_read, expected 498, is {}",
                    msg.buckets[5].io_read
                );
                assert_eq!(
                    msg.buckets[5].io_write, 235451,
                    "incorrect value for buckets[5].io_write, expected 235451, is {}",
                    msg.buckets[5].io_write
                );
                assert_eq!(
                    msg.buckets[5].mutex, 2,
                    "incorrect value for buckets[5].mutex, expected 2, is {}",
                    msg.buckets[5].mutex
                );
                assert_eq!(
                    msg.buckets[5].name.as_bytes(),
                    &[115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    "incorrect value for msg.buckets[5].name, expected string '{:?}', is '{:?}'",
                    &[115, 98, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    msg.buckets[5].name.as_bytes()
                );
                assert_eq!(
                    msg.buckets[5].thread, 5,
                    "incorrect value for buckets[5].thread, expected 5, is {}",
                    msg.buckets[5].thread
                );
                assert_eq!(
                    msg.seq_len, 3,
                    "incorrect value for seq_len, expected 3, is {}",
                    msg.seq_len
                );
                assert_eq!(
                    msg.seq_no, 1,
                    "incorrect value for seq_no, expected 1, is {}",
                    msg.seq_no
                );
            }
            _ => panic!("Invalid message type! Expected a MsgProfilingResourceCounter"),
        };

        // Check payload is still identical
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
