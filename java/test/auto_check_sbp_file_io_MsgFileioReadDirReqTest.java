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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadDirReq.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.file_io.MsgFileioReadDirReq;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_file_io_MsgFileioReadDirReqTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_file_io_MsgFileioReadDirReqTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 130, (byte) 231, (byte) 255, (byte) 90, (byte) 196, (byte) 134,
                    (byte) 47, (byte) 134, (byte) 47, (byte) 115, (byte) 111, (byte) 109,
                    (byte) 101, (byte) 47, (byte) 114, (byte) 97, (byte) 110, (byte) 100,
                    (byte) 111, (byte) 109, (byte) 47, (byte) 112, (byte) 97, (byte) 116,
                    (byte) 104, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xa9, payload);
        MsgFileioReadDirReq msg = new MsgFileioReadDirReq(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.dirname, "/some/random/path ");
        value = msg.offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.offset + "' != '" + 2251261636L + "'",
                    value.equals(new BigInteger("2251261636")));
        } else {
            value = value.longValue();
            expected = 2251261636L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sequence + "' != '" + 1526720386 + "'",
                    value.equals(BigInteger.valueOf(1526720386L)));
        } else {
            value = value.longValue();
            expected = 1526720386L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
