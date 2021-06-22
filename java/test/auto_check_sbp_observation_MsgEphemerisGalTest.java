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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGal.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisGal;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgEphemerisGalTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgEphemerisGalTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 27,
                    (byte) 14,
                    (byte) 32,
                    (byte) 217,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 20,
                    (byte) 174,
                    (byte) 71,
                    (byte) 64,
                    (byte) 64,
                    (byte) 56,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 16,
                    (byte) 49,
                    (byte) 0,
                    (byte) 0,
                    (byte) 16,
                    (byte) 49,
                    (byte) 0,
                    (byte) 0,
                    (byte) 34,
                    (byte) 65,
                    (byte) 0,
                    (byte) 184,
                    (byte) 132,
                    (byte) 67,
                    (byte) 0,
                    (byte) 0,
                    (byte) 16,
                    (byte) 53,
                    (byte) 0,
                    (byte) 0,
                    (byte) 134,
                    (byte) 54,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 179,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 179,
                    (byte) 217,
                    (byte) 204,
                    (byte) 130,
                    (byte) 105,
                    (byte) 128,
                    (byte) 182,
                    (byte) 43,
                    (byte) 62,
                    (byte) 248,
                    (byte) 106,
                    (byte) 31,
                    (byte) 220,
                    (byte) 8,
                    (byte) 136,
                    (byte) 253,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 151,
                    (byte) 92,
                    (byte) 38,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 55,
                    (byte) 154,
                    (byte) 64,
                    (byte) 181,
                    (byte) 64,
                    (byte) 56,
                    (byte) 38,
                    (byte) 1,
                    (byte) 141,
                    (byte) 255,
                    (byte) 182,
                    (byte) 242,
                    (byte) 63,
                    (byte) 222,
                    (byte) 147,
                    (byte) 136,
                    (byte) 39,
                    (byte) 79,
                    (byte) 186,
                    (byte) 56,
                    (byte) 190,
                    (byte) 80,
                    (byte) 114,
                    (byte) 204,
                    (byte) 251,
                    (byte) 193,
                    (byte) 92,
                    (byte) 191,
                    (byte) 63,
                    (byte) 237,
                    (byte) 55,
                    (byte) 19,
                    (byte) 41,
                    (byte) 177,
                    (byte) 73,
                    (byte) 239,
                    (byte) 63,
                    (byte) 49,
                    (byte) 65,
                    (byte) 189,
                    (byte) 240,
                    (byte) 8,
                    (byte) 216,
                    (byte) 245,
                    (byte) 189,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 67,
                    (byte) 235,
                    (byte) 241,
                    (byte) 190,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 161,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 32,
                    (byte) 217,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 108,
                    (byte) 0,
                    (byte) 108,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xf080, 0x8d, payload);
        MsgEphemerisGal msg = new MsgEphemerisGal(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -1.70888961292803254e-05, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -8.18545231595635253e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.bgd_e1e5a, 2.09547579288482666e-09, DELTA);
        org.junit.Assert.assertEquals(msg.bgd_e1e5b, 2.09547579288482666e-09, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, -3.16649675369262695e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, -3.16649675369262695e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 2.65437500000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, 1.01250000000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, 5.36441802978515625e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 3.99351119995117188e-06, DELTA);
        value = msg.common.fit_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.fit_interval + "' != '" + 14400 + "'",
                    value.equals(BigInteger.valueOf(14400L)));
        } else {
            value = value.longValue();
            expected = 14400L;
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
                    "'" + msg.common.sid.code + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.sat + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toe.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toe.tow + "' != '" + 448800 + "'",
                    value.equals(BigInteger.valueOf(448800L)));
        } else {
            value = value.longValue();
            expected = 448800L;
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
        org.junit.Assert.assertEquals(msg.common.ura, 3.11999988555908203e+00, DELTA);
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
        org.junit.Assert.assertEquals(msg.dn, 3.22620581299322575e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 1.70606072060763836e-04, DELTA);
        org.junit.Assert.assertEquals(msg.inc, 9.77745609497785773e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, -3.17870383434514646e-10, DELTA);
        value = msg.iodc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iodc + "' != '" + 108 + "'", value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 108 + "'", value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, -1.84571157441558675e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, 1.16967730598334008e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -5.75738267524087236e-09, DELTA);
        value = msg.source;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.source + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.44060240173339844e+03, DELTA);
        value = msg.toc.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc.tow + "' != '" + 448800 + "'",
                    value.equals(BigInteger.valueOf(448800L)));
        } else {
            value = value.longValue();
            expected = 448800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.toc.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc.wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.w, 1.22509120916626246e-01, DELTA);
    }
}
