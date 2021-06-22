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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgObsDepB;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgObsDepBTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepBTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 120, (byte) 46, (byte) 39, (byte) 0, (byte) 251, (byte) 6, (byte) 32,
                    (byte) 180, (byte) 175, (byte) 187, (byte) 133, (byte) 223, (byte) 53, (byte) 7,
                    (byte) 7, (byte) 27, (byte) 157, (byte) 0, (byte) 0, (byte) 202, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 58, (byte) 140, (byte) 85, (byte) 147, (byte) 88,
                    (byte) 28, (byte) 190, (byte) 7, (byte) 175, (byte) 144, (byte) 0, (byte) 0,
                    (byte) 203, (byte) 0, (byte) 0, (byte) 0, (byte) 220, (byte) 140, (byte) 248,
                    (byte) 138, (byte) 208, (byte) 172, (byte) 77, (byte) 7, (byte) 135, (byte) 151,
                    (byte) 0, (byte) 0, (byte) 208, (byte) 0, (byte) 0, (byte) 0, (byte) 173,
                    (byte) 194, (byte) 72, (byte) 135, (byte) 115, (byte) 18, (byte) 28, (byte) 7,
                    (byte) 242, (byte) 156, (byte) 0, (byte) 0, (byte) 212, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 164, (byte) 144, (byte) 105, (byte) 124, (byte) 18, (byte) 196,
                    (byte) 137, (byte) 6, (byte) 120, (byte) 168, (byte) 0, (byte) 0, (byte) 217,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 30, (byte) 232, (byte) 228, (byte) 139,
                    (byte) 210, (byte) 7, (byte) 90, (byte) 7, (byte) 87, (byte) 150, (byte) 0,
                    (byte) 0, (byte) 218, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x43, payload);
        MsgObsDepB msg = new MsgObsDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 2567800 + "'",
                    value.equals(BigInteger.valueOf(2567800L)));
        } else {
            value = value.longValue();
            expected = 2567800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1787 + "'",
                    value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 117913055 + "'",
                    value.equals(BigInteger.valueOf(117913055L)));
        } else {
            value = value.longValue();
            expected = 117913055L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2243669940L + "'",
                    value.equals(new BigInteger("2243669940")));
        } else {
            value = value.longValue();
            expected = 2243669940L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 129899608 + "'",
                    value.equals(BigInteger.valueOf(129899608L)));
        } else {
            value = value.longValue();
            expected = 129899608L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2471857210L + "'",
                    value.equals(new BigInteger("2471857210")));
        } else {
            value = value.longValue();
            expected = 2471857210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 122531024 + "'",
                    value.equals(BigInteger.valueOf(122531024L)));
        } else {
            value = value.longValue();
            expected = 122531024L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2331544796L + "'",
                    value.equals(new BigInteger("2331544796")));
        } else {
            value = value.longValue();
            expected = 2331544796L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 119280243 + "'",
                    value.equals(BigInteger.valueOf(119280243L)));
        } else {
            value = value.longValue();
            expected = 119280243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2269692589L + "'",
                    value.equals(new BigInteger("2269692589")));
        } else {
            value = value.longValue();
            expected = 2269692589L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 109691922 + "'",
                    value.equals(BigInteger.valueOf(109691922L)));
        } else {
            value = value.longValue();
            expected = 109691922L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 2087293092 + "'",
                    value.equals(BigInteger.valueOf(2087293092L)));
        } else {
            value = value.longValue();
            expected = 2087293092L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.f + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.i + "' != '" + 123340754 + "'",
                    value.equals(BigInteger.valueOf(123340754L)));
        } else {
            value = value.longValue();
            expected = 123340754L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].P + "' != '" + 2347034654L + "'",
                    value.equals(new BigInteger("2347034654")));
        } else {
            value = value.longValue();
            expected = 2347034654L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].cn0 + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepBTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 120,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 251,
                    (byte) 6,
                    (byte) 33,
                    (byte) 68,
                    (byte) 199,
                    (byte) 101,
                    (byte) 136,
                    (byte) 133,
                    (byte) 247,
                    (byte) 42,
                    (byte) 7,
                    (byte) 219,
                    (byte) 154,
                    (byte) 0,
                    (byte) 0,
                    (byte) 220,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 219,
                    (byte) 14,
                    (byte) 123,
                    (byte) 133,
                    (byte) 96,
                    (byte) 215,
                    (byte) 3,
                    (byte) 7,
                    (byte) 235,
                    (byte) 156,
                    (byte) 0,
                    (byte) 0,
                    (byte) 222,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 87,
                    (byte) 166,
                    (byte) 81,
                    (byte) 122,
                    (byte) 5,
                    (byte) 173,
                    (byte) 109,
                    (byte) 6,
                    (byte) 174,
                    (byte) 170,
                    (byte) 0,
                    (byte) 0,
                    (byte) 225,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x43, payload);
        MsgObsDepB msg = new MsgObsDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 2567800 + "'",
                    value.equals(BigInteger.valueOf(2567800L)));
        } else {
            value = value.longValue();
            expected = 2567800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1787 + "'",
                    value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 120256389 + "'",
                    value.equals(BigInteger.valueOf(120256389L)));
        } else {
            value = value.longValue();
            expected = 120256389L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2288371524L + "'",
                    value.equals(new BigInteger("2288371524")));
        } else {
            value = value.longValue();
            expected = 2288371524L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 154 + "'",
                    value.equals(BigInteger.valueOf(154L)));
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 117692256 + "'",
                    value.equals(BigInteger.valueOf(117692256L)));
        } else {
            value = value.longValue();
            expected = 117692256L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2239434459L + "'",
                    value.equals(new BigInteger("2239434459")));
        } else {
            value = value.longValue();
            expected = 2239434459L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 107851013 + "'",
                    value.equals(BigInteger.valueOf(107851013L)));
        } else {
            value = value.longValue();
            expected = 107851013L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2052171351 + "'",
                    value.equals(BigInteger.valueOf(2052171351L)));
        } else {
            value = value.longValue();
            expected = 2052171351L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepBTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 64, (byte) 47, (byte) 39, (byte) 0, (byte) 251, (byte) 6, (byte) 32,
                    (byte) 100, (byte) 132, (byte) 187, (byte) 133, (byte) 236, (byte) 51, (byte) 7,
                    (byte) 7, (byte) 94, (byte) 156, (byte) 0, (byte) 0, (byte) 202, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 97, (byte) 184, (byte) 85, (byte) 147, (byte) 178,
                    (byte) 30, (byte) 190, (byte) 7, (byte) 40, (byte) 140, (byte) 0, (byte) 0,
                    (byte) 203, (byte) 0, (byte) 0, (byte) 0, (byte) 135, (byte) 111, (byte) 248,
                    (byte) 138, (byte) 90, (byte) 171, (byte) 77, (byte) 7, (byte) 2, (byte) 150,
                    (byte) 0, (byte) 0, (byte) 208, (byte) 0, (byte) 0, (byte) 0, (byte) 180,
                    (byte) 238, (byte) 72, (byte) 135, (byte) 190, (byte) 20, (byte) 28, (byte) 7,
                    (byte) 241, (byte) 155, (byte) 0, (byte) 0, (byte) 212, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 15, (byte) 153, (byte) 105, (byte) 124, (byte) 92, (byte) 196,
                    (byte) 137, (byte) 6, (byte) 153, (byte) 168, (byte) 0, (byte) 0, (byte) 217,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 49, (byte) 185, (byte) 228, (byte) 139,
                    (byte) 144, (byte) 5, (byte) 90, (byte) 7, (byte) 41, (byte) 150, (byte) 0,
                    (byte) 0, (byte) 218, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x43, payload);
        MsgObsDepB msg = new MsgObsDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 2568000 + "'",
                    value.equals(BigInteger.valueOf(2568000L)));
        } else {
            value = value.longValue();
            expected = 2568000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1787 + "'",
                    value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 94 + "'",
                    value.equals(BigInteger.valueOf(94L)));
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 117912556 + "'",
                    value.equals(BigInteger.valueOf(117912556L)));
        } else {
            value = value.longValue();
            expected = 117912556L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2243658852L + "'",
                    value.equals(new BigInteger("2243658852")));
        } else {
            value = value.longValue();
            expected = 2243658852L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 129900210 + "'",
                    value.equals(BigInteger.valueOf(129900210L)));
        } else {
            value = value.longValue();
            expected = 129900210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2471868513L + "'",
                    value.equals(new BigInteger("2471868513")));
        } else {
            value = value.longValue();
            expected = 2471868513L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 122530650 + "'",
                    value.equals(BigInteger.valueOf(122530650L)));
        } else {
            value = value.longValue();
            expected = 122530650L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2331537287L + "'",
                    value.equals(new BigInteger("2331537287")));
        } else {
            value = value.longValue();
            expected = 2331537287L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 119280830 + "'",
                    value.equals(BigInteger.valueOf(119280830L)));
        } else {
            value = value.longValue();
            expected = 119280830L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2269703860L + "'",
                    value.equals(new BigInteger("2269703860")));
        } else {
            value = value.longValue();
            expected = 2269703860L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 109691996 + "'",
                    value.equals(BigInteger.valueOf(109691996L)));
        } else {
            value = value.longValue();
            expected = 109691996L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 2087295247 + "'",
                    value.equals(BigInteger.valueOf(2087295247L)));
        } else {
            value = value.longValue();
            expected = 2087295247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.f + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.i + "' != '" + 123340176 + "'",
                    value.equals(BigInteger.valueOf(123340176L)));
        } else {
            value = value.longValue();
            expected = 123340176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].P + "' != '" + 2347022641L + "'",
                    value.equals(new BigInteger("2347022641")));
        } else {
            value = value.longValue();
            expected = 2347022641L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].cn0 + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepBTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 64,
                    (byte) 47,
                    (byte) 39,
                    (byte) 0,
                    (byte) 251,
                    (byte) 6,
                    (byte) 33,
                    (byte) 234,
                    (byte) 148,
                    (byte) 101,
                    (byte) 136,
                    (byte) 15,
                    (byte) 245,
                    (byte) 42,
                    (byte) 7,
                    (byte) 20,
                    (byte) 154,
                    (byte) 0,
                    (byte) 0,
                    (byte) 220,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 208,
                    (byte) 247,
                    (byte) 122,
                    (byte) 133,
                    (byte) 16,
                    (byte) 214,
                    (byte) 3,
                    (byte) 7,
                    (byte) 38,
                    (byte) 156,
                    (byte) 0,
                    (byte) 0,
                    (byte) 222,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 150,
                    (byte) 81,
                    (byte) 122,
                    (byte) 22,
                    (byte) 172,
                    (byte) 109,
                    (byte) 6,
                    (byte) 7,
                    (byte) 172,
                    (byte) 0,
                    (byte) 0,
                    (byte) 225,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x43, payload);
        MsgObsDepB msg = new MsgObsDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 2568000 + "'",
                    value.equals(BigInteger.valueOf(2568000L)));
        } else {
            value = value.longValue();
            expected = 2568000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1787 + "'",
                    value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 120255759 + "'",
                    value.equals(BigInteger.valueOf(120255759L)));
        } else {
            value = value.longValue();
            expected = 120255759L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2288358634L + "'",
                    value.equals(new BigInteger("2288358634")));
        } else {
            value = value.longValue();
            expected = 2288358634L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 154 + "'",
                    value.equals(BigInteger.valueOf(154L)));
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 117691920 + "'",
                    value.equals(BigInteger.valueOf(117691920L)));
        } else {
            value = value.longValue();
            expected = 117691920L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2239428560L + "'",
                    value.equals(new BigInteger("2239428560")));
        } else {
            value = value.longValue();
            expected = 2239428560L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 107850774 + "'",
                    value.equals(BigInteger.valueOf(107850774L)));
        } else {
            value = value.longValue();
            expected = 107850774L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2052167183 + "'",
                    value.equals(BigInteger.valueOf(2052167183L)));
        } else {
            value = value.longValue();
            expected = 2052167183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepBTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 8,
                    (byte) 48,
                    (byte) 39,
                    (byte) 0,
                    (byte) 251,
                    (byte) 6,
                    (byte) 32,
                    (byte) 254,
                    (byte) 96,
                    (byte) 187,
                    (byte) 133,
                    (byte) 249,
                    (byte) 49,
                    (byte) 7,
                    (byte) 7,
                    (byte) 165,
                    (byte) 156,
                    (byte) 0,
                    (byte) 0,
                    (byte) 202,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 113,
                    (byte) 229,
                    (byte) 85,
                    (byte) 147,
                    (byte) 11,
                    (byte) 33,
                    (byte) 190,
                    (byte) 7,
                    (byte) 106,
                    (byte) 143,
                    (byte) 0,
                    (byte) 0,
                    (byte) 203,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 182,
                    (byte) 85,
                    (byte) 248,
                    (byte) 138,
                    (byte) 227,
                    (byte) 169,
                    (byte) 77,
                    (byte) 7,
                    (byte) 159,
                    (byte) 150,
                    (byte) 0,
                    (byte) 0,
                    (byte) 208,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 17,
                    (byte) 24,
                    (byte) 73,
                    (byte) 135,
                    (byte) 10,
                    (byte) 23,
                    (byte) 28,
                    (byte) 7,
                    (byte) 7,
                    (byte) 156,
                    (byte) 0,
                    (byte) 0,
                    (byte) 212,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 108,
                    (byte) 155,
                    (byte) 105,
                    (byte) 124,
                    (byte) 166,
                    (byte) 196,
                    (byte) 137,
                    (byte) 6,
                    (byte) 186,
                    (byte) 170,
                    (byte) 0,
                    (byte) 0,
                    (byte) 217,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 214,
                    (byte) 142,
                    (byte) 228,
                    (byte) 139,
                    (byte) 77,
                    (byte) 3,
                    (byte) 90,
                    (byte) 7,
                    (byte) 236,
                    (byte) 151,
                    (byte) 0,
                    (byte) 0,
                    (byte) 218,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x43, payload);
        MsgObsDepB msg = new MsgObsDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 2568200 + "'",
                    value.equals(BigInteger.valueOf(2568200L)));
        } else {
            value = value.longValue();
            expected = 2568200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1787 + "'",
                    value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 117912057 + "'",
                    value.equals(BigInteger.valueOf(117912057L)));
        } else {
            value = value.longValue();
            expected = 117912057L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2243649790L + "'",
                    value.equals(new BigInteger("2243649790")));
        } else {
            value = value.longValue();
            expected = 2243649790L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 129900811 + "'",
                    value.equals(BigInteger.valueOf(129900811L)));
        } else {
            value = value.longValue();
            expected = 129900811L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2471880049L + "'",
                    value.equals(new BigInteger("2471880049")));
        } else {
            value = value.longValue();
            expected = 2471880049L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 122530275 + "'",
                    value.equals(BigInteger.valueOf(122530275L)));
        } else {
            value = value.longValue();
            expected = 122530275L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2331530678L + "'",
                    value.equals(new BigInteger("2331530678")));
        } else {
            value = value.longValue();
            expected = 2331530678L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 119281418 + "'",
                    value.equals(BigInteger.valueOf(119281418L)));
        } else {
            value = value.longValue();
            expected = 119281418L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2269714449L + "'",
                    value.equals(new BigInteger("2269714449")));
        } else {
            value = value.longValue();
            expected = 2269714449L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 109692070 + "'",
                    value.equals(BigInteger.valueOf(109692070L)));
        } else {
            value = value.longValue();
            expected = 109692070L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 2087295852 + "'",
                    value.equals(BigInteger.valueOf(2087295852L)));
        } else {
            value = value.longValue();
            expected = 2087295852L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.f + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.i + "' != '" + 123339597 + "'",
                    value.equals(BigInteger.valueOf(123339597L)));
        } else {
            value = value.longValue();
            expected = 123339597L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].P + "' != '" + 2347011798L + "'",
                    value.equals(new BigInteger("2347011798")));
        } else {
            value = value.longValue();
            expected = 2347011798L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].cn0 + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].lock + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
