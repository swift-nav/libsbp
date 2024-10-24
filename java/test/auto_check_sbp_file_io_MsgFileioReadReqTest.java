/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadReq.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.file_io.MsgFileioReadReq;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_file_io_MsgFileioReadReqTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_file_io_MsgFileioReadReqTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 34,
                    (byte) 156,
                    (byte) 130,
                    (byte) 40,
                    (byte) 98,
                    (byte) 178,
                    (byte) 190,
                    (byte) 23,
                    (byte) 53,
                    (byte) 47,
                    (byte) 112,
                    (byte) 97,
                    (byte) 116,
                    (byte) 104,
                    (byte) 47,
                    (byte) 116,
                    (byte) 111,
                    (byte) 47,
                    (byte) 115,
                    (byte) 111,
                    (byte) 109,
                    (byte) 101,
                    (byte) 47,
                    (byte) 102,
                    (byte) 105,
                    (byte) 108,
                    (byte) 101,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xa8, payload);
        MsgFileioReadReq msg = new MsgFileioReadReq(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.chunk_size;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.chunk_size + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.filename, "/path/to/some/file ");
        value = msg.offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.offset + "' != '" + 398373474 + "'",
                    value.equals(BigInteger.valueOf(398373474L)));
        } else {
            value = value.longValue();
            expected = 398373474L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sequence + "' != '" + 679648290 + "'",
                    value.equals(BigInteger.valueOf(679648290L)));
        } else {
            value = value.longValue();
            expected = 679648290L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
