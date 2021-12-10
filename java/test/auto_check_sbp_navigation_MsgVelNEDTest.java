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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgVelNED;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgVelNEDTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNEDTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 40,
                    (byte) 244,
                    (byte) 122,
                    (byte) 19,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 252,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 243,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20e, payload);
        MsgVelNED msg = new MsgVelNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + -13 + "'", value.equals(BigInteger.valueOf(-13L)));
        } else {
            value = value.longValue();
            expected = -13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -4 + "'", value.equals(BigInteger.valueOf(-4L)));
        } else {
            value = value.longValue();
            expected = -4L;
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
                    "'" + msg.n + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNEDTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 28,
                    (byte) 246,
                    (byte) 122,
                    (byte) 19,
                    (byte) 252,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 232,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20e, payload);
        MsgVelNED msg = new MsgVelNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + -24 + "'", value.equals(BigInteger.valueOf(-24L)));
        } else {
            value = value.longValue();
            expected = -24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -1 + "'", value.equals(BigInteger.valueOf(-1L)));
        } else {
            value = value.longValue();
            expected = -1L;
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
                    "'" + msg.n + "' != '" + -4 + "'", value.equals(BigInteger.valueOf(-4L)));
        } else {
            value = value.longValue();
            expected = -4L;
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
                    "'" + msg.tow + "' != '" + 326825500 + "'",
                    value.equals(BigInteger.valueOf(326825500L)));
        } else {
            value = value.longValue();
            expected = 326825500L;
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNEDTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 16,
                    (byte) 248,
                    (byte) 122,
                    (byte) 19,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 253,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 244,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20e, payload);
        MsgVelNED msg = new MsgVelNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + -12 + "'", value.equals(BigInteger.valueOf(-12L)));
        } else {
            value = value.longValue();
            expected = -12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + -3 + "'", value.equals(BigInteger.valueOf(-3L)));
        } else {
            value = value.longValue();
            expected = -3L;
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
                    "'" + msg.n + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
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
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNEDTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 4, (byte) 250, (byte) 122, (byte) 19, (byte) 2, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 3, (byte) 0, (byte) 0, (byte) 0, (byte) 232, (byte) 255,
                    (byte) 255, (byte) 255, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20e, payload);
        MsgVelNED msg = new MsgVelNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + -24 + "'", value.equals(BigInteger.valueOf(-24L)));
        } else {
            value = value.longValue();
            expected = -24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
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
                    "'" + msg.n + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
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
                    "'" + msg.tow + "' != '" + 326826500 + "'",
                    value.equals(BigInteger.valueOf(326826500L)));
        } else {
            value = value.longValue();
            expected = 326826500L;
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNEDTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 248, (byte) 251, (byte) 122, (byte) 19, (byte) 1, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 235, (byte) 255,
                    (byte) 255, (byte) 255, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20e, payload);
        MsgVelNED msg = new MsgVelNED(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + -21 + "'", value.equals(BigInteger.valueOf(-21L)));
        } else {
            value = value.longValue();
            expected = -21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
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
                    "'" + msg.n + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
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
}
