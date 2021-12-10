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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ext_events/test_MsgExtEvent.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ext_events.MsgExtEvent;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ext_events_MsgExtEventTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_ext_events_MsgExtEventTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 48,
                    (byte) 7,
                    (byte) 199,
                    (byte) 216,
                    (byte) 49,
                    (byte) 15,
                    (byte) 202,
                    (byte) 65,
                    (byte) 15,
                    (byte) 0,
                    (byte) 3,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x6f5, 0x101, payload);
        MsgExtEvent msg = new MsgExtEvent(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 999882 + "'",
                    value.equals(BigInteger.valueOf(999882L)));
        } else {
            value = value.longValue();
            expected = 999882L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pin + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 254924999 + "'",
                    value.equals(BigInteger.valueOf(254924999L)));
        } else {
            value = value.longValue();
            expected = 254924999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1840 + "'", value.equals(BigInteger.valueOf(1840L)));
        } else {
            value = value.longValue();
            expected = 1840L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
