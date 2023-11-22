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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevelDepA.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgProtectionLevelDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgProtectionLevelDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_navigation_MsgProtectionLevelDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 52,
                    (byte) 126,
                    (byte) 69,
                    (byte) 185,
                    (byte) 47,
                    (byte) 85,
                    (byte) 4,
                    (byte) 139,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 244,
                    (byte) 190,
                    (byte) 64,
                    (byte) 102,
                    (byte) 102,
                    (byte) 102,
                    (byte) 102,
                    (byte) 102,
                    (byte) 204,
                    (byte) 168,
                    (byte) 64,
                    (byte) 154,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 25,
                    (byte) 39,
                    (byte) 192,
                    (byte) 64,
                    (byte) 248,
                };
        SBPMessage sbp = new SBPMessage(0x1694, 0x216, payload);
        MsgProtectionLevelDepA msg = new MsgProtectionLevelDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 248 + "'", value.equals(BigInteger.valueOf(248L)));
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.height, 8.27020000000000073e+03, DELTA);
        value = msg.hpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hpl + "' != '" + 35588 + "'",
                    value.equals(BigInteger.valueOf(35588L)));
        } else {
            value = value.longValue();
            expected = 35588L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.lat, 7.92419999999999982e+03, DELTA);
        org.junit.Assert.assertEquals(msg.lon, 3.17419999999999982e+03, DELTA);
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 3108339252L + "'",
                    value.equals(new BigInteger("3108339252")));
        } else {
            value = value.longValue();
            expected = 3108339252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vpl + "' != '" + 21807 + "'",
                    value.equals(BigInteger.valueOf(21807L)));
        } else {
            value = value.longValue();
            expected = 21807L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
