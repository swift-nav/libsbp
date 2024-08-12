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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgCsacTelemetry.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.system.MsgCsacTelemetry;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_system_MsgCsacTelemetryTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgCsacTelemetryTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 105,
                    (byte) 115,
                    (byte) 111,
                    (byte) 109,
                    (byte) 101,
                    (byte) 32,
                    (byte) 100,
                    (byte) 97,
                    (byte) 116,
                    (byte) 97,
                };
        SBPMessage sbp = new SBPMessage(0xa9f4, 0xff04, payload);
        MsgCsacTelemetry msg = new MsgCsacTelemetry(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.id + "' != '" + 105 + "'", value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.telemetry, "some data");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
