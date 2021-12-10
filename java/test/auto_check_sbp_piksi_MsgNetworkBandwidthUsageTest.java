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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgNetworkBandwidthUsage;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgNetworkBandwidthUsageTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgNetworkBandwidthUsageTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 94,
                    (byte) 105,
                    (byte) 178,
                    (byte) 128,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 99,
                    (byte) 97,
                    (byte) 110,
                    (byte) 48,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 94,
                    (byte) 105,
                    (byte) 178,
                    (byte) 128,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 99,
                    (byte) 97,
                    (byte) 110,
                    (byte) 49,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 94,
                    (byte) 105,
                    (byte) 178,
                    (byte) 128,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 165,
                    (byte) 235,
                    (byte) 94,
                    (byte) 203,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 237,
                    (byte) 14,
                    (byte) 148,
                    (byte) 240,
                    (byte) 184,
                    (byte) 220,
                    (byte) 202,
                    (byte) 218,
                    (byte) 101,
                    (byte) 116,
                    (byte) 104,
                    (byte) 48,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 94,
                    (byte) 105,
                    (byte) 178,
                    (byte) 128,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 108,
                    (byte) 111,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 94,
                    (byte) 105,
                    (byte) 178,
                    (byte) 128,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 115,
                    (byte) 105,
                    (byte) 116,
                    (byte) 48,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x79CF, 0xBD, payload);
        MsgNetworkBandwidthUsage msg = new MsgNetworkBandwidthUsage(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.interfaces[0].duration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[0].duration + "' != '" + 2159176030L + "'",
                    value.equals(new BigInteger("2159176030")));
        } else {
            value = value.longValue();
            expected = 2159176030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.interfaces[0].interface_name, "can0            ");
        value = msg.interfaces[0].rx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[0].rx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[0].total_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[0].total_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[0].tx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[0].tx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[1].duration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[1].duration + "' != '" + 2159176030L + "'",
                    value.equals(new BigInteger("2159176030")));
        } else {
            value = value.longValue();
            expected = 2159176030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.interfaces[1].interface_name, "can1            ");
        value = msg.interfaces[1].rx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[1].rx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[1].total_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[1].total_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[1].tx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[1].tx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[2].duration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[2].duration + "' != '" + 2159176030L + "'",
                    value.equals(new BigInteger("2159176030")));
        } else {
            value = value.longValue();
            expected = 2159176030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.interfaces[2].interface_name, "eth0            ");
        value = msg.interfaces[2].rx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[2].rx_bytes + "' != '" + 4036234989L + "'",
                    value.equals(new BigInteger("4036234989")));
        } else {
            value = value.longValue();
            expected = 4036234989L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[2].total_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[2].total_bytes + "' != '" + 3411995557L + "'",
                    value.equals(new BigInteger("3411995557")));
        } else {
            value = value.longValue();
            expected = 3411995557L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[2].tx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[2].tx_bytes + "' != '" + 3670727864L + "'",
                    value.equals(new BigInteger("3670727864")));
        } else {
            value = value.longValue();
            expected = 3670727864L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[3].duration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[3].duration + "' != '" + 2159176030L + "'",
                    value.equals(new BigInteger("2159176030")));
        } else {
            value = value.longValue();
            expected = 2159176030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.interfaces[3].interface_name, "lo              ");
        value = msg.interfaces[3].rx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[3].rx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[3].total_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[3].total_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[3].tx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[3].tx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[4].duration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[4].duration + "' != '" + 2159176030L + "'",
                    value.equals(new BigInteger("2159176030")));
        } else {
            value = value.longValue();
            expected = 2159176030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.interfaces[4].interface_name, "sit0            ");
        value = msg.interfaces[4].rx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[4].rx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[4].total_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[4].total_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.interfaces[4].tx_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.interfaces[4].tx_bytes + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
