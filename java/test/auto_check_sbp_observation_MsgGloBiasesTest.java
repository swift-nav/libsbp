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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgGloBiases;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgGloBiasesTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgGloBiasesTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0, 0x75, payload);
        MsgGloBiases msg = new MsgGloBiases(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.l1ca_bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.l1ca_bias + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.l1p_bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.l1p_bias + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.l2ca_bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.l2ca_bias + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.l2p_bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.l2p_bias + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.mask;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mask + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
