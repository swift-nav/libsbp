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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisBds;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgEphemerisBdsTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgEphemerisBdsTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 8,
                    (byte) 12,
                    (byte) 174,
                    (byte) 179,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 48,
                    (byte) 42,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 125,
                    (byte) 99,
                    (byte) 52,
                    (byte) 50,
                    (byte) 207,
                    (byte) 46,
                    (byte) 151,
                    (byte) 176,
                    (byte) 0,
                    (byte) 112,
                    (byte) 96,
                    (byte) 67,
                    (byte) 0,
                    (byte) 164,
                    (byte) 106,
                    (byte) 67,
                    (byte) 0,
                    (byte) 60,
                    (byte) 255,
                    (byte) 54,
                    (byte) 0,
                    (byte) 224,
                    (byte) 47,
                    (byte) 53,
                    (byte) 0,
                    (byte) 0,
                    (byte) 143,
                    (byte) 179,
                    (byte) 0,
                    (byte) 192,
                    (byte) 190,
                    (byte) 52,
                    (byte) 146,
                    (byte) 101,
                    (byte) 162,
                    (byte) 196,
                    (byte) 109,
                    (byte) 104,
                    (byte) 19,
                    (byte) 62,
                    (byte) 253,
                    (byte) 87,
                    (byte) 86,
                    (byte) 202,
                    (byte) 62,
                    (byte) 28,
                    (byte) 251,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 96,
                    (byte) 151,
                    (byte) 60,
                    (byte) 117,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 154,
                    (byte) 127,
                    (byte) 93,
                    (byte) 185,
                    (byte) 64,
                    (byte) 151,
                    (byte) 193,
                    (byte) 64,
                    (byte) 0,
                    (byte) 10,
                    (byte) 166,
                    (byte) 4,
                    (byte) 192,
                    (byte) 160,
                    (byte) 75,
                    (byte) 174,
                    (byte) 98,
                    (byte) 8,
                    (byte) 201,
                    (byte) 35,
                    (byte) 190,
                    (byte) 205,
                    (byte) 29,
                    (byte) 12,
                    (byte) 71,
                    (byte) 189,
                    (byte) 150,
                    (byte) 5,
                    (byte) 192,
                    (byte) 176,
                    (byte) 72,
                    (byte) 249,
                    (byte) 189,
                    (byte) 193,
                    (byte) 172,
                    (byte) 240,
                    (byte) 63,
                    (byte) 72,
                    (byte) 249,
                    (byte) 188,
                    (byte) 180,
                    (byte) 160,
                    (byte) 203,
                    (byte) 9,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 92,
                    (byte) 51,
                    (byte) 77,
                    (byte) 191,
                    (byte) 0,
                    (byte) 128,
                    (byte) 174,
                    (byte) 43,
                    (byte) 0,
                    (byte) 0,
                    (byte) 88,
                    (byte) 161,
                    (byte) 174,
                    (byte) 179,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 6,
                    (byte) 5,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xf080, 0x89, payload);
        MsgEphemerisBds msg = new MsgEphemerisBds(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -8.91132280230522156e-04, DELTA);
        org.junit.Assert.assertEquals(msg.af1, 1.23989707390137482e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, -7.31836466427715493e-19, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, -6.65895640850067139e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, 3.55299562215805054e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 2.34640625000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, 2.24437500000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, 7.60657712817192078e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 6.55185431241989136e-07, DELTA);
        value = msg.common.fit_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.fit_interval + "' != '" + 10800 + "'",
                    value.equals(BigInteger.valueOf(10800L)));
        } else {
            value = value.longValue();
            expected = 10800L;
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
                    "'" + msg.common.sid.code + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.sat + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toe.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toe.tow + "' != '" + 439214 + "'",
                    value.equals(BigInteger.valueOf(439214L)));
        } else {
            value = value.longValue();
            expected = 439214L;
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
        org.junit.Assert.assertEquals(msg.dn, 1.12968991326221325e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 5.18473749980330467e-03, DELTA);
        org.junit.Assert.assertEquals(msg.inc, 1.04217695435049151e+00, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, 7.50745557280168303e-10, DELTA);
        value = msg.iodc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iodc + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, 1.69439581907272374e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, -2.58107376287098189e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -2.30331022783054511e-09, DELTA);
        org.junit.Assert.assertEquals(msg.sqrta, 6.49349845123291016e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd1, 1.04999999805954758e-08, DELTA);
        org.junit.Assert.assertEquals(msg.tgd2, -1.09999997999210564e-09, DELTA);
        value = msg.toc.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc.tow + "' != '" + 439214 + "'",
                    value.equals(BigInteger.valueOf(439214L)));
        } else {
            value = value.longValue();
            expected = 439214L;
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
        org.junit.Assert.assertEquals(msg.w, -2.69860320573545787e+00, DELTA);
    }
}
