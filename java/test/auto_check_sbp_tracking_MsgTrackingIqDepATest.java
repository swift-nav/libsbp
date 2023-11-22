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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepA.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.tracking.MsgTrackingIqDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_tracking_MsgTrackingIqDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingIqDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 139, (byte) 28, (byte) 250, (byte) 15, (byte) 0, (byte) 99, (byte) 90,
                    (byte) 170, (byte) 96, (byte) 71, (byte) 121, (byte) 33, (byte) 161, (byte) 52,
                    (byte) 211, (byte) 162, (byte) 101, (byte) 41, (byte) 36, (byte) 226, (byte) 99,
                    (byte) 71, (byte) 75, (byte) 14, (byte) 240, (byte) 134, (byte) 82, (byte) 175,
                    (byte) 83,
                };
        SBPMessage sbp = new SBPMessage(0x43b8, 0x1c, payload);
        MsgTrackingIqDepA msg = new MsgTrackingIqDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.channel;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.channel + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[0].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[0].I + "' != '" + 1621776995 + "'",
                    value.equals(BigInteger.valueOf(1621776995L)));
        } else {
            value = value.longValue();
            expected = 1621776995L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[0].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[0].Q + "' != '" + -1591641785 + "'",
                    value.equals(BigInteger.valueOf(-1591641785L)));
        } else {
            value = value.longValue();
            expected = -1591641785L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[1].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[1].I + "' != '" + 1705169716 + "'",
                    value.equals(BigInteger.valueOf(1705169716L)));
        } else {
            value = value.longValue();
            expected = 1705169716L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[1].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[1].Q + "' != '" + 1675764777 + "'",
                    value.equals(BigInteger.valueOf(1675764777L)));
        } else {
            value = value.longValue();
            expected = 1675764777L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[2].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[2].I + "' != '" + -267498681 + "'",
                    value.equals(BigInteger.valueOf(-267498681L)));
        } else {
            value = value.longValue();
            expected = -267498681L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[2].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[2].Q + "' != '" + 1403998854 + "'",
                    value.equals(BigInteger.valueOf(1403998854L)));
        } else {
            value = value.longValue();
            expected = 1403998854L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 64028 + "'",
                    value.equals(BigInteger.valueOf(64028L)));
        } else {
            value = value.longValue();
            expected = 64028L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
