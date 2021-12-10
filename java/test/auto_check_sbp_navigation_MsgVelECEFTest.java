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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgVelECEF;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgVelECEFTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelECEFTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 40,
                    (byte) 244,
                    (byte) 122,
                    (byte) 19,
                    (byte) 248,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 251,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20d, payload);
        MsgVelECEF msg = new MsgVelECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -8 + "'", value.equals(BigInteger.valueOf(-8L)));
        } else {
            value = value.longValue();
            expected = -8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -5 + "'", value.equals(BigInteger.valueOf(-5L)));
        } else {
            value = value.longValue();
            expected = -5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 10 + "'", value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelECEFTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 28,
                    (byte) 246,
                    (byte) 122,
                    (byte) 19,
                    (byte) 244,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 238,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 11,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20d, payload);
        MsgVelECEF msg = new MsgVelECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -12 + "'", value.equals(BigInteger.valueOf(-12L)));
        } else {
            value = value.longValue();
            expected = -12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -18 + "'", value.equals(BigInteger.valueOf(-18L)));
        } else {
            value = value.longValue();
            expected = -18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 11 + "'", value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelECEFTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 16,
                    (byte) 248,
                    (byte) 122,
                    (byte) 19,
                    (byte) 248,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 250,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20d, payload);
        MsgVelECEF msg = new MsgVelECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -8 + "'", value.equals(BigInteger.valueOf(-8L)));
        } else {
            value = value.longValue();
            expected = -8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -6 + "'", value.equals(BigInteger.valueOf(-6L)));
        } else {
            value = value.longValue();
            expected = -6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 7 + "'", value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelECEFTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 4, (byte) 250, (byte) 122, (byte) 19, (byte) 249, (byte) 255, (byte) 255,
                    (byte) 255, (byte) 239, (byte) 255, (byte) 255, (byte) 255, (byte) 16, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20d, payload);
        MsgVelECEF msg = new MsgVelECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -7 + "'", value.equals(BigInteger.valueOf(-7L)));
        } else {
            value = value.longValue();
            expected = -7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -17 + "'", value.equals(BigInteger.valueOf(-17L)));
        } else {
            value = value.longValue();
            expected = -17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 16 + "'", value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelECEFTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 248,
                    (byte) 251,
                    (byte) 122,
                    (byte) 19,
                    (byte) 247,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 243,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 14,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20d, payload);
        MsgVelECEF msg = new MsgVelECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -9 + "'", value.equals(BigInteger.valueOf(-9L)));
        } else {
            value = value.longValue();
            expected = -9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -13 + "'", value.equals(BigInteger.valueOf(-13L)));
        } else {
            value = value.longValue();
            expected = -13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
