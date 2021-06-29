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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.logging.MsgFwd;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_logging_MsgFwdTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_logging_MsgFwdTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0, (byte) 0, (byte) 86, (byte) 81, (byte) 68, (byte) 47, (byte) 81,
                    (byte) 103, (byte) 65, (byte) 69, (byte) 65, (byte) 65, (byte) 65, (byte) 65,
                    (byte) 65, (byte) 69, (byte) 97, (byte) 103,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0x402, payload);
        MsgFwd msg = new MsgFwd(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.fwd_payload[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[0] + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[1] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[2] + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[3] + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[4] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[5] + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[6] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[7] + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[8] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[9] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[10] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[11] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[12] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[13] + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[14] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fwd_payload[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fwd_payload[15] + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.protocol;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.protocol + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.source;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.source + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
