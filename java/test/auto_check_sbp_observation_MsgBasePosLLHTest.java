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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosLLH.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgBasePosLLH;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgBasePosLLHTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgBasePosLLHTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 225, (byte) 237, (byte) 238, (byte) 90, (byte) 42, (byte) 160, (byte) 66,
                    (byte) 64, (byte) 59, (byte) 143, (byte) 70, (byte) 235, (byte) 0, (byte) 120,
                    (byte) 94, (byte) 192, (byte) 51, (byte) 181, (byte) 124, (byte) 240, (byte) 65,
                    (byte) 248, (byte) 66, (byte) 64,
                };
        SBPMessage sbp = new SBPMessage(0x007b, 0x44, payload);
        MsgBasePosLLH msg = new MsgBasePosLLH(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.height, 3.79395123108792163e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 3.72512925783773952e+01, DELTA);
        org.junit.Assert.assertEquals(msg.lon, -1.21875056094079739e+02, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
