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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineHeadingDepA.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgBaselineHeadingDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgBaselineHeadingDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_navigation_MsgBaselineHeadingDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 82,
                    (byte) 109,
                    (byte) 88,
                    (byte) 176,
                    (byte) 68,
                    (byte) 14,
                    (byte) 82,
                    (byte) 203,
                    (byte) 186,
                    (byte) 58,
                };
        SBPMessage sbp = new SBPMessage(0xce7c, 0x207, payload);
        MsgBaselineHeadingDepA msg = new MsgBaselineHeadingDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 58 + "'", value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.heading;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.heading + "' != '" + 3411152452L + "'",
                    value.equals(new BigInteger("3411152452")));
        } else {
            value = value.longValue();
            expected = 3411152452L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2958585170L + "'",
                    value.equals(new BigInteger("2958585170")));
        } else {
            value = value.longValue();
            expected = 2958585170L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
