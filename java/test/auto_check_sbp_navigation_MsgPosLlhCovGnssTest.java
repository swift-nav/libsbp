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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosLLHCovGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosLlhCovGnssTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLlhCovGnssTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 24,
                    (byte) 229,
                    (byte) 233,
                    (byte) 29,
                    (byte) 73,
                    (byte) 123,
                    (byte) 28,
                    (byte) 207,
                    (byte) 101,
                    (byte) 234,
                    (byte) 66,
                    (byte) 64,
                    (byte) 100,
                    (byte) 168,
                    (byte) 19,
                    (byte) 20,
                    (byte) 86,
                    (byte) 146,
                    (byte) 94,
                    (byte) 192,
                    (byte) 214,
                    (byte) 198,
                    (byte) 35,
                    (byte) 120,
                    (byte) 209,
                    (byte) 100,
                    (byte) 49,
                    (byte) 192,
                    (byte) 12,
                    (byte) 102,
                    (byte) 245,
                    (byte) 59,
                    (byte) 6,
                    (byte) 181,
                    (byte) 192,
                    (byte) 185,
                    (byte) 168,
                    (byte) 79,
                    (byte) 243,
                    (byte) 58,
                    (byte) 96,
                    (byte) 60,
                    (byte) 148,
                    (byte) 59,
                    (byte) 253,
                    (byte) 58,
                    (byte) 93,
                    (byte) 186,
                    (byte) 159,
                    (byte) 174,
                    (byte) 6,
                    (byte) 61,
                    (byte) 18,
                    (byte) 4,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0x231, payload);
        MsgPosLLHCovGnss msg = new MsgPosLLHCovGnss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_d_d, 3.28813754022121429e-02, DELTA);
        org.junit.Assert.assertEquals(msg.cov_e_d, -8.43927089590579271e-04, DELTA);
        org.junit.Assert.assertEquals(msg.cov_e_e, 4.52379882335662842e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_d, 1.85631681233644485e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_e, -3.67559667211025953e-04, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_n, 7.48897157609462738e-03, DELTA);
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.height, -1.73938212478013483e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.78312319649763324e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.22286503810116812e+02, DELTA);
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 18 + "'", value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
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
    }
}
