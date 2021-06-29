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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgDops;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgDopsTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 100,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 2,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                    (byte) 5,
                    (byte) 0,
                    (byte) 5,
                    (byte) 0,
                    (byte) 5,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0x208, payload);
        MsgDops msg = new MsgDops(sbp);
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
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 100 + "'", value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
