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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosECEF;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosECEFTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 16,
                    (byte) 248,
                    (byte) 122,
                    (byte) 19,
                    (byte) 73,
                    (byte) 29,
                    (byte) 46,
                    (byte) 132,
                    (byte) 182,
                    (byte) 122,
                    (byte) 68,
                    (byte) 193,
                    (byte) 219,
                    (byte) 192,
                    (byte) 29,
                    (byte) 176,
                    (byte) 121,
                    (byte) 119,
                    (byte) 80,
                    (byte) 193,
                    (byte) 83,
                    (byte) 11,
                    (byte) 210,
                    (byte) 90,
                    (byte) 79,
                    (byte) 75,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x209, payload);
        MsgPosECEF msg = new MsgPosECEF(sbp);
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
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
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
                    "'" + msg.tow + "' != '" + 326826000 + "'",
                    value.equals(BigInteger.valueOf(326826000L)));
        } else {
            value = value.longValue();
            expected = 326826000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.68426903265729966e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.31664675181599986e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.83964670953504136e+06, DELTA);
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 248,
                    (byte) 251,
                    (byte) 122,
                    (byte) 19,
                    (byte) 103,
                    (byte) 106,
                    (byte) 57,
                    (byte) 136,
                    (byte) 182,
                    (byte) 122,
                    (byte) 68,
                    (byte) 193,
                    (byte) 176,
                    (byte) 242,
                    (byte) 200,
                    (byte) 176,
                    (byte) 121,
                    (byte) 119,
                    (byte) 80,
                    (byte) 193,
                    (byte) 244,
                    (byte) 135,
                    (byte) 97,
                    (byte) 59,
                    (byte) 79,
                    (byte) 75,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x209, payload);
        MsgPosECEF msg = new MsgPosECEF(sbp);
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
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
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
                    "'" + msg.tow + "' != '" + 326827000 + "'",
                    value.equals(BigInteger.valueOf(326827000L)));
        } else {
            value = value.longValue();
            expected = 326827000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.68426906425218610e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.31664676226489246e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.83964646391391195e+06, DELTA);
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 224,
                    (byte) 255,
                    (byte) 122,
                    (byte) 19,
                    (byte) 101,
                    (byte) 179,
                    (byte) 242,
                    (byte) 182,
                    (byte) 182,
                    (byte) 122,
                    (byte) 68,
                    (byte) 193,
                    (byte) 130,
                    (byte) 196,
                    (byte) 145,
                    (byte) 199,
                    (byte) 121,
                    (byte) 119,
                    (byte) 80,
                    (byte) 193,
                    (byte) 212,
                    (byte) 10,
                    (byte) 253,
                    (byte) 15,
                    (byte) 79,
                    (byte) 75,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x209, payload);
        MsgPosECEF msg = new MsgPosECEF(sbp);
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
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
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
                    "'" + msg.tow + "' != '" + 326828000 + "'",
                    value.equals(BigInteger.valueOf(326828000L)));
        } else {
            value = value.longValue();
            expected = 326828000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.68426942928163940e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.31664711827194877e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.83964612490973808e+06, DELTA);
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 200,
                    (byte) 3,
                    (byte) 123,
                    (byte) 19,
                    (byte) 146,
                    (byte) 214,
                    (byte) 132,
                    (byte) 215,
                    (byte) 182,
                    (byte) 122,
                    (byte) 68,
                    (byte) 193,
                    (byte) 213,
                    (byte) 68,
                    (byte) 49,
                    (byte) 215,
                    (byte) 121,
                    (byte) 119,
                    (byte) 80,
                    (byte) 193,
                    (byte) 71,
                    (byte) 34,
                    (byte) 110,
                    (byte) 243,
                    (byte) 78,
                    (byte) 75,
                    (byte) 77,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x209, payload);
        MsgPosECEF msg = new MsgPosECEF(sbp);
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
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
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
                    "'" + msg.tow + "' != '" + 326829000 + "'",
                    value.equals(BigInteger.valueOf(326829000L)));
        } else {
            value = value.longValue();
            expected = 326829000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.x, -2.68426968374139909e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.31664736238213349e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.83964590179851977e+06, DELTA);
    }
}
