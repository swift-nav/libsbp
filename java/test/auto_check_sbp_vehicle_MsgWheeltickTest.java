/* Copyright (C) 2015-2022 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgWheeltick.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.vehicle.MsgWheeltick;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_vehicle_MsgWheeltickTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_vehicle_MsgWheeltickTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 254, (byte) 27, (byte) 114, (byte) 44, (byte) 26, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 1, (byte) 146, (byte) 225, (byte) 51, (byte) 9, (byte) 210,
                };
        SBPMessage sbp = new SBPMessage(0x456b, 0x904, payload);
        MsgWheeltick msg = new MsgWheeltick(sbp);
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
        value = msg.source;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.source + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ticks;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ticks + "' != '" + -771148831 + "'",
                    value.equals(BigInteger.valueOf(-771148831L)));
        } else {
            value = value.longValue();
            expected = -771148831L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time + "' != '" + 112414825470L + "'",
                    value.equals(new BigInteger("112414825470")));
        } else {
            value = value.longValue();
            expected = 112414825470L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
