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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.system.MsgInsUpdates;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_system_MsgInsUpdatesTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgInsUpdatesTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 84,
                    (byte) 229,
                    (byte) 17,
                    (byte) 30,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x315, 0xff06, payload);
        MsgInsUpdates msg = new MsgInsUpdates(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gnsspos;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gnsspos + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gnssvel;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gnssvel + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nhc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.nhc + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.speed;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.speed + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 504489300 + "'",
                    value.equals(BigInteger.valueOf(504489300L)));
        } else {
            value = value.longValue();
            expected = 504489300L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wheelticks;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wheelticks + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.zerovel;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.zerovel + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
