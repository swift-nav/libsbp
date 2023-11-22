/* Copyright (C) 2015-2022 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGnssTimeOffset.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.system.MsgGnssTimeOffset;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_system_MsgGnssTimeOffsetTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgGnssTimeOffsetTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 9,
                    (byte) 58,
                    (byte) 82,
                    (byte) 83,
                    (byte) 9,
                    (byte) 103,
                    (byte) 22,
                    (byte) 37,
                    (byte) 221,
                };
        SBPMessage sbp = new SBPMessage(0x0f16, 0xff07, payload);
        MsgGnssTimeOffset msg = new MsgGnssTimeOffset(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 221 + "'", value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.microseconds;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.microseconds + "' != '" + 9494 + "'",
                    value.equals(BigInteger.valueOf(9494L)));
        } else {
            value = value.longValue();
            expected = 9494L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.milliseconds;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.milliseconds + "' != '" + 1728664402 + "'",
                    value.equals(BigInteger.valueOf(1728664402L)));
        } else {
            value = value.longValue();
            expected = 1728664402L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.weeks;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.weeks + "' != '" + 14857 + "'",
                    value.equals(BigInteger.valueOf(14857L)));
        } else {
            value = value.longValue();
            expected = 14857L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
