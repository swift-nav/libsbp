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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsWriteResp.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.settings.MsgSettingsWriteResp;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_settings_MsgSettingsWriteRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_settings_MsgSettingsWriteRespTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 152,
                    (byte) 115,
                    (byte) 101,
                    (byte) 99,
                    (byte) 116,
                    (byte) 105,
                    (byte) 111,
                    (byte) 110,
                    (byte) 45,
                    (byte) 110,
                    (byte) 97,
                    (byte) 109,
                    (byte) 101,
                    (byte) 0,
                    (byte) 115,
                    (byte) 101,
                    (byte) 116,
                    (byte) 116,
                    (byte) 105,
                    (byte) 110,
                    (byte) 103,
                    (byte) 45,
                    (byte) 110,
                    (byte) 97,
                    (byte) 109,
                    (byte) 101,
                    (byte) 0,
                    (byte) 115,
                    (byte) 101,
                    (byte) 116,
                    (byte) 116,
                    (byte) 105,
                    (byte) 110,
                    (byte) 103,
                    (byte) 45,
                    (byte) 118,
                    (byte) 97,
                    (byte) 108,
                    (byte) 117,
                    (byte) 101,
                    (byte) 0,
                    (byte) 101,
                    (byte) 110,
                    (byte) 117,
                    (byte) 109,
                    (byte) 59,
                    (byte) 118,
                    (byte) 97,
                    (byte) 108,
                    (byte) 117,
                    (byte) 101,
                    (byte) 49,
                    (byte) 44,
                    (byte) 118,
                    (byte) 97,
                    (byte) 108,
                    (byte) 117,
                    (byte) 101,
                    (byte) 50,
                    (byte) 44,
                    (byte) 118,
                    (byte) 97,
                    (byte) 108,
                    (byte) 117,
                    (byte) 101,
                    (byte) 51,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x375b, 0xaf, payload);
        MsgSettingsWriteResp msg = new MsgSettingsWriteResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(
                msg.setting, "section-name setting-name setting-value enum;value1,value2,value3 ");
        value = msg.status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.status + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
