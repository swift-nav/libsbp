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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexReq.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.settings.MsgSettingsReadByIndexReq;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_settings_MsgSettingsReadByIndexReqTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_settings_MsgSettingsReadByIndexReqTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 244, (byte) 34,
                };
        SBPMessage sbp = new SBPMessage(0x7b7a, 0xa2, payload);
        MsgSettingsReadByIndexReq msg = new MsgSettingsReadByIndexReq(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 8948 + "'",
                    value.equals(BigInteger.valueOf(8948L)));
        } else {
            value = value.longValue();
            expected = 8948L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
