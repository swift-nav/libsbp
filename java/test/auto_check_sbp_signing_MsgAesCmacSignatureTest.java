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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgAesCmacSignature.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.signing.MsgAesCmacSignature;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_signing_MsgAesCmacSignatureTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_signing_MsgAesCmacSignatureTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 2, (byte) 1, (byte) 2, (byte) 3, (byte) 4, (byte) 0, (byte) 1,
                    (byte) 2, (byte) 3, (byte) 4, (byte) 5, (byte) 6, (byte) 7, (byte) 8, (byte) 9,
                    (byte) 10, (byte) 11, (byte) 12, (byte) 13, (byte) 14, (byte) 15, (byte) 0,
                    (byte) 11, (byte) 22, (byte) 33,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0xC10, payload);
        MsgAesCmacSignature msg = new MsgAesCmacSignature(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.certificate_id[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[0] + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[1] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[2] + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[3] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.on_demand_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.on_demand_counter + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[0] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[1] + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[2] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[3] + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[4] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[5] + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[6] + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[7] + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[8] + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[9] + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[10] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[11] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[12] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[13] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[14] + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[15] + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[0] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[1] + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[2] + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stream_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stream_counter + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
