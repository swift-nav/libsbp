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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTimeGNSS.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgUtcTimeGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgUTCTimeGNSSTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgUTCTimeGNSSTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 24, (byte) 229, (byte) 233, (byte) 29, (byte) 229, (byte) 7,
                    (byte) 4, (byte) 9, (byte) 19, (byte) 24, (byte) 9, (byte) 0, (byte) 8,
                    (byte) 175, (byte) 47,
                };
        SBPMessage sbp = new SBPMessage(0x315, 0x105, payload);
        MsgUtcTimeGnss msg = new MsgUtcTimeGnss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.day;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.day + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hours;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hours + "' != '" + 19 + "'", value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.minutes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.minutes + "' != '" + 24 + "'", value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.month;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.month + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns + "' != '" + 800000000 + "'",
                    value.equals(BigInteger.valueOf(800000000L)));
        } else {
            value = value.longValue();
            expected = 800000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.seconds;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.seconds + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
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
        value = msg.year;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.year + "' != '" + 2021 + "'",
                    value.equals(BigInteger.valueOf(2021L)));
        } else {
            value = value.longValue();
            expected = 2021L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
