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
// spec/tests/yaml/swiftnav/sbp/bootload/test_MsgNapDeviceDnaResp.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.bootload.MsgNapDeviceDnaResp;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_bootload_MsgNapDeviceDnaRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_bootload_MsgNapDeviceDnaRespTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 2,
                    (byte) 187,
                    (byte) 1,
                    (byte) 130,
                    (byte) 173,
                    (byte) 244,
                    (byte) 67,
                    (byte) 122,
                };
        SBPMessage sbp = new SBPMessage(0x38a9, 0xdd, payload);
        MsgNapDeviceDnaResp msg = new MsgNapDeviceDnaResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.dna[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[0] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[1] + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[2] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[3] + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[4] + "' != '" + 173 + "'",
                    value.equals(BigInteger.valueOf(173L)));
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[5] + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[6] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dna[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dna[7] + "' != '" + 122 + "'",
                    value.equals(BigInteger.valueOf(122L)));
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
