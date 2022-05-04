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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgItrf.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_navigation_msg_itrf() {
    {
        let mut payload = Cursor::new(vec![
            85, 68, 2, 66, 0, 124, 1, 2, 102, 111, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 98, 97, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 0, 6, 0, 7, 0, 0, 0, 8, 0,
            0, 0, 9, 0, 0, 0, 10, 0, 0, 0, 11, 0, 0, 0, 12, 0, 0, 0, 13, 0, 0, 0, 14, 0, 0, 0, 15,
            0, 0, 0, 16, 0, 0, 0, 17, 0, 0, 0, 18, 0, 0, 0, 19, 0, 0, 0, 20, 0, 66, 126,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgItrf(msg) => {
                assert_eq!(
                    msg.message_type(),
                    580,
                    "Incorrect message type, expected 580, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x0042,
                    "incorrect sender id, expected 0x0042, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.stub[0], 1,
                    "incorrect value for stub[0], expected 1, is {}",
                    msg.stub[0]
                );
                assert_eq!(
                    msg.stub[1], 2,
                    "incorrect value for stub[1], expected 2, is {}",
                    msg.stub[1]
                );
                assert_eq!(
                    msg.stub[2], 102,
                    "incorrect value for stub[2], expected 102, is {}",
                    msg.stub[2]
                );
                assert_eq!(
                    msg.stub[3], 111,
                    "incorrect value for stub[3], expected 111, is {}",
                    msg.stub[3]
                );
                assert_eq!(
                    msg.stub[4], 111,
                    "incorrect value for stub[4], expected 111, is {}",
                    msg.stub[4]
                );
                assert_eq!(
                    msg.stub[5], 0,
                    "incorrect value for stub[5], expected 0, is {}",
                    msg.stub[5]
                );
                assert_eq!(
                    msg.stub[6], 0,
                    "incorrect value for stub[6], expected 0, is {}",
                    msg.stub[6]
                );
                assert_eq!(
                    msg.stub[7], 0,
                    "incorrect value for stub[7], expected 0, is {}",
                    msg.stub[7]
                );
                assert_eq!(
                    msg.stub[8], 0,
                    "incorrect value for stub[8], expected 0, is {}",
                    msg.stub[8]
                );
                assert_eq!(
                    msg.stub[9], 0,
                    "incorrect value for stub[9], expected 0, is {}",
                    msg.stub[9]
                );
                assert_eq!(
                    msg.stub[10], 0,
                    "incorrect value for stub[10], expected 0, is {}",
                    msg.stub[10]
                );
                assert_eq!(
                    msg.stub[11], 0,
                    "incorrect value for stub[11], expected 0, is {}",
                    msg.stub[11]
                );
                assert_eq!(
                    msg.stub[12], 0,
                    "incorrect value for stub[12], expected 0, is {}",
                    msg.stub[12]
                );
                assert_eq!(
                    msg.stub[13], 0,
                    "incorrect value for stub[13], expected 0, is {}",
                    msg.stub[13]
                );
                assert_eq!(
                    msg.stub[14], 0,
                    "incorrect value for stub[14], expected 0, is {}",
                    msg.stub[14]
                );
                assert_eq!(
                    msg.stub[15], 0,
                    "incorrect value for stub[15], expected 0, is {}",
                    msg.stub[15]
                );
                assert_eq!(
                    msg.stub[16], 0,
                    "incorrect value for stub[16], expected 0, is {}",
                    msg.stub[16]
                );
                assert_eq!(
                    msg.stub[17], 0,
                    "incorrect value for stub[17], expected 0, is {}",
                    msg.stub[17]
                );
                assert_eq!(
                    msg.stub[18], 0,
                    "incorrect value for stub[18], expected 0, is {}",
                    msg.stub[18]
                );
                assert_eq!(
                    msg.stub[19], 0,
                    "incorrect value for stub[19], expected 0, is {}",
                    msg.stub[19]
                );
                assert_eq!(
                    msg.stub[20], 0,
                    "incorrect value for stub[20], expected 0, is {}",
                    msg.stub[20]
                );
                assert_eq!(
                    msg.stub[21], 0,
                    "incorrect value for stub[21], expected 0, is {}",
                    msg.stub[21]
                );
                assert_eq!(
                    msg.stub[22], 0,
                    "incorrect value for stub[22], expected 0, is {}",
                    msg.stub[22]
                );
                assert_eq!(
                    msg.stub[23], 0,
                    "incorrect value for stub[23], expected 0, is {}",
                    msg.stub[23]
                );
                assert_eq!(
                    msg.stub[24], 0,
                    "incorrect value for stub[24], expected 0, is {}",
                    msg.stub[24]
                );
                assert_eq!(
                    msg.stub[25], 0,
                    "incorrect value for stub[25], expected 0, is {}",
                    msg.stub[25]
                );
                assert_eq!(
                    msg.stub[26], 0,
                    "incorrect value for stub[26], expected 0, is {}",
                    msg.stub[26]
                );
                assert_eq!(
                    msg.stub[27], 0,
                    "incorrect value for stub[27], expected 0, is {}",
                    msg.stub[27]
                );
                assert_eq!(
                    msg.stub[28], 0,
                    "incorrect value for stub[28], expected 0, is {}",
                    msg.stub[28]
                );
                assert_eq!(
                    msg.stub[29], 0,
                    "incorrect value for stub[29], expected 0, is {}",
                    msg.stub[29]
                );
                assert_eq!(
                    msg.stub[30], 0,
                    "incorrect value for stub[30], expected 0, is {}",
                    msg.stub[30]
                );
                assert_eq!(
                    msg.stub[31], 0,
                    "incorrect value for stub[31], expected 0, is {}",
                    msg.stub[31]
                );
                assert_eq!(
                    msg.stub[32], 0,
                    "incorrect value for stub[32], expected 0, is {}",
                    msg.stub[32]
                );
                assert_eq!(
                    msg.stub[33], 3,
                    "incorrect value for stub[33], expected 3, is {}",
                    msg.stub[33]
                );
                assert_eq!(
                    msg.stub[34], 98,
                    "incorrect value for stub[34], expected 98, is {}",
                    msg.stub[34]
                );
                assert_eq!(
                    msg.stub[35], 97,
                    "incorrect value for stub[35], expected 97, is {}",
                    msg.stub[35]
                );
                assert_eq!(
                    msg.stub[36], 114,
                    "incorrect value for stub[36], expected 114, is {}",
                    msg.stub[36]
                );
                assert_eq!(
                    msg.stub[37], 0,
                    "incorrect value for stub[37], expected 0, is {}",
                    msg.stub[37]
                );
                assert_eq!(
                    msg.stub[38], 0,
                    "incorrect value for stub[38], expected 0, is {}",
                    msg.stub[38]
                );
                assert_eq!(
                    msg.stub[39], 0,
                    "incorrect value for stub[39], expected 0, is {}",
                    msg.stub[39]
                );
                assert_eq!(
                    msg.stub[40], 0,
                    "incorrect value for stub[40], expected 0, is {}",
                    msg.stub[40]
                );
                assert_eq!(
                    msg.stub[41], 0,
                    "incorrect value for stub[41], expected 0, is {}",
                    msg.stub[41]
                );
                assert_eq!(
                    msg.stub[42], 0,
                    "incorrect value for stub[42], expected 0, is {}",
                    msg.stub[42]
                );
                assert_eq!(
                    msg.stub[43], 0,
                    "incorrect value for stub[43], expected 0, is {}",
                    msg.stub[43]
                );
                assert_eq!(
                    msg.stub[44], 0,
                    "incorrect value for stub[44], expected 0, is {}",
                    msg.stub[44]
                );
                assert_eq!(
                    msg.stub[45], 0,
                    "incorrect value for stub[45], expected 0, is {}",
                    msg.stub[45]
                );
                assert_eq!(
                    msg.stub[46], 0,
                    "incorrect value for stub[46], expected 0, is {}",
                    msg.stub[46]
                );
                assert_eq!(
                    msg.stub[47], 0,
                    "incorrect value for stub[47], expected 0, is {}",
                    msg.stub[47]
                );
                assert_eq!(
                    msg.stub[48], 0,
                    "incorrect value for stub[48], expected 0, is {}",
                    msg.stub[48]
                );
                assert_eq!(
                    msg.stub[49], 0,
                    "incorrect value for stub[49], expected 0, is {}",
                    msg.stub[49]
                );
                assert_eq!(
                    msg.stub[50], 0,
                    "incorrect value for stub[50], expected 0, is {}",
                    msg.stub[50]
                );
                assert_eq!(
                    msg.stub[51], 0,
                    "incorrect value for stub[51], expected 0, is {}",
                    msg.stub[51]
                );
                assert_eq!(
                    msg.stub[52], 0,
                    "incorrect value for stub[52], expected 0, is {}",
                    msg.stub[52]
                );
                assert_eq!(
                    msg.stub[53], 0,
                    "incorrect value for stub[53], expected 0, is {}",
                    msg.stub[53]
                );
                assert_eq!(
                    msg.stub[54], 0,
                    "incorrect value for stub[54], expected 0, is {}",
                    msg.stub[54]
                );
                assert_eq!(
                    msg.stub[55], 0,
                    "incorrect value for stub[55], expected 0, is {}",
                    msg.stub[55]
                );
                assert_eq!(
                    msg.stub[56], 0,
                    "incorrect value for stub[56], expected 0, is {}",
                    msg.stub[56]
                );
                assert_eq!(
                    msg.stub[57], 0,
                    "incorrect value for stub[57], expected 0, is {}",
                    msg.stub[57]
                );
                assert_eq!(
                    msg.stub[58], 0,
                    "incorrect value for stub[58], expected 0, is {}",
                    msg.stub[58]
                );
                assert_eq!(
                    msg.stub[59], 0,
                    "incorrect value for stub[59], expected 0, is {}",
                    msg.stub[59]
                );
                assert_eq!(
                    msg.stub[60], 0,
                    "incorrect value for stub[60], expected 0, is {}",
                    msg.stub[60]
                );
                assert_eq!(
                    msg.stub[61], 0,
                    "incorrect value for stub[61], expected 0, is {}",
                    msg.stub[61]
                );
                assert_eq!(
                    msg.stub[62], 0,
                    "incorrect value for stub[62], expected 0, is {}",
                    msg.stub[62]
                );
                assert_eq!(
                    msg.stub[63], 0,
                    "incorrect value for stub[63], expected 0, is {}",
                    msg.stub[63]
                );
                assert_eq!(
                    msg.stub[64], 0,
                    "incorrect value for stub[64], expected 0, is {}",
                    msg.stub[64]
                );
                assert_eq!(
                    msg.stub[65], 4,
                    "incorrect value for stub[65], expected 4, is {}",
                    msg.stub[65]
                );
                assert_eq!(
                    msg.stub[66], 5,
                    "incorrect value for stub[66], expected 5, is {}",
                    msg.stub[66]
                );
                assert_eq!(
                    msg.stub[67], 0,
                    "incorrect value for stub[67], expected 0, is {}",
                    msg.stub[67]
                );
                assert_eq!(
                    msg.stub[68], 6,
                    "incorrect value for stub[68], expected 6, is {}",
                    msg.stub[68]
                );
                assert_eq!(
                    msg.stub[69], 0,
                    "incorrect value for stub[69], expected 0, is {}",
                    msg.stub[69]
                );
                assert_eq!(
                    msg.stub[70], 7,
                    "incorrect value for stub[70], expected 7, is {}",
                    msg.stub[70]
                );
                assert_eq!(
                    msg.stub[71], 0,
                    "incorrect value for stub[71], expected 0, is {}",
                    msg.stub[71]
                );
                assert_eq!(
                    msg.stub[72], 0,
                    "incorrect value for stub[72], expected 0, is {}",
                    msg.stub[72]
                );
                assert_eq!(
                    msg.stub[73], 0,
                    "incorrect value for stub[73], expected 0, is {}",
                    msg.stub[73]
                );
                assert_eq!(
                    msg.stub[74], 8,
                    "incorrect value for stub[74], expected 8, is {}",
                    msg.stub[74]
                );
                assert_eq!(
                    msg.stub[75], 0,
                    "incorrect value for stub[75], expected 0, is {}",
                    msg.stub[75]
                );
                assert_eq!(
                    msg.stub[76], 0,
                    "incorrect value for stub[76], expected 0, is {}",
                    msg.stub[76]
                );
                assert_eq!(
                    msg.stub[77], 0,
                    "incorrect value for stub[77], expected 0, is {}",
                    msg.stub[77]
                );
                assert_eq!(
                    msg.stub[78], 9,
                    "incorrect value for stub[78], expected 9, is {}",
                    msg.stub[78]
                );
                assert_eq!(
                    msg.stub[79], 0,
                    "incorrect value for stub[79], expected 0, is {}",
                    msg.stub[79]
                );
                assert_eq!(
                    msg.stub[80], 0,
                    "incorrect value for stub[80], expected 0, is {}",
                    msg.stub[80]
                );
                assert_eq!(
                    msg.stub[81], 0,
                    "incorrect value for stub[81], expected 0, is {}",
                    msg.stub[81]
                );
                assert_eq!(
                    msg.stub[82], 10,
                    "incorrect value for stub[82], expected 10, is {}",
                    msg.stub[82]
                );
                assert_eq!(
                    msg.stub[83], 0,
                    "incorrect value for stub[83], expected 0, is {}",
                    msg.stub[83]
                );
                assert_eq!(
                    msg.stub[84], 0,
                    "incorrect value for stub[84], expected 0, is {}",
                    msg.stub[84]
                );
                assert_eq!(
                    msg.stub[85], 0,
                    "incorrect value for stub[85], expected 0, is {}",
                    msg.stub[85]
                );
                assert_eq!(
                    msg.stub[86], 11,
                    "incorrect value for stub[86], expected 11, is {}",
                    msg.stub[86]
                );
                assert_eq!(
                    msg.stub[87], 0,
                    "incorrect value for stub[87], expected 0, is {}",
                    msg.stub[87]
                );
                assert_eq!(
                    msg.stub[88], 0,
                    "incorrect value for stub[88], expected 0, is {}",
                    msg.stub[88]
                );
                assert_eq!(
                    msg.stub[89], 0,
                    "incorrect value for stub[89], expected 0, is {}",
                    msg.stub[89]
                );
                assert_eq!(
                    msg.stub[90], 12,
                    "incorrect value for stub[90], expected 12, is {}",
                    msg.stub[90]
                );
                assert_eq!(
                    msg.stub[91], 0,
                    "incorrect value for stub[91], expected 0, is {}",
                    msg.stub[91]
                );
                assert_eq!(
                    msg.stub[92], 0,
                    "incorrect value for stub[92], expected 0, is {}",
                    msg.stub[92]
                );
                assert_eq!(
                    msg.stub[93], 0,
                    "incorrect value for stub[93], expected 0, is {}",
                    msg.stub[93]
                );
                assert_eq!(
                    msg.stub[94], 13,
                    "incorrect value for stub[94], expected 13, is {}",
                    msg.stub[94]
                );
                assert_eq!(
                    msg.stub[95], 0,
                    "incorrect value for stub[95], expected 0, is {}",
                    msg.stub[95]
                );
                assert_eq!(
                    msg.stub[96], 0,
                    "incorrect value for stub[96], expected 0, is {}",
                    msg.stub[96]
                );
                assert_eq!(
                    msg.stub[97], 0,
                    "incorrect value for stub[97], expected 0, is {}",
                    msg.stub[97]
                );
                assert_eq!(
                    msg.stub[98], 14,
                    "incorrect value for stub[98], expected 14, is {}",
                    msg.stub[98]
                );
                assert_eq!(
                    msg.stub[99], 0,
                    "incorrect value for stub[99], expected 0, is {}",
                    msg.stub[99]
                );
                assert_eq!(
                    msg.stub[100], 0,
                    "incorrect value for stub[100], expected 0, is {}",
                    msg.stub[100]
                );
                assert_eq!(
                    msg.stub[101], 0,
                    "incorrect value for stub[101], expected 0, is {}",
                    msg.stub[101]
                );
                assert_eq!(
                    msg.stub[102], 15,
                    "incorrect value for stub[102], expected 15, is {}",
                    msg.stub[102]
                );
                assert_eq!(
                    msg.stub[103], 0,
                    "incorrect value for stub[103], expected 0, is {}",
                    msg.stub[103]
                );
                assert_eq!(
                    msg.stub[104], 0,
                    "incorrect value for stub[104], expected 0, is {}",
                    msg.stub[104]
                );
                assert_eq!(
                    msg.stub[105], 0,
                    "incorrect value for stub[105], expected 0, is {}",
                    msg.stub[105]
                );
                assert_eq!(
                    msg.stub[106], 16,
                    "incorrect value for stub[106], expected 16, is {}",
                    msg.stub[106]
                );
                assert_eq!(
                    msg.stub[107], 0,
                    "incorrect value for stub[107], expected 0, is {}",
                    msg.stub[107]
                );
                assert_eq!(
                    msg.stub[108], 0,
                    "incorrect value for stub[108], expected 0, is {}",
                    msg.stub[108]
                );
                assert_eq!(
                    msg.stub[109], 0,
                    "incorrect value for stub[109], expected 0, is {}",
                    msg.stub[109]
                );
                assert_eq!(
                    msg.stub[110], 17,
                    "incorrect value for stub[110], expected 17, is {}",
                    msg.stub[110]
                );
                assert_eq!(
                    msg.stub[111], 0,
                    "incorrect value for stub[111], expected 0, is {}",
                    msg.stub[111]
                );
                assert_eq!(
                    msg.stub[112], 0,
                    "incorrect value for stub[112], expected 0, is {}",
                    msg.stub[112]
                );
                assert_eq!(
                    msg.stub[113], 0,
                    "incorrect value for stub[113], expected 0, is {}",
                    msg.stub[113]
                );
                assert_eq!(
                    msg.stub[114], 18,
                    "incorrect value for stub[114], expected 18, is {}",
                    msg.stub[114]
                );
                assert_eq!(
                    msg.stub[115], 0,
                    "incorrect value for stub[115], expected 0, is {}",
                    msg.stub[115]
                );
                assert_eq!(
                    msg.stub[116], 0,
                    "incorrect value for stub[116], expected 0, is {}",
                    msg.stub[116]
                );
                assert_eq!(
                    msg.stub[117], 0,
                    "incorrect value for stub[117], expected 0, is {}",
                    msg.stub[117]
                );
                assert_eq!(
                    msg.stub[118], 19,
                    "incorrect value for stub[118], expected 19, is {}",
                    msg.stub[118]
                );
                assert_eq!(
                    msg.stub[119], 0,
                    "incorrect value for stub[119], expected 0, is {}",
                    msg.stub[119]
                );
                assert_eq!(
                    msg.stub[120], 0,
                    "incorrect value for stub[120], expected 0, is {}",
                    msg.stub[120]
                );
                assert_eq!(
                    msg.stub[121], 0,
                    "incorrect value for stub[121], expected 0, is {}",
                    msg.stub[121]
                );
                assert_eq!(
                    msg.stub[122], 20,
                    "incorrect value for stub[122], expected 20, is {}",
                    msg.stub[122]
                );
                assert_eq!(
                    msg.stub[123], 0,
                    "incorrect value for stub[123], expected 0, is {}",
                    msg.stub[123]
                );
            }
            _ => panic!("Invalid message type! Expected a MsgItrf"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
