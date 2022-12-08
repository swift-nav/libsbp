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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/skylark/test_MsgAcknowledge.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.skylark.MsgAcknowledge;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_skylark_MsgAcknowledgeTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_skylark_MsgAcknowledgeTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 30,
                    (byte) 64,
                    (byte) 226,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0xFA0, payload);
        MsgAcknowledge msg = new MsgAcknowledge(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.area_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.area_id + "' != '" + 123456 + "'",
                    value.equals(BigInteger.valueOf(123456L)));
        } else {
            value = value.longValue();
            expected = 123456L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.correction_mask_on_demand;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.correction_mask_on_demand + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.correction_mask_stream;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.correction_mask_stream + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.request_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.request_counter + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.response_code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.response_code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.solution_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.solution_id + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
