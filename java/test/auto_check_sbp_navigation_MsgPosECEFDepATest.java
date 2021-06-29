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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosECEFDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosECEFDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 20, (byte) 46, (byte) 39, (byte) 0, (byte) 195, (byte) 122, (byte) 175,
                    (byte) 75, (byte) 33, (byte) 154, (byte) 68, (byte) 193, (byte) 164, (byte) 14,
                    (byte) 230, (byte) 176, (byte) 231, (byte) 95, (byte) 80, (byte) 193, (byte) 78,
                    (byte) 220, (byte) 22, (byte) 253, (byte) 254, (byte) 105, (byte) 77, (byte) 65,
                    (byte) 0, (byte) 0, (byte) 9, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
        org.junit.Assert.assertEquals(msg.x, -2.70035459129271051e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.29251076404157653e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.85535797726014908e+06, DELTA);
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 20, (byte) 46, (byte) 39, (byte) 0, (byte) 212, (byte) 196, (byte) 12,
                    (byte) 42, (byte) 34, (byte) 154, (byte) 68, (byte) 193, (byte) 9, (byte) 113,
                    (byte) 112, (byte) 123, (byte) 231, (byte) 95, (byte) 80, (byte) 193, (byte) 54,
                    (byte) 97, (byte) 38, (byte) 192, (byte) 254, (byte) 105, (byte) 77, (byte) 65,
                    (byte) 0, (byte) 0, (byte) 9, (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
        org.junit.Assert.assertEquals(msg.x, -2.70035632851467468e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.29250992873788718e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.85535750117125642e+06, DELTA);
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 120, (byte) 46, (byte) 39, (byte) 0, (byte) 112, (byte) 97, (byte) 39,
                    (byte) 190, (byte) 34, (byte) 154, (byte) 68, (byte) 193, (byte) 230, (byte) 43,
                    (byte) 119, (byte) 115, (byte) 231, (byte) 95, (byte) 80, (byte) 193, (byte) 50,
                    (byte) 199, (byte) 76, (byte) 66, (byte) 254, (byte) 105, (byte) 77, (byte) 65,
                    (byte) 0, (byte) 0, (byte) 9, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
        org.junit.Assert.assertEquals(msg.x, -2.70035748557680100e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.29250980414864980e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.85535651796808187e+06, DELTA);
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 120,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 194,
                    (byte) 82,
                    (byte) 121,
                    (byte) 4,
                    (byte) 34,
                    (byte) 154,
                    (byte) 68,
                    (byte) 193,
                    (byte) 223,
                    (byte) 186,
                    (byte) 1,
                    (byte) 140,
                    (byte) 231,
                    (byte) 95,
                    (byte) 80,
                    (byte) 193,
                    (byte) 176,
                    (byte) 152,
                    (byte) 147,
                    (byte) 181,
                    (byte) 254,
                    (byte) 105,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
        org.junit.Assert.assertEquals(msg.x, -2.70035603495249245e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.29251018760558870e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.85535741856678575e+06, DELTA);
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 220,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 216,
                    (byte) 41,
                    (byte) 227,
                    (byte) 254,
                    (byte) 33,
                    (byte) 154,
                    (byte) 68,
                    (byte) 193,
                    (byte) 9,
                    (byte) 151,
                    (byte) 154,
                    (byte) 124,
                    (byte) 231,
                    (byte) 95,
                    (byte) 80,
                    (byte) 193,
                    (byte) 1,
                    (byte) 183,
                    (byte) 214,
                    (byte) 139,
                    (byte) 255,
                    (byte) 105,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
        org.junit.Assert.assertEquals(msg.x, -2.70035599130747840e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.29250994693542365e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.85535909249007748e+06, DELTA);
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 212,
                    (byte) 157,
                    (byte) 67,
                    (byte) 24,
                    (byte) 153,
                    (byte) 222,
                    (byte) 105,
                    (byte) 1,
                    (byte) 252,
                    (byte) 161,
                    (byte) 68,
                    (byte) 193,
                    (byte) 254,
                    (byte) 247,
                    (byte) 52,
                    (byte) 112,
                    (byte) 74,
                    (byte) 67,
                    (byte) 80,
                    (byte) 193,
                    (byte) 164,
                    (byte) 207,
                    (byte) 47,
                    (byte) 146,
                    (byte) 44,
                    (byte) 163,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084500 + "'",
                    value.equals(BigInteger.valueOf(407084500L)));
        } else {
            value = value.longValue();
            expected = 407084500L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.70437601104338141e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26320975323295407e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.88463314208407886e+06, DELTA);
    }

    @Test
    public void test7() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 56,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 215,
                    (byte) 184,
                    (byte) 223,
                    (byte) 246,
                    (byte) 251,
                    (byte) 161,
                    (byte) 68,
                    (byte) 193,
                    (byte) 36,
                    (byte) 126,
                    (byte) 17,
                    (byte) 39,
                    (byte) 74,
                    (byte) 67,
                    (byte) 80,
                    (byte) 193,
                    (byte) 19,
                    (byte) 179,
                    (byte) 70,
                    (byte) 80,
                    (byte) 44,
                    (byte) 163,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084600 + "'",
                    value.equals(BigInteger.valueOf(407084600L)));
        } else {
            value = value.longValue();
            expected = 407084600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.70437592870245455e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26320861044267192e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.88463262715757778e+06, DELTA);
    }

    @Test
    public void test8() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test8");
        byte[] payload =
                new byte[] {
                    (byte) 156,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 73,
                    (byte) 74,
                    (byte) 214,
                    (byte) 148,
                    (byte) 251,
                    (byte) 161,
                    (byte) 68,
                    (byte) 193,
                    (byte) 213,
                    (byte) 151,
                    (byte) 184,
                    (byte) 215,
                    (byte) 73,
                    (byte) 67,
                    (byte) 80,
                    (byte) 193,
                    (byte) 110,
                    (byte) 99,
                    (byte) 38,
                    (byte) 164,
                    (byte) 43,
                    (byte) 163,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084700 + "'",
                    value.equals(BigInteger.valueOf(407084700L)));
        } else {
            value = value.longValue();
            expected = 407084700L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.70437516278961720e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26320737064166833e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.88463128242152091e+06, DELTA);
    }

    @Test
    public void test9() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test9");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 177,
                    (byte) 111,
                    (byte) 112,
                    (byte) 45,
                    (byte) 252,
                    (byte) 161,
                    (byte) 68,
                    (byte) 193,
                    (byte) 213,
                    (byte) 168,
                    (byte) 198,
                    (byte) 253,
                    (byte) 73,
                    (byte) 67,
                    (byte) 80,
                    (byte) 193,
                    (byte) 245,
                    (byte) 12,
                    (byte) 228,
                    (byte) 12,
                    (byte) 44,
                    (byte) 163,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084800 + "'",
                    value.equals(BigInteger.valueOf(407084800L)));
        } else {
            value = value.longValue();
            expected = 407084800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.70437635499378340e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26320796525021363e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.88463210070955241e+06, DELTA);
    }

    @Test
    public void test10() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test10");
        byte[] payload =
                new byte[] {
                    (byte) 100,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 67,
                    (byte) 231,
                    (byte) 72,
                    (byte) 165,
                    (byte) 251,
                    (byte) 161,
                    (byte) 68,
                    (byte) 193,
                    (byte) 150,
                    (byte) 210,
                    (byte) 36,
                    (byte) 212,
                    (byte) 73,
                    (byte) 67,
                    (byte) 80,
                    (byte) 193,
                    (byte) 234,
                    (byte) 33,
                    (byte) 25,
                    (byte) 189,
                    (byte) 43,
                    (byte) 163,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084900 + "'",
                    value.equals(BigInteger.valueOf(407084900L)));
        } else {
            value = value.longValue();
            expected = 407084900L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.70437529128733417e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26320731474747322e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.88463147732948232e+06, DELTA);
    }

    @Test
    public void test11() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFDepATest.test11");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 162,
                    (byte) 68,
                    (byte) 24,
                    (byte) 224,
                    (byte) 72,
                    (byte) 131,
                    (byte) 215,
                    (byte) 251,
                    (byte) 161,
                    (byte) 68,
                    (byte) 193,
                    (byte) 180,
                    (byte) 123,
                    (byte) 222,
                    (byte) 94,
                    (byte) 74,
                    (byte) 67,
                    (byte) 80,
                    (byte) 193,
                    (byte) 191,
                    (byte) 3,
                    (byte) 131,
                    (byte) 193,
                    (byte) 45,
                    (byte) 163,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 5,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x200, payload);
        MsgPosECEFDepA msg = new MsgPosECEFDepA(sbp);
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
                    "'" + msg.n_sats + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407151150 + "'",
                    value.equals(BigInteger.valueOf(407151150L)));
        } else {
            value = value.longValue();
            expected = 407151150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.70437568369399011e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26320948232929781e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.88463551181074930e+06, DELTA);
    }
}
