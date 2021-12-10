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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgBaselineNED;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgBaselineNEDTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineNEDTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 40,
                    (byte) 244,
                    (byte) 122,
                    (byte) 19,
                    (byte) 201,
                    (byte) 115,
                    (byte) 12,
                    (byte) 0,
                    (byte) 179,
                    (byte) 88,
                    (byte) 230,
                    (byte) 255,
                    (byte) 153,
                    (byte) 125,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20c, payload);
        MsgBaselineNED msg = new MsgBaselineNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + 32153 + "'", value.equals(BigInteger.valueOf(32153L)));
        } else {
            value = value.longValue();
            expected = 32153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -1681229 + "'",
                    value.equals(BigInteger.valueOf(-1681229L)));
        } else {
            value = value.longValue();
            expected = -1681229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.h_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.h_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + 816073 + "'",
                    value.equals(BigInteger.valueOf(816073L)));
        } else {
            value = value.longValue();
            expected = 816073L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326825000 + "'",
                    value.equals(BigInteger.valueOf(326825000L)));
        } else {
            value = value.longValue();
            expected = 326825000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineNEDTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 16,
                    (byte) 248,
                    (byte) 122,
                    (byte) 19,
                    (byte) 98,
                    (byte) 115,
                    (byte) 12,
                    (byte) 0,
                    (byte) 194,
                    (byte) 88,
                    (byte) 230,
                    (byte) 255,
                    (byte) 110,
                    (byte) 127,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20c, payload);
        MsgBaselineNED msg = new MsgBaselineNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + 32622 + "'", value.equals(BigInteger.valueOf(32622L)));
        } else {
            value = value.longValue();
            expected = 32622L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -1681214 + "'",
                    value.equals(BigInteger.valueOf(-1681214L)));
        } else {
            value = value.longValue();
            expected = -1681214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.h_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.h_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + 815970 + "'",
                    value.equals(BigInteger.valueOf(815970L)));
        } else {
            value = value.longValue();
            expected = 815970L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326826000 + "'",
                    value.equals(BigInteger.valueOf(326826000L)));
        } else {
            value = value.longValue();
            expected = 326826000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineNEDTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 248,
                    (byte) 251,
                    (byte) 122,
                    (byte) 19,
                    (byte) 143,
                    (byte) 114,
                    (byte) 12,
                    (byte) 0,
                    (byte) 173,
                    (byte) 88,
                    (byte) 230,
                    (byte) 255,
                    (byte) 238,
                    (byte) 127,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20c, payload);
        MsgBaselineNED msg = new MsgBaselineNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + 32750 + "'", value.equals(BigInteger.valueOf(32750L)));
        } else {
            value = value.longValue();
            expected = 32750L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -1681235 + "'",
                    value.equals(BigInteger.valueOf(-1681235L)));
        } else {
            value = value.longValue();
            expected = -1681235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.h_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.h_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + 815759 + "'",
                    value.equals(BigInteger.valueOf(815759L)));
        } else {
            value = value.longValue();
            expected = 815759L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326827000 + "'",
                    value.equals(BigInteger.valueOf(326827000L)));
        } else {
            value = value.longValue();
            expected = 326827000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineNEDTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 224,
                    (byte) 255,
                    (byte) 122,
                    (byte) 19,
                    (byte) 86,
                    (byte) 112,
                    (byte) 12,
                    (byte) 0,
                    (byte) 51,
                    (byte) 88,
                    (byte) 230,
                    (byte) 255,
                    (byte) 47,
                    (byte) 127,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20c, payload);
        MsgBaselineNED msg = new MsgBaselineNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + 32559 + "'", value.equals(BigInteger.valueOf(32559L)));
        } else {
            value = value.longValue();
            expected = 32559L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -1681357 + "'",
                    value.equals(BigInteger.valueOf(-1681357L)));
        } else {
            value = value.longValue();
            expected = -1681357L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.h_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.h_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + 815190 + "'",
                    value.equals(BigInteger.valueOf(815190L)));
        } else {
            value = value.longValue();
            expected = 815190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326828000 + "'",
                    value.equals(BigInteger.valueOf(326828000L)));
        } else {
            value = value.longValue();
            expected = 326828000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineNEDTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 200,
                    (byte) 3,
                    (byte) 123,
                    (byte) 19,
                    (byte) 214,
                    (byte) 110,
                    (byte) 12,
                    (byte) 0,
                    (byte) 220,
                    (byte) 87,
                    (byte) 230,
                    (byte) 255,
                    (byte) 165,
                    (byte) 126,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20c, payload);
        MsgBaselineNED msg = new MsgBaselineNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + 32421 + "'", value.equals(BigInteger.valueOf(32421L)));
        } else {
            value = value.longValue();
            expected = 32421L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -1681444 + "'",
                    value.equals(BigInteger.valueOf(-1681444L)));
        } else {
            value = value.longValue();
            expected = -1681444L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.h_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.h_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + 814806 + "'",
                    value.equals(BigInteger.valueOf(814806L)));
        } else {
            value = value.longValue();
            expected = 814806L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326829000 + "'",
                    value.equals(BigInteger.valueOf(326829000L)));
        } else {
            value = value.longValue();
            expected = 326829000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
