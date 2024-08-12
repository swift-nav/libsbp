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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgFrontEndGain.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgFrontEndGain;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgFrontEndGainTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgFrontEndGainTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 41,
                    (byte) 133,
                    (byte) 134,
                    (byte) 10,
                    (byte) 105,
                    (byte) 20,
                    (byte) 38,
                    (byte) 38,
                    (byte) 246,
                    (byte) 233,
                    (byte) 216,
                    (byte) 80,
                    (byte) 187,
                    (byte) 213,
                    (byte) 85,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0xf5af, 0xbf, payload);
        MsgFrontEndGain msg = new MsgFrontEndGain(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.if_gain[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[0] + "' != '" + -10 + "'",
                    value.equals(BigInteger.valueOf(-10L)));
        } else {
            value = value.longValue();
            expected = -10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[1] + "' != '" + -23 + "'",
                    value.equals(BigInteger.valueOf(-23L)));
        } else {
            value = value.longValue();
            expected = -23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[2] + "' != '" + -40 + "'",
                    value.equals(BigInteger.valueOf(-40L)));
        } else {
            value = value.longValue();
            expected = -40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[3] + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[4] + "' != '" + -69 + "'",
                    value.equals(BigInteger.valueOf(-69L)));
        } else {
            value = value.longValue();
            expected = -69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[5] + "' != '" + -43 + "'",
                    value.equals(BigInteger.valueOf(-43L)));
        } else {
            value = value.longValue();
            expected = -43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[6] + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.if_gain[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.if_gain[7] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[0] + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[1] + "' != '" + -123 + "'",
                    value.equals(BigInteger.valueOf(-123L)));
        } else {
            value = value.longValue();
            expected = -123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[2] + "' != '" + -122 + "'",
                    value.equals(BigInteger.valueOf(-122L)));
        } else {
            value = value.longValue();
            expected = -122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[3] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[4] + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[5] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[6] + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rf_gain[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rf_gain[7] + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
