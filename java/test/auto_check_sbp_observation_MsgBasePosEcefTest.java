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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosEcef.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgBasePosECEF;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgBasePosEcefTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgBasePosEcefTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 228,
                    (byte) 131,
                    (byte) 158,
                    (byte) 245,
                    (byte) 87,
                    (byte) 205,
                    (byte) 68,
                    (byte) 193,
                    (byte) 66,
                    (byte) 62,
                    (byte) 232,
                    (byte) 209,
                    (byte) 32,
                    (byte) 118,
                    (byte) 80,
                    (byte) 193,
                    (byte) 213,
                    (byte) 231,
                    (byte) 106,
                    (byte) 251,
                    (byte) 63,
                    (byte) 20,
                    (byte) 77,
                    (byte) 65,
                };
        SBPMessage sbp = new SBPMessage(0, 0x48, payload);
        MsgBasePosECEF msg = new MsgBasePosECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.x, -2.72657591889999993e+06, DELTA);
        org.junit.Assert.assertEquals(msg.y, -4.31526727979999967e+06, DELTA);
        org.junit.Assert.assertEquals(msg.z, 3.81145596419999981e+06, DELTA);
    }
}
