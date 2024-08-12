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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepB.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.tracking.MsgTrackingIqDepB;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_tracking_MsgTrackingIqDepBTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingIqDepBTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 45,
                    (byte) 188,
                    (byte) 183,
                    (byte) 72,
                    (byte) 185,
                    (byte) 157,
                    (byte) 15,
                    (byte) 187,
                    (byte) 249,
                    (byte) 101,
                    (byte) 24,
                    (byte) 135,
                    (byte) 146,
                    (byte) 180,
                    (byte) 224,
                    (byte) 123,
                    (byte) 235,
                    (byte) 142,
                    (byte) 208,
                    (byte) 102,
                    (byte) 112,
                    (byte) 25,
                    (byte) 21,
                    (byte) 177,
                    (byte) 96,
                    (byte) 116,
                    (byte) 68,
                };
        SBPMessage sbp = new SBPMessage(0x6527, 0x2c, payload);
        MsgTrackingIqDepB msg = new MsgTrackingIqDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.channel;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.channel + "' != '" + 45 + "'", value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[0].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[0].I + "' != '" + 261994824 + "'",
                    value.equals(BigInteger.valueOf(261994824L)));
        } else {
            value = value.longValue();
            expected = 261994824L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[0].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[0].Q + "' != '" + 409336251 + "'",
                    value.equals(BigInteger.valueOf(409336251L)));
        } else {
            value = value.longValue();
            expected = 409336251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[1].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[1].I + "' != '" + -525036921 + "'",
                    value.equals(BigInteger.valueOf(-525036921L)));
        } else {
            value = value.longValue();
            expected = -525036921L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[1].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[1].Q + "' != '" + -795939973 + "'",
                    value.equals(BigInteger.valueOf(-795939973L)));
        } else {
            value = value.longValue();
            expected = -795939973L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[2].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[2].I + "' != '" + 353988710 + "'",
                    value.equals(BigInteger.valueOf(353988710L)));
        } else {
            value = value.longValue();
            expected = 353988710L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[2].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corrs[2].Q + "' != '" + 1148477617 + "'",
                    value.equals(BigInteger.valueOf(1148477617L)));
        } else {
            value = value.longValue();
            expected = 1148477617L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
