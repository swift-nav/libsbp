/* Copyright (C) 2015-2022 Swift Navigation Inc.
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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgReferenceFrameParam;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgReferenceFrameParamTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_navigation_MsgReferenceFrameParamTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1,
                    (byte) 102,
                    (byte) 111,
                    (byte) 111,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 98,
                    (byte) 97,
                    (byte) 114,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
                    (byte) 5,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 11,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 12,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 13,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 16,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 17,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 18,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 19,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 20,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x0244, payload);
        MsgReferenceFrameParam msg = new MsgReferenceFrameParam(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.delta_X0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.delta_X0 + "' != '" + 7 + "'", value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.delta_Y0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.delta_Y0 + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.delta_Z0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.delta_Z0 + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_delta_X0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_delta_X0 + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_delta_Y0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_delta_Y0 + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_delta_Z0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_delta_Z0 + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_scale;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_scale + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_theta_01;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_theta_01 + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_theta_02;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_theta_02 + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_theta_03;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dot_theta_03 + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.re_t0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.re_t0 + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.scale;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.scale + "' != '" + 13 + "'", value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sin + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.sn, "foo                             ");
        value = msg.ssr_iod;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ssr_iod + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.theta_01;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.theta_01 + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.theta_02;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.theta_02 + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.theta_03;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.theta_03 + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.tn, "bar                             ");
        value = msg.utn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.utn + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
