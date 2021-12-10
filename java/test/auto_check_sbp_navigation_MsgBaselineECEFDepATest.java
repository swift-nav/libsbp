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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgBaselineECEFDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgBaselineECEFDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 20,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 21,
                    (byte) 48,
                    (byte) 255,
                    (byte) 255,
                    (byte) 52,
                    (byte) 117,
                    (byte) 255,
                    (byte) 255,
                    (byte) 216,
                    (byte) 211,
                    (byte) 254,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2567700 + "'",
                    value.equals(BigInteger.valueOf(2567700L)));
        } else {
            value = value.longValue();
            expected = 2567700L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -53227 + "'",
                    value.equals(BigInteger.valueOf(-53227L)));
        } else {
            value = value.longValue();
            expected = -53227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -35532 + "'",
                    value.equals(BigInteger.valueOf(-35532L)));
        } else {
            value = value.longValue();
            expected = -35532L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + -76840 + "'",
                    value.equals(BigInteger.valueOf(-76840L)));
        } else {
            value = value.longValue();
            expected = -76840L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 120,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 58,
                    (byte) 49,
                    (byte) 255,
                    (byte) 255,
                    (byte) 49,
                    (byte) 116,
                    (byte) 255,
                    (byte) 255,
                    (byte) 134,
                    (byte) 211,
                    (byte) 254,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2567800 + "'",
                    value.equals(BigInteger.valueOf(2567800L)));
        } else {
            value = value.longValue();
            expected = 2567800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -52934 + "'",
                    value.equals(BigInteger.valueOf(-52934L)));
        } else {
            value = value.longValue();
            expected = -52934L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -35791 + "'",
                    value.equals(BigInteger.valueOf(-35791L)));
        } else {
            value = value.longValue();
            expected = -35791L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + -76922 + "'",
                    value.equals(BigInteger.valueOf(-76922L)));
        } else {
            value = value.longValue();
            expected = -76922L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 220,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 97,
                    (byte) 50,
                    (byte) 255,
                    (byte) 255,
                    (byte) 47,
                    (byte) 115,
                    (byte) 255,
                    (byte) 255,
                    (byte) 52,
                    (byte) 211,
                    (byte) 254,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2567900 + "'",
                    value.equals(BigInteger.valueOf(2567900L)));
        } else {
            value = value.longValue();
            expected = 2567900L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -52639 + "'",
                    value.equals(BigInteger.valueOf(-52639L)));
        } else {
            value = value.longValue();
            expected = -52639L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -36049 + "'",
                    value.equals(BigInteger.valueOf(-36049L)));
        } else {
            value = value.longValue();
            expected = -36049L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + -77004 + "'",
                    value.equals(BigInteger.valueOf(-77004L)));
        } else {
            value = value.longValue();
            expected = -77004L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 64,
                    (byte) 47,
                    (byte) 39,
                    (byte) 0,
                    (byte) 136,
                    (byte) 51,
                    (byte) 255,
                    (byte) 255,
                    (byte) 45,
                    (byte) 114,
                    (byte) 255,
                    (byte) 255,
                    (byte) 228,
                    (byte) 210,
                    (byte) 254,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2568000 + "'",
                    value.equals(BigInteger.valueOf(2568000L)));
        } else {
            value = value.longValue();
            expected = 2568000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -52344 + "'",
                    value.equals(BigInteger.valueOf(-52344L)));
        } else {
            value = value.longValue();
            expected = -52344L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -36307 + "'",
                    value.equals(BigInteger.valueOf(-36307L)));
        } else {
            value = value.longValue();
            expected = -36307L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + -77084 + "'",
                    value.equals(BigInteger.valueOf(-77084L)));
        } else {
            value = value.longValue();
            expected = -77084L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 164,
                    (byte) 47,
                    (byte) 39,
                    (byte) 0,
                    (byte) 176,
                    (byte) 52,
                    (byte) 255,
                    (byte) 255,
                    (byte) 44,
                    (byte) 113,
                    (byte) 255,
                    (byte) 255,
                    (byte) 149,
                    (byte) 210,
                    (byte) 254,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2568100 + "'",
                    value.equals(BigInteger.valueOf(2568100L)));
        } else {
            value = value.longValue();
            expected = 2568100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -52048 + "'",
                    value.equals(BigInteger.valueOf(-52048L)));
        } else {
            value = value.longValue();
            expected = -52048L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -36564 + "'",
                    value.equals(BigInteger.valueOf(-36564L)));
        } else {
            value = value.longValue();
            expected = -36564L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + -77163 + "'",
                    value.equals(BigInteger.valueOf(-77163L)));
        } else {
            value = value.longValue();
            expected = -77163L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 156,
                    (byte) 21,
                    (byte) 69,
                    (byte) 24,
                    (byte) 169,
                    (byte) 231,
                    (byte) 255,
                    (byte) 255,
                    (byte) 102,
                    (byte) 208,
                    (byte) 255,
                    (byte) 255,
                    (byte) 251,
                    (byte) 28,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407180700 + "'",
                    value.equals(BigInteger.valueOf(407180700L)));
        } else {
            value = value.longValue();
            expected = 407180700L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -6231 + "'", value.equals(BigInteger.valueOf(-6231L)));
        } else {
            value = value.longValue();
            expected = -6231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -12186 + "'",
                    value.equals(BigInteger.valueOf(-12186L)));
        } else {
            value = value.longValue();
            expected = -12186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 7419 + "'", value.equals(BigInteger.valueOf(7419L)));
        } else {
            value = value.longValue();
            expected = 7419L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test7() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 22,
                    (byte) 69,
                    (byte) 24,
                    (byte) 169,
                    (byte) 231,
                    (byte) 255,
                    (byte) 255,
                    (byte) 103,
                    (byte) 208,
                    (byte) 255,
                    (byte) 255,
                    (byte) 252,
                    (byte) 28,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407180800 + "'",
                    value.equals(BigInteger.valueOf(407180800L)));
        } else {
            value = value.longValue();
            expected = 407180800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -6231 + "'", value.equals(BigInteger.valueOf(-6231L)));
        } else {
            value = value.longValue();
            expected = -6231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -12185 + "'",
                    value.equals(BigInteger.valueOf(-12185L)));
        } else {
            value = value.longValue();
            expected = -12185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 7420 + "'", value.equals(BigInteger.valueOf(7420L)));
        } else {
            value = value.longValue();
            expected = 7420L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test8() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test8");
        byte[] payload =
                new byte[] {
                    (byte) 100,
                    (byte) 22,
                    (byte) 69,
                    (byte) 24,
                    (byte) 30,
                    (byte) 224,
                    (byte) 255,
                    (byte) 255,
                    (byte) 192,
                    (byte) 183,
                    (byte) 255,
                    (byte) 255,
                    (byte) 239,
                    (byte) 53,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407180900 + "'",
                    value.equals(BigInteger.valueOf(407180900L)));
        } else {
            value = value.longValue();
            expected = 407180900L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -8162 + "'", value.equals(BigInteger.valueOf(-8162L)));
        } else {
            value = value.longValue();
            expected = -8162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -18496 + "'",
                    value.equals(BigInteger.valueOf(-18496L)));
        } else {
            value = value.longValue();
            expected = -18496L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 13807 + "'", value.equals(BigInteger.valueOf(13807L)));
        } else {
            value = value.longValue();
            expected = 13807L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test9() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test9");
        byte[] payload =
                new byte[] {
                    (byte) 200,
                    (byte) 22,
                    (byte) 69,
                    (byte) 24,
                    (byte) 28,
                    (byte) 224,
                    (byte) 255,
                    (byte) 255,
                    (byte) 191,
                    (byte) 183,
                    (byte) 255,
                    (byte) 255,
                    (byte) 242,
                    (byte) 53,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407181000 + "'",
                    value.equals(BigInteger.valueOf(407181000L)));
        } else {
            value = value.longValue();
            expected = 407181000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -8164 + "'", value.equals(BigInteger.valueOf(-8164L)));
        } else {
            value = value.longValue();
            expected = -8164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -18497 + "'",
                    value.equals(BigInteger.valueOf(-18497L)));
        } else {
            value = value.longValue();
            expected = -18497L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 13810 + "'", value.equals(BigInteger.valueOf(13810L)));
        } else {
            value = value.longValue();
            expected = 13810L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test10() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test10");
        byte[] payload =
                new byte[] {
                    (byte) 44,
                    (byte) 23,
                    (byte) 69,
                    (byte) 24,
                    (byte) 24,
                    (byte) 227,
                    (byte) 255,
                    (byte) 255,
                    (byte) 25,
                    (byte) 195,
                    (byte) 255,
                    (byte) 255,
                    (byte) 153,
                    (byte) 59,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407181100 + "'",
                    value.equals(BigInteger.valueOf(407181100L)));
        } else {
            value = value.longValue();
            expected = 407181100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -7400 + "'", value.equals(BigInteger.valueOf(-7400L)));
        } else {
            value = value.longValue();
            expected = -7400L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -15591 + "'",
                    value.equals(BigInteger.valueOf(-15591L)));
        } else {
            value = value.longValue();
            expected = -15591L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 15257 + "'", value.equals(BigInteger.valueOf(15257L)));
        } else {
            value = value.longValue();
            expected = 15257L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test11() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFDepATest.test11");
        byte[] payload =
                new byte[] {
                    (byte) 144,
                    (byte) 23,
                    (byte) 69,
                    (byte) 24,
                    (byte) 23,
                    (byte) 227,
                    (byte) 255,
                    (byte) 255,
                    (byte) 25,
                    (byte) 195,
                    (byte) 255,
                    (byte) 255,
                    (byte) 153,
                    (byte) 59,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x202, payload);
        MsgBaselineECEFDepA msg = new MsgBaselineECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407181200 + "'",
                    value.equals(BigInteger.valueOf(407181200L)));
        } else {
            value = value.longValue();
            expected = 407181200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -7401 + "'", value.equals(BigInteger.valueOf(-7401L)));
        } else {
            value = value.longValue();
            expected = -7401L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -15591 + "'",
                    value.equals(BigInteger.valueOf(-15591L)));
        } else {
            value = value.longValue();
            expected = -15591L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 15257 + "'", value.equals(BigInteger.valueOf(15257L)));
        } else {
            value = value.longValue();
            expected = 15257L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
