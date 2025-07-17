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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChainDep.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.signing.MsgCertificateChainDep;


public class auto_check_sbp_signing_MsgCertificateChainDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_signing_MsgCertificateChainDepTest.test1");
        byte[] payload = new byte[] {(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)8,(byte)9,(byte)10,(byte)11,(byte)12,(byte)13,(byte)14,(byte)15,(byte)16,(byte)17,(byte)18,(byte)19,(byte)10,(byte)11,(byte)12,(byte)13,(byte)14,(byte)15,(byte)16,(byte)17,(byte)18,(byte)19,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)8,(byte)9,(byte)20,(byte)21,(byte)22,(byte)23,(byte)24,(byte)25,(byte)26,(byte)27,(byte)28,(byte)29,(byte)10,(byte)11,(byte)12,(byte)13,(byte)14,(byte)15,(byte)16,(byte)17,(byte)18,(byte)19,(byte)232,(byte)7,(byte)3,(byte)30,(byte)12,(byte)34,(byte)59,(byte)21,(byte)205,(byte)91,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7,(byte)0,(byte)1,(byte)2,(byte)3,(byte)4,(byte)5,(byte)6,(byte)7, };
        SBPMessage sbp = new SBPMessage( 0x42, 0xC05, payload );
        MsgCertificateChainDep msg = new MsgCertificateChainDep( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.corrections_certificate[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[0] + "' != '" + 20 + "'", value.equals(BigInteger.valueOf( 20L ) ) );
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[1] + "' != '" + 21 + "'", value.equals(BigInteger.valueOf( 21L ) ) );
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[2] + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[3] + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[4] + "' != '" + 24 + "'", value.equals(BigInteger.valueOf( 24L ) ) );
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[5] + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[6] + "' != '" + 26 + "'", value.equals(BigInteger.valueOf( 26L ) ) );
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[7] + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[8] + "' != '" + 28 + "'", value.equals(BigInteger.valueOf( 28L ) ) );
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[9] + "' != '" + 29 + "'", value.equals(BigInteger.valueOf( 29L ) ) );
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[10] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[11] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[12] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[13] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[14] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[15] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[16] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[17] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[18] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrections_certificate[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrections_certificate[19] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.day;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.day + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.hours;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.hours + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.minutes;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.minutes + "' != '" + 34 + "'", value.equals(BigInteger.valueOf( 34L ) ) );
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.month;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.month + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.ns;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.ns + "' != '" + 123456789 + "'", value.equals(BigInteger.valueOf( 123456789L ) ) );
        } else {
            value = value.longValue();
            expected = 123456789L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.seconds;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.seconds + "' != '" + 59 + "'", value.equals(BigInteger.valueOf( 59L ) ) );
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.expiration.year;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.expiration.year + "' != '" + 2024 + "'", value.equals(BigInteger.valueOf( 2024L ) ) );
        } else {
            value = value.longValue();
            expected = 2024L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[0] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[1] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[2] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[3] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[4] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[5] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[6] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[7] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[8] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[9] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[10] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[11] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[12] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[13] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[14] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[15] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[16] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[17] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[18] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.intermediate_certificate[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.intermediate_certificate[19] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[0] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[1] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[2] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[3] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[4] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[5] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[6] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[7] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[8] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[9] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf( 9L ) ) );
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[10] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[11] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[12] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[13] + "' != '" + 13 + "'", value.equals(BigInteger.valueOf( 13L ) ) );
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[14] + "' != '" + 14 + "'", value.equals(BigInteger.valueOf( 14L ) ) );
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[15] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[16] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[17] + "' != '" + 17 + "'", value.equals(BigInteger.valueOf( 17L ) ) );
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[18] + "' != '" + 18 + "'", value.equals(BigInteger.valueOf( 18L ) ) );
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.root_certificate[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.root_certificate[19] + "' != '" + 19 + "'", value.equals(BigInteger.valueOf( 19L ) ) );
        } else {
            value = value.longValue();
            expected = 19L;
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
            org.junit.Assert.assertTrue("'" + msg.signature[8] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[9] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[10] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[11] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[12] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[13] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[14] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[15] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[16] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[17] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[18] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[19] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[20] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[21] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[22] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[23] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[24] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[25] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[26] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[27] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[28] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[29] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[30] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[31] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[32] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[33] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[34] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[35] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[36] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[37] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[38] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[39] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[40] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[41] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[42] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[43] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[44] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[45] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[46] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[47] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[48] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[49] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[50] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[51] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[52] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[53] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[54] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[55] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[56] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[57] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[58] + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[59] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[60] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[61] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[62] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.signature[63] + "' != '" + 7 + "'", value.equals(BigInteger.valueOf( 7L ) ) );
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
