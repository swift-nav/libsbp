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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClockDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrOrbitClockDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrOrbitClockDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 225,
                    (byte) 114,
                    (byte) 31,
                    (byte) 189,
                    (byte) 43,
                    (byte) 30,
                    (byte) 1,
                    (byte) 30,
                    (byte) 194,
                    (byte) 211,
                    (byte) 193,
                    (byte) 175,
                    (byte) 161,
                    (byte) 143,
                    (byte) 254,
                    (byte) 56,
                    (byte) 63,
                    (byte) 232,
                    (byte) 7,
                    (byte) 216,
                    (byte) 69,
                    (byte) 1,
                    (byte) 110,
                    (byte) 165,
                    (byte) 124,
                    (byte) 196,
                    (byte) 189,
                    (byte) 27,
                    (byte) 116,
                    (byte) 88,
                    (byte) 4,
                    (byte) 61,
                    (byte) 3,
                    (byte) 151,
                    (byte) 18,
                    (byte) 171,
                    (byte) 147,
                    (byte) 46,
                    (byte) 198,
                    (byte) 85,
                    (byte) 243,
                    (byte) 245,
                    (byte) 225,
                    (byte) 235,
                    (byte) 123,
                    (byte) 181,
                    (byte) 210,
                };
        SBPMessage sbp = new SBPMessage(0xa621, 0x5dc, payload);
        MsgSsrOrbitClockDepA msg = new MsgSsrOrbitClockDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.along;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.along + "' != '" + 132661048 + "'",
                    value.equals(BigInteger.valueOf(132661048L)));
        } else {
            value = value.longValue();
            expected = 132661048L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.c0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.c0 + "' != '" + -970026069 + "'",
                    value.equals(BigInteger.valueOf(-970026069L)));
        } else {
            value = value.longValue();
            expected = -970026069L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.c1;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.c1 + "' != '" + -503975083 + "'",
                    value.equals(BigInteger.valueOf(-503975083L)));
        } else {
            value = value.longValue();
            expected = -503975083L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.c2;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.c2 + "' != '" + -759858197 + "'",
                    value.equals(BigInteger.valueOf(-759858197L)));
        } else {
            value = value.longValue();
            expected = -759858197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cross;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cross + "' != '" + 1845577176 + "'",
                    value.equals(BigInteger.valueOf(1845577176L)));
        } else {
            value = value.longValue();
            expected = 1845577176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_along;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_along + "' != '" + 72905755 + "'",
                    value.equals(BigInteger.valueOf(72905755L)));
        } else {
            value = value.longValue();
            expected = 72905755L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_cross;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_cross + "' != '" + 311886653 + "'",
                    value.equals(BigInteger.valueOf(311886653L)));
        } else {
            value = value.longValue();
            expected = 311886653L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_radial;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_radial + "' != '" + -1111196507 + "'",
                    value.equals(BigInteger.valueOf(-1111196507L)));
        } else {
            value = value.longValue();
            expected = -1111196507L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iod + "' != '" + 193 + "'", value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod_ssr;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iod_ssr + "' != '" + 211 + "'",
                    value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.radial;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.radial + "' != '" + -24141393 + "'",
                    value.equals(BigInteger.valueOf(-24141393L)));
        } else {
            value = value.longValue();
            expected = -24141393L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.tow + "' != '" + 3172954849L + "'",
                    value.equals(new BigInteger("3172954849")));
        } else {
            value = value.longValue();
            expected = 3172954849L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.wn + "' != '" + 7723 + "'",
                    value.equals(BigInteger.valueOf(7723L)));
        } else {
            value = value.longValue();
            expected = 7723L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.update_interval + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
