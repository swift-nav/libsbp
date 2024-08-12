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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/mag/test_MsgMagRaw.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.mag.MsgMagRaw;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_mag_MsgMagRawTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_mag_MsgMagRawTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 173,
                    (byte) 227,
                    (byte) 158,
                    (byte) 198,
                    (byte) 206,
                    (byte) 98,
                    (byte) 3,
                    (byte) 230,
                    (byte) 2,
                    (byte) 110,
                    (byte) 229,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0x902, payload);
        MsgMagRaw msg = new MsgMagRaw(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.mag_x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mag_x + "' != '" + 866 + "'", value.equals(BigInteger.valueOf(866L)));
        } else {
            value = value.longValue();
            expected = 866L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.mag_y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mag_y + "' != '" + 742 + "'", value.equals(BigInteger.valueOf(742L)));
        } else {
            value = value.longValue();
            expected = 742L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.mag_z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mag_z + "' != '" + -6802 + "'",
                    value.equals(BigInteger.valueOf(-6802L)));
        } else {
            value = value.longValue();
            expected = -6802L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 3332301741L + "'",
                    value.equals(new BigInteger("3332301741")));
        } else {
            value = value.longValue();
            expected = 3332301741L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_f + "' != '" + 206 + "'", value.equals(BigInteger.valueOf(206L)));
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
