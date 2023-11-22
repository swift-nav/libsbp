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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisDepD.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisDepD;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgEphemerisDepDTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgEphemerisDepDTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 83,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 74,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 74,
                    (byte) 115,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
                    (byte) 199,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 80,
                    (byte) 202,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 127,
                    (byte) 190,
                    (byte) 114,
                    (byte) 216,
                    (byte) 96,
                    (byte) 180,
                    (byte) 49,
                    (byte) 117,
                    (byte) 56,
                    (byte) 62,
                    (byte) 142,
                    (byte) 41,
                    (byte) 5,
                    (byte) 235,
                    (byte) 95,
                    (byte) 135,
                    (byte) 150,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 32,
                    (byte) 191,
                    (byte) 247,
                    (byte) 124,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 206,
                    (byte) 140,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 41,
                    (byte) 131,
                    (byte) 179,
                    (byte) 134,
                    (byte) 141,
                    (byte) 248,
                    (byte) 253,
                    (byte) 191,
                    (byte) 227,
                    (byte) 133,
                    (byte) 81,
                    (byte) 54,
                    (byte) 204,
                    (byte) 30,
                    (byte) 67,
                    (byte) 190,
                    (byte) 216,
                    (byte) 59,
                    (byte) 199,
                    (byte) 39,
                    (byte) 96,
                    (byte) 168,
                    (byte) 239,
                    (byte) 191,
                    (byte) 71,
                    (byte) 11,
                    (byte) 217,
                    (byte) 147,
                    (byte) 145,
                    (byte) 228,
                    (byte) 237,
                    (byte) 63,
                    (byte) 221,
                    (byte) 47,
                    (byte) 100,
                    (byte) 224,
                    (byte) 255,
                    (byte) 47,
                    (byte) 198,
                    (byte) 189,
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
                    (byte) 154,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 201,
                    (byte) 63,
                    (byte) 205,
                    (byte) 204,
                    (byte) 204,
                    (byte) 204,
                    (byte) 192,
                    (byte) 62,
                    (byte) 27,
                    (byte) 65,
                    (byte) 106,
                    (byte) 8,
                    (byte) 205,
                    (byte) 204,
                    (byte) 204,
                    (byte) 204,
                    (byte) 192,
                    (byte) 62,
                    (byte) 27,
                    (byte) 65,
                    (byte) 106,
                    (byte) 8,
                    (byte) 1,
                    (byte) 0,
                    (byte) 22,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 45,
                    (byte) 45,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0x80, payload);
        MsgEphemerisDepD msg = new MsgEphemerisDepD(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -6.31501898169517517e-04, DELTA);
        org.junit.Assert.assertEquals(msg.af1, 8.98126018000766635e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 2.00000000000000011e-01, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, 7.45058059692382812e-09, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, -1.15483999252319336e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 3.08625000000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, -5.23125000000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, -2.74367630481719971e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 3.13669443130493164e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 5.69452291402237483e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 7.07220705226063728e-03, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.34151448025979714e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, -4.03588239641575691e-11, DELTA);
        value = msg.iodc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iodc + "' != '" + 45 + "'", value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 45 + "'", value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, -2.20007884211468815e-02, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, -1.87318184487976169e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -8.90358515577419627e-09, DELTA);
        value = msg.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 22 + "'", value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15355002975463867e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -1.76951289176940918e-08, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.46384200000000012e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.46384200000000012e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.valid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.valid + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.w, -9.89303662959964747e-01, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
