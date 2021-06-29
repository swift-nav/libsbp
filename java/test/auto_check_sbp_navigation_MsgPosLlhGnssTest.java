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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhGnss.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosLLHGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosLlhGnssTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLlhGnssTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 24,
                    (byte) 229,
                    (byte) 233,
                    (byte) 29,
                    (byte) 73,
                    (byte) 123,
                    (byte) 28,
                    (byte) 207,
                    (byte) 101,
                    (byte) 234,
                    (byte) 66,
                    (byte) 64,
                    (byte) 100,
                    (byte) 168,
                    (byte) 19,
                    (byte) 20,
                    (byte) 86,
                    (byte) 146,
                    (byte) 94,
                    (byte) 192,
                    (byte) 214,
                    (byte) 198,
                    (byte) 35,
                    (byte) 120,
                    (byte) 209,
                    (byte) 100,
                    (byte) 49,
                    (byte) 192,
                    (byte) 87,
                    (byte) 0,
                    (byte) 181,
                    (byte) 0,
                    (byte) 18,
                    (byte) 4,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0x22a, payload);
        MsgPosLLHGnss msg = new MsgPosLLHGnss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.h_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.h_accuracy + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.height, -1.73938212478013483e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.78312319649763324e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22286503810116812e+02, DELTA);
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 18 + "'", value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 501867800 + "'",
                    value.equals(BigInteger.valueOf(501867800L)));
        } else {
            value = value.longValue();
            expected = 501867800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.v_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.v_accuracy + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
