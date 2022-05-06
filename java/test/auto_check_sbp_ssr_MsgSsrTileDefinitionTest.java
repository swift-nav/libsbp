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
                    (byte) 31,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 2,
                    (byte) 0,
                    (byte) 4,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                    (byte) 16,
                    (byte) 0,
                    (byte) 32,
                    (byte) 0,
                    (byte) 64,
                    (byte) 0,
                    (byte) 128,
                    (byte) 210,
                    (byte) 2,
                    (byte) 150,
                    (byte) 73,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x05F7, payload);
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
                    "'" + msg.cols + "' != '" + 32768 + "'",
                    value.equals(BigInteger.valueOf(32768L)));
        } else {
            value = value.longValue();
            expected = 32768L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corner_nw_lat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corner_nw_lat + "' != '" + 1024 + "'",
                    value.equals(BigInteger.valueOf(1024L)));
        } else {
            value = value.longValue();
            expected = 1024L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corner_nw_lon;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corner_nw_lon + "' != '" + 2048 + "'",
                    value.equals(BigInteger.valueOf(2048L)));
        } else {
            value = value.longValue();
            expected = 2048L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.rows;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.rows + "' != '" + 16384 + "'",
                    value.equals(BigInteger.valueOf(16384L)));
        } else {
            value = value.longValue();
            expected = 16384L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.spacing_lat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.spacing_lat + "' != '" + 4096 + "'",
                    value.equals(BigInteger.valueOf(4096L)));
        } else {
            value = value.longValue();
            expected = 4096L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.spacing_lon;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.spacing_lon + "' != '" + 8192 + "'",
                    value.equals(BigInteger.valueOf(8192L)));
        } else {
            value = value.longValue();
            expected = 8192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ssr_sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ssr_sol_id + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_id + "' != '" + 512 + "'",
                    value.equals(BigInteger.valueOf(512L)));
        } else {
            value = value.longValue();
            expected = 512L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_set_id + "' != '" + 256 + "'",
                    value.equals(BigInteger.valueOf(256L)));
        } else {
            value = value.longValue();
            expected = 256L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
