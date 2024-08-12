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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinition.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrTileDefinition;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrTileDefinitionTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrTileDefinitionTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 127, (byte) 58, (byte) 9, (byte) 0, (byte) 174, (byte) 8, (byte) 1,
                    (byte) 2, (byte) 3, (byte) 4, (byte) 0, (byte) 5, (byte) 0, (byte) 186,
                    (byte) 28, (byte) 59, (byte) 167, (byte) 100, (byte) 0, (byte) 100, (byte) 0,
                    (byte) 6, (byte) 0, (byte) 6, (byte) 0, (byte) 210, (byte) 2, (byte) 150,
                    (byte) 73, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x0, 0x5F8, payload);
        MsgSsrTileDefinition msg = new MsgSsrTileDefinition(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.bitmask;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.bitmask + "' != '" + 1234567890 + "'",
                    value.equals(BigInteger.valueOf(1234567890L)));
        } else {
            value = value.longValue();
            expected = 1234567890L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cols;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cols + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corner_nw_lat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corner_nw_lat + "' != '" + 7354 + "'",
                    value.equals(BigInteger.valueOf(7354L)));
        } else {
            value = value.longValue();
            expected = 7354L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corner_nw_lon;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corner_nw_lon + "' != '" + -22725 + "'",
                    value.equals(BigInteger.valueOf(-22725L)));
        } else {
            value = value.longValue();
            expected = -22725L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iod_atmo + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rows;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rows + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_id + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.spacing_lat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.spacing_lat + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.spacing_lon;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.spacing_lon + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_id + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_set_id + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.tow + "' != '" + 604799 + "'",
                    value.equals(BigInteger.valueOf(604799L)));
        } else {
            value = value.longValue();
            expected = 604799L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.wn + "' != '" + 2222 + "'",
                    value.equals(BigInteger.valueOf(2222L)));
        } else {
            value = value.longValue();
            expected = 2222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.update_interval + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
