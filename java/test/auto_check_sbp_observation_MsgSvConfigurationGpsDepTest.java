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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvConfigurationGpsDep.yaml by generate.py. Do
// not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgSvConfigurationGPSDep;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgSvConfigurationGpsDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_observation_MsgSvConfigurationGpsDepTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 66,
                    (byte) 188,
                    (byte) 101,
                    (byte) 167,
                };
        SBPMessage sbp = new SBPMessage(0x007b, 0x91, payload);
        MsgSvConfigurationGPSDep msg = new MsgSvConfigurationGPSDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.l2c_mask;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.l2c_mask + "' != '" + 2808462402L + "'",
                    value.equals(new BigInteger("2808462402")));
        } else {
            value = value.longValue();
            expected = 2808462402L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t_nmct.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.t_nmct.tow + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t_nmct.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.t_nmct.wn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
