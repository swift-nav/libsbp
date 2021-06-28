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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisDepB.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgEphemerisDepB;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_msgEphemerisDepBTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisDepBTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 60,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 186,
                    (byte) 82,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 76,
                    (byte) 109,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 132,
                    (byte) 208,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 254,
                    (byte) 220,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 113,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 133,
                    (byte) 190,
                    (byte) 28,
                    (byte) 36,
                    (byte) 25,
                    (byte) 81,
                    (byte) 223,
                    (byte) 254,
                    (byte) 52,
                    (byte) 62,
                    (byte) 220,
                    (byte) 116,
                    (byte) 216,
                    (byte) 39,
                    (byte) 33,
                    (byte) 189,
                    (byte) 3,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 156,
                    (byte) 177,
                    (byte) 204,
                    (byte) 134,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 160,
                    (byte) 220,
                    (byte) 182,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 152,
                    (byte) 225,
                    (byte) 192,
                    (byte) 44,
                    (byte) 254,
                    (byte) 76,
                    (byte) 238,
                    (byte) 191,
                    (byte) 41,
                    (byte) 150,
                    (byte) 24,
                    (byte) 2,
                    (byte) 148,
                    (byte) 156,
                    (byte) 65,
                    (byte) 190,
                    (byte) 252,
                    (byte) 90,
                    (byte) 119,
                    (byte) 48,
                    (byte) 15,
                    (byte) 215,
                    (byte) 240,
                    (byte) 63,
                    (byte) 124,
                    (byte) 127,
                    (byte) 115,
                    (byte) 94,
                    (byte) 208,
                    (byte) 16,
                    (byte) 238,
                    (byte) 63,
                    (byte) 165,
                    (byte) 115,
                    (byte) 52,
                    (byte) 74,
                    (byte) 97,
                    (byte) 167,
                    (byte) 246,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 180,
                    (byte) 229,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 112,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 1,
                    (byte) 1,
                    (byte) 3,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x46, payload);
        MsgEphemerisDepB msg = new MsgEphemerisDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -1.03502534329891205e-05, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -9.09494701772928238e-13, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, 6.33299350738525391e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, -1.56462192535400391e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 2.34375000000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, -7.49062500000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, -3.93763184547424316e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 6.91227614879608154e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 4.88841790794180047e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 1.11326099140569568e-02, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.39552483057908727e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, -3.29656588662985413e-10, DELTA);
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, 2.46734839562723884e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, -9.46898543747965782e-01, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -8.20105589261047769e-09, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15371430397033691e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -6.51925802230834961e-09, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
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
        org.junit.Assert.assertEquals(msg.w, 1.05250472004053020e+00, DELTA);
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisDepBTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 68,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 72,
                    (byte) 66,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 188,
                    (byte) 115,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 80,
                    (byte) 193,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 164,
                    (byte) 204,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 130,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 62,
                    (byte) 72,
                    (byte) 181,
                    (byte) 127,
                    (byte) 6,
                    (byte) 208,
                    (byte) 225,
                    (byte) 52,
                    (byte) 62,
                    (byte) 158,
                    (byte) 174,
                    (byte) 129,
                    (byte) 91,
                    (byte) 27,
                    (byte) 105,
                    (byte) 249,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 96,
                    (byte) 204,
                    (byte) 57,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 160,
                    (byte) 35,
                    (byte) 146,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 247,
                    (byte) 169,
                    (byte) 1,
                    (byte) 36,
                    (byte) 133,
                    (byte) 206,
                    (byte) 243,
                    (byte) 63,
                    (byte) 79,
                    (byte) 11,
                    (byte) 109,
                    (byte) 92,
                    (byte) 156,
                    (byte) 208,
                    (byte) 65,
                    (byte) 190,
                    (byte) 103,
                    (byte) 78,
                    (byte) 3,
                    (byte) 253,
                    (byte) 223,
                    (byte) 147,
                    (byte) 255,
                    (byte) 191,
                    (byte) 164,
                    (byte) 214,
                    (byte) 90,
                    (byte) 250,
                    (byte) 218,
                    (byte) 240,
                    (byte) 238,
                    (byte) 63,
                    (byte) 94,
                    (byte) 239,
                    (byte) 187,
                    (byte) 37,
                    (byte) 36,
                    (byte) 10,
                    (byte) 242,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 176,
                    (byte) 91,
                    (byte) 19,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 137,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 1,
                    (byte) 1,
                    (byte) 13,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x46, payload);
        MsgEphemerisDepB msg = new MsgEphemerisDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, 7.38454982638359070e-05, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -2.84217094304040074e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, 1.34110450744628906e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, 1.19209289550781250e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 3.15781250000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, 3.65625000000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, 2.06381082534790039e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 3.41422855854034424e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 4.86198823561129038e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 7.92274158447980881e-03, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.66901291822712228e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, 2.62510934634121662e-10, DELTA);
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, -1.58816085572008303e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, 1.23791994156874607e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -8.29570269217244098e-09, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 13 + "'", value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15357085609436035e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -9.31322574615478516e-09, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
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
        org.junit.Assert.assertEquals(msg.w, -1.97360228379411651e+00, DELTA);
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisDepBTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 56,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 81,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 129,
                    (byte) 109,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 28,
                    (byte) 205,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 76,
                    (byte) 223,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 105,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 92,
                    (byte) 190,
                    (byte) 134,
                    (byte) 161,
                    (byte) 223,
                    (byte) 255,
                    (byte) 243,
                    (byte) 43,
                    (byte) 51,
                    (byte) 62,
                    (byte) 146,
                    (byte) 176,
                    (byte) 113,
                    (byte) 142,
                    (byte) 234,
                    (byte) 164,
                    (byte) 5,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 56,
                    (byte) 175,
                    (byte) 140,
                    (byte) 112,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 90,
                    (byte) 171,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 36,
                    (byte) 38,
                    (byte) 237,
                    (byte) 255,
                    (byte) 200,
                    (byte) 160,
                    (byte) 237,
                    (byte) 191,
                    (byte) 204,
                    (byte) 92,
                    (byte) 63,
                    (byte) 154,
                    (byte) 49,
                    (byte) 91,
                    (byte) 65,
                    (byte) 190,
                    (byte) 125,
                    (byte) 94,
                    (byte) 251,
                    (byte) 132,
                    (byte) 52,
                    (byte) 61,
                    (byte) 216,
                    (byte) 63,
                    (byte) 2,
                    (byte) 139,
                    (byte) 28,
                    (byte) 27,
                    (byte) 231,
                    (byte) 199,
                    (byte) 238,
                    (byte) 63,
                    (byte) 124,
                    (byte) 183,
                    (byte) 4,
                    (byte) 180,
                    (byte) 194,
                    (byte) 30,
                    (byte) 247,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 104,
                    (byte) 222,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 96,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 1,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x46, payload);
        MsgEphemerisDepB msg = new MsgEphemerisDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -7.24941492080688477e-06, DELTA);
        org.junit.Assert.assertEquals(msg.af1, 4.54747350886464119e-13, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, -4.65661287307739258e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, -2.60770320892333984e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 2.36031250000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, -6.86250000000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, -3.47010791301727295e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 7.46175646781921387e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 4.46375736198265652e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 4.04041714500635862e-03, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.61902192070141604e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, -3.36442585612711049e-10, DELTA);
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, 2.70552550587132945e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, -9.25877094131639655e-01, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -8.08212236712318227e-09, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15366935348510742e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, 5.58793544769287109e-09, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
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
        org.junit.Assert.assertEquals(msg.w, 3.78735666146418570e-01, DELTA);
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisDepBTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 68,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 72,
                    (byte) 66,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 188,
                    (byte) 115,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 80,
                    (byte) 193,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 164,
                    (byte) 204,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 130,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 62,
                    (byte) 72,
                    (byte) 181,
                    (byte) 127,
                    (byte) 6,
                    (byte) 208,
                    (byte) 225,
                    (byte) 52,
                    (byte) 62,
                    (byte) 158,
                    (byte) 174,
                    (byte) 129,
                    (byte) 91,
                    (byte) 27,
                    (byte) 105,
                    (byte) 249,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 96,
                    (byte) 204,
                    (byte) 57,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 160,
                    (byte) 35,
                    (byte) 146,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 247,
                    (byte) 169,
                    (byte) 1,
                    (byte) 36,
                    (byte) 133,
                    (byte) 206,
                    (byte) 243,
                    (byte) 63,
                    (byte) 79,
                    (byte) 11,
                    (byte) 109,
                    (byte) 92,
                    (byte) 156,
                    (byte) 208,
                    (byte) 65,
                    (byte) 190,
                    (byte) 103,
                    (byte) 78,
                    (byte) 3,
                    (byte) 253,
                    (byte) 223,
                    (byte) 147,
                    (byte) 255,
                    (byte) 191,
                    (byte) 164,
                    (byte) 214,
                    (byte) 90,
                    (byte) 250,
                    (byte) 218,
                    (byte) 240,
                    (byte) 238,
                    (byte) 63,
                    (byte) 94,
                    (byte) 239,
                    (byte) 187,
                    (byte) 37,
                    (byte) 36,
                    (byte) 10,
                    (byte) 242,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 176,
                    (byte) 91,
                    (byte) 19,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 137,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 1,
                    (byte) 1,
                    (byte) 13,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x46, payload);
        MsgEphemerisDepB msg = new MsgEphemerisDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, 7.38454982638359070e-05, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -2.84217094304040074e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, 1.34110450744628906e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, 1.19209289550781250e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 3.15781250000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, 3.65625000000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, 2.06381082534790039e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 3.41422855854034424e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 4.86198823561129038e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 7.92274158447980881e-03, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.66901291822712228e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, 2.62510934634121662e-10, DELTA);
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, -1.58816085572008303e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, 1.23791994156874607e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -8.29570269217244098e-09, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 13 + "'", value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15357085609436035e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -9.31322574615478516e-09, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
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
        org.junit.Assert.assertEquals(msg.w, -1.97360228379411651e+00, DELTA);
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisDepBTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 85,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 156,
                    (byte) 69,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 19,
                    (byte) 115,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 160,
                    (byte) 193,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 152,
                    (byte) 207,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 97,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 139,
                    (byte) 190,
                    (byte) 26,
                    (byte) 26,
                    (byte) 13,
                    (byte) 149,
                    (byte) 16,
                    (byte) 152,
                    (byte) 54,
                    (byte) 62,
                    (byte) 104,
                    (byte) 7,
                    (byte) 46,
                    (byte) 214,
                    (byte) 75,
                    (byte) 84,
                    (byte) 5,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 230,
                    (byte) 82,
                    (byte) 132,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 160,
                    (byte) 252,
                    (byte) 162,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 73,
                    (byte) 6,
                    (byte) 130,
                    (byte) 54,
                    (byte) 217,
                    (byte) 171,
                    (byte) 242,
                    (byte) 63,
                    (byte) 81,
                    (byte) 224,
                    (byte) 163,
                    (byte) 123,
                    (byte) 238,
                    (byte) 42,
                    (byte) 66,
                    (byte) 190,
                    (byte) 206,
                    (byte) 43,
                    (byte) 141,
                    (byte) 67,
                    (byte) 243,
                    (byte) 157,
                    (byte) 5,
                    (byte) 192,
                    (byte) 113,
                    (byte) 179,
                    (byte) 153,
                    (byte) 187,
                    (byte) 43,
                    (byte) 92,
                    (byte) 238,
                    (byte) 63,
                    (byte) 254,
                    (byte) 236,
                    (byte) 31,
                    (byte) 43,
                    (byte) 224,
                    (byte) 157,
                    (byte) 244,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 232,
                    (byte) 4,
                    (byte) 26,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 134,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 1,
                    (byte) 1,
                    (byte) 22,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x46, payload);
        MsgEphemerisDepB msg = new MsgEphemerisDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, -9.92552377283573151e-05, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -2.50111042987555265e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, -3.16649675369262695e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, -2.06753611564636230e-07, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 3.05218750000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, 4.32187500000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, 2.10106372833251953e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 3.76626849174499512e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 5.26057626697411973e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 9.92374494671821594e-03, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.48751322180767187e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, 3.00012496724710486e-10, DELTA);
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, -2.66616027191132687e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, 1.16695519725944252e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -8.45999524990263948e-09, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 22 + "'", value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15363666725158691e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -2.00234353542327881e-08, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
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
        org.junit.Assert.assertEquals(msg.w, -2.70212414526529354e+00, DELTA);
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_msgEphemerisDepBTest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 77,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 122,
                    (byte) 83,
                    (byte) 192,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 233,
                    (byte) 110,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 60,
                    (byte) 207,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 28,
                    (byte) 222,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 120,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 108,
                    (byte) 62,
                    (byte) 10,
                    (byte) 230,
                    (byte) 183,
                    (byte) 140,
                    (byte) 214,
                    (byte) 230,
                    (byte) 50,
                    (byte) 62,
                    (byte) 54,
                    (byte) 86,
                    (byte) 196,
                    (byte) 164,
                    (byte) 252,
                    (byte) 10,
                    (byte) 255,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 36,
                    (byte) 247,
                    (byte) 191,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 160,
                    (byte) 5,
                    (byte) 193,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 186,
                    (byte) 138,
                    (byte) 81,
                    (byte) 129,
                    (byte) 88,
                    (byte) 239,
                    (byte) 1,
                    (byte) 64,
                    (byte) 94,
                    (byte) 210,
                    (byte) 120,
                    (byte) 170,
                    (byte) 106,
                    (byte) 25,
                    (byte) 65,
                    (byte) 190,
                    (byte) 103,
                    (byte) 213,
                    (byte) 32,
                    (byte) 155,
                    (byte) 227,
                    (byte) 194,
                    (byte) 224,
                    (byte) 191,
                    (byte) 156,
                    (byte) 47,
                    (byte) 104,
                    (byte) 93,
                    (byte) 101,
                    (byte) 55,
                    (byte) 239,
                    (byte) 63,
                    (byte) 196,
                    (byte) 83,
                    (byte) 100,
                    (byte) 254,
                    (byte) 51,
                    (byte) 54,
                    (byte) 4,
                    (byte) 190,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 50,
                    (byte) 242,
                    (byte) 52,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 114,
                    (byte) 189,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 12,
                    (byte) 25,
                    (byte) 65,
                    (byte) 46,
                    (byte) 7,
                    (byte) 1,
                    (byte) 1,
                    (byte) 30,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x46, payload);
        MsgEphemerisDepB msg = new MsgEphemerisDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.af0, 3.19611746817827225e-04, DELTA);
        org.junit.Assert.assertEquals(msg.af1, -1.02318153949454427e-12, DELTA);
        org.junit.Assert.assertEquals(msg.af2, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.c_ic, 9.12696123123168945e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_is, 5.21540641784667969e-08, DELTA);
        org.junit.Assert.assertEquals(msg.c_rc, 2.47281250000000000e+02, DELTA);
        org.junit.Assert.assertEquals(msg.c_rs, -7.79062500000000000e+01, DELTA);
        org.junit.Assert.assertEquals(msg.c_uc, -3.72342765331268311e-06, DELTA);
        org.junit.Assert.assertEquals(msg.c_us, 7.17863440513610840e-06, DELTA);
        org.junit.Assert.assertEquals(msg.dn, 4.40089760076414576e-09, DELTA);
        org.junit.Assert.assertEquals(msg.ecc, 8.17864493001252413e-03, DELTA);
        value = msg.healthy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.healthy + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.inc, 9.75512201724530126e-01, DELTA);
        org.junit.Assert.assertEquals(msg.inc_dot, -5.88238788220950205e-10, DELTA);
        value = msg.iode;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iode + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.m0, 1.94018234598241923e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omega0, 2.24186802892776615e+00, DELTA);
        org.junit.Assert.assertEquals(msg.omegadot, -7.96247452616749420e-09, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 30 + "'", value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sqrta, 5.15375399208068848e+03, DELTA);
        org.junit.Assert.assertEquals(msg.tgd, -1.35041773319244385e-08, DELTA);
        org.junit.Assert.assertEquals(msg.toc_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toc_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toc_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.toe_tow, 4.10400000000000000e+05, DELTA);
        value = msg.toe_wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.toe_wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
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
        org.junit.Assert.assertEquals(msg.w, -5.23790171608806143e-01, DELTA);
    }
}
