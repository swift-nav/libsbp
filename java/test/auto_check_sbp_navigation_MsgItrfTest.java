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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgItrf.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgItrf;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgItrfTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgItrfTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1,
                    (byte) 2,
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
                    (byte) 3,
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
        MsgItrf msg = new MsgItrf(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.stub[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[0] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[1] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[2] + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[3] + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[4] + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[5] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[6] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[7] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[8] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[9] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[10] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[11] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[12] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[13] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[14] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[15] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[16] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[17] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[18] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[19] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[20] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[21] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[22] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[23] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[24] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[25] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[26] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[27] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[28] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[29] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[30] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[31] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[32] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[33] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[34] + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[35] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[36] + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[37] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[38] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[39] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[40] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[41] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[42] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[43] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[44] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[45] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[46] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[47] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[48] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[49] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[50] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[51] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[52] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[53] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[54] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[55] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[56] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[57] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[58] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[59] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[60] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[61] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[62] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[63] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[64] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[65] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[66] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[67] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[68] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[69] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[70] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[71] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[72] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[73] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[74] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[75] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[76] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[77] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[78] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[79] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[80] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[81] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[82] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[83] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[84] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[85] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[86] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[87] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[88] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[89] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[90] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[91] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[92] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[93] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[94] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[95] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[96] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[97] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[98] + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[99] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[100] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[101] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[102] + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[103] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[104] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[105] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[106] + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[107] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[108] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[109] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[110] + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[111] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[112] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[113] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[114] + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[115] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[116] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[117] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[118] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[119] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[120] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[121] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[122] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stub[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stub[123] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
