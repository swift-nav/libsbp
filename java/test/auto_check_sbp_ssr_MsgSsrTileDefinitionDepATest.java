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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepA.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrTileDefinitionDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrTileDefinitionDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrTileDefinitionDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 57,
                    (byte) 190,
                    (byte) 178,
                    (byte) 247,
                    (byte) 8,
                    (byte) 185,
                    (byte) 9,
                    (byte) 181,
                    (byte) 162,
                    (byte) 240,
                    (byte) 65,
                    (byte) 19,
                    (byte) 255,
                    (byte) 143,
                    (byte) 21,
                    (byte) 191,
                    (byte) 239,
                    (byte) 205,
                    (byte) 171,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x85c8, 0x5f6, payload);
        MsgSsrTileDefinitionDepA msg = new MsgSsrTileDefinitionDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.bitmask;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.bitmask + "' != '" + 11259375 + "'",
                    value.equals(BigInteger.valueOf(11259375L)));
        } else {
            value = value.longValue();
            expected = 11259375L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cols;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cols + "' != '" + 48917 + "'",
                    value.equals(BigInteger.valueOf(48917L)));
        } else {
            value = value.longValue();
            expected = 48917L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corner_nw_lat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corner_nw_lat + "' != '" + -18168 + "'",
                    value.equals(BigInteger.valueOf(-18168L)));
        } else {
            value = value.longValue();
            expected = -18168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corner_nw_lon;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corner_nw_lon + "' != '" + -19191 + "'",
                    value.equals(BigInteger.valueOf(-19191L)));
        } else {
            value = value.longValue();
            expected = -19191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rows;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rows + "' != '" + 36863 + "'",
                    value.equals(BigInteger.valueOf(36863L)));
        } else {
            value = value.longValue();
            expected = 36863L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.spacing_lat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.spacing_lat + "' != '" + 61602 + "'",
                    value.equals(BigInteger.valueOf(61602L)));
        } else {
            value = value.longValue();
            expected = 61602L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.spacing_lon;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.spacing_lon + "' != '" + 4929 + "'",
                    value.equals(BigInteger.valueOf(4929L)));
        } else {
            value = value.longValue();
            expected = 4929L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_id + "' != '" + 63410 + "'",
                    value.equals(BigInteger.valueOf(63410L)));
        } else {
            value = value.longValue();
            expected = 63410L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_set_id + "' != '" + 48697 + "'",
                    value.equals(BigInteger.valueOf(48697L)));
        } else {
            value = value.longValue();
            expected = 48697L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
