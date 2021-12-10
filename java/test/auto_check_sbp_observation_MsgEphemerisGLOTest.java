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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLO.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisGlo;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgEphemerisGLOTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgEphemerisGLOTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 4, (byte) 3, (byte) 70, (byte) 197, (byte) 6, (byte) 0, (byte) 106,
                    (byte) 8, (byte) 0, (byte) 0, (byte) 160, (byte) 64, (byte) 96, (byte) 9,
                    (byte) 0, (byte) 0, (byte) 1, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 43, (byte) 128, (byte) 97, (byte) 175, (byte) 184, (byte) 0, (byte) 0,
                    (byte) 64, (byte) 177, (byte) 0, (byte) 0, (byte) 128, (byte) 66, (byte) 246,
                    (byte) 57, (byte) 103, (byte) 193, (byte) 0, (byte) 0, (byte) 0, (byte) 34,
                    (byte) 170, (byte) 78, (byte) 34, (byte) 65, (byte) 0, (byte) 0, (byte) 240,
                    (byte) 199, (byte) 84, (byte) 86, (byte) 117, (byte) 193, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 98, (byte) 6, (byte) 250, (byte) 154, (byte) 192, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 217, (byte) 58, (byte) 221, (byte) 163, (byte) 192,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 184, (byte) 138, (byte) 46, (byte) 139,
                    (byte) 64, (byte) 0, (byte) 0, (byte) 122, (byte) 53, (byte) 0, (byte) 0,
                    (byte) 122, (byte) 53, (byte) 0, (byte) 128, (byte) 59, (byte) 54, (byte) 14,
                    (byte) 100,
                };
        SBPMessage sbp = new SBPMessage(0x90a, 0x8b, payload);
        MsgEphemerisGlo msg = new MsgEphemerisGlo(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.acc[0], 9.31322574615478516e-07, DELTA);
        org.junit.Assert.assertEquals(msg.acc[1], 9.31322574615478516e-07, DELTA);
        org.junit.Assert.assertEquals(msg.acc[2], 2.79396772384643555e-06, DELTA);
        value = msg.common.fit_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.fit_interval + "' != '" + 2400 + "'",
                    value.equals(BigInteger.valueOf(2400L)));
        } else {
            value = value.longValue();
            expected = 2400L;
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
                    "'" + msg.common.sid.code + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.sat + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toe.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toe.tow + "' != '" + 443718 + "'",
                    value.equals(BigInteger.valueOf(443718L)));
        } else {
            value = value.longValue();
            expected = 443718L;
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
        org.junit.Assert.assertEquals(msg.common.ura, 5.00000000000000000e+00, DELTA);
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
        org.junit.Assert.assertEquals(msg.d_tau, -2.79396772384643555e-09, DELTA);
        value = msg.fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fcn + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.gamma, 9.09494701772928238e-13, DELTA);
        value = msg.iod;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iod + "' != '" + 100 + "'", value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.pos[0], -1.21773300781250000e+07, DELTA);
        org.junit.Assert.assertEquals(msg.pos[1], 5.99893066406250000e+05, DELTA);
        org.junit.Assert.assertEquals(msg.pos[2], -2.23737084960937500e+07, DELTA);
        org.junit.Assert.assertEquals(msg.tau, -8.36281105875968933e-05, DELTA);
        org.junit.Assert.assertEquals(msg.vel[0], -1.72650623321533203e+03, DELTA);
        org.junit.Assert.assertEquals(msg.vel[1], -2.54261493682861328e+03, DELTA);
        org.junit.Assert.assertEquals(msg.vel[2], 8.69817733764648438e+02, DELTA);
    }
}
