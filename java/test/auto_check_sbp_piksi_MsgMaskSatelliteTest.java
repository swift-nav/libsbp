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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatellite.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgMaskSatellite;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgMaskSatelliteTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgMaskSatelliteTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 183, (byte) 87, (byte) 57,
                };
        SBPMessage sbp = new SBPMessage(0x97ad, 0x2b, payload);
        MsgMaskSatellite msg = new MsgMaskSatellite(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.mask;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mask + "' != '" + 183 + "'", value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 87 + "'", value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
