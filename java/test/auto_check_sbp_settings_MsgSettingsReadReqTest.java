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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadReq.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.settings.MsgSettingsReadReq;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_settings_MsgSettingsReadReqTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_settings_MsgSettingsReadReqTest.test1");
        byte[] payload =
                new byte[] {
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
                };
        SBPMessage sbp = new SBPMessage(0xd698, 0xa4, payload);
        MsgSettingsReadReq msg = new MsgSettingsReadReq(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.setting, "section-name setting-name ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
