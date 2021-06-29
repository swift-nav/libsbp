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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosLLHDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosLLHDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 20,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 250,
                    (byte) 29,
                    (byte) 226,
                    (byte) 186,
                    (byte) 235,
                    (byte) 182,
                    (byte) 66,
                    (byte) 64,
                    (byte) 19,
                    (byte) 203,
                    (byte) 51,
                    (byte) 196,
                    (byte) 24,
                    (byte) 139,
                    (byte) 94,
                    (byte) 192,
                    (byte) 31,
                    (byte) 157,
                    (byte) 160,
                    (byte) 232,
                    (byte) 122,
                    (byte) 115,
                    (byte) 81,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 6.98043767517560667e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.74290689090812094e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22173386622027735e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 20, (byte) 46, (byte) 39, (byte) 0, (byte) 161, (byte) 51, (byte) 75,
                    (byte) 148, (byte) 235, (byte) 182, (byte) 66, (byte) 64, (byte) 36, (byte) 41,
                    (byte) 246, (byte) 30, (byte) 25, (byte) 139, (byte) 94, (byte) 192, (byte) 254,
                    (byte) 218, (byte) 49, (byte) 127, (byte) 10, (byte) 108, (byte) 81, (byte) 64,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 9, (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
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
        org.junit.Assert.assertEquals(msg.height, 6.96881406771535410e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.74290643088527375e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22173408260718645e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 120, (byte) 46, (byte) 39, (byte) 0, (byte) 56, (byte) 214, (byte) 210,
                    (byte) 65, (byte) 235, (byte) 182, (byte) 66, (byte) 64, (byte) 13, (byte) 46,
                    (byte) 132, (byte) 80, (byte) 25, (byte) 139, (byte) 94, (byte) 192, (byte) 22,
                    (byte) 143, (byte) 46, (byte) 234, (byte) 191, (byte) 95, (byte) 81, (byte) 64,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 9, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 6.94960885481526418e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.74290544776417278e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22173420075494690e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 120,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 251,
                    (byte) 117,
                    (byte) 115,
                    (byte) 140,
                    (byte) 235,
                    (byte) 182,
                    (byte) 66,
                    (byte) 64,
                    (byte) 152,
                    (byte) 134,
                    (byte) 167,
                    (byte) 12,
                    (byte) 25,
                    (byte) 139,
                    (byte) 94,
                    (byte) 192,
                    (byte) 160,
                    (byte) 22,
                    (byte) 137,
                    (byte) 253,
                    (byte) 4,
                    (byte) 108,
                    (byte) 81,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
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
        org.junit.Assert.assertEquals(msg.height, 6.96878045881990147e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.74290633739255654e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22173403895949718e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 220, (byte) 46, (byte) 39, (byte) 0, (byte) 51, (byte) 124, (byte) 88,
                    (byte) 251, (byte) 235, (byte) 182, (byte) 66, (byte) 64, (byte) 153, (byte) 5,
                    (byte) 250, (byte) 16, (byte) 25, (byte) 139, (byte) 94, (byte) 192, (byte) 146,
                    (byte) 60, (byte) 187, (byte) 219, (byte) 152, (byte) 161, (byte) 81, (byte) 64,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 9, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 7.05249547317964982e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.74290765935951626e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22173404926454523e+02, DELTA);
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
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 212,
                    (byte) 157,
                    (byte) 67,
                    (byte) 24,
                    (byte) 8,
                    (byte) 23,
                    (byte) 228,
                    (byte) 8,
                    (byte) 151,
                    (byte) 225,
                    (byte) 66,
                    (byte) 64,
                    (byte) 156,
                    (byte) 174,
                    (byte) 42,
                    (byte) 194,
                    (byte) 230,
                    (byte) 152,
                    (byte) 94,
                    (byte) 192,
                    (byte) 153,
                    (byte) 23,
                    (byte) 72,
                    (byte) 47,
                    (byte) 196,
                    (byte) 40,
                    (byte) 16,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 4.03981088521495568e+00, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.77624217141838585e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22389084378892619e+02, DELTA);
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
    public void test7() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 56,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 220,
                    (byte) 109,
                    (byte) 212,
                    (byte) 24,
                    (byte) 151,
                    (byte) 225,
                    (byte) 66,
                    (byte) 64,
                    (byte) 159,
                    (byte) 231,
                    (byte) 254,
                    (byte) 219,
                    (byte) 230,
                    (byte) 152,
                    (byte) 94,
                    (byte) 192,
                    (byte) 128,
                    (byte) 151,
                    (byte) 67,
                    (byte) 19,
                    (byte) 233,
                    (byte) 105,
                    (byte) 7,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 2.92671408700965685e+00, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.77624236142398502e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22389090537004890e+02, DELTA);
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
    public void test8() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test8");
        byte[] payload =
                new byte[] {
                    (byte) 156,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 13,
                    (byte) 91,
                    (byte) 237,
                    (byte) 11,
                    (byte) 151,
                    (byte) 225,
                    (byte) 66,
                    (byte) 64,
                    (byte) 75,
                    (byte) 113,
                    (byte) 210,
                    (byte) 220,
                    (byte) 230,
                    (byte) 152,
                    (byte) 94,
                    (byte) 192,
                    (byte) 37,
                    (byte) 6,
                    (byte) 145,
                    (byte) 188,
                    (byte) 89,
                    (byte) 112,
                    (byte) 238,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 9.51214664739556626e-01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.77624220761264056e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22389090734014800e+02, DELTA);
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
    public void test9() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test9");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 51,
                    (byte) 183,
                    (byte) 5,
                    (byte) 8,
                    (byte) 151,
                    (byte) 225,
                    (byte) 66,
                    (byte) 64,
                    (byte) 13,
                    (byte) 226,
                    (byte) 148,
                    (byte) 253,
                    (byte) 230,
                    (byte) 152,
                    (byte) 94,
                    (byte) 192,
                    (byte) 187,
                    (byte) 27,
                    (byte) 11,
                    (byte) 32,
                    (byte) 69,
                    (byte) 213,
                    (byte) 2,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 2.35413575204753789e+00, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.77624216106327353e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22389098544496122e+02, DELTA);
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
    public void test10() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test10");
        byte[] payload =
                new byte[] {
                    (byte) 100,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 22,
                    (byte) 77,
                    (byte) 146,
                    (byte) 22,
                    (byte) 151,
                    (byte) 225,
                    (byte) 66,
                    (byte) 64,
                    (byte) 64,
                    (byte) 134,
                    (byte) 105,
                    (byte) 227,
                    (byte) 230,
                    (byte) 152,
                    (byte) 94,
                    (byte) 192,
                    (byte) 37,
                    (byte) 99,
                    (byte) 114,
                    (byte) 72,
                    (byte) 31,
                    (byte) 103,
                    (byte) 241,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 1.08767631816426413e+00, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.77624233450280116e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22389092305232225e+02, DELTA);
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
    public void test11() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHDepATest.test11");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 162,
                    (byte) 68,
                    (byte) 24,
                    (byte) 124,
                    (byte) 245,
                    (byte) 46,
                    (byte) 169,
                    (byte) 151,
                    (byte) 225,
                    (byte) 66,
                    (byte) 64,
                    (byte) 135,
                    (byte) 149,
                    (byte) 234,
                    (byte) 187,
                    (byte) 230,
                    (byte) 152,
                    (byte) 94,
                    (byte) 192,
                    (byte) 194,
                    (byte) 201,
                    (byte) 115,
                    (byte) 145,
                    (byte) 166,
                    (byte) 175,
                    (byte) 20,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 5,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x201, payload);
        MsgPosLLHDepA msg = new MsgPosLLHDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
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
        org.junit.Assert.assertEquals(msg.height, 5.17153384465422228e+00, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.77624408225337618e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22389082888685252e+02, DELTA);
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
