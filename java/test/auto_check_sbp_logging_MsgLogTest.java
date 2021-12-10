/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgLog.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.logging.MsgLog;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_logging_MsgLogTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgLogTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 6,
                    (byte) 70,
                    (byte) 105,
                    (byte) 108,
                    (byte) 116,
                    (byte) 101,
                    (byte) 114,
                    (byte) 101,
                    (byte) 100,
                    (byte) 32,
                    (byte) 97,
                    (byte) 108,
                    (byte) 108,
                    (byte) 32,
                    (byte) 111,
                    (byte) 98,
                    (byte) 115,
                    (byte) 32,
                    (byte) 102,
                    (byte) 114,
                    (byte) 111,
                    (byte) 109,
                    (byte) 32,
                    (byte) 50,
                    (byte) 51,
                    (byte) 49,
                    (byte) 52,
                    (byte) 32,
                    (byte) 97,
                    (byte) 116,
                    (byte) 32,
                    (byte) 116,
                    (byte) 111,
                    (byte) 119,
                    (byte) 32,
                    (byte) 56,
                    (byte) 51,
                    (byte) 46,
                    (byte) 53,
                    (byte) 51,
                    (byte) 57,
                    (byte) 48,
                    (byte) 49,
                    (byte) 57,
                };
        SBPMessage sbp = new SBPMessage(0x90a, 0x0401, payload);
        MsgLog msg = new MsgLog(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.level + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.text, "Filtered all obs from 2314 at tow 83.539019");
    }
}
