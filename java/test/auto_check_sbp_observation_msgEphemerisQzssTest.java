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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisQzss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_msgEphemerisQzssTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisQzssTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 193,
                    (byte) 31,
                    (byte) 208,
                    (byte) 221,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 64,
                    (byte) 56,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 177,
                    (byte) 0,
                    (byte) 232,
                    (byte) 228,
                    (byte) 195,
                    (byte) 0,
                    (byte) 160,
                    (byte) 19,
                    (byte) 194,
                    (byte) 0,
                    (byte) 224,
                    (byte) 135,
                    (byte) 183,
                    (byte) 0,
                    (byte) 96,
                    (byte) 10,
                    (byte) 55,
                    (byte) 0,
                    (byte) 192,
                    (byte) 157,
                    (byte) 181,
                    (byte) 0,
                    (byte) 0,
                    (byte) 46,
                    (byte) 52,
                    (byte) 167,
                    (byte) 72,
                    (byte) 107,
                    (byte) 105,
                    (byte) 179,
                    (byte) 1,
                    (byte) 39,
                    (byte) 62,
                    (byte) 15,
                    (byte) 224,
                    (byte) 158,
                    (byte) 211,
                    (byte) 241,
                    (byte) 164,
                    (byte) 211,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 24,
                    (byte) 251,
                    (byte) 83,
                    (byte) 179,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 34,
                    (byte) 44,
                    (byte) 93,
                    (byte) 185,
                    (byte) 64,
                    (byte) 143,
                    (byte) 62,
                    (byte) 206,
                    (byte) 232,
                    (byte) 193,
                    (byte) 181,
                    (byte) 242,
                    (byte) 191,
                    (byte) 207,
                    (byte) 216,
                    (byte) 69,
                    (byte) 106,
                    (byte) 98,
                    (byte) 255,
                    (byte) 39,
                    (byte) 190,
                    (byte) 65,
                    (byte) 132,
                    (byte) 95,
                    (byte) 22,
                    (byte) 48,
                    (byte) 15,
                    (byte) 249,
                    (byte) 191,
                    (byte) 249,
                    (byte) 82,
                    (byte) 67,
                    (byte) 94,
                    (byte) 30,
                    (byte) 100,
                    (byte) 231,
                    (byte) 63,
                    (byte) 117,
                    (byte) 167,
                    (byte) 187,
                    (byte) 233,
                    (byte) 187,
                    (byte) 253,
                    (byte) 181,
                    (byte) 61,
                    (byte) 160,
                    (byte) 129,
                    (byte) 193,
                    (byte) 185,
                    (byte) 0,
                    (byte) 0,
                    (byte) 168,
                    (byte) 172,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 208,
                    (byte) 221,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 49,
                    (byte) 49,
                    (byte) 3,
                };
        SBPMessage sbp = new SBPMessage(0xf080, 0x8e, payload);
        MsgEphemerisQzss msg = new MsgEphemerisQzss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -3.69084067642688751e-04, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -4.77484718430787325e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, -1.17532908916473389e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, 1.62050127983093262e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, -3.69062500000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, -4.57812500000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, -1.61975622177124023e-05, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 8.24779272079467773e-06, DELTA);
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
                    "'" + msg.common.sid.code + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.sat + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toe.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toe.tow + "' != '" + 450000 + "'",
                    value.equals(BigInteger.valueOf(450000L)));
        } else {
            value = value.longValue();
            expected = 450000L;
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
                    "'" + msg.common.valid + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.dn, 2.67832584873643293e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 7.55001958459615707e-02, DELTA);
        org.junit.Assert.assertEquals(msg.inc, 7.30971511943237506e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, 2.00008331149806980e-11, DELTA);
        value = msg.iodc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iodc + "' != '" + 817 + "'", value.equals(BigInteger.valueOf(817L)));
        } else {
            value = value.longValue();
            expected = 817L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 49 + "'", value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, 3.06942421589611436e-01, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, -1.16937437953666623e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -2.79368779688176837e-09, DELTA);
        org.junit.Assert.assertEquals(msg.sqrta, 6.49317239379882812e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -5.58793544769287109e-09, DELTA);
        value = msg.toc.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc.tow + "' != '" + 450000 + "'",
                    value.equals(BigInteger.valueOf(450000L)));
        } else {
            value = value.longValue();
            expected = 450000L;
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
        org.junit.Assert.assertEquals(msg.w, -1.56620796908852378e+00, DELTA);
    }
}
