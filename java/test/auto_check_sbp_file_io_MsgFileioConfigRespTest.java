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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioConfigResp.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.file_io.MsgFileioConfigResp;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_file_io_MsgFileioConfigRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_file_io_MsgFileioConfigRespTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 170, (byte) 76, (byte) 52, (byte) 91, (byte) 149, (byte) 186, (byte) 44,
                    (byte) 3, (byte) 216, (byte) 151, (byte) 255, (byte) 61, (byte) 12, (byte) 97,
                    (byte) 66, (byte) 144,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0x1002, payload);
        MsgFileioConfigResp msg = new MsgFileioConfigResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.batch_size;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.batch_size + "' != '" + 1040160728 + "'",
                    value.equals(BigInteger.valueOf(1040160728L)));
        } else {
            value = value.longValue();
            expected = 1040160728L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fileio_version;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fileio_version + "' != '" + 2420269324L + "'",
                    value.equals(new BigInteger("2420269324")));
        } else {
            value = value.longValue();
            expected = 2420269324L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sequence + "' != '" + 1530154154 + "'",
                    value.equals(BigInteger.valueOf(1530154154L)));
        } else {
            value = value.longValue();
            expected = 1530154154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.window_size;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.window_size + "' != '" + 53262997 + "'",
                    value.equals(BigInteger.valueOf(53262997L)));
        } else {
            value = value.longValue();
            expected = 53262997L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
