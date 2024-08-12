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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.solution_meta.MsgSolnMetaDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_solution_meta_MsgSolnMetaDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_solution_meta_MsgSolnMetaDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 183,
                    (byte) 222,
                    (byte) 157,
                    (byte) 121,
                    (byte) 5,
                    (byte) 164,
                    (byte) 238,
                    (byte) 31,
                    (byte) 190,
                    (byte) 115,
                    (byte) 93,
                    (byte) 59,
                    (byte) 103,
                    (byte) 36,
                    (byte) 83,
                    (byte) 161,
                    (byte) 156,
                    (byte) 46,
                    (byte) 253,
                    (byte) 67,
                    (byte) 87,
                    (byte) 200,
                    (byte) 39,
                    (byte) 250,
                    (byte) 245,
                    (byte) 242,
                    (byte) 228,
                    (byte) 72,
                    (byte) 18,
                    (byte) 222,
                    (byte) 11,
                    (byte) 88,
                    (byte) 207,
                    (byte) 218,
                    (byte) 231,
                    (byte) 13,
                    (byte) 226,
                    (byte) 224,
                    (byte) 22,
                    (byte) 196,
                    (byte) 21,
                    (byte) 242,
                    (byte) 12,
                    (byte) 89,
                    (byte) 71,
                    (byte) 219,
                    (byte) 182,
                    (byte) 85,
                    (byte) 145,
                    (byte) 204,
                    (byte) 146,
                    (byte) 40,
                    (byte) 204,
                    (byte) 51,
                    (byte) 21,
                    (byte) 153,
                    (byte) 227,
                    (byte) 44,
                    (byte) 15,
                    (byte) 28,
                    (byte) 255,
                    (byte) 39,
                    (byte) 205,
                    (byte) 216,
                    (byte) 240,
                    (byte) 190,
                    (byte) 93,
                    (byte) 219,
                    (byte) 103,
                    (byte) 42,
                    (byte) 41,
                    (byte) 182,
                    (byte) 76,
                    (byte) 222,
                    (byte) 17,
                    (byte) 23,
                    (byte) 125,
                    (byte) 31,
                    (byte) 18,
                    (byte) 229,
                    (byte) 28,
                    (byte) 47,
                    (byte) 214,
                    (byte) 25,
                    (byte) 100,
                    (byte) 84,
                    (byte) 106,
                    (byte) 72,
                    (byte) 48,
                    (byte) 10,
                    (byte) 222,
                    (byte) 232,
                    (byte) 235,
                    (byte) 73,
                    (byte) 109,
                    (byte) 163,
                    (byte) 51,
                    (byte) 152,
                    (byte) 133,
                    (byte) 235,
                    (byte) 87,
                    (byte) 70,
                    (byte) 2,
                    (byte) 108,
                    (byte) 91,
                    (byte) 101,
                    (byte) 200,
                    (byte) 55,
                    (byte) 24,
                    (byte) 156,
                    (byte) 233,
                    (byte) 73,
                    (byte) 39,
                    (byte) 66,
                    (byte) 97,
                    (byte) 140,
                    (byte) 252,
                    (byte) 227,
                    (byte) 230,
                    (byte) 237,
                    (byte) 135,
                    (byte) 241,
                    (byte) 245,
                    (byte) 205,
                    (byte) 70,
                    (byte) 0,
                    (byte) 219,
                    (byte) 188,
                    (byte) 107,
                    (byte) 136,
                    (byte) 178,
                    (byte) 58,
                    (byte) 1,
                    (byte) 29,
                    (byte) 44,
                    (byte) 213,
                    (byte) 225,
                    (byte) 147,
                    (byte) 190,
                    (byte) 96,
                    (byte) 192,
                    (byte) 108,
                    (byte) 228,
                    (byte) 15,
                    (byte) 203,
                    (byte) 18,
                    (byte) 3,
                    (byte) 222,
                    (byte) 180,
                    (byte) 68,
                    (byte) 101,
                    (byte) 229,
                    (byte) 223,
                    (byte) 203,
                    (byte) 243,
                    (byte) 164,
                    (byte) 92,
                    (byte) 165,
                    (byte) 220,
                    (byte) 159,
                    (byte) 174,
                    (byte) 121,
                    (byte) 112,
                    (byte) 167,
                    (byte) 240,
                    (byte) 40,
                    (byte) 59,
                    (byte) 3,
                    (byte) 230,
                    (byte) 52,
                    (byte) 149,
                    (byte) 148,
                    (byte) 218,
                    (byte) 142,
                    (byte) 212,
                    (byte) 109,
                    (byte) 176,
                    (byte) 71,
                    (byte) 179,
                    (byte) 172,
                    (byte) 77,
                    (byte) 1,
                    (byte) 193,
                    (byte) 70,
                    (byte) 147,
                    (byte) 149,
                    (byte) 23,
                    (byte) 144,
                    (byte) 148,
                    (byte) 239,
                    (byte) 195,
                    (byte) 186,
                    (byte) 86,
                    (byte) 30,
                    (byte) 34,
                    (byte) 143,
                    (byte) 156,
                    (byte) 207,
                    (byte) 63,
                    (byte) 55,
                    (byte) 117,
                    (byte) 255,
                    (byte) 222,
                    (byte) 222,
                    (byte) 219,
                    (byte) 145,
                    (byte) 224,
                    (byte) 191,
                    (byte) 210,
                    (byte) 109,
                    (byte) 86,
                    (byte) 153,
                    (byte) 21,
                    (byte) 32,
                    (byte) 226,
                    (byte) 10,
                    (byte) 60,
                    (byte) 63,
                    (byte) 106,
                    (byte) 236,
                    (byte) 93,
                    (byte) 96,
                    (byte) 30,
                    (byte) 163,
                    (byte) 106,
                    (byte) 238,
                    (byte) 147,
                    (byte) 133,
                    (byte) 132,
                    (byte) 107,
                    (byte) 152,
                    (byte) 214,
                    (byte) 221,
                    (byte) 185,
                    (byte) 202,
                    (byte) 21,
                    (byte) 252,
                    (byte) 51,
                    (byte) 130,
                    (byte) 59,
                    (byte) 166,
                    (byte) 202,
                    (byte) 127,
                    (byte) 170,
                    (byte) 58,
                    (byte) 193,
                    (byte) 215,
                    (byte) 125,
                    (byte) 22,
                    (byte) 58,
                    (byte) 135,
                    (byte) 47,
                    (byte) 88,
                    (byte) 142,
                };
        SBPMessage sbp = new SBPMessage(0xf154, 0xff0f, payload);
        MsgSolnMetaDepA msg = new MsgSolnMetaDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.age_corrections;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.age_corrections + "' != '" + 48671 + "'",
                    value.equals(BigInteger.valueOf(48671L)));
        } else {
            value = value.longValue();
            expected = 48671L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.alignment_status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.alignment_status + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 31133 + "'",
                    value.equals(BigInteger.valueOf(31133L)));
        } else {
            value = value.longValue();
            expected = 31133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.last_used_gnss_pos_tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.last_used_gnss_pos_tow + "' != '" + 610745181 + "'",
                    value.equals(BigInteger.valueOf(610745181L)));
        } else {
            value = value.longValue();
            expected = 610745181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.last_used_gnss_vel_tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.last_used_gnss_vel_tow + "' != '" + 782016851 + "'",
                    value.equals(BigInteger.valueOf(782016851L)));
        } else {
            value = value.longValue();
            expected = 782016851L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 57015 + "'",
                    value.equals(BigInteger.valueOf(57015L)));
        } else {
            value = value.longValue();
            expected = 57015L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[0].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[0].flags + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[0].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[0].sensor_type + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[1].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[1].flags + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[1].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[1].sensor_type + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[2].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[2].flags + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[2].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[2].sensor_type + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[3].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[3].flags + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[3].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[3].sensor_type + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[4].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[4].flags + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[4].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[4].sensor_type + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[5].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[5].flags + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[5].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[5].sensor_type + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[6].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[6].flags + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[6].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[6].sensor_type + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[7].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[7].flags + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[7].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[7].sensor_type + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[8].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[8].flags + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[8].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[8].sensor_type + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[9].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[9].flags + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[9].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[9].sensor_type + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[10].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[10].flags + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[10].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[10].sensor_type + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[11].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[11].flags + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[11].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[11].sensor_type + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[12].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[12].flags + "' != '" + 89 + "'",
                    value.equals(BigInteger.valueOf(89L)));
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[12].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[12].sensor_type + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[13].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[13].flags + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[13].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[13].sensor_type + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[14].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[14].flags + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[14].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[14].sensor_type + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[15].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[15].flags + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[15].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[15].sensor_type + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[16].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[16].flags + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[16].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[16].sensor_type + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[17].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[17].flags + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[17].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[17].sensor_type + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[18].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[18].flags + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[18].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[18].sensor_type + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[19].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[19].flags + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[19].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[19].sensor_type + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[20].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[20].flags + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[20].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[20].sensor_type + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[21].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[21].flags + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[21].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[21].sensor_type + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[22].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[22].flags + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[22].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[22].sensor_type + "' != '" + 205 + "'",
                    value.equals(BigInteger.valueOf(205L)));
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[23].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[23].flags + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[23].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[23].sensor_type + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[24].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[24].flags + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[24].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[24].sensor_type + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[25].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[25].flags + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[25].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[25].sensor_type + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[26].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[26].flags + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[26].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[26].sensor_type + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[27].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[27].flags + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[27].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[27].sensor_type + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[28].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[28].flags + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[28].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[28].sensor_type + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[29].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[29].flags + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[29].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[29].sensor_type + "' != '" + 125 + "'",
                    value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[30].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[30].flags + "' != '" + 229 + "'",
                    value.equals(BigInteger.valueOf(229L)));
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[30].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[30].sensor_type + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[31].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[31].flags + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[31].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[31].sensor_type + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[32].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[32].flags + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[32].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[32].sensor_type + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[33].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[33].flags + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[33].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[33].sensor_type + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[34].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[34].flags + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[34].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[34].sensor_type + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[35].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[35].flags + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[35].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[35].sensor_type + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[36].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[36].flags + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[36].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[36].sensor_type + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[37].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[37].flags + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[37].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[37].sensor_type + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[38].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[38].flags + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[38].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[38].sensor_type + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[39].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[39].flags + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[39].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[39].sensor_type + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[40].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[40].flags + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[40].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[40].sensor_type + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[41].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[41].flags + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[41].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[41].sensor_type + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[42].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[42].flags + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[42].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[42].sensor_type + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[43].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[43].flags + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[43].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[43].sensor_type + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[44].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[44].flags + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[44].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[44].sensor_type + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[45].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[45].flags + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[45].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[45].sensor_type + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[46].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[46].flags + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[46].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[46].sensor_type + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[47].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[47].flags + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[47].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[47].sensor_type + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[48].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[48].flags + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[48].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[48].sensor_type + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[49].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[49].flags + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[49].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[49].sensor_type + "' != '" + 252 + "'",
                    value.equals(BigInteger.valueOf(252L)));
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[50].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[50].flags + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[50].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[50].sensor_type + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[51].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[51].flags + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[51].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[51].sensor_type + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[52].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[52].flags + "' != '" + 205 + "'",
                    value.equals(BigInteger.valueOf(205L)));
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[52].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[52].sensor_type + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[53].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[53].flags + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[53].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[53].sensor_type + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[54].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[54].flags + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[54].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[54].sensor_type + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[55].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[55].flags + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[55].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[55].sensor_type + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[56].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[56].flags + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[56].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[56].sensor_type + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[57].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[57].flags + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[57].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[57].sensor_type + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[58].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[58].flags + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[58].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[58].sensor_type + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[59].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[59].flags + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[59].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[59].sensor_type + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[60].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[60].flags + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[60].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[60].sensor_type + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[61].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[61].flags + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[61].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[61].sensor_type + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[62].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[62].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[62].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[62].sensor_type + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[63].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[63].flags + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[63].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[63].sensor_type + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[64].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[64].flags + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[64].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[64].sensor_type + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[65].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[65].flags + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[65].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[65].sensor_type + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[66].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[66].flags + "' != '" + 229 + "'",
                    value.equals(BigInteger.valueOf(229L)));
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[66].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[66].sensor_type + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[67].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[67].flags + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[67].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[67].sensor_type + "' != '" + 223 + "'",
                    value.equals(BigInteger.valueOf(223L)));
        } else {
            value = value.longValue();
            expected = 223L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[68].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[68].flags + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[68].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[68].sensor_type + "' != '" + 243 + "'",
                    value.equals(BigInteger.valueOf(243L)));
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[69].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[69].flags + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[69].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[69].sensor_type + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[70].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[70].flags + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[70].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[70].sensor_type + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[71].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[71].flags + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[71].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[71].sensor_type + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[72].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[72].flags + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[72].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[72].sensor_type + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[73].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[73].flags + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[73].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[73].sensor_type + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[74].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[74].flags + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[74].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[74].sensor_type + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[75].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[75].flags + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[75].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[75].sensor_type + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[76].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[76].flags + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[76].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[76].sensor_type + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[77].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[77].flags + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[77].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[77].sensor_type + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[78].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[78].flags + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[78].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[78].sensor_type + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[79].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[79].flags + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[79].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[79].sensor_type + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[80].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[80].flags + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[80].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[80].sensor_type + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[81].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[81].flags + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[81].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[81].sensor_type + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[82].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[82].flags + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[82].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[82].sensor_type + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[83].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[83].flags + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[83].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[83].sensor_type + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[84].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[84].flags + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[84].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[84].sensor_type + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[85].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[85].flags + "' != '" + 239 + "'",
                    value.equals(BigInteger.valueOf(239L)));
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[85].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[85].sensor_type + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[86].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[86].flags + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[86].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[86].sensor_type + "' != '" + 195 + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[87].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[87].flags + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[87].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[87].sensor_type + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[88].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[88].flags + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[88].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[88].sensor_type + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[89].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[89].flags + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[89].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[89].sensor_type + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[90].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[90].flags + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[90].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[90].sensor_type + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[91].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[91].flags + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[91].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[91].sensor_type + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[92].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[92].flags + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[92].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[92].sensor_type + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[93].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[93].flags + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[93].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[93].sensor_type + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[94].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[94].flags + "' != '" + 191 + "'",
                    value.equals(BigInteger.valueOf(191L)));
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[94].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[94].sensor_type + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[95].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[95].flags + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[95].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[95].sensor_type + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[96].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[96].flags + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[96].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[96].sensor_type + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[97].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[97].flags + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[97].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[97].sensor_type + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[98].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[98].flags + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[98].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[98].sensor_type + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[99].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[99].flags + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[99].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[99].sensor_type + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[100].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[100].flags + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[100].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[100].sensor_type + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[101].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[101].flags + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[101].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[101].sensor_type + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[102].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[102].flags + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[102].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[102].sensor_type + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[103].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[103].flags + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[103].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[103].sensor_type + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[104].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[104].flags + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[104].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[104].sensor_type + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[105].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[105].flags + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[105].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[105].sensor_type + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[106].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[106].flags + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[106].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[106].sensor_type + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[107].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[107].flags + "' != '" + 185 + "'",
                    value.equals(BigInteger.valueOf(185L)));
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[107].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[107].sensor_type + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[108].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[108].flags + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[108].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[108].sensor_type + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[109].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[109].flags + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[109].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[109].sensor_type + "' != '" + 252 + "'",
                    value.equals(BigInteger.valueOf(252L)));
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[110].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[110].flags + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[110].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[110].sensor_type + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[111].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[111].flags + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[111].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[111].sensor_type + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[112].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[112].flags + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[112].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[112].sensor_type + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[113].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[113].flags + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[113].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[113].sensor_type + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[114].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[114].flags + "' != '" + 125 + "'",
                    value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[114].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[114].sensor_type + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[115].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[115].flags + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[115].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[115].sensor_type + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[116].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[116].flags + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[116].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[116].sensor_type + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[117].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[117].flags + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_in[117].sensor_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sol_in[117].sensor_type + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 41989 + "'",
                    value.equals(BigInteger.valueOf(41989L)));
        } else {
            value = value.longValue();
            expected = 41989L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
