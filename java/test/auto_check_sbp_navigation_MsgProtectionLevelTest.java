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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgProtectionLevel;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgProtectionLevelTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgProtectionLevelTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 110,
                    (byte) 84,
                    (byte) 4,
                    (byte) 242,
                    (byte) 46,
                    (byte) 51,
                    (byte) 53,
                    (byte) 160,
                    (byte) 89,
                    (byte) 84,
                    (byte) 167,
                    (byte) 41,
                    (byte) 57,
                    (byte) 21,
                    (byte) 217,
                    (byte) 244,
                    (byte) 61,
                    (byte) 161,
                    (byte) 83,
                    (byte) 104,
                    (byte) 140,
                    (byte) 137,
                    (byte) 90,
                    (byte) 246,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 170,
                    (byte) 180,
                    (byte) 64,
                    (byte) 154,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 25,
                    (byte) 88,
                    (byte) 195,
                    (byte) 64,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 51,
                    (byte) 195,
                    (byte) 121,
                    (byte) 64,
                    (byte) 231,
                    (byte) 251,
                    (byte) 38,
                    (byte) 221,
                    (byte) 208,
                    (byte) 183,
                    (byte) 167,
                    (byte) 80,
                    (byte) 223,
                    (byte) 26,
                    (byte) 97,
                    (byte) 164,
                    (byte) 45,
                    (byte) 46,
                    (byte) 186,
                    (byte) 60,
                    (byte) 235,
                    (byte) 227,
                    (byte) 183,
                    (byte) 160,
                    (byte) 187,
                    (byte) 93,
                    (byte) 116,
                    (byte) 224,
                    (byte) 105,
                    (byte) 40,
                    (byte) 32,
                    (byte) 33,
                };
        SBPMessage sbp = new SBPMessage(0x032d, 0x217, payload);
        MsgProtectionLevel msg = new MsgProtectionLevel(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.atpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.atpl + "' != '" + 10663 + "'",
                    value.equals(BigInteger.valueOf(10663L)));
        } else {
            value = value.longValue();
            expected = 10663L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ctpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ctpl + "' != '" + 5433 + "'",
                    value.equals(BigInteger.valueOf(5433L)));
        } else {
            value = value.longValue();
            expected = 5433L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 555755625 + "'",
                    value.equals(BigInteger.valueOf(555755625L)));
        } else {
            value = value.longValue();
            expected = 555755625L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.heading;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.heading + "' != '" + -529244741 + "'",
                    value.equals(BigInteger.valueOf(-529244741L)));
        } else {
            value = value.longValue();
            expected = -529244741L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.height, 4.12199999999999989e+02, DELTA);
        value = msg.hopl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hopl + "' != '" + 26707 + "'",
                    value.equals(BigInteger.valueOf(26707L)));
        } else {
            value = value.longValue();
            expected = 26707L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hpl + "' != '" + 41013 + "'",
                    value.equals(BigInteger.valueOf(41013L)));
        } else {
            value = value.longValue();
            expected = 41013L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hvpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hvpl + "' != '" + 62681 + "'",
                    value.equals(BigInteger.valueOf(62681L)));
        } else {
            value = value.longValue();
            expected = 62681L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.lat, 5.29019999999999982e+03, DELTA);
        org.junit.Assert.assertEquals(msg.lon, 9.90420000000000073e+03, DELTA);
        value = msg.pitch;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pitch + "' != '" + -1598561301 + "'",
                    value.equals(BigInteger.valueOf(-1598561301L)));
        } else {
            value = value.longValue();
            expected = -1598561301L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.popl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.popl + "' != '" + 35212 + "'",
                    value.equals(BigInteger.valueOf(35212L)));
        } else {
            value = value.longValue();
            expected = 35212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.roll;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.roll + "' != '" + 1018834477 + "'",
                    value.equals(BigInteger.valueOf(1018834477L)));
        } else {
            value = value.longValue();
            expected = 1018834477L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ropl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ropl + "' != '" + 63066 + "'",
                    value.equals(BigInteger.valueOf(63066L)));
        } else {
            value = value.longValue();
            expected = 63066L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 4060370030L + "'",
                    value.equals(new BigInteger("4060370030")));
        } else {
            value = value.longValue();
            expected = 4060370030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_x + "' != '" + -584647705 + "'",
                    value.equals(BigInteger.valueOf(-584647705L)));
        } else {
            value = value.longValue();
            expected = -584647705L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_y + "' != '" + 1353168848 + "'",
                    value.equals(BigInteger.valueOf(1353168848L)));
        } else {
            value = value.longValue();
            expected = 1353168848L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_z + "' != '" + -1537140001 + "'",
                    value.equals(BigInteger.valueOf(-1537140001L)));
        } else {
            value = value.longValue();
            expected = -1537140001L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vpl + "' != '" + 21593 + "'",
                    value.equals(BigInteger.valueOf(21593L)));
        } else {
            value = value.longValue();
            expected = 21593L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vvpl;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vvpl + "' != '" + 41277 + "'",
                    value.equals(BigInteger.valueOf(41277L)));
        } else {
            value = value.longValue();
            expected = 41277L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 13102 + "'",
                    value.equals(BigInteger.valueOf(13102L)));
        } else {
            value = value.longValue();
            expected = 13102L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
