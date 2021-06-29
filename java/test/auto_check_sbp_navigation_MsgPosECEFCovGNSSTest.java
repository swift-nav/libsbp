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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPosECEFCovGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPosECEFCovGNSSTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosECEFCovGNSSTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 24,
                    (byte) 229,
                    (byte) 233,
                    (byte) 29,
                    (byte) 52,
                    (byte) 254,
                    (byte) 158,
                    (byte) 218,
                    (byte) 42,
                    (byte) 142,
                    (byte) 68,
                    (byte) 193,
                    (byte) 69,
                    (byte) 162,
                    (byte) 89,
                    (byte) 91,
                    (byte) 34,
                    (byte) 68,
                    (byte) 80,
                    (byte) 193,
                    (byte) 131,
                    (byte) 21,
                    (byte) 176,
                    (byte) 129,
                    (byte) 239,
                    (byte) 174,
                    (byte) 77,
                    (byte) 65,
                    (byte) 158,
                    (byte) 232,
                    (byte) 30,
                    (byte) 60,
                    (byte) 218,
                    (byte) 221,
                    (byte) 20,
                    (byte) 60,
                    (byte) 129,
                    (byte) 136,
                    (byte) 198,
                    (byte) 187,
                    (byte) 205,
                    (byte) 120,
                    (byte) 166,
                    (byte) 60,
                    (byte) 5,
                    (byte) 166,
                    (byte) 35,
                    (byte) 188,
                    (byte) 122,
                    (byte) 177,
                    (byte) 115,
                    (byte) 60,
                    (byte) 18,
                    (byte) 4,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0x234, payload);
        MsgPosECEFCovGnss msg = new MsgPosECEFCovGnss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_x_x, 9.69901494681835175e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_x_y, 9.08609665930271149e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_x_z, -6.05875300243496895e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_y_y, 2.03212741762399673e-02, DELTA);
        org.junit.Assert.assertEquals(msg.cov_y_z, -9.98831260949373245e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_z_z, 1.48738566786050797e-02, DELTA);
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
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
        org.junit.Assert.assertEquals(msg.x, -2.69422970797708072e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.26407342734581698e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.89065501318615815e+06, DELTA);
    }
}
