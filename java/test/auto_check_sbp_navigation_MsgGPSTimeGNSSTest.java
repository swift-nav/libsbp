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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeGNSS.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgGPSTimeGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgGPSTimeGNSSTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeGNSSTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 128,
                    (byte) 7,
                    (byte) 40,
                    (byte) 244,
                    (byte) 122,
                    (byte) 19,
                    (byte) 244,
                    (byte) 139,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x104, payload);
        MsgGPSTimeGnss msg = new MsgGPSTimeGnss(sbp);
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
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 166900 + "'",
                    value.equals(BigInteger.valueOf(166900L)));
        } else {
            value = value.longValue();
            expected = 166900L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1920 + "'", value.equals(BigInteger.valueOf(1920L)));
        } else {
            value = value.longValue();
            expected = 1920L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeGNSSTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 128,
                    (byte) 7,
                    (byte) 28,
                    (byte) 246,
                    (byte) 122,
                    (byte) 19,
                    (byte) 126,
                    (byte) 234,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x104, payload);
        MsgGPSTimeGnss msg = new MsgGPSTimeGnss(sbp);
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
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 256638 + "'",
                    value.equals(BigInteger.valueOf(256638L)));
        } else {
            value = value.longValue();
            expected = 256638L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1920 + "'", value.equals(BigInteger.valueOf(1920L)));
        } else {
            value = value.longValue();
            expected = 1920L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeGNSSTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 128,
                    (byte) 7,
                    (byte) 16,
                    (byte) 248,
                    (byte) 122,
                    (byte) 19,
                    (byte) 129,
                    (byte) 12,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x104, payload);
        MsgGPSTimeGnss msg = new MsgGPSTimeGnss(sbp);
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
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 265345 + "'",
                    value.equals(BigInteger.valueOf(265345L)));
        } else {
            value = value.longValue();
            expected = 265345L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1920 + "'", value.equals(BigInteger.valueOf(1920L)));
        } else {
            value = value.longValue();
            expected = 1920L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeGNSSTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 128,
                    (byte) 7,
                    (byte) 4,
                    (byte) 250,
                    (byte) 122,
                    (byte) 19,
                    (byte) 137,
                    (byte) 204,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x104, payload);
        MsgGPSTimeGnss msg = new MsgGPSTimeGnss(sbp);
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
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 314505 + "'",
                    value.equals(BigInteger.valueOf(314505L)));
        } else {
            value = value.longValue();
            expected = 314505L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1920 + "'", value.equals(BigInteger.valueOf(1920L)));
        } else {
            value = value.longValue();
            expected = 1920L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeGNSSTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 128,
                    (byte) 7,
                    (byte) 248,
                    (byte) 251,
                    (byte) 122,
                    (byte) 19,
                    (byte) 181,
                    (byte) 137,
                    (byte) 5,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x104, payload);
        MsgGPSTimeGnss msg = new MsgGPSTimeGnss(sbp);
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
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 362933 + "'",
                    value.equals(BigInteger.valueOf(362933L)));
        } else {
            value = value.longValue();
            expected = 362933L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1920 + "'", value.equals(BigInteger.valueOf(1920L)));
        } else {
            value = value.longValue();
            expected = 1920L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
