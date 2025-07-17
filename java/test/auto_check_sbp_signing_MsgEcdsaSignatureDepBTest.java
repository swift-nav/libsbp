/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepB.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.signing.MsgEcdsaSignatureDepB;


public class auto_check_sbp_signing_MsgEcdsaSignatureDepBTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_signing_MsgEcdsaSignatureDepBTest.test1");
        byte[] payload = new byte[] {(byte)0,(byte)1,(byte)2,(byte)1,(byte)2,(byte)3,(byte)4,(byte)72,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)8,(byte)9,(byte)10,(byte)11,(byte)12,(byte)13,(byte)14,(byte)15,(byte)16,(byte)17,(byte)18,(byte)19,(byte)20,(byte)21,(byte)22,(byte)23,(byte)24,(byte)25,(byte)26,(byte)27,(byte)28,(byte)29,(byte)30,(byte)31,(byte)32,(byte)33,(byte)34,(byte)35,(byte)36,(byte)37,(byte)38,(byte)39,(byte)40,(byte)41,(byte)42,(byte)43,(byte)44,(byte)45,(byte)46,(byte)47,(byte)48,(byte)49,(byte)50,(byte)51,(byte)52,(byte)53,(byte)54,(byte)55,(byte)56,(byte)57,(byte)58,(byte)59,(byte)60,(byte)61,(byte)62,(byte)63,(byte)64,(byte)65,(byte)66,(byte)67,(byte)68,(byte)69,(byte)70,(byte)71,(byte)10,(byte)21,(byte)23, };
        SBPMessage sbp = new SBPMessage( 0x42, 0xC07, payload );
        MsgEcdsaSignatureDepB msg = new MsgEcdsaSignatureDepB( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.certificate_id[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.certificate_id[0] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.certificate_id[1] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.certificate_id[2] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.certificate_id[3] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_signature_bytes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.n_signature_bytes + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.on_demand_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.on_demand_counter + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[0] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[1] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[2] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[3] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[4] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[5] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[6] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[7] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[8] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[9] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[10] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[11] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[12] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[13] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[14] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[15] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[16] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[17] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[18] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[19] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[20] + "' != '" + 20 + "'", value.equals(BigInteger.valueOf( 20L ) ) );
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[21] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[22] + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[23] + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[24] + "' != '" + 24 + "'", value.equals(BigInteger.valueOf( 24L ) ) );
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[25] + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[26] + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[27] + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[28] + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[29] + "' != '" + 29 + "'", value.equals(BigInteger.valueOf( 29L ) ) );
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[30] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[31] + "' != '" + 31 + "'", value.equals(BigInteger.valueOf( 31L ) ) );
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[32] + "' != '" + 32 + "'", value.equals(BigInteger.valueOf( 32L ) ) );
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[33] + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[34] + "' != '" + 34 + "'", value.equals(BigInteger.valueOf( 34L ) ) );
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[35] + "' != '" + 35 + "'", value.equals(BigInteger.valueOf( 35L ) ) );
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[36] + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[37] + "' != '" + 37 + "'", value.equals(BigInteger.valueOf( 37L ) ) );
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[38] + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[39] + "' != '" + 39 + "'", value.equals(BigInteger.valueOf( 39L ) ) );
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[40] + "' != '" + 40 + "'", value.equals(BigInteger.valueOf( 40L ) ) );
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[41] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[42] + "' != '" + 42 + "'", value.equals(BigInteger.valueOf( 42L ) ) );
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[43] + "' != '" + 43 + "'", value.equals(BigInteger.valueOf( 43L ) ) );
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[44] + "' != '" + 44 + "'", value.equals(BigInteger.valueOf( 44L ) ) );
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[45] + "' != '" + 45 + "'", value.equals(BigInteger.valueOf( 45L ) ) );
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[46] + "' != '" + 46 + "'", value.equals(BigInteger.valueOf( 46L ) ) );
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[47] + "' != '" + 47 + "'", value.equals(BigInteger.valueOf( 47L ) ) );
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[48] + "' != '" + 48 + "'", value.equals(BigInteger.valueOf( 48L ) ) );
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[49] + "' != '" + 49 + "'", value.equals(BigInteger.valueOf( 49L ) ) );
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[50] + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[51] + "' != '" + 51 + "'", value.equals(BigInteger.valueOf( 51L ) ) );
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[52] + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[53] + "' != '" + 53 + "'", value.equals(BigInteger.valueOf( 53L ) ) );
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[54] + "' != '" + 54 + "'", value.equals(BigInteger.valueOf( 54L ) ) );
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[55] + "' != '" + 55 + "'", value.equals(BigInteger.valueOf( 55L ) ) );
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[56] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[57] + "' != '" + 57 + "'", value.equals(BigInteger.valueOf( 57L ) ) );
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[58] + "' != '" + 58 + "'", value.equals(BigInteger.valueOf( 58L ) ) );
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[59] + "' != '" + 59 + "'", value.equals(BigInteger.valueOf( 59L ) ) );
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[60] + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[61] + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[62] + "' != '" + 62 + "'", value.equals(BigInteger.valueOf( 62L ) ) );
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[63] + "' != '" + 63 + "'", value.equals(BigInteger.valueOf( 63L ) ) );
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[64] + "' != '" + 64 + "'", value.equals(BigInteger.valueOf( 64L ) ) );
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[65] + "' != '" + 65 + "'", value.equals(BigInteger.valueOf( 65L ) ) );
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[66] + "' != '" + 66 + "'", value.equals(BigInteger.valueOf( 66L ) ) );
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[67] + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[68] + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[69] + "' != '" + 69 + "'", value.equals(BigInteger.valueOf( 69L ) ) );
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[70] + "' != '" + 70 + "'", value.equals(BigInteger.valueOf( 70L ) ) );
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[71] + "' != '" + 71 + "'", value.equals(BigInteger.valueOf( 71L ) ) );
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signed_messages[0] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signed_messages[1] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signed_messages[2] + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stream_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stream_counter + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
