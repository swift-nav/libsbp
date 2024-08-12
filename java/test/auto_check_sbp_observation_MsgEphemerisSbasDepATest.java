/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisSbasDepA.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisSbasDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgEphemerisSbasDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_observation_MsgEphemerisSbasDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 22,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                    (byte) 176,
                    (byte) 207,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 66,
                    (byte) 246,
                    (byte) 57,
                    (byte) 103,
                    (byte) 193,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 34,
                    (byte) 170,
                    (byte) 78,
                    (byte) 34,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 240,
                    (byte) 199,
                    (byte) 84,
                    (byte) 86,
                    (byte) 117,
                    (byte) 193,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 98,
                    (byte) 6,
                    (byte) 250,
                    (byte) 154,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 217,
                    (byte) 58,
                    (byte) 221,
                    (byte) 163,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 184,
                    (byte) 138,
                    (byte) 46,
                    (byte) 139,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 175,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 175,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 112,
                    (byte) 199,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 108,
                    (byte) 177,
                    (byte) 68,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 163,
                    (byte) 61,
                };
        SBPMessage sbp = new SBPMessage(0x007b, 0x82, payload);
        MsgEphemerisSbasDepA msg = new MsgEphemerisSbasDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.a_gf0, -6.31501898169517517e-04, DELTA);
        org.junit.Assert.assertEquals(msg.a_gf1, 8.98126018000766635e-12, DELTA);
        org.junit.Assert.assertEquals(msg.acc[0], 9.31322574615478516e-07, DELTA);
        org.junit.Assert.assertEquals(msg.acc[1], 9.31322574615478516e-07, DELTA);
        org.junit.Assert.assertEquals(msg.acc[2], 2.79396772384643555e-06, DELTA);
        value = msg.common.fit_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.fit_interval + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.health_bits;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.health_bits + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.code + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.sat + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toe.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toe.tow + "' != '" + 446384 + "'",
                    value.equals(BigInteger.valueOf(446384L)));
        } else {
            value = value.longValue();
            expected = 446384L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toe.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toe.wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.common.ura, 2.00000000000000000e+00, DELTA);
        value = msg.common.valid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.valid + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.pos[0], -1.21773300781250000e+07, DELTA);
        org.junit.Assert.assertEquals(msg.pos[1], 5.99893066406250000e+05, DELTA);
        org.junit.Assert.assertEquals(msg.pos[2], -2.23737084960937500e+07, DELTA);
        org.junit.Assert.assertEquals(msg.vel[0], -1.72650623321533203e+03, DELTA);
        org.junit.Assert.assertEquals(msg.vel[1], -2.54261493682861328e+03, DELTA);
        org.junit.Assert.assertEquals(msg.vel[2], 8.69817733764648438e+02, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
