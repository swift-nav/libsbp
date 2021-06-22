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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgDeviceMonitor.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgDeviceMonitor;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgDeviceMonitorTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgDeviceMonitorTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 241,
                    (byte) 216,
                    (byte) 219,
                    (byte) 3,
                    (byte) 253,
                    (byte) 6,
                    (byte) 21,
                    (byte) 24,
                    (byte) 168,
                    (byte) 18,
                };
        SBPMessage sbp = new SBPMessage(0x425f, 0xb5, payload);
        MsgDeviceMonitor msg = new MsgDeviceMonitor(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_temperature + "' != '" + 6165 + "'",
                    value.equals(BigInteger.valueOf(6165L)));
        } else {
            value = value.longValue();
            expected = 6165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vaux;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vaux + "' != '" + 1789 + "'",
                    value.equals(BigInteger.valueOf(1789L)));
        } else {
            value = value.longValue();
            expected = 1789L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vint;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vint + "' != '" + 987 + "'",
                    value.equals(BigInteger.valueOf(987L)));
        } else {
            value = value.longValue();
            expected = 987L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dev_vin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dev_vin + "' != '" + -9999 + "'",
                    value.equals(BigInteger.valueOf(-9999L)));
        } else {
            value = value.longValue();
            expected = -9999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fe_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fe_temperature + "' != '" + 4776 + "'",
                    value.equals(BigInteger.valueOf(4776L)));
        } else {
            value = value.longValue();
            expected = 4776L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgDeviceMonitorTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 241,
                    (byte) 216,
                    (byte) 219,
                    (byte) 3,
                    (byte) 254,
                    (byte) 6,
                    (byte) 24,
                    (byte) 24,
                    (byte) 168,
                    (byte) 18,
                };
        SBPMessage sbp = new SBPMessage(0x425f, 0xb5, payload);
        MsgDeviceMonitor msg = new MsgDeviceMonitor(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_temperature + "' != '" + 6168 + "'",
                    value.equals(BigInteger.valueOf(6168L)));
        } else {
            value = value.longValue();
            expected = 6168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vaux;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vaux + "' != '" + 1790 + "'",
                    value.equals(BigInteger.valueOf(1790L)));
        } else {
            value = value.longValue();
            expected = 1790L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vint;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vint + "' != '" + 987 + "'",
                    value.equals(BigInteger.valueOf(987L)));
        } else {
            value = value.longValue();
            expected = 987L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dev_vin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dev_vin + "' != '" + -9999 + "'",
                    value.equals(BigInteger.valueOf(-9999L)));
        } else {
            value = value.longValue();
            expected = -9999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fe_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fe_temperature + "' != '" + 4776 + "'",
                    value.equals(BigInteger.valueOf(4776L)));
        } else {
            value = value.longValue();
            expected = 4776L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgDeviceMonitorTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 241,
                    (byte) 216,
                    (byte) 219,
                    (byte) 3,
                    (byte) 253,
                    (byte) 6,
                    (byte) 22,
                    (byte) 24,
                    (byte) 168,
                    (byte) 18,
                };
        SBPMessage sbp = new SBPMessage(0x425f, 0xb5, payload);
        MsgDeviceMonitor msg = new MsgDeviceMonitor(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_temperature + "' != '" + 6166 + "'",
                    value.equals(BigInteger.valueOf(6166L)));
        } else {
            value = value.longValue();
            expected = 6166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vaux;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vaux + "' != '" + 1789 + "'",
                    value.equals(BigInteger.valueOf(1789L)));
        } else {
            value = value.longValue();
            expected = 1789L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vint;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vint + "' != '" + 987 + "'",
                    value.equals(BigInteger.valueOf(987L)));
        } else {
            value = value.longValue();
            expected = 987L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dev_vin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dev_vin + "' != '" + -9999 + "'",
                    value.equals(BigInteger.valueOf(-9999L)));
        } else {
            value = value.longValue();
            expected = -9999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fe_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fe_temperature + "' != '" + 4776 + "'",
                    value.equals(BigInteger.valueOf(4776L)));
        } else {
            value = value.longValue();
            expected = 4776L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgDeviceMonitorTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 241,
                    (byte) 216,
                    (byte) 218,
                    (byte) 3,
                    (byte) 252,
                    (byte) 6,
                    (byte) 6,
                    (byte) 24,
                    (byte) 168,
                    (byte) 18,
                };
        SBPMessage sbp = new SBPMessage(0x425f, 0xb5, payload);
        MsgDeviceMonitor msg = new MsgDeviceMonitor(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_temperature + "' != '" + 6150 + "'",
                    value.equals(BigInteger.valueOf(6150L)));
        } else {
            value = value.longValue();
            expected = 6150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vaux;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vaux + "' != '" + 1788 + "'",
                    value.equals(BigInteger.valueOf(1788L)));
        } else {
            value = value.longValue();
            expected = 1788L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vint;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vint + "' != '" + 986 + "'",
                    value.equals(BigInteger.valueOf(986L)));
        } else {
            value = value.longValue();
            expected = 986L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dev_vin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dev_vin + "' != '" + -9999 + "'",
                    value.equals(BigInteger.valueOf(-9999L)));
        } else {
            value = value.longValue();
            expected = -9999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fe_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fe_temperature + "' != '" + 4776 + "'",
                    value.equals(BigInteger.valueOf(4776L)));
        } else {
            value = value.longValue();
            expected = 4776L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgDeviceMonitorTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 241,
                    (byte) 216,
                    (byte) 220,
                    (byte) 3,
                    (byte) 253,
                    (byte) 6,
                    (byte) 235,
                    (byte) 23,
                    (byte) 168,
                    (byte) 18,
                };
        SBPMessage sbp = new SBPMessage(0x425f, 0xb5, payload);
        MsgDeviceMonitor msg = new MsgDeviceMonitor(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_temperature + "' != '" + 6123 + "'",
                    value.equals(BigInteger.valueOf(6123L)));
        } else {
            value = value.longValue();
            expected = 6123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vaux;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vaux + "' != '" + 1789 + "'",
                    value.equals(BigInteger.valueOf(1789L)));
        } else {
            value = value.longValue();
            expected = 1789L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cpu_vint;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu_vint + "' != '" + 988 + "'",
                    value.equals(BigInteger.valueOf(988L)));
        } else {
            value = value.longValue();
            expected = 988L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dev_vin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dev_vin + "' != '" + -9999 + "'",
                    value.equals(BigInteger.valueOf(-9999L)));
        } else {
            value = value.longValue();
            expected = -9999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fe_temperature;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fe_temperature + "' != '" + 4776 + "'",
                    value.equals(BigInteger.valueOf(4776L)));
        } else {
            value = value.longValue();
            expected = 4776L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
