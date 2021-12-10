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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosLLH;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosLLHTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 40,
                    (byte) 244,
                    (byte) 122,
                    (byte) 19,
                    (byte) 201,
                    (byte) 106,
                    (byte) 155,
                    (byte) 186,
                    (byte) 42,
                    (byte) 160,
                    (byte) 66,
                    (byte) 64,
                    (byte) 168,
                    (byte) 109,
                    (byte) 26,
                    (byte) 225,
                    (byte) 0,
                    (byte) 120,
                    (byte) 94,
                    (byte) 192,
                    (byte) 130,
                    (byte) 102,
                    (byte) 237,
                    (byte) 230,
                    (byte) 43,
                    (byte) 54,
                    (byte) 60,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20a, payload);
        MsgPosLLH msg = new MsgPosLLH(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
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
        org.junit.Assert.assertEquals(msg.height, 2.82116073922720787e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.72513039835808470e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.21875053668793612e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 16, (byte) 248, (byte) 122, (byte) 19, (byte) 52, (byte) 177, (byte) 251,
                    (byte) 178, (byte) 42, (byte) 160, (byte) 66, (byte) 64, (byte) 237, (byte) 22,
                    (byte) 97, (byte) 224, (byte) 0, (byte) 120, (byte) 94, (byte) 192, (byte) 107,
                    (byte) 188, (byte) 109, (byte) 90, (byte) 247, (byte) 189, (byte) 59, (byte) 64,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20a, payload);
        MsgPosLLH msg = new MsgPosLLH(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
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
        org.junit.Assert.assertEquals(msg.height, 2.77420555608663726e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.72513030747381038e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.21875053496183412e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 248, (byte) 251, (byte) 122, (byte) 19, (byte) 135, (byte) 66, (byte) 9,
                    (byte) 163, (byte) 42, (byte) 160, (byte) 66, (byte) 64, (byte) 146, (byte) 8,
                    (byte) 99, (byte) 225, (byte) 0, (byte) 120, (byte) 94, (byte) 192, (byte) 45,
                    (byte) 181, (byte) 143, (byte) 219, (byte) 28, (byte) 157, (byte) 59, (byte) 64,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20a, payload);
        MsgPosLLH msg = new MsgPosLLH(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
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
        org.junit.Assert.assertEquals(msg.height, 2.76137215829705163e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.72513011737074109e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.21875053736412411e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 224, (byte) 255, (byte) 122, (byte) 19, (byte) 18, (byte) 44, (byte) 253,
                    (byte) 119, (byte) 42, (byte) 160, (byte) 66, (byte) 64, (byte) 48, (byte) 109,
                    (byte) 39, (byte) 231, (byte) 0, (byte) 120, (byte) 94, (byte) 192, (byte) 185,
                    (byte) 76, (byte) 48, (byte) 17, (byte) 119, (byte) 205, (byte) 59, (byte) 64,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20a, payload);
        MsgPosLLH msg = new MsgPosLLH(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
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
        org.junit.Assert.assertEquals(msg.height, 2.78025980704230484e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.72512960420791757e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.21875055111410575e+02, DELTA);
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
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLLHTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 200,
                    (byte) 3,
                    (byte) 123,
                    (byte) 19,
                    (byte) 225,
                    (byte) 237,
                    (byte) 238,
                    (byte) 90,
                    (byte) 42,
                    (byte) 160,
                    (byte) 66,
                    (byte) 64,
                    (byte) 59,
                    (byte) 143,
                    (byte) 70,
                    (byte) 235,
                    (byte) 0,
                    (byte) 120,
                    (byte) 94,
                    (byte) 192,
                    (byte) 101,
                    (byte) 106,
                    (byte) 249,
                    (byte) 224,
                    (byte) 131,
                    (byte) 240,
                    (byte) 59,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20a, payload);
        MsgPosLLH msg = new MsgPosLLH(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
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
        org.junit.Assert.assertEquals(msg.height, 2.79395123108792127e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.72512925783773952e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.21875056094079739e+02, DELTA);
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
